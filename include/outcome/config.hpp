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
#if __cpp_constexpr < 201304 && _MSC_FULL_VER < 191100000
#error Outcome needs constexpr (C++ 14) support in the compiler
#endif
#ifndef __cpp_variable_templates
#error Outcome needs variable template support in the compiler
#endif

#ifdef DOXYGEN_IS_IN_THE_HOUSE
#define OUTCOME_FORCEINLINE
#define OUTCOME_NODISCARD [[nodiscard]]
#define OUTCOME_TEMPLATE(...) template <__VA_ARGS__
#define OUTCOME_TREQUIRES(...) , __VA_ARGS__ >
#define OUTCOME_TEXPR(...) typename = decltype(__VA_ARGS__)
#define OUTCOME_TPRED(...) typename = std::enable_if_t<__VA_ARGS__>
#define OUTCOME_REQUIRES(...) requires __VA_ARGS__
/*! \mainpage
\htmlonly
<script type="text/javascript">
window.location.href = "https://ned14.github.io/outcome/"
</script>
If you are not redirected automatically, follow this link to <a href='https://ned14.github.io/outcome/'>https://ned14.github.io/outcome/</a>.
\endhtmlonly
*/
#endif

#ifndef OUTCOME_SYMBOL_VISIBLE
#define OUTCOME_SYMBOL_VISIBLE QUICKCPPLIB_SYMBOL_VISIBLE
#endif
#ifndef OUTCOME_NODISCARD
#define OUTCOME_NODISCARD QUICKCPPLIB_NODISCARD
#endif
#ifndef OUTCOME_THREAD_LOCAL
#define OUTCOME_THREAD_LOCAL QUICKCPPLIB_THREAD_LOCAL
#endif
#ifndef OUTCOME_TEMPLATE
#define OUTCOME_TEMPLATE(...) QUICKCPPLIB_TEMPLATE(__VA_ARGS__)
#endif
#ifndef OUTCOME_TREQUIRES
#define OUTCOME_TREQUIRES(...) QUICKCPPLIB_TREQUIRES(__VA_ARGS__)
#endif
#ifndef OUTCOME_TEXPR
#define OUTCOME_TEXPR(...) QUICKCPPLIB_TEXPR(__VA_ARGS__)
#endif
#ifndef OUTCOME_TPRED
#define OUTCOME_TPRED(...) QUICKCPPLIB_TPRED(__VA_ARGS__)
#endif
#ifndef OUTCOME_REQUIRES
#define OUTCOME_REQUIRES(...) QUICKCPPLIB_REQUIRES(__VA_ARGS__)
#endif

#include "quickcpplib/include/import.h"

#ifdef STANDARDESE_IS_IN_THE_HOUSE
/*! The namespace configuration of this Outcome v2. Consists of a sequence
of bracketed tokens later fused by the preprocessor into namespace and C++ module names.
*/
#define OUTCOME_V2
//! The Outcome namespace
namespace outcome_v2_xxx
{
}
/*! The namespace of this Outcome v2.
*/
#define OUTCOME_V2_NAMESPACE outcome_v2_xxx
/*! Expands into the appropriate namespace markup to enter the Outcome v2 namespace.
*/
#define OUTCOME_V2_NAMESPACE_BEGIN                                                                                                                                                                                                                                                                                             \
  namespace outcome_v2_xxx                                                                                                                                                                                                                                                                                                     \
  {
/*! Expands into the appropriate namespace markup to enter the C++ module
exported Outcome v2 namespace.
*/
#define OUTCOME_V2_NAMESPACE_EXPORT_BEGIN                                                                                                                                                                                                                                                                                      \
  export namespace outcome_v2_xxx                                                                                                                                                                                                                                                                                              \
  {
/*! \brief Expands into the appropriate namespace markup to exit the Outcome v2 namespace.
\ingroup config
*/
#define OUTCOME_V2_NAMESPACE_END }
#else

#if defined(OUTCOME_UNSTABLE_VERSION)
#include "revision.hpp"
#define OUTCOME_V2 (QUICKCPPLIB_BIND_NAMESPACE_VERSION(outcome_v2, OUTCOME_PREVIOUS_COMMIT_UNIQUE))
#else
#define OUTCOME_V2 (QUICKCPPLIB_BIND_NAMESPACE_VERSION(outcome_v2))
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

#ifndef OUTCOME_THROW_EXCEPTION
#ifdef __cpp_exceptions
#define OUTCOME_THROW_EXCEPTION(expr) throw expr
#else

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
#define OUTCOME_THROW_EXCEPTION(expr) OUTCOME_V2_NAMESPACE::detail::do_fatal_exit(#expr)

#endif
#endif

#ifndef BOOST_OUTCOME_AUTO_TEST_CASE
#define BOOST_OUTCOME_AUTO_TEST_CASE(a, b) BOOST_AUTO_TEST_CASE(a, b)
#endif

#endif
