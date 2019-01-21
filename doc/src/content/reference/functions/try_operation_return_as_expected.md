+++
title = "`std::experimental::unexpected<E> try_operation_return_as(std::experimental::expected<T, E>)`"
description = "Implementation of `try_operation_return_as(expr)` ADL customisation point for `expected<T, E>`."
+++

This implementation of {{% api "try_operation_return_as(expr)" %}} returns an unexpected for any expected input. This allows the use of functions returning `std::experimental::expected<T, E>` in `OUTCOME_TRY(...)`.

*Requires*: Always available.

*Namespace*: `OUTCOME_V2_NAMESPACE`

*Header*: `<outcome/try.hpp>`
