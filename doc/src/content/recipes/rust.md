+++
title = "Rust FFI"
description = "How to teach Rust about `result<T>`."
tags = [ "Rust" ]
+++

A nice side effect of [Outcome.Experimental's excellent C support]({{% relref "/experimental/c-api" %}})
is that teaching Rust about Outcome's `result<T>` becomes trivially
easy. C and C++ results propagate _losslessly_ into Rust Results, and the
full power of the Outcome C API is available to Rust code for semantic
equivalence comparison et al.

Here's a quick snippet to get you started. This assumes that you have declared
your C result using `CXX_DECLARE_RESULT_SYSTEM(outcome, intptr_t)` in order
to produce a C result named "outcome" compatible with an erased system code C++ result:

```rust
// Rust representation of an Outcome.Experimental Result
pub type OutcomeCResult<T> = Result<T, cxx_status_code_system>;

unsafe impl Send for cxx_status_code_system {}
unsafe impl Sync for cxx_status_code_system {}

impl std::fmt::Display for cxx_status_code_system {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(
            f,
            "{}",
            String::from_utf8_lossy(unsafe {
                CStr::from_ptr(outcome_status_code_message(
                    self as *const _ as *const ::std::os::raw::c_void,
                ))
                .to_bytes()
            })
        )
    }
}

impl std::fmt::Debug for cxx_status_code_system {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        write!(
            f,
            "{}",
            String::from_utf8_lossy(unsafe {
                CStr::from_ptr(outcome_status_code_message(
                    self as *const _ as *const ::std::os::raw::c_void,
                ))
                .to_bytes()
            })
        )
    }
}

// Tell Rust that this meets the `Error` trait
impl std::error::Error for cxx_status_code_system {
    fn source(&self) -> Option<&(dyn std::error::Error + 'static)> {
        None
    }
}

// Tell Rust how to make an `io::Result<T>` from a `OutcomeCResult<T>`
impl From<cxx_status_code_system> for std::io::Error {
    fn from(val: cxx_status_code_system) -> Self {
        // This is nasty, and we ought to figure out a better way of doing this
        for n in 1..200 {
            if unsafe {
                outcome_status_code_equal_generic(
                    &val as *const cxx_status_code_system as *const ::std::os::raw::c_void,
                    n,
                ) != 0
            } {
                return Self::new(Self::from_raw_os_error(n).kind(), val);
            }
        }
        Self::new(std::io::ErrorKind::Other, val)
    }
}

impl std::fmt::Debug for cxx_result_status_code_system_outcome {
    fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        if (self.flags & 1) == 1 {
            let v: OutcomeCResult<isize> = Ok(self.value);
            return v.fmt(f);
        } else {
            let v: OutcomeCResult<isize> = Err(self.error);
            return v.fmt(f);
        }
    }
}

pub fn to_result(res: cxx_result_status_code_system_outcome) -> OutcomeCResult<isize> {
    if (res.flags & 1) == 1 {
        return Ok(res.value);
    }
    Err(res.error)
}

pub fn success(val: isize) -> outcome_c_result {
    // You will need to export BOOST_OUTCOME_C_MAKE_RESULT_SYSTEM_SUCCESS(outcome, v) as
    // FFI outcome_c_make_success()
    unsafe { outcome_c_make_success(val) }
}

pub fn failure_from_errno(val: ::std::os::raw::c_int) -> outcome_c_result {
    // You will need to export BOOST_OUTCOME_C_MAKE_RESULT_SYSTEM_FAILURE_SYSTEM(outcome, v) as
    // FFI outcome_c_make_failure()
    unsafe { outcome_c_make_failure(val) }
}
```

Let's say there is an FFI function like this:

```rust
unsafe extern "C" {
    pub fn file_read(
        arg1: *mut db,
        buffer: *mut u8,
        bytes: usize,
    ) -> outcome_c_result;
}
```

You can now do:

```rust
// Make a Rust Result equivalent to the Outcome Result
let res = to_result(unsafe { file_read(db, buffer, 256) });
// Asks Outcome for the message automatically
println!("Message: {}", res.err().unwrap());
```

You can use the standard Rust `?` to TRY Rust Results, same as anywhere else in Rust.

As we taught Rust how to lossy map `OutcomeCResult<T>` into an `io::Result<T>`, you
can also `?` from an Outcome C Result function into an i/o Result function. Note that
this is **lossy**, and you may not wish to allow that by removing the `From` trait
definition above.

Easy as pie!
