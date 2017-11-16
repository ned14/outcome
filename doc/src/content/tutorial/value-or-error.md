+++
title = "ValueOrError Concept"
description = "Interoperating with std::expected<T, E> and other ValueOrError concept matching types."
weight = 80
+++

Something not really mentioned until now is how Outcome interoperates with the proposed
[`std::expected<T, E>`](https://wg21.link/P0323), whose design lands in between `outcome::unchecked<T, E>`
and `outcome::checked<T, E>`, both of which are simplified aliases for `outcome::result<T, E>` [hard
coding the `NoValuePolicy` to a fixed policy](../policies).

Expected and Outcome are [isomorphic to one another in design intent](../../faq/#why-doesn-t-outcome-duplicate-std-expected-t-e-s-design), but interoperation
for code using Expected and Outcome ought to be seamless thanks to the proposed [`ValueOrError`
concept framework](https://wg21.link/P0786), a subset of which Outcome implements.

Outcome's `result<X, Y>` will explicitly construct from any type matching the `ValueOrError`
concept, which includes `std::expected<A, B>`, if `A` is constructible to `X` and `B` is
constructible to `Y`. The `ValueOrError` concept in turn is true if and only if the input type has:

1. A `value_type` and `error_type` member typedefs.
2. A `.has_value()` observer returning a `bool`.
3. `.value()` and `.error()` observers.

## Implementation

Outcome's machinery for implementing `ValueOrError` conversion is user extensible by injection
of specialisations of the `value_or_error<DEST, SRC>` type into the `OUTCOME_V2_NAMESPACE::convert` namespace.

Outcome's default `convert::value_or_error<DEST, SRC>` implementation explicitly excludes Outcome `result`
and `outcome` types from the default mechanism as there is a major gotcha:
Outcome's `.value()` is often not callable in constexpr as it can throw, which makes this mechanism pretty much
useless for constexpr code. Thus separate explicit converting constructors exist which constexpr convert
from any Outcome type (though note that `result` construction from `outcome` does use the
`ValueOrError` mechanism).

No example of how to implement your own `convert::value_or_error<DEST, SRC>` is given here as many
examples of implementation follow in the final tutorial section, next.