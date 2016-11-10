<center><table border="0">
<tr>
<td align="center"> <a href="http://my.cdash.org/index.php?project=Boost.Outcome">CTest summary</a><br/><a href="http://my.cdash.org/index.php?project=Boost.Outcome">dashboard</a> </td>
<td align="center"> <a href="https://travis-ci.org/ned14/boost.outcome">Linux CI:</a><img src="https://travis-ci.org/ned14/boost.outcome.svg?branch=master"/> </td>
<td align="center"> <a href="https://ci.appveyor.com/project/ned14/boost-outcome/branch/master">Windows CI:</a><img src="https://ci.appveyor.com/api/projects/status/roe4dacos4gnlu66/branch/master?svg=true"/> </td>
<td align="center"> <a href="https://coveralls.io/r/ned14/boost.outcome?branch=master">Coverage:</a><img src="https://coveralls.io/repos/ned14/boost.outcome/badge.svg?branch=master"/> </td>
</tr>
</table></center>

\tableofcontents

\section description Description

This is the proposed Boost.Outcome library, a Boost C++ 14 library providing
a factory and family of policy driven lightweight monadic value-or-error transports with
the convenience simple specialisations of `outcome<T>`, `result<T>` and `option<T>`.
Its main intended usage is as an ultra light weight error handling framework,
providing a more expressive and type safe alternative to error code integers
or enums, yet much lower overhead than exception throws. Unlike alternatives
such as `expected<T, E>`, it works perfectly with exceptions and RTTI disabled and
thus is suitable for low-latency/games/finance/SG14 users. One could view Outcome as a
"hard coded", less generic `expected<T, E>` intended mainly as a minimum overhead
universal outcome handling framework for C++, hence being named "Outcome".

If you are familiar with Swift's error code throws or Rust's `Result<T>` and `Option<T>`,
you will find almost identical semantics in the transports provided here.
One can therefore write systems programming code using these transports in C++
in the same design pattern as when writing in Rust or Swift, and with a similarly
low runtime overhead. Outcome even has a `try` macro doing the same thing as in
Rust and Swift!

\section prerequisites Prerequisites and Installation

Boost.Outcome is a header only library known to work on these compilers or better:
- GCC 5.0
- clang 3.7
- VS2015 Update 2
- clang 3.7 with Microsoft Codegen ("winclang")

Its sole mandatory dependency is on https://github.com/ned14/boost-lite, a minimal
emulation of Boost for C++ 14. A copy is embedded internally so a copy of Boost is
**not** required to use this library. You can simply drop Outcome into your project
and go, including Outcome using one of these depending on how you install Outcome:

- \code #include <boost/outcome.hpp> \endcode
- \code #include "boost.outcome/include/boost/outcome.hpp" \endcode

Each commit is tested by Travis and Appveyor. A nightly cronjob figures out which
latest commit all tests passed for and pushes a distribution to the following
package repositories:

\subsection windows Installing on Windows

If you are using VS15 or better it comes with VCPkg, a package manager. Open
a Developer Tools prompt and type:

`vcpkg install boost.outcome`

Once installed it is available for usage in any Visual Studio project.

\subsection linux Installing on Ubuntu/Debian

<pre>add-apt-repository ppa:ned14/boost.outcome
apt-get install libboost-outcome-dev</pre>

\subsection osx Installing on OS X

Assuming you have <a href="http://brew.sh/">homebrew</a> installed, then:

<pre>brew tap ned14/tap
brew install boost.outcome</pre>

\subsection source Installing via source archive

Visit https://dedi4.nedprod.com/static/files/ and download the latest boost.outcome
tarball. Tarballs are only uploaded if everything built and all tests passed.

\subsection repo Installing via git subrepository

`git submodule add https://github.com/ned14/boost.outcome`

The master branch is automatically set to whichever was the last commit on develop
branch to pass all unit tests.

\section support Support

<a href="https://stackoverflow.com/">StackOverflow</a> with the boost-outcome tag is the preferred place to ask questions on usage.

If you have a problem, please review the FAQ and the wiki. Searching
<a href="https://github.com/ned14/boost.outcome/issues">the issues</a>
for your problem is also a good idea. If you are encountering what you
think is a bug, please open an issue.


\section cpp_error_handling_history Quick history of error handling design patterns from C++ 98 to C++ 17

\subsection c-style C style error handling: integer returns

Historically C++ 98 code has taken one of two design patterns when returning
errors from functions. This pattern is taken from C, and indeed is pure C:

\code
struct handle
{
  int fd;
  ...
};
enum errors
{
  SUCCESS=0,
  NOMEM,
  NOTFOUND,
  ...
};
...
int openfile(struct handle **outh, const char *path)
{
  *outh = malloc(sizeof(struct handle));
  if(!*outh)
    return NOMEM;
  (*outh)->fd = open(path, O_RDONLY);
  if((*outh)->fd == -1)
  {
    free(*outh);
    *outh = NULL;
    return NOTFOUND;
  }
  ...
  return SUCCESS;
}
\endcode

Almost certainly anyone reading this has seen this error handling design umpteen
times in their career. Variations on the same pattern are returning the enum type
directly, returning a boolean and using a thread locally stored global variable
such as `errno` and so on.

\subsection cpp98-style C++ 98 style error handling: throwing exceptions

The second C++ 98 design pattern ought to also be very familiar to readers:
\code
// Abstract base class for some handle implementation
struct handle
{
  int fd;
  ...
  virtual ~handle()
  {
    if(fd != -1)
    {
      close(fd);
      fd = -1;
    }
  }
};
class handle_ref;  // Some sort of smart pointer managing a handle *
handle_ref openfile(const char *path)
{
  int fd = open(path, O_RDONLY);
  if(fd == -1)
  {
    throw std::runtime_error("File not found");
  }
  try
  {
    // Could throw std::bad_alloc or any other kind of exception during construction
    return handle_ref(new some_derived_handle_implementation(fd));
  }
  catch(...)
  {
    close(fd);
    throw;
  }
}
\endcode

Experts will quite correctly chafe at the use of `std::runtime_error` to
report a file not found, but nevertheless such a design pattern is very
common in the wild.

\subsection cpp11-style C++ 11 style error handling: error_code and noexcept

C++ 11 brought in two new features to help bridge the gap between the over use of
exception throws to report routine failures and C error handling:
(i) `noexcept` and (ii) the standardisation of
`error_code` from Boost. `noexcept` lets you mark functions with the
guarantee that they shall **never** throw exceptions. This is commonly
described as a feature enabling the compiler and standard library to
use faster algorithms which can assume that operations never need to
undone part way through, however it also enables a whole new way of
writing C++ which we shall call *"islands of exception throw in a sea
of noexcept"* which will be described later.

Both the Boost and C++ 11 `error_code` consists of an integer and
a reference to an `error_category` instance. This allows one to set
a *domain* for an integer error code such that `NOTFOUND` in library A
can have a different integer value to `NOTFOUND` in library B.
Because the reference to the domain of the error code is transported
with the error code,
integer error codes can be propagated *without losing information*
into other code which need have no knowledge whatsover of libraries A nor
B. `error_code` and the other machinery in `<system_error>` lets you
handle errors from unknown libraries via `error_condition` which
lets you inspect unknown third party `error_code`'s for whether they
have semantic equivalence to the standard POSIX errors, and
therefore handle a file-not-found situation based on semantic
equivalence rather than losing information from the original source
by doing an error code conversion. Therefore as with exception types deriving
from `std::exception`, a central error handling routine can understand just
enough of unknown third party error codes to act appropriately.

The C++ 11 standard library makes very limited use of `error_code` for
reporting errors, however the Filesystem TS and Networking TS as indeed
much of Boost uses this error handling design pattern extensively:

\code
// Abstract base class for some handle implementation
struct handle
{
  int fd;
  ...
  virtual ~handle()
  {
    if(fd != -1)
    {
      close(fd);
      fd = -1;
    }
  }
};
class handle_ref;  // Some sort of smart pointer managing a handle *

// Non-throwing overload
handle_ref openfile(const char *path, std::error_code &ec) noexcept
{
  int fd = open(path, O_RDONLY);
  if(fd == -1)
  {
    // Construct an error code in the OS errors domain
    ec = std::error_code(errno, std::system_category());
    return {};
  }
  auto *p = new(std::nothrow) some_derived_handle_implementation(fd, ec);
  if(p == nullptr)
  {
    close(fd);
    // Construct an error code matching the generic OS error equivalent
    // to the ENOMEM error condition
    ec = std::make_error_code(std::errc::not_enough_memory);
    return {};
  }
  if(ec)
  {
    delete p;
    return {};
  }
  return handle_ref(p);
}

// Throwing overload
handle_ref openfile(const char *path)
{
  std::error_code ec;
  handle_ref ret(openfile(path, ec));
  if(ec)
  {
    throw std::system_error(ec);
  }
  return ret;
}
\endcode

This third error handling design pattern has two big advantages:

1. You only pay for what you use, so if you call the non-throwing overload
you are guaranteed by the `noexcept` that execution flow will not unexpectedly
invert. This makes writing correct exception safe code much easier, plus
unpredictable execution times due to exception throws cannot occur. The
compiler can also reduce executable bloat by not generating stack unwind tables
around that call which is useful for some C++ users.
2. It allows one to segment truly exceptional events into exception throws with
stack unwinds and to handle ordinary and common failures in normal forward execution
program logic. This is exactly the error handling model used by the new systems
languages Swift and Rust.


\subsection cpp17-style C++ 17/20 style error handling: optional<T> and expected<T, E>

C++ 17 isn't finished at the time of writing, but we are very sure that at least
<a href="http://en.cppreference.com/w/cpp/utility/optional">`std::optional<T>`</a>
will be in it. It remains to be seen if LEWG's `expected<T, E>` will make it,
if not then most STL implementations will probably ship an implementation as an experimental
and if your STL does not, there is always the reference implementation at https://github.com/viboes/std-make
which ought to work on any C++ 14 compiler.

The following discussion is based on `expected<T, E>` as detailed by
<a href="http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0323r1.pdf">P0323R1</a>
which is the latest LEWG proposal paper at the time of writing (Nov 2016) and indeed
one where `expected<T, E>` was pared down significantly from its original proposal. It
should be noted that C++ may yet end up adopting something quite different, though
given how long `expected<T, E>` has been around by now, and how it is getting to fitting
nicely between `optional<T>` and `variant<T, E>`, it would seem unlikely.
`expected<T, E>` is intended as a strict superset of `optional<T>` with aspects
of <a href="http://en.cppreference.com/w/cpp/utility/variant">`std::variant<T, E>`</a>,
indeed much of LEWG's remaining work on the proposal is on reconciling the small
remaining semantic differences between `expected<T, nullopt_t>` and `optional<T>`.

The original prototype Boost.Expected library was a large and very complex beastie -
I was fortunate to be employed on a contract in 2015 where I saw it deployed at
scale into a large C++ codebase. Indeed, much of what I witnessed there had a big impact in
how Outcome ended up being designed. P0323R1 proposes an enormously simplified
implementation which ought to fix all of the showstopper problems with the original
that I am aware of, and P0323R1's `expected<T, E>` has a huge resemblance to
Outcome in every day usage, which is unintentionally deliberate as the committee have
made most of the changes I also made in Outcome. Outcome still
contributes significant value for low-latency users, as we shall see later.


\subsubsection optional Returning optional<T>

In some programming contexts we don't need to know why an operation failed, only
that it did. Throwing an exception after failing to find a file is a good example
of the kind of failure which is very common and where throwing an exception to
handle that event is excessive and inappropriate. One might therefore design
a routine expected to frequently fail in C++ as:

\code
// Returns true for success and fills \em out with the opened file, else false
bool openfile(handle_ref &out, const char *path) noexcept;
\endcode

Wouldn't it be much nicer though if you didn't force the caller to have to
instantiate a copy of `handle_ref` before each call, not least because such
a requirement messes badly with using `openfile()` in generic template code
and moreover it could be the case that constructing a `handle_ref` is an
atomic operation, and is thus wasted work if the failure to open is very
common? This is where `optional<T>` comes in:

\code
// Returns the opened handle on success, else an empty optional
std::optional<handle_ref> openfile(const char *path) noexcept;
...
auto fh_ = openfile("foo");
if(fh_)
{
  handle_ref fh = std::move(fh_.value());
  fh->read(... etc
}
\endcode

`optional<T>` is pretty boring and unsurprising like any good primitive. It's
also fairly intuitive, almost any C++ programmer will immediately understand
what the code above does from inspection.


\subsubsection expected Returning expected<T, E>

Many familiar with the filesystem will find the above use case of `optional<T>`
unsettling because there are many reasons why one couldn't open a file rather
than merely it was not found. Imagine, for example, that a program is attempting
to open a few thousand files on a networked drive which has broken its connection -
in this case every single failure will take considerable time to return and
there is zero chance *any* file open will ever succeed, so what the user sees
is an apparently hanged program. Far better would be if the `openfile()` function
could return the cause of its failure, and we could then treat all errors which are different
to file-not-found as reason to abort.

Enter LEWG's proposed `expected<T, E>` which can hold either an expected value of
type `T` or an unexpected value of type `E`. Like `variant<T, E>`, `expected<T, E>`
is a discrimated union storing either `T` or `E` in the same storage space, but
unlike the variant, expected treats the `T` as a positive thing (fetchable via a
`.value()`) and `E` as a negative thing (fetchable via a `.error()`). Because
`expected<T, E>` provides a "never empty" guarantee similar to variant,
it currently requires type `E` to be nothrow copy and move constructible and assignable.
Expected is a bit less intuitive to use than optional, but its rules are straightforward:
`expected<T, E>` will greedily and implicitly construct from any type from which a `T` can be constructed,
after which it will hold an instance of `T`. If you wish to construct an `expected<T, E>`
holding an instance of unexpected `E`, you need to feed it an `unexpected<E>` which is
type sugar to indicate you want an instance of `E` implicitly converted into an `expected<T, E>`.
As with everything else in C++ 11 onwards, there is a `make_expected(T)` and a `make_unexpected(E)`
which do any type deduction and conversion for you into the right contents of `expected<T, E>`.

All this sounds a bit complex, but really it's much easier to use. Here is a
non-throwing implementation based on `expected<T, E>`

\code
// Returns the expected opened handle on success, or an unexpected cause of failure
std::expected<handle_ref, std::error_code> openfile(const char *path) noexcept
{
  int fd = open(path, O_RDONLY);
  if(fd == -1)
  {
    return std::make_unexpected(std::error_code(errno, std::system_category());
  }
  std::error_code ec;
  auto *p = new(std::nothrow) some_derived_handle_implementation(fd, ec);
  if(p == nullptr)
  {
    close(fd);
    return std::make_unexpected(std::make_error_code(std::errc::not_enough_memory));
  }
  if(ec)
  {
    delete p;
    return std::make_unexpected(std::move(ec));
  }
  return handle_ref(p);  // expected<> takes implicit conversion from type T
}
...
auto fh_ = openfile("foo");
if(!fh_ && fh_.error() != std::errc::no_such_file_or_directory)
{
  // This is serious, abort
  throw std::system_error(std::move(fh_.error()));
}
else if(fh_)
{
  handle_ref fh = std::move(fh_.value());
  fh->read(... etc
}
\endcode

The prototype Boost.Expected library and the P0323R1 reference library actually
declares `expected<T, E = std::exception_ptr>` as the default despite that P0323R1
specifies `expected<T, E = std::error_condition>` as the default (note: I have no
idea why LEWG would use error condition as a default, such a default would lose
information for users so I have assumed they'll change it to error code soon), so for completeness
let's rewrite the above to match a `E = std::exception_ptr` design instead:

\code
// Returns the expected opened handle on success, or an unexpected cause of failure
std::expected<handle_ref, std::exception_ptr> openfile(const char *path) noexcept
{
  int fd = -1;
  try
  {
    fd = open(path, O_RDONLY);
    if(fd == -1)
    {
      throw std::system_error(std::error_code(errno, std::system_category()));
    }
    return make_handle_ref<some_derived_handle_implementation>(fd);
  }
  catch(...)
  {
    if(fd != -1)
      close(fd);
    return std::make_unexpected(std::current_exception());
  }
}
...
auto fh_ = openfile("foo");
if(!fh_)
{
  try
  {
    std::rethrow_exception(fh_.error());
  }
  catch(const std::system_error &e)
  {
    if(e.code() != std::errc::no_such_file_or_directory)
      rethrow;
  }
  // All other exception types are rethrown
}
else
{
  handle_ref fh = std::move(fh_.value());
  fh->read(... etc
}
\endcode

This is the very first time in this tutorial that we have seen the design pattern
around which Outcome was specifically designed to make easy: *islands of exception
throw in a sea of noexcept*.

\subsubsection sea-of-noexcept "Islands of exception throw in a sea of noexcept"

This design pattern was intended in C++ 11 to be the method by which that large
minority of C++ users who disable RTTI and exceptions entirely could be brought
back into ISO standard C++. The pattern is easy:
1. Every `extern` API in your translation unit is marked `noexcept` and uses a
non-throwing mechanism such as `std::error_code` or `std::expected<T, E>` or
Outcomes to return errors.
2. Code within a translation unit is generally not marked `noexcept`, or indeed
may throw and catch exceptions before returning out of an extern `noexcept` API.
3. Because all `extern` function calls are `noexcept` throughout the entire codebase, the compiler's optimiser 
*ought* to elide emission of stack unwind code and all other exception throw handling
overhead in any sequence of code inside the translation unit *as if* exceptions had
been globally disabled at the command line.
4. Where code inside a translation unit does call something which could throw e.g.
much of the STL, exception handling overhead *ought* to be confined to the containing `try` ...
`catch` **island**.
5. Consumers of your `extern` API need not care how that API is internally implemented
as they shall never see an exception thrown out of that API, and the compiler will
optimise your code which uses that `extern` API in its **sea** of `noexcept` accordingly.


\subsubsection exceptions-are-exceptional "Exceptions are exceptional, errors are not failure"

In addition to the pure "sea of noexcept" for low latency users, there is one other new
error handling design pattern to mention made possible by `expected<T, E>` or especially
Outcomes which combines "sea of noexcept" with exception throws. The idea is that ordinarily
speaking code never throws an exception, and returns all failures anticipated by the programmer
through `expected<T, E>` as an `E`. If however something
very unexpected occurs, an *exceptional* event, we exclusively use exception throws to abort
the current operation entirely. For anyone familiar with Rust, this is **exactly** the Rust
error handling model: `Result<T>` and `Option<T>` return errors expected by the programmer
whereas a stack unwinding panic of the current thread is how exceptional, programmer
unanticipated events are handled.

As you will see later, Outcome makes implementing this error handling design pattern easier
than in Expected, but let's merge our two code examples using Expected above into one
treating expected failures are unexceptional and exceptional failures as thrown exceptions:

\code
// Returns the expected opened handle on success, an error code if an anticipated error,
// throws a system error if an unanticipated exceptional failure
std::expected<handle_ref, std::error_code> openfile(const char *path)
{
  int fd = open(path, O_RDONLY);
  if(fd == -1)
  {
    int code=errno;
    // If a temporary failure, this is an expected unexpected outcome
    if(EINTR==code || EBUSY==code || EISDIR==code || ELOOP==code || ENOENT==code || ENOTDIR==code || EPERM==code || EACCES==code)
      return std::make_unexpected(std::error_code(code, std::system_category());
    // If anything else, it's serious and we should abort
    throw std::system_error(std::error_code(code, std::system_category()));
  }
  try
  {
    return make_handle_ref<some_derived_handle_implementation>(fd);
  }
  catch(...)
  {
    close(fd);
    throw;
  }
}
...
auto fh_ = openfile("foo");
// If !fh_, it's an expected failure we ignored
if(fh_)
{
  handle_ref fh = std::move(fh_.value());
  fh->read(... etc
}
\endcode

This "separation of concerns" pattern has a great aesthetic appeal to most,
including myself. However I must admit that in practice I haven't found myself
using it a great deal because I find writing forwards only exception safe code
much quicker to write correctly first time than exception safe code which correctly
handles arbitrary control flow reversal.


\section introduction Introduction and Design Rationale of Outcome

After that literature review of how C++ has implemented error handling and how code
might implement error handling from C++ 17/20 onwards, one might think that Outcome
and Expected are interchangeable. They do cover substantially similar ground and in
the semantic sense they are the same thing, however where Expected is intended as a
generic fundamental type useful for many things, Outcome is specifically
intended as a universal error handling framework capable of lossless propagation of
all possible kinds of C++ error with the least possible runtime and compile time
overhead. It could be considered as a "fixed feature" Expected specialised for the
use case of handling errors only.

\subsection design_differences Design differences between Expected and Outcomes

1. Outcome is designed specifically for returning output from function calls in
low latency/very high performance C++ of the kind
<a href="https://groups.google.com/a/isocpp.org/forum/#!forum/sg14">WG21 WG14</a> is working upon. It
therefore works perfectly with exceptions and RTTI disabled and its CI compiles per
commit typical use cases of Outcomes and counts the assembler operations emitted by GCC, clang and MSVC to ensure
code bloat is kept optimally minimal. On all recent GCCs and clangs, if the compiler's
optimiser can infer the state of an outcome, **all runtime overhead due to the outcome
ought to be completely eliminated** (sans optimiser bugs which appear from time to time). This
means for inlined code if you return a `result<T>(T())`, the compiler will generate
identical code as if you had returned a `T()` directly.
2. Outcome's actual core implementation is `boost::outcome::basic_monad<Policy<T, EC, E>>` with these
convenience typedefs:
 \code
 template<class T> using outcome = basic_monad<monad_policy<T, std::error_code, std::exception_ptr>>;
 template<class T> using result = basic_monad<result_policy<T, std::error_code, void>>;
 template<class T> using option = basic_monad<option_policy<T, void, void>>;
 \endcode 
 You can use any type `EC` or `E` you like so long as they act as if a `std::error_code`
 and a `std::exception_ptr` respectively e.g. `boost::error_code` and `boost::exception_ptr`.
 **Unlike** the `E` in `expected<T, E>`, Outcome hard codes the model of `EC` and `E` in stone,
 so they *must* provide at least the same APIs and behaviours as an error code and an
 exception pointer or be `void`, in which case the specialisation doesn't provide the ability
 to store an instance of that type.
3. As suggested by the presence of an `option<T>` convenience typedef, all `basic_monad<>` instances have a
formal empty state. There is no "never empty" guarantee which
enables sane semantics when exceptions are disabled and also to not confuse the compiler's
optimiser with complex potential branches in move construction (which can cause the optimiser
to give up prematurely). It sidesteps handling the problem of move assignment throwing an
exception, in which case Outcomes are left in an empty state. It ensures all `basic_monad<>`
are constexpr default constructible. If you attempt to get a value from an empty Outcome,
the compiler will throw an `outcome::monad_error` if exceptions are available, else it
calls the macro `BOOST_OUTCOME_THROW_MONAD_ERROR()` which by default dumps a stack trace
and terminates the process.
4. Like `expected<T, E>`, explicit conversion exists from any `basic_monad<Policy<T1, EC1, E1>>` to
any `basic_monad<Policy<T2, EC2, E2>>` if all of `T2`, `EC2` and `E2` are constructible from
`T1`, `EC1` and `E1` respectively. `basic_monad<Policy<void>>` has special significance: you
can always implicitly safely construct any arbitrary `basic_monad<Policy<T>>` from any
`basic_monad<Policy<void>>` which is always a lossless operation. The rules are as follows:
 1. If input `basic_monad<Policy<void>>` is empty, `basic_monad<Policy<T>>` is empty.
 2. If input `basic_monad<Policy<void>>` has value, `basic_monad<Policy<T>>` is a default
constructed `T`.
 3. If input `basic_monad<Policy<void>>` has an error, `basic_monad<Policy<T>>` has the
same error either copy or move constructed as appropriate.
 4. If input `basic_monad<Policy<void>>` has an exception, `basic_monad<Policy<T>>` has the
same exception either copy or move constructed as appropriate.

 This is Outcome's implementation of the `unexpected<E>` type sugar used by Expected to initialise
an `expected<T, E>` with an `E`. In Outcome, returning a void Outcome with the error or exception
you want (or better, use the `make_errored_result<>`, `make_errored_outcome<>` or
`make_exceptional_outcome<>` free functions) will be implicitly converted into whatever type of
Outcome you wish with the errored or excepted state.
5. Types `T`, `EC` and `E` cannot be the same nor be constructible from one another, and this
is enforced by static assertion at compile time. This prevents pointless confusion and
maintenance difficulty (if you really, really need to return error codes or exception
pointers as `T`, wrap them in a thin type wrapper).
6. You can explicitly convert from any less representative `basic_monad<>` to any more
representative form because that is always a loss free, non-throwing operation (and usually
entirely eliminated by the compiler at runtime, if it can it will simply treat the same
storage differently as if by `static_cast<>`). This is
because it is expected that lowest level code will return `option<T>` and `result<T>`
and higher level code will return `outcome<T>`, so this makes for seamless up-conversion as
you move further away from low level code. This also lets you return a `result<void>` with
an error code and it'll auto upconvert to any `outcome<T>`.
7. For the most part, `expected<T, std::error_code>` and `outcome::result<T>` ought to be close
to interchangeable in most use cases, and could be configurably template alias swappable in most
code. There is one glaring exception however, and that is that a default constructed Outcome
is **empty**, not to a default constructed `T` which makes sense given the formal empty state.
8. Outcomes implement equality/non-equality operators, but not ordering comparison nor hash operations.
This is due to https://akrzemi1.wordpress.com/2014/12/02/a-gotcha-with-optional/ where
you either choose implicit construction OR comparison operations or else risk surprising
behaviours. That means you can only place Outcomes in non-mapped STL containers. It is
trivial for users to write a simple wrapper class for Outcomes implementing comparison
and hashing if they ever really needed to store Outcomes in associative maps.
9. Finally, Outcome goes out of its way to be as cheap on compile time as possible by having
the compiler do as little work as possible if not optimising. A lot of the hard coded rigidity
above stems from systematically avoiding, whenever possible, metaprogramming, SFINAE, instantiation of helper types
during deduction, or doing anything which would cause the compiler to not use `O(1)` constant
time operations during non-optimising compilation. I have also found empirically that there
is also a useful side effect of this simplicity of implementation on helping the compiler's
optimiser "to do the right thing" when facing real world use cases.

 The reason for this minimum compile time load approach was due to my work experience
with original prototype Boost.Expected in 2015 where we saw large increases in compile times
once Expected was deployed at scale - remember
*every single API* is returning an instance of one of these and much branch logic is working
with them in every function, potentially instantiating lots of shim and helper deduction and
introspection types each time. P0323R1 Expected removes a large chunk of metaprogrammed functionality,
specifically the monadic operations which should help a great deal. Nevertheless, from
my best reading, P0323R1 Expected still demands more from the compiler than Outcome does.
Deploying Outcome into a large C++ codebase ought to have as minimal a compile time impact
as possible for a variant implementation, something which matters on code bases heading into
the tens of millions of lines like many potential low latency/high performance users will have.


\section synopsis Synopsis of basic_monad<> and outcome<T>, result<T> and option<T>

It should be stressed that `basic_monad<>` is a policy driven class where the policy
class has the ability to arbitrarily extend and/or replace member functions listed in this
synopsis. Indeed originally a non-allocating high performance `promise<T>...future<T>` implementation
simply supplied a policy class implementing the additional features of promise-future to
`basic_monad<>` whereby C++ 17 future continuations were modelled as monadic binds
(it can be still found in the attic directory for anyone interested, though note how stale
it likely is by now). That level of flexibility remains in the design for anyone interested in adding more
`basic_monad<>` specialisations e.g. packed storage.

The following is a synopsis for `outcome<T>` which is configured with `value_type = T`,
`error_type = std::error_code` and `exception_type = std::exception_ptr`. If it were a
`result<T>`, only `value_type` and `error_type` functions would be present, similarly if it were
an `option<T>` only `value_type` functions would be present.

\code
BOOST_OUTCOME_V1_NAMESPACE_BEGIN

// Tag types for creating empty, valued, errored and excepted basic_monad's
struct empty_t; constexpr empty_t empty;
struct value_t; constexpr value_t value;
struct error_t; constexpr error_t error;
struct exception_t; constexpr exception_t exception;

// Specialise to std::true_type for types you wish to store in a packed single byte
// (void and bool are done for you unless you define BOOST_OUTCOME_DISABLE_DEFAULT_SINGLE_BYTE_VALUE_STORAGE)
template <class _value_type> struct enable_single_byte_value_storage;

// Remember basic_monad<Policy<...>> is aliased to outcome<T>, result<T> and option<T>
template <class T, class EC = std::error_code, class E = std::exception_ptr>
class basic_monad<monad_policy<T, EC, E>>
{
public:
  // true if configured to hold a value_type, an error_type or an exception_type
  static constexpr bool has_value_type;
  static constexpr bool has_error_type;
  static constexpr bool has_exception_type;
 
  // If configured with void, set to a helpfully named unusable type 
  using value_type = T | unusable;                                             // similar in expected<> [3]
  using error_type = EC | unusable;                                            // similar in expected<> [3]
  using exception_type = E | unusable;                                         // [3]
  
  // The actual types configured
  using raw_value_type = T | void;                                             // The actual type configured
  using raw_error_type = EC | void;                                            // ditto
  using raw_exception_type = E | void;                                         // ditto

  template <class U> using rebind = basic_monad<U>;                            // also in expected<>

  // The properties of this monad, and relative to other monads
  static constexpr bool is_nothrow_copy_constructible;
  static constexpr bool is_nothrow_move_constructible;
  static constexpr bool is_nothrow_copy_assignable;
  static constexpr bool is_nothrow_move_assignable;
  static constexpr bool is_nothrow_destructible;
  static constexpr bool is_trivially_destructible;
  template <class OtherMonad> static constexpr bool is_constructible;
  template <class OtherMonad> static constexpr bool is_comparable;

  // Default implicit construction and copy and move construction
  constexpr basic_monad() noexcept([1]);                                       // also in expected<>, use make_basic_monad<T>() instead
  constexpr basic_monad(const basic_monad&) noexcept([1]);                     // also in expected<>
  constexpr basic_monad(basic_monad&&) noexcept([1]);                          // also in expected<>

  // Implicit constructing empty or with a value_type
  constexpr basic_monad(empty_t) noexcept;                                     // use make_basic_XXX<T>() instead
  constexpr basic_monad(value_t) noexcept(T);                                  // use make_ready_XXX<T>() instead
  constexpr basic_monad(const value_type&) noexcept(T);                        // also in expected<>
  constexpr basic_monad(value_type&&) noexcept(T);                             // also in expected<>
  
  // Explicit emplacement of a value_type
  template <class... Args>
    constexpr explicit basic_monad(in_place_t, Args&&...) noexcept(T);         // also in expected<>
  template <class U>
    constexpr basic_monad(in_place_t, std::initializer_list<U>) noexcept(T);   // also in expected<>

  // Implicit construction from emptiness, error or excepted state of a void basic_monad
  constexpr basic_monad(const rebind<void>&) noexcept([1]);                    // use as_void() to create a void monad
  constexpr basic_monad(rebind<void>&&) noexcept([1]);                         // use as_void() to create a void monad
  
  // Implicit construction with error_type or exception_type
  constexpr basic_monad(const error_type&) noexcept(EC);                       // use make_errored_XXX() instead
  constexpr basic_monad(error_type&&) noexcept(EC);                            // use make_errored_XXX() instead
  constexpr basic_monad(const exception_type&) noexcept(E);                    // use make_exceptional_XXX() instead
  constexpr basic_monad(exception_type&&) noexcept(E);                         // use make_exceptional_XXX() instead
  
  // Explicit up converting move and copy constructors, only
  // available if T, EC and E are constructible from T2, EC2 and E2
  // and no information can ever be lost
  template <class T2, class EC2, class E2>
    constexpr explicit basic_monad(basic_monad<monad_policy<T2, EC2, E2>> &&) noexcept([1]);
  template <class T2, class EC2, class E2>
    constexpr explicit basic_monad(const basic_monad<monad_policy<T2, EC2, E2>> &) noexcept([1]);
  
  // Not implemented if value_type, error_type and exception_type are all trivially destructible
  // thus making basic_monad a LiteralType (i.e. constexpr usable)
  ~basic_monad() noexcept([1]);

  // Assignment. Note exception throws during assignment leave the monad empty
  constexpr basic_monad& operator=(const basic_monad&) noexcept([1]);          // also in expected<>
  constexpr basic_monad& operator=(basic_monad&&) noexcept([1]);               // also in expected<>

  // Observers
  constexpr explicit operator bool() const noexcept;                           // also in expected<>
  constexpr explicit operator boost_lite::tribool::tribool() const noexcept;   // other if monad empty, false if monad errored/excepted
  constexpr bool is_ready() const noexcept;                                    // i.e. not empty
  constexpr bool empty() const noexcept;
  constexpr bool has_value() const noexcept;                                   // also in expected<>
  constexpr bool has_error() const noexcept;
  constexpr bool has_exception(bool only_exception = false) const noexcept;    // NOTE defaults to true also if has_error()

  // For compatibility with expected<T, E> and optional<T>
  constexpr const value_type* operator ->() const;                             // also in expected<>, missing if [2]
  constexpr value_type* operator ->();                                         // also in expected<>, missing if [2]
  constexpr const value_type& operator *() const&;                             // also in expected<>, returns by value if [2]
  constexpr value_type& operator *() &;                                        // also in expected<>, returns by value if [2]
  constexpr const value_type&& operator *() const&&;                           // also in expected<>, returns by value if [2]
  constexpr value_type&& operator *() &&;                                      // also in expected<>, returns by value if [2]

  // Retrieving value_type
  constexpr const value_type& value() const&;                                  // also in expected<>
  constexpr value_type& value() &;                                             // also in expected<>
  constexpr const value_type&& value() const&&;                                // also in expected<>
  constexpr value_type&& value() &&;                                           // also in expected<>
  constexpr const value_type &value_or(const value_type &) noexcept const&;    // similar in expected<>
  constexpr value_type& value_or(value_type&) noexcept &;                      // similar in expected<>
  constexpr const value_type&& value_or(const value_type&&) noexcept const&&;  // similar in expected<>
  constexpr value_type&& value_or(value_type&&) noexcept &&;                   // similar in expected<>

  // Setting value_type, disposes any previous state
  constexpr void set_value(const value_type&);
  constexpr void set_value(value_type&&);
  constexpr void set_value();
  template <class... Args>
    constexpr void emplace(Args&&...) noexcept([1]);                           // also in expected<>
  
  // Retrieving and setting error_type and exception_type
  constexpr error_type error() const;                                          // similar in expected<>
  constexpr error_type error_or(error_type) noexcept const;
  constexpr void set_error(error_type);
  constexpr exception_type exception() const;
  constexpr exception_type exception_or(exception_type) noexcept const;
  constexpr void set_exception(exception_type);
  template<class E> void set_exception(E&&);                                   // via std::make_exception_ptr

  // Swap and clear to empty
  void swap(basic_monad&) noexcept([1]);                                       // also in expected<>
  void clear() noexcept([1]);

#ifdef BOOST_OUTCOME_ENABLE_OPERATORS                                          // defaults to disabled (documented below)
  basic_monad<...> unwrap() const &;
  basic_monad<...> unwrap() &&;
  template<class F> basic_monad<...> bind(F &&f);
  template<class F> basic_monad<...> operator>>(F &&f);
  template<class F> basic_monad<...> map(F &&f);
  template<class F> basic_monad(F(contents)).unwrap() match(F &&f);
  template<class... Args> decltype(value_type(Args...)) operator()(Args &&...);
  
  template<class U> constexpr basic_monad operator|(U &&) &;
  template<class U> constexpr basic_monad operator|(U &&) const&;
  template<class U> constexpr basic_monad operator|(U &&) &&;
  template<class U> constexpr basic_monad operator&(U &&) &;
  template<class U> constexpr basic_monad operator&(U &&) const&;
  template<class U> constexpr basic_monad operator&(U &&) &&;
#endif
};

// NOTE requires state to be set to valued beforehand (and can only deserialise a value)
template<class Policy> inline std::istream &operator>>(std::istream &s, basic_monad<Policy> &v);
template<class Policy> inline std::ostream &operator<<(std::ostream &s, const basic_monad<Policy> &v);

// Equality operators
template<class Policy1, class Policy2> constexpr inline bool operator==(const basic_monad<Policy1> &, const basic_monad<Policy2> &);
template<class Policy1, class Policy2> constexpr inline bool operator!=(const basic_monad<Policy1> &, const basic_monad<Policy2> &);

// Outcome makers
template <class T> constexpr inline outcome<T> make_outcome(T &&v);
template <class T> constexpr inline outcome<T> make_outcome(const T &v);
template <class T = void> inline outcome<T> make_outcome(error_code_extended v);
template <class T = void> inline outcome<T> make_outcome(std::exception_ptr v);
template <class T = void> constexpr inline outcome<T> make_outcome();
template <class T = void> constexpr inline outcome<T> make_empty_outcome();
template <class T> constexpr inline outcome<T> make_ready_outcome(T &&v);
template <class T> constexpr inline outcome<T> make_ready_outcome(const T &v);
template <class T = void> constexpr inline outcome<T> make_ready_outcome();
template <> inline outcome<void> make_ready_outcome<void>();
template <class T = void> inline outcome<T> make_errored_outcome(error_code_extended v);
template <class T = void> inline outcome<T> make_errored_outcome(int e, const char *extended = nullptr);                      // errno consumer
#if defined(_WIN32)
template <class T = void> constexpr inline outcome<T> make_errored_outcome(unsigned long e, const char *extended = nullptr);  // GetLastError() consumer
#endif
template <class T = void> inline outcome<T> make_exceptional_outcome(std::exception_ptr v);

// Result makers
template <class T> constexpr inline result<T> make_result(T &&v);
template <class T> constexpr inline result<T> make_result(const T &v);
template <class T = void> inline result<T> make_result(error_code_extended v);
template <class T = void> constexpr inline result<T> make_result();
template <class T = void> constexpr inline result<T> make_empty_result();
template <class T> constexpr inline result<T> make_ready_result(T &&v);
template <class T> constexpr inline result<T> make_ready_result(const T &v);
template <class T = void> constexpr inline result<T> make_ready_result();
template <> inline result<void> make_ready_result<void>();
template <class T = void> inline result<T> make_errored_result(error_code_extended v);
template <class T = void> constexpr inline result<T> make_errored_result(int e, const char *extended = nullptr);              // errno consumer
#if defined(_WIN32)
template <class T = void> constexpr inline result<T> make_errored_result(unsigned long e, const char *extended = nullptr);    // GetLastError() consumer
#endif

// Option makers
template <class T> constexpr inline option<T> make_option(T &&v);
template <class T> constexpr inline option<T> make_option(const T &v);
template <class T = void> constexpr inline option<T> make_option();
template <class T = void> constexpr inline option<T> make_empty_option();
template <class T> constexpr inline option<T> make_ready_option(T &&v);
template <class T> constexpr inline option<T> make_ready_option(const T &v);
template <class T = void> constexpr inline option<T> make_ready_option();
template <> constexpr inline option<void> make_ready_option<void>();

// Upconverters
template <class T> constexpr inline outcome<T> as_outcome(result<T> &&v);
template <class T> constexpr inline outcome<T> as_outcome(const result<T> &v);
template <class T> constexpr inline outcome<T> as_outcome(option<T> &&v);
template <class T> constexpr inline outcome<T> as_outcome(const option<T> &v);
template <class T> constexpr inline result<T> as_result(option<T> &&v);
template <class T> constexpr inline result<T> as_result(const option<T> &v);

// Emptiness, errored and excepted state extractors
template <class T> inline outcome<void> as_void(const outcome<T> &v);
template <class T> inline result<void> as_void(const result<T> &v);
template <class T> constexpr inline option<void> as_void(const option<T> &v);

// Equivalent to try! in Rust and Swift (see below for docs)
#define BOOST_OUTCOME_TRY(variable_to_initialise, monad)

// Boilerplate catching all the STL exceptions, returning an equivalent result<void> (see below for docs)
#define BOOST_OUTCOME_CATCH_EXCEPTION_TO_RESULT

BOOST_OUTCOME_V1_NAMESPACE_END
\endcode

[1]: The `noexcept` for each of these is determined by calculating the `noexcept`
for the same operation in each of `T`, `EC` and `E`. If the same operation on any
of those types can throw, so can the basic_monad's operation.

[2]: The trait `boost::outcome::enable_single_byte_value_storage<T>` determines if
a single byte is used to store `T`, in which case you will not be returned a pointer
nor reference to `T`. It is enabled for `bool` and `void` unless the
macro `BOOST_OUTCOME_DISABLE_DEFAULT_SINGLE_BYTE_VALUE_STORAGE` is defined.

[3]: If the monad was configured with `void` in this place, this is configured with an
internal non-accessible type usefully named to indicate you are trying to use
something not possible which will generate a very obvious descriptive compiler error.


\section examples Examples of usage

The above synopsis of Outcome looks lengthy and complex, but almost all of it is
convenience overloads of one form or other. In usage Outcome is generally "stupid easy"
to program with, especially if you're already used to `std::optional`. Here is a real
world use case distilled from AFIO v2's source code:

\snippet usecase_example.cpp file_create_example

Unlike the earlier example functions opening a file, the above is not a toy use case
and it covers almost all of the permutations of creating or opening a file which is
common to POSIX and Windows. We make use of the fact that `basic_monad<> ::value()`
returns a non-const lvalue ref when the monad instance is a non-const stack allocated
instance, binding it to the convenience lvalue ref `nativeh` which points at a union
containing the `HANDLE` later filled with the opened handle.

We make use of `BOOST_OUTCOME_TRY(var, expr)` which is a macro expanding to:

\code
  auto &&unique = (expr);                                  // "unique" is a preprocessor generated unique temporary identifier
  if(!unique.has_value())
    return BOOST_OUTCOME_V1_NAMESPACE::as_void(unique);
  auto var(std::move(std::move(unique).value()))
\endcode

This gets as close as is possible in C++ to the `try!` facility in Rust or Swift without
using exception throws, and you'll find yourself using it a very great deal when writing
code using Outcome. Like `try!`, the monad returning expression is executed and its returned
monad checked to see if it has a value. If it does, the value is extracted out of the monad
and placed in the variable you asked for. If it did not contain a value, the emptiness/errored/excepted
state is converted into a void form monad and returned immediately from the calling function,
thus propagating the errored state up the stack. You'll note we cast the stack allocated monad
instance into a rvalue ref before asking for its value, this returns a rvalue ref to the value.
We then pass that rvalue ref through to the variable instance constructor so the value is moved
and not copied. I have disassembled this sequence on the main compilers and found that where
the compiler knows for a fact that a value is being returned, all runtime overhead over a
straight return of a value is eliminated.

We also make use of a convenience overload of the `make_errored_XXX()` functions where a
single `int` is assumed to be a POSIX code in the `errno` domain and a single `DWORD` is assumed to
be a Win32 code in the `GetLastError()` domain. This allows very easy conversion of system
error codes into the appropriate `std::error_code` thusly returned wrapped in a monad.

Finally we also make use of the `BOOST_OUTCOME_CATCH_EXCEPTION_TO_RESULT` macro which is a long
sequence of STL exception type catch clauses converting STL exception types into their
equivalent error codes:

\code
catch(const std::invalid_argument &e)
{
  return BOOST_OUTCOME_V1_NAMESPACE::make_errored_result<void>(EINVAL, e.what());
}
catch(const std::domain_error &e)
{
  return BOOST_OUTCOME_V1_NAMESPACE::make_errored_result<void>(EDOM, e.what());
}
catch(const std::length_error &e)
{
  return BOOST_OUTCOME_V1_NAMESPACE::make_errored_result<void>(E2BIG, e.what());
}
catch(const std::out_of_range &e)
{
  return BOOST_OUTCOME_V1_NAMESPACE::make_errored_result<void>(ERANGE, e.what());
}
catch(const std::logic_error &e) /* base class for this group */
{
  return BOOST_OUTCOME_V1_NAMESPACE::make_errored_result<void>(EINVAL, e.what());
}
catch(const std::system_error &e) /* also catches ios::failure */
{
  return BOOST_OUTCOME_V1_NAMESPACE::make_errored_result<void>(BOOST_OUTCOME_V1_NAMESPACE::error_code_extended(e.code(), e.what()));
}
catch(const std::overflow_error &e)
{
  return BOOST_OUTCOME_V1_NAMESPACE::make_errored_result<void>(EOVERFLOW, e.what());
}
catch(const std::range_error &e)
{
  return BOOST_OUTCOME_V1_NAMESPACE::make_errored_result<void>(ERANGE, e.what());
}
catch(const std::runtime_error &e) /* base class for this group */
{
  return BOOST_OUTCOME_V1_NAMESPACE::make_errored_result<void>(EAGAIN, e.what());
}
catch(const std::bad_alloc &e)
{
  return BOOST_OUTCOME_V1_NAMESPACE::make_errored_result<void>(ENOMEM, e.what());
}
catch(const std::exception &e)
{
  return BOOST_OUTCOME_V1_NAMESPACE::make_errored_result<void>(EINVAL, e.what());
}
catch(...)
{
  return BOOST_OUTCOME_V1_NAMESPACE::make_errored_result<void>(EAGAIN, "unknown exception");
}
\endcode

You will surely note that the `make_errored_XXX()` functions actually take an `int` and an optional
`const char *`. This is the purpose of `error_code_extended` which extends `std::error_code` with
the following synposis:

\code
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
  size_t extended_message(char *buffer, size_t len, unsigned &code1, unsigned &code2) const noexcept;
  char **backtrace() const noexcept;
};
inline std::ostream &operator<<(std::ostream &s, const error_code_extended &ec);
\endcode

`error_code_extended` is completely API compatible with `std::error_code` and all its
member functions can be used the same way. You can supply a `std::error_code` to an
extended error code, or else construct an extended error code the same way you would a
STL error code. You should note that it is **always safe** to slice `error_code_extended`
into an `std::error_code`, so you can safely feed `error_code_extended` to anything
consuming a `std::error_code`.

The main big additions are obviously the ability to add a custom string message to an extended
error code, this allows the preservation of the original `what()` message when converting a
thrown exception into an extended error code. You can also add two arbitrary unsigned integer
codes and most interestingly, a backtrace. The extended message and backtrace can be later
fetched using the new member functions, though note that the storage for these is kept in a
statically allocated threadsafe ring buffer and so may vanish at some arbitrary later point
when the storage gets recycled.

If you are throwing your own custom types with custom information, you should note that
you can create your own custom extended error code type using the same reusable
microsecond fast threadsafe logging framework that Outcome uses. This won't be documented
here as that framework (`ringbuffer_log`) lives in Boost-lite, but it's fairly easy to study
Outcome's and Boost-lite's source code which is all on github.


\section when_use When am I supposed to use what when?

The total available permutations may seem overwhelming at this point, but as with any
fundamental primitive the possibilities are endless. However, here are some quick notes
to help you decide what design pattern to use for your particular code base:

\subsection outcome_vs_result When should I use a result<T> instead of an outcome<T>?

`outcome<T>` has the potential to carry a `std::exception_ptr` which is implemented
by any STL I can think of as something very similar to a `std::shared_ptr` i.e. it
uses atomics to manage the reference count. Atomics are unavoidably a *compiler fence*
i.e. the compiler **must** emit code at the point of the fence. Outcome has been
very carefully written to let the compiler's optimiser *not* emit code thus leading
to its stellar low runtime overhead. Whilst recent versions of GCC and clang seem
reasonably good at eliding compiler fences caused by use of atomics in `std::exception_ptr`
when the compiler is absolutely sure that no `std::exception_ptr` can be transported,
where there is doubt the compiler has no choice but to generate a lot more output.
`result<T>` cannot transport a `std::exception_ptr` and therefore doesn't force the
compiler to generate output (except unfortunately on the Dinkumware STL where fetching
a STL error category e.g. `std::generic_category()` uses atomics).

So in short, always use `result<T>` where possible.

\subsection result_vs_outcome When should I use an outcome<T> instead of a result<T>?

The main reason to use an `outcome<T>` is in the "sea of noexcept" design pattern
where implementations may throw exceptions, but all public extern APIs are always
noexcept. `outcome<T>` provides a lossless method of exporting the thrown exception
but without loading the programmer with dealing with control flow reversal.

However the role where `outcome<T>` really shines is in the "exceptions are exceptional"
design pattern where the errored state means an expected error which was handled inline
but the exceptioned state means an operation was aborted.

The main reason I designed and wrote Outcome was to gain a universal error handling
framework which could express *in the minimum possible overhead* the many
error handling designs possible and even more importantly, that individual libraries
could use the design pattern which best suited them whilst seamlessly interoperating
with other libraries using different error handling designs. To go into a bit more
detail:
* Proposed <a href="https://ned14.github.io/boost.afio/">Boost.AFIO v2</a>


\section advanced More advanced usage

99% of Outcome users already have everything they will ever need - Outcome is a very
simple library. However "full fat" monadic functional programming is also provided
using a very clean and powerful API, albeit at a fair cost to compile times.

\subsection functional Functional programming extensions (optional)

\note All code in this section can be enabled by defining `BOOST_OUTCOME_ENABLE_OPERATORS`.
By default only `next()` is available. This prevents you writing code which impacts build times.

It is assumed in this section that you already understand monadic functional programming. This
section is simply to explain how these are implemented in Outcome.

Classic monadic programming consists of a sequence of nested functional operations:
<dl>
  <dt>JOIN (single): `outcome<outcome<T>>.value()` -> `outcome<T>`</dt>
  <dt>JOIN (maximum): `outcome<outcome<outcome<outcome<T>>>>.unwrap()` -> `outcome<T>`</dt>
    <dd>Whatever is the first monad containing a non-monad is returned.</dd>
  <dt>MAP: `outcome<T>.map(R(T))` -> `outcome<R>`</dt>
    <dd>If callable maps `T` to `R`, `map()` maps an `outcome<T>` to an `outcome<R>` if `outcome<T>`
    contains a `T`. If it contains an error or is empty, that is passed through.</dd>
  <dt>BIND: `outcome<T>.bind(outcome<R>(T))` -> `outcome<R>`</dt>
  <dt>BIND: `outcome<T>.bind(R(T))` -> `outcome<R>`</dt>
    <dd>If callable maps `T` to `outcome<R>` and if `outcome<T>` contains a `T`, then `bind()` maps
    an `outcome<T>` to an `outcome<R>` else if callable maps `T` to `R` and if `outcome<T>` contains a `T`,
    `bind()` maps an `outcome<T>` to an `outcome<R>`. In other words, returning a monad from the
    callable does not wrap it in another monad. If the originating monad did not
    contain a `T`, that is passed through.</dd>
</dl>
We also support `outcome<T>.next(R(outcome<T>))` for semantic equivalence to futures where the
callable is called with the originating monad. This
acts like `bind()`, so if the callable returns a monad it is not wrapped in another
monad. Unlike `map()` or `bind()`, `next()` always calls the callable no matter what the
monad contains, so it is up to you to interrogate the monad. Note that the originating
monad is passed by const lvalue ref unless the callable takes a rvalue ref to the monad.

A quick use example:
\snippet monad_example.cpp monad_bind_example
\snippet unittests.cpp monad_match_example
\snippet unittests.cpp monad_operators_example

You will note in the code example that the type of the callable for `bind()` and `map()`
determines what operation happens. Here are the rules:
- If the monad contains a `T` and the callable takes a `T` or an `auto`, then:
  - If the callable takes a `T` or any reference to a `T` which isn't an rvalue reference,
  the `T` is passed by const lvalue reference (i.e. copy semantics).
  - If the callable takes a `T` by non-const rvalue reference, the `T` is passed by rvalue ref.
  This lets you move from the value held by the originating monad if so desired.
  - If the callable takes the originating monad or any reference to such which isn't a
  rvalue reference, then the originating monad is passed by const lvalue reference.
  - If the callable takes the originating monad by non-const rvalue reference, the
  originating monad is passed by rvalue reference.
The ability to take the originating monad makes `bind()` identical to `next()` though much
harder on build times. Note that these options let you rebind the type of the monad,
so if your callable returns a different type from the originating monad then the resulting
monad is based on that different return type.
\warning The current implementation requires you to specify a non-dependent return
type for all generic lambdas, else you'll get compile errors where the compiler tried
to insert `error_type`, `exception_type` etc when it was trying to figure out if the
return type is correct. A future implementation (once MSVC has Expression SFINAE) may
remove this restriction, until then just hard specify your return types if your lambdas
take an `auto`, or use lambdas not taking `auto`.

- If the monad contains an `error_type` and the callable takes an `error_type`, then
call the callable, else pass through the monad. For this reason, any callable taking
an `error_type` must always return the same monad type as the originating monad.
- If the monad contains an `error_type` or an `exception_type` and the callable takes
an `exception_type`, then call the callable, else pass through the monad. For this reason,
any callable taking an `exception_type` must always return the same monad type as the
originating monad.
- If the monad is empty and the callable takes an `empty_type`, then call the callable,
else pass through the monad. For this reason, any callable with an `empty_type` parameter must
always return the same monad type as the originating monad.

Note that for nested monads e.g. `outcome<outcome<int>>`, either or both of the inner or outer
monads can be with value or with error or empty. You should have your binds and maps
work appropriately.

For maximum build performance, try to avoid `bind()` and `map()` as these use some hefty
metaprogramming to deduce what kind of bind and map you're doing based on the callables
passed. `unwrap()` is implemented using a recursively expanded structure which is probably
okay for low unwrap depths. `next()` is probably the least weighty of the monadic operators
as it's relatively dumb and the only metaprogramming is to determine whether to wrap
the return type with a monad or not. Because of this impact on compile times, by default
all operations apart from `next()` are not compiled in without the `BOOST_OUTCOME_ENABLE_OPERATORS`
macro being defined beforehand.

### Acknowledgements ###
To T.C. on Stack Overflow for answering my question at https://stackoverflow.com/questions/30802404/how-to-detect-whether-some-callable-takes-a-rvalue-reference
and without whose excellent answer the intelligent `map()` and `bind()` above could not work.

