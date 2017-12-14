+++
title = "Hook result"
description = ""
weight = 30
+++

We now tell Outcome that for every instance of our localised `result<T>`, that
on failure construction only, we want custom code to be run which increments the current
slot in TLS storage and writes the current stack backtrace into it.

{{% snippet "error_code_extended.cpp" "error_code_extended3" %}}

The only non-obvious part above is the call to {{< api "result/#standardese-outcome_v2_xxx::hooks::set_spare_storage%3CR,S,NoValuePolicy%3E(result_or_outcome%3CR,S,NoValuePolicy%3E*,uint16_t)" "hooks::set_spare_storage()" >}}.
Both `result` and `outcome` keep their internal state metadata in a `uint32_t`,
half of which is not used by Outcome. As it can be very useful to keep a small
unique number attached to any particular `result` or `outcome` instance, we
permit user code to set those sixteen bits to anything they feel like.
The corresponding function to retrieve those sixteen bits is {{< api "result/#standardese-outcome_v2_xxx::hooks::spare_storage%3CR,S,NoValuePolicy%3E(result_or_outcome%3CR,S,NoValuePolicy%3Econst*)" "hooks::spare_storage()" >}}.