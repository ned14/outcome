+++
title = "The payload"
weight = 20
+++

We define the code domain's `value_type` -- the payload to be transported by
status codes using this code domain -- to be a POSIX `errno` value, an integer
line number and a const char pointer.

{{% snippet "experimental_status_code.cpp" "value_type" %}}
