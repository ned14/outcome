+++
title = "Policies"
description = "Defining your own NoValuePolicy policies, plus an overview of the precanned policies which come in the Outcome source code."
weight = 60
tags = [ "policies" ]
+++

Earlier in the section on [Default actions](../default-actions), we covered all the different
actions which Outcome can take upon no-value observation, and we noted that this facility
is fully programmable.

`result<T, EC>` is actually `result<T, EC, NoValuePolicy>`. `outcome<T, EC, EP>` is in
fact `outcome<T, EC, EP, NoValuePolicy>`. The `NoValuePolicy` template type is defaulted
to a template alias as follows:

 ```c++
namespace policy {
  template <class T, class EC, class E>
  using default_policy = std::conditional_t<
    std::is_void<EC>::value && std::is_void<E>::value,
    terminate,
    std::conditional_t<
      trait::has_error_code_v<EC>,
      error_code_throw_as_system_error<T, EC, E>,
      std::conditional_t<
        trait::has_exception_ptr_v<EC> || trait::has_exception_ptr_v<E>,
        exception_ptr_rethrow<T, EC, E>,
        all_narrow
  >>>;
}
  ```  
- For `unchecked<T, EC>`, `NoValuePolicy` is hard coded to {{< api "policies/all_narrow" "policy::all_narrow" >}}.
- For `checked<T, EC>`, `NoValuePolicy` is hard coded to {{< api "policies/throw_bad_result_access" "policy::throw_bad_result_access<EC>" >}}.
  
These exactly match the Default Actions described earlier.

This section describes
what a `NoValuePolicy` looks like, how to write your own, and each of the prewritten
policies supplied with Outcome.

