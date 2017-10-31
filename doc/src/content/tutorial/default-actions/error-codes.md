+++
title = "error_code"
description = ""
weight = 30
+++

Now that we have told the C++ standard library about our custom error code enum `err`,
we actually no longer need to specify `EC = err`, we can just leave it default to
`std::error_code`:

{{% snippet "error_code_enums2.cpp" "usage2" %}}

The reason that this works is because `std::error_code` provides implicit construction
from any type with the trait `std::is_error_code_enum<>` defined to be true, it uses
the ADL discovered free function `make_error_code()` during that implicit construction.

The big advantage of always using `EC = std::error_code` is that `OUTCOME_TRY` only works when the `EC` type is the
same in the try expression as the calling function, so by leaving it at the default of `std::error_code`, we can use `OUTCOME_TRY`
and save having to type boilerplate:

{{% snippet "error_code_enums2.cpp" "usage3" %}}
