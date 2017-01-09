# Outcome and the upcoming std::expected<T, E> {#std-expected}

C++ 17 isn't finished at the time of writing, but we are very sure that at least
<a href="http://en.cppreference.com/w/cpp/utility/optional">`std::optional<T>`</a>
will be in it. It remains to be seen if LEWG's `expected<T, E>` will make it,
if not then most STL implementations will probably ship an implementation as an experimental
and if your STL does not, there is always the reference implementation at https://github.com/viboes/std-make
which ought to work on any C++ 14 compiler.

\note LEWG is the C++ standard committee's Library Evolution Working Group. They work
on improving the C++ standard runtime library which will gain `std::optional<T>` and
`std::variant<...>` in C++ 17 and probably `std::expected<T, E>` in C++ 17 or C++ 20.

The following discussion is based on `expected<T, E>` as detailed by
<a href="http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0323r1.pdf">P0323R1</a>
which is the latest LEWG proposal paper at the time of writing (Nov 2016) and indeed
one where `expected<T, E>` was pared down significantly from its original proposal. It
should be noted that C++ may yet end up adopting something quite different, though
given how long `expected<T, E>` has been around by now, and how well it fits
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
that I am aware of, and P0323R1's reduced `expected<T, E>` has ended up having a huge
resemblance to Outcome in every day usage. It is heartening that the committee have
made most of the changes I also made in Outcome, as that suggests I am on the right track.
Outcome's slightly different design still contributes a lot of value for the specific
use of error handling in my opinion, as we shall hopefully see next.


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
to file-not-found as reason to **abort**.

Enter LEWG's proposed `expected<T, E>` which can hold either an expected value of
type `T` or an unexpected value of type `E`. Like `variant<T, E>`, `expected<T, E>`
is a discriminated union storing either `T` or `E` in the same storage space, but
unlike the variant, expected treats the `T` as a positive thing (fetchable via a
`.value()`) and `E` as a negative thing (fetchable via an `.error()`). Because
`expected<T, E>` provides a "almost never empty" guarantee similar to variant,
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
let's rewrite the above to match an `E = std::exception_ptr` design instead:

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
      throw;
  }
  // All other exception types were rethrown
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
    int code = errno;
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
including myself. This is likely why Rust adopted it.

However I must admit that after more than a year of using Outcome I haven't found myself
using this design a great deal. It fits well for some codebases, but very much a
minority. The problem in my opinion is that the cost of writing and maintaining correct
and fully tested code which can invert control flow at any moment is high
and typically very much underestimated. Therefore, it is only in some code bases
that it is worth placing that high burden on the code, and in most code bases it is not.
Hence in most code bases I write forwards only execution code where there is no
possible way of inverting control flow at all i.e. no exceptions can be thrown,
despite that exceptions are available.

<br><hr><br>

\section introduction Introducing Outcome

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
<a href="https://groups.google.com/a/isocpp.org/forum/#!forum/sg14">WG21 SG14</a> is working upon. It
therefore works perfectly with exceptions and RTTI disabled and its CI compiles per
commit typical use cases of Outcomes and counts the assembler operations emitted by GCC, clang and MSVC to ensure
code bloat is kept optimally minimal. On all recent GCCs and clangs, if the compiler's
optimiser can infer the state of an outcome, **all runtime overhead due to the outcome
ought to be completely eliminated** (sans optimiser bugs which appear from time to time). This
means for inlined code if you return a `result<T>(T(...))`, the compiler will generate
identical code as if you had returned a `T(...)` directly.
2. Outcome's actual core implementation is `boost::outcome::basic_monad<Policy<T, EC, E>>` with these
convenience typedefs:
 \code
 template<class T> using outcome = basic_monad< monad_policy<T, std::error_code, std::exception_ptr>>;
 template<class T> using result  = basic_monad<result_policy<T, std::error_code, void>>;
 template<class T> using option  = basic_monad<option_policy<T, void, void>>;
 \endcode 
 You can use any type `EC` or `E` you like so long as they act as if a `std::error_code`
 and a `std::exception_ptr` respectively e.g. `boost::error_code` and `boost::exception_ptr`.
 **Unlike** the `E` in `expected<T, E>`, Outcome hard codes the model of `EC` and `E` in stone,
 so they *must* provide at least the same APIs and behaviours as an error code and an
 exception pointer or be `void`, in which case the specialisation doesn't provide the ability
 to store an instance of that type.
3. As suggested by the presence of an `option<T>` convenience typedef, all `basic_monad<>` instances have a
formal empty state. There is no <a href="http://en.cppreference.com/w/cpp/utility/variant/valueless_by_exception">"almost never empty" guarantee</a> which
enables sane semantics when exceptions are disabled and also to not confuse the compiler's
optimiser with complex potential branches in move construction (which can cause the optimiser
to give up prematurely). It sidesteps handling the problem of move assignment throwing an
exception, in which case Outcomes are left in an empty state. It ensures all `basic_monad<>`
are constexpr default constructible. If you attempt to get a value from an empty Outcome,
the compiler will throw an `outcome::monad_error` if exceptions are available, else it
calls the macro `BOOST_OUTCOME_THROW_MONAD_ERROR()` which by default dumps a stack trace
and terminates the process.
4. Like `expected<T, E>`, **explicit** conversion exists from any `basic_monad<Policy<T1, EC1, E1>>` to
any `basic_monad<Policy<T2, EC2, E2>>` if all of `T2`, `EC2` and `E2` are constructible from
`T1`, `EC1` and `E1` respectively. `basic_monad<Policy<void>>` has special significance: you
can always **implicitly** safely construct any arbitrary `basic_monad<Policy<T>>` from any
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
trivial for users to supply custom comparison and hashing operations to the STL associative
map if they ever really needed to store Outcomes in associative maps.
9. Finally, Outcome goes out of its way to be as cheap on compile time as possible by having
the compiler do as little work as possible if not optimising. A lot of the hard coded rigidity
above stems from systematically avoiding, whenever possible, metaprogramming, SFINAE, instantiation of helper types
during deduction, or doing anything which would cause the compiler to not use `O(1)` constant
time operations during non-optimising compilation. I have also found empirically that there
is also a useful side effect of this simplicity of implementation on helping the compiler's
optimiser "to do the right thing" by eliminating assembler generated when facing real world use cases.

 The reason for this minimum compile time load approach was due to my work experience
with original prototype Boost.Expected in 2015 where we saw large increases in compile times
once Expected was deployed at scale - remember
*every single function* is returning an instance of one of these and much branch logic is working
with them in every function, potentially instantiating lots of shim and helper deduction and
introspection types each time. P0323R1 Expected removes a large chunk of metaprogrammed functionality,
specifically the monadic operations which should help a great deal. Nevertheless, from
my best reading, P0323R1 Expected still demands more from the compiler than Outcome does.
Deploying Outcome into a large C++ codebase ought to have as minimal a compile time impact
as possible for a variant implementation, something which matters on code bases heading into
the tens of millions of lines like many potential low latency/high performance users will have.
