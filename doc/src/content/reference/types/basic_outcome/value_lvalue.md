+++
title = "`value_type &value() &`"
description = "Wide contract lvalue reference observer of any value present. Constexpr propagating."
categories = ["observers"]
weight = 640
+++

Wide contract lvalue reference observer of any value present. `NoValuePolicy::wide_value_check()` is first invoked, then the reference to the value is returned.

*Requires*: `value_type` to not be `void`, otherwise return type is `void`.

*Complexity*: Depends on `NoValuePolicy::wide_value_check()`.

*Guarantees*: None.
