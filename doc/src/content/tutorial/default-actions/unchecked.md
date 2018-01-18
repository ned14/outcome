+++
title = "unchecked<T, E> and checked<T, E>"
description = ""
weight = 60
tags = ["checked", "unchecked", "bad_result_access", "expected", "assume_value", "assume_error"]
+++

We have now covered all of the default actions in Outcome whereby `result<T, EC>` and `outcome<T, EC, EP>` implement
various default actions upon no-value observation according to traits defined upon the `EC` and `EP` chosen.

If you don't want all this clever automatic detection of traits, and just want a plain,
always-undefined-behaviour-on-no-value-observation success-or-failure type, we provide
a simplified template alias to `result<T, E>` called {{< api "result/#standardese-outcome_v2_xxx__unchecked-R-S-" "unchecked<T, E>" >}}. It literally does
no run time checking whatsoever, no-value observation is always undefined behaviour.

If instead you would prefer a plain, always-throwing-logic-error-on-no-value-observation
type, we also provide another simplified template alias to `result<T, E>` called {{< api "result/#standardese-outcome_v2_xxx__checked-R-S-" "checked<T, E>" >}}.
Similar to `.value()` in the WG21 Expected proposal or Optional, no-value observation throws
these logic error type exceptions:

- No-value `.value()` observation throws {{< api "bad_access/#standardese-outcome_v2_xxx__bad_result_access_with-S-" "bad_result_access_with<E>" >}}.
- No-error `.error()` observation throws {{< api "bad_access/#standardese-outcome_v2_xxx__bad_result_access" "bad_result_access" >}}.

If you need run time unchecked observers, `.assume_value()` and `.assume_error()` are
always unchecked at run time.

Finally, if you would like to implement your own default actions, you will find the
tutorial section on [Policies](../../policies) useful.
