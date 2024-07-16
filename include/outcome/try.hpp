/* Try operation macros
(C) 2017-2021 Niall Douglas <http://www.nedproductions.biz/> (20 commits)
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

#ifndef OUTCOME_TRY_HPP
#define OUTCOME_TRY_HPP

#include "detail/try.h"
#include "success_failure.hpp"

OUTCOME_V2_NAMESPACE_BEGIN

namespace detail
{
  struct has_value_overload
  {
  };
  struct as_failure_overload
  {
  };
  struct assume_error_overload
  {
  };
  struct error_overload
  {
  };
  struct assume_value_overload
  {
  };
  struct value_overload
  {
  };
  // #ifdef __APPLE__
  //   OUTCOME_TEMPLATE(class T, class R = decltype(std::declval<T>()._xcode_workaround_as_failure()))
  // #else
  OUTCOME_TEMPLATE(class T, class R = decltype(std::declval<T>().as_failure()))
  // #endif
  OUTCOME_TREQUIRES(OUTCOME_TPRED(OUTCOME_V2_NAMESPACE::is_failure_type<R>))
  constexpr inline bool has_as_failure(int /*unused */)
  {
    return true;
  }
  template <class T> constexpr inline bool has_as_failure(...)
  {
    return false;
  }
  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TEXPR(std::declval<T>().assume_error()))
  constexpr inline bool has_assume_error(int /*unused */)
  {
    return true;
  }
  template <class T> constexpr inline bool has_assume_error(...)
  {
    return false;
  }
  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TEXPR(std::declval<T>().error()))
  constexpr inline bool has_error(int /*unused */)
  {
    return true;
  }
  template <class T> constexpr inline bool has_error(...)
  {
    return false;
  }
  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TEXPR(std::declval<T>().assume_value()))
  constexpr inline bool has_assume_value(int /*unused */)
  {
    return true;
  }
  template <class T> constexpr inline bool has_assume_value(...)
  {
    return false;
  }
  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TEXPR(std::declval<T>().value()))
  constexpr inline bool has_value(int /*unused */)
  {
    return true;
  }
  template <class T> constexpr inline bool has_value(...)
  {
    return false;
  }
}  // namespace detail

/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
OUTCOME_TEMPLATE(class T)
OUTCOME_TREQUIRES(OUTCOME_TEXPR(std::declval<T>().has_value()))
constexpr inline bool try_operation_has_value(T &&v, detail::has_value_overload = {})
{
  return v.has_value();
}

/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
OUTCOME_TEMPLATE(class T)
OUTCOME_TREQUIRES(OUTCOME_TPRED(detail::has_as_failure<T>(5)))
constexpr inline decltype(auto) try_operation_return_as(T &&v, detail::as_failure_overload = {})
{
  return static_cast<T &&>(v).as_failure();
}
/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
OUTCOME_TEMPLATE(class T)
OUTCOME_TREQUIRES(OUTCOME_TPRED(!detail::has_as_failure<T>(5) && detail::has_assume_error<T>(5)))
constexpr inline decltype(auto) try_operation_return_as(T &&v, detail::assume_error_overload = {})
{
  return failure(static_cast<T &&>(v).assume_error());
}
/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
OUTCOME_TEMPLATE(class T)
OUTCOME_TREQUIRES(OUTCOME_TPRED(!detail::has_as_failure<T>(5) && !detail::has_assume_error<T>(5) && detail::has_error<T>(5)))
constexpr inline decltype(auto) try_operation_return_as(T &&v, detail::error_overload = {})
{
  return failure(static_cast<T &&>(v).error());
}

/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
OUTCOME_TEMPLATE(class T)
OUTCOME_TREQUIRES(OUTCOME_TPRED(detail::has_assume_value<T>(5)))
constexpr inline decltype(auto) try_operation_extract_value(T &&v, detail::assume_value_overload = {})
{
  return static_cast<T &&>(v).assume_value();
}
/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
OUTCOME_TEMPLATE(class T)
OUTCOME_TREQUIRES(OUTCOME_TPRED(!detail::has_assume_value<T>(5) && detail::has_value<T>(5)))
constexpr inline decltype(auto) try_operation_extract_value(T &&v, detail::value_overload = {})
{
  return static_cast<T &&>(v).value();
}

OUTCOME_V2_NAMESPACE_END

#if !defined(__clang__) && defined(__GNUC__) && __GNUC__ >= 8
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wparentheses"
#endif

// Use if(!expr); else as some compilers assume else clauses are always unlikely
#define OUTCOME_TRYV2_SUCCESS_LIKELY(unique, retstmt, spec, ...)                                                                                               \
  OUTCOME_TRYV2_UNIQUE_STORAGE(unique, spec, __VA_ARGS__);                                                                                                     \
  OUTCOME_TRY_LIKELY_IF(::OUTCOME_V2_NAMESPACE::try_operation_has_value(unique));                                                                              \
  else                                                                                                                                                         \
  { /* works around ICE in GCC's coroutines implementation */                                                                                                  \
    auto unique##_f(::OUTCOME_V2_NAMESPACE::try_operation_return_as(static_cast<decltype(unique) &&>(unique)));                                                \
    retstmt unique##_f;                                                                                                                                        \
  }
#define OUTCOME_TRYV3_FAILURE_LIKELY(unique, retstmt, spec, ...)                                                                                               \
  OUTCOME_TRYV2_UNIQUE_STORAGE(unique, spec, __VA_ARGS__);                                                                                                     \
  OUTCOME_TRY_LIKELY_IF(!OUTCOME_V2_NAMESPACE::try_operation_has_value(unique))                                                                                \
  { /* works around ICE in GCC's coroutines implementation */                                                                                                  \
    auto unique##_f(::OUTCOME_V2_NAMESPACE::try_operation_return_as(static_cast<decltype(unique) &&>(unique)));                                                \
    retstmt unique##_f;                                                                                                                                        \
  }

#define OUTCOME_TRY2_SUCCESS_LIKELY(unique, retstmt, var, ...)                                                                                                 \
  OUTCOME_TRYV2_SUCCESS_LIKELY(unique, retstmt, var, __VA_ARGS__);                                                                                             \
  OUTCOME_TRY2_VAR(var) = ::OUTCOME_V2_NAMESPACE::try_operation_extract_value(static_cast<decltype(unique) &&>(unique))
#define OUTCOME_TRY2_FAILURE_LIKELY(unique, retstmt, var, ...)                                                                                                 \
  OUTCOME_TRYV3_FAILURE_LIKELY(unique, retstmt, var, __VA_ARGS__);                                                                                             \
  OUTCOME_TRY2_VAR(var) = ::OUTCOME_V2_NAMESPACE::try_operation_extract_value(static_cast<decltype(unique) &&>(unique))

/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
#define OUTCOME_TRYV(...) OUTCOME_TRYV2_SUCCESS_LIKELY(OUTCOME_TRY_UNIQUE_NAME, return, deduce, __VA_ARGS__)
/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
#define OUTCOME_TRYV_FAILURE_LIKELY(...) OUTCOME_TRYV3_FAILURE_LIKELY(OUTCOME_TRY_UNIQUE_NAME, return, deduce, __VA_ARGS__)

/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
#define OUTCOME_CO_TRYV(...) OUTCOME_TRYV2_SUCCESS_LIKELY(OUTCOME_TRY_UNIQUE_NAME, co_return, deduce, __VA_ARGS__)
/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
#define OUTCOME_CO_TRYV_FAILURE_LIKELY(...) OUTCOME_TRYV3_FAILURE_LIKELY(OUTCOME_TRY_UNIQUE_NAME, co_return, deduce, __VA_ARGS__)

/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
#define OUTCOME_TRYV2(s, ...) OUTCOME_TRYV2_SUCCESS_LIKELY(OUTCOME_TRY_UNIQUE_NAME, return, (s, ), __VA_ARGS__)
/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
#define OUTCOME_TRYV2_FAILURE_LIKELY(s, ...) OUTCOME_TRYV3_FAILURE_LIKELY(OUTCOME_TRY_UNIQUE_NAME, return, (s, ), __VA_ARGS__)

/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
#define OUTCOME_CO_TRYV2(s, ...) OUTCOME_TRYV2_SUCCESS_LIKELY(OUTCOME_TRY_UNIQUE_NAME, co_return, (s, ), __VA_ARGS__)
/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
#define OUTCOME_CO_TRYV2_FAILURE_LIKELY(s, ...) OUTCOME_TRYV3_FAILURE_LIKELY(OUTCOME_TRY_UNIQUE_NAME, co_return, s(, ), __VA_ARGS__)


#if defined(__GNUC__) || defined(__clang__)

#define OUTCOME_TRYX2(unique, retstmt, ...)                                                                                                                    \
  ({                                                                                                                                                           \
    OUTCOME_TRYV2_SUCCESS_LIKELY(unique, retstmt, deduce, __VA_ARGS__);                                                                                        \
    ::OUTCOME_V2_NAMESPACE::try_operation_extract_value(static_cast<decltype(unique) &&>(unique));                                                             \
  })

/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
#define OUTCOME_TRYX(...) OUTCOME_TRYX2(OUTCOME_TRY_UNIQUE_NAME, return, __VA_ARGS__)

/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
#define OUTCOME_CO_TRYX(...) OUTCOME_TRYX2(OUTCOME_TRY_UNIQUE_NAME, co_return, __VA_ARGS__)
#endif

/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
#define OUTCOME_TRYA(v, ...) OUTCOME_TRY2_SUCCESS_LIKELY(OUTCOME_TRY_UNIQUE_NAME, return, v, __VA_ARGS__)
/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
#define OUTCOME_TRYA_FAILURE_LIKELY(v, ...) OUTCOME_TRY2_FAILURE_LIKELY(OUTCOME_TRY_UNIQUE_NAME, return, v, __VA_ARGS__)

/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
#define OUTCOME_CO_TRYA(v, ...) OUTCOME_TRY2_SUCCESS_LIKELY(OUTCOME_TRY_UNIQUE_NAME, co_return, v, __VA_ARGS__)
/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
#define OUTCOME_CO_TRYA_FAILURE_LIKELY(v, ...) OUTCOME_TRY2_FAILURE_LIKELY(OUTCOME_TRY_UNIQUE_NAME, co_return, v, __VA_ARGS__)


#define OUTCOME_TRY_INVOKE_TRY8(a, b, c, d, e, f, g, h) OUTCOME_TRYA(a, b, c, d, e, f, g, h)
#define OUTCOME_TRY_INVOKE_TRY7(a, b, c, d, e, f, g) OUTCOME_TRYA(a, b, c, d, e, f, g)
#define OUTCOME_TRY_INVOKE_TRY6(a, b, c, d, e, f) OUTCOME_TRYA(a, b, c, d, e, f)
#define OUTCOME_TRY_INVOKE_TRY5(a, b, c, d, e) OUTCOME_TRYA(a, b, c, d, e)
#define OUTCOME_TRY_INVOKE_TRY4(a, b, c, d) OUTCOME_TRYA(a, b, c, d)
#define OUTCOME_TRY_INVOKE_TRY3(a, b, c) OUTCOME_TRYA(a, b, c)
#define OUTCOME_TRY_INVOKE_TRY2(a, b) OUTCOME_TRYA(a, b)
#define OUTCOME_TRY_INVOKE_TRY1(a) OUTCOME_TRYV(a)

/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
#define OUTCOME_TRY(...) OUTCOME_TRY_CALL_OVERLOAD(OUTCOME_TRY_INVOKE_TRY, __VA_ARGS__)

#define OUTCOME_TRY_FAILURE_LIKELY_INVOKE_TRY8(a, b, c, d, e, f, g, h) OUTCOME_TRYA_FAILURE_LIKELY(a, b, c, d, e, f, g, h)
#define OUTCOME_TRY_FAILURE_LIKELY_INVOKE_TRY7(a, b, c, d, e, f, g) OUTCOME_TRYA_FAILURE_LIKELY(a, b, c, d, e, f, g)
#define OUTCOME_TRY_FAILURE_LIKELY_INVOKE_TRY6(a, b, c, d, e, f) OUTCOME_TRYA_FAILURE_LIKELY(a, b, c, d, e, f)
#define OUTCOME_TRY_FAILURE_LIKELY_INVOKE_TRY5(a, b, c, d, e) OUTCOME_TRYA_FAILURE_LIKELY(a, b, c, d, e)
#define OUTCOME_TRY_FAILURE_LIKELY_INVOKE_TRY4(a, b, c, d) OUTCOME_TRYA_FAILURE_LIKELY(a, b, c, d)
#define OUTCOME_TRY_FAILURE_LIKELY_INVOKE_TRY3(a, b, c) OUTCOME_TRYA_FAILURE_LIKELY(a, b, c)
#define OUTCOME_TRY_FAILURE_LIKELY_INVOKE_TRY2(a, b) OUTCOME_TRYA_FAILURE_LIKELY(a, b)
#define OUTCOME_TRY_FAILURE_LIKELY_INVOKE_TRY1(a) OUTCOME_TRYV_FAILURE_LIKELY(a)
/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
#define OUTCOME_TRY_FAILURE_LIKELY(...) OUTCOME_TRY_CALL_OVERLOAD(OUTCOME_TRY_FAILURE_LIKELY_INVOKE_TRY, __VA_ARGS__)

#define OUTCOME_CO_TRY_INVOKE_TRY8(a, b, c, d, e, f, g, h) OUTCOME_CO_TRYA(a, b, c, d, e, f, g, h)
#define OUTCOME_CO_TRY_INVOKE_TRY7(a, b, c, d, e, f, g) OUTCOME_CO_TRYA(a, b, c, d, e, f, g)
#define OUTCOME_CO_TRY_INVOKE_TRY6(a, b, c, d, e, f) OUTCOME_CO_TRYA(a, b, c, d, e, f)
#define OUTCOME_CO_TRY_INVOKE_TRY5(a, b, c, d, e) OUTCOME_CO_TRYA(a, b, c, d, e)
#define OUTCOME_CO_TRY_INVOKE_TRY4(a, b, c, d) OUTCOME_CO_TRYA(a, b, c, d)
#define OUTCOME_CO_TRY_INVOKE_TRY3(a, b, c) OUTCOME_CO_TRYA(a, b, c)
#define OUTCOME_CO_TRY_INVOKE_TRY2(a, b) OUTCOME_CO_TRYA(a, b)
#define OUTCOME_CO_TRY_INVOKE_TRY1(a) OUTCOME_CO_TRYV(a)
/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
#define OUTCOME_CO_TRY(...) OUTCOME_TRY_CALL_OVERLOAD(OUTCOME_CO_TRY_INVOKE_TRY, __VA_ARGS__)

/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
#define OUTCOME_TRY(...) OUTCOME_TRY_CALL_OVERLOAD(OUTCOME_TRY_INVOKE_TRY, __VA_ARGS__)

#define OUTCOME_CO_TRY_FAILURE_LIKELY_INVOKE_TRY8(a, b, c, d, e, f, g, h) OUTCOME_CO_TRYA_FAILURE_LIKELY(a, b, c, d, e, f, g, h)
#define OUTCOME_CO_TRY_FAILURE_LIKELY_INVOKE_TRY7(a, b, c, d, e, f, g) OUTCOME_CO_TRYA_FAILURE_LIKELY(a, b, c, d, e, f, g)
#define OUTCOME_CO_TRY_FAILURE_LIKELY_INVOKE_TRY6(a, b, c, d, e, f) OUTCOME_CO_TRYA_FAILURE_LIKELY(a, b, c, d, e, f)
#define OUTCOME_CO_TRY_FAILURE_LIKELY_INVOKE_TRY5(a, b, c, d, e) OUTCOME_CO_TRYA_FAILURE_LIKELY(a, b, c, d, e)
#define OUTCOME_CO_TRY_FAILURE_LIKELY_INVOKE_TRY4(a, b, c, d) OUTCOME_CO_TRYA_FAILURE_LIKELY(a, b, c, d)
#define OUTCOME_CO_TRY_FAILURE_LIKELY_INVOKE_TRY3(a, b, c) OUTCOME_CO_TRYA_FAILURE_LIKELY(a, b, c)
#define OUTCOME_CO_TRY_FAILURE_LIKELY_INVOKE_TRY2(a, b) OUTCOME_CO_TRYA_FAILURE_LIKELY(a, b)
#define OUTCOME_CO_TRY_FAILURE_LIKELY_INVOKE_TRY1(a) OUTCOME_CO_TRYV_FAILURE_LIKELY(a)
/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
#define OUTCOME_CO_TRY_FAILURE_LIKELY(...) OUTCOME_TRY_CALL_OVERLOAD(OUTCOME_CO_TRY_FAILURE_LIKELY_INVOKE_TRY, __VA_ARGS__)


/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
#define OUTCOME21_TRYA(v, ...) OUTCOME_TRY2_SUCCESS_LIKELY(OUTCOME_TRY_UNIQUE_NAME, return, deduce, auto &&v, __VA_ARGS__)
/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
#define OUTCOME21_TRYA_FAILURE_LIKELY(v, ...) OUTCOME_TRY2_FAILURE_LIKELY(OUTCOME_TRY_UNIQUE_NAME, return, deduce, auto &&v, __VA_ARGS__)

/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
#define OUTCOME21_CO_TRYA(v, ...) OUTCOME_TRY2_FAILURE_LIKELY(OUTCOME_TRY_UNIQUE_NAME, co_return, deduce, auto &&v, __VA_ARGS__)
/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
#define OUTCOME21_CO_TRYA_FAILURE_LIKELY(v, ...) OUTCOME_TRY2_FAILURE_LIKELY(OUTCOME_TRY_UNIQUE_NAME, co_retrn, deduce, auto &&v, __VA_ARGS__)


#define OUTCOME21_TRY_INVOKE_TRY8(a, b, c, d, e, f, g, h) OUTCOME21_TRYA(a, b, c, d, e, f, g, h)
#define OUTCOME21_TRY_INVOKE_TRY7(a, b, c, d, e, f, g) OUTCOME21_TRYA(a, b, c, d, e, f, g)
#define OUTCOME21_TRY_INVOKE_TRY6(a, b, c, d, e, f) OUTCOME21_TRYA(a, b, c, d, e, f)
#define OUTCOME21_TRY_INVOKE_TRY5(a, b, c, d, e) OUTCOME21_TRYA(a, b, c, d, e)
#define OUTCOME21_TRY_INVOKE_TRY4(a, b, c, d) OUTCOME21_TRYA(a, b, c, d)
#define OUTCOME21_TRY_INVOKE_TRY3(a, b, c) OUTCOME21_TRYA(a, b, c)
#define OUTCOME21_TRY_INVOKE_TRY2(a, b) OUTCOME21_TRYA(a, b)
#define OUTCOME21_TRY_INVOKE_TRY1(a) OUTCOME_TRYV(a)

/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
#define OUTCOME21_TRY(...) OUTCOME_TRY_CALL_OVERLOAD(OUTCOME21_TRY_INVOKE_TRY, __VA_ARGS__)

#define OUTCOME21_TRY_FAILURE_LIKELY_INVOKE_TRY8(a, b, c, d, e, f, g, h) OUTCOME21_TRYA_FAILURE_LIKELY(a, b, c, d, e, f, g, h)
#define OUTCOME21_TRY_FAILURE_LIKELY_INVOKE_TRY7(a, b, c, d, e, f, g) OUTCOME21_TRYA_FAILURE_LIKELY(a, b, c, d, e, f, g)
#define OUTCOME21_TRY_FAILURE_LIKELY_INVOKE_TRY6(a, b, c, d, e, f) OUTCOME21_TRYA_FAILURE_LIKELY(a, b, c, d, e, f)
#define OUTCOME21_TRY_FAILURE_LIKELY_INVOKE_TRY5(a, b, c, d, e) OUTCOME21_TRYA_FAILURE_LIKELY(a, b, c, d, e)
#define OUTCOME21_TRY_FAILURE_LIKELY_INVOKE_TRY4(a, b, c, d) OUTCOME21_TRYA_FAILURE_LIKELY(a, b, c, d)
#define OUTCOME21_TRY_FAILURE_LIKELY_INVOKE_TRY3(a, b, c) OUTCOME21_TRYA_FAILURE_LIKELY(a, b, c)
#define OUTCOME21_TRY_FAILURE_LIKELY_INVOKE_TRY2(a, b) OUTCOME21_TRYA_FAILURE_LIKELY(a, b)
#define OUTCOME21_TRY_FAILURE_LIKELY_INVOKE_TRY1(a) OUTCOME_TRYV_FAILURE_LIKELY(a)
/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
#define OUTCOME21_TRY_FAILURE_LIKELY(...) OUTCOME_TRY_CALL_OVERLOAD(OUTCOME21_TRY_FAILURE_LIKELY_INVOKE_TRY, __VA_ARGS__)

#define OUTCOME21_CO_TRY_INVOKE_TRY8(a, b, c, d, e, f, g, h) OUTCOME21_CO_TRYA(a, b, c, d, e, f, g, h)
#define OUTCOME21_CO_TRY_INVOKE_TRY7(a, b, c, d, e, f, g) OUTCOME21_CO_TRYA(a, b, c, d, e, f, g)
#define OUTCOME21_CO_TRY_INVOKE_TRY6(a, b, c, d, e, f) OUTCOME21_CO_TRYA(a, b, c, d, e, f)
#define OUTCOME21_CO_TRY_INVOKE_TRY5(a, b, c, d, e) OUTCOME21_CO_TRYA(a, b, c, d, e)
#define OUTCOME21_CO_TRY_INVOKE_TRY4(a, b, c, d) OUTCOME21_CO_TRYA(a, b, c, d)
#define OUTCOME21_CO_TRY_INVOKE_TRY3(a, b, c) OUTCOME21_CO_TRYA(a, b, c)
#define OUTCOME21_CO_TRY_INVOKE_TRY2(a, b) OUTCOME21_CO_TRYA(a, b)
#define OUTCOME21_CO_TRY_INVOKE_TRY1(a) OUTCOME_CO_TRYV(a)
/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
#define OUTCOME21_CO_TRY(...) OUTCOME_TRY_CALL_OVERLOAD(OUTCOME21_CO_TRY_INVOKE_TRY, __VA_ARGS__)

#define OUTCOME21_CO_TRY_FAILURE_LIKELY_INVOKE_TRY8(a, b, c, d, e, f, g, h) OUTCOME21_CO_TRYA_FAILURE_LIKELY(a, b, c, d, e, f, g, h)
#define OUTCOME21_CO_TRY_FAILURE_LIKELY_INVOKE_TRY7(a, b, c, d, e, f, g) OUTCOME21_CO_TRYA_FAILURE_LIKELY(a, b, c, d, e, f, g)
#define OUTCOME21_CO_TRY_FAILURE_LIKELY_INVOKE_TRY6(a, b, c, d, e, f) OUTCOME21_CO_TRYA_FAILURE_LIKELY(a, b, c, d, e, f)
#define OUTCOME21_CO_TRY_FAILURE_LIKELY_INVOKE_TRY5(a, b, c, d, e) OUTCOME21_CO_TRYA_FAILURE_LIKELY(a, b, c, d, e)
#define OUTCOME21_CO_TRY_FAILURE_LIKELY_INVOKE_TRY4(a, b, c, d) OUTCOME21_CO_TRYA_FAILURE_LIKELY(a, b, c, d)
#define OUTCOME21_CO_TRY_FAILURE_LIKELY_INVOKE_TRY3(a, b, c) OUTCOME21_CO_TRYA_FAILURE_LIKELY(a, b, c)
#define OUTCOME21_CO_TRY_FAILURE_LIKELY_INVOKE_TRY2(a, b) OUTCOME21_CO_TRYA_FAILURE_LIKELY(a, b)
#define OUTCOME21_CO_TRY_FAILURE_LIKELY_INVOKE_TRY1(a) OUTCOME_CO_TRYV_FAILURE_LIKELY(a)
/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
#define OUTCOME21_CO_TRY_FAILURE_LIKELY(...) OUTCOME_TRY_CALL_OVERLOAD(OUTCOME21_CO_TRY_FAILURE_LIKELY_INVOKE_TRY, __VA_ARGS__)


#if !defined(__clang__) && defined(__GNUC__) && __GNUC__ >= 8
#pragma GCC diagnostic pop
#endif

#endif
