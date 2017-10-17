+++
title = "Throwing filesystem_error"
description = ""
weight = 30
+++

Telling Outcome how to throw a system error with payload is easy:

{{% snippet "outcome_payload.cpp" "filesystem_api_custom_throw" %}}

Note that if you configure `outcome<T, EC, P>` in the error code + payload
edition and forget to define this free function, if you then write code
which could throw the error code + payload as an exception, you will get
a helpful compile time error message reminding you that you have forgotten
to define this function.

Usage of our new "upgraded" Filesystem `copy_file()` might be as follows:

{{% snippet "outcome_payload.cpp" "filesystem_api_custom_throw_demo" %}}

