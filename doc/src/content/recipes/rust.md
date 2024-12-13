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
            .to_string()
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
            .to_string()
        )
    }
}

fn to_result(res: cxx_result_status_code_system_outcome) -> OutcomeCResult<isize> {
    if (res.flags & 1) == 1 {
        return Ok(res.value);
    }
    Err(res.error)
}
```

Let's say there is an FFI function like this:

```rust
unsafe extern "C" {
    pub fn file_read(
        arg1: *mut db,
        buffer: *mut u8,
        bytes: usize,
    ) -> monad_c_result;
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

Easy as pie!
