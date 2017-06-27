+++
title = "API reference"
weight = 20
+++
  - [OUTCOME\_ENABLE\_POSITIVE\_STATUS](doc_result.md#OUTCOME_ENABLE_POSITIVE_STATUS "OUTCOME_ENABLE_POSITIVE_STATUS") - Define to enable positive value + status returns

  - [OUTCOME\_NODISCARD](doc_result.md#result.hpp "OUTCOME_NODISCARD")

  - [OUTCOME\_OUTCOME\_HPP](doc_outcome.md#outcome.hpp "OUTCOME_OUTCOME_HPP")

  - [OUTCOME\_RESULT\_HPP](doc_result.md#result.hpp "OUTCOME_RESULT_HPP")

  - [OUTCOME\_SYMBOL\_VISIBLE](doc_result.md#result.hpp "OUTCOME_SYMBOL_VISIBLE")

  - `outcome`
    
      - [bad\_outcome\_access](doc_outcome.md#outcome::bad_outcome_access "outcome::bad_outcome_access") - Thrown when you try to access state in a `outcome<T, EC, E>` which isn't present.
    
      - [bad\_result\_access](doc_result.md#outcome::bad_result_access "outcome::bad_result_access") - Thrown when you try to access state in a `result<R, S>` which isn't present.
    
      - [in\_place\_type\_t](doc_result.md#outcome::in_place_type_t-T- "outcome::in_place_type_t\<T\>") - Aliases `std::in_place_type_t<T>` if on C++ 17 or later, else defined locally.
    
      - [no\_error\_type](doc_result.md#outcome::no_error_type "outcome::no_error_type") - Placeholder type to indicate there is no error type
    
      - [no\_exception\_type](doc_outcome.md#outcome::no_exception_type "outcome::no_exception_type") - Placeholder type to indicate there is no exception type
    
      - [no\_payload\_type](doc_outcome.md#outcome::no_payload_type "outcome::no_payload_type") - Placeholder type to indicate there is no payload type
    
      - [outcome](doc_outcome.md#outcome::outcome-R,S,P,NoValuePolicy- "outcome::outcome\<R, S, P, NoValuePolicy\>") - Used to return from functions (i) a value and (a positive status and/or a payload) or (ii) no value and (a negative status and/or a payload). `constexpr` capable.
    
      - [result](doc_result.md#outcome::result-R,S,NoValuePolicy- "outcome::result\<R, S, NoValuePolicy\>") - Used to return from functions (i) a value (ii) a value and a positive status or (iii) no value and a negative status. `constexpr` capable.
    
      - [result\<void, void, NoValuePolicy\>](doc_result.md#outcome::result-void,void,NoValuePolicy- "outcome::result\<void, void, NoValuePolicy\>") - `result<void, void>` specialisation.

  - `outcome::impl`
    
      - [outcome\_exception\_observers](doc_outcome.md#outcome::impl::outcome_exception_observers-Base,R,S,P,NoValuePolicy- "outcome::impl::outcome_exception_observers\<Base, R, S, P, NoValuePolicy\>") - The exception observers implementation of `outcome<R, S, P>`. Only appears separate due to standardese limitations.
    
      - [outcome\_exception\_observers\<Base, R, S, void, NoValuePolicy\>](doc_outcome.md#outcome.hpp "outcome::impl::outcome_exception_observers\<Base, R, S, void, NoValuePolicy\>")
    
      - [outcome\_payload\_observers](doc_outcome.md#outcome::impl::outcome_payload_observers-Base,R,S,P,NoValuePolicy- "outcome::impl::outcome_payload_observers\<Base, R, S, P, NoValuePolicy\>") - The payload observers implementation of `outcome<R, S, P>`. Only appears separate due to standardese limitations.
    
      - [outcome\_payload\_observers\<Base, R, S, void, NoValuePolicy\>](doc_outcome.md#outcome.hpp "outcome::impl::outcome_payload_observers\<Base, R, S, void, NoValuePolicy\>")
    
      - [result\_error\_observers](doc_result.md#outcome::impl::result_error_observers-Base,EC,NoValuePolicy- "outcome::impl::result_error_observers\<Base, EC, NoValuePolicy\>") - The error observers implementation of `result<R, EC, NoValuePolicy>`. Only appears separate due to standardese limitations.
    
      - [result\_error\_observers\<Base, void, NoValuePolicy\>](doc_result.md#result.hpp "outcome::impl::result_error_observers\<Base, void, NoValuePolicy\>")
    
      - [result\_final](doc_result.md#outcome::impl::result_final-R,S,NoValuePolicy- "outcome::impl::result_final\<R, S, NoValuePolicy\>") - The assembled implementation type of `result<R, EC, NoValuePolicy>`. Only appears separate due to standardese limitations.
    
      - [result\_storage](doc_result.md#outcome::impl::result_storage-R,EC,NoValuePolicy- "outcome::impl::result_storage\<R, EC, NoValuePolicy\>") - The base implementation type of `result<R, EC, NoValuePolicy>`. Only appears separate due to standardese limitations.
    
      - [result\_value\_observers](doc_result.md#outcome::impl::result_value_observers-Base,R,NoValuePolicy- "outcome::impl::result_value_observers\<Base, R, NoValuePolicy\>") - The value observers implementation of `result<R, EC, NoValuePolicy>`. Only appears separate due to standardese limitations.
    
      - [result\_value\_observers\<Base, void, NoValuePolicy\>](doc_result.md#result.hpp "outcome::impl::result_value_observers\<Base, void, NoValuePolicy\>")
    
      - [select\_result\_impl](doc_result.md#result.hpp "outcome::impl::select_result_impl\<R, EC, NoValuePolicy\>")

  - `outcome::policy`
    
      - [default\_outcome\_policy](doc_outcome.md#outcome::policy::default_outcome_policy-R,S,P- "outcome::policy::default_outcome_policy\<R, S, P\>") - Default `outcome<R, S, P>` policy selector.
    
      - [default\_result\_policy](doc_result.md#outcome::policy::default_result_policy-EC- "outcome::policy::default_result_policy\<EC\>") - Default `result<R, S>` policy selector.
    
      - [error\_code\_throw\_as\_system\_error](doc_result.md#outcome::policy::error_code_throw_as_system_error-EC- "outcome::policy::error_code_throw_as_system_error\<EC\>") - Policy interpreting EC as a type implementing the `std::error_code` contract and any wide attempt to access the successful state throws the `error_code` wrapped into a `std::system_error`
    
      - [error\_code\_throw\_as\_system\_error\_exception\_rethrow](doc_outcome.md#outcome::policy::error_code_throw_as_system_error_exception_rethrow-R,S,P- "outcome::policy::error_code_throw_as_system_error_exception_rethrow\<R, S, P\>") - Policy interpreting S as a type implementing the `std::error_code` contract, E as a type implementing the `std::exception_ptr` contract, and any wide attempt to access the successful state throws the `exception_ptr` if available, then the `error_code` wrapped into a `std::system_error`.
    
      - [exception\_ptr\_rethrow](doc_result.md#outcome::policy::exception_ptr_rethrow-EC- "outcome::policy::exception_ptr_rethrow\<EC\>") - Policy interpreting EC as a type implementing the `std::exception_ptr` contract and any wide attempt to access the successful state calls `std::rethrow_exception()`.
    
      - [terminate](doc_result.md#outcome::policy::terminate "outcome::policy::terminate") - Policy implementing any wide attempt to access the successful state as calling `std::terminate`
    
      - [throw\_directly](doc_result.md#outcome::policy::throw_directly-EC- "outcome::policy::throw_directly\<EC\>") - Policy interpreting EC as a type to be thrown directly during wide checks.

  - `outcome::trait` - Namespace for traits
    
      - [is\_exception\_ptr](doc_outcome.md#outcome::trait::is_exception_ptr-P- "outcome::trait::is_exception_ptr\<P\>") - Trait for whether type `P` is to be considered a payload to an exception.
