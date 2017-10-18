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

#ifndef OUTCOME_POLICY_DETAIL_COMMON_HPP
#define OUTCOME_POLICY_DETAIL_COMMON_HPP

#include "../../config.hpp"

OUTCOME_V2_NAMESPACE_EXPORT_BEGIN

namespace policy
{
  namespace detail
  {
    struct base
    {
    private:
      static void _ub()
      {
#if defined(__GNUC__) || defined(__clang__)
        __builtin_unreachable();
#endif
      }

    public:
      /*! Performs a narrow check of state, used in the assume_value() functions.
      \effects None.
      */
      template <class Impl> static constexpr void narrow_value_check(Impl *self) noexcept
      {
        if((self->_state._status & OUTCOME_V2_NAMESPACE::detail::status_have_value) == 0)
        {
          _ub();
        }
      }
      /*! Performs a narrow check of state, used in the assume_error() functions
      \effects None.
      */
      template <class Impl> static constexpr void narrow_error_check(Impl *self) noexcept
      {
        if((self->_state._status & OUTCOME_V2_NAMESPACE::detail::status_have_error) == 0)
        {
          _ub();
        }
      }
      /*! Performs a narrow check of state, used in the assume_payload() functions
      \effects None.
      */
      template <class Impl> static constexpr void narrow_payload_check(Impl *self) noexcept
      {
        if((self->_state._status & OUTCOME_V2_NAMESPACE::detail::status_have_payload) == 0)
        {
          _ub();
        }
      }
      /*! Performs a narrow check of state, used in the assume_exception() functions
      \effects None.
      */
      template <class Impl> static constexpr void narrow_exception_check(Impl *self) noexcept
      {
        if((self->_state._status & OUTCOME_V2_NAMESPACE::detail::status_have_exception) == 0)
        {
          _ub();
        }
      }
    };
  }  // namespace detail
}  // namespace policy

OUTCOME_V2_NAMESPACE_END

#endif
