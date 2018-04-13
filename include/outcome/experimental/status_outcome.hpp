/* A less simple result type
(C) 2018 Niall Douglas <http://www.nedproductions.biz/> (59 commits)
File Created: Apr 2018


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

#ifndef OUTCOME_STATUS_OUTCOME_HPP
#define OUTCOME_STATUS_OUTCOME_HPP

#include "../basic_outcome.hpp"

#include "status_result.hpp"

OUTCOME_V2_NAMESPACE_EXPORT_BEGIN

//! Namespace for policies
namespace policy
{
  /*! Default policy selector.
  */
  template <class T, class EC, class E>
  using default_status_policy = std::conditional_t<                                                                                    //
  std::is_void<EC>::value && std::is_void<E>::value,                                                                                   //
  terminate,                                                                                                                           //
  std::conditional_t<SYSTEM_ERROR2_NAMESPACE::is_status_code<EC>::value && (std::is_void<E>::value || trait::has_exception_ptr_v<E>),  //
                     status_code_throw<T, EC, E>,                                                                                      //
                     all_narrow                                                                                                        //
                     >>;
}  // namespace policy

/*! TODO
*/
template <class R, class S = SYSTEM_ERROR2_NAMESPACE::error, class P = std::exception_ptr>  //
using status_outcome = basic_outcome<R, S, P, policy::default_status_policy<R, S, P>>;

//! Namespace for policies
namespace policy
{
  /*!
  */
  template <class T, class DomainType, class E> struct status_code_throw<T, SYSTEM_ERROR2_NAMESPACE::status_code<DomainType>, E> : detail::base
  {
    /*! Performs a wide check of state, used in the value() functions.
    \effects See description of class for effects.
    */
    template <class Impl> static constexpr void wide_value_check(Impl &&self)
    {
      if((self._state._status & OUTCOME_V2_NAMESPACE::detail::status_have_value) == 0)
      {
        if((self._state._status & OUTCOME_V2_NAMESPACE::detail::status_have_exception) != 0)
        {
          using Outcome = OUTCOME_V2_NAMESPACE::detail::rebind_type<basic_outcome<T, SYSTEM_ERROR2_NAMESPACE::status_code<DomainType>, E, status_code_throw>, decltype(self)>;
          Outcome _self = static_cast<Outcome>(self);  // NOLINT
          detail::_rethrow_exception<trait::has_exception_ptr_v<E>>{std::forward<Outcome>(_self)._ptr};
        }
        if((self._state._status & OUTCOME_V2_NAMESPACE::detail::status_have_error) != 0)
        {
          self.assume_error().throw_exception();
        }
      }
    }
    /*! Performs a wide check of state, used in the error() functions
    \effects TODO
    */
    template <class Impl> static constexpr void wide_error_check(Impl &&self) { detail::base::narrow_error_check(static_cast<Impl &&>(self)); }
    /*! Performs a wide check of state, used in the exception() functions
    \effects TODO
    */
    template <class Impl> static constexpr void wide_exception_check(Impl &&self) { detail::base::narrow_exception_check(static_cast<Impl &&>(self)); }
  };
}  // namespace policy

OUTCOME_V2_NAMESPACE_END

#endif
