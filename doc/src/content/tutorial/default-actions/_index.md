+++
title = "Default actions"
description = "The default rules for handling different categories of failure type"
weight = 45
+++

In the last section, we observed the value of the `outcome` returned by `copy_file`
and saw that it may throw a C++ exception configured by an ADL discovered function.
This behaviour is what we will call a "default action" i.e. an action taken by
Outcome in response to *incorrect usage*.

Some -- strongly -- feel that these success-or-failure objects should not have any
"default action" other than to throw a logic error exception. Indeed, the Expected
proposal before WG21 which intends to standardise a value-or-error object not
dissimilar to Outcome's objects does just this (at the time of writing).

However Outcome does not provide value-or-error objects, it provides *success-or-failure*
objects. And we define the difference as being "having programmable default actions
other than throwing a logic error exception".


So, let us imagine a some user
defined type (UDT) and some arbitrary error type:

{{% snippet "udts.cpp" "udts" %}}

Firstly, note that both the `udt` and `err` types can be constructed from an `int`.
Thus this won't compile:

{{% snippet "udts.cpp" "implicit" %}}

This is because all the implicit constructors self-disable because it could be ambiguous whether you
might mean `udt` or `err`. This is not a problem, it just requires typing some more so you
are explicit as to which you intend:

{{% snippet "udts.cpp" "explicit" %}}

Now, what do you think will happen if we try to retrieve a `udt` from this `result` holding an `err`?

{{% snippet "udts.cpp" "access" %}}
