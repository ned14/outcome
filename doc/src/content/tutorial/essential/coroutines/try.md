+++
title = "Coroutine TRY operation"
weight = 10
tags = [ "coroutines", "try" ]
+++

As one cannot call statement `return` from within a Coroutine, the very first part of Outcome's
support for Coroutines is {{% api "OUTCOME_CO_TRYV(expr)/OUTCOME_CO_TRY(expr)" %}},
which is literally the same as `OUTCOME_TRY()` except that `co_return` is called
to return early instead of `return`.

```c++
eager<result<std::string>> to_string(int x)
{
  if(x >= 0)
  {
    OUTCOME_CO_TRY(convert(x));
  }
  co_return "out of range";
}
```
