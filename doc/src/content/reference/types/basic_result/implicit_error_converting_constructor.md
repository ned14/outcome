+++
title = "`basic_result(S &&)`"
description = "Implicit `error_type` constructor. Available if `predicate::enable_error_converting_constructor<S>` is true. Constexpr, triviality and noexcept propagating."
categories = ["constructors", "implicit-constructors", "converting-constructors"]
weight = 190
+++

Implicit `error_type` constructor. Calls {{% api "hook_result_construction(basic_result<T, E, NoValuePolicy> *, U &&)" %}} with `this` and `S`.

*Requires*: `predicate::enable_error_converting_constructor<R>` is true.

*Complexity*: Same as for `error_type`'s copy or move constructor. Constexpr, triviality and noexcept of underlying operations is propagated.