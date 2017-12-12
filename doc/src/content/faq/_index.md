+++
title = "Frequently asked questions"
weight = 30
+++

{{% toc %}}

## Is Outcome safe to use in extern APIs?

Outcome is specifically designed for use in the public interfaces of multi-million
line codebases. Its layout is hard coded to:

```c
struct
{
  T value;
  unsigned int flags;
  EC error;
};
```

This is, of course, C-compatible and Outcome provides [a macro-based C interface](../tutorial/c-api)
for C code needing to call `extern "C"` C++ functions returning a `result<T, EC>`.


## Does Outcome have a stable ABI and API?

Until Outcome passes a second Boost peer review and enters Boost, no. Once into Boost,
Outcome's ABI and API will be formally fixed as the v2 interface one year after its first Boost release.
Thereafter the [ABI compliance checker](https://lvc.github.io/abi-compliance-checker/)
will be run per-commit to ensure Outcome's ABI and API remains stable.

Note that the stable ABI and API guarantee will only apply to standalone Outcome, not to Boost.Outcome.
Boost.Outcome has dependencies on other parts of Boost which are not stable across releases.


## How badly will including Outcome in my public interface affect compile times?

Outcome is dependent on `<system_error>`, which unfortunately includes `<string>` and thus
drags in quite a lot of other stuff. If your public interface already includes `<string>`,
then the impact of including Outcome will be very low. If you do not include `<string>`,
unfortunately impact may be relatively quite high, depending on the total impact of your
public interface files.

Measures are being taken to remedy this situation however. The first is that C++ Modules
will eliminate much of the impact of being dependent on `<string>`, and Outcome will make
use of C++ Modules where enabled as soon as a compiler does not ICE on Outcome (i.e. Modules
support is implemented specifically for the Microsoft compiler, but said compiler still
internal compiler errors when attempting to create an Outcome Module. Microsoft are aware
of the cause and hope to fix it within the next year or two).

Longer term, SG14 the WG21 study group for low latency/high performance C++ are working on
a `<system_error2>` which remedies some of the problems in `<system_error>`. The dependency
on `<string>` has been removed, and thus any `<system_error2>` would be considerably lower
impact. An Outcome v3 is likely to support any proposed `<system_error2>`, and
that is likely many years away yet as ISO standardisation takes time.


## Is Outcome suitable for fixed latency/predictable execution coding such as for high frequency trading or audio?

Great care has been taken to ensure that Outcome never unexpectedly executes anything
with unbounded execution times such as `malloc()`, `dynamic_cast<>()` or `throw`.
Outcome works perfectly with C++ exceptions and RTTI globally disabled.

Outcome's entire design premise is that its users are happy to exchange a small, predictable constant overhead
during successful code paths, in exchange for completely predictable failure code paths.
In contrast, table-based exception handling gives zero run time overhead for the
successful code path, and completely unpredictable (and very expensive) overhead
for failure code paths.

For code where predictability of execution no matter the code path is paramount,
writing all your code to use Outcome is not a bad place to start. Obviously enough,
do choose a non-throwing policy when configuring `outcome` or `result` such as
`policy::all_narrow` to guarantee that exceptions can never be thrown by Outcome
(or use the convenience typedef for `result`, `unchecked` which uses `policy::all_narrow`).


## What kind of performance benefits will using Outcome in my code bring?

It is very hard to say anything definitive about performance impacts in codebases one
has never seen. Each codebase is unique. However to come up with some form of measure,
we timed returning an error via each of the main mechanisms, doing so over ten stack
frames. A stack frame is defined to be something called by the compiler whilst
unwinding the stack between the point of returning the error and the thing which handles
the error, so for example ten stack allocated objects might be destructed, or ten levels
of stack depth might be unwound. This is not a particularly realistic test, but it
should at least give one an idea of the performance impact of returning Outcome's
`result` or `outcome` over say returning a plain integer, or throwing an exception.

{{% figure src="results_log.png" title="Log graph comparing GCC 7.2, clang 5.0, Visual Studio 2017.5 and XCode 8.2" %}}

As you can see, throwing and catching an exception is
expensive on table-based exception handling implementations such as these, anywhere
between 16,000 and 36,000 CPU cycles. Simple integer returns are always going to be
the fastest as they do the least work, and that costs 90 to 100 CPU cycles.

Note that returning a `result<int, std::error_code>` with an int (result-error-value)
is no additional runtime overhead over returning a naked int on most compilers.

Returning a `result<int, std::error_code>` with an error code (result-error-error)
is no additional runtime overhead over returning a naked int on most compilers.

You might wonder what happens if type `E` has a non-trivial destructor, thus making the
`result<T, E>` have a non-trivial destructor? We tested `E = std::exception_ptr` and
found no performance difference to `E = std::error_code` for returning a value. Returning an error
was obviously much slower at anywhere between 300 and 1,500 CPU cycles due to returning
an exception pointer being at least two atomic operations per stack frame, but that is
still two orders of magnitude better than throwing and catching an exception.

We conclude that if failure is anything but extremely rare in your C++ codebase,
using Outcome instead of throwing and catching exceptions ought to be quicker overall.


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

Not far, in fact after the Boost.Outcome peer review in May 2017, Expected moved
much closer to Outcome. Here are the remaining differences which represent the
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
   Expected's `.error()` is narrow (UB on no-error). (`checked<T, E>` provides
   `.assume_value()` and `.assume_error()` for narrow (UB causing) observers)
8. `checked<T, E>` uses `success<T>` and `failure<E>` type sugars for disambiguation.
Expected uses `unexpected<E>` only.
9. `checked<T, E>` requires `E` to be default constructible.
10. `checked<T, E>` defaults `E` to `std::error_code`. Expected does not default `E`.

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
party libraries each using incommensurate Outcome configurations. Expected does
not do any of this, but subsequent WG21 papers do propose various interoperation
mechanisms, [one of which](https://wg21.link/P0786) Outcome implements so code using Expected will seamlessly
interoperate with code using Outcome.
