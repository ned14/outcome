# Tutorial part B: Outcome's outcome<T>, result<T> and option<T>
\anchor tutorial_outcome

[TOC]

\todo This section is not finished yet and may contain inaccurate or incorrect information.

Outcome provides a number of utility classes useful for ultra lightweight and constant time error
handling in C++ 14 and later. One of these is \ref expected_qoi "a highly conforming expected<T, E> implementation"
which is currently before the ISO C++ standards Library Evolution Working Group for
standardisation. `expected<T, E>` is a very flexible
and generic utility class allowing perhaps too much unwise customisation in the hands
of its users, so Outcome also provides a family of more hard coded and deliberately
less flexible refinements to `expected<T, E>` called `outcome<T>` and `result<T>`
the use of which ought to generate lower overhead.
These less flexible refinements are likely much better suited to large code bases,
encourage users to not unintentionally write bad practice code and come with the
big advantage of requiring you to type less boilerplate during use.

This tutorial is therefore split into two parts. The first part (\ref tutorial_expected "part A") provides a broad
overview of error handling in C++ in general and how `expected<T, E>` will
contribute to that big menu of error handling design patterns available to the C++ programmer.
The second part (part B) describes why you probably ought
to not use unrestricted `expected<T, E>` in any real world code base and why
you ought to use the refinements of `outcome<T>` or `result<T>` instead.

<hr><br>

\section expected_is_bad Unrestricted use of expected<T, E> is bad practice

Most people very keen on Expected entering C++ will be coming from a Swift or especially
Rust background where when you use `Result<T, E>`, you invariably supply a bespoke enum of
error codes for type E like this fragment of Rust:

~~~{.rs}
pub enum MathError {
  DivisionByZero,
  NegativeLogarithm,
  NegativeSquareRoot,
}

pub type MathResult = Result<f64, MathError>;
~~~

I will tell you now that this is a **bad idea** in large C++ codebases or in any code
expected to be used by others, and you should not do this with `expected<T, E>`.

The first reason is because C++ 11 brought in an infrastructure from Boost which allows
you to *non-intrusively* mark up **any** arbitrary third party error code system to
tell the C++ standard library about it such that any other C++ code using that system
can handle any third party error situation *without being recompiled* and *without
losing information*. If you refuse to use the C++ 11 standard way of working with
error codes, then you are being **anti-social** to other C++ code and devaluing the
experience of anybody else who works with your code. Moreover, it is extremely easy
to do the right thing and use the standard C++ 11 infrastructure for error codes, and
a worked example follows below.

The second reason is that if everybody goes off and locally defines their own custom error
code system, you multiply significantly the number of `expected<T, E>` permutations
which the compiler has to deal with. That means slower compile and link times, just
because you couldn't be bothered to use the standard library's infrastructure for error
codes. You also force programmers coming later to your code to deal with a multitude
of local error code domains which may or may not mean the same thing. Expect a multiplication of lots of
little switch statements mapping one small domain of error code to another, all of which
must be maintained and parsed by programmers coming later to your codebase. The growing
maintenance burden over time is obvious, and a further worked example follows below.

The third reason is that the C++ 11 standard library already provides an enum of the
most common error codes for you so you don't feel like going off and reinventing
the wheel. It's called <a href="http://en.cppreference.com/w/cpp/error/errc">`std::errc`</a>
and it has the following contents:

~~~{.cpp}
#include <system_error>  // header to bring in this enum

namespace std
{
  enum class errc
  {
    address_family_not_supported        = EAFNOSUPPORT,
    address_in_use                      = EADDRINUSE,
    address_not_available               = EADDRNOTAVAIL,
    already_connected                   = EISCONN,
    argument_list_too_long              = E2BIG,
    argument_out_of_domain              = EDOM,
    bad_address                         = EFAULT,
    bad_file_descriptor                 = EBADF,
    bad_message                         = EBADMSG,
    broken_pipe                         = EPIPE,
    connection_aborted                  = ECONNABORTED,
    connection_already_in_progress      = EALREADY,
    connection_refused                  = ECONNREFUSED,
    connection_reset                    = ECONNRESET,
    cross_device_link                   = EXDEV,
    destination_address_required        = EDESTADDRREQ,
    device_or_resource_busy             = EBUSY,
    directory_not_empty                 = ENOTEMPTY,
    executable_format_error             = ENOEXEC,
    file_exists                         = EEXIST,
    file_too_large                      = EFBIG,
    filename_too_long                   = ENAMETOOLONG,
    function_not_supported              = ENOSYS,
    host_unreachable                    = EHOSTUNREACH,
    identifier_removed                  = EIDRM,
    illegal_byte_sequence               = EILSEQ,
    inappropriate_io_control_operation  = ENOTTY,
    interrupted                         = EINTR,
    invalid_argument                    = EINVAL,
    invalid_seek                        = ESPIPE,
    io_error                            = EIO,
    is_a_directory                      = EISDIR,
    message_size                        = EMSGSIZE,
    network_down                        = ENETDOWN,
    network_reset                       = ENETRESET,
    network_unreachable                 = ENETUNREACH,
    no_buffer_space                     = ENOBUFS,
    no_child_process                    = ECHILD,
    no_link                             = ENOLINK,
    no_lock_available                   = ENOLCK,
    no_message_available                = ENODATA,
    no_message                          = ENOMSG,
    no_protocol_option                  = ENOPROTOOPT,
    no_space_on_device                  = ENOSPC,
    no_stream_resources                 = ENOSR,
    no_such_device_or_address           = ENXIO,
    no_such_device                      = ENODEV,
    no_such_file_or_directory           = ENOENT,
    no_such_process                     = ESRCH,
    not_a_directory                     = ENOTDIR,
    not_a_socket                        = ENOTSOCK,
    not_a_stream                        = ENOSTR,
    not_connected                       = ENOTCONN,
    not_enough_memory                   = ENOMEM,
    not_supported                       = ENOTSUP,
    operation_canceled                  = ECANCELED,
    operation_in_progress               = EINPROGRESS,
    operation_not_permitted             = EPERM,
    operation_not_supported             = EOPNOTSUPP,
    operation_would_block               = EWOULDBLOCK,
    owner_dead                          = EOWNERDEAD,
    permission_denied                   = EACCES,
    protocol_error                      = EPROTO,
    protocol_not_supported              = EPROTONOSUPPORT,
    read_only_file_system               = EROFS,
    resource_deadlock_would_occur       = EDEADLK,
    resource_unavailable_try_again      = EAGAIN,
    result_out_of_range                 = ERANGE,
    state_not_recoverable               = ENOTRECOVERABLE,
    stream_timeout                      = ETIME,
    text_file_busy                      = ETXTBSY,
    timed_out                           = ETIMEDOUT,
    too_many_files_open_in_system       = ENFILE,
    too_many_files_open                 = EMFILE,
    too_many_links                      = EMLINK,
    too_many_symbolic_link_levels       = ELOOP,
    value_too_large                     = EOVERFLOW,
    wrong_protocol_type                 = EPROTOTYPE
  };
}
~~~

As you will note, these are the standard POSIX error codes, and most of the time you'll find that
whatever custom error code domain you are about to write can be adequately covered by `std::errc`.
In fact, let's try it:

~~~{.cpp}
// Mathematical "errors" we want to catch
using MathError = std::error_code;
static constexpr MathError DivisionByZero = std::errc::result_out_of_range;
static constexpr MathError NegativeLogarithm = std::errc::argument_out_of_domain;
static constexpr MathError NegativeSquareRoot = std::errc::argument_out_of_domain;  

using MathResult = outcome::expected<double, MathError>;
~~~

Anything which can "speak" `std::error_code` can now work perfectly with your error
code system because you are using a standard error code domain (i.e. the POSIX error
code domain).

But let's say you really, really wanted to have your own custom error
code scheme, this is how you tell C++ 11's standard error code infrastructure about
your custom error code domain:

\snippet error_code_registration.cpp error_code_registration

This might look like an awful lot of extra boilerplate, but look at the advantages:
1. Any code which can speak `std::error_code` can now work with errors from your
code, AND without being recompiled.
2. `std::system_error` can now wrap your custom error codes seamlessly, allowing
your custom error code to be converted into a C++ exception *and back out again*
without losing information.
3. `std::error_code` knows how to print itself, and will print your custom error
code without extra work from you. As usually you'd need to define a print routine
for any custom error code you'd write anyway, there is actually very little extra
boilerplate here.
4. If you implement the `default_error_condition()` override, you can allow code
exclusively written to understand `std::errc` alone to examine your custom error
code domain for equivalence to the standard error conditions, AND without being
recompiled.

So to sum up, if you are going to deploy `expected<T, E>` into your C++ codebase,
I **urge** you do not use unrestricted `expected<T, E>` because that will tempt
people into using custom error enums as type `E` which I've hopefully proven by
now is a bad idea. Instead *restrict* `expected<T, E>` to a hard coded error type
using something like:

~~~{.cpp}
namespace my_codes_namespace
{
  template<class T> using result = expected<T, std::error_code>;
  
  // Custom error code enum
  enum class MathError {
    DivisionByZero,
    NegativeLogarithm,
    NegativeSquareRoot
  };
  ... boilerplate to tell error_code about MathError ...
  
  template<class T> inline result<T> make_result(T &&v)
  {
    return make_expected(std::forward<T>(v));
  }
  inline unexpected_type<std::error_code> make_error(std::error_code ec)
  {
    return make_unexpected(ec);
  }
}
~~~

Now instead of directly calling Expected's factory functions, simply return all
values from your functions using `make_result()`. Returning a value now becomes:

~~~{.cpp}
result<int> foo()
{
  return make_result(5);
}
~~~

Returning an error now becomes:

~~~{.cpp}
result<int> foo()
{
  return make_error(MathError::DivisionByZero);
}
~~~

... and note that you can feed `make_error()` any custom error code enum understood
by `std::error_code`.

<hr><br>

\section expected_boilerplate Unrestricted use of expected<T, E> means typing more boilerplate

If you weren't convinced by the previous section, let's look at another problem which
unrestricted use of Expected has: the quantity of boilerplate it makes you write.

\snippet expected_try1.cpp expected_try1

The example is contrived for sure, but it shows the problem of having lots of local
custom error code domains. In the above example, `MathError2` has a different assignment
of integer values to `MathError1`, but they could simply be different error code enums.
As is common in any code base of any size, one layer of functions (`div10mul3()`) will call into an
inner layer of more basic functions (`div()`) and will need to pass back out any errors
encountered.

There are two things to note in this example. The first is that due to the error code
domains being different, you need to convert error codes using a switch statement. The
second is that on bad access, Expected throws a templated exception type with the type `E` as the
template parameter. I can tell you that it is far too easy in the real world to accidentally
mistype or forget to update the type caught in the catch statement leading to unintentional
bugs which are quite tricky to track down.

Again, restricting `expected<T, E>` to `E =  std::error_code` makes the code much more
maintainable and easy to parse by humans:

\snippet expected_try2.cpp expected_try2

You'll note the use of the convenience macro `BOOST_OUTCOME_TRY(var, expr)` which provides
some of the `try` keyword in Swift or Rust. The try operation evaluates the expression and if
the result returned is an unexpected value, it immediately returns from the current function
with the same unexpected value - therefore your type `E` needs to be the same. If it is an
expected value, that value is *unwrapped* and returned as the result from the try operation.

Unlike the `try` keyword, the macro is not an expression so you can't write statements like
`if(BOOST_OUTCOME_TRY(var, expr))` as you can in Rust or Swift, this is due to a limitation
of the C++ language (you can't return from functions in an expression). What you can do is to
initialise a variable `var` on the stack to the unwrapped return value from the expression,
so you might write:

~~~{.cpp}
expected<std::string, std::error_code> somefunc();
...
expected<int, std::error_code> someotherfunc()
{
  // If somefunc() returns an E, immediately return an
  // expected<int, std::error_code> with the same E
  // as if return make_unexpected(somefunc().error());
  BOOST_OUTCOME_TRY(v, somefunc());
  // ... else unpack the T into v as if
  // std::string v(std::move(somefunc().value());
  return v.empty() ? 0 : v.size();
}
~~~

<hr><br>

\section error_code_extended Outcome's extended std::error_code

A lot of people find `std::error_code` too constraining and value their custom error types
precisely because they can carry *payload* e.g. a custom string describing exactly the cause
of the error, or maybe a backtrace of the exact offending call sequence leading to the error.
They therefore reject the restriction to `std::error_code` as unsuitable for their use case.

Outcome provides an \ref boost::outcome::v1_xxx::error_code_extended "error_code_extended"
refinement of `std::error_code` for exactly this situation. `error_code_extended` inherits publicly from `std::error_code`,
adding two new member functions: `extended_message()` and `backtrace()`. These *may* provide
additional information about the error code like any `what()` message from the C++ exception
the error code was constructed from (if any), or the stack backtrace of the point at which the
`error_code_extended` was constructed.

~~~{.cpp}
class error_code_extended : public std::error_code
{
public:
  error_code_extended();
  error_code_extended(int ec, const std::error_category &cat, const char *msg = nullptr, unsigned code1 = 0, unsigned code2 = 0, bool backtrace = false);
  template <class ErrorCodeEnum, typename = typename std::enable_if<std::is_error_code_enum<ErrorCodeEnum>::value>::type>
    error_code_extended(ErrorCodeEnum e);
  explicit error_code_extended(const std::error_code &e, const char *msg = nullptr, unsigned code1 = 0, unsigned code2 = 0, bool backtrace = false);
  explicit error_code_extended(std::error_code &&e, const char *msg = nullptr, unsigned code1 = 0, unsigned code2 = 0, bool backtrace = false);
  void assign(int ec, const std::error_category &cat, const char *msg = nullptr, unsigned code1 = 0, unsigned code2 = 0, bool backtrace = false);
  void clear();
  
  // New member functions

  // Fill a char buffer with the extended message, retrieving the two extended unsigned integer codes
  size_t extended_message(char *buffer, size_t len, unsigned &code1, unsigned &code2) const noexcept;

  // Return an array of strings describing the stack at the time of construction. MUST call free() on this returned pointer.
  char **backtrace() const noexcept;
};

// Prints the extended error code, including any extended information if available
inline std::ostream &operator<<(std::ostream &s, const error_code_extended &ec);
~~~

`error_code_extended` is completely API compatible with `std::error_code` and all its
member functions can be used the same way. You can supply a `std::error_code` to an
extended error code, or else construct an extended error code the same way you would a
STL error code. You should note that it is **always safe** to slice `error_code_extended`
into an `std::error_code`, so you can safely feed `error_code_extended` to anything
consuming a `std::error_code`.

The main big additions are obviously the ability to add a custom string message to an extended
error code, this allows the preservation of the original `what()` message when converting a
thrown exception into an extended error code. You can also add two arbitrary unsigned integer
codes and most interestingly, a backtrace of the stack at the point of construction. The extended message and backtrace can be later
fetched using the new member functions, though note that the storage for these is kept in a
statically allocated threadsafe ring buffer and so may vanish at some arbitrary later point
when the storage gets recycled. If this happens, `extended_message()` will return zero characters
written and `backtrace()` will return a null pointer.

Because the storage for the extended information may be recycled at any arbitrary future
point, you ought to make sure that you copy the extended information as soon as possible
after the `error_code_extended` is constructed. In other words, don't store `error_code_extended`
as-is into say a vector, instead extract the information into a custom struct.

\note Construction of an extended error code with extended message or codes takes a maximum of
a microsecond on recent hardware due to an atomic pointer increment. Constructing an extended
error code with backtrace takes a maximum of about 35 microseconds on a recent Ivy Bridge Intel CPU.
**No memory allocation** is ever performed when constructing an extended error code, latency
is always predictable.

<hr><br>

\section outcome_rationale Where Outcome's outcome<T>, result<T> and option<T> come from

Hopefully by now you are persuaded to always *restrict* your use of `expected<T, E>` to
one of:

~~~{.cpp}
template<class T> using result = outcome::expected<T, std::error_code>;
using bad_result_access = outcome::bad_expected_access<std::error_code>;
~~~

... or ...

~~~{.cpp}
template<class T> using result = outcome::expected<T, std::exception_ptr>;
using bad_result_access = outcome::bad_expected_access<std::exception_ptr>;
~~~

If you've been convinced, then you'll be glad that Outcome provides additional
refinements of `expected<T, E>` designed to make your programming life even easier again.
As a rough **semantic** map onto `optional<T>`, `variant<...>` and
`expected<T, E>`:

<pre>
template<class T> using option = std::optional<T>;

template<class T> using result = std::optional<
  std::experimental::expected<
    T,
    error_code_extended
  >
>;

template<class T> using outcome = std::optional<
  std::experimental::expected<
    T,
    std::variant<
      error_code_extended,
      std::exception_ptr
    >
  >
>;
</pre>

So Outcome's `outcome<T>`, `result<T>` and `option<T>` assume the error type is hard coded
to the C++ 11 standard error transport infrastructure, and because they hard code this they
can make a series of optimisations both at runtime and for you the programmer during
coding which an `expected<T, E>` implementation can not. In Outcome's refinements,
an *empty* transport is empty, a *valued* transport contains a `T`, an *errored* transport
contains an `error_code_extended` and an *excepted* transport contains a `std::exception_ptr`.
- `.value()` on an errored transport directly throws `std::system_error` with the error code
instead of throwing a wrapper type.
- `.value()` on an excepted transport directly rethrows the exception pointer instead of
throwing a wrapper type.
- Implicit conversion is permitted for any less representative form into any more
representative form, so `option<T>` auto converts to a `result<T>` preserving exact contents.
This turns out to be very useful in large C++ codebases where the lowest layers tend
to be written using `option<T>` and `result<T>`, whilst highest layers tend to be written
using `outcome<T>` and C++ exception throws.


todo
