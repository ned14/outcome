+++
title = "`exception_type &exception() &`"
description = "Wide contract lvalue reference observer of the stored exception. Constexpr propagating."
categories = ["observers"]
weight = 785
+++

Wide contract lvalue reference observer of the stored exception. `NoValuePolicy::wide_exception_check()` is first invoked, then the reference to the exception is returned. As a valid default constructed exception is always present, no undefined behaviour occurs if `NoValuePolicy::wide_exception_check()` returns.

*Requires*: `exception_type` to not be `void`, otherwise return type is `void`.

*Complexity*: Depends on `NoValuePolicy::wide_exception_check()`.

*Guarantees*: None.
