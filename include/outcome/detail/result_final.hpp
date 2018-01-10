/* Finaliser for a very simple result type
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

#ifndef OUTCOME_RESULT_FINAL_HPP
#define OUTCOME_RESULT_FINAL_HPP

#include "result_error_observers.hpp"
#include "result_value_observers.hpp"

OUTCOME_V2_NAMESPACE_EXPORT_BEGIN

namespace detail
{
  template <class R, class EC, class NoValuePolicy> using select_result_impl = result_error_observers<result_value_observers<result_storage<R, EC, NoValuePolicy>, R, NoValuePolicy>, EC, NoValuePolicy>;

  //! The assembled implementation type of `result<R, S, NoValuePolicy>`.
  template <class R, class S, class NoValuePolicy>
  class result_final
#if defined(DOXYGEN_IS_IN_THE_HOUSE)
  : public result_error_observers<result_value_observers<result_storage<R, S, NoValuePolicy>, R, NoValuePolicy>, S, NoValuePolicy>
#else
  : public select_result_impl<R, S, NoValuePolicy>
#endif
  {
    using base = select_result_impl<R, S, NoValuePolicy>;

  public:
    using base::base;

    /// \output_section State check observers
    /*! Checks if has value.
    \returns True if has value.
    */
    constexpr explicit operator bool() const noexcept { return (this->_state._status & detail::status_have_value) != 0; }
    /*! Checks if has value.
    \returns True if has value.
    */
    constexpr bool has_value() const noexcept { return (this->_state._status & detail::status_have_value) != 0; }
    /*! Checks if has error.
    \returns True if has error.
    */
    constexpr bool has_error() const noexcept { return (this->_state._status & detail::status_have_error) != 0; }
    /*! Checks if has exception.
    \returns True if has exception.
    */
    constexpr bool has_exception() const noexcept { return (this->_state._status & detail::status_have_exception) != 0; }
    /*! Checks if has error or exception.
    \returns True if has error or exception.
    */
    constexpr bool has_failure() const noexcept { return (this->_state._status & detail::status_have_error) != 0 && (this->_state._status & detail::status_have_exception) != 0; }

    /// \output_section Comparison operators
    /*! True if equal to the other result.
    \param o The other result to compare to.

    \effects If a valid expression to do so, calls the `operator==` operation on each
    of the two stored items returning true if both are true. Otherwise returns false.
    \throws Any exception the individual `operator==` operations might throw.
    */
    template <class T, class U, class V>
    constexpr bool operator==(const result_final<T, U, V> &o) const noexcept(                                   //
    noexcept(detail::safe_compare_equal(std::declval<detail::devoid<R>>(), std::declval<detail::devoid<T>>()))  //
    && noexcept(detail::safe_compare_equal(std::declval<detail::devoid<S>>(), std::declval<detail::devoid<U>>())))
    {
      if(this->_state._status == o._state._status)
      {
        if(this->_state._status & detail::status_have_value)
        {
          return detail::safe_compare_equal(this->_state._value, o._state._value) && detail::safe_compare_equal(this->_error, o._error);  // NOLINT
        }
        return detail::safe_compare_equal(this->_error, o._error);
      }
      return false;
    }
    /*! True if equal to the success type sugar.
    \param o The success type sugar to compare to.

    \effects If a valid expression to do so, calls the `operator==` operation on the successful item returning true if equal. Otherwise returns false.
    \throws Any exception the `operator==` operation might throw.
    */
    template <class T> constexpr bool operator==(const success_type<T> &o) const noexcept(noexcept(detail::safe_compare_equal(std::declval<detail::devoid<R>>(), std::declval<detail::devoid<T>>())))
    {
      if(this->_state._status & detail::status_have_value)
      {
        return detail::safe_compare_equal(this->_state._value, o._value);  // NOLINT
      }
      return false;
    }
    /*! True if equal to the success type sugar.
    \param o The success type sugar to compare to.

    \effects If a valid expression to do so, calls the `operator==` operation on the successful item returning true if equal. Otherwise returns false.
    \throws Any exception the `operator==` operation might throw.
    */
    constexpr bool operator==(const success_type<void> &o) const noexcept
    {
      (void) o;
      return static_cast<bool>(this->_state._status & detail::status_have_value);
    }
    /*! True if equal to the failure type sugar.
    \param o The failure type sugar to compare to.

    \effects If a valid expression to do so, calls the `operator==` operation on the failure item returning true if equal. Otherwise returns false.
    \throws Any exception the `operator==` operation might throw.
    */
    template <class T> constexpr bool operator==(const failure_type<T, void> &o) const noexcept(noexcept(detail::safe_compare_equal(std::declval<detail::devoid<S>>(), std::declval<detail::devoid<T>>()))) { return detail::safe_compare_equal(this->_error, o._error); }
    /*! True if not equal to the other result.
    \param o The other result to compare to.

    \effects If a valid expression to do so, calls the `operator!=` operation on each
    of the two stored items, returning true if any are not equal. Otherwise returns true.
    \throws Any exception the individual `operator!=` operations might throw.
    */
    template <class T, class U, class V>
    constexpr bool operator!=(const result_final<T, U, V> &o) const noexcept(                                      //
    noexcept(detail::safe_compare_notequal(std::declval<detail::devoid<R>>(), std::declval<detail::devoid<T>>()))  //
    && noexcept(detail::safe_compare_notequal(std::declval<detail::devoid<S>>(), std::declval<detail::devoid<U>>())))
    {
      if(this->_state._status != o._state._status)
      {
        return true;
      }
      if(this->_state._status & detail::status_have_value)
      {
        if(detail::safe_compare_notequal(this->_state._value, o._state._value))  // NOLINT
        {
          return true;
        }
      }
      return detail::safe_compare_notequal(this->_error, o._error);
    }
    /*! True if not equal to the success type sugar.
    \param o The success type sugar to compare to.

    \effects If a valid expression to do so, calls the `operator!=` operation on the successful item returning true if not equal. Otherwise returns false.
    \throws Any exception the `operator!=` operation might throw.
    */
    template <class T> constexpr bool operator!=(const success_type<T> &o) const noexcept(noexcept(detail::safe_compare_notequal(std::declval<detail::devoid<R>>(), std::declval<detail::devoid<T>>())))
    {
      if(this->_state._status & detail::status_have_value)
      {
        return detail::safe_compare_notequal(this->_state._value, o._value);  // NOLINT
      }
      return true;
    }
    /*! True if not equal to the success type sugar.
    \param o The success type sugar to compare to.

    \effects If a valid expression to do so, calls the `operator!=` operation on the successful item returning true if not equal. Otherwise returns false.
    \throws Any exception the `operator!=` operation might throw.
    */
    constexpr bool operator!=(const success_type<void> &o) const noexcept
    {
      (void) o;
      return !static_cast<bool>(this->_state._status & detail::status_have_value);
    }
    /*! True if not equal to the failure type sugar.
    \param o The failure type sugar to compare to.

    \effects If a valid expression to do so, calls the `operator!=` operation on the failure item returning true if not equal. Otherwise returns false.
    \throws Any exception the `operator!=` operation might throw.
    */
    template <class T> constexpr bool operator!=(const failure_type<T, void> &o) const noexcept(noexcept(detail::safe_compare_notequal(std::declval<detail::devoid<S>>(), std::declval<detail::devoid<T>>()))) { return detail::safe_compare_notequal(this->error(), o.error()); }
  };
  //! Calls b == a
  template <class T, class U, class V, class W> constexpr inline bool operator==(const success_type<W> &a, const result_final<T, U, V> &b) noexcept(noexcept(b == a)) { return b == a; }
  //! Calls b == a
  template <class T, class U, class V, class W> constexpr inline bool operator==(const failure_type<W, void> &a, const result_final<T, U, V> &b) noexcept(noexcept(b == a)) { return b == a; }
  //! Calls b != a
  template <class T, class U, class V, class W> constexpr inline bool operator!=(const success_type<W> &a, const result_final<T, U, V> &b) noexcept(noexcept(b == a)) { return b != a; }
  //! Calls b != a
  template <class T, class U, class V, class W> constexpr inline bool operator!=(const failure_type<W, void> &a, const result_final<T, U, V> &b) noexcept(noexcept(b == a)) { return b != a; }
}  // namespace detail

OUTCOME_V2_NAMESPACE_END

#endif
