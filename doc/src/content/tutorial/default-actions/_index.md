+++
title = "Default actions"
description = "The default rules for handling different categories of failure type"
weight = 45
+++

In the last section, we observed with `.value()` the value of the `outcome` returned by `copy_file()`
and saw that it may throw a C++ exception configured by an ADL discovered function.
This behaviour is what we will call a "default action" i.e. a pre-programmed action taken by
Outcome in response to *no-value observation*.

Some -- strongly -- feel that these value-or-error objects should not have any
"default action" other than to throw a special exception carrying as payload the cause
of the no-value i.e. the error. Most with this opinion feel that the "default action" is in fact to unwind
the stack, and that using an exception throw instead of a function return is
basically the same thing precisely because a stack unwind occurs in both cases, and
the mechanism by which that is achieved isn't particularly important. Indeed, the Expected
proposal before WG21, which intends to standardise a value-or-error object not
dissimilar to Outcome's objects, does just this (at the time of writing). Optional,
which is a value-or-nothing object, similarly throws a special exception on
no-value observation via `.value()`.

Outcome's default is to not provide value-or-error objects. It provides **success-or-failure**
objects. We define the difference as being "having programmable actions in
response to no-value observation other than throwing a hard coded logic error type exception[^1]".
This philosophical difference implies that throwing a C++ exception is
solely used to *abort the current operation with a useful-to-the-programmer default action*,
**not** as a control flow alternative to ordinary returns from function, **not** for reporting "recoverable" logic errors.

You can, of course,
choose different default actions for your particular Outcome instance, implement your own
default actions, and indeed configure a `result` and `outcome` which throw a
logic error type exception exactly the same way as Expected or Optional does.
How to do this is described later in this tutorial.

This section describes the default actions implemented by Outcome, which
we believe will cover the large majority of users with no further configuration
needed.

[^1]: I take exception to throwing logic error type exceptions as is unfortunately the case throughout the C++ standard library. What *actual* value to the programmer do they deliver? If used as control flow, then there are **always** much superior alternatives. If used for spotting a true logic error, then you just detected bad logic by the programmer or memory corruption, in which case this situation is **not** recoverable and you really ought to fatal exit. <p>And then consider all the many negatives: (i) you force programmers to have to deal with exception safety, substantially increasing development costs for virtually no gain to the programmer (ii) you force the compiler to have to deal with potential exception throws, slowing down compile times and generating bloatier code just in case something which should almost never happen might occur (iii) analysis tooling can't tell between control flow and logic error type exception throws, and thus cannot spot nor warn you when you didn't mean them to occur.<p>On table-based exception handling implementations, throwing an exception is assumed to be extremely rare. This allows zero performance impact on the non-throwing code paths, but at a very severe performance cost to any time that you throw and catch an exception. This is unavoidable in any table-based exception handling implementation. A `throw...catch` cycle is always [at least thousands of times more expensive than a `return` statement](../../faq/#what-kind-of-performance-benefits-will-using-outcome-in-my-code-bring), and always must be so, *even when the `throw...catch` is inlined* on current compiler technology.
