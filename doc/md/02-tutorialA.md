# Tutorial part A: Outcome's expected<T, E>
\anchor tutorial_expected

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
1. The first part (part A, this part) provides a broad overview of error handling in
C++ in general and how the `expected<T, E>` proposed for standardisation will contribute
to that big menu of error handling design patterns available to the C++ programmer.
This part isn't relevant to Outcome the library, but places it in context.
2. The second part (\ref tutorial_whynot "part B") describes why you probably ought
to not use unrestricted `expected<T, E>` in any real world code base and why
you ought to use the refinements of `outcome<T>` or `result<T>` instead.
3. The third part (\ref tutorial_outcome "part C") walks you through using Outcome's refinements `outcome<T>`
and `result<T>`, plus its `extended_error_code`. Usage is very similar to Expected,
but with less typing and more convenient extensions.

\section c-style C style error handling: integer returns

Historically C++ 98 code has taken one of two design patterns when returning
errors from functions. This pattern is taken from C, and indeed is pure C:

~~~{.cpp}
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
extern int openfile(struct handle **outh, const char *path)
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
~~~

Almost certainly anyone reading this has seen this error handling design umpteen
times in their career. Variations on the same pattern are returning the enum type
directly, returning a boolean and using a thread locally stored global variable
such as `errno` and so on.


<hr><br>

\section cpp98-style C++ 98 style error handling: throwing exceptions

The second C++ 98 design pattern ought to also be very familiar to readers:

~~~{.cpp}
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
extern handle_ref openfile(const char *path)
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
~~~

Old hands will quite correctly chafe at the use of `std::runtime_error` to
report a file not found, but nevertheless such a design pattern is very
common in the wild, especially in older C++ which went a bit mad on using
exception throws for control flow.


<hr><br>

\section cpp11-style C++ 11 style error handling: error_code and noexcept

C++ 11 brought in two new features to help bridge the gap between the over use of
exception throws to report routine failures and C error handling:
(i) `noexcept` and (ii) the standardisation of
`error_code` from Boost. `noexcept` lets you mark functions with the
guarantee that they shall **never** throw exceptions. This is commonly
described as a feature enabling the compiler and standard library to
use faster algorithms which can assume that operations never need to
be rolled back part way through, however it also enables a whole new way of
writing C++ which we shall call <em>"islands of exception throw in a sea
of noexcept"</em> which will be described later.

\note In some C++ code, marking a function as `noexcept` has the additional
semantic that "this function cannot fail". As the C++ standard does not
say this about `noexcept` and functions marked `noexcept` can absolutely fail,
just not throw exceptions out of themselves, we shall not assume that `noexcept`
means functions marked so cannot fail.

Both the Boost and C++ 11 `error_code` consists of an integer and
a reference to a singleton `error_category` instance. This allows one to set
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

The fact that C++ 11's standard library can *unintrusively* do this with any arbitrary
custom enum or integer error code system is not widely realised. It is
hoped that Outcome helps make more people embrace this feature in their
code (see tutorial part B).

The C++ 11 standard library makes very limited use of `error_code` for
reporting errors, however the Filesystem TS and Networking TS as indeed
much of Boost uses this error handling design pattern extensively:

~~~{.cpp}
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
extern handle_ref openfile(const char *path, std::error_code &ec) noexcept
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
extern handle_ref openfile(const char *path)
{
  std::error_code ec;
  handle_ref ret(openfile(path, ec));
  if(ec)
  {
    throw std::system_error(ec);
  }
  return ret;
}
~~~

This third error handling design pattern has two big advantages:

1. You only pay for what you use, so if you call the non-throwing overload
you are guaranteed by the `noexcept` that execution flow will not unexpectedly
invert. This makes writing correct exception safe code much easier, plus
unpredictable execution times due to exception throws cannot occur. The
compiler can also reduce executable bloat by not generating stack unwind tables
around that call which is useful for some C++ users.
2. Simple usage of the API will default to the throwing (i.e. abort this operation)
overload which is probably what most users *think* they want. This does have
the advantage that the error won't be lost, however in practice aborting partially
completed operations can lose other people's data just as easily as ignoring errors
and proceeding regardless.

Once you've been programming using the non-throwing API form for a while, some
disadvantages begin to become obvious (which upcoming C++ 17/20 library additions
will address):

1. It is clunky for callers of your function to have to create
a `std::error_code` on the stack before calling the function passing in a lvalue
ref. There is a temptation for programmers to reuse the `error_code &ec` instance passed
to their function, and this can become a source of unintended lost errors because
errors already written there get overwritten or reset during error handling.
2. It is annoying having to type more boilerplate and remembering to check return codes just
like in C. The compiler should be telling me when I forget to check an error, but
the C++ 17 `[[nodiscard]]` attribute can't work with the lvalue ref passing pattern.
This design pattern therefore suffers from the same problem as C style error codes,
errors "get lost" or ignored inadvertently.
3. It might not seem a big thing until you see it in a large program, but having
throwing and non-throwing variants of every API means doubling your API count.
That means more maintenance, more testing, more documentation, more clutter.

<hr><br>

\section cpp17-style C++ 17 style error handling: optional<T> and expected<T, E>

There are useful improvements coming in C++ 17/20 with which one can implement some
new error handling design patterns in addition to those already covered above:
<dl>
  <dt><a href="http://en.cppreference.com/w/cpp/utility/optional">`std::optional<T>`</a></dt>
  <dd>Utility class managing an optional contained value i.e. a value which may or may
  not be present. Available in C++ 17.</dd>
  <dt><a href="http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0323r1.pdf">`std::experimental::expected<T, E>` (P0323R1)</a></dt>
  <dd>Utility class managing one of three variant states, an expected `T` or an unexpected `E`
  or valueless due to exception (with the valueless semantics matching <a href="http://en.cppreference.com/w/cpp/utility/variant">`std::variant<...>`</a>).
  Currently expected to be available in C++ 20, if not then very likely in the following C++ standard.</dd>
</dl>

\subsection optional std::optional<T> (C++ 17)

In some programming contexts we don't need to know why an operation failed, only
that it did. Throwing an exception after failing to find a file is a good example
of the kind of failure which is very common and where throwing an exception to
handle that event is excessive and inappropriate. One might therefore design
a routine expected to frequently fail in C++ as:

~~~{.cpp}
// Returns true for success and fills \em out with the opened file, else false
bool openfile(handle_ref &out, const char *path) noexcept;
~~~

Wouldn't it be much nicer though if you didn't force the caller to have to
instantiate a copy of `handle_ref` before each call, not least because such
a requirement messes badly with using `openfile()` in generic template code
and moreover it could be the case that constructing a `handle_ref` is an
atomic operation, and is thus wasted work if the failure to open is very
common? This is where `optional<T>` comes in:

~~~{.cpp}
// Returns the opened handle on success, else an empty optional
extern std::optional<handle_ref> openfile(const char *path) noexcept;
...
auto fh_ = openfile("foo");
if(fh_)
{
  handle_ref fh = std::move(fh_.value());
  fh->read(... etc
}
~~~

`optional<T>` is pretty boring and unsurprising like any good primitive. It's
also fairly intuitive, almost any C++ programmer will immediately understand
what the code above does from inspection.


\subsection expected std::experimental::expected<T, E> (on standards track)

Many familiar with the filesystem will find the above use case of `optional<T>`
unsettling because there are many reasons why one couldn't open a file rather
than merely it was not found. Imagine, for example, that a program is attempting
to open a few thousand files on a networked drive which has broken its connection -
in this case every single failure will take considerable time to return and
there is zero chance *any* file open will ever succeed, so what the user sees
is an apparently hanged program. Far better would be if the `openfile()` function
could return the cause of its failure, and we could then treat all errors which are different
to file-not-found as reason to **abort**.

This where the proposed `expected<T, E>` comes in. It refines `optional<T>` with
variant storage which can hold either an expected value of
type `T` or an unexpected value of type `E`. Like `variant<T, E>`, `expected<T, E>`
is a discriminated union storing either `T` or `E` in the same storage space, but
unlike the variant, expected treats the `T` as a positive thing (fetchable via a
`.value()`) and `E` as a negative thing (fetchable via an `.error()`). Because
`expected<T, E>` provides an "almost never empty" guarantee similar to variant,
it currently requires type `E` to be nothrow copy and move constructible and assignable
and default constructing an `expected<T, E>` will set its variant storage to a default
constructed `T`, so `T` must be default constructible.
Expected is a bit less intuitive to use than optional, but its rules are straightforward:
`expected<T, E>` will greedily and implicitly construct from any type from which a `T` can be constructed,
after which it will hold an instance of `T`. If you wish to construct an `expected<T, E>`
holding an instance of unexpected `E`, you need to feed it an `unexpected_type<E>` which is
type sugar to indicate you want an instance of `E` implicitly converted into an `expected<T, E>`.
As with everything else in C++ 11 onwards, there is a `make_expected(T)` and a `make_unexpected(E)`
which do any type deduction and conversion for you into the right contents of `expected<T, E>`.

All this sounds a bit complex, but really it's much easier to use. Here is a
non-throwing implementation of `openfile()` based on `expected<T, E>`:

~~~{.cpp}
// Returns the expected opened handle on success, or an unexpected cause of failure
extern std::experimental::expected<handle_ref, std::error_code> openfile(const char *path) noexcept
{
  int fd = open(path, O_RDONLY);
  if(fd == -1)
  {
    return std::experimental::make_unexpected(std::error_code(errno, std::system_category());
  }
  std::error_code ec;
  auto *p = new(std::nothrow) some_derived_handle_implementation(fd, ec);
  if(p == nullptr)
  {
    close(fd);
    // C++ 11 lets you convert generic portable error_condition's into a platform
    // specific error_code like this
    return std::experimental::make_unexpected(std::make_error_code(std::errc::not_enough_memory));
  }
  // The some_derived_handle_implementation constructor failed
  if(ec)
  {
    delete p;
    return std::experimental::make_unexpected(std::move(ec));
  }
  return handle_ref(p);  // expected<> takes implicit conversion to type T
}
...
auto fh_ = openfile("foo");
// C++ 11 lets you compare some platform specific error code to a generic
// portable error_condition
if(!fh_ && fh_.error() != std::errc::no_such_file_or_directory)
{
  // This is serious, abort by throwing a system_error wrapping the error code
  throw std::system_error(std::move(fh_.error()));
}
if(fh_)
{
  handle_ref fh = std::move(fh_.value());
  fh->read(... etc
}
~~~

The part in the middle where we pass an `error_code &` to the `some_derived_handle_implementation`
constructor looks a bit weird. So let's rewrite the above to use the "sea of noexcept,
islands of exception throw" design pattern which is much more natural:

~~~{.cpp}
// Returns the expected opened handle on success, or an unexpected cause of failure
extern std::experimental::expected<handle_ref, std::exception_ptr> openfile(const char *path) noexcept
{
  int fd = -1;
  try
  {
    fd = open(path, O_RDONLY);
    if(fd == -1)
    {
      // Convert errno into a platform specific error code and wrap that in a throw of a system error
      throw std::system_error(std::error_code(errno, std::system_category()));
    }
    // Implicit conversion to T (handle_ref)
    return make_handle_ref<some_derived_handle_implementation>(fd);
  }
  catch(...)
  {
    if(fd != -1)
      close(fd);
    return std::experimental::make_unexpected(std::current_exception());
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
    // Ignore file not found errors
    if(e.code() != std::errc::no_such_file_or_directory)
      throw;
  }
  // All other exception types were rethrown
}
if(fh_)
{
  handle_ref fh = std::move(fh_.value());
  fh->read(... etc
}
~~~

You'll note we've changed the error type from a `std::error_code` to a `std::exception_ptr`
in order to transport, without losing information, all possible C++ exception throws.

\subsubsection sea_of_noexcept Sea of noexcept, islands of exception throw

The "sea of noexcept, islands of exception throw" design pattern is characterised by
all `extern` function APIs i.e. all functions callable by code outside the current
translation unit being marked `noexcept`. Because code outside the current translation
unit will only see a header declaration of the form:

~~~{.cpp}
extern std::experimental::expected<handle_ref, std::exception_ptr> openfile(const char *path) noexcept;
~~~

... it is guaranteed by the C++ standard that calling that function will not throw an
exception, and therefore invert the flow of execution. That makes writing exception safe
code considerably easier in a lot of cases, which means lower maintenance and considerably
fewer implicit potential execution paths to test for correctness.

Meanwhile internal to the implementation of `openfile()`, we do throw exceptions, but
there is **always** a master `try...catch(...)` catchall clause at the base of the
function. This is because if you have anything but a catchall try-catch, the compiler is required by the C++
standard to insert a call to `std::terminate()` if any exception throw reaches a noexcept
function boundary. Assuming that you really don't want that to happen, we therefore always
catch all exceptions and convert them into a `std::exception_ptr` which we return out
of the function via the normal value return mechanism as an unexpected Expected instance.

\note Old hands would consider any use of `exception_ptr` to be similarly heavyweight to
any use of `std::shared_ptr` as they need to be implemented the same way (i.e. with malloc and atomics) according to the
C++ standard. For most code this is an acceptable overhead, if that is not the case in your
code then Tutorial part B is for you.

Finally, within any translation unit you do NOT mark non-extern functions with `noexcept`
unless the function cannot fail. Because the compiler can see an entire translation unit
as a single whole, it will deduce which non-extern functions can throw and which can not
(any calls by you into other translation units will use extern functions marked `noexcept`,
hence the only exception throws which the compiler needs to consider will be thrown from
within the current translation unit only). The compiler ought to then optimise the current
translation unit down to an **optimal** edition maximising the regions of code known by
the compiler to be incapable of throwing exceptions, thus eliminating any EH tables etc
for that code. Indeed, if the master catchall try-catch at the base of an extern function
is deduced by the compiler to not be needed, all recent compilers will eliminate that
from the runtime code generated too, effectively making it as if you compiled the
translation unit with C++ exceptions globally disabled.

\subsubsection bad_expected_access Expected's bad_expected_access<E>

The proposed Expected implementation defines this exception type to represent when you try
to use an `expected<T, E>` in a way not compatible with its current state:

~~~{.cpp}
template <class E> class bad_expected_access : public std::logic_error
{
public:
  using error_type = E;

  explicit bad_expected_access(const error_type &e) noexcept;

  const error_type &error() const & noexcept;
  error_type &error() & noexcept;
  const error_type &&error() const && noexcept;
  error_type &&error() && noexcept;
};

// This is currently an extension to the proposal by Outcome, but we think it highly
// likely to be in the next revision of the proposal
template <> class bad_expected_access<void> : public std::logic_error
{
public:
  using error_type = void;

  explicit bad_expected_access() noexcept;
};
~~~

So for example, if you tried to get the value of an Expected when it was errored,
you would see this:

~~~{.cpp}
std::experimental::expected<int, std::error_code> a(std::experimental::make_unexpected(std::make_error_code(std::errc::no_such_file_or_directory)));
try
{
  // a is errored, so this will throw
  a.value();
}
catch(const std::experimental::bad_expected_access<std::error_code> &e)
{
  // expected throws a bad_expected_access<E> with the current value of the E
  std::cerr << "Expected throws bad_expected_access with error " << e.error() << std::endl;
}
~~~

The <a href="http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0323r1.pdf">most recent proposal for Expected (P0323R1)</a>
added the valueless by exception state from Variant,
so if a move or copy constructor or assignment throws, like Variant Expected is left in an
intermediate "valueless" state. The current proposal isn't clear what ought to happen when
you try to get a value or error from such a valueless Expected instance, so Outcome has chosen to
throw a `bad_expected_access<void>` exception when Expected is valueless. We expect the
standards proposal to do something similar next revision, if not we will update Outcome's Expected
implementation to match.

\subsubsection expected_observers Expected's observers

Generally speaking you will not want Expected to throw `bad_expected_access<E>` as a
try-catch cycle is a lot less efficient than simply asking an `expected<T, E>` instance
what state it has before accessing it. Expected has the following highly unsurprising
observers with standard STL semantics and meaning matching those in `std::optional<T>` and
`std::variant<...>`:

~~~{.cpp}
template <class T, class E>
class expected
{
public:
  using value_type = T;
  using error_type = E;
  
  template <class U>
    struct rebind {
      using type = expected<U, error_type>;
    };

  // As if &value()
  constexpr const T* operator ->() const;
  T* operator ->();
  // As if value()
  constexpr const T& operator *() const&;
  T& operator *() &;
  constexpr const T&& operator *() const &&;
  constexpr T&& operator *() &&;
  
  // True if and only if currently storing a value_type
  constexpr explicit operator bool() const noexcept;
  constexpr bool has_value() const noexcept;
  
  // Returns a lvalue or rvalue ref to the stored value_type if there is one, else throws a bad_expected_access<E>
  constexpr const T& value() const&;
  constexpr T& value() &;
  constexpr const T&& value() const &&;
  constexpr T&& value() &&;
  
  // Returns a lvalue or rvalue ref to the stored error_type if there is one, else undefined behaviour
  constexpr const E& error() const&;
  E& error() &;
  constexpr E&& error() &&;
  constexpr const E&& error() const &&;

  // Returns the stored error_type as an unexpected_type<E> if there is one, else undefined behaviour
  constexpr unexpected_type<E> get_unexpected() const;

  // If currently storing a value_type, returns that, else the parameter passed  
  template <class U>
    constexpr T value_or(U&&) const&;
  template <class U>
    T value_or(U&&) &&;

};
~~~

\note You should be aware that Outcome's Expected implementation varies from the above in
a few very minor ways. It also provides a considerable number of extensions. See
\ref outcome_expected_reference "Outcome's implementation of Expected" for an exact detail.

As inferred in the example code cases earlier, you can check if an `expected<T, E>`
has an expected value via a simple test for boolean true or more explicitly via `.has_value()`
before retrieving the value using `.value()`. A useful shortcut can be `.value_or()`
where you would otherwise write a ternary operation selecting on the Expected having
an expected value.

Finally, the current proposal before WG21 has not yet added a mechanism for testing if
the Expected is valueless or not, so you currently have no way of testing for that
except by catching the exception thrown. It *may* mirror `std::variant<...>`'s `valueless_by_exception()`
observer function, or it may choose something else. Outcome's implementation of
Expected implements a '.empty()' extension, this seemed to fit the rest of STL the best.

\section expected_example Short example program using expected<T, E>

Up until now we have been referring to Expected via the namespace `std::experimental`.
Outcome obviously does not provide Expected in that namespace, instead it uses the
outcome namespace which you can find via either of these forms:

~~~{.cpp}
// Traditional: use SOME version Boost.Outcome visible to the compiler/linker
namespace outcome = boost::outcome;

// Better: use EXACTLY the Boost.Outcome visible in the current translation unit
namespace outcome = BOOST_OUTCOME_V1_NAMESPACE;
~~~

The `BOOST_OUTCOME_V1_NAMESPACE` macro encodes a unique hexadecimal value per release. This guarantees
that the linker will not substitute a different version of Outcome than the Outcome you compiled against.
It is therefore recommended that you use the `BOOST_OUTCOME_V1_NAMESPACE` macro.

This example program using `expected<T, E>` replicates <a href="http://rustbyexample.com/std/result.html">the use example in
the documentation for Rust's `Result<T, E>`</a>. As you will see in Tutorial part B, you
would be unwise to use `expected<T, E>` like this in large C++ programs.

\snippet expected_example.cpp expected_example

