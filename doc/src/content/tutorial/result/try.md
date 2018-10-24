+++
title = "TRY operations"
description = ""
weight = 30
tags = ["try"]
+++

In the implementation of function `print_half` we have seen the usage of the macro {{< api try OUTCOME_TRY >}}:

```c++
OUTCOME_TRY (i, BigInt::fromString(text));
```

The `OUTCOME_TRY` macro uses C macro overloading to select between two implementations based on the number of
input parameters. If there is exactly one input parameter i.e. without the `i, `, the control statement is
roughly equivalent to:

```c++
auto&& __result = BigInt::fromString(text);
if (!__result)
  return __result.as_failure();
```

Where `__result` is a compile time generated unique name. If there are between two and eight parameters,
this control statement is roughly equivalent to:

```c++
auto&& __result = BigInt::fromString(text);
if (!__result)
  return __result.as_failure();
auto&& i = __result.value();
```

So here `i` as the first C macro parameter is set to the value of any successful result. To prevent
confounding of the C preprocessor, you should always wrap the function invocation in brackets. This is done
throughout this tutorial.

Additionally, in GCC and Clang which provide an extension to C++ known as
[statement expressions](https://gcc.gnu.org/onlinedocs/gcc/Statement-Exprs.html "GCC docs on statement expressions")
it is possible to use an alternative macro: `OUTCOME_TRYX`, which is an expression. With the above macro, the above declaration of variable `i` can be rewritten to:

```c++
int i = OUTCOME_TRYX (BigInt::fromString(text));
```

This has an advantage that you can use it any place where you can put an expression, e.g., in "simple initialization":

```c++
if (int i = OUTCOME_TRYX(BigInt::fromString(text)))
  use_a_non_zero_int(i);
```

or in as a subexpression of a bigger full expression:

```c++
int ans = OUTCOME_TRYX(BigInt::fromString("1")) + OUTCOME_TRYX(BigInt::fromString("2"));
```

{{% notice note %}}
This macro makes use of a proprietary extension in GCC and clang and is not
portable. The macro is not made available on unsupported compilers,
so you can test for its presence using `#ifdef OUTCOME_TRYX`.
{{% /notice %}}

Macro `OUTCOME_TRY` does two things:

1. It extracts a `T` from `result<T>` (or `outcome<T>`).
2. It declares a dependency between statements: If the "tried" statement fails, the next statement is not executed.

When you are calling functions that return `result<void>` the first of the two things does not make sense. You then have to use macro `OUTCOME_TRYV` instead. Let's use our function `print_half`:

{{% snippet "using_result.cpp" "tryv" %}}

The first statement will succeed. The second statement will "fail", i.e. it will return an *errored* result. This will cause an immediate return and the subsequent statements will be skipped.
