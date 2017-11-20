+++
title = "exception_ptr"
description = ""
weight = 40
+++

Another default action exists for `result<T, EC>` where `trait::has_exception_ptr<EC>` is
true, and for `outcome<T, EC, EP>` where either or both `trait::has_exception_ptr<EC>` and
`trait::has_exception_ptr<EP>` is true.

This default action simply rethrows
the exception pointer via `std::rethrow_exception(make_exception_ptr(.error()))` for `result` and
`std::rethrow_exception(make_exception_ptr(.error()))` and/or
`std::rethrow_exception(make_exception_ptr(.exception()))` for `outcome`, if
`trait::has_exception_ptr<EC>` and/or `trait::has_exception_ptr<EP>` is true.

{{% snippet "exception_ptr.cpp" "exception_ptr" %}}

Running this yields:

```
ned@lyta:~/outcome/build_posix$ bin/outcome-snippets_exception_ptr
Exception thrown was hello
ned@lyta:~/outcome/build_posix$
```
