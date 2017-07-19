/* Type sugar for success and failure
(C) 2017 Niall Douglas <http://www.nedproductions.biz/> (59 commits)
File Created: July 2017


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

#ifndef OUTCOME_SUCCESS_FAILURE_HPP
#define OUTCOME_SUCCESS_FAILURE_HPP

#include "config.hpp"

#include <system_error>
#include <type_traits>

namespace std
{
  class exception_ptr;
}

OUTCOME_V2_NAMESPACE_BEGIN

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

// Do we have C++ 17 deduced templates?
#if 0  // def __cpp_deduction_guides

template <class T> struct success
{
  T value;
  constexpr success(T &&v)
      : value(std::move(v))
  {
  }
  constexpr success(const T &v)
      : value(v)
  {
  }
};
template <> struct success<void>
{
};
template <class T> success(T /*unused*/)->success<T>;
success()->success<void>;
template <class T> using success_type = success<T>;

template <class EC, class E, bool e_is_exception_ptr = trait::is_exception_ptr<E>::value> struct failure;
template <class EC, class E> using failure_type = failure<EC, E>;
template <class EC, class P> struct failure<EC, P, false>
{
  EC error;
  P payload;
};
template <class EC, class E> struct failure<EC, E, true>
{
  EC error;
  E exception;
};
template <class EC> struct failure<EC, void, false>
{
  EC error;
};
template <class P> struct failure<void, P, false>
{
  P payload;
};
template <class E> struct failure<void, E, true>
{
  E exception;
};
#else

/*! Type sugar for implicitly constructing a `result<>` with a successful state.
*/
template <class T> struct success_type
{
  //! The type of the successful state.
  using value_type = T;
  //! The value of the successful state.
  value_type value;
};
/*! Type sugar for implicitly constructing a `result<>` with a successful state.
*/
template <> struct success_type<void>
{
  //! The type of the successful state.
  using value_type = void;
};
/*! Returns type sugar for implicitly constructing a `result<T>` with a successful state,
default constructing `T` if necessary.
*/
inline constexpr success_type<void> success() noexcept
{
  return success_type<void>{};
}
/*! Returns type sugar for implicitly constructing a `result<T>` with a successful state.
\effects Copies or moves the successful state supplied into the returned type sugar.
*/
template <class T> inline constexpr success_type<std::decay_t<T>> success(T &&v)
{
  return success_type<std::decay_t<T>>{std::forward<T>(v)};
}

/*! Type sugar for implicitly constructing a `result<>` with a failure state.
*/
template <class EC = std::error_code, class E = void, bool e_is_exception_ptr = trait::is_exception_ptr<E>::value> struct failure_type;
/*! Type sugar for implicitly constructing a `result<>` with a failure state of error code and payload.
*/
template <class EC, class P> struct failure_type<EC, P, false>
{
  //! The type of the error code
  using error_type = EC;
  //! The type of the payload
  using payload_type = P;
  //! The type of the exception
  using exception_type = void;
  //! The error code
  error_type error;
  //! The payload
  payload_type payload;
};
/*! Type sugar for implicitly constructing a `result<>` with a failure state of error code and exception.
*/
template <class EC, class E> struct failure_type<EC, E, true>
{
  //! The type of the error code
  using error_type = EC;
  //! The type of the payload
  using payload_type = void;
  //! The type of the exception
  using exception_type = E;
  //! The error code
  error_type error;
  //! The exception
  exception_type exception;
};
/*! Type sugar for implicitly constructing a `result<>` with a failure state of error code.
*/
template <class EC> struct failure_type<EC, void, false>
{
  //! The type of the error code
  using error_type = EC;
  //! The type of the payload
  using payload_type = void;
  //! The type of the exception
  using exception_type = void;
  //! The error code
  error_type error;
};
/*! Type sugar for implicitly constructing a `result<>` with a failure state of payload.
*/
template <class P> struct failure_type<void, P, false>
{
  //! The type of the error code
  using error_type = void;
  //! The type of the payload
  using payload_type = P;
  //! The type of the exception
  using exception_type = void;
  //! The payload
  payload_type payload;
};
/*! Type sugar for implicitly constructing a `result<>` with a failure state of exception.
*/
template <class E> struct failure_type<void, E, true>
{
  //! The type of the error code
  using error_type = void;
  //! The type of the payload
  using payload_type = void;
  //! The type of the exception
  using exception_type = E;
  //! The exception
  exception_type exception;
};
/*! Returns type sugar for implicitly constructing a `result<T>` with a failure state.
\effects Copies or moves the failure state supplied into the returned type sugar.
*/
template <class EC> inline constexpr failure_type<std::decay_t<EC>> failure(EC &&v)
{
  return failure_type<std::decay_t<EC>>{std::forward<EC>(v)};
}
/*! Returns type sugar for implicitly constructing a `result<T>` with a failure state.
\effects Copies or moves the failure state supplied into the returned type sugar.
*/
template <class EC, class E> inline constexpr failure_type<std::decay_t<EC>, std::decay_t<E>> failure(EC &&v, E &&w)
{
  return failure_type<std::decay_t<EC>, std::decay_t<E>>{std::forward<EC>(v), std::forward<E>(w)};
}

#endif

OUTCOME_V2_NAMESPACE_END

#endif
