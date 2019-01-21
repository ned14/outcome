+++
title = "`const value_type &&assume_value() const && noexcept`"
description = "Narrow contract const rvalue reference observer of any value present. Constexpr propagating, never throws."
categories = ["observers"]
weight = 630
+++

Narrow contract const rvalue reference observer of any value present. `NoValuePolicy::narrow_value_check()` is first invoked, then the reference to the value is returned. The convention is that hard undefined behaviour occurs if no value is actually present, however `NoValuePolicy::narrow_value_check()` can do something to avoid that.

*Requires*: `value_type` to not be `void`, otherwise return type is `void`.

*Complexity*: Depends on `NoValuePolicy::narrow_value_check()`.

*Guarantees*: An exception is never thrown.
