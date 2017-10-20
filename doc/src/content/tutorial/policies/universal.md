+++
title = "Result + Outcome"
description = ""
weight = 25
+++

These are the precanned policies suitable for use with both `result` and `outcome`:

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