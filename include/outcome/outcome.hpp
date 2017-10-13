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

#include "detail/outcome_exception_observers.hpp"
#include "detail/outcome_failure_observers.hpp"
#include "detail/outcome_payload_observers.hpp"
#include "result.hpp"

#include <memory>

OUTCOME_V2_NAMESPACE_BEGIN

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


namespace policy
{
#ifdef __cpp_exceptions
  template <class R, class S, class P> struct error_enum_throw_as_system_error_exception_rethrow;
  template <class R, class S, class P> struct error_enum_throw_as_system_error_with_payload;
  template <class R, class S, class P> struct error_code_throw_as_system_error_exception_rethrow;
  template <class R, class S, class P> struct error_code_throw_as_system_error_with_payload;
  template <class R, class S, class P> struct exception_ptr_rethrow_with_payload;
  /*! Default `outcome<R, S, P>` policy selector.
  */
  template <class R, class S, class P>
  using default_outcome_policy =                                                                                                                                                    //
  std::conditional_t<                                                                                                                                                               //
  (std::is_error_code_enum<S>::value || std::is_error_condition_enum<S>::value) && trait::is_exception_ptr<P>::value, error_enum_throw_as_system_error_exception_rethrow<R, S, P>,  //
  std::conditional_t<                                                                                                                                                               //
  (std::is_error_code_enum<S>::value || std::is_error_condition_enum<S>::value) && !trait::is_exception_ptr<P>::value, error_enum_throw_as_system_error_with_payload<R, S, P>,      //
  std::conditional_t<                                                                                                                                                               //
  trait::is_error_code<S>::value && trait::is_exception_ptr<P>::value, error_code_throw_as_system_error_exception_rethrow<R, S, P>,                                                 //
  std::conditional_t<                                                                                                                                                               //
  trait::is_error_code<S>::value && !trait::is_exception_ptr<P>::value, error_code_throw_as_system_error_with_payload<R, S, P>,
  std::conditional_t<  //
  trait::is_exception_ptr<S>::value, exception_ptr_rethrow_with_payload<R, S, P>,
  all_narrow  //
  >>>>>;
#else
  template <class R, class S, class P> using default_outcome_policy = terminate;
#endif
}

template <class R, class S = std::error_code, class P = std::exception_ptr, class NoValuePolicy = policy::default_outcome_policy<R, S, P>>  //
OUTCOME_REQUIRES(detail::type_can_be_used_in_result<P> && (std::is_void<P>::value || std::is_default_constructible<P>::value))              //
class outcome;

namespace detail
{
  // May be reused by outcome subclasses to save load on the compiler
  template <class value_type, class error_type, class payload_exception_type, class payload_type, class exception_type> struct outcome_predicates
  {
    using result = result_predicates<value_type, error_type>;

    // Predicate for the implicit constructors to be available
    static constexpr bool implicit_constructors_enabled =                                                                     //
    (std::is_same<bool, std::decay_t<value_type>>::value || !is_same_or_constructible<value_type, error_type>)                //
    &&(std::is_same<bool, std::decay_t<value_type>>::value || !is_same_or_constructible<value_type, payload_exception_type>)  //
    &&!is_same_or_constructible<error_type, value_type>                                                                       //
    && !is_same_or_constructible<error_type, payload_exception_type>                                                          //
    && !is_same_or_constructible<payload_exception_type, value_type>                                                          //
    && !is_same_or_constructible<payload_exception_type, error_type>;

    // Predicate for the value converting constructor to be available.
    template <class T>
    static constexpr bool enable_value_converting_constructor =  //
    implicit_constructors_enabled                                //
    &&result::template enable_value_converting_constructor<T>    //
    && !std::is_constructible<exception_type, T>::value;

    // Predicate for the error converting constructor to be available.
    template <class T>
    static constexpr bool enable_error_converting_constructor =  //
    implicit_constructors_enabled                                //
    &&result::template enable_error_converting_constructor<T>    //
    && !std::is_constructible<payload_exception_type, T>::value;

    // Predicate for the error + payload/exception constructor to be available.
    template <class T, class U>
    static constexpr bool enable_error_payload_converting_constructor =                                 //
    !is_in_place_type_t<std::decay_t<T>>::value                                                         // not in place construction
    && !std::is_constructible<value_type, T>::value && detail::is_same_or_constructible<error_type, T>  //
    && detail::is_same_or_constructible<payload_exception_type, U> && !std::is_constructible<value_type, U>::value;

    // Predicate for the error condition converting constructor to be available.
    template <class ErrorCondEnum>
    static constexpr bool enable_error_condition_converting_constructor = result::template enable_error_condition_converting_constructor<ErrorCondEnum>  //
                                                                          && !std::is_constructible<payload_exception_type, ErrorCondEnum>::value;

    // Predicate for the exception converting constructor to be available.
    template <class T>
    static constexpr bool enable_exception_converting_constructor =  //
    implicit_constructors_enabled                                    //
    && !is_in_place_type_t<std::decay_t<T>>::value                   // not in place construction
    && !std::is_constructible<value_type, T>::value && !std::is_constructible<error_type, T>::value && detail::is_same_or_constructible<exception_type, T>;

    // Predicate for the converting copy constructor from a compatible outcome to be available.
    template <class T, class U, class V, class W>
    static constexpr bool enable_compatible_conversion =                                                                          //
    (std::is_void<T>::value || detail::is_same_or_constructible<value_type, typename outcome<T, U, V, W>::value_type>)            // if our value types are constructible
    &&(std::is_void<U>::value || detail::is_same_or_constructible<error_type, typename outcome<T, U, V, W>::error_type>)          // if our error types are constructible
    &&(std::is_void<V>::value || detail::is_same_or_constructible<payload_type, typename outcome<T, U, V, W>::payload_type>)      // if our payload types are constructible
    &&(std::is_void<V>::value || detail::is_same_or_constructible<exception_type, typename outcome<T, U, V, W>::exception_type>)  // if our exception types are constructible
    ;

    // Predicate for the implicit converting inplace constructor from a compatible input to be available.
    struct disable_inplace_value_error_exception_constructor;
    template <class... Args>
    using choose_inplace_value_error_exception_constructor = std::conditional_t<                                                                                                                                                  //
    ((static_cast<int>(std::is_constructible<value_type, Args...>::value) + static_cast<int>(std::is_constructible<error_type, Args...>::value) + static_cast<int>(std::is_constructible<exception_type, Args...>::value)) > 1),  //
    disable_inplace_value_error_exception_constructor,                                                                                                                                                                            //
    std::conditional_t<                                                                                                                                                                                                           //
    std::is_constructible<value_type, Args...>::value,                                                                                                                                                                            //
    value_type,                                                                                                                                                                                                                   //
    std::conditional_t<                                                                                                                                                                                                           //
    std::is_constructible<error_type, Args...>::value,                                                                                                                                                                            //
    error_type,                                                                                                                                                                                                                   //
    std::conditional_t<                                                                                                                                                                                                           //
    std::is_constructible<exception_type, Args...>::value,                                                                                                                                                                        //
    exception_type,                                                                                                                                                                                                               //
    disable_inplace_value_error_exception_constructor>>>>;
    template <class... Args>
    static constexpr bool enable_inplace_value_error_exception_constructor =  //
    implicit_constructors_enabled && !std::is_same<choose_inplace_value_error_exception_constructor<Args...>, disable_inplace_value_error_exception_constructor>::value;
  };

  struct enable_payload_from_failure
  {
  };
  struct enable_exception_from_failure
  {
  };
  template <class T, class U, class V, typename = std::enable_if_t<!trait::is_exception_ptr<V>::value>> constexpr inline const V &extract_exception_payload_from_failure(const failure_type<U, V> &v, enable_payload_from_failure = enable_payload_from_failure()) { return v.payload; }
  template <class T, class U, class V, typename = std::enable_if_t<!trait::is_exception_ptr<V>::value>> constexpr inline V &&extract_exception_payload_from_failure(failure_type<U, V> &&v, enable_payload_from_failure = enable_payload_from_failure()) { return std::move(v.payload); }
  template <class T, class U, class V, typename = std::enable_if_t<trait::is_exception_ptr<V>::value>> constexpr inline const V &extract_exception_payload_from_failure(const failure_type<U, V> &v, enable_exception_from_failure = enable_exception_from_failure()) { return v.exception; }
  template <class T, class U, class V, typename = std::enable_if_t<trait::is_exception_ptr<V>::value>> constexpr inline V &&extract_exception_payload_from_failure(failure_type<U, V> &&v, enable_exception_from_failure = enable_exception_from_failure()) { return std::move(v.exception); }
  template <class T, class U> constexpr inline T extract_exception_payload_from_failure(const failure_type<U, void> & /*unused*/) { return T{}; }

  template <class Base, class R, class S, class P, class NoValuePolicy> using select_outcome_observers_payload_or_exception = std::conditional_t<trait::is_exception_ptr<P>::value, detail::outcome_exception_observers<Base, R, S, P, NoValuePolicy>, detail::outcome_payload_observers<Base, R, S, P, NoValuePolicy>>;
  template <class R, class S, class P, class NoValuePolicy> using select_outcome_impl2 = select_outcome_observers_payload_or_exception<detail::result_final<R, S, NoValuePolicy>, R, S, P, NoValuePolicy>;
  template <class R, class S, class P, class NoValuePolicy>
  using select_outcome_impl = std::conditional_t<std::is_base_of<std::error_code, S>::value && trait::is_exception_ptr<P>::value, detail::outcome_failure_observers<select_outcome_impl2<R, S, P, NoValuePolicy>, R, S, P, NoValuePolicy>, select_outcome_impl2<R, S, P, NoValuePolicy>>;
}

namespace hooks
{
  /*! The default instantiation hook implementation called when a `outcome` is first created
  by conversion from one of its possible types. Does nothing.
  \tparam T One of `value_type`, `error_type`, `std::pair<error_type, payload_type>` or `exception_type`.

  WARNING: The compiler is permitted to elide calls to constructors, and thus this hook may not get called when you think it should!
  */
  template <class T, class U> constexpr inline void hook_outcome_construction(in_place_type_t<T> /*unused*/, U * /*unused*/) noexcept {}
  /*! The default instantiation hook implementation called when a `outcome` is created by copying
  from another `outcome` or `result`. Does nothing.
  \tparam T The type of the source.

  WARNING: The compiler is permitted to elide calls to constructors, and thus this hook may not get called when you think it should!
  */
  template <class T, class U> constexpr inline void hook_outcome_copy_construction(in_place_type_t<T> /*unused*/, U * /*unused*/) noexcept {}
  /*! The default instantiation hook implementation called when a `outcome` is created by moving
  from another `outcome` or `result`. Does nothing.
  \tparam T The type of the source.

  WARNING: The compiler is permitted to elide calls to constructors, and thus this hook may not get called when you think it should!
  */
  template <class T, class U> constexpr inline void hook_outcome_move_construction(in_place_type_t<T> /*unused*/, U * /*unused*/) noexcept {}
  /*! The default instantiation hook implementation called when a `outcome` is created by in place
  construction. Does nothing.
  \tparam T One of `value_type`, `error_type`, `std::pair<error_type, payload_type>` or `exception_type`.

  WARNING: The compiler is permitted to elide calls to constructors, and thus this hook may not get called when you think it should!
  */
  template <class T, class U> constexpr inline void hook_outcome_in_place_construction(in_place_type_t<T> /*unused*/, U * /*unused*/) noexcept {}

  template <class R, class S, class P, class NoValuePolicy, class U> constexpr inline void override_outcome_payload_exception(outcome<R, S, P, NoValuePolicy> *o, U &&v) noexcept;
}

/*! Used to return from functions one of (i) a successful value (ii) a cause of failure, with optional additional information. `constexpr` capable.
\tparam R The optional type of the successful result (use `void` to disable).
Cannot be a reference, a `in_place_type_t<>`, `success<>`, `failure<>`, an array, a function or non-destructible.
\tparam S The optional type of the failure result (use `void` to disable). Must be either `void` or `DefaultConstructible`.
Cannot be a reference, a `in_place_type_t<>`, `success<>`, `failure<>`, an array, a function or non-destructible.
\tparam P The optional type of the payload/exception result (use `void` to disable). Must be either `void` or `DefaultConstructible`.
Cannot be a reference, a `in_place_type_t<>`, `success<>`, `failure<>`, an array, a function or non-destructible.
\tparam NoValuePolicy Policy on how to interpret types `S` and `P` when a wide observation of a not present value occurs.

This is an extension of `result<T, E>` and it comes in two variants:
  1. `outcome<T, E, P>`: simply as if a `result<T, E + P>` i.e. if a failure result, there may be an additional arbitrary payload of type `P`.
  In this form, `.payload()` returns the payload and there is no `.exception()`.
  2. `outcome<T, EC, EP>`: Failure cause can be `EC` (`.error()`), or `EP` (`.exception()`) or `EC + EP` i.e. both together.
  In this form, there is no `.payload()`.

Which variant is chosen depends on `trait::is_exception_ptr<P>`. If it is true, you get the second form, if it is false you get the first form.
*/
template <class R, class S, class P, class NoValuePolicy>                                                                       //
OUTCOME_REQUIRES(detail::type_can_be_used_in_result<P> && (std::is_void<P>::value || std::is_default_constructible<P>::value))  //
class OUTCOME_NODISCARD outcome
#ifdef DOXYGEN_IS_IN_THE_HOUSE
: public detail::outcome_failure_observers<detail::outcome_exception_observers<detail::result_final<R, S, NoValuePolicy>, R, S, P, NoValuePolicy>>
#else
: public detail::select_outcome_impl<R, S, P, NoValuePolicy>
#endif
{
  static_assert(detail::type_can_be_used_in_result<P>, "The payload_type/exception_type cannot be used");
  static_assert(std::is_void<P>::value || std::is_default_constructible<P>::value, "payload_type/exception_type must be void or default constructible");
  using base = detail::select_outcome_impl<R, S, P, NoValuePolicy>;
  friend NoValuePolicy;
  friend detail::select_outcome_impl2<R, S, P, NoValuePolicy>;
  template <class T, class U, class V, class W> friend class outcome;
  template <class T, class U, class V, class W> friend inline std::istream &operator>>(std::istream &s, outcome<T, U, V, W> &v);
  template <class T, class U, class V, class W> friend inline std::ostream &operator<<(std::ostream &s, const outcome<T, U, V, W> &v);
  template <class T, class U, class V, class W, class X> friend constexpr inline void hooks::override_outcome_payload_exception(outcome<T, U, V, W> *o, X &&v) noexcept;

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
  struct error_condition_converting_constructor_tag
  {
  };
  struct error_payload_converting_constructor_tag
  {
  };
  struct exception_converting_constructor_tag
  {
  };

  struct disable_in_place_value_type
  {
  };
  struct disable_in_place_error_type
  {
  };
  struct disable_in_place_payload_exception_type
  {
  };

public:
  /// \output_section Member types
  //! The success type.
  using value_type = R;
  //! The failure type.
  using error_type = S;
  //! The P type configured.
  using payload_exception_type = P;
  //! The payload type, always `no_payload_type` if `trait::is_exception_ptr<P>` is true.
  using payload_type = std::conditional_t<trait::is_exception_ptr<P>::value, no_payload_type, P>;
  //! The exception type, always `no_exception_type` if `trait::is_exception_ptr<P>` is false.
  using exception_type = std::conditional_t<!trait::is_exception_ptr<P>::value, no_exception_type, P>;

  //! Used to rebind this outcome to a different outcome type
  template <class T, class U = S, class V = P> using rebind = outcome<T, U, P>;

protected:
  //! Requirement predicates for outcome.
  struct predicate
  {
    using base = detail::outcome_predicates<value_type, error_type, payload_exception_type, payload_type, exception_type>;

    //! Predicate for the value converting constructor to be available.
    template <class T>
    static constexpr bool enable_value_converting_constructor =  //
    !std::is_same<std::decay_t<T>, outcome>::value               // not my type
    && base::template enable_value_converting_constructor<T>;

    //! Predicate for the error converting constructor to be available.
    template <class T>
    static constexpr bool enable_error_converting_constructor =  //
    !std::is_same<std::decay_t<T>, outcome>::value               // not my type
    && base::template enable_error_converting_constructor<T>;

    // Predicate for the error + payload/exception constructor to be available.
    template <class T, class U>
    static constexpr bool enable_error_payload_converting_constructor =  //
    !std::is_same<std::decay_t<T>, outcome>::value                       // not my type
    && base::template enable_error_payload_converting_constructor<T, U>;

    //! Predicate for the error condition converting constructor to be available.
    template <class ErrorCondEnum>
    static constexpr bool enable_error_condition_converting_constructor =  //
    !std::is_same<std::decay_t<ErrorCondEnum>, outcome>::value             // not my type
    && base::template enable_error_condition_converting_constructor<ErrorCondEnum>;

    // Predicate for the exception converting constructor to be available.
    template <class T>
    static constexpr bool enable_exception_converting_constructor =  //
    !std::is_same<std::decay_t<T>, outcome>::value                   // not my type
    && base::template enable_exception_converting_constructor<T>;

    //! Predicate for the converting constructor from a compatible input to be available.
    template <class T, class U, class V, class W>
    static constexpr bool enable_compatible_conversion =  //
    !std::is_same<outcome<T, U, V, W>, outcome>::value    // not my type
    && base::template enable_compatible_conversion<T, U, V, W>;

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

    //! Predicate for the inplace construction of exception to be available.
    template <class... Args>
    static constexpr bool enable_inplace_exception_constructor =  //
    std::is_void<exception_type>::value                           //
    || std::is_constructible<exception_type, Args...>::value;

    // Predicate for the implicit converting inplace constructor to be available.
    template <class... Args>
    static constexpr bool enable_inplace_value_error_exception_constructor =  //
    base::template enable_inplace_value_error_exception_constructor<Args...>;
    template <class... Args> using choose_inplace_value_error_exception_constructor = typename base::template choose_inplace_value_error_exception_constructor<Args...>;
  };

public:
  //! Used to disable in place type construction when `value_type` is ambiguous with `error_type` or `payload_exception_type`.
  using value_type_if_enabled = std::conditional_t<std::is_same<value_type, error_type>::value || std::is_same<value_type, payload_exception_type>::value, disable_in_place_value_type, value_type>;
  //! Used to disable in place type construction when `error_type` is ambiguous with `value_type` or `payload_exception_type`.
  using error_type_if_enabled = std::conditional_t<std::is_same<error_type, value_type>::value || std::is_same<error_type, payload_exception_type>::value, disable_in_place_error_type, error_type>;
  //! Used to disable in place type construction when `payload_exception_type` is ambiguous with `value_type` or `error_type`.
  using exception_type_if_enabled = std::conditional_t<std::is_same<exception_type, value_type>::value || std::is_same<exception_type, error_type>::value, disable_in_place_payload_exception_type, exception_type>;

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
  \requires Type T is constructible to `value_type`, is not constructible to `error_type`, is not constructible to `exception_type` and is not `outcome<R, S, P>` and not `in_place_type<>`.
  \throws Any exception the construction of `value_type(T)` might throw.
  */
  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_value_converting_constructor<T>))
  constexpr outcome(T &&t, value_converting_constructor_tag = value_converting_constructor_tag()) noexcept(std::is_nothrow_constructible<value_type, T>::value)
      : base{in_place_type<typename base::_value_type>, std::forward<T>(t)}
      , _ptr()
  {
    using namespace hooks;
    hook_outcome_construction(in_place_type<value_type>, this);
  }
  /*! Converting constructor to an errored outcome.
  \tparam enable_error_converting_constructor
  \exclude
  \param 1
  \exclude
  \param t The value from which to initialise the `error_type`.

  \effects Initialises the outcome with a `error_type`.
  \requires Type T is constructible to `error_type`,
  is not constructible to `value_type`, is not constructible to `payload_exception_type`, and is not `outcome<R, S, P>` and not `in_place_type<>`.
  \throws Any exception the construction of `error_type(T)` might throw.
  */
  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_error_converting_constructor<T>))
  constexpr outcome(T &&t, error_converting_constructor_tag = error_converting_constructor_tag()) noexcept(std::is_nothrow_constructible<error_type, T>::value)
      : base{in_place_type<typename base::_error_type>, std::forward<T>(t)}
      , _ptr()
  {
    using namespace hooks;
    hook_outcome_construction(in_place_type<error_type>, this);
  }
  /*! Converting constructor to an errored outcome + payload/exception.
  \tparam enable_error_payload_converting_constructor
  \exclude
  \param 2
  \exclude
  \param t The value from which to initialise the `error_type`.
  \param u The value from which to initialise the `payload_exception_type`.

  \effects Initialises the outcome with a `error_type` and a `payload_exception_type`.
  \requires Type T is constructible to `error_type`,
  is not constructible to `value_type`, and is not `outcome<R, S, P>` and not `in_place_type<>`;
  Type `U` is constructible to `payload_exception_type`, is not constructible to `value_type`.
  \throws Any exception the construction of `error_type(T)` and `payload_exception_type(U)` might throw.
  */
  OUTCOME_TEMPLATE(class T, class U)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_error_payload_converting_constructor<T, U>))
  constexpr outcome(T &&t, U &&u, error_payload_converting_constructor_tag = error_payload_converting_constructor_tag()) noexcept(std::is_nothrow_constructible<error_type, T>::value &&std::is_nothrow_constructible<payload_exception_type, U>::value)
      : base{in_place_type<typename base::_error_type>, std::forward<T>(t)}
      , _ptr(std::forward<U>(u))
  {
    using namespace hooks;
    this->_state._status |= trait::is_exception_ptr<payload_exception_type>::value ? detail::status_have_exception : detail::status_have_payload;
    hook_outcome_construction(in_place_type<std::pair<error_type, payload_exception_type>>, this);
  }
  /*! Special error condition converting constructor to an errored outcome.
  \tparam enable_error_condition_converting_constructor
  \exclude
  \param 1
  \exclude
  \param t The error condition from which to initialise the `error_type`.

  \effects Initialises the outcome with a `error_type` constructed via `make_error_code(t)`.
  \requires `std::is_error_condition_enum<ErrorCondEnum>` must be true,
  `ErrorCondEnum` is not constructible to `value_type`, `error_type` nor `payload_exception_type`, and is not `outcome<R, S, P>` and not `in_place_type<>`;
  Finally, the expression `error_type(make_error_code(ErrorCondEnum()))` must be valid.
  \throws Any exception the construction of `error_type(make_error_code(t))` might throw.
  */
  OUTCOME_TEMPLATE(class ErrorCondEnum)
  OUTCOME_TREQUIRES(OUTCOME_TEXPR(error_type(make_error_code(ErrorCondEnum()))),  //
                    OUTCOME_TPRED(predicate::template enable_error_condition_converting_constructor<ErrorCondEnum>))
  constexpr outcome(ErrorCondEnum &&t, error_condition_converting_constructor_tag = error_condition_converting_constructor_tag()) noexcept(noexcept(error_type(make_error_code(std::forward<ErrorCondEnum>(t)))))
      : base{in_place_type<typename base::_error_type>, make_error_code(t)}
  {
    using namespace hooks;
    hook_outcome_construction(in_place_type<error_type>, this);
  }
  /*! Converting constructor to an excepted outcome.
  \tparam enable_exception_converting_constructor
  \exclude
  \param 1
  \exclude
  \param t The value from which to initialise the `exception_type`.

  \effects Initialises the outcome with a `exception_type`.
  \requires `trait::is_exception_ptr<P>` must be true; Type T is constructible to `exception_type`,
  is not constructible to `value_type`, is not constructible to `error_type`, and is not `outcome<R, S, P>` and not `in_place_type<>`.
  \throws Any exception the construction of `exception_type(T)` might throw.
  */
  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_exception_converting_constructor<T>))
  constexpr outcome(T &&t, exception_converting_constructor_tag = exception_converting_constructor_tag()) noexcept(std::is_nothrow_constructible<exception_type, T>::value)
      : base()
      , _ptr(std::forward<T>(t))
  {
    using namespace hooks;
    this->_state._status |= detail::status_have_exception;
    hook_outcome_construction(in_place_type<exception_type>, this);
  }

  /*! Explicit converting copy constructor from a compatible outcome type.
  \tparam 4
  \exclude
  \param o The compatible outcome.

  \effects Initialises the outcome with a copy of the compatible outcome.
  \requires Both outcome's `value_type`, `error_type`, `payload_type` and `exception_type` need to be constructible, or the source `void`.
  \throws Any exception the construction of `value_type(T)`, `error_type(U)` or `payload_exception_type(V)` might throw.
  */
  OUTCOME_TEMPLATE(class T, class U, class V, class W)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_compatible_conversion<T, U, V, W>))
  constexpr explicit outcome(const outcome<T, U, V, W> &o) noexcept(std::is_nothrow_constructible<value_type, T>::value &&std::is_nothrow_constructible<error_type, U>::value &&std::is_nothrow_constructible<payload_exception_type, V>::value)
      : base{typename base::compatible_conversion_tag(), o}
      , _ptr(o._ptr)
  {
    using namespace hooks;
    hook_outcome_copy_construction(in_place_type<decltype(o)>, this);
  }
  /*! Explicit converting move constructor from a compatible outcome type.
  \tparam 4
  \exclude
  \param o The compatible outcome.

  \effects Initialises the outcome with a move of the compatible outcome.
  \requires Both outcome's `value_type`, `error_type`, `payload_type` and `exception_type` need to be constructible, or the source `void`.
  \throws Any exception the construction of `value_type(T)`, `error_type(U)` or `payload_exception_type(V)` might throw.
  */
  OUTCOME_TEMPLATE(class T, class U, class V, class W)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_compatible_conversion<T, U, V, W>))
  constexpr explicit outcome(outcome<T, U, V, W> &&o) noexcept(std::is_nothrow_constructible<value_type, T>::value &&std::is_nothrow_constructible<error_type, U>::value &&std::is_nothrow_constructible<payload_exception_type, V>::value)
      : base{typename base::compatible_conversion_tag(), std::move(o)}
      , _ptr(std::move(o._ptr))
  {
    using namespace hooks;
    hook_outcome_move_construction(in_place_type<decltype(o)>, this);
  }
  /*! Explicit converting copy constructor from a compatible result type.
  \tparam 3
  \exclude
  \param o The compatible result.

  \effects Initialises the outcome with a copy of the compatible result.
  \requires Both outcome's `value_type` and `error_type` need to be constructible, or the source `void`.
  \throws Any exception the construction of `value_type(T)`, `error_type(U)` or `payload_exception_type()` might throw.
  */
  OUTCOME_TEMPLATE(class T, class U, class V)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(detail::result_predicates<value_type, error_type>::template enable_compatible_conversion<T, U, V>))
  constexpr explicit outcome(const result<T, U, V> &o) noexcept(std::is_nothrow_constructible<value_type, T>::value &&std::is_nothrow_constructible<error_type, U>::value &&std::is_nothrow_constructible<payload_exception_type>::value)
      : base{typename base::compatible_conversion_tag(), o}
      , _ptr()
  {
    using namespace hooks;
    hook_outcome_copy_construction(in_place_type<decltype(o)>, this);
  }
  /*! Explicit converting move constructor from a compatible result type.
  \tparam 3
  \exclude
  \param o The compatible result.

  \effects Initialises the outcome with a move of the compatible result.
  \requires Both outcome's `value_type` and `error_type` need to be constructible, or the source `void`.
  \throws Any exception the construction of `value_type(T)`, `error_type(U)` or `payload_exception_type()` might throw.
  */
  OUTCOME_TEMPLATE(class T, class U, class V)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(detail::result_predicates<value_type, error_type>::template enable_compatible_conversion<T, U, V>))
  constexpr explicit outcome(result<T, U, V> &&o) noexcept(std::is_nothrow_constructible<value_type, T>::value &&std::is_nothrow_constructible<error_type, U>::value &&std::is_nothrow_constructible<payload_exception_type>::value)
      : base{typename base::compatible_conversion_tag(), std::move(o)}
      , _ptr()
  {
    using namespace hooks;
    hook_outcome_move_construction(in_place_type<decltype(o)>, this);
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
  OUTCOME_TEMPLATE(class... Args)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_inplace_value_constructor<Args...>))
  constexpr explicit outcome(in_place_type_t<value_type_if_enabled> _, Args &&... args) noexcept(std::is_nothrow_constructible<value_type, Args...>::value)
      : base{_, std::forward<Args>(args)...}
      , _ptr()
  {
    using namespace hooks;
    hook_outcome_in_place_construction(in_place_type<value_type>, this);
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
  OUTCOME_TEMPLATE(class U, class... Args)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_inplace_value_constructor<std::initializer_list<U>, Args...>))
  constexpr explicit outcome(in_place_type_t<value_type_if_enabled> _, std::initializer_list<U> il, Args &&... args) noexcept(std::is_nothrow_constructible<value_type, std::initializer_list<U>, Args...>::value)
      : base{_, il, std::forward<Args>(args)...}
      , _ptr()
  {
    using namespace hooks;
    hook_outcome_in_place_construction(in_place_type<value_type>, this);
  }
  /*! Inplace constructor to an unsuccessful error.
  \tparam 1
  \exclude
  \param _ Tag type to indicate we are doing in place construction of `error_type`.
  \param args Arguments with which to in place construct.

  \effects Initialises the outcome with a `error_type`.
  \requires `error_type` is void or `Args...` are constructible to `error_type`.
  \throws Any exception the construction of `error_type(Args...)` might throw.
  */
  OUTCOME_TEMPLATE(class... Args)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_inplace_error_constructor<Args...>))
  constexpr explicit outcome(in_place_type_t<error_type_if_enabled> _, Args &&... args) noexcept(std::is_nothrow_constructible<error_type, Args...>::value)
      : base{_, std::forward<Args>(args)...}
      , _ptr()
  {
    using namespace hooks;
    hook_outcome_in_place_construction(in_place_type<error_type>, this);
  }
  /*! Inplace constructor to an unsuccessful error.
  \tparam 2
  \exclude
  \param _ Tag type to indicate we are doing in place construction of `error_type`.
  \param il An initializer list with which to in place construct.
  \param args Arguments with which to in place construct.

  \effects Initialises the outcome with a `error_type`.
  \requires The initializer list + `Args...` are constructible to `error_type`.
  \throws Any exception the construction of `error_type(il, Args...)` might throw.
  */
  OUTCOME_TEMPLATE(class U, class... Args)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_inplace_error_constructor<std::initializer_list<U>, Args...>))
  constexpr explicit outcome(in_place_type_t<error_type_if_enabled> _, std::initializer_list<U> il, Args &&... args) noexcept(std::is_nothrow_constructible<error_type, std::initializer_list<U>, Args...>::value)
      : base{_, il, std::forward<Args>(args)...}
      , _ptr()
  {
    using namespace hooks;
    hook_outcome_in_place_construction(in_place_type<error_type>, this);
  }
  /*! Inplace constructor to an unsuccessful exception.
  \tparam 1
  \exclude
  \param _ Tag type to indicate we are doing in place construction of `exception_type`.
  \param args Arguments with which to in place construct.

  \effects Initialises the outcome with an `exception_type`.
  \requires `exception_type` is void or `Args...` are constructible to `exception_type`.
  \throws Any exception the construction of `exception_type(Args...)` might throw.
  */
  OUTCOME_TEMPLATE(class... Args)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_inplace_exception_constructor<Args...>))
  constexpr explicit outcome(in_place_type_t<exception_type_if_enabled>, Args &&... args) noexcept(std::is_nothrow_constructible<exception_type, Args...>::value)
      : base()
      , _ptr(std::forward<Args>(args)...)
  {
    using namespace hooks;
    this->_state._status |= detail::status_have_exception;
    hook_outcome_in_place_construction(in_place_type<exception_type>, this);
  }
  /*! Inplace constructor to an unsuccessful exception.
  \tparam 2
  \exclude
  \param _ Tag type to indicate we are doing in place construction of `exception_type`.
  \param il An initializer list with which to in place construct.
  \param args Arguments with which to in place construct.

  \effects Initialises the outcome with an `exception_type`.
  \requires The initializer list + `Args...` are constructible to `exception_type`.
  \throws Any exception the construction of `exception_type(il, Args...)` might throw.
  */
  OUTCOME_TEMPLATE(class U, class... Args)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_inplace_exception_constructor<std::initializer_list<U>, Args...>))
  constexpr explicit outcome(in_place_type_t<exception_type_if_enabled>, std::initializer_list<U> il, Args &&... args) noexcept(std::is_nothrow_constructible<exception_type, std::initializer_list<U>, Args...>::value)
      : base()
      , _ptr(il, std::forward<Args>(args)...)
  {
    using namespace hooks;
    this->_state._status |= detail::status_have_exception;
    hook_outcome_in_place_construction(in_place_type<exception_type>, this);
  }
  /*! Implicit inplace constructor to successful value, or unsuccessful error, or unsuccessful exception.
  \tparam 3
  \exclude
  \param args Arguments with which to in place construct.

  \effects Calls the appropriate `in_place_type_t<...>` constructor depending on constructibility of args.
  \requires That the args can construct exactly one of `value_type` or `error_type` or `exception_type`.
  \throws Any exception the `in_place_type_t<...>` constructor might throw.
  */
  OUTCOME_TEMPLATE(class A1, class A2, class... Args)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_inplace_value_error_exception_constructor<A1, A2, Args...>))
  constexpr outcome(A1 &&a1, A2 &&a2, Args &&... args) noexcept(noexcept(typename predicate::template choose_inplace_value_error_exception_constructor<A1, A2, Args...>(std::declval<A1>(), std::declval<A2>(), std::declval<Args>()...)))
      : outcome(in_place_type<typename predicate::template choose_inplace_value_error_exception_constructor<A1, A2, Args...>>, std::forward<A1>(a1), std::forward<A2>(a2), std::forward<Args>(args)...)
  {
    /* I was a little surprised that the below is needed given that we forward to another constructor.
    But it turns out that ADL only fires on the first constructor for some reason.
    */
    using namespace hooks;
    // hook_outcome_in_place_construction(in_place_type<typename predicate::template choose_inplace_value_error_exception_constructor<A1, A2, Args...>>, this);
  }

  /// \output_section Tagged constructors
  /*! Implicit tagged constructor of a successful outcome.
  \param o The compatible success type sugar.

  \effects Initialises the outcome with a default constructed success type.
  \requires  `value_type` to be default constructible, or `void`.
  \throws Any exception the construction of `value_type()` might throw.
  */
  constexpr outcome(const success_type<void> &o) noexcept(std::is_nothrow_default_constructible<value_type>::value)
      : base{in_place_type<typename base::_value_type>}
  {
    using namespace hooks;
    hook_outcome_copy_construction(in_place_type<decltype(o)>, this);
  }
  /*! Implicit tagged constructor of a successful outcome.
  \tparam 1
  \exclude
  \param o The compatible success type sugar.

  \effects Initialises the outcome with a copy of the value in the type sugar.
  \requires Both outcome and success' `value_type` need to be constructible. The source cannot be `void`.
  \throws Any exception the construction of `value_type(T)` might throw.
  */
  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(!std::is_void<T>::value && predicate::template enable_compatible_conversion<T, void, void, void>))
  constexpr outcome(const success_type<T> &o) noexcept(std::is_nothrow_constructible<value_type, T>::value)
      : base{in_place_type<typename base::_value_type>, detail::extract_value_from_success<value_type>(o)}
  {
    using namespace hooks;
    hook_outcome_copy_construction(in_place_type<decltype(o)>, this);
  }
  /*! Implicit tagged constructor of a successful outcome.
  \tparam 1
  \exclude
  \param o The compatible success type sugar.

  \effects Initialises the outcome with a move of the value in the type sugar.
  \requires Both outcome and success' `value_type` need to be constructible. The source cannot be `void`.
  \throws Any exception the construction of `value_type(T)` might throw.
  */
  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(!std::is_void<T>::value && predicate::template enable_compatible_conversion<T, void, void, void>))
  constexpr outcome(success_type<T> &&o) noexcept(std::is_nothrow_constructible<value_type, T>::value)
      : base{in_place_type<typename base::_value_type>, std::move(detail::extract_value_from_success<value_type>(std::move(o)))}
  {
    using namespace hooks;
    hook_outcome_move_construction(in_place_type<decltype(o)>, this);
  }
  /*! Implicit tagged constructor of a failure outcome.
  \tparam 2
  \exclude
  \param o The compatible failure type sugar.

  \effects Initialises the outcome with a copy of the error and/or exception in the type sugar.
  \requires Both outcome and failure's `error_type` and `exception_type` need to be constructible, or the source can be `void`.
  \throws Any exception the construction of `error_type(T)` and/or `exception_type(U)` might throw.
  */
  OUTCOME_TEMPLATE(class T, class U)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_compatible_conversion<void, T, U, void>))
  constexpr outcome(const failure_type<T, U> &o) noexcept(std::is_nothrow_constructible<error_type, T>::value &&std::is_nothrow_constructible<exception_type, U>::value)
      : base{in_place_type<typename base::_error_type>, detail::extract_error_from_failure<error_type>(o)}
      , _ptr(detail::extract_exception_payload_from_failure<exception_type>(o))
  {
    if(this->_error == decltype(this->_error){})
    {
      this->_state._status &= ~detail::status_have_error;
    }
    if(_ptr != decltype(_ptr){})
    {
      this->_state._status |= detail::status_have_exception;
    }
    using namespace hooks;
    hook_outcome_copy_construction(in_place_type<decltype(o)>, this);
  }
  /*! Implicit tagged constructor of a failure outcome.
  \tparam 2
  \exclude
  \param o The compatible failure type sugar.

  \effects Initialises the outcome with a copy of the error and/or exception in the type sugar.
  \requires Both outcome and failure's `error_type` and `exception_type` need to be constructible, or the source can be `void`.
  \throws Any exception the construction of `error_type(T)` and/or `exception_type(U)` might throw.
  */
  OUTCOME_TEMPLATE(class T, class U)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_compatible_conversion<void, T, U, void>))
  constexpr outcome(failure_type<T, U> &&o) noexcept(std::is_nothrow_constructible<error_type, T>::value &&std::is_nothrow_constructible<exception_type, U>::value)
      : base{in_place_type<typename base::_error_type>, std::move(detail::extract_error_from_failure<error_type>(std::move(o)))}
      , _ptr(std::move(detail::extract_exception_payload_from_failure<decltype(_ptr)>(std::move(o))))
  {
    if(this->_error == decltype(this->_error){})
    {
      this->_state._status &= ~detail::status_have_error;
    }
    if(_ptr != decltype(_ptr){})
    {
      this->_state._status |= detail::status_have_exception;
    }
    using namespace hooks;
    hook_outcome_move_construction(in_place_type<decltype(o)>, this);
  }

  /// \output_section Comparison operators
  using base::operator==;
  using base::operator!=;
  /*! True if equal to the other outcome.
  \param o The other outcome to compare to.

  \effects If a valid expression to do so, calls the `operator==` operation on each
  of the three stored items returning true if both are true. Otherwise returns false.
  \throws Any exception the individual `operator==` operations might throw.
  */
  template <class T, class U, class V, class W>
  constexpr bool operator==(const outcome<T, U, V, W> &o) const noexcept(                                        //
  noexcept(detail::safe_compare_equal(std::declval<detail::devoid<R>>(), std::declval<detail::devoid<T>>()))     //
  && noexcept(detail::safe_compare_equal(std::declval<detail::devoid<S>>(), std::declval<detail::devoid<U>>()))  //
  && noexcept(detail::safe_compare_equal(std::declval<detail::devoid<P>>(), std::declval<detail::devoid<V>>())))
  {
    if(this->_state._status == o._state._status)
    {
      if(!base::operator==(o))
      {
        return false;
      }
      if((this->_state._status & detail::status_have_exception) || (this->_state._status & detail::status_have_payload))
      {
        return detail::safe_compare_equal(this->_ptr, o._ptr);
      }
    }
    return true;
  }
  /*! True if equal to the failure type sugar.
  \param o The failure type sugar to compare to.

  \effects If a valid expression to do so, calls the `operator==` operation on the failure items returning true if equal. Otherwise returns false.
  \throws Any exception the `operator==` operations might throw.
  */
  template <class T, class U>
  constexpr bool operator==(const failure_type<T, U, false> &o) const noexcept(                               //
  noexcept(detail::safe_compare_equal(std::declval<detail::devoid<S>>(), std::declval<detail::devoid<T>>()))  //
  && noexcept(detail::safe_compare_equal(std::declval<detail::devoid<P>>(), std::declval<detail::devoid<U>>())))
  {
    if(!(this->_state._status & detail::status_have_payload))
      return false;
    if(this->_state._status & detail::status_have_error)
    {
      if(!detail::safe_compare_equal(this->_error, o.error))
        return false;
    }
    if((this->_state._status & detail::status_have_exception) || (this->_state._status & detail::status_have_payload))
    {
      return detail::safe_compare_equal(this->_ptr, o.payload);
    }
    return true;
  }
  /*! True if equal to the failure type sugar.
  \param o The failure type sugar to compare to.

  \effects If a valid expression to do so, calls the `operator==` operation on the failure items returning true if equal. Otherwise returns false.
  \throws Any exception the `operator==` operations might throw.
  */
  template <class T, class U>
  constexpr bool operator==(const failure_type<T, U, true> &o) const noexcept(                                //
  noexcept(detail::safe_compare_equal(std::declval<detail::devoid<S>>(), std::declval<detail::devoid<T>>()))  //
  && noexcept(detail::safe_compare_equal(std::declval<detail::devoid<P>>(), std::declval<detail::devoid<U>>())))
  {
    if(!(this->_state._status & detail::status_have_exception))
      return false;
    if(this->_state._status & detail::status_have_error)
    {
      if(!detail::safe_compare_equal(this->_error, o.error))
        return false;
    }
    if((this->_state._status & detail::status_have_exception) || (this->_state._status & detail::status_have_payload))
    {
      return detail::safe_compare_equal(this->_ptr, o.exception);
    }
    return true;
  }
  /*! True if not equal to the other outcome.
  \param o The other outcome to compare to.

  \effects If a valid expression to do so, calls the `operator!=` operation on each
  of the three stored items, returning true if any are not equal. Otherwise returns true.
  \throws Any exception the individual `operator!=` operations might throw.
  */
  template <class T, class U, class V, class W>
  constexpr bool operator!=(const outcome<T, U, V, W> &o) const noexcept(                                           //
  noexcept(detail::safe_compare_notequal(std::declval<detail::devoid<R>>(), std::declval<detail::devoid<T>>()))     //
  && noexcept(detail::safe_compare_notequal(std::declval<detail::devoid<S>>(), std::declval<detail::devoid<U>>()))  //
  && noexcept(detail::safe_compare_notequal(std::declval<detail::devoid<P>>(), std::declval<detail::devoid<V>>())))
  {
    if(this->_state._status != o._state._status)
    {
      return true;
    }
    if(base::operator!=(o))
    {
      return true;
    }
    if((this->_state._status & detail::status_have_exception) || (this->_state._status & detail::status_have_payload))
    {
      return detail::safe_compare_notequal(this->_ptr, o._ptr);
    }
    return false;
  }
  /*! True if not equal to the failure type sugar.
  \param o The failure type sugar to compare to.

  \effects If a valid expression to do so, calls the `operator!=` operation on the failure items returning true if not equal. Otherwise returns true.
  \throws Any exception the `operator!=` operations might throw.
  */
  template <class T, class U>
  constexpr bool operator!=(const failure_type<T, U, false> &o) const noexcept(                                  //
  noexcept(detail::safe_compare_notequal(std::declval<detail::devoid<S>>(), std::declval<detail::devoid<T>>()))  //
  && noexcept(detail::safe_compare_notequal(std::declval<detail::devoid<P>>(), std::declval<detail::devoid<U>>())))
  {
    if(!(this->_state._status & detail::status_have_payload))
    {
      return true;
    }
    if(this->_state._status & detail::status_have_error)
    {
      if(detail::safe_compare_notequal(this->_error, o.error))
      {
        return true;
      }
    }
    if((this->_state._status & detail::status_have_exception) || (this->_state._status & detail::status_have_payload))
    {
      return detail::safe_compare_notequal(this->_ptr, o.payload);
    }
    return false;
  }
  /*! True if not equal to the failure type sugar.
  \param o The failure type sugar to compare to.

  \effects If a valid expression to do so, calls the `operator!=` operation on the failure items returning true if not equal. Otherwise returns false.
  \throws Any exception the `operator!=` operations might throw.
  */
  template <class T, class U>
  constexpr bool operator!=(const failure_type<T, U, true> &o) const noexcept(                                   //
  noexcept(detail::safe_compare_notequal(std::declval<detail::devoid<S>>(), std::declval<detail::devoid<T>>()))  //
  && noexcept(detail::safe_compare_notequal(std::declval<detail::devoid<P>>(), std::declval<detail::devoid<U>>())))
  {
    if(!(this->_state._status & detail::status_have_exception))
    {
      return true;
    }
    if(this->_state._status & detail::status_have_error)
    {
      if(detail::safe_compare_notequal(this->_error, o.error))
      {
        return true;
      }
    }
    if((this->_state._status & detail::status_have_exception) || (this->_state._status & detail::status_have_payload))
    {
      return detail::safe_compare_notequal(this->_ptr, o.exception);
    }
    return false;
  }

  /// \output_section Swap
  /*! Swaps this result with another result
  \effects Any `R` and/or `S` is swapped along with the metadata tracking them.
  */
  void swap(outcome &o) noexcept(detail::is_nothrow_swappable<value_type>::value    //
                                 &&detail::is_nothrow_swappable<error_type>::value  //
                                 &&detail::is_nothrow_swappable<payload_exception_type>::value)
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
      try
      {
        swap(this->_ptr, o._ptr);
      }
      catch(...)
      {
        swap(this->_state, o._state);
        swap(this->_error, o._error);
        throw;
      }
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
    swap(this->_ptr, o._ptr);
#endif
  }

  /// \output_section Converters
  /*! Returns this outcome as a `failure_type` with any errored and/or excepted state copied.
  \requires This outcome to have a failed state, else whatever `assume_error()` would do.
  */
  failure_type<error_type, payload_exception_type> as_failure() const &
  {
    if(this->has_error() && this->has_exception())
    {
      return OUTCOME_V2_NAMESPACE::failure(this->assume_error(), _ptr);
    }
    if(this->has_exception())
    {
      return OUTCOME_V2_NAMESPACE::failure(error_type(), _ptr);
    }
    return OUTCOME_V2_NAMESPACE::failure(this->assume_error(), payload_exception_type());
  }

  /*! Returns this outcome as a `failure_type` with any errored and/or excepted state moved.
  \requires This outcome to have a failed state, else whatever `assume_error()` would do.
  */
  failure_type<error_type, payload_exception_type> as_failure() &&
  {
    if(this->has_error() && this->has_exception())
    {
      return OUTCOME_V2_NAMESPACE::failure(std::move(this->assume_error()), std::move(_ptr));
    }
    if(this->has_exception())
    {
      return OUTCOME_V2_NAMESPACE::failure(error_type(), std::move(_ptr));
    }
    return OUTCOME_V2_NAMESPACE::failure(std::move(this->assume_error()), payload_exception_type());
  }
};

/*! True if the result is equal to the outcome
\tparam 7
\exclude
\param a The result to compare.
\param b The outcome to compare.

\effects Calls `b == a`.
\requires That the expression `b == a` is a valid expression.
\throws Any exception that `b == a` might throw.
*/
OUTCOME_TEMPLATE(class T, class U, class V,  //
                 class R, class S, class P, class N)
OUTCOME_TREQUIRES(OUTCOME_TEXPR(std::declval<outcome<R, S, P, N>>() == std::declval<result<T, U, V>>()))
constexpr inline bool operator==(const result<T, U, V> &a, const outcome<R, S, P, N> &b) noexcept(  //
noexcept(std::declval<outcome<R, S, P, N>>() == std::declval<result<T, U, V>>()))
{
  return b == a;
}
/*! True if the result is not equal to the outcome
\tparam 7
\exclude
\param a The result to compare.
\param b The outcome to compare.

\effects Calls `b != a`.
\requires That the expression `b != a` is a valid expression.
\throws Any exception that `b != a` might throw.
*/
OUTCOME_TEMPLATE(class T, class U, class V,  //
                 class R, class S, class P, class N)
OUTCOME_TREQUIRES(OUTCOME_TEXPR(std::declval<outcome<R, S, P, N>>() != std::declval<result<T, U, V>>()))
constexpr inline bool operator!=(const result<T, U, V> &a, const outcome<R, S, P, N> &b) noexcept(  //
noexcept(std::declval<outcome<R, S, P, N>>() != std::declval<result<T, U, V>>()))
{
  return b != a;
}
/*! Specialise swap for outcome.
\effects Calls `a.swap(b)`.
*/
template <class R, class S, class P, class N> inline void swap(outcome<R, S, P, N> &a, outcome<R, S, P, N> &b) noexcept(noexcept(a.swap(b)))
{
  a.swap(b);
}

namespace hooks
{
  /*! Used to set/override a payload/exception during a construction hook implementation.
  \param o The outcome you wish to change.
  \param v Payload/Exception to be set.
  \effects Sets the payload/exception of the outcome to the given value.
  */
  template <class R, class S, class P, class NoValuePolicy, class U> constexpr inline void override_outcome_payload_exception(outcome<R, S, P, NoValuePolicy> *o, U &&v) noexcept
  {
    o->_ptr = std::forward<U>(v);
    if(trait::is_exception_ptr<P>::value)
      o->_state._status |= detail::status_have_exception;
    else
      o->_state._status |= detail::status_have_payload;
  }
}
OUTCOME_V2_NAMESPACE_END

#include "policy/error_code_throw_as_system_error_exception_rethrow.hpp"

#include "detail/outcome_payload_observers_impl.hpp"

#endif
