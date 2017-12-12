+++
title = "API reference"
weight = 20
+++
# Project index

  - [`CXX_DECLARE_RESULT`](result#standardese-CXX_DECLARE_RESULT) &mdash; Declares a C struct representation of `result<R, S>`.

  - [`CXX_DECLARE_RESULT_EC`](result#standardese-CXX_DECLARE_RESULT_EC) &mdash; Declares a C struct representation of `result<R, std::error_code>`.

  - [`CXX_RESULT`](result#standardese-CXX_RESULT) &mdash; A reference to a previously declared struct by `CXX_DECLARE_RESULT(R, RD, S, SD)`

  - [`CXX_RESULT_EC`](result#standardese-CXX_RESULT_EC) &mdash; A reference to a previously declared struct by `CXX_DECLARE_RESULT_EC(R, RD)`

  - [`CXX_RESULT_ERROR`](result#standardese-CXX_RESULT_ERROR) &mdash; C11 generic selecting a result struct’s `error` or `code` integer member.

  - [`CXX_RESULT_ERROR_IS_ERRNO`](result#standardese-CXX_RESULT_ERROR_IS_ERRNO) &mdash; True if a result struct’s `error` or `code` is an `errno` domain code suitable for setting `errno` with.

  - [`CXX_RESULT_HAS_ERROR`](result#standardese-CXX_RESULT_HAS_ERROR) &mdash; True if a result struct has a valid error

  - [`CXX_RESULT_HAS_VALUE`](result#standardese-CXX_RESULT_HAS_VALUE) &mdash; True if a result struct has a valid value

  - [`CXX_RESULT_SET_ERRNO`](result#standardese-CXX_RESULT_SET_ERRNO) &mdash; Convenience macro setting `errno` to a result struct’s `errno` compatible error if present, or `EAGAIN` if errored but incompatible.

  - [`OUTCOME_ERROR_FROM_EXCEPTION_HPP`](utils#standardese-utils.hpp)

  - [`OUTCOME_TRY`](try#standardese-OUTCOME_TRY) &mdash; If the outcome returned by expression … is not valued, propagate any failure by immediately returning that failure immediately, else set *v* to the unwrapped value.

  - [`OUTCOME_TRY2`](try#standardese-try.hpp)

  - [`OUTCOME_TRYV`](try#standardese-OUTCOME_TRYV) &mdash; If the outcome returned by expression … is not valued, propagate any failure by immediately returning that failure state immediately

  - [`OUTCOME_TRYV2`](try#standardese-try.hpp)

  - [`OUTCOME_TRYX`](try#standardese-OUTCOME_TRYX) &mdash; If the outcome returned by expression … is not valued, propagate any failure by immediately returning that failure state immediately, else become the unwrapped value as an expression. This makes `OUTCOME_TRYX(expr)` an expression which can be used exactly like the `try` operator in other languages.

  - [`OUTCOME_TRY_GLUE`](try#standardese-try.hpp)

  - [`OUTCOME_TRY_GLUE2`](try#standardese-try.hpp)

  - [`OUTCOME_TRY_UNIQUE_NAME`](try#standardese-try.hpp)

  - [`cxx_error_code`](result#standardese-cxx_error_code) &mdash; A C struct representation of `std::error_code`.

  - ## Namespace `outcome_v2_xxx::convert`
    
    <a id="standardese-outcome_v2_xxx::convert"></a>
    
    Namespace for injected convertibility
    
      - [`ValueOrError`](convert#standardese-outcome_v2_xxx::convert)
    
      - [`ValueOrNone`](convert#standardese-outcome_v2_xxx::convert)
    
      - [`value_or_error`](convert#standardese-outcome_v2_xxx::convert::value_or_error\<T,U\>) &mdash; Default converter for types matching the `ValueOrError` concept.

  - ## Namespace `outcome_v2_xxx::hooks`
    
    <a id="standardese-outcome_v2_xxx::hooks"></a>
    
    Namespace for ADL discovered hooks into events in `result` and `outcome`.
    
      - [`hook_outcome_construction`](outcome#standardese-outcome_v2_xxx::hooks)
    
      - [`hook_outcome_copy_construction`](outcome#standardese-outcome_v2_xxx::hooks)
    
      - [`hook_outcome_in_place_construction`](outcome#standardese-outcome_v2_xxx::hooks)
    
      - [`hook_outcome_move_construction`](outcome#standardese-outcome_v2_xxx::hooks)
    
      - [`hook_result_construction`](result#standardese-outcome_v2_xxx::hooks::hook_result_construction\<T,U\>\(T*,U&&\)) &mdash; The default instantiation hook implementation called when a `result` is first created by conversion from one of its possible types. Does nothing.
    
      - [`hook_result_copy_construction`](result#standardese-outcome_v2_xxx::hooks::hook_result_copy_construction\<T,U\>\(T*,U&&\)) &mdash; The default instantiation hook implementation called when a `result` is created by copying from another `result`. Does nothing.
    
      - [`hook_result_in_place_construction`](result#standardese-outcome_v2_xxx::hooks::hook_result_in_place_construction\<T,U,Args\>\(T*,in_place_type_t\<U\>,Args&&...\)) &mdash; The default instantiation hook implementation called when a `result` is created by in place construction. Does nothing.
    
      - [`hook_result_move_construction`](result#standardese-outcome_v2_xxx::hooks::hook_result_move_construction\<T,U\>\(T*,U&&\)) &mdash; The default instantiation hook implementation called when a `result` is created by moving from another `result`. Does nothing.
    
      - [`override_outcome_exception`](outcome#standardese-outcome_v2_xxx::hooks)
    
      - [`set_spare_storage`](result#standardese-outcome_v2_xxx::hooks::set_spare_storage\<R,S,NoValuePolicy\>\(result_or_outcome\<R,S,NoValuePolicy\>*,uint16_t\)) &mdash; Sets the 16 bits of spare storage in result/outcome.
    
      - [`spare_storage`](result#standardese-outcome_v2_xxx::hooks::spare_storage\<R,S,NoValuePolicy\>\(result_or_outcome\<R,S,NoValuePolicy\>const*\)) &mdash; Retrieves the 16 bits of spare storage in result/outcome.

  - ## Namespace `outcome_v2_xxx::policy`
    
    <a id="standardese-outcome_v2_xxx::policy"></a>
    
    Namespace for policies
    
      - [`all_narrow`](policies/all_narrow#standardese-outcome_v2_xxx::policy::all_narrow) &mdash; Policy which treats wide checks as narrow checks.
    
      - [`default_policy`](result#standardese-outcome_v2_xxx::policy::default_policy\<T,EC,E\>) &mdash; Default policy selector.
    
      - [`error_code`](success_failure#standardese-outcome_v2_xxx::policy::error_code\<T\>\(T&&\)) &mdash; Used by policies to extract a `std::error_code` from some input `T` via ADL discovery of some `make_error_code(T)` function.
    
      - [`error_code_throw_as_system_error`](policies/outcome_error_code_throw_as_system_error#standardese-outcome_v2_xxx::policy::error_code_throw_as_system_error\<T,EC,E\>) &mdash; Policy interpreting `EC` as a type for which `trait::has_error_code_v<EC>` is true.
    
      - [`exception_ptr`](success_failure#standardese-outcome_v2_xxx::policy::exception_ptr\<T\>\(T&&\)) &mdash; Used by policies to extract a `std::exception_ptr` from some input `T` via ADL discovery of some `make_exception_ptr(T)` function.
    
      - [`exception_ptr_rethrow`](policies/outcome_exception_ptr_rethrow#standardese-outcome_v2_xxx::policy::exception_ptr_rethrow\<T,EC,E\>) &mdash; Policy interpreting `EC` or `E` as a type for which `trait::has_exception_ptr_v<EC|E>` is true.
    
      - [`terminate`](policies/terminate#standardese-outcome_v2_xxx::policy::terminate) &mdash; Policy implementing any wide attempt to access the successful state as calling `std::terminate`
    
      - [`throw_as_system_error_with_payload`](success_failure#standardese-outcome_v2_xxx::policy::throw_as_system_error_with_payload\<Error\>\(Errorconst&\)) &mdash; Override to define what the policies which throw a system error with payload ought to do for some particular `result.error()`.
    
      - [`throw_bad_result_access`](policies/throw_bad_result_access#standardese-outcome_v2_xxx::policy::throw_bad_result_access\<EC\>) &mdash; Policy which throws `bad_result_access_with<EC>` or `bad_result_access` during wide checks.

  - ## Namespace `outcome_v2_xxx::trait`
    
    <a id="standardese-outcome_v2_xxx::trait"></a>
    
    Namespace for traits
    
      - [`has_error_code`](success_failure#standardese-outcome_v2_xxx::trait::has_error_code\<T\>) &mdash; Trait for whether a free function `make_error_code(T)` returning a `std::error_code` exists or not.
    
      - [`has_error_code_v`](success_failure#standardese-outcome_v2_xxx::trait::has_error_code_v) &mdash; Trait for whether a free function `make_error_code(T)` returning a `std::error_code` exists or not.
    
      - [`has_exception_ptr`](success_failure#standardese-outcome_v2_xxx::trait::has_exception_ptr\<T\>) &mdash; Trait for whether a free function `make_exception_ptr(T)` returning a `std::exception_ptr` exists or not.
    
      - [`has_exception_ptr_v`](success_failure#standardese-outcome_v2_xxx::trait::has_exception_ptr_v) &mdash; Trait for whether a free function `make_exception_ptr(T)` returning a `std::exception_ptr` exists or not.

  - ## Namespace `outcome_v2_xxx`
    
    <a id="standardese-outcome_v2_xxx"></a>
    
      - [`bad_outcome_access`](bad_access#standardese-outcome_v2_xxx::bad_outcome_access) &mdash; Thrown when you try to access state in a `outcome<T, EC, E>` which isn’t present.
    
      - [`bad_result_access`](bad_access#standardese-outcome_v2_xxx::bad_result_access) &mdash; Thrown when you try to access state in a `result<R, S>` which isn’t present.
    
      - [`bad_result_access_with`](bad_access#standardese-outcome_v2_xxx::bad_result_access_with\<S\>) &mdash; Thrown when you try to access a vlue in a `result<R, S>` which isn’t present.
    
      - [`checked`](result#standardese-outcome_v2_xxx::checked\<R,S\>) &mdash; A “checked” edition of `result<T, E>` which does no special handling of specific `E` types at all.
    
      - [`error_from_exception`](utils#standardese-outcome_v2_xxx::error_from_exception\(std::exception_ptr&&,std::error_code\)) &mdash; Utility function which tries to match the exception in the pointer provided to an equivalent error code. Ought to work for all standard STL types.
    
      - [`failure`](success_failure#standardese-outcome_v2_xxx::failure\<EC\>\(EC&&\)) &mdash; Returns type sugar for implicitly constructing a `result<T>` with a failure state.
    
      - [`failure_type`](success_failure#standardese-outcome_v2_xxx::failure_type\<EC,E\>) &mdash; Type sugar for implicitly constructing a `result<>` with a failure state of error code and exception.
    
      - [`is_outcome`](outcome#standardese-outcome_v2_xxx)
    
      - [`is_outcome_v`](outcome#standardese-outcome_v2_xxx)
    
      - [`is_result`](result#standardese-outcome_v2_xxx::is_result\<T\>) &mdash; True if a result
    
      - [`is_result_v`](result#standardese-outcome_v2_xxx::is_result_v) &mdash; True if a result
    
      - [`no_error_type`](result#standardese-outcome_v2_xxx::no_error_type) &mdash; Placeholder type to indicate there is no error type
    
      - [`no_exception_type`](outcome#standardese-outcome_v2_xxx)
    
      - [`no_value_type`](result#standardese-outcome_v2_xxx::no_value_type) &mdash; Placeholder type to indicate there is no value type
    
      - [`operator!=`](outcome#standardese-outcome_v2_xxx)
    
      - [`operator<<`](iostream_support#standardese-outcome_v2_xxx::operator\<\<\<R,S,P\>\(std::ostream&,result\<R,S,P\>const&\)) &mdash; Serialise a result
    
      - [`operator==`](outcome#standardese-outcome_v2_xxx)
    
      - [`operator>>`](iostream_support#standardese-outcome_v2_xxx::operator\>\>\<R,S,P\>\(std::istream&,result\<R,S,P\>&\)) &mdash; Deserialise a result
    
      - [`outcome`](outcome#standardese-outcome_v2_xxx)
    
      - [`print`](iostream_support#standardese-outcome_v2_xxx::print\<R,S,P\>\(result_or_outcome\<R,S,P\>const&\)) &mdash; Debug print a result
    
      - [`result`](result#standardese-outcome_v2_xxx::result\<R,S,NoValuePolicy\>) &mdash; Used to return from functions either (i) a successful value (ii) a cause of failure. `constexpr` capable.
    
      - [`success`](success_failure#standardese-outcome_v2_xxx::success\<T\>\(T&&\)) &mdash; Returns type sugar for implicitly constructing a `result<T>` with a successful state, default constructing `T` if necessary.
    
      - [`success_type`](success_failure#standardese-outcome_v2_xxx::success_type\<T\>) &mdash; Type sugar for implicitly constructing a `result<>` with a successful state.
    
      - [`swap`](result#standardese-outcome_v2_xxx::swap\<R,S,P\>\(result\<R,S,P\>&,result\<R,S,P\>&\)) &mdash; Specialise swap for result.
    
      - [`try_operation_return_as`](try#standardese-outcome_v2_xxx::try_operation_return_as\<T\>\(T&&\)) &mdash; Customisation point for changing what the `OUTCOME_TRY` macros do. This function defaults to returning `std::forward<T>(v).as_failure()`.
    
      - [`try_throw_std_exception_from_error`](utils#standardese-outcome_v2_xxx::try_throw_std_exception_from_error\(std::error_code,std::stringconst&\)) &mdash; Utility function which tries to throw the equivalent STL exception type for some given error code, not including `system_error`.
    
      - [`unchecked`](result#standardese-outcome_v2_xxx::unchecked\<R,S\>) &mdash; An “unchecked” edition of `result<T, E>` which does no special handling of specific `E` types at all.
