/* C interface for result
(C) 2017-2024 Niall Douglas <http://www.nedproductions.biz/> (6 commits)
File Created: Aug 2017


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

#ifndef OUTCOME_EXPERIMENTAL_RESULT_H
#define OUTCOME_EXPERIMENTAL_RESULT_H

#include <stddef.h>  // for size_t
#include <stdint.h>  // for intptr_t

#include "../detail/try.h"

#if __STDC_VERSION__ >= 199900L
#define OUTCOME_C_INLINE inline
#else
#define OUTCOME_C_INLINE
#endif

#ifndef OUTCOME_C_NODISCARD
#if defined __STDC_VERSION__ && __STDC_VERSION__ >= 202000L
#define OUTCOME_C_NODISCARD [[nodiscard]]
#elif defined(__GNUC__) || defined(__clang__)
#define OUTCOME_C_NODISCARD __attribute__((warn_unused_result))
#else
#define OUTCOME_C_NODISCARD
#endif
#endif

#include "../outcome_gdb.h"

#ifdef __cplusplus
extern "C"
{
#endif

#define CXX_DECLARE_RESULT(ident, R, S)                                                                                                                        \
  struct cxx_result_##ident                                                                                                                                    \
  {                                                                                                                                                            \
    union                                                                                                                                                      \
    {                                                                                                                                                          \
      R value;                                                                                                                                                 \
      S error;                                                                                                                                                 \
    };                                                                                                                                                         \
    unsigned flags;                                                                                                                                            \
  }

#define CXX_RESULT(ident) struct cxx_result_##ident


#define CXX_RESULT_HAS_VALUE(r) (((r).flags & 1U) == 1U)

#define CXX_RESULT_HAS_ERROR(r) (((r).flags & 2U) == 2U)

#define CXX_RESULT_ERROR_IS_ERRNO(r) (((r).flags & (1U << 4U)) == (1U << 4U))

  /***************************** <system_error2> support ******************************/

#define CXX_DECLARE_STATUS_CODE(ident, value_type)                                                                                                             \
  struct cxx_status_code_##ident                                                                                                                               \
  {                                                                                                                                                            \
    void *domain;                                                                                                                                              \
    value_type value;                                                                                                                                          \
  };

#define CXX_STATUS_CODE(ident) struct cxx_status_code_##ident

  extern void outcome_make_result_status_code_success(void *out, size_t bytes, size_t offset, const void *toset, size_t tosetbytes);
  extern void outcome_make_result_status_code_failure_posix(void *out, size_t bytes, size_t offset, int errcode);
  extern void outcome_make_result_status_code_failure_system(void *out, size_t bytes, size_t offset, intptr_t errcode);
  extern int outcome_status_code_equal(const void *a, const void *b);
  extern int outcome_status_code_equal_generic(const void *a, int errcode);
  extern const char *outcome_status_code_message(const void *a);


#ifdef __cplusplus
#define CXX_DECLARE_RESULT_STATUS_CODE_CXX(ident, R, S)                                                                                                        \
  static_assert(std::is_trivially_copyable<R>::value || OUTCOME_V2_NAMESPACE::trait::is_move_bitcopying<R>::value,                                             \
                "R must be trivially copyable or move bitcopying to be used in a C Result");                                                                   \
  static_assert(std::is_trivially_copyable<S>::value || OUTCOME_V2_NAMESPACE::trait::is_move_bitcopying<S>::value,                                             \
                "S must be trivially copyable or move bitcopying to be used in a C Result");                                                                   \
  inline OUTCOME_V2_NAMESPACE::experimental::status_result<R> to_result(const cxx_result_status_code_##ident &v)                                               \
  {                                                                                                                                                            \
    union type_punner_t                                                                                                                                        \
    {                                                                                                                                                          \
      cxx_result_status_code_##ident c;                                                                                                                        \
      OUTCOME_V2_NAMESPACE::experimental::status_result<R> cpp;                                                                                                \
                                                                                                                                                               \
      type_punner_t()                                                                                                                                          \
          : c{}                                                                                                                                                \
      {                                                                                                                                                        \
      }                                                                                                                                                        \
      ~type_punner_t() {}                                                                                                                                      \
    } pun;                                                                                                                                                     \
                                                                                                                                                               \
    pun.c = v;                                                                                                                                                 \
    return std::move(pun.cpp);                                                                                                                                 \
  }                                                                                                                                                            \
  inline OUTCOME_C_NODISCARD cxx_result_status_code_##ident to_##ident(OUTCOME_V2_NAMESPACE::experimental::status_result<R> v)                                 \
  {                                                                                                                                                            \
    union type_punner_t                                                                                                                                        \
    {                                                                                                                                                          \
      OUTCOME_V2_NAMESPACE::experimental::status_result<R> cpp;                                                                                                \
      cxx_result_status_code_##ident c;                                                                                                                        \
                                                                                                                                                               \
      type_punner_t(OUTCOME_V2_NAMESPACE::experimental::status_result<R> v)                                                                                    \
          : cpp(std::move(v))                                                                                                                                  \
      {                                                                                                                                                        \
      }                                                                                                                                                        \
      ~type_punner_t() {}                                                                                                                                      \
    } pun{std::move(v)};                                                                                                                                       \
                                                                                                                                                               \
    return pun.c;                                                                                                                                              \
  }
#else
#define CXX_DECLARE_RESULT_STATUS_CODE_CXX(ident, R, S)
#endif

#define CXX_DECLARE_RESULT_STATUS_CODE(ident, R, S)                                                                                                            \
  struct cxx_result_status_code_##ident                                                                                                                        \
  {                                                                                                                                                            \
    R value;                                                                                                                                                   \
    unsigned flags;                                                                                                                                            \
    S error;                                                                                                                                                   \
  };                                                                                                                                                           \
  static OUTCOME_C_INLINE OUTCOME_C_NODISCARD struct cxx_result_status_code_##ident outcome_make_result_##ident##_success(R value)                             \
  {                                                                                                                                                            \
    struct cxx_result_status_code_##ident ret;                                                                                                                 \
    outcome_make_result_status_code_success((void *) &ret, sizeof(ret), offsetof(struct cxx_result_status_code_##ident, flags), (const void *) &value,         \
                                            sizeof(value));                                                                                                    \
    return ret;                                                                                                                                                \
  }                                                                                                                                                            \
  static OUTCOME_C_INLINE OUTCOME_C_NODISCARD struct cxx_result_status_code_##ident outcome_make_result_##ident##_failure_posix(int errcode)                   \
  {                                                                                                                                                            \
    struct cxx_result_status_code_##ident ret;                                                                                                                 \
    outcome_make_result_status_code_failure_posix((void *) &ret, sizeof(ret), offsetof(struct cxx_result_status_code_##ident, flags), errcode);                \
    return ret;                                                                                                                                                \
  }                                                                                                                                                            \
  static OUTCOME_C_INLINE OUTCOME_C_NODISCARD struct cxx_result_status_code_##ident outcome_make_result_##ident##_failure_system(intptr_t errcode)             \
  {                                                                                                                                                            \
    struct cxx_result_status_code_##ident ret;                                                                                                                 \
    outcome_make_result_status_code_failure_system((void *) &ret, sizeof(ret), offsetof(struct cxx_result_status_code_##ident, flags), errcode);               \
    return ret;                                                                                                                                                \
  }                                                                                                                                                            \
  CXX_DECLARE_RESULT_STATUS_CODE_CXX(ident, R, S)

#define CXX_RESULT_STATUS_CODE(ident) struct cxx_result_status_code_##ident

#define CXX_TO_RESULT_STATUS_CODE(ident, ...) to_##ident(__VA_ARGS__)
#define CXX_MAKE_RESULT_STATUS_CODE_SUCCESS(ident, ...) outcome_make_result_##ident##_success(__VA_ARGS__)
#define CXX_MAKE_RESULT_STATUS_CODE_FAILURE_POSIX(ident, ...) outcome_make_result_##ident##_failure_posix(__VA_ARGS__)
#define CXX_MAKE_RESULT_STATUS_CODE_FAILURE_SYSTEM(ident, ...) outcome_make_result_##ident##_failure_system(__VA_ARGS__)


  struct cxx_status_code_posix
  {
    void *domain;
    int value;
  };
#define CXX_DECLARE_RESULT_ERRNO(ident, R) CXX_DECLARE_RESULT_STATUS_CODE(posix_##ident, R, struct cxx_status_code_posix)
#define CXX_RESULT_ERRNO(ident) CXX_RESULT_STATUS_CODE(posix_##ident)

  struct cxx_status_code_system
  {
    void *domain;
    intptr_t value;
  };
#define CXX_DECLARE_RESULT_SYSTEM(ident, R) CXX_DECLARE_RESULT_STATUS_CODE(system_##ident, R, struct cxx_status_code_system)
#define CXX_RESULT_SYSTEM(ident) CXX_RESULT_STATUS_CODE(system_##ident)

#define CXX_TO_RESULT_SYSTEM_CODE(ident, ...) to_system_##ident(__VA_ARGS__)
#define CXX_MAKE_RESULT_SYSTEM_SUCCESS(ident, ...) CXX_MAKE_RESULT_STATUS_CODE_SUCCESS(system_##ident, __VA_ARGS__)
#define CXX_MAKE_RESULT_SYSTEM_FAILURE_POSIX(ident, ...) CXX_MAKE_RESULT_STATUS_CODE_FAILURE_POSIX(system_##ident, __VA_ARGS__)
#define CXX_MAKE_RESULT_SYSTEM_FAILURE_SYSTEM(ident, ...) CXX_MAKE_RESULT_STATUS_CODE_FAILURE_SYSTEM(system_##ident, __VA_ARGS__)

#define CXX_RESULT_SYSTEM_TRY_IMPLV(unique, retstmt, cleanup, spec, ...)                                                                                       \
  OUTCOME_TRYV2_UNIQUE_STORAGE(unique, spec, __VA_ARGS__);                                                                                                     \
  OUTCOME_TRY_LIKELY_IF(CXX_RESULT_HAS_VALUE(unique));                                                                                                         \
  else                                                                                                                                                         \
  {                                                                                                                                                            \
    retstmt;                                                                                                                                                   \
  }
#define CXX_RESULT_SYSTEM_TRY_IMPLA(unique, retstmt, cleanup, var, ...)                                                                                        \
  CXX_RESULT_SYSTEM_TRY_IMPLV(unique, retstmt, cleanup, var, __VA_ARGS__)                                                                                      \
  OUTCOME_TRY2_VAR(var) = unique.value

#define CXX_RESULT_SYSTEM_TRY_IMPL_RETURN(unique, ident)                                                                                                       \
  CXX_RESULT_SYSTEM(ident) unique##_f;                                                                                                                         \
  unique##_f.flags = (unique).flags;                                                                                                                           \
  unique##_f.error = (unique).error;                                                                                                                           \
  return unique##_f

#define CXX_RESULT_SYSTEM_TRY_WITH_SPEC_AND_CLEANUP_AND_NEW_RETURN_TYPE(unique, spec, ident, cleanup, ...)                                                     \
  CXX_RESULT_SYSTEM_TRY_IMPLA(unique, CXX_RESULT_SYSTEM_TRY_IMPL_RETURN(unique, ident), cleanup, spec, __VA_ARGS__)
#define CXX_RESULT_SYSTEM_TRY_WITH_SPEC_AND_CLEANUP(unique, spec, cleanup, ...) CXX_RESULT_SYSTEM_TRY_IMPLA(unique, return unique, cleanup, spec, __VA_ARGS__)
#define CXX_RESULT_SYSTEM_TRY_WITH_CLEANUP(unique, cleanup, ...) CXX_RESULT_SYSTEM_TRY_IMPLV(unique, return unique, cleanup, deduce, __VA_ARGS__)
#define CXX_RESULT_SYSTEM_TRY_SAME_RETURN_TYPE(unique, ...) CXX_RESULT_SYSTEM_TRY_IMPLV(unique, return unique, , deduce, __VA_ARGS__)

#define CXX_RESULT_SYSTEM_TRY_INVOKE_TRY8(a, b, c, d, e, f, g, h)                                                                                              \
  CXX_RESULT_SYSTEM_TRY_WITH_SPEC_AND_CLEANUP_AND_NEW_RETURN_TYPE(OUTCOME_TRY_UNIQUE_NAME, a, b, c, d, e, f, g, h)
#define CXX_RESULT_SYSTEM_TRY_INVOKE_TRY7(a, b, c, d, e, f, g)                                                                                                 \
  CXX_RESULT_SYSTEM_TRY_WITH_SPEC_AND_CLEANUP_AND_NEW_RETURN_TYPE(OUTCOME_TRY_UNIQUE_NAME, a, b, c, d, e, f, g)
#define CXX_RESULT_SYSTEM_TRY_INVOKE_TRY6(a, b, c, d, e, f)                                                                                                    \
  CXX_RESULT_SYSTEM_TRY_WITH_SPEC_AND_CLEANUP_AND_NEW_RETURN_TYPE(OUTCOME_TRY_UNIQUE_NAME, a, b, c, d, e, f)
#define CXX_RESULT_SYSTEM_TRY_INVOKE_TRY5(a, b, c, d, e) CXX_RESULT_SYSTEM_TRY_WITH_SPEC_AND_CLEANUP_AND_NEW_RETURN_TYPE(OUTCOME_TRY_UNIQUE_NAME, a, b, c, d, e)
#define CXX_RESULT_SYSTEM_TRY_INVOKE_TRY4(a, b, c, d) CXX_RESULT_SYSTEM_TRY_WITH_SPEC_AND_CLEANUP_AND_NEW_RETURN_TYPE(OUTCOME_TRY_UNIQUE_NAME, a, b, c, d)
#define CXX_RESULT_SYSTEM_TRY_INVOKE_TRY3(a, b, c) CXX_RESULT_SYSTEM_TRY_WITH_SPEC_AND_CLEANUP(OUTCOME_TRY_UNIQUE_NAME, a, b, c)
#define CXX_RESULT_SYSTEM_TRY_INVOKE_TRY2(a, b) CXX_RESULT_SYSTEM_TRY_WITH_CLEANUP(OUTCOME_TRY_UNIQUE_NAME, a, b)
#define CXX_RESULT_SYSTEM_TRY_INVOKE_TRY1(expr) CXX_RESULT_SYSTEM_TRY_SAME_RETURN_TYPE(OUTCOME_TRY_UNIQUE_NAME, expr)

#define CXX_RESULT_SYSTEM_TRY(...) OUTCOME_TRY_CALL_OVERLOAD(CXX_RESULT_SYSTEM_TRY_INVOKE_TRY, __VA_ARGS__)

#define CXX_MAKE_RESULT_SYSTEM_FROM_ENUM(ident, enum_name, ...) outcome_make_result_##ident##_failure_system_enum_##enum_name(__VA_ARGS__)
#ifndef __cplusplus
// Declares the function in C, needs to occur at least once in a C++ source file to get implemented
#define CXX_DECLARE_RESULT_SYSTEM_FROM_ENUM(ident, enum_name, uuid, ...)                                                                                       \
  extern OUTCOME_C_NODISCARD struct cxx_result_status_code_system_##ident outcome_make_result_##ident##_failure_system_enum_##enum_name(enum enum_name v);
#else
}

#include "../config.hpp"
#include "status-code/include/status-code/config.hpp"
#include "status-code/include/status-code/system_code.hpp"
#include "status_result.hpp"


#include "status-code/include/status-code/posix_code.hpp"
#ifdef _WIN32
#include "status-code/include/status-code/win32_code.hpp"
#endif

#include <algorithm>
#include <cstring>

#ifndef OUTCOME_C_WEAK
#ifdef _MSC_VER
#define OUTCOME_C_WEAK inline
#else
#define OUTCOME_C_WEAK __attribute__((weak))
#endif
#endif

#ifndef OUTCOME_C_MSVC_FORCE_EMIT
#ifdef _MSC_VER
#define OUTCOME_C_MSVC_FORCE_EMIT(x) extern "C" __declspec(selectany) void *x##_emit = x;
#else
#define OUTCOME_C_MSVC_FORCE_EMIT(x)
#endif
#endif


// You need to include this C header in at least one C++ source file to have these C helper functions be implemented
extern "C" OUTCOME_C_WEAK void outcome_make_result_status_code_success(void *out, size_t bytes, size_t offset, const void *toset, size_t tosetbytes)
{
  union type_punner_t
  {
    OUTCOME_V2_NAMESPACE::experimental::status_result<intptr_t> cpp;
    struct cxx_status_code
    {
      intptr_t value;
      unsigned flags;
      cxx_status_code_system error;
    } c;

    type_punner_t()
        : cpp(0)
    {
    }
    ~type_punner_t() {}
  } pun;
  static_assert(sizeof(pun.cpp) == sizeof(pun.c), "");
  static constexpr size_t punoffset = offsetof(type_punner_t::cxx_status_code, flags);
  assert(bytes - tosetbytes >= sizeof(pun.cpp) - punoffset);
  const size_t tocopy = std::min(bytes - tosetbytes, sizeof(pun.c) - punoffset);
  memcpy(out, toset, tosetbytes);
  memcpy((void *) ((char *) out + offset), (const void *) ((const char *) &pun.c + punoffset), tocopy);
}
OUTCOME_C_MSVC_FORCE_EMIT(outcome_make_result_status_code_success)

extern "C" OUTCOME_C_WEAK void outcome_make_result_status_code_failure_posix(void *out, size_t bytes, size_t offset, int errcode)
{
  using value_type = OUTCOME_V2_NAMESPACE::experimental::posix_code::value_type;
  union type_punner_t
  {
    OUTCOME_V2_NAMESPACE::experimental::status_result<intptr_t> cpp;
    struct cxx_status_code
    {
      intptr_t value;
      unsigned flags;
      cxx_status_code_system error;
    } c;

    explicit type_punner_t(OUTCOME_V2_NAMESPACE::experimental::status_result<intptr_t> res)
        : cpp(std::move(res))
    {
    }
    ~type_punner_t() {}
  } pun{OUTCOME_V2_NAMESPACE::experimental::posix_code(errcode)};
  static_assert(sizeof(pun.cpp) == sizeof(pun.c), "");
  static constexpr size_t punoffset = offsetof(type_punner_t::cxx_status_code, flags);
  assert(bytes - offset >= sizeof(pun.cpp) - punoffset);
  const size_t tocopy = std::min(bytes - offset, sizeof(pun.cpp) - punoffset);
  memcpy(out, (void *) &pun.c, sizeof(value_type));
  memcpy((void *) ((char *) out + offset), (const void *) ((const char *) &pun.c + punoffset), tocopy);
}
OUTCOME_C_MSVC_FORCE_EMIT(outcome_make_result_status_code_failure_posix)

extern "C" OUTCOME_C_WEAK void outcome_make_result_status_code_failure_system(void *out, size_t bytes, size_t offset, intptr_t errcode)
{
  using value_type = OUTCOME_V2_NAMESPACE::experimental::system_code::value_type;
  union type_punner_t
  {
    OUTCOME_V2_NAMESPACE::experimental::status_result<intptr_t> cpp;
    struct cxx_status_code
    {
      intptr_t value;
      unsigned flags;
      cxx_status_code_system error;
    } c;

    explicit type_punner_t(OUTCOME_V2_NAMESPACE::experimental::status_result<intptr_t> res)
        : cpp(std::move(res))
    {
    }
    ~type_punner_t() {}
  } pun{
#ifdef _WIN32
  OUTCOME_V2_NAMESPACE::experimental::win32_code((OUTCOME_V2_NAMESPACE::experimental::win32::DWORD) errcode)
#else
  OUTCOME_V2_NAMESPACE::experimental::posix_code((int) errcode)
#endif
  };
  static_assert(sizeof(pun.cpp) == sizeof(pun.c), "");
  static constexpr size_t punoffset = offsetof(type_punner_t::cxx_status_code, flags);
  assert(bytes - offset >= sizeof(pun.cpp) - punoffset);
  const size_t tocopy = std::min(bytes - offset, sizeof(pun.cpp) - punoffset);
  memcpy(out, (void *) &pun.c, sizeof(value_type));
  memcpy((void *) ((char *) out + offset), (const void *) ((const char *) &pun.c + punoffset), tocopy);
}
OUTCOME_C_MSVC_FORCE_EMIT(outcome_make_result_status_code_failure_system)

extern "C" OUTCOME_C_WEAK int outcome_status_code_equal(const void *_a, const void *_b)
{
  const auto *a = (const SYSTEM_ERROR2_NAMESPACE::system_code *) _a;
  const auto *b = (const SYSTEM_ERROR2_NAMESPACE::system_code *) _b;
  return *a == *b;
}
OUTCOME_C_MSVC_FORCE_EMIT(outcome_status_code_equal)

extern "C" OUTCOME_C_WEAK int outcome_status_code_equal_generic(const void *_a, int errcode)
{
  const auto *a = (const SYSTEM_ERROR2_NAMESPACE::system_code *) _a;
  return *a == (SYSTEM_ERROR2_NAMESPACE::errc) errcode;
}
OUTCOME_C_MSVC_FORCE_EMIT(outcome_status_code_equal_generic)

extern "C" OUTCOME_C_WEAK const char *outcome_status_code_message(const void *_a)
{
  static thread_local SYSTEM_ERROR2_NAMESPACE::system_code::string_ref msg((const char *) nullptr, 0);
  const auto *a = (const SYSTEM_ERROR2_NAMESPACE::system_code *) _a;
  msg = a->message();
  return msg.c_str();
}
OUTCOME_C_MSVC_FORCE_EMIT(outcome_status_code_message)

OUTCOME_V2_NAMESPACE_BEGIN
namespace experimental
{
  namespace detail
  {
    template <class RetType, class EnumType> inline RetType outcome_make_result_failure_system_enum(EnumType v)
    {
      using value_type = OUTCOME_V2_NAMESPACE::experimental::system_code::value_type;
      union type_punner_t
      {
        OUTCOME_V2_NAMESPACE::experimental::status_result<intptr_t> cpp;
        struct cxx_status_code
        {
          intptr_t value;
          unsigned flags;
          cxx_status_code_system error;
        } c;

        explicit type_punner_t(OUTCOME_V2_NAMESPACE::experimental::status_result<intptr_t> res)
            : cpp(std::move(res))
        {
        }
        ~type_punner_t() {}
      } pun{OUTCOME_V2_NAMESPACE::experimental::quick_status_code_from_enum_code<EnumType>(v)};
      static constexpr size_t bytes = sizeof(RetType);
      static constexpr size_t offset = offsetof(RetType, flags);
      static constexpr size_t punoffset = offsetof(typename type_punner_t::cxx_status_code, flags);
      assert(bytes - offset >= sizeof(pun.cpp) - punoffset);
      const size_t tocopy = std::min(bytes - offset, sizeof(pun.cpp) - punoffset);
      RetType ret;
      memcpy(&ret, (void *) &pun.c, sizeof(value_type));
      memcpy((void *) ((char *) &ret + offset), (const void *) ((const char *) &pun.c + punoffset), tocopy);
      return ret;
    }
  }
}
OUTCOME_V2_NAMESPACE_END

// Unique UUID for the enum PLEASE use https://www.random.org/cgi-bin/randbyte?nbytes=16&format=h
// .. is sequence of {enum_name::value, "text description", {errc::equivalent, ...}},
#define CXX_DECLARE_RESULT_SYSTEM_FROM_ENUM(ident, enum_name, uuid, ...)                                                                                       \
  SYSTEM_ERROR2_NAMESPACE_BEGIN                                                                                                                                \
  template <> struct quick_status_code_from_enum<enum enum_name> : quick_status_code_from_enum_defaults<enum enum_name>                                        \
  {                                                                                                                                                            \
    static constexpr const auto domain_name = #enum_name;                                                                                                      \
    static constexpr const auto domain_uuid = uuid;                                                                                                            \
    static const std::initializer_list<mapping> &value_mappings()                                                                                              \
    {                                                                                                                                                          \
      static const std::initializer_list<mapping> v = {__VA_ARGS__};                                                                                           \
      return v;                                                                                                                                                \
    }                                                                                                                                                          \
  };                                                                                                                                                           \
  SYSTEM_ERROR2_NAMESPACE_END                                                                                                                                  \
  extern "C" OUTCOME_C_WEAK OUTCOME_C_NODISCARD struct cxx_result_status_code_system_##ident outcome_make_result_##ident##_failure_system_enum_##enum_name(    \
  enum enum_name v)                                                                                                                                            \
  {                                                                                                                                                            \
    return OUTCOME_V2_NAMESPACE::experimental::detail::outcome_make_result_failure_system_enum<struct cxx_result_status_code_system_##ident>(v);               \
  }                                                                                                                                                            \
  OUTCOME_C_MSVC_FORCE_EMIT(outcome_make_result_##ident##_failure_system_enum_##enum_name)


#endif

#endif
