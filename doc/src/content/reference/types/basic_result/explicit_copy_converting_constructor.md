+++
title = "`explicit basic_result(const basic_result<R, S, P> &)`"
description = "Explicit converting copy constructor from compatible `basic_result`. Available if `predicate::enable_compatible_conversion<R, S, P>` is true. Constexpr, triviality and noexcept propagating."
categories = ["constructors", "explicit-constructors", "converting-constructors"]
weight = 310
+++

Explicit converting copy constructor from compatible `basic_result`. Calls {{% api "hook_result_copy_construction(basic_result<T, E, NoValuePolicy> *, U &&)" %}} with `this` and the input.

*Requires*: `predicate::enable_compatible_conversion<R, S, P>` is true.

*Complexity*: Same as for the copy constructors of the underlying types. Constexpr, triviality and noexcept of underlying operations is propagated.