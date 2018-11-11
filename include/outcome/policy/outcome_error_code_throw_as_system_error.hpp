/* Policies for result and outcome
(C) 2017 Niall Douglas <http://www.nedproductions.biz/> (59 commits)
File Created: Oct 2017


Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License in the accompanying file
Licence.txt or at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.


Distributed under the Boost Software License, Version 1.0.
(See accompanying file Licence.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#ifndef OUTCOME_POLICY_OUTCOME_ERROR_CODE_THROW_AS_SYSTEM_ERROR_HPP
#define OUTCOME_POLICY_OUTCOME_ERROR_CODE_THROW_AS_SYSTEM_ERROR_HPP

#include "result_error_code_throw_as_system_error.hpp"

OUTCOME_V2_NAMESPACE_EXPORT_BEGIN

namespace policy
{
  /*! Policy interpreting `EC` as a type for which `trait::has_error_code_v<EC>` is true.
  Any wide attempt to access the successful state where there is none causes
  an attempt to rethrow `E` if `trait::has_exception_ptr_v<E>` is true, else:

  1. If `trait::has_error_payload_v<EC>` is true, it calls an
  ADL discovered free function `outcome_throw_as_system_error_with_payload(.error())`.
  2. If `trait::has_error_payload_v<EC>` is false, it calls `OUTCOME_THROW_EXCEPTION(std::system_error(policy::error_code(.error())))`
  */
  template <class T, class EC, class E> struct error_code_throw_as_system_error : base
  {
    /*! Performs a wide check of state, used in the value() functions.
    \effects See description of class for effects.
    */
    template <class Impl> static constexpr void wide_value_check(Impl &&self)
    {
      if(!base::_has_value(std::forward<Impl>(self)))
      {
        if(base::_has_exception(std::forward<Impl>(self)))
        {
          using Outcome = OUTCOME_V2_NAMESPACE::detail::rebind_type<basic_outcome<T, EC, E, error_code_throw_as_system_error>, decltype(self)>;
          Outcome _self = static_cast<Outcome>(self);  // NOLINT
          detail::_rethrow_exception<trait::has_exception_ptr_v<E>>{std::forward<Outcome>(_self)._ptr};
        }
        if(base::_has_error(std::forward<Impl>(self)))
        {
          // ADL discovered
          outcome_throw_as_system_error_with_payload(base::_error(std::forward<Impl>(self)));
        }
        OUTCOME_THROW_EXCEPTION(bad_outcome_access("no value"));
      }
    }
    /*! Performs a wide check of state, used in the error() functions
    \effects If result does not have an error, it throws `bad_outcome_access`.
    */
    template <class Impl> static constexpr void wide_error_check(Impl &&self)
    {
      if(!base::_has_error(std::forward<Impl>(self)))
      {
        OUTCOME_THROW_EXCEPTION(bad_outcome_access("no error"));
      }
    }
    /*! Performs a wide check of state, used in the exception() functions
    \effects If result does not have an exception, it throws `bad_outcome_access`.
    */
    template <class Impl> static constexpr void wide_exception_check(Impl &&self)
    {
      if(!base::_has_exception(std::forward<Impl>(self)))
      {
        OUTCOME_THROW_EXCEPTION(bad_outcome_access("no exception"));
      }
    }
  };
}  // namespace policy

OUTCOME_V2_NAMESPACE_END

#endif
