+++
title = "Inspecting outcome<T, EC, EP>"
weight = 30
+++

Continuing with the previous example, in `Layer3` we obtain an `outcome<double>` which may store a `double` or an `std::error_code` or an `std::exception_ptr`.
`Layer3` uses exceptions to indicate failure, so we want to turn a failed result into an exception: if we are storing an `std::exception_ptr` just rethrow it.
If we are storing an `std::error_code` throw it as `std::system_error`, which is designed to store `std::error_code`s:

{{% snippet "using_outcome.cpp" "fun_3run" %}}

Function `has_exception` checks if it is `EP` (`std::exception_ptr`) that is stored, function `exception` accesses it. Similarly, function `error` accesses the `EC` (`std::error_code`) if it is stored.
`outcome<>` has also function `has_failure` to check if either `EC` or `EP` is being stored. In fact, this pattern of "unpacking" `outcome<>`
is so common that it has been implemented inside function `value`, so function `Layer3::run` could be written as:

```c++
return Layer2NX::fun().value();
```   
