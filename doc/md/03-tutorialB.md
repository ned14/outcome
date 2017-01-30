# Tutorial part B: Don't use expected<T, E>!
\anchor tutorial_whynot

[TOC]

Outcome provides a number of utility classes useful for ultra lightweight and constant time error
handling in C++ 14 and later. One of these is \ref outcome_expected_reference "a highly conforming expected<T, E> implementation"
which is currently before the ISO C++ standards Library Evolution Working Group for
standardisation. `expected<T, E>` is a very flexible
and generic utility class allowing perhaps too much unwise customisation in the hands
of its users, so Outcome also provides a family of more hard coded and deliberately
less flexible refinements to `expected<T, E>` called `outcome<T>` and `result<T>`
the use of which ought to generate more maintainable code bases and require less
typing of boilerplate by the programmer.

This tutorial is therefore split into three parts:
1. The first part (\ref tutorial_expected "part A") provides a broad overview of error handling in
C++ in general and how the `expected<T, E>` proposed for standardisation will contribute
to that big menu of error handling design patterns available to the C++ programmer.
This part isn't relevant to Outcome the library, but places it in context.
2. The second part (part B, this part) describes why you probably ought
to not use unrestricted `expected<T, E>` in any real world code base and why
you ought to use the refinements of `outcome<T>` or `result<T>` instead.
3. The third part (\ref tutorial_outcome "part C") walks you through using Outcome's refinements `outcome<T>`
and `result<T>`, plus its `extended_error_code`. Usage is very similar to Expected,
but with less typing and more convenient extensions.

<hr><br>

This part of the tutorial is a bit unusual as it's a sort of polemic against what most
consider to be one of the best parts of `expected<T, E>`: that you can and should choose
any arbitrary type `E` on a case by case basis as is conventional in other languages such
as Rust or Swift. Hopefully by the end of this part you will be persuaded to always
*restrict* your use of `expected<T, E>` in C++ to one of:

~~~{.cpp}
template<class T> using result = outcome::expected<T, std::error_code>;
using bad_result_access = outcome::bad_expected_access<std::error_code>;
~~~

... or ...

~~~{.cpp}
template<class T> using result = outcome::expected<T, std::exception_ptr>;
using bad_result_access = outcome::bad_expected_access<std::exception_ptr>;
~~~

... where the latter is a superset of the former, because you can wrap any arbitrary
`std::error_code` instance into a `std::exception_ptr` instance using the C++ 11 STL
error code wrapping C++ exception type `std::system_error`:

~~~{.cpp}
std::error_code ec;
std::exception_ptr e = std::make_exception_ptr(std::system_error(ec));

// OR

std::exception_ptr e = std::make_exception_ptr(std::system_error(ec, "custom what() string"));
~~~

The reason why this polemic is needed is because during the many pre-reviews
of Outcome on Boost, SG14 and Reddit, it became clear that the choice that Outcome
made to hard code the error type to error codes or exception pointers in Outcome's
refinements of `outcome<T>` and `result<T>` was not at all clear to most people
interested in using `expected<T, E>`. It became clear that the rationale would need
to be spelled out, and that is this part B of the tutorial.

As with all polemical texts, you may find yourself disagreeing with everything in this
section and that therefore you will think the hardcoded `E` refinements of `outcome<T>` and
`result<T>` will be of no use to you. Two things should be noted. The first is that the
hard coding allows the refinements to do a fair bit of tedious boilerplate for you,
so the refinements are undoubtedly less tedious to program with if you accept the hard coding.
The second is that even if you profoundly disagree with everything in this section,
there is no obligation to use anything in Outcome outside what was already described
in part A and in \ref outcome_expected_reference "the reference API page for Outcome's Expected implementation".
Outcome's Expected implementation is high quality, and should be competitive with any
future STL implementation of `expected<T, E>`.

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
code domain). And for reference, the C++ 11 STL ships with these ready to go predefined error
categories and error enumerations:

<dl>
  <dt><a href="http://en.cppreference.com/w/cpp/error/generic_category">`std::generic_category()`</a>
  with corresponding enumeration <a href="http://en.cppreference.com/w/cpp/error/errc">`std::errc`</a></dt>
  <dd>The POSIX standard error code domain as retrieved by the `errno` variable after calling
  a POSIX function.</dd>
  <dt><a href="http://en.cppreference.com/w/cpp/error/system_category">`std::system_category()`</a>
  with a platform specific enumeration</dt>
  <dd>The "usual" error code domain for your particular host OS, so on Linux/FreeBSD/OS X/Android
  this is the exact same domain as `generic_category()`. On Microsoft Windows this is the error code
  domain as returned by the Win32 `GetLastError()` function. Other platforms can vary.</dd>
  <dt><a href="http://en.cppreference.com/w/cpp/io/iostream_category">`std::iostream_category()`</a>
  with corresponding enumeration <a href="http://en.cppreference.com/w/cpp/io/io_errc">`std::io_errc`</a></dt>
  <dd>The STL iostreams error code domain.</dd>
  <dt><a href="http://en.cppreference.com/w/cpp/thread/future/future_category">`std::future_category()`</a>
  with corresponding enumeration <a href="http://en.cppreference.com/w/cpp/thread/future_errc">`std::future_errc`</a></dt>
  <dd>The STL future-promise error code domain.</dd>
</dl>

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

\section error_codes_insufficient std::error_code CAN replace your custom error types

The final reason that people say they need to use custom error types with Expected is because
they need the custom error type to carry custom *payload* such as data directly relating to the error
which occurred, and because `std::error_code` can only
carry a situation-unspecific integer code and category, that it is therefore unsuited for
their particular use case. Let's have a look at a typical custom error type carrying payload:

\snippet expected_payload1.cpp expected_payload1

So here we have a file open function which opens some path returning a reference counted handle
to the open file and if that fails, it will return
a custom error type with the path of the file which failed as its payload. As much as this is
a simple example where the payload carried is just a pointer, you could actually transport any
arbitrary data as your payload such as a stack backtrace etc.

The thing is, `std::error_code` is exactly the right solution to this problem. A lot of people
hung up on their custom error types aren't thinking the problem through using STL fundamentals
as building blocks with which to compose better and more elegant solutions:

\snippet expected_payload2.cpp expected_payload2

As you can now see, we still have a custom error type, but it's now a `std::error_code` combined
with payload. A big improvement with this design is that the errors returned by the system calls
are now preserved perfectly rather than being converted into some generic "i/o failed" error code,
and in fact because we use `system_category` for the error codes returned by the host OS, we lose
no information whatsoever about the original error.
The failure to allocate memory is now returned using the standard error code for that event, and
the only error condition which is truly bespoke `format_corrupt` gets its own error code category.

As much as the second example is much better design, it still has a custom error type the use of which
precludes using convenience macros like `BOOST_OUTCOME_TRY` across disjoint domains of error.
If that's acceptable to you, then work away, but be aware that Outcome's refinements of `outcome<T>`
and `result<T>` don't use a `std::error_code`, they instead use an `outcome::error_code_extended`
which extends `std::error_code` with most of the common payloads that most people would want to
transmit with their errors.

`error_code_extended` won't of course cover truly bespoke needs, and if you are finding your
custom error type is getting richly featured enough to require
<a href="http://en.cppreference.com/w/cpp/language/destructor#Trivial_destructor">a non-trivial destructor</a>
then you should be aware that `expected<T, E>` must always use the lowest common denominator
between `T` and `E`, so if your `E` has a non-trivial destructor, so will all `expected<T, E>`.
This can mean that compilers will "blow out" code where such `expected<T, E>` is used i.e.
generate a lot of code bloat. Again, if that's acceptable to you for your use case, then work away.
But if that worries or bothers you, then you had best stick to trivial custom error types or
better still, use Outcome's refinements of `outcome<T>` and `result<T>` which remove that
choice entirely and give you in return a less boilerplate and more powerful programming
experience. That is exactly the subject of Part C of this tutorial, next.
