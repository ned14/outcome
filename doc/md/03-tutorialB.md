# Expected<T, E> in Practice
\anchor tutorial_whynot

[TOC]

Outcome's design rationale and tutorial is split into three parts:
1. The \ref tutorial_expected "first part" provides a broad overview of error handling in
C++ in general and how the `expected<T, E>` proposed for standardisation will contribute
to that big menu of error handling design patterns available to the C++ programmer.
This part places Outcome the library in context.
2. The second part (this part) describes some design anti-patterns common
with inexperienced usage of `expected<T, E>` in C++ which you ought to avoid.
It shows you how to use `expected<T, E>` in a way which integrates well with the
C++ 11 STL's standard error code facilities `std::error_code` and `std::error_category`.
3. The \ref tutorial_outcome "third part" walks you through using Outcome's
`expected<T, E>` refinements `outcome<T>` and `result<T>`, plus its `extended_error_code`.
Usage is very similar to Expected, but with less typing, less runtime overhead and
more convenient extensions.

<hr><br>

\section expected_simple_e_is_bad Simple E types in expected<T, E> is bad practice in C++

Most people very keen on Expected entering C++ will be coming from a Swift or especially
Rust background where when you use `Result<T, E>`, you invariably supply a bespoke enum of
error codes for type `E` like this fragment of Rust:

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
code system, you force programmers coming later to your code to deal with a multitude
of local error code domains which may or may not mean the same thing. Expect a multiplication of lots of
little switch statements mapping one small domain of error code to another, all of which
must be maintained and parsed by programmers coming later to your codebase. The growing
maintenance burden over time is obvious, and a further worked example follows below.

The third reason is that the C++ 11 standard library already provides an enum of the
most common error codes for you so you don't feel like going off and reinventing
the wheel. It's called <a href="http://en.cppreference.com/w/cpp/error/errc">`std::errc`</a>
brought in by <tt>\#include <system_error></tt> and as you'll see, it contains the standard
POSIX error codes, and most of the time you'll find that whatever custom error code
domain you are about to write can be adequately covered by `std::errc`.
In fact, let's try it:

~~~{.cpp}
// Mathematical "errors" we want to catch
using MathError = std::error_code;
static const MathError DivisionByZero = std::make_error_code(std::errc::result_out_of_range);
static const MathError NegativeLogarithm = std::make_error_code(std::errc::argument_out_of_domain);
static const MathError NegativeSquareRoot = std::make_error_code(std::errc::argument_out_of_domain);  

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

Because `std::error_code` is the C++ 11 standard way of doing error codes, `expected<T, E>`
defaults `E` to `std::error_code` both in the proposed standard and in Outcome's implementation.

The big problem with directly using `std::error_code` as `E` is the loss of type safety because
`std::error_code` will accept any input implicitly convertible. So you can write this code
and the compiler won't complain:

~~~{.cpp}
// Not a valid MathError, yet the compiler won't stop you doing this
return MathResult(make_unexpected(std::make_error_code(std::errc::executable_format_error)));
~~~

As is usually the case in C++, fixing this is straightforward but requires typing boilerplate
to tell the C++ STL about your custom error type. As how to do this is not well documented [1],
next follows a very quick howto guide.

[1]: The only documentation I'm aware of is the quite old guide by Chris Kohlhoff, founder of
ASIO and the Networking TS:
- http://blog.think-async.com/2010/04/system-error-support-in-c0x-part-1.html
- http://blog.think-async.com/2010/04/system-error-support-in-c0x-part-2.html
- http://blog.think-async.com/2010/04/system-error-support-in-c0x-part-3.html
- http://blog.think-async.com/2010/04/system-error-support-in-c0x-part-4.html
- http://blog.think-async.com/2010/04/system-error-support-in-c0x-part-5.html


<hr><br>

\section custom_error_codes Marking up your custom error code domain so the STL understands it

Let's get into it! This is how you tell C++ 11's standard error code infrastructure about
your custom `expected<T, E>` error code type so it works well with anything speaking
`std::error_code`:

\snippet error_code_registration.cpp error_code_registration

This might look like a lot of extra boilerplate over simply using your custom
error code enum directly, but look at the advantages:
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
5. Type safety is preserved, you cannot construct a `MathError` from anything but
the officially sanctioned enums in `MathError`.


<hr><br>

\section expected_tension The tension between type safety and convenient programming

Let's look at another problem which naive direct usage of custom error code enums
has: the quantity of boilerplate it makes you write.

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

Let's try a different approach. What we do now is to hard code
our use of `expected<T, E>` to `E = std::error_code` which is made easy for us by the fact
it's already been defaulted to that for us by Expected's definition:

\snippet expected_try2.cpp expected_try2

This eliminates the fragile switch statements converting between error code domains in
favour of a information loss free transmission. The cost is once again a loss of type safety
because a function might return an error code it should never be able to return and the
compiler will not complain.

Mashing together both approaches we can solve the problem of type safety by making `MathError2`
explicitly constructible from `MathError1`:

\snippet expected_try3.cpp expected_try3

This approach means that `MathError2` can contain an error code which has nothing to do with
`MathError2`'s enumerations. This may be confusing initially, but you need to consider the
compile time and run time separately - this approach comes with compile time safety but without
run time safety.

So which approach should you use in your code? It depends on the specific application. If your code base
needs to tightly specify all the exact errors which can occur in some function call stack rather similarly
to <a href="http://en.cppreference.com/w/cpp/language/except_spec">dynamic C++ exception specifications</a>,
then the third example is the form you should use. If your code base is mostly a systems
abstraction layer where errors from the OS ought to be returned exactly as from the OS,
you should leave `E` default to `std::error_code` and return `std::system_category()` error
codes from `errno` or `GetLastError()` as appropriate. If you don't care and/or you're in a rush,
`E = std::error_code` and returning some enumeration from `std::errc` will get you working code
the quickest (and be aware that Outcome's refinements of `expected<T, E>`, `outcome<T>` and `result<T>`
hard code the `E` to an enhanced `error_code_extended` and will save you typing a fair bit of boilerplate).
As the latter two use patterns may be unclear, a worked example follows in the next section.

\subsection try_operation The TRY operation

You may have noted the earlier use of the convenience macro `BOOST_OUTCOME_TRY(var, expr)` which provides
some of the `try` operator in Swift or Rust. The TRY operation evaluates the expression and if
the result returned is an unexpected value, it immediately returns from the current function
with the same unexpected value - therefore your type `E` needs to be identical. If it is an
expected value, that value is *unwrapped* and returned as the result from the TRY operation.

Unlike the `try` operator, the macro is not an expression so you can't write statements like
`if(BOOST_OUTCOME_TRY(var, expr))` as you can in Rust or Swift, this is due to a limitation
of the C++ language (you can't return from functions in an expression) [1]. What you can do is to
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

\note If you wish to `try` a function call but not unwrap any returned value, use the
`BOOST_OUTCOME_TRYV(expr)` macro instead.

[1]: GCC and clang provide a proprietary extension to the language letting you encode a sequence
of statements into an expression, so on those compilers only a `BOOST_OUTCOME_TRYX(expr)` macro
behaves exactly like the `try` operator in Swift or Rust. The `BOOST_OUTCOME_TRYX` macro is not
defined on compilers not supporting that proprietary extension.


<hr><br>

\section expected_payload Sending payload with your custom error type

One of the most common error types people write with `expected<T, E>` is `expected<T, std::string>`
so they can return some arbitrary string explaining the error. This is the simplest example
of sending runtime *payload* with the returned error explaining the error.
Let's have a look at a typical naive custom error type carrying payload:

\snippet expected_payload1.cpp expected_payload1

So here we have a file open function which opens some path returning a reference counted handle
to the open file and if that fails, it will return
a custom error type with the path of the file which failed as its payload. As much as this is
a simple example where the payload carried is just a pointer, you could actually transport any
arbitrary data as your payload such as a stack backtrace etc.

Earlier we subclassed `std::error_code` to add in type safety to prevent the accidental return
of errors not permitted by a function's specification. Here we take yet another approach, this
time *embedding* a `std::error_code` inside our custom error type along with payload:

\snippet expected_payload2.cpp expected_payload2

A nice consequence of this design is that the errors returned by the system calls
are preserved perfectly rather than being converted into some generic "i/o failed" error code,
and because we use `system_category` for the error codes returned by the host OS, we lose
no information whatsoever about the original error.
The failure to allocate memory is now returned using the standard error condition for that event, and
the only error code which is truly bespoke `format_corrupt` gets its own custom error code category.

As much as the second example is much better design, it still has a custom error type the use of which
precludes using convenience macros like `BOOST_OUTCOME_TRY` across disjoint domains of error.
If that's acceptable to you, then work away, but be aware that Outcome's refinements of `outcome<T>`
and `result<T>` don't use a `std::error_code`, they instead use an `outcome::error_code_extended`
which extends `std::error_code` with most of the common payloads that most people would want to
transmit along with their errors, such as a custom string.

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
experience. That is exactly the subject of the third and final part of this tutorial, next.
