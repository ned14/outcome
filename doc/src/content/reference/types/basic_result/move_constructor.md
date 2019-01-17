+++
title = "`basic_result(basic_result &&)`"
description = "Move constructor. Constexpr, triviality and noexcept propagating."
categories = ["constructors", "implicit-constructors", "move-constructors"]
weight = 110
+++

Move constructor.

*Requires*: that `value_type` and `error_type` both implement a move constructor.

*Complexity*: Same as for `value_type`'s and `error_type`'s move constructors. Constexpr, triviality and noexcept of underlying operations is propagated.

*Guarantees*: If an exception is thrown during the operation, the state of both operands on entry is restored, if at least one of the underlying operations is marked `noexcept`.
