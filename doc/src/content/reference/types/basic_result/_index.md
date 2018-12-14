+++
title = "`basic_result<T, E, NoValuePolicy>`"
description = "A sum type carrying either a successful `T`, or a disappointment `E`, with `NoValuePolicy` specifying what to do if one tries to read state which isn't there."
+++

A sum type carrying either a `T` or an `E`, with `NoValuePolicy` specifying what to do if one tries to read state which isn't there. Either or both of `T` and `E` can be `void` to indicate no value for that state is present.

*Requires*: Concept requirements if C++ 20, else static asserted:

- That trait {{% api "type_can_be_used_in_basic_result<R>" %}} is true for both `T` and `E`.
- That either `E` is `void` or `DefaultConstructible`.

*Namespace*: `OUTCOME_V2_NAMESPACE`

*Header*: `<outcome/basic_result.hpp>`

*Inclusions*: The very lightest weight of C and C++ header files:

1. `<cstdint>`
2. `<initializer_list>`
3. `<iosfwd>`
4. `<new>`
5. `<type_traits>`
6. `<utility>` (C++ 17 or later only, for {{% api "std::in_place_type_t<T>" %}})
7. If C++ exceptions disabled and `OUTCOME_DISABLE_EXECINFO` undefined only (used to print stack backtraces on "exception throw"):
    1. `<sal.h>` (Windows only)
    2. `<stddef.h>` (Windows only)
    3. `<string.h>` (Windows only)
    4. `<execinfo.h>` (POSIX only)
8. `<cstdio>`
9. `<cstdlib>`
10. `<cassert>`

This very light weight inclusion dependencies makes basic result suitable for use in global header files of very large C++ codebases.

### Design rationale:

The basic result type is the main workhorse type of the Outcome library, providing a simple sum type with optional values representing success or disappointment. Unlike {{% api "std::expected<T, E>" %}}, Outcome's result type is designed specifically for convenience when implementing failure handling, and it has a number of API differences to facilitate that.

The first major design difference is that basic result models its constructor design on {{% api "std::variant<...>" %}}, rather than modelling {{% api "std::optional<T>" %}}'s constructor design like `std::expected<T, E>` does. This means that basic result will implicitly construct either a `T` or an `E` if doing so is unambiguous, same as `variant` does. Where implicit construction is ambiguous, the implicit constructors disable and a `T` or `E` can be specified via {{% api "in_place_type_t<T>" %}}, or via {{% api "success_type<T>" %}} or {{% api "failure_type<T>" %}}.

The second major design difference is that union storage is NOT used, as it is assumed that `sizeof(E)` will be small for failure handling. This very considerably reduces load on the compiler, and substantially improves compile times in very large C++ codebases.

### Public member type aliases:

- `value_type` is `T`.
- `error_type` is `E`.
- `value_type_if_enabled` is `T` if construction from `T` is available, else it is a usefully named unusable internal type.
- `error_type_if_enabled` is `E` if construction from `T` is available, else it is a usefully named unusable internal type.
- `rebind<A, B = E, C = NoValuePolicy>` is `basic_result<A, B, C>`.

### Protected member predicate booleans:

- `predicate::constructors_enabled` is constexpr boolean true if decayed `value_type` and decayed `error_type` are not the same type.

- `predicate::implicit_constructors_enabled` is constexpr boolean true if:
    1. `predicate::constructors_enabled` is true.
    2. Trait {{% api "is_error_type<E>" %}} is not true for both decayed `value_type` and decayed `error_type` at the same time.
    3. `value_type` is not implicitly constructible from `error_type` and `error_type` is not implicitly constructible from `value_type`.<br>OR<br>trait {{% api "is_error_type<E>" %}} is true for decayed `error_type` and `error_type` is not implicitly constructible from `value_type` and `value_type` is an integral type.

- `predicate::enable_value_converting_constructor<R>` is constexpr boolean true if:
    1. `predicate::constructors_enabled` is true.
    2. Decayed `R` is not this `basic_result` type.
    3. Decayed `R` is not an `in_place_type_t`.
    4. Trait {{% api "is_error_type_enum<E, Enum>" %}} is false for `error_type` and decayed `R`.
    5. `value_type` is implicitly constructible from `R` and `error_type` is not implicitly constructible from `R`.<br>OR<br>`value_type` is the exact same type as decayed `R` and `value_type` is implicitly constructible from `R`.

- `predicate::enable_error_converting_constructor<R>` is constexpr boolean true if:
    1. `predicate::constructors_enabled` is true.
    2. Decayed `R` is not this `basic_result` type.
    3. Decayed `R` is not an `in_place_type_t`.
    4. Trait {{% api "is_error_type_enum<E, Enum>" %}} is false for `error_type` and decayed `R`.
    5. `value_type` is not implicitly constructible from `R` and `error_type` is implicitly constructible from `R`.<br>OR<br>`error_type` is the exact same type as decayed `R` and `error_type` is implicitly constructible from `R`.

- `predicate::enable_error_condition_converting_constructor<ErrorCondEnum>` is constexpr boolean true if:
    1. `predicate::constructors_enabled` is true.
    2. Decayed `ErrorCondEnum` is not this `basic_result` type.
    3. Decayed `ErrorCondEnum` is not an `in_place_type_t`.
    4. Trait {{% api "is_error_type_enum<E, Enum>" %}} is true for `error_type` and decayed `ErrorCondEnum`.

- `predicate::enable_compatible_conversion<R, S, P>` is constexpr boolean true if:
    1. `predicate::constructors_enabled` is true.
    2. `basic_result<R, S, P>` is not this `basic_result` type.
    3. `R` is `void` OR `value_type` is explicitly constructible from `R`.
    4. `S` is `void` OR `error_type` is explicitly constructible from `S`.

- `predicate::enable_inplace_value_constructor<Args...>` is constexpr boolean true if:
    1. `predicate::constructors_enabled` is true.
    2. `value_type` is `void` OR `value_type` is explicitly constructible from `Args...`.

- `predicate::enable_inplace_error_constructor<Args...>` is constexpr boolean true if:
    1. `predicate::constructors_enabled` is true.
    2. `error_type` is `void` OR `error_type` is explicitly constructible from `Args...`.

- `predicate::enable_inplace_value_error_constructor<Args...>` is constexpr boolean true if:
    1. `predicate::constructors_enabled` is true.
    2. Either, but not both, of `value_type` is explicitly constructible from `Args...` or `error_type` is explicitly constructible from `Args...`.

### Public member functions:

{{% children description="true" depth="2" %}}
