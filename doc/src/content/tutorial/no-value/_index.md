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

When designing your own success-or-failure type using templates
`basic_result<>` or `basic_outcome<>` you have to decide what no-value policy
you want to use. Either create your own, or use one of the predefined policies.
