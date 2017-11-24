+++
title = "outcome<T, EC, EP>"
description = "Success-or-failure return types where failure can take two forms, expected/handled failure and unexpected/abort failure."
weight = 20
+++

## `outcome<>`

Type `outcome<T, EC, EP>` can store either a `T` or an `EC` or an `EP`.
The first parameter (`T`) represents a value returned from functions upon success.
Both `EC` and `EP` represent the reason for function failure when function fails.
Conceptually, `outcome<T, EC, EP>` can be thought of as `variant<T, EC, EP>` or `variant<T, variant<EC, EP>>`, or `result<T, variant<EC, EP>>`.
`EC` defaults to `std::error_code` and `EP` defaults to `std::exception_ptr`. The distinction is made into two types, `EC` and `EP` for the following reasosns:

1. The interface: `EC` is inspected in a different way that `EP`.
2. Performance: handling of `EC` is optimized for POD types.
3. Interoperability with `result<T, EC>`.


`outcome<T, EC, EP>` is useful for transporting exceptions across layers of the program that were never designed with exception safety in mind.

Consider a program consisting of three layers:

{{<mermaid>}}
graph BT
    L3["Layer3"]
    L2["Layer2_old"] --> L3
    L1["Layer1"] --> L2
{{</mermaid>}}
  
The highest-level layer, `Layer3`, uses exceptions for signalling failures. The middle layer, `Layer2_old`,
was not designed with exception safety in mind and functions need to return information about failures in return value.
But down in the implementation details, in `Layer1`, another library is used that again throws exceptions. The goal is
to be able to transfer an exception thrown in `Layer1` through `Layer2_old`, which is not exception-safe,
and be able to rethrow it in `Layer3`.

In `Layer1` we have two functions from two libraries: one reports failures by throwin exceptions, the other by returnin `result<>`:

{{% snippet "using_outcome.cpp" "decl_f_g" %}}  

In `Layer2_old` we cannot use exceptions, so its function `h` uses return type `outcome<>` to report failures. It is using functions `f` and `g` and reports their failures inside `outcome<>`:

{{% snippet "using_outcome.cpp" "def_h" %}} 

#1. Operator `TRY` can forward failures encoded in `result<T, EC>` as `outcome<T, EC, EP>` without any loss in information. You can also use `TRY` to forward failure from one `outcome<>` to another. 

#2. You can store the current exception through `std::exception_ptr` inside `outcome<T, EC, EP>` without any loss in information
    (provided that `EP` is `std::exception_ptr`).