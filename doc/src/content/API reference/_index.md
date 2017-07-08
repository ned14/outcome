+++
title = "API reference"
weight = 20
+++
  - [OUTCOME\_ENABLE\_POSITIVE\_STATUS](doc_result.md#result.hpp "OUTCOME_ENABLE_POSITIVE_STATUS")

  - [OUTCOME\_ERROR\_FROM\_EXCEPTION\_HPP](doc_utils.md#utils.hpp "OUTCOME_ERROR_FROM_EXCEPTION_HPP")

  - [OUTCOME\_IOSTREAM\_SUPPORT\_HPP](doc_iostream_support.md#iostream_support.hpp "OUTCOME_IOSTREAM_SUPPORT_HPP")

  - [OUTCOME\_OUTCOME\_HPP](doc_outcome.md#outcome.hpp "OUTCOME_OUTCOME_HPP")

  - [OUTCOME\_RESULT\_HPP](doc_result.md#result.hpp "OUTCOME_RESULT_HPP")

  - [OUTCOME\_TRY](doc_try.md#OUTCOME_TRY "OUTCOME_TRY") - If the outcome returned by expression *m* is not valued, propagate any failure by immediately returning that failure immediately, else set \*v( to the unwrapped value

  - [OUTCOME\_TRY2](doc_try.md#try.hpp "OUTCOME_TRY2")

  - [OUTCOME\_TRYV](doc_try.md#OUTCOME_TRYV "OUTCOME_TRYV") - If the outcome returned by expression *m* is not valued, propagate any failure by immediately returning that failure state immediately

  - [OUTCOME\_TRYV2](doc_try.md#try.hpp "OUTCOME_TRYV2")

  - [OUTCOME\_TRYX](doc_try.md#OUTCOME_TRYX "OUTCOME_TRYX") - If the outcome returned by expression *m* is not valued, propagate any failure by immediately returning that failure state immediately, else become the unwrapped value as an expression. This makes `OUTCOME_TRYX(expr)` an expression which can be used exactly like the `try` operator in other languages.

  - [OUTCOME\_TRY\_GLUE](doc_try.md#try.hpp "OUTCOME_TRY_GLUE")

  - [OUTCOME\_TRY\_GLUE2](doc_try.md#try.hpp "OUTCOME_TRY_GLUE2")

  - [OUTCOME\_TRY\_HPP](doc_try.md#try.hpp "OUTCOME_TRY_HPP")

  - [OUTCOME\_TRY\_UNIQUE\_NAME](doc_try.md#try.hpp "OUTCOME_TRY_UNIQUE_NAME")

  - `outcome_v2_xxx`
    
      - [bad\_outcome\_access](doc_outcome.md#outcome_v2_xxx::bad_outcome_access "outcome_v2_xxx::bad_outcome_access") - Thrown when you try to access state in a `outcome<T, EC, E>` which isn't present.
    
      - [bad\_result\_access](doc_result.md#outcome_v2_xxx::bad_result_access "outcome_v2_xxx::bad_result_access") - Thrown when you try to access state in a `result<R, S>` which isn't present.
    
      - [error\_from\_exception(std::exception\_ptr &&, std::error\_code)](doc_utils.md#outcome_v2_xxx::error_from_exception(std::exception_ptr&&,std::error_code) "outcome_v2_xxx::error_from_exception(std::exception_ptr &&, std::error_code)") - Utility function which tries to match the exception in the pointer provided to an equivalent error code. Ought to work for all standard STL types. param e The pointer to an exception to convert. If matched, on exit this is reset to a null pointer. param not\_matched The error code to return if we could not match the exception. Note that a null pointer in returns a null error code.
    
      - [hook\_outcome\_construction(in\_place\_type\_t\<T\>, U \*)](doc_outcome.md#outcome_v2_xxx::hook_outcome_construction(in_place_type_t-T-,U*) "outcome_v2_xxx::hook_outcome_construction(in_place_type_t\<T\>, U *)") - The default instantiation hook implementation called when a `outcome` is first created by conversion from one of its possible types. Does nothing.
    
      - [hook\_outcome\_copy\_construction(in\_place\_type\_t\<T\>, U \*)](doc_outcome.md#outcome_v2_xxx::hook_outcome_copy_construction(in_place_type_t-T-,U*) "outcome_v2_xxx::hook_outcome_copy_construction(in_place_type_t\<T\>, U *)") - The default instantiation hook implementation called when a `outcome` is created by copying from another `outcome` or `result`. Does nothing.
    
      - [hook\_outcome\_in\_place\_construction(in\_place\_type\_t\<T\>, U \*)](doc_outcome.md#outcome_v2_xxx::hook_outcome_in_place_construction(in_place_type_t-T-,U*) "outcome_v2_xxx::hook_outcome_in_place_construction(in_place_type_t\<T\>, U *)") - The default instantiation hook implementation called when a `outcome` is created by in place construction. Does nothing.
    
      - [hook\_outcome\_move\_construction(in\_place\_type\_t\<T\>, U \*)](doc_outcome.md#outcome_v2_xxx::hook_outcome_move_construction(in_place_type_t-T-,U*) "outcome_v2_xxx::hook_outcome_move_construction(in_place_type_t\<T\>, U *)") - The default instantiation hook implementation called when a `outcome` is created by moving from another `outcome` or `result`. Does nothing.
    
      - [hook\_result\_construction(in\_place\_type\_t\<T\>, U \*)](doc_result.md#outcome_v2_xxx::hook_result_construction(in_place_type_t-T-,U*) "outcome_v2_xxx::hook_result_construction(in_place_type_t\<T\>, U *)") - The default instantiation hook implementation called when a `result` is first created by conversion from one of its possible types. Does nothing.
    
      - [hook\_result\_copy\_construction(in\_place\_type\_t\<T\>, U \*)](doc_result.md#outcome_v2_xxx::hook_result_copy_construction(in_place_type_t-T-,U*) "outcome_v2_xxx::hook_result_copy_construction(in_place_type_t\<T\>, U *)") - The default instantiation hook implementation called when a `result` is created by copying from another `result`. Does nothing.
    
      - [hook\_result\_in\_place\_construction(in\_place\_type\_t\<T\>, U \*)](doc_result.md#outcome_v2_xxx::hook_result_in_place_construction(in_place_type_t-T-,U*) "outcome_v2_xxx::hook_result_in_place_construction(in_place_type_t\<T\>, U *)") - The default instantiation hook implementation called when a `result` is created by in place construction. Does nothing.
    
      - [hook\_result\_move\_construction(in\_place\_type\_t\<T\>, U \*)](doc_result.md#outcome_v2_xxx::hook_result_move_construction(in_place_type_t-T-,U*) "outcome_v2_xxx::hook_result_move_construction(in_place_type_t\<T\>, U *)") - The default instantiation hook implementation called when a `result` is created by moving from another `result`. Does nothing.
    
      - [no\_error\_type](doc_result.md#outcome_v2_xxx::no_error_type "outcome_v2_xxx::no_error_type") - Placeholder type to indicate there is no error type
    
      - [no\_exception\_type](doc_outcome.md#outcome_v2_xxx::no_exception_type "outcome_v2_xxx::no_exception_type") - Placeholder type to indicate there is no exception type
    
      - [no\_payload\_type](doc_outcome.md#outcome_v2_xxx::no_payload_type "outcome_v2_xxx::no_payload_type") - Placeholder type to indicate there is no payload type
    
      - [no\_value\_type](doc_result.md#outcome_v2_xxx::no_value_type "outcome_v2_xxx::no_value_type") - Placeholder type to indicate there is no value type
    
      - [operator\!=(const result\<T, U, V\> &, const outcome\<R, S, P, N\> &)](doc_outcome.md#outcome_v2_xxx::operator!=(constresult-T,U,V-&,constoutcome-R,S,P,N-&) "outcome_v2_xxx::operator!=(const result\<T, U, V\> &, const outcome\<R, S, P, N\> &)") - True if the result is not equal to the outcome
    
      - [operator\<\<(std::ostream &, const outcome\<R, S, P, N\> &)](doc_iostream_support.md#outcome_v2_xxx::operator--(std::ostream&,constoutcome-R,S,P,N-&) "outcome_v2_xxx::operator\<\<(std::ostream &, const outcome\<R, S, P, N\> &)") - Serialise an outcome
    
      - [operator\<\<(std::ostream &, const result\<R, S, P\> &)](doc_iostream_support.md#outcome_v2_xxx::operator--(std::ostream&,constresult-R,S,P-&) "outcome_v2_xxx::operator\<\<(std::ostream &, const result\<R, S, P\> &)") - Serialise a result
    
      - [operator==(const result\<T, U, V\> &, const outcome\<R, S, P, N\> &)](doc_outcome.md#outcome_v2_xxx::operator==(constresult-T,U,V-&,constoutcome-R,S,P,N-&) "outcome_v2_xxx::operator==(const result\<T, U, V\> &, const outcome\<R, S, P, N\> &)") - True if the result is equal to the outcome
    
      - [operator\>\>(std::istream &, outcome\<R, S, P, N\> &)](doc_iostream_support.md#outcome_v2_xxx::operator--(std::istream&,outcome-R,S,P,N-&) "outcome_v2_xxx::operator\>\>(std::istream &, outcome\<R, S, P, N\> &)") - Deserialise an outcome
    
      - [operator\>\>(std::istream &, result\<R, S, P\> &)](doc_iostream_support.md#outcome_v2_xxx::operator--(std::istream&,result-R,S,P-&) "outcome_v2_xxx::operator\>\>(std::istream &, result\<R, S, P\> &)") - Deserialise a result
    
      - [outcome](doc_outcome.md#outcome_v2_xxx::outcome-R,S,P,NoValuePolicy- "outcome_v2_xxx::outcome\<R, S, P, NoValuePolicy\>") - Used to return from functions (i) a value and (a positive status and/or a payload) or (ii) no value and (a negative status and/or a payload). `constexpr` capable.
    
      - [print(const outcome\<R, S, P, N\> &)](doc_iostream_support.md#outcome_v2_xxx::print(constoutcome-R,S,P,N-&) "outcome_v2_xxx::print(const outcome\<R, S, P, N\> &)") - Debug print an outcome
    
      - [print(const result\<R, S, P\> &)](doc_iostream_support.md#outcome_v2_xxx::print(constresult-R,S,P-&) "outcome_v2_xxx::print(const result\<R, S, P\> &)") - Debug print a result
    
      - [result](doc_result.md#outcome_v2_xxx::result-R,S,NoValuePolicy- "outcome_v2_xxx::result\<R, S, NoValuePolicy\>") - Used to return from functions (i) a value (ii) a value and a positive status or (iii) no value and a negative status. `constexpr` capable.
    
      - [swap(outcome\<R, S, P, N\> &, outcome\<R, S, P, N\> &)](doc_outcome.md#outcome_v2_xxx::swap(outcome-R,S,P,N-&,outcome-R,S,P,N-&) "outcome_v2_xxx::swap(outcome\<R, S, P, N\> &, outcome\<R, S, P, N\> &)") - Specialise swap for outcome.
    
      - [swap(result\<R, S, P\> &, result\<R, S, P\> &)](doc_result.md#outcome_v2_xxx::swap(result-R,S,P-&,result-R,S,P-&) "outcome_v2_xxx::swap(result\<R, S, P\> &, result\<R, S, P\> &)") - Specialise swap for result.
    
      - [try\_operation\_return\_as(T &&)](doc_try.md#outcome_v2_xxx::try_operation_return_as(T&&) "outcome_v2_xxx::try_operation_return_as(T &&)") - Customisation point for changing what the `OUTCOME_TRY` macros do. This function defaults to returning `std::move(v).as_void()`.

  - `outcome_v2_xxx::impl`
    
      - [outcome\_exception\_observers](doc_outcome.md#outcome_v2_xxx::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy- "outcome_v2_xxx::impl::outcome_exception_observers\<Base, R, S, P, NoValuePolicy\>") - The exception observers implementation of `outcome<R, S, P>`. Only appears separate due to standardese limitations.
    
      - [outcome\_exception\_observers\<Base, R, S, void, NoValuePolicy\>](doc_outcome.md#outcome.hpp "outcome_v2_xxx::impl::outcome_exception_observers\<Base, R, S, void, NoValuePolicy\>")
    
      - [outcome\_failure\_observers](doc_outcome.md#outcome_v2_xxx::impl::outcome_failure_observers-Base,R,S,P,NoValuePolicy- "outcome_v2_xxx::impl::outcome_failure_observers\<Base, R, S, P, NoValuePolicy\>") - The failure observers implementation of `outcome<R, S, P>`. Only appears separate due to standardese limitations.
    
      - [outcome\_failure\_observers\<Base, R, std::error\_code, std::exception\_ptr, NoValuePolicy\>](doc_outcome.md#outcome.hpp "outcome_v2_xxx::impl::outcome_failure_observers\<Base, R, std::error_code, std::exception_ptr, NoValuePolicy\>")
    
      - [outcome\_payload\_observers](doc_outcome.md#outcome_v2_xxx::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy- "outcome_v2_xxx::impl::outcome_payload_observers\<Base, R, S, P, NoValuePolicy\>") - The payload observers implementation of `outcome<R, S, P>`. Only appears separate due to standardese limitations.
    
      - [outcome\_payload\_observers\<Base, R, S, void, NoValuePolicy\>](doc_outcome.md#outcome.hpp "outcome_v2_xxx::impl::outcome_payload_observers\<Base, R, S, void, NoValuePolicy\>")
    
      - [result\_error\_observers](doc_result.md#outcome_v2_xxx::impl::result_error_observers-Base,EC,NoValuePolicy- "outcome_v2_xxx::impl::result_error_observers\<Base, EC, NoValuePolicy\>") - The error observers implementation of `result<R, EC, NoValuePolicy>`. Only appears separate due to standardese limitations.
    
      - [result\_error\_observers\<Base, void, NoValuePolicy\>](doc_result.md#result.hpp "outcome_v2_xxx::impl::result_error_observers\<Base, void, NoValuePolicy\>")
    
      - [result\_final](doc_result.md#outcome_v2_xxx::impl::result_final-R,S,NoValuePolicy- "outcome_v2_xxx::impl::result_final\<R, S, NoValuePolicy\>") - The assembled implementation type of `result<R, EC, NoValuePolicy>`. Only appears separate due to standardese limitations.
    
      - [result\_storage](doc_result.md#outcome_v2_xxx::impl::result_storage-R,EC,NoValuePolicy- "outcome_v2_xxx::impl::result_storage\<R, EC, NoValuePolicy\>") - The base implementation type of `result<R, EC, NoValuePolicy>`. Only appears separate due to standardese limitations.
    
      - [result\_value\_observers](doc_result.md#outcome_v2_xxx::impl::result_value_observers-Base,R,NoValuePolicy- "outcome_v2_xxx::impl::result_value_observers\<Base, R, NoValuePolicy\>") - The value observers implementation of `result<R, EC, NoValuePolicy>`. Only appears separate due to standardese limitations.
    
      - [result\_value\_observers\<Base, void, NoValuePolicy\>](doc_result.md#result.hpp "outcome_v2_xxx::impl::result_value_observers\<Base, void, NoValuePolicy\>")
    
      - [select\_result\_impl](doc_result.md#result.hpp "outcome_v2_xxx::impl::select_result_impl\<R, EC, NoValuePolicy\>")

  - `outcome_v2_xxx::policy`
    
      - [default\_outcome\_policy](doc_outcome.md#outcome_v2_xxx::policy::default_outcome_policy-R,S,P- "outcome_v2_xxx::policy::default_outcome_policy\<R, S, P\>") - Default `outcome<R, S, P>` policy selector.
    
      - [default\_result\_policy](doc_result.md#outcome_v2_xxx::policy::default_result_policy-EC- "outcome_v2_xxx::policy::default_result_policy\<EC\>") - Default `result<R, S>` policy selector.
    
      - [error\_code\_throw\_as\_system\_error](doc_result.md#outcome_v2_xxx::policy::error_code_throw_as_system_error-EC- "outcome_v2_xxx::policy::error_code_throw_as_system_error\<EC\>") - Policy interpreting EC as a type implementing the `std::error_code` contract and any wide attempt to access the successful state throws the `error_code` wrapped into a `std::system_error`
    
      - [error\_code\_throw\_as\_system\_error\_exception\_rethrow](doc_outcome.md#outcome_v2_xxx::policy::error_code_throw_as_system_error_exception_rethrow-R,S,P- "outcome_v2_xxx::policy::error_code_throw_as_system_error_exception_rethrow\<R, S, P\>") - Policy interpreting S as a type implementing the `std::error_code` contract, E as a type implementing the `std::exception_ptr` contract, and any wide attempt to access the successful state throws the `exception_ptr` if available, then the `error_code` wrapped into a `std::system_error`.
    
      - [exception\_ptr\_rethrow](doc_result.md#outcome_v2_xxx::policy::exception_ptr_rethrow-EC- "outcome_v2_xxx::policy::exception_ptr_rethrow\<EC\>") - Policy interpreting EC as a type implementing the `std::exception_ptr` contract and any wide attempt to access the successful state calls `std::rethrow_exception()`.
    
      - [terminate](doc_result.md#outcome_v2_xxx::policy::terminate "outcome_v2_xxx::policy::terminate") - Policy implementing any wide attempt to access the successful state as calling `std::terminate`
    
      - [throw\_directly](doc_result.md#outcome_v2_xxx::policy::throw_directly-EC- "outcome_v2_xxx::policy::throw_directly\<EC\>") - Policy interpreting EC as a type to be thrown directly during wide checks.

  - `outcome_v2_xxx::trait` - Namespace for traits
    
      - [is\_exception\_ptr](doc_outcome.md#outcome_v2_xxx::trait::is_exception_ptr-P- "outcome_v2_xxx::trait::is_exception_ptr\<P\>") - Trait for whether type `P` is to be considered a payload to an exception.
