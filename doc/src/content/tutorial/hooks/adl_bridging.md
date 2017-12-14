+++
title = "ADL bridging"
description = ""
weight = 20
tags = [ "adl-bridging"]
+++

In a previous section, we used the `failure_info` type to create
the ADL bridge into the namespace where the ADL discovered {{< api "success_failure/#standardese-outcome_v2_xxx::policy::throw_as_system_error_with_payload%3CError%3E(Errorconst&)" "throw_as_system_error_with_payload()" >}}
function was to be found.

Here we do the same, but more directly by creating a thin clone of `std::error_code`
into the local namespace. This ensures that this namespace will be searched by the
compiler when discovering the event hooks.

{{% snippet "error_code_extended.cpp" "error_code_extended2" %}}

For convenience, we template alias local copies of `result` and `outcome` in this
namespace bound to the ADL bridging `error_code`.