+++
title = "Casting workaround"
description = ""
weight = 20
+++

The templated `Impl` type on each policy function is `decltype(*this)` of the
part of Outcome's internal implementation which calls the policy. It therefore
may be quite removed from the actual `outcome` type in play, and thus the
`.exception()` member function and others belonging to `outcome` only will
not be immediately visible.

Hence a very common thing you'll need to do is static
cast to a more derived form before use like this:

{{% snippet "policies.cpp" "cast" %}}

Note that const-ness and lvalue/rvalue-ness is propagated to
`Impl &&self`, so if the `result` or `outcome` is a const rvalue and the user
calls `.value()` on that, the `wide_value_check()` will see a const rvalue `self`.
This lets you move from `self` when implementing the wide value check appropriately.