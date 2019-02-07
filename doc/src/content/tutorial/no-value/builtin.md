+++
title = "Built-in policies"
description = ""
weight = 20
+++

These are the predefined policies built into Outcome:

{{< api "all_narrow" >}}

If there is an observation of a value/error/exception which is not present,
the program is put into a hard undefined behaviour situation. However this
is a tool-friendly UB using intrinsics
such as `__builtin_unreachable()` that allows tools to make use of it, e.g.,
better bug detection or optimizations.

<hr>

{{< api "terminate" >}}

Observation of a missing value/error/exception causes a call to
`std::terminate()`.

<hr>

{{< api "error_code_throw_as_system_error<T, EC, EP>" >}}

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

Overloads are provided for `boost::system::error_code` and `boost::exception_ptr`.

<hr>

{{< api "exception_ptr_rethrow<T, EC, EP>" >}}

This policy assumes that either `EC` or `EP` (unless `void`) has the interface of `std::exception_ptr`. Upon missing value observation:

* in instances of `basic_result<>`, rethrows exception pointed to by `EC`;
* in instances of `basic_outcome<>`, if exception `EP` is present rethrows it,
  otherwise rethrows `EC`.

Upon missing error observation:

* in instances of `basic_result<>`, throws  `bad_result_access("no error")` ;
* in instances of `basic_outcome<>`, throws  `bad_outcome_access("no error")`.

Upon missing exception observation throws `bad_outcome_access("no exception")`.

Overloads are provided for `boost::exception_ptr`.

<hr>

{{< api "throw_bad_result_access<EC>" >}}

Upon missing value observation throws `bad_result_access_with<EC>(ec)`,
where `ec` is the value of the stored error. If error is not stored,
the behaviour is undefined.

Upon missing error observation throws `bad_result_access("no error")`.

This policy can be used with `basic_outcome<>` instances, where it always
throws `bad_outcome_access` for all no-value/error/exception observations.
