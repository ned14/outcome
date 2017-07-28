/* A very simple result type
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

#ifndef OUTCOME_RESULT_HPP
#define OUTCOME_RESULT_HPP

#include "detail/value_storage.hpp"
#include "success_failure.hpp"

#ifndef OUTCOME_ENABLE_POSITIVE_STATUS
//! Define to enable positive value + status returns
#define OUTCOME_ENABLE_POSITIVE_STATUS 0
#endif

OUTCOME_V2_NAMESPACE_BEGIN

//! Thrown when you try to access state in a `result<R, S>` which isn't present.
class OUTCOME_SYMBOL_VISIBLE bad_result_access : public std::logic_error
{
public:
  bad_result_access(const char *what)
      : std::logic_error(what)
  {
  }
};

#if OUTCOME_ENABLE_POSITIVE_STATUS
//! Namespace for traits
namespace trait
{
  /*! Trait for whether type `S` is to be considered a negative rather than positive status type.
  \module Error code interpretation policy
  */
  template <class S> struct status_type_is_negative : std::integral_constant<bool, false>
  {
  };
  /*! Trait is enabled for `std::error_code`.
  \module Error code interpretation policy
  */
  template <> struct status_type_is_negative<std::error_code> : std::integral_constant<bool, true>
  {
  };
  /*! Trait is enabled for `std::exception_ptr`.
  \module Error code interpretation policy
  */
  template <> struct status_type_is_negative<std::exception_ptr> : std::integral_constant<bool, true>
  {
  };
  /*! Trait is enabled for `void`.
  \module Error code interpretation policy
  */
  template <> struct status_type_is_negative<void> : std::integral_constant<bool, true>
  {
  };
}
#endif

//! Placeholder type to indicate there is no value type
struct no_value_type
{
  no_value_type() = delete;
};
#if OUTCOME_ENABLE_POSITIVE_STATUS
//! Placeholder type to indicate there is no status type
struct no_status_type
{
  no_status_type() = delete;
};
#endif
//! Placeholder type to indicate there is no error type
struct no_error_type
{
  no_error_type() = delete;
};

namespace detail
{
  // True if type is the same or constructible
  template <class T, class U, class... Args> static constexpr bool is_same_or_constructible = std::is_same<T, U>::value || std::is_constructible<T, U, Args...>::value;
// True if type is nothrow swappable
#if !defined(STANDARDESE_IS_IN_THE_HOUSE) && __cplusplus >= 201700
  template <class T> using is_nothrow_swappable = std::is_nothrow_swappable<T>;
#else
  namespace _is_nothrow_swappable
  {
    using namespace std;
    template <class T> constexpr inline T &ldeclval();
    template <class T> struct is_nothrow_swappable : std::integral_constant<bool, noexcept(swap(ldeclval<T>(), ldeclval<T>()))>
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
}

namespace impl
{
  template <class R, class S, class NoValuePolicy> class result_final;
}
//! Namespace containing hooks used for intercepting and manipulating result/outcome
namespace hooks
{
  template <class R, class S, class NoValuePolicy> constexpr inline uint16_t spare_storage(const impl::result_final<R, S, NoValuePolicy> *r) noexcept;
  template <class R, class S, class NoValuePolicy> constexpr inline void set_spare_storage(impl::result_final<R, S, NoValuePolicy> *r, uint16_t v) noexcept;
}
namespace impl
{
  //! The base implementation type of `result<R, EC, NoValuePolicy>`. Only appears separate due to standardese limitations.
  template <class R, class EC, class NoValuePolicy> OUTCOME_REQUIRES(std::is_void<EC>::value || std::is_default_constructible<EC>::value) class result_storage
  {
    static_assert(std::is_void<EC>::value || std::is_default_constructible<EC>::value, "error_type must be default constructible");

    friend NoValuePolicy;
    template <class T, class U, class V> friend class result_storage;
    template <class T, class U, class V> friend class result_final;
    template <class T, class U, class V> friend constexpr inline uint16_t hooks::spare_storage(const impl::result_final<T, U, V> *r) noexcept;
    template <class T, class U, class V> friend constexpr inline void hooks::set_spare_storage(impl::result_final<T, U, V> *r, uint16_t v) noexcept;

    struct disable_in_place_value_type
    {
    };
    struct disable_in_place_error_type
    {
    };

  protected:
    using _value_type = std::conditional_t<std::is_same<R, EC>::value, disable_in_place_value_type, R>;
    using _error_type = std::conditional_t<std::is_same<R, EC>::value, disable_in_place_error_type, EC>;
#if OUTCOME_ENABLE_POSITIVE_STATUS
    using _status_type = std::conditional_t<std::is_same<R, EC>::value, disable_in_place_error_type, EC>;
#endif

    detail::value_storage_select_impl<_value_type> _state;
    detail::devoid<_error_type> _error;

    result_storage() = default;
    result_storage(const result_storage &) = default;
    result_storage(result_storage &&) = default;
    result_storage &operator=(const result_storage &) = default;
    result_storage &operator=(result_storage &&) = default;

    template <class... Args>
    constexpr result_storage(in_place_type_t<_value_type> _, Args &&... args) noexcept(std::is_nothrow_constructible<_value_type, Args...>::value)
        : _state(_, std::forward<Args>(args)...)
        , _error()
    {
    }
    template <class U, class... Args>
    constexpr result_storage(in_place_type_t<_value_type> _, std::initializer_list<U> il, Args &&... args) noexcept(std::is_nothrow_constructible<_value_type, std::initializer_list<U>, Args...>::value)
        : _state(_, il, std::forward<Args>(args)...)
        , _error()
    {
    }
    template <class... Args>
    constexpr result_storage(in_place_type_t<_error_type>, Args &&... args) noexcept(std::is_nothrow_constructible<_error_type, Args...>::value)
        : _state(detail::status_have_error)
        , _error(std::forward<Args>(args)...)
    {
    }
    template <class U, class... Args>
    constexpr result_storage(in_place_type_t<_error_type>, std::initializer_list<U> il, Args &&... args) noexcept(std::is_nothrow_constructible<_error_type, std::initializer_list<U>, Args...>::value)
        : _state(detail::status_have_error)
        , _error(il, std::forward<Args>(args)...)
    {
    }
#if OUTCOME_ENABLE_POSITIVE_STATUS
    struct value_status_construction_tag
    {
    };
    template <class T, class U>
    constexpr result_storage(value_status_construction_tag, T &&t, U &&u) noexcept(std::is_nothrow_constructible<_value_type, T>::value &&std::is_nothrow_constructible<_status_type, U>::value)
        : _state(in_place_type<_value_type>, std::forward<T>(t))
        , _error(std::forward<U>(u))
    {
      _state._status |= detail::status_have_status;
    }
#endif
    struct compatible_conversion_tag
    {
    };
    template <class T, class U, class V>
    constexpr result_storage(compatible_conversion_tag, const result_storage<T, U, V> &o) noexcept(std::is_nothrow_constructible<_value_type, T>::value &&std::is_nothrow_constructible<_error_type, U>::value)
        : _state(o._state)
        , _error(o._error)
    {
    }
    template <class T, class V>
    constexpr result_storage(compatible_conversion_tag, const result_storage<T, void, V> &o) noexcept(std::is_nothrow_constructible<_value_type, T>::value)
        : _state(o._state)
        , _error(_error_type{})
    {
    }
    template <class T, class U, class V>
    constexpr result_storage(compatible_conversion_tag, result_storage<T, U, V> &&o) noexcept(std::is_nothrow_constructible<_value_type, T>::value &&std::is_nothrow_constructible<_error_type, U>::value)
        : _state(std::move(o._state))
        , _error(std::move(o._error))
    {
    }
    template <class T, class V>
    constexpr result_storage(compatible_conversion_tag, result_storage<T, void, V> &&o) noexcept(std::is_nothrow_constructible<_value_type, T>::value)
        : _state(std::move(o._state))
        , _error(_error_type{})
    {
    }
  };
  //! The value observers implementation of `result<R, EC, NoValuePolicy>`. Only appears separate due to standardese limitations.
  template <class Base, class R, class NoValuePolicy> class result_value_observers : public Base
  {
  public:
    using value_type = R;
    using Base::Base;

    /// \output_section Narrow state observers
    /*! Access value without runtime checks.
    \preconditions The result to have a successful state, otherwise it is undefined behaviour.
    \returns Reference to the held `value_type` according to overload.
    \group assume_value
    */
    constexpr value_type &assume_value() & noexcept
    {
      NoValuePolicy::narrow_value_check(this);
      return this->_state._value;
    }
    /// \group assume_value
    constexpr const value_type &assume_value() const &noexcept
    {
      NoValuePolicy::narrow_value_check(this);
      return this->_state._value;
    }
    /// \group assume_value
    constexpr value_type &&assume_value() && noexcept
    {
      NoValuePolicy::narrow_value_check(this);
      return std::move(this->_state._value);
    }
    /// \group assume_value
    constexpr const value_type &&assume_value() const &&noexcept
    {
      NoValuePolicy::narrow_value_check(this);
      return std::move(this->_state._value);
    }

    /// \output_section Wide state observers
    /*! Access value with runtime checks.
    \returns Reference to the held `value_type` according to overload.
    \requires The result to have a successful state, else whatever `NoValuePolicy` says ought to happen.
    \group value
    */
    constexpr value_type &value() &
    {
      NoValuePolicy::wide_value_check(this);
      return this->_state._value;
    }
    /// \group value
    constexpr const value_type &value() const &
    {
      NoValuePolicy::wide_value_check(this);
      return this->_state._value;
    }
    /// \group value
    constexpr value_type &&value() &&
    {
      NoValuePolicy::wide_value_check(this);
      return std::move(this->_state._value);
    }
    /// \group value
    constexpr const value_type &&value() const &&
    {
      NoValuePolicy::wide_value_check(this);
      return std::move(this->_state._value);
    }
  };
  template <class Base, class NoValuePolicy> class result_value_observers<Base, void, NoValuePolicy> : public Base
  {
  public:
    using Base::Base;

    /// \output_section Narrow state observers
    /*! Access value without runtime checks.
    \returns Nothing.
    */
    constexpr void assume_value() const noexcept { NoValuePolicy::narrow_value_check(this); }
    /// \output_section Wide state observers
    /*! Access value with runtime checks.
    \returns Nothing.
    \requires The result to have a successful state, else whatever `NoValuePolicy` says ought to happen.
    */
    constexpr void value() const { NoValuePolicy::wide_value_check(this); }
  };

  //! The error observers implementation of `result<R, EC, NoValuePolicy>`. Only appears separate due to standardese limitations.
  template <class Base, class EC, class NoValuePolicy> class result_error_observers : public Base
  {
  public:
    using error_type = EC;
    using Base::Base;

    /// \output_section Narrow state observers
    /*! Access error without runtime checks.
    \preconditions The result to have a failed state, otherwise it is undefined behaviour.
    \returns Reference to the held `error_type` according to overload.
    \group assume_error
    */
    constexpr error_type &assume_error() & noexcept
    {
      NoValuePolicy::narrow_error_check(this);
      return this->_error;
    }
    /// \group assume_error
    constexpr const error_type &assume_error() const &noexcept
    {
      NoValuePolicy::narrow_error_check(this);
      return this->_error;
    }
    /// \group assume_error
    constexpr error_type &&assume_error() && noexcept
    {
      NoValuePolicy::narrow_error_check(this);
      return std::move(this->_error);
    }
    /// \group assume_error
    constexpr const error_type &&assume_error() const &&noexcept
    {
      NoValuePolicy::narrow_error_check(this);
      return std::move(this->_error);
    }

    /// \output_section Wide state observers
    /*! Access error with runtime checks.
    \returns Reference to the held `error_type` according to overload.
    \requires The result to have a failed state, else whatever `NoValuePolicy` says ought to happen.
    \group error
    */
    constexpr error_type &error() &
    {
      NoValuePolicy::wide_error_check(this);
      return this->_error;
    }
    /// \group error
    constexpr const error_type &error() const &
    {
      NoValuePolicy::wide_error_check(this);
      return this->_error;
    }
    /// \group error
    constexpr error_type &&error() &&
    {
      NoValuePolicy::wide_error_check(this);
      return std::move(this->_error);
    }
    /// \group error
    constexpr const error_type &&error() const &&
    {
      NoValuePolicy::wide_error_check(this);
      return std::move(this->_error);
    }
  };
  template <class Base, class NoValuePolicy> class result_error_observers<Base, void, NoValuePolicy> : public Base
  {
  public:
    using Base::Base;
    /// \output_section Narrow state observers
    /*! Access error without runtime checks.
    \returns Nothing.
    */
    constexpr void assume_error() const noexcept { NoValuePolicy::narrow_error_check(this); }
    /// \output_section Wide state observers
    /*! Access error with runtime checks.
    \returns Nothing.
    \requires The result to have a failed state, else whatever `NoValuePolicy` says ought to happen.
    */
    constexpr void error() const { NoValuePolicy::wide_error_check(this); }
  };

#if OUTCOME_ENABLE_POSITIVE_STATUS
  //! The status observers implementation of `result<R, EC, NoValuePolicy>`. Only appears separate due to standardese limitations.
  template <class Base, class EC, class NoValuePolicy> class result_status_observers : public Base
  {
  public:
    using status_type = EC;
    using Base::Base;

    /// \output_section Narrow state observers
    /*! Access status without runtime checks.
    \preconditions The result to have a status state, otherwise it is undefined behaviour.
    \returns Reference to the held `status_type` according to overload.
    \group assume_status
    */
    constexpr status_type &assume_status() & noexcept
    {
      NoValuePolicy::narrow_status_check(this);
      return this->_error;
    }
    /// \group assume_status
    constexpr const status_type &assume_status() const &noexcept
    {
      NoValuePolicy::narrow_status_check(this);
      return this->_error;
    }
    /// \group assume_status
    constexpr status_type &&assume_status() && noexcept
    {
      NoValuePolicy::narrow_status_check(this);
      return std::move(this->_error);
    }
    /// \group assume_status
    constexpr const status_type &&assume_status() const &&noexcept
    {
      NoValuePolicy::narrow_status_check(this);
      return std::move(this->_error);
    }

    /// \output_section Wide state observers
    /*! Access status with runtime checks.
    \returns Reference to the held `status_type` according to overload.
    \requires The result to have a success + status state, else whatever `NoValuePolicy` says ought to happen.
    \group status
    */
    constexpr status_type &status() &
    {
      NoValuePolicy::wide_status_check(this);
      return this->_error;
    }
    /// \group status
    constexpr const status_type &status() const &
    {
      NoValuePolicy::wide_status_check(this);
      return this->_error;
    }
    /// \group status
    constexpr status_type &&status() &&
    {
      NoValuePolicy::wide_status_check(this);
      return std::move(this->_error);
    }
    /// \group status
    constexpr const status_type &&status() const &&
    {
      NoValuePolicy::wide_status_check(this);
      return std::move(this->_error);
    }
  };
  template <class Base, class NoValuePolicy> class result_status_observers<Base, void, NoValuePolicy> : public Base
  {
  public:
    using Base::Base;
    /// \output_section Narrow state observers
    /*! Access status without runtime checks.
    \returns Nothing.
    */
    constexpr void assume_status() const noexcept { NoValuePolicy::narrow_status_check(this); }

    /// \output_section Wide state observers
    /*! Access status with runtime checks.
    \returns Nothing.
    \requires The result to have a success + status state, else whatever `NoValuePolicy` says ought to happen.
    */
    constexpr void status() const { NoValuePolicy::wide_status_check(this); }
  };
  template <class Base, class EC, class NoValuePolicy> using select_result_observers_error_or_status = std::conditional_t<trait::status_type_is_negative<std::decay_t<EC>>::value, result_error_observers<Base, EC, NoValuePolicy>, result_status_observers<Base, EC, NoValuePolicy>>;
  template <class R, class EC, class NoValuePolicy> using select_result_impl = select_result_observers_error_or_status<result_value_observers<result_storage<R, EC, NoValuePolicy>, R, NoValuePolicy>, EC, NoValuePolicy>;
#else
  template <class R, class EC, class NoValuePolicy> using select_result_impl = result_error_observers<result_value_observers<result_storage<R, EC, NoValuePolicy>, R, NoValuePolicy>, EC, NoValuePolicy>;
#endif

  //! The assembled implementation type of `result<R, EC, NoValuePolicy>`. Only appears separate due to standardese limitations.
  template <class R, class S, class NoValuePolicy> class result_final : public select_result_impl<R, S, NoValuePolicy>
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
#if OUTCOME_ENABLE_POSITIVE_STATUS
    /*! Checks if has status information.
\returns True if has status.
*/
    constexpr bool has_status() const noexcept { return (this->_state._status & detail::status_have_status) != 0; }
#endif
    /*! Checks if has payload.
    \returns True if has payload.
    */
    constexpr bool has_payload() const noexcept { return (this->_state._status & detail::status_have_payload) != 0; }
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
          return detail::safe_compare_equal(this->_state._value, o._state._value) && detail::safe_compare_equal(this->_error, o._error);
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
        return detail::safe_compare_equal(this->_state._value, o.value);
      }
      return false;
    }
    /*! True if equal to the success type sugar.
    \param o The success type sugar to compare to.

    \effects If a valid expression to do so, calls the `operator==` operation on the successful item returning true if equal. Otherwise returns false.
    \throws Any exception the `operator==` operation might throw.
    */
    constexpr bool operator==(const success_type<void> & /*unused*/) const noexcept
    {
      if(this->_state._status & detail::status_have_value)
      {
        return true;
      }
      return false;
    }
    /*! True if equal to the failure type sugar.
    \param o The failure type sugar to compare to.

    \effects If a valid expression to do so, calls the `operator==` operation on the failure item returning true if equal. Otherwise returns false.
    \throws Any exception the `operator==` operation might throw.
    */
    template <class T> constexpr bool operator==(const failure_type<T, void> &o) const noexcept(noexcept(detail::safe_compare_equal(std::declval<detail::devoid<S>>(), std::declval<detail::devoid<T>>())))
    {
      if(this->_state._status & detail::status_have_error)
      {
        return detail::safe_compare_equal(this->_error, o.error);
      }
      return false;
    }
    /*! True if not equal to the other result.
    \param o The other result to compare to.

    \effects If a valid expression to do so, calls the `operator!=` operation on each
    of the two stored items, returning true if any are not equal.
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
        if(detail::safe_compare_notequal(this->_state._value, o._state._value))
          return true;
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
        return detail::safe_compare_notequal(this->_state._value, o.value);
      }
      return true;
    }
    /*! True if not equal to the success type sugar.
    \param o The success type sugar to compare to.

    \effects If a valid expression to do so, calls the `operator!=` operation on the successful item returning true if not equal. Otherwise returns false.
    \throws Any exception the `operator!=` operation might throw.
    */
    constexpr bool operator!=(const success_type<void> & /*unused*/) const noexcept
    {
      if(this->_state._status & detail::status_have_value)
      {
        return false;
      }
      return true;
    }
    /*! True if not equal to the failure type sugar.
    \param o The failure type sugar to compare to.

    \effects If a valid expression to do so, calls the `operator!=` operation on the failure item returning true if not equal. Otherwise returns false.
    \throws Any exception the `operator!=` operation might throw.
    */
    template <class T> constexpr bool operator!=(const failure_type<T, void> &o) const noexcept(noexcept(detail::safe_compare_notequal(std::declval<detail::devoid<S>>(), std::declval<detail::devoid<T>>())))
    {
      if(this->_state._status & detail::status_have_error)
      {
        return detail::safe_compare_notequal(this->_error, o.error);
      }
      return true;
    }
  };
  //! Calls b == a
  template <class T, class U, class V, class W> constexpr inline bool operator==(const success_type<W> &a, const result_final<T, U, V> &b) noexcept(noexcept(b == a)) { return b == a; }
  //! Calls b == a
  template <class T, class U, class V, class W> constexpr inline bool operator==(const failure_type<W, void> &a, const result_final<T, U, V> &b) noexcept(noexcept(b == a)) { return b == a; }
  //! Calls b != a
  template <class T, class U, class V, class W> constexpr inline bool operator!=(const success_type<W> &a, const result_final<T, U, V> &b) noexcept(noexcept(b == a)) { return b != a; }
  //! Calls b != a
  template <class T, class U, class V, class W> constexpr inline bool operator!=(const failure_type<W, void> &a, const result_final<T, U, V> &b) noexcept(noexcept(b == a)) { return b != a; }
}

//! Namespace for policies
namespace policy
{
#ifdef __cpp_exceptions
  /*! Policy interpreting EC as a type to be thrown directly during wide checks.
  \module Error code interpretation policy
  */
  template <class EC> struct throw_directly
  {
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
#if OUTCOME_ENABLE_POSITIVE_STATUS
    /*! Performs a narrow check of state, used in the assume_status() functions
\effects None.
*/
    template <class Impl> static constexpr void narrow_status_check(Impl *self) noexcept
    {
      (void) self;
#if defined(__GNUC__) || defined(__clang__)
      if((self->_state._status & detail::status_have_status) == 0)
        __builtin_unreachable();
#endif
    }
#endif
    /*! Performs a wide check of state, used in the value() functions.
    \effects If result does not have a value, if it has an error it throws that `error()`, else it throws `bad_result_access`.
    */
    template <class Impl> static constexpr void wide_value_check(Impl *self)
    {
      if((self->_state._status & detail::status_have_value) == 0)
      {
        if((self->_state._status & detail::status_have_error) != 0)
        {
          throw self->_error;
        }
        throw bad_result_access("no value");
      }
    }
    /*! Performs a wide check of state, used in the error() functions
    \effects If result does not have an error, it throws `bad_result_access`.
    */
    template <class Impl> static constexpr void wide_error_check(Impl *self)
    {
      if((self->_state._status & detail::status_have_error) == 0)
      {
        throw bad_result_access("no error");
      }
    }
#if OUTCOME_ENABLE_POSITIVE_STATUS
    /*! Performs a wide check of state, used in the status() functions
\effects If result does not have an status, it throws `bad_result_access`.
*/
    template <class Impl> static constexpr void wide_status_check(Impl *self)
    {
      if((self->_state._status & detail::status_have_status) == 0)
      {
        throw bad_result_access("no status");
      }
    }
#endif
  };
  /*! Policy interpreting EC as a type implementing the `std::error_code` contract
  and any wide attempt to access the successful state throws the `error_code` wrapped into
  a `std::system_error`
  \module Error code interpretation policy
  */
  template <class EC> struct error_code_throw_as_system_error
  {
    static_assert(std::is_base_of<std::error_code, EC>::value, "error_type must be a base of a std::error_code to be used with this policy");
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
    /*! Performs a narrow check of state, used in the assume_error() functions.
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
#if OUTCOME_ENABLE_POSITIVE_STATUS
    /*! Performs a narrow check of state, used in the assume_status() functions
\effects None.
*/
    template <class Impl> static constexpr void narrow_status_check(Impl *self) noexcept
    {
      (void) self;
#if defined(__GNUC__) || defined(__clang__)
      if((self->_state._status & detail::status_have_status) == 0)
        __builtin_unreachable();
#endif
    }
#endif
    /*! Performs a wide check of state, used in the value() functions.
    \effects If result does not have a value, if it has an error it throws a `std::system_error(error())`, else it throws `bad_result_access`.
    */
    template <class Impl> static constexpr void wide_value_check(Impl *self)
    {
      if((self->_state._status & detail::status_have_value) == 0)
      {
        if((self->_state._status & detail::status_have_error) != 0)
        {
          throw std::system_error(self->_error);
        }
        throw bad_result_access("no value");
      }
    }
    /*! Performs a wide check of state, used in the error() functions
    \effects If result does not have an error, it throws `bad_result_access`.
    */
    template <class Impl> static constexpr void wide_error_check(Impl *self)
    {
      if((self->_state._status & detail::status_have_error) == 0)
      {
        throw bad_result_access("no error");
      }
    }
#if OUTCOME_ENABLE_POSITIVE_STATUS
    /*! Performs a wide check of state, used in the status() functions
\effects If result does not have an status, it throws `bad_result_access`.
*/
    template <class Impl> static constexpr void wide_status_check(Impl *self)
    {
      if((self->_state._status & detail::status_have_status) == 0)
      {
        throw bad_result_access("no status");
      }
    }
#endif
  };
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
#if OUTCOME_ENABLE_POSITIVE_STATUS
    /*! Performs a narrow check of state, used in the assume_status() functions
\effects None.
*/
    template <class Impl> static constexpr void narrow_status_check(Impl *self) noexcept
    {
      (void) self;
#if defined(__GNUC__) || defined(__clang__)
      if((self->_state._status & detail::status_have_status) == 0)
        __builtin_unreachable();
#endif
    }
#endif
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
        throw bad_result_access("no value");
      }
    }
    /*! Performs a wide check of state, used in the value() functions
    \effects If result does not have a value, if it has an error it throws that error, else it throws `bad_result_access`.
    */
    template <class Impl> static constexpr void wide_error_check(Impl *self)
    {
      if((self->_state._status & detail::status_have_error) == 0)
      {
        throw bad_result_access("no error");
      }
    }
#if OUTCOME_ENABLE_POSITIVE_STATUS
    /*! Performs a wide check of state, used in the status() functions
\effects If result does not have an status, it throws `bad_result_access`.
*/
    template <class Impl> static constexpr void wide_status_check(Impl *self)
    {
      if((self->_state._status & detail::status_have_status) == 0)
      {
        throw bad_result_access("no status");
      }
    }
#endif
  };
#endif
  /*! Policy implementing any wide attempt to access the successful state as calling `std::terminate`
  \module Error code interpretation policy
  */
  struct terminate
  {
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
#if OUTCOME_ENABLE_POSITIVE_STATUS
    /*! Performs a narrow check of state, used in the assume_status() functions
\effects None.
*/
    template <class Impl> static constexpr void narrow_status_check(Impl *self) noexcept
    {
      (void) self;
#if defined(__GNUC__) || defined(__clang__)
      if((self->_state._status & detail::status_have_status) == 0)
        __builtin_unreachable();
#endif
    }
#endif
    /*! Performs a narrow check of state, used in the assume_payload() functions
    \effects None.
    */
    template <class Impl> static constexpr void narrow_payload_check(Impl *self) noexcept
    {
      (void) self;
#if defined(__GNUC__) || defined(__clang__)
      if((self->_state._status & detail::status_have_payload) == 0)
        __builtin_unreachable();
#endif
    }
    /*! Performs a narrow check of state, used in the assume_exception() functions
    \effects None.
    */
    template <class Impl> static constexpr void narrow_exception_check(Impl *self) noexcept
    {
      (void) self;
#if defined(__GNUC__) || defined(__clang__)
      if((self->_state._status & detail::status_have_exception) == 0)
        __builtin_unreachable();
#endif
    }
    /*! Performs a wide check of state, used in the value() functions.
    \effects If result does not have a value, calls `std::terminate()`.
    */
    template <class Impl> static constexpr void wide_value_check(Impl *self)
    {
      if((self->_state._status & detail::status_have_value) == 0)
      {
        std::terminate();
      }
    }
    /*! Performs a wide check of state, used in the error() functions
    \effects If result does not have an error, calls `std::terminate()`.
    */
    template <class Impl> static constexpr void wide_error_check(Impl *self) noexcept
    {
      if((self->_state._status & detail::status_have_error) == 0)
      {
        std::terminate();
      }
    }
#if OUTCOME_ENABLE_POSITIVE_STATUS
    /*! Performs a wide check of state, used in the status() functions
\effects If result does not have an status, calls `std::terminate()`.
*/
    template <class Impl> static constexpr void wide_status_check(Impl *self)
    {
      if((self->_state._status & detail::status_have_status) == 0)
      {
        std::terminate();
      }
    }
#endif
    /*! Performs a wide check of state, used in the payload() functions
    \effects If outcome does not have an exception, calls `std::terminate()`.
    */
    template <class Impl> static constexpr void wide_payload_check(Impl *self)
    {
      if((self->_state._status & detail::status_have_payload) == 0)
      {
        std::terminate();
      }
    }
    /*! Performs a wide check of state, used in the exception() functions
    \effects If outcome does not have an exception, calls `std::terminate()`.
    */
    template <class Impl> static constexpr void wide_exception_check(Impl *self)
    {
      if((self->_state._status & detail::status_have_exception) == 0)
      {
        std::terminate();
      }
    }
  };

#ifdef __cpp_exceptions
  /*! Default `result<R, S>` policy selector.
  \module Error code interpretation policy
  */
  template <class EC>
  using default_result_policy = std::conditional_t<                                             //
  std::is_void<EC>::value,                                                                      //
  terminate,                                                                                    //
  std::conditional_t<                                                                           //
  detail::is_same_or_constructible<std::error_code, EC>, error_code_throw_as_system_error<EC>,  //
  std::conditional_t<                                                                           //
  detail::is_same_or_constructible<std::exception_ptr, EC>, exception_ptr_rethrow<EC>,          //
  throw_directly<EC>                                                                            //
  >>>;
#else
  template <class EC> using default_result_policy = terminate;
#endif
}

template <class R, class S = std::error_code, class NoValuePolicy = policy::default_result_policy<S>> class result;

namespace detail
{
  // These are reused by outcome to save load on the compiler
  template <class value_type, class status_error_type, class error_type> struct result_predicates
  {
    // Predicate for the value converting constructor to be available.
    template <class T>
    static constexpr bool enable_value_converting_constructor =  //
    !is_in_place_type_t<std::decay_t<T>>::value                  // not in place construction
    && is_same_or_constructible<value_type, T> && !std::is_constructible<status_error_type, T>::value;

    // Predicate for the error converting constructor to be available.
    template <class T>
    static constexpr bool enable_error_converting_constructor =  //
    !is_in_place_type_t<std::decay_t<T>>::value                  // not in place construction
    && !std::is_constructible<value_type, T>::value && is_same_or_constructible<error_type, T>;

    // Predicate for the error condition converting constructor to be available.
    template <class ErrorCondEnum>
    static constexpr bool enable_error_condition_converting_constructor =                                                     //
    !is_in_place_type_t<std::decay_t<ErrorCondEnum>>::value                                                                   // not in place construction
    && std::is_error_condition_enum<ErrorCondEnum>::value                                                                     // is an error condition enum
    && !std::is_constructible<value_type, ErrorCondEnum>::value && !std::is_constructible<error_type, ErrorCondEnum>::value;  // not constructible via any other means

    // Predicate for the converting copy constructor from a compatible input to be available.
    template <class T, class U, class V>
    static constexpr bool enable_compatible_conversion =                                                      //
    (std::is_void<T>::value || is_same_or_constructible<value_type, typename result<T, U, V>::value_type>)    // if our value types are constructible
    &&(std::is_void<U>::value || is_same_or_constructible<error_type, typename result<T, U, V>::error_type>)  // if our error types are constructible
#if OUTCOME_ENABLE_POSITIVE_STATUS
    &&(std::is_void<U>::value || is_same_or_constructible<status_type, typename result<T, U, V>::status_type>)  // if our status types are constructible
#endif
    ;

    // Predicate for the implicit converting inplace constructor from a compatible input to be available.
    struct disable_inplace_value_error_constructor;
    template <class... Args>
    using choose_inplace_value_error_constructor = std::conditional_t<                                       //
    std::is_constructible<value_type, Args...>::value && std::is_constructible<error_type, Args...>::value,  //
    disable_inplace_value_error_constructor,                                                                 //
    std::conditional_t<                                                                                      //
    std::is_constructible<value_type, Args...>::value,                                                       //
    value_type,                                                                                              //
    std::conditional_t<                                                                                      //
    std::is_constructible<error_type, Args...>::value,                                                       //
    error_type,                                                                                              //
    disable_inplace_value_error_constructor>>>;
    template <class... Args> static constexpr bool enable_inplace_value_error_constructor = !std::is_same<choose_inplace_value_error_constructor<Args...>, disable_inplace_value_error_constructor>::value;
  };

  template <class T, class U> constexpr inline const U &extract_value_from_success(const success_type<U> &v) { return v.value; }
  template <class T, class U> constexpr inline U &&extract_value_from_success(success_type<U> &&v) { return std::move(v.value); }
  template <class T> constexpr inline T extract_value_from_success(const success_type<void> & /*unused*/) { return T{}; }

  template <class T, class U, class V> constexpr inline const U &extract_error_from_failure(const failure_type<U, V> &v) { return v.error; }
  template <class T, class U, class V> constexpr inline U &&extract_error_from_failure(failure_type<U, V> &&v) { return std::move(v.error); }
  template <class T, class V> constexpr inline T extract_error_from_failure(const failure_type<void, V> & /*unused*/) { return T{}; }
}

namespace hooks
{
  /*! The default instantiation hook implementation called when a `result` is first created
  by conversion from one of its possible types. Does nothing.
  \tparam T One of `value_type` or `error_type`.

  WARNING: The compiler is permitted to elide calls to constructors, and thus this hook may not get called when you think it should!
  */
  template <class T, class U> constexpr inline void hook_result_construction(in_place_type_t<T> /*unused*/, U * /*unused*/) noexcept {}
  /*! The default instantiation hook implementation called when a `result` is created by copying
  from another `result`. Does nothing.
  \tparam T The type of the source.

  WARNING: The compiler is permitted to elide calls to constructors, and thus this hook may not get called when you think it should!
  */
  template <class T, class U> constexpr inline void hook_result_copy_construction(in_place_type_t<T> /*unused*/, U * /*unused*/) noexcept {}
  /*! The default instantiation hook implementation called when a `result` is created by moving
  from another `result`. Does nothing.
  \tparam T The type of the source.

  WARNING: The compiler is permitted to elide calls to constructors, and thus this hook may not get called when you think it should!
  */
  template <class T, class U> constexpr inline void hook_result_move_construction(in_place_type_t<T> /*unused*/, U * /*unused*/) noexcept {}
  /*! The default instantiation hook implementation called when a `result` is created by in place
  construction. Does nothing.
  \tparam T One of `value_type` or `error_type`.

  WARNING: The compiler is permitted to elide calls to constructors, and thus this hook may not get called when you think it should!
  */
  template <class T, class U> constexpr inline void hook_result_in_place_construction(in_place_type_t<T> /*unused*/, U * /*unused*/) noexcept {}

  //! Retrieves the 16 bits of spare storage in result/outcome.
  template <class R, class S, class NoValuePolicy> constexpr inline uint16_t spare_storage(const impl::result_final<R, S, NoValuePolicy> *r) noexcept { return (r->_state._status >> detail::status_2byte_shift) & 0xffff; }
  template <class R, class S, class NoValuePolicy> constexpr inline void set_spare_storage(impl::result_final<R, S, NoValuePolicy> *r, uint16_t v) noexcept { r->_state._status |= (v << detail::status_2byte_shift); }
}

/*! Used to return from functions (i) a value (ii) a value and a positive status or (iii) no value and a negative status. `constexpr` capable.
\module result<R, S> implementation
\tparam R The optional type of the successful result (use `void` to disable).
\tparam S The optional type of the status result (use `void` to disable). Must be either `void` or DefaultConstructible.
\tparam NoValuePolicy Policy on how to interpret type `S` when a wide observation of a not present value occurs.

This is a vocabulary type implementing [P0262R0 A Class for Status and Optional Value](http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0262r0.html),
albeit with types `Status` and `Value` reversed in lexical order. By default `S` is considered to be a *positive* status type used to supply
additional information about the successful return of a type `R`. If however the trait `trait::status_type_is_negative<S>`
has been specialised to be true, then `S` is considered to be a *negative* status type used to supply information about
the cause of failure to return a type `R`.

`trait::status_type_is_negative<S>` is already set to true for these types (you can specialise in your own types easily):
- `std::error_code`
- `std::exception_ptr`
- `void`

When `trait::status_type_is_negative<S>` is false, the default for `NoValuePolicy` is:
  1. If `.status()` called when there is no `status_type`:
    - `throw bad_result_access()` if C++ exceptions are enabled, else call `std::terminate()`.

When `trait::status_type_is_negative<S>` is true, the default for `NoValuePolicy` is:
  1. If `.value()` called when there is no `value_type` but there is an `error_type`:
    - If `S` convertible to a `std::error_code`, then `throw std::system_error(error())` [`policy::error_code_throw_as_system_error<S>`]
    if C++ exceptions are enabled, else call `std::terminate()`.
    - If `S` convertible to a `std::exception_ptr`, then `std::rethrow_exception(error())` [`policy::exception_ptr_rethrow<S>`]
    if C++ exceptions are enabled, else call `std::terminate()`.
    - If `S` is `void`, call `std::terminate()` [`policy::terminate<S>`]
    - If `S` is none of the above, then someone has enabled the negative status type trait but did not specify a custom policy.
    We therefore simply `throw error()` [`policy::throw_directly<S>`] if C++ exceptions are enabled, else call `std::terminate`.
  2. If `.error()` called when there is no `error_type`:
    - `throw bad_result_access()` if C++ exceptions are enabled, else call `std::terminate()`.

*/
template <class R, class S, class NoValuePolicy> class OUTCOME_NODISCARD result : public impl::result_final<R, S, NoValuePolicy>
{
  using base = impl::result_final<R, S, NoValuePolicy>;
  template <class T, class U, class V> friend inline std::istream &operator>>(std::istream &s, result<T, U, V> &v);
  template <class T, class U, class V> friend inline std::ostream &operator<<(std::ostream &s, const result<T, U, V> &v);

  struct value_converting_constructor_tag
  {
  };
  struct error_converting_constructor_tag
  {
  };
  struct error_condition_converting_constructor_tag
  {
  };
  struct value_status_converting_constructor_tag
  {
  };

public:
  /// \output_section Member types
  //! The success type.
  using value_type = R;
  //! The S type configured
  using status_error_type = S;
#if OUTCOME_ENABLE_POSITIVE_STATUS
  //! The status type, always `no_status_type` if `trait::status_type_is_negative<S>` is true.
  using status_type = typename base::status_type;
  //! The failure type, always `no_error_type` if `trait::status_type_is_negative<S>` is false.
  using error_type = typename base::error_type;
#else
  //! The failure type.
  using error_type = S;
#endif

  //! Used to disable in place type construction when `value_type` and `error_type` are ambiguous.
  using value_type_if_enabled = typename base::_value_type;
  //! Used to disable in place type construction when `value_type` and `error_type` are ambiguous.
  using error_type_if_enabled = typename base::_error_type;

  //! Used to rebind this result to a different result type.
  template <class T, class U = S> using rebind = result<T, U>;

protected:
  //! Requirement predicates for result.
  struct predicate
  {
    using base = detail::result_predicates<value_type, status_error_type, error_type>;

    //! Predicate for the value converting constructor to be available.
    template <class T>
    static constexpr bool enable_value_converting_constructor =  //
    !std::is_same<std::decay_t<T>, result>::value                // not my type
    && base::template enable_value_converting_constructor<T>;

    //! Predicate for the error converting constructor to be available.
    template <class T>
    static constexpr bool enable_error_converting_constructor =  //
    !std::is_same<std::decay_t<T>, result>::value                // not my type
    && base::template enable_error_converting_constructor<T>;

    //! Predicate for the error condition converting constructor to be available.
    template <class ErrorCondEnum>
    static constexpr bool enable_error_condition_converting_constructor =  //
    !std::is_same<std::decay_t<ErrorCondEnum>, result>::value              // not my type
    && base::template enable_error_condition_converting_constructor<ErrorCondEnum>;

    //! Predicate for the converting copy constructor from a compatible input to be available.
    template <class T, class U, class V>
    static constexpr bool enable_compatible_conversion =  //
    !std::is_same<result<T, U, V>, result>::value         // not my type
    && base::template enable_compatible_conversion<T, U, V>;

    //! Predicate for the inplace construction of value to be available.
    template <class... Args>
    static constexpr bool enable_inplace_value_constructor =  //
    std::is_void<value_type>::value                           //
    || std::is_constructible<value_type, Args...>::value;

    //! Predicate for the inplace construction of error to be available.
    template <class... Args>
    static constexpr bool enable_inplace_error_constructor =  //
    std::is_void<error_type>::value                           //
    || std::is_constructible<error_type, Args...>::value;

    // Predicate for the implicit converting inplace constructor to be available.
    template <class... Args>
    static constexpr bool enable_inplace_value_error_constructor =  //
    base::template enable_inplace_value_error_constructor<Args...>;
    template <class... Args> using choose_inplace_value_error_constructor = typename base::template choose_inplace_value_error_constructor<Args...>;
  };

public:
  /// \output_section Default, copy/move constructors and assignment
  //! Default construction is not permitted.
  result() = delete;
  //! Move construction available if `value_type` and `status_error_type` implement it.
  result(result && /*unused*/) = default;
  //! Copy construction available if `value_type` and `status_error_type` implement it.
  result(const result & /*unused*/) = default;
  //! Move assignment available if `value_type` and `status_error_type` implement it.
  result &operator=(result && /*unused*/) = default;
  //! Copy assignment available if `value_type` and `status_error_type` implement it.
  result &operator=(const result & /*unused*/) = default;

  /// \output_section Converting constructors
  /*! Implicit converting constructor to a successful result.
  \tparam 1
  \exclude
  \param 1
  \exclude
  \param t The value from which to initialise the `value_type`.

  \effects Initialises the result with a `value_type`.
  \requires Type T is constructible to `value_type`, is not constructible to `status_error_type`, and is not `result<R, S>` and not `in_place_type<>`.
  \throws Any exception the construction of `value_type(T)` might throw.
  */
  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_value_converting_constructor<T>))
  constexpr result(T &&t, value_converting_constructor_tag = value_converting_constructor_tag()) noexcept(std::is_nothrow_constructible<value_type, T>::value)
      : base(in_place_type<typename base::value_type>, std::forward<T>(t))
  {
    using namespace hooks;
    hook_result_construction(in_place_type<value_type>, this);
  }
#if OUTCOME_ENABLE_POSITIVE_STATUS
  /*! Implicit converting constructor to a successful result + status.
\tparam enable_value_status_converting_constructor
\exclude
\param 2
\exclude
\param t The value from which to initialise the `value_type`.
\param u The value from which to initialise the `status_type`.

\effects Initialises the result with a `value_type` and an additional `status_type`.
\requires `trait::status_type_is_negative<EC>` must be false; Type `T` is constructible to `value_type`, is not constructible to `status_type`, and is not `result<R, S>` and not `in_place_type<>`;
Type `U` is constructible to `status_type`, is not constructible to `value_type`.
\throws Any exception the construction of `value_type(T)` and `status_type(U)` might throw.
*/
  template <class T, class U, typename enable_value_status_converting_constructor = std::enable_if_t<  //
                              !std::is_same<std::decay_t<T>, result>::value                            // not my type
                              && !detail::is_in_place_type_t<std::decay_t<T>>::value                   // not in place construction
                              && detail::is_same_or_constructible<value_type, T> && !std::is_constructible<status_type, T>::value && detail::is_same_or_constructible<status_type, U> && !std::is_constructible<value_type, U>::value>>
  constexpr result(T &&t, U &&u, value_status_converting_constructor_tag = value_status_converting_constructor_tag()) noexcept(std::is_nothrow_constructible<value_type, T>::value &&std::is_nothrow_constructible<status_type, U>::value)
      : base(typename base::value_status_construction_tag(), std::forward<T>(t), std::forward<U>(u))
  {
    using namespace hooks;
    hook_result_construction(in_place_type<std::pair<value_type, status_type>>, this);
  }
#endif
  /*! Implicit converting constructor to a failure result.
  \tparam 1
  \exclude
  \param 1
  \exclude
  \param t The value from which to initialise the `error_type`.

  \effects Initialises the result with a `error_type`.
  \requires `trait::status_type_is_negative<EC>` must be true; Type T is constructible to `error_type`,
  is not constructible to `value_type`, and is not `result<R, S>` and not `in_place_type<>`.
  \throws Any exception the construction of `error_type(T)` might throw.
  */
  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_error_converting_constructor<T>))
  constexpr result(T &&t, error_converting_constructor_tag = error_converting_constructor_tag()) noexcept(std::is_nothrow_constructible<error_type, T>::value)
      : base(in_place_type<typename base::error_type>, std::forward<T>(t))
  {
    using namespace hooks;
    hook_result_construction(in_place_type<error_type>, this);
  }
  /*! Implicit special error condition converting constructor to a failure result.
  \tparam 1
  \exclude
  \tparam 2
  \exclude
  \param 1
  \exclude
  \param t The error condition from which to initialise the `error_type`.

  \effects Initialises the result with a `error_type` constructed via `make_error_code(t)`.
  \requires `trait::status_type_is_negative<EC>` must be true; `std::is_error_condition_enum<ErrorCondEnum>` must be true,
  `ErrorCondEnum` is not constructible to `value_type` nor `error_type`, and is not `result<R, S>` and not `in_place_type<>`;
  Finally, the expression `error_type(make_error_code(ErrorCondEnum()))` must be valid.
  \throws Any exception the construction of `error_type(make_error_code(t))` might throw.
  */
  OUTCOME_TEMPLATE(class ErrorCondEnum)
  OUTCOME_TREQUIRES(OUTCOME_TEXPR(error_type(make_error_code(ErrorCondEnum()))),  //
                    OUTCOME_TPRED(predicate::template enable_error_condition_converting_constructor<ErrorCondEnum>))
  constexpr result(ErrorCondEnum &&t, error_condition_converting_constructor_tag = error_condition_converting_constructor_tag()) noexcept(noexcept(error_type(make_error_code(std::forward<ErrorCondEnum>(t)))))
      : base(in_place_type<typename base::error_type>, make_error_code(t))
  {
    using namespace hooks;
    hook_result_construction(in_place_type<error_type>, this);
  }

  /*! Explicit converting copy constructor from a compatible result type.
  \tparam 3
  \exclude
  \param o The compatible result.

  \effects Initialises the result with a copy of the compatible result.
  \requires Both result's `value_type`, `error_type` and `status_type` need to be constructible, or the source can be `void`.
  \throws Any exception the construction of `value_type(T)` and `status_error_type(U)` might throw.
  */
  OUTCOME_TEMPLATE(class T, class U, class V)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_compatible_conversion<T, U, V>))
  constexpr explicit result(const result<T, U, V> &o) noexcept(std::is_nothrow_constructible<value_type, T>::value &&std::is_nothrow_constructible<status_error_type, U>::value)
      : base(typename base::compatible_conversion_tag(), o)
  {
    using namespace hooks;
    hook_result_copy_construction(in_place_type<decltype(o)>, this);
  }
  /*! Explicit converting move constructor from a compatible result type.
  \tparam 3
  \exclude
  \param o The compatible result.

  \effects Initialises the result with a move of the compatible result.
  \requires Both result's `value_type`, `error_type` and `status_type` need to be constructible, or the source can be `void`.
  \throws Any exception the construction of `value_type(T)` and `status_error_type(U)` might throw.
  */
  OUTCOME_TEMPLATE(class T, class U, class V)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_compatible_conversion<T, U, V>))
  constexpr explicit result(result<T, U, V> &&o) noexcept(std::is_nothrow_constructible<value_type, T>::value &&std::is_nothrow_constructible<status_error_type, U>::value)
      : base(typename base::compatible_conversion_tag(), std::move(o))
  {
    using namespace hooks;
    hook_result_move_construction(in_place_type<decltype(o)>, this);
  }

  /// \output_section In place constructors
  /*! Explicit inplace constructor to a successful result.
  \tparam 1
  \exclude
  \param _ Tag type to indicate we are doing in place construction of `value_type`.
  \param args Arguments with which to in place construct.

  \effects Initialises the result with a `value_type`.
  \requires `value_type` is void or `Args...` are constructible to `value_type`.
  \throws Any exception the construction of `value_type(Args...)` might throw.
  */
  OUTCOME_TEMPLATE(class... Args)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_inplace_value_constructor<Args...>))
  constexpr explicit result(in_place_type_t<value_type_if_enabled>, Args &&... args) noexcept(std::is_nothrow_constructible<value_type, Args...>::value)
      : base(in_place_type<value_type_if_enabled>, std::forward<Args>(args)...)
  {
    using namespace hooks;
    hook_result_in_place_construction(in_place_type<value_type>, this);
  }
  /*! Explicit inplace constructor to a successful result.
  \tparam 2
  \exclude
  \param _ Tag type to indicate we are doing in place construction of `value_type`.
  \param il An initializer list with which to in place construct.
  \param args Arguments with which to in place construct.

  \effects Initialises the result with a `value_type`.
  \requires The initializer list + `Args...` are constructible to `value_type`.
  \throws Any exception the construction of `value_type(il, Args...)` might throw.
  */
  OUTCOME_TEMPLATE(class U, class... Args)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_inplace_value_constructor<std::initializer_list<U>, Args...>))
  constexpr explicit result(in_place_type_t<value_type_if_enabled>, std::initializer_list<U> il, Args &&... args) noexcept(std::is_nothrow_constructible<value_type, std::initializer_list<U>, Args...>::value)
      : base(in_place_type<value_type_if_enabled>, il, std::forward<Args>(args)...)
  {
    using namespace hooks;
    hook_result_in_place_construction(in_place_type<value_type>, this);
  }
  /*! Explicit inplace constructor to a failure result.
  \tparam 1
  \exclude
  \param _ Tag type to indicate we are doing in place construction of `error_type`.
  \param args Arguments with which to in place construct.

  \effects Initialises the result with a `error_type`.
  \requires `trait::status_type_is_negative<EC>` must be true; `error_type` is void or `Args...` are constructible to `error_type`.
  \throws Any exception the construction of `error_type(Args...)` might throw.
  */
  OUTCOME_TEMPLATE(class... Args)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_inplace_error_constructor<Args...>))
  constexpr explicit result(in_place_type_t<error_type_if_enabled>, Args &&... args) noexcept(std::is_nothrow_constructible<error_type, Args...>::value)
      : base(in_place_type<error_type_if_enabled>, std::forward<Args>(args)...)
  {
    using namespace hooks;
    hook_result_in_place_construction(in_place_type<error_type>, this);
  }
  /*! Explicit inplace constructor to a failure result.
  \tparam 2
  \exclude
  \param _ Tag type to indicate we are doing in place construction of `error_type`.
  \param il An initializer list with which to in place construct.
  \param args Arguments with which to in place construct.

  \effects Initialises the result with a `error_type`.
  \requires `trait::status_type_is_negative<EC>` must be true; The initializer list + `Args...` are constructible to `error_type`.
  \throws Any exception the construction of `error_type(il, Args...)` might throw.
  */
  OUTCOME_TEMPLATE(class U, class... Args)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_inplace_error_constructor<std::initializer_list<U>, Args...>))
  constexpr explicit result(in_place_type_t<error_type_if_enabled>, std::initializer_list<U> il, Args &&... args) noexcept(std::is_nothrow_constructible<error_type, std::initializer_list<U>, Args...>::value)
      : base(in_place_type<error_type_if_enabled>, il, std::forward<Args>(args)...)
  {
    using namespace hooks;
    hook_result_in_place_construction(in_place_type<error_type>, this);
  }
  /*! Implicit inplace constructor to successful or failure result.
  \tparam 3
  \exclude
  \param args Arguments with which to in place construct.

  \effects Calls the appropriate `in_place_type_t<...>` constructor depending on constructibility of args.
  \requires That the args can construct exactly one of `value_type` or `error_type`.
  \throws Any exception the `in_place_type_t<...>` constructor might throw.
  */
  OUTCOME_TEMPLATE(class A1, class A2, class... Args)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_inplace_value_error_constructor<A1, A2, Args...>))
  constexpr result(A1 &&a1, A2 &&a2, Args &&... args) noexcept(noexcept(typename predicate::template choose_inplace_value_error_constructor<A1, A2, Args...>(std::declval<A1>(), std::declval<A2>(), std::declval<Args>()...)))
      : result(in_place_type<typename predicate::template choose_inplace_value_error_constructor<A1, A2, Args...>>, std::forward<A1>(a1), std::forward<A2>(a2), std::forward<Args>(args)...)
  {
  }

  /// \output_section Tagged constructors
  /*! Implicit tagged constructor of a successful result.
  \param o The compatible success type sugar.

  \effects Initialises the result with a default constructed success type.
  \requires `value_type` to be default constructible, or `void`.
  \throws Any exception the construction of `value_type()` might throw.
  */
  constexpr result(const success_type<void> &o) noexcept(std::is_nothrow_default_constructible<value_type>::value)
      : base(in_place_type<value_type_if_enabled>)
  {
    using namespace hooks;
    hook_result_copy_construction(in_place_type<decltype(o)>, this);
  }
  /*! Implicit tagged constructor of a successful result.
  \tparam 1
  \exclude
  \param o The compatible success type sugar.

  \effects Initialises the result with a copy of the value in the type sugar.
  \requires Both result and success' `value_type` need to be constructible, or the source can be `void`.
  \throws Any exception the construction of `value_type(T)` might throw.
  */
  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_compatible_conversion<T, void, void>))
  constexpr result(const success_type<T> &o) noexcept(std::is_nothrow_constructible<value_type, T>::value)
      : base(in_place_type<value_type_if_enabled>, detail::extract_value_from_success<value_type>(o))
  {
    using namespace hooks;
    hook_result_copy_construction(in_place_type<decltype(o)>, this);
  }
  /*! Implicit tagged constructor of a successful result.
  \tparam 1
  \exclude
  \param o The compatible success type sugar.

  \effects Initialises the result with a move of the value in the type sugar.
  \requires Both result and success' `value_type` need to be constructible. The source cannot be `void`.
  \throws Any exception the construction of `value_type(T)` might throw.
  */
  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(!std::is_void<T>::value && predicate::template enable_compatible_conversion<T, void, void>))
  constexpr result(success_type<T> &&o) noexcept(std::is_nothrow_constructible<value_type, T>::value)
      : base(in_place_type<value_type_if_enabled>, std::move(detail::extract_value_from_success<value_type>(std::move(o))))
  {
    using namespace hooks;
    hook_result_move_construction(in_place_type<decltype(o)>, this);
  }
  /*! Implicit tagged constructor of a failure result.
  \tparam 1
  \exclude
  \param o The compatible failure type sugar.

  \effects Initialises the result with a copy of the error in the type sugar.
  \requires Both result and failure's `error_type` need to be constructible, or the source can be `void`.
  \throws Any exception the construction of `error_type(T)` might throw.
  */
  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_compatible_conversion<void, T, void>))
  constexpr result(const failure_type<T> &o) noexcept(std::is_nothrow_constructible<error_type, T>::value)
      : base(in_place_type<error_type_if_enabled>, detail::extract_error_from_failure<error_type>(o))
  {
    using namespace hooks;
    hook_result_copy_construction(in_place_type<decltype(o)>, this);
  }
  /*! Implicit tagged constructor of a failure result.
  \tparam 1
  \exclude
  \param o The compatible failure type sugar.

  \effects Initialises the result with a move of the error in the type sugar.
  \requires Both result and failure's `error_type` need to be constructible, or the source can be `void`.
  \throws Any exception the construction of `error_type(T)` might throw.
  */
  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_compatible_conversion<void, T, void>))
  constexpr result(failure_type<T> &&o) noexcept(std::is_nothrow_constructible<error_type, T>::value)
      : base(in_place_type<error_type_if_enabled>, std::move(detail::extract_error_from_failure<error_type>(std::move(o))))
  {
    using namespace hooks;
    hook_result_move_construction(in_place_type<decltype(o)>, this);
  }

  /// \output_section Swap
  /*! Swaps this result with another result
  \effects Any `R` and/or `S` is swapped along with the metadata tracking them.
  */
  void swap(result &o) noexcept(detail::is_nothrow_swappable<value_type>::value  //
                                &&detail::is_nothrow_swappable<status_error_type>::value)
  {
    using std::swap;
#ifdef __cpp_exceptions
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4297)  // use of throw in noexcept function
#endif
    this->_state.swap(o._state);
    try
    {
      swap(this->_error, o._error);
    }
    catch(...)
    {
      swap(this->_state, o._state);
      throw;
    }
#ifdef _MSC_VER
#pragma warning(pop)
#endif
#else
    swap(this->_state, o._state);
    swap(this->_error, o._error);
#endif
  }

  /// \output_section Converters
  /*! Returns this result as a `failure_type` with any errored state copied.
  \requires This result to have a failed state, else whatever `assume_error()` would do.
  */
  auto as_failure() const & { return failure(this->assume_error()); }
  /*! Returns this result as a `failure_type` with any errored state moved.
  \requires This result to have a failed state, else whatever `assume_error()` would do.
  */
  auto as_failure() && { return failure(std::move(this->assume_error())); }
};

/*! Specialise swap for result.
\effects Calls `a.swap(b)`.
*/
template <class R, class S, class P> inline void swap(result<R, S, P> &a, result<R, S, P> &b) noexcept(noexcept(a.swap(b)))
{
  a.swap(b);
}

#ifndef NDEBUG
// Check is trivial in all ways except default constructibility
// static_assert(std::is_trivial<result<int>>::value, "result<int> is not trivial!");
// static_assert(std::is_trivially_default_constructible<result<int>>::value, "result<int> is not trivially default constructible!");
static_assert(std::is_trivially_copyable<result<int>>::value, "result<int> is not trivially copyable!");
static_assert(std::is_trivially_assignable<result<int>, result<int>>::value, "result<int> is not trivially assignable!");
static_assert(std::is_trivially_destructible<result<int>>::value, "result<int> is not trivially destructible!");
static_assert(std::is_trivially_copy_constructible<result<int>>::value, "result<int> is not trivially copy constructible!");
static_assert(std::is_trivially_move_constructible<result<int>>::value, "result<int> is not trivially move constructible!");
static_assert(std::is_trivially_copy_assignable<result<int>>::value, "result<int> is not trivially copy assignable!");
static_assert(std::is_trivially_move_assignable<result<int>>::value, "result<int> is not trivially move assignable!");
// Also check is standard layout
static_assert(std::is_standard_layout<result<int>>::value, "result<int> is not a standard layout type!");
#endif

OUTCOME_V2_NAMESPACE_END

#endif
