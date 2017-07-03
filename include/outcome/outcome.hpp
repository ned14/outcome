/* A less simple result type
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

#ifndef OUTCOME_OUTCOME_HPP
#define OUTCOME_OUTCOME_HPP

#include "result.hpp"

#include <exception>
#include <memory>

OUTCOME_V2_NAMESPACE_BEGIN

//! Thrown when you try to access state in a `outcome<T, EC, E>` which isn't present.
class OUTCOME_SYMBOL_VISIBLE bad_outcome_access : public std::logic_error
{
public:
  bad_outcome_access(const char *what)
      : std::logic_error(what)
  {
  }
};

//! Namespace for traits
namespace trait
{
  /*! Trait for whether type `P` is to be considered a payload to an exception.
  \module Error code interpretation policy
  */
  template <class P> struct is_exception_ptr : std::integral_constant<bool, std::is_constructible<std::exception_ptr, P>::value>
  {
  };
}

//! Placeholder type to indicate there is no payload type
struct no_payload_type
{
  no_payload_type() = delete;
};
//! Placeholder type to indicate there is no exception type
struct no_exception_type
{
  no_exception_type() = delete;
};

namespace impl
{
  //! The payload observers implementation of `outcome<R, S, P>`. Only appears separate due to standardese limitations.
  template <class Base, class R, class S, class P, class NoValuePolicy> class outcome_payload_observers : public Base
  {
  public:
    using payload_type = P;
    using Base::Base;

    /// \output_section Narrow state observers
    /*! Access payload without runtime checks.
    \preconditions The outcome to have an payload state, otherwise it is undefined behaviour.
    \returns Reference to the held `payload_type` according to overload.
    \group assume_payload
    */
    inline constexpr payload_type &assume_payload() & noexcept;
    /// \group assume_payload
    inline constexpr const payload_type &assume_payload() const &noexcept;
    /// \group assume_payload
    inline constexpr payload_type &&assume_payload() && noexcept;
    /// \group assume_payload
    inline constexpr const payload_type &&assume_payload() const &&noexcept;

    /// \output_section Wide state observers
    /*! Access payload with runtime checks.
    \returns Reference to the held `payload_type` according to overload.
    \requires The outcome to have an payload state, else whatever `NoValuePolicy` says ought to happen.
    \group payload
    */
    inline constexpr payload_type &payload() &;
    /// \group payload
    inline constexpr const payload_type &payload() const &;
    /// \group payload
    inline constexpr payload_type &&payload() &&;
    /// \group payload
    inline constexpr const payload_type &&payload() const &&;
  };

  template <class Base, class R, class S, class NoValuePolicy> class outcome_payload_observers<Base, R, S, void, NoValuePolicy> : public Base
  {
  public:
    using Base::Base;
    /// \output_section Narrow state observers
    /*! Access payload without runtime checks.
    \returns Nothing.
    */
    constexpr void assume_payload() const noexcept { NoValuePolicy::narrow_payload_check(this); }
    /// \output_section Wide state observers
    /*! Access payload with runtime checks.
    \returns Nothing.
    \requires The outcome to have an payload state, else whatever `NoValuePolicy` says ought to happen.
    */
    constexpr void payload() const { NoValuePolicy::wide_payload_check(this); }
  };

  //! The exception observers implementation of `outcome<R, S, P>`. Only appears separate due to standardese limitations.
  template <class Base, class R, class S, class P, class NoValuePolicy> class outcome_exception_observers : public Base
  {
  public:
    using exception_type = P;
    using Base::Base;

    /// \output_section Narrow state observers
    /*! Access exception without runtime checks.
    \preconditions The outcome to have an exception state, otherwise it is undefined behaviour.
    \returns Reference to the held `exception_type` according to overload.
    \group assume_exception
    */
    constexpr inline exception_type &assume_exception() & noexcept;
    /// \group assume_exception
    constexpr inline const exception_type &assume_exception() const &noexcept;
    /// \group assume_exception
    constexpr inline exception_type &&assume_exception() && noexcept;
    /// \group assume_exception
    constexpr inline const exception_type &&assume_exception() const &&noexcept;

    /// \output_section Wide state observers
    /*! Access exception with runtime checks.
    \returns Reference to the held `exception_type` according to overload.
    \requires The outcome to have an exception state, else whatever `NoValuePolicy` says ought to happen.
    \group exception
    */
    constexpr inline exception_type &exception() &;
    /// \group exception
    constexpr inline const exception_type &exception() const &;
    /// \group exception
    constexpr inline exception_type &&exception() &&;
    /// \group exception
    constexpr inline const exception_type &&exception() const &&;
  };
  template <class Base, class R, class S, class NoValuePolicy> class outcome_exception_observers<Base, R, S, void, NoValuePolicy> : public Base
  {
  public:
    using Base::Base;
    /// \output_section Narrow state observers
    /*! Access exception without runtime checks.
    \returns Nothing.
    */
    constexpr void assume_exception() const noexcept { NoValuePolicy::narrow_exception_check(this); }
    /// \output_section Wide state observers
    /*! Access exception with runtime checks.
    \returns Nothing.
    \requires The outcome to have an exception state, else whatever `NoValuePolicy` says ought to happen.
    */
    constexpr void exception() const { NoValuePolicy::wide_exception_check(this); }
  };
}

namespace policy
{
#ifdef __cpp_exceptions
  template <class R, class S, class P> struct error_code_throw_as_system_error_exception_rethrow;
  /*! Default `outcome<R, S, P>` policy selector.
  \module Error code interpretation policy
  */
  template <class R, class S, class P>
  using default_outcome_policy = std::conditional_t<                                                                                                       //
  detail::is_same_or_constructible<std::error_code, S> && trait::is_exception_ptr<P>::value, error_code_throw_as_system_error_exception_rethrow<R, S, P>,  //
  terminate                                                                                                                                                //
  >;
#else
  template <class R, class S, class P> using default_outcome_policy = terminate;
#endif
}

namespace detail
{
  template <class Base, class R, class S, class P, class NoValuePolicy> using select_outcome_observers_payload_or_exception = std::conditional_t<trait::is_exception_ptr<P>::value, impl::outcome_exception_observers<Base, R, S, P, NoValuePolicy>, impl::outcome_payload_observers<Base, R, S, P, NoValuePolicy>>;
  template <class R, class S, class P, class NoValuePolicy> using select_outcome_impl = select_outcome_observers_payload_or_exception<impl::result_final<R, S, NoValuePolicy>, R, S, P, NoValuePolicy>;
}

/*! Used to return from functions (i) a value and (a positive status and/or a payload) or
(ii) no value and (a negative status and/or a payload). `constexpr` capable.
\module outcome<R, S, P> implementation
\tparam R The optional type of the successful result (use `void` to disable).
\tparam S The optional type of the status result (use `void` to disable). Must be either `void` or DefaultConstructible.
\tparam P The optional type of the payload/exception result (use `void` to disable). Must be either `void` or DefaultConstructible.
\tparam NoValuePolicy Policy on how to interpret types `S` and `P` when a wide observation of a not present value occurs.
*/
template <class R,                       //
          class S = std::error_code,     //
          class P = std::exception_ptr,  //
          class NoValuePolicy = policy::default_outcome_policy<R, S, P>>
class OUTCOME_NODISCARD outcome : public detail::select_outcome_impl<R, S, P, NoValuePolicy>
{
  friend NoValuePolicy;
  using base = detail::select_outcome_impl<R, S, P, NoValuePolicy>;
  friend base;
  template <class T, class U, class V, class W> friend class outcome;
  static_assert(std::is_void<P>::value || std::is_default_constructible<P>::value, "payload_type/exception_type must be default constructible");

  struct value_converting_constructor_tag
  {
  };
  struct value_status_converting_constructor_tag
  {
  };
  struct value_payload_converting_constructor_tag
  {
  };
  struct value_status_payload_converting_constructor_tag
  {
  };
  struct error_converting_constructor_tag
  {
  };
  struct error_payload_converting_constructor_tag
  {
  };
  struct payload_converting_constructor_tag
  {
  };

public:
  /// \output_section Member types
  //! The success type.
  using value_type = typename base::value_type;
  //! The S type configured
  using status_error_type = typename base::status_error_type;
#if OUTCOME_ENABLE_POSITIVE_STATUS
  //! The status type, always `no_status_type` if `trait::status_type_is_negative<S>` is true.
  using status_type = typename base::status_type;
#endif
  //! The failure type, always `no_error_type` if `trait::status_type_is_negative<S>` is false.
  using error_type = typename base::error_type;
  //! The P type configured.
  using payload_exception_type = P;
  //! The payload type, always `no_payload_type` if `trait::is_exception_ptr<P>` is true.
  using payload_type = std::conditional_t<!trait::is_exception_ptr<P>::value, no_payload_type, P>;
  //! The exception type, always `no_exception_type` if `trait::is_exception_ptr<P>` is false.
  using exception_type = std::conditional_t<trait::is_exception_ptr<P>::value, no_exception_type, P>;

protected:
  detail::devoid<payload_exception_type> _ptr;

public:
  /// \output_section Converting constructors
  /*! Converting constructor to a successful outcome.
  \tparam enable_value_converting_constructor
  \exclude
  \param 1
  \exclude
  \param t The value from which to initialise the `value_type`.

  \effects Initialises the outcome with a `value_type`.
  \requires Type T is constructible to `value_type`, is not constructible to `status_error_type`, is not constructible to `payload_exception_type` and is not `outcome<R, S, P>` and not `in_place_type<>`.
  \throws Any exception the construction of `value_type(T)` might throw.
  */
  template <class T, typename enable_value_converting_constructor = std::enable_if_t<  //
                     !std::is_same<std::decay_t<T>, outcome>::value                    // not my type
                     && !detail::is_in_place_type_t<std::decay_t<T>>::value            // not in place construction
                     && detail::is_same_or_constructible<value_type, T> && !std::is_constructible<status_error_type, T>::value && !std::is_constructible<payload_exception_type, T>::value>>
  constexpr outcome(T &&t, value_converting_constructor_tag = value_converting_constructor_tag()) noexcept(std::is_nothrow_constructible<value_type, T>::value)
      : base(in_place_type<value_type>, std::forward<T>(t))
      , _ptr()
  {
  }
#if OUTCOME_ENABLE_POSITIVE_STATUS
  /*! Converting constructor to a successful outcome + status.
\tparam enable_value_status_converting_constructor
\exclude
\param 2
\exclude
\param t The value from which to initialise the `value_type`.
\param u The value from which to initialise the `status_type`.

\effects Initialises the outcome with a `value_type` and an additional `status_type`.
\requires `trait::status_type_is_negative<EC>` must be false; Type `T` is constructible to `value_type`, is not constructible to `status_type`
is not constructible to `payload_exception_type`, and is not `outcome<R, S, P>` and not `in_place_type<>`;
Type `U` is constructible to `status_type`, is not constructible to `value_type`, and is not constructible to `payload_exception_type`.
\throws Any exception the construction of `value_type(T)` and `status_type(U)` might throw.
*/
  template <class T, class U, typename enable_value_status_converting_constructor = std::enable_if_t<                                                                                          //
                              !std::is_same<std::decay_t<T>, outcome>::value                                                                                                                   // not my type
                              && !detail::is_in_place_type_t<std::decay_t<T>>::value                                                                                                           // not in place construction
                              && detail::is_same_or_constructible<value_type, T> && !std::is_constructible<status_type, T>::value && !std::is_constructible<payload_exception_type, T>::value  //
                              && detail::is_same_or_constructible<status_type, U> && !std::is_constructible<value_type, U>::value && !std::is_constructible<payload_exception_type, U>::value>>
  constexpr outcome(T &&t, U &&u, value_status_converting_constructor_tag = value_status_converting_constructor_tag()) noexcept(std::is_nothrow_constructible<value_type, T>::value &&std::is_nothrow_constructible<status_type, U>::value)
      : base(typename base::value_status_construction_tag(), std::forward<T>(t), std::forward<U>(u))
      , _ptr()
  {
  }
  /*! Converting constructor to a successful outcome + status + payload/exception_ptr.
  \tparam enable_value_status_payload_converting_constructor
  \exclude
  \param 3
  \exclude
  \param t The value from which to initialise the `value_type`.
  \param u The value from which to initialise the `status_type`.
  \param v The value from which to initialise the `payload_exception_type`.

  \effects Initialises the outcome with a `value_type`, a `status_type` and a `payload_exception_type`.
  \requires `trait::status_type_is_negative<EC>` must be false; Type `T` is constructible to `value_type`, is not constructible to `status_type`
  is not constructible to `payload_exception_type`, and is not `outcome<R, S, P>` and not `in_place_type<>`;
  Type `U` is constructible to `status_type`, is not constructible to `value_type`, and is not constructible to `payload_exception_type`;
  Type `V` is constructible to `payload_exception_type`, is not constructible to `value_type`, and is not constructible to `status_type`.
  \throws Any exception the construction of `value_type(T)`, `status_type(U)` and `payload_exception_type(V)` might throw.
  */
  template <class T, class U, class V, typename enable_value_status_payload_converting_constructor = std::enable_if_t<                                                                                  //
                                       !std::is_same<std::decay_t<T>, outcome>::value                                                                                                                   // not my type
                                       && !detail::is_in_place_type_t<std::decay_t<T>>::value                                                                                                           // not in place construction
                                       && detail::is_same_or_constructible<value_type, T> && !std::is_constructible<status_type, T>::value && !std::is_constructible<payload_exception_type, T>::value  //
                                       && detail::is_same_or_constructible<status_type, U> && !std::is_constructible<value_type, U>::value && !std::is_constructible<payload_exception_type, U>::value  //
                                       && detail::is_same_or_constructible<payload_exception_type, V> && !std::is_constructible<value_type, V>::value && !std::is_constructible<status_type, V>::value  //
                                       >>
  constexpr outcome(T &&t, U &&u, V &&v,
                    value_status_payload_converting_constructor_tag = value_status_payload_converting_constructor_tag()) noexcept(std::is_nothrow_constructible<value_type, T>::value &&std::is_nothrow_constructible<status_type, U>::value &&std::is_nothrow_constructible<payload_exception_type, V>::value)
      : base(typename base::value_status_construction_tag(), std::forward<T>(t), std::forward<U>(u))
      , _ptr(std::forward<V>(v))
  {
    this->_state._status |= detail::status_have_payload;
  }
#endif
  /*! Converting constructor to a successful outcome + payload.
  \tparam enable_value_payload_converting_constructor_tag
  \exclude
  \param 2
  \exclude
  \param t The value from which to initialise the `value_type`.
  \param u The value from which to initialise the `payload_type`.

  \effects Initialises the outcome with a `value_type` and a `payload_type`.
  \requires `trait::is_exception_ptr<P>` must be false; Type `T` is constructible to `value_type`, is not constructible to `status_error_type`,
  is not constructible to `payload_type`, and is not `outcome<R, S, P>` and not `in_place_type<>`;
  Type `U` is constructible to `payload_type`, is not constructible to `value_type`, and is not constructible to `status_error_type`.
  \throws Any exception the construction of `value_type(T)` and `payload_type(U)` might throw.
  */
  template <class T, class U, typename enable_value_payload_converting_constructor_tag = std::enable_if_t<                                                                                           //
                              !std::is_same<std::decay_t<T>, outcome>::value                                                                                                                         // not my type
                              && !detail::is_in_place_type_t<std::decay_t<T>>::value                                                                                                                 // not in place construction
                              && detail::is_same_or_constructible<value_type, T> && !std::is_constructible<status_error_type, T>::value && !std::is_constructible<payload_exception_type, T>::value  //
                              && detail::is_same_or_constructible<payload_exception_type, U> && !std::is_constructible<value_type, U>::value && !std::is_constructible<status_error_type, U>::value>>
  constexpr outcome(T &&t, U &&u, value_payload_converting_constructor_tag = value_payload_converting_constructor_tag()) noexcept(std::is_nothrow_constructible<value_type, T>::value &&std::is_nothrow_constructible<payload_exception_type, U>::value)
      : base(in_place_type<value_type>, std::forward<T>(t))
      , _ptr(std::forward<U>(u))
  {
  }
  /*! Converting constructor to an errored outcome.
\tparam enable_error_converting_constructor
\exclude
\param 1
\exclude
\param t The value from which to initialise the `error_type`.

\effects Initialises the outcome with a `error_type`.
\requires `trait::status_type_is_negative<EC>` must be true; Type T is constructible to `error_type`,
is not constructible to `value_type`, is not constructible to `payload_exception_type`, and is not `outcome<R, S, P>` and not `in_place_type<>`.
\throws Any exception the construction of `error_type(T)` might throw.
*/
  template <class T, typename enable_error_converting_constructor = std::enable_if_t<  //
                     !std::is_same<std::decay_t<T>, outcome>::value                    // not my type
                     && !detail::is_in_place_type_t<std::decay_t<T>>::value            // not in place construction
                     && !std::is_constructible<value_type, T>::value && detail::is_same_or_constructible<error_type, T> && !std::is_constructible<payload_exception_type, T>::value>>
  constexpr outcome(T &&t, error_converting_constructor_tag = error_converting_constructor_tag()) noexcept(std::is_nothrow_constructible<error_type, T>::value)
      : base(in_place_type<error_type>, std::forward<T>(t))
      , _ptr()
  {
  }
  /*! Converting constructor to an errored outcome + payload/exception.
  \tparam enable_error_payload_converting_constructor
  \exclude
  \param 2
  \exclude
  \param t The value from which to initialise the `error_type`.
  \param u The value from which to initialise the `payload_exception_type`.

  \effects Initialises the outcome with a `error_type` and a `payload_exception_type`.
  \requires `trait::status_type_is_negative<EC>` must be true; Type T is constructible to `error_type`,
  is not constructible to `value_type`, is not constructible to `payload_exception_type`, and is not `outcome<R, S, P>` and not `in_place_type<>`;
  Type `U` is constructible to `payload_exception_type`, is not constructible to `value_type`, and is not constructible to `error_type`.
  \throws Any exception the construction of `error_type(T)` and `payload_exception_type(U)` might throw.
  */
  template <class T, class U, typename enable_error_payload_converting_constructor = std::enable_if_t<                                                                                        //
                              !std::is_same<std::decay_t<T>, outcome>::value                                                                                                                  // not my type
                              && !detail::is_in_place_type_t<std::decay_t<T>>::value                                                                                                          // not in place construction
                              && !std::is_constructible<value_type, T>::value && detail::is_same_or_constructible<error_type, T> && !std::is_constructible<payload_exception_type, T>::value  //
                              && detail::is_same_or_constructible<payload_exception_type, U> && !std::is_constructible<value_type, U>::value && !std::is_constructible<error_type, U>::value>>
  constexpr outcome(T &&t, U &&u, error_payload_converting_constructor_tag = error_payload_converting_constructor_tag()) noexcept(std::is_nothrow_constructible<error_type, T>::value &&std::is_nothrow_constructible<payload_exception_type, U>::value)
      : base(in_place_type<error_type>, std::forward<T>(t))
      , _ptr(std::forward<U>(u))
  {
    this->_state._status |= trait::is_exception_ptr<payload_exception_type>::value ? detail::status_have_exception : detail::status_have_payload;
  }
  /*! Converting copy constructor from a compatible outcome type.
  \tparam enable_compatible_conversion
  \exclude
  \param o The compatible outcome.

  \effects Initialises the outcome with a copy of the compatible outcome.
  \requires Both outcome's `value_type`, `error_type`, `status_type`, `payload_type` and `exception_type` need to be constructible, or the source `void`.
  \throws Any exception the construction of `value_type(T)`, `status_error_type(U)` or `payload_exception_type(V)` might throw.
  */
  template <class T, class U, class V, class W, typename enable_compatible_conversion = std::enable_if_t<                                                              //
                                                !std::is_same<outcome<T, U, V, W>, outcome>::value                                                                     // not my type
                                                && (std::is_void<T>::value || detail::is_same_or_constructible<value_type, typename outcome<T, U, V, W>::value_type>)  // if our value types are constructible
                                                &&(std::is_void<U>::value || detail::is_same_or_constructible<error_type, typename outcome<T, U, V, W>::error_type>)   // if our error types are constructible
#if OUTCOME_ENABLE_POSITIVE_STATUS
                                                &&(std::is_void<U>::value || detail::is_same_or_constructible<status_type, typename outcome<T, U, V, W>::status_type>)  // if our status types are constructible
#endif
                                                &&(std::is_void<V>::value || detail::is_same_or_constructible<payload_type, typename outcome<T, U, V, W>::payload_type>)      // if our payload types are constructible
                                                &&(std::is_void<V>::value || detail::is_same_or_constructible<exception_type, typename outcome<T, U, V, W>::exception_type>)  // if our exception types are constructible
                                                >>
  constexpr explicit outcome(const outcome<T, U, V, W> &o) noexcept(std::is_nothrow_constructible<value_type, T>::value &&std::is_nothrow_constructible<status_error_type, U>::value &&std::is_nothrow_constructible<payload_exception_type, V>::value)
      : base(typename base::compatible_conversion_tag(), o)
      , _ptr(o._ptr)
  {
  }
  /*! Converting move constructor from a compatible outcome type.
  \tparam enable_compatible_conversion
  \exclude
  \param o The compatible outcome.

  \effects Initialises the outcome with a move of the compatible outcome.
      \requires Both outcome's `value_type`, `error_type`, `status_type`, `payload_type` and `exception_type` need to be constructible, or the source `void`.
      \throws Any exception the construction of `value_type(T)`, `status_error_type(U)` or `payload_exception_type(V)` might throw.
      */
  template <class T, class U, class V, class W, typename enable_compatible_conversion = std::enable_if_t<                                                              //
                                                !std::is_same<outcome<T, U, V, W>, outcome>::value                                                                     // not my type
                                                && (std::is_void<T>::value || detail::is_same_or_constructible<value_type, typename outcome<T, U, V, W>::value_type>)  // if our value types are constructible
                                                &&(std::is_void<U>::value || detail::is_same_or_constructible<error_type, typename outcome<T, U, V, W>::error_type>)   // if our error types are constructible
#if OUTCOME_ENABLE_POSITIVE_STATUS
                                                &&(std::is_void<U>::value || detail::is_same_or_constructible<status_type, typename outcome<T, U, V, W>::status_type>)  // if our status types are constructible
#endif
                                                &&(std::is_void<V>::value || detail::is_same_or_constructible<payload_type, typename outcome<T, U, V, W>::payload_type>)      // if our payload types are constructible
                                                &&(std::is_void<V>::value || detail::is_same_or_constructible<exception_type, typename outcome<T, U, V, W>::exception_type>)  // if our exception types are constructible
                                                >>
  constexpr explicit outcome(outcome<T, U, V, W> &&o) noexcept(std::is_nothrow_constructible<value_type, T>::value &&std::is_nothrow_constructible<status_error_type, U>::value &&std::is_nothrow_constructible<payload_exception_type, V>::value)
      : base(typename base::compatible_conversion_tag(), std::move(o))
      , _ptr(std::move(o._ptr))
  {
  }
  /*! Converting copy constructor from a compatible result type.
  \tparam enable_compatible_conversion
  \exclude
  \param o The compatible result.

  \effects Initialises the outcome with a copy of the compatible result.
  \requires Both outcome's `value_type`, `error_type` and `status_type` need to be constructible, or the source `void`.
  \throws Any exception the construction of `value_type(T)`, `status_error_type(U)` or `payload_exception_type()` might throw.
  */
  template <class T, class U, class V, typename enable_compatible_conversion = std::enable_if_t<                                                         //
                                       (std::is_void<T>::value || detail::is_same_or_constructible<value_type, typename result<T, U, V>::value_type>)    // if our value types are constructible
                                       &&(std::is_void<U>::value || detail::is_same_or_constructible<error_type, typename result<T, U, V>::error_type>)  // if our error types are constructible
#if OUTCOME_ENABLE_POSITIVE_STATUS
                                       &&(std::is_void<U>::value || detail::is_same_or_constructible<status_type, typename result<T, U, V>::status_type>)  // if our status types are constructible
#endif
                                       >>
  constexpr explicit outcome(const result<T, U, V> &o) noexcept(std::is_nothrow_constructible<value_type, T>::value &&std::is_nothrow_constructible<status_error_type, U>::value &&std::is_nothrow_constructible<payload_exception_type>::value)
      : base(typename base::compatible_conversion_tag(), o)
      , _ptr()
  {
  }
  /*! Converting move constructor from a compatible result type.
  \tparam enable_compatible_conversion
  \exclude
  \param o The compatible result.

  \effects Initialises the outcome with a move of the compatible result.
  \requires Both outcome's `value_type`, `error_type` and `status_type` need to be constructible, or the source `void`.
  \throws Any exception the construction of `value_type(T)`, `status_error_type(U)` or `payload_exception_type()` might throw.
  */
  template <class T, class U, class V, typename enable_compatible_conversion = std::enable_if_t<                                                         //
                                       (std::is_void<T>::value || detail::is_same_or_constructible<value_type, typename result<T, U, V>::value_type>)    // if our value types are constructible
                                       &&(std::is_void<U>::value || detail::is_same_or_constructible<error_type, typename result<T, U, V>::error_type>)  // if our error types are constructible
#if OUTCOME_ENABLE_POSITIVE_STATUS
                                       &&(std::is_void<U>::value || detail::is_same_or_constructible<status_type, typename result<T, U, V>::status_type>)  // if our status types are constructible
#endif
                                       >>
  constexpr explicit outcome(result<T, U, V> &&o) noexcept(std::is_nothrow_constructible<value_type, T>::value &&std::is_nothrow_constructible<status_error_type, U>::value &&std::is_nothrow_constructible<payload_exception_type>::value)
      : base(typename base::compatible_conversion_tag(), std::move(o))
      , _ptr()
  {
  }

  /// \output_section In place constructors
  /*! Inplace constructor to a successful value.
  \tparam 1
  \exclude
  \param _ Tag type to indicate we are doing in place construction of `value_type`.
  \param args Arguments with which to in place construct.

  \effects Initialises the outcome with a `value_type`.
  \requires `value_type` is void or `Args...` are constructible to `value_type`.
  \throws Any exception the construction of `value_type(Args...)` might throw.
  */
  template <class... Args, typename = std::enable_if_t<std::is_void<value_type>::value || std::is_constructible<value_type, Args...>::value>>
  constexpr explicit outcome(in_place_type_t<value_type> _, Args &&... args) noexcept(std::is_nothrow_constructible<value_type, Args...>::value)
      : base(_, std::forward<Args>(args)...)
      , _ptr()
  {
  }
  /*! Inplace constructor to a successful value.
  \tparam 2
  \exclude
  \param _ Tag type to indicate we are doing in place construction of `value_type`.
  \param il An initializer list with which to in place construct.
  \param args Arguments with which to in place construct.

  \effects Initialises the outcome with a `value_type`.
  \requires The initializer list + `Args...` are constructible to `value_type`.
  \throws Any exception the construction of `value_type(il, Args...)` might throw.
  */
  template <class U, class... Args, typename = std::enable_if_t<std::is_constructible<value_type, std::initializer_list<U>, Args...>::value>>
  constexpr explicit outcome(in_place_type_t<value_type> _, std::initializer_list<U> il, Args &&... args) noexcept(std::is_nothrow_constructible<value_type, std::initializer_list<U>, Args...>::value)
      : base(_, il, std::forward<Args>(args)...)
      , _ptr()
  {
  }
  /*! Inplace constructor to an unsuccessful error.
  \tparam 1
  \exclude
  \param _ Tag type to indicate we are doing in place construction of `error_type`.
  \param args Arguments with which to in place construct.

  \effects Initialises the outcome with a `error_type`.
  \requires `trait::status_type_is_negative<EC>` must be true; `error_type` is void or `Args...` are constructible to `error_type`.
  \throws Any exception the construction of `error_type(Args...)` might throw.
  */
  template <class... Args, typename = std::enable_if_t<std::is_void<error_type>::value || std::is_constructible<error_type, Args...>::value>>
  constexpr explicit outcome(in_place_type_t<error_type> _, Args &&... args) noexcept(std::is_nothrow_constructible<error_type, Args...>::value)
      : base(_, std::forward<Args>(args)...)
      , _ptr()
  {
  }
  /*! Inplace constructor to an unsuccessful error.
  \tparam 2
  \exclude
  \param _ Tag type to indicate we are doing in place construction of `error_type`.
  \param il An initializer list with which to in place construct.
  \param args Arguments with which to in place construct.

  \effects Initialises the outcome with a `error_type`.
  \requires `trait::status_type_is_negative<EC>` must be true; The initializer list + `Args...` are constructible to `error_type`.
  \throws Any exception the construction of `error_type(il, Args...)` might throw.
  */
  template <class U, class... Args, typename = std::enable_if_t<std::is_constructible<error_type, std::initializer_list<U>, Args...>::value>>
  constexpr explicit outcome(in_place_type_t<error_type> _, std::initializer_list<U> il, Args &&... args) noexcept(std::is_nothrow_constructible<error_type, std::initializer_list<U>, Args...>::value)
      : base(_, il, std::forward<Args>(args)...)
      , _ptr()
  {
  }
  /*! Inplace constructor to an unsuccessful payload/exception.
  \tparam 1
  \exclude
  \param _ Tag type to indicate we are doing in place construction of `payload_exception_type`.
  \param args Arguments with which to in place construct.

  \effects Initialises the outcome with a `payload_exception_type`.
  \requires `payload_exception_type` is void or `Args...` are constructible to `payload_exception_type`.
  \throws Any exception the construction of `payload_exception_type(Args...)` might throw.
  */
  template <class... Args, typename = std::enable_if_t<std::is_void<payload_exception_type>::value || std::is_constructible<payload_exception_type, Args...>::value>>
  constexpr explicit outcome(in_place_type_t<payload_exception_type> _, Args &&... args) noexcept(std::is_nothrow_constructible<payload_exception_type, Args...>::value)
      : base()
      , _ptr(std::forward<Args>(args)...)
  {
    this->_state._status |= trait::is_exception_ptr<payload_exception_type>::value ? detail::status_have_exception : detail::status_have_payload;
  }
  /*! Inplace constructor to an unsuccessful payload/exception.
  \tparam 2
  \exclude
  \param _ Tag type to indicate we are doing in place construction of `payload_exception_type`.
  \param il An initializer list with which to in place construct.
  \param args Arguments with which to in place construct.

  \effects Initialises the outcome with a `payload_exception_type`.
  \requires The initializer list + `Args...` are constructible to `payload_exception_type`.
  \throws Any exception the construction of `payload_exception_type(il, Args...)` might throw.
  */
  template <class U, class... Args, typename = std::enable_if_t<std::is_constructible<payload_exception_type, std::initializer_list<U>, Args...>::value>>
  constexpr explicit outcome(in_place_type_t<payload_exception_type> _, std::initializer_list<U> il, Args &&... args) noexcept(std::is_nothrow_constructible<payload_exception_type, std::initializer_list<U>, Args...>::value)
      : base()
      , _ptr(il, std::forward<Args>(args)...)
  {
    this->_state._status |= trait::is_exception_ptr<payload_exception_type>::value ? detail::status_have_exception : detail::status_have_payload;
  }
};

namespace policy
{
#ifdef __cpp_exceptions
  /*! Policy interpreting S as a type implementing the `std::error_code` contract, E as
  a type implementing the `std::exception_ptr` contract, and any wide attempt to access the
  successful state throws the `exception_ptr` if available, then the `error_code` wrapped
  into a `std::system_error`.
  \module Error code interpretation policy
  */
  template <class R, class S, class P> struct error_code_throw_as_system_error_exception_rethrow
  {
    static_assert(std::is_convertible<std::error_code, S>::value, "error_type must be convertible into a std::error_code to be used with this policy");
    static_assert(std::is_convertible<std::exception_ptr, P>::value, "exception_type must be convertible into a std::exception_ptr to be used with this policy");
    /*! Performs a narrow check of state, used in the assume_value() functions.
    \effects None.
    */
    template <class Impl> static constexpr void narrow_value_check(Impl *self) noexcept
    {
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
#if defined(__GNUC__) || defined(__clang__)
      if((self->_state._status & detail::status_have_status) == 0)
        __builtin_unreachable();
#endif
    }
#endif
    /*! Performs a narrow check of state, used in the assume_payload() functions.
    \effects None.
    */
    template <class Impl> static constexpr void narrow_payload_check(Impl *self) noexcept
    {
#if defined(__GNUC__) || defined(__clang__)
      if((self->_state._status & detail::status_have_payload) == 0)
        __builtin_unreachable();
#endif
    }
    /*! Performs a narrow check of state, used in the assume_exception() functions.
    \effects None.
    */
    template <class Impl> static constexpr void narrow_exception_check(Impl *self) noexcept
    {
#if defined(__GNUC__) || defined(__clang__)
      if((self->_state._status & detail::status_have_exception) == 0)
        __builtin_unreachable();
#endif
    }
    /*! Performs a wide check of state, used in the value() functions.
    \effects If outcome does not have a value, if it has an exception it rethrows it via `std::rethrow_exception()`,
    if has an error it throws a `std::system_error(error())`, else it throws `bad_outcome_access`.
    */
    template <class Impl> static constexpr void wide_value_check(Impl *self)
    {
      if((self->_state._status & detail::status_have_value) == 0)
      {
        if((self->_state._status & detail::status_have_exception) != 0)
        {
          auto *_self = static_cast<const outcome<R, S, P, error_code_throw_as_system_error_exception_rethrow> *>(self);
          std::rethrow_exception(_self->_ptr);
        }
        if((self->_state._status & detail::status_have_error) != 0)
        {
          throw std::system_error(self->_error);
        }
        throw bad_outcome_access("no value");
      }
    }
    /*! Performs a wide check of state, used in the error() functions
    \effects If outcome does not have an error, it throws `bad_outcome_access`.
    */
    template <class Impl> static constexpr void wide_error_check(Impl *self)
    {
      if((self->_state._status & detail::status_have_error) == 0)
      {
        throw bad_outcome_access("no error");
      }
    }
#if OUTCOME_ENABLE_POSITIVE_STATUS
    /*! Performs a wide check of state, used in the status() functions
\effects If outcome does not have an status, it throws `bad_outcome_access`.
*/
    template <class Impl> static constexpr void wide_status_check(Impl *self)
    {
      if((self->_state._status & detail::status_have_status) == 0)
      {
        throw bad_outcome_access("no status");
      }
    }
#endif
    /*! Performs a wide check of state, used in the payload() functions
    \effects If outcome does not have a payload, it throws `bad_outcome_access`.
    */
    template <class Impl> static constexpr void wide_payload_check(Impl *self)
    {
      if((self->_state._status & detail::status_have_payload) == 0)
      {
        throw bad_outcome_access("no payload");
      }
    }
    /*! Performs a wide check of state, used in the exception() functions
    \effects If outcome does not have an exception, it throws `bad_outcome_access`.
    */
    template <class Impl> static constexpr void wide_exception_check(Impl *self)
    {
      if((self->_state._status & detail::status_have_exception) == 0)
      {
        throw bad_outcome_access("no exception");
      }
    }
  };
#endif
}
namespace impl
{
  template <class Base, class R, class S, class P, class NoValuePolicy> inline constexpr typename outcome_payload_observers<Base, R, S, P, NoValuePolicy>::payload_type &outcome_payload_observers<Base, R, S, P, NoValuePolicy>::assume_payload() & noexcept
  {
    auto *self = static_cast<outcome<R, S, P, NoValuePolicy> *>(this);
    NoValuePolicy::narrow_payload_check(this);
    return self->_ptr;
  }
  template <class Base, class R, class S, class P, class NoValuePolicy> inline constexpr const typename outcome_payload_observers<Base, R, S, P, NoValuePolicy>::payload_type &outcome_payload_observers<Base, R, S, P, NoValuePolicy>::assume_payload() const &noexcept
  {
    auto *self = static_cast<const outcome<R, S, P, NoValuePolicy> *>(this);
    NoValuePolicy::narrow_payload_check(this);
    return self->_ptr;
  }
  template <class Base, class R, class S, class P, class NoValuePolicy> inline constexpr typename outcome_payload_observers<Base, R, S, P, NoValuePolicy>::payload_type &&outcome_payload_observers<Base, R, S, P, NoValuePolicy>::assume_payload() && noexcept
  {
    auto *self = static_cast<outcome<R, S, P, NoValuePolicy> *>(this);
    NoValuePolicy::narrow_payload_check(this);
    return std::move(self->_ptr);
  }
  template <class Base, class R, class S, class P, class NoValuePolicy> inline constexpr const typename outcome_payload_observers<Base, R, S, P, NoValuePolicy>::payload_type &&outcome_payload_observers<Base, R, S, P, NoValuePolicy>::assume_payload() const &&noexcept
  {
    auto *self = static_cast<const outcome<R, S, P, NoValuePolicy> *>(this);
    NoValuePolicy::narrow_payload_check(this);
    return std::move(self->_ptr);
  }

  template <class Base, class R, class S, class P, class NoValuePolicy> inline constexpr typename outcome_payload_observers<Base, R, S, P, NoValuePolicy>::payload_type &outcome_payload_observers<Base, R, S, P, NoValuePolicy>::payload() &
  {
    auto *self = static_cast<outcome<R, S, P, NoValuePolicy> *>(this);
    NoValuePolicy::wide_payload_check(this);
    return self->_ptr;
  }
  template <class Base, class R, class S, class P, class NoValuePolicy> inline constexpr const typename outcome_payload_observers<Base, R, S, P, NoValuePolicy>::payload_type &outcome_payload_observers<Base, R, S, P, NoValuePolicy>::payload() const &
  {
    auto *self = static_cast<const outcome<R, S, P, NoValuePolicy> *>(this);
    NoValuePolicy::wide_payload_check(this);
    return self->_ptr;
  }
  template <class Base, class R, class S, class P, class NoValuePolicy> inline constexpr typename outcome_payload_observers<Base, R, S, P, NoValuePolicy>::payload_type &&outcome_payload_observers<Base, R, S, P, NoValuePolicy>::payload() &&
  {
    auto *self = static_cast<outcome<R, S, P, NoValuePolicy> *>(this);
    NoValuePolicy::wide_payload_check(this);
    return std::move(self->_ptr);
  }
  template <class Base, class R, class S, class P, class NoValuePolicy> inline constexpr const typename outcome_payload_observers<Base, R, S, P, NoValuePolicy>::payload_type &&outcome_payload_observers<Base, R, S, P, NoValuePolicy>::payload() const &&
  {
    auto *self = static_cast<const outcome<R, S, P, NoValuePolicy> *>(this);
    NoValuePolicy::wide_payload_check(this);
    return std::move(self->_ptr);
  }

  template <class Base, class R, class S, class P, class NoValuePolicy> inline constexpr typename outcome_exception_observers<Base, R, S, P, NoValuePolicy>::exception_type &outcome_exception_observers<Base, R, S, P, NoValuePolicy>::assume_exception() & noexcept
  {
    auto *self = static_cast<outcome<R, S, P, NoValuePolicy> *>(this);
    NoValuePolicy::narrow_exception_check(this);
    return self->_ptr;
  }
  template <class Base, class R, class S, class P, class NoValuePolicy> inline constexpr const typename outcome_exception_observers<Base, R, S, P, NoValuePolicy>::exception_type &outcome_exception_observers<Base, R, S, P, NoValuePolicy>::assume_exception() const &noexcept
  {
    auto *self = static_cast<const outcome<R, S, P, NoValuePolicy> *>(this);
    NoValuePolicy::narrow_exception_check(this);
    return self->_ptr;
  }
  template <class Base, class R, class S, class P, class NoValuePolicy> inline constexpr typename outcome_exception_observers<Base, R, S, P, NoValuePolicy>::exception_type &&outcome_exception_observers<Base, R, S, P, NoValuePolicy>::assume_exception() && noexcept
  {
    auto *self = static_cast<outcome<R, S, P, NoValuePolicy> *>(this);
    NoValuePolicy::narrow_exception_check(this);
    return std::move(self->_ptr);
  }
  template <class Base, class R, class S, class P, class NoValuePolicy> inline constexpr const typename outcome_exception_observers<Base, R, S, P, NoValuePolicy>::exception_type &&outcome_exception_observers<Base, R, S, P, NoValuePolicy>::assume_exception() const &&noexcept
  {
    auto *self = static_cast<const outcome<R, S, P, NoValuePolicy> *>(this);
    NoValuePolicy::narrow_exception_check(this);
    return std::move(self->_ptr);
  }

  template <class Base, class R, class S, class P, class NoValuePolicy> inline constexpr typename outcome_exception_observers<Base, R, S, P, NoValuePolicy>::exception_type &outcome_exception_observers<Base, R, S, P, NoValuePolicy>::exception() &
  {
    auto *self = static_cast<outcome<R, S, P, NoValuePolicy> *>(this);
    NoValuePolicy::wide_exception_check(this);
    return self->_ptr;
  }
  template <class Base, class R, class S, class P, class NoValuePolicy> inline constexpr const typename outcome_exception_observers<Base, R, S, P, NoValuePolicy>::exception_type &outcome_exception_observers<Base, R, S, P, NoValuePolicy>::exception() const &
  {
    auto *self = static_cast<const outcome<R, S, P, NoValuePolicy> *>(this);
    NoValuePolicy::wide_exception_check(this);
    return self->_ptr;
  }
  template <class Base, class R, class S, class P, class NoValuePolicy> inline constexpr typename outcome_exception_observers<Base, R, S, P, NoValuePolicy>::exception_type &&outcome_exception_observers<Base, R, S, P, NoValuePolicy>::exception() &&
  {
    auto *self = static_cast<outcome<R, S, P, NoValuePolicy> *>(this);
    NoValuePolicy::wide_exception_check(this);
    return std::move(self->_ptr);
  }
  template <class Base, class R, class S, class P, class NoValuePolicy> inline constexpr const typename outcome_exception_observers<Base, R, S, P, NoValuePolicy>::exception_type &&outcome_exception_observers<Base, R, S, P, NoValuePolicy>::exception() const &&
  {
    auto *self = static_cast<const outcome<R, S, P, NoValuePolicy> *>(this);
    NoValuePolicy::wide_exception_check(this);
    return std::move(self->_ptr);
  }
}
OUTCOME_V2_NAMESPACE_END

#endif
