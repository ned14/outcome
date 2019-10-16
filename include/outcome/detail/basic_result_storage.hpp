/* Storage for a very simple basic_result type
(C) 2017-2019 Niall Douglas <http://www.nedproductions.biz/> (6 commits)
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

#ifndef OUTCOME_BASIC_RESULT_STORAGE_HPP
#define OUTCOME_BASIC_RESULT_STORAGE_HPP

#include "../success_failure.hpp"
#include "../trait.hpp"
#include "value_storage.hpp"

OUTCOME_V2_NAMESPACE_EXPORT_BEGIN

namespace detail
{
  template <class State, class E> constexpr inline void _set_error_is_errno(State & /*unused*/, const E & /*unused*/) {}
  template <class R, class S, class NoValuePolicy> class basic_result_final;
}  // namespace detail

namespace hooks
{
  template <class R, class S, class NoValuePolicy> constexpr inline uint16_t spare_storage(const detail::basic_result_final<R, S, NoValuePolicy> *r) noexcept;
  template <class R, class S, class NoValuePolicy> constexpr inline void set_spare_storage(detail::basic_result_final<R, S, NoValuePolicy> *r, uint16_t v) noexcept;
}  // namespace hooks

namespace policy
{
  struct base;
}  // namespace policy

namespace detail
{
  template <class R, class EC, class NoValuePolicy>                                                                                                                                    //
  OUTCOME_REQUIRES(trait::type_can_be_used_in_basic_result<R> &&trait::type_can_be_used_in_basic_result<EC> && (std::is_void<EC>::value || std::is_default_constructible<EC>::value))  //
  class basic_result_storage;
  template <class R, class EC, class NoValuePolicy>                                                                                                                                    //
  OUTCOME_REQUIRES(trait::type_can_be_used_in_basic_result<R> &&trait::type_can_be_used_in_basic_result<EC> && (std::is_void<EC>::value || std::is_default_constructible<EC>::value))  //
  class basic_result_storage
  {
    static_assert(trait::type_can_be_used_in_basic_result<R>, "The type R cannot be used in a basic_result");
    static_assert(trait::type_can_be_used_in_basic_result<EC>, "The type S cannot be used in a basic_result");
    static_assert(std::is_void<EC>::value || std::is_default_constructible<EC>::value, "The type S must be void or default constructible");

    friend struct policy::base;
    template <class T, class U, class V>                                                                                                                                              //
    OUTCOME_REQUIRES(trait::type_can_be_used_in_basic_result<T> &&trait::type_can_be_used_in_basic_result<U> && (std::is_void<U>::value || std::is_default_constructible<U>::value))  //
    friend class basic_result_storage;
    template <class T, class U, class V> friend class basic_result_final;
    template <class T, class U, class V> friend constexpr inline uint16_t hooks::spare_storage(const detail::basic_result_final<T, U, V> *r) noexcept;        // NOLINT
    template <class T, class U, class V> friend constexpr inline void hooks::set_spare_storage(detail::basic_result_final<T, U, V> *r, uint16_t v) noexcept;  // NOLINT

  protected:
    using _value_type = typename value_storage_select_impl<R, EC>::_value_type;
    using _error_type = typename value_storage_select_impl<R, EC>::_error_type;

#ifdef STANDARDESE_IS_IN_THE_HOUSE
    value_storage_trivial<R, EC> _state;
#else
    value_storage_select_impl<R, EC> _state;
#endif

  public:
    // Used by iostream support to access state
    typename value_storage_select_impl<_value_type, _error_type>::value_storage_type &_iostreams_state() { return _state; }
    const typename value_storage_select_impl<_value_type, _error_type>::value_storage_type &_iostreams_state() const { return _state; }

    // Hack to work around MSVC bug in /permissive-
    value_storage_select_impl<_value_type, _error_type> &_msvc_nonpermissive_state() { return _state; }

  protected:
    basic_result_storage() = default;
    basic_result_storage(const basic_result_storage &) = default;             // NOLINT
    basic_result_storage(basic_result_storage &&) = default;                  // NOLINT
    basic_result_storage &operator=(const basic_result_storage &) = default;  // NOLINT
    basic_result_storage &operator=(basic_result_storage &&) = default;       // NOLINT
    ~basic_result_storage() = default;

    template <class... Args>
    constexpr explicit basic_result_storage(in_place_type_t<_value_type> _, Args &&... args) noexcept(std::is_nothrow_constructible<_value_type, Args...>::value)
        : _state{_, static_cast<Args &&>(args)...}
    {
    }
    template <class U, class... Args>
    constexpr basic_result_storage(in_place_type_t<_value_type> _, std::initializer_list<U> il, Args &&... args) noexcept(std::is_nothrow_constructible<_value_type, std::initializer_list<U>, Args...>::value)
        : _state{_, il, static_cast<Args &&>(args)...}
    {
    }
    template <class... Args>
    constexpr explicit basic_result_storage(in_place_type_t<_error_type> _, Args &&... args) noexcept(std::is_nothrow_constructible<_error_type, Args...>::value)
        : _state{_, static_cast<Args &&>(args)...}
    {
      _set_error_is_errno(_state, _state._error);
    }
    template <class U, class... Args>
    constexpr basic_result_storage(in_place_type_t<_error_type> _, std::initializer_list<U> il, Args &&... args) noexcept(std::is_nothrow_constructible<_error_type, std::initializer_list<U>, Args...>::value)
        : _state{_, il, static_cast<Args &&>(args)...}
    {
      _set_error_is_errno(_state, _state._error);
    }
    struct compatible_conversion_tag
    {
    };
    template <class T, class U, class V>
    constexpr basic_result_storage(compatible_conversion_tag /*unused*/, const basic_result_storage<T, U, V> &o) noexcept(std::is_nothrow_constructible<_value_type, T>::value &&std::is_nothrow_constructible<_error_type, U>::value)
        : _state(o._state)
    {
    }
    template <class T, class U, class V>
    constexpr basic_result_storage(compatible_conversion_tag /*unused*/, basic_result_storage<T, U, V> &&o) noexcept(std::is_nothrow_constructible<_value_type, T>::value &&std::is_nothrow_constructible<_error_type, U>::value)
        : _state(static_cast<decltype(o._state) &&>(o._state))
    {
    }

    struct make_error_code_compatible_conversion_tag
    {
    };
    template <class T, class U, class V>
    constexpr basic_result_storage(make_error_code_compatible_conversion_tag /*unused*/, const basic_result_storage<T, U, V> &o) noexcept(std::is_nothrow_constructible<_value_type, T>::value &&noexcept(make_error_code(std::declval<U>())))
        : _state(o._state)
        , _error(make_error_code(o._error))
    {
    }
    template <class T, class U, class V>
    constexpr basic_result_storage(make_error_code_compatible_conversion_tag /*unused*/, basic_result_storage<T, U, V> &&o) noexcept(std::is_nothrow_constructible<_value_type, T>::value &&noexcept(make_error_code(std::declval<U>())))
        : _state(static_cast<decltype(o._state) &&>(o._state))
        , _error(make_error_code(static_cast<U &&>(o._error)))
    {
    }

    struct make_exception_ptr_compatible_conversion_tag
    {
    };
    template <class T, class U, class V>
    constexpr basic_result_storage(make_exception_ptr_compatible_conversion_tag /*unused*/, const basic_result_storage<T, U, V> &o) noexcept(std::is_nothrow_constructible<_value_type, T>::value &&noexcept(make_exception_ptr(std::declval<U>())))
        : _state(o._state)
        , _error(make_exception_ptr(o._error))
    {
    }
    template <class T, class U, class V>
    constexpr basic_result_storage(make_exception_ptr_compatible_conversion_tag /*unused*/, basic_result_storage<T, U, V> &&o) noexcept(std::is_nothrow_constructible<_value_type, T>::value &&noexcept(make_exception_ptr(std::declval<U>())))
        : _state(static_cast<decltype(o._state) &&>(o._state))
        , _error(make_exception_ptr(static_cast<U &&>(o._error)))
    {
    }
  };
}  // namespace detail
OUTCOME_V2_NAMESPACE_END

#endif
