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
  // For T <=> U, nothrow
  template <class T, bool T_nothrow, class U, bool U_nothrow> struct strong_swap_impl
  {
    constexpr strong_swap_impl(bool &allgood, T &destA, T &srcA, U &destB, U &srcB)
    {
      allgood = true;
      T _a(static_cast<T &&>(srcA));
      U _b(static_cast<U &&>(srcB));
      srcA.~T();
      srcB.~U();
      new(&destA) T(static_cast<T &&>(_a));
      new(&destB) U(static_cast<U &&>(_b));
    }
  };
  // For T <=> T, nothrow
  template <class T, bool T_nothrow, bool U_nothrow> struct strong_swap_impl<T, T_nothrow, T, U_nothrow>
  {
    constexpr strong_swap_impl(bool &allgood, T &a, T &b)
    {
      allgood = true;
      using std::swap;
      swap(a, b);
    }
  };
#ifdef __cpp_exceptions
  // For T <=> T, throwing
  template <class T> struct strong_swap_impl<T, false, T, false>
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
  // Common implementation for the throwing heterogeneous strong swap
  template <class T, class U> struct strong_swap_throwing_impl
  {
    strong_swap_throwing_impl(bool &allgood, T &destA, T &srcA, U &destB, U &srcB)
    {
      allgood = true;
      bool donotrestore = false;
      T _a(static_cast<T &&>(srcA));
      try
      {
        U _b(static_cast<U &&>(srcB));
        // srcA has been moved to _a, srcB has been moved to _b, destroy the originals
        srcA.~T();
        srcB.~U();
        donotrestore = true;
        // Move _a to destA
        try
        {
          new(&destA) T(static_cast<T &&>(_a));
        }
        catch(...)
        {
          // Try to put _a and _b back to src
          try
          {
            new(&srcA) T(static_cast<T &&>(_a));
          }
          catch(...)
          {
            // failed to completely restore
            allgood = false;
            // throw away second exception
          }
          try
          {
            new(&srcB) U(static_cast<U &&>(_b));
          }
          catch(...)
          {
            // failed to completely restore
            allgood = false;
            // throw away second exception
          }
          throw;  // rethrow original exception
        }
        // Move _b to destB
        try
        {
          new(&destB) U(static_cast<U &&>(_b));
        }
        catch(...)
        {
          // Put destA back to _a, then try to put _a and _b back to src
          try
          {
            _a = static_cast<T &&>(destA);
            destA.~T();
          }
          catch(...)
          {
            // failed to completely restore
            allgood = false;
            // throw away second exception
          }
          try
          {
            new(&srcA) T(static_cast<T &&>(_a));
          }
          catch(...)
          {
            // failed to completely restore
            allgood = false;
            // throw away second exception
          }
          try
          {
            new(&srcB) U(static_cast<U &&>(_b));
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
      catch(...)
      {
        if(!donotrestore)
        {
          // Try to put back a
          try
          {
            srcA = static_cast<T &&>(_a);
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
    }
  };
  // For T <=> U, T's swap is throwing, U's swap is non-throwing
  template <class T, class U> struct strong_swap_impl<T, false, U, true> : strong_swap_throwing_impl<T, U>
  {
    constexpr strong_swap_impl(bool &allgood, T &destA, T &srcA, U &destB, U &srcB)
        : strong_swap_throwing_impl<T, U>(allgood, destA, srcA, destB, srcB)
    {
    }
  };
  // For T <=> U, T's swap is non-throwing, U's swap is throwing
  template <class T, class U> struct strong_swap_impl<T, true, U, false> : strong_swap_throwing_impl<T, U>
  {
    constexpr strong_swap_impl(bool &allgood, T &destA, T &srcA, U &destB, U &srcB)
        : strong_swap_throwing_impl<T, U>(allgood, destA, srcA, destB, srcB)
    {
    }
  };
  // For T <=> U, T's swap is throwing, U's swap is throwing
  template <class T, class U> struct strong_swap_impl<T, false, U, false> : strong_swap_throwing_impl<T, U>
  {
    constexpr strong_swap_impl(bool &allgood, T &destA, T &srcA, U &destB, U &srcB)
        : strong_swap_throwing_impl<T, U>(allgood, destA, srcA, destB, srcB)
    {
    }
  };
#endif
}  // namespace detail

/*!
 */
OUTCOME_TEMPLATE(class T) OUTCOME_TREQUIRES(OUTCOME_TPRED(std::is_move_constructible<T>::value &&std::is_move_assignable<T>::value)) constexpr inline void strong_swap(bool &allgood, T &a, T &b) noexcept(detail::is_nothrow_swappable<T>::value)
{
  detail::strong_swap_impl<T, detail::is_nothrow_swappable<T>::value, T, detail::is_nothrow_swappable<T>::value>(allgood, a, b);
}

/*!
 */
OUTCOME_TEMPLATE(class T, class U)
OUTCOME_TREQUIRES(OUTCOME_TPRED(std::is_move_constructible<T>::value &&std::is_move_assignable<T>::value &&std::is_move_constructible<U>::value &&std::is_move_assignable<U>::value))
constexpr inline void strong_swap(bool &allgood, T &destA, T &srcA, U &destB, U &srcB) noexcept(detail::is_nothrow_swappable<T>::value &&detail::is_nothrow_swappable<U>::value)
{
  detail::strong_swap_impl<T, detail::is_nothrow_swappable<T>::value, U, detail::is_nothrow_swappable<U>::value>(allgood, destA, srcA, destB, srcB);
}

namespace detail
{
  using status_bitfield_type = uint32_t;

  // WARNING: These bits are not tracked by abi-dumper, but changing them will break ABI!
  static constexpr status_bitfield_type status_have_value = (1U << 0U);
  static constexpr status_bitfield_type status_have_error = (1U << 1U);
  static constexpr status_bitfield_type status_have_exception = (1U << 2U);
  static constexpr status_bitfield_type status_lost_consistency = (1U << 3U);  // failed to complete a strong swap
  static constexpr status_bitfield_type status_error_is_errno = (1U << 4U);    // can errno be set from this error?
  static constexpr status_bitfield_type status_is_moved_from = (1U << 5U);     // has been moved from
  // bits 6-15 unused
  static constexpr status_bitfield_type status_srconly_mask = (0x00ffU);
  // bits 16-31 used for user supplied 16 bit value
  static constexpr status_bitfield_type status_2byte_shift = 16;
  static constexpr status_bitfield_type status_2byte_mask = (0xffffU << status_2byte_shift);

  // Used if both T and E are trivial
  template <class T, class E> struct value_storage_trivial
  {
    using value_storage_type = value_storage_trivial;
    struct disable_in_place_value_type
    {
    };
    struct disable_in_place_error_type
    {
    };

    using value_type = T;
    using error_type = E;
    using _value_type = std::conditional_t<std::is_same<T, E>::value, disable_in_place_value_type, T>;
    using _error_type = std::conditional_t<std::is_same<T, E>::value, disable_in_place_error_type, E>;
    using _value_type_ = devoid<_value_type>;
    using _error_type_ = devoid<_error_type>;

    union {
      empty_type _empty;
      _value_type_ _value;
      _error_type_ _error;
    };
    status_bitfield_type _status{0};
    constexpr value_storage_trivial() noexcept
        : _empty{}
    {
    }
    value_storage_trivial(const value_storage_trivial &) = default;             // NOLINT
    value_storage_trivial(value_storage_trivial &&) = default;                  // NOLINT
    value_storage_trivial &operator=(const value_storage_trivial &) = default;  // NOLINT
    value_storage_trivial &operator=(value_storage_trivial &&) = default;       // NOLINT
    ~value_storage_trivial() = default;
    constexpr explicit value_storage_trivial(status_bitfield_type status)
        : _empty()
        , _status(status & status_srconly_mask)
    {
    }
    constexpr explicit value_storage_trivial(in_place_type_t<_value_type> /*unused*/, void_type /*unused*/) noexcept(std::is_nothrow_default_constructible<value_type>::value)
        : _value()
        , _status(status_have_value)
    {
    }
    constexpr explicit value_storage_trivial(in_place_type_t<_error_type> /*unused*/, void_type /*unused*/) noexcept(std::is_nothrow_default_constructible<error_type>::value)
        : _error()
        , _status(status_have_error)
    {
    }
    template <class... Args>
    constexpr explicit value_storage_trivial(in_place_type_t<_value_type> /*unused*/, Args &&... args) noexcept(std::is_nothrow_constructible<value_type, Args...>::value)
        : _value(static_cast<Args &&>(args)...)
        , _status(status_have_value)
    {
    }
    template <class U, class... Args>
    constexpr value_storage_trivial(in_place_type_t<_value_type> /*unused*/, std::initializer_list<U> il, Args &&... args) noexcept(std::is_nothrow_constructible<value_type, std::initializer_list<U>, Args...>::value)
        : _value(il, static_cast<Args &&>(args)...)
        , _status(status_have_value)
    {
    }
    template <class... Args>
    constexpr explicit value_storage_trivial(in_place_type_t<_error_type> /*unused*/, Args &&... args) noexcept(std::is_nothrow_constructible<error_type, Args...>::value)
        : _error(static_cast<Args &&>(args)...)
        , _status(status_have_error)
    {
    }
    template <class U, class... Args>
    constexpr value_storage_trivial(in_place_type_t<_error_type> /*unused*/, std::initializer_list<U> il, Args &&... args) noexcept(std::is_nothrow_constructible<error_type, std::initializer_list<U>, Args...>::value)
        : _error(il, static_cast<Args &&>(args)...)
        , _status(status_have_error)
    {
    }

    template <class U, class V>
    static constexpr bool enable_converting_constructor =                                                     //
    (!std::is_same<std::decay_t<U>, value_type>::value || !std::is_same<std::decay_t<V>, error_type>::value)  //
    && (std::is_void<U>::value || std::is_constructible<value_type, U>::value) && (std::is_void<V>::value || std::is_constructible<error_type, V>::value);

    OUTCOME_TEMPLATE(class U, class V)
    OUTCOME_TREQUIRES(OUTCOME_TPRED(enable_converting_constructor<U, V>))
    constexpr explicit value_storage_trivial(const value_storage_trivial<U, V> &o) noexcept(std::is_nothrow_constructible<value_type, U>::value &&std::is_nothrow_constructible<error_type, V>::value)
        : value_storage_trivial(((o._status & status_have_value) != 0) ? value_storage_trivial(in_place_type<value_type>, o._value) : (((o._status & status_have_error) != 0) ? value_storage_trivial(in_place_type<error_type>, o._error) : value_storage_trivial()))  // NOLINT
    {
      _status = o._status;
    }
    OUTCOME_TEMPLATE(class U, class V)
    OUTCOME_TREQUIRES(OUTCOME_TPRED(enable_converting_constructor<U, V>))
    constexpr explicit value_storage_trivial(value_storage_trivial<U, V> &&o) noexcept(std::is_nothrow_constructible<value_type, U>::value &&std::is_nothrow_constructible<error_type, V>::value)
        : value_storage_trivial(((o._status & status_have_value) != 0) ? value_storage_trivial(in_place_type<value_type>, static_cast<devoid<U> &&>(o._value)) :
                                                                         (((o._status & status_have_error) != 0) ? value_storage_trivial(in_place_type<error_type>, static_cast<devoid<V> &&>(o._error)) : value_storage_trivial()))  // NOLINT
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
  // Used if either T or E is non-trivial
  template <class T, class E> struct value_storage_nontrivial
  {
    using value_storage_type = value_storage_nontrivial;
    struct disable_in_place_value_type
    {
    };
    struct disable_in_place_error_type
    {
    };

    using value_type = T;
    using error_type = E;
    using _value_type = std::conditional_t<std::is_same<T, E>::value, disable_in_place_value_type, T>;
    using _error_type = std::conditional_t<std::is_same<T, E>::value, disable_in_place_error_type, E>;
    using _value_type_ = devoid<_value_type>;
    using _error_type_ = devoid<_error_type>;

    union {
      empty_type _empty;
      _value_type_ _value;
      _error_type_ _error;
    };
    status_bitfield_type _status{0};
    value_storage_nontrivial() noexcept
        : _empty{}
    {
    }
    value_storage_nontrivial(value_storage_nontrivial &&o) noexcept(std::is_nothrow_move_constructible<value_type>::value &&std::is_nothrow_move_constructible<error_type>::value)  // NOLINT
        : _status(o._status)
    {
      if(this->_status & status_have_value)
      {
        this->_status &= ~status_have_value;
        new(&_value) _value_type_(static_cast<_value_type_ &&>(o._value));  // NOLINT
        _status = o._status;
      }
      else if(this->_status & status_have_error)
      {
        this->_status &= ~status_have_error;
        new(&_error) _error_type_(static_cast<_error_type_ &&>(o._error));  // NOLINT
        _status = o._status;
      }
      o._status |= status_is_moved_from;
    }
    value_storage_nontrivial(const value_storage_nontrivial &o) noexcept(std::is_nothrow_copy_constructible<value_type>::value &&std::is_nothrow_copy_constructible<error_type>::value)
        : _status(o._status)
    {
      if(this->_status & status_have_value)
      {
        this->_status &= ~status_have_value;
        new(&_value) _value_type_(o._value);  // NOLINT
        _status = o._status;
      }
      else if(this->_status & status_have_error)
      {
        this->_status &= ~status_have_error;
        new(&_error) _error_type_(o._error);  // NOLINT
        _status = o._status;
      }
    }
    // Special from-void constructor, constructs default T if void valued
    explicit value_storage_nontrivial(const value_storage_trivial<void, E> &o) noexcept(std::is_nothrow_default_constructible<value_type>::value)
        : _status(o._status)
    {
      if(this->_status & status_have_value)
      {
        this->_status &= ~status_have_value;
        new(&_value) _value_type_;  // NOLINT
        _status = o._status;
      }
      else if(this->_status & status_have_error)
      {
        this->_status &= ~status_have_error;
        new(&_error) _error_type_(o._error);  // NOLINT
        _status = o._status;
      }
    }
    // Special from-void constructor, constructs default E if void errored
    explicit value_storage_nontrivial(const value_storage_trivial<T, void> &o) noexcept(std::is_nothrow_default_constructible<error_type>::value)
        : _status(o._status)
    {
      if(this->_status & status_have_value)
      {
        this->_status &= ~status_have_value;
        new(&_value) _value_type_(o._value);  // NOLINT
        _status = o._status;
      }
      else if(this->_status & status_have_error)
      {
        this->_status &= ~status_have_error;
        new(&_error) _error_type_;  // NOLINT
        _status = o._status;
      }
    }
    explicit value_storage_nontrivial(status_bitfield_type status)
        : _empty()
        , _status(status)
    {
    }
    template <class... Args>
    explicit value_storage_nontrivial(in_place_type_t<_value_type> /*unused*/, Args &&... args) noexcept(std::is_nothrow_constructible<value_type, Args...>::value)
        : _value(static_cast<Args &&>(args)...)  // NOLINT
        , _status(status_have_value)
    {
    }
    template <class U, class... Args>
    value_storage_nontrivial(in_place_type_t<_value_type> /*unused*/, std::initializer_list<U> il, Args &&... args) noexcept(std::is_nothrow_constructible<value_type, std::initializer_list<U>, Args...>::value)
        : _value(il, static_cast<Args &&>(args)...)
        , _status(status_have_value)
    {
    }
    template <class... Args>
    constexpr explicit value_storage_nontrivial(in_place_type_t<_error_type> /*unused*/, Args &&... args) noexcept(std::is_nothrow_constructible<error_type, Args...>::value)
        : _error(static_cast<Args &&>(args)...)
        , _status(status_have_error)
    {
    }
    template <class U, class... Args>
    constexpr value_storage_nontrivial(in_place_type_t<_error_type> /*unused*/, std::initializer_list<U> il, Args &&... args) noexcept(std::is_nothrow_constructible<error_type, std::initializer_list<U>, Args...>::value)
        : _error(il, static_cast<Args &&>(args)...)
        , _status(status_have_error)
    {
    }

    template <class U, class V>
    static constexpr bool enable_converting_constructor =                                                     //
    (!std::is_same<std::decay_t<U>, value_type>::value || !std::is_same<std::decay_t<V>, error_type>::value)  //
    && std::is_constructible<value_type, U>::value &&std::is_constructible<error_type, V>::value;
    OUTCOME_TEMPLATE(class U, class V)
    OUTCOME_TREQUIRES(OUTCOME_TPRED(enable_converting_constructor<U, V>))
    constexpr explicit value_storage_nontrivial(const value_storage_trivial<U, V> &o) noexcept(std::is_nothrow_constructible<value_type, U>::value &&std::is_nothrow_constructible<error_type, V>::value)
        : value_storage_nontrivial(((o._status & status_have_value) != 0) ? value_storage_nontrivial(in_place_type<value_type>, o._value) : (((o._status & status_have_error) != 0) ? value_storage_nontrivial(in_place_type<error_type>, o._error) : value_storage_nontrivial()))  // NOLINT
    {
      _status = o._status;
    }
    OUTCOME_TEMPLATE(class U, class V)
    OUTCOME_TREQUIRES(OUTCOME_TPRED(enable_converting_constructor<U, V>))
    constexpr explicit value_storage_nontrivial(value_storage_trivial<U, V> &&o) noexcept(std::is_nothrow_constructible<value_type, U>::value &&std::is_nothrow_constructible<error_type, V>::value)
        : value_storage_nontrivial(((o._status & status_have_value) != 0) ? value_storage_nontrivial(in_place_type<value_type>, static_cast<U &&>(o._value)) :
                                                                            (((o._status & status_have_error) != 0) ? value_storage_nontrivial(in_place_type<error_type>, static_cast<V &&>(o._error)) : value_storage_nontrivial()))  // NOLINT
    {
      _status = o._status;
    }
    OUTCOME_TEMPLATE(class U, class V)
    OUTCOME_TREQUIRES(OUTCOME_TPRED(enable_converting_constructor<U, V>))
    constexpr explicit value_storage_nontrivial(const value_storage_nontrivial<U, V> &o) noexcept(std::is_nothrow_constructible<value_type, U>::value &&std::is_nothrow_constructible<error_type, V>::value)
        : value_storage_nontrivial(((o._status & status_have_value) != 0) ? value_storage_nontrivial(in_place_type<value_type>, o._value) : (((o._status & status_have_error) != 0) ? value_storage_nontrivial(in_place_type<error_type>, o._error) : value_storage_nontrivial()))  // NOLINT
    {
      _status = o._status;
    }
    OUTCOME_TEMPLATE(class U, class V)
    OUTCOME_TREQUIRES(OUTCOME_TPRED(enable_converting_constructor<U, V>))
    constexpr explicit value_storage_nontrivial(value_storage_nontrivial<U, V> &&o) noexcept(std::is_nothrow_constructible<value_type, U>::value &&std::is_nothrow_constructible<error_type, V>::value)
        : value_storage_nontrivial(((o._status & status_have_value) != 0) ? value_storage_nontrivial(in_place_type<value_type>, static_cast<U &&>(o._value)) :
                                                                            (((o._status & status_have_error) != 0) ? value_storage_nontrivial(in_place_type<error_type>, static_cast<V &&>(o._error)) : value_storage_nontrivial()))  // NOLINT
    {
      _status = o._status;
    }
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4127)  // conditional expression is constant
#endif
#if defined(__GNUC__) && defined(OUTCOME_FORCEINLINE)
    OUTCOME_FORCEINLINE  // GCC dislikes inlining this
#endif
    ~value_storage_nontrivial() noexcept(std::is_nothrow_destructible<T>::value)
    {
      if(!std::is_trivially_destructible<_value_type_>::value && this->_status & status_have_value)
      {
        // If not move relocating, or not moved from, call the destructor
        if(!trait::template is_move_relocating<value_type>::value || !(this->_status & status_is_moved_from))
        {
          this->_value.~_value_type_();  // NOLINT
        }
      }
      else if(!std::is_trivially_destructible<_error_type_>::value && this->_status & status_have_error)
      {
        // If not move relocating, or not moved from, call the destructor
        if(!trait::template is_move_relocating<error_type>::value || !(this->_status & status_is_moved_from))
        {
          this->_error.~_error_type_();  // NOLINT
        }
      }
    }
#ifdef _MSC_VER
#pragma warning(pop)
#endif

    value_storage_nontrivial &operator=(value_storage_nontrivial &&o) noexcept(std::is_nothrow_move_constructible<value_type>::value &&std::is_nothrow_move_assignable<value_type>::value &&std::is_nothrow_move_constructible<error_type>::value &&std::is_nothrow_move_assignable<error_type>::value)  // NOLINT
    {
      // empty-empty?
      if((_status & (status_have_value | status_have_error)) == 0 && (o._status & (status_have_value | status_have_error)) == 0)
      {
        _status = o._status;
        o._status |= status_is_moved_from;
        return *this;
      }
      // value-value?
      if((_status & (status_have_value | status_have_error)) == status_have_value && (o._status & (status_have_value | status_have_error)) == status_have_value)
      {
        _value = static_cast<_value_type_ &&>(o._value);
        _status = o._status;
        o._status |= status_is_moved_from;
        return *this;
      }
      // error-error?
      if((_status & (status_have_value | status_have_error)) == status_have_error && (o._status & (status_have_value | status_have_error)) == status_have_error)
      {
        _error = static_cast<_error_type_ &&>(o._error);
        _status = o._status;
        o._status |= status_is_moved_from;
        return *this;
      }
      // Am I empty and the other not empty?
      if((_status & (status_have_value | status_have_error)) == 0 && (o._status & (status_have_value | status_have_error)) != 0)
      {
        if((o._status & (status_have_value | status_have_error)) == status_have_value)
        {
          new(&_value) _value_type_(static_cast<_value_type_ &&>(o._value));  // NOLINT
        }
        else if((o._status & (status_have_value | status_have_error)) == status_have_error)
        {
          new(&_error) _error_type_(static_cast<_error_type_ &&>(o._error));  // NOLINT
        }
        _status = o._status;
        o._status |= status_is_moved_from;
        return *this;
      }
      // Is the other empty and I am not empty?
      if((_status & (status_have_value | status_have_error)) != 0 && (o._status & (status_have_value | status_have_error)) == 0)
      {
        if((_status & (status_have_value | status_have_error)) == status_have_value)
        {
          this->_value.~_value_type_();  // NOLINT
        }
        else if((_status & (status_have_value | status_have_error)) == status_have_error)
        {
          this->_error.~_error_type_();  // NOLINT
        }
        _status = o._status;
        o._status |= status_is_moved_from;
        return *this;
      }
      // value-error?
      if((_status & (status_have_value | status_have_error)) == status_have_value && (o._status & (status_have_value | status_have_error)) == status_have_error)
      {
        this->_value.~_value_type_();                                       // NOLINT
        new(&_error) _error_type_(static_cast<_error_type_ &&>(o._error));  // NOLINT
        _status = o._status;
        o._status |= status_is_moved_from;
        return *this;
      }
      // value-error?
      if((_status & (status_have_value | status_have_error)) == status_have_error && (o._status & (status_have_value | status_have_error)) == status_have_value)
      {
        this->_error.~error_type();                                         // NOLINT
        new(&_value) _value_type_(static_cast<_value_type_ &&>(o._value));  // NOLINT
        _status = o._status;
        o._status |= status_is_moved_from;
        return *this;
      }
      // Did I forget any scenario?
      assert(false);
    }
    value_storage_nontrivial &operator=(const value_storage_nontrivial &o) noexcept(std::is_nothrow_copy_constructible<value_type>::value &&std::is_nothrow_copy_assignable<value_type>::value &&std::is_nothrow_copy_constructible<error_type>::value &&std::is_nothrow_copy_assignable<error_type>::value)
    {
      // empty-empty?
      if((_status & (status_have_value | status_have_error)) == 0 && (o._status & (status_have_value | status_have_error)) == 0)
      {
        _status = o._status;
        return *this;
      }
      // value-value?
      if((_status & (status_have_value | status_have_error)) == status_have_value && (o._status & (status_have_value | status_have_error)) == status_have_value)
      {
        _value = o._value;
        _status = o._status;
        return *this;
      }
      // error-error?
      if((_status & (status_have_value | status_have_error)) == status_have_error && (o._status & (status_have_value | status_have_error)) == status_have_error)
      {
        _error = o._error;
        _status = o._status;
        return *this;
      }
      // Am I empty and the other not empty?
      if((_status & (status_have_value | status_have_error)) == 0 && (o._status & (status_have_value | status_have_error)) != 0)
      {
        if((o._status & (status_have_value | status_have_error)) == status_have_value)
        {
          new(&_value) _value_type_(o._value);  // NOLINT
        }
        else if((o._status & (status_have_value | status_have_error)) == status_have_error)
        {
          new(&_error) _error_type_(o._error);  // NOLINT
        }
        _status = o._status;
        return *this;
      }
      // Is the other empty and I am not empty?
      if((_status & (status_have_value | status_have_error)) != 0 && (o._status & (status_have_value | status_have_error)) == 0)
      {
        if((_status & (status_have_value | status_have_error)) == status_have_value)
        {
          this->_value.~_value_type_();  // NOLINT
        }
        else if((_status & (status_have_value | status_have_error)) == status_have_error)
        {
          this->_error.~_error_type_();  // NOLINT
        }
        _status = o._status;
        return *this;
      }
      // value-error?
      if((_status & (status_have_value | status_have_error)) == status_have_value && (o._status & (status_have_value | status_have_error)) == status_have_error)
      {
        this->_value.~_value_type_();         // NOLINT
        new(&_error) _error_type_(o._error);  // NOLINT
        _status = o._status;
        return *this;
      }
      // value-error?
      if((_status & (status_have_value | status_have_error)) == status_have_error && (o._status & (status_have_value | status_have_error)) == status_have_value)
      {
        this->_error.~_error_type_();         // NOLINT
        new(&_value) _value_type_(o._value);  // NOLINT
        _status = o._status;
        return *this;
      }
      // Did I forget any scenario?
      assert(false);
    }

    constexpr void swap(value_storage_nontrivial &o) noexcept(detail::is_nothrow_swappable<value_type>::value &&detail::is_nothrow_swappable<error_type>::value)
    {
      using std::swap;
      // empty-empty?
      if((_status & (status_have_value | status_have_error)) == 0 && (o._status & (status_have_value | status_have_error)) == 0)
      {
        swap(_status, o._status);
        return;
      }
      // value-value?
      if((_status & (status_have_value | status_have_error)) == status_have_value && (o._status & (status_have_value | status_have_error)) == status_have_value)
      {
        struct _
        {
          unsigned &a, &b;
          bool all_good{false};
          ~_()
          {
            if(!all_good)
            {
              // We lost one of the values
              a |= status_lost_consistency;
              b |= status_lost_consistency;
            }
          }
        } _{_status, o._status};
        strong_swap(_.all_good, _value, o._value);
        swap(_status, o._status);
        return;
      }
      // error-error?
      if((_status & (status_have_value | status_have_error)) == status_have_error && (o._status & (status_have_value | status_have_error)) == status_have_error)
      {
        struct _
        {
          unsigned &a, &b;
          bool all_good{false};
          ~_()
          {
            if(!all_good)
            {
              // We lost one of the values
              a |= status_lost_consistency;
              b |= status_lost_consistency;
            }
          }
        } _{_status, o._status};
        strong_swap(_.all_good, _error, o._error);
        swap(_status, o._status);
        return;
      }
      // Am I empty and the other not empty?
      if((_status & (status_have_value | status_have_error)) == 0 && (o._status & (status_have_value | status_have_error)) != 0)
      {
        if((o._status & (status_have_value | status_have_error)) == status_have_value)
        {
          new(&_value) _value_type_(static_cast<_value_type_ &&>(o._value));  // NOLINT
          o._value.~_value_type_();                                           // NOLINT
        }
        else if((o._status & (status_have_value | status_have_error)) == status_have_error)
        {
          new(&_error) _error_type_(static_cast<_error_type_ &&>(o._error));  // NOLINT
          o._error.~_error_type_();                                           // NOLINT
        }
        swap(_status, o._status);
        return;
      }
      // Is the other empty and I am not empty?
      if((_status & (status_have_value | status_have_error)) != 0 && (o._status & (status_have_value | status_have_error)) == 0)
      {
        if((_status & (status_have_value | status_have_error)) == status_have_value)
        {
          new(&o._value) _value_type_(static_cast<_value_type_ &&>(_value));  // NOLINT
          this->_value.~_value_type_();                                       // NOLINT
        }
        else if((_status & (status_have_value | status_have_error)) == status_have_error)
        {
          new(&o._error) _error_type_(static_cast<_error_type_ &&>(_error));  // NOLINT
          this->_error.~_error_type_();                                       // NOLINT
        }
        swap(_status, o._status);
        return;
      }
      // Temporaries are unavoidable at this point
      // value-error?
      if((_status & (status_have_value | status_have_error)) == status_have_value && (o._status & (status_have_value | status_have_error)) == status_have_error)
      {
        struct _
        {
          unsigned &a, &b;
          bool all_good{false};
          ~_()
          {
            if(!all_good)
            {
              // We lost one of the values
              a |= status_lost_consistency;
              b |= status_lost_consistency;
            }
          }
        } _{_status, o._status};
        strong_swap(_.all_good, o._value, _value, _error, o._error);
        swap(_status, o._status);
        return;
      }
      // error-value?
      if((_status & (status_have_value | status_have_error)) == status_have_error && (o._status & (status_have_value | status_have_error)) == status_have_value)
      {
        struct _
        {
          unsigned &a, &b;
          bool all_good{false};
          ~_()
          {
            if(!all_good)
            {
              // We lost one of the values
              a |= status_lost_consistency;
              b |= status_lost_consistency;
            }
          }
        } _{_status, o._status};
        strong_swap(_.all_good, _value, o._value, o._error, _error);
        swap(_status, o._status);
        return;
      }
      // Did I forget any scenario?
      assert(false);
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
    value_storage_nontrivial_move_assignment &
    operator=(value_storage_nontrivial_move_assignment &&o) noexcept(std::is_nothrow_move_constructible<value_type>::value &&std::is_nothrow_move_assignable<value_type>::value &&std::is_nothrow_move_constructible<error_type>::value &&std::is_nothrow_move_assignable<error_type>::value)  // NOLINT
    {
      // empty-empty?
      if((this->_status & (status_have_value | status_have_error)) == 0 && (o._status & (status_have_value | status_have_error)) == 0)
      {
        this->_value = static_cast<value_type &&>(o._value);  // NOLINT
        this->_status = o._status;
        o._status |= status_is_moved_from;
        return *this;
      }
      // value-value?
      if((this->_status & (status_have_value | status_have_error)) == status_have_value && (o._status & (status_have_value | status_have_error)) == status_have_value)
      {
        this->_value = static_cast<value_type &&>(o._value);  // NOLINT
        this->_status = o._status;
        o._status |= status_is_moved_from;
        return *this;
      }
      // error-error?
      if((this->_status & (status_have_value | status_have_error)) == status_have_error && (o._status & (status_have_value | status_have_error)) == status_have_error)
      {
        this->_error = static_cast<error_type &&>(o._error);  // NOLINT
        this->_status = o._status;
        o._status |= status_is_moved_from;
        return *this;
      }
      // value-empty?
      if((this->_status & (status_have_value | status_have_error)) == status_have_value && (o._status & (status_have_value | status_have_error)) == 0)
      {
        if(!trait::template is_move_relocating<value_type>::value || !(this->_status & status_is_moved_from))
        {
          this->_value.~value_type();  // NOLINT
        }
        this->_status = o._status;
        o._status |= status_is_moved_from;
        return *this;
      }
      // error-empty?
      if((this->_status & (status_have_value | status_have_error)) == status_have_error && (o._status & (status_have_value | status_have_error)) == 0)
      {
        if(!trait::template is_move_relocating<error_type>::value || !(this->_status & status_is_moved_from))
        {
          this->_error.~error_type();  // NOLINT
        }
        this->_status = o._status;
        o._status |= status_is_moved_from;
        return *this;
      }
      // empty-value?
      if((this->_status & (status_have_value | status_have_error)) == 0 && (o._status & (status_have_value | status_have_error)) == status_have_value)
      {
        new(&this->_value) value_type(static_cast<value_type &&>(o._value));  // NOLINT
        this->_status = o._status;
        o._status |= status_is_moved_from;
        return *this;
      }
      // empty-error?
      if((this->_status & (status_have_value | status_have_error)) == 0 && (o._status & (status_have_value | status_have_error)) == status_have_error)
      {
        new(&this->_error) error_type(static_cast<error_type &&>(o._error));  // NOLINT
        this->_status = o._status;
        o._status |= status_is_moved_from;
        return *this;
      }
      // value-error?
      if((this->_status & (status_have_value | status_have_error)) == status_have_value && (o._status & (status_have_value | status_have_error)) == status_have_error)
      {
        if(!trait::template is_move_relocating<value_type>::value || !(this->_status & status_is_moved_from))
        {
          this->_value.~value_type();  // NOLINT
        }
        new(&this->_error) error_type(static_cast<error_type &&>(o._error));  // NOLINT
        this->_status = o._status;
        o._status |= status_is_moved_from;
        return *this;
      }
      // error-value?
      if((this->_status & (status_have_value | status_have_error)) == status_have_error && (o._status & (status_have_value | status_have_error)) == status_have_value)
      {
        if(!trait::template is_move_relocating<error_type>::value || !(this->_status & status_is_moved_from))
        {
          this->_error.~error_type();  // NOLINT
        }
        new(&this->_value) value_type(static_cast<value_type &&>(o._value));  // NOLINT
        this->_status = o._status;
        o._status |= status_is_moved_from;
        return *this;
      }
      assert(false);
      return *this;
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
    value_storage_nontrivial_copy_assignment &
    operator=(const value_storage_nontrivial_copy_assignment &o) noexcept(std::is_nothrow_copy_constructible<value_type>::value &&std::is_nothrow_copy_assignable<value_type>::value &&std::is_nothrow_copy_constructible<error_type>::value &&std::is_nothrow_copy_assignable<error_type>::value)
    {
      // empty-empty?
      if((this->_status & (status_have_value | status_have_error)) == 0 && (o._status & (status_have_value | status_have_error)) == 0)
      {
        this->_value = o._value;  // NOLINT
        this->_status = o._status;
        return *this;
      }
      // value-value?
      if((this->_status & (status_have_value | status_have_error)) == status_have_value && (o._status & (status_have_value | status_have_error)) == status_have_value)
      {
        this->_value = o._value;  // NOLINT
        this->_status = o._status;
        return *this;
      }
      // error-error?
      if((this->_status & (status_have_value | status_have_error)) == status_have_error && (o._status & (status_have_value | status_have_error)) == status_have_error)
      {
        this->_error = o._error;  // NOLINT
        this->_status = o._status;
        return *this;
      }
      // value-empty?
      if((this->_status & (status_have_value | status_have_error)) == status_have_value && (o._status & (status_have_value | status_have_error)) == 0)
      {
        if(!trait::template is_move_relocating<value_type>::value || !(this->_status & status_is_moved_from))
        {
          this->_value.~value_type();  // NOLINT
        }
        this->_status = o._status;
        return *this;
      }
      // error-empty?
      if((this->_status & (status_have_value | status_have_error)) == status_have_error && (o._status & (status_have_value | status_have_error)) == 0)
      {
        if(!trait::template is_move_relocating<error_type>::value || !(this->_status & status_is_moved_from))
        {
          this->_error.~error_type();  // NOLINT
        }
        this->_status = o._status;
        return *this;
      }
      // empty-value?
      if((this->_status & (status_have_value | status_have_error)) == 0 && (o._status & (status_have_value | status_have_error)) == status_have_value)
      {
        new(&this->_value) value_type(o._value);  // NOLINT
        this->_status = o._status;
        return *this;
      }
      // empty-error?
      if((this->_status & (status_have_value | status_have_error)) == 0 && (o._status & (status_have_value | status_have_error)) == status_have_error)
      {
        new(&this->_error) error_type(o._error);  // NOLINT
        this->_status = o._status;
        return *this;
      }
      // value-error?
      if((this->_status & (status_have_value | status_have_error)) == status_have_value && (o._status & (status_have_value | status_have_error)) == status_have_error)
      {
        if(!trait::template is_move_relocating<value_type>::value || !(this->_status & status_is_moved_from))
        {
          this->_value.~value_type();  // NOLINT
        }
        new(&this->_error) error_type(o._error);  // NOLINT
        this->_status = o._status;
        return *this;
      }
      // error-value?
      if((this->_status & (status_have_value | status_have_error)) == status_have_error && (o._status & (status_have_value | status_have_error)) == status_have_value)
      {
        if(!trait::template is_move_relocating<error_type>::value || !(this->_status & status_is_moved_from))
        {
          this->_error.~error_type();  // NOLINT
        }
        new(&this->_value) value_type(o._value);  // NOLINT
        this->_status = o._status;
        return *this;
      }
      assert(false);
      return *this;
    }
  };

  // We don't actually need all of std::is_trivial<>, std::is_trivially_copyable<> is sufficient
  template <class T, class E>
  using value_storage_select_trivality =
  std::conditional_t<std::is_trivially_copy_constructible<devoid<T>>::value && std::is_trivially_copyable<devoid<T>>::value && std::is_trivially_copy_constructible<devoid<E>>::value && std::is_trivially_copyable<devoid<E>>::value, value_storage_trivial<T, E>, value_storage_nontrivial<T, E>>;
  template <class T, class E> using value_storage_select_move_constructor = std::conditional_t<std::is_move_constructible<devoid<T>>::value, value_storage_select_trivality<T, E>, value_storage_delete_move_constructor<value_storage_select_trivality<T, E>>>;
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
  // static_assert(std::is_trivial<value_storage_select_impl<int>>::value, "value_storage_select_impl<int> is not trivial!");
  // static_assert(std::is_trivially_default_constructible<value_storage_select_impl<int>>::value, "value_storage_select_impl<int> is not trivially default constructible!");
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
