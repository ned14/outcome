+++
title = "Casting workaround"
description = ""
weight = 20
+++

The templated `Impl` type on each policy function is `decltype(*this)` of the
part of Outcome's internal implementation which calls the policy. It may also
be `const`, depending on the observer called.
It is highly unlikely to be `result<T, EC>` or especially
`outcome<T, EC, EP|P>`, so a very common thing you'll need to do is static
cast to a more derived form before use like this:

{{% snippet "policies.cpp" "cast" %}}
