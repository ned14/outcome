+++
title = "void"
description = ""
weight = 50
+++

What about `result<udt, void>`? This is absolutely legal, it means that no error state is
returned when there was an error. This can help with clarifying in code the use of `std::optional<udt>`
as Optional more logically means value-or-nothing, not necessarily value-or-error.
`result<udt, void>` unambiguously does mean success-or-failure, just with an unspecified
cause of failure.

Outcome's default action for `EC = void` is to call `std::terminate`:

{{% snippet "void_terminate.cpp" "void_terminate" %}}

Running this yields:

```
ned@lyta:~/outcome/build_posix$ bin/outcome-snippets_void_terminate
terminate called without an active exception
Aborted (core dumped)
ned@lyta:~/outcome/build_posix$
```
