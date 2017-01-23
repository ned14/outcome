# Outcome and the upcoming C++ 20 std::expected<T, E>
\anchor std-expected

C++ 17 isn't finished at the time of writing, but we are very sure that at least
<a href="http://en.cppreference.com/w/cpp/utility/optional">`std::optional<T>`</a>
will be in it. It remains to be seen if LEWG's `expected<T, E>` will make it,
if not then most STL implementations will probably ship an implementation as an experimental
and if your STL does not, there is always the reference implementation at https://github.com/viboes/std-make
which ought to work on any C++ 14 compiler.

\note LEWG is the C++ standard committee's Library Evolution Working Group. They work
on improving the C++ standard runtime library which will gain `std::optional<T>` and
`std::variant<...>` in C++ 17 and probably `std::expected<T, E>` in C++ 20.
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

LEWG's proposed `expected<T, E>` as per P0323R1 can hold either an expected value of
type `T` or an unexpected value of type `E`. Like `variant<T, E>`, `expected<T, E>`
is a discriminated union storing either `T` or `E` in the same storage space, but
unlike the variant, expected treats the `T` as a positive thing (fetchable via a
`.value()`) and `E` as a negative thing (fetchable via an `.error()`). Because
`expected<T, E>` provides an "almost never empty" guarantee similar to variant,
it currently requires type `E` to be nothrow copy and move constructible and assignable.
Expected is a bit less intuitive to use than optional, but its rules are straightforward:
`expected<T, E>` will greedily and implicitly construct from any type from which a `T` can be constructed,
after which it will hold an instance of `T`. If you wish to construct an `expected<T, E>`
holding an instance of unexpected `E`, you need to feed it an `unexpected<E>` which is
type sugar to indicate you want an instance of `E` implicitly converted into an `expected<T, E>`.
As with everything else in C++ 11 onwards, there is a `make_expected(T)` and a `make_unexpected(E)`
which do any type deduction and conversion for you into the right contents of `expected<T, E>`.

All this sounds a bit complex, but really it's much easier to use. Here is a
non-throwing implementation of the tutorial's `openfile()` based on `expected<T, E>`

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
if(fh_)
{
  handle_ref fh = std::move(fh_.value());
  fh->read(... etc
}
~~~

\note The prototype Boost.Expected library and the P0323R1 reference library actually
declares `expected<T, E = std::exception_ptr>` as the default despite that P0323R1
specifies `expected<T, E = std::error_condition>` as the default. I have no
idea why LEWG would use error condition as a default, such a default would lose
information for users so I have assumed they'll change it to error code soon.

<br><hr><br>

\section design_differences Design differences between Expected and Outcome

After all the documentation to date, one might think that Outcome
and Expected are interchangeable. They do cover substantially similar ground and in
the semantic sense they are the same thing, however where Expected is intended as a
generic fundamental type useful for many things, Outcome is specifically
intended as a universal error handling framework capable of lossless propagation of
all possible kinds of C++ error with the least possible runtime and compile time
overhead. It could be considered as a "fixed feature" Expected specialised for the
use case of handling errors only. Here are the exact differences:

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
 ~~~{.cpp}
 template<class T> using outcome = basic_monad< monad_policy<T, std::error_code, std::exception_ptr>>;
 template<class T> using result  = basic_monad<result_policy<T, std::error_code, void>>;
 template<class T> using option  = basic_monad<option_policy<T, void, void>>;
 ~~~
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
