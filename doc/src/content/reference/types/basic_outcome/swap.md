+++
title = "`void swap(basic_outcome &)`"
description = "Swap one basic_outcome with another. Noexcept propagating."
categories = ["modifiers"]
weight = 900
+++

Swap one basic_outcome with another.

*Requires*: Always available.

*Complexity*: Same as for the `swap()` implementations of the `value_type`, `error_type` and `exception_type`. The noexcept of underlying operations is propagated.

*Guarantees*: If an exception is thrown during the operation, the state of all three operands on entry is restored, if at least two of the underlying operations is marked `noexcept`.
