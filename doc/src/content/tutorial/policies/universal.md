+++
title = "Result + Outcome"
description = ""
weight = 25
+++

These are the precanned policies suitable for use with both `result` and `outcome`:

`all_narrow`
: Wide checks call their narrow check cousins only. Narrow checks
call `__builtin_unreachable()` on compilers which support that intrinsic.

`terminate`
: Wide checks call `std::terminate` if they fail. Narrow checks
call `__builtin_unreachable()` on compilers which support that intrinsic.