+++
title = "Built-in policies"
description = ""
weight = 30
+++

These are the precanned policies built into Outcome:

`all_narrow`
: Wide checks call their narrow check cousins only. Narrow checks
call a function called `_ub()` which:

 1. Is marked with any compiler-specific markup to say it will never return,
 which should cause the compiler's optimiser to generate perfectly minimum code.
 2. Calls `__builtin_unreachable()` on compilers which support that intrinsic
 to further encourage perfectly minimum code (and to trigger the undefined
 behaviour sanitiser if execution ever reaches such a code path).

`error_code_throw_as_system_error<T, EC, EP>`
: Policy interpreting either `EC` as meeting the `std::error_code` contract,
and `EP` as optionally meeting the `std::exception_ptr` contract. If
there is no value and `EP` is set to an exception ptr, `.value()` will
`std::rethrow_exception(exception)` or `std::rethrow_exception(make_exception_ptr(exception))`. If
there is no value and `EP` is not set to an exception ptr, `.value()` will `OUTCOME_THROW_EXCEPTION(std::system_error(error))`
or `OUTCOME_THROW_EXCEPTION(std::system_error(make_error_code(error)))` if
`EC` is implicitly convertible to a `std::error_code`, or is an error code enum
or error condition enum, otherwise it will invoke the ADL discovered free function
`throw_as_system_error_with_payload(error)`.
`.error()` will `OUTCOME_THROW_EXCEPTION(bad_result_access("no error"))`
or `OUTCOME_THROW_EXCEPTION(bad_outcome_access("no error"))`
if there is no error.
`.exception()` will`OUTCOME_THROW_EXCEPTION(bad_outcome_access("no exception"))`
if there is no exception.
The narrow checks are the same as for the `all_narrow` policy.

`exception_ptr_rethrow<T, EC, EP>`
: Policy interpreting either or both `EC` and `EP` as meeting the `std::exception_ptr` contract. If
there is no value, `.value()`
will `std::rethrow_exception(error)` or `std::rethrow_exception(make_exception_ptr(error))`
if `EP` is `void`, else `std::rethrow_exception(exception)` or `std::rethrow_exception(make_exception_ptr(exception))`
or `std::rethrow_exception(error)` or `std::rethrow_exception(make_exception_ptr(error))` as appropriate.
`.error()` will `OUTCOME_THROW_EXCEPTION(bad_result_access("no error"))`
or `OUTCOME_THROW_EXCEPTION(bad_outcome_access("no error"))`
if there is no error.
`.exception()` will`OUTCOME_THROW_EXCEPTION(bad_outcome_access("no exception"))`
if there is no exception.
The narrow checks are the same as for the `all_narrow` policy.

`terminate`
: Wide checks call `std::terminate` if they fail.
The narrow checks are the same as for the `all_narrow` policy.

`throw_bad_result_access<EC>`
: Policy implementing throws of `bad_result_access_with<EC>`. `.value()`
will `OUTCOME_THROW_EXCEPTION(bad_result_access_with<EC>(error))`
if there is no value, `.error()` will `OUTCOME_THROW_EXCEPTION(bad_result_access("no error"))`
if there is no error.
The narrow checks are the same as for the `all_narrow` policy.
This policy can be used with `outcome`, but any `EP` state is ignored
and will appear to the policy as if neither value nor error is set,
so `.value()` in this situation would `OUTCOME_THROW_EXCEPTION(bad_result_access("no value"))`.
