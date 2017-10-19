+++
title = "-- What happens?"
description = ""
weight = 25
+++

Let us run the code from the previous page:

```
ned@lyta:~/outcome/build_posix$ bin/outcome-snippets_error_code_enums1
Segmentation fault (core dumped)
ned@lyta:~/outcome/build_posix$
```

Also undefined behaviour. This is because Outcome doesn't know what to do
with a strongly typed `enum` any more than some user defined `struct`.

Let's register our error code enum with the C++ standard library. This causes
Outcome to treat it quite differently.

{{% snippet "error_code_enums2.cpp" "declaration" %}}
