+++
title = "ValueOrError Concept"
description = "Interoperating with std::expected<T, E> and other ValueOrError concept matching types."
weight = 80
+++

Something not really mentioned until now is how Outcome interoperates with the proposed
[`std::expected<T, E>`](https://wg21.link/P0323), whose design lands in between `outcome::unchecked<T, E>`
and `outcome::checked<T, E>`, both of which are simplified aliases for `outcome::result<T, E>` hard
coding the `NoValuePolicy` to a fixed policy.

Expected and Outcome are [isomorphic to one another in design intent](../../faq/#why-doesn-t-outcome-duplicate-std-expected-t-e-s-design), but interoperation
for code using Expected and Outcome ought to be seamless thanks to the proposed [`ValueOrError`
concept framework](https://wg21.link/P0786), a subset of which Outcome implements.

Outcome's `result<X, Y>` will explicitly construct from any type matching the `ValueOrError`
concept, which includes `std::expected<A, B>`, if `A` is constructible to `X` and `B` is
constructible to `Y`. The `ValueOrError` concept in turn is true if and only if the input type has:

1. A `value_type` and `error_type` member typedefs.
2. A `.has_value()` observer returning a `bool`.
3. `.value()` and `.error()` observers.

Outcome's default `convert::value_or_error(U&&)` implementation explicitly excludes Outcome `result`
types from this mechanism as there is a major gotcha:
`.value()` is often not callable in constexpr, which makes this built-in interoperation support pretty much
useless for constexpr code. Thus separate explicit converting constructors exist which will constexpr convert
from any `result<A, B>`.

You may inject your own custom `value_or_error()` converters into the `OUTCOME_V2_NAMESPACE::convert`
namespace. If an overload is available for some input `T` and some output `result<A, B>`, the
converting constructor will become available. `T` need not match the `ValueOrError` concept unless
you wish it to.
