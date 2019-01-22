+++
title = "`explicit basic_result(const basic_result<R, S, P> &)`"
description = "Explicit converting copy constructor from compatible `basic_result`. Available if `predicate::enable_compatible_conversion<R, S, P>` is true. Constexpr, triviality and noexcept propagating."
categories = ["constructors", "explicit-constructors", "converting-constructors"]
weight = 310
+++

Explicit converting copy constructor from compatible `basic_result`. Calls {{% api "void hook_result_copy_construction(T *, U &&) noexcept" %}} with `this` and the input.

*Requires*: `predicate::enable_compatible_conversion<R, S, P>` is true.

*Complexity*: Same as for the copy constructors of the underlying types. Constexpr, triviality and noexcept of underlying operations is propagated.

*Guarantees*: If an exception is thrown during the operation, the state of both operands on entry is restored, if at least one of the underlying operations is marked `noexcept`.
