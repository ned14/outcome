+++
title = "`explicit basic_outcome(const basic_outcome<A, B, C, D> &)`"
description = "Explicit converting copy constructor from compatible `basic_outcome`. Available if `predicate::enable_compatible_conversion<A, B, C, D>` is true. Constexpr, triviality and noexcept propagating."
categories = ["constructors", "explicit-constructors", "converting-constructors"]
weight = 310
+++

Explicit converting copy constructor from compatible `basic_outcome`. Calls {{% api "void hook_outcome_copy_construction(T *, U &&) noexcept" %}} with `this` and the input.

*Requires*: `predicate::enable_compatible_conversion<A, B, C, D>` is true.

*Complexity*: Same as for the copy constructors of the underlying types. Constexpr, triviality and noexcept of underlying operations is propagated.

*Guarantees*: If an exception is thrown during the operation, the state of all three operands on entry is restored, if at least two of the underlying operations are marked `noexcept`.
