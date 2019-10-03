+++
title = "`task<T>`"
description = "A lazily evaluated coroutine awaitable with Outcome customisation."
+++

This is very similar to {{% api "awaitable<T>" %}}, except that execution of the
`task<T>` returning function suspends immediately. Functions which return `task<T>`
are therefore suitable for tasks which you need to instantiate right now, but whose
execution will occur elsewhere e.g. in a separate kernel thread. Because of the
very common use case of using worker threads to execute the body of tasks, the
completion status is kept in an atomic, and thus synchronises the writing of the
coroutine's result with other threads.

Example of use (must be called from within a coroutinised function):

```c++
task<int> func(int x)
{
  co_return x + 1;
}
...
// Always suspends perhaps causing other coroutines to execute, then resumes.
int r = co_await func(5);
```

`task<T>` has special semantics if `T` is a type capable of constructing from
an `exception_ptr` or `error_code` -- any exceptions thrown during the function's body
are sent via `T`, preferably via the error code route if {{% api "error_from_exception(" %}}`)`
successfully matches the exception throw. This means that a {{% api "basic_result<T, E, NoValuePolicy>" %}}
or {{% api "basic_outcome<T, EC, EP, NoValuePolicy>" %}} where one of its types is
is compatible will have its `.error()` or `.exception()` set.

Note that `task<T>` does not otherwise transport exception throws, and rethrows
any exceptions thrown within the coroutine body through the coroutine machinery.
This does not produce reliable consequences in current C++ compilers. You should
therefore wrap the coroutine body in a `try...catch` if `T` is not able to transport
exceptions on its own.

*Requires*: C++ coroutines to be available in your compiler.

*Namespace*: `OUTCOME_V2_NAMESPACE`

*Header*: `<outcome/coroutine_support.hpp>`
