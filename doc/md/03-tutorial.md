# Tutorial
\anchor tutorial

[TOC]

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

Summarising this into a design pattern:

\subsection sea-of-noexcept The "Islands of exception throw in a sea of noexcept" design pattern

This design pattern was intended by the committee in C++ 11 to be the method by which that large
minority of C++ users who disable RTTI and exceptions entirely could be brought
back into ISO standard C++. The pattern is easy:
1. Every `extern` API in your translation unit is marked `noexcept` and uses a
non-throwing mechanism such as `std::error_code` or even a C-style integer to return errors.
2. Functions within a translation unit not called from outside are generally not marked `noexcept`, or indeed
may throw and catch exceptions before returning out of an extern `noexcept` API.
3. Because all `extern` function calls are `noexcept` throughout the entire codebase,
from any given translation unit it is never the case that implementation code will
ever call a potentially throwing function (C APIs are assumed to never throw on
most C++ compilers). Because no calls to unknown code will ever throw, the compiler's
optimiser *ought* to elide emission of stack unwind code and all other exception throw handling
overhead in any sequence of code inside the translation unit *as if* exceptions had
been globally disabled at the command line.
4. Where code inside a translation unit does call something which could throw e.g.
much of the STL, exception handling overhead *ought* to be confined to the containing `try` ...
`catch` **island** at best, at worst to that given translation unit.
5. Consumers of your `extern` API need not care how that API is internally implemented
as they shall never see an exception thrown out of that API, and the compiler will
optimise your code which uses that `extern` API in its **sea** of `noexcept` accordingly.

<hr><br>

\section cpp17-style C++ 17 style error handling: outcome<T>, result<T> and option<T>

We are finally onto Outcome. Outcome provides three simple utility classes:
<dl>
  <dt>`option<T>`</dt>
  <dd>Either empty, or an instance of type `T`.</dd>
  <dt>`result<T>`</dt>
  <dd>One of empty, an instance of type `T` or a `std::error_code`.</dd>
  <dt>`outcome<T>`</dt>
  <dd>One of empty, an instance of type `T`, a `std::error_code` or a `std::exception_ptr`.</dd>
</dl>

All three of these are actually the same \ref boost::outcome::v1_xxx::basic_monad "basic_monad<>"
class specialised with a policy which very closely matches `basic_monad<>`'s semantics to the C++ 17/20 utility classes
`std::optional<T>` and `std::experimental::expected<T, E>` (this hasn't been approved
yet by ISO WG21, but it's very close, likely later in 2017). In addition you gain a much more
comprehensive monadic programming interface, and ultra low runtime overheads. But we will come
back to that later.

Each of `option<T>`, `result<T>` and `outcome<T>` being actually a `basic_monad<>` instance
have a very straightforward API, and less expressive monads implicitly convert into more
expressive forms on demand. We will call the type `T` the value type, the error type
will be any `std::error_code` present and the exception type will be any `std::exception_ptr` present.
- You retrieve a value type using the `value()` or `get()` member functions. These come
with const lvalue ref, lvalue ref and rvalue ref overloads, so you can directly modify or
move from a contained value.
- You retrieve an error type using the `error()` or `get_error()` member functions.
- You retrieve an exception type use the `exception()` or `get_exception()` member functions.
- There are also state inspection member functions which have the entirely unsurprising
nomenclature `empty()`, `has_value()`, `has_error()` and `has_exception()`.
- Semantics of things like `emplace()`, `operator*()` and `operator->()` all
behave exactly the same as `std::optional<T>` and `std::experimental::expected<T, E>`,
and indeed exactly as you would intutively guess as they behave the same as anywhere in the STL.
- `if(monad)` is true if and only if the monad contains an instance of `T`.

What happens if you try retrieving a value from a monad not containing a value?
- If it is empty, the macro `BOOST_OUTCOME_THROW_MONAD_ERROR(monad_error(monad_errc::no_state))`
is executed. This can be user redefined to do anything, but the default implementation throws
a C++ exception of type \ref boost::outcome::v1_xxx::monad_error "monad_error" with code
\ref boost::outcome::v1_xxx::monad_errc "monad_errc::no_state" if C++ exceptions are enabled
by the compiler. If they are not, it prints a stack backtrace to stderr and aborts the process.
- If it is errored, the macro `BOOST_OUTCOME_THROW_SYSTEM_ERROR(std::system_error(ec))` is executed
where `ec` is the `std::error_code` contained by the monad. Similarly to before, this can be
redefined by the user to do anything, and its default implementation is exactly as earlier.
- If it is excepted, the macro `BOOST_OUTCOME_RETHROW_EXCEPTION(e)` is executed where `e` is
the `std::exception_ptr` contained by the monad.

What happens if you try retrieving an error from a monad not containing an error?
- If it is empty, same as for the retrieving a value from not a valued monad.
- If it is valued, returns a default constructed error code.
- If it is excepted, returns an error code of `monad_category()` with code `monad_errc::exception_present`. 

What happens if you try retrieving an exception from a monad not containing an exception?
- If it is empty, same as for the retrieving a value from not a valued monad.
- If it is valued, returns a default constructed exception ptr.
- If it is errored, returns an exception ptr to a `std::system_error` instance containing
the monad's error code.

Reusing the same `openfile()` example from the earlier examples, this is it written
using Outcome's `result<T>`:

~~~{.cpp}
using namespace BOOST_OUTCOME_V1_NAMESPACE;

// Returns the expected opened handle on success, or an unexpected cause of failure
result<handle_ref> openfile(const char *path) noexcept
{
  int fd = open(path, O_RDONLY);
  if(fd == -1)
  {
    // Normally make_errored_result<>() would take a std::error_code, but for convenience
    // if make_errored_result<>() is given an int, we assume this means a POSIX error
    // code. An additional overload exists on Windows for DWORDs so GetLastError() can be
    // passed directly to make_errored_result<>().

    return make_errored_result<>(errno);
  }
  try
  {
    try
    {
      return handle_ref(new some_derived_handle_implementation(fd));  // result<> implicitly constructs from its `T`
    }
    catch(...)
    {
      close(fd);
      throw;
    }
  }
  /* This macro is a long series of catch(const std::exception_type &) clauses
  converting the STL exception types into their corresponding std::error_code with
  std::generic_category. At the end a catch all clause converts to EAGAIN.
  The error code is then returned via make_errored_result<>. */
  BOOST_OUTCOME_CATCH_EXCEPTION_TO_RESULT
}
...
auto fh_ = openfile("foo");
// We don't mind file not found errors, but anything else is serious
if(!fh_ && fh_.error() != std::errc::no_such_file_or_directory)
{
  // If the error code was not file not found, abort the current operation by
  // throwing the special exception type the STL reserves for transporting an
  // error code
  (void) fh_.value();  // does throw std::system_error(std::move(fh_.error())) for you
}
else if(fh_)  // outcomes are boolean true if and only if they contain a value type
{
  handle_ref fh = std::move(fh_.value());  // extract via move the value type
  fh->read(... etc
}
~~~

Some may feel that the potential loss of information caused by throwing away unknown C++
exception throws is unacceptable. This of course depends on your particular code base,
if you are really sure that you never will throw anything but STL exception types, then
you need not worry. Still, if your code may well throw a custom exception type then this
is what `outcome<T>` is for:

~~~{.cpp}
using namespace BOOST_OUTCOME_V1_NAMESPACE;

// Returns the expected opened handle on success, a cause of not success (error_code),
// or why there was an unexpected and probably catastrophic failure (exception_ptr)
outcome<handle_ref> openfile(const char *path) noexcept
{
  int fd = open(path, O_RDONLY);
  if(fd == -1)
  {
    // result<> is less expressive than outcome<> and so implicitly converts into outcome<>
    return make_errored_result<>(errno);
  }
  try
  {
    return handle_ref(new some_derived_handle_implementation(fd));  // outcome<> implicitly constructs from its `T`
  }
  catch(...)
  {
    close(fd);
    return make_exceptional_outcome<>();  // defaults to using std::current_exception()
  }
}
...
auto fh_ = openfile("foo");
// We don't mind file not found errors, but anything else is serious
if(!fh_)
{
  // If the error code was not file not found, abort by rethrowing the
  // exact error or exception which occurred
  if(!fh_.has_error() || fh_.error() != std::errc::no_such_file_or_directory)
  {
    (void) fh_.value();
  }
}
else
{
  handle_ref fh = std::move(fh_.value());  // extract via move the value type
  fh->read(... etc
}
~~~

This is a really elegant expression of error handling in C++: catastrophic errors are returned
as exception ptrs, non serious errors are returned as error codes. All public APIs are `noexcept`
and therefore calling them never causes an unexpected inversion of control flow. If this aesthetic
appeals to you, then you need to be using Outcome in your code!

You might wonder why one would ever use `result<>` instead of `outcome<>` seeing as it leads
to simpler, more elegant and expressive code? The reason why is that the compiler's optimiser
is required to treat a potential use of `exception_ptr` as a synchronisation event because like
`shared_ptr`, it is implemented using an atomically incremented and decremented reference count.
By "synchronisation event" I mean that the compiler is *required* to assume memory could be modified, and therefore
*must* emit assembler to check the globally visible state rather than elide it. In other words, the compiler can entirely elide
and fuse long sequences of `result<>` to a much greater extent than it can `outcome<>`
because the only globally visible effects of potentially creating an error code is the
effect on global state of instantiating its error category. Therefore the compiler can emit
exactly one call of the error category function, and thereafter assume subsequent calls to
it will not affect globally visible state.

\note The Dinkumware STL supplied with Visual Studio makes any fetch of an error category
an operation with globally visible consequences. Compilers using this STL therefore must
emit a lot more assembler than with other STL implementations. This is part of the reason
why MSVC generates code bloat unlike GCC or clang.

So, to sum up, try to use `option<T>` where that's appropriate. `option<T>` is constexpr
available and very often vanishes entirely from the assembler generated. Try to use
`result<T>` where you don't need a full `outcome<T>` where that's appropriate. And
remember a less expressive form always implicitly converts into a more expressive form,
so you can always feed options into results or outcomes, or results into outcomes.

Let's summarise all this into another new error handling design pattern:

\subsection exceptions-are-exceptional The "Exceptions are exceptional, errors are not failure" design pattern

In addition to the pure "sea of noexcept" for low latency users mentioned earlier, there is one other new
error handling design pattern to mention made possible by
Outcomes which combines "sea of noexcept" with exception throws. The idea is that ordinarily
speaking code never throws an exception, and returns all failures anticipated by the programmer
through `result<T>` as an error_code. If however something
very unexpected occurs, a truly *exceptional* event, we exclusively use exception throws to abort
the current operation entirely. For anyone familiar with Rust, this is **exactly** the Rust
error handling model: Rust's `Result<T>` and `Option<T>` return errors expected by the programmer
whereas a stack unwinding panic of the current thread is how exceptional, programmer
unanticipated events are handled.


\subsection try The BOOST_OUTCOME_TRY(var, expression) macro

A very common operation with monadic transports is the `try` operation which means this
boilerplate:

~~~{.cpp}
// Some other function returning a monad
outcome<handle_ref> openfile(const char *path) noexcept;
// This is the function we are in, it must be returning a monad too
// and sometype is not going to be handle_ref
outcome<sometype> another_function()
{
  ...
  // This is the "try" operation common in Rust or Swift
  // It takes the form try! var = openfile(...);
  handle_ref var;
  {
    outcome<handle_ref> unique_temporary = openfile(...);
    if(unique_temporary.has_error())
    {
      return make_errored_outcome<sometype>(std::move(unique_temporary.error());
    }
    if(unique_temporary.has_exception())
    {
      return make_exceptional_outcome<sometype>(std::move(unique_temporary.exception());
    }
    var = std::move(unique_temporary.value());
  }
}
~~~

In other words, the `try var = openfile(...)` operation examines the monad returned from calling
`openfile(...)` to see if it is errored in some way. If it is, it extracts the error value,
constructs a monad of the return type of the calling function and sets it to be errored to the
same error value, returning immediately. If it is not errored, it extracts/unwraps the contained value
in the monad into the `var` variable which is of the contained value type.

Because of the limitations of C++, Outcome cannot provide a nice syntax like `try var = openfile(...)`.
The best it can do is `BOOST_OUTCOME_TRY(var, openfile(...))` which will declare `var` using `auto`
onto the stack.


\section conclusion Conclusion

This tutorial has been kept deliberately as simple as possible after feedback from the Boost developers'
mailing list, and it has intentionally not covered a large chunk of Outcome's detail.
Further documentation includes \ref advanced "Advanced usage: Outcome as a Monad" and
\ref std-expected "Outcome and the upcoming std::expected<T, E>".

\subsection basic_monad What you need to know about basic_monad

There is some detail which you do need to know if you are to use Outcome in your own code though.
During debugging sessions with code using Outcome you will find much reference `basic_monad<>`
and you ought to understand the signature of its policy so you can read compiler warnings or debug prints:
~~~{.cpp}
template<
  class monad_storage,
  class value_type,
  class error_type,
  class exception_type>
struct BOOST_OUTCOME_MONAD_POLICY_BASE_NAME : public monad_storage
{ ... };
~~~
Any of `value_type`, `error_type` and `exception_type` can be `void`, in which case they are not in
use in this instance. If you are using Microsoft Visual Studio, Outcome provides a debugging visualiser
such that any `basic_monad<>` displays itself without any internal clutter. Just link into your final binary
the `monad.natvis` file.

\subsection error_codes What you need to know about error_code_extended

\todo Talk about error_code_extended

\subsection optimal A demonstration of how optimally tuned code using Outcome becomes

We shall end this tutorial with a demonstration of how little runtime overhead Outcome produces which
was achieved after investing a lot of effort. Unlike
many libraries which claim to care about runtime overhead, Outcome's CIs actually run per-commit a test
suite which compiles various sequences of code using outcomes and counts the assembler instructions
emitted. This ensures changes do not ruin Outcome's laboriously implemented tuning for current compiler
optimisers to make sure they generate minimum runtime overhead. Here is a small program written using
Outcome's monadic operators and lambda bind:

~~~{.cpp}
int main(void)
{
  using namespace boost::outcome;
  result<int> f(5);
  auto g = (f & 6) >> [](auto v) -> int { return v==5 ? 2 : 8; } | 2; 
  return g.value();
}
~~~
So this program will test if f is valued via the AND operator and if so returns a new `result<int>`
containing a 6, that is then bound to the generic lambda which compares the value to 5, and because it
is not returns 8, creating another new `result<int>` (because the lambda returned an `int`) containing
the returned value. The OR operator creates yet another `result<int>` replacing the value with 2 if the
monad were not valued, but because it is valued g will take on the type `result<int>` propagated from the
front and the value 8. So that is at least four `result<int>` instances constructed and destructed above.

Compiling this with GCC 6.2 with `-std=c++1z -S -O3` yields this assembler:
~~~{.s}
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB3280:
	.cfi_startproc
	movl	$8, %eax
	ret
	.cfi_endproc
~~~
To achieve this level of optimiser strength reduction on the big three compilers took a great deal of
tedious trial and error so your code using Outcome didn't have to. Enjoy!
