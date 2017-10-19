+++
title = "Default actions"
description = "The default rules for handling different categories of failure type"
weight = 45
+++

In the last section, we observed with `.value()` the value of the `outcome` returned by `copy_file()`
and saw that it may throw a C++ exception configured by an ADL discovered function.
This behaviour is what we will call a "default action" i.e. a pre-programmed action taken by
Outcome in response to *incorrect observation*.

Some -- strongly -- feel that these value-or-error objects should not have any
"default action" other than to throw a logic error exception. Indeed, the Expected
proposal before WG21, which intends to standardise a value-or-error object not
dissimilar to Outcome's objects, does just this (at the time of writing). Optional,
which is a value-or-nothing object, similarly throws a logic error exception on
incorrect observation via `.value()`.

Outcome's default is to not provide value-or-error objects, it defaults
to providing *success-or-failure*
objects. And we define the difference as being "having programmable actions in
response to incorrect observation other than throwing a logic error exception".

You can, of course,
choose different default actions for your particular Outcome type, implement your own
default actions, and indeed configure a `result` and `outcome` which throw a
logic error exception exactly the same way as Expected or Optional does.
How to do this is described later in this tutorial.

But this section describes the default actions implemented by Outcome, which
we believe will cover the large majority of users with no further configuration
needed.