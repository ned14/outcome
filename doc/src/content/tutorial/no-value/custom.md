+++
title = "A custom no-value policy"
description = ""
weight = 10
+++

If you want your `basic_outcome<>` or `basic_result<>` instances to call
`std::abort()` whenever `.value()` is called on an object that does not contain a value, or `.error()` is called on an object that does not contain an error, you will need to define your own no-value policy as follows:

{{% snippet "policies.cpp" "abort_policy" %}}

Once the policy is defined, you have to use it when providing your own
`basic_outcome` specialization:

{{% snippet "policies.cpp" "outcome_spec" %}}
