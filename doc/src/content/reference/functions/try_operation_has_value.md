+++
title = "`bool try_operation_has_value(X)`"
description = "Default implementation of `try_operation_has_value(X)` ADL customisation point for `OUTCOME_TRY`."
+++

This default implementation returns whatever the `.has_value()` member function returns.

*Requires*: That the expression `std::declval<T>().has_value()` is a valid expression.

*Namespace*: `OUTCOME_V2_NAMESPACE`

*Header*: `<outcome/try.hpp>`
