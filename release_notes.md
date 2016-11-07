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
the convenience specialisations of `outcome<T>`, `result<T>` and `option<T>`.
Its main intended usage is as an ultra light weight error handling framework,
providing a more expressive and type safe alternative to error code integers
or enums, yet much lower overhead than exception throws, and unlike alternatives
it works perfectly with exceptions and RTTI disabled. It may have lower compile
and runtime overheads than the `expected<T, E>` heading for standardisation, if not then it
is certainly more convenient to program with for error handling than using
`expected<T, E>` as it was specifically designed and tailored for this purpose.
One could view Outcome as a "hard coded for performance" `expected<T, E>`.

If you are familiar with Swift's error code throws or Rust's `Result<T>` and `Option<T>`,
you will find almost identical semantics in the transports provided here.
One can therefore write systems programming code using these transports in C++
in the same design pattern as when writing in Rust or Swift, and with a similarly
low runtime overhead.

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

1. Outcome is designed specifically for returning output from function calls in low latency/very high performance C++. It
therefore works perfectly with exceptions and RTTI disabled and its CI compiles per
commit typical use cases of Outcomes and counts the assembler operations emitted by GCC, clang and MSVC to ensure
code bloat is kept optimally minimal. On all recent GCCs and clangs, if the compiler's
optimiser can infer the state of an outcome, **all runtime overhead due to the outcome
is completely eliminated** (sans optimiser bugs which appear from time to time). This
means for inlined code if you return a `result<T>(T())`, the compiler will generate
identical code as if you had returned a `T()` directly.
2. Outcome's actual core implementation is `boost::outcome::basic_monad<Policy<T, EC, E>>` with these
convenience typedefs:
 \code
 template<class T> using outcome = basic_monad<Policy<T, std::error_code, std::exception_ptr>>;
 template<class T> using result = basic_monad<Policy<T, std::error_code, void>>;
 template<class T> using option = basic_monad<Policy<T, void, void>>;
 \endcode 
 You can use any type `EC` or `E` you like so long as they act as if a `std::error_code`
 and a `std::exception_ptr` respectively e.g. `boost::error_code` and `boost::exception_ptr`.
 **Unlike** the `E` in `expected<T, E>`, Outcome hard codes the model of `EC` and `E` in stone,
 so they *must* provide at least the same APIs and behaviours as an error code and an
 exception pointer or be `void`, in which case the specialisation doesn't provide the ability
 to store an instance of that type.
3. Types `T`, `EC` and `E` cannot be the same nor be constructible from one another (this
is enforced by static assertion at compile time). The
reason for this is that unlike `expected<T, E>`, outcomes implicitly construct from any
of types `T`, `EC` or `E`. A lot of readers will groan on reading that, but
in practice because there is no possibility of the programmer confusing how to construct a
`T` or an `EC` or an `E` due to the hard coding, there is no unexpected behaviours in practice
as you cannot accidentally construct the wrong state unintentionally.
4. As suggested by the presence of an `option<T>` convenience typedef, all `basic_monad<>` instances have a
formal empty state. There is no "never empty" guarantee which
enables sane semantics when exceptions are disabled and also to not confuse the compiler's
optimiser with complex potential branches in move construction (which can cause the optimiser
to give up prematurely). It also sidesteps the problem of move assignment throwing an
exception, in which case Outcomes are left in an empty state.
5. You can explicitly convert from any less representative `basic_monad<>` to any more
representative form because that is always a loss free, non-throwing operation (and usually
entirely eliminated by the compiler at runtime, if it can it will simply treat the same
storage differently as if by `static_cast<>`). This is
because it is expected that lowest level code will return `option<T>` and `result<T>`
and higher level code will return `outcome<T>`, so this makes for seamless up-conversion as
you move further away from low level code.
6. For the most part, `expected<T, std::error_code>` and `outcome::result<T>` ought to be close
to interchangeable in most use cases, and could be configurable template alias swappable in most code. This is
intentional and deliberate to provide a bridge for code until Expected is standardised.
7. Outcomes implement equality/non-equality operators, but not ordering comparison nor hash operations.
This is due to https://akrzemi1.wordpress.com/2014/12/02/a-gotcha-with-optional/ where
you either choose implicit construction OR comparison operations or else risk surprising
behaviours. That means you can only place Outcomes in non-mapped STL containers. It is
trivial for users to write a simple wrapper class for Outcomes implementing comparison
and hashing if they ever really needed to store Outcomes in associative maps.
8. Finally, Outcome goes out of its way to be as cheap on compile time as possible by having
the compiler do as little work as possible if not optimising. A lot of the rigidity
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
my best reading, P0323R1 Expected still demands much more from the compiler than Outcome does.
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
it likely is by now).
That level of flexibility remains in the design for anyone interested in adding more
`basic_monad<>` specialisations e.g. packed storage.

The following is a synopsis for `outcome<T>` which is configured with `value_type = T`,
`error_type = std::error_code` and `exception_type = std::exception_ptr`. If it were a
`result<T>`, only `value_type` and `error_type` functions would be present, similar if it were
a `option<T>` only `value_type` functions would be present.

\code
// "class" outcome is actually a template alias to basic_monad<Policy<...>>
template <class T>
class outcome
{
public:
  using value_type = T;                                       // also in expected<>
  using error_type = std::error_code;                         // also in expected<>
  using exception_type = std::exception_ptr;
  template <class U> using rebind = outcome<U>;               // also in expected<>

  constexpr outcome() noexcept([1]);                          // also in expected<>
  constexpr outcome(const outcome&) noexcept([1]);            // also in expected<>
  constexpr outcome(outcome&&) noexcept([1]);                 // also in expected<>
  constexpr outcome(const value_type&) noexcept([1]);         // also in expected<>
  constexpr outcome(value_type&&) noexcept([1]);              // also in expected<>
  template <class... Args>
    constexpr explicit outcome(in_place_t, Args&&...);        // also in expected<>

  ~outcome() noexcept([1]);  // Not implemented if value_type, error_type and exception_type are trivially destructible

  constexpr outcome& operator=(const outcome&) noexcept([1]); // also in expected<>
  constexpr outcome& operator=(outcome&&) noexcept([1]);      // also in expected<>
  template <class... Args>
    constexpr void emplace(Args&&...) noexcept([1]);          // also in expected<>
  constexpr void swap(outcome&) noexcept([1]);                // also in expected<>

  constexpr explicit operator bool() const noexcept;          // also in expected<>
  constexpr bool has_value() const noexcept;                  // also in expected<>
  constexpr bool has_error() const noexcept;
  constexpr bool has_exception() const noexcept;

  constexpr const value_type* operator ->() const;            // also in expected<>, missing if [2]
  constexpr value_type* operator ->();                        // also in expected<>, missing if [2]
  constexpr const value_type& operator *() const&;            // also in expected<>, returns by value if [2]
  constexpr value_type& operator *() &;                       // also in expected<>, returns by value if [2]
  constexpr value_type&& operator *() &&;                     // also in expected<>, returns by value if [2]

  constexpr const value_type& value() const&;                 // also in expected<>
  constexpr value_type& value() &;                            // also in expected<>
  constexpr value_type&& value() &&;                          // also in expected<>
  constexpr const value_type &value_or(const value_type &) noexcept const&;  // similar in expected<>
  constexpr value_type& value_or(value_type&) noexcept &;                    // similar in expected<>
  constexpr value_type&& value_or(value_type&&) noexcept &&;                 // similar in expected<>

  constexpr const error_type& error() const&;                 // also in expected<>
  constexpr error_type& error() &;                            // also in expected<>
  constexpr error_type&& error() &&;                          // also in expected<>
  constexpr const error_type &error_or(const error_type &) noexcept const&;
  constexpr error_type& error_or(error_type&) noexcept &;
  constexpr error_type&& error_or(error_type&&) noexcept &&;

};
\endcode

[1]: The `noexcept` for each of these is determined by calculating the `noexcept`
for the same operation in each of `T`, `EC` and `E`. If the same operation on any
of those types can throw, so can the outcome's operation.

[2]: The trait `boost::outcome::enable_single_byte_value_storage<T>` determines if
a single byte is used to store `T`, in which case you will not be returned a pointer
nor reference to `T`. It is enabled for `bool` and `void` unless the
macro `BOOST_OUTCOME_DISABLE_DEFAULT_SINGLE_BYTE_VALUE_STORAGE` is defined.

To be continued ...
