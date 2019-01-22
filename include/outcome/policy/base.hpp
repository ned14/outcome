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

#ifndef OUTCOME_POLICY_BASE_HPP
#define OUTCOME_POLICY_BASE_HPP

#include "../config.hpp"

#include <cassert>

OUTCOME_V2_NAMESPACE_EXPORT_BEGIN

namespace policy
{
  struct base
  {
  protected:
    //! Invokes noticeable UB!
    template <class Impl>
    static constexpr
#ifdef _MSC_VER
    __declspec(noreturn)
#elif defined(__GNUC__) || defined(__clang__)
        __attribute__((noreturn))
#endif
    void _ub(Impl && /*unused*/)
    {
      assert(false);
#if defined(__GNUC__) || defined(__clang__)
      __builtin_unreachable();
#endif
    }

    //! True if the current state's status has its value bit set.
    template <class Impl> static constexpr bool _has_value(Impl &&self) noexcept { return (self._state._status & OUTCOME_V2_NAMESPACE::detail::status_have_value) != 0; }
    //! True if the current state's status has its error bit set.
    template <class Impl> static constexpr bool _has_error(Impl &&self) noexcept { return (self._state._status & OUTCOME_V2_NAMESPACE::detail::status_have_error) != 0; }
    //! True if the current state's status has its exception bit set.
    template <class Impl> static constexpr bool _has_exception(Impl &&self) noexcept { return (self._state._status & OUTCOME_V2_NAMESPACE::detail::status_have_exception) != 0; }
    //! True if the current state's status has its error-is-errno bit set.
    template <class Impl> static constexpr bool _has_error_is_errno(Impl &&self) noexcept { return (self._state._status & OUTCOME_V2_NAMESPACE::detail::status_error_is_errno) != 0; }

    //! Changes the current state's status value bit.
    template <class Impl> static constexpr void _set_has_value(Impl &&self, bool v) noexcept { v ? self._state._status |= OUTCOME_V2_NAMESPACE::detail::status_have_value : self._state._status &= ~OUTCOME_V2_NAMESPACE::detail::status_have_value; }
    //! Changes the current state's status error bit.
    template <class Impl> static constexpr void _set_has_error(Impl &&self, bool v) noexcept { v ? self._state._status |= OUTCOME_V2_NAMESPACE::detail::status_have_error : self._state._status &= ~OUTCOME_V2_NAMESPACE::detail::status_have_error; }
    //! Changes the current state's status exception bit.
    template <class Impl> static constexpr void _set_has_exception(Impl &&self, bool v) noexcept { v ? self._state._status |= OUTCOME_V2_NAMESPACE::detail::status_have_exception : self._state._status &= ~OUTCOME_V2_NAMESPACE::detail::status_have_exception; }
    //! Changes the current state's status error-is-errno bit.
    template <class Impl> static constexpr void _set_has_error_is_errno(Impl &&self, bool v) noexcept { v ? self._state._status |= OUTCOME_V2_NAMESPACE::detail::status_error_is_errno : self._state._status &= ~OUTCOME_V2_NAMESPACE::detail::status_error_is_errno; }

    //! Accesses the current state's value. No checking of validity is made.
    template <class Impl> static constexpr auto &&_value(Impl &&self) noexcept { return static_cast<Impl &&>(self)._state._value; }
    //! Accesses the current state's error. No checking of validity is made.
    template <class Impl> static constexpr auto &&_error(Impl &&self) noexcept { return static_cast<Impl &&>(self)._error; }

  public:
    //! Accesses the current state's exception. No checking of validity is made.
    template <class R, class S, class P, class NoValuePolicy, class Impl> static inline constexpr auto &&_exception(Impl &&self) noexcept;

    /*! Performs a narrow check of state, used in the assume_value() functions.
    \effects None.
    */
    template <class Impl> static constexpr void narrow_value_check(Impl &&self) noexcept
    {
      if(!_has_value(self))
      {
        _ub(self);
      }
    }
    /*! Performs a narrow check of state, used in the assume_error() functions
    \effects None.
    */
    template <class Impl> static constexpr void narrow_error_check(Impl &&self) noexcept
    {
      if(!_has_error(self))
      {
        _ub(self);
      }
    }
    /*! Performs a narrow check of state, used in the assume_exception() functions
    \effects None.
    */
    template <class Impl> static constexpr void narrow_exception_check(Impl &&self) noexcept
    {
      if(!_has_exception(self))
      {
        _ub(self);
      }
    }
  };
}  // namespace policy

OUTCOME_V2_NAMESPACE_END

#endif
