+++
title = "`has_error_code<T>`"
description = "True if an ADL discovered free function overload `make_error_code(T)` exists and returns an error type."
+++

True if an ADL discovered free function overload `make_error_code(T)` exists and returns an error type.

*Overridable*: By template specialisation into the `trait` namespace.

*Default*: To metaprogramming which performs ADL discovery. Note that the STL defines multiple overloads of an ADL discovered free function {{% api "std::make_error_code(T)" %}} for its error enumerations, as does Boost.System for the Boost error enumerations.

*Namespace*: `OUTCOME_V2_NAMESPACE::trait`

*Header*: Declared by `<outcome/trait.hpp>`, defined by `<outcome/std_result.hpp>`.

*Alias*: `has_error_code_v<T>`
