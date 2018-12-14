+++
title = "`has_error_code<T>`"
description = "True if an error code can be constructed from a `T`."
+++

True if an error code can be constructed from a `T` e.g. if there exists an ADL discovered free function `make_error_code(T)` and it returns an error code.

*Overridable*: By template specialisation into the `trait` namespace.

*Default*: True if `T` is implicitly constructible to an error code, else to metaprogramming which performs the ADL discovery and testing of the result type of `make_error_code(T)`. Note that the STL defines multiple overloads of an ADL discovered free function {{% api "std::make_error_code(T)" %}} for its error enumerations, as does Boost.System for the Boost error enumerations. Thus this trait will pick up those free functions for those error types.

*Namespace*: `OUTCOME_V2_NAMESPACE::trait`

*Header*: Declared by `<outcome/trait.hpp>`, defined by `<outcome/std_result.hpp>`.

*Variable alias*: `has_error_code_v<T>`
