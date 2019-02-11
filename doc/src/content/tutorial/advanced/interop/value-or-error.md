+++
title = "ValueOrError Concept"
weight = 7
tags = [ "value-or-error" ]
+++

Something not really mentioned until now is how Outcome interoperates with the proposed
{{% api "std::expected<T, E>" %}}, whose design lands in between {{% api "unchecked<T, E = varies>" %}}
and {{% api "checked<T, E = varies>" %}} (both of which are type aliases hard coding no-value
policies [as previously covered in this tutorial]({{< relref "/tutorial/essential/no-value/builtin" >}})).

Expected and Outcome are [isomorphic to one another in design intent]({{< relref "/faq" >}}#why-doesn-t-outcome-duplicate-std-expected-t-e-s-design), but interoperation
for code using Expected and Outcome ought to be seamless thanks to the [proposed `ValueOrError`
concept framework](https://wg21.link/P0786), a subset of which Outcome implements.

The {{% api "explicit basic_result(ValueOrError<T, E> &&)" %}} and {{% api "explicit basic_outcome(ValueOrError<T, E> &&)" %}}
constructors will explicitly construct from any type matching the {{% api "ValueOrError<T, E>" %}}
concept, which includes `std::expected<A, B>`, if `A` is constructible to `X`, and `B` is
constructible to `Y`. The `ValueOrError` concept in turn is true if and only if the input type has:

1. A `.has_value()` observer returning a `bool`.
2. `.value()` and `.error()` observers.

## Implementation

Outcome's machinery for implementing `ValueOrError` conversion is user extensible by injection
of specialisations of the `value_or_error<DEST, SRC>` type into the `OUTCOME_V2_NAMESPACE::convert` namespace.

Outcome's default `convert::value_or_error<DEST, SRC>` implementation explicitly excludes Outcome `result`
and `outcome` types from the default mechanism as there is a major gotcha:
Outcome's `.value()` is often not callable in constexpr as it can throw, which makes this mechanism pretty much
useless for constexpr code. Thus separate explicit converting constructors exist which constexpr convert
from any Outcome type (though note that `result` construction from `outcome` does use the
`ValueOrError` mechanism).

Examples of how to implement your own `convert::value_or_error<DEST, SRC>` converter
is demonstrated in the worked example, next.