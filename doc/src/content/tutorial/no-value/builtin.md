+++
title = "Built-in policies"
description = ""
weight = 20
+++

These are the predefined policies built into Outcome:

{{< api "policies/all_narrow" "all_narrow" >}}

If there is an observation of a value/error/exception which is not present,
the behavior is undefined. However this is a tool-friendly UB using intrinsics
such as `__builtin_unreachable()` that allows tool to make use of it, e.g.,
better bug detection or optimizations.


{{< api "policies/terminate" "terminate" >}}

Observation of a missing value/error/exception causes the call to
`std::terminate()`.


{{< api "policies/outcome_error_code_throw_as_system_error" "error_code_throw_as_system_error<T, EC, EP>" >}}

This policy assumes that `EC` has the interface of `std::error_code`,
and `EP` has the interface of `std::exception_ptr`. Upon missing value
observation:

* if an exception is stored through pointer of type `EP` it is rethrown;
* otherwise, if an error of type `EC` is stored, it is converted to `error_code`
  and then thrown as `system_error`.

Upon missing error observation throws:

* `bad_result_access("no error")` from instances of `basic_result<>`.
* `bad_outcome_access("no error")` from instances of `basic_outcome<>`.

Upon missing exception observation throws `bad_outcome_access("no exception")`.


{{< api "policies/outcome_exception_ptr_rethrow" "exception_ptr_rethrow<T, EC, EP>" >}}

This policy assumes that both `EC` and `EP` (unless `void`) has the interface of `std::exception_ptr`. Upon missing value observation:

* in instances of `basic_result<>`, rethrows exception pointed to by `EC`;
* in instances of `basic_outcome<>`, if exception `ep` is present rethrows it,
  otherwise rethrows the stored error.

Upon missing error observation:

* in instances of `basic_result<>`, throws  `bad_result_access("no error")` ;
* in instances of `basic_outcome<>`, throws  `bad_outcome_access("no error")`.

Upon missing exception observation throws `bad_outcome_access("no exception")`.


{{< api "policies/throw_bad_result_access" "throw_bad_result_access<EC>" >}}

Upon missing value observation throws `bad_result_access_with<EC>(ec)`,
where `ec` is the value of the stored error. If error is not stored,
the behavior is undefined.

Upon missing error observation throws `bad_result_access("no error")`.

This policy should not be used with `basic_outcome<>` instances.
