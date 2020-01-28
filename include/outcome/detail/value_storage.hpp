/* Essentially an internal optional implementation :)
(C) 2017-2019 Niall Douglas <http://www.nedproductions.biz/> (24 commits)
File Created: June 2017


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

#ifndef OUTCOME_VALUE_STORAGE_HPP
#define OUTCOME_VALUE_STORAGE_HPP

#include "../config.hpp"

#include <cassert>

OUTCOME_V2_NAMESPACE_BEGIN

namespace detail
{
  template <class T, bool nothrow> struct strong_swap_impl
  {
    constexpr strong_swap_impl(bool &allgood, T &a, T &b)
    {
      allgood = true;
      using std::swap;
      swap(a, b);
    }
  };
#ifdef __cpp_exceptions
  template <class T> struct strong_swap_impl<T, false>
  {
    strong_swap_impl(bool &allgood, T &a, T &b)
    {
      allgood = true;
      T v(static_cast<T &&>(a));
      try
      {
        a = static_cast<T &&>(b);
      }
      catch(...)
      {
        // Try to put back a
        try
        {
          a = static_cast<T &&>(v);
          // fall through as all good
        }
        catch(...)
        {
          // failed to completely restore
          allgood = false;
          // throw away second exception
        }
        throw;  // rethrow original exception
      }
      // b has been moved to a, try to move v to b
      try
      {
        b = static_cast<T &&>(v);
      }
      catch(...)
      {
        // Try to restore a to b, and v to a
        try
        {
          b = static_cast<T &&>(a);
          a = static_cast<T &&>(v);
          // fall through as all good
        }
        catch(...)
        {
          // failed to completely restore
          allgood = false;
          // throw away second exception
        }
        throw;  // rethrow original exception
      }
    }
  };
#endif
}  // namespace detail

/*!
 */
OUTCOME_TEMPLATE(class T)
OUTCOME_TREQUIRES(OUTCOME_TPRED(std::is_move_constructible<T>::value &&std::is_move_assignable<T>::value))
constexpr inline void strong_swap(bool &allgood, T &a, T &b) noexcept(detail::is_nothrow_swappable<T>::value)
{
  detail::strong_swap_impl<T, detail::is_nothrow_swappable<T>::value>(allgood, a, b);
}

namespace detail
{
  template <class T>
  constexpr
#ifdef _MSC_VER
  __declspec(noreturn)
#elif defined(__GNUC__) || defined(__clang__)
        __attribute__((noreturn))
#endif
  void make_ub(T && /*unused*/)
  {
    assert(false);  // NOLINT
#if defined(__GNUC__) || defined(__clang__)
    __builtin_unreachable();
#elif defined(_MSC_VER)
    __assume(0);
#endif
  }

  /* Outcome v1 used a C bitfield whose values were tracked by compiler optimisers nicely,
  but that produces ICEs when used in constexpr.

  Outcome v2.0-v2.1 used a 32 bit integer and manually set and cleared bits. Unfortunately
  only GCC's optimiser tracks bit values during constant folding, and only per byte, and
  even then unreliably. https://wg21.link/P1886 "Error speed benchmarking" showed just how
  poorly clang and MSVC fails to optimise outcome-using code, if you manually set bits.

  Outcome v2.2 therefore uses an enum with fixed values, and constexpr manipulation functions
  to change the value to one of the enum's values. This is stupid to look at in source code,
  but it make clang's optimiser do the right thing, so it's worth it.
  */
#define OUTCOME_USE_CONSTEXPR_ENUM_STATUS 0
  enum class status : uint16_t
  {
    // WARNING: These bits are not tracked by abi-dumper, but changing them will break ABI!
    none = 0,

    have_value = (1U << 0U),
    have_error = (1U << 1U),
    have_exception = (2U << 1U),
    have_error_exception = (3U << 1U),

    // failed to complete a strong swap
    have_lost_consistency = (1U << 3U),
    have_value_lost_consistency = (1U << 0U) | (1U << 3U),
    have_error_lost_consistency = (1U << 1U) | (1U << 3U),
    have_exception_lost_consistency = (2U << 1U) | (1U << 3U),
    have_error_exception_lost_consistency = (3U << 1U) | (1U << 3U),

    // can errno be set from this error?
    have_error_is_errno = (1U << 4U),
    have_error_error_is_errno = (1U << 1U) | (1U << 4U),
    have_error_exception_error_is_errno = (3U << 1U) | (1U << 4U),

    have_error_lost_consistency_error_is_errno = (1U << 1U) | (1U << 3U) | (1U << 4U),
    have_error_exception_lost_consistency_error_is_errno = (3U << 1U) | (1U << 3U) | (1U << 4U),

    // value has been moved from
    have_moved_from = (1U << 5U)
  };
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4201)  // nameless struct/union
#endif
  struct status_bitfield_type
  {
    union {
      uint32_t _default{0};
      struct
      {
        status status_value;
        uint16_t spare_storage_value;  // hooks::spare_storage()
      };
    };

    status_bitfield_type() = default;
    constexpr status_bitfield_type(status v) noexcept
        : status_value(v)
        , spare_storage_value(0)
    {
    }  // NOLINT
    constexpr status_bitfield_type(status v, uint16_t s) noexcept
        : status_value(v)
        , spare_storage_value(s)
    {
    }

    constexpr bool have_value() const noexcept
    {
#if OUTCOME_USE_CONSTEXPR_ENUM_STATUS
      return (status_value == status::have_value)                      //
             || (status_value == status::have_value_lost_consistency)  //
      ;
#else
      return (static_cast<uint16_t>(status_value) & static_cast<uint16_t>(status::have_value)) != 0;
#endif
    }
    constexpr bool have_error() const noexcept
    {
#if OUTCOME_USE_CONSTEXPR_ENUM_STATUS
      return (status_value == status::have_error)                                               //
             || (status_value == status::have_error_exception)                                  //
             || (status_value == status::have_error_lost_consistency)                           //
             || (status_value == status::have_error_exception_lost_consistency)                 //
             || (status_value == status::have_error_error_is_errno)                             //
             || (status_value == status::have_error_exception_error_is_errno)                   //
             || (status_value == status::have_error_lost_consistency_error_is_errno)            //
             || (status_value == status::have_error_exception_lost_consistency_error_is_errno)  //
      ;
#else
      return (static_cast<uint16_t>(status_value) & static_cast<uint16_t>(status::have_error)) != 0;
#endif
    }
    constexpr bool have_exception() const noexcept
    {
#if OUTCOME_USE_CONSTEXPR_ENUM_STATUS
      return (status_value == status::have_exception)                                           //
             || (status_value == status::have_error_exception)                                  //
             || (status_value == status::have_exception_lost_consistency)                       //
             || (status_value == status::have_error_exception_lost_consistency)                 //
             || (status_value == status::have_error_exception_error_is_errno)                   //
             || (status_value == status::have_error_exception_lost_consistency_error_is_errno)  //
      ;
#else
      return (static_cast<uint16_t>(status_value) & static_cast<uint16_t>(status::have_exception)) != 0;
#endif
    }
    constexpr bool have_lost_consistency() const noexcept
    {
#if OUTCOME_USE_CONSTEXPR_ENUM_STATUS
      return (status_value == status::have_value_lost_consistency)                              //
             || (status_value == status::have_error_lost_consistency)                           //
             || (status_value == status::have_exception_lost_consistency)                       //
             || (status_value == status::have_error_lost_consistency_error_is_errno)            //
             || (status_value == status::have_error_exception_lost_consistency_error_is_errno)  //
      ;
#else
      return (static_cast<uint16_t>(status_value) & static_cast<uint16_t>(status::have_lost_consistency)) != 0;
#endif
    }
    constexpr bool have_error_is_errno() const noexcept
    {
#if OUTCOME_USE_CONSTEXPR_ENUM_STATUS
      return (status_value == status::have_error_error_is_errno)                                //
             || (status_value == status::have_error_exception_error_is_errno)                   //
             || (status_value == status::have_error_lost_consistency_error_is_errno)            //
             || (status_value == status::have_error_exception_lost_consistency_error_is_errno)  //
      ;
#else
      return (static_cast<uint16_t>(status_value) & static_cast<uint16_t>(status::have_error_is_errno)) != 0;
#endif
    }
    constexpr bool have_moved_from() const noexcept
    {
#if OUTCOME_USE_CONSTEXPR_ENUM_STATUS
#error Fixme
#else
      return (static_cast<uint16_t>(status_value) & static_cast<uint16_t>(status::have_moved_from)) != 0;
#endif
    }

    constexpr status_bitfield_type &set_have_value(bool v) noexcept
    {
#if OUTCOME_USE_CONSTEXPR_ENUM_STATUS
      switch(status_value)
      {
      case status::none:
        if(v)
        {
          status_value = status::have_value;
        }
        break;
      case status::have_value:
        if(!v)
        {
          status_value = status::none;
        }
        break;
      case status::have_error:
        if(v)
        {
          make_ub(*this);
        }
        break;
      case status::have_exception:
        if(v)
        {
          make_ub(*this);
        }
        break;
      case status::have_error_exception:
        if(v)
        {
          make_ub(*this);
        }
        break;
      case status::have_value_lost_consistency:
        if(!v)
        {
          status_value = status::none;
        }
        break;
      case status::have_error_lost_consistency:
        if(v)
        {
          make_ub(*this);
        }
        break;
      case status::have_exception_lost_consistency:
        if(v)
        {
          make_ub(*this);
        }
        break;
      case status::have_error_exception_lost_consistency:
        if(v)
        {
          make_ub(*this);
        }
        break;
      case status::have_error_error_is_errno:
        if(v)
        {
          make_ub(*this);
        }
        break;
      case status::have_error_exception_error_is_errno:
        if(v)
        {
          make_ub(*this);
        }
        break;
      case status::have_error_lost_consistency_error_is_errno:
        if(v)
        {
          make_ub(*this);
        }
        break;
      case status::have_error_exception_lost_consistency_error_is_errno:
        if(v)
        {
          make_ub(*this);
        }
        break;
      }
#else
      status_value = static_cast<status>(v ? (static_cast<uint16_t>(status_value) | static_cast<uint16_t>(status::have_value)) : (static_cast<uint16_t>(status_value) & ~static_cast<uint16_t>(status::have_value)));
#endif
      return *this;
    }
    constexpr status_bitfield_type &set_have_error(bool v) noexcept
    {
#if OUTCOME_USE_CONSTEXPR_ENUM_STATUS
      switch(status_value)
      {
      case status::none:
        if(v)
        {
          status_value = status::have_error;
        }
        break;
      case status::have_value:
        if(v)
        {
          make_ub(*this);
        }
        break;
      case status::have_error:
        if(!v)
        {
          status_value = status::none;
        }
        break;
      case status::have_exception:
        if(v)
        {
          status_value = status::have_error_exception;
        }
        break;
      case status::have_error_exception:
        if(!v)
        {
          status_value = status::have_exception;
        }
        break;
      case status::have_value_lost_consistency:
        if(v)
        {
          make_ub(*this);
        }
        break;
      case status::have_error_lost_consistency:
        if(!v)
        {
          status_value = status::none;
        }
        break;
      case status::have_exception_lost_consistency:
        if(v)
        {
          status_value = status::have_error_exception_lost_consistency;
        }
        break;
      case status::have_error_exception_lost_consistency:
        if(!v)
        {
          status_value = status::have_exception_lost_consistency;
        }
        break;
      case status::have_error_error_is_errno:
        if(!v)
        {
          status_value = status::none;
        }
        break;
      case status::have_error_exception_error_is_errno:
        if(!v)
        {
          status_value = status::have_exception;
        }
        break;
      case status::have_error_lost_consistency_error_is_errno:
        if(!v)
        {
          status_value = status::none;
        }
        break;
      case status::have_error_exception_lost_consistency_error_is_errno:
        if(!v)
        {
          status_value = status::have_exception_lost_consistency;
        }
        break;
      }
#else
      status_value = static_cast<status>(v ? (static_cast<uint16_t>(status_value) | static_cast<uint16_t>(status::have_error)) : (static_cast<uint16_t>(status_value) & ~static_cast<uint16_t>(status::have_error)));
#endif
      return *this;
    }
    constexpr status_bitfield_type &set_have_exception(bool v) noexcept
    {
#if OUTCOME_USE_CONSTEXPR_ENUM_STATUS
      switch(status_value)
      {
      case status::none:
        if(v)
        {
          status_value = status::have_exception;
        }
        break;
      case status::have_value:
        if(v)
        {
          make_ub(*this);
        }
        break;
      case status::have_error:
        if(v)
        {
          status_value = status::have_error_exception;
        }
        break;
      case status::have_exception:
        if(!v)
        {
          status_value = status::none;
        }
        break;
      case status::have_error_exception:
        if(!v)
        {
          status_value = status::have_error;
        }
        break;
      case status::have_value_lost_consistency:
        if(v)
        {
          make_ub(*this);
        }
        break;
      case status::have_error_lost_consistency:
        if(v)
        {
          status_value = status::have_error_exception_lost_consistency;
        }
        break;
      case status::have_exception_lost_consistency:
        if(!v)
        {
          status_value = status::none;
        }
        break;
      case status::have_error_exception_lost_consistency:
        if(!v)
        {
          status_value = status::have_error_lost_consistency;
        }
        break;
      case status::have_error_error_is_errno:
        if(v)
        {
          status_value = status::have_error_exception_error_is_errno;
        }
        break;
      case status::have_error_exception_error_is_errno:
        if(!v)
        {
          status_value = status::have_error_error_is_errno;
        }
        break;
      case status::have_error_lost_consistency_error_is_errno:
        if(v)
        {
          status_value = status::have_error_exception_lost_consistency_error_is_errno;
        }
        break;
      case status::have_error_exception_lost_consistency_error_is_errno:
        if(!v)
        {
          status_value = status::have_error_lost_consistency_error_is_errno;
        }
        break;
      }
#else
      status_value = static_cast<status>(v ? (static_cast<uint16_t>(status_value) | static_cast<uint16_t>(status::have_exception)) : (static_cast<uint16_t>(status_value) & ~static_cast<uint16_t>(status::have_exception)));
#endif
      return *this;
    }
    constexpr status_bitfield_type &set_have_error_is_errno(bool v) noexcept
    {
#if OUTCOME_USE_CONSTEXPR_ENUM_STATUS
      switch(status_value)
      {
      case status::none:
        make_ub(*this);
        break;
      case status::have_value:
        make_ub(*this);
        break;
      case status::have_error:
        if(v)
        {
          status_value = status::have_error_error_is_errno;
        }
        break;
      case status::have_exception:
        make_ub(*this);
        break;
      case status::have_error_exception:
        if(v)
        {
          status_value = status::have_error_exception_error_is_errno;
        }
        break;
      case status::have_value_lost_consistency:
        make_ub(*this);
        break;
      case status::have_error_lost_consistency:
        if(v)
        {
          status_value = status::have_error_lost_consistency_error_is_errno;
        }
        break;
      case status::have_exception_lost_consistency:
        make_ub(*this);
        break;
      case status::have_error_exception_lost_consistency:
        if(v)
        {
          status_value = status::have_error_exception_lost_consistency_error_is_errno;
        }
        break;
      case status::have_error_error_is_errno:
        if(!v)
        {
          status_value = status::have_error;
        }
        break;
      case status::have_error_exception_error_is_errno:
        if(!v)
        {
          status_value = status::have_error_exception;
        }
        break;
      case status::have_error_lost_consistency_error_is_errno:
        if(!v)
        {
          status_value = status::have_error_lost_consistency;
        }
        break;
      case status::have_error_exception_lost_consistency_error_is_errno:
        if(!v)
        {
          status_value = status::have_error_exception_lost_consistency;
        }
        break;
      }
#else
      status_value = static_cast<status>(v ? (static_cast<uint16_t>(status_value) | static_cast<uint16_t>(status::have_error_is_errno)) : (static_cast<uint16_t>(status_value) & ~static_cast<uint16_t>(status::have_error_is_errno)));
#endif
      return *this;
    }
    constexpr status_bitfield_type &set_have_lost_consistency(bool v) noexcept
    {
#if OUTCOME_USE_CONSTEXPR_ENUM_STATUS
      switch(status_value)
      {
      case status::none:
        if(v)
        {
          make_ub(*this);
        }
        break;
      case status::have_value:
        if(v)
        {
          status_value = status::have_value_lost_consistency;
        }
        break;
      case status::have_error:
        if(v)
        {
          status_value = status::have_error_lost_consistency;
        }
        break;
      case status::have_exception:
        if(v)
        {
          status_value = status::have_exception_lost_consistency;
        }
        break;
      case status::have_error_exception:
        if(v)
        {
          status_value = status::have_error_exception_lost_consistency;
        }
        break;
      case status::have_value_lost_consistency:
        if(!v)
        {
          status_value = status::have_value;
        }
        break;
      case status::have_error_lost_consistency:
        if(!v)
        {
          status_value = status::have_error;
        }
        break;
      case status::have_exception_lost_consistency:
        if(!v)
        {
          status_value = status::have_exception;
        }
        break;
      case status::have_error_exception_lost_consistency:
        if(!v)
        {
          status_value = status::have_error_exception;
        }
        break;
      case status::have_error_error_is_errno:
        if(v)
        {
          status_value = status::have_error_lost_consistency_error_is_errno;
        }
        break;
      case status::have_error_exception_error_is_errno:
        if(v)
        {
          status_value = status::have_error_exception_lost_consistency_error_is_errno;
        }
        break;
      case status::have_error_lost_consistency_error_is_errno:
        if(!v)
        {
          status_value = status::have_error_exception_error_is_errno;
        }
        break;
      case status::have_error_exception_lost_consistency_error_is_errno:
        if(!v)
        {
          status_value = status::have_error_exception_error_is_errno;
        }
        break;
      }
#else
      status_value = static_cast<status>(v ? (static_cast<uint16_t>(status_value) | static_cast<uint16_t>(status::have_lost_consistency)) : (static_cast<uint16_t>(status_value) & ~static_cast<uint16_t>(status::have_lost_consistency)));
#endif
      return *this;
    }
    constexpr status_bitfield_type &set_have_moved_from(bool v) noexcept
    {
#if OUTCOME_USE_CONSTEXPR_ENUM_STATUS
#error Fixme
#else
      status_value = static_cast<status>(v ? (static_cast<uint16_t>(status_value) | static_cast<uint16_t>(status::have_moved_from)) : (static_cast<uint16_t>(status_value) & ~static_cast<uint16_t>(status::have_moved_from)));
#endif
      return *this;
    }
  };
#ifdef _MSC_VER
#pragma warning(pop)
#endif
  static_assert(sizeof(status_bitfield_type) == 4, "status_bitfield_type is not sized 4 bytes!");
  static_assert(std::is_trivially_copyable<status_bitfield_type>::value, "status_bitfield_type is not trivially copyable!");

  template <class State> constexpr inline void _set_error_is_errno(State & /*unused*/) {}

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4127)  // conditional expression is constant
#pragma warning(disable : 4624)  // destructor was implicitly defined as deleted
#endif
  // Used if both T and E are trivial
  template <class T, class E> struct value_storage_trivial
  {
    using value_type = T;
    using error_type = E;
    union {
      empty_type _empty;
      devoid<T> _value;
      devoid<E> _error;
    };
    status_bitfield_type _status;
    constexpr value_storage_trivial() noexcept
        : _empty{}
    {
    }
    // Special from-void catchall constructor, always constructs default T irrespective of whether void is valued or not (can do no better if T cannot be copied)
    struct disable_void_catchall
    {
    };
    using void_value_storage_trivial = std::conditional_t<std::is_void<T>::value, disable_void_catchall, value_storage_trivial<void, error_type>>;
    explicit constexpr value_storage_trivial(const void_value_storage_trivial &o) noexcept(std::is_nothrow_default_constructible<value_type>::value)
        : _value()
        , _status(o._status)
    {
    }
    value_storage_trivial(const value_storage_trivial &) = default;             // NOLINT
    value_storage_trivial(value_storage_trivial &&) = default;                  // NOLINT
    value_storage_trivial &operator=(const value_storage_trivial &) = default;  // NOLINT
    value_storage_trivial &operator=(value_storage_trivial &&) = default;       // NOLINT
    ~value_storage_trivial() = default;
    constexpr explicit value_storage_trivial(status_bitfield_type status)
        : _empty()
        , _status(status)
    {
    }
    template <class... Args>
    constexpr explicit value_storage_trivial(in_place_type_t<value_type> /*unused*/, Args &&... args) noexcept(std::is_nothrow_constructible<value_type, Args...>::value)
        : _value(static_cast<Args &&>(args)...)
        , _status(status::have_value)
    {
    }
    template <class U, class... Args>
    constexpr value_storage_trivial(in_place_type_t<value_type> /*unused*/, std::initializer_list<U> il, Args &&... args) noexcept(std::is_nothrow_constructible<value_type, std::initializer_list<U>, Args...>::value)
        : _value(il, static_cast<Args &&>(args)...)
        , _status(status::have_value)
    {
    }
    template <class... Args>
    constexpr explicit value_storage_trivial(in_place_type_t<error_type> /*unused*/, Args &&... args) noexcept(std::is_nothrow_constructible<error_type, Args...>::value)
        : _error(static_cast<Args &&>(args)...)
        , _status(status::have_error)
    {
      _set_error_is_errno(*this);
    }
    template <class U, class... Args>
    constexpr value_storage_trivial(in_place_type_t<error_type> /*unused*/, std::initializer_list<U> il, Args &&... args) noexcept(std::is_nothrow_constructible<error_type, std::initializer_list<U>, Args...>::value)
        : _error(il, static_cast<Args &&>(args)...)
        , _status(status::have_error)
    {
      _set_error_is_errno(*this);
    }
    template <class U, class V>
    static constexpr bool enable_converting_constructor = !(std::is_same<std::decay_t<U>, value_type>::value && std::is_same<std::decay_t<V>, error_type>::value)  //
                                                          && std::is_constructible<value_type, U>::value && std::is_constructible<error_type, V>::value;
    OUTCOME_TEMPLATE(class U, class V)
    OUTCOME_TREQUIRES(OUTCOME_TPRED(enable_converting_constructor<U, V>))
    constexpr explicit value_storage_trivial(const value_storage_trivial<U, V> &o) noexcept(std::is_nothrow_constructible<value_type, U>::value &&std::is_nothrow_constructible<error_type, V>::value)
        : value_storage_trivial(o._status.have_value() ? value_storage_trivial(in_place_type<value_type>, o._value) : (o._status.have_error() ? value_storage_trivial(in_place_type<error_type>, o._error) : value_storage_trivial()))  // NOLINT
    {
      _status = o._status;
    }
    OUTCOME_TEMPLATE(class U, class V)
    OUTCOME_TREQUIRES(OUTCOME_TPRED(enable_converting_constructor<U, V>))
    constexpr explicit value_storage_trivial(value_storage_trivial<U, V> &&o) noexcept(std::is_nothrow_constructible<value_type, U>::value &&std::is_nothrow_constructible<error_type, V>::value)
        : value_storage_trivial(o._status.have_value() ? value_storage_trivial(in_place_type<value_type>, static_cast<U &&>(o._value)) : (o._status.have_error() ? value_storage_trivial(in_place_type<error_type>, static_cast<V &&>(o._error)) : value_storage_trivial()))  // NOLINT
    {
      _status = o._status;
    }
    constexpr void swap(value_storage_trivial &o) noexcept
    {
      // storage is trivial, so just use assignment
      auto temp = static_cast<value_storage_trivial &&>(*this);
      *this = static_cast<value_storage_trivial &&>(o);
      o = static_cast<value_storage_trivial &&>(temp);
    }
  };
  // Used if T is non-trivial
  template <class T, class E> struct value_storage_nontrivial
  {
    using value_type = T;
    using error_type = E;
    union {
      empty_type _empty1;
      devoid<value_type> _value;
    };
    status_bitfield_type _status;
    union {
      empty_type _empty2;
      devoid<error_type> _error;
    };
    value_storage_nontrivial() noexcept
        : _empty1{}
        , _empty2{}
    {
    }
    value_storage_nontrivial &operator=(const value_storage_nontrivial &) = default;                                                                                                // if reaches here, copy assignment is trivial
    value_storage_nontrivial &operator=(value_storage_nontrivial &&) = default;                                                                                                     // NOLINT if reaches here, move assignment is trivial
    value_storage_nontrivial(value_storage_nontrivial &&o) noexcept(std::is_nothrow_move_constructible<value_type>::value &&std::is_nothrow_move_constructible<error_type>::value)  // NOLINT
    {
      if(o._status.have_value())
      {
        new(&_value) value_type(static_cast<value_type &&>(o._value));  // NOLINT
      }
      else if(o._status.have_error())
      {
        new(&_error) error_type(static_cast<error_type &&>(o._error));  // NOLINT
      }
      _status = o._status;
      o._status.set_have_moved_from(true);
    }
    value_storage_nontrivial(const value_storage_nontrivial &o) noexcept(std::is_nothrow_copy_constructible<value_type>::value &&std::is_nothrow_copy_constructible<error_type>::value)
    {
      if(o._status.have_value())
      {
        new(&_value) value_type(o._value);  // NOLINT
      }
      else if(o._status.have_error())
      {
        new(&_error) error_type(o._error);  // NOLINT
      }
      _status = o._status;
    }
    // Special from-void constructor, constructs default T if void valued
    explicit value_storage_nontrivial(const value_storage_trivial<void, error_type> &o) noexcept(std::is_nothrow_default_constructible<value_type>::value)
        : _status(o._status)
    {
      if(o._status.have_value())
      {
        new(&_value) value_type;  // NOLINT
      }
      _status = o._status;
    }
    explicit value_storage_nontrivial(status_bitfield_type status)
        : _empty1()
        , _status(status)
        , _empty2()
    {
    }
    template <class... Args>
    explicit value_storage_nontrivial(in_place_type_t<value_type> /*unused*/, Args &&... args) noexcept(std::is_nothrow_constructible<value_type, Args...>::value)
        : _value(static_cast<Args &&>(args)...)  // NOLINT
        , _status(status::have_value)
    {
    }
    template <class U, class... Args>
    value_storage_nontrivial(in_place_type_t<value_type> /*unused*/, std::initializer_list<U> il, Args &&... args) noexcept(std::is_nothrow_constructible<value_type, std::initializer_list<U>, Args...>::value)
        : _value(il, static_cast<Args &&>(args)...)
        , _status(status::have_value)
    {
    }
    template <class... Args>
    explicit value_storage_nontrivial(in_place_type_t<error_type> /*unused*/, Args &&... args) noexcept(std::is_nothrow_constructible<error_type, Args...>::value)
        : _status(status::have_error)
        , _error(static_cast<Args &&>(args)...)  // NOLINT
    {
      _set_error_is_errno(*this);
    }
    template <class U, class... Args>
    value_storage_nontrivial(in_place_type_t<error_type> /*unused*/, std::initializer_list<U> il, Args &&... args) noexcept(std::is_nothrow_constructible<error_type, std::initializer_list<U>, Args...>::value)
        : _status(status::have_error)
        , _error(il, static_cast<Args &&>(args)...)
    {
      _set_error_is_errno(*this);
    }
    template <class U, class V>
    static constexpr bool enable_converting_constructor = !(std::is_same<std::decay_t<U>, value_type>::value && std::is_same<std::decay_t<V>, error_type>::value)  //
                                                          && std::is_constructible<value_type, U>::value && std::is_constructible<error_type, V>::value;
    OUTCOME_TEMPLATE(class U, class V)
    OUTCOME_TREQUIRES(OUTCOME_TPRED(enable_converting_constructor<U, V>))
    constexpr explicit value_storage_nontrivial(const value_storage_nontrivial<U, V> &o) noexcept(std::is_nothrow_constructible<value_type, U>::value &&std::is_nothrow_constructible<error_type, V>::value)
        : value_storage_nontrivial(o._status.have_value() ? value_storage_nontrivial(in_place_type<value_type>, o._value) : (o._status.have_error() ? value_storage_nontrivial(in_place_type<error_type>, o._error) : value_storage_nontrivial()))
    {
      _status = o._status;
    }
    OUTCOME_TEMPLATE(class U, class V)
    OUTCOME_TREQUIRES(OUTCOME_TPRED(enable_converting_constructor<U, V>))
    constexpr explicit value_storage_nontrivial(const value_storage_trivial<U, V> &o) noexcept(std::is_nothrow_constructible<value_type, U>::value &&std::is_nothrow_constructible<error_type, V>::value)
        : value_storage_nontrivial(o._status.have_value() ? value_storage_nontrivial(in_place_type<value_type>, o._value) : (o._status.have_error() ? value_storage_nontrivial(in_place_type<error_type>, o._error) : value_storage_nontrivial()))
    {
      _status = o._status;
    }
    OUTCOME_TEMPLATE(class U, class V)
    OUTCOME_TREQUIRES(OUTCOME_TPRED(enable_converting_constructor<U, V>))
    constexpr explicit value_storage_nontrivial(value_storage_nontrivial<U, V> &&o) noexcept(std::is_nothrow_constructible<value_type, U>::value &&std::is_nothrow_constructible<error_type, V>::value)
        : value_storage_nontrivial(o._status.have_value() ? value_storage_nontrivial(in_place_type<value_type>, static_cast<U &&>(o._value)) : (o._status.have_error() ? value_storage_nontrivial(in_place_type<error_type>, static_cast<V &&>(o._error)) : value_storage_nontrivial()))
    {
      _status = o._status;
    }
    OUTCOME_TEMPLATE(class U, class V)
    OUTCOME_TREQUIRES(OUTCOME_TPRED(enable_converting_constructor<U, V>))
    constexpr explicit value_storage_nontrivial(value_storage_trivial<U, V> &&o) noexcept(std::is_nothrow_constructible<value_type, U>::value &&std::is_nothrow_constructible<error_type, V>::value)
        : value_storage_nontrivial(o._status.have_value() ? value_storage_nontrivial(in_place_type<value_type>, static_cast<U &&>(o._value)) : (o._status.have_error() ? value_storage_nontrivial(in_place_type<error_type>, static_cast<V &&>(o._error)) : value_storage_nontrivial()))
    {
      _status = o._status;
    }
    ~value_storage_nontrivial() noexcept(std::is_nothrow_destructible<T>::value)
    {
      if(this->_status.have_value())
      {
        if(!trait::is_move_relocating<value_type>::value || !this->_status.have_moved_from())
        {
          using _value_type = devoid<value_type>;
          this->_value.~_value_type();  // NOLINT
        }
        this->_status.set_have_value(false);
      }
      else if(this->_status.have_error())
      {
        if(!trait::is_move_relocating<error_type>::value || !this->_status.have_moved_from())
        {
          using _error_type = devoid<error_type>;
          this->_error.~_error_type();  // NOLINT
        }
        this->_status.set_have_error(false);
      }
    }
    constexpr void swap(value_storage_nontrivial &o) noexcept(detail::is_nothrow_swappable<value_type>::value)
    {
      using std::swap;
      if(!_status.have_value() && !o._status.have_value() && !_status.have_error() && !o._status.have_error())
      {
        swap(_status, o._status);
        return;
      }
      if(_status.have_value() && o._status.have_value())
      {
        struct _
        {
          status_bitfield_type &a, &b;
          bool all_good{false};
          ~_()
          {
            if(!all_good)
            {
              // We lost one of the values
              a.set_have_lost_consistency(true);
              b.set_have_lost_consistency(true);
            }
          }
        } _{_status, o._status};
        strong_swap(_.all_good, _value, o._value);
        swap(_status, o._status);
        return;
      }
      if(_status.have_error() && o._status.have_error())
      {
        struct _
        {
          status_bitfield_type &a, &b;
          bool all_good{false};
          ~_()
          {
            if(!all_good)
            {
              // We lost one of the values
              a.set_have_lost_consistency(true);
              b.set_have_lost_consistency(true);
            }
          }
        } _{_status, o._status};
        strong_swap(_.all_good, _error, o._error);
        swap(_status, o._status);
        return;
      }
      // Could be value/empty, error/empty, etc
      if(_status.have_value() && !o._status.have_error())
      {
        // Move construct me into other
        new(&o._value) value_type(static_cast<value_type &&>(_value));  // NOLINT
        if(!trait::is_move_relocating<value_type>::value)
        {
          this->_value.~value_type();  // NOLINT
        }
        swap(_status, o._status);
        return;
      }
      if(o._status.have_value() && !_status.have_error())
      {
        // Move construct other into me
        new(&_value) value_type(static_cast<value_type &&>(o._value));  // NOLINT
        if(!trait::is_move_relocating<value_type>::value)
        {
          o._value.~value_type();  // NOLINT
        }
        swap(_status, o._status);
        return;
      }
      if(_status.have_error() && !o._status.have_value())
      {
        // Move construct me into other
        new(&o._error) error_type(static_cast<error_type &&>(_error));  // NOLINT
        if(!trait::is_move_relocating<error_type>::value)
        {
          this->_error.~error_type();  // NOLINT
        }
        swap(_status, o._status);
        return;
      }
      if(o._status.have_error() && !_status.have_value())
      {
        // Move construct other into me
        new(&_error) error_type(static_cast<error_type &&>(o._error));  // NOLINT
        if(!trait::is_move_relocating<error_type>::value)
        {
          o._error.~error_type();  // NOLINT
        }
        swap(_status, o._status);
        return;
      }
      // It can now only be value/error, or error/value
      union {
        empty_type empty1;
        value_type temp_value;
      };
      union {
        empty_type empty2;
        error_type temp_error;
      };
      if(_status.have_value() && o._status.have_error())
      {
        struct _
        {
          status_bitfield_type &a, &b;
          bool all_good{false};
          ~_()
          {
            if(!all_good)
            {
              // We lost one of the values
              a.set_have_lost_consistency(true);
              b.set_have_lost_consistency(true);
            }
          }
        } _{_status, o._status};
        strong_placement(_.all_good, temp_value, _value);
        strong_placement(_.all_good, temp_error, o._error);
        strong_placement(_.all_good, o._value, temp_value);
        strong_placement(_.all_good, _error, temp_error);
        swap(_status, o._status);
        return;
      }
      if(_status.have_error() && o._status.have_value())
      {
        struct _
        {
          status_bitfield_type &a, &b;
          bool all_good{false};
          ~_()
          {
            if(!all_good)
            {
              // We lost one of the values
              a.set_have_lost_consistency(true);
              b.set_have_lost_consistency(true);
            }
          }
        } _{_status, o._status};
        strong_placement(_.all_good, temp_error, _error);
        strong_placement(_.all_good, temp_value, o._value);
        strong_placement(_.all_good, o._error, temp_error);
        strong_placement(_.all_good, _value, temp_value);
        swap(_status, o._status);
        return;
      }
      // Should never reach here
      make_ub(_value);
    }
  };
  template <class Base> struct value_storage_delete_copy_constructor : Base  // NOLINT
  {
    using Base::Base;
    using value_type = typename Base::value_type;
    using error_type = typename Base::error_type;
    value_storage_delete_copy_constructor() = default;
    value_storage_delete_copy_constructor(const value_storage_delete_copy_constructor &) = delete;
    value_storage_delete_copy_constructor(value_storage_delete_copy_constructor &&) = default;  // NOLINT
  };
  template <class Base> struct value_storage_delete_copy_assignment : Base  // NOLINT
  {
    using Base::Base;
    using value_type = typename Base::value_type;
    using error_type = typename Base::error_type;
    value_storage_delete_copy_assignment() = default;
    value_storage_delete_copy_assignment(const value_storage_delete_copy_assignment &) = default;
    value_storage_delete_copy_assignment(value_storage_delete_copy_assignment &&) = default;  // NOLINT
    value_storage_delete_copy_assignment &operator=(const value_storage_delete_copy_assignment &o) = delete;
    value_storage_delete_copy_assignment &operator=(value_storage_delete_copy_assignment &&o) = default;  // NOLINT
  };
  template <class Base> struct value_storage_delete_move_assignment : Base  // NOLINT
  {
    using Base::Base;
    using value_type = typename Base::value_type;
    using error_type = typename Base::error_type;
    value_storage_delete_move_assignment() = default;
    value_storage_delete_move_assignment(const value_storage_delete_move_assignment &) = default;
    value_storage_delete_move_assignment(value_storage_delete_move_assignment &&) = default;  // NOLINT
    value_storage_delete_move_assignment &operator=(const value_storage_delete_move_assignment &o) = default;
    value_storage_delete_move_assignment &operator=(value_storage_delete_move_assignment &&o) = delete;
  };
  template <class Base> struct value_storage_delete_move_constructor : Base  // NOLINT
  {
    using Base::Base;
    using value_type = typename Base::value_type;
    using error_type = typename Base::error_type;
    value_storage_delete_move_constructor() = default;
    value_storage_delete_move_constructor(const value_storage_delete_move_constructor &) = default;
    value_storage_delete_move_constructor(value_storage_delete_move_constructor &&) = delete;
  };
  template <class Base> struct value_storage_nontrivial_move_assignment : Base  // NOLINT
  {
    using Base::Base;
    using value_type = typename Base::value_type;
    using error_type = typename Base::error_type;
    value_storage_nontrivial_move_assignment() = default;
    value_storage_nontrivial_move_assignment(const value_storage_nontrivial_move_assignment &) = default;
    value_storage_nontrivial_move_assignment(value_storage_nontrivial_move_assignment &&) = default;  // NOLINT
    value_storage_nontrivial_move_assignment &operator=(const value_storage_nontrivial_move_assignment &o) = default;
    value_storage_nontrivial_move_assignment &operator=(value_storage_nontrivial_move_assignment &&o) noexcept(std::is_nothrow_move_assignable<value_type>::value &&std::is_nothrow_move_assignable<error_type>::value)  // NOLINT
    {
      if(!this->_status.have_value() && !this->_status.have_error() && !o._status.have_value() && !o._status.have_error())
      {
        this->_status = o._status;
        o._status.set_have_moved_from(true);
        return *this;
      }
      if(this->_status.have_value() && o._status.have_value())
      {
        this->_value = static_cast<value_type &&>(o._value);  // NOLINT
        this->_status = o._status;
        o._status.set_have_moved_from(true);
        return *this;
      }
      if(this->_status.have_error() && o._status.have_error())
      {
        this->_error = static_cast<error_type &&>(o._error);  // NOLINT
        this->_status = o._status;
        o._status.set_have_moved_from(true);
        return *this;
      }
      if(this->_status.have_value() && !o._status.have_value() && !o._status.have_error())
      {
        if(!trait::is_move_relocating<value_type>::value || this->_status.have_moved_from())
        {
          this->_value.~value_type();  // NOLINT
        }
        this->_status = o._status;
        o._status.set_have_moved_from(true);
        return *this;
      }
      if(!this->_status.have_value() && !this->_status.have_error() && o._status.have_value())
      {
        new(&this->_value) value_type(static_cast<value_type &&>(o._value));  // NOLINT
        this->_status = o._status;
        o._status.set_have_moved_from(true);
        return *this;
      }
      if(this->_status.have_error() && !o._status.have_value() && !o._status.have_error())
      {
        if(!trait::is_move_relocating<error_type>::value || this->_status.have_moved_from())
        {
          this->_error.~error_type();  // NOLINT
        }
        this->_status = o._status;
        o._status.set_have_moved_from(true);
        return *this;
      }
      if(!this->_status.have_value() && !this->_status.have_error() && o._status.have_error())
      {
        new(&this->_error) error_type(static_cast<error_type &&>(o._error));  // NOLINT
        this->_status = o._status;
        o._status.set_have_moved_from(true);
        return *this;
      }
      if(this->_status.have_value() && o._status.have_error())
      {
        if(!trait::is_move_relocating<value_type>::value || this->_status.have_moved_from())
        {
          this->_value.~value_type();  // NOLINT
        }
        new(&this->_error) error_type(static_cast<error_type &&>(o._error));  // NOLINT
        this->_status = o._status;
        o._status.set_have_moved_from(true);
        return *this;
      }
      if(this->_status.have_error() && o._status.have_value())
      {
        if(!trait::is_move_relocating<error_type>::value || this->_status.have_moved_from())
        {
          this->_error.~error_type();  // NOLINT
        }
        new(&this->_value) value_type(static_cast<value_type &&>(o._value));  // NOLINT
        this->_status = o._status;
        o._status.set_have_moved_from(true);
        return *this;
      }
      // Should never reach here
      make_ub(this->_value);
    }
  };
  template <class Base> struct value_storage_nontrivial_copy_assignment : Base  // NOLINT
  {
    using Base::Base;
    using value_type = typename Base::value_type;
    using error_type = typename Base::error_type;
    value_storage_nontrivial_copy_assignment() = default;
    value_storage_nontrivial_copy_assignment(const value_storage_nontrivial_copy_assignment &) = default;
    value_storage_nontrivial_copy_assignment(value_storage_nontrivial_copy_assignment &&) = default;              // NOLINT
    value_storage_nontrivial_copy_assignment &operator=(value_storage_nontrivial_copy_assignment &&o) = default;  // NOLINT
    value_storage_nontrivial_copy_assignment &operator=(const value_storage_nontrivial_copy_assignment &o) noexcept(std::is_nothrow_copy_assignable<value_type>::value &&std::is_nothrow_copy_assignable<error_type>::value)
    {
      if(!this->_status.have_value() && !this->_status.have_error() && !o._status.have_value() && !o._status.have_error())
      {
        this->_status = o._status;
        return *this;
      }
      if(this->_status.have_value() && o._status.have_value())
      {
        this->_value = o._value;  // NOLINT
        this->_status = o._status;
        return *this;
      }
      if(this->_status.have_error() && o._status.have_error())
      {
        this->_error = o._error;  // NOLINT
        this->_status = o._status;
        return *this;
      }
      if(this->_status.have_value() && !o._status.have_value() && !o._status.have_error())
      {
        if(!trait::is_move_relocating<value_type>::value || this->_status.have_moved_from())
        {
          this->_value.~value_type();  // NOLINT
        }
        this->_status = o._status;
        return *this;
      }
      if(!this->_status.have_value() && !this->_status.have_error() && o._status.have_value())
      {
        new(&this->_value) value_type(o._value);  // NOLINT
        this->_status = o._status;
        return *this;
      }
      if(this->_status.have_error() && !o._status.have_value() && !o._status.have_error())
      {
        if(!trait::is_move_relocating<error_type>::value || this->_status.have_moved_from())
        {
          this->_error.~error_type();  // NOLINT
        }
        this->_status = o._status;
        return *this;
      }
      if(!this->_status.have_value() && !this->_status.have_error() && o._status.have_error())
      {
        new(&this->_error) error_type(o._error);  // NOLINT
        this->_status = o._status;
        return *this;
      }
      if(this->_status.have_value() && o._status.have_error())
      {
        if(!trait::is_move_relocating<value_type>::value || this->_status.have_moved_from())
        {
          this->_value.~value_type();  // NOLINT
        }
        new(&this->_error) error_type(o._error);  // NOLINT
        this->_status = o._status;
        return *this;
      }
      if(this->_status.have_error() && o._status.have_value())
      {
        if(!trait::is_move_relocating<error_type>::value || this->_status.have_moved_from())
        {
          this->_error.~error_type();  // NOLINT
        }
        new(&this->_value) value_type(o._value);  // NOLINT
        this->_status = o._status;
        return *this;
      }
      // Should never reach here
      make_ub(this->_value);
    }
  };
#ifdef _MSC_VER
#pragma warning(pop)
#endif

  // We don't actually need all of std::is_trivial<>, std::is_trivially_copyable<> is sufficient
  template <class T, class E> using value_storage_select_trivality = std::conditional_t<std::is_trivially_copyable<devoid<T>>::value && std::is_trivially_copyable<devoid<E>>::value, value_storage_trivial<T, E>, value_storage_nontrivial<T, E>>;
  template <class T, class E> using value_storage_select_move_constructor = std::conditional_t<std::is_move_constructible<devoid<T>>::value && std::is_move_constructible<devoid<E>>::value, value_storage_select_trivality<T, E>, value_storage_delete_move_constructor<value_storage_select_trivality<T, E>>>;
  template <class T, class E> using value_storage_select_copy_constructor = std::conditional_t<std::is_copy_constructible<devoid<T>>::value && std::is_copy_constructible<devoid<E>>::value, value_storage_select_move_constructor<T, E>, value_storage_delete_copy_constructor<value_storage_select_move_constructor<T, E>>>;
  template <class T, class E>
  using value_storage_select_move_assignment =
  std::conditional_t<std::is_trivially_move_assignable<devoid<T>>::value && std::is_trivially_move_assignable<devoid<E>>::value, value_storage_select_copy_constructor<T, E>,
                     std::conditional_t<std::is_move_assignable<devoid<T>>::value && std::is_move_assignable<devoid<E>>::value, value_storage_nontrivial_move_assignment<value_storage_select_copy_constructor<T, E>>, value_storage_delete_copy_assignment<value_storage_select_copy_constructor<T, E>>>>;
  template <class T, class E>
  using value_storage_select_copy_assignment =
  std::conditional_t<std::is_trivially_copy_assignable<devoid<T>>::value && std::is_trivially_copy_assignable<devoid<E>>::value, value_storage_select_move_assignment<T, E>,
                     std::conditional_t<std::is_copy_assignable<devoid<T>>::value && std::is_copy_assignable<devoid<E>>::value, value_storage_nontrivial_copy_assignment<value_storage_select_move_assignment<T, E>>, value_storage_delete_copy_assignment<value_storage_select_move_assignment<T, E>>>>;
  template <class T, class E> using value_storage_select_impl = value_storage_select_copy_assignment<T, E>;
#ifndef NDEBUG
  // Check is trivial in all ways except default constructibility
  // static_assert(std::is_trivial<value_storage_select_impl<int, long>>::value, "value_storage_select_impl<int, long> is not trivial!");
  // static_assert(std::is_trivially_default_constructible<value_storage_select_impl<int, long>>::value, "value_storage_select_impl<int, long> is not trivially default constructible!");
  static_assert(std::is_trivially_copyable<value_storage_select_impl<int, long>>::value, "value_storage_select_impl<int, long> is not trivially copyable!");
  static_assert(std::is_trivially_assignable<value_storage_select_impl<int, long>, value_storage_select_impl<int, long>>::value, "value_storage_select_impl<int, long> is not trivially assignable!");
  static_assert(std::is_trivially_destructible<value_storage_select_impl<int, long>>::value, "value_storage_select_impl<int, long> is not trivially destructible!");
  static_assert(std::is_trivially_copy_constructible<value_storage_select_impl<int, long>>::value, "value_storage_select_impl<int, long> is not trivially copy constructible!");
  static_assert(std::is_trivially_move_constructible<value_storage_select_impl<int, long>>::value, "value_storage_select_impl<int, long> is not trivially move constructible!");
  static_assert(std::is_trivially_copy_assignable<value_storage_select_impl<int, long>>::value, "value_storage_select_impl<int, long> is not trivially copy assignable!");
  static_assert(std::is_trivially_move_assignable<value_storage_select_impl<int, long>>::value, "value_storage_select_impl<int, long> is not trivially move assignable!");
  // Also check is standard layout
  static_assert(std::is_standard_layout<value_storage_select_impl<int, long>>::value, "value_storage_select_impl<int, long> is not a standard layout type!");
#endif
}  // namespace detail

OUTCOME_V2_NAMESPACE_END

#endif
