/* Storage for a very simple result type
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

#ifndef OUTCOME_RESULT_STORAGE_HPP
#define OUTCOME_RESULT_STORAGE_HPP

#include "../success_failure.hpp"
#include "../trait.hpp"
#include "value_storage.hpp"

OUTCOME_V2_NAMESPACE_EXPORT_BEGIN

namespace detail
{
  template <class State, class E> constexpr inline void _set_error_is_errno(State & /*unused*/, const E & /*unused*/) {}
  template <class R, class S, class NoValuePolicy> class result_final;
}

//! Namespace containing hooks used for intercepting and manipulating result/outcome
namespace hooks
{
  //! Get the sixteen bits of spare storage in a `result` or `outcome`.
  template <class R, class S, class NoValuePolicy> constexpr inline uint16_t spare_storage(const detail::result_final<R, S, NoValuePolicy> *r) noexcept;
  //! Sets the sixteen bits of spare storage in a `result` or `outcome`.
  template <class R, class S, class NoValuePolicy> constexpr inline void set_spare_storage(detail::result_final<R, S, NoValuePolicy> *r, uint16_t v) noexcept;
}  // namespace hooks

namespace policy
{
  namespace detail
  {
    struct base;
  }  // namespace detail
}  // namespace policy

namespace detail
{
  //! The base implementation type of `result<R, EC, NoValuePolicy>`.
  template <class R, class EC, class NoValuePolicy>                                                                                                                        //
  OUTCOME_REQUIRES(trait::type_can_be_used_in_result<R> &&trait::type_can_be_used_in_result<EC> && (std::is_void<EC>::value || std::is_default_constructible<EC>::value))  //
  class result_storage
  {
    static_assert(trait::type_can_be_used_in_result<R>, "The type R cannot be used in a result");
    static_assert(trait::type_can_be_used_in_result<EC>, "The type S cannot be used in a result");
    static_assert(std::is_void<EC>::value || std::is_default_constructible<EC>::value, "The type S must be void or default constructible");

    friend NoValuePolicy;
    friend struct policy::detail::base;
    template <class T, class U, class V> friend class result_storage;
    template <class T, class U, class V> friend class result_final;
    template <class T, class U, class V> friend constexpr inline uint16_t hooks::spare_storage(const detail::result_final<T, U, V> *r) noexcept;        // NOLINT
    template <class T, class U, class V> friend constexpr inline void hooks::set_spare_storage(detail::result_final<T, U, V> *r, uint16_t v) noexcept;  // NOLINT

    struct disable_in_place_value_type
    {
    };
    struct disable_in_place_error_type
    {
    };

  protected:
    using _value_type = std::conditional_t<std::is_same<R, EC>::value, disable_in_place_value_type, R>;
    using _error_type = std::conditional_t<std::is_same<R, EC>::value, disable_in_place_error_type, EC>;

#ifdef STANDARDESE_IS_IN_THE_HOUSE
    detail::value_storage_trivial<_value_type> _state;
#else
    detail::value_storage_select_impl<_value_type> _state;
#endif
    detail::devoid<_error_type> _error;

  public:
    // Used by iostream support to access state
    detail::value_storage_select_impl<_value_type> &__state() { return _state; }
    const detail::value_storage_select_impl<_value_type> &__state() const { return _state; }

  protected:
    result_storage() = default;
    result_storage(const result_storage &) = default;             // NOLINT
    result_storage(result_storage &&) = default;                  // NOLINT
    result_storage &operator=(const result_storage &) = default;  // NOLINT
    result_storage &operator=(result_storage &&) = default;       // NOLINT
    ~result_storage() = default;

    template <class... Args>
    constexpr explicit result_storage(in_place_type_t<_value_type> _, Args &&... args) noexcept(std::is_nothrow_constructible<_value_type, Args...>::value)
        : _state{_, static_cast<Args &&>(args)...}
        , _error()
    {
    }
    template <class U, class... Args>
    constexpr result_storage(in_place_type_t<_value_type> _, std::initializer_list<U> il, Args &&... args) noexcept(std::is_nothrow_constructible<_value_type, std::initializer_list<U>, Args...>::value)
        : _state{_, il, static_cast<Args &&>(args)...}
        , _error()
    {
    }
    template <class... Args>
    constexpr explicit result_storage(in_place_type_t<_error_type> /*unused*/, Args &&... args) noexcept(std::is_nothrow_constructible<_error_type, Args...>::value)
        : _state{detail::status_have_error}
        , _error(static_cast<Args &&>(args)...)
    {
      detail::_set_error_is_errno(_state, _error);
    }
    template <class U, class... Args>
    constexpr result_storage(in_place_type_t<_error_type> /*unused*/, std::initializer_list<U> il, Args &&... args) noexcept(std::is_nothrow_constructible<_error_type, std::initializer_list<U>, Args...>::value)
        : _state{detail::status_have_error}
        , _error{il, static_cast<Args &&>(args)...}
    {
      detail::_set_error_is_errno(_state, _error);
    }
    struct compatible_conversion_tag
    {
    };
    template <class T, class U, class V>
    constexpr result_storage(compatible_conversion_tag /*unused*/, const result_storage<T, U, V> &o) noexcept(std::is_nothrow_constructible<_value_type, T>::value &&std::is_nothrow_constructible<_error_type, U>::value)
        : _state(o._state)
        , _error(o._error)
    {
    }
    template <class T, class V>
    constexpr result_storage(compatible_conversion_tag /*unused*/, const result_storage<T, void, V> &o) noexcept(std::is_nothrow_constructible<_value_type, T>::value)
        : _state(o._state)
        , _error(_error_type{})
    {
    }
    template <class T, class U, class V>
    constexpr result_storage(compatible_conversion_tag /*unused*/, result_storage<T, U, V> &&o) noexcept(std::is_nothrow_constructible<_value_type, T>::value &&std::is_nothrow_constructible<_error_type, U>::value)
        : _state(static_cast<decltype(o._state) &&>(o._state))
        , _error(static_cast<U &&>(o._error))
    {
    }
    template <class T, class V>
    constexpr result_storage(compatible_conversion_tag /*unused*/, result_storage<T, void, V> &&o) noexcept(std::is_nothrow_constructible<_value_type, T>::value)
        : _state(static_cast<decltype(o._state) &&>(o._state))
        , _error(_error_type{})
    {
    }
  };
}  // namespace detail
OUTCOME_V2_NAMESPACE_END

#endif
