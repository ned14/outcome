+++
title = "`basic_result(const basic_result &)`"
description = "Copy constructor. Constexpr, triviality and noexcept propagating."
weight = 120
+++

Copy constructor.

*Requires*: that `value_type` and `error_type` both implement a copy constructor.

*Complexity*: Same as for `value_type`'s and `error_type`'s copy constructors. Constexpr, triviality and noexcept of underlying operations is propagated.