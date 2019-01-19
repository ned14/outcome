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

#ifndef OUTCOME_BASIC_RESULT_FINAL_HPP
#define OUTCOME_BASIC_RESULT_FINAL_HPP

#include "basic_result_error_observers.hpp"
#include "basic_result_value_observers.hpp"

OUTCOME_V2_NAMESPACE_EXPORT_BEGIN

namespace detail
{
  template <class R, class EC, class NoValuePolicy> using select_basic_result_impl = basic_result_error_observers<basic_result_value_observers<basic_result_storage<R, EC, NoValuePolicy>, R, NoValuePolicy>, EC, NoValuePolicy>;

  //! The assembled implementation type of `basic_result<R, S, NoValuePolicy>`.
  template <class R, class S, class NoValuePolicy>
  class basic_result_final
#if defined(DOXYGEN_IS_IN_THE_HOUSE)
  : public basic_result_error_observers<basic_result_value_observers<basic_result_storage<R, S, NoValuePolicy>, R, NoValuePolicy>, S, NoValuePolicy>
#else
  : public select_basic_result_impl<R, S, NoValuePolicy>
#endif
  {
    using base = select_basic_result_impl<R, S, NoValuePolicy>;

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
    constexpr bool has_failure() const noexcept { return (this->_state._status & detail::status_have_error) != 0 || (this->_state._status & detail::status_have_exception) != 0; }

    /// \output_section Comparison operators
    /*! True if equal to the other basic_result.
    \param o The other basic_result to compare to.

    \requires That both `value_type`'s have an `operator==` available;
    that both `error_type`'s have an `operator==` available.
    \effects Calls the `operator==` operation on any common stored state.
    Otherwise returns false. Ignores spare storage.
    \throws Any exception the individual `operator==` operations might throw.
    */
    OUTCOME_TEMPLATE(class T, class U, class V)
    OUTCOME_TREQUIRES(OUTCOME_TEXPR(std::declval<detail::devoid<R>>() == std::declval<detail::devoid<T>>()),  //
                      OUTCOME_TEXPR(std::declval<detail::devoid<S>>() == std::declval<detail::devoid<U>>()))
    constexpr bool operator==(const basic_result_final<T, U, V> &o) const noexcept(  //
    noexcept(std::declval<detail::devoid<R>>() == std::declval<detail::devoid<T>>()) && noexcept(std::declval<detail::devoid<S>>() == std::declval<detail::devoid<U>>()))
    {
      if((this->_state._status & detail::status_have_value) != 0 && (o._state._status & detail::status_have_value) != 0)
      {
        return this->_state._value == o._state._value;
      }
      if((this->_state._status & detail::status_have_error) != 0 && (o._state._status & detail::status_have_error) != 0)
      {
        return this->_error == o._error;
      }
      return false;
    }
    /*! True if equal to the success type sugar.
    \param o The success type sugar to compare to.

    \requires That both `value_type`'s have an `operator==` available.
    \effects Calls the `operator==` operation on any common stored state.
    Otherwise returns false. Ignores spare storage.
    \throws Any exception the individual `operator==` operations might throw.
    */
    OUTCOME_TEMPLATE(class T)
    OUTCOME_TREQUIRES(OUTCOME_TEXPR(std::declval<R>() == std::declval<T>()))
    constexpr bool operator==(const success_type<T> &o) const noexcept(  //
    noexcept(std::declval<R>() == std::declval<T>()))
    {
      if((this->_state._status & detail::status_have_value) != 0)
      {
        return this->_state._value == o.value();
      }
      return false;
    }
    /*! True if equal to the success type sugar.
    \param o The success type sugar to compare to.

    \effects True if the result is valued.
    */
    constexpr bool operator==(const success_type<void> &o) const noexcept
    {
      (void) o;
      return (this->_state._status & detail::status_have_value) != 0;
    }
    /*! True if equal to the failure type sugar.
    \param o The failure type sugar to compare to.

    \requires That both `error_type`'s have an `operator==` available.
    \effects Calls the `operator==` operation on any common stored state.
    Otherwise returns false. Ignores spare storage.
    \throws Any exception the individual `operator==` operations might throw.
    */
    OUTCOME_TEMPLATE(class T)
    OUTCOME_TREQUIRES(OUTCOME_TEXPR(std::declval<S>() == std::declval<T>()))
    constexpr bool operator==(const failure_type<T, void> &o) const noexcept(  //
    noexcept(std::declval<S>() == std::declval<T>()))
    {
      if((this->_state._status & detail::status_have_error) != 0)
      {
        return this->_error == o.error();
      }
      return false;
    }
    /*! True if not equal to the other basic_result.
    \param o The other basic_result to compare to.

    \requires That both `value_type`'s have an `operator!=` available;
    that both `error_type`'s have an `operator!=` available.
    \effects Calls the `operator!=` operation on any common stored state.
    Otherwise returns true. Ignores spare storage.
    \throws Any exception the individual `operator!=` operations might throw.
    */
    OUTCOME_TEMPLATE(class T, class U, class V)
    OUTCOME_TREQUIRES(OUTCOME_TEXPR(std::declval<detail::devoid<R>>() != std::declval<detail::devoid<T>>()),  //
                      OUTCOME_TEXPR(std::declval<detail::devoid<S>>() != std::declval<detail::devoid<U>>()))
    constexpr bool operator!=(const basic_result_final<T, U, V> &o) const noexcept(  //
    noexcept(std::declval<detail::devoid<R>>() != std::declval<detail::devoid<T>>()) && noexcept(std::declval<detail::devoid<S>>() != std::declval<detail::devoid<U>>()))
    {
      if((this->_state._status & detail::status_have_value) != 0 && (o._state._status & detail::status_have_value) != 0)
      {
        return this->_state._value != o._state._value;
      }
      if((this->_state._status & detail::status_have_error) != 0 && (o._state._status & detail::status_have_error) != 0)
      {
        return this->_error != o._error;
      }
      return true;
    }
    /*! True if not equal to the success type sugar.
    \param o The success type sugar to compare to.

    \requires That both `value_type`'s have an `operator!=` available.
    \effects Calls the `operator!=` operation on any common stored state.
    Otherwise returns true. Ignores spare storage.
    \throws Any exception the individual `operator!=` operations might throw.
    */
    OUTCOME_TEMPLATE(class T)
    OUTCOME_TREQUIRES(OUTCOME_TEXPR(std::declval<R>() != std::declval<T>()))
    constexpr bool operator!=(const success_type<T> &o) const noexcept(  //
    noexcept(std::declval<R>() != std::declval<T>()))
    {
      if((this->_state._status & detail::status_have_value) != 0)
      {
        return this->_state._value != o.value();
      }
      return false;
    }
    /*! True if not equal to the success type sugar.
    \param o The success type sugar to compare to.

    \effects False if the result is valued.
    */
    constexpr bool operator!=(const success_type<void> &o) const noexcept
    {
      (void) o;
      return (this->_state._status & detail::status_have_value) == 0;
    }
    /*! True if not equal to the failure type sugar.
    \param o The failure type sugar to compare to.

    \requires That both `error_type`'s have an `operator!=` available.
    \effects Calls the `operator!=` operation on any common stored state.
    Otherwise returns true. Ignores spare storage.
    \throws Any exception the individual `operator!=` operations might throw.
    */
    OUTCOME_TEMPLATE(class T)
    OUTCOME_TREQUIRES(OUTCOME_TEXPR(std::declval<S>() != std::declval<T>()))
    constexpr bool operator!=(const failure_type<T, void> &o) const noexcept(  //
    noexcept(std::declval<S>() != std::declval<T>()))
    {
      if((this->_state._status & detail::status_have_error) != 0)
      {
        return this->_error != o.error();
      }
      return true;
    }
  };
  /*! True if the basic_result is equal to the success type sugar.
  \param a The success type sugar to compare.
  \param b The basic_result to compare.

  \effects If a valid expression to do so, calls the `operator==` operation on the successful item returning true if equal. Otherwise returns false.
  \remarks Implemented as `b == a`.
  \throws Any exception the `operator==` operation might throw.
  */
  template <class T, class U, class V, class W> constexpr inline bool operator==(const success_type<W> &a, const basic_result_final<T, U, V> &b) noexcept(noexcept(b == a)) { return b == a; }
  /*! True if the basic_result is equal to the failure type sugar.
  \param a The failure type sugar to compare.
  \param b The basic_result to compare.

  \effects If a valid expression to do so, calls the `operator==` operation on the failure item returning true if equal. Otherwise returns false.
  \remarks Implemented as `b == a`.
  \throws Any exception the `operator==` operation might throw.
  */
  template <class T, class U, class V, class W> constexpr inline bool operator==(const failure_type<W, void> &a, const basic_result_final<T, U, V> &b) noexcept(noexcept(b == a)) { return b == a; }
  /*! True if the basic_result is not equal to the success type sugar.
  \param a The success type sugar to compare.
  \param b The basic_result to compare.

  \effects If a valid expression to do so, calls the `operator!=` operation on the successful item returning true if not equal. Otherwise returns false.
  \remarks Implemented as `b != a`.
  \throws Any exception the `operator!=` operation might throw.
  */
  template <class T, class U, class V, class W> constexpr inline bool operator!=(const success_type<W> &a, const basic_result_final<T, U, V> &b) noexcept(noexcept(b == a)) { return b != a; }
  /*! True if the basic_result is not equal to the failure type sugar.
  \param a The failure type sugar to compare.
  \param b The basic_result to compare.

  \effects If a valid expression to do so, calls the `operator!=` operation on the failure item returning true if not equal. Otherwise returns false.
  \remarks Implemented as `b != a`.
  \throws Any exception the `operator!=` operation might throw.
  */
  template <class T, class U, class V, class W> constexpr inline bool operator!=(const failure_type<W, void> &a, const basic_result_final<T, U, V> &b) noexcept(noexcept(b == a)) { return b != a; }
}  // namespace detail

OUTCOME_V2_NAMESPACE_END

#endif
