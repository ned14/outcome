+++
title = "Example C++ function"
description = ""
weight = 20
+++

Let us start with a simple C++ function which we wish to make available to C code:

{{% snippet "cpp_api.cpp.disabled" "function" %}}

A surprise to some may be that one can return an `outcome::result<size_t>`
from a C function! This is because if for some `result<T, EC>` where both `T` and `EC` have
standard layout and are trivially copyable, then Outcome guarantees so will
`result<T, EC>`. Thus `outcome::result<size_t>` is a perfectly legal C type,
and can be returned directly to C code.