+++
title = "Frequently asked questions"
weight = 30
+++

{{% toc %}}

## Is Outcome safe to use in extern APIs?

Outcome is specifically designed for use in the public interfaces of multi-million
line codebases. `result`'s layout is hard coded to:

```c
struct
{
  T value;
  unsigned int flags;
  EC error;
};
```

This is C-compatible if `T` and `EC` are C-compatible. {{% api "std::error_code" %}}
is *probably* C-compatible, but its layout is not standardised (though there is a
normative note in the standard about its layout). Hence Outcome cannot provide a
C macro API for standard Outcome, but we can for [Experimental Outcome]({{< relref "/experimental/c-api" >}}).


## Does Outcome have a stable ABI and API?

Right now, no. Though the data layout shown above is not expected to change.

Outcome's ABI and API will be formally fixed as **the** v2 interface approximately
one year after its first Boost release. Thereafter the
[ABI compliance checker](https://lvc.github.io/abi-compliance-checker/)
will be run per-commit to ensure Outcome's ABI and API remains stable.

Note that the stable ABI and API guarantee will only apply to standalone
Outcome, not to Boost.Outcome. Boost.Outcome has dependencies on other
parts of Boost which are not stable across releases.


## Why two types `result<>`  and `outcome<>`, rather than just one?

`result` is the simple, success OR failure type.

`outcome` extends `result` with a third state to transport, conventionally (but not necessarily) some sort of "abort" or "exceptional" state which a function can return to indicate that not only did the operation fail, but it did so *catastrophically* i.e. please abort any attempt to retry the operation.

A perfect alternative to using `outcome` is to throw a C++ exception for the abort code path, and indeed most programs ought to do exactly that instead of using `outcome`. However there are a number of use cases where choosing `outcome` shines:

1. Where C++ exceptions or RTTI is not available, but the ability to fail catastrophically without terminating the program is important.
2. Where deterministic behaviour is required even in the catastrophic failure situation.
3. In unit test suites of code using Outcome it is extremely convenient to accumulate test failures into an `outcome` for later reporting. A similar convenience applies to RPC situations, where C++ exception throws need to be accumulated for reporting back to the initiating endpoint.
4. Where a function is "dual use deterministic" i.e. it can be used deterministically, in which case one switches control flow based on `.error()`, or it can be used non-deterministically by throwing an exception perhaps carrying a custom payload.


## How badly will including Outcome in my public interface affect compile times?

The quick answer is that it depends on how much convenience you want.

The convenience header `<result.hpp>` is dependent on `<system_error>` or Boost.System, which unfortunately includes `<string>` and thus
drags in quite a lot of other slow-to-parse stuff. If your public interface already includes `<string>`,
then the impact of additionally including Outcome will be low. If you do not include `<string>`,
unfortunately impact may be relatively quite high, depending on the total impact of your
public interface files.

If you've been extremely careful to avoid ever including the most of the STL headers
into your interfaces in order to maximise build performance, then `<basic_result.hpp>`
can have as few dependencies as:

1. `<cstdint>`
2. `<initializer_list>`
3. `<iosfwd>`
4. `<new>`
5. `<type_traits>`
6. `<cstdio>`
7. `<cstdlib>`
8. `<cassert>`

These, apart from `<iosfwd>`, tend to be very low build time impact in most standard
library implementations. If you include only `<basic_result.hpp>`, and manually configure
`basic_result<>` by hand, compile time impact will be minimised.

(See reference documentation for {{% api "basic_result<T, E, NoValuePolicy>" %}} for more detail.


## Is Outcome suitable for fixed latency/predictable execution coding such as for high frequency trading or audio?

Great care has been taken to ensure that Outcome never unexpectedly executes anything
with unbounded execution times such as `malloc()`, `dynamic_cast<>()` or `throw`.
Outcome works perfectly with C++ exceptions and RTTI globally disabled.

Outcome's entire design premise is that its users are happy to exchange a small, predictable constant overhead
during successful code paths, in exchange for completely predictable failure code paths.

In contrast, table-based exception handling gives zero run time overhead for the
successful code path, and completely unpredictable (and very expensive) overhead
for failure code paths.

For code where predictability of execution, no matter the code path, is paramount,
writing all your code to use Outcome is not a bad place to start. Obviously enough,
do choose a non-throwing policy when configuring `outcome` or `result` such as
{{% api "all_narrow" %}} to guarantee that exceptions can never be thrown by Outcome
(or use the convenience typedef for `result`, {{% api "unchecked<T, E = varies>" %}} which uses `policy::all_narrow`).


## What kind of runtime performance impact will using Outcome in my code introduce?

It is very hard to say anything definitive about performance impacts in codebases one
has never seen. Each codebase is unique. However to come up with some form of measure,
we timed traversing ten stack frames via each of the main mechanisms, including the
"do nothing" (null) case.

A stack frame is defined to be something called by the compiler whilst
unwinding the stack between the point of return in the ultimate callee and the base
caller, so for example ten stack allocated objects might be destructed, or ten levels
of stack depth might be unwound. This is not a particularly realistic test, but it
should at least give one an idea of the performance impact of returning Outcome's
`result` or `outcome` over say returning a plain integer, or throwing an exception.

{{% figure src="/faq/results_log.png" title="Log graph comparing GCC 7.4, clang 8.0 and Visual Studio 2017.9 on x64, for exceptions-globally-disabled, ordinary and link-time-optimised build configurations." %}}

As you can see, throwing and catching an exception is
expensive on table-based exception handling implementations such as these, anywhere
between 26,000 and 43,000 CPU cycles. And this is the *hot path* situation, this
benchmark is a loop around hot cached code. If the tables are paged out onto storage,
you are talking about **millions** of CPU cycles.

Simple integer returns (i.e. do nothing null case)
are always going to be the fastest as they do the least work, and that costs 80 to 90
CPU cycles on this Intel Skylake CPU.

Note that returning a `result<int, std::error_code>` with a "success (error code)"
is no more than 5% added runtime overhead over returning a naked int on GCC and clang. On MSVC
it costs an extra 20% or so, mainly due to poor code optimisation in the VS2017.9 compiler. Note that "success
(experimental status code)" optimises much better, and has almost no overhead over a
naked int.

Returning a `result<int, std::error_code>` with a "failure (error code)"
is less than 5% runtime overhead over returning a success on GCC, clang and MSVC.

You might wonder what happens if type `E` has a non-trivial destructor, thus making the
`result<T, E>` have a non-trivial destructor? We tested `E = std::exception_ptr` and
found less than a 5% overhead to `E = std::error_code` for returning success. Returning a failure
was obviously much slower at anywhere between 300 and 1,100 CPU cycles, due to the
dynamic memory allocation and free of the exception ptr, plus at least two atomic operations per stack frame, but that is
still two orders of magnitude better than throwing and catching an exception.

We conclude that if failure is anything but extremely rare in your C++ codebase,
using Outcome instead of throwing and catching exceptions ought to be quicker overall:

- Experimental Outcome is statistically indistinguishable from the null case, for
both returning success and failure, on all compilers.
- Standard Outcome is less than 5%
worse than the null case for returning successes on GCC and clang, and less than 10% worse than
the null case for returning failures on GCC and clang.
- Standard Outcome optimises
poorly on VS2017.9, indeed markedly worse than on previous point releases, so let's
hope that Microsoft fix that soon. It currently has a less than 20% overhead on the null case.


## Can I use result<T,EC> across DLL boundaries?

The class template result<T, EC> itself has been designed to be safe for inter-DLL usage.
The only question is whether the T and especially the EC are safe for inter-DLL usage.
Specifically std::error_code is not guaranteed to be safe because standard does not recognize existance of DLLs or shared libraries, although [some](https://stackoverflow.com/a/32656333/700825) implementations of standard library may provide this guarantee voluntarily.
boost::system::error_code currently(version [1.69](https://www.boost.org/doc/libs/1_69_0/libs/system/doc/html/system.html#ref_synopsis)) explicitly offers this guarantee, and can be used across DLL boundaries.



## Why is implicit default construction disabled?

This was one of the more interesting points of discussion during the peer review of
Outcome v1. v1 had a formal empty state. This came with many advantages, but it
was not felt to be STL idiomatic as `std::optional<result<T>>` is what was meant, so
v2 has eliminated any legal possibility of being empty.

The `expected<T, E>` proposal of that time (May 2017) did permit default construction
if its `T` type allowed default construction. This was specifically done to make
`expected<T, E>` more useful in STL containers as one can say resize a vector without
having to supply an `expected<T, E>` instance to fill the new items with. However
there was some unease with that design choice, because it may cause programmers to
use some type `T` whose default constructed state is overloaded with additional meaning,
typically "to be filled" i.e. a de facto empty state via choosing a magic value.

For the v2 redesign, the various arguments during the v1 review were considered.
Unlike `expected<T, E>` which is intended to be a general purpose Either monad
vocabulary type, Outcome's types are meant primarily for returning success or failure
from functions. The API should therefore encourage the programmer to not overload
the successful type with additional meaning of "to be filled" e.g. `result<std::optional<T>>`.
The decision was therefore taken to disable *implicit* default construction, but
still permit *explicit* default construction by making the programmer spell out their
intention with extra typing.

To therefore explicitly default construct a `result<T>` or `outcome<T>`, use one
of these forms as is the most appropriate for the use case:

1. Construct with just `in_place_type<T>` e.g. `result<T>(in_place_type<T>)`.
2. Construct via `success()` e.g. `outcome<T>(success())`.
3. Construct from a `void` form e.g. `result<T>(result<void>(in_place_type<void>))`.


## How far away from the proposed `std::expected<T, E>` is Outcome's `checked<T, E>`?

Not far, in fact after the first Boost.Outcome peer review in May 2017, Expected moved
much closer to Outcome, and Outcome deliberately provides {{% api "checked<T, E = varies>" %}}
as a semantic equivalent.

Here are the remaining differences which represent the
divergence of consensus opinion between the Boost peer review and WG21 on the proper
design for this object:

1. `checked<T, E>` has no default constructor. Expected has a default constructor if
`T` has a default constructor.
2. `checked<T, E>` uses the same constructor design as `std::variant<...>`. Expected
uses the constructor design of `std::optional<T>`.
3. `checked<T, E>` cannot be modified after construction except by assignment.
Expected provides an `.emplace()` modifier.
4. `checked<T, E>` permits implicit construction from both `T` and `E` when
unambiguous. Expected permits implicit construction from `T` alone.
5. `checked<T, E>` does not permit `T` and `E` to be the same, and becomes annoying
to use if they are constructible into one another (implicit construction self-disables).
Expected permits `T` and `E` to be the same.
6. `checked<T, E>` throws `bad_result_access_with<E>` instead of Expected's
`bad_expected_access<E>`.
7. `checked<T, E>` models `std::variant<...>`. Expected models `std::optional<T>`. Thus:
   - `checked<T, E>` does not provide `operator*()` nor `operator->`
   - `checked<T, E>` `.error()` is wide (i.e. throws on no-value) like `.value()`.
   Expected's `.error()` is narrow (UB on no-error). [`checked<T, E>` provides
   `.assume_value()` and `.assume_error()` for narrow (UB causing) observers].
8. `checked<T, E>` uses `success<T>` and `failure<E>` type sugars for disambiguation.
Expected uses `unexpected<E>` only.
9. `checked<T, E>` requires `E` to be default constructible.
10. `checked<T, E>` defaults `E` to `std::error_code` or `boost::system::error_code`.
Expected does not default `E`.

In fact, the two are sufficiently close in design that a highly conforming `expected<T, E>`
can be implemented by wrapping up `checked<T, E>` with the differing functionality:

{{% snippet "expected_implementation.cpp" "expected_implementation" %}}


## Why doesn't Outcome duplicate `std::expected<T, E>`'s design?

There are a number of reasons:

1. Outcome is not aimed at the same audience as Expected. We target developers
and users who would be happy to use Boost. Expected targets the standard library user.

2. Outcome believes that the monadic use case isn't as important as Expected does.
Specifically, we think that 99% of use of Expected in the real world will be to
return failure from functions, and not as some sort of enhanced or "rich" Optional.
Outcome therefore models a subset of Variant, whereas Expected models an extended Optional.

3. Outcome believes that if you are thinking about using something like Outcome,
then for you writing failure code will be in the same proportion as writing success code,
and thus in Outcome writing for failure is exactly the same as writing for success.
Expected assumes that success will be more common than failure, and makes you type
more when writing for failure.

4. Outcome goes to considerable effort to help the end user type fewer characters
during use. This results in tighter, less verbose, more succinct code. The cost of this is a steeper
learning curve and more complex mental model than when programming with Expected.

5. Outcome has facilities to make easier interoperation between multiple third
party libraries each using incommensurate Outcome (or Expected) configurations. Expected does
not do any of this, but subsequent WG21 papers do propose various interoperation
mechanisms, [one of which](https://wg21.link/P0786) Outcome implements so code using Expected will seamlessly
interoperate with code using Outcome.
