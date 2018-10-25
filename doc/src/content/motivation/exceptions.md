+++
title = "Exceptions"
description = "Exceptions with their good and bad sides."
weight = 10
+++

## Exceptions

Exceptions are the default mechanism in C++ for reporting, propagating and
processing the information about function failures. Their main advantage is
the ability to describe the "success dependency" between functions: if you want to
say that calling function `g()` depends on the successful execution of function `f()`,
you just put `g()` below `f()` and that's it:

```c++
int a()
{
  f();
  g();        // don't call g() and further if f() fails
  return h(); // don't call h() if g() fails
}
```

In the Standard C++ terms this means that `f()` is *sequenced before* `g()`. 
This makes failure handling extremely easy: in a lot of cases you do not have
to do anything.

But there is also cost to be paid when using exceptions.

This tutorial is in the process of being written. Once done we will explain in detail
why it is sometimes beneficial not to use exceptions to signal failures.
