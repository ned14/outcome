/* Essentially an internal optional implementation :)
(C) 2017 Niall Douglas <http://www.nedproductions.biz/> (59 commits)
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

#include <cstdint>  // for uint32_t etc
#include <initializer_list>
#include <iosfwd>  // for serialisation
#include <type_traits>
#include <utility>  // for in_place_type_t

OUTCOME_V2_NAMESPACE_BEGIN

#if __cplusplus >= 201700
template <class T> using in_place_type_t = std::in_place_type_t<T>;
using std::in_place_type;
#else
//! Aliases `std::in_place_type_t<T>` if on C++ 17 or later, else defined locally.
template <class T> struct in_place_type_t
{
  explicit in_place_type_t() = default;
};
//! Aliases `std::in_place_type<T>` if on C++ 17 or later, else defined locally.
template <class T> constexpr in_place_type_t<T> in_place_type{};
#endif

namespace detail
{
  // Test if type is an in_place_type_t
  template <class T> struct is_in_place_type_t : std::false_type
  {
  };
  template <class U> struct is_in_place_type_t<in_place_type_t<U>> : std::true_type
  {
  };

  // Replace void with constructible void_type
  struct empty_type
  {
  };
  struct void_type
  {
  };
  template <class T> using devoid = std::conditional_t<std::is_void<T>::value, void_type, T>;

  using status_bitfield_type = uint32_t;
  static constexpr status_bitfield_type status_have_value = (1 << 0);
  static constexpr status_bitfield_type status_have_error = (1 << 1);
  static constexpr status_bitfield_type status_have_status = (1 << 2);
  static constexpr status_bitfield_type status_have_payload = (1 << 3);
  static constexpr status_bitfield_type status_have_exception = (1 << 4);
  static constexpr status_bitfield_type status_2byte_shift = 16;
  static constexpr status_bitfield_type status_2byte_mask = (0xffffU << status_2byte_shift);

  // Used if T is trivial
  template <class T> struct value_storage_trivial
  {
    using value_type = T;
    union {
      empty_type _empty;
      devoid<T> _value;
    };
    status_bitfield_type _status;
    constexpr value_storage_trivial() noexcept : _empty{}, _status(0) {}
    explicit constexpr value_storage_trivial(const value_storage_trivial<void> &o) noexcept(std::is_nothrow_default_constructible<value_type>::value)
        : _value()
        , _status(o._status)
    {
    }
    // value_storage_trivial(const value_storage_trivial &) = default;
    // value_storage_trivial(value_storage_trivial &&) = default;
    // value_storage_trivial &operator=(const value_storage_trivial &) = default;
    // value_storage_trivial &operator=(value_storage_trivial &&) = default;
    constexpr explicit value_storage_trivial(status_bitfield_type status)
        : _empty()
        , _status(status)
    {
    }
    template <class... Args>
    constexpr value_storage_trivial(in_place_type_t<value_type>, Args &&... args) noexcept(std::is_nothrow_constructible<value_type, Args...>::value)
        : _value(std::forward<Args>(args)...)
        , _status(status_have_value)
    {
    }
    template <class U, class... Args>
    constexpr value_storage_trivial(in_place_type_t<value_type>, std::initializer_list<U> il, Args &&... args) noexcept(std::is_nothrow_constructible<value_type, std::initializer_list<U>, Args...>::value)
        : _value(il, std::forward<Args>(args)...)
        , _status(status_have_value)
    {
    }
    template <class U> static constexpr bool enable_converting_constructor = !std::is_same<std::decay_t<U>, value_type>::value && std::is_constructible<value_type, U>::value;
    OUTCOME_TEMPLATE(class U)
    OUTCOME_TREQUIRES(OUTCOME_TPRED(enable_converting_constructor<U>))
    constexpr explicit value_storage_trivial(const value_storage_trivial<U> &o) noexcept(std::is_nothrow_constructible<value_type, U>::value)
        : value_storage_trivial(((o._status & status_have_value) != 0) ? value_storage_trivial(in_place_type<value_type>, o._value) : value_storage_trivial())
    {
      _status = o._status;
    }
    OUTCOME_TEMPLATE(class U)
    OUTCOME_TREQUIRES(OUTCOME_TPRED(enable_converting_constructor<U>))
    constexpr explicit value_storage_trivial(value_storage_trivial<U> &&o) noexcept(std::is_nothrow_constructible<value_type, U>::value)
        : value_storage_trivial(((o._status & status_have_value) != 0) ? value_storage_trivial(in_place_type<value_type>, std::move(o._value)) : value_storage_trivial())
    {
      _status = o._status;
    }
    constexpr void swap(value_storage_trivial &o)
    {
      // storage is trivial, so just use assignment
      using std::swap;
      swap(*this, o);
    }
  };
  // Used if T is non-trivial
  template <class T> struct value_storage_nontrivial
  {
    using value_type = T;
    union {
      empty_type _empty;
      value_type _value;
    };
    status_bitfield_type _status;
    value_storage_nontrivial() noexcept : _empty{}, _status(0) {}
    value_storage_nontrivial &operator=(const value_storage_nontrivial &) = default;  // if reaches here, copy assignment is trivial
    value_storage_nontrivial &operator=(value_storage_nontrivial &&) = default;       // if reaches here, move assignment is trivial
    value_storage_nontrivial(value_storage_nontrivial &&o) noexcept(std::is_nothrow_move_constructible<value_type>::value)
        : _status(o._status)
    {
      if(this->_status & status_have_value)
      {
        this->_status &= ~status_have_value;
        new(&_value) value_type(std::move(o._value));
        _status = o._status;
      }
    }
    value_storage_nontrivial(const value_storage_nontrivial &o) noexcept(std::is_nothrow_copy_constructible<value_type>::value)
        : _status(o._status)
    {
      if(this->_status & status_have_value)
      {
        this->_status &= ~status_have_value;
        new(&_value) value_type(o._value);
        _status = o._status;
      }
    }
    explicit value_storage_nontrivial(value_storage_trivial<void> o) noexcept(std::is_nothrow_default_constructible<value_type>::value)
        : _status(o._status)
    {
      if(this->_status & status_have_value)
      {
        this->_status &= ~status_have_value;
        new(&_value) value_type;
        _status = o._status;
      }
    }
    explicit value_storage_nontrivial(status_bitfield_type status)
        : _empty()
        , _status(status)
    {
    }
    template <class... Args>
    value_storage_nontrivial(in_place_type_t<value_type>, Args &&... args) noexcept(std::is_nothrow_constructible<value_type, Args...>::value)
        : _value(std::forward<Args>(args)...)
        , _status(status_have_value)
    {
    }
    template <class U, class... Args>
    value_storage_nontrivial(in_place_type_t<value_type>, std::initializer_list<U> il, Args &&... args) noexcept(std::is_nothrow_constructible<value_type, std::initializer_list<U>, Args...>::value)
        : _value(il, std::forward<Args>(args)...)
        , _status(status_have_value)
    {
    }
    template <class U> static constexpr bool enable_converting_constructor = !std::is_same<std::decay_t<U>, value_type>::value && std::is_constructible<value_type, U>::value;
    OUTCOME_TEMPLATE(class U)
    OUTCOME_TREQUIRES(OUTCOME_TPRED(enable_converting_constructor<U>))
    constexpr explicit value_storage_nontrivial(const value_storage_nontrivial<U> &o) noexcept(std::is_nothrow_constructible<value_type, U>::value)
        : value_storage_nontrivial((o._status & status_have_value) != 0 ? value_storage_nontrivial(in_place_type<value_type>, o._value) : value_storage_nontrivial())
    {
      _status = o._status;
    }
    OUTCOME_TEMPLATE(class U)
    OUTCOME_TREQUIRES(OUTCOME_TPRED(enable_converting_constructor<U>))
    constexpr explicit value_storage_nontrivial(value_storage_nontrivial<U> &&o) noexcept(std::is_nothrow_constructible<value_type, U>::value)
        : value_storage_nontrivial((o._status & status_have_value) != 0 ? value_storage_nontrivial(in_place_type<value_type>, std::move(o._value)) : value_storage_nontrivial())
    {
      _status = o._status;
    }
    ~value_storage_nontrivial() noexcept(std::is_nothrow_destructible<T>::value)
    {
      if(this->_status & status_have_value)
      {
        this->_value.~value_type();
        this->_status &= ~status_have_value;
      }
    }
    constexpr void swap(value_storage_nontrivial &o)
    {
      using std::swap;
      if((_status & status_have_value) == 0 && (o._status & status_have_value) == 0)
      {
        swap(_status, o._status);
        return;
      }
      if((_status & status_have_value) != 0 && (o._status & status_have_value) != 0)
      {
        swap(_value, o._value);
        swap(_status, o._status);
        return;
      }
      // One must be empty and the other non-empty, so use move construction
      if((_status & status_have_value) != 0)
      {
        // Move construct me into other
        new(&o._value) value_type(std::move(_value));
        this->_value.~value_type();
        swap(_status, o._status);
      }
      else
      {
        // Move construct other into me
        new(&_value) value_type(std::move(o._value));
        o._value.~value_type();
        swap(_status, o._status);
      }
    }
  };
  template <class Base> struct value_storage_delete_copy_constructor : Base
  {
    using Base::Base;
    using value_type = typename Base::value_type;
    value_storage_delete_copy_constructor() = default;
    value_storage_delete_copy_constructor(const value_storage_delete_copy_constructor &) = delete;
    value_storage_delete_copy_constructor(value_storage_delete_copy_constructor &&) = default;
  };
  template <class Base> struct value_storage_delete_copy_assignment : Base
  {
    using Base::Base;
    using value_type = typename Base::value_type;
    value_storage_delete_copy_assignment() = default;
    value_storage_delete_copy_assignment(const value_storage_delete_copy_assignment &) = default;
    value_storage_delete_copy_assignment(value_storage_delete_copy_assignment &&) = default;
    value_storage_delete_copy_assignment &operator=(const value_storage_delete_copy_assignment &o) = delete;
    value_storage_delete_copy_assignment &operator=(value_storage_delete_copy_assignment &&o) = default;
  };
  template <class Base> struct value_storage_delete_move_assignment : Base
  {
    using Base::Base;
    using value_type = typename Base::value_type;
    value_storage_delete_move_assignment() = default;
    value_storage_delete_move_assignment(const value_storage_delete_move_assignment &) = default;
    value_storage_delete_move_assignment(value_storage_delete_move_assignment &&) = default;
    value_storage_delete_move_assignment &operator=(const value_storage_delete_move_assignment &o) = default;
    value_storage_delete_move_assignment &operator=(value_storage_delete_move_assignment &&o) = delete;
  };
  template <class Base> struct value_storage_delete_move_constructor : Base
  {
    using Base::Base;
    using value_type = typename Base::value_type;
    value_storage_delete_move_constructor() = default;
    value_storage_delete_move_constructor(const value_storage_delete_move_constructor &) = default;
    value_storage_delete_move_constructor(value_storage_delete_move_constructor &&) = delete;
  };
  template <class Base> struct value_storage_nontrivial_move_assignment : Base
  {
    using Base::Base;
    using value_type = typename Base::value_type;
    value_storage_nontrivial_move_assignment() = default;
    value_storage_nontrivial_move_assignment(const value_storage_nontrivial_move_assignment &) = default;
    value_storage_nontrivial_move_assignment(value_storage_nontrivial_move_assignment &&) = default;
    value_storage_nontrivial_move_assignment &operator=(const value_storage_nontrivial_move_assignment &o) = default;
    value_storage_nontrivial_move_assignment &operator=(value_storage_nontrivial_move_assignment &&o) noexcept(std::is_nothrow_move_assignable<value_type>::value)
    {
      if((this->_status & status_have_value) != 0 && (o._status & status_have_value) != 0)
      {
        this->_value = std::move(o._value);
      }
      else if((this->_status & status_have_value) != 0 && (o._status & status_have_value) == 0)
      {
        this->_value.~value_type();
      }
      else if((this->_status & status_have_value) == 0 && (o._status & status_have_value) != 0)
      {
        new(&this->_value) value_type(std::move(o._value));
      }
      this->_status = o._status;
      return *this;
    }
  };
  template <class Base> struct value_storage_nontrivial_copy_assignment : Base
  {
    using Base::Base;
    using value_type = typename Base::value_type;
    value_storage_nontrivial_copy_assignment() = default;
    value_storage_nontrivial_copy_assignment(const value_storage_nontrivial_copy_assignment &) = default;
    value_storage_nontrivial_copy_assignment(value_storage_nontrivial_copy_assignment &&) = default;
    value_storage_nontrivial_copy_assignment &operator=(value_storage_nontrivial_copy_assignment &&o) = default;
    value_storage_nontrivial_copy_assignment &operator=(const value_storage_nontrivial_copy_assignment &o) noexcept(std::is_nothrow_copy_assignable<value_type>::value)
    {
      if((this->_status & status_have_value) != 0 && (o._status & status_have_value) != 0)
      {
        this->_value = o._value;
      }
      else if((this->_status & status_have_value) != 0 && (o._status & status_have_value) == 0)
      {
        this->_value.~value_type();
      }
      else if((this->_status & status_have_value) == 0 && (o._status & status_have_value) != 0)
      {
        new(&this->_value) value_type(o._value);
      }
      this->_status = o._status;
      return *this;
    }
  };

  // We don't actually need all of std::is_trivial<>, std::is_trivially_copyable<> is sufficient
  template <class T> using value_storage_select_trivality = std::conditional_t<std::is_trivially_copyable<devoid<T>>::value, value_storage_trivial<T>, value_storage_nontrivial<T>>;
  template <class T> using value_storage_select_move_constructor = std::conditional_t<std::is_move_constructible<devoid<T>>::value, value_storage_select_trivality<T>, value_storage_delete_move_constructor<value_storage_select_trivality<T>>>;
  template <class T> using value_storage_select_copy_constructor = std::conditional_t<std::is_copy_constructible<devoid<T>>::value, value_storage_select_move_constructor<T>, value_storage_delete_copy_constructor<value_storage_select_move_constructor<T>>>;
  template <class T>
  using value_storage_select_move_assignment = std::conditional_t<std::is_trivially_move_assignable<devoid<T>>::value, value_storage_select_copy_constructor<T>,
                                                                  std::conditional_t<std::is_move_assignable<devoid<T>>::value, value_storage_nontrivial_move_assignment<value_storage_select_copy_constructor<T>>, value_storage_delete_copy_assignment<value_storage_select_copy_constructor<T>>>>;
  template <class T>
  using value_storage_select_copy_assignment = std::conditional_t<std::is_trivially_copy_assignable<devoid<T>>::value, value_storage_select_move_assignment<T>,
                                                                  std::conditional_t<std::is_copy_assignable<devoid<T>>::value, value_storage_nontrivial_copy_assignment<value_storage_select_move_assignment<T>>, value_storage_delete_copy_assignment<value_storage_select_move_assignment<T>>>>;
  template <class T> using value_storage_select_impl = value_storage_select_copy_assignment<T>;
#ifndef NDEBUG
  // Check is trivial in all ways except default constructibility
  // static_assert(std::is_trivial<value_storage_select_impl<int>>::value, "value_storage_select_impl<int> is not trivial!");
  // static_assert(std::is_trivially_default_constructible<value_storage_select_impl<int>>::value, "value_storage_select_impl<int> is not trivially default constructible!");
  static_assert(std::is_trivially_copyable<value_storage_select_impl<int>>::value, "value_storage_select_impl<int> is not trivially copyable!");
  static_assert(std::is_trivially_assignable<value_storage_select_impl<int>, value_storage_select_impl<int>>::value, "value_storage_select_impl<int> is not trivially assignable!");
  static_assert(std::is_trivially_destructible<value_storage_select_impl<int>>::value, "value_storage_select_impl<int> is not trivially destructible!");
  static_assert(std::is_trivially_copy_constructible<value_storage_select_impl<int>>::value, "value_storage_select_impl<int> is not trivially copy constructible!");
  static_assert(std::is_trivially_move_constructible<value_storage_select_impl<int>>::value, "value_storage_select_impl<int> is not trivially move constructible!");
  static_assert(std::is_trivially_copy_assignable<value_storage_select_impl<int>>::value, "value_storage_select_impl<int> is not trivially copy assignable!");
  static_assert(std::is_trivially_move_assignable<value_storage_select_impl<int>>::value, "value_storage_select_impl<int> is not trivially move assignable!");
  // Also check is standard layout
  static_assert(std::is_standard_layout<value_storage_select_impl<int>>::value, "value_storage_select_impl<int> is not a standard layout type!");
#endif
}

OUTCOME_V2_NAMESPACE_END

#endif
