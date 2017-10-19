+++
title = "unchecked<T, E> and checked<T, E>"
description = ""
weight = 60
+++

We have now covered all of the default actions in Outcome whereby `result<T, EC>` and `outcome<T, EC, EP|P>` implement
various default actions upon incorrect observation according to traits defined upon the `EC` and `EP|P` chosen.

If you don't want all this clever automatic detection of traits, and just want a plain,
always-undefined-behaviour-on-incorrect-observation success-or-failure type, we provide
a simplified template alias to `result<T, E>` called `unchecked<T, E>`. It literally does
no run time checking whatsoever, incorrect observation is always undefined behaviour.

If instead you would prefer a plain, always-throwing-logic-error-on-incorrect-observation
type, we also provide another simplified template alias to `result<T, E>` called `checked<T, E>`.
Similar to `.value()` in the WG21 Expected proposal or Optional, incorrect observation throws
these logic error exception types:

- Incorrect `.value()` observation throws `bad_result_access_with<E>`.
- Incorrect `.error()` observation throws `bad_result_access`.

If you need run time unchecked observers, `.assume_value()` and `.assume_error()` are
always unchecked at run time.

Finally, if you would like to implement your own default actions, you will find the
tutorial section on [Policies](policies) useful.
