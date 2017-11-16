+++
title = "In use"
weight = 50
+++

This is how you might now write application code using these three libraries:

{{% snippet "finale.cpp" "app_go" %}}

Many will wish that the explicit converting wrappers around third party
library APIs were not there. Note that in C++ 17 you should be able to
dispense with the angle bracketed type as the compiler can now deduce that.
But one must still wrap all third party API invocations with `outcome()`
i.e. explicit construction to namespace-localised `outcome`.
This is a deliberate design decision: in Outcome, all *converting*
construction is always explicit, except when the source is `success` or
`failure` type sugar. And down the line when others come to maintain
this code, we think it will be very useful to be explicit on this because
user defined code that we customised earlier is being executed.

Note also that we are able to use `TRY` throughout this function,
and most especially note that we never, at any stage, needed to modify
the source code of `httplib`, `tidylib` nor `filelib`, or inject
custom things into their namespaces. This entire worked example was
achieved solely by `app` based customisation points and via `convert`.