/* A very simple result type
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

#ifndef OUTCOME_STATUS_RESULT_HPP
#define OUTCOME_STATUS_RESULT_HPP

#include "../basic_result.hpp"

#include "status-code/include/system_error2.hpp"

OUTCOME_V2_NAMESPACE_EXPORT_BEGIN

namespace detail
{
  // Customise _set_error_is_errno
  template <class State> constexpr inline void _set_error_is_errno(State &state, const SYSTEM_ERROR2_NAMESPACE::generic_code & /*unused*/) { state._status |= status_error_is_errno; }
  template <class State> constexpr inline void _set_error_is_errno(State &state, const SYSTEM_ERROR2_NAMESPACE::posix_code & /*unused*/) { state._status |= status_error_is_errno; }
  template <class State> constexpr inline void _set_error_is_errno(State &state, const SYSTEM_ERROR2_NAMESPACE::errc & /*unused*/) { state._status |= status_error_is_errno; }

}  // namespace detail

//! Namespace for experimental features
namespace experimental
{
  //! Namespace for policies
  namespace policy
  {
    template <class T, class EC, class E> struct status_code_throw
    {
      static_assert(!std::is_same<T, T>::value, "policy::status_code_throw not specialised for these types, did you use status_result<T, status_code<DomainType>, E>?");
    };
    /*!
    */
    template <class T, class DomainType> struct status_code_throw<T, SYSTEM_ERROR2_NAMESPACE::status_code<DomainType>, void> : OUTCOME_V2_NAMESPACE::policy::detail::base
    {
      using _base = OUTCOME_V2_NAMESPACE::policy::detail::base;
      /*! Performs a wide check of state, used in the value() functions.
      \effects TODO
      */
      template <class Impl> static constexpr void wide_value_check(Impl &&self)
      {
        if((self._state._status & OUTCOME_V2_NAMESPACE::detail::status_have_value) == 0)
        {
          if((self._state._status & OUTCOME_V2_NAMESPACE::detail::status_have_error) != 0)
          {
            self._error.throw_exception();
          }
        }
      }
      /*! Performs a wide check of state, used in the error() functions
      \effects TODO
      */
      template <class Impl> static constexpr void wide_error_check(Impl &&self) { _base::narrow_error_check(static_cast<Impl &&>(self)); }
    };

    /*! Default policy selector.
    */
    template <class T, class EC>
    using default_status_result_policy = std::conditional_t<                //
    std::is_void<EC>::value,                                                //
    OUTCOME_V2_NAMESPACE::policy::terminate,                                //
    std::conditional_t<SYSTEM_ERROR2_NAMESPACE::is_status_code<EC>::value,  //
                       status_code_throw<T, EC, void>,                      //
                       OUTCOME_V2_NAMESPACE::policy::all_narrow             //
                       >>;
  }  // namespace policy

  /*! TODO
  */
  template <class R, class S = SYSTEM_ERROR2_NAMESPACE::system_code>  //
  using erased_result = basic_result<R, S, policy::default_status_result_policy<R, S>>;

  /*! TODO
  */
  template <class R, class DomainType>  //
  using status_result = basic_result<R, SYSTEM_ERROR2_NAMESPACE::status_code<DomainType>, policy::default_status_result_policy<R, SYSTEM_ERROR2_NAMESPACE::status_code<DomainType>>>;

}  // namespace experimental

OUTCOME_V2_NAMESPACE_END

#endif
