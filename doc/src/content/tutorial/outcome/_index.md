+++
title = "outcome<T, EC, EP>"
weight = 20
+++

## `outcome`

Type `outcome<T, EC, EP>` can store either a `T` or an `EC` or an `EP`.
The first parameter (`T`) represents a value returned from functions upon success.
Both `EC` and `EP` represent the reason for function failure when function fails.
Conceptually, `outcome<T, EC, EP>` can be thought of as `variant<T, EC, EP>` or `variant<T, variant<EC, EP>>`, or `result<variant<EC, EP>>`.
`EC` defaults to `std::error_code` and `EP` defaults to `std::exception_ptr`. THe distinction is made into two types, `EC` and `EP` for the following reasosns:

1. The interface: `EC` is inspected in a different way that `EP`.
2. Performance: handling of `EC` is optimized for POD types.
3. Interoperability with `result<T, EC>`: like converisons.


`outcome<T, EC, EP>` is useful for transporting exceptions across layers of the program that was never designed with exception_ptr`safety in mind.

Consider a program consisting of three layers:

```
Layer3
  ^
  |
Layer2NX
  ^
  |
Layer1
```
  
The highest-level layer, `Layer3`, uses exceptions for signalling failures. The middle layer, `Layer2NX`,
was not designed with exception safety in mind and function need to return information about failures in return value.
But down in the implementation details, in `Layer1`, another library is used that again throws exceptions. The goal is
to be able to transfer an exception thrown in `Layer1` through `Layer2`, which is not exception-safe, and be able to rethrow it in `Layer3`.

In `Layer1` we have a throwing function:

{{% snippet "using_outcome.cpp" "fun_1f" %}}  

In `Layer2NX` we cannot use exceptions, so its function `g` uses `result<>` to report failures:

{{% snippet "using_outcome.cpp" "fun_2g" %}} 

There is another function in `Layer2NX` that has to use both `Layer1::f` and `Layer2NX::g`.
It cannot use `Layer1::f` directly as the later may throw an exception, so it has to wrap it into a non-throwing function `Layer2NX::f`:

{{% snippet "using_outcome.cpp" "fun_2f" %}}

This wrapper funciton returns type `outcome<int>`. If an exception is thrown, it is caught by an `std::exception_ptr`. This `std::exception_ptr` is converted to `outcome<T>` upon return.
`outcome<T, EC, EP>` is convertible from `T`, `EC` and `EP` as long as such conversion is not ambiguous.


Now function `Layer2NX::fun` can be implemented with non-throwing `Layer2NX::f` and `Layer2NX::g`:

{{% snippet "using_outcome.cpp" "fun_2fun" %}}

In the example above, manually deleting `resource` represents a non-exception-safe code.
Typically it is not recommended to manually delete memory because it is hard to get right in case exceptions are thrown.
But when exceptions are known not to be thrown (e.g., when they are disabled) this recommendation is weakened.

#1. When we want to forward (return up) the `outcome<>` object representing failure, we use function `as_failure()` it returns type `failure_type<EC, EP>` which is convertible to any to `outcome<T, EC, EP>` for any `T`.

#2. We can similarly forward a failure from `result<>` again by calling `as_failure()`, the result will be converted to `outcome<>` preserving the information about function failure.

If the management of `resource` is automated through RAII, even with exceptions disabled, you can use `OUTCOME_TRY` to make the code more concise:

{{% snippet "using_outcome.cpp" "fun_2fun2" %}}  

Statement `OUTCOME_TRY` works for `outcome` and you can also use it to return failure from `result<>` as `outcome<>` as shown in the second `OUTCOME_TRY`.