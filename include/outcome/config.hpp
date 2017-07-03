/* Configure Outcome with QuickCppLib
(C) 2015-2017 Niall Douglas <http://www.nedproductions.biz/> (24 commits)
File Created: August 2015


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

#ifndef OUTCOME_V2_CONFIG_HPP
#define OUTCOME_V2_CONFIG_HPP

#include "version.hpp"

// Pull in detection of __MINGW64_VERSION_MAJOR
#if defined(__MINGW32__) && !defined(DOXYGEN_IS_IN_THE_HOUSE)
#include <_mingw.h>
#endif

#include "quickcpplib/include/config.hpp"

#ifndef __cpp_variadic_templates
#error Outcome needs variadic template support in the compiler
#endif
#ifndef __cpp_constexpr
#error Outcome needs constexpr (C++ 11) support in the compiler
#endif
#ifndef __cpp_variable_templates
#error Outcome needs variable template support in the compiler
#endif

#ifndef OUTCOME_SYMBOL_VISIBLE
#define OUTCOME_SYMBOL_VISIBLE QUICKCPPLIB_SYMBOL_VISIBLE
#endif
#ifndef OUTCOME_NODISCARD
#define OUTCOME_NODISCARD QUICKCPPLIB_NODISCARD
#endif
#ifndef OUTCOME_MSVC_WORKAROUNDS
// Older MSVC's constexpr isn't up to Outcome v2 and it ICEs, so don't use constexpr in those situations
#if defined(_MSC_VER) && !defined(__clang__) && _MSC_FULL_VER <= 191025019 /* VS2017 Update 2*/
#define OUTCOME_MSVC_WORKAROUNDS 1
#endif
#endif
#ifndef OUTCOME_MSVC_CONSTEXPR
#if OUTCOME_MSVC_WORKAROUNDS
#define OUTCOME_MSVC_CONSTEXPR
#else
#define OUTCOME_MSVC_CONSTEXPR constexpr
#endif
#endif

#include "quickcpplib/include/import.h"

#ifdef STANDARDESE_IS_IN_THE_HOUSE
/*! The namespace configuration of this Outcome v2. Consists of a sequence
of bracketed tokens later fused by the preprocessor into namespace and C++ module names.
*/
#define OUTCOME_V2
//! The Outcome namespace
namespace outcome
{
  //! Inline namespace for this version of Outcome
  inline namespace v2_xxx
  {
  }
}
}
/*! The namespace of this Boost.Outcome v2 which will be some unknown inline
namespace starting with `v2_` inside the `outcome` namespace.
*/
#define OUTCOME_V2_NAMESPACE outcome::v2_xxx
/*! Expands into the appropriate namespace markup to enter the Outcome v2 namespace.
*/
#define OUTCOME_V2_NAMESPACE_BEGIN                                                                                                                                                                                                                                                                                             \
  namespace outcome                                                                                                                                                                                                                                                                                                            \
  {                                                                                                                                                                                                                                                                                                                            \
    namespace v2_xxx                                                                                                                                                                                                                                                                                                           \
    {
/*! Expands into the appropriate namespace markup to enter the C++ module
exported Outcome v2 namespace.
*/
#define OUTCOME_V2_NAMESPACE_EXPORT_BEGIN                                                                                                                                                                                                                                                                                      \
  export namespace outcome                                                                                                                                                                                                                                                                                                     \
  {                                                                                                                                                                                                                                                                                                                            \
    inline namespace v2_xxx                                                                                                                                                                                                                                                                                                    \
    {
/*! \brief Expands into the appropriate namespace markup to exit the Outcome v2 namespace.
\ingroup config
*/
#define OUTCOME_V2_NAMESPACE_END                                                                                                                                                                                                                                                                                               \
  }                                                                                                                                                                                                                                                                                                                            \
  }
#else

#if defined(OUTCOME_UNSTABLE_VERSION)
#include "revision.hpp"
#ifdef OUTCOME_DISABLE_INLINE_NAMESPACE
#define OUTCOME_V2 (outcome), (QUICKCPPLIB_BIND_NAMESPACE_VERSION(, OUTCOME_NAMESPACE_VERSION, OUTCOME_PREVIOUS_COMMIT_UNIQUE))
#else
#define OUTCOME_V2 (outcome), (QUICKCPPLIB_BIND_NAMESPACE_VERSION(, OUTCOME_NAMESPACE_VERSION, OUTCOME_PREVIOUS_COMMIT_UNIQUE), inline)
#endif
#else
#ifdef OUTCOME_DISABLE_INLINE_NAMESPACE
#define OUTCOME_V2 (outcome), (QUICKCPPLIB_BIND_NAMESPACE_VERSION(, OUTCOME_NAMESPACE_VERSION))
#else
#define OUTCOME_V2 (outcome), (QUICKCPPLIB_BIND_NAMESPACE_VERSION(, OUTCOME_NAMESPACE_VERSION), inline)
#endif
#endif

#if defined(GENERATING_OUTCOME_MODULE_INTERFACE)
#define OUTCOME_V2_NAMESPACE QUICKCPPLIB_BIND_NAMESPACE(OUTCOME_V2)
#define OUTCOME_V2_NAMESPACE_BEGIN QUICKCPPLIB_BIND_NAMESPACE_BEGIN(OUTCOME_V2)
#define OUTCOME_V2_NAMESPACE_EXPORT_BEGIN QUICKCPPLIB_BIND_NAMESPACE_EXPORT_BEGIN(OUTCOME_V2)
#define OUTCOME_V2_NAMESPACE_END QUICKCPPLIB_BIND_NAMESPACE_END(OUTCOME_V2)
#else
#define OUTCOME_V2_NAMESPACE QUICKCPPLIB_BIND_NAMESPACE(OUTCOME_V2)
#define OUTCOME_V2_NAMESPACE_BEGIN QUICKCPPLIB_BIND_NAMESPACE_BEGIN(OUTCOME_V2)
#define OUTCOME_V2_NAMESPACE_EXPORT_BEGIN QUICKCPPLIB_BIND_NAMESPACE_BEGIN(OUTCOME_V2)
#define OUTCOME_V2_NAMESPACE_END QUICKCPPLIB_BIND_NAMESPACE_END(OUTCOME_V2)
#endif
#endif

#ifndef OUTCOME_DO_FATAL_EXIT
#ifdef _WIN32
#include "quickcpplib/include/execinfo_win64.h"
#else
#include <execinfo.h>
#endif
#include <stdio.h>
#include <stdlib.h>
OUTCOME_V2_NAMESPACE_BEGIN
namespace detail
{
  QUICKCPPLIB_NORETURN inline void do_fatal_exit(const char *expr)
  {
    void *bt[16];
    size_t btlen = backtrace(bt, sizeof(bt) / sizeof(bt[0]));
    fprintf(stderr, "FATAL: Outcome throws exception %s with exceptions disabled\n", expr);
    char **bts = backtrace_symbols(bt, btlen);
    if(bts)
    {
      for(size_t n = 0; n < btlen; n++)
        fprintf(stderr, "  %s\n", bts[n]);
      free(bts);
    }
    abort();
  }
}
OUTCOME_V2_NAMESPACE_END
#define OUTCOME_DO_FATAL_EXIT(expr) OUTCOME_V2_NAMESPACE::detail::do_fatal_exit(#expr)
#endif


#endif
