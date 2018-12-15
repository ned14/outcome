+++
title = "`basic_result(R &&)`"
description = "Implicit `value_type` constructor. Available if `predicate::enable_value_converting_constructor<R>` is true. Constexpr, triviality and noexcept propagating."
categories = ["constructors", "implicit-constructors", "converting-constructors"]
weight = 180
+++

Implicit `value_type` constructor. Calls {{% api "hook_result_construction(basic_result<T, E, NoValuePolicy> *, U &&)" %}} with `this` and `R`.

*Requires*: `predicate::enable_value_converting_constructor<R>` is true.

*Complexity*: Same as for `value_type`'s copy or move constructor. Constexpr, triviality and noexcept of underlying operations is propagated.