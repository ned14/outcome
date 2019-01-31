+++
title = "`const error_type &&error() const &&`"
description = "Wide contract const rvalue reference observer of the stored error. Constexpr propagating."
categories = ["observers"]
weight = 770
+++

Wide contract const rvalue reference observer of the stored error. `NoValuePolicy::wide_error_check()` is first invoked, then the reference to the error is returned. As a valid default constructed error is always present, no undefined behaviour occurs if `NoValuePolicy::wide_error_check()` returns.

*Requires*: `error_type` to not be `void`, otherwise return type is `void`.

*Complexity*: Depends on `NoValuePolicy::wide_error_check()`.

*Guarantees*: None.
