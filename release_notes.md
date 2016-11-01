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
it works perfectly with exceptions and RTTI disabled. It may be lower overhead
than the `expected<T, E>` heading for standardisation, if not then it
is certainly more convenient to program with for error handling than using
`expected<T, E>` as it was specifically designed and tailored for this purpose.

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
apt-get install boost.outcome</pre>

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


\section introduction Introduction and Design Rationale

\subsection enums C style error handling: integer returns

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

\subsection exceptions C++ 98 style error handling: throwing exceptions

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

\subsection error_code C++ 11 style error handling: `error_code` and `noexcept`

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


\subsection optional C++ 17/20 style error handling: `optional<T>` and `expected<T, E>`

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
of `std::variant<T, E>`, indeed much of LEWG's remaining work on the proposal is on
reconciling the small remaining semantic differences between `expected<T, nullopt_t>`
and `optional<T>`.

\subsubsection optional Returning `optional<T>`

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


\subsubsection expected `expected<T, E>`

Many familiar with the filesystem will find the above use case of `optional<T>`
unsettling because there are many reasons why one couldn't open a file rather
than merely it was not found. Imagine, for example, that a program is attempting
to open a few thousand files on a networked drive which has broken its connection -
in this case every single failure will take considerable time to return and
there is zero chance *any* file open will ever succeed, so what the user sees
is an apparently hanged program. Far better would be if the `openfile()` function
could return the cause of its failure, and we could then treat all errors which are different
to file not found as reason to abort.

Enter LEWG's proposed `expected<T, E>` which can hold either an expected value of
type `T` or an unexpected value of type `E`. Like `variant<T, E>`, `expected<T, E>`
is a discrimated union storing either `T` or `E` in the same storage space.

\code
// Returns the expected opened handle on success, or an unexpected cause of failure
std::expected<handle_ref, std::error_code> openfile(const char *path) noexcept
{
  int fd = open(path, O_RDONLY);
  if(fd == -1)
  {
    return std::make_unexpected<std::error_code>(errno, std::system_category());
  }
  std::error_code ec;
  auto *p = new(std::nothrow) some_derived_handle_implementation(fd, ec);
  if(p == nullptr)
  {
    close(fd);
    return std::make_unexpected<std::error_code>(std::errc::not_enough_memory);
  }
  if(ec)
  {
    delete p;
    return std::make_unexpected<std::error_code>(std::move(ec));
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

This code looks a bit contrived and artificial, but from my best reading of
P0323R1 it is minimal. I would say that the reference library actually
declares `expected<T, E = std::exception_ptr>` as the default, so let's rewrite
the above to match that design instead:

\code
// Returns the expected opened handle on success, or an unexpected cause of failure
std::expected<handle_ref> openfile(const char *path) noexcept
{
  int fd = -1;
  try
  {
    fd = open(path, O_RDONLY);
    if(fd == -1)
    {
      return std::system_error(std::error_code(errno, std::system_category()));
    }
    return handle_ref(new some_derived_handle_implementation(fd));
  }
  catch(...)
  {
    if(fd == -1)
      close(fd);
    return std::unexpected<>(std::current_exception());
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

This looks much more like how `expected<T, E>` is supposed to be used. It
also demonstrates for the first time a design pattern which Outcome is
designed to ease writing: *islands of exception throw in a sea of noexcept*.

\subsection islands Islands of exception throw in a sea of `noexcept`

To be continued ...
