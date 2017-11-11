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
#include "value_storage.hpp"

#include <system_error>

OUTCOME_V2_NAMESPACE_EXPORT_BEGIN

namespace detail
{
  /* True if type is the same or constructible. Works around a bug where clang + libstdc++
  pukes on std::is_constructible<filesystem::path, void> (this bug is fixed upstream).
  */
  template <class T, class U, class... Args> struct _is_same_or_constructible
  {
    static constexpr bool value = std::is_constructible<T, U, Args...>::value;
  };
  template <class T> struct _is_same_or_constructible<T, T>
  {
    static constexpr bool value = true;
  };
  template <class T> struct _is_same_or_constructible<T, void>
  {
    static constexpr bool value = false;
  };
  template <> struct _is_same_or_constructible<void, void>
  {
    static constexpr bool value = false;
  };
  template <class T, class U, class... Args> static constexpr bool is_same_or_constructible = _is_same_or_constructible<T, U>::value;
// True if type is nothrow swappable
#if !defined(STANDARDESE_IS_IN_THE_HOUSE) && (_HAS_CXX17 || __cplusplus >= 201700)
  template <class T> using is_nothrow_swappable = std::is_nothrow_swappable<T>;
#else
  namespace _is_nothrow_swappable
  {
    using namespace std;
    template <class T> constexpr inline T &ldeclval();
    template <class T, class = void> struct is_nothrow_swappable : std::integral_constant<bool, false>
    {
    };
    template <class T> struct is_nothrow_swappable<T, decltype(swap(ldeclval<T>(), ldeclval<T>()))> : std::integral_constant<bool, noexcept(swap(ldeclval<T>(), ldeclval<T>()))>
    {
    };
  }
  template <class T> using is_nothrow_swappable = _is_nothrow_swappable::is_nothrow_swappable<T>;
#endif
  OUTCOME_TEMPLATE(class T, class U)
  OUTCOME_TREQUIRES(OUTCOME_TEXPR(std::declval<T>() == std::declval<U>()))
  inline bool safe_compare_equal(const T &a, const U &b) noexcept(noexcept(std::declval<T>() == std::declval<U>()))
  {
    // std::cout << "Taken " << typeid(T).name() << " == " << typeid(U).name() << " = " << (a == b) << std::endl;
    return a == b;
  }
  template <class T, class U> inline bool safe_compare_equal(T && /*unused*/, U && /*unused*/) noexcept
  {
    // std::cout << "Fallback " << typeid(T).name() << " == " << typeid(U).name() << " = false" << std::endl;
    return false;
  }
  OUTCOME_TEMPLATE(class T, class U)
  OUTCOME_TREQUIRES(OUTCOME_TEXPR(std::declval<T>() != std::declval<U>()))
  inline bool safe_compare_notequal(const T &a, const U &b) noexcept(noexcept(std::declval<T>() != std::declval<U>()))
  {
    // std::cout << "Taken " << typeid(T).name() << " != " << typeid(U).name() << " = " << (a != b) << std::endl;
    return a != b;
  }
  template <class T, class U> inline bool safe_compare_notequal(T && /*unused*/, U && /*unused*/) noexcept
  {
    // std::cout << "Fallback " << typeid(T).name() << " != " << typeid(U).name() << " = true" << std::endl;
    return true;
  }

  template <class State, class E> constexpr inline void _set_error_is_errno(State & /*unused*/, const E & /*unused*/) {}
  template <class State> constexpr inline void _set_error_is_errno(State &state, const std::error_code &error)
  {
    if(error.category() == std::generic_category()
#ifndef _WIN32
       || error.category() == std::system_category()
#endif
       )
    {
      state._status |= status_error_is_errno;
    }
  }
  template <class State> constexpr inline void _set_error_is_errno(State &state, const std::error_condition &error)
  {
    if(error.category() == std::generic_category()
#ifndef _WIN32
       || error.category() == std::system_category()
#endif
       )
    {
      state._status |= status_error_is_errno;
    }
  }
  template <class State> constexpr inline void _set_error_is_errno(State &state, const std::errc & /*unused*/) { state._status |= status_error_is_errno; }

  template <class R, class S, class NoValuePolicy> class result_final;
}  // namespace detail
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
  //! Predicate for permitting type to be used in outcome
  template <class R>                                                   //
  static constexpr bool type_can_be_used_in_result =                   //
  (!std::is_reference<R>::value                                        //
   && !detail::is_in_place_type_t<std::decay_t<R>>::value              //
   && !detail::is_success_type<R>::value                               //
   && !detail::is_failure_type<R>::value                               //
   && !std::is_array<R>::value                                         //
   && (std::is_void<R>::value || (std::is_object<R>::value             //
                                  && std::is_destructible<R>::value))  //
   );

  //! The base implementation type of `result<R, EC, NoValuePolicy>`.
  template <class R, class EC, class NoValuePolicy>                                                                                                          //
  OUTCOME_REQUIRES(type_can_be_used_in_result<R> &&type_can_be_used_in_result<EC> && (std::is_void<EC>::value || std::is_default_constructible<EC>::value))  //
  class result_storage
  {
    static_assert(type_can_be_used_in_result<R>, "The type R cannot be used in a result");
    static_assert(type_can_be_used_in_result<EC>, "The type S cannot be used in a result");
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

    detail::value_storage_select_impl<_value_type> _state;
    detail::devoid<_error_type> _error;

    result_storage() = default;
    result_storage(const result_storage &) = default;             // NOLINT
    result_storage(result_storage &&) = default;                  // NOLINT
    result_storage &operator=(const result_storage &) = default;  // NOLINT
    result_storage &operator=(result_storage &&) = default;       // NOLINT
    ~result_storage() = default;

    template <class... Args>
    constexpr explicit result_storage(in_place_type_t<_value_type> _, Args &&... args) noexcept(std::is_nothrow_constructible<_value_type, Args...>::value)
        : _state{_, std::forward<Args>(args)...}
        , _error()
    {
    }
    template <class U, class... Args>
    constexpr result_storage(in_place_type_t<_value_type> _, std::initializer_list<U> il, Args &&... args) noexcept(std::is_nothrow_constructible<_value_type, std::initializer_list<U>, Args...>::value)
        : _state{_, il, std::forward<Args>(args)...}
        , _error()
    {
    }
    template <class... Args>
    constexpr explicit result_storage(in_place_type_t<_error_type> /*unused*/, Args &&... args) noexcept(std::is_nothrow_constructible<_error_type, Args...>::value)
        : _state{detail::status_have_error}
        , _error{std::forward<Args>(args)...}
    {
      detail::_set_error_is_errno(_state, _error);
    }
    template <class U, class... Args>
    constexpr result_storage(in_place_type_t<_error_type> /*unused*/, std::initializer_list<U> il, Args &&... args) noexcept(std::is_nothrow_constructible<_error_type, std::initializer_list<U>, Args...>::value)
        : _state{detail::status_have_error}
        , _error{il, std::forward<Args>(args)...}
    {
      detail::_set_error_is_errno(_state, _error);
    }
    struct compatible_conversion_tag
    {
    };
    template <class U, class V>
    constexpr result_storage(compatible_conversion_tag /*unused*/, U &&a, V &&b)
        : _state(in_place_type<_value_type>, std::forward<U>(a))
        , _error(std::forward<V>(b))
    {
    }
    template <class V>
    constexpr result_storage(compatible_conversion_tag /*unused*/, detail::void_type /*unused*/, V &&b)
        : _state(in_place_type<_value_type>)
        , _error(std::forward<V>(b))
    {
    }
    template <class U, class V>
    constexpr result_storage(compatible_conversion_tag /*unused*/, U &&a, detail::void_type /*unused*/)
        : _state(in_place_type<_value_type>, std::forward<U>(a))
        , _error()
    {
    }
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
        : _state(std::move(o._state))
        , _error(std::move(o._error))
    {
    }
    template <class T, class V>
    constexpr result_storage(compatible_conversion_tag /*unused*/, result_storage<T, void, V> &&o) noexcept(std::is_nothrow_constructible<_value_type, T>::value)
        : _state(std::move(o._state))
        , _error(_error_type{})
    {
    }  };
}  // namespace detail
OUTCOME_V2_NAMESPACE_END

#endif
