+++
title = "Result"
description = ""
weight = 30
+++

These are the precanned policies suitable for use with `result`:

`error_code_throw_as_system_error<EC>`
: *Requires that `EC` must be a base of `std::error_code`*. `.value()`
will `OUTCOME_THROW_EXCEPTION(std::system_error(make_error_code(error)))`
if there is no value, `.error()` will `OUTCOME_THROW_EXCEPTION(bad_result_access("no error"))`
if there is no error. The narrow checks call `__builtin_unreachable()`
on compilers which support that intrinsic.

wip