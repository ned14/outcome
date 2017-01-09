# Tutorial {#tutorial}

Outcome's utility cannot be fully understood without understanding how C++ does
error handling. Due to C++'s maturity, error handling takes many forms which
we will need to recap first.

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
~~~

Experts will quite correctly chafe at the use of `std::runtime_error` to
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
completed operations can lose other people's data just as much as ignoring errors
and proceeding regardless.


<hr><br>

\section cpp17-style C++ 17 style error handling: outcome<T>, result<T> and option<T>, and their C++ standard near-equivalents optional<T> and expected<T, E>

todo

Reusing the same `openfile()` example from the earlier examples, this is it written
using Outcome's `result<T>`:

~~~{.cpp}
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
~~~


\subsubsection sea-of-noexcept The "Islands of exception throw in a sea of noexcept" design pattern

This design pattern was intended by the committee in C++ 11 to be the method by which that large
minority of C++ users who disable RTTI and exceptions entirely could be brought
back into ISO standard C++. The pattern is easy:
1. Every `extern` API in your translation unit is marked `noexcept` and uses a
non-throwing mechanism such as `std::error_code` or `std::expected<T, E>` or
Outcomes or even a C-style integer to return errors.
2. Code within a translation unit is generally not marked `noexcept`, or indeed
may throw and catch exceptions before returning out of an extern `noexcept` API.
3. Because all `extern` function calls are `noexcept` throughout the entire codebase,
from any given translation unit it is never the case that implementation code will
ever call a potentially throwing function (C APIs are assumed to never throw on
most C++ compilers). Because no calls to unknown code will ever throw, the compiler's
optimiser  *ought* to elide emission of stack unwind code and all other exception throw handling
overhead in any sequence of code inside the translation unit *as if* exceptions had
been globally disabled at the command line.
4. Where code inside a translation unit does call something which could throw e.g.
much of the STL, exception handling overhead *ought* to be confined to the containing `try` ...
`catch` **island** at best, at worst to that given translation unit.
5. Consumers of your `extern` API need not care how that API is internally implemented
as they shall never see an exception thrown out of that API, and the compiler will
optimise your code which uses that `extern` API in its **sea** of `noexcept` accordingly.


\subsubsection exceptions-are-exceptional The "Exceptions are exceptional, errors are not failure" design pattern

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


\subsection cpp17-stl Standardised optional<T> and expected<T, E>
There are useful improvements coming in C++ 17/20 with which one can implement some
new error handling design patterns in addition to those already covered above:
<dl>
  <dt><a href="http://en.cppreference.com/w/cpp/utility/optional">`std::optional<T>`</a></dt>
  <dd>Utility class managing an optional contained value i.e. a value which may or may
  not be present.</dd>
  <dt><a href="http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0323r1.pdf">`std::experimental::expected<T, E>` (P0323R1)</a></dt>
  <dd>Utility class managing one of three variant states, an expected `T` or an unexpected `E`
  or no value (with the no value semantics matching <a href="http://en.cppreference.com/w/cpp/utility/variant">std::variant<...></a>).</dd>
</dl>

Outcome provides convenience typedefs which map \ref boost::outcome::v1_xxx::basic_monad "basic_monad<>"
as close as is feasible onto the standard utility classes:
- `BOOST_OUTCOME_V1_NAMESPACE::option<T>` => `std::optional<T>`
- `BOOST_OUTCOME_V1_NAMESPACE::result<T>` => `std::experimental::expected<T, E = std::error_code>`
- `BOOST_OUTCOME_V1_NAMESPACE::outcome<T>` => no longer any equivalent in the STL
  - but in an earlier proposal for Expected it would have been `std::experimental::expected<T, E = std::experimental::expected<T = std::error_code, E = std::exception_ptr>>`
  i.e. either an expected `T` or an unexpected `std::error_code` or a really unexpected `std::exception_ptr`.

In 95% of use cases, Outcome's convenience typedefs should be typedef-swappable for `optional<T>`
and `expected<T, E>`, and Outcome has been carefully designed to maximise this.
There are some important semantic differences though, for those interested please see \ref std_expected
for lots of detail. In summary, Outcome is intended as an *ultra lightweight universal 
error handling framework* which lets you the programmer seamlessly transport error states
around without adding any extra overhead nor losing any information, folding everything into
C-style returns of some `basic_monad<>` implementation.
It therefore has a different intent and purpose than Expected which is more of a general
purpose building block primitive intended for much more general (i.e. unknown) use cases than Outcome.

Outcome takes absolute minimum runtime overhead unusually seriously, and generates exceptionally tight code
with recent versions of GCC and clang which a design making more use of potential exception
throws currently can not achieve with current compiler optimiser technology.
To achieve its ultra lightweightness, Outcome is written to enable as much as possible current compiler
optimisers to deduce when to elide the underlying variant storage used by `basic_monad<>`
such that if you do `return outcome<int>(5);` then the compiler generates code exactly as if
you wrote `return 5;` i.e. Outcome disappears entirely from the assembler generated.
And this is not some vague aspiration: Outcome's unit test suite actually tests that outcomes
vanish from runtime overhead per commit.
To achieve this with current optimiser technologies, it needs to be implemented less branchy 
and with a formal constexpr empty state to avoid the potential `valueless_by_exception` state
that `expected<T, E>` requires. Another big goal for Outcome is that it works perfectly with
C++ exceptions and RTTI disabled so it is useful for high performance/gaming/finance applications
such as those studied by ISO WG21 SG14. In fact, it is intended to submit Outcome to SG14 for
standardisation as the low latency/high performance friendly close alternative to `expected<T, E>`.

Whether you choose in your own code to use Outcome or the C++ 17/21 STL is up to you, and there
are pro and cons to choosing either. The rest of this tutorial will focus on Outcome
of course, but please do bear in mind that any of the design patterns mentioned during the
remainder of this tutorial can be implemented almost as easily using `expected<T, E>` and
`variant<...>` as using Outcomes. I think you'll find Outcomes are more convenient to use
for error handling, but it wouldn't require you writing much additional macro and type boilerplate to use
Expected and Variant just as easily as your base transports.

\subsection outcome_example Example function using Outcome's result<T>




\subsection examples Examples of usage

The above synopsis of Outcome looks lengthy and complex, but almost all of it is
convenience overloads of one form or other. In usage Outcome is generally "stupid easy"
to program with, especially if you're already used to `std::optional`. Here is a real
world use case distilled from AFIO v2's source code:

\snippet usecase_example.cpp file_create_example

\todo Add link to whole source code in an online compiler explorer so end users can
play with the use case

Unlike the earlier example functions opening a file, the above is not a toy use case
and it covers almost all of the permutations of creating or opening a file which are
common to POSIX and Windows. We make use of the fact that `basic_monad<>``::``value()`
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
and placed in the variable you asked for. If it did not contain a value, the emptiness/errored/exceptioned
state is converted into a void form monad and returned immediately from the calling function,
thus propagating the empty/errored/exceptioned state up the stack. You'll note we cast the stack allocated monad
instance into a rvalue ref before asking for its value, this returns a rvalue ref to the value.
We then pass that rvalue ref through to the variable instance constructor so the value is moved
and not copied when possible. I have disassembled this sequence on the main compilers and found that where
the compiler knows for a fact that a value is being returned, all runtime overhead over a
straight return of a value is usually eliminated.

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
  // Fill a char buffer with the extended message, retrieving the two extended unsigned integer codes
  size_t extended_message(char *buffer, size_t len, unsigned &code1, unsigned &code2) const noexcept;
  // Return an array of strings describing the stack at the time of construction. MUST call free() on this returned pointer.
  char **backtrace() const noexcept;
};
// Prints the extended error code, including any extended information if available
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
codes and most interestingly, a backtrace of the stack at the point of construction. The extended message and backtrace can be later
fetched using the new member functions, though note that the storage for these is kept in a
statically allocated threadsafe ring buffer and so may vanish at some arbitrary later point
when the storage gets recycled. If this happens, `extended_message()` will return zero characters
written and `backtrace()` will return a null pointer.

If you are throwing your own custom types with custom information, you should note that
you can create your own custom extended error code type using the same reusable
microsecond fast threadsafe logging framework that Outcome uses. This won't be documented
here as that framework (`ringbuffer_log`) lives in Boost-lite, but it's fairly easy to study
Outcome's and Boost-lite's source code all of which is on github.












<br><hr><br>

\section when_use When am I supposed to use what when?

The total available permutations may seem overwhelming at this point, because as with any
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
where there is doubt the compiler has no choice but to generate a lot more assembler
to cover all the possible outcomes.
`result<T>` cannot transport a `std::exception_ptr` and therefore doesn't force the
compiler to generate output (except unfortunately on the Dinkumware STL where fetching
a STL error category e.g. `std::generic_category()` uses atomics).

So in short, always use `result<T>` instead of `outcome<T>` where doing so does not
impact negatively on your codebase, and remember one bit of your code can use
`result<T>` and another `outcome<T>` just fine.

\subsection result_vs_outcome When should I use an outcome<T> instead of a result<T>?

The main reason to use an `outcome<T>` is in the "sea of noexcept" design pattern
where implementations may throw exceptions internally, but all public extern APIs are always
noexcept. `outcome<T>` provides a lossless method of exporting the thrown exception
but without loading the programmer with dealing with unexpected control flow reversal,
thus helping the programmer write correct exception safe code faster.

One can implement the "exceptions are exceptional" design pattern easily with Expected:
expected errors are returned via `expected<T, E> = E` and aborting errors are returned via
an exception throw. However the role where using `outcome<T>` really shines is in the "exceptions
are exceptional" combined with "sea of noexcept" design pattern where the errored state
means an expected error which was handled inline, but the exceptioned state means an operation
was aborted, yet the programmer still can easily write exception safe forward-only-execution
code not having to worry about unexpected control flow inversion. This is where using Outcome
adds significant value over using Expected.

Finally, there is a third big reason to use Outcome. The main reason I designed and wrote
Outcome was to implement a universal error handling framework which could express *in the
minimum possible overhead*, and without losing information, the many C++ error handling design patterns possible, and even
more importantly that individual libraries could use the design pattern which best suited
them whilst seamlessly interoperating with other libraries using different error handling
designs. To go into a bit more detail:
* Proposed <a href="https://ned14.github.io/boost.afio/">Boost.AFIO v2</a> is a very low
level very thin file i/o and filesystem library which sits just above the raw kernel syscalls.
Throwing exceptions in such a library is overkill, so AFIO v2 uses the "sea of noexcept"
design pattern both in its public API and in its internal implementation (i.e. it doesn't
use C++ exceptions at all).
* Proposed <a href="https://github.com/ned14/boost.kerneltest">Boost.KernelTest</a> is a
kernel based testing infrastructure which uses Outcomes as the storage for each kernel
permutation run in its permutation tables of preconditions, postconditions, parameters
and outcomes. KernelTest itself is written using the
"exceptions are exceptional" design pattern where expected errors are returned via
outcomes but unexpected errors which abort the test use thrown exceptions which are
collected into `outcome<T>`'s. AFIO v2's test suite is written using KernelTest.
* Planned Boost.BLOBStore will be a versioned, ACID transactional key to BLOB store written
using AFIO v2 which will use both the "sea of noexcept" and the "exceptions are exceptional"
design patterns together. This allows user supplied callbacks to throw exceptions which aborts
the current transaction and for those exceptions to be propagated, if desired, out of BLOBStore
whilst the internal implementation of BLOBStore and indeed its public API is all noexcept
and never throws exceptions (writing correct filesystem code is hard enough without dealing
with unexpected control flow reversal). BLOBStore will also use KernelTest for its test suite.
