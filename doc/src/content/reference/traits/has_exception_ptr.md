+++
title = "`has_exception_ptr<T>`"
description = "True if an exception ptr can be constructed from a `T`."
+++

True if an exception ptr can be constructed from a `T` e.g. if there exists an ADL discovered free function `make_exception_ptr(T)` and it returns an exception ptr.

*Overridable*: By template specialisation into the `trait` namespace.

*Default*: True if `T` is implicitly constructible to an exception ptr, else to metaprogramming which performs the ADL discovery and testing of the result type of `make_exception_ptr(T)`. Note that the STL defines an ADL discovered free function {{% api "std::make_exception_ptr(T)" %}}. Thus this trait will pick up that free function.

*Namespace*: `OUTCOME_V2_NAMESPACE::trait`

*Header*: Declared by `<outcome/trait.hpp>`, defined by `<outcome/std_result.hpp>`.

*Variable alias*: `has_exception_ptr_v<T>`
