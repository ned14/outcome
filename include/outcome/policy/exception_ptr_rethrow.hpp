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

#ifndef OUTCOME_POLICY_EXCEPTION_PTR_RETHROW_HPP
#define OUTCOME_POLICY_EXCEPTION_PTR_RETHROW_HPP

#include "../bad_access.hpp"

OUTCOME_V2_NAMESPACE_EXPORT_BEGIN

namespace policy
{
#ifdef __cpp_exceptions
  /*! Policy interpreting EC as a type implementing the `std::exception_ptr` contract
  and any wide attempt to access the successful state calls `std::rethrow_exception()`.
  \module Error code interpretation policy
  */
  template <class EC> struct exception_ptr_rethrow
  {
    static_assert(std::is_base_of<std::exception_ptr, EC>::value, "error_type must be a base of a std::exception_ptr to be used with this policy");
    /*! Performs a narrow check of state, used in the assume_value() functions.
    \effects None.
    */
    template <class Impl> static constexpr void narrow_value_check(Impl *self) noexcept
    {
      (void) self;
#if defined(__GNUC__) || defined(__clang__)
      if((self->_state._status & detail::status_have_value) == 0)
        __builtin_unreachable();
#endif
    }
    /*! Performs a narrow check of state, used in the assume_error() functions
    \effects None.
    */
    template <class Impl> static constexpr void narrow_error_check(Impl *self) noexcept
    {
      (void) self;
#if defined(__GNUC__) || defined(__clang__)
      if((self->_state._status & detail::status_have_error) == 0)
        __builtin_unreachable();
#endif
    }
    /*! Performs a wide check of state, used in the value() functions
    \effects If result does not have a value, if it has an error it rethrows that error via `std::rethrow_exception()`, else it throws `bad_result_access`.
    */
    template <class Impl> static constexpr void wide_value_check(Impl *self)
    {
      if((self->_state._status & detail::status_have_value) == 0)
      {
        if((self->_state._status & detail::status_have_error) != 0)
        {
          std::rethrow_exception(self->_error);
        }
        OUTCOME_THROW_EXCEPTION(bad_result_access("no value"));
      }
    }
    /*! Performs a wide check of state, used in the value() functions
    \effects If result does not have a value, if it has an error it throws that error, else it throws `bad_result_access`.
    */
    template <class Impl> static constexpr void wide_error_check(Impl *self)
    {
      if((self->_state._status & detail::status_have_error) == 0)
      {
        OUTCOME_THROW_EXCEPTION(bad_result_access("no error"));
      }
    }
  };
#endif
}

OUTCOME_V2_NAMESPACE_END

#endif
