+++
title = "Hook outcome"
description = ""
weight = 50
+++

The final step is to add ADL discovered event hooks for the very specific case of
when our localised `outcome` is copy or move constructed from our localised `result`.
There isn't really much to say about these, just be careful to mark them `noexcept`
or not based on whether the types `T`, `EC` or `EP` could throw during copy or move
construction. As `poke_exception()` creates a `std::string` and appends to it,
it could indeed throw an exception and thus with the `noexcept` hooks below, the
process would be terminated.

{{% snippet "error_code_extended.cpp" "error_code_extended5" %}}

