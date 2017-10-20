+++
title = "Outcome only"
description = ""
weight = 40
+++

These are the precanned policies suitable for use with `outcome`:

`error_code_throw_as_system_error_exception_rethrow<R, S, P>`
: Policy interpreting `S` as meeting the `std::error_code` contract, and
`P` as meeting the `std::exception_ptr` contract. If there is no value, `.value()`
will `std::rethrow_exception(exception)` if there is an exception, else
`OUTCOME_THROW_EXCEPTION(std::system_error(error))`.
`.error()` will `OUTCOME_THROW_EXCEPTION(bad_result_access("no error"))`
if there is no error. `.exception()` will `OUTCOME_THROW_EXCEPTION(bad_result_access("no exception"))`
if there is no exception. The narrow checks call `__builtin_unreachable()`
on compilers which support that intrinsic.

`error_code_throw_as_system_error_with_payload<R, S, P>`
: Policy interpreting `S` as meeting the `std::error_code` contract. If there is no value, `.value()`
will `throw_as_system_error_with_payload(this)` if there is a payload, else
`OUTCOME_THROW_EXCEPTION(std::system_error(error))`.
`.error()` will `OUTCOME_THROW_EXCEPTION(bad_result_access("no error"))`
if there is no error. `.payload()` will `OUTCOME_THROW_EXCEPTION(bad_result_access("no payload"))`
if there is no payload. The narrow checks call `__builtin_unreachable()`
on compilers which support that intrinsic.

`error_enum_throw_as_system_error_exception_rethrow<R, S, P>`
: Policy interpreting `make_error_code(S)` as meeting the `std::error_code` contract, and
`P` as meeting the `std::exception_ptr` contract. If there is no value, `.value()`
will `std::rethrow_exception(exception)` if there is an exception, else
`OUTCOME_THROW_EXCEPTION(std::system_error(make_error_code(error)))`.
`.error()` will `OUTCOME_THROW_EXCEPTION(bad_result_access("no error"))`
if there is no error. `.exception()` will `OUTCOME_THROW_EXCEPTION(bad_result_access("no exception"))`
if there is no exception. The narrow checks call `__builtin_unreachable()`
on compilers which support that intrinsic.

`error_enum_throw_as_system_error_with_payload<R, S, P>`
: Policy interpreting `make_error_code(S)` as meeting the `std::error_code` contract. If there is no value, `.value()`
will `throw_as_system_error_with_payload(this)` if there is a payload, else
`OUTCOME_THROW_EXCEPTION(std::system_error(make_error_code(error)))`.
`.error()` will `OUTCOME_THROW_EXCEPTION(bad_result_access("no error"))`
if there is no error. `.payload()` will `OUTCOME_THROW_EXCEPTION(bad_result_access("no payload"))`
if there is no payload. The narrow checks call `__builtin_unreachable()`
on compilers which support that intrinsic.

