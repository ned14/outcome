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
maintenance burden over time is obvious.

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

If you have found this explanation persuasive so far, you can guess where Outcome's more
hard coded and less flexible refinements to `expected<T, E>` are going.

<hr><br>

\section expected_boilerplate Using expected<T, E> means typing more boilerplate

todo

<hr><br>

\section outcome_rationale Where Outcome's outcome<T>, result<T> and option<T> come from

todo
