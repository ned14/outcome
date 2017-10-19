+++
title = "Policies"
description = "Defining your own NoValuePolicy policies, plus an overview of the precanned policies which come in the Outcome source code."
weight = 60
+++

Earlier in the section on [Default actions](../default-actions), we covered all the different
actions which Outcome can take upon incorrect observation, and we noted that this facility
is fully programmable.

`result<T, EC>` is actually `result<T, EC, NoValuePolicy>`. So is `outcome<T, EC, EP|P>` in
fact `outcome<T, EC, EP|P, NoValuePolicy>`. The `NoValuePolicy` template type is defaulted
to a template alias as follows:

- For `result<T, EC>`, `NoValuePolicy` is defaulted to:

  ```c++
namespace policy {
  template <class T, class EC>
  using default_result_policy = std::conditional_t<
    std::is_void<EC>::value, terminate,
    std::conditional_t<
    std::is_error_code_enum<EC>::value || std::is_error_condition_enum<EC>::value, error_enum_throw_as_system_error<EC>,
    std::conditional_t<
    trait::is_error_code<EC>::value, error_code_throw_as_system_error<EC>,
    std::conditional_t<
    trait::is_exception_ptr<EC>::value, exception_ptr_rethrow<T, EC, void>,
    all_narrow
  >>>>;
}
  ```  
- For `outcome<R, S, P>`, `NoValuePolicy` is defaulted to:

  ```c++
namespace policy {
  template <class R, class S, class P>
  using default_outcome_policy = std::conditional_t<
    (std::is_error_code_enum<S>::value || std::is_error_condition_enum<S>::value) && trait::is_exception_ptr<P>::value, error_enum_throw_as_system_error_exception_rethrow<R, S, P>, std::conditional_t<
    (std::is_error_code_enum<S>::value || std::is_error_condition_enum<S>::value) && !trait::is_exception_ptr<P>::value, error_enum_throw_as_system_error_with_payload<R, S, P>,std::conditional_t<
    trait::is_error_code<S>::value && trait::is_exception_ptr<P>::value, error_code_throw_as_system_error_exception_rethrow<R, S, P>,std::conditional_t<
    trait::is_error_code<S>::value && !trait::is_exception_ptr<P>::value, error_code_throw_as_system_error_with_payload<R, S, P>,
    std::conditional_t<  
    trait::is_exception_ptr<S>::value, exception_ptr_rethrow_with_payload<R, S, P>,
    std::conditional_t<  
    trait::is_exception_ptr<P>::value, exception_ptr_rethrow<R, S, P>,
    std::conditional_t<  
    std::is_void<S>::value, terminate,
    all_narrow  
  >>>>>>>;
}
  ```
- For `unchecked<T, EC>`, `NoValuePolicy` is set to `policy::all_narrow`.
- For `checked<T, EC>`, `NoValuePolicy` is set to `policy::throw_bad_result_access<EC>`.
  
These exactly matches the Default Actions described earlier.

This section describes
what a `NoValuePolicy` looks like, how to write your own, and each of the prewritten
policies supplied with Outcome.

