+++
title = "Frequently asked questions"
weight = 30
+++

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
