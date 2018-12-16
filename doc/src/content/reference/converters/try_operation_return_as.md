+++
title = "`try_operation_return_as(expr)`"
description = "A customisable converter of `ValueOrError<T, E>` concept matching types to a returnable failure type."
+++

A customisable converter of {{% api "ValueOrError<T, E>" %}} concept matching types to a returnable failure type.

*Overridable*: By template specialisation into the `OUTCOME_V2_NAMESPACE` namespace.

*Default*: A number of overloads are provided by default:

1. `try_operation_return_as(T &&)` which requires `T` to provide an `.as_failure()` member function in order to be available. This is selected for all `basic_result` and `basic_outcome` types.

2. Copy and move editions of `try_operation_return_as(std::experimental::expected<T, E>)` which return a `std::experimental::unexpected<E>` for the input's `.error()` member function.

*Namespace*: `OUTCOME_V2_NAMESPACE`

*Header*: `<outcome/try.hpp>`
