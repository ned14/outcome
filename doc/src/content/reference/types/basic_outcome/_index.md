+++
title = "`basic_outcome<T, EC, EP, NoValuePolicy>`"
description = "A type carrying one of (i) a successful `T` (ii) a disappointment `EC` (iii) a failure `EP` (iv) both a disappointment `EC` and a failure `EP`, with `NoValuePolicy` specifying what to do if one tries to read state which isn't there."
+++

A type carrying one of (i) a successful `T` (ii) a disappointment `EC` (iii) a failure `EP` (iv) both a disappointment `EC` and a failure `EP`, with `NoValuePolicy` specifying what to do if one tries to read state which isn't there. Any one, two, or all of `T`, `EC` and `EP` can be `void` to indicate no value for that state is present. Detectable using {{% api "is_basic_outcome<T>" %}}.

*Requires*: Concept requirements if C++ 20, else static asserted:

- That trait {{% api "type_can_be_used_in_basic_result<R>" %}} is true for `T`, `EC` and `EP`.
- That either `EC` is `void` or `DefaultConstructible`.
- That either `EP` is `void` or `DefaultConstructible`.

*Namespace*: `OUTCOME_V2_NAMESPACE`

*Header*: `<outcome/basic_outcome.hpp>`

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

This very light weight set of inclusion dependencies makes basic result suitable for use in global header files of very large C++ codebases.

### Design rationale

To write

### Public member type aliases

- `value_type` is `T`.
- `error_type` is `EC`.
- `exception_type` is `EP`.
- `value_type_if_enabled` is `T` if construction from `T` is available, else it is a usefully named unusable internal type.
- `error_type_if_enabled` is `EC` if construction from `EC` is available, else it is a usefully named unusable internal type.
- `exception_type_if_enabled` is `EP` if construction from `EP` is available, else it is a usefully named unusable internal type.
- `rebind<A, B = EC, C = EP, D = NoValuePolicy>` is `basic_outcome<A, B, C, D>`.


REST TO DO TOMORROW!


### Protected member predicate booleans

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

#### Summary of [standard requirements provided](https://en.cppreference.com/w/cpp/named_req)

- ~~`DefaultConstructible`~~, always deleted to force user to choose valued or errored for every result instanced.
- `MoveConstructible`, if both `value_type` and `error_type` implement move constructors.
- `CopyConstructible`, if both `value_type` and `error_type` implement copy constructors.
- `MoveAssignable`, if both `value_type` and `error_type` implement move constructors and move assignment.
- `CopyAssignable`, if both `value_type` and `error_type` implement copy constructors and copy assignment.
- `Destructible`
- `TriviallyCopyable`, if both `value_type` and `error_type` are trivially copyable.
- `TrivialType`, if both `value_type` and `error_type` are trivial types.
- `LiteralType`, if both `value_type` and `error_type` are literal types.
- `StandardLayoutType`, if both `value_type` and `error_type` are standard layout types. If so, layout of `basic_result` in C is guaranteed to be:

    ```c++
    struct result_layout {
      value_type value;
      unsigned int flags;
      error_type error;
    };
    ```
- `EqualityComparable`, if both `value_type` and `error_type` implement equality comparisons with one another.
- ~~`LessThanComparable`~~, not implemented due to availability of implicit conversions from `value_type` and `error_type`, this can cause major surprise (i.e. hard to diagnose bugs), so we don't implement these at all.
~ `Swappable`
- ~~`Hash`~~, not implemented as a generic implementation of a unique hash for non-valued items which are unequal would require a dependency on RTTI being enabled.

Thus `basic_result` meets the `Regular` concept if both `value_type` and `error_type` are `Regular`, except for the lack of a default constructor. Often where one needs a default constructor, wrapping `basic_result` into {{% api "std::optional<T>" %}} will suffice.

### Public member functions

#### Disabling constructors

{{% children description="true" depth="2" categories="disabling-constructors" %}}

#### Copy and move constructors and assignment, and destructor

{{% children description="true" depth="2" categories="default-constructors,copy-constructors,move-constructors,copy-assignment,move-assignment,destructors" %}}

#### Converting constructors

{{% children description="true" depth="2" categories="converting-constructors" %}}

#### Inplace constructors

{{% children description="true" depth="2" categories="inplace-constructors" %}}

#### Tagged constructors

{{% children description="true" depth="2" categories="tagged-constructors" %}}

#### Observers

{{% children description="true" depth="2" categories="observers" %}}

#### Modifiers

{{% children description="true" depth="2" categories="modifiers" %}}

#### Comparisons

See above for why `LessThanComparable` is not implemented.

{{% children description="true" depth="2" categories="comparisons" %}}

