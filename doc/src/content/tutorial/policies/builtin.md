+++
title = "Built-in policies"
description = ""
weight = 30
+++

These are the precanned policies built into Outcome:

`all_narrow`
: Wide checks call their narrow check cousins only. Narrow checks
call `__builtin_unreachable()` on compilers which support that intrinsic.

`exception_ptr_rethrow<T, EC, EP>`
: Policy interpreting either `EC` or `EP` as meeting the `std::exception_ptr` contract. If
there is no value, `.value()`
will `std::rethrow_exception(error)` if `EP` is `void`, else `std::rethrow_exception(exception)`.
`.error()` will `OUTCOME_THROW_EXCEPTION(bad_result_access("no error"))`
if there is no error.
The narrow checks call `__builtin_unreachable()`
on compilers which support that intrinsic.

`terminate`
: Wide checks call `std::terminate` if they fail. Narrow checks
call `__builtin_unreachable()` on compilers which support that intrinsic.

FIXME

`error_code_throw_as_system_error<EC>`
: Policy interpreting `EC` as meeting the `std::error_code` contract. `.value()`
will `OUTCOME_THROW_EXCEPTION(std::system_error(error))`
if there is no value, `.error()` will `OUTCOME_THROW_EXCEPTION(bad_result_access("no error"))`
if there is no error. The narrow checks call `__builtin_unreachable()`
on compilers which support that intrinsic.

`error_enum_throw_as_system_error<EC>`
: Policy interpreting `make_error_code(EC)` as meeting the `std::error_code` contract. `.value()`
will `OUTCOME_THROW_EXCEPTION(std::system_error(make_error_code(error)))`
if there is no value, `.error()` will `OUTCOME_THROW_EXCEPTION(bad_result_access("no error"))`
if there is no error. The narrow checks call `__builtin_unreachable()`
on compilers which support that intrinsic.

`throw_bad_result_access<EC>`
: Policy implementing throws of `bad_result_access_with<EC>`. `.value()`
will `OUTCOME_THROW_EXCEPTION(bad_result_access_with<EC>(error))`
if there is no value, `.error()` will `OUTCOME_THROW_EXCEPTION(bad_result_access("no error"))`
if there is no error. The narrow checks call `__builtin_unreachable()`
on compilers which support that intrinsic.
