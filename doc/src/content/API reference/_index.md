+++
title = "API reference"
weight = 20
+++
  - [OUTCOME\_ENABLE\_POSITIVE\_STATUS](doc_result.md#result.hpp "OUTCOME_ENABLE_POSITIVE_STATUS")

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

  - `outcome_v2_c9e8c1da`
    
      - [bad\_outcome\_access](doc_outcome.md#outcome_v2_c9e8c1da::bad_outcome_access "outcome_v2_c9e8c1da::bad_outcome_access") - Thrown when you try to access state in a `outcome<T, EC, E>` which isn't present.
    
      - [bad\_result\_access](doc_result.md#outcome_v2_c9e8c1da::bad_result_access "outcome_v2_c9e8c1da::bad_result_access") - Thrown when you try to access state in a `result<R, S>` which isn't present.
    
      - [hook\_outcome\_construction(in\_place\_type\_t\<T\>, U \*)](doc_outcome.md#outcome_v2_c9e8c1da::hook_outcome_construction(in_place_type_t-T-,U*) "outcome_v2_c9e8c1da::hook_outcome_construction(in_place_type_t\<T\>, U *)") - The default instantiation hook implementation called when a `outcome` is first created by conversion from one of its possible types. Does nothing.
    
      - [hook\_outcome\_copy\_construction(in\_place\_type\_t\<T\>, U \*)](doc_outcome.md#outcome_v2_c9e8c1da::hook_outcome_copy_construction(in_place_type_t-T-,U*) "outcome_v2_c9e8c1da::hook_outcome_copy_construction(in_place_type_t\<T\>, U *)") - The default instantiation hook implementation called when a `outcome` is created by copying from another `outcome` or `result`. Does nothing.
    
      - [hook\_outcome\_in\_place\_construction(in\_place\_type\_t\<T\>, U \*)](doc_outcome.md#outcome_v2_c9e8c1da::hook_outcome_in_place_construction(in_place_type_t-T-,U*) "outcome_v2_c9e8c1da::hook_outcome_in_place_construction(in_place_type_t\<T\>, U *)") - The default instantiation hook implementation called when a `outcome` is created by in place construction. Does nothing.
    
      - [hook\_outcome\_move\_construction(in\_place\_type\_t\<T\>, U \*)](doc_outcome.md#outcome_v2_c9e8c1da::hook_outcome_move_construction(in_place_type_t-T-,U*) "outcome_v2_c9e8c1da::hook_outcome_move_construction(in_place_type_t\<T\>, U *)") - The default instantiation hook implementation called when a `outcome` is created by moving from another `outcome` or `result`. Does nothing.
    
      - [hook\_result\_construction(in\_place\_type\_t\<T\>, U \*)](doc_result.md#outcome_v2_c9e8c1da::hook_result_construction(in_place_type_t-T-,U*) "outcome_v2_c9e8c1da::hook_result_construction(in_place_type_t\<T\>, U *)") - The default instantiation hook implementation called when a `result` is first created by conversion from one of its possible types. Does nothing.
    
      - [hook\_result\_copy\_construction(in\_place\_type\_t\<T\>, U \*)](doc_result.md#outcome_v2_c9e8c1da::hook_result_copy_construction(in_place_type_t-T-,U*) "outcome_v2_c9e8c1da::hook_result_copy_construction(in_place_type_t\<T\>, U *)") - The default instantiation hook implementation called when a `result` is created by copying from another `result`. Does nothing.
    
      - [hook\_result\_in\_place\_construction(in\_place\_type\_t\<T\>, U \*)](doc_result.md#outcome_v2_c9e8c1da::hook_result_in_place_construction(in_place_type_t-T-,U*) "outcome_v2_c9e8c1da::hook_result_in_place_construction(in_place_type_t\<T\>, U *)") - The default instantiation hook implementation called when a `result` is created by in place construction. Does nothing.
    
      - [hook\_result\_move\_construction(in\_place\_type\_t\<T\>, U \*)](doc_result.md#outcome_v2_c9e8c1da::hook_result_move_construction(in_place_type_t-T-,U*) "outcome_v2_c9e8c1da::hook_result_move_construction(in_place_type_t\<T\>, U *)") - The default instantiation hook implementation called when a `result` is created by moving from another `result`. Does nothing.
    
      - [no\_error\_type](doc_result.md#outcome_v2_c9e8c1da::no_error_type "outcome_v2_c9e8c1da::no_error_type") - Placeholder type to indicate there is no error type
    
      - [no\_exception\_type](doc_outcome.md#outcome_v2_c9e8c1da::no_exception_type "outcome_v2_c9e8c1da::no_exception_type") - Placeholder type to indicate there is no exception type
    
      - [no\_payload\_type](doc_outcome.md#outcome_v2_c9e8c1da::no_payload_type "outcome_v2_c9e8c1da::no_payload_type") - Placeholder type to indicate there is no payload type
    
      - [no\_value\_type](doc_result.md#outcome_v2_c9e8c1da::no_value_type "outcome_v2_c9e8c1da::no_value_type") - Placeholder type to indicate there is no value type
    
      - [operator\!=(const result\<T, U, V\> &, const outcome\<R, S, P, N\> &)](doc_outcome.md#outcome_v2_c9e8c1da::operator!=(constresult-T,U,V-&,constoutcome-R,S,P,N-&) "outcome_v2_c9e8c1da::operator!=(const result\<T, U, V\> &, const outcome\<R, S, P, N\> &)") - True if the result is not equal to the outcome
    
      - [operator==(const result\<T, U, V\> &, const outcome\<R, S, P, N\> &)](doc_outcome.md#outcome_v2_c9e8c1da::operator==(constresult-T,U,V-&,constoutcome-R,S,P,N-&) "outcome_v2_c9e8c1da::operator==(const result\<T, U, V\> &, const outcome\<R, S, P, N\> &)") - True if the result is equal to the outcome
    
      - [outcome](doc_outcome.md#outcome_v2_c9e8c1da::outcome-R,S,P,NoValuePolicy- "outcome_v2_c9e8c1da::outcome\<R, S, P, NoValuePolicy\>") - Used to return from functions (i) a value and (a positive status and/or a payload) or (ii) no value and (a negative status and/or a payload). `constexpr` capable.
    
      - [result](doc_result.md#outcome_v2_c9e8c1da::result-R,S,NoValuePolicy- "outcome_v2_c9e8c1da::result\<R, S, NoValuePolicy\>") - Used to return from functions (i) a value (ii) a value and a positive status or (iii) no value and a negative status. `constexpr` capable.

  - `outcome_v2_c9e8c1da::impl`
    
      - [outcome\_exception\_observers](doc_outcome.md#outcome_v2_c9e8c1da::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy- "outcome_v2_c9e8c1da::impl::outcome_exception_observers\<Base, R, S, P, NoValuePolicy\>") - The exception observers implementation of `outcome<R, S, P>`. Only appears separate due to standardese limitations.
    
      - [outcome\_exception\_observers\<Base, R, S, void, NoValuePolicy\>](doc_outcome.md#outcome.hpp "outcome_v2_c9e8c1da::impl::outcome_exception_observers\<Base, R, S, void, NoValuePolicy\>")
    
      - [outcome\_failure\_observers](doc_outcome.md#outcome_v2_c9e8c1da::impl::outcome_failure_observers-Base,R,S,P,NoValuePolicy- "outcome_v2_c9e8c1da::impl::outcome_failure_observers\<Base, R, S, P, NoValuePolicy\>") - The failure observers implementation of `outcome<R, S, P>`. Only appears separate due to standardese limitations.
    
      - [outcome\_failure\_observers\<Base, R, std::error\_code, std::exception\_ptr, NoValuePolicy\>](doc_outcome.md#outcome.hpp "outcome_v2_c9e8c1da::impl::outcome_failure_observers\<Base, R, std::error_code, std::exception_ptr, NoValuePolicy\>")
    
      - [outcome\_payload\_observers](doc_outcome.md#outcome_v2_c9e8c1da::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy- "outcome_v2_c9e8c1da::impl::outcome_payload_observers\<Base, R, S, P, NoValuePolicy\>") - The payload observers implementation of `outcome<R, S, P>`. Only appears separate due to standardese limitations.
    
      - [outcome\_payload\_observers\<Base, R, S, void, NoValuePolicy\>](doc_outcome.md#outcome.hpp "outcome_v2_c9e8c1da::impl::outcome_payload_observers\<Base, R, S, void, NoValuePolicy\>")
    
      - [result\_error\_observers](doc_result.md#outcome_v2_c9e8c1da::impl::result_error_observers-Base,EC,NoValuePolicy- "outcome_v2_c9e8c1da::impl::result_error_observers\<Base, EC, NoValuePolicy\>") - The error observers implementation of `result<R, EC, NoValuePolicy>`. Only appears separate due to standardese limitations.
    
      - [result\_error\_observers\<Base, void, NoValuePolicy\>](doc_result.md#result.hpp "outcome_v2_c9e8c1da::impl::result_error_observers\<Base, void, NoValuePolicy\>")
    
      - [result\_final](doc_result.md#outcome_v2_c9e8c1da::impl::result_final-R,S,NoValuePolicy- "outcome_v2_c9e8c1da::impl::result_final\<R, S, NoValuePolicy\>") - The assembled implementation type of `result<R, EC, NoValuePolicy>`. Only appears separate due to standardese limitations.
    
      - [result\_storage](doc_result.md#outcome_v2_c9e8c1da::impl::result_storage-R,EC,NoValuePolicy- "outcome_v2_c9e8c1da::impl::result_storage\<R, EC, NoValuePolicy\>") - The base implementation type of `result<R, EC, NoValuePolicy>`. Only appears separate due to standardese limitations.
    
      - [result\_value\_observers](doc_result.md#outcome_v2_c9e8c1da::impl::result_value_observers-Base,R,NoValuePolicy- "outcome_v2_c9e8c1da::impl::result_value_observers\<Base, R, NoValuePolicy\>") - The value observers implementation of `result<R, EC, NoValuePolicy>`. Only appears separate due to standardese limitations.
    
      - [result\_value\_observers\<Base, void, NoValuePolicy\>](doc_result.md#result.hpp "outcome_v2_c9e8c1da::impl::result_value_observers\<Base, void, NoValuePolicy\>")
    
      - [select\_result\_impl](doc_result.md#result.hpp "outcome_v2_c9e8c1da::impl::select_result_impl\<R, EC, NoValuePolicy\>")

  - `outcome_v2_c9e8c1da::policy`
    
      - [default\_outcome\_policy](doc_outcome.md#outcome_v2_c9e8c1da::policy::default_outcome_policy-R,S,P- "outcome_v2_c9e8c1da::policy::default_outcome_policy\<R, S, P\>") - Default `outcome<R, S, P>` policy selector.
    
      - [default\_result\_policy](doc_result.md#outcome_v2_c9e8c1da::policy::default_result_policy-EC- "outcome_v2_c9e8c1da::policy::default_result_policy\<EC\>") - Default `result<R, S>` policy selector.
    
      - [error\_code\_throw\_as\_system\_error](doc_result.md#outcome_v2_c9e8c1da::policy::error_code_throw_as_system_error-EC- "outcome_v2_c9e8c1da::policy::error_code_throw_as_system_error\<EC\>") - Policy interpreting EC as a type implementing the `std::error_code` contract and any wide attempt to access the successful state throws the `error_code` wrapped into a `std::system_error`
    
      - [error\_code\_throw\_as\_system\_error\_exception\_rethrow](doc_outcome.md#outcome_v2_c9e8c1da::policy::error_code_throw_as_system_error_exception_rethrow-R,S,P- "outcome_v2_c9e8c1da::policy::error_code_throw_as_system_error_exception_rethrow\<R, S, P\>") - Policy interpreting S as a type implementing the `std::error_code` contract, E as a type implementing the `std::exception_ptr` contract, and any wide attempt to access the successful state throws the `exception_ptr` if available, then the `error_code` wrapped into a `std::system_error`.
    
      - [exception\_ptr\_rethrow](doc_result.md#outcome_v2_c9e8c1da::policy::exception_ptr_rethrow-EC- "outcome_v2_c9e8c1da::policy::exception_ptr_rethrow\<EC\>") - Policy interpreting EC as a type implementing the `std::exception_ptr` contract and any wide attempt to access the successful state calls `std::rethrow_exception()`.
    
      - [terminate](doc_result.md#outcome_v2_c9e8c1da::policy::terminate "outcome_v2_c9e8c1da::policy::terminate") - Policy implementing any wide attempt to access the successful state as calling `std::terminate`
    
      - [throw\_directly](doc_result.md#outcome_v2_c9e8c1da::policy::throw_directly-EC- "outcome_v2_c9e8c1da::policy::throw_directly\<EC\>") - Policy interpreting EC as a type to be thrown directly during wide checks.

  - `outcome_v2_c9e8c1da::trait` - Namespace for traits
    
      - [is\_exception\_ptr](doc_outcome.md#outcome_v2_c9e8c1da::trait::is_exception_ptr-P- "outcome_v2_c9e8c1da::trait::is_exception_ptr\<P\>") - Trait for whether type `P` is to be considered a payload to an exception.
