+++
title = "No-value policies"
description = "Describes the concept of NoValuePolicy and how to use no-value policies."
weight = 25
tags = [ "policies" ]
+++

In the previous section we have seen that calling member function `.value()` on
object of type `outcome<T>` that did not contain a value caused an exception to
be thrown. This is only part of the story. The full semantics of member function
`.value()` are a bit more complex.

Let's consider `result<T>` first. It is an alias on `basic_result<T, EC, NVP>`,
where `EC` is the type storing error information and defaulted to
`std::error_code` and `NVP` is a *no-value policy* and defaulted to
`policy::default_policy<T, EC, void>`.

The semantics of `basic_result::value()` are:
1. Calls `NVP::wide_value_check(*this)`.
2. If `this->has_value() == true` then returns a reference to the contained value,
  otherwise the behavior is undefined.

Thus, the semantics of function `.value()` depend on the no-value policy. The
default policy (`policy::default_policy<T, EC, void>`) for `EC` of type
`std::error_code` does the following:

* If `r.has_value() == false` throws exception `std::system_error{r.error()}`,
* otherwise no effect.

{{% notice note %}}
Class templates `basic_result<T, EC, NVP>` and `basic_outcome<T, EC, EP, NVP>`
never use exceptions. Any exception-related logic is provided through no-value
policies.
{{% /notice %}}

When designing your own success-or-failure type using templates
`basic_result<>` or `basic_outcome<>` you have to decide what no-value policy
you want to use. Either create your own, or use one of the predefined policies.

You can also use two predefined aliases for `basic_result<>`:
* {{< api "result/#standardese-outcome_v2_xxx__unchecked-R-S-" "unchecked<T, EC>" >}}: it uses policy {{< api "policies/all_narrow" "all_narrow" >}}, where any observation of a missing value or error is undefined behavior;
* {{< api "result/#standardese-outcome_v2_xxx__checked-R-S-" "checked<T, EC>" >}}:
  it uses policy {{< api "policies/throw_bad_result_access" "throw_bad_result_access<EC>" >}}, where any observation of a missing value or error throws {{< api "bad_access/#standardese-outcome_v2_xxx__bad_result_access_with-S-" "bad_result_access_with<EC>" >}} or {{< api "bad_access/#standardese-outcome_v2_xxx__bad_result_access" "bad_result_access" >}}
  respectively.
