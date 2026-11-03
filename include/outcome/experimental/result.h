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

#include <assert.h>
#include <stddef.h>  // for size_t
#include <stdint.h>  // for intptr_t

#include "../detail/try.h"

#ifndef OUTCOME_C_WEAK
#ifdef _MSC_VER
#define OUTCOME_C_WEAK inline
#else
#define OUTCOME_C_WEAK __attribute__((weak))
#endif
#endif

// The weak helpers below sit on a cross-language AND cross-DSO boundary: a C
// consumer living in another shared object has to be able to bind to them, so
// they must stay exported even when the project builds with
// -fvisibility=hidden. (On MSVC the COMDAT emitted by OUTCOME_C_WEAK inline plus
// OUTCOME_C_MSVC_FORCE_EMIT already reaches the consumer through the import
// library, and mixing dllexport with inline is not portable.)
#ifndef OUTCOME_C_EXPORT
#ifdef _MSC_VER
#define OUTCOME_C_EXPORT
#else
#define OUTCOME_C_EXPORT __attribute__((visibility("default")))
#endif
#endif

#ifndef OUTCOME_C_MSVC_FORCE_EMIT
#ifdef _MSC_VER
#ifdef __cplusplus
#define OUTCOME_C_MSVC_FORCE_EMIT(x) extern "C" __declspec(selectany) void *x##_emit = x;
#else
#define OUTCOME_C_MSVC_FORCE_EMIT(x) extern __declspec(selectany) void *x##_emit = x;
#endif
#else
#define OUTCOME_C_MSVC_FORCE_EMIT(x)
#endif
#endif


#ifndef OUTCOME_C_NODISCARD
#if __STDC_VERSION__ >= 202000L || __cplusplus >= 201700L
#define OUTCOME_C_NODISCARD [[nodiscard]]
#elif defined(__GNUC__) || defined(__clang__)
#define OUTCOME_C_NODISCARD __attribute__((warn_unused_result))
#else
#define OUTCOME_C_NODISCARD
#endif
#endif

// The C ABI's names must have C linkage in EVERY C++ translation unit, and that is
// not something the language version can tell you: MSVC reports __cplusplus as
// 199711L unless /Zc:__cplusplus is passed, which is not CMake's default. Spelling
// `extern "C"` only on the C++17-or-later and GNU branches therefore left the
// definitions below with C++ linkage - a mangled name - in every default MSVC C++
// build: `_Z47outcome_make_result_system_mylib_failure_systeml` where the C
// translation unit beside it referenced
// `outcome_make_result_system_mylib_failure_system`, i.e. LNK2019 "unresolved
// external symbol" on the Windows lane, for every result type. `extern "C"` is
// now decided by the language alone, and the attribute only by the version.
#ifndef OUTCOME_C_NODISCARD_EXTERN_C
#ifdef __cplusplus
#define OUTCOME_C_NODISCARD_EXTERN_C extern "C" OUTCOME_C_NODISCARD
#else
#define OUTCOME_C_NODISCARD_EXTERN_C OUTCOME_C_NODISCARD extern
#endif
#endif

#ifndef OUTCOME_C_INLINE
#if __STDC_VERSION__ >= 199900L || __cplusplus > 0
#define OUTCOME_C_INLINE inline
#elif defined(__GNUC__) || defined(__clang__) || defined(_MSC_VER)
#define OUTCOME_C_INLINE __inline
#else
#define OUTCOME_C_INLINE
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

  // These are STRONG declarations on purpose. The DEFINITIONS below are weak so
  // that any number of C++ translation units including this header coalesce into
  // one - that is the intended paradigm, "compile this header in C++ at least
  // once". Marking the declarations weak as well made every reference a WEAK
  // reference, and a weak reference neither causes the linker to extract an
  // archive member nor fails when nothing defines the symbol: a C consumer
  // linking a static library got NULL and called it (assert in debug, SIGSEGV in
  // release). Strong references turn "you forgot the C++ TU" into an
  // undefined-reference error, i.e. the paradigm enforced by the linker.
  extern void outcome_make_result_status_code_failure_posix(void *out, size_t bytes, size_t offset, int errcode);
  extern void outcome_make_result_status_code_failure_system(void *out, size_t bytes, size_t offset, intptr_t errcode);
  extern int outcome_status_code_equal(const void *a, const void *b);
  extern int outcome_status_code_equal_generic(const void *a, int errcode);
  extern const char *outcome_status_code_message(const void *a);

#ifdef OUTCOME_C_RESULT_NO_CXX
#ifndef __cplusplus
  // Opt-in escape hatch for a C-only program that cannot add a C++ TU: stubs
  // that say what is wrong, instead of the link error above. Weak so several C
  // TUs can include this header without duplicate symbols.
#include <stdio.h>
#include <stdlib.h>
  static void outcome_c_result_no_cxx_support(const char *fn)
  {
    fprintf(stderr,
            "FATAL: %s() needs Outcome's C ABI, which is implemented in C++. Compile "
            "<outcome/experimental/result.h> in at least one C++ translation unit, or remove "
            "OUTCOME_C_RESULT_NO_CXX to get a link error instead of this runtime one.\n",
            fn);
    abort();
  }
  OUTCOME_C_WEAK OUTCOME_C_EXPORT void outcome_make_result_status_code_failure_posix(void *out, size_t bytes, size_t offset, int errcode)
  {
    (void) out; (void) bytes; (void) offset; (void) errcode;
    outcome_c_result_no_cxx_support("outcome_make_result_status_code_failure_posix");
  }
  OUTCOME_C_WEAK OUTCOME_C_EXPORT void outcome_make_result_status_code_failure_system(void *out, size_t bytes, size_t offset, intptr_t errcode)
  {
    (void) out; (void) bytes; (void) offset; (void) errcode;
    outcome_c_result_no_cxx_support("outcome_make_result_status_code_failure_system");
  }
  OUTCOME_C_WEAK OUTCOME_C_EXPORT int outcome_status_code_equal(const void *a, const void *b)
  {
    (void) a; (void) b;
    outcome_c_result_no_cxx_support("outcome_status_code_equal");
    return 0;
  }
  OUTCOME_C_WEAK OUTCOME_C_EXPORT int outcome_status_code_equal_generic(const void *a, int errcode)
  {
    (void) a; (void) errcode;
    outcome_c_result_no_cxx_support("outcome_status_code_equal_generic");
    return 0;
  }
  OUTCOME_C_WEAK OUTCOME_C_EXPORT const char *outcome_status_code_message(const void *a)
  {
    (void) a;
    outcome_c_result_no_cxx_support("outcome_status_code_message");
    return "";
  }
#endif
#endif


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
  OUTCOME_C_NODISCARD inline cxx_result_status_code_##ident to_##ident(OUTCOME_V2_NAMESPACE::experimental::status_result<R> v)                                 \
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
  }                                                                                                                                                            \
  /* The struct declared by CXX_DECLARE_RESULT_STATUS_CODE is the layout; this  \
  proves the C++ type it is punned against has that same layout, so the puns    \
  above and the makers are sound. Offsets are read off the real                \
  status_result<R> storage, never off a second description of the layout. */    \
  static_assert(offsetof(struct cxx_result_status_code_##ident, value) == OUTCOME_V2_NAMESPACE::detail::cxx_result_cpp_layout<R>::value_offset,                \
                "the C result's value must sit where status_result<R>'s value does");                                                                        \
  static_assert(offsetof(struct cxx_result_status_code_##ident, flags) == OUTCOME_V2_NAMESPACE::detail::cxx_result_cpp_layout<R>::flags_offset,                \
                "the C result's status word must sit where status_result<R>'s status word does");                                                            \
  static_assert(offsetof(struct cxx_result_status_code_##ident, error) == OUTCOME_V2_NAMESPACE::detail::cxx_result_cpp_layout<R>::error_offset,                \
                "the C result's status code must sit where status_result<R>'s status code does");                                                             \
  static_assert(sizeof(struct cxx_result_status_code_##ident) == sizeof(OUTCOME_V2_NAMESPACE::experimental::status_result<R>),                                 \
                "the C result must be exactly as big as status_result<R>");                                                                                   \
  static_assert(alignof(struct cxx_result_status_code_##ident) == alignof(OUTCOME_V2_NAMESPACE::experimental::status_result<R>),                              \
                "the C result must be aligned as status_result<R>")
#else
#define CXX_DECLARE_RESULT_STATUS_CODE_CXX(ident, R, S)
#endif

// The status code object the system variant of every C result starts from. It
// differs per platform (and so does the expression which makes it).
#ifdef __cplusplus
#ifdef _WIN32
#define OUTCOME_C_RESULT_SYSTEM_CODE(errcode) OUTCOME_V2_NAMESPACE::experimental::win32_code((OUTCOME_V2_NAMESPACE::experimental::win32::DWORD) (errcode))
#else
#define OUTCOME_C_RESULT_SYSTEM_CODE(errcode) OUTCOME_V2_NAMESPACE::experimental::posix_code((int) (errcode))
#endif

// Fills a C result from a freshly made failure status code.
//
// There is exactly ONE description of a C result's layout: the struct that
// CXX_DECLARE_RESULT_STATUS_CODE declares. This puns the C++ `status_result<R>`
// against that very struct - `pun.c` IS the declared type - so every offset comes
// from the compiler and none is written out here (there is no mirror struct and no
// caller-supplied layout fact left to drift).
//
// What makes the pun sound is CXX_DECLARE_RESULT_STATUS_CODE_CXX: it
// static_asserts that the declared struct and `status_result<R>` agree on the
// offsets of the value, of the status word and of the status code, on their size
// and on their alignment. If the two layouts ever drift, the header stops
// compiling instead of the status code landing where the reader never looks. (The
// makers used to pun against a hand written
// `{intptr_t value; unsigned flags; ...}` mirror, so any R whose status word was
// not pointer sized was filled at the wrong offset: an assert in a debug build,
// silent corruption with NDEBUG.)
#define CXX_DECLARE_RESULT_FAILURE_MAKER(ident, R, S, suffix, argtype, code_expr)                                                                              \
  OUTCOME_C_NODISCARD_EXTERN_C OUTCOME_C_WEAK struct cxx_result_status_code_##ident outcome_make_result_##ident##_failure_##suffix(argtype errcode)            \
  {                                                                                                                                                            \
    union type_punner_t                                                                                                                                        \
    {                                                                                                                                                          \
      struct cxx_result_status_code_##ident c;                                                                                                                 \
      OUTCOME_V2_NAMESPACE::experimental::status_result<R> cpp;                                                                                                \
                                                                                                                                                               \
      explicit type_punner_t(OUTCOME_V2_NAMESPACE::experimental::status_result<R> res)                                                                         \
          : cpp(static_cast<OUTCOME_V2_NAMESPACE::experimental::status_result<R> &&>(res))                                                                     \
      {                                                                                                                                                        \
      }                                                                                                                                                        \
      ~type_punner_t() {}                                                                                                                                      \
    } pun{code_expr};                                                                                                                                          \
    return pun.c;                                                                                                                                              \
  }                                                                                                                                                            \
  OUTCOME_C_MSVC_FORCE_EMIT(outcome_make_result_##ident##_failure_##suffix)
#else
// No status code can be constructed without a C++ compiler, so a C translation
// unit cannot supply the implementation any more than it can supply the shared
// helpers below: it gets a declaration, and a program which forgot the C++ TU
// fails to link instead of filling the result from a layout guess. (Before this
// the C side emitted its own weak definition calling the intptr_t-shaped helper,
// which both broke R != intptr_t and left two competing weak definitions of the
// same symbol.)
#ifdef OUTCOME_C_RESULT_NO_CXX
// ... except in the documented C-only escape hatch, which forwards to the stub
// that explains what is missing (and aborts) rather than to a link error. The
// last two arguments describe the failure status code and are only used by the
// C++ definition above.
#define CXX_DECLARE_RESULT_FAILURE_MAKER(ident, R, S, suffix, argtype, code_expr)                                                                              \
  OUTCOME_C_NODISCARD_EXTERN_C OUTCOME_C_WEAK struct cxx_result_status_code_##ident outcome_make_result_##ident##_failure_##suffix(argtype errcode)            \
  {                                                                                                                                                            \
    struct cxx_result_status_code_##ident ret;                                                                                                                 \
    outcome_make_result_status_code_failure_##suffix((void *) &ret, sizeof(ret), offsetof(struct cxx_result_status_code_##ident, flags), errcode);              \
    return ret;                                                                                                                                                \
  }
#else
#define CXX_DECLARE_RESULT_FAILURE_MAKER(ident, R, S, suffix, argtype, code_expr)                                                                              \
  OUTCOME_C_NODISCARD_EXTERN_C struct cxx_result_status_code_##ident outcome_make_result_##ident##_failure_##suffix(argtype errcode);
#endif
#endif

#define CXX_DECLARE_RESULT_FAILURE_MAKERS(ident, R, S)                                                                                                         \
  CXX_DECLARE_RESULT_FAILURE_MAKER(ident, R, S, posix, int, OUTCOME_V2_NAMESPACE::experimental::posix_code(errcode))                                          \
  CXX_DECLARE_RESULT_FAILURE_MAKER(ident, R, S, system, intptr_t, OUTCOME_C_RESULT_SYSTEM_CODE(errcode))

// The one and only description of a C result's layout. The status word is the 4
// byte `{unsigned short status; unsigned short spare_storage;}` that
// status_result<R> keeps in its status_bitfield_type, i.e. a 4 byte word aligned
// to 2 - which is why it is spelled as two 16 bit halves and not as one `unsigned
// flags` (a 4 byte member would be forced to a 4 byte offset, which is NOT where
// status_result<R> puts its status word when sizeof(R) % 4 is 1 or 2: an `int`
// would agree, a `char` would not). CXX_DECLARE_RESULT_STATUS_CODE_CXX
// static_asserts that this struct and status_result<R> agree in every offset,
// their size and their alignment.
#define CXX_DECLARE_RESULT_STATUS_CODE(ident, R, S)                                                                                                            \
  struct cxx_result_status_code_##ident                                                                                                                        \
  {                                                                                                                                                            \
    R value;                                                                                                                                                   \
    unsigned short flags; /* status::have_value, status::have_error, ... */                                                                                    \
    unsigned short spare_storage; /* hooks::spare_storage() */                                                                                                 \
    S error;                                                                                                                                                   \
  };                                                                                                                                                           \
  OUTCOME_C_NODISCARD static OUTCOME_C_INLINE struct cxx_result_status_code_##ident outcome_make_result_##ident##_success(R value)                             \
  { /* We special case this so it inlines efficiently */                                                                                                       \
    struct cxx_result_status_code_##ident ret;                                                                                                                 \
    ret.value = value;                                                                                                                                         \
    ret.flags = 1 /* have_value */;                                                                                                                            \
    ret.spare_storage = 0;                                                                                                                                     \
    return ret;                                                                                                                                                \
  }                                                                                                                                                            \
  CXX_DECLARE_RESULT_FAILURE_MAKERS(ident, R, S)                                                                                                               \
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
  OUTCOME_C_NODISCARD_EXTERN_C struct cxx_result_status_code_system_##ident outcome_make_result_##ident##_failure_system_enum_##enum_name(enum enum_name v);
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
#include <type_traits>
#include <utility>

OUTCOME_V2_NAMESPACE_BEGIN
namespace detail
{
  // The class a pointer to member belongs to: `T C::*` -> `C`.
  template <class Pm> struct cxx_pointer_to_member_class;
  template <class C, class T> struct cxx_pointer_to_member_class<T C::*>
  {
    using type = C;
  };

  // Where a `status_result<R>` keeps its value, its status word and its status
  // code. Read off the C++ type itself - `_state`'s own member offsets - rather
  // than computed from a formula, so that the header has no layout description
  // other than the C result struct which the CXX_DECLARE_RESULT_* macros declare
  // (and which is checked against these numbers where it is declared).
  //
  // `_state` is basic_result_storage's only data member and the observer bases are
  // empty, so its offsets are the result's offsets. `_state` itself may be one of
  // the value_storage_delete_* wrappers, which derive from the storage that
  // declares `_status`; the pointer-to-member type names that declaration's class.
  //
  // That class is not a standard layout type (its status code member's type is
  // not), so `offsetof` on it is conditionally-supported. Every compiler this
  // header supports answers with the member's real offset - the same one codegen
  // uses - which is exactly what is wanted here; the pragma silences the pedantic
  // "conditionally-supported" diagnostic that would otherwise be emitted in every
  // user's translation unit.
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"
#elif defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Winvalid-offsetof"
#endif
  template <class R> struct cxx_result_cpp_layout
  {
    using result_type = OUTCOME_V2_NAMESPACE::experimental::status_result<R>;
    // _iostreams_state() is the public accessor for _state (basic_result_storage).
    using state_type = std::remove_reference_t<decltype(std::declval<result_type &>()._iostreams_state())>;
    using state_root_type = typename cxx_pointer_to_member_class<decltype(&state_type::_status)>::type;

    static constexpr size_t value_offset = offsetof(state_root_type, _value);
    static constexpr size_t flags_offset = offsetof(state_root_type, _status);
    static constexpr size_t error_offset = offsetof(state_root_type, _error);
  };
#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
}  // namespace detail
OUTCOME_V2_NAMESPACE_END

#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
#endif

// You need to include this C header in at least one C++ source file to have these C helper functions be implemented
//
// Both helpers fill a caller's buffer with a failure `status_result<intptr_t>`: the
// shape these symbols were defined with, and the only shape they can support since
// they are told nothing about the caller's value type. Their layout facts (the
// status word's offset, the result's size) are read off that real C++ type, not off
// a struct written out here by hand: the C result structs declared by
// CXX_DECLARE_RESULT_STATUS_CODE are this header's one description of a result's
// layout, and each is static_asserted against the C++ type it is punned with where
// it is declared. A caller whose struct is not this shape gets a bitless zeroed
// result rather than a status code written where the reader never looks (in a debug
// build the assert names the mismatch). Nothing in this header routes a result
// through here - the makers pun their own R, see
// CXX_DECLARE_RESULT_FAILURE_MAKER - so these symbols exist for the
// OUTCOME_C_RESULT_NO_CXX escape hatch and for C callers who want the intptr_t
// shape explicitly.
template <class StatusCode> static OUTCOME_C_INLINE void outcome_fill_intptr_result(void *out, size_t bytes, size_t offset, StatusCode code)
{
  using cpp_result_t = OUTCOME_V2_NAMESPACE::experimental::status_result<intptr_t>;
  using layout_t = OUTCOME_V2_NAMESPACE::detail::cxx_result_cpp_layout<intptr_t>;
  const cpp_result_t res(code);
  if(offset != layout_t::flags_offset || bytes != sizeof(cpp_result_t))
  {
    assert(offset == layout_t::flags_offset && bytes == sizeof(cpp_result_t));
    memset(out, 0, bytes);  // a bitless result: neither a value nor an error
    return;
  }
  memcpy(out, (const void *) &res, sizeof(cpp_result_t));
}

extern "C" OUTCOME_C_WEAK OUTCOME_C_EXPORT void outcome_make_result_status_code_failure_posix(void *out, size_t bytes, size_t offset, int errcode)
{
  outcome_fill_intptr_result(out, bytes, offset, OUTCOME_V2_NAMESPACE::experimental::posix_code(errcode));
}
OUTCOME_C_MSVC_FORCE_EMIT(outcome_make_result_status_code_failure_posix)

extern "C" OUTCOME_C_WEAK OUTCOME_C_EXPORT void outcome_make_result_status_code_failure_system(void *out, size_t bytes, size_t offset, intptr_t errcode)
{
  outcome_fill_intptr_result(out, bytes, offset, OUTCOME_C_RESULT_SYSTEM_CODE(errcode));
}
OUTCOME_C_MSVC_FORCE_EMIT(outcome_make_result_status_code_failure_system)

extern "C" OUTCOME_C_WEAK OUTCOME_C_EXPORT int outcome_status_code_equal(const void *_a, const void *_b)
{
  const auto *a = (const SYSTEM_ERROR2_NAMESPACE::system_code *) _a;
  const auto *b = (const SYSTEM_ERROR2_NAMESPACE::system_code *) _b;
  return *a == *b;
}
OUTCOME_C_MSVC_FORCE_EMIT(outcome_status_code_equal)

extern "C" OUTCOME_C_WEAK OUTCOME_C_EXPORT int outcome_status_code_equal_generic(const void *_a, int errcode)
{
  const auto *a = (const SYSTEM_ERROR2_NAMESPACE::system_code *) _a;
  return *a == (SYSTEM_ERROR2_NAMESPACE::errc) errcode;
}
OUTCOME_C_MSVC_FORCE_EMIT(outcome_status_code_equal_generic)

extern "C" OUTCOME_C_WEAK OUTCOME_C_EXPORT const char *outcome_status_code_message(const void *_a)
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
      // The value type of the C result being filled, taken from the struct itself
      // so this punner has exactly the shape of RetType (it used to be intptr_t,
      // which put the status word at the wrong offset for every other R), and
      // punned against RetType, whose layout is static_asserted against it where
      // the result was declared.
      union type_punner_t
      {
        RetType c;
        OUTCOME_V2_NAMESPACE::experimental::status_result<std::remove_reference_t<decltype(std::declval<RetType>().value)>> cpp;

        explicit type_punner_t(OUTCOME_V2_NAMESPACE::experimental::status_result<std::remove_reference_t<decltype(std::declval<RetType>().value)>> res)
            : cpp(std::move(res))
        {
        }
        ~type_punner_t() {}
      } pun{OUTCOME_V2_NAMESPACE::experimental::quick_status_code_from_enum_code<EnumType>(v)};
      return pun.c;
    }
  }  // namespace detail
}  // namespace experimental
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
  extern "C" OUTCOME_C_NODISCARD OUTCOME_C_WEAK struct cxx_result_status_code_system_##ident outcome_make_result_##ident##_failure_system_enum_##enum_name(    \
  enum enum_name v)                                                                                                                                            \
  {                                                                                                                                                            \
    return OUTCOME_V2_NAMESPACE::experimental::detail::outcome_make_result_failure_system_enum<struct cxx_result_status_code_system_##ident>(v);               \
  }                                                                                                                                                            \
  OUTCOME_C_MSVC_FORCE_EMIT(outcome_make_result_##ident##_failure_system_enum_##enum_name)

#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif

#endif

#endif
