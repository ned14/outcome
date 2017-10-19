+++
title = "exception_ptr"
description = ""
weight = 40
+++

Another default action exists for `result<T, EC>` where `trait::is_exception_ptr<EC>` is
true, and for `outcome<T, EC, EP>` where `trait::is_exception_ptr<EP>` is true.

This default action simply rethrows
the exception pointer via `std::rethrow_exception(.error())` for `result` and
`std::rethrow_exception(.exception())` for `outcome`.

{{% snippet "exception_ptr.cpp" "exception_ptr" %}}

Running this yields:

```
ned@lyta:~/outcome/build_posix$ bin/outcome-snippets_exception_ptr
Exception thrown was hello
ned@lyta:~/outcome/build_posix$
```
