/* A less simple result type
(C) 2018 Niall Douglas <http://www.nedproductions.biz/> (59 commits)
File Created: Apr 2018


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

#ifndef OUTCOME_EXPERIMENTAL_STATUS_OUTCOME_HPP
#define OUTCOME_EXPERIMENTAL_STATUS_OUTCOME_HPP
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

#ifndef OUTCOME_BASIC_OUTCOME_HPP
#define OUTCOME_BASIC_OUTCOME_HPP
/* Configure Outcome with QuickCppLib
(C) 2015-2018 Niall Douglas <http://www.nedproductions.biz/> (24 commits)
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
/*! AWAITING HUGO JSON CONVERSION TOOL */
#define OUTCOME_VERSION_MAJOR    2
/*! AWAITING HUGO JSON CONVERSION TOOL */
#define OUTCOME_VERSION_MINOR    0
/*! AWAITING HUGO JSON CONVERSION TOOL */
#define OUTCOME_VERSION_PATCH    0
/*! AWAITING HUGO JSON CONVERSION TOOL */
#define OUTCOME_VERSION_REVISION 0  // Revision version for cmake and DLL version stamping

/*! AWAITING HUGO JSON CONVERSION TOOL */
#ifndef OUTCOME_DISABLE_ABI_PERMUTATION
#define OUTCOME_UNSTABLE_VERSION
#endif
// Pull in detection of __MINGW64_VERSION_MAJOR
#if defined(__MINGW32__) && !0
#include <_mingw.h>
#endif
/* Configure QuickCppLib
(C) 2016-2017 Niall Douglas <http://www.nedproductions.biz/> (8 commits)


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

#ifndef QUICKCPPLIB_CONFIG_HPP
#define QUICKCPPLIB_CONFIG_HPP
/* Provides SG-10 feature checking for all C++ compilers
(C) 2014-2017 Niall Douglas <http://www.nedproductions.biz/> (13 commits)
File Created: Nov 2014


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

#ifndef QUICKCPPLIB_HAS_FEATURE_H
#define QUICKCPPLIB_HAS_FEATURE_H

#if __cplusplus >= 201103

// Some of these macros ended up getting removed by ISO standards,
// they are prefixed with ////
////#if !defined(__cpp_alignas)
////#define __cpp_alignas 190000
////#endif
////#if !defined(__cpp_default_function_template_args)
////#define __cpp_default_function_template_args 190000
////#endif
////#if !defined(__cpp_defaulted_functions)
////#define __cpp_defaulted_functions 190000
////#endif
////#if !defined(__cpp_deleted_functions)
////#define __cpp_deleted_functions 190000
////#endif
////#if !defined(__cpp_generalized_initializers)
////#define __cpp_generalized_initializers 190000
////#endif
////#if !defined(__cpp_implicit_moves)
////#define __cpp_implicit_moves 190000
////#endif
////#if !defined(__cpp_inline_namespaces)
////#define __cpp_inline_namespaces 190000
////#endif
////#if !defined(__cpp_local_type_template_args)
////#define __cpp_local_type_template_args 190000
////#endif
////#if !defined(__cpp_noexcept)
////#define __cpp_noexcept 190000
////#endif
////#if !defined(__cpp_nonstatic_member_init)
////#define __cpp_nonstatic_member_init 190000
////#endif
////#if !defined(__cpp_nullptr)
////#define __cpp_nullptr 190000
////#endif
////#if !defined(__cpp_override_control)
////#define __cpp_override_control 190000
////#endif
////#if !defined(__cpp_thread_local)
////#define __cpp_thread_local 190000
////#endif
////#if !defined(__cpp_auto_type)
////#define __cpp_auto_type 190000
////#endif
////#if !defined(__cpp_strong_enums)
////#define __cpp_strong_enums 190000
////#endif
////#if !defined(__cpp_trailing_return)
////#define __cpp_trailing_return 190000
////#endif
////#if !defined(__cpp_unrestricted_unions)
////#define __cpp_unrestricted_unions 190000
////#endif

#if !defined(__cpp_alias_templates)
#define __cpp_alias_templates 190000
#endif

#if !defined(__cpp_attributes)
#define __cpp_attributes 190000
#endif

#if !defined(__cpp_constexpr)
#if __cplusplus >= 201402
#define __cpp_constexpr 201304  // relaxed constexpr
#else
#define __cpp_constexpr 190000
#endif
#endif

#if !defined(__cpp_decltype)
#define __cpp_decltype 190000
#endif

#if !defined(__cpp_delegating_constructors)
#define __cpp_delegating_constructors 190000
#endif

#if !defined(__cpp_explicit_conversion)   //// renamed from __cpp_explicit_conversions
#define __cpp_explicit_conversion 190000
#endif

#if !defined(__cpp_inheriting_constructors)
#define __cpp_inheriting_constructors 190000
#endif

#if !defined(__cpp_initializer_lists)   //// NEW
#define __cpp_initializer_lists 190000
#endif

#if !defined(__cpp_lambdas)
#define __cpp_lambdas 190000
#endif

#if !defined(__cpp_nsdmi)
#define __cpp_nsdmi 190000  //// NEW
#endif

#if !defined(__cpp_range_based_for)   //// renamed from __cpp_range_for
#define __cpp_range_based_for 190000
#endif

#if !defined(__cpp_raw_strings)
#define __cpp_raw_strings 190000
#endif

#if !defined(__cpp_ref_qualifiers)   //// renamed from __cpp_reference_qualified_functions
#define __cpp_ref_qualifiers 190000
#endif

#if !defined(__cpp_rvalue_references)
#define __cpp_rvalue_references 190000
#endif

#if !defined(__cpp_static_assert)
#define __cpp_static_assert 190000
#endif

#if !defined(__cpp_unicode_characters)   //// NEW
#define __cpp_unicode_characters 190000
#endif

#if !defined(__cpp_unicode_literals)
#define __cpp_unicode_literals 190000
#endif

#if !defined(__cpp_user_defined_literals)
#define __cpp_user_defined_literals 190000
#endif

#if !defined(__cpp_variadic_templates)
#define __cpp_variadic_templates 190000
#endif

#endif

#if __cplusplus >= 201402

// Some of these macros ended up getting removed by ISO standards,
// they are prefixed with ////
////#if !defined(__cpp_contextual_conversions)
////#define __cpp_contextual_conversions 190000
////#endif
////#if !defined(__cpp_digit_separators)
////#define __cpp_digit_separators 190000
////#endif
////#if !defined(__cpp_relaxed_constexpr)
////#define __cpp_relaxed_constexpr 190000
////#endif
////#if !defined(__cpp_runtime_arrays)
////# define __cpp_runtime_arrays 190000
////#endif


#if !defined(__cpp_aggregate_nsdmi)
#define __cpp_aggregate_nsdmi 190000
#endif

#if !defined(__cpp_binary_literals)
#define __cpp_binary_literals 190000
#endif

#if !defined(__cpp_decltype_auto)
#define __cpp_decltype_auto 190000
#endif

#if !defined(__cpp_generic_lambdas)
#define __cpp_generic_lambdas 190000
#endif

#if !defined(__cpp_init_captures)
#define __cpp_init_captures 190000
#endif

#if !defined(__cpp_return_type_deduction)
#define __cpp_return_type_deduction 190000
#endif

#if !defined(__cpp_sized_deallocation)
#define __cpp_sized_deallocation 190000
#endif

#if !defined(__cpp_variable_templates)
#define __cpp_variable_templates 190000
#endif

#endif


// VS2010: _MSC_VER=1600
// VS2012: _MSC_VER=1700
// VS2013: _MSC_VER=1800
// VS2015: _MSC_VER=1900
// VS2017: _MSC_VER=1910
#if defined(_MSC_VER) && !defined(__clang__)

#if !defined(__cpp_exceptions) && defined(_CPPUNWIND)
#define __cpp_exceptions 190000
#endif

#if !defined(__cpp_rtti) && defined(_CPPRTTI)
#define __cpp_rtti 190000
#endif


// C++ 11

#if !defined(__cpp_alias_templates) && _MSC_VER >= 1800
#define __cpp_alias_templates 190000
#endif

#if !defined(__cpp_attributes)
#define __cpp_attributes 190000
#endif

#if !defined(__cpp_constexpr) && _MSC_FULL_VER >= 190023506 /* VS2015 */
#define __cpp_constexpr 190000
#endif

#if !defined(__cpp_decltype) && _MSC_VER >= 1600
#define __cpp_decltype 190000
#endif

#if !defined(__cpp_delegating_constructors) && _MSC_VER >= 1800
#define __cpp_delegating_constructors 190000
#endif

#if !defined(__cpp_explicit_conversion) && _MSC_VER >= 1800
#define __cpp_explicit_conversion 190000
#endif

#if !defined(__cpp_inheriting_constructors) && _MSC_VER >= 1900
#define __cpp_inheriting_constructors 190000
#endif

#if !defined(__cpp_initializer_lists) && _MSC_VER >= 1900
#define __cpp_initializer_lists 190000
#endif

#if !defined(__cpp_lambdas) && _MSC_VER >= 1600
#define __cpp_lambdas 190000
#endif

#if !defined(__cpp_nsdmi) && _MSC_VER >= 1900
#define __cpp_nsdmi 190000
#endif

#if !defined(__cpp_range_based_for) && _MSC_VER >= 1700
#define __cpp_range_based_for 190000
#endif

#if !defined(__cpp_raw_strings) && _MSC_VER >= 1800
#define __cpp_raw_strings 190000
#endif

#if !defined(__cpp_ref_qualifiers) && _MSC_VER >= 1900
#define __cpp_ref_qualifiers 190000
#endif

#if !defined(__cpp_rvalue_references) && _MSC_VER >= 1600
#define __cpp_rvalue_references 190000
#endif

#if !defined(__cpp_static_assert) && _MSC_VER >= 1600
#define __cpp_static_assert 190000
#endif

//#if !defined(__cpp_unicode_literals)
//# define __cpp_unicode_literals 190000
//#endif

#if !defined(__cpp_user_defined_literals) && _MSC_VER >= 1900
#define __cpp_user_defined_literals 190000
#endif

#if !defined(__cpp_variadic_templates) && _MSC_VER >= 1800
#define __cpp_variadic_templates 190000
#endif


// C++ 14

//#if !defined(__cpp_aggregate_nsdmi)
//#define __cpp_aggregate_nsdmi 190000
//#endif

#if !defined(__cpp_binary_literals) && _MSC_VER >= 1900
#define __cpp_binary_literals 190000
#endif

#if !defined(__cpp_decltype_auto) && _MSC_VER >= 1900
#define __cpp_decltype_auto 190000
#endif

#if !defined(__cpp_generic_lambdas) && _MSC_VER >= 1900
#define __cpp_generic_lambdas 190000
#endif

#if !defined(__cpp_init_captures) && _MSC_VER >= 1900
#define __cpp_init_captures 190000
#endif

#if !defined(__cpp_return_type_deduction) && _MSC_VER >= 1900
#define __cpp_return_type_deduction 190000
#endif

#if !defined(__cpp_sized_deallocation) && _MSC_VER >= 1900
#define __cpp_sized_deallocation 190000
#endif

#if !defined(__cpp_variable_templates) && _MSC_FULL_VER >= 190023506
#define __cpp_variable_templates 190000
#endif

#endif  // _MSC_VER


// Much to my surprise, GCC's support of these is actually incomplete, so fill in the gaps
#if (defined(__GNUC__) && !defined(__clang__))

#define QUICKCPPLIB_GCC (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)

#if !defined(__cpp_exceptions) && defined(__EXCEPTIONS)
#define __cpp_exceptions 190000
#endif

#if !defined(__cpp_rtti) && defined(__GXX_RTTI)
#define __cpp_rtti 190000
#endif


// C++ 11
#if defined(__GXX_EXPERIMENTAL_CXX0X__)

#if !defined(__cpp_alias_templates) && (QUICKCPPLIB_GCC >= 40700)
#define __cpp_alias_templates 190000
#endif

#if !defined(__cpp_attributes) && (QUICKCPPLIB_GCC >= 40800)
#define __cpp_attributes 190000
#endif

#if !defined(__cpp_constexpr) && (QUICKCPPLIB_GCC >= 40600)
#define __cpp_constexpr 190000
#endif

#if !defined(__cpp_decltype) && (QUICKCPPLIB_GCC >= 40300)
#define __cpp_decltype 190000
#endif

#if !defined(__cpp_delegating_constructors) && (QUICKCPPLIB_GCC >= 40700)
#define __cpp_delegating_constructors 190000
#endif

#if !defined(__cpp_explicit_conversion) && (QUICKCPPLIB_GCC >= 40500)
#define __cpp_explicit_conversion 190000
#endif

#if !defined(__cpp_inheriting_constructors) && (QUICKCPPLIB_GCC >= 40800)
#define __cpp_inheriting_constructors 190000
#endif

#if !defined(__cpp_initializer_lists) && (QUICKCPPLIB_GCC >= 40800)
#define __cpp_initializer_lists 190000
#endif

#if !defined(__cpp_lambdas) && (QUICKCPPLIB_GCC >= 40500)
#define __cpp_lambdas 190000
#endif

#if !defined(__cpp_nsdmi) && (QUICKCPPLIB_GCC >= 40700)
#define __cpp_nsdmi 190000
#endif

#if !defined(__cpp_range_based_for) && (QUICKCPPLIB_GCC >= 40600)
#define __cpp_range_based_for 190000
#endif

#if !defined(__cpp_raw_strings) && (QUICKCPPLIB_GCC >= 40500)
#define __cpp_raw_strings 190000
#endif

#if !defined(__cpp_ref_qualifiers) && (QUICKCPPLIB_GCC >= 40801)
#define __cpp_ref_qualifiers 190000
#endif

// __cpp_rvalue_reference deviation
#if !defined(__cpp_rvalue_references) && defined(__cpp_rvalue_reference)
#define __cpp_rvalue_references __cpp_rvalue_reference
#endif

#if !defined(__cpp_static_assert) && (QUICKCPPLIB_GCC >= 40300)
#define __cpp_static_assert 190000
#endif

#if !defined(__cpp_unicode_characters) && (QUICKCPPLIB_GCC >= 40500)
#define __cpp_unicode_characters 190000
#endif

#if !defined(__cpp_unicode_literals) && (QUICKCPPLIB_GCC >= 40500)
#define __cpp_unicode_literals 190000
#endif

#if !defined(__cpp_user_defined_literals) && (QUICKCPPLIB_GCC >= 40700)
#define __cpp_user_defined_literals 190000
#endif

#if !defined(__cpp_variadic_templates) && (QUICKCPPLIB_GCC >= 40400)
#define __cpp_variadic_templates 190000
#endif


// C++ 14
// Every C++ 14 supporting GCC does the right thing here

#endif  // __GXX_EXPERIMENTAL_CXX0X__

#endif  // GCC


// clang deviates in some places from the present SG-10 draft, plus older
// clangs are quite incomplete
#if defined(__clang__)

#define QUICKCPPLIB_CLANG (__clang_major__ * 10000 + __clang_minor__ * 100 + __clang_patchlevel__)

#if !defined(__cpp_exceptions) && (defined(__EXCEPTIONS) || defined(_CPPUNWIND))
#define __cpp_exceptions 190000
#endif

#if !defined(__cpp_rtti) && (defined(__GXX_RTTI) || defined(_CPPRTTI))
#define __cpp_rtti 190000
#endif


// C++ 11
#if defined(__GXX_EXPERIMENTAL_CXX0X__)

#if !defined(__cpp_alias_templates) && (QUICKCPPLIB_CLANG >= 30000)
#define __cpp_alias_templates 190000
#endif

#if !defined(__cpp_attributes) && (QUICKCPPLIB_CLANG >= 30300)
#define __cpp_attributes 190000
#endif

#if !defined(__cpp_constexpr) && (QUICKCPPLIB_CLANG >= 30100)
#define __cpp_constexpr 190000
#endif

#if !defined(__cpp_decltype) && (QUICKCPPLIB_CLANG >= 20900)
#define __cpp_decltype 190000
#endif

#if !defined(__cpp_delegating_constructors) && (QUICKCPPLIB_CLANG >= 30000)
#define __cpp_delegating_constructors 190000
#endif

#if !defined(__cpp_explicit_conversion) && (QUICKCPPLIB_CLANG >= 30000)
#define __cpp_explicit_conversion 190000
#endif

#if !defined(__cpp_inheriting_constructors) && (QUICKCPPLIB_CLANG >= 30300)
#define __cpp_inheriting_constructors 190000
#endif

#if !defined(__cpp_initializer_lists) && (QUICKCPPLIB_CLANG >= 30100)
#define __cpp_initializer_lists 190000
#endif

#if !defined(__cpp_lambdas) && (QUICKCPPLIB_CLANG >= 30100)
#define __cpp_lambdas 190000
#endif

#if !defined(__cpp_nsdmi) && (QUICKCPPLIB_CLANG >= 30000)
#define __cpp_nsdmi 190000
#endif

#if !defined(__cpp_range_based_for) && (QUICKCPPLIB_CLANG >= 30000)
#define __cpp_range_based_for 190000
#endif

// __cpp_raw_string_literals deviation
#if !defined(__cpp_raw_strings) && defined(__cpp_raw_string_literals)
#define __cpp_raw_strings __cpp_raw_string_literals
#endif
#if !defined(__cpp_raw_strings) && (QUICKCPPLIB_CLANG >= 30000)
#define __cpp_raw_strings 190000
#endif

#if !defined(__cpp_ref_qualifiers) && (QUICKCPPLIB_CLANG >= 20900)
#define __cpp_ref_qualifiers 190000
#endif

// __cpp_rvalue_reference deviation
#if !defined(__cpp_rvalue_references) && defined(__cpp_rvalue_reference)
#define __cpp_rvalue_references __cpp_rvalue_reference
#endif
#if !defined(__cpp_rvalue_references) && (QUICKCPPLIB_CLANG >= 20900)
#define __cpp_rvalue_references 190000
#endif

#if !defined(__cpp_static_assert) && (QUICKCPPLIB_CLANG >= 20900)
#define __cpp_static_assert 190000
#endif

#if !defined(__cpp_unicode_characters) && (QUICKCPPLIB_CLANG >= 30000)
#define __cpp_unicode_characters 190000
#endif

#if !defined(__cpp_unicode_literals) && (QUICKCPPLIB_CLANG >= 30000)
#define __cpp_unicode_literals 190000
#endif

// __cpp_user_literals deviation
#if !defined(__cpp_user_defined_literals) && defined(__cpp_user_literals)
#define __cpp_user_defined_literals __cpp_user_literals
#endif
#if !defined(__cpp_user_defined_literals) && (QUICKCPPLIB_CLANG >= 30100)
#define __cpp_user_defined_literals 190000
#endif

#if !defined(__cpp_variadic_templates) && (QUICKCPPLIB_CLANG >= 20900)
#define __cpp_variadic_templates 190000
#endif


// C++ 14
// Every C++ 14 supporting clang does the right thing here

#endif  // __GXX_EXPERIMENTAL_CXX0X__

#endif  // clang

#endif
#ifndef QUICKCPPLIB_DISABLE_ABI_PERMUTATION
// Note the second line of this file must ALWAYS be the git SHA, third line ALWAYS the git SHA update time
#define QUICKCPPLIB_PREVIOUS_COMMIT_REF    01e18d3e6549400646f41b79de318994eac95f25
#define QUICKCPPLIB_PREVIOUS_COMMIT_DATE   "2019-02-11 10:00:33 +00:00"
#define QUICKCPPLIB_PREVIOUS_COMMIT_UNIQUE 01e18d3e
#endif

#define QUICKCPPLIB_VERSION_GLUE2(a, b) a##b
#define QUICKCPPLIB_VERSION_GLUE(a, b) QUICKCPPLIB_VERSION_GLUE2(a, b)

// clang-format off












#if defined(QUICKCPPLIB_DISABLE_ABI_PERMUTATION)
#define QUICKCPPLIB_NAMESPACE quickcpplib
#define QUICKCPPLIB_NAMESPACE_BEGIN namespace quickcpplib {
#define QUICKCPPLIB_NAMESPACE_END }
#else
#define QUICKCPPLIB_NAMESPACE quickcpplib::QUICKCPPLIB_VERSION_GLUE(_, QUICKCPPLIB_PREVIOUS_COMMIT_UNIQUE)
#define QUICKCPPLIB_NAMESPACE_BEGIN namespace quickcpplib { namespace QUICKCPPLIB_VERSION_GLUE(_, QUICKCPPLIB_PREVIOUS_COMMIT_UNIQUE) {
#define QUICKCPPLIB_NAMESPACE_END } }
#endif
// clang-format on

#ifdef _MSC_VER
#define QUICKCPPLIB_BIND_MESSAGE_PRAGMA2(x) __pragma(message(x))
#define QUICKCPPLIB_BIND_MESSAGE_PRAGMA(x) QUICKCPPLIB_BIND_MESSAGE_PRAGMA2(x)
#define QUICKCPPLIB_BIND_MESSAGE_PREFIX(type) __FILE__ "(" QUICKCPPLIB_BIND_STRINGIZE2(__LINE__) "): " type ": "
#define QUICKCPPLIB_BIND_MESSAGE_(type, prefix, msg) QUICKCPPLIB_BIND_MESSAGE_PRAGMA(prefix msg)
#else
#define QUICKCPPLIB_BIND_MESSAGE_PRAGMA2(x) _Pragma(#x)
#define QUICKCPPLIB_BIND_MESSAGE_PRAGMA(type, x) QUICKCPPLIB_BIND_MESSAGE_PRAGMA2(type x)
#define QUICKCPPLIB_BIND_MESSAGE_(type, prefix, msg) QUICKCPPLIB_BIND_MESSAGE_PRAGMA(type, msg)
#endif
//! Have the compiler output a message
#define QUICKCPPLIB_MESSAGE(msg) QUICKCPPLIB_BIND_MESSAGE_(message, QUICKCPPLIB_BIND_MESSAGE_PREFIX("message"), msg)
//! Have the compiler output a note
#define QUICKCPPLIB_NOTE(msg) QUICKCPPLIB_BIND_MESSAGE_(message, QUICKCPPLIB_BIND_MESSAGE_PREFIX("note"), msg)
//! Have the compiler output a warning
#define QUICKCPPLIB_WARNING(msg) QUICKCPPLIB_BIND_MESSAGE_(GCC warning, QUICKCPPLIB_BIND_MESSAGE_PREFIX("warning"), msg)
//! Have the compiler output an error
#define QUICKCPPLIB_ERROR(msg) QUICKCPPLIB_BIND_MESSAGE_(GCC error, QUICKCPPLIB_BIND_MESSAGE_PREFIX("error"), msg)
















#define QUICKCPPLIB_ANNOTATE_RWLOCK_CREATE(p)
#define QUICKCPPLIB_ANNOTATE_RWLOCK_DESTROY(p)
#define QUICKCPPLIB_ANNOTATE_RWLOCK_ACQUIRED(p, s)
#define QUICKCPPLIB_ANNOTATE_RWLOCK_RELEASED(p, s)
#define QUICKCPPLIB_ANNOTATE_IGNORE_READS_BEGIN()
#define QUICKCPPLIB_ANNOTATE_IGNORE_READS_END()
#define QUICKCPPLIB_ANNOTATE_IGNORE_WRITES_BEGIN()
#define QUICKCPPLIB_ANNOTATE_IGNORE_WRITES_END()
#define QUICKCPPLIB_DRD_IGNORE_VAR(x)
#define QUICKCPPLIB_DRD_STOP_IGNORING_VAR(x)
#define QUICKCPPLIB_RUNNING_ON_VALGRIND (0)


#ifndef QUICKCPPLIB_IN_THREAD_SANITIZER
#if defined(__has_feature)
#if __has_feature(thread_sanitizer)
#define QUICKCPPLIB_IN_THREAD_SANITIZER 1
#endif
#elif defined(__SANITIZE_ADDRESS__)
#define QUICKCPPLIB_IN_THREAD_SANITIZER 1
#endif
#endif
#ifndef QUICKCPPLIB_IN_THREAD_SANITIZER
#define QUICKCPPLIB_IN_THREAD_SANITIZER 0
#endif

#if QUICKCPPLIB_IN_THREAD_SANITIZER
#define QUICKCPPLIB_DISABLE_THREAD_SANITIZE __attribute__((no_sanitize_thread))
#else
#define QUICKCPPLIB_DISABLE_THREAD_SANITIZE
#endif

#ifndef QUICKCPPLIB_SMT_PAUSE
#if !defined(__clang__) && defined(_MSC_VER) && _MSC_VER >= 1310 && (defined(_M_IX86) || defined(_M_X64))
extern "C" void _mm_pause();
#pragma intrinsic(_mm_pause)
#define QUICKCPPLIB_SMT_PAUSE _mm_pause();
#elif !defined(__c2__) && defined(__GNUC__) && (defined(__i386__) || defined(__x86_64__))
#define QUICKCPPLIB_SMT_PAUSE __asm__ __volatile__("rep; nop" : : : "memory");
#endif
#endif

#ifndef QUICKCPPLIB_FORCEINLINE
#if defined(_MSC_VER)
#define QUICKCPPLIB_FORCEINLINE __forceinline
#elif defined(__GNUC__)
#define QUICKCPPLIB_FORCEINLINE __attribute__((always_inline))
#else
#define QUICKCPPLIB_FORCEINLINE
#endif
#endif

#ifndef QUICKCPPLIB_NOINLINE
#if defined(_MSC_VER)
#define QUICKCPPLIB_NOINLINE __declspec(noinline)
#elif defined(__GNUC__)
#define QUICKCPPLIB_NOINLINE __attribute__((noinline))
#else
#define QUICKCPPLIB_NOINLINE
#endif
#endif

#if !defined(QUICKCPPLIB_NORETURN)
#ifdef __cpp_attributes
#define QUICKCPPLIB_NORETURN [[noreturn]]
#elif defined(_MSC_VER)
#define QUICKCPPLIB_NORETURN __declspec(noreturn)
#elif defined(__GNUC__)
#define QUICKCPPLIB_NORETURN __attribute__((__noreturn__))
#else
#define QUICKCPPLIB_NORETURN
#endif
#endif

#ifndef QUICKCPPLIB_NODISCARD
#if 0 || (_HAS_CXX17 && _MSC_VER >= 1911 /* VS2017.3 */)
#define QUICKCPPLIB_NODISCARD [[nodiscard]]
#endif
#endif
#ifndef QUICKCPPLIB_NODISCARD
#ifdef __has_cpp_attribute
#if __has_cpp_attribute(nodiscard)
#define QUICKCPPLIB_NODISCARD [[nodiscard]]
#endif
#elif defined(__clang__)
#define QUICKCPPLIB_NODISCARD __attribute__((warn_unused_result))
#elif defined(_MSC_VER)
// _Must_inspect_result_ expands into this
#define QUICKCPPLIB_NODISCARD                                                                                                                                                                                                                                                                                                    __declspec("SAL_name"                                                                                                                                                                                                                                                                                                                     "("                                                                                                                                                                                                                                                                                                                            "\"_Must_inspect_result_\""                                                                                                                                                                                                                                                                                                    ","                                                                                                                                                                                                                                                                                                                            "\"\""                                                                                                                                                                                                                                                                                                                         ","                                                                                                                                                                                                                                                                                                                            "\"2\""                                                                                                                                                                                                                                                                                                                        ")") __declspec("SAL_begin") __declspec("SAL_post") __declspec("SAL_mustInspect") __declspec("SAL_post") __declspec("SAL_checkReturn") __declspec("SAL_end")








#endif
#endif
#ifndef QUICKCPPLIB_NODISCARD
#define QUICKCPPLIB_NODISCARD
#endif

#ifndef QUICKCPPLIB_SYMBOL_VISIBLE
#if defined(_MSC_VER)
#define QUICKCPPLIB_SYMBOL_VISIBLE
#elif defined(__GNUC__)
#define QUICKCPPLIB_SYMBOL_VISIBLE __attribute__((visibility("default")))
#else
#define QUICKCPPLIB_SYMBOL_VISIBLE
#endif
#endif

#ifndef QUICKCPPLIB_SYMBOL_EXPORT
#if defined(_MSC_VER)
#define QUICKCPPLIB_SYMBOL_EXPORT __declspec(dllexport)
#elif defined(__GNUC__)
#define QUICKCPPLIB_SYMBOL_EXPORT __attribute__((visibility("default")))
#else
#define QUICKCPPLIB_SYMBOL_EXPORT
#endif
#endif

#ifndef QUICKCPPLIB_SYMBOL_IMPORT
#if defined(_MSC_VER)
#define QUICKCPPLIB_SYMBOL_IMPORT __declspec(dllimport)
#elif defined(__GNUC__)
#define QUICKCPPLIB_SYMBOL_IMPORT
#else
#define QUICKCPPLIB_SYMBOL_IMPORT
#endif
#endif

#ifndef QUICKCPPLIB_THREAD_LOCAL
#if _MSC_VER >= 1800
#define QUICKCPPLIB_THREAD_LOCAL_IS_CXX11 1
#elif __cplusplus >= 201103
#if __GNUC__ >= 5 && !defined(__clang__)
#define QUICKCPPLIB_THREAD_LOCAL_IS_CXX11 1
#elif defined(__has_feature)
#if __has_feature(cxx_thread_local)
#define QUICKCPPLIB_THREAD_LOCAL_IS_CXX11 1
#endif
#endif
#endif
#ifdef QUICKCPPLIB_THREAD_LOCAL_IS_CXX11
#define QUICKCPPLIB_THREAD_LOCAL thread_local
#endif
#ifndef QUICKCPPLIB_THREAD_LOCAL
#if defined(_MSC_VER)
#define QUICKCPPLIB_THREAD_LOCAL __declspec(thread)
#elif defined(__GNUC__)
#define QUICKCPPLIB_THREAD_LOCAL __thread
#else
#error Unknown compiler, cannot set QUICKCPPLIB_THREAD_LOCAL
#endif
#endif
#endif
/* MSVC capable preprocessor macro overloading
(C) 2014-2017 Niall Douglas <http://www.nedproductions.biz/> (3 commits)
File Created: Aug 2014


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

#ifndef QUICKCPPLIB_PREPROCESSOR_MACRO_OVERLOAD_H
#define QUICKCPPLIB_PREPROCESSOR_MACRO_OVERLOAD_H

#define QUICKCPPLIB_GLUE(x, y) x y

#define QUICKCPPLIB_RETURN_ARG_COUNT(_1_, _2_, _3_, _4_, _5_, _6_, _7_, _8_, count, ...) count
#define QUICKCPPLIB_EXPAND_ARGS(args) QUICKCPPLIB_RETURN_ARG_COUNT args
#define QUICKCPPLIB_COUNT_ARGS_MAX8(...) QUICKCPPLIB_EXPAND_ARGS((__VA_ARGS__, 8, 7, 6, 5, 4, 3, 2, 1, 0))

#define QUICKCPPLIB_OVERLOAD_MACRO2(name, count) name##count
#define QUICKCPPLIB_OVERLOAD_MACRO1(name, count) QUICKCPPLIB_OVERLOAD_MACRO2(name, count)
#define QUICKCPPLIB_OVERLOAD_MACRO(name, count) QUICKCPPLIB_OVERLOAD_MACRO1(name, count)

#define QUICKCPPLIB_CALL_OVERLOAD(name, ...) QUICKCPPLIB_GLUE(QUICKCPPLIB_OVERLOAD_MACRO(name, QUICKCPPLIB_COUNT_ARGS_MAX8(__VA_ARGS__)), (__VA_ARGS__))

#define QUICKCPPLIB_GLUE_(x, y) x y

#define QUICKCPPLIB_RETURN_ARG_COUNT_(_1_, _2_, _3_, _4_, _5_, _6_, _7_, _8_, count, ...) count
#define QUICKCPPLIB_EXPAND_ARGS_(args) QUICKCPPLIB_RETURN_ARG_COUNT_ args
#define QUICKCPPLIB_COUNT_ARGS_MAX8_(...) QUICKCPPLIB_EXPAND_ARGS_((__VA_ARGS__, 8, 7, 6, 5, 4, 3, 2, 1, 0))

#define QUICKCPPLIB_OVERLOAD_MACRO2_(name, count) name##count
#define QUICKCPPLIB_OVERLOAD_MACRO1_(name, count) QUICKCPPLIB_OVERLOAD_MACRO2_(name, count)
#define QUICKCPPLIB_OVERLOAD_MACRO_(name, count) QUICKCPPLIB_OVERLOAD_MACRO1_(name, count)

#define QUICKCPPLIB_CALL_OVERLOAD_(name, ...) QUICKCPPLIB_GLUE_(QUICKCPPLIB_OVERLOAD_MACRO_(name, QUICKCPPLIB_COUNT_ARGS_MAX8_(__VA_ARGS__)), (__VA_ARGS__))

#endif
#ifdef __cpp_concepts
#define QUICKCPPLIB_TREQUIRES_EXPAND8(a, b, c, d, e, f, g, h) a &&QUICKCPPLIB_TREQUIRES_EXPAND7(b, c, d, e, f, g, h)
#define QUICKCPPLIB_TREQUIRES_EXPAND7(a, b, c, d, e, f, g) a &&QUICKCPPLIB_TREQUIRES_EXPAND6(b, c, d, e, f, g)
#define QUICKCPPLIB_TREQUIRES_EXPAND6(a, b, c, d, e, f) a &&QUICKCPPLIB_TREQUIRES_EXPAND5(b, c, d, e, f)
#define QUICKCPPLIB_TREQUIRES_EXPAND5(a, b, c, d, e) a &&QUICKCPPLIB_TREQUIRES_EXPAND4(b, c, d, e)
#define QUICKCPPLIB_TREQUIRES_EXPAND4(a, b, c, d) a &&QUICKCPPLIB_TREQUIRES_EXPAND3(b, c, d)
#define QUICKCPPLIB_TREQUIRES_EXPAND3(a, b, c) a &&QUICKCPPLIB_TREQUIRES_EXPAND2(b, c)
#define QUICKCPPLIB_TREQUIRES_EXPAND2(a, b) a &&QUICKCPPLIB_TREQUIRES_EXPAND1(b)
#define QUICKCPPLIB_TREQUIRES_EXPAND1(a) a

//! Expands into a && b && c && ...
#define QUICKCPPLIB_TREQUIRES(...) requires QUICKCPPLIB_CALL_OVERLOAD(QUICKCPPLIB_TREQUIRES_EXPAND, __VA_ARGS__)

#define QUICKCPPLIB_TEMPLATE(...) template <__VA_ARGS__>
#define QUICKCPPLIB_TEXPR(...)                                                                                                                                                                                                                                                                                                   requires { (__VA_ARGS__); }

#define QUICKCPPLIB_TPRED(...) (__VA_ARGS__)
#define QUICKCPPLIB_REQUIRES(...) requires __VA_ARGS__
#else
#define QUICKCPPLIB_TEMPLATE(...) template <__VA_ARGS__
#define QUICKCPPLIB_TREQUIRES(...) , __VA_ARGS__ >
#define QUICKCPPLIB_TEXPR(...) typename = decltype(__VA_ARGS__)
#define QUICKCPPLIB_TPRED(...) typename = std::enable_if_t<__VA_ARGS__>
#define QUICKCPPLIB_REQUIRES(...)
#endif


#endif
#ifndef __cpp_variadic_templates
#error Outcome needs variadic template support in the compiler
#endif
#if __cpp_constexpr < 201304 && _MSC_FULL_VER < 191100000
#error Outcome needs constexpr (C++ 14) support in the compiler
#endif
#ifndef __cpp_variable_templates
#error Outcome needs variable template support in the compiler
#endif
#if !defined(__clang__) && defined(__GNUC__) && __GNUC__ < 6
#error Due to a bug in nested template variables parsing, Outcome does not work on GCCs earlier than v6.
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
/* Convenience macros for importing local namespace binds
(C) 2014-2017 Niall Douglas <http://www.nedproductions.biz/> (9 commits)
File Created: Aug 2014


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

#ifndef QUICKCPPLIB_BIND_IMPORT_HPP
#define QUICKCPPLIB_BIND_IMPORT_HPP

/* 2014-10-9 ned: I lost today figuring out the below. I really hate the C preprocessor now.
 *
 * Anyway, infinity = 8. It's easy to expand below if needed.
 */


#define QUICKCPPLIB_BIND_STRINGIZE(a) #a
#define QUICKCPPLIB_BIND_STRINGIZE2(a) QUICKCPPLIB_BIND_STRINGIZE(a)
#define QUICKCPPLIB_BIND_NAMESPACE_VERSION8(a, b, c, d, e, f, g, h) a##_##b##_##c##_##d##_##e##_##f##_##g##_##h
#define QUICKCPPLIB_BIND_NAMESPACE_VERSION7(a, b, c, d, e, f, g) a##_##b##_##c##_##d##_##e##_##f##_##g
#define QUICKCPPLIB_BIND_NAMESPACE_VERSION6(a, b, c, d, e, f) a##_##b##_##c##_##d##_##e##_##f
#define QUICKCPPLIB_BIND_NAMESPACE_VERSION5(a, b, c, d, e) a##_##b##_##c##_##d##_##e
#define QUICKCPPLIB_BIND_NAMESPACE_VERSION4(a, b, c, d) a##_##b##_##c##_##d
#define QUICKCPPLIB_BIND_NAMESPACE_VERSION3(a, b, c) a##_##b##_##c
#define QUICKCPPLIB_BIND_NAMESPACE_VERSION2(a, b) a##_##b
#define QUICKCPPLIB_BIND_NAMESPACE_VERSION1(a) a
//! Concatenates each parameter with _
#define QUICKCPPLIB_BIND_NAMESPACE_VERSION(...) QUICKCPPLIB_CALL_OVERLOAD(QUICKCPPLIB_BIND_NAMESPACE_VERSION, __VA_ARGS__)

#define QUICKCPPLIB_BIND_NAMESPACE_SELECT_2(name, modifier) name
#define QUICKCPPLIB_BIND_NAMESPACE_SELECT2(name, modifier) ::name
#define QUICKCPPLIB_BIND_NAMESPACE_SELECT_1(name) name
#define QUICKCPPLIB_BIND_NAMESPACE_SELECT1(name) ::name
#define QUICKCPPLIB_BIND_NAMESPACE_SELECT_(...) QUICKCPPLIB_CALL_OVERLOAD_(QUICKCPPLIB_BIND_NAMESPACE_SELECT_, __VA_ARGS__)
#define QUICKCPPLIB_BIND_NAMESPACE_SELECT(...) QUICKCPPLIB_CALL_OVERLOAD_(QUICKCPPLIB_BIND_NAMESPACE_SELECT, __VA_ARGS__)
#define QUICKCPPLIB_BIND_NAMESPACE_EXPAND8(a, b, c, d, e, f, g, h)                                                                                                                                                                                                                                                               QUICKCPPLIB_BIND_NAMESPACE_SELECT_ a QUICKCPPLIB_BIND_NAMESPACE_SELECT b QUICKCPPLIB_BIND_NAMESPACE_SELECT c QUICKCPPLIB_BIND_NAMESPACE_SELECT d QUICKCPPLIB_BIND_NAMESPACE_SELECT e QUICKCPPLIB_BIND_NAMESPACE_SELECT f QUICKCPPLIB_BIND_NAMESPACE_SELECT g QUICKCPPLIB_BIND_NAMESPACE_SELECT h

#define QUICKCPPLIB_BIND_NAMESPACE_EXPAND7(a, b, c, d, e, f, g) QUICKCPPLIB_BIND_NAMESPACE_SELECT_ a QUICKCPPLIB_BIND_NAMESPACE_SELECT b QUICKCPPLIB_BIND_NAMESPACE_SELECT c QUICKCPPLIB_BIND_NAMESPACE_SELECT d QUICKCPPLIB_BIND_NAMESPACE_SELECT e QUICKCPPLIB_BIND_NAMESPACE_SELECT f QUICKCPPLIB_BIND_NAMESPACE_SELECT g
#define QUICKCPPLIB_BIND_NAMESPACE_EXPAND6(a, b, c, d, e, f) QUICKCPPLIB_BIND_NAMESPACE_SELECT_ a QUICKCPPLIB_BIND_NAMESPACE_SELECT b QUICKCPPLIB_BIND_NAMESPACE_SELECT c QUICKCPPLIB_BIND_NAMESPACE_SELECT d QUICKCPPLIB_BIND_NAMESPACE_SELECT e QUICKCPPLIB_BIND_NAMESPACE_SELECT f
#define QUICKCPPLIB_BIND_NAMESPACE_EXPAND5(a, b, c, d, e) QUICKCPPLIB_BIND_NAMESPACE_SELECT_ a QUICKCPPLIB_BIND_NAMESPACE_SELECT b QUICKCPPLIB_BIND_NAMESPACE_SELECT c QUICKCPPLIB_BIND_NAMESPACE_SELECT d QUICKCPPLIB_BIND_NAMESPACE_SELECT e
#define QUICKCPPLIB_BIND_NAMESPACE_EXPAND4(a, b, c, d) QUICKCPPLIB_BIND_NAMESPACE_SELECT_ a QUICKCPPLIB_BIND_NAMESPACE_SELECT b QUICKCPPLIB_BIND_NAMESPACE_SELECT c QUICKCPPLIB_BIND_NAMESPACE_SELECT d
#define QUICKCPPLIB_BIND_NAMESPACE_EXPAND3(a, b, c) QUICKCPPLIB_BIND_NAMESPACE_SELECT_ a QUICKCPPLIB_BIND_NAMESPACE_SELECT b QUICKCPPLIB_BIND_NAMESPACE_SELECT c
#define QUICKCPPLIB_BIND_NAMESPACE_EXPAND2(a, b) QUICKCPPLIB_BIND_NAMESPACE_SELECT_ a QUICKCPPLIB_BIND_NAMESPACE_SELECT b
#define QUICKCPPLIB_BIND_NAMESPACE_EXPAND1(a) QUICKCPPLIB_BIND_NAMESPACE_SELECT_ a
//! Expands into a::b::c:: ...
#define QUICKCPPLIB_BIND_NAMESPACE(...) QUICKCPPLIB_CALL_OVERLOAD(QUICKCPPLIB_BIND_NAMESPACE_EXPAND, __VA_ARGS__)

#define QUICKCPPLIB_BIND_NAMESPACE_BEGIN_NAMESPACE_SELECT2(name, modifier)                                                                                                                                                                                                                                                       modifier namespace name                                                                                                                                                                                                                                                                                                        {


#define QUICKCPPLIB_BIND_NAMESPACE_BEGIN_NAMESPACE_SELECT1(name)                                                                                                                                                                                                                                                                 namespace name                                                                                                                                                                                                                                                                                                                 {


#define QUICKCPPLIB_BIND_NAMESPACE_BEGIN_NAMESPACE_SELECT(...) QUICKCPPLIB_CALL_OVERLOAD_(QUICKCPPLIB_BIND_NAMESPACE_BEGIN_NAMESPACE_SELECT, __VA_ARGS__)
#define QUICKCPPLIB_BIND_NAMESPACE_BEGIN_EXPAND8(a, b, c, d, e, f, g, h) QUICKCPPLIB_BIND_NAMESPACE_BEGIN_NAMESPACE_SELECT a QUICKCPPLIB_BIND_NAMESPACE_BEGIN_EXPAND7(b, c, d, e, f, g, h)
#define QUICKCPPLIB_BIND_NAMESPACE_BEGIN_EXPAND7(a, b, c, d, e, f, g) QUICKCPPLIB_BIND_NAMESPACE_BEGIN_NAMESPACE_SELECT a QUICKCPPLIB_BIND_NAMESPACE_BEGIN_EXPAND6(b, c, d, e, f, g)
#define QUICKCPPLIB_BIND_NAMESPACE_BEGIN_EXPAND6(a, b, c, d, e, f) QUICKCPPLIB_BIND_NAMESPACE_BEGIN_NAMESPACE_SELECT a QUICKCPPLIB_BIND_NAMESPACE_BEGIN_EXPAND5(b, c, d, e, f)
#define QUICKCPPLIB_BIND_NAMESPACE_BEGIN_EXPAND5(a, b, c, d, e) QUICKCPPLIB_BIND_NAMESPACE_BEGIN_NAMESPACE_SELECT a QUICKCPPLIB_BIND_NAMESPACE_BEGIN_EXPAND4(b, c, d, e)
#define QUICKCPPLIB_BIND_NAMESPACE_BEGIN_EXPAND4(a, b, c, d) QUICKCPPLIB_BIND_NAMESPACE_BEGIN_NAMESPACE_SELECT a QUICKCPPLIB_BIND_NAMESPACE_BEGIN_EXPAND3(b, c, d)
#define QUICKCPPLIB_BIND_NAMESPACE_BEGIN_EXPAND3(a, b, c) QUICKCPPLIB_BIND_NAMESPACE_BEGIN_NAMESPACE_SELECT a QUICKCPPLIB_BIND_NAMESPACE_BEGIN_EXPAND2(b, c)
#define QUICKCPPLIB_BIND_NAMESPACE_BEGIN_EXPAND2(a, b) QUICKCPPLIB_BIND_NAMESPACE_BEGIN_NAMESPACE_SELECT a QUICKCPPLIB_BIND_NAMESPACE_BEGIN_EXPAND1(b)
#define QUICKCPPLIB_BIND_NAMESPACE_BEGIN_EXPAND1(a) QUICKCPPLIB_BIND_NAMESPACE_BEGIN_NAMESPACE_SELECT a

//! Expands into namespace a { namespace b { namespace c ...
#define QUICKCPPLIB_BIND_NAMESPACE_BEGIN(...) QUICKCPPLIB_CALL_OVERLOAD(QUICKCPPLIB_BIND_NAMESPACE_BEGIN_EXPAND, __VA_ARGS__)

#define QUICKCPPLIB_BIND_NAMESPACE_EXPORT_BEGIN_NAMESPACE_SELECT2(name, modifier)                                                                                                                                                                                                                                                modifier namespace name                                                                                                                                                                                                                                                                                                        {


#define QUICKCPPLIB_BIND_NAMESPACE_EXPORT_BEGIN_NAMESPACE_SELECT1(name)                                                                                                                                                                                                                                                          export namespace name                                                                                                                                                                                                                                                                                                          {


#define QUICKCPPLIB_BIND_NAMESPACE_EXPORT_BEGIN_NAMESPACE_SELECT(...) QUICKCPPLIB_CALL_OVERLOAD_(QUICKCPPLIB_BIND_NAMESPACE_EXPORT_BEGIN_NAMESPACE_SELECT, __VA_ARGS__)
#define QUICKCPPLIB_BIND_NAMESPACE_EXPORT_BEGIN_EXPAND8(a, b, c, d, e, f, g, h) QUICKCPPLIB_BIND_NAMESPACE_EXPORT_BEGIN_NAMESPACE_SELECT a QUICKCPPLIB_BIND_NAMESPACE_EXPORT_BEGIN_EXPAND7(b, c, d, e, f, g, h)
#define QUICKCPPLIB_BIND_NAMESPACE_EXPORT_BEGIN_EXPAND7(a, b, c, d, e, f, g) QUICKCPPLIB_BIND_NAMESPACE_EXPORT_BEGIN_NAMESPACE_SELECT a QUICKCPPLIB_BIND_NAMESPACE_EXPORT_BEGIN_EXPAND6(b, c, d, e, f, g)
#define QUICKCPPLIB_BIND_NAMESPACE_EXPORT_BEGIN_EXPAND6(a, b, c, d, e, f) QUICKCPPLIB_BIND_NAMESPACE_EXPORT_BEGIN_NAMESPACE_SELECT a QUICKCPPLIB_BIND_NAMESPACE_EXPORT_BEGIN_EXPAND5(b, c, d, e, f)
#define QUICKCPPLIB_BIND_NAMESPACE_EXPORT_BEGIN_EXPAND5(a, b, c, d, e) QUICKCPPLIB_BIND_NAMESPACE_EXPORT_BEGIN_NAMESPACE_SELECT a QUICKCPPLIB_BIND_NAMESPACE_EXPORT_BEGIN_EXPAND4(b, c, d, e)
#define QUICKCPPLIB_BIND_NAMESPACE_EXPORT_BEGIN_EXPAND4(a, b, c, d) QUICKCPPLIB_BIND_NAMESPACE_EXPORT_BEGIN_NAMESPACE_SELECT a QUICKCPPLIB_BIND_NAMESPACE_EXPORT_BEGIN_EXPAND3(b, c, d)
#define QUICKCPPLIB_BIND_NAMESPACE_EXPORT_BEGIN_EXPAND3(a, b, c) QUICKCPPLIB_BIND_NAMESPACE_EXPORT_BEGIN_NAMESPACE_SELECT a QUICKCPPLIB_BIND_NAMESPACE_EXPORT_BEGIN_EXPAND2(b, c)
#define QUICKCPPLIB_BIND_NAMESPACE_EXPORT_BEGIN_EXPAND2(a, b) QUICKCPPLIB_BIND_NAMESPACE_EXPORT_BEGIN_NAMESPACE_SELECT a QUICKCPPLIB_BIND_NAMESPACE_EXPORT_BEGIN_EXPAND1(b)
#define QUICKCPPLIB_BIND_NAMESPACE_EXPORT_BEGIN_EXPAND1(a) QUICKCPPLIB_BIND_NAMESPACE_EXPORT_BEGIN_NAMESPACE_SELECT a

//! Expands into export namespace a { namespace b { namespace c ...
#define QUICKCPPLIB_BIND_NAMESPACE_EXPORT_BEGIN(...) QUICKCPPLIB_CALL_OVERLOAD(QUICKCPPLIB_BIND_NAMESPACE_EXPORT_BEGIN_EXPAND, __VA_ARGS__)

#define QUICKCPPLIB_BIND_NAMESPACE_END_NAMESPACE_SELECT2(name, modifier) }
#define QUICKCPPLIB_BIND_NAMESPACE_END_NAMESPACE_SELECT1(name) }
#define QUICKCPPLIB_BIND_NAMESPACE_END_NAMESPACE_SELECT(...) QUICKCPPLIB_CALL_OVERLOAD_(QUICKCPPLIB_BIND_NAMESPACE_END_NAMESPACE_SELECT, __VA_ARGS__)
#define QUICKCPPLIB_BIND_NAMESPACE_END_EXPAND8(a, b, c, d, e, f, g, h) QUICKCPPLIB_BIND_NAMESPACE_END_NAMESPACE_SELECT a QUICKCPPLIB_BIND_NAMESPACE_END_EXPAND7(b, c, d, e, f, g, h)
#define QUICKCPPLIB_BIND_NAMESPACE_END_EXPAND7(a, b, c, d, e, f, g) QUICKCPPLIB_BIND_NAMESPACE_END_NAMESPACE_SELECT a QUICKCPPLIB_BIND_NAMESPACE_END_EXPAND6(b, c, d, e, f, g)
#define QUICKCPPLIB_BIND_NAMESPACE_END_EXPAND6(a, b, c, d, e, f) QUICKCPPLIB_BIND_NAMESPACE_END_NAMESPACE_SELECT a QUICKCPPLIB_BIND_NAMESPACE_END_EXPAND5(b, c, d, e, f)
#define QUICKCPPLIB_BIND_NAMESPACE_END_EXPAND5(a, b, c, d, e) QUICKCPPLIB_BIND_NAMESPACE_END_NAMESPACE_SELECT a QUICKCPPLIB_BIND_NAMESPACE_END_EXPAND4(b, c, d, e)
#define QUICKCPPLIB_BIND_NAMESPACE_END_EXPAND4(a, b, c, d) QUICKCPPLIB_BIND_NAMESPACE_END_NAMESPACE_SELECT a QUICKCPPLIB_BIND_NAMESPACE_END_EXPAND3(b, c, d)
#define QUICKCPPLIB_BIND_NAMESPACE_END_EXPAND3(a, b, c) QUICKCPPLIB_BIND_NAMESPACE_END_NAMESPACE_SELECT a QUICKCPPLIB_BIND_NAMESPACE_END_EXPAND2(b, c)
#define QUICKCPPLIB_BIND_NAMESPACE_END_EXPAND2(a, b) QUICKCPPLIB_BIND_NAMESPACE_END_NAMESPACE_SELECT a QUICKCPPLIB_BIND_NAMESPACE_END_EXPAND1(b)
#define QUICKCPPLIB_BIND_NAMESPACE_END_EXPAND1(a) QUICKCPPLIB_BIND_NAMESPACE_END_NAMESPACE_SELECT a

//! Expands into } } ...
#define QUICKCPPLIB_BIND_NAMESPACE_END(...) QUICKCPPLIB_CALL_OVERLOAD(QUICKCPPLIB_BIND_NAMESPACE_END_EXPAND, __VA_ARGS__)

//! Expands into a static const char string array used to mark BindLib compatible namespaces
#define QUICKCPPLIB_BIND_DECLARE(decl, desc) static const char *quickcpplib_out[] = {#decl, desc};

#endif
#if defined(OUTCOME_UNSTABLE_VERSION)
// Note the second line of this file must ALWAYS be the git SHA, third line ALWAYS the git SHA update time
#define OUTCOME_PREVIOUS_COMMIT_REF b93403b9a55355b8f6783320c8d2db2c14b3517d
#define OUTCOME_PREVIOUS_COMMIT_DATE "2019-02-28 22:02:20 +00:00"
#define OUTCOME_PREVIOUS_COMMIT_UNIQUE b93403b9
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

#include <cstdint>  // for uint32_t etc
#include <initializer_list>
#include <iosfwd>  // for future serialisation
#include <new>     // for placement in moves etc
#include <type_traits>

#ifndef OUTCOME_USE_STD_IN_PLACE_TYPE
#if defined(_MSC_VER) && _HAS_CXX17
#define OUTCOME_USE_STD_IN_PLACE_TYPE 1  // MSVC always has std::in_place_type
#elif __cplusplus >= 201700
// libstdc++ before GCC 6 doesn't have it, despite claiming C++ 17 support
#ifdef __has_include
#if !__has_include(<variant>)
#define OUTCOME_USE_STD_IN_PLACE_TYPE 0  // must have it if <variant> is present
#endif
#endif

#ifndef OUTCOME_USE_STD_IN_PLACE_TYPE
#define OUTCOME_USE_STD_IN_PLACE_TYPE 1
#endif
#else
#define OUTCOME_USE_STD_IN_PLACE_TYPE 0
#endif
#endif

#if OUTCOME_USE_STD_IN_PLACE_TYPE
#include <utility>  // for in_place_type_t

OUTCOME_V2_NAMESPACE_BEGIN
template <class T> using in_place_type_t = std::in_place_type_t<T>;
using std::in_place_type;
OUTCOME_V2_NAMESPACE_END
#else
OUTCOME_V2_NAMESPACE_BEGIN
/*! AWAITING HUGO JSON CONVERSION TOOL
type definition template <class T> in_place_type_t. Potential doc page: `in_place_type_t<T>`
*/
template <class T> struct in_place_type_t
{
  explicit in_place_type_t() = default;
};
/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
template <class T> constexpr in_place_type_t<T> in_place_type{};
OUTCOME_V2_NAMESPACE_END
#endif

OUTCOME_V2_NAMESPACE_BEGIN
namespace detail
{
  // Test if type is an in_place_type_t
  template <class T> struct is_in_place_type_t
  {
    static constexpr bool value = false;
  };
  template <class U> struct is_in_place_type_t<in_place_type_t<U>>
  {
    static constexpr bool value = true;
  };

  // Replace void with constructible void_type
  struct empty_type
  {
  };
  struct void_type
  {
    // We always compare true to another instance of me
    constexpr bool operator==(void_type /*unused*/) const noexcept { return true; }
    constexpr bool operator!=(void_type /*unused*/) const noexcept { return false; }
  };
  template <class T> using devoid = std::conditional_t<std::is_void<T>::value, void_type, T>;

  template <class Output, class Input> using rebind_type5 = Output;
  template <class Output, class Input>
  using rebind_type4 = std::conditional_t<                                   //
  std::is_volatile<Input>::value,                                            //
  std::add_volatile_t<rebind_type5<Output, std::remove_volatile_t<Input>>>,  //
  rebind_type5<Output, Input>>;
  template <class Output, class Input>
  using rebind_type3 = std::conditional_t<                             //
  std::is_const<Input>::value,                                         //
  std::add_const_t<rebind_type4<Output, std::remove_const_t<Input>>>,  //
  rebind_type4<Output, Input>>;
  template <class Output, class Input>
  using rebind_type2 = std::conditional_t<                                            //
  std::is_lvalue_reference<Input>::value,                                             //
  std::add_lvalue_reference_t<rebind_type3<Output, std::remove_reference_t<Input>>>,  //
  rebind_type3<Output, Input>>;
  template <class Output, class Input>
  using rebind_type = std::conditional_t<                                             //
  std::is_rvalue_reference<Input>::value,                                             //
  std::add_rvalue_reference_t<rebind_type2<Output, std::remove_reference_t<Input>>>,  //
  rebind_type2<Output, Input>>;

  // static_assert(std::is_same_v<rebind_type<int, volatile const double &&>, volatile const int &&>, "");


  /* True if type is the same or constructible. Works around a bug where clang + libstdc++
  pukes on std::is_constructible<filesystem::path, void> (this bug is fixed upstream).
  */


  template <class T, class U> struct _is_explicitly_constructible
  {
    static constexpr bool value = std::is_constructible<T, U>::value;
  };
  template <class T> struct _is_explicitly_constructible<T, void>
  {
    static constexpr bool value = false;
  };
  template <> struct _is_explicitly_constructible<void, void>
  {
    static constexpr bool value = false;
  };
  template <class T, class U> static constexpr bool is_explicitly_constructible = _is_explicitly_constructible<T, U>::value;

  template <class T, class U> struct _is_implicitly_constructible
  {
    static constexpr bool value = std::is_convertible<U, T>::value;
  };
  template <class T> struct _is_implicitly_constructible<T, void>
  {
    static constexpr bool value = false;
  };
  template <> struct _is_implicitly_constructible<void, void>
  {
    static constexpr bool value = false;
  };
  template <class T, class U> static constexpr bool is_implicitly_constructible = _is_implicitly_constructible<T, U>::value;

#ifndef OUTCOME_USE_STD_IS_NOTHROW_SWAPPABLE
#if defined(_MSC_VER) && _HAS_CXX17
#define OUTCOME_USE_STD_IS_NOTHROW_SWAPPABLE 1  // MSVC always has std::is_nothrow_swappable
#elif __cplusplus >= 201700
// libstdc++ before GCC 6 doesn't have it, despite claiming C++ 17 support
#ifdef __has_include
#if !__has_include(<variant>)
#define OUTCOME_USE_STD_IS_NOTHROW_SWAPPABLE 0
#endif
#endif

#ifndef OUTCOME_USE_STD_IS_NOTHROW_SWAPPABLE
#define OUTCOME_USE_STD_IS_NOTHROW_SWAPPABLE 1
#endif
#else
#define OUTCOME_USE_STD_IS_NOTHROW_SWAPPABLE 0
#endif
#endif

// True if type is nothrow swappable
#if !0 && OUTCOME_USE_STD_IS_NOTHROW_SWAPPABLE
  template <class T> using is_nothrow_swappable = std::is_nothrow_swappable<T>;
#else
  namespace _is_nothrow_swappable
  {
    using namespace std;
    template <class T> constexpr inline T &ldeclval();
    template <class T, class = void> struct is_nothrow_swappable : std::integral_constant<bool, false>
    {
    };
    template <class T> struct is_nothrow_swappable<T, decltype(swap(ldeclval<T>(), ldeclval<T>()))> : std::integral_constant<bool, noexcept(swap(ldeclval<T>(), ldeclval<T>()))>
    {
    };
  }  // namespace _is_nothrow_swappable
  template <class T> using is_nothrow_swappable = _is_nothrow_swappable::is_nothrow_swappable<T>;
#endif
}  // namespace detail
OUTCOME_V2_NAMESPACE_END


#ifndef OUTCOME_THROW_EXCEPTION
#ifdef __cpp_exceptions
#define OUTCOME_THROW_EXCEPTION(expr) throw expr
#else

#ifdef __ANDROID__
#define OUTCOME_DISABLE_EXECINFO
#endif

#ifndef OUTCOME_DISABLE_EXECINFO
#ifdef _WIN32
/* Implements backtrace() et al from glibc on win64
(C) 2016-2017 Niall Douglas <http://www.nedproductions.biz/> (4 commits)
File Created: Mar 2016


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

#ifndef BOOST_BINDLIB_EXECINFO_WIN64_H
#define BOOST_BINDLIB_EXECINFO_WIN64_H

#ifndef _WIN32
#error Can only be included on Windows
#endif

#include <sal.h>
#include <stddef.h>

#ifdef QUICKCPPLIB_EXPORTS
#define EXECINFO_DECL extern __declspec(dllexport)
#else
#if defined(__cplusplus) && (!defined(QUICKCPPLIB_HEADERS_ONLY) || QUICKCPPLIB_HEADERS_ONLY == 1) && !0
#define EXECINFO_DECL inline
#else
#define EXECINFO_DECL extern __declspec(dllimport)
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif

//! Fill the array of void * at bt with up to len entries, returning entries filled.
EXECINFO_DECL _Check_return_ size_t backtrace(_Out_writes_(len) void **bt, _In_ size_t len);

//! Returns a malloced block of string representations of the input backtrace.
EXECINFO_DECL _Check_return_ _Ret_writes_maybenull_(len) char **backtrace_symbols(_In_reads_(len) void *const *bt, _In_ size_t len);

// extern void backtrace_symbols_fd(void *const *bt, size_t len, int fd);

#ifdef __cplusplus
}

#if (!defined(QUICKCPPLIB_HEADERS_ONLY) || QUICKCPPLIB_HEADERS_ONLY == 1) && !0
#define QUICKCPPLIB_INCLUDED_BY_HEADER 1
/* Implements backtrace() et al from glibc on win64
(C) 2016-2017 Niall Douglas <http://www.nedproductions.biz/> (14 commits)
File Created: Mar 2016


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
/* Implements backtrace() et al from glibc on win64
(C) 2016-2017 Niall Douglas <http://www.nedproductions.biz/> (4 commits)
File Created: Mar 2016


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
#include <stdlib.h>  // for abort
#include <string.h>

// To avoid including windows.h, this source has been macro expanded and win32 function shimmed for C++ only
#if defined(__cplusplus) && !defined(__clang__)
namespace win32
{
  extern "C" __declspec(dllimport) _Ret_maybenull_ void *__stdcall LoadLibraryA(_In_ const char *lpLibFileName);
  typedef int(__stdcall *GetProcAddress_returntype)();
  extern "C" GetProcAddress_returntype __stdcall GetProcAddress(_In_ void *hModule, _In_ const char *lpProcName);
  extern "C" __declspec(dllimport) _Success_(return != 0) unsigned short __stdcall RtlCaptureStackBackTrace(_In_ unsigned long FramesToSkip, _In_ unsigned long FramesToCapture, _Out_writes_to_(FramesToCapture, return ) void **BackTrace, _Out_opt_ unsigned long *BackTraceHash);
  extern "C" __declspec(dllimport) _Success_(return != 0)
  _When_((cchWideChar == -1) && (cbMultiByte != 0), _Post_equal_to_(_String_length_(lpMultiByteStr) + 1)) int __stdcall WideCharToMultiByte(_In_ unsigned int CodePage, _In_ unsigned long dwFlags, const wchar_t *lpWideCharStr, _In_ int cchWideChar, _Out_writes_bytes_to_opt_(cbMultiByte, return ) char *lpMultiByteStr,
                                                                                                                                            _In_ int cbMultiByte, _In_opt_ const char *lpDefaultChar, _Out_opt_ int *lpUsedDefaultChar);
}
#else
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <Windows.h>
#endif

#ifdef __cplusplus
namespace
{
#endif

  typedef struct _IMAGEHLP_LINE64
  {
    unsigned long SizeOfStruct;
    void *Key;
    unsigned long LineNumber;
    wchar_t *FileName;
    unsigned long long int Address;
  } IMAGEHLP_LINE64, *PIMAGEHLP_LINE64;

  typedef int(__stdcall *SymInitialize_t)(_In_ void *hProcess, _In_opt_ const wchar_t *UserSearchPath, _In_ int fInvadeProcess);

  typedef int(__stdcall *SymGetLineFromAddr64_t)(_In_ void *hProcess, _In_ unsigned long long int dwAddr, _Out_ unsigned long *pdwDisplacement, _Out_ PIMAGEHLP_LINE64 Line);

#if defined(__cplusplus) && !defined(__clang__)
  static void *dbghelp;
#else
static HMODULE dbghelp;
#endif
  static SymInitialize_t SymInitialize;
  static SymGetLineFromAddr64_t SymGetLineFromAddr64;

  static void load_dbghelp()
  {
#if defined(__cplusplus) && !defined(__clang__)
    using win32::LoadLibraryA;
    using win32::GetProcAddress;
#endif
    if(dbghelp)
      return;
    dbghelp = LoadLibraryA("DBGHELP.DLL");
    if(dbghelp)
    {
      SymInitialize = (SymInitialize_t) GetProcAddress(dbghelp, "SymInitializeW");
      if(!SymInitialize)
        abort();
      if(!SymInitialize((void *) (size_t) -1 /*GetCurrentProcess()*/, NULL, 1))
        abort();
      SymGetLineFromAddr64 = (SymGetLineFromAddr64_t) GetProcAddress(dbghelp, "SymGetLineFromAddrW64");
      if(!SymGetLineFromAddr64)
        abort();
    }
  }

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C" {
#endif

_Check_return_ size_t backtrace(_Out_writes_(len) void **bt, _In_ size_t len)
{
#if defined(__cplusplus) && !defined(__clang__)
  using win32::RtlCaptureStackBackTrace;
#endif
  return RtlCaptureStackBackTrace(1, (unsigned long) len, bt, NULL);
}

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 6385 6386)  // MSVC static analyser can't grok this function. clang's analyser gives it thumbs up.
#endif
_Check_return_ _Ret_writes_maybenull_(len) char **backtrace_symbols(_In_reads_(len) void *const *bt, _In_ size_t len)
{
#if defined(__cplusplus) && !defined(__clang__)
  using win32::WideCharToMultiByte;
#endif
  size_t bytes = (len + 1) * sizeof(void *) + 256, n;
  if(!len)
    return NULL;
  else
  {
    char **ret = (char **) malloc(bytes);
    char *p = (char *) (ret + len + 1), *end = (char *) ret + bytes;
    if(!ret)
      return NULL;
    for(n = 0; n < len + 1; n++)
      ret[n] = NULL;
    load_dbghelp();
    for(n = 0; n < len; n++)
    {
      unsigned long displ;
      IMAGEHLP_LINE64 ihl;
      memset(&ihl, 0, sizeof(ihl));
      ihl.SizeOfStruct = sizeof(IMAGEHLP_LINE64);
      int please_realloc = 0;
      if(!bt[n])
      {
        ret[n] = NULL;
      }
      else
      {
        // Keep offset till later
        ret[n] = (char *) ((char *) p - (char *) ret);
        if(!SymGetLineFromAddr64 || !SymGetLineFromAddr64((void *) (size_t) -1 /*GetCurrentProcess()*/, (size_t) bt[n], &displ, &ihl))
        {
          if(n == 0)
          {
            free(ret);
            return NULL;
          }
          ihl.FileName = (wchar_t *) L"unknown";
          ihl.LineNumber = 0;
        }
      retry:
        if(please_realloc)
        {
          char **temp = (char **) realloc(ret, bytes + 256);
          if(!temp)
          {
            free(ret);
            return NULL;
          }
          p = (char *) temp + (p - (char *) ret);
          ret = temp;
          bytes += 256;
          end = (char *) ret + bytes;
        }
        if(ihl.FileName && ihl.FileName[0])
        {
          int plen = WideCharToMultiByte(65001 /*CP_UTF8*/, 0, ihl.FileName, -1, p, (int) (end - p), NULL, NULL);
          if(!plen)
          {
            please_realloc = 1;
            goto retry;
          }
          p[plen - 1] = 0;
          p += plen - 1;
        }
        else
        {
          if(end - p < 16)
          {
            please_realloc = 1;
            goto retry;
          }
          _ui64toa_s((size_t) bt[n], p, end - p, 16);
          p = strchr(p, 0);
        }
        if(end - p < 16)
        {
          please_realloc = 1;
          goto retry;
        }
        *p++ = ':';
        _itoa_s(ihl.LineNumber, p, end - p, 10);
        p = strchr(p, 0) + 1;
      }
    }
    for(n = 0; n < len; n++)
    {
      if(ret[n])
        ret[n] = (char *) ret + (size_t) ret[n];
    }
    return ret;
  }
}
#ifdef _MSC_VER
#pragma warning(pop)
#endif

// extern void backtrace_symbols_fd(void *const *bt, size_t len, int fd);

#ifdef __cplusplus
}
#endif
#undef QUICKCPPLIB_INCLUDED_BY_HEADER
#endif

#endif

#endif
#else
#include <execinfo.h>
#endif
#endif  // OUTCOME_DISABLE_EXECINFO
#include <cstdio>
#include <cstdlib>
OUTCOME_V2_NAMESPACE_BEGIN
namespace detail
{
  QUICKCPPLIB_NORETURN inline void do_fatal_exit(const char *expr)
  {
#if !defined(OUTCOME_DISABLE_EXECINFO)
    void *bt[16];
    size_t btlen = backtrace(bt, sizeof(bt) / sizeof(bt[0]));                                // NOLINT
#endif
    fprintf(stderr, "FATAL: Outcome throws exception %s with exceptions disabled\n", expr);  // NOLINT
#if !defined(OUTCOME_DISABLE_EXECINFO)
    char **bts = backtrace_symbols(bt, btlen);                                               // NOLINT
    if(bts != nullptr)
    {
      for(size_t n = 0; n < btlen; n++)
      {
        fprintf(stderr, "  %s\n", bts[n]);  // NOLINT
      }
      free(bts);  // NOLINT
    }
#endif
    abort();
  }
}  // namespace detail
OUTCOME_V2_NAMESPACE_END
#define OUTCOME_THROW_EXCEPTION(expr) OUTCOME_V2_NAMESPACE::detail::do_fatal_exit(#expr), (void) (expr)

#endif
#endif

#ifndef BOOST_OUTCOME_AUTO_TEST_CASE
#define BOOST_OUTCOME_AUTO_TEST_CASE(a, b) BOOST_AUTO_TEST_CASE(a, b)
#endif

#endif
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

#ifndef OUTCOME_BASIC_RESULT_HPP
#define OUTCOME_BASIC_RESULT_HPP
/* Says how to convert value, error and exception types
(C) 2017 Niall Douglas <http://www.nedproductions.biz/> (59 commits)
File Created: Nov 2017


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

#ifndef OUTCOME_CONVERT_HPP
#define OUTCOME_CONVERT_HPP
/* Storage for a very simple basic_result type
(C) 2017 Niall Douglas <http://www.nedproductions.biz/> (59 commits)
File Created: Oct 2017


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

#ifndef OUTCOME_BASIC_RESULT_STORAGE_HPP
#define OUTCOME_BASIC_RESULT_STORAGE_HPP
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



OUTCOME_V2_NAMESPACE_BEGIN

/*! AWAITING HUGO JSON CONVERSION TOOL
type definition template <class T> success_type. Potential doc page: `success_type<T>`
*/
template <class T> struct OUTCOME_NODISCARD success_type
{
  using value_type = T;

private:
  value_type _value;

public:
  success_type() = default;
  success_type(const success_type &) = default;
  success_type(success_type &&) = default;  // NOLINT
  success_type &operator=(const success_type &) = default;
  success_type &operator=(success_type &&) = default;  // NOLINT
  ~success_type() = default;
  OUTCOME_TEMPLATE(class U)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(!std::is_same<success_type, std::decay_t<U>>::value))
  constexpr explicit success_type(U &&v)
      : _value(static_cast<U &&>(v))  // NOLINT
  {
  }

  constexpr value_type &value() & { return _value; }
  constexpr const value_type &value() const & { return _value; }
  constexpr value_type &&value() && { return static_cast<value_type &&>(_value); }
  constexpr const value_type &&value() const && { return static_cast<value_type &&>(_value); }
};
template <> struct OUTCOME_NODISCARD success_type<void>
{
  using value_type = void;
};
/*! Returns type sugar for implicitly constructing a `basic_result<T>` with a successful state,
default constructing `T` if necessary.
*/
inline constexpr success_type<void> success() noexcept
{
  return success_type<void>{};
}
/*! Returns type sugar for implicitly constructing a `basic_result<T>` with a successful state.
\effects Copies or moves the successful state supplied into the returned type sugar.
*/
template <class T> inline constexpr success_type<std::decay_t<T>> success(T &&v)
{
  return success_type<std::decay_t<T>>{static_cast<T &&>(v)};
}

/*! AWAITING HUGO JSON CONVERSION TOOL
type definition template <class EC, class E = void> failure_type. Potential doc page: `failure_type<EC, EP = void>`
*/
template <class EC, class E = void> struct OUTCOME_NODISCARD failure_type
{
  using error_type = EC;
  using exception_type = E;

private:
  bool _have_error{}, _have_exception{};
  error_type _error;
  exception_type _exception;

  struct error_init_tag
  {
  };
  struct exception_init_tag
  {
  };

public:
  failure_type() = default;
  failure_type(const failure_type &) = default;
  failure_type(failure_type &&) = default;  // NOLINT
  failure_type &operator=(const failure_type &) = default;
  failure_type &operator=(failure_type &&) = default;  // NOLINT
  ~failure_type() = default;
  template <class U, class V>
  constexpr explicit failure_type(U &&u, V &&v)
      : _have_error(true)
      , _have_exception(true)
      , _error(static_cast<U &&>(u))
      , _exception(static_cast<V &&>(v))
  {
  }
  template <class U>
  constexpr explicit failure_type(in_place_type_t<error_type> /*unused*/, U &&u, error_init_tag /*unused*/ = error_init_tag())
      : _have_error(true)
      , _error(static_cast<U &&>(u))
      , _exception()
  {
  }
  template <class U>
  constexpr explicit failure_type(in_place_type_t<exception_type> /*unused*/, U &&u, exception_init_tag /*unused*/ = exception_init_tag())
      : _have_exception(true)
      , _error()
      , _exception(static_cast<U &&>(u))
  {
  }

  constexpr bool has_error() const { return _have_error; }
  constexpr bool has_exception() const { return _have_exception; }

  constexpr error_type &error() & { return _error; }
  constexpr const error_type &error() const & { return _error; }
  constexpr error_type &&error() && { return static_cast<error_type &&>(_error); }
  constexpr const error_type &&error() const && { return static_cast<error_type &&>(_error); }

  constexpr exception_type &exception() & { return _exception; }
  constexpr const exception_type &exception() const & { return _exception; }
  constexpr exception_type &&exception() && { return static_cast<exception_type &&>(_exception); }
  constexpr const exception_type &&exception() const && { return static_cast<exception_type &&>(_exception); }
};
template <class EC> struct OUTCOME_NODISCARD failure_type<EC, void>
{
  using error_type = EC;
  using exception_type = void;

private:
  error_type _error;

public:
  failure_type() = default;
  failure_type(const failure_type &) = default;
  failure_type(failure_type &&) = default;  // NOLINT
  failure_type &operator=(const failure_type &) = default;
  failure_type &operator=(failure_type &&) = default;  // NOLINT
  ~failure_type() = default;
  OUTCOME_TEMPLATE(class U)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(!std::is_same<failure_type, std::decay_t<U>>::value))
  constexpr explicit failure_type(U &&u)
      : _error(static_cast<U &&>(u))  // NOLINT
  {
  }

  constexpr error_type &error() & { return _error; }
  constexpr const error_type &error() const & { return _error; }
  constexpr error_type &&error() && { return static_cast<error_type &&>(_error); }
  constexpr const error_type &&error() const && { return static_cast<error_type &&>(_error); }
};
template <class E> struct OUTCOME_NODISCARD failure_type<void, E>
{
  using error_type = void;
  using exception_type = E;

private:
  exception_type _exception;

public:
  failure_type() = default;
  failure_type(const failure_type &) = default;
  failure_type(failure_type &&) = default;  // NOLINT
  failure_type &operator=(const failure_type &) = default;
  failure_type &operator=(failure_type &&) = default;  // NOLINT
  ~failure_type() = default;
  OUTCOME_TEMPLATE(class V)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(!std::is_same<failure_type, std::decay_t<V>>::value))
  constexpr explicit failure_type(V &&v)
      : _exception(static_cast<V &&>(v))  // NOLINT
  {
  }

  constexpr exception_type &exception() & { return _exception; }
  constexpr const exception_type &exception() const & { return _exception; }
  constexpr exception_type &&exception() && { return static_cast<exception_type &&>(_exception); }
  constexpr const exception_type &&exception() const && { return static_cast<exception_type &&>(_exception); }
};
/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
template <class EC> inline constexpr failure_type<std::decay_t<EC>> failure(EC &&v)
{
  return failure_type<std::decay_t<EC>>{static_cast<EC &&>(v)};
}
/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
template <class EC, class E> inline constexpr failure_type<std::decay_t<EC>, std::decay_t<E>> failure(EC &&v, E &&w)
{
  return failure_type<std::decay_t<EC>, std::decay_t<E>>{static_cast<EC &&>(v), static_cast<E &&>(w)};
}

namespace detail
{
  template <class T> struct is_success_type
  {
    static constexpr bool value = false;
  };
  template <class T> struct is_success_type<success_type<T>>
  {
    static constexpr bool value = true;
  };
  template <class T> struct is_failure_type
  {
    static constexpr bool value = false;
  };
  template <class EC, class E> struct is_failure_type<failure_type<EC, E>>
  {
    static constexpr bool value = true;
  };
}  // namespace detail

/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
template <class T> static constexpr bool is_success_type = detail::is_success_type<std::decay_t<T>>::value;

/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
template <class T> static constexpr bool is_failure_type = detail::is_failure_type<std::decay_t<T>>::value;

OUTCOME_V2_NAMESPACE_END

#endif
/* Traits for Outcome
(C) 2018 Niall Douglas <http://www.nedproductions.biz/> (59 commits)
File Created: March 2018


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

#ifndef OUTCOME_TRAIT_HPP
#define OUTCOME_TRAIT_HPP



OUTCOME_V2_NAMESPACE_BEGIN

namespace trait
{
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  template <class R>                                                             //
  static constexpr bool type_can_be_used_in_basic_result =                       //
  (!std::is_reference<R>::value                                                  //
   && !OUTCOME_V2_NAMESPACE::detail::is_in_place_type_t<std::decay_t<R>>::value  //
   && !is_success_type<R>                                                        //
   && !is_failure_type<R>                                                        //
   && !std::is_array<R>::value                                                   //
   && (std::is_void<R>::value || (std::is_object<R>::value                       //
                                  && std::is_destructible<R>::value))            //
   );

  /*! AWAITING HUGO JSON CONVERSION TOOL
type definition  is_error_type. Potential doc page: NOT FOUND
*/


  template <class E> struct is_error_type
  {
    static constexpr bool value = false;
  };

  /*! AWAITING HUGO JSON CONVERSION TOOL
type definition  is_error_type_enum. Potential doc page: NOT FOUND
*/


  template <class E, class Enum> struct is_error_type_enum
  {
    static constexpr bool value = false;
  };

  namespace detail
  {
    template <class T> using devoid = OUTCOME_V2_NAMESPACE::detail::devoid<T>;
    template <class T> std::add_rvalue_reference_t<devoid<T>> declval() noexcept;

    // From http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4436.pdf
    namespace detector_impl
    {
      template <class...> using void_t = void;
      template <class Default, class, template <class...> class Op, class... Args> struct detector
      {
        static constexpr bool value = false;
        using type = Default;
      };
      template <class Default, template <class...> class Op, class... Args> struct detector<Default, void_t<Op<Args...>>, Op, Args...>
      {
        static constexpr bool value = true;
        using type = Op<Args...>;
      };
    }  // namespace detector_impl
    template <template <class...> class Op, class... Args> using is_detected = detector_impl::detector<void, void, Op, Args...>;

    template <class Arg> using result_of_make_error_code = decltype(make_error_code(declval<Arg>()));
    template <class Arg> using introspect_make_error_code = is_detected<result_of_make_error_code, Arg>;

    template <class Arg> using result_of_make_exception_ptr = decltype(make_exception_ptr(declval<Arg>()));
    template <class Arg> using introspect_make_exception_ptr = is_detected<result_of_make_exception_ptr, Arg>;

    template <class T> struct _is_error_code_available
    {
      static constexpr bool value = detail::introspect_make_error_code<T>::value;
    };
    template <class T> struct _is_exception_ptr_available
    {
      static constexpr bool value = detail::introspect_make_exception_ptr<T>::value;
    };
  }  // namespace detail

  /*! AWAITING HUGO JSON CONVERSION TOOL
type definition  is_error_code_available. Potential doc page: NOT FOUND
*/


  template <class T> struct is_error_code_available
  {
    static constexpr bool value = detail::_is_error_code_available<std::decay_t<T>>::value;
  };
  template <class T> constexpr bool is_error_code_available_v = detail::_is_error_code_available<std::decay_t<T>>::value;

  /*! AWAITING HUGO JSON CONVERSION TOOL
type definition  is_exception_ptr_available. Potential doc page: NOT FOUND
*/


  template <class T> struct is_exception_ptr_available
  {
    static constexpr bool value = detail::_is_exception_ptr_available<std::decay<T>>::value;
  };
  template <class T> constexpr bool is_exception_ptr_available_v = detail::_is_exception_ptr_available<std::decay<T>>::value;


}  // namespace trait

OUTCOME_V2_NAMESPACE_END

#endif
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



OUTCOME_V2_NAMESPACE_BEGIN

namespace detail
{
  using status_bitfield_type = uint32_t;

  // WARNING: These bits are not tracked by abi-dumper, but changing them will break ABI!
  static constexpr status_bitfield_type status_have_value = (1U << 0U);
  static constexpr status_bitfield_type status_have_error = (1U << 1U);
  static constexpr status_bitfield_type status_have_exception = (1U << 2U);
  static constexpr status_bitfield_type status_error_is_errno = (1U << 4U);  // can errno be set from this error?
  // bit 7 unused
  // bits 8-15 unused
  // bits 16-31 used for user supplied 16 bit value
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
    status_bitfield_type _status{0};
    constexpr value_storage_trivial() noexcept : _empty{} {}
    // Special from-void catchall constructor, always constructs default T irrespective of whether void is valued or not (can do no better if T cannot be copied)
    struct disable_void_catchall
    {
    };
    using void_value_storage_trivial = std::conditional_t<std::is_void<T>::value, disable_void_catchall, value_storage_trivial<void>>;
    explicit constexpr value_storage_trivial(const void_value_storage_trivial &o) noexcept(std::is_nothrow_default_constructible<value_type>::value)
        : _value()
        , _status(o._status)
    {
    }
    value_storage_trivial(const value_storage_trivial &) = default;             // NOLINT
    value_storage_trivial(value_storage_trivial &&) = default;                  // NOLINT
    value_storage_trivial &operator=(const value_storage_trivial &) = default;  // NOLINT
    value_storage_trivial &operator=(value_storage_trivial &&) = default;       // NOLINT
    ~value_storage_trivial() = default;
    constexpr explicit value_storage_trivial(status_bitfield_type status)
        : _empty()
        , _status(status)
    {
    }
    template <class... Args>
    constexpr explicit value_storage_trivial(in_place_type_t<value_type> /*unused*/, Args &&... args) noexcept(std::is_nothrow_constructible<value_type, Args...>::value)
        : _value(static_cast<Args &&>(args)...)
        , _status(status_have_value)
    {
    }
    template <class U, class... Args>
    constexpr value_storage_trivial(in_place_type_t<value_type> /*unused*/, std::initializer_list<U> il, Args &&... args) noexcept(std::is_nothrow_constructible<value_type, std::initializer_list<U>, Args...>::value)
        : _value(il, static_cast<Args &&>(args)...)
        , _status(status_have_value)
    {
    }
    template <class U> static constexpr bool enable_converting_constructor = !std::is_same<std::decay_t<U>, value_type>::value && std::is_constructible<value_type, U>::value;
    OUTCOME_TEMPLATE(class U)
    OUTCOME_TREQUIRES(OUTCOME_TPRED(enable_converting_constructor<U>))
    constexpr explicit value_storage_trivial(const value_storage_trivial<U> &o) noexcept(std::is_nothrow_constructible<value_type, U>::value)
        : value_storage_trivial(((o._status & status_have_value) != 0) ? value_storage_trivial(in_place_type<value_type>, o._value) : value_storage_trivial())  // NOLINT
    {
      _status = o._status;
    }
    OUTCOME_TEMPLATE(class U)
    OUTCOME_TREQUIRES(OUTCOME_TPRED(enable_converting_constructor<U>))
    constexpr explicit value_storage_trivial(value_storage_trivial<U> &&o) noexcept(std::is_nothrow_constructible<value_type, U>::value)
        : value_storage_trivial(((o._status & status_have_value) != 0) ? value_storage_trivial(in_place_type<value_type>, static_cast<U &&>(o._value)) : value_storage_trivial())  // NOLINT
    {
      _status = o._status;
    }
    constexpr void swap(value_storage_trivial &o) noexcept
    {
      // storage is trivial, so just use assignment
      auto temp = static_cast<value_storage_trivial &&>(*this);
      *this = static_cast<value_storage_trivial &&>(o);
      o = static_cast<value_storage_trivial &&>(temp);
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
    status_bitfield_type _status{0};
    value_storage_nontrivial() noexcept : _empty{} {}
    value_storage_nontrivial &operator=(const value_storage_nontrivial &) = default;                                        // if reaches here, copy assignment is trivial
    value_storage_nontrivial &operator=(value_storage_nontrivial &&) = default;                                             // NOLINT if reaches here, move assignment is trivial
    value_storage_nontrivial(value_storage_nontrivial &&o) noexcept(std::is_nothrow_move_constructible<value_type>::value)  // NOLINT
    : _status(o._status)
    {
      if(this->_status & status_have_value)
      {
        this->_status &= ~status_have_value;
        new(&_value) value_type(static_cast<value_type &&>(o._value));  // NOLINT
        _status = o._status;
      }
    }
    value_storage_nontrivial(const value_storage_nontrivial &o) noexcept(std::is_nothrow_copy_constructible<value_type>::value)
        : _status(o._status)
    {
      if(this->_status & status_have_value)
      {
        this->_status &= ~status_have_value;
        new(&_value) value_type(o._value);  // NOLINT
        _status = o._status;
      }
    }
    // Special from-void constructor, constructs default T if void valued
    explicit value_storage_nontrivial(const value_storage_trivial<void> &o) noexcept(std::is_nothrow_default_constructible<value_type>::value)
        : _status(o._status)
    {
      if(this->_status & status_have_value)
      {
        this->_status &= ~status_have_value;
        new(&_value) value_type;  // NOLINT
        _status = o._status;
      }
    }
    explicit value_storage_nontrivial(status_bitfield_type status)
        : _empty()
        , _status(status)
    {
    }
    template <class... Args>
    explicit value_storage_nontrivial(in_place_type_t<value_type> /*unused*/, Args &&... args) noexcept(std::is_nothrow_constructible<value_type, Args...>::value)
        : _value(static_cast<Args &&>(args)...)  // NOLINT
        , _status(status_have_value)
    {
    }
    template <class U, class... Args>
    value_storage_nontrivial(in_place_type_t<value_type> /*unused*/, std::initializer_list<U> il, Args &&... args) noexcept(std::is_nothrow_constructible<value_type, std::initializer_list<U>, Args...>::value)
        : _value(il, static_cast<Args &&>(args)...)
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
    constexpr explicit value_storage_nontrivial(const value_storage_trivial<U> &o) noexcept(std::is_nothrow_constructible<value_type, U>::value)
        : value_storage_nontrivial((o._status & status_have_value) != 0 ? value_storage_nontrivial(in_place_type<value_type>, o._value) : value_storage_nontrivial())
    {
      _status = o._status;
    }
    OUTCOME_TEMPLATE(class U)
    OUTCOME_TREQUIRES(OUTCOME_TPRED(enable_converting_constructor<U>))
    constexpr explicit value_storage_nontrivial(value_storage_nontrivial<U> &&o) noexcept(std::is_nothrow_constructible<value_type, U>::value)
        : value_storage_nontrivial((o._status & status_have_value) != 0 ? value_storage_nontrivial(in_place_type<value_type>, static_cast<U &&>(o._value)) : value_storage_nontrivial())
    {
      _status = o._status;
    }
    OUTCOME_TEMPLATE(class U)
    OUTCOME_TREQUIRES(OUTCOME_TPRED(enable_converting_constructor<U>))
    constexpr explicit value_storage_nontrivial(value_storage_trivial<U> &&o) noexcept(std::is_nothrow_constructible<value_type, U>::value)
        : value_storage_nontrivial((o._status & status_have_value) != 0 ? value_storage_nontrivial(in_place_type<value_type>, static_cast<U &&>(o._value)) : value_storage_nontrivial())
    {
      _status = o._status;
    }
    ~value_storage_nontrivial() noexcept(std::is_nothrow_destructible<T>::value)
    {
      if(this->_status & status_have_value)
      {
        this->_value.~value_type();  // NOLINT
        this->_status &= ~status_have_value;
      }
    }
    constexpr void swap(value_storage_nontrivial &o) noexcept(detail::is_nothrow_swappable<value_type>::value &&std::is_nothrow_move_constructible<value_type>::value)
    {
      using std::swap;
      if((_status & status_have_value) == 0 && (o._status & status_have_value) == 0)
      {
        swap(_status, o._status);
        return;
      }
      if((_status & status_have_value) != 0 && (o._status & status_have_value) != 0)
      {
        swap(_value, o._value);  // NOLINT
        swap(_status, o._status);
        return;
      }
      // One must be empty and the other non-empty, so use move construction
      if((_status & status_have_value) != 0)
      {
        // Move construct me into other
        new(&o._value) value_type(static_cast<value_type &&>(_value));  // NOLINT
        this->_value.~value_type();                                     // NOLINT
        swap(_status, o._status);
      }
      else
      {
        // Move construct other into me
        new(&_value) value_type(static_cast<value_type &&>(o._value));  // NOLINT
        o._value.~value_type();                                         // NOLINT
        swap(_status, o._status);
      }
    }
  };
  template <class Base> struct value_storage_delete_copy_constructor : Base  // NOLINT
  {
    using Base::Base;
    using value_type = typename Base::value_type;
    value_storage_delete_copy_constructor() = default;
    value_storage_delete_copy_constructor(const value_storage_delete_copy_constructor &) = delete;
    value_storage_delete_copy_constructor(value_storage_delete_copy_constructor &&) = default;  // NOLINT
  };
  template <class Base> struct value_storage_delete_copy_assignment : Base  // NOLINT
  {
    using Base::Base;
    using value_type = typename Base::value_type;
    value_storage_delete_copy_assignment() = default;
    value_storage_delete_copy_assignment(const value_storage_delete_copy_assignment &) = default;
    value_storage_delete_copy_assignment(value_storage_delete_copy_assignment &&) = default;  // NOLINT
    value_storage_delete_copy_assignment &operator=(const value_storage_delete_copy_assignment &o) = delete;
    value_storage_delete_copy_assignment &operator=(value_storage_delete_copy_assignment &&o) = default;  // NOLINT
  };
  template <class Base> struct value_storage_delete_move_assignment : Base  // NOLINT
  {
    using Base::Base;
    using value_type = typename Base::value_type;
    value_storage_delete_move_assignment() = default;
    value_storage_delete_move_assignment(const value_storage_delete_move_assignment &) = default;
    value_storage_delete_move_assignment(value_storage_delete_move_assignment &&) = default;  // NOLINT
    value_storage_delete_move_assignment &operator=(const value_storage_delete_move_assignment &o) = default;
    value_storage_delete_move_assignment &operator=(value_storage_delete_move_assignment &&o) = delete;
  };
  template <class Base> struct value_storage_delete_move_constructor : Base  // NOLINT
  {
    using Base::Base;
    using value_type = typename Base::value_type;
    value_storage_delete_move_constructor() = default;
    value_storage_delete_move_constructor(const value_storage_delete_move_constructor &) = default;
    value_storage_delete_move_constructor(value_storage_delete_move_constructor &&) = delete;
  };
  template <class Base> struct value_storage_nontrivial_move_assignment : Base  // NOLINT
  {
    using Base::Base;
    using value_type = typename Base::value_type;
    value_storage_nontrivial_move_assignment() = default;
    value_storage_nontrivial_move_assignment(const value_storage_nontrivial_move_assignment &) = default;
    value_storage_nontrivial_move_assignment(value_storage_nontrivial_move_assignment &&) = default;  // NOLINT
    value_storage_nontrivial_move_assignment &operator=(const value_storage_nontrivial_move_assignment &o) = default;
    value_storage_nontrivial_move_assignment &operator=(value_storage_nontrivial_move_assignment &&o) noexcept(std::is_nothrow_move_assignable<value_type>::value)  // NOLINT
    {
      if((this->_status & status_have_value) != 0 && (o._status & status_have_value) != 0)
      {
        this->_value = static_cast<value_type &&>(o._value);  // NOLINT
      }
      else if((this->_status & status_have_value) != 0 && (o._status & status_have_value) == 0)
      {
        this->_value.~value_type();  // NOLINT
      }
      else if((this->_status & status_have_value) == 0 && (o._status & status_have_value) != 0)
      {
        new(&this->_value) value_type(static_cast<value_type &&>(o._value));  // NOLINT
      }
      this->_status = o._status;
      return *this;
    }
  };
  template <class Base> struct value_storage_nontrivial_copy_assignment : Base  // NOLINT
  {
    using Base::Base;
    using value_type = typename Base::value_type;
    value_storage_nontrivial_copy_assignment() = default;
    value_storage_nontrivial_copy_assignment(const value_storage_nontrivial_copy_assignment &) = default;
    value_storage_nontrivial_copy_assignment(value_storage_nontrivial_copy_assignment &&) = default;              // NOLINT
    value_storage_nontrivial_copy_assignment &operator=(value_storage_nontrivial_copy_assignment &&o) = default;  // NOLINT
    value_storage_nontrivial_copy_assignment &operator=(const value_storage_nontrivial_copy_assignment &o) noexcept(std::is_nothrow_copy_assignable<value_type>::value)
    {
      if((this->_status & status_have_value) != 0 && (o._status & status_have_value) != 0)
      {
        this->_value = o._value;  // NOLINT
      }
      else if((this->_status & status_have_value) != 0 && (o._status & status_have_value) == 0)
      {
        this->_value.~value_type();  // NOLINT
      }
      else if((this->_status & status_have_value) == 0 && (o._status & status_have_value) != 0)
      {
        new(&this->_value) value_type(o._value);  // NOLINT
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
}  // namespace detail

OUTCOME_V2_NAMESPACE_END

#endif
OUTCOME_V2_NAMESPACE_EXPORT_BEGIN

namespace detail
{
  template <class State, class E> constexpr inline void _set_error_is_errno(State & /*unused*/, const E & /*unused*/) {}
  template <class R, class S, class NoValuePolicy> class basic_result_final;
}  // namespace detail

namespace hooks
{
  template <class R, class S, class NoValuePolicy> constexpr inline uint16_t spare_storage(const detail::basic_result_final<R, S, NoValuePolicy> *r) noexcept;
  template <class R, class S, class NoValuePolicy> constexpr inline void set_spare_storage(detail::basic_result_final<R, S, NoValuePolicy> *r, uint16_t v) noexcept;
}  // namespace hooks

namespace policy
{
  struct base;
}  // namespace policy

namespace detail
{
  template <bool value_throws, bool error_throws> struct basic_result_storage_swap;
  template <class R, class EC, class NoValuePolicy>                                                                                                                                    //
  OUTCOME_REQUIRES(trait::type_can_be_used_in_basic_result<R> &&trait::type_can_be_used_in_basic_result<EC> && (std::is_void<EC>::value || std::is_default_constructible<EC>::value))  //
  class basic_result_storage
  {
    static_assert(trait::type_can_be_used_in_basic_result<R>, "The type R cannot be used in a basic_result");
    static_assert(trait::type_can_be_used_in_basic_result<EC>, "The type S cannot be used in a basic_result");
    static_assert(std::is_void<EC>::value || std::is_default_constructible<EC>::value, "The type S must be void or default constructible");

    friend struct policy::base;
    template <class T, class U, class V> friend class basic_result_storage;
    template <class T, class U, class V> friend class basic_result_final;
    template <class T, class U, class V> friend constexpr inline uint16_t hooks::spare_storage(const detail::basic_result_final<T, U, V> *r) noexcept;        // NOLINT
    template <class T, class U, class V> friend constexpr inline void hooks::set_spare_storage(detail::basic_result_final<T, U, V> *r, uint16_t v) noexcept;  // NOLINT
    template <bool value_throws, bool error_throws> struct basic_result_storage_swap;

    struct disable_in_place_value_type
    {
    };
    struct disable_in_place_error_type
    {
    };

  protected:
    using _value_type = std::conditional_t<std::is_same<R, EC>::value, disable_in_place_value_type, R>;
    using _error_type = std::conditional_t<std::is_same<R, EC>::value, disable_in_place_error_type, EC>;




    detail::value_storage_select_impl<_value_type> _state;

    detail::devoid<_error_type> _error;

  public:
    // Used by iostream support to access state
    detail::value_storage_select_impl<_value_type> &_iostreams_state() { return _state; }
    const detail::value_storage_select_impl<_value_type> &_iostreams_state() const { return _state; }

    // Hack to work around MSVC bug in /permissive-
    detail::value_storage_select_impl<_value_type> &_msvc_nonpermissive_state() { return _state; }
    detail::devoid<_error_type> &_msvc_nonpermissive_error() { return _error; }

  protected:
    basic_result_storage() = default;
    basic_result_storage(const basic_result_storage &) = default;             // NOLINT
    basic_result_storage(basic_result_storage &&) = default;                  // NOLINT
    basic_result_storage &operator=(const basic_result_storage &) = default;  // NOLINT
    basic_result_storage &operator=(basic_result_storage &&) = default;       // NOLINT
    ~basic_result_storage() = default;

    template <class... Args>
    constexpr explicit basic_result_storage(in_place_type_t<_value_type> _, Args &&... args) noexcept(std::is_nothrow_constructible<_value_type, Args...>::value)
        : _state{_, static_cast<Args &&>(args)...}
        , _error()
    {
    }
    template <class U, class... Args>
    constexpr basic_result_storage(in_place_type_t<_value_type> _, std::initializer_list<U> il, Args &&... args) noexcept(std::is_nothrow_constructible<_value_type, std::initializer_list<U>, Args...>::value)
        : _state{_, il, static_cast<Args &&>(args)...}
        , _error()
    {
    }
    template <class... Args>
    constexpr explicit basic_result_storage(in_place_type_t<_error_type> /*unused*/, Args &&... args) noexcept(std::is_nothrow_constructible<_error_type, Args...>::value)
        : _state{detail::status_have_error}
        , _error(static_cast<Args &&>(args)...)
    {
      _set_error_is_errno(_state, _error);
    }
    template <class U, class... Args>
    constexpr basic_result_storage(in_place_type_t<_error_type> /*unused*/, std::initializer_list<U> il, Args &&... args) noexcept(std::is_nothrow_constructible<_error_type, std::initializer_list<U>, Args...>::value)
        : _state{detail::status_have_error}
        , _error{il, static_cast<Args &&>(args)...}
    {
      _set_error_is_errno(_state, _error);
    }
    struct compatible_conversion_tag
    {
    };
    template <class T, class U, class V>
    constexpr basic_result_storage(compatible_conversion_tag /*unused*/, const basic_result_storage<T, U, V> &o) noexcept(std::is_nothrow_constructible<_value_type, T>::value &&std::is_nothrow_constructible<_error_type, U>::value)
        : _state(o._state)
        , _error(o._error)
    {
    }
    template <class T, class V>
    constexpr basic_result_storage(compatible_conversion_tag /*unused*/, const basic_result_storage<T, void, V> &o) noexcept(std::is_nothrow_constructible<_value_type, T>::value)
        : _state(o._state)
        , _error(_error_type{})
    {
    }
    template <class T, class U, class V>
    constexpr basic_result_storage(compatible_conversion_tag /*unused*/, basic_result_storage<T, U, V> &&o) noexcept(std::is_nothrow_constructible<_value_type, T>::value &&std::is_nothrow_constructible<_error_type, U>::value)
        : _state(static_cast<decltype(o._state) &&>(o._state))
        , _error(static_cast<U &&>(o._error))
    {
    }
    template <class T, class V>
    constexpr basic_result_storage(compatible_conversion_tag /*unused*/, basic_result_storage<T, void, V> &&o) noexcept(std::is_nothrow_constructible<_value_type, T>::value)
        : _state(static_cast<decltype(o._state) &&>(o._state))
        , _error(_error_type{})
    {
    }
  };

// Neither value nor error type can throw during swap
#ifdef __cpp_exceptions
  template <> struct basic_result_storage_swap<false, false>
#else
  template <bool value_throws, bool error_throws> struct basic_result_storage_swap
#endif
  {
    template <class R, class EC, class NoValuePolicy> constexpr basic_result_storage_swap(basic_result_storage<R, EC, NoValuePolicy> &a, basic_result_storage<R, EC, NoValuePolicy> &b)
    {
      using std::swap;
      a._msvc_nonpermissive_state().swap(b._msvc_nonpermissive_state());
      swap(a._msvc_nonpermissive_error(), b._msvc_nonpermissive_error());
    }
  };
#ifdef __cpp_exceptions
  // Swap potentially throwing value first
  template <> struct basic_result_storage_swap<true, false>
  {
    template <class R, class EC, class NoValuePolicy> constexpr basic_result_storage_swap(basic_result_storage<R, EC, NoValuePolicy> &a, basic_result_storage<R, EC, NoValuePolicy> &b)
    {
      using std::swap;
      a._msvc_nonpermissive_state().swap(b._msvc_nonpermissive_state());
      swap(a._msvc_nonpermissive_error(), b._msvc_nonpermissive_error());
    }
  };
  // Swap potentially throwing error first
  template <> struct basic_result_storage_swap<false, true>
  {
    template <class R, class EC, class NoValuePolicy> constexpr basic_result_storage_swap(basic_result_storage<R, EC, NoValuePolicy> &a, basic_result_storage<R, EC, NoValuePolicy> &b)
    {
      using std::swap;
      swap(a._msvc_nonpermissive_error(), b._msvc_nonpermissive_error());
      a._msvc_nonpermissive_state().swap(b._msvc_nonpermissive_state());
    }
  };
  // Both could throw
  template <> struct basic_result_storage_swap<true, true>
  {
    template <class R, class EC, class NoValuePolicy> basic_result_storage_swap(basic_result_storage<R, EC, NoValuePolicy> &a, basic_result_storage<R, EC, NoValuePolicy> &b)
    {
      using std::swap;
      // Swap value and status first, if it throws, status will remain unchanged
      a._msvc_nonpermissive_state().swap(b._msvc_nonpermissive_state());
      try
      {
        swap(a._msvc_nonpermissive_error(), b._msvc_nonpermissive_error());
      }
      catch(...)
      {
        // First try to put the value and status back
        try
        {
          a._msvc_nonpermissive_state().swap(b._msvc_nonpermissive_state());
          // If that succeeded, continue by rethrowing the exception
        }
        catch(...)
        {
          // We are now trapped. The value swapped, the error did not,
          // trying to restore the value failed. We now have
          // inconsistent result objects. Best we can do is fix up the
          // status bits to prevent has_value() == has_error().
          auto check = [](basic_result_storage<R, EC, NoValuePolicy> &x) {
            bool has_value = (x._state._status & detail::status_have_value) != 0;
            bool has_error = (x._state._status & detail::status_have_error) != 0;
            bool has_exception = (x._state._status & detail::status_have_exception) != 0;
            if(has_value == (has_error || has_exception))
            {
              if(has_value)
              {
                // We know the value swapped and is now set, so clear error and exception
                x._state._status &= ~(detail::status_have_error | detail::status_have_exception);
              }
              else
              {
                // We know the value swapped and is now unset, so set error
                x._state._status |= detail::status_have_error;
                // TODO: Should I default construct reset _error? It's guaranteed default constructible.
              }
            }
          };
          check(a);
          check(b);
        }
        throw;
      }
    }
  };
#endif

}  // namespace detail
OUTCOME_V2_NAMESPACE_END

#endif
OUTCOME_V2_NAMESPACE_EXPORT_BEGIN

namespace convert
{
#if defined(__cpp_concepts)
  /* The `ValueOrNone` concept.
  \requires That `U::value_type` exists and that `std::declval<U>().has_value()` returns a `bool` and `std::declval<U>().value()` exists.
  */


  template <class U> concept bool ValueOrNone = requires(U a)
  {
    {
      a.has_value()
    }
    ->bool;
    {a.value()};
  };
  /* The `ValueOrError` concept.
  \requires That `U::value_type` and `U::error_type` exist;
  that `std::declval<U>().has_value()` returns a `bool`, `std::declval<U>().value()` and  `std::declval<U>().error()` exists.
  */



  template <class U> concept bool ValueOrError = requires(U a)
  {
    {
      a.has_value()
    }
    ->bool;
    {a.value()};
    {a.error()};
  };
#else
  namespace detail
  {
    struct no_match
    {
    };
    inline no_match match_value_or_none(...);
    inline no_match match_value_or_error(...);
    OUTCOME_TEMPLATE(class U)
    OUTCOME_TREQUIRES(OUTCOME_TEXPR(std::declval<U>().has_value()), OUTCOME_TEXPR(std::declval<U>().value()))
    inline U match_value_or_none(U &&);
    OUTCOME_TEMPLATE(class U)
    OUTCOME_TREQUIRES(OUTCOME_TEXPR(std::declval<U>().has_value()), OUTCOME_TEXPR(std::declval<U>().value()), OUTCOME_TEXPR(std::declval<U>().error()))
    inline U match_value_or_error(U &&);

    template <class U> static constexpr bool ValueOrNone = !std::is_same<no_match, decltype(match_value_or_none(std::declval<OUTCOME_V2_NAMESPACE::detail::devoid<U>>()))>::value;
    template <class U> static constexpr bool ValueOrError = !std::is_same<no_match, decltype(match_value_or_error(std::declval<OUTCOME_V2_NAMESPACE::detail::devoid<U>>()))>::value;
  }  // namespace detail
  /* The `ValueOrNone` concept.
  \requires That `U::value_type` exists and that `std::declval<U>().has_value()` returns a `bool` and `std::declval<U>().value()` exists.
  */


  template <class U> static constexpr bool ValueOrNone = detail::ValueOrNone<U>;
  /* The `ValueOrError` concept.
  \requires That `U::value_type` and `U::error_type` exist;
  that `std::declval<U>().has_value()` returns a `bool`, `std::declval<U>().value()` and  `std::declval<U>().error()` exists.
  */



  template <class U> static constexpr bool ValueOrError = detail::ValueOrError<U>;
#endif

  namespace detail
  {
    template <class T, class X> struct make_type
    {
      template <class U> static constexpr T value(U &&v) { return T{in_place_type<typename T::value_type>, static_cast<U &&>(v).value()}; }
      template <class U> static constexpr T error(U &&v) { return T{in_place_type<typename T::error_type>, static_cast<U &&>(v).error()}; }
      static constexpr T error() { return T{in_place_type<typename T::error_type>}; }
    };
    template <class T> struct make_type<T, void>
    {
      template <class U> static constexpr T value(U && /*unused*/) { return T{in_place_type<typename T::value_type>}; }
      template <class U> static constexpr T error(U && /*unused*/) { return T{in_place_type<typename T::error_type>}; }
      static constexpr T error() { return T{in_place_type<typename T::error_type>}; }
    };
  }  // namespace detail

  /*! AWAITING HUGO JSON CONVERSION TOOL
type definition  value_or_error. Potential doc page: NOT FOUND
*/


  template <class T, class U> struct value_or_error
  {
    static constexpr bool enable_result_inputs = false;
    static constexpr bool enable_outcome_inputs = false;
    OUTCOME_TEMPLATE(class X)
    OUTCOME_TREQUIRES(OUTCOME_TPRED(std::is_same<U, std::decay_t<X>>::value                                                                                                                                                    //
                                    &&ValueOrError<U>                                                                                                                                                                          //
                                    && (std::is_void<typename std::decay_t<X>::value_type>::value || OUTCOME_V2_NAMESPACE::detail::is_explicitly_constructible<typename T::value_type, typename std::decay_t<X>::value_type>)  //
                                    &&(std::is_void<typename std::decay_t<X>::error_type>::value || OUTCOME_V2_NAMESPACE::detail::is_explicitly_constructible<typename T::error_type, typename std::decay_t<X>::error_type>) ))
    constexpr T operator()(X &&v) { return v.has_value() ? detail::make_type<T, typename T::value_type>::value(static_cast<X &&>(v)) : detail::make_type<T, typename U::error_type>::error(static_cast<X &&>(v)); }
  };
}  // namespace convert

OUTCOME_V2_NAMESPACE_END

#endif
/* Finaliser for a very simple result type
(C) 2017 Niall Douglas <http://www.nedproductions.biz/> (59 commits)
File Created: Oct 2017


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

#ifndef OUTCOME_BASIC_RESULT_FINAL_HPP
#define OUTCOME_BASIC_RESULT_FINAL_HPP
/* Error observers for a very simple basic_result type
(C) 2017 Niall Douglas <http://www.nedproductions.biz/> (59 commits)
File Created: Oct 2017


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

#ifndef OUTCOME_BASIC_RESULT_ERROR_OBSERVERS_HPP
#define OUTCOME_BASIC_RESULT_ERROR_OBSERVERS_HPP



OUTCOME_V2_NAMESPACE_EXPORT_BEGIN

namespace detail
{
  template <class Base, class EC, class NoValuePolicy> class basic_result_error_observers : public Base
  {
  public:
    using error_type = EC;
    using Base::Base;

    constexpr error_type &assume_error() & noexcept
    {
      NoValuePolicy::narrow_error_check(static_cast<basic_result_error_observers &>(*this));
      return this->_error;
    }
    constexpr const error_type &assume_error() const &noexcept
    {
      NoValuePolicy::narrow_error_check(static_cast<const basic_result_error_observers &>(*this));
      return this->_error;
    }
    constexpr error_type &&assume_error() && noexcept
    {
      NoValuePolicy::narrow_error_check(static_cast<basic_result_error_observers &&>(*this));
      return static_cast<error_type &&>(this->_error);
    }
    constexpr const error_type &&assume_error() const &&noexcept
    {
      NoValuePolicy::narrow_error_check(static_cast<const basic_result_error_observers &&>(*this));
      return static_cast<const error_type &&>(this->_error);
    }

    constexpr error_type &error() &
    {
      NoValuePolicy::wide_error_check(static_cast<basic_result_error_observers &>(*this));
      return this->_error;
    }
    constexpr const error_type &error() const &
    {
      NoValuePolicy::wide_error_check(static_cast<const basic_result_error_observers &>(*this));
      return this->_error;
    }
    constexpr error_type &&error() &&
    {
      NoValuePolicy::wide_error_check(static_cast<basic_result_error_observers &&>(*this));
      return static_cast<error_type &&>(this->_error);
    }
    constexpr const error_type &&error() const &&
    {
      NoValuePolicy::wide_error_check(static_cast<const basic_result_error_observers &&>(*this));
      return static_cast<const error_type &&>(this->_error);
    }
  };
  template <class Base, class NoValuePolicy> class basic_result_error_observers<Base, void, NoValuePolicy> : public Base
  {
  public:
    using Base::Base;
    constexpr void assume_error() const noexcept { NoValuePolicy::narrow_error_check(*this); }
    constexpr void error() const { NoValuePolicy::wide_error_check(*this); }
  };
}  // namespace detail
OUTCOME_V2_NAMESPACE_END

#endif
/* Value observers for a very simple basic_result type
(C) 2017 Niall Douglas <http://www.nedproductions.biz/> (59 commits)
File Created: Oct 2017


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

#ifndef OUTCOME_RESULT_VALUE_OBSERVERS_HPP
#define OUTCOME_RESULT_VALUE_OBSERVERS_HPP



OUTCOME_V2_NAMESPACE_EXPORT_BEGIN

namespace detail
{
  template <class Base, class R, class NoValuePolicy> class basic_result_value_observers : public Base
  {
  public:
    using value_type = R;
    using Base::Base;

    constexpr value_type &assume_value() & noexcept
    {
      NoValuePolicy::narrow_value_check(static_cast<basic_result_value_observers &>(*this));
      return this->_state._value;  // NOLINT
    }
    constexpr const value_type &assume_value() const &noexcept
    {
      NoValuePolicy::narrow_value_check(static_cast<const basic_result_value_observers &>(*this));
      return this->_state._value;  // NOLINT
    }
    constexpr value_type &&assume_value() && noexcept
    {
      NoValuePolicy::narrow_value_check(static_cast<basic_result_value_observers &&>(*this));
      return static_cast<value_type &&>(this->_state._value);  // NOLINT
    }
    constexpr const value_type &&assume_value() const &&noexcept
    {
      NoValuePolicy::narrow_value_check(static_cast<const basic_result_value_observers &&>(*this));
      return static_cast<const value_type &&>(this->_state._value);  // NOLINT
    }

    constexpr value_type &value() &
    {
      NoValuePolicy::wide_value_check(static_cast<basic_result_value_observers &>(*this));
      return this->_state._value;  // NOLINT
    }
    constexpr const value_type &value() const &
    {
      NoValuePolicy::wide_value_check(static_cast<const basic_result_value_observers &>(*this));
      return this->_state._value;  // NOLINT
    }
    constexpr value_type &&value() &&
    {
      NoValuePolicy::wide_value_check(static_cast<basic_result_value_observers &&>(*this));
      return static_cast<value_type &&>(this->_state._value);  // NOLINT
    }
    constexpr const value_type &&value() const &&
    {
      NoValuePolicy::wide_value_check(static_cast<const basic_result_value_observers &&>(*this));
      return static_cast<const value_type &&>(this->_state._value);  // NOLINT
    }
  };
  template <class Base, class NoValuePolicy> class basic_result_value_observers<Base, void, NoValuePolicy> : public Base
  {
  public:
    using Base::Base;

    constexpr void assume_value() const noexcept { NoValuePolicy::narrow_value_check(*this); }
    constexpr void value() const { NoValuePolicy::wide_value_check(*this); }
  };
}  // namespace detail

OUTCOME_V2_NAMESPACE_END

#endif
OUTCOME_V2_NAMESPACE_EXPORT_BEGIN

namespace detail
{
  template <class R, class EC, class NoValuePolicy> using select_basic_result_impl = basic_result_error_observers<basic_result_value_observers<basic_result_storage<R, EC, NoValuePolicy>, R, NoValuePolicy>, EC, NoValuePolicy>;

  template <class R, class S, class NoValuePolicy>
  class basic_result_final



  : public select_basic_result_impl<R, S, NoValuePolicy>

  {
    using base = select_basic_result_impl<R, S, NoValuePolicy>;

  public:
    using base::base;

    constexpr explicit operator bool() const noexcept { return (this->_state._status & detail::status_have_value) != 0; }
    constexpr bool has_value() const noexcept { return (this->_state._status & detail::status_have_value) != 0; }
    constexpr bool has_error() const noexcept { return (this->_state._status & detail::status_have_error) != 0; }
    constexpr bool has_exception() const noexcept { return (this->_state._status & detail::status_have_exception) != 0; }
    constexpr bool has_failure() const noexcept { return (this->_state._status & detail::status_have_error) != 0 || (this->_state._status & detail::status_have_exception) != 0; }

    OUTCOME_TEMPLATE(class T, class U, class V)
    OUTCOME_TREQUIRES(OUTCOME_TEXPR(std::declval<detail::devoid<R>>() == std::declval<detail::devoid<T>>()),  //
                      OUTCOME_TEXPR(std::declval<detail::devoid<S>>() == std::declval<detail::devoid<U>>()))
    constexpr bool operator==(const basic_result_final<T, U, V> &o) const noexcept(  //
    noexcept(std::declval<detail::devoid<R>>() == std::declval<detail::devoid<T>>()) && noexcept(std::declval<detail::devoid<S>>() == std::declval<detail::devoid<U>>()))
    {
      if((this->_state._status & detail::status_have_value) != 0 && (o._state._status & detail::status_have_value) != 0)
      {
        return this->_state._value == o._state._value;  // NOLINT
      }
      if((this->_state._status & detail::status_have_error) != 0 && (o._state._status & detail::status_have_error) != 0)
      {
        return this->_error == o._error;
      }
      return false;
    }
    OUTCOME_TEMPLATE(class T)
    OUTCOME_TREQUIRES(OUTCOME_TEXPR(std::declval<R>() == std::declval<T>()))
    constexpr bool operator==(const success_type<T> &o) const noexcept(  //
    noexcept(std::declval<R>() == std::declval<T>()))
    {
      if((this->_state._status & detail::status_have_value) != 0)
      {
        return this->_state._value == o.value();
      }
      return false;
    }
    constexpr bool operator==(const success_type<void> &o) const noexcept
    {
      (void) o;
      return (this->_state._status & detail::status_have_value) != 0;
    }
    OUTCOME_TEMPLATE(class T)
    OUTCOME_TREQUIRES(OUTCOME_TEXPR(std::declval<S>() == std::declval<T>()))
    constexpr bool operator==(const failure_type<T, void> &o) const noexcept(  //
    noexcept(std::declval<S>() == std::declval<T>()))
    {
      if((this->_state._status & detail::status_have_error) != 0)
      {
        return this->_error == o.error();
      }
      return false;
    }
    OUTCOME_TEMPLATE(class T, class U, class V)
    OUTCOME_TREQUIRES(OUTCOME_TEXPR(std::declval<detail::devoid<R>>() != std::declval<detail::devoid<T>>()),  //
                      OUTCOME_TEXPR(std::declval<detail::devoid<S>>() != std::declval<detail::devoid<U>>()))
    constexpr bool operator!=(const basic_result_final<T, U, V> &o) const noexcept(  //
    noexcept(std::declval<detail::devoid<R>>() != std::declval<detail::devoid<T>>()) && noexcept(std::declval<detail::devoid<S>>() != std::declval<detail::devoid<U>>()))
    {
      if((this->_state._status & detail::status_have_value) != 0 && (o._state._status & detail::status_have_value) != 0)
      {
        return this->_state._value != o._state._value;
      }
      if((this->_state._status & detail::status_have_error) != 0 && (o._state._status & detail::status_have_error) != 0)
      {
        return this->_error != o._error;
      }
      return true;
    }
    OUTCOME_TEMPLATE(class T)
    OUTCOME_TREQUIRES(OUTCOME_TEXPR(std::declval<R>() != std::declval<T>()))
    constexpr bool operator!=(const success_type<T> &o) const noexcept(  //
    noexcept(std::declval<R>() != std::declval<T>()))
    {
      if((this->_state._status & detail::status_have_value) != 0)
      {
        return this->_state._value != o.value();
      }
      return false;
    }
    constexpr bool operator!=(const success_type<void> &o) const noexcept
    {
      (void) o;
      return (this->_state._status & detail::status_have_value) == 0;
    }
    OUTCOME_TEMPLATE(class T)
    OUTCOME_TREQUIRES(OUTCOME_TEXPR(std::declval<S>() != std::declval<T>()))
    constexpr bool operator!=(const failure_type<T, void> &o) const noexcept(  //
    noexcept(std::declval<S>() != std::declval<T>()))
    {
      if((this->_state._status & detail::status_have_error) != 0)
      {
        return this->_error != o.error();
      }
      return true;
    }
  };
  template <class T, class U, class V, class W> constexpr inline bool operator==(const success_type<W> &a, const basic_result_final<T, U, V> &b) noexcept(noexcept(b == a)) { return b == a; }
  template <class T, class U, class V, class W> constexpr inline bool operator==(const failure_type<W, void> &a, const basic_result_final<T, U, V> &b) noexcept(noexcept(b == a)) { return b == a; }
  template <class T, class U, class V, class W> constexpr inline bool operator!=(const success_type<W> &a, const basic_result_final<T, U, V> &b) noexcept(noexcept(b == a)) { return b != a; }
  template <class T, class U, class V, class W> constexpr inline bool operator!=(const failure_type<W, void> &a, const basic_result_final<T, U, V> &b) noexcept(noexcept(b == a)) { return b != a; }
}  // namespace detail

OUTCOME_V2_NAMESPACE_END

#endif
/* Policies for result and outcome
(C) 2017 Niall Douglas <http://www.nedproductions.biz/> (59 commits)
File Created: Oct 2017


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

#ifndef OUTCOME_POLICY_ALL_NARROW_HPP
#define OUTCOME_POLICY_ALL_NARROW_HPP
/* Policies for result and outcome
(C) 2017 Niall Douglas <http://www.nedproductions.biz/> (59 commits)
File Created: Oct 2017


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

#ifndef OUTCOME_POLICY_BASE_HPP
#define OUTCOME_POLICY_BASE_HPP



#include <cassert>

OUTCOME_V2_NAMESPACE_EXPORT_BEGIN

namespace policy
{
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  struct base
  {
  protected:
    template <class Impl>
    static constexpr
#ifdef _MSC_VER
    __declspec(noreturn)
#elif defined(__GNUC__) || defined(__clang__)
        __attribute__((noreturn))
#endif
    void _ub(Impl && /*unused*/)
    {
      assert(false);  // NOLINT
#if defined(__GNUC__) || defined(__clang__)
      __builtin_unreachable();
#elif defined(_MSC_VER)
      __assume(0);
#endif
    }

    template <class Impl> static constexpr bool _has_value(Impl &&self) noexcept { return (self._state._status & OUTCOME_V2_NAMESPACE::detail::status_have_value) != 0; }
    template <class Impl> static constexpr bool _has_error(Impl &&self) noexcept { return (self._state._status & OUTCOME_V2_NAMESPACE::detail::status_have_error) != 0; }
    template <class Impl> static constexpr bool _has_exception(Impl &&self) noexcept { return (self._state._status & OUTCOME_V2_NAMESPACE::detail::status_have_exception) != 0; }
    template <class Impl> static constexpr bool _has_error_is_errno(Impl &&self) noexcept { return (self._state._status & OUTCOME_V2_NAMESPACE::detail::status_error_is_errno) != 0; }

    template <class Impl> static constexpr void _set_has_value(Impl &&self, bool v) noexcept { v ? self._state._status |= OUTCOME_V2_NAMESPACE::detail::status_have_value : self._state._status &= ~OUTCOME_V2_NAMESPACE::detail::status_have_value; }
    template <class Impl> static constexpr void _set_has_error(Impl &&self, bool v) noexcept { v ? self._state._status |= OUTCOME_V2_NAMESPACE::detail::status_have_error : self._state._status &= ~OUTCOME_V2_NAMESPACE::detail::status_have_error; }
    template <class Impl> static constexpr void _set_has_exception(Impl &&self, bool v) noexcept { v ? self._state._status |= OUTCOME_V2_NAMESPACE::detail::status_have_exception : self._state._status &= ~OUTCOME_V2_NAMESPACE::detail::status_have_exception; }
    template <class Impl> static constexpr void _set_has_error_is_errno(Impl &&self, bool v) noexcept { v ? self._state._status |= OUTCOME_V2_NAMESPACE::detail::status_error_is_errno : self._state._status &= ~OUTCOME_V2_NAMESPACE::detail::status_error_is_errno; }

    template <class Impl> static constexpr auto &&_value(Impl &&self) noexcept { return static_cast<Impl &&>(self)._state._value; }
    template <class Impl> static constexpr auto &&_error(Impl &&self) noexcept { return static_cast<Impl &&>(self)._error; }

  public:
    template <class R, class S, class P, class NoValuePolicy, class Impl> static inline constexpr auto &&_exception(Impl &&self) noexcept;

    template <class Impl> static constexpr void narrow_value_check(Impl &&self) noexcept
    {
      if(!_has_value(self))
      {
        _ub(self);
      }
    }
    template <class Impl> static constexpr void narrow_error_check(Impl &&self) noexcept
    {
      if(!_has_error(self))
      {
        _ub(self);
      }
    }
    template <class Impl> static constexpr void narrow_exception_check(Impl &&self) noexcept
    {
      if(!_has_exception(self))
      {
        _ub(self);
      }
    }
  };
}  // namespace policy

OUTCOME_V2_NAMESPACE_END

#endif
OUTCOME_V2_NAMESPACE_EXPORT_BEGIN

namespace policy
{
  /*! AWAITING HUGO JSON CONVERSION TOOL
type definition  all_narrow. Potential doc page: `all_narrow`
*/


  struct all_narrow : base
  {
    template <class Impl> static constexpr void wide_value_check(Impl &&self) { base::narrow_value_check(static_cast<Impl &&>(self)); }
    template <class Impl> static constexpr void wide_error_check(Impl &&self) { base::narrow_error_check(static_cast<Impl &&>(self)); }
    template <class Impl> static constexpr void wide_exception_check(Impl &&self) { base::narrow_exception_check(static_cast<Impl &&>(self)); }
  };
}  // namespace policy

OUTCOME_V2_NAMESPACE_END

#endif
/* Policies for result and outcome
(C) 2017 Niall Douglas <http://www.nedproductions.biz/> (59 commits)
File Created: Oct 2017


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

#ifndef OUTCOME_POLICY_TERMINATE_HPP
#define OUTCOME_POLICY_TERMINATE_HPP



#include <cstdlib>

OUTCOME_V2_NAMESPACE_EXPORT_BEGIN

namespace policy
{
  /*! AWAITING HUGO JSON CONVERSION TOOL
type definition  terminate. Potential doc page: `terminate`
*/


  struct terminate : base
  {
    template <class Impl> static constexpr void wide_value_check(Impl &&self)
    {
      if(!base::_has_value(static_cast<Impl &&>(self)))
      {
        std::abort();
      }
    }
    template <class Impl> static constexpr void wide_error_check(Impl &&self) noexcept
    {
      if(!base::_has_error(static_cast<Impl &&>(self)))
      {
        std::abort();
      }
    }
    template <class Impl> static constexpr void wide_exception_check(Impl &&self)
    {
      if(!base::_has_exception(static_cast<Impl &&>(self)))
      {
        std::abort();
      }
    }
  };
}  // namespace policy

OUTCOME_V2_NAMESPACE_END

#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"  // Standardese markup confuses clang
#endif

OUTCOME_V2_NAMESPACE_EXPORT_BEGIN

template <class R, class S, class NoValuePolicy>                                                                                                                                  //
#if !defined(__GNUC__) || __GNUC__ >= 8                                                                                                                                           // GCC's constraints implementation is buggy
OUTCOME_REQUIRES(trait::type_can_be_used_in_basic_result<R> &&trait::type_can_be_used_in_basic_result<S> && (std::is_void<S>::value || std::is_default_constructible<S>::value))  //
#endif
class basic_result;

namespace detail
{
  // These are reused by basic_outcome to save load on the compiler
  template <class value_type, class error_type> struct result_predicates
  {
    // Predicate for the implicit constructors to be available
    static constexpr bool implicit_constructors_enabled =                                                                               //
    !(trait::is_error_type<std::decay_t<value_type>>::value && trait::is_error_type<std::decay_t<error_type>>::value)                   // both value and error types are not whitelisted error types
    && ((!detail::is_implicitly_constructible<value_type, error_type> && !detail::is_implicitly_constructible<error_type, value_type>)  // if value and error types cannot be constructed into one another
        || (trait::is_error_type<std::decay_t<error_type>>::value                                                                       // if error type is a whitelisted error type
            && !detail::is_implicitly_constructible<error_type, value_type>                                                             // AND which cannot be constructed from the value type
            && std::is_integral<value_type>::value));                                                                                   // AND the value type is some integral type

    // Predicate for the value converting constructor to be available. Weakened to allow result<int, C enum>.
    template <class T>
    static constexpr bool enable_value_converting_constructor =                                                      //
    implicit_constructors_enabled                                                                                    //
    && !is_in_place_type_t<std::decay_t<T>>::value                                                                   // not in place construction
    && !trait::is_error_type_enum<error_type, std::decay_t<T>>::value                                                // not an enum valid for my error type
    && ((detail::is_implicitly_constructible<value_type, T> && !detail::is_implicitly_constructible<error_type, T>)  // is unambiguously for value type
        || (std::is_same<value_type, std::decay_t<T>>::value                                                         // OR is my value type exactly
            && detail::is_implicitly_constructible<value_type, T>) );                                                // and my value type is constructible from this ref form of T


    // Predicate for the error converting constructor to be available. Weakened to allow result<int, C enum>.
    template <class T>
    static constexpr bool enable_error_converting_constructor =                                                      //
    implicit_constructors_enabled                                                                                    //
    && !is_in_place_type_t<std::decay_t<T>>::value                                                                   // not in place construction
    && !trait::is_error_type_enum<error_type, std::decay_t<T>>::value                                                // not an enum valid for my error type
    && ((!detail::is_implicitly_constructible<value_type, T> && detail::is_implicitly_constructible<error_type, T>)  // is unambiguously for error type
        || (std::is_same<error_type, std::decay_t<T>>::value                                                         // OR is my error type exactly
            && detail::is_implicitly_constructible<error_type, T>) );                                                // and my error type is constructible from this ref form of T

    // Predicate for the error condition converting constructor to be available.
    template <class ErrorCondEnum>
    static constexpr bool enable_error_condition_converting_constructor =                                                                       //
    !is_in_place_type_t<std::decay_t<ErrorCondEnum>>::value                                                                                     // not in place construction
    && trait::is_error_type_enum<error_type, std::decay_t<ErrorCondEnum>>::value                                                                // is an error condition enum
    /*&& !detail::is_implicitly_constructible<value_type, ErrorCondEnum> && !detail::is_implicitly_constructible<error_type, ErrorCondEnum>*/;  // not constructible via any other means

    // Predicate for the converting copy constructor from a compatible input to be available.
    template <class T, class U, class V>
    static constexpr bool enable_compatible_conversion =                                                                       //
    (std::is_void<T>::value || detail::is_explicitly_constructible<value_type, typename basic_result<T, U, V>::value_type>)    // if our value types are constructible
    &&(std::is_void<U>::value || detail::is_explicitly_constructible<error_type, typename basic_result<T, U, V>::error_type>)  // if our error types are constructible
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
    template <class... Args>
    static constexpr bool enable_inplace_value_error_constructor = implicit_constructors_enabled  //
                                                                   && !std::is_same<choose_inplace_value_error_constructor<Args...>, disable_inplace_value_error_constructor>::value;
  };

  template <class T, class U> constexpr inline const U &extract_value_from_success(const success_type<U> &v) { return v.value(); }
  template <class T, class U> constexpr inline U &&extract_value_from_success(success_type<U> &&v) { return static_cast<success_type<U> &&>(v).value(); }
  template <class T> constexpr inline T extract_value_from_success(const success_type<void> & /*unused*/) { return T{}; }

  template <class T, class U, class V> constexpr inline const U &extract_error_from_failure(const failure_type<U, V> &v) { return v.error(); }
  template <class T, class U, class V> constexpr inline U &&extract_error_from_failure(failure_type<U, V> &&v) { return static_cast<failure_type<U, V> &&>(v).error(); }
  template <class T, class V> constexpr inline T extract_error_from_failure(const failure_type<void, V> & /*unused*/) { return T{}; }

  template <class T> struct is_basic_result
  {
    static constexpr bool value = false;
  };
  template <class R, class S, class T> struct is_basic_result<basic_result<R, S, T>>
  {
    static constexpr bool value = true;
  };
}  // namespace detail

/*! AWAITING HUGO JSON CONVERSION TOOL
type alias template <class T> is_basic_result. Potential doc page: `is_basic_result<T>`
*/
template <class T> using is_basic_result = detail::is_basic_result<std::decay_t<T>>;
/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
template <class T> static constexpr bool is_basic_result_v = detail::is_basic_result<std::decay_t<T>>::value;

/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
namespace hooks
{
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  template <class T, class U> constexpr inline void hook_result_construction(T * /*unused*/, U && /*unused*/) noexcept {}
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  template <class T, class U> constexpr inline void hook_result_copy_construction(T * /*unused*/, U && /*unused*/) noexcept {}
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  template <class T, class U> constexpr inline void hook_result_move_construction(T * /*unused*/, U && /*unused*/) noexcept {}
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  template <class T, class U, class... Args> constexpr inline void hook_result_in_place_construction(T * /*unused*/, in_place_type_t<U> /*unused*/, Args &&... /*unused*/) noexcept {}

  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  template <class R, class S, class NoValuePolicy> constexpr inline uint16_t spare_storage(const detail::basic_result_final<R, S, NoValuePolicy> *r) noexcept { return (r->_state._status >> detail::status_2byte_shift) & 0xffff; }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  template <class R, class S, class NoValuePolicy> constexpr inline void set_spare_storage(detail::basic_result_final<R, S, NoValuePolicy> *r, uint16_t v) noexcept { r->_state._status |= (v << detail::status_2byte_shift); }
}  // namespace hooks

/*! AWAITING HUGO JSON CONVERSION TOOL
type definition template <class R, class S, class NoValuePolicy> basic_result. Potential doc page: `basic_result<T, E, NoValuePolicy>`
*/
template <class R, class S, class NoValuePolicy>                                                                                                                                  //
#if !defined(__GNUC__) || __GNUC__ >= 8                                                                                                                                           // GCC's constraints implementation is buggy
OUTCOME_REQUIRES(trait::type_can_be_used_in_basic_result<R> &&trait::type_can_be_used_in_basic_result<S> && (std::is_void<S>::value || std::is_default_constructible<S>::value))  //
#endif
class OUTCOME_NODISCARD basic_result : public detail::basic_result_final<R, S, NoValuePolicy>
{
  static_assert(trait::type_can_be_used_in_basic_result<R>, "The type R cannot be used in a basic_result");
  static_assert(trait::type_can_be_used_in_basic_result<S>, "The type S cannot be used in a basic_result");
  static_assert(std::is_void<S>::value || std::is_default_constructible<S>::value, "The type S must be void or default constructible");

  using base = detail::basic_result_final<R, S, NoValuePolicy>;

  struct implicit_constructors_disabled_tag
  {
  };
  struct value_converting_constructor_tag
  {
  };
  struct error_converting_constructor_tag
  {
  };
  struct error_condition_converting_constructor_tag
  {
  };
  struct explicit_valueornone_converting_constructor_tag
  {
  };
  struct explicit_valueorerror_converting_constructor_tag
  {
  };

public:
  using value_type = R;
  using error_type = S;

  using value_type_if_enabled = typename base::_value_type;
  using error_type_if_enabled = typename base::_error_type;

  template <class T, class U = S, class V = NoValuePolicy> using rebind = basic_result<T, U, V>;

protected:
  // Requirement predicates for result.
  struct predicate
  {
    using base = detail::result_predicates<value_type, error_type>;

    // Predicate for any constructors to be available at all
    static constexpr bool constructors_enabled = !std::is_same<std::decay_t<value_type>, std::decay_t<error_type>>::value;

    // Predicate for implicit constructors to be available at all
    static constexpr bool implicit_constructors_enabled = constructors_enabled && base::implicit_constructors_enabled;

    // Predicate for the value converting constructor to be available.
    template <class T>
    static constexpr bool enable_value_converting_constructor =  //
    constructors_enabled                                         //
    && !std::is_same<std::decay_t<T>, basic_result>::value       // not my type
    && base::template enable_value_converting_constructor<T>;

    // Predicate for the error converting constructor to be available.
    template <class T>
    static constexpr bool enable_error_converting_constructor =  //
    constructors_enabled                                         //
    && !std::is_same<std::decay_t<T>, basic_result>::value       // not my type
    && base::template enable_error_converting_constructor<T>;

    // Predicate for the error condition converting constructor to be available.
    template <class ErrorCondEnum>
    static constexpr bool enable_error_condition_converting_constructor =  //
    constructors_enabled                                                   //
    && !std::is_same<std::decay_t<ErrorCondEnum>, basic_result>::value     // not my type
    && base::template enable_error_condition_converting_constructor<ErrorCondEnum>;

    // Predicate for the converting copy constructor from a compatible input to be available.
    template <class T, class U, class V>
    static constexpr bool enable_compatible_conversion =          //
    constructors_enabled                                          //
    && !std::is_same<basic_result<T, U, V>, basic_result>::value  // not my type
    && base::template enable_compatible_conversion<T, U, V>;

    // Predicate for the inplace construction of value to be available.
    template <class... Args>
    static constexpr bool enable_inplace_value_constructor =  //
    constructors_enabled                                      //
    && (std::is_void<value_type>::value                       //
        || std::is_constructible<value_type, Args...>::value);

    // Predicate for the inplace construction of error to be available.
    template <class... Args>
    static constexpr bool enable_inplace_error_constructor =  //
    constructors_enabled                                      //
    && (std::is_void<error_type>::value                       //
        || std::is_constructible<error_type, Args...>::value);

    // Predicate for the implicit converting inplace constructor to be available.
    template <class... Args>
    static constexpr bool enable_inplace_value_error_constructor =  //
    constructors_enabled                                            //
    &&base::template enable_inplace_value_error_constructor<Args...>;
    template <class... Args> using choose_inplace_value_error_constructor = typename base::template choose_inplace_value_error_constructor<Args...>;
  };

public:
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  basic_result() = delete;
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  basic_result(basic_result && /*unused*/) = default;  // NOLINT
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  basic_result(const basic_result & /*unused*/) = default;
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  basic_result &operator=(basic_result && /*unused*/) = default;  // NOLINT
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  basic_result &operator=(const basic_result & /*unused*/) = default;
  ~basic_result() = default;

  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  OUTCOME_TEMPLATE(class Arg, class... Args)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(!predicate::constructors_enabled && (sizeof...(Args) >= 0)))
  basic_result(Arg && /*unused*/, Args &&... /*unused*/) = delete;  // NOLINT basic_result<T, T> is NOT SUPPORTED, see docs!

  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED((predicate::constructors_enabled && !predicate::implicit_constructors_enabled  //
                                   && (detail::is_implicitly_constructible<value_type, T> || detail::is_implicitly_constructible<error_type, T>) )))
  basic_result(T && /*unused*/, implicit_constructors_disabled_tag /*unused*/ = implicit_constructors_disabled_tag()) = delete;  // NOLINT Implicit constructors disabled, use explicit in_place_type<T>, success() or failure(). see docs!

  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_value_converting_constructor<T>))
  constexpr basic_result(T &&t, value_converting_constructor_tag /*unused*/ = value_converting_constructor_tag()) noexcept(std::is_nothrow_constructible<value_type, T>::value)  // NOLINT
  : base{in_place_type<typename base::value_type>, static_cast<T &&>(t)}
  {
    using namespace hooks;
    hook_result_construction(this, static_cast<T &&>(t));
  }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_error_converting_constructor<T>))
  constexpr basic_result(T &&t, error_converting_constructor_tag /*unused*/ = error_converting_constructor_tag()) noexcept(std::is_nothrow_constructible<error_type, T>::value)  // NOLINT
  : base{in_place_type<typename base::error_type>, static_cast<T &&>(t)}
  {
    using namespace hooks;
    hook_result_construction(this, static_cast<T &&>(t));
  }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  OUTCOME_TEMPLATE(class ErrorCondEnum)
  OUTCOME_TREQUIRES(OUTCOME_TEXPR(error_type(make_error_code(ErrorCondEnum()))),  //
                    OUTCOME_TPRED(predicate::template enable_error_condition_converting_constructor<ErrorCondEnum>))
  constexpr basic_result(ErrorCondEnum &&t, error_condition_converting_constructor_tag /*unused*/ = error_condition_converting_constructor_tag()) noexcept(noexcept(error_type(make_error_code(static_cast<ErrorCondEnum &&>(t)))))  // NOLINT
  : base{in_place_type<typename base::error_type>, make_error_code(t)}
  {
    using namespace hooks;
    hook_result_construction(this, static_cast<ErrorCondEnum &&>(t));
  }

  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(convert::value_or_error<basic_result, std::decay_t<T>>::enable_result_inputs || !is_basic_result_v<T>),  //
                    OUTCOME_TEXPR(convert::value_or_error<basic_result, std::decay_t<T>>{}(std::declval<T>())))
  constexpr explicit basic_result(T &&o, explicit_valueorerror_converting_constructor_tag /*unused*/ = explicit_valueorerror_converting_constructor_tag())  // NOLINT
  : basic_result{convert::value_or_error<basic_result, std::decay_t<T>>{}(static_cast<T &&>(o))}
  {
  }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  OUTCOME_TEMPLATE(class T, class U, class V)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_compatible_conversion<T, U, V>))
  constexpr explicit basic_result(const basic_result<T, U, V> &o) noexcept(std::is_nothrow_constructible<value_type, T>::value &&std::is_nothrow_constructible<error_type, U>::value)
      : base{typename base::compatible_conversion_tag(), o}
  {
    using namespace hooks;
    hook_result_copy_construction(this, o);
  }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  OUTCOME_TEMPLATE(class T, class U, class V)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_compatible_conversion<T, U, V>))
  constexpr explicit basic_result(basic_result<T, U, V> &&o) noexcept(std::is_nothrow_constructible<value_type, T>::value &&std::is_nothrow_constructible<error_type, U>::value)
      : base{typename base::compatible_conversion_tag(), static_cast<basic_result<T, U, V> &&>(o)}
  {
    using namespace hooks;
    hook_result_move_construction(this, static_cast<basic_result<T, U, V> &&>(o));
  }

  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  OUTCOME_TEMPLATE(class... Args)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_inplace_value_constructor<Args...>))
  constexpr explicit basic_result(in_place_type_t<value_type_if_enabled> _, Args &&... args) noexcept(std::is_nothrow_constructible<value_type, Args...>::value)
      : base{_, static_cast<Args &&>(args)...}
  {
    using namespace hooks;
    hook_result_in_place_construction(this, in_place_type<value_type>, static_cast<Args &&>(args)...);
  }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  OUTCOME_TEMPLATE(class U, class... Args)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_inplace_value_constructor<std::initializer_list<U>, Args...>))
  constexpr explicit basic_result(in_place_type_t<value_type_if_enabled> _, std::initializer_list<U> il, Args &&... args) noexcept(std::is_nothrow_constructible<value_type, std::initializer_list<U>, Args...>::value)
      : base{_, il, static_cast<Args &&>(args)...}
  {
    using namespace hooks;
    hook_result_in_place_construction(this, in_place_type<value_type>, il, static_cast<Args &&>(args)...);
  }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  OUTCOME_TEMPLATE(class... Args)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_inplace_error_constructor<Args...>))
  constexpr explicit basic_result(in_place_type_t<error_type_if_enabled> _, Args &&... args) noexcept(std::is_nothrow_constructible<error_type, Args...>::value)
      : base{_, static_cast<Args &&>(args)...}
  {
    using namespace hooks;
    hook_result_in_place_construction(this, in_place_type<error_type>, static_cast<Args &&>(args)...);
  }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  OUTCOME_TEMPLATE(class U, class... Args)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_inplace_error_constructor<std::initializer_list<U>, Args...>))
  constexpr explicit basic_result(in_place_type_t<error_type_if_enabled> _, std::initializer_list<U> il, Args &&... args) noexcept(std::is_nothrow_constructible<error_type, std::initializer_list<U>, Args...>::value)
      : base{_, il, static_cast<Args &&>(args)...}
  {
    using namespace hooks;
    hook_result_in_place_construction(this, in_place_type<error_type>, il, static_cast<Args &&>(args)...);
  }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  OUTCOME_TEMPLATE(class A1, class A2, class... Args)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_inplace_value_error_constructor<A1, A2, Args...>))
  constexpr basic_result(A1 &&a1, A2 &&a2, Args &&... args) noexcept(noexcept(typename predicate::template choose_inplace_value_error_constructor<A1, A2, Args...>(std::declval<A1>(), std::declval<A2>(), std::declval<Args>()...)))
      : basic_result(in_place_type<typename predicate::template choose_inplace_value_error_constructor<A1, A2, Args...>>, static_cast<A1 &&>(a1), static_cast<A2 &&>(a2), static_cast<Args &&>(args)...)
  {
    /* I was a little surprised that the below is needed given that we forward to another constructor.
    But it turns out that ADL only fires on the first constructor for some reason.
    */


    using namespace hooks;
    // hook_result_in_place_construction(in_place_type<typename predicate::template choose_inplace_value_error_constructor<A1, A2, Args...>>, this);
  }

  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  constexpr basic_result(const success_type<void> &o) noexcept(std::is_nothrow_default_constructible<value_type>::value)  // NOLINT
  : base{in_place_type<value_type_if_enabled>}
  {
    using namespace hooks;
    hook_result_copy_construction(this, o);
  }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_compatible_conversion<T, void, void>))
  constexpr basic_result(const success_type<T> &o) noexcept(std::is_nothrow_constructible<value_type, T>::value)  // NOLINT
  : base{in_place_type<value_type_if_enabled>, detail::extract_value_from_success<value_type>(o)}
  {
    using namespace hooks;
    hook_result_copy_construction(this, o);
  }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(!std::is_void<T>::value && predicate::template enable_compatible_conversion<T, void, void>))
  constexpr basic_result(success_type<T> &&o) noexcept(std::is_nothrow_constructible<value_type, T>::value)  // NOLINT
  : base{in_place_type<value_type_if_enabled>, detail::extract_value_from_success<value_type>(static_cast<success_type<T> &&>(o))}
  {
    using namespace hooks;
    hook_result_move_construction(this, static_cast<success_type<T> &&>(o));
  }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_compatible_conversion<void, T, void>))
  constexpr basic_result(const failure_type<T> &o) noexcept(std::is_nothrow_constructible<error_type, T>::value)  // NOLINT
  : base{in_place_type<error_type_if_enabled>, detail::extract_error_from_failure<error_type>(o)}
  {
    using namespace hooks;
    hook_result_copy_construction(this, o);
  }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_compatible_conversion<void, T, void>))
  constexpr basic_result(failure_type<T> &&o) noexcept(std::is_nothrow_constructible<error_type, T>::value)  // NOLINT
  : base{in_place_type<error_type_if_enabled>, detail::extract_error_from_failure<error_type>(static_cast<failure_type<T> &&>(o))}
  {
    using namespace hooks;
    hook_result_move_construction(this, static_cast<failure_type<T> &&>(o));
  }

  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  constexpr void swap(basic_result &o) noexcept(detail::is_nothrow_swappable<value_type>::value &&std::is_nothrow_move_constructible<value_type>::value  //
                                                &&detail::is_nothrow_swappable<error_type>::value &&std::is_nothrow_move_constructible<error_type>::value)
  {
    using std::swap;
    constexpr bool value_throws = !noexcept(this->_state.swap(o._state));
    constexpr bool error_throws = !noexcept(swap(this->_error, o._error));
    detail::basic_result_storage_swap<value_throws, error_throws>(*this, o);
  }

  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  auto as_failure() const & { return failure(this->assume_error()); }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  auto as_failure() && { return failure(static_cast<basic_result &&>(*this).assume_error()); }
};

/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
template <class R, class S, class P> inline void swap(basic_result<R, S, P> &a, basic_result<R, S, P> &b) noexcept(noexcept(a.swap(b)))
{
  a.swap(b);
}

#if !defined(NDEBUG)
// Check is trivial in all ways except default constructibility
// static_assert(std::is_trivial<basic_result<int, long, policy::all_narrow>>::value, "result<int> is not trivial!");
// static_assert(std::is_trivially_default_constructible<basic_result<int, long, policy::all_narrow>>::value, "result<int> is not trivially default constructible!");
static_assert(std::is_trivially_copyable<basic_result<int, long, policy::all_narrow>>::value, "result<int> is not trivially copyable!");
static_assert(std::is_trivially_assignable<basic_result<int, long, policy::all_narrow>, basic_result<int, long, policy::all_narrow>>::value, "result<int> is not trivially assignable!");
static_assert(std::is_trivially_destructible<basic_result<int, long, policy::all_narrow>>::value, "result<int> is not trivially destructible!");
static_assert(std::is_trivially_copy_constructible<basic_result<int, long, policy::all_narrow>>::value, "result<int> is not trivially copy constructible!");
static_assert(std::is_trivially_move_constructible<basic_result<int, long, policy::all_narrow>>::value, "result<int> is not trivially move constructible!");
static_assert(std::is_trivially_copy_assignable<basic_result<int, long, policy::all_narrow>>::value, "result<int> is not trivially copy assignable!");
static_assert(std::is_trivially_move_assignable<basic_result<int, long, policy::all_narrow>>::value, "result<int> is not trivially move assignable!");
// Also check is standard layout
static_assert(std::is_standard_layout<basic_result<int, long, policy::all_narrow>>::value, "result<int> is not a standard layout type!");
#endif

OUTCOME_V2_NAMESPACE_END

#ifdef __clang__
#pragma clang diagnostic pop
#endif

#endif
/* Exception observers for outcome type
(C) 2017 Niall Douglas <http://www.nedproductions.biz/> (59 commits)
File Created: Oct 2017


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

#ifndef OUTCOME_BASIC_OUTCOME_EXCEPTION_OBSERVERS_HPP
#define OUTCOME_BASIC_OUTCOME_EXCEPTION_OBSERVERS_HPP



OUTCOME_V2_NAMESPACE_EXPORT_BEGIN

namespace detail
{
  template <class Base, class R, class S, class P, class NoValuePolicy> class basic_outcome_exception_observers : public Base
  {
  public:
    using exception_type = P;
    using Base::Base;

    constexpr inline exception_type &assume_exception() & noexcept;
    constexpr inline const exception_type &assume_exception() const &noexcept;
    constexpr inline exception_type &&assume_exception() && noexcept;
    constexpr inline const exception_type &&assume_exception() const &&noexcept;

    constexpr inline exception_type &exception() &;
    constexpr inline const exception_type &exception() const &;
    constexpr inline exception_type &&exception() &&;
    constexpr inline const exception_type &&exception() const &&;
  };

  // Exception observers not present
  template <class Base, class R, class S, class NoValuePolicy> class basic_outcome_exception_observers<Base, R, S, void, NoValuePolicy> : public Base
  {
  public:
    using Base::Base;
    constexpr void assume_exception() const noexcept { NoValuePolicy::narrow_exception_check(this); }
    constexpr void exception() const { NoValuePolicy::wide_exception_check(this); }
  };

}  // namespace detail

OUTCOME_V2_NAMESPACE_END

#endif
/* Failure observers for outcome type
(C) 2017 Niall Douglas <http://www.nedproductions.biz/> (59 commits)
File Created: Oct 2017


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

#ifndef OUTCOME_BASIC_OUTCOME_FAILURE_OBSERVERS_HPP
#define OUTCOME_BASIC_OUTCOME_FAILURE_OBSERVERS_HPP



OUTCOME_V2_NAMESPACE_EXPORT_BEGIN

namespace detail
{
  namespace adl
  {
    struct search_detail_adl
    {
    };
    OUTCOME_TEMPLATE(class S)                                                                        //
    OUTCOME_TREQUIRES(OUTCOME_TEXPR(basic_outcome_failure_exception_from_error(std::declval<S>())))  //
    inline auto _delayed_lookup_basic_outcome_failure_exception_from_error(const S &ec, search_detail_adl /*unused*/)
    {
      // ADL discovered
      return basic_outcome_failure_exception_from_error(ec);
    }
  }                                        // namespace adl
#if defined(_MSC_VER) && _MSC_VER <= 1920  // VS2019
  // VS2017 and VS2019 with /permissive- chokes on the correct form due to over eager early instantiation.
  template <class S, class P> inline void _delayed_lookup_basic_outcome_failure_exception_from_error(...) { static_assert(sizeof(S) == 0, "No specialisation for these error and exception types available!"); }
#else
  template <class S, class P> inline void _delayed_lookup_basic_outcome_failure_exception_from_error(...) = delete;  // NOLINT No specialisation for these error and exception types available!
#endif

  template <class exception_type> inline exception_type current_exception_or_fatal(std::exception_ptr e) { std::rethrow_exception(e); }
  template <> inline std::exception_ptr current_exception_or_fatal<std::exception_ptr>(std::exception_ptr e) { return e; }

  template <class Base, class R, class S, class P, class NoValuePolicy> class basic_outcome_failure_observers : public Base
  {
  public:
    using exception_type = P;
    using Base::Base;

    exception_type failure() const noexcept
    {
#ifdef __cpp_exceptions
      try
#endif
      {
        if((this->_state._status & detail::status_have_exception) != 0)
        {
          return this->assume_exception();
        }
        if((this->_state._status & detail::status_have_error) != 0)
        {
          return _delayed_lookup_basic_outcome_failure_exception_from_error(this->assume_error(), adl::search_detail_adl());
        }
        return exception_type();
      }
#ifdef __cpp_exceptions
      catch(...)
      {
        // Return the failure if exception_type is std::exception_ptr,
        // otherwise terminate same as throwing an exception inside noexcept
        return current_exception_or_fatal<exception_type>(std::current_exception());
      }
#endif
    }
  };

}  // namespace detail

OUTCOME_V2_NAMESPACE_END

#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation"  // Standardese markup confuses clang
#endif

OUTCOME_V2_NAMESPACE_EXPORT_BEGIN

template <class R, class S, class P, class NoValuePolicy>                                                                            //
OUTCOME_REQUIRES(trait::type_can_be_used_in_basic_result<P> && (std::is_void<P>::value || std::is_default_constructible<P>::value))  //
class basic_outcome;

namespace detail
{
  // May be reused by basic_outcome subclasses to save load on the compiler
  template <class value_type, class error_type, class exception_type> struct outcome_predicates
  {
    using result = result_predicates<value_type, error_type>;

    // Predicate for the implicit constructors to be available
    static constexpr bool implicit_constructors_enabled =                //
    result::implicit_constructors_enabled                                //
    && !detail::is_implicitly_constructible<value_type, exception_type>  //
    && !detail::is_implicitly_constructible<error_type, exception_type>  //
    && !detail::is_implicitly_constructible<exception_type, value_type>  //
    && !detail::is_implicitly_constructible<exception_type, error_type>;

    // Predicate for the value converting constructor to be available.
    template <class T>
    static constexpr bool enable_value_converting_constructor =  //
    implicit_constructors_enabled                                //
    &&result::template enable_value_converting_constructor<T>    //
    && !detail::is_implicitly_constructible<exception_type, T>;  // deliberately less tolerant of ambiguity than result's edition

    // Predicate for the error converting constructor to be available.
    template <class T>
    static constexpr bool enable_error_converting_constructor =  //
    implicit_constructors_enabled                                //
    &&result::template enable_error_converting_constructor<T>    //
    && !detail::is_implicitly_constructible<exception_type, T>;  // deliberately less tolerant of ambiguity than result's edition

    // Predicate for the error condition converting constructor to be available.
    template <class ErrorCondEnum>
    static constexpr bool enable_error_condition_converting_constructor = result::template enable_error_condition_converting_constructor<ErrorCondEnum>  //
                                                                          && !detail::is_implicitly_constructible<exception_type, ErrorCondEnum>;

    // Predicate for the exception converting constructor to be available.
    template <class T>
    static constexpr bool enable_exception_converting_constructor =  //
    implicit_constructors_enabled                                    //
    && !is_in_place_type_t<std::decay_t<T>>::value                   // not in place construction
    && !detail::is_implicitly_constructible<value_type, T> && !detail::is_implicitly_constructible<error_type, T> && detail::is_implicitly_constructible<exception_type, T>;

    // Predicate for the error + exception converting constructor to be available.
    template <class T, class U>
    static constexpr bool enable_error_exception_converting_constructor =                                         //
    implicit_constructors_enabled                                                                                 //
    && !is_in_place_type_t<std::decay_t<T>>::value                                                                // not in place construction
    && !detail::is_implicitly_constructible<value_type, T> && detail::is_implicitly_constructible<error_type, T>  //
    && !detail::is_implicitly_constructible<value_type, U> && detail::is_implicitly_constructible<exception_type, U>;

    // Predicate for the converting copy constructor from a compatible outcome to be available.
    template <class T, class U, class V, class W>
    static constexpr bool enable_compatible_conversion =                                                                                   //
    (std::is_void<T>::value || detail::is_explicitly_constructible<value_type, typename basic_outcome<T, U, V, W>::value_type>)            // if our value types are constructible
    &&(std::is_void<U>::value || detail::is_explicitly_constructible<error_type, typename basic_outcome<T, U, V, W>::error_type>)          // if our error types are constructible
    &&(std::is_void<V>::value || detail::is_explicitly_constructible<exception_type, typename basic_outcome<T, U, V, W>::exception_type>)  // if our exception types are constructible
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

  // Select whether to use basic_outcome_failure_observers or not
  template <class Base, class R, class S, class P, class NoValuePolicy>
  using select_basic_outcome_failure_observers =  //
  std::conditional_t<trait::is_error_code_available<S>::value && trait::is_exception_ptr_available<P>::value, basic_outcome_failure_observers<Base, R, S, P, NoValuePolicy>, Base>;

  template <class T, class U, class V> constexpr inline const V &extract_exception_from_failure(const failure_type<U, V> &v) { return v.exception(); }
  template <class T, class U, class V> constexpr inline V &&extract_exception_from_failure(failure_type<U, V> &&v) { return static_cast<failure_type<U, V> &&>(v).exception(); }
  template <class T, class U> constexpr inline const U &extract_exception_from_failure(const failure_type<U, void> &v) { return v.error(); }
  template <class T, class U> constexpr inline U &&extract_exception_from_failure(failure_type<U, void> &&v) { return static_cast<failure_type<U, void> &&>(v).error(); }

  template <class T> struct is_basic_outcome
  {
    static constexpr bool value = false;
  };
  template <class R, class S, class T, class N> struct is_basic_outcome<basic_outcome<R, S, T, N>>
  {
    static constexpr bool value = true;
  };
}  // namespace detail

/*! AWAITING HUGO JSON CONVERSION TOOL
type alias template <class T> is_basic_outcome. Potential doc page: `is_basic_outcome<T>`
*/
template <class T> using is_basic_outcome = detail::is_basic_outcome<std::decay_t<T>>;
/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
template <class T> static constexpr bool is_basic_outcome_v = detail::is_basic_outcome<std::decay_t<T>>::value;

namespace hooks
{
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  template <class T, class... U> constexpr inline void hook_outcome_construction(T * /*unused*/, U &&... /*unused*/) noexcept {}
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  template <class T, class U> constexpr inline void hook_outcome_copy_construction(T * /*unused*/, U && /*unused*/) noexcept {}
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  template <class T, class U> constexpr inline void hook_outcome_move_construction(T * /*unused*/, U && /*unused*/) noexcept {}
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  template <class T, class U, class... Args> constexpr inline void hook_outcome_in_place_construction(T * /*unused*/, in_place_type_t<U> /*unused*/, Args &&... /*unused*/) noexcept {}

  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  template <class R, class S, class P, class NoValuePolicy, class U> constexpr inline void override_outcome_exception(basic_outcome<R, S, P, NoValuePolicy> *o, U &&v) noexcept;
}  // namespace hooks

/*! AWAITING HUGO JSON CONVERSION TOOL
type definition template <class R, class S, class P, class NoValuePolicy> basic_outcome. Potential doc page: `basic_outcome<T, EC, EP, NoValuePolicy>`
*/
template <class R, class S, class P, class NoValuePolicy>                                                                            //
OUTCOME_REQUIRES(trait::type_can_be_used_in_basic_result<P> && (std::is_void<P>::value || std::is_default_constructible<P>::value))  //
class OUTCOME_NODISCARD basic_outcome





: public detail::select_basic_outcome_failure_observers<detail::basic_outcome_exception_observers<detail::basic_result_final<R, S, NoValuePolicy>, R, S, P, NoValuePolicy>, R, S, P, NoValuePolicy>

{
  static_assert(trait::type_can_be_used_in_basic_result<P>, "The exception_type cannot be used");
  static_assert(std::is_void<P>::value || std::is_default_constructible<P>::value, "exception_type must be void or default constructible");
  using base = detail::select_basic_outcome_failure_observers<detail::basic_outcome_exception_observers<detail::basic_result_final<R, S, NoValuePolicy>, R, S, P, NoValuePolicy>, R, S, P, NoValuePolicy>;
  friend struct policy::base;
  template <class T, class U, class V, class W> friend class basic_outcome;
  template <class T, class U, class V, class W, class X> friend constexpr inline void hooks::override_outcome_exception(basic_outcome<T, U, V, W> *o, X &&v) noexcept;  // NOLINT

  struct implicit_constructors_disabled_tag
  {
  };
  struct value_converting_constructor_tag
  {
  };
  struct error_converting_constructor_tag
  {
  };
  struct error_condition_converting_constructor_tag
  {
  };
  struct exception_converting_constructor_tag
  {
  };
  struct error_exception_converting_constructor_tag
  {
  };
  struct explicit_valueorerror_converting_constructor_tag
  {
  };
  struct error_failure_tag
  {
  };
  struct exception_failure_tag
  {
  };

  struct disable_in_place_value_type
  {
  };
  struct disable_in_place_error_type
  {
  };
  struct disable_in_place_exception_type
  {
  };

public:
  using value_type = R;
  using error_type = S;
  using exception_type = P;

  template <class T, class U = S, class V = P, class W = NoValuePolicy> using rebind = basic_outcome<T, U, V, W>;

protected:
  // Requirement predicates for outcome.
  struct predicate
  {
    using base = detail::outcome_predicates<value_type, error_type, exception_type>;

    // Predicate for any constructors to be available at all
    static constexpr bool constructors_enabled = (!std::is_same<std::decay_t<value_type>, std::decay_t<error_type>>::value || (std::is_void<value_type>::value && std::is_void<error_type>::value))             //
                                                 && (!std::is_same<std::decay_t<value_type>, std::decay_t<exception_type>>::value || (std::is_void<value_type>::value && std::is_void<exception_type>::value))  //
                                                 && (!std::is_same<std::decay_t<error_type>, std::decay_t<exception_type>>::value || (std::is_void<error_type>::value && std::is_void<exception_type>::value))  //
    ;

    // Predicate for implicit constructors to be available at all
    static constexpr bool implicit_constructors_enabled = constructors_enabled && base::implicit_constructors_enabled;

    // Predicate for the value converting constructor to be available.
    template <class T>
    static constexpr bool enable_value_converting_constructor =  //
    constructors_enabled                                         //
    && !std::is_same<std::decay_t<T>, basic_outcome>::value      // not my type
    && base::template enable_value_converting_constructor<T>;

    // Predicate for the error converting constructor to be available.
    template <class T>
    static constexpr bool enable_error_converting_constructor =  //
    constructors_enabled                                         //
    && !std::is_same<std::decay_t<T>, basic_outcome>::value      // not my type
    && base::template enable_error_converting_constructor<T>;

    // Predicate for the error condition converting constructor to be available.
    template <class ErrorCondEnum>
    static constexpr bool enable_error_condition_converting_constructor =  //
    constructors_enabled                                                   //
    && !std::is_same<std::decay_t<ErrorCondEnum>, basic_outcome>::value    // not my type
    && base::template enable_error_condition_converting_constructor<ErrorCondEnum>;

    // Predicate for the exception converting constructor to be available.
    template <class T>
    static constexpr bool enable_exception_converting_constructor =  //
    constructors_enabled                                             //
    && !std::is_same<std::decay_t<T>, basic_outcome>::value          // not my type
    && base::template enable_exception_converting_constructor<T>;

    // Predicate for the error + exception converting constructor to be available.
    template <class T, class U>
    static constexpr bool enable_error_exception_converting_constructor =  //
    constructors_enabled                                                   //
    && !std::is_same<std::decay_t<T>, basic_outcome>::value                // not my type
    && base::template enable_error_exception_converting_constructor<T, U>;

    // Predicate for the converting constructor from a compatible input to be available.
    template <class T, class U, class V, class W>
    static constexpr bool enable_compatible_conversion =               //
    constructors_enabled                                               //
    && !std::is_same<basic_outcome<T, U, V, W>, basic_outcome>::value  // not my type
    && base::template enable_compatible_conversion<T, U, V, W>;

    // Predicate for the inplace construction of value to be available.
    template <class... Args>
    static constexpr bool enable_inplace_value_constructor =  //
    constructors_enabled                                      //
    && (std::is_void<value_type>::value                       //
        || std::is_constructible<value_type, Args...>::value);

    // Predicate for the inplace construction of error to be available.
    template <class... Args>
    static constexpr bool enable_inplace_error_constructor =  //
    constructors_enabled                                      //
    && (std::is_void<error_type>::value                       //
        || std::is_constructible<error_type, Args...>::value);

    // Predicate for the inplace construction of exception to be available.
    template <class... Args>
    static constexpr bool enable_inplace_exception_constructor =  //
    constructors_enabled                                          //
    && (std::is_void<exception_type>::value                       //
        || std::is_constructible<exception_type, Args...>::value);

    // Predicate for the implicit converting inplace constructor to be available.
    template <class... Args>
    static constexpr bool enable_inplace_value_error_exception_constructor =  //
    constructors_enabled                                                      //
    &&base::template enable_inplace_value_error_exception_constructor<Args...>;
    template <class... Args> using choose_inplace_value_error_exception_constructor = typename base::template choose_inplace_value_error_exception_constructor<Args...>;
  };

public:
  using value_type_if_enabled = std::conditional_t<std::is_same<value_type, error_type>::value || std::is_same<value_type, exception_type>::value, disable_in_place_value_type, value_type>;
  using error_type_if_enabled = std::conditional_t<std::is_same<error_type, value_type>::value || std::is_same<error_type, exception_type>::value, disable_in_place_error_type, error_type>;
  using exception_type_if_enabled = std::conditional_t<std::is_same<exception_type, value_type>::value || std::is_same<exception_type, error_type>::value, disable_in_place_exception_type, exception_type>;

protected:
  detail::devoid<exception_type> _ptr;

public:
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  OUTCOME_TEMPLATE(class Arg, class... Args)
  OUTCOME_TREQUIRES(OUTCOME_TPRED((!predicate::constructors_enabled && sizeof...(Args) >= 0)))
  basic_outcome(Arg && /*unused*/, Args &&... /*unused*/) = delete;  // NOLINT basic_outcome<> with any of the same type is NOT SUPPORTED, see docs!

  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED((predicate::constructors_enabled && !predicate::implicit_constructors_enabled  //
                                   && (detail::is_implicitly_constructible<value_type, T> || detail::is_implicitly_constructible<error_type, T> || detail::is_implicitly_constructible<exception_type, T>) )))
  basic_outcome(T && /*unused*/, implicit_constructors_disabled_tag /*unused*/ = implicit_constructors_disabled_tag()) = delete;  // NOLINT Implicit constructors disabled, use explicit in_place_type<T>, success() or failure(). see docs!

  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_value_converting_constructor<T>))
  constexpr basic_outcome(T &&t, value_converting_constructor_tag /*unused*/ = value_converting_constructor_tag()) noexcept(std::is_nothrow_constructible<value_type, T>::value)  // NOLINT
  : base{in_place_type<typename base::_value_type>, static_cast<T &&>(t)},
    _ptr()
  {
    using namespace hooks;
    hook_outcome_construction(this, static_cast<T &&>(t));
  }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_error_converting_constructor<T>))
  constexpr basic_outcome(T &&t, error_converting_constructor_tag /*unused*/ = error_converting_constructor_tag()) noexcept(std::is_nothrow_constructible<error_type, T>::value)  // NOLINT
  : base{in_place_type<typename base::_error_type>, static_cast<T &&>(t)},
    _ptr()
  {
    using namespace hooks;
    hook_outcome_construction(this, static_cast<T &&>(t));
  }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  OUTCOME_TEMPLATE(class ErrorCondEnum)
  OUTCOME_TREQUIRES(OUTCOME_TEXPR(error_type(make_error_code(ErrorCondEnum()))),  //
                    OUTCOME_TPRED(predicate::template enable_error_condition_converting_constructor<ErrorCondEnum>))
  constexpr basic_outcome(ErrorCondEnum &&t, error_condition_converting_constructor_tag /*unused*/ = error_condition_converting_constructor_tag()) noexcept(noexcept(error_type(make_error_code(static_cast<ErrorCondEnum &&>(t)))))  // NOLINT
  : base{in_place_type<typename base::_error_type>, make_error_code(t)}
  {
    using namespace hooks;
    hook_outcome_construction(this, static_cast<ErrorCondEnum &&>(t));
  }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_exception_converting_constructor<T>))
  constexpr basic_outcome(T &&t, exception_converting_constructor_tag /*unused*/ = exception_converting_constructor_tag()) noexcept(std::is_nothrow_constructible<exception_type, T>::value)  // NOLINT
  : base(),
    _ptr(static_cast<T &&>(t))
  {
    using namespace hooks;
    this->_state._status |= detail::status_have_exception;
    hook_outcome_construction(this, static_cast<T &&>(t));
  }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  OUTCOME_TEMPLATE(class T, class U)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_error_exception_converting_constructor<T, U>))
  constexpr basic_outcome(T &&a, U &&b, error_exception_converting_constructor_tag /*unused*/ = error_exception_converting_constructor_tag()) noexcept(std::is_nothrow_constructible<error_type, T>::value &&std::is_nothrow_constructible<exception_type, U>::value)  // NOLINT
  : base{in_place_type<typename base::_error_type>, static_cast<T &&>(a)},
    _ptr(static_cast<U &&>(b))
  {
    using namespace hooks;
    this->_state._status |= detail::status_have_exception;
    hook_outcome_construction(this, static_cast<T &&>(a), static_cast<U &&>(b));
  }

  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(convert::value_or_error<basic_outcome, std::decay_t<T>>::enable_result_inputs || !is_basic_result_v<T>),    //
                    OUTCOME_TPRED(convert::value_or_error<basic_outcome, std::decay_t<T>>::enable_outcome_inputs || !is_basic_outcome_v<T>),  //
                    OUTCOME_TEXPR(convert::value_or_error<basic_outcome, std::decay_t<T>>{}(std::declval<T>())))
  constexpr explicit basic_outcome(T &&o, explicit_valueorerror_converting_constructor_tag /*unused*/ = explicit_valueorerror_converting_constructor_tag())  // NOLINT
  : basic_outcome{convert::value_or_error<basic_outcome, std::decay_t<T>>{}(static_cast<T &&>(o))}
  {
  }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  OUTCOME_TEMPLATE(class T, class U, class V, class W)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_compatible_conversion<T, U, V, W>))
  constexpr explicit basic_outcome(const basic_outcome<T, U, V, W> &o) noexcept(std::is_nothrow_constructible<value_type, T>::value &&std::is_nothrow_constructible<error_type, U>::value &&std::is_nothrow_constructible<exception_type, V>::value)
      : base{typename base::compatible_conversion_tag(), o}
      , _ptr(o._ptr)
  {
    using namespace hooks;
    hook_outcome_copy_construction(this, o);
  }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  OUTCOME_TEMPLATE(class T, class U, class V, class W)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_compatible_conversion<T, U, V, W>))
  constexpr explicit basic_outcome(basic_outcome<T, U, V, W> &&o) noexcept(std::is_nothrow_constructible<value_type, T>::value &&std::is_nothrow_constructible<error_type, U>::value &&std::is_nothrow_constructible<exception_type, V>::value)
      : base{typename base::compatible_conversion_tag(), static_cast<basic_outcome<T, U, V, W> &&>(o)}
      , _ptr(static_cast<typename basic_outcome<T, U, V, W>::exception_type &&>(o._ptr))
  {
    using namespace hooks;
    hook_outcome_move_construction(this, static_cast<basic_outcome<T, U, V, W> &&>(o));
  }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  OUTCOME_TEMPLATE(class T, class U, class V)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(detail::result_predicates<value_type, error_type>::template enable_compatible_conversion<T, U, V>))
  constexpr explicit basic_outcome(const basic_result<T, U, V> &o) noexcept(std::is_nothrow_constructible<value_type, T>::value &&std::is_nothrow_constructible<error_type, U>::value &&std::is_nothrow_constructible<exception_type>::value)
      : base{typename base::compatible_conversion_tag(), o}
      , _ptr()
  {
    using namespace hooks;
    hook_outcome_copy_construction(this, o);
  }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  OUTCOME_TEMPLATE(class T, class U, class V)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(detail::result_predicates<value_type, error_type>::template enable_compatible_conversion<T, U, V>))
  constexpr explicit basic_outcome(basic_result<T, U, V> &&o) noexcept(std::is_nothrow_constructible<value_type, T>::value &&std::is_nothrow_constructible<error_type, U>::value &&std::is_nothrow_constructible<exception_type>::value)
      : base{typename base::compatible_conversion_tag(), static_cast<basic_result<T, U, V> &&>(o)}
      , _ptr()
  {
    using namespace hooks;
    hook_outcome_move_construction(this, static_cast<basic_result<T, U, V> &&>(o));
  }


  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  OUTCOME_TEMPLATE(class... Args)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_inplace_value_constructor<Args...>))
  constexpr explicit basic_outcome(in_place_type_t<value_type_if_enabled> _, Args &&... args) noexcept(std::is_nothrow_constructible<value_type, Args...>::value)
      : base{_, static_cast<Args &&>(args)...}
      , _ptr()
  {
    using namespace hooks;
    hook_outcome_in_place_construction(this, in_place_type<value_type>, static_cast<Args &&>(args)...);
  }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  OUTCOME_TEMPLATE(class U, class... Args)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_inplace_value_constructor<std::initializer_list<U>, Args...>))
  constexpr explicit basic_outcome(in_place_type_t<value_type_if_enabled> _, std::initializer_list<U> il, Args &&... args) noexcept(std::is_nothrow_constructible<value_type, std::initializer_list<U>, Args...>::value)
      : base{_, il, static_cast<Args &&>(args)...}
      , _ptr()
  {
    using namespace hooks;
    hook_outcome_in_place_construction(this, in_place_type<value_type>, il, static_cast<Args &&>(args)...);
  }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  OUTCOME_TEMPLATE(class... Args)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_inplace_error_constructor<Args...>))
  constexpr explicit basic_outcome(in_place_type_t<error_type_if_enabled> _, Args &&... args) noexcept(std::is_nothrow_constructible<error_type, Args...>::value)
      : base{_, static_cast<Args &&>(args)...}
      , _ptr()
  {
    using namespace hooks;
    hook_outcome_in_place_construction(this, in_place_type<error_type>, static_cast<Args &&>(args)...);
  }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  OUTCOME_TEMPLATE(class U, class... Args)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_inplace_error_constructor<std::initializer_list<U>, Args...>))
  constexpr explicit basic_outcome(in_place_type_t<error_type_if_enabled> _, std::initializer_list<U> il, Args &&... args) noexcept(std::is_nothrow_constructible<error_type, std::initializer_list<U>, Args...>::value)
      : base{_, il, static_cast<Args &&>(args)...}
      , _ptr()
  {
    using namespace hooks;
    hook_outcome_in_place_construction(this, in_place_type<error_type>, il, static_cast<Args &&>(args)...);
  }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  OUTCOME_TEMPLATE(class... Args)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_inplace_exception_constructor<Args...>))
  constexpr explicit basic_outcome(in_place_type_t<exception_type_if_enabled> /*unused*/, Args &&... args) noexcept(std::is_nothrow_constructible<exception_type, Args...>::value)
      : base()
      , _ptr(static_cast<Args &&>(args)...)
  {
    using namespace hooks;
    this->_state._status |= detail::status_have_exception;
    hook_outcome_in_place_construction(this, in_place_type<exception_type>, static_cast<Args &&>(args)...);
  }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  OUTCOME_TEMPLATE(class U, class... Args)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_inplace_exception_constructor<std::initializer_list<U>, Args...>))
  constexpr explicit basic_outcome(in_place_type_t<exception_type_if_enabled> /*unused*/, std::initializer_list<U> il, Args &&... args) noexcept(std::is_nothrow_constructible<exception_type, std::initializer_list<U>, Args...>::value)
      : base()
      , _ptr(il, static_cast<Args &&>(args)...)
  {
    using namespace hooks;
    this->_state._status |= detail::status_have_exception;
    hook_outcome_in_place_construction(this, in_place_type<exception_type>, il, static_cast<Args &&>(args)...);
  }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  OUTCOME_TEMPLATE(class A1, class A2, class... Args)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_inplace_value_error_exception_constructor<A1, A2, Args...>))
  constexpr basic_outcome(A1 &&a1, A2 &&a2, Args &&... args) noexcept(noexcept(typename predicate::template choose_inplace_value_error_exception_constructor<A1, A2, Args...>(std::declval<A1>(), std::declval<A2>(), std::declval<Args>()...)))
      : basic_outcome(in_place_type<typename predicate::template choose_inplace_value_error_exception_constructor<A1, A2, Args...>>, static_cast<A1 &&>(a1), static_cast<A2 &&>(a2), static_cast<Args &&>(args)...)
  {
  }

  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  constexpr basic_outcome(const success_type<void> &o) noexcept(std::is_nothrow_default_constructible<value_type>::value)  // NOLINT
  : base{in_place_type<typename base::_value_type>}
  {
    using namespace hooks;
    hook_outcome_copy_construction(this, o);
  }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(!std::is_void<T>::value && predicate::template enable_compatible_conversion<T, void, void, void>))
  constexpr basic_outcome(const success_type<T> &o) noexcept(std::is_nothrow_constructible<value_type, T>::value)  // NOLINT
  : base{in_place_type<typename base::_value_type>, detail::extract_value_from_success<value_type>(o)}
  {
    using namespace hooks;
    hook_outcome_copy_construction(this, o);
  }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(!std::is_void<T>::value && predicate::template enable_compatible_conversion<T, void, void, void>))
  constexpr basic_outcome(success_type<T> &&o) noexcept(std::is_nothrow_constructible<value_type, T>::value)  // NOLINT
  : base{in_place_type<typename base::_value_type>, detail::extract_value_from_success<value_type>(static_cast<success_type<T> &&>(o))}
  {
    using namespace hooks;
    hook_outcome_move_construction(this, static_cast<success_type<T> &&>(o));
  }

  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(!std::is_void<T>::value && predicate::template enable_compatible_conversion<void, T, void, void>))
  constexpr basic_outcome(const failure_type<T> &o, error_failure_tag /*unused*/ = error_failure_tag()) noexcept(std::is_nothrow_constructible<error_type, T>::value)  // NOLINT
  : base{in_place_type<typename base::_error_type>, detail::extract_error_from_failure<error_type>(o)},
    _ptr()
  {
    using namespace hooks;
    hook_outcome_copy_construction(this, o);
  }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(!std::is_void<T>::value && predicate::template enable_compatible_conversion<void, void, T, void>))
  constexpr basic_outcome(const failure_type<T> &o, exception_failure_tag /*unused*/ = exception_failure_tag()) noexcept(std::is_nothrow_constructible<exception_type, T>::value)  // NOLINT
  : base(),
    _ptr(detail::extract_exception_from_failure<exception_type>(o))
  {
    this->_state._status |= detail::status_have_exception;
    using namespace hooks;
    hook_outcome_copy_construction(this, o);
  }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  OUTCOME_TEMPLATE(class T, class U)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(!std::is_void<U>::value && predicate::template enable_compatible_conversion<void, T, U, void>))
  constexpr basic_outcome(const failure_type<T, U> &o) noexcept(std::is_nothrow_constructible<error_type, T>::value &&std::is_nothrow_constructible<exception_type, U>::value)  // NOLINT
  : base{in_place_type<typename base::_error_type>, detail::extract_error_from_failure<error_type>(o)},
    _ptr(detail::extract_exception_from_failure<exception_type>(o))
  {
    if(!o.has_error())
    {
      this->_state._status &= ~detail::status_have_error;
    }
    if(o.has_exception())
    {
      this->_state._status |= detail::status_have_exception;
    }
    using namespace hooks;
    hook_outcome_copy_construction(this, o);
  }

  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(!std::is_void<T>::value && predicate::template enable_compatible_conversion<void, T, void, void>))
  constexpr basic_outcome(failure_type<T> &&o, error_failure_tag /*unused*/ = error_failure_tag()) noexcept(std::is_nothrow_constructible<error_type, T>::value)  // NOLINT
  : base{in_place_type<typename base::_error_type>, detail::extract_error_from_failure<error_type>(static_cast<failure_type<T> &&>(o))},
    _ptr()
  {
    using namespace hooks;
    hook_outcome_copy_construction(this, o);
  }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(!std::is_void<T>::value && predicate::template enable_compatible_conversion<void, void, T, void>))
  constexpr basic_outcome(failure_type<T> &&o, exception_failure_tag /*unused*/ = exception_failure_tag()) noexcept(std::is_nothrow_constructible<exception_type, T>::value)  // NOLINT
  : base(),
    _ptr(detail::extract_exception_from_failure<exception_type>(static_cast<failure_type<T> &&>(o)))
  {
    this->_state._status |= detail::status_have_exception;
    using namespace hooks;
    hook_outcome_copy_construction(this, o);
  }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  OUTCOME_TEMPLATE(class T, class U)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(!std::is_void<U>::value && predicate::template enable_compatible_conversion<void, T, U, void>))
  constexpr basic_outcome(failure_type<T, U> &&o) noexcept(std::is_nothrow_constructible<error_type, T>::value &&std::is_nothrow_constructible<exception_type, U>::value)  // NOLINT
  : base{in_place_type<typename base::_error_type>, detail::extract_error_from_failure<error_type>(static_cast<failure_type<T, U> &&>(o))},
    _ptr(detail::extract_exception_from_failure<exception_type>(static_cast<failure_type<T, U> &&>(o)))
  {
    if(!o.has_error())
    {
      this->_state._status &= ~detail::status_have_error;
    }
    if(o.has_exception())
    {
      this->_state._status |= detail::status_have_exception;
    }
    using namespace hooks;
    hook_outcome_move_construction(this, static_cast<failure_type<T, U> &&>(o));
  }

  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  using base::operator==;
  using base::operator!=;
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  OUTCOME_TEMPLATE(class T, class U, class V, class W)
  OUTCOME_TREQUIRES(OUTCOME_TEXPR(std::declval<detail::devoid<value_type>>() == std::declval<detail::devoid<T>>()),  //
                    OUTCOME_TEXPR(std::declval<detail::devoid<error_type>>() == std::declval<detail::devoid<U>>()),  //
                    OUTCOME_TEXPR(std::declval<detail::devoid<exception_type>>() == std::declval<detail::devoid<V>>()))
  constexpr bool operator==(const basic_outcome<T, U, V, W> &o) const noexcept(                 //
  noexcept(std::declval<detail::devoid<value_type>>() == std::declval<detail::devoid<T>>())     //
  && noexcept(std::declval<detail::devoid<error_type>>() == std::declval<detail::devoid<U>>())  //
  && noexcept(std::declval<detail::devoid<exception_type>>() == std::declval<detail::devoid<V>>()))
  {
    if((this->_state._status & detail::status_have_value) != 0 && (o._state._status & detail::status_have_value) != 0)
    {
      return this->_state._value == o._state._value;  // NOLINT
    }
    if((this->_state._status & detail::status_have_error) != 0 && (o._state._status & detail::status_have_error) != 0  //
       && (this->_state._status & detail::status_have_exception) != 0 && (o._state._status & detail::status_have_exception) != 0)
    {
      return this->_error == o._error && this->_ptr == o._ptr;
    }
    if((this->_state._status & detail::status_have_error) != 0 && (o._state._status & detail::status_have_error) != 0)
    {
      return this->_error == o._error;
    }
    if((this->_state._status & detail::status_have_exception) != 0 && (o._state._status & detail::status_have_exception) != 0)
    {
      return this->_ptr == o._ptr;
    }
    return false;
  }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  OUTCOME_TEMPLATE(class T, class U)
  OUTCOME_TREQUIRES(OUTCOME_TEXPR(std::declval<error_type>() == std::declval<T>()),  //
                    OUTCOME_TEXPR(std::declval<exception_type>() == std::declval<U>()))
  constexpr bool operator==(const failure_type<T, U> &o) const noexcept(  //
  noexcept(std::declval<error_type>() == std::declval<T>()) && noexcept(std::declval<exception_type>() == std::declval<U>()))
  {
    if((this->_state._status & detail::status_have_error) != 0 && (o._state._status & detail::status_have_error) != 0  //
       && (this->_state._status & detail::status_have_exception) != 0 && (o._state._status & detail::status_have_exception) != 0)
    {
      return this->_error == o.error() && this->_ptr == o.exception();
    }
    if((this->_state._status & detail::status_have_error) != 0 && (o._state._status & detail::status_have_error) != 0)
    {
      return this->_error == o.error();
    }
    if((this->_state._status & detail::status_have_exception) != 0 && (o._state._status & detail::status_have_exception) != 0)
    {
      return this->_ptr == o.exception();
    }
    return false;
  }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  OUTCOME_TEMPLATE(class T, class U, class V, class W)
  OUTCOME_TREQUIRES(OUTCOME_TEXPR(std::declval<detail::devoid<value_type>>() != std::declval<detail::devoid<T>>()),  //
                    OUTCOME_TEXPR(std::declval<detail::devoid<error_type>>() != std::declval<detail::devoid<U>>()),  //
                    OUTCOME_TEXPR(std::declval<detail::devoid<exception_type>>() != std::declval<detail::devoid<V>>()))
  constexpr bool operator!=(const basic_outcome<T, U, V, W> &o) const noexcept(                 //
  noexcept(std::declval<detail::devoid<value_type>>() != std::declval<detail::devoid<T>>())     //
  && noexcept(std::declval<detail::devoid<error_type>>() != std::declval<detail::devoid<U>>())  //
  && noexcept(std::declval<detail::devoid<exception_type>>() != std::declval<detail::devoid<V>>()))
  {
    if((this->_state._status & detail::status_have_value) != 0 && (o._state._status & detail::status_have_value) != 0)
    {
      return this->_state._value != o._state._value;  // NOLINT
    }
    if((this->_state._status & detail::status_have_error) != 0 && (o._state._status & detail::status_have_error) != 0  //
       && (this->_state._status & detail::status_have_exception) != 0 && (o._state._status & detail::status_have_exception) != 0)
    {
      return this->_error != o._error || this->_ptr != o._ptr;
    }
    if((this->_state._status & detail::status_have_error) != 0 && (o._state._status & detail::status_have_error) != 0)
    {
      return this->_error != o._error;
    }
    if((this->_state._status & detail::status_have_exception) != 0 && (o._state._status & detail::status_have_exception) != 0)
    {
      return this->_ptr != o._ptr;
    }
    return true;
  }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  OUTCOME_TEMPLATE(class T, class U)
  OUTCOME_TREQUIRES(OUTCOME_TEXPR(std::declval<error_type>() != std::declval<T>()),  //
                    OUTCOME_TEXPR(std::declval<exception_type>() != std::declval<U>()))
  constexpr bool operator!=(const failure_type<T, U> &o) const noexcept(  //
  noexcept(std::declval<error_type>() == std::declval<T>()) && noexcept(std::declval<exception_type>() == std::declval<U>()))
  {
    if((this->_state._status & detail::status_have_error) != 0 && (o._state._status & detail::status_have_error) != 0  //
       && (this->_state._status & detail::status_have_exception) != 0 && (o._state._status & detail::status_have_exception) != 0)
    {
      return this->_error != o.error() || this->_ptr != o.exception();
    }
    if((this->_state._status & detail::status_have_error) != 0 && (o._state._status & detail::status_have_error) != 0)
    {
      return this->_error != o.error();
    }
    if((this->_state._status & detail::status_have_exception) != 0 && (o._state._status & detail::status_have_exception) != 0)
    {
      return this->_ptr != o.exception();
    }
    return true;
  }

  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  void swap(basic_outcome &o) noexcept(detail::is_nothrow_swappable<value_type>::value &&std::is_nothrow_move_constructible<value_type>::value    //
                                       &&detail::is_nothrow_swappable<error_type>::value &&std::is_nothrow_move_constructible<error_type>::value  //
                                       &&detail::is_nothrow_swappable<exception_type>::value &&std::is_nothrow_move_constructible<exception_type>::value)
  {
    using std::swap;
#ifdef __cpp_exceptions
    constexpr bool value_throws = !noexcept(this->_state.swap(o._state));
    constexpr bool error_throws = !noexcept(swap(this->_error, o._error));
    constexpr bool exception_throws = !noexcept(swap(this->_ptr, o._ptr));
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4127)  // conditional expression is constant
#endif
    // Do throwing swap first
    if((value_throws && !error_throws && !exception_throws) || (!value_throws && !error_throws && !exception_throws))
    {
      this->_state.swap(o._state);
      swap(this->_error, o._error);
      swap(this->_ptr, o._ptr);
    }
    else if(!value_throws && !error_throws && exception_throws)
    {
      swap(this->_ptr, o._ptr);
      this->_state.swap(o._state);
      swap(this->_error, o._error);
    }
    else if(!value_throws && error_throws && !exception_throws)
    {
      swap(this->_error, o._error);
      this->_state.swap(o._state);
      swap(this->_ptr, o._ptr);
    }
    else
    {
      // Two or more can throw
      this->_state.swap(o._state);
      bool exception_threw = false;
      try
      {
        swap(this->_error, o._error);
        exception_threw = true;
        swap(this->_ptr, o._ptr);
      }
      catch(...)
      {
        // Try to put it back
        bool error_is_mine = !exception_threw;
        try
        {
          if(exception_threw)
          {
            swap(this->_error, o._error);
            error_is_mine = true;
          }
          this->_state.swap(o._state);
          // If that succeeded, continue by rethrowing the exception
        }
        catch(...)
        {
          if(error_is_mine)
          {
            try
            {
              swap(this->_error, o._error);
              error_is_mine = false;
            }
            catch(...)
            {
            }
          }
          // Prevent has_value() == has_error() or has_value() == has_exception()
          auto check = [](basic_outcome *t, bool set_error) {
            if(t->has_value() && (t->has_error() || t->has_exception()))
            {
              // We know the value swapped and is now set, so clear error and exception
              t->_state._status &= ~(detail::status_have_error | detail::status_have_exception);
            }
            if(!t->has_value() && !(t->has_error() || t->has_exception()))
            {
              // We know the value swapped and is now unset, so either set exception or error
              if(set_error)
              {
                t->_state._status |= detail::status_have_error;
              }
              else
              {
                t->_state._status |= detail::status_have_exception;
              }
            }
          };
          // If my value is unset and error is not mine, set error
          check(this, !error_is_mine);
          // If other's value is unset and error is not mine, set error
          check(&o, !error_is_mine);
        }
        throw;
      }
    }
#ifdef _MSC_VER
#pragma warning(pop)
#endif
#else
    this->_state.swap(o._state);
    swap(this->_error, o._error);
    swap(this->_ptr, o._ptr);
#endif
  }

  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  failure_type<error_type, exception_type> as_failure() const &
  {
    if(this->has_error() && this->has_exception())
    {
      return failure_type<error_type, exception_type>(this->assume_error(), this->assume_exception());
    }
    if(this->has_exception())
    {
      return failure_type<error_type, exception_type>(in_place_type<exception_type>, this->assume_exception());
    }
    return failure_type<error_type, exception_type>(in_place_type<error_type>, this->assume_error());
  }

  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  failure_type<error_type, exception_type> as_failure() &&
  {
    if(this->has_error() && this->has_exception())
    {
      return failure_type<error_type, exception_type>(static_cast<S &&>(this->assume_error()), static_cast<P &&>(this->assume_exception()));
    }
    if(this->has_exception())
    {
      return failure_type<error_type, exception_type>(in_place_type<exception_type>, static_cast<P &&>(this->assume_exception()));
    }
    return failure_type<error_type, exception_type>(in_place_type<error_type>, static_cast<S &&>(this->assume_error()));
  }
};

/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
OUTCOME_TEMPLATE(class T, class U, class V,  //
                 class R, class S, class P, class N)
OUTCOME_TREQUIRES(OUTCOME_TEXPR(std::declval<basic_outcome<R, S, P, N>>() == std::declval<basic_result<T, U, V>>()))
constexpr inline bool operator==(const basic_result<T, U, V> &a, const basic_outcome<R, S, P, N> &b) noexcept(  //
noexcept(std::declval<basic_outcome<R, S, P, N>>() == std::declval<basic_result<T, U, V>>()))
{
  return b == a;
}
/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
OUTCOME_TEMPLATE(class T, class U, class V,  //
                 class R, class S, class P, class N)
OUTCOME_TREQUIRES(OUTCOME_TEXPR(std::declval<basic_outcome<R, S, P, N>>() != std::declval<basic_result<T, U, V>>()))
constexpr inline bool operator!=(const basic_result<T, U, V> &a, const basic_outcome<R, S, P, N> &b) noexcept(  //
noexcept(std::declval<basic_outcome<R, S, P, N>>() != std::declval<basic_result<T, U, V>>()))
{
  return b != a;
}
/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
template <class R, class S, class P, class N> inline void swap(basic_outcome<R, S, P, N> &a, basic_outcome<R, S, P, N> &b) noexcept(noexcept(a.swap(b)))
{
  a.swap(b);
}

namespace hooks
{
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  template <class R, class S, class P, class NoValuePolicy, class U> constexpr inline void override_outcome_exception(basic_outcome<R, S, P, NoValuePolicy> *o, U &&v) noexcept
  {
    o->_ptr = static_cast<U &&>(v);  // NOLINT
    o->_state._status |= detail::status_have_exception;
  }
}  // namespace hooks

OUTCOME_V2_NAMESPACE_END

#ifdef __clang__
#pragma clang diagnostic pop
#endif
/* Exception observers for outcome type
(C) 2017 Niall Douglas <http://www.nedproductions.biz/> (59 commits)
File Created: Oct 2017


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

#ifndef OUTCOME_BASIC_OUTCOME_EXCEPTION_OBSERVERS_IMPL_HPP
#define OUTCOME_BASIC_OUTCOME_EXCEPTION_OBSERVERS_IMPL_HPP





OUTCOME_V2_NAMESPACE_EXPORT_BEGIN

namespace policy
{
  template <class R, class S, class P, class NoValuePolicy, class Impl> inline constexpr auto &&base::_exception(Impl &&self) noexcept
  {
    // Impl will be some internal implementation class which has no knowledge of the _ptr stored
    // beneath it. So statically cast, preserving rvalue and constness, to the derived class.
    using Outcome = OUTCOME_V2_NAMESPACE::detail::rebind_type<basic_outcome<R, S, P, NoValuePolicy>, decltype(self)>;
#if defined(_MSC_VER) && _MSC_VER < 1920
    // VS2017 tries a copy construction in the correct implementation despite that Outcome is always a rvalue or lvalue ref! :(
    basic_outcome<R, S, P, NoValuePolicy> &_self = (basic_outcome<R, S, P, NoValuePolicy> &) (self);  // NOLINT
#else
    Outcome _self = static_cast<Outcome>(self);  // NOLINT
#endif
    return static_cast<Outcome>(_self)._ptr;
  }
}  // namespace policy

namespace detail
{
  template <class Base, class R, class S, class P, class NoValuePolicy> inline constexpr typename basic_outcome_exception_observers<Base, R, S, P, NoValuePolicy>::exception_type &basic_outcome_exception_observers<Base, R, S, P, NoValuePolicy>::assume_exception() & noexcept
  {
    NoValuePolicy::narrow_exception_check(*this);
    return NoValuePolicy::template _exception<R, S, P, NoValuePolicy>(*this);
  }
  template <class Base, class R, class S, class P, class NoValuePolicy> inline constexpr const typename basic_outcome_exception_observers<Base, R, S, P, NoValuePolicy>::exception_type &basic_outcome_exception_observers<Base, R, S, P, NoValuePolicy>::assume_exception() const &noexcept
  {
    NoValuePolicy::narrow_exception_check(*this);
    return NoValuePolicy::template _exception<R, S, P, NoValuePolicy>(*this);
  }
  template <class Base, class R, class S, class P, class NoValuePolicy> inline constexpr typename basic_outcome_exception_observers<Base, R, S, P, NoValuePolicy>::exception_type &&basic_outcome_exception_observers<Base, R, S, P, NoValuePolicy>::assume_exception() && noexcept
  {
    NoValuePolicy::narrow_exception_check(std::move(*this));
    return NoValuePolicy::template _exception<R, S, P, NoValuePolicy>(std::move(*this));
  }
  template <class Base, class R, class S, class P, class NoValuePolicy> inline constexpr const typename basic_outcome_exception_observers<Base, R, S, P, NoValuePolicy>::exception_type &&basic_outcome_exception_observers<Base, R, S, P, NoValuePolicy>::assume_exception() const &&noexcept
  {
    NoValuePolicy::narrow_exception_check(std::move(*this));
    return NoValuePolicy::template _exception<R, S, P, NoValuePolicy>(std::move(*this));
  }

  template <class Base, class R, class S, class P, class NoValuePolicy> inline constexpr typename basic_outcome_exception_observers<Base, R, S, P, NoValuePolicy>::exception_type &basic_outcome_exception_observers<Base, R, S, P, NoValuePolicy>::exception() &
  {
    NoValuePolicy::wide_exception_check(*this);
    return NoValuePolicy::template _exception<R, S, P, NoValuePolicy>(*this);
  }
  template <class Base, class R, class S, class P, class NoValuePolicy> inline constexpr const typename basic_outcome_exception_observers<Base, R, S, P, NoValuePolicy>::exception_type &basic_outcome_exception_observers<Base, R, S, P, NoValuePolicy>::exception() const &
  {
    NoValuePolicy::wide_exception_check(*this);
    return NoValuePolicy::template _exception<R, S, P, NoValuePolicy>(*this);
  }
  template <class Base, class R, class S, class P, class NoValuePolicy> inline constexpr typename basic_outcome_exception_observers<Base, R, S, P, NoValuePolicy>::exception_type &&basic_outcome_exception_observers<Base, R, S, P, NoValuePolicy>::exception() &&
  {
    NoValuePolicy::wide_exception_check(std::move(*this));
    return NoValuePolicy::template _exception<R, S, P, NoValuePolicy>(std::move(*this));
  }
  template <class Base, class R, class S, class P, class NoValuePolicy> inline constexpr const typename basic_outcome_exception_observers<Base, R, S, P, NoValuePolicy>::exception_type &&basic_outcome_exception_observers<Base, R, S, P, NoValuePolicy>::exception() const &&
  {
    NoValuePolicy::wide_exception_check(std::move(*this));
    return NoValuePolicy::template _exception<R, S, P, NoValuePolicy>(std::move(*this));
  }
}  // namespace detail

OUTCOME_V2_NAMESPACE_END

#endif
#if !defined(NDEBUG)
OUTCOME_V2_NAMESPACE_BEGIN
// Check is trivial in all ways except default constructibility and standard layout
// static_assert(std::is_trivial<basic_outcome<int, long, double, policy::all_narrow>>::value, "outcome<int> is not trivial!");
// static_assert(std::is_trivially_default_constructible<basic_outcome<int, long, double, policy::all_narrow>>::value, "outcome<int> is not trivially default constructible!");
static_assert(std::is_trivially_copyable<basic_outcome<int, long, double, policy::all_narrow>>::value, "outcome<int> is not trivially copyable!");
static_assert(std::is_trivially_assignable<basic_outcome<int, long, double, policy::all_narrow>, basic_outcome<int, long, double, policy::all_narrow>>::value, "outcome<int> is not trivially assignable!");
static_assert(std::is_trivially_destructible<basic_outcome<int, long, double, policy::all_narrow>>::value, "outcome<int> is not trivially destructible!");
static_assert(std::is_trivially_copy_constructible<basic_outcome<int, long, double, policy::all_narrow>>::value, "outcome<int> is not trivially copy constructible!");
static_assert(std::is_trivially_move_constructible<basic_outcome<int, long, double, policy::all_narrow>>::value, "outcome<int> is not trivially move constructible!");
static_assert(std::is_trivially_copy_assignable<basic_outcome<int, long, double, policy::all_narrow>>::value, "outcome<int> is not trivially copy assignable!");
static_assert(std::is_trivially_move_assignable<basic_outcome<int, long, double, policy::all_narrow>>::value, "outcome<int> is not trivially move assignable!");
// Can't be standard layout as non-static member data is defined in more than one inherited class
// static_assert(std::is_standard_layout<basic_outcome<int, long, double, policy::all_narrow>>::value, "outcome<int> is not a standard layout type!");
OUTCOME_V2_NAMESPACE_END
#endif

#endif
/* Traits for Outcome
(C) 2018 Niall Douglas <http://www.nedproductions.biz/> (59 commits)
File Created: March 2018


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

#ifndef OUTCOME_TRAIT_STD_EXCEPTION_HPP
#define OUTCOME_TRAIT_STD_EXCEPTION_HPP



#include <exception>

OUTCOME_V2_NAMESPACE_BEGIN

namespace policy
{
  namespace detail
  {
    /* Pass through `make_exception_ptr` function for `std::exception_ptr`.
    */

    inline std::exception_ptr make_exception_ptr(std::exception_ptr v) { return v; }

    // Try ADL, if not use fall backs above
    template <class T> constexpr inline decltype(auto) exception_ptr(T &&v) { return make_exception_ptr(std::forward<T>(v)); }
  }  // namespace detail

  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  template <class T> constexpr inline decltype(auto) exception_ptr(T &&v) { return detail::exception_ptr(std::forward<T>(v)); }

  namespace detail
  {
    template <bool has_error_payload> struct _rethrow_exception
    {
      template <class Exception> explicit _rethrow_exception(Exception && /*unused*/)  // NOLINT
      {
      }
    };
    template <> struct _rethrow_exception<true>
    {
      template <class Exception> explicit _rethrow_exception(Exception &&excpt)  // NOLINT
      {
        // ADL
        rethrow_exception(policy::exception_ptr(std::forward<Exception>(excpt)));
      }
    };
  }  // namespace detail
}  // namespace policy

namespace trait
{
  namespace detail
  {
    // Shortcut this for lower build impact
    template <> struct _is_exception_ptr_available<std::exception_ptr>
    {
      static constexpr bool value = true;
    };
  }  // namespace detail

  // std::exception_ptr is an error type
  template <> struct is_error_type<std::exception_ptr>
  {
    static constexpr bool value = true;
  };

}  // namespace trait

OUTCOME_V2_NAMESPACE_END

#endif
/* A very simple result type
(C) 2018 Niall Douglas <http://www.nedproductions.biz/> (59 commits)
File Created: Apr 2018


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

#ifndef OUTCOME_EXPERIMENTAL_STATUS_RESULT_HPP
#define OUTCOME_EXPERIMENTAL_STATUS_RESULT_HPP
/* Policies for result and outcome
(C) 2018 Niall Douglas <http://www.nedproductions.biz/> (59 commits)
File Created: Sep 2018


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

#ifndef OUTCOME_POLICY_FAIL_TO_COMPILE_OBSERVERS_HPP
#define OUTCOME_POLICY_FAIL_TO_COMPILE_OBSERVERS_HPP



OUTCOME_V2_NAMESPACE_EXPORT_BEGIN

#define OUTCOME_FAIL_TO_COMPILE_OBSERVERS_MESSAGE                                                                                                                                                                                                                                                                                "Attempt to wide observe value, error or "                                                                                                                                                                                                                                                                                     "exception for a basic_result/basic_outcome given an EC or EP type which is not void, and for whom "                                                                                                                                                                                                                           "trait::is_error_code_available<EC>, trait::is_exception_ptr_available<EC>, and trait::is_exception_ptr_available<EP> "                                                                                                                                                                                                        "are all false. Please specify a NoValuePolicy to tell basic_result/basic_outcome what to do, or else use "                                                                                                                                                                                                                    "a more specific convenience type alias such as unchecked<T, E> to indicate you want the wide "                                                                                                                                                                                                                                "observers to be narrow, or checked<T, E> to indicate you always want an exception throw etc."







namespace policy
{
  struct fail_to_compile_observers : base
  {
    template <class Impl> static constexpr void wide_value_check(Impl && /* unused */) { static_assert(!std::is_same<Impl, Impl>::value, "Attempt to wide observe value, error or "                                                                                                                                                                                                                                                                                     "exception for a basic_result/basic_outcome given an EC or EP type which is not void, and for whom "                                                                                                                                                                                                                           "trait::is_error_code_available<EC>, trait::is_exception_ptr_available<EC>, and trait::is_exception_ptr_available<EP> "                                                                                                                                                                                                        "are all false. Please specify a NoValuePolicy to tell basic_result/basic_outcome what to do, or else use "                                                                                                                                                                                                                    "a more specific convenience type alias such as unchecked<T, E> to indicate you want the wide "                                                                                                                                                                                                                                "observers to be narrow, or checked<T, E> to indicate you always want an exception throw etc."); }
    template <class Impl> static constexpr void wide_error_check(Impl && /* unused */) { static_assert(!std::is_same<Impl, Impl>::value, "Attempt to wide observe value, error or "                                                                                                                                                                                                                                                                                     "exception for a basic_result/basic_outcome given an EC or EP type which is not void, and for whom "                                                                                                                                                                                                                           "trait::is_error_code_available<EC>, trait::is_exception_ptr_available<EC>, and trait::is_exception_ptr_available<EP> "                                                                                                                                                                                                        "are all false. Please specify a NoValuePolicy to tell basic_result/basic_outcome what to do, or else use "                                                                                                                                                                                                                    "a more specific convenience type alias such as unchecked<T, E> to indicate you want the wide "                                                                                                                                                                                                                                "observers to be narrow, or checked<T, E> to indicate you always want an exception throw etc."); }
    template <class Impl> static constexpr void wide_exception_check(Impl && /* unused */) { static_assert(!std::is_same<Impl, Impl>::value, "Attempt to wide observe value, error or "                                                                                                                                                                                                                                                                                     "exception for a basic_result/basic_outcome given an EC or EP type which is not void, and for whom "                                                                                                                                                                                                                           "trait::is_error_code_available<EC>, trait::is_exception_ptr_available<EC>, and trait::is_exception_ptr_available<EP> "                                                                                                                                                                                                        "are all false. Please specify a NoValuePolicy to tell basic_result/basic_outcome what to do, or else use "                                                                                                                                                                                                                    "a more specific convenience type alias such as unchecked<T, E> to indicate you want the wide "                                                                                                                                                                                                                                "observers to be narrow, or checked<T, E> to indicate you always want an exception throw etc."); }
  };
}  // namespace policy

#undef OUTCOME_FAIL_TO_COMPILE_OBSERVERS_MESSAGE

OUTCOME_V2_NAMESPACE_END

#endif
/* Proposed SG14 status_code
(C) 2018 Niall Douglas <http://www.nedproductions.biz/> (5 commits)
File Created: Feb 2018


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

#ifndef SYSTEM_ERROR2_HPP
#define SYSTEM_ERROR2_HPP
/* Proposed SG14 status_code
(C) 2018 Niall Douglas <http://www.nedproductions.biz/> (5 commits)
File Created: Feb 2018


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

#ifndef SYSTEM_ERROR2_ERROR_HPP
#define SYSTEM_ERROR2_ERROR_HPP
/* Proposed SG14 status_code
(C) 2018 Niall Douglas <http://www.nedproductions.biz/> (5 commits)
File Created: Jun 2018


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

#ifndef SYSTEM_ERROR2_ERRORED_STATUS_CODE_HPP
#define SYSTEM_ERROR2_ERRORED_STATUS_CODE_HPP
/* Proposed SG14 status_code
(C) 2018 Niall Douglas <http://www.nedproductions.biz/> (5 commits)
File Created: Feb 2018


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

#ifndef SYSTEM_ERROR2_GENERIC_CODE_HPP
#define SYSTEM_ERROR2_GENERIC_CODE_HPP
/* Proposed SG14 status_code
(C) 2018 Niall Douglas <http://www.nedproductions.biz/> (5 commits)
File Created: Feb 2018


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

#ifndef SYSTEM_ERROR2_STATUS_ERROR_HPP
#define SYSTEM_ERROR2_STATUS_ERROR_HPP
/* Proposed SG14 status_code
(C) 2018 Niall Douglas <http://www.nedproductions.biz/> (5 commits)
File Created: Feb 2018


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

#ifndef SYSTEM_ERROR2_STATUS_CODE_HPP
#define SYSTEM_ERROR2_STATUS_CODE_HPP
/* Proposed SG14 status_code
(C) 2018 Niall Douglas <http://www.nedproductions.biz/> (5 commits)
File Created: Feb 2018


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

#ifndef SYSTEM_ERROR2_STATUS_CODE_DOMAIN_HPP
#define SYSTEM_ERROR2_STATUS_CODE_DOMAIN_HPP
/* Proposed SG14 status_code
(C) 2018 Niall Douglas <http://www.nedproductions.biz/> (5 commits)
File Created: Feb 2018


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

#ifndef SYSTEM_ERROR2_CONFIG_HPP
#define SYSTEM_ERROR2_CONFIG_HPP

// < 0.1 each
#include <cassert>
#include <cstddef>  // for size_t
#include <cstdlib>  // for free

// 0.22
#include <type_traits>

// 0.29
#include <atomic>

// 0.28 (0.15 of which is exception_ptr)
#include <exception>  // for std::exception
// <new> includes <exception>, <exception> includes <new>
#include <new>

// 0.01
#include <initializer_list>

#ifndef SYSTEM_ERROR2_CONSTEXPR14
#if 0 || __cplusplus >= 201400 || _MSC_VER >= 1910 /* VS2017 */
/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
#define SYSTEM_ERROR2_CONSTEXPR14 constexpr
#else
#define SYSTEM_ERROR2_CONSTEXPR14
#endif
#endif

#ifndef SYSTEM_ERROR2_NORETURN
#if 0 || (_HAS_CXX17 && _MSC_VER >= 1911 /* VS2017.3 */)
#define SYSTEM_ERROR2_NORETURN [[noreturn]]
#endif
#endif
#if !defined(SYSTEM_ERROR2_NORETURN)
#ifdef __has_cpp_attribute
#if __has_cpp_attribute(noreturn)
#define SYSTEM_ERROR2_NORETURN [[noreturn]]
#endif
#endif
#endif
#if !defined(SYSTEM_ERROR2_NORETURN)
#if defined(_MSC_VER)
#define SYSTEM_ERROR2_NORETURN __declspec(noreturn)
#elif defined(__GNUC__)
#define SYSTEM_ERROR2_NORETURN __attribute__((__noreturn__))
#else
#define SYSTEM_ERROR2_NORETURN
#endif
#endif
// GCCs before 7 don't grok [[noreturn]] virtual functions, and warn annoyingly
#if defined(__GNUC__) && !defined(__clang__) && __GNUC__ < 7
#undef SYSTEM_ERROR2_NORETURN
#define SYSTEM_ERROR2_NORETURN
#endif

#ifndef SYSTEM_ERROR2_NODISCARD
#if 0 || (_HAS_CXX17 && _MSC_VER >= 1911 /* VS2017.3 */)
#define SYSTEM_ERROR2_NODISCARD [[nodiscard]]
#endif
#endif
#ifndef SYSTEM_ERROR2_NODISCARD
#ifdef __has_cpp_attribute
#if __has_cpp_attribute(nodiscard)
#define SYSTEM_ERROR2_NODISCARD [[nodiscard]]
#endif
#elif defined(__clang__)
#define SYSTEM_ERROR2_NODISCARD __attribute__((warn_unused_result))
#elif defined(_MSC_VER)
// _Must_inspect_result_ expands into this
#define SYSTEM_ERROR2_NODISCARD                                                                                                                                                                                                                                                                                                  __declspec("SAL_name"                                                                                                                                                                                                                                                                                                                     "("                                                                                                                                                                                                                                                                                                                            "\"_Must_inspect_result_\""                                                                                                                                                                                                                                                                                                    ","                                                                                                                                                                                                                                                                                                                            "\"\""                                                                                                                                                                                                                                                                                                                         ","                                                                                                                                                                                                                                                                                                                            "\"2\""                                                                                                                                                                                                                                                                                                                        ")") __declspec("SAL_begin") __declspec("SAL_post") __declspec("SAL_mustInspect") __declspec("SAL_post") __declspec("SAL_checkReturn") __declspec("SAL_end")








#endif
#endif
#ifndef SYSTEM_ERROR2_NODISCARD
#define SYSTEM_ERROR2_NODISCARD
#endif

#ifndef SYSTEM_ERROR2_NAMESPACE
/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
#define SYSTEM_ERROR2_NAMESPACE system_error2
/*! AWAITING HUGO JSON CONVERSION TOOL */
#define SYSTEM_ERROR2_NAMESPACE_BEGIN                                                                                                                                                                                                                                                                                            namespace system_error2                                                                                                                                                                                                                                                                                                        {


/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
#define SYSTEM_ERROR2_NAMESPACE_END }
#endif

/*! AWAITING HUGO JSON CONVERSION TOOL */
SYSTEM_ERROR2_NAMESPACE_BEGIN

/*! AWAITING HUGO JSON CONVERSION TOOL */
namespace traits
{
  /*! AWAITING HUGO JSON CONVERSION TOOL
type definition  is_move_relocating. Potential doc page: NOT FOUND
*/


  template <class T> struct is_move_relocating
  {
    static constexpr bool value = std::is_trivially_copyable<T>::value;
  };
}  // namespace traits

namespace detail
{
  inline SYSTEM_ERROR2_CONSTEXPR14 size_t cstrlen(const char *str)
  {
    const char *end = nullptr;
    for(end = str; *end != 0; ++end)  // NOLINT
      ;
    return end - str;
  }

  /* A partially compliant implementation of C++20's std::bit_cast function contributed
  by Jesse Towner. TODO FIXME Replace with C++ 20 bit_cast when available.

  Our bit_cast is only guaranteed to be constexpr when both the input and output
  arguments are either integrals or enums. However, this covers most use cases
  since the vast majority of status_codes have an underlying type that is either
  an integral or enum.
  */








  template <class T> using is_integral_or_enum = std::integral_constant<bool, std::is_integral<T>::value || std::is_enum<T>::value>;

  template <class To, class From> using is_static_castable = std::integral_constant<bool, is_integral_or_enum<To>::value && is_integral_or_enum<From>::value>;

  template <class To, class From> using is_bit_castable = std::integral_constant<bool, sizeof(To) == sizeof(From) && traits::is_move_relocating<To>::value && traits::is_move_relocating<From>::value>;

  template <class To, class From> union bit_cast_union {
    From source;
    To target;
  };

  template <class To, class From, typename std::enable_if<is_bit_castable<To, From>::value && is_static_castable<To, From>::value, bool>::type = true> constexpr To bit_cast(const From &from) noexcept { return static_cast<To>(from); }

  template <class To, class From, typename std::enable_if<is_bit_castable<To, From>::value && !is_static_castable<To, From>::value, bool>::type = true> constexpr To bit_cast(const From &from) noexcept { return bit_cast_union<To, From>{from}.target; }

  /* erasure_cast performs a bit_cast with additional rules to handle types
  of differing sizes. For integral & enum types, it may perform a narrowing
  or widing conversion with static_cast if necessary, before doing the final
  conversion with bit_cast. When casting to or from non-integral, non-enum
  types it may insert the value into another object with extra padding bytes
  to satisfy bit_cast's preconditions that both types have the same size. */






  template <class To, class From> using is_erasure_castable = std::integral_constant<bool, traits::is_move_relocating<To>::value && traits::is_move_relocating<From>::value>;

  template <class T, bool = std::is_enum<T>::value> struct identity_or_underlying_type
  {
    using type = T;
  };
  template <class T> struct identity_or_underlying_type<T, true>
  {
    using type = typename std::underlying_type<T>::type;
  };

  template <class OfSize, class OfSign>
  using erasure_integer_type = typename std::conditional<std::is_signed<typename identity_or_underlying_type<OfSign>::type>::value, typename std::make_signed<typename identity_or_underlying_type<OfSize>::type>::type, typename std::make_unsigned<typename identity_or_underlying_type<OfSize>::type>::type>::type;

  template <class ErasedType, std::size_t N> struct padded_erasure_object
  {
    static_assert(traits::is_move_relocating<ErasedType>::value, "ErasedType must be TriviallyCopyable or MoveRelocating");
    static_assert(alignof(ErasedType) <= sizeof(ErasedType), "ErasedType must not be over-aligned");
    ErasedType value;
    char padding[N];
    constexpr explicit padded_erasure_object(const ErasedType &v) noexcept
        : value(v)
        , padding{}
    {
    }
  };

  template <class To, class From, typename std::enable_if<is_erasure_castable<To, From>::value && (sizeof(To) == sizeof(From)), bool>::type = true> constexpr To erasure_cast(const From &from) noexcept { return bit_cast<To>(from); }

  template <class To, class From, typename std::enable_if<is_erasure_castable<To, From>::value && is_static_castable<To, From>::value && (sizeof(To) < sizeof(From)), bool>::type = true> constexpr To erasure_cast(const From &from) noexcept { return static_cast<To>(bit_cast<erasure_integer_type<From, To>>(from)); }

  template <class To, class From, typename std::enable_if<is_erasure_castable<To, From>::value && is_static_castable<To, From>::value && (sizeof(To) > sizeof(From)), bool>::type = true> constexpr To erasure_cast(const From &from) noexcept { return bit_cast<To>(static_cast<erasure_integer_type<To, From>>(from)); }

  template <class To, class From, typename std::enable_if<is_erasure_castable<To, From>::value && !is_static_castable<To, From>::value && (sizeof(To) < sizeof(From)), bool>::type = true> constexpr To erasure_cast(const From &from) noexcept
  {
    return bit_cast<padded_erasure_object<To, sizeof(From) - sizeof(To)>>(from).value;
  }

  template <class To, class From, typename std::enable_if<is_erasure_castable<To, From>::value && !is_static_castable<To, From>::value && (sizeof(To) > sizeof(From)), bool>::type = true> constexpr To erasure_cast(const From &from) noexcept
  {
    return bit_cast<To>(padded_erasure_object<From, sizeof(To) - sizeof(From)>{from});
  }
}  // namespace detail
SYSTEM_ERROR2_NAMESPACE_END

#ifndef SYSTEM_ERROR2_FATAL
#include <cstdlib>  // for abort
#ifdef __APPLE__
#include <unistd.h>  // for write
#endif

SYSTEM_ERROR2_NAMESPACE_BEGIN
namespace detail
{
  namespace avoid_stdio_include
  {
#ifndef __APPLE__
    extern "C" ptrdiff_t write(int, const void *, size_t);
#endif
  }
  inline void do_fatal_exit(const char *msg)
  {
    using namespace avoid_stdio_include;
    write(2 /*stderr*/, msg, cstrlen(msg));
    write(2 /*stderr*/, "\n", 1);
    abort();
  }
}  // namespace detail
SYSTEM_ERROR2_NAMESPACE_END
/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
#define SYSTEM_ERROR2_FATAL(msg) ::SYSTEM_ERROR2_NAMESPACE::detail::do_fatal_exit(msg)
#endif

#endif
#include <cstring>  // for strchr

SYSTEM_ERROR2_NAMESPACE_BEGIN

/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
template <class DomainType> class status_code;
class _generic_code_domain;
/*! AWAITING HUGO JSON CONVERSION TOOL
type alias  generic_code. Potential doc page: NOT FOUND
*/
using generic_code = status_code<_generic_code_domain>;

namespace detail
{
  template <class StatusCode> class indirecting_domain;
  template <class T> struct status_code_sizer
  {
    void *a;
    T b;
  };
  template <class To, class From> struct type_erasure_is_safe
  {
    static constexpr bool value = traits::is_move_relocating<From>::value  //
                                  && (sizeof(status_code_sizer<From>) <= sizeof(status_code_sizer<To>));
  };
}  // namespace detail

/*! AWAITING HUGO JSON CONVERSION TOOL
type definition  status_code_domain. Potential doc page: NOT FOUND
*/
class status_code_domain
{
  template <class DomainType> friend class status_code;
  template <class StatusCode> friend class indirecting_domain;

public:
  /*! AWAITING HUGO JSON CONVERSION TOOL
type alias  unique_id_type. Potential doc page: NOT FOUND
*/


  using unique_id_type = unsigned long long;
  /*! AWAITING HUGO JSON CONVERSION TOOL
type definition  string_ref. Potential doc page: NOT FOUND
*/


  class string_ref
  {
  public:
    /*! AWAITING HUGO JSON CONVERSION TOOL
type alias  value_type. Potential doc page: `value_type &value() &`
*/


    using value_type = const char;
    /*! AWAITING HUGO JSON CONVERSION TOOL
type alias  size_type. Potential doc page: NOT FOUND
*/


    using size_type = size_t;
    /*! AWAITING HUGO JSON CONVERSION TOOL
type alias  pointer. Potential doc page: NOT FOUND
*/


    using pointer = const char *;
    /*! AWAITING HUGO JSON CONVERSION TOOL
type alias  const_pointer. Potential doc page: NOT FOUND
*/


    using const_pointer = const char *;
    /*! AWAITING HUGO JSON CONVERSION TOOL
type alias  iterator. Potential doc page: NOT FOUND
*/


    using iterator = const char *;
    /*! AWAITING HUGO JSON CONVERSION TOOL
type alias  const_iterator. Potential doc page: NOT FOUND
*/


    using const_iterator = const char *;

  protected:
    /*! AWAITING HUGO JSON CONVERSION TOOL
type definition  _thunk_op. Potential doc page: NOT FOUND
*/


    enum class _thunk_op
    {
      copy,
      move,
      destruct
    };
    /*! AWAITING HUGO JSON CONVERSION TOOL
type alias  _thunk_spec. Potential doc page: NOT FOUND
*/


    using _thunk_spec = void (*)(string_ref *dest, const string_ref *src, _thunk_op op);
#ifndef NDEBUG
  private:
    static void _checking_string_thunk(string_ref *dest, const string_ref *src, _thunk_op /*unused*/) noexcept
    {
      (void) dest;
      (void) src;
      assert(dest->_thunk == _checking_string_thunk);  // NOLINT
      assert(src == nullptr || src->_thunk == _checking_string_thunk);  // NOLINT
      // do nothing
    }

  protected:
#endif
    /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


    pointer _begin{}, _end{};
    /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


    void *_state[3]{};  // at least the size of a shared_ptr
    /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


    const _thunk_spec _thunk{nullptr};

    constexpr explicit string_ref(_thunk_spec thunk) noexcept : _thunk(thunk) {}

  public:
    /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


    SYSTEM_ERROR2_CONSTEXPR14 explicit string_ref(const char *str, size_type len = static_cast<size_type>(-1), void *state0 = nullptr, void *state1 = nullptr, void *state2 = nullptr,
#ifndef NDEBUG
                                                  _thunk_spec thunk = _checking_string_thunk
#else
                                                  _thunk_spec thunk = nullptr
#endif
                                                  ) noexcept : _begin(str),
                                                               _end((len == static_cast<size_type>(-1)) ? (str + detail::cstrlen(str)) : (str + len)),  // NOLINT
                                                               _state{state0, state1, state2},
                                                               _thunk(thunk)
    {
    }
    /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


    string_ref(const string_ref &o)
        : _begin(o._begin)
        , _end(o._end)
        , _state{o._state[0], o._state[1], o._state[2]}
        , _thunk(o._thunk)
    {
      if(_thunk != nullptr)
      {
        _thunk(this, &o, _thunk_op::copy);
      }
    }
    /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


    string_ref(string_ref &&o) noexcept : _begin(o._begin), _end(o._end), _state{o._state[0], o._state[1], o._state[2]}, _thunk(o._thunk)
    {
      if(_thunk != nullptr)
      {
        _thunk(this, &o, _thunk_op::move);
      }
    }
    /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


    string_ref &operator=(const string_ref &o)
    {
      if(this != &o)
      {
#if defined(__cpp_exceptions) || defined(__EXCEPTIONS) || defined(_CPPUNWIND)
        string_ref temp(static_cast<string_ref &&>(*this));
        this->~string_ref();
        try
        {
          new(this) string_ref(o);  // may throw
        }
        catch(...)
        {
          new(this) string_ref(static_cast<string_ref &&>(temp));
          throw;
        }
#else
        this->~string_ref();
        new(this) string_ref(o);
#endif
      }
      return *this;
    }
    /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


    string_ref &operator=(string_ref &&o) noexcept
    {
      if(this != &o)
      {
        this->~string_ref();
        new(this) string_ref(static_cast<string_ref &&>(o));
      }
      return *this;
    }
    /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


    ~string_ref()
    {
      if(_thunk != nullptr)
      {
        _thunk(this, nullptr, _thunk_op::destruct);
      }
      _begin = _end = nullptr;
    }

    /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


    SYSTEM_ERROR2_NODISCARD bool empty() const noexcept { return _begin == _end; }
    /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


    size_type size() const noexcept { return _end - _begin; }
    /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


    const_pointer c_str() const noexcept { return _begin; }
    /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


    const_pointer data() const noexcept { return _begin; }
    /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


    iterator begin() noexcept { return _begin; }
    /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


    const_iterator begin() const noexcept { return _begin; }
    /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


    const_iterator cbegin() const noexcept { return _begin; }
    /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


    iterator end() noexcept { return _end; }
    /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


    const_iterator end() const noexcept { return _end; }
    /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


    const_iterator cend() const noexcept { return _end; }
  };

  /*! AWAITING HUGO JSON CONVERSION TOOL
type definition  atomic_refcounted_string_ref. Potential doc page: NOT FOUND
*/


  class atomic_refcounted_string_ref : public string_ref
  {
    struct _allocated_msg
    {
      mutable std::atomic<unsigned> count{1};
    };
    _allocated_msg *&_msg() noexcept { return reinterpret_cast<_allocated_msg *&>(this->_state[0]); }                  // NOLINT
    const _allocated_msg *_msg() const noexcept { return reinterpret_cast<const _allocated_msg *>(this->_state[0]); }  // NOLINT

    static void _refcounted_string_thunk(string_ref *_dest, const string_ref *_src, _thunk_op op) noexcept
    {
      auto dest = static_cast<atomic_refcounted_string_ref *>(_dest);  // NOLINT
      auto src = static_cast<const atomic_refcounted_string_ref *>(_src);  // NOLINT
      (void) src;
      assert(dest->_thunk == _refcounted_string_thunk);  // NOLINT
      assert(src == nullptr || src->_thunk == _refcounted_string_thunk);  // NOLINT
      switch(op)
      {
      case _thunk_op::copy:
      {
        if(dest->_msg() != nullptr)
        {
          auto count = dest->_msg()->count.fetch_add(1, std::memory_order_relaxed);
          (void) count;
          assert(count != 0);  // NOLINT
        }
        return;
      }
      case _thunk_op::move:
      {
        assert(src);  // NOLINT
        auto msrc = const_cast<atomic_refcounted_string_ref *>(src);  // NOLINT
        msrc->_begin = msrc->_end = nullptr;
        msrc->_state[0] = msrc->_state[1] = msrc->_state[2] = nullptr;
        return;
      }
      case _thunk_op::destruct:
      {
        if(dest->_msg() != nullptr)
        {
          auto count = dest->_msg()->count.fetch_sub(1, std::memory_order_release);
          if(count == 1)
          {
            std::atomic_thread_fence(std::memory_order_acquire);
            free((void *) dest->_begin);  // NOLINT
            delete dest->_msg();  // NOLINT
          }
        }
      }
      }
    }

  public:
    /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


    explicit atomic_refcounted_string_ref(const char *str, size_type len = static_cast<size_type>(-1), void *state1 = nullptr, void *state2 = nullptr) noexcept : string_ref(str, len, new(std::nothrow) _allocated_msg, state1, state2, _refcounted_string_thunk)
    {
      if(_msg() == nullptr)
      {
        free((void *) this->_begin);  // NOLINT
        _msg() = nullptr;             // disabled
        this->_begin = "failed to get message from system";
        this->_end = strchr(this->_begin, 0);
        return;
      }
    }
  };

private:
  unique_id_type _id;

protected:
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  constexpr explicit status_code_domain(unique_id_type id) noexcept : _id(id) {}
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  status_code_domain(const status_code_domain &) = default;
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  status_code_domain(status_code_domain &&) = default;
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  status_code_domain &operator=(const status_code_domain &) = default;
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  status_code_domain &operator=(status_code_domain &&) = default;
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  ~status_code_domain() = default;

public:
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  constexpr bool operator==(const status_code_domain &o) const noexcept { return _id == o._id; }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  constexpr bool operator!=(const status_code_domain &o) const noexcept { return _id != o._id; }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  constexpr bool operator<(const status_code_domain &o) const noexcept { return _id < o._id; }

  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  constexpr unique_id_type id() const noexcept { return _id; }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  virtual string_ref name() const noexcept = 0;

protected:
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  virtual bool _do_failure(const status_code<void> &code) const noexcept = 0;
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  virtual bool _do_equivalent(const status_code<void> &code1, const status_code<void> &code2) const noexcept = 0;
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  virtual generic_code _generic_code(const status_code<void> &code) const noexcept = 0;
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  virtual string_ref _do_message(const status_code<void> &code) const noexcept = 0;
#if defined(_CPPUNWIND) || defined(__EXCEPTIONS) || 0
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  SYSTEM_ERROR2_NORETURN virtual void _do_throw_exception(const status_code<void> &code) const = 0;
#else
  // Keep a vtable slot for binary compatibility
  SYSTEM_ERROR2_NORETURN virtual void _do_throw_exception(const status_code<void> & /*code*/) const { abort(); }
#endif
  // For a `status_code<erased<T>>` only, copy from `src` to `dst`. Default implementation uses `memcpy()`.
  virtual void _do_erased_copy(status_code<void> &dst, const status_code<void> &src, size_t bytes) const { memcpy(&dst, &src, bytes); }  // NOLINT
  // For a `status_code<erased<T>>` only, destroy the erased value type. Default implementation does nothing.
  virtual void _do_erased_destroy(status_code<void> &code, size_t bytes) const noexcept  // NOLINT
  {
    (void) code;
    (void) bytes;
  }
};

SYSTEM_ERROR2_NAMESPACE_END

#endif
#if __cplusplus >= 201700 || _HAS_CXX17
// 0.26
#include <utility>  // for in_place

SYSTEM_ERROR2_NAMESPACE_BEGIN
using in_place_t = std::in_place_t;
using std::in_place;
SYSTEM_ERROR2_NAMESPACE_END

#else

SYSTEM_ERROR2_NAMESPACE_BEGIN
/*! AWAITING HUGO JSON CONVERSION TOOL
type definition  in_place_t. Potential doc page: NOT FOUND
*/
struct in_place_t
{
  explicit in_place_t() = default;
};
/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
constexpr in_place_t in_place{};
SYSTEM_ERROR2_NAMESPACE_END
#endif

SYSTEM_ERROR2_NAMESPACE_BEGIN

/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
namespace mixins
{
  template <class Base, class T> struct mixin : public Base
  {
    using Base::Base;
  };
}  // namespace mixins

/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
template <class ErasedType,  //
          typename std::enable_if<traits::is_move_relocating<ErasedType>::value, bool>::type = true>
struct erased
{
  using value_type = ErasedType;
};

namespace detail
{
  template <class T> struct is_status_code
  {
    static constexpr bool value = false;
  };
  template <class T> struct is_status_code<status_code<T>>
  {
    static constexpr bool value = true;
  };
  template <class T> struct is_erased_status_code
  {
    static constexpr bool value = false;
  };
  template <class T> struct is_erased_status_code<status_code<erased<T>>>
  {
    static constexpr bool value = true;
  };

  // From http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4436.pdf
  namespace impl
  {
    template <typename... Ts> struct make_void
    {
      using type = void;
    };
    template <typename... Ts> using void_t = typename make_void<Ts...>::type;
    template <class...> struct types
    {
      using type = types;
    };
    template <template <class...> class T, class types, class = void> struct test_apply
    {
      using type = void;
    };
    template <template <class...> class T, class... Ts> struct test_apply<T, types<Ts...>, void_t<T<Ts...>>>
    {
      using type = T<Ts...>;
    };
  }  // namespace impl
  template <template <class...> class T, class... Ts> using test_apply = impl::test_apply<T, impl::types<Ts...>>;

  template <class T, class... Args> using get_make_status_code_result = decltype(make_status_code(std::declval<T>(), std::declval<Args>()...));
  template <class... Args> using safe_get_make_status_code_result = test_apply<get_make_status_code_result, Args...>;
}  // namespace detail

/*! AWAITING HUGO JSON CONVERSION TOOL
type definition template <class T> is_status_code. Potential doc page: NOT FOUND
*/
template <class T> struct is_status_code
{
  static constexpr bool value = detail::is_status_code<typename std::decay<T>::type>::value || detail::is_erased_status_code<typename std::decay<T>::type>::value;
};

/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
template <> class status_code<void>
{
  template <class T> friend class status_code;

public:
  /*! AWAITING HUGO JSON CONVERSION TOOL
type alias  domain_type. Potential doc page: NOT FOUND
*/


  using domain_type = void;
  /*! AWAITING HUGO JSON CONVERSION TOOL
type alias  value_type. Potential doc page: `value_type &value() &`
*/


  using value_type = void;
  /*! AWAITING HUGO JSON CONVERSION TOOL
type alias  string_ref. Potential doc page: NOT FOUND
*/


  using string_ref = typename status_code_domain::string_ref;

protected:
  const status_code_domain *_domain{nullptr};

protected:
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  status_code() = default;
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  status_code(const status_code &) = default;
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  status_code(status_code &&) = default;
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  status_code &operator=(const status_code &) = default;
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  status_code &operator=(status_code &&) = default;
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  ~status_code() = default;

  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  constexpr explicit status_code(const status_code_domain *v) noexcept : _domain(v) {}

public:
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  constexpr const status_code_domain &domain() const noexcept { return *_domain; }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  SYSTEM_ERROR2_NODISCARD constexpr bool empty() const noexcept { return _domain == nullptr; }

  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  string_ref message() const noexcept { return (_domain != nullptr) ? _domain->_do_message(*this) : string_ref("(empty)"); }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  bool success() const noexcept { return (_domain != nullptr) ? !_domain->_do_failure(*this) : false; }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  bool failure() const noexcept { return (_domain != nullptr) ? _domain->_do_failure(*this) : false; }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  template <class T> bool strictly_equivalent(const status_code<T> &o) const noexcept
  {
    if(_domain && o._domain)
    {
      return _domain->_do_equivalent(*this, o);
    }
    // If we are both empty, we are equivalent
    if(!_domain && !o._domain)
    {
      return true;  // NOLINT
    }
    // Otherwise not equivalent
    return false;
  }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  template <class T> inline bool equivalent(const status_code<T> &o) const noexcept;
#if defined(_CPPUNWIND) || defined(__EXCEPTIONS) || 0
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  SYSTEM_ERROR2_NORETURN void throw_exception() const { _domain->_do_throw_exception(*this); }
#endif
};

namespace detail
{
  template <class DomainType> struct get_domain_value_type
  {
    using domain_type = DomainType;
    using value_type = typename domain_type::value_type;
  };
  template <class ErasedType> struct get_domain_value_type<erased<ErasedType>>
  {
    using domain_type = status_code_domain;
    using value_type = ErasedType;
  };
  template <class DomainType> class status_code_storage : public status_code<void>
  {
    using _base = status_code<void>;

  public:
    /*! AWAITING HUGO JSON CONVERSION TOOL
type alias  domain_type. Potential doc page: NOT FOUND
*/


    using domain_type = typename get_domain_value_type<DomainType>::domain_type;
    /*! AWAITING HUGO JSON CONVERSION TOOL
type alias  value_type. Potential doc page: `value_type &value() &`
*/


    using value_type = typename get_domain_value_type<DomainType>::value_type;
    /*! AWAITING HUGO JSON CONVERSION TOOL
type alias  string_ref. Potential doc page: NOT FOUND
*/


    using string_ref = typename domain_type::string_ref;

#ifndef NDEBUG
    static_assert(std::is_move_constructible<value_type>::value || std::is_copy_constructible<value_type>::value, "DomainType::value_type is neither move nor copy constructible!");
    static_assert(!std::is_default_constructible<value_type>::value || std::is_nothrow_default_constructible<value_type>::value, "DomainType::value_type is not nothrow default constructible!");
    static_assert(!std::is_move_constructible<value_type>::value || std::is_nothrow_move_constructible<value_type>::value, "DomainType::value_type is not nothrow move constructible!");
    static_assert(std::is_nothrow_destructible<value_type>::value, "DomainType::value_type is not nothrow destructible!");
#endif

    // Replace the type erased implementations with type aware implementations for better codegen
    /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


    constexpr const domain_type &domain() const noexcept { return *static_cast<const domain_type *>(this->_domain); }

    /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


    SYSTEM_ERROR2_CONSTEXPR14 void clear() noexcept
    {
      this->_value.~value_type();
      this->_domain = nullptr;
      new(&this->_value) value_type();
    }

#if __cplusplus >= 201400 || _MSC_VER >= 1910 /* VS2017 */
    /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


    constexpr value_type &value() & noexcept { return this->_value; }
    /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


    constexpr value_type &&value() && noexcept { return this->_value; }
#endif
    /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


    constexpr const value_type &value() const &noexcept { return this->_value; }
    /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


    constexpr const value_type &&value() const &&noexcept { return this->_value; }

  protected:
    status_code_storage() = default;
    status_code_storage(const status_code_storage &) = default;
    SYSTEM_ERROR2_CONSTEXPR14 status_code_storage(status_code_storage &&o) noexcept : _base(static_cast<status_code_storage &&>(o)), _value(static_cast<status_code_storage &&>(o)._value) { o._domain = nullptr; }
    status_code_storage &operator=(const status_code_storage &) = default;
    SYSTEM_ERROR2_CONSTEXPR14 status_code_storage &operator=(status_code_storage &&o) noexcept
    {
      this->~status_code_storage();
      new(this) status_code_storage(static_cast<status_code_storage &&>(o));
      return *this;
    }
    ~status_code_storage() = default;

    value_type _value{};
    struct _value_type_constructor
    {
    };
    template <class... Args>
    constexpr status_code_storage(_value_type_constructor /*unused*/, const status_code_domain *v, Args &&... args)
        : _base(v)
        , _value(static_cast<Args &&>(args)...)
    {
    }
  };
}  // namespace detail

/*! AWAITING HUGO JSON CONVERSION TOOL
type definition template <class DomainType> status_code. Potential doc page: NOT FOUND
*/
template <class DomainType> class status_code : public mixins::mixin<detail::status_code_storage<DomainType>, DomainType>
{
  template <class T> friend class status_code;
  using _base = mixins::mixin<detail::status_code_storage<DomainType>, DomainType>;

public:
  /*! AWAITING HUGO JSON CONVERSION TOOL
type alias  domain_type. Potential doc page: NOT FOUND
*/


  using domain_type = DomainType;
  /*! AWAITING HUGO JSON CONVERSION TOOL
type alias  value_type. Potential doc page: `value_type &value() &`
*/


  using value_type = typename domain_type::value_type;
  /*! AWAITING HUGO JSON CONVERSION TOOL
type alias  string_ref. Potential doc page: NOT FOUND
*/


  using string_ref = typename domain_type::string_ref;

public:
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  status_code() = default;
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  status_code(const status_code &) = default;
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  status_code(status_code &&) = default;  // NOLINT
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  status_code &operator=(const status_code &) = default;
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  status_code &operator=(status_code &&) = default;  // NOLINT
  ~status_code() = default;

  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  SYSTEM_ERROR2_CONSTEXPR14 status_code clone() const { return *this; }

  /***** KEEP THESE IN SYNC WITH ERRORED_STATUS_CODE *****/
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  template <class T, class... Args,                                                                            //
            class MakeStatusCodeResult = typename detail::safe_get_make_status_code_result<T, Args...>::type,  // Safe ADL lookup of make_status_code(), returns void if not found
            typename std::enable_if<!std::is_same<typename std::decay<T>::type, status_code>::value            // not copy/move of self
                                    && !std::is_same<typename std::decay<T>::type, in_place_t>::value          // not in_place_t
                                    && is_status_code<MakeStatusCodeResult>::value                             // ADL makes a status code
                                    && std::is_constructible<status_code, MakeStatusCodeResult>::value,        // ADLed status code is compatible

                                    bool>::type = true>
  constexpr status_code(T &&v, Args &&... args) noexcept(noexcept(make_status_code(std::declval<T>(), std::declval<Args>()...)))  // NOLINT
  : status_code(make_status_code(static_cast<T &&>(v), static_cast<Args &&>(args)...))
  {
  }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  template <class... Args>
  constexpr explicit status_code(in_place_t /*unused */, Args &&... args) noexcept(std::is_nothrow_constructible<value_type, Args &&...>::value)
      : _base(typename _base::_value_type_constructor{}, &domain_type::get(), static_cast<Args &&>(args)...)
  {
  }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  template <class T, class... Args>
  constexpr explicit status_code(in_place_t /*unused */, std::initializer_list<T> il, Args &&... args) noexcept(std::is_nothrow_constructible<value_type, std::initializer_list<T>, Args &&...>::value)
      : _base(typename _base::_value_type_constructor{}, &domain_type::get(), il, static_cast<Args &&>(args)...)
  {
  }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  constexpr explicit status_code(const value_type &v) noexcept(std::is_nothrow_copy_constructible<value_type>::value)
      : _base(typename _base::_value_type_constructor{}, &domain_type::get(), v)
  {
  }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  constexpr explicit status_code(value_type &&v) noexcept(std::is_nothrow_move_constructible<value_type>::value)
      : _base(typename _base::_value_type_constructor{}, &domain_type::get(), static_cast<value_type &&>(v))
  {
  }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  template <class ErasedType,  //
            typename std::enable_if<detail::type_erasure_is_safe<ErasedType, value_type>::value, bool>::type = true>
  constexpr explicit status_code(const status_code<erased<ErasedType>> &v) noexcept(std::is_nothrow_copy_constructible<value_type>::value)
      : status_code(detail::erasure_cast<value_type>(v.value()))
  {
#if __cplusplus >= 201400
    assert(v.domain() == this->domain());
#endif
  }

  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  SYSTEM_ERROR2_CONSTEXPR14 status_code &operator=(const value_type &v) noexcept(std::is_nothrow_copy_assignable<value_type>::value)
  {
    this->_value = v;
    return *this;
  }

  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  string_ref message() const noexcept { return this->_domain ? string_ref(this->domain()._do_message(*this)) : string_ref("(empty)"); }
};

namespace traits
{
  template <class DomainType> struct is_move_relocating<status_code<DomainType>>
  {
    static constexpr bool value = is_move_relocating<typename DomainType::value_type>::value;
  };
}  // namespace traits


/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
template <class ErasedType> class status_code<erased<ErasedType>> : public mixins::mixin<detail::status_code_storage<erased<ErasedType>>, erased<ErasedType>>
{
  template <class T> friend class status_code;
  using _base = mixins::mixin<detail::status_code_storage<erased<ErasedType>>, erased<ErasedType>>;

public:
  /*! AWAITING HUGO JSON CONVERSION TOOL
type alias  domain_type. Potential doc page: NOT FOUND
*/


  using domain_type = void;
  /*! AWAITING HUGO JSON CONVERSION TOOL
type alias  value_type. Potential doc page: `value_type &value() &`
*/


  using value_type = ErasedType;
  /*! AWAITING HUGO JSON CONVERSION TOOL
type alias  string_ref. Potential doc page: NOT FOUND
*/


  using string_ref = typename _base::string_ref;

public:
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  status_code() = default;
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  status_code(const status_code &) = delete;
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  status_code(status_code &&) = default;  // NOLINT
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  status_code &operator=(const status_code &) = delete;
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  status_code &operator=(status_code &&) = default;  // NOLINT
  ~status_code()
  {
    if(nullptr != this->_domain)
    {
      this->_domain->_do_erased_destroy(*this, sizeof(*this));
    }
  }

  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  status_code clone() const
  {
    if(nullptr == this->_domain)
    {
      return {};
    }
    status_code x;
    this->_domain->_do_erased_copy(x, *this, sizeof(*this));
    return x;
  }

  /***** KEEP THESE IN SYNC WITH ERRORED_STATUS_CODE *****/
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  template <class DomainType,                                                                              //
            typename std::enable_if<!detail::is_erased_status_code<status_code<DomainType>>::value         //
                                    && std::is_trivially_copyable<typename DomainType::value_type>::value  //
                                    && detail::type_erasure_is_safe<value_type, typename DomainType::value_type>::value,
                                    bool>::type = true>
  constexpr status_code(const status_code<DomainType> &v) noexcept  // NOLINT
      : _base(typename _base::_value_type_constructor{}, &v.domain(), detail::erasure_cast<value_type>(v.value()))
  {
  }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  template <class DomainType,  //
            typename std::enable_if<detail::type_erasure_is_safe<value_type, typename DomainType::value_type>::value, bool>::type = true>
  SYSTEM_ERROR2_CONSTEXPR14 status_code(status_code<DomainType> &&v) noexcept  // NOLINT
      : _base(typename _base::_value_type_constructor{}, &v.domain(), detail::erasure_cast<value_type>(v.value()))
  {
    v._domain = nullptr;
  }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  template <class T, class... Args,                                                                            //
            class MakeStatusCodeResult = typename detail::safe_get_make_status_code_result<T, Args...>::type,  // Safe ADL lookup of make_status_code(), returns void if not found
            typename std::enable_if<!std::is_same<typename std::decay<T>::type, status_code>::value            // not copy/move of self
                                    && !std::is_same<typename std::decay<T>::type, value_type>::value          // not copy/move of value type
                                    && is_status_code<MakeStatusCodeResult>::value                             // ADL makes a status code
                                    && std::is_constructible<status_code, MakeStatusCodeResult>::value,        // ADLed status code is compatible
                                    bool>::type = true>
  constexpr status_code(T &&v, Args &&... args) noexcept(noexcept(make_status_code(std::declval<T>(), std::declval<Args>()...)))  // NOLINT
  : status_code(make_status_code(static_cast<T &&>(v), static_cast<Args &&>(args)...))
  {
  }

  /**** By rights ought to be removed in any formal standard ****/
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  SYSTEM_ERROR2_CONSTEXPR14 void clear() noexcept { *this = status_code(); }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  constexpr value_type value() const noexcept { return this->_value; }
};

namespace traits
{
  template <class ErasedType> struct is_move_relocating<status_code<erased<ErasedType>>>
  {
    static constexpr bool value = true;
  };
}  // namespace traits

SYSTEM_ERROR2_NAMESPACE_END

#endif
#include <exception>  // for std::exception

SYSTEM_ERROR2_NAMESPACE_BEGIN

/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
template <class DomainType> class status_error;

/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
template <> class status_error<void> : public std::exception
{
protected:
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  status_error() = default;
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  status_error(const status_error &) = default;
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  status_error(status_error &&) = default;
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  status_error &operator=(const status_error &) = default;
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  status_error &operator=(status_error &&) = default;
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  ~status_error() override = default;

public:
  /*! AWAITING HUGO JSON CONVERSION TOOL
type alias  domain_type. Potential doc page: NOT FOUND
*/


  using domain_type = void;
  /*! AWAITING HUGO JSON CONVERSION TOOL
type alias  status_code_type. Potential doc page: NOT FOUND
*/


  using status_code_type = status_code<void>;
};

/*! AWAITING HUGO JSON CONVERSION TOOL
type definition template <class DomainType> status_error. Potential doc page: NOT FOUND
*/
template <class DomainType> class status_error : public status_error<void>
{
  status_code<DomainType> _code;
  typename DomainType::string_ref _msgref;

public:
  /*! AWAITING HUGO JSON CONVERSION TOOL
type alias  domain_type. Potential doc page: NOT FOUND
*/


  using domain_type = DomainType;
  /*! AWAITING HUGO JSON CONVERSION TOOL
type alias  status_code_type. Potential doc page: NOT FOUND
*/


  using status_code_type = status_code<DomainType>;

  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  explicit status_error(status_code<DomainType> code)
      : _code(static_cast<status_code<DomainType> &&>(code))
      , _msgref(_code.message())
  {
  }

  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  virtual const char *what() const noexcept override { return _msgref.c_str(); }  // NOLINT

  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  const status_code_type &code() const & { return _code; }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  status_code_type &code() & { return _code; }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  const status_code_type &&code() const && { return _code; }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  status_code_type &&code() && { return _code; }
};

SYSTEM_ERROR2_NAMESPACE_END

#endif
#include <cerrno>  // for error constants

SYSTEM_ERROR2_NAMESPACE_BEGIN

/*! AWAITING HUGO JSON CONVERSION TOOL
type definition  errc. Potential doc page: `std::error_code error_from_exception(std::exception_ptr &&ep = std::current_exception(), std::error_code not_matched = std::make_error_code(std::errc::resource_unavailable_try_again)) noexcept`
*/
enum class errc : int
{
  success = 0,
  unknown = -1,

  address_family_not_supported = EAFNOSUPPORT,
  address_in_use = EADDRINUSE,
  address_not_available = EADDRNOTAVAIL,
  already_connected = EISCONN,
  argument_list_too_long = E2BIG,
  argument_out_of_domain = EDOM,
  bad_address = EFAULT,
  bad_file_descriptor = EBADF,
  bad_message = EBADMSG,
  broken_pipe = EPIPE,
  connection_aborted = ECONNABORTED,
  connection_already_in_progress = EALREADY,
  connection_refused = ECONNREFUSED,
  connection_reset = ECONNRESET,
  cross_device_link = EXDEV,
  destination_address_required = EDESTADDRREQ,
  device_or_resource_busy = EBUSY,
  directory_not_empty = ENOTEMPTY,
  executable_format_error = ENOEXEC,
  file_exists = EEXIST,
  file_too_large = EFBIG,
  filename_too_long = ENAMETOOLONG,
  function_not_supported = ENOSYS,
  host_unreachable = EHOSTUNREACH,
  identifier_removed = EIDRM,
  illegal_byte_sequence = EILSEQ,
  inappropriate_io_control_operation = ENOTTY,
  interrupted = EINTR,
  invalid_argument = EINVAL,
  invalid_seek = ESPIPE,
  io_error = EIO,
  is_a_directory = EISDIR,
  message_size = EMSGSIZE,
  network_down = ENETDOWN,
  network_reset = ENETRESET,
  network_unreachable = ENETUNREACH,
  no_buffer_space = ENOBUFS,
  no_child_process = ECHILD,
  no_link = ENOLINK,
  no_lock_available = ENOLCK,
  no_message = ENOMSG,
  no_protocol_option = ENOPROTOOPT,
  no_space_on_device = ENOSPC,
  no_stream_resources = ENOSR,
  no_such_device_or_address = ENXIO,
  no_such_device = ENODEV,
  no_such_file_or_directory = ENOENT,
  no_such_process = ESRCH,
  not_a_directory = ENOTDIR,
  not_a_socket = ENOTSOCK,
  not_a_stream = ENOSTR,
  not_connected = ENOTCONN,
  not_enough_memory = ENOMEM,
  not_supported = ENOTSUP,
  operation_canceled = ECANCELED,
  operation_in_progress = EINPROGRESS,
  operation_not_permitted = EPERM,
  operation_not_supported = EOPNOTSUPP,
  operation_would_block = EWOULDBLOCK,
  owner_dead = EOWNERDEAD,
  permission_denied = EACCES,
  protcol_error = EPROTO,
  protocol_not_supported = EPROTONOSUPPORT,
  read_only_file_system = EROFS,
  resource_deadlock_would_occur = EDEADLK,
  resource_unavailable_try_again = EAGAIN,
  result_out_of_range = ERANGE,
  state_not_recoverable = ENOTRECOVERABLE,
  stream_timeout = ETIME,
  text_file_busy = ETXTBSY,
  timed_out = ETIMEDOUT,
  too_many_files_open_in_system = ENFILE,
  too_many_files_open = EMFILE,
  too_many_links = EMLINK,
  too_many_symbolic_link_levels = ELOOP,
  value_too_large = EOVERFLOW,
  wrong_protocol_type = EPROTOTYPE
};

namespace detail
{
  struct generic_code_messages
  {
    // libc++ defines missing errc macros to integers in the 9xxx range
    // As much as 10,000 seems wasteful, bear in mind this is all constexpr
    // and on C++ 14 or later this entire construct disappears.
    const char *msgs[(ETIME >= 256) ? 10000 : 256];
    SYSTEM_ERROR2_CONSTEXPR14 size_t size() const { return sizeof(msgs) / sizeof(*msgs); }  // NOLINT
    SYSTEM_ERROR2_CONSTEXPR14 const char *operator[](int i) const { return (i < 0 || i >= static_cast<int>(size()) || nullptr == msgs[i]) ? "unknown" : msgs[i]; }  // NOLINT
    SYSTEM_ERROR2_CONSTEXPR14 generic_code_messages()
        : msgs{}
    {
      msgs[0] = "Success";

      msgs[EAFNOSUPPORT] = "Address family not supported by protocol";
      msgs[EADDRINUSE] = "Address already in use";
      msgs[EADDRNOTAVAIL] = "Cannot assign requested address";
      msgs[EISCONN] = "Transport endpoint is already connected";
      msgs[E2BIG] = "Argument list too long";
      msgs[EDOM] = "Numerical argument out of domain";
      msgs[EFAULT] = "Bad address";
      msgs[EBADF] = "Bad file descriptor";
      msgs[EBADMSG] = "Bad message";
      msgs[EPIPE] = "Broken pipe";
      msgs[ECONNABORTED] = "Software caused connection abort";
      msgs[EALREADY] = "Operation already in progress";
      msgs[ECONNREFUSED] = "Connection refused";
      msgs[ECONNRESET] = "Connection reset by peer";
      msgs[EXDEV] = "Invalid cross-device link";
      msgs[EDESTADDRREQ] = "Destination address required";
      msgs[EBUSY] = "Device or resource busy";
      msgs[ENOTEMPTY] = "Directory not empty";
      msgs[ENOEXEC] = "Exec format error";
      msgs[EEXIST] = "File exists";
      msgs[EFBIG] = "File too large";
      msgs[ENAMETOOLONG] = "File name too long";
      msgs[ENOSYS] = "Function not implemented";
      msgs[EHOSTUNREACH] = "No route to host";
      msgs[EIDRM] = "Identifier removed";
      msgs[EILSEQ] = "Invalid or incomplete multibyte or wide character";
      msgs[ENOTTY] = "Inappropriate ioctl for device";
      msgs[EINTR] = "Interrupted system call";
      msgs[EINVAL] = "Invalid argument";
      msgs[ESPIPE] = "Illegal seek";
      msgs[EIO] = "Input/output error";
      msgs[EISDIR] = "Is a directory";
      msgs[EMSGSIZE] = "Message too long";
      msgs[ENETDOWN] = "Network is down";
      msgs[ENETRESET] = "Network dropped connection on reset";
      msgs[ENETUNREACH] = "Network is unreachable";
      msgs[ENOBUFS] = "No buffer space available";
      msgs[ECHILD] = "No child processes";
      msgs[ENOLINK] = "Link has been severed";
      msgs[ENOLCK] = "No locks available";
      msgs[ENOMSG] = "No message of desired type";
      msgs[ENOPROTOOPT] = "Protocol not available";
      msgs[ENOSPC] = "No space left on device";
      msgs[ENOSR] = "Out of streams resources";
      msgs[ENXIO] = "No such device or address";
      msgs[ENODEV] = "No such device";
      msgs[ENOENT] = "No such file or directory";
      msgs[ESRCH] = "No such process";
      msgs[ENOTDIR] = "Not a directory";
      msgs[ENOTSOCK] = "Socket operation on non-socket";
      msgs[ENOSTR] = "Device not a stream";
      msgs[ENOTCONN] = "Transport endpoint is not connected";
      msgs[ENOMEM] = "Cannot allocate memory";
      msgs[ENOTSUP] = "Operation not supported";
      msgs[ECANCELED] = "Operation canceled";
      msgs[EINPROGRESS] = "Operation now in progress";
      msgs[EPERM] = "Operation not permitted";
      msgs[EOPNOTSUPP] = "Operation not supported";
      msgs[EWOULDBLOCK] = "Resource temporarily unavailable";
      msgs[EOWNERDEAD] = "Owner died";
      msgs[EACCES] = "Permission denied";
      msgs[EPROTO] = "Protocol error";
      msgs[EPROTONOSUPPORT] = "Protocol not supported";
      msgs[EROFS] = "Read-only file system";
      msgs[EDEADLK] = "Resource deadlock avoided";
      msgs[EAGAIN] = "Resource temporarily unavailable";
      msgs[ERANGE] = "Numerical result out of range";
      msgs[ENOTRECOVERABLE] = "State not recoverable";
      msgs[ETIME] = "Timer expired";
      msgs[ETXTBSY] = "Text file busy";
      msgs[ETIMEDOUT] = "Connection timed out";
      msgs[ENFILE] = "Too many open files in system";
      msgs[EMFILE] = "Too many open files";
      msgs[EMLINK] = "Too many links";
      msgs[ELOOP] = "Too many levels of symbolic links";
      msgs[EOVERFLOW] = "Value too large for defined data type";
      msgs[EPROTOTYPE] = "Protocol wrong type for socket";
    }
  };
}  // namespace detail

/*! AWAITING HUGO JSON CONVERSION TOOL
type definition  _generic_code_domain. Potential doc page: NOT FOUND
*/
class _generic_code_domain : public status_code_domain
{
  template <class> friend class status_code;
  template <class StatusCode> friend class detail::indirecting_domain;
  using _base = status_code_domain;

public:
  /*! AWAITING HUGO JSON CONVERSION TOOL
type alias  value_type. Potential doc page: `value_type &value() &`
*/


  using value_type = errc;
  using string_ref = _base::string_ref;

public:
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  constexpr explicit _generic_code_domain(typename _base::unique_id_type id = 0x746d6354f4f733e9) noexcept : _base(id) {}
  _generic_code_domain(const _generic_code_domain &) = default;
  _generic_code_domain(_generic_code_domain &&) = default;
  _generic_code_domain &operator=(const _generic_code_domain &) = default;
  _generic_code_domain &operator=(_generic_code_domain &&) = default;
  ~_generic_code_domain() = default;

  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  static inline constexpr const _generic_code_domain &get();

  virtual _base::string_ref name() const noexcept override { return string_ref("generic domain"); }  // NOLINT
protected:
  virtual bool _do_failure(const status_code<void> &code) const noexcept override  // NOLINT
  {
    assert(code.domain() == *this);  // NOLINT
    return static_cast<const generic_code &>(code).value() != errc::success;  // NOLINT
  }
  virtual bool _do_equivalent(const status_code<void> &code1, const status_code<void> &code2) const noexcept override  // NOLINT
  {
    assert(code1.domain() == *this);  // NOLINT
    const auto &c1 = static_cast<const generic_code &>(code1);  // NOLINT
    if(code2.domain() == *this)
    {
      const auto &c2 = static_cast<const generic_code &>(code2);  // NOLINT
      return c1.value() == c2.value();
    }
    return false;
  }
  virtual generic_code _generic_code(const status_code<void> &code) const noexcept override  // NOLINT
  {
    assert(code.domain() == *this);  // NOLINT
    return static_cast<const generic_code &>(code);  // NOLINT
  }
  virtual _base::string_ref _do_message(const status_code<void> &code) const noexcept override  // NOLINT
  {
    assert(code.domain() == *this);  // NOLINT
    const auto &c = static_cast<const generic_code &>(code);  // NOLINT
    static SYSTEM_ERROR2_CONSTEXPR14 detail::generic_code_messages msgs;
    return string_ref(msgs[static_cast<int>(c.value())]);
  }
#if defined(_CPPUNWIND) || defined(__EXCEPTIONS) || 0
  SYSTEM_ERROR2_NORETURN virtual void _do_throw_exception(const status_code<void> &code) const override  // NOLINT
  {
    assert(code.domain() == *this);  // NOLINT
    const auto &c = static_cast<const generic_code &>(code);  // NOLINT
    throw status_error<_generic_code_domain>(c);
  }
#endif
};
/*! AWAITING HUGO JSON CONVERSION TOOL
type alias  generic_error. Potential doc page: NOT FOUND
*/
using generic_error = status_error<_generic_code_domain>;
/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
constexpr _generic_code_domain generic_code_domain;
inline constexpr const _generic_code_domain &_generic_code_domain::get()
{
  return generic_code_domain;
}
// Enable implicit construction of generic_code from errc
SYSTEM_ERROR2_CONSTEXPR14 inline generic_code make_status_code(errc c) noexcept
{
  return generic_code(in_place, c);
}


/*************************************************************************************************************/


template <class T> inline bool status_code<void>::equivalent(const status_code<T> &o) const noexcept
{
  if(_domain && o._domain)
  {
    if(_domain->_do_equivalent(*this, o))
    {
      return true;
    }
    if(o._domain->_do_equivalent(o, *this))
    {
      return true;
    }
    generic_code c1 = o._domain->_generic_code(o);
    if(c1.value() != errc::unknown && _domain->_do_equivalent(*this, c1))
    {
      return true;
    }
    generic_code c2 = _domain->_generic_code(*this);
    if(c2.value() != errc::unknown && o._domain->_do_equivalent(o, c2))
    {
      return true;
    }
  }
  // If we are both empty, we are equivalent, otherwise not equivalent
  return (!_domain && !o._domain);
}
/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
template <class DomainType1, class DomainType2> inline bool operator==(const status_code<DomainType1> &a, const status_code<DomainType2> &b) noexcept
{
  return a.equivalent(b);
}
/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
template <class DomainType1, class DomainType2> inline bool operator!=(const status_code<DomainType1> &a, const status_code<DomainType2> &b) noexcept
{
  return !a.equivalent(b);
}
/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
template <class DomainType1, class T,                                                                       //
          class MakeStatusCodeResult = typename detail::safe_get_make_status_code_result<const T &>::type,  // Safe ADL lookup of make_status_code(), returns void if not found
          typename std::enable_if<is_status_code<MakeStatusCodeResult>::value, bool>::type = true>          // ADL makes a status code
inline bool
operator==(const status_code<DomainType1> &a, const T &b)
{
  return a.equivalent(make_status_code(b));
}
/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
template <class T, class DomainType1,                                                                       //
          class MakeStatusCodeResult = typename detail::safe_get_make_status_code_result<const T &>::type,  // Safe ADL lookup of make_status_code(), returns void if not found
          typename std::enable_if<is_status_code<MakeStatusCodeResult>::value, bool>::type = true>          // ADL makes a status code
inline bool
operator==(const T &a, const status_code<DomainType1> &b)
{
  return b.equivalent(make_status_code(a));
}
/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
template <class DomainType1, class T,                                                                       //
          class MakeStatusCodeResult = typename detail::safe_get_make_status_code_result<const T &>::type,  // Safe ADL lookup of make_status_code(), returns void if not found
          typename std::enable_if<is_status_code<MakeStatusCodeResult>::value, bool>::type = true>          // ADL makes a status code
inline bool
operator!=(const status_code<DomainType1> &a, const T &b)
{
  return !a.equivalent(make_status_code(b));
}
/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
template <class T, class DomainType1,                                                                       //
          class MakeStatusCodeResult = typename detail::safe_get_make_status_code_result<const T &>::type,  // Safe ADL lookup of make_status_code(), returns void if not found
          typename std::enable_if<is_status_code<MakeStatusCodeResult>::value, bool>::type = true>          // ADL makes a status code
inline bool
operator!=(const T &a, const status_code<DomainType1> &b)
{
  return !b.equivalent(make_status_code(a));
}

SYSTEM_ERROR2_NAMESPACE_END

#endif
/* Pointer to a SG14 status_code
(C) 2018 Niall Douglas <http://www.nedproductions.biz/> (5 commits)
File Created: Sep 2018


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

#ifndef SYSTEM_ERROR2_STATUS_CODE_PTR_HPP
#define SYSTEM_ERROR2_STATUS_CODE_PTR_HPP



SYSTEM_ERROR2_NAMESPACE_BEGIN

namespace detail
{
  template <class StatusCode> class indirecting_domain : public status_code_domain
  {
    template <class DomainType> friend class status_code;
    using _base = status_code_domain;

  public:
    using value_type = StatusCode *;
    using _base::string_ref;

    constexpr indirecting_domain() noexcept : _base(0xc44f7bdeb2cc50e9 ^ typename StatusCode::domain_type().id() /* unique-ish based on domain's unique id */) {}
    indirecting_domain(const indirecting_domain &) = default;
    indirecting_domain(indirecting_domain &&) = default;  // NOLINT
    indirecting_domain &operator=(const indirecting_domain &) = default;
    indirecting_domain &operator=(indirecting_domain &&) = default;  // NOLINT
    ~indirecting_domain() = default;

#if __cplusplus < 201402 && !defined(_MSC_VER)
    static inline const indirecting_domain &get()
    {
      static indirecting_domain v;
      return v;
    }
#else
    static inline constexpr const indirecting_domain &get();
#endif

    virtual string_ref name() const noexcept override { return typename StatusCode::domain_type().name(); }  // NOLINT
  protected:
    using _mycode = status_code<indirecting_domain>;
    virtual bool _do_failure(const status_code<void> &code) const noexcept override  // NOLINT
    {
      assert(code.domain() == *this);
      const auto &c = static_cast<const _mycode &>(code);  // NOLINT
      return typename StatusCode::domain_type()._do_failure(*c.value());
    }
    virtual bool _do_equivalent(const status_code<void> &code1, const status_code<void> &code2) const noexcept override  // NOLINT
    {
      assert(code1.domain() == *this);
      const auto &c1 = static_cast<const _mycode &>(code1);  // NOLINT
      return typename StatusCode::domain_type()._do_equivalent(*c1.value(), code2);
    }
    virtual generic_code _generic_code(const status_code<void> &code) const noexcept override  // NOLINT
    {
      assert(code.domain() == *this);
      const auto &c = static_cast<const _mycode &>(code);  // NOLINT
      return typename StatusCode::domain_type()._generic_code(*c.value());
    }
    virtual string_ref _do_message(const status_code<void> &code) const noexcept override  // NOLINT
    {
      assert(code.domain() == *this);
      const auto &c = static_cast<const _mycode &>(code);  // NOLINT
      return typename StatusCode::domain_type()._do_message(*c.value());
    }
#if defined(_CPPUNWIND) || defined(__EXCEPTIONS) || 0
    SYSTEM_ERROR2_NORETURN virtual void _do_throw_exception(const status_code<void> &code) const override  // NOLINT
    {
      assert(code.domain() == *this);
      const auto &c = static_cast<const _mycode &>(code);  // NOLINT
      typename StatusCode::domain_type()._do_throw_exception(*c.value());
    }
#endif
    virtual void _do_erased_copy(status_code<void> &dst, const status_code<void> &src, size_t /*unused*/) const override  // NOLINT
    {
      assert(dst.domain() == *this);
      assert(src.domain() == *this);
      auto &d = static_cast<_mycode &>(dst);               // NOLINT
      const auto &_s = static_cast<const _mycode &>(src);  // NOLINT
      const StatusCode &s = *_s.value();
      new(&d) _mycode(in_place, new StatusCode(s));
    }
    virtual void _do_erased_destroy(status_code<void> &code, size_t /*unused*/) const noexcept override  // NOLINT
    {
      assert(code.domain() == *this);
      auto &c = static_cast<_mycode &>(code);  // NOLINT
      delete c.value();  // NOLINT
    }
  };
#if __cplusplus >= 201402 || defined(_MSC_VER)
  template <class StatusCode> constexpr indirecting_domain<StatusCode> _indirecting_domain{};
  template <class StatusCode> inline constexpr const indirecting_domain<StatusCode> &indirecting_domain<StatusCode>::get() { return _indirecting_domain<StatusCode>; }
#endif
}  // namespace detail

/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
template <class T, typename std::enable_if<is_status_code<T>::value, bool>::type = true>  //
inline status_code<erased<typename std::add_pointer<typename std::decay<T>::type>::type>> make_status_code_ptr(T &&v)
{
  using status_code_type = typename std::decay<T>::type;
  return status_code<detail::indirecting_domain<status_code_type>>(in_place, new status_code_type(static_cast<T &&>(v)));
}

SYSTEM_ERROR2_NAMESPACE_END

#endif
SYSTEM_ERROR2_NAMESPACE_BEGIN

/*! AWAITING HUGO JSON CONVERSION TOOL
type definition template <class DomainType> errored_status_code. Potential doc page: NOT FOUND
*/
template <class DomainType> class errored_status_code : public status_code<DomainType>
{
  using _base = status_code<DomainType>;
  using _base::clear;
  using _base::success;

  void _check()
  {
    if(_base::success())
    {
      std::terminate();
    }
  }

public:
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  using typename _base::value_type;
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  using typename _base::string_ref;

  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  errored_status_code() = default;
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  errored_status_code(const errored_status_code &) = default;
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  errored_status_code(errored_status_code &&) = default;  // NOLINT
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  errored_status_code &operator=(const errored_status_code &) = default;
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  errored_status_code &operator=(errored_status_code &&) = default;  // NOLINT
  ~errored_status_code() = default;

  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  explicit errored_status_code(const _base &o) noexcept(std::is_nothrow_copy_constructible<_base>::value)
      : _base(o)
  {
    _check();
  }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  explicit errored_status_code(_base &&o) noexcept(std::is_nothrow_move_constructible<_base>::value)
      : _base(static_cast<_base &&>(o))
  {
    _check();
  }

  /***** KEEP THESE IN SYNC WITH STATUS_CODE *****/
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  template <class T, class... Args,                                                                              //
            class MakeStatusCodeResult = typename detail::safe_get_make_status_code_result<T, Args...>::type,    // Safe ADL lookup of make_status_code(), returns void if not found
            typename std::enable_if<!std::is_same<typename std::decay<T>::type, errored_status_code>::value      // not copy/move of self
                                    && !std::is_same<typename std::decay<T>::type, in_place_t>::value            // not in_place_t
                                    && is_status_code<MakeStatusCodeResult>::value                               // ADL makes a status code
                                    && std::is_constructible<errored_status_code, MakeStatusCodeResult>::value,  // ADLed status code is compatible
                                    bool>::type = true>
  errored_status_code(T &&v, Args &&... args) noexcept(noexcept(make_status_code(std::declval<T>(), std::declval<Args>()...)))  // NOLINT
  : errored_status_code(make_status_code(static_cast<T &&>(v), static_cast<Args &&>(args)...))
  {
    _check();
  }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  template <class... Args>
  explicit errored_status_code(in_place_t _, Args &&... args) noexcept(std::is_nothrow_constructible<value_type, Args &&...>::value)
      : _base(_, static_cast<Args &&>(args)...)
  {
    _check();
  }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  template <class T, class... Args>
  explicit errored_status_code(in_place_t _, std::initializer_list<T> il, Args &&... args) noexcept(std::is_nothrow_constructible<value_type, std::initializer_list<T>, Args &&...>::value)
      : _base(_, il, static_cast<Args &&>(args)...)
  {
    _check();
  }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  explicit errored_status_code(const value_type &v) noexcept(std::is_nothrow_copy_constructible<value_type>::value)
      : _base(v)
  {
    _check();
  }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  explicit errored_status_code(value_type &&v) noexcept(std::is_nothrow_move_constructible<value_type>::value)
      : _base(static_cast<value_type &&>(v))
  {
    _check();
  }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  template <class ErasedType,  //
            typename std::enable_if<detail::type_erasure_is_safe<ErasedType, value_type>::value, bool>::type = true>
  explicit errored_status_code(const status_code<erased<ErasedType>> &v) noexcept(std::is_nothrow_copy_constructible<value_type>::value)
      : errored_status_code(detail::erasure_cast<value_type>(v.value()))  // NOLINT
  {
    assert(v.domain() == this->domain());  // NOLINT
    _check();
  }

  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  constexpr const value_type &value() const &noexcept { return this->_value; }
};

namespace traits
{
  template <class DomainType> struct is_move_relocating<errored_status_code<DomainType>>
  {
    static constexpr bool value = is_move_relocating<typename DomainType::value_type>::value;
  };
}  // namespace traits

template <class ErasedType> class errored_status_code<erased<ErasedType>> : public status_code<erased<ErasedType>>
{
  using _base = status_code<erased<ErasedType>>;
  using _base::success;

  void _check()
  {
    if(_base::success())
    {
      std::terminate();
    }
  }

public:
  using value_type = typename _base::value_type;
  using string_ref = typename _base::string_ref;

  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  errored_status_code() = default;
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  errored_status_code(const errored_status_code &) = default;
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  errored_status_code(errored_status_code &&) = default;  // NOLINT
                                                          /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  errored_status_code &operator=(const errored_status_code &) = default;
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  errored_status_code &operator=(errored_status_code &&) = default;  // NOLINT
  ~errored_status_code() = default;

  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  explicit errored_status_code(const _base &o) noexcept(std::is_nothrow_copy_constructible<_base>::value)
      : _base(o)
  {
    _check();
  }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  explicit errored_status_code(_base &&o) noexcept(std::is_nothrow_move_constructible<_base>::value)
      : _base(static_cast<_base &&>(o))
  {
    _check();
  }

  /***** KEEP THESE IN SYNC WITH STATUS_CODE *****/
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  template <class DomainType,                                                                              //
            typename std::enable_if<!detail::is_erased_status_code<status_code<DomainType>>::value         //
                                    && std::is_trivially_copyable<typename DomainType::value_type>::value  //
                                    && detail::type_erasure_is_safe<value_type, typename DomainType::value_type>::value,
                                    bool>::type = true>
  errored_status_code(const status_code<DomainType> &v) noexcept : _base(v)  // NOLINT
  {
    _check();
  }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  template <class DomainType,  //
            typename std::enable_if<detail::type_erasure_is_safe<value_type, typename DomainType::value_type>::value,
                                    bool>::type = true>
  errored_status_code(status_code<DomainType> &&v) noexcept : _base(static_cast<status_code<DomainType> &&>(v))  // NOLINT
  {
    _check();
  }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  template <class T, class... Args,                                                                              //
            class MakeStatusCodeResult = typename detail::safe_get_make_status_code_result<T, Args...>::type,    // Safe ADL lookup of make_status_code(), returns void if not found
            typename std::enable_if<!std::is_same<typename std::decay<T>::type, errored_status_code>::value      // not copy/move of self
                                    && !std::is_same<typename std::decay<T>::type, value_type>::value            // not copy/move of value type
                                    && is_status_code<MakeStatusCodeResult>::value                               // ADL makes a status code
                                    && std::is_constructible<errored_status_code, MakeStatusCodeResult>::value,  // ADLed status code is compatible
                                    bool>::type = true>
  errored_status_code(T &&v, Args &&... args) noexcept(noexcept(make_status_code(std::declval<T>(), std::declval<Args>()...)))  // NOLINT
  : errored_status_code(make_status_code(static_cast<T &&>(v), static_cast<Args &&>(args)...))
  {
    _check();
  }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  constexpr value_type value() const noexcept { return this->_value; }
};

namespace traits
{
  template <class ErasedType> struct is_move_relocating<errored_status_code<erased<ErasedType>>>
  {
    static constexpr bool value = true;
  };
}  // namespace traits


/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
template <class DomainType1, class DomainType2> inline bool operator==(const errored_status_code<DomainType1> &a, const errored_status_code<DomainType2> &b) noexcept
{
  return a.equivalent(static_cast<const status_code<DomainType2> &>(b));
}
/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
template <class DomainType1, class DomainType2> inline bool operator==(const status_code<DomainType1> &a, const errored_status_code<DomainType2> &b) noexcept
{
  return a.equivalent(static_cast<const status_code<DomainType2> &>(b));
}
/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
template <class DomainType1, class DomainType2> inline bool operator==(const errored_status_code<DomainType1> &a, const status_code<DomainType2> &b) noexcept
{
  return static_cast<const status_code<DomainType1> &>(a).equivalent(b);
}
/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
template <class DomainType1, class DomainType2> inline bool operator!=(const errored_status_code<DomainType1> &a, const errored_status_code<DomainType2> &b) noexcept
{
  return !a.equivalent(static_cast<const status_code<DomainType2> &>(b));
}
/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
template <class DomainType1, class DomainType2> inline bool operator!=(const status_code<DomainType1> &a, const errored_status_code<DomainType2> &b) noexcept
{
  return !a.equivalent(static_cast<const status_code<DomainType2> &>(b));
}
/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
template <class DomainType1, class DomainType2> inline bool operator!=(const errored_status_code<DomainType1> &a, const status_code<DomainType2> &b) noexcept
{
  return !static_cast<const status_code<DomainType1> &>(a).equivalent(b);
}
/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
template <class DomainType1, class T,                                                                       //
          class MakeStatusCodeResult = typename detail::safe_get_make_status_code_result<const T &>::type,  // Safe ADL lookup of make_status_code(), returns void if not found
          typename std::enable_if<is_status_code<MakeStatusCodeResult>::value, bool>::type = true>          // ADL makes a status code
inline bool
operator==(const errored_status_code<DomainType1> &a, const T &b)
{
  return a.equivalent(make_status_code(b));
}
/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
template <class T, class DomainType1,                                                                       //
          class MakeStatusCodeResult = typename detail::safe_get_make_status_code_result<const T &>::type,  // Safe ADL lookup of make_status_code(), returns void if not found
          typename std::enable_if<is_status_code<MakeStatusCodeResult>::value, bool>::type = true>          // ADL makes a status code
inline bool
operator==(const T &a, const errored_status_code<DomainType1> &b)
{
  return b.equivalent(make_status_code(a));
}
/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
template <class DomainType1, class T,                                                                       //
          class MakeStatusCodeResult = typename detail::safe_get_make_status_code_result<const T &>::type,  // Safe ADL lookup of make_status_code(), returns void if not found
          typename std::enable_if<is_status_code<MakeStatusCodeResult>::value, bool>::type = true>          // ADL makes a status code
inline bool
operator!=(const errored_status_code<DomainType1> &a, const T &b)
{
  return !a.equivalent(make_status_code(b));
}
/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
template <class T, class DomainType1,                                                                       //
          class MakeStatusCodeResult = typename detail::safe_get_make_status_code_result<const T &>::type,  // Safe ADL lookup of make_status_code(), returns void if not found
          typename std::enable_if<is_status_code<MakeStatusCodeResult>::value, bool>::type = true>          // ADL makes a status code
inline bool
operator!=(const T &a, const errored_status_code<DomainType1> &b)
{
  return !b.equivalent(make_status_code(a));
}


namespace detail
{
  template <class T> struct is_errored_status_code
  {
    static constexpr bool value = false;
  };
  template <class T> struct is_errored_status_code<errored_status_code<T>>
  {
    static constexpr bool value = true;
  };
  template <class T> struct is_erased_errored_status_code
  {
    static constexpr bool value = false;
  };
  template <class T> struct is_erased_errored_status_code<errored_status_code<erased<T>>>
  {
    static constexpr bool value = true;
  };
}  // namespace detail

/*! AWAITING HUGO JSON CONVERSION TOOL
type definition template <class T> is_errored_status_code. Potential doc page: NOT FOUND
*/
template <class T> struct is_errored_status_code
{
  static constexpr bool value = detail::is_errored_status_code<typename std::decay<T>::type>::value || detail::is_erased_errored_status_code<typename std::decay<T>::type>::value;
};


SYSTEM_ERROR2_NAMESPACE_END

#endif
/* Proposed SG14 status_code
(C) 2018 Niall Douglas <http://www.nedproductions.biz/> (5 commits)
File Created: Feb 2018


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

#ifndef SYSTEM_ERROR2_SYSTEM_CODE_HPP
#define SYSTEM_ERROR2_SYSTEM_CODE_HPP
/* Proposed SG14 status_code
(C) 2018 Niall Douglas <http://www.nedproductions.biz/> (5 commits)
File Created: Feb 2018


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

#ifndef SYSTEM_ERROR2_POSIX_CODE_HPP
#define SYSTEM_ERROR2_POSIX_CODE_HPP



#include <cstring>  // for strchr and strerror_r

SYSTEM_ERROR2_NAMESPACE_BEGIN

class _posix_code_domain;
/*! AWAITING HUGO JSON CONVERSION TOOL
type alias  posix_code. Potential doc page: NOT FOUND
*/
using posix_code = status_code<_posix_code_domain>;
/*! AWAITING HUGO JSON CONVERSION TOOL
type alias  posix_error. Potential doc page: NOT FOUND
*/
using posix_error = status_error<_posix_code_domain>;

/*! AWAITING HUGO JSON CONVERSION TOOL
type definition  _posix_code_domain. Potential doc page: NOT FOUND
*/
class _posix_code_domain : public status_code_domain
{
  template <class DomainType> friend class status_code;
  template <class StatusCode> friend class detail::indirecting_domain;
  using _base = status_code_domain;

  static _base::string_ref _make_string_ref(int c) noexcept
  {
    char buffer[1024] = "";
#ifdef _WIN32
    strerror_s(buffer, sizeof(buffer), c);
#elif defined(__linux__)
    char *s = strerror_r(c, buffer, sizeof(buffer));  // NOLINT
    if(s != nullptr)
    {
      strncpy(buffer, s, sizeof(buffer));  // NOLINT
      buffer[1023] = 0;
    }
#else
    strerror_r(c, buffer, sizeof(buffer));
#endif
    size_t length = strlen(buffer);  // NOLINT
    auto *p = static_cast<char *>(malloc(length + 1));  // NOLINT
    if(p == nullptr)
    {
      return _base::string_ref("failed to get message from system");
    }
    memcpy(p, buffer, length + 1);  // NOLINT
    return _base::atomic_refcounted_string_ref(p, length);
  }

public:
  /*! AWAITING HUGO JSON CONVERSION TOOL
type alias  value_type. Potential doc page: `value_type &value() &`
*/


  using value_type = int;
  using _base::string_ref;

  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  constexpr explicit _posix_code_domain(typename _base::unique_id_type id = 0xa59a56fe5f310933) noexcept : _base(id) {}
  _posix_code_domain(const _posix_code_domain &) = default;
  _posix_code_domain(_posix_code_domain &&) = default;
  _posix_code_domain &operator=(const _posix_code_domain &) = default;
  _posix_code_domain &operator=(_posix_code_domain &&) = default;
  ~_posix_code_domain() = default;

  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  static inline constexpr const _posix_code_domain &get();

  virtual string_ref name() const noexcept override { return string_ref("posix domain"); }  // NOLINT
protected:
  virtual bool _do_failure(const status_code<void> &code) const noexcept override  // NOLINT
  {
    assert(code.domain() == *this);  // NOLINT
    return static_cast<const posix_code &>(code).value() != 0;  // NOLINT
  }
  virtual bool _do_equivalent(const status_code<void> &code1, const status_code<void> &code2) const noexcept override  // NOLINT
  {
    assert(code1.domain() == *this);  // NOLINT
    const auto &c1 = static_cast<const posix_code &>(code1);  // NOLINT
    if(code2.domain() == *this)
    {
      const auto &c2 = static_cast<const posix_code &>(code2);  // NOLINT
      return c1.value() == c2.value();
    }
    if(code2.domain() == generic_code_domain)
    {
      const auto &c2 = static_cast<const generic_code &>(code2);  // NOLINT
      if(static_cast<int>(c2.value()) == c1.value())
      {
        return true;
      }
    }
    return false;
  }
  virtual generic_code _generic_code(const status_code<void> &code) const noexcept override  // NOLINT
  {
    assert(code.domain() == *this);  // NOLINT
    const auto &c = static_cast<const posix_code &>(code);  // NOLINT
    return generic_code(static_cast<errc>(c.value()));
  }
  virtual string_ref _do_message(const status_code<void> &code) const noexcept override  // NOLINT
  {
    assert(code.domain() == *this);  // NOLINT
    const auto &c = static_cast<const posix_code &>(code);  // NOLINT
    return _make_string_ref(c.value());
  }
#if defined(_CPPUNWIND) || defined(__EXCEPTIONS) || 0
  SYSTEM_ERROR2_NORETURN virtual void _do_throw_exception(const status_code<void> &code) const override  // NOLINT
  {
    assert(code.domain() == *this);  // NOLINT
    const auto &c = static_cast<const posix_code &>(code);  // NOLINT
    throw status_error<_posix_code_domain>(c);
  }
#endif
};
/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
constexpr _posix_code_domain posix_code_domain;
inline constexpr const _posix_code_domain &_posix_code_domain::get()
{
  return posix_code_domain;
}

SYSTEM_ERROR2_NAMESPACE_END

#endif
#if defined(_WIN32) || 0
/* Proposed SG14 status_code
(C) 2018 Niall Douglas <http://www.nedproductions.biz/> (5 commits)
File Created: Feb 2018


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

#ifndef SYSTEM_ERROR2_NT_CODE_HPP
#define SYSTEM_ERROR2_NT_CODE_HPP

#if !defined(_WIN32) && !0
#error This file should only be included on Windows
#endif
/* Proposed SG14 status_code
(C) 2018 Niall Douglas <http://www.nedproductions.biz/> (5 commits)
File Created: Feb 2018


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

#ifndef SYSTEM_ERROR2_WIN32_CODE_HPP
#define SYSTEM_ERROR2_WIN32_CODE_HPP

#if !defined(_WIN32) && !0
#error This file should only be included on Windows
#endif



SYSTEM_ERROR2_NAMESPACE_BEGIN

/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
namespace win32
{
  // A Win32 DWORD
  using DWORD = unsigned long;
  // Used to retrieve the current Win32 error code
  extern "C" DWORD __stdcall GetLastError();
  // Used to retrieve a locale-specific message string for some error code
  extern "C" DWORD __stdcall FormatMessageW(DWORD dwFlags, const void *lpSource, DWORD dwMessageId, DWORD dwLanguageId, wchar_t *lpBuffer, DWORD nSize, void /*va_list*/ *Arguments);
  // Converts UTF-16 message string to UTF-8
  extern "C" int __stdcall WideCharToMultiByte(unsigned int CodePage, DWORD dwFlags, const wchar_t *lpWideCharStr, int cchWideChar, char *lpMultiByteStr, int cbMultiByte, const char *lpDefaultChar, int *lpUsedDefaultChar);
#pragma comment(lib, "kernel32.lib")
}  // namespace win32

class _win32_code_domain;
class _com_code_domain;
/*! AWAITING HUGO JSON CONVERSION TOOL
type alias  win32_code. Potential doc page: NOT FOUND
*/
using win32_code = status_code<_win32_code_domain>;
/*! AWAITING HUGO JSON CONVERSION TOOL
type alias  win32_error. Potential doc page: NOT FOUND
*/
using win32_error = status_error<_win32_code_domain>;

/*! AWAITING HUGO JSON CONVERSION TOOL
type definition  _win32_code_domain. Potential doc page: NOT FOUND
*/
class _win32_code_domain : public status_code_domain
{
  template <class DomainType> friend class status_code;
  template <class StatusCode> friend class detail::indirecting_domain;
  friend class _com_code_domain;
  using _base = status_code_domain;
  static int _win32_code_to_errno(win32::DWORD c)
  {
    switch(c)
    {
    case 0:
      return 0;
case 0x1: return ENOSYS;
case 0x2: return ENOENT;
case 0x3: return ENOENT;
case 0x4: return EMFILE;
case 0x5: return EACCES;
case 0x6: return EINVAL;
case 0x8: return ENOMEM;
case 0xc: return EACCES;
case 0xe: return ENOMEM;
case 0xf: return ENODEV;
case 0x10: return EACCES;
case 0x11: return EXDEV;
case 0x13: return EACCES;
case 0x14: return ENODEV;
case 0x15: return EAGAIN;
case 0x19: return EIO;
case 0x1d: return EIO;
case 0x1e: return EIO;
case 0x20: return EACCES;
case 0x21: return ENOLCK;
case 0x27: return ENOSPC;
case 0x37: return ENODEV;
case 0x50: return EEXIST;
case 0x52: return EACCES;
case 0x57: return EINVAL;
case 0x6e: return EIO;
case 0x6f: return ENAMETOOLONG;
case 0x70: return ENOSPC;
case 0x7b: return EINVAL;
case 0x83: return EINVAL;
case 0x8e: return EBUSY;
case 0x91: return ENOTEMPTY;
case 0xaa: return EBUSY;
case 0xb7: return EEXIST;
case 0xd4: return ENOLCK;
case 0x10b: return EINVAL;
case 0x3e3: return ECANCELED;
case 0x3e6: return EACCES;
case 0x3f3: return EIO;
case 0x3f4: return EIO;
case 0x3f5: return EIO;
case 0x4d5: return EAGAIN;
case 0x961: return EBUSY;
case 0x964: return EBUSY;
case 0x2714: return EINTR;
case 0x2719: return EBADF;
case 0x271d: return EACCES;
case 0x271e: return EFAULT;
case 0x2726: return EINVAL;
case 0x2728: return EMFILE;
case 0x2733: return EWOULDBLOCK;
case 0x2734: return EINPROGRESS;
case 0x2735: return EALREADY;
case 0x2736: return ENOTSOCK;
case 0x2737: return EDESTADDRREQ;
case 0x2738: return EMSGSIZE;
case 0x2739: return EPROTOTYPE;
case 0x273a: return ENOPROTOOPT;
case 0x273b: return EPROTONOSUPPORT;
case 0x273d: return EOPNOTSUPP;
case 0x273f: return EAFNOSUPPORT;
case 0x2740: return EADDRINUSE;
case 0x2741: return EADDRNOTAVAIL;
case 0x2742: return ENETDOWN;
case 0x2743: return ENETUNREACH;
case 0x2744: return ENETRESET;
case 0x2745: return ECONNABORTED;
case 0x2746: return ECONNRESET;
case 0x2747: return ENOBUFS;
case 0x2748: return EISCONN;
case 0x2749: return ENOTCONN;
case 0x274c: return ETIMEDOUT;
case 0x274d: return ECONNREFUSED;
case 0x274f: return ENAMETOOLONG;
case 0x2751: return EHOSTUNREACH;
    }
    return -1;
  }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  static _base::string_ref _make_string_ref(win32::DWORD c) noexcept
  {
    wchar_t buffer[32768];
    win32::DWORD wlen = win32::FormatMessageW(0x00001000 /*FORMAT_MESSAGE_FROM_SYSTEM*/ | 0x00000200 /*FORMAT_MESSAGE_IGNORE_INSERTS*/, nullptr, c, 0, buffer, 32768, nullptr);
    size_t allocation = wlen + (wlen >> 1);
    win32::DWORD bytes;
    if(wlen == 0)
    {
      return _base::string_ref("failed to get message from system");
    }
    for(;;)
    {
      auto *p = static_cast<char *>(malloc(allocation));  // NOLINT
      if(p == nullptr)
      {
        return _base::string_ref("failed to get message from system");
      }
      bytes = win32::WideCharToMultiByte(65001 /*CP_UTF8*/, 0, buffer, (int) (wlen + 1), p, (int) allocation, nullptr, nullptr);
      if(bytes != 0)
      {
        char *end = strchr(p, 0);
        while(end[-1] == 10 || end[-1] == 13)
        {
          --end;
        }
        *end = 0;  // NOLINT
        return _base::atomic_refcounted_string_ref(p, end - p);
      }
      free(p);  // NOLINT
      if(win32::GetLastError() == 0x7a /*ERROR_INSUFFICIENT_BUFFER*/)
      {
        allocation += allocation >> 2;
        continue;
      }
      return _base::string_ref("failed to get message from system");
    }
  }

public:
  /*! AWAITING HUGO JSON CONVERSION TOOL
type alias  value_type. Potential doc page: `value_type &value() &`
*/


  using value_type = win32::DWORD;
  using _base::string_ref;

public:
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  constexpr explicit _win32_code_domain(typename _base::unique_id_type id = 0x8cd18ee72d680f1b) noexcept : _base(id) {}
  _win32_code_domain(const _win32_code_domain &) = default;
  _win32_code_domain(_win32_code_domain &&) = default;
  _win32_code_domain &operator=(const _win32_code_domain &) = default;
  _win32_code_domain &operator=(_win32_code_domain &&) = default;
  ~_win32_code_domain() = default;

  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  static inline constexpr const _win32_code_domain &get();

  virtual string_ref name() const noexcept override { return string_ref("win32 domain"); }  // NOLINT
protected:
  virtual bool _do_failure(const status_code<void> &code) const noexcept override  // NOLINT
  {
    assert(code.domain() == *this);
    return static_cast<const win32_code &>(code).value() != 0;  // NOLINT
  }
  virtual bool _do_equivalent(const status_code<void> &code1, const status_code<void> &code2) const noexcept override  // NOLINT
  {
    assert(code1.domain() == *this);
    const auto &c1 = static_cast<const win32_code &>(code1);  // NOLINT
    if(code2.domain() == *this)
    {
      const auto &c2 = static_cast<const win32_code &>(code2);  // NOLINT
      return c1.value() == c2.value();
    }
    if(code2.domain() == generic_code_domain)
    {
      const auto &c2 = static_cast<const generic_code &>(code2);  // NOLINT
      if(static_cast<int>(c2.value()) == _win32_code_to_errno(c1.value()))
      {
        return true;
      }
    }
    return false;
  }
  virtual generic_code _generic_code(const status_code<void> &code) const noexcept override  // NOLINT
  {
    assert(code.domain() == *this);
    const auto &c = static_cast<const win32_code &>(code);  // NOLINT
    return generic_code(static_cast<errc>(_win32_code_to_errno(c.value())));
  }
  virtual string_ref _do_message(const status_code<void> &code) const noexcept override  // NOLINT
  {
    assert(code.domain() == *this);
    const auto &c = static_cast<const win32_code &>(code);  // NOLINT
    return _make_string_ref(c.value());
  }
#if defined(_CPPUNWIND) || defined(__EXCEPTIONS) || 0
  SYSTEM_ERROR2_NORETURN virtual void _do_throw_exception(const status_code<void> &code) const override  // NOLINT
  {
    assert(code.domain() == *this);
    const auto &c = static_cast<const win32_code &>(code);  // NOLINT
    throw status_error<_win32_code_domain>(c);
  }
#endif
};
/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
constexpr _win32_code_domain win32_code_domain;
inline constexpr const _win32_code_domain &_win32_code_domain::get()
{
  return win32_code_domain;
}

SYSTEM_ERROR2_NAMESPACE_END

#endif
SYSTEM_ERROR2_NAMESPACE_BEGIN

/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
namespace win32
{
  // A Win32 NTSTATUS
  using NTSTATUS = long;
  // A Win32 HMODULE
  using HMODULE = void *;
  // Used to retrieve where the NTDLL DLL is mapped into memory
  extern "C" HMODULE __stdcall GetModuleHandleW(const wchar_t *lpModuleName);
}

class _nt_code_domain;
/*! AWAITING HUGO JSON CONVERSION TOOL
type alias  nt_code. Potential doc page: NOT FOUND
*/
using nt_code = status_code<_nt_code_domain>;
/*! AWAITING HUGO JSON CONVERSION TOOL
type alias  nt_error. Potential doc page: NOT FOUND
*/
using nt_error = status_error<_nt_code_domain>;

/*! AWAITING HUGO JSON CONVERSION TOOL
type definition  _nt_code_domain. Potential doc page: NOT FOUND
*/
class _nt_code_domain : public status_code_domain
{
  template <class DomainType> friend class status_code;
  template <class StatusCode> friend class detail::indirecting_domain;
  friend class _com_code_domain;
  using _base = status_code_domain;
  static int _nt_code_to_errno(win32::NTSTATUS c)
  {
    if(c >= 0)
    {
      return 0;  // success
    }
    switch(static_cast<unsigned>(c))
    {
case 0x80000002: return EACCES;
case 0x8000000f: return EAGAIN;
case 0x80000010: return EAGAIN;
case 0x80000011: return EBUSY;
case 0xc0000002: return ENOSYS;
case 0xc0000005: return EACCES;
case 0xc0000008: return EINVAL;
case 0xc000000e: return ENOENT;
case 0xc000000f: return ENOENT;
case 0xc0000010: return ENOSYS;
case 0xc0000013: return EAGAIN;
case 0xc0000017: return ENOMEM;
case 0xc000001c: return ENOSYS;
case 0xc000001e: return EACCES;
case 0xc000001f: return EACCES;
case 0xc0000021: return EACCES;
case 0xc0000022: return EACCES;
case 0xc0000024: return EINVAL;
case 0xc0000033: return EINVAL;
case 0xc0000034: return ENOENT;
case 0xc0000035: return EEXIST;
case 0xc0000037: return EINVAL;
case 0xc000003a: return ENOENT;
case 0xc0000040: return ENOMEM;
case 0xc0000041: return EACCES;
case 0xc0000042: return EINVAL;
case 0xc0000043: return EACCES;
case 0xc000004b: return EACCES;
case 0xc0000054: return ENOLCK;
case 0xc0000055: return ENOLCK;
case 0xc0000056: return EACCES;
case 0xc000007f: return ENOSPC;
case 0xc0000087: return ENOMEM;
case 0xc0000097: return ENOMEM;
case 0xc000009b: return ENOENT;
case 0xc000009e: return EAGAIN;
case 0xc00000a2: return EACCES;
case 0xc00000a3: return EAGAIN;
case 0xc00000af: return ENOSYS;
case 0xc00000ba: return EACCES;
case 0xc00000c0: return ENODEV;
case 0xc00000d4: return EXDEV;
case 0xc00000d5: return EACCES;
case 0xc00000fb: return ENOENT;
case 0xc0000101: return ENOTEMPTY;
case 0xc0000103: return EINVAL;
case 0xc0000107: return EBUSY;
case 0xc0000108: return EBUSY;
case 0xc000010a: return EACCES;
case 0xc000011f: return EMFILE;
case 0xc0000120: return ECANCELED;
case 0xc0000121: return EACCES;
case 0xc0000123: return EACCES;
case 0xc0000128: return EINVAL;
case 0xc0000189: return EACCES;
case 0xc00001ad: return ENOMEM;
case 0xc000022d: return EAGAIN;
case 0xc0000235: return EINVAL;
case 0xc000026e: return EAGAIN;
case 0xc000028a: return EACCES;
case 0xc000028b: return EACCES;
case 0xc000028d: return EACCES;
case 0xc000028e: return EACCES;
case 0xc000028f: return EACCES;
case 0xc0000290: return EACCES;
case 0xc000029c: return ENOSYS;
case 0xc00002c5: return EACCES;
case 0xc00002d3: return EAGAIN;
case 0xc00002ea: return EACCES;
case 0xc00002f0: return ENOENT;
case 0xc0000373: return ENOMEM;
case 0xc0000416: return ENOMEM;
case 0xc0000433: return EBUSY;
case 0xc0000434: return EBUSY;
case 0xc0000455: return EINVAL;
case 0xc0000467: return EACCES;
case 0xc0000491: return ENOENT;
case 0xc0000495: return EAGAIN;
case 0xc0000503: return EAGAIN;
case 0xc0000507: return EBUSY;
case 0xc0000512: return EACCES;
case 0xc000070a: return EINVAL;
case 0xc000070b: return EINVAL;
case 0xc000070c: return EINVAL;
case 0xc000070d: return EINVAL;
case 0xc000070e: return EINVAL;
case 0xc000070f: return EINVAL;
case 0xc0000710: return ENOSYS;
case 0xc0000711: return ENOSYS;
case 0xc0000716: return EINVAL;
case 0xc000071b: return ENOSYS;
case 0xc000071d: return ENOSYS;
case 0xc000071e: return ENOSYS;
case 0xc000071f: return ENOSYS;
case 0xc0000720: return ENOSYS;
case 0xc0000721: return ENOSYS;
case 0xc000080f: return EAGAIN;
case 0xc000a203: return EACCES;
    }
    return -1;
  }
  static win32::DWORD _nt_code_to_win32_code(win32::NTSTATUS c)  // NOLINT
  {
    if(c >= 0)
    {
      return 0;  // success
    }
    switch(static_cast<unsigned>(c))
    {
case 0x80000002: return 0x3e6;
case 0x80000005: return 0xea;
case 0x80000006: return 0x12;
case 0x80000007: return 0x2a3;
case 0x8000000a: return 0x2a4;
case 0x8000000b: return 0x56f;
case 0x8000000c: return 0x2a8;
case 0x8000000d: return 0x12b;
case 0x8000000e: return 0x1c;
case 0x8000000f: return 0x15;
case 0x80000010: return 0x15;
case 0x80000011: return 0xaa;
case 0x80000012: return 0x103;
case 0x80000013: return 0xfe;
case 0x80000014: return 0xff;
case 0x80000015: return 0xff;
case 0x80000016: return 0x456;
case 0x80000017: return 0x2a5;
case 0x80000018: return 0x2a6;
case 0x8000001a: return 0x103;
case 0x8000001b: return 0x44d;
case 0x8000001c: return 0x456;
case 0x8000001d: return 0x457;
case 0x8000001e: return 0x44c;
case 0x8000001f: return 0x44e;
case 0x80000020: return 0x2a7;
case 0x80000021: return 0x44f;
case 0x80000022: return 0x450;
case 0x80000023: return 0x702;
case 0x80000024: return 0x713;
case 0x80000025: return 0x962;
case 0x80000026: return 0x2aa;
case 0x80000027: return 0x10f4;
case 0x80000028: return 0x2ab;
case 0x80000029: return 0x2ac;
case 0x8000002a: return 0x2ad;
case 0x8000002b: return 0x2ae;
case 0x8000002c: return 0x2af;
case 0x8000002d: return 0x2a9;
case 0x8000002e: return 0x321;
case 0x8000002f: return 0x324;
case 0x80000030: return 0xab;
case 0x80000032: return 0xeb;
case 0x80000288: return 0x48d;
case 0x80000289: return 0x48e;
case 0x80000803: return 0x1abb;
case 0x8000a127: return 0x3bdf;
case 0x8000cf00: return 0x16e;
case 0x8000cf04: return 0x16d;
case 0x8000cf05: return 0x176;
case 0x80130001: return 0x13c5;
case 0x80130002: return 0x13c6;
case 0x80130003: return 0x13c7;
case 0x80130004: return 0x13c8;
case 0x80130005: return 0x13c9;
case 0x80190009: return 0x19e5;
case 0x80190029: return 0x1aa0;
case 0x80190031: return 0x1aa2;
case 0x80190041: return 0x1ab3;
case 0x80190042: return 0x1ab4;
case 0x801c0001: return 0x7a;
case 0xc0000001: return 0x1f;
case 0xc0000002: return 0x1;
case 0xc0000003: return 0x57;
case 0xc0000004: return 0x18;
case 0xc0000005: return 0x3e6;
case 0xc0000006: return 0x3e7;
case 0xc0000007: return 0x5ae;
case 0xc0000008: return 0x6;
case 0xc0000009: return 0x3e9;
case 0xc000000a: return 0xc1;
case 0xc000000b: return 0x57;
case 0xc000000c: return 0x21d;
case 0xc000000d: return 0x57;
case 0xc000000e: return 0x2;
case 0xc000000f: return 0x2;
case 0xc0000010: return 0x1;
case 0xc0000011: return 0x26;
case 0xc0000012: return 0x22;
case 0xc0000013: return 0x15;
case 0xc0000014: return 0x6f9;
case 0xc0000015: return 0x1b;
case 0xc0000016: return 0xea;
case 0xc0000017: return 0x8;
case 0xc0000018: return 0x1e7;
case 0xc0000019: return 0x1e7;
case 0xc000001a: return 0x57;
case 0xc000001b: return 0x57;
case 0xc000001c: return 0x1;
case 0xc000001e: return 0x5;
case 0xc000001f: return 0x5;
case 0xc0000020: return 0xc1;
case 0xc0000021: return 0x5;
case 0xc0000022: return 0x5;
case 0xc0000023: return 0x7a;
case 0xc0000024: return 0x6;
case 0xc0000027: return 0x21e;
case 0xc0000028: return 0x21f;
case 0xc0000029: return 0x220;
case 0xc000002a: return 0x9e;
case 0xc000002c: return 0x1e7;
case 0xc000002d: return 0x1e7;
case 0xc000002e: return 0x221;
case 0xc000002f: return 0x222;
case 0xc0000030: return 0x57;
case 0xc0000031: return 0x223;
case 0xc0000032: return 0x571;
case 0xc0000033: return 0x7b;
case 0xc0000034: return 0x2;
case 0xc0000035: return 0xb7;
case 0xc0000036: return 0x72a;
case 0xc0000037: return 0x6;
case 0xc0000038: return 0x224;
case 0xc0000039: return 0xa1;
case 0xc000003a: return 0x3;
case 0xc000003b: return 0xa1;
case 0xc000003c: return 0x45d;
case 0xc000003d: return 0x45d;
case 0xc000003e: return 0x17;
case 0xc000003f: return 0x17;
case 0xc0000040: return 0x8;
case 0xc0000041: return 0x5;
case 0xc0000042: return 0x6;
case 0xc0000043: return 0x20;
case 0xc0000044: return 0x718;
case 0xc0000045: return 0x57;
case 0xc0000046: return 0x120;
case 0xc0000047: return 0x12a;
case 0xc0000048: return 0x57;
case 0xc0000049: return 0x57;
case 0xc000004a: return 0x9c;
case 0xc000004b: return 0x5;
case 0xc000004c: return 0x57;
case 0xc000004d: return 0x57;
case 0xc000004e: return 0x57;
case 0xc000004f: return 0x11a;
case 0xc0000050: return 0xff;
case 0xc0000051: return 0x570;
case 0xc0000052: return 0x570;
case 0xc0000053: return 0x570;
case 0xc0000054: return 0x21;
case 0xc0000055: return 0x21;
case 0xc0000056: return 0x5;
case 0xc0000057: return 0x32;
case 0xc0000058: return 0x519;
case 0xc0000059: return 0x51a;
case 0xc000005a: return 0x51b;
case 0xc000005b: return 0x51c;
case 0xc000005c: return 0x51d;
case 0xc000005d: return 0x51e;
case 0xc000005e: return 0x51f;
case 0xc000005f: return 0x520;
case 0xc0000060: return 0x521;
case 0xc0000061: return 0x522;
case 0xc0000062: return 0x523;
case 0xc0000063: return 0x524;
case 0xc0000064: return 0x525;
case 0xc0000065: return 0x526;
case 0xc0000066: return 0x527;
case 0xc0000067: return 0x528;
case 0xc0000068: return 0x529;
case 0xc0000069: return 0x52a;
case 0xc000006a: return 0x56;
case 0xc000006b: return 0x52c;
case 0xc000006c: return 0x52d;
case 0xc000006d: return 0x52e;
case 0xc000006e: return 0x52f;
case 0xc000006f: return 0x530;
case 0xc0000070: return 0x531;
case 0xc0000071: return 0x532;
case 0xc0000072: return 0x533;
case 0xc0000073: return 0x534;
case 0xc0000074: return 0x535;
case 0xc0000075: return 0x536;
case 0xc0000076: return 0x537;
case 0xc0000077: return 0x538;
case 0xc0000078: return 0x539;
case 0xc0000079: return 0x53a;
case 0xc000007a: return 0x7f;
case 0xc000007b: return 0xc1;
case 0xc000007c: return 0x3f0;
case 0xc000007d: return 0x53c;
case 0xc000007e: return 0x9e;
case 0xc000007f: return 0x70;
case 0xc0000080: return 0x53d;
case 0xc0000081: return 0x53e;
case 0xc0000082: return 0x44;
case 0xc0000083: return 0x103;
case 0xc0000084: return 0x53f;
case 0xc0000085: return 0x103;
case 0xc0000086: return 0x9a;
case 0xc0000087: return 0xe;
case 0xc0000088: return 0x1e7;
case 0xc0000089: return 0x714;
case 0xc000008a: return 0x715;
case 0xc000008b: return 0x716;
case 0xc0000095: return 0x216;
case 0xc0000097: return 0x8;
case 0xc0000098: return 0x3ee;
case 0xc0000099: return 0x540;
case 0xc000009a: return 0x5aa;
case 0xc000009b: return 0x3;
case 0xc000009c: return 0x17;
case 0xc000009d: return 0x48f;
case 0xc000009e: return 0x15;
case 0xc000009f: return 0x1e7;
case 0xc00000a0: return 0x1e7;
case 0xc00000a1: return 0x5ad;
case 0xc00000a2: return 0x13;
case 0xc00000a3: return 0x15;
case 0xc00000a4: return 0x541;
case 0xc00000a5: return 0x542;
case 0xc00000a6: return 0x543;
case 0xc00000a7: return 0x544;
case 0xc00000a8: return 0x545;
case 0xc00000a9: return 0x57;
case 0xc00000aa: return 0x225;
case 0xc00000ab: return 0xe7;
case 0xc00000ac: return 0xe7;
case 0xc00000ad: return 0xe6;
case 0xc00000ae: return 0xe7;
case 0xc00000af: return 0x1;
case 0xc00000b0: return 0xe9;
case 0xc00000b1: return 0xe8;
case 0xc00000b2: return 0x217;
case 0xc00000b3: return 0x218;
case 0xc00000b4: return 0xe6;
case 0xc00000b5: return 0x79;
case 0xc00000b6: return 0x26;
case 0xc00000b7: return 0x226;
case 0xc00000b8: return 0x227;
case 0xc00000b9: return 0x228;
case 0xc00000ba: return 0x5;
case 0xc00000bb: return 0x32;
case 0xc00000bc: return 0x33;
case 0xc00000bd: return 0x34;
case 0xc00000be: return 0x35;
case 0xc00000bf: return 0x36;
case 0xc00000c0: return 0x37;
case 0xc00000c1: return 0x38;
case 0xc00000c2: return 0x39;
case 0xc00000c3: return 0x3a;
case 0xc00000c4: return 0x3b;
case 0xc00000c5: return 0x3c;
case 0xc00000c6: return 0x3d;
case 0xc00000c7: return 0x3e;
case 0xc00000c8: return 0x3f;
case 0xc00000c9: return 0x40;
case 0xc00000ca: return 0x41;
case 0xc00000cb: return 0x42;
case 0xc00000cc: return 0x43;
case 0xc00000cd: return 0x44;
case 0xc00000ce: return 0x45;
case 0xc00000cf: return 0x46;
case 0xc00000d0: return 0x47;
case 0xc00000d1: return 0x48;
case 0xc00000d2: return 0x58;
case 0xc00000d3: return 0x229;
case 0xc00000d4: return 0x11;
case 0xc00000d5: return 0x5;
case 0xc00000d6: return 0xf0;
case 0xc00000d7: return 0x546;
case 0xc00000d8: return 0x22a;
case 0xc00000d9: return 0xe8;
case 0xc00000da: return 0x547;
case 0xc00000db: return 0x22b;
case 0xc00000dc: return 0x548;
case 0xc00000dd: return 0x549;
case 0xc00000de: return 0x54a;
case 0xc00000df: return 0x54b;
case 0xc00000e0: return 0x54c;
case 0xc00000e1: return 0x54d;
case 0xc00000e2: return 0x12c;
case 0xc00000e3: return 0x12d;
case 0xc00000e4: return 0x54e;
case 0xc00000e5: return 0x54f;
case 0xc00000e6: return 0x550;
case 0xc00000e7: return 0x551;
case 0xc00000e8: return 0x6f8;
case 0xc00000e9: return 0x45d;
case 0xc00000ea: return 0x22c;
case 0xc00000eb: return 0x22d;
case 0xc00000ec: return 0x22e;
case 0xc00000ed: return 0x552;
case 0xc00000ee: return 0x553;
case 0xc00000ef: return 0x57;
case 0xc00000f0: return 0x57;
case 0xc00000f1: return 0x57;
case 0xc00000f2: return 0x57;
case 0xc00000f3: return 0x57;
case 0xc00000f4: return 0x57;
case 0xc00000f5: return 0x57;
case 0xc00000f6: return 0x57;
case 0xc00000f7: return 0x57;
case 0xc00000f8: return 0x57;
case 0xc00000f9: return 0x57;
case 0xc00000fa: return 0x57;
case 0xc00000fb: return 0x3;
case 0xc00000fc: return 0x420;
case 0xc00000fd: return 0x3e9;
case 0xc00000fe: return 0x554;
case 0xc00000ff: return 0x22f;
case 0xc0000100: return 0xcb;
case 0xc0000101: return 0x91;
case 0xc0000102: return 0x570;
case 0xc0000103: return 0x10b;
case 0xc0000104: return 0x555;
case 0xc0000105: return 0x556;
case 0xc0000106: return 0xce;
case 0xc0000107: return 0x961;
case 0xc0000108: return 0x964;
case 0xc000010a: return 0x5;
case 0xc000010b: return 0x557;
case 0xc000010c: return 0x230;
case 0xc000010d: return 0x558;
case 0xc000010e: return 0x420;
case 0xc000010f: return 0x21a;
case 0xc0000110: return 0x21a;
case 0xc0000111: return 0x21a;
case 0xc0000112: return 0x21a;
case 0xc0000113: return 0x21a;
case 0xc0000114: return 0x21a;
case 0xc0000115: return 0x21a;
case 0xc0000116: return 0x21a;
case 0xc0000117: return 0x5a4;
case 0xc0000118: return 0x231;
case 0xc0000119: return 0x233;
case 0xc000011a: return 0x234;
case 0xc000011b: return 0xc1;
case 0xc000011c: return 0x559;
case 0xc000011d: return 0x55a;
case 0xc000011e: return 0x3ee;
case 0xc000011f: return 0x4;
case 0xc0000120: return 0x3e3;
case 0xc0000121: return 0x5;
case 0xc0000122: return 0x4ba;
case 0xc0000123: return 0x5;
case 0xc0000124: return 0x55b;
case 0xc0000125: return 0x55c;
case 0xc0000126: return 0x55d;
case 0xc0000127: return 0x55e;
case 0xc0000128: return 0x6;
case 0xc0000129: return 0x235;
case 0xc000012a: return 0x236;
case 0xc000012b: return 0x55f;
case 0xc000012c: return 0x237;
case 0xc000012d: return 0x5af;
case 0xc000012e: return 0xc1;
case 0xc000012f: return 0xc1;
case 0xc0000130: return 0xc1;
case 0xc0000131: return 0xc1;
case 0xc0000132: return 0x238;
case 0xc0000133: return 0x576;
case 0xc0000134: return 0x239;
case 0xc0000135: return 0x7e;
case 0xc0000136: return 0x23a;
case 0xc0000137: return 0x23b;
case 0xc0000138: return 0xb6;
case 0xc0000139: return 0x7f;
case 0xc000013a: return 0x23c;
case 0xc000013b: return 0x40;
case 0xc000013c: return 0x40;
case 0xc000013d: return 0x33;
case 0xc000013e: return 0x3b;
case 0xc000013f: return 0x3b;
case 0xc0000140: return 0x3b;
case 0xc0000141: return 0x3b;
case 0xc0000142: return 0x45a;
case 0xc0000143: return 0x23d;
case 0xc0000144: return 0x23e;
case 0xc0000145: return 0x23f;
case 0xc0000146: return 0x240;
case 0xc0000147: return 0x242;
case 0xc0000148: return 0x7c;
case 0xc0000149: return 0x56;
case 0xc000014a: return 0x243;
case 0xc000014b: return 0x6d;
case 0xc000014c: return 0x3f1;
case 0xc000014d: return 0x3f8;
case 0xc000014e: return 0x244;
case 0xc000014f: return 0x3ed;
case 0xc0000150: return 0x45e;
case 0xc0000151: return 0x560;
case 0xc0000152: return 0x561;
case 0xc0000153: return 0x562;
case 0xc0000154: return 0x563;
case 0xc0000155: return 0x564;
case 0xc0000156: return 0x565;
case 0xc0000157: return 0x566;
case 0xc0000158: return 0x567;
case 0xc0000159: return 0x3ef;
case 0xc000015a: return 0x568;
case 0xc000015b: return 0x569;
case 0xc000015c: return 0x3f9;
case 0xc000015d: return 0x56a;
case 0xc000015e: return 0x245;
case 0xc000015f: return 0x45d;
case 0xc0000160: return 0x4db;
case 0xc0000161: return 0x246;
case 0xc0000162: return 0x459;
case 0xc0000163: return 0x247;
case 0xc0000164: return 0x248;
case 0xc0000165: return 0x462;
case 0xc0000166: return 0x463;
case 0xc0000167: return 0x464;
case 0xc0000168: return 0x465;
case 0xc0000169: return 0x466;
case 0xc000016a: return 0x467;
case 0xc000016b: return 0x468;
case 0xc000016c: return 0x45f;
case 0xc000016d: return 0x45d;
case 0xc000016e: return 0x249;
case 0xc0000172: return 0x451;
case 0xc0000173: return 0x452;
case 0xc0000174: return 0x453;
case 0xc0000175: return 0x454;
case 0xc0000176: return 0x455;
case 0xc0000177: return 0x469;
case 0xc0000178: return 0x458;
case 0xc000017a: return 0x56b;
case 0xc000017b: return 0x56c;
case 0xc000017c: return 0x3fa;
case 0xc000017d: return 0x3fb;
case 0xc000017e: return 0x56d;
case 0xc000017f: return 0x56e;
case 0xc0000180: return 0x3fc;
case 0xc0000181: return 0x3fd;
case 0xc0000182: return 0x57;
case 0xc0000183: return 0x45d;
case 0xc0000184: return 0x16;
case 0xc0000185: return 0x45d;
case 0xc0000186: return 0x45d;
case 0xc0000187: return 0x24a;
case 0xc0000188: return 0x5de;
case 0xc0000189: return 0x13;
case 0xc000018a: return 0x6fa;
case 0xc000018b: return 0x6fb;
case 0xc000018c: return 0x6fc;
case 0xc000018d: return 0x6fd;
case 0xc000018e: return 0x5dc;
case 0xc000018f: return 0x5dd;
case 0xc0000190: return 0x6fe;
case 0xc0000191: return 0x24b;
case 0xc0000192: return 0x700;
case 0xc0000193: return 0x701;
case 0xc0000194: return 0x46b;
case 0xc0000195: return 0x4c3;
case 0xc0000196: return 0x4c4;
case 0xc0000197: return 0x5df;
case 0xc0000198: return 0x70f;
case 0xc0000199: return 0x710;
case 0xc000019a: return 0x711;
case 0xc000019b: return 0x712;
case 0xc000019c: return 0x24c;
case 0xc000019d: return 0x420;
case 0xc000019e: return 0x130;
case 0xc000019f: return 0x131;
case 0xc00001a0: return 0x132;
case 0xc00001a1: return 0x133;
case 0xc00001a2: return 0x325;
case 0xc00001a3: return 0x134;
case 0xc00001a4: return 0x135;
case 0xc00001a5: return 0x136;
case 0xc00001a6: return 0x137;
case 0xc00001a7: return 0x139;
case 0xc00001a8: return 0x1abb;
case 0xc00001a9: return 0x32;
case 0xc00001aa: return 0x3d54;
case 0xc00001ab: return 0x329;
case 0xc00001ac: return 0x678;
case 0xc00001ad: return 0x8;
case 0xc00001ae: return 0x2f7;
case 0xc00001af: return 0x32d;
case 0xc0000201: return 0x41;
case 0xc0000202: return 0x572;
case 0xc0000203: return 0x3b;
case 0xc0000204: return 0x717;
case 0xc0000205: return 0x46a;
case 0xc0000206: return 0x6f8;
case 0xc0000207: return 0x4be;
case 0xc0000208: return 0x4be;
case 0xc0000209: return 0x44;
case 0xc000020a: return 0x34;
case 0xc000020b: return 0x40;
case 0xc000020c: return 0x40;
case 0xc000020d: return 0x40;
case 0xc000020e: return 0x44;
case 0xc000020f: return 0x3b;
case 0xc0000210: return 0x3b;
case 0xc0000211: return 0x3b;
case 0xc0000212: return 0x3b;
case 0xc0000213: return 0x3b;
case 0xc0000214: return 0x3b;
case 0xc0000215: return 0x3b;
case 0xc0000216: return 0x32;
case 0xc0000217: return 0x32;
case 0xc0000218: return 0x24d;
case 0xc0000219: return 0x24e;
case 0xc000021a: return 0x24f;
case 0xc000021b: return 0x250;
case 0xc000021c: return 0x17e6;
case 0xc000021d: return 0x251;
case 0xc000021e: return 0x252;
case 0xc000021f: return 0x253;
case 0xc0000220: return 0x46c;
case 0xc0000221: return 0xc1;
case 0xc0000222: return 0x254;
case 0xc0000223: return 0x255;
case 0xc0000224: return 0x773;
case 0xc0000225: return 0x490;
case 0xc0000226: return 0x256;
case 0xc0000227: return 0x4ff;
case 0xc0000228: return 0x257;
case 0xc0000229: return 0x57;
case 0xc000022a: return 0x1392;
case 0xc000022b: return 0x1392;
case 0xc000022c: return 0x258;
case 0xc000022d: return 0x4d5;
case 0xc000022e: return 0x259;
case 0xc000022f: return 0x25a;
case 0xc0000230: return 0x492;
case 0xc0000231: return 0x25b;
case 0xc0000232: return 0x25c;
case 0xc0000233: return 0x774;
case 0xc0000234: return 0x775;
case 0xc0000235: return 0x6;
case 0xc0000236: return 0x4c9;
case 0xc0000237: return 0x4ca;
case 0xc0000238: return 0x4cb;
case 0xc0000239: return 0x4cc;
case 0xc000023a: return 0x4cd;
case 0xc000023b: return 0x4ce;
case 0xc000023c: return 0x4cf;
case 0xc000023d: return 0x4d0;
case 0xc000023e: return 0x4d1;
case 0xc000023f: return 0x4d2;
case 0xc0000240: return 0x4d3;
case 0xc0000241: return 0x4d4;
case 0xc0000242: return 0x25d;
case 0xc0000243: return 0x4c8;
case 0xc0000244: return 0x25e;
case 0xc0000245: return 0x25f;
case 0xc0000246: return 0x4d6;
case 0xc0000247: return 0x4d7;
case 0xc0000248: return 0x4d8;
case 0xc0000249: return 0xc1;
case 0xc0000250: return 0x260;
case 0xc0000251: return 0x261;
case 0xc0000252: return 0x262;
case 0xc0000253: return 0x4d4;
case 0xc0000254: return 0x263;
case 0xc0000255: return 0x264;
case 0xc0000256: return 0x265;
case 0xc0000257: return 0x4d0;
case 0xc0000258: return 0x266;
case 0xc0000259: return 0x573;
case 0xc000025a: return 0x267;
case 0xc000025b: return 0x268;
case 0xc000025c: return 0x269;
case 0xc000025e: return 0x422;
case 0xc000025f: return 0x26a;
case 0xc0000260: return 0x26b;
case 0xc0000261: return 0x26c;
case 0xc0000262: return 0xb6;
case 0xc0000263: return 0x7f;
case 0xc0000264: return 0x120;
case 0xc0000265: return 0x476;
case 0xc0000266: return 0x26d;
case 0xc0000267: return 0x10fe;
case 0xc0000268: return 0x26e;
case 0xc0000269: return 0x26f;
case 0xc000026a: return 0x1b8e;
case 0xc000026b: return 0x270;
case 0xc000026c: return 0x7d1;
case 0xc000026d: return 0x4b1;
case 0xc000026e: return 0x15;
case 0xc000026f: return 0x21c;
case 0xc0000270: return 0x21c;
case 0xc0000271: return 0x271;
case 0xc0000272: return 0x491;
case 0xc0000273: return 0x272;
case 0xc0000275: return 0x1126;
case 0xc0000276: return 0x1129;
case 0xc0000277: return 0x112a;
case 0xc0000278: return 0x1128;
case 0xc0000279: return 0x780;
case 0xc000027a: return 0x291;
case 0xc000027b: return 0x54f;
case 0xc000027c: return 0x54f;
case 0xc0000280: return 0x781;
case 0xc0000281: return 0xa1;
case 0xc0000282: return 0x273;
case 0xc0000283: return 0x488;
case 0xc0000284: return 0x489;
case 0xc0000285: return 0x48a;
case 0xc0000286: return 0x48b;
case 0xc0000287: return 0x48c;
case 0xc000028a: return 0x5;
case 0xc000028b: return 0x5;
case 0xc000028c: return 0x284;
case 0xc000028d: return 0x5;
case 0xc000028e: return 0x5;
case 0xc000028f: return 0x5;
case 0xc0000290: return 0x5;
case 0xc0000291: return 0x1777;
case 0xc0000292: return 0x1778;
case 0xc0000293: return 0x1772;
case 0xc0000295: return 0x1068;
case 0xc0000296: return 0x1069;
case 0xc0000297: return 0x106a;
case 0xc0000298: return 0x106b;
case 0xc0000299: return 0x201a;
case 0xc000029a: return 0x201b;
case 0xc000029b: return 0x201c;
case 0xc000029c: return 0x1;
case 0xc000029d: return 0x10ff;
case 0xc000029e: return 0x1100;
case 0xc000029f: return 0x494;
case 0xc00002a0: return 0x274;
case 0xc00002a1: return 0x200a;
case 0xc00002a2: return 0x200b;
case 0xc00002a3: return 0x200c;
case 0xc00002a4: return 0x200d;
case 0xc00002a5: return 0x200e;
case 0xc00002a6: return 0x200f;
case 0xc00002a7: return 0x2010;
case 0xc00002a8: return 0x2011;
case 0xc00002a9: return 0x2012;
case 0xc00002aa: return 0x2013;
case 0xc00002ab: return 0x2014;
case 0xc00002ac: return 0x2015;
case 0xc00002ad: return 0x2016;
case 0xc00002ae: return 0x2017;
case 0xc00002af: return 0x2018;
case 0xc00002b0: return 0x2019;
case 0xc00002b1: return 0x211e;
case 0xc00002b2: return 0x1127;
case 0xc00002b3: return 0x275;
case 0xc00002b4: return 0x276;
case 0xc00002b5: return 0x277;
case 0xc00002b6: return 0x651;
case 0xc00002b7: return 0x49a;
case 0xc00002b8: return 0x49b;
case 0xc00002b9: return 0x278;
case 0xc00002ba: return 0x2047;
case 0xc00002c1: return 0x2024;
case 0xc00002c2: return 0x279;
case 0xc00002c3: return 0x575;
case 0xc00002c4: return 0x27a;
case 0xc00002c5: return 0x3e6;
case 0xc00002c6: return 0x1075;
case 0xc00002c7: return 0x1076;
case 0xc00002c8: return 0x27b;
case 0xc00002c9: return 0x4ed;
case 0xc00002ca: return 0x10e8;
case 0xc00002cb: return 0x2138;
case 0xc00002cc: return 0x4e3;
case 0xc00002cd: return 0x2139;
case 0xc00002ce: return 0x27c;
case 0xc00002cf: return 0x49d;
case 0xc00002d0: return 0x213a;
case 0xc00002d1: return 0x27d;
case 0xc00002d2: return 0x27e;
case 0xc00002d3: return 0x15;
case 0xc00002d4: return 0x2141;
case 0xc00002d5: return 0x2142;
case 0xc00002d6: return 0x2143;
case 0xc00002d7: return 0x2144;
case 0xc00002d8: return 0x2145;
case 0xc00002d9: return 0x2146;
case 0xc00002da: return 0x2147;
case 0xc00002db: return 0x2148;
case 0xc00002dc: return 0x2149;
case 0xc00002dd: return 0x32;
case 0xc00002de: return 0x27f;
case 0xc00002df: return 0x2151;
case 0xc00002e0: return 0x2152;
case 0xc00002e1: return 0x2153;
case 0xc00002e2: return 0x2154;
case 0xc00002e3: return 0x215d;
case 0xc00002e4: return 0x2163;
case 0xc00002e5: return 0x2164;
case 0xc00002e6: return 0x2165;
case 0xc00002e7: return 0x216d;
case 0xc00002e8: return 0x280;
case 0xc00002e9: return 0x577;
case 0xc00002ea: return 0x52;
case 0xc00002eb: return 0x281;
case 0xc00002ec: return 0x2171;
case 0xc00002ed: return 0x2172;
case 0xc00002f0: return 0x2;
case 0xc00002fe: return 0x45b;
case 0xc00002ff: return 0x4e7;
case 0xc0000300: return 0x4e6;
case 0xc0000301: return 0x106f;
case 0xc0000302: return 0x1074;
case 0xc0000303: return 0x106e;
case 0xc0000304: return 0x12e;
case 0xc000030c: return 0x792;
case 0xc000030d: return 0x793;
case 0xc0000320: return 0x4ef;
case 0xc0000321: return 0x4f0;
case 0xc0000350: return 0x4e8;
case 0xc0000352: return 0x177d;
case 0xc0000353: return 0x282;
case 0xc0000354: return 0x504;
case 0xc0000355: return 0x283;
case 0xc0000357: return 0x217c;
case 0xc0000358: return 0x2182;
case 0xc0000359: return 0xc1;
case 0xc000035a: return 0xc1;
case 0xc000035c: return 0x572;
case 0xc000035d: return 0x4eb;
case 0xc000035f: return 0x286;
case 0xc0000361: return 0x4ec;
case 0xc0000362: return 0x4ec;
case 0xc0000363: return 0x4ec;
case 0xc0000364: return 0x4ec;
case 0xc0000365: return 0x287;
case 0xc0000366: return 0x288;
case 0xc0000368: return 0x289;
case 0xc0000369: return 0x28a;
case 0xc000036a: return 0x28b;
case 0xc000036b: return 0x4fb;
case 0xc000036c: return 0x4fb;
case 0xc000036d: return 0x28c;
case 0xc000036e: return 0x28d;
case 0xc000036f: return 0x4fc;
case 0xc0000371: return 0x21ac;
case 0xc0000372: return 0x312;
case 0xc0000373: return 0x8;
case 0xc0000374: return 0x54f;
case 0xc0000388: return 0x4f1;
case 0xc000038e: return 0x28e;
case 0xc0000401: return 0x78c;
case 0xc0000402: return 0x78d;
case 0xc0000403: return 0x78e;
case 0xc0000404: return 0x217b;
case 0xc0000405: return 0x219d;
case 0xc0000406: return 0x219f;
case 0xc0000407: return 0x28f;
case 0xc0000408: return 0x52e;
case 0xc0000409: return 0x502;
case 0xc0000410: return 0x503;
case 0xc0000411: return 0x290;
case 0xc0000412: return 0x505;
case 0xc0000413: return 0x78f;
case 0xc0000414: return 0x506;
case 0xc0000416: return 0x8;
case 0xc0000417: return 0x508;
case 0xc0000418: return 0x791;
case 0xc0000419: return 0x215b;
case 0xc000041a: return 0x21ba;
case 0xc000041b: return 0x21bb;
case 0xc000041c: return 0x21bc;
case 0xc000041d: return 0x2c9;
case 0xc0000420: return 0x29c;
case 0xc0000421: return 0x219;
case 0xc0000423: return 0x300;
case 0xc0000424: return 0x4fb;
case 0xc0000425: return 0x3fa;
case 0xc0000426: return 0x301;
case 0xc0000427: return 0x299;
case 0xc0000428: return 0x241;
case 0xc0000429: return 0x307;
case 0xc000042a: return 0x308;
case 0xc000042b: return 0x50c;
case 0xc000042c: return 0x2e4;
case 0xc0000432: return 0x509;
case 0xc0000433: return 0xaa;
case 0xc0000434: return 0xaa;
case 0xc0000435: return 0x4c8;
case 0xc0000441: return 0x1781;
case 0xc0000442: return 0x1782;
case 0xc0000443: return 0x1783;
case 0xc0000444: return 0x1784;
case 0xc0000445: return 0x1785;
case 0xc0000446: return 0x513;
case 0xc0000450: return 0x50b;
case 0xc0000451: return 0x3b92;
case 0xc0000452: return 0x3bc3;
case 0xc0000453: return 0x5bb;
case 0xc0000454: return 0x5be;
case 0xc0000455: return 0x6;
case 0xc0000456: return 0x57;
case 0xc0000457: return 0x57;
case 0xc0000458: return 0x57;
case 0xc0000459: return 0xbea;
case 0xc0000460: return 0x138;
case 0xc0000461: return 0x13a;
case 0xc0000462: return 0x3cfc;
case 0xc0000463: return 0x13c;
case 0xc0000464: return 0x141;
case 0xc0000465: return 0x13b;
case 0xc0000466: return 0x40;
case 0xc0000467: return 0x20;
case 0xc0000468: return 0x142;
case 0xc0000469: return 0x3d00;
case 0xc000046a: return 0x151;
case 0xc000046b: return 0x152;
case 0xc000046c: return 0x153;
case 0xc000046d: return 0x156;
case 0xc000046e: return 0x157;
case 0xc000046f: return 0x158;
case 0xc0000470: return 0x143;
case 0xc0000471: return 0x144;
case 0xc0000472: return 0x146;
case 0xc0000473: return 0x14b;
case 0xc0000474: return 0x147;
case 0xc0000475: return 0x148;
case 0xc0000476: return 0x149;
case 0xc0000477: return 0x14a;
case 0xc0000478: return 0x14c;
case 0xc0000479: return 0x14d;
case 0xc000047a: return 0x14e;
case 0xc000047b: return 0x14f;
case 0xc000047c: return 0x150;
case 0xc000047d: return 0x5b4;
case 0xc000047e: return 0x3d07;
case 0xc000047f: return 0x3d08;
case 0xc0000480: return 0x40;
case 0xc0000481: return 0x7e;
case 0xc0000482: return 0x7e;
case 0xc0000483: return 0x1e3;
case 0xc0000486: return 0x159;
case 0xc0000487: return 0x1f;
case 0xc0000488: return 0x15a;
case 0xc0000489: return 0x3d0f;
case 0xc000048a: return 0x32a;
case 0xc000048b: return 0x32c;
case 0xc000048c: return 0x15b;
case 0xc000048d: return 0x15c;
case 0xc000048e: return 0x162;
case 0xc000048f: return 0x15d;
case 0xc0000490: return 0x491;
case 0xc0000491: return 0x2;
case 0xc0000492: return 0x490;
case 0xc0000493: return 0x492;
case 0xc0000494: return 0x307;
case 0xc0000495: return 0x15;
case 0xc0000496: return 0x163;
case 0xc0000497: return 0x3d5a;
case 0xc0000499: return 0x167;
case 0xc000049a: return 0x168;
case 0xc000049b: return 0x12e;
case 0xc000049c: return 0x169;
case 0xc000049d: return 0x16f;
case 0xc000049e: return 0x170;
case 0xc000049f: return 0x49f;
case 0xc00004a0: return 0x4a0;
case 0xc00004a1: return 0x18f;
case 0xc0000500: return 0x60e;
case 0xc0000501: return 0x60f;
case 0xc0000502: return 0x610;
case 0xc0000503: return 0x15;
case 0xc0000504: return 0x13f;
case 0xc0000505: return 0x140;
case 0xc0000506: return 0x5bf;
case 0xc0000507: return 0xaa;
case 0xc0000508: return 0x5e0;
case 0xc0000509: return 0x5e1;
case 0xc000050b: return 0x112b;
case 0xc000050e: return 0x115c;
case 0xc000050f: return 0x10d3;
case 0xc0000510: return 0x4df;
case 0xc0000511: return 0x32e;
case 0xc0000512: return 0x5;
case 0xc0000513: return 0x180;
case 0xc0000514: return 0x115d;
case 0xc0000602: return 0x675;
case 0xc0000604: return 0x677;
case 0xc0000606: return 0x679;
case 0xc000060a: return 0x67c;
case 0xc000060b: return 0x67d;
case 0xc0000700: return 0x54f;
case 0xc0000701: return 0x54f;
case 0xc0000702: return 0x57;
case 0xc0000703: return 0x54f;
case 0xc0000704: return 0x32;
case 0xc0000705: return 0x57;
case 0xc0000706: return 0x57;
case 0xc0000707: return 0x32;
case 0xc0000708: return 0x54f;
case 0xc0000709: return 0x30b;
case 0xc000070a: return 0x6;
case 0xc000070b: return 0x6;
case 0xc000070c: return 0x6;
case 0xc000070d: return 0x6;
case 0xc000070e: return 0x6;
case 0xc000070f: return 0x6;
case 0xc0000710: return 0x1;
case 0xc0000711: return 0x1;
case 0xc0000712: return 0x50d;
case 0xc0000713: return 0x310;
case 0xc0000714: return 0x52e;
case 0xc0000715: return 0x5b7;
case 0xc0000716: return 0x7b;
case 0xc0000717: return 0x459;
case 0xc0000718: return 0x54f;
case 0xc0000719: return 0x54f;
case 0xc000071a: return 0x54f;
case 0xc000071b: return 0x1;
case 0xc000071c: return 0x57;
case 0xc000071d: return 0x1;
case 0xc000071e: return 0x1;
case 0xc000071f: return 0x1;
case 0xc0000720: return 0x1;
case 0xc0000721: return 0x1;
case 0xc0000722: return 0x72b;
case 0xc0000723: return 0x1f;
case 0xc0000724: return 0x1f;
case 0xc0000725: return 0x1f;
case 0xc0000726: return 0x1f;
case 0xc0000800: return 0x30c;
case 0xc0000801: return 0x21a4;
case 0xc0000802: return 0x50f;
case 0xc0000804: return 0x510;
case 0xc0000805: return 0x1ac1;
case 0xc0000806: return 0x1ac3;
case 0xc0000808: return 0x319;
case 0xc0000809: return 0x31a;
case 0xc000080a: return 0x31b;
case 0xc000080b: return 0x31c;
case 0xc000080c: return 0x31d;
case 0xc000080d: return 0x31e;
case 0xc000080e: return 0x31f;
case 0xc000080f: return 0x4d5;
case 0xc0000810: return 0x328;
case 0xc0000811: return 0x54f;
case 0xc0000901: return 0xdc;
case 0xc0000902: return 0xdd;
case 0xc0000903: return 0xde;
case 0xc0000904: return 0xdf;
case 0xc0000905: return 0xe0;
case 0xc0000906: return 0xe1;
case 0xc0000907: return 0xe2;
case 0xc0000908: return 0x317;
case 0xc0000909: return 0x322;
case 0xc0000910: return 0x326;
case 0xc0009898: return 0x29e;
case 0xc000a002: return 0x17;
case 0xc000a003: return 0x139f;
case 0xc000a004: return 0x154;
case 0xc000a005: return 0x155;
case 0xc000a006: return 0x32b;
case 0xc000a007: return 0x32;
case 0xc000a010: return 0xea;
case 0xc000a011: return 0xea;
case 0xc000a012: return 0x4d0;
case 0xc000a013: return 0x32;
case 0xc000a014: return 0x4d1;
case 0xc000a080: return 0x314;
case 0xc000a081: return 0x315;
case 0xc000a082: return 0x316;
case 0xc000a083: return 0x5b9;
case 0xc000a084: return 0x5ba;
case 0xc000a085: return 0x5bc;
case 0xc000a086: return 0x5bd;
case 0xc000a087: return 0x21bd;
case 0xc000a088: return 0x21be;
case 0xc000a089: return 0x21c6;
case 0xc000a100: return 0x3bc4;
case 0xc000a101: return 0x3bc5;
case 0xc000a121: return 0x3bd9;
case 0xc000a122: return 0x3bda;
case 0xc000a123: return 0x3bdb;
case 0xc000a124: return 0x3bdc;
case 0xc000a125: return 0x3bdd;
case 0xc000a126: return 0x3bde;
case 0xc000a141: return 0x3c28;
case 0xc000a142: return 0x3c29;
case 0xc000a143: return 0x3c2a;
case 0xc000a145: return 0x3c2b;
case 0xc000a146: return 0x3c2c;
case 0xc000a200: return 0x109a;
case 0xc000a201: return 0x109c;
case 0xc000a202: return 0x109d;
case 0xc000a203: return 0x5;
case 0xc000a281: return 0x1130;
case 0xc000a282: return 0x1131;
case 0xc000a283: return 0x1132;
case 0xc000a284: return 0x1133;
case 0xc000a285: return 0x1134;
case 0xc000a2a1: return 0x1158;
case 0xc000a2a2: return 0x1159;
case 0xc000a2a3: return 0x115a;
case 0xc000a2a4: return 0x115b;
case 0xc000ce01: return 0x171;
case 0xc000ce02: return 0x172;
case 0xc000ce03: return 0x173;
case 0xc000ce04: return 0x174;
case 0xc000ce05: return 0x181;
case 0xc000cf00: return 0x166;
case 0xc000cf01: return 0x16a;
case 0xc000cf02: return 0x16b;
case 0xc000cf03: return 0x16c;
case 0xc000cf06: return 0x177;
case 0xc000cf07: return 0x178;
case 0xc000cf08: return 0x179;
case 0xc000cf09: return 0x17a;
case 0xc000cf0a: return 0x17b;
case 0xc000cf0b: return 0x17c;
case 0xc000cf0c: return 0x17d;
case 0xc000cf0d: return 0x17e;
case 0xc000cf0e: return 0x17f;
case 0xc000cf0f: return 0x182;
case 0xc000cf10: return 0x183;
case 0xc000cf11: return 0x184;
case 0xc000cf12: return 0x185;
case 0xc000cf13: return 0x186;
case 0xc000cf14: return 0x187;
case 0xc000cf15: return 0x188;
case 0xc000cf16: return 0x189;
case 0xc000cf17: return 0x18a;
case 0xc000cf18: return 0x18b;
case 0xc000cf19: return 0x18c;
case 0xc000cf1a: return 0x18d;
case 0xc000cf1b: return 0x18e;
    }
    return static_cast<win32::DWORD>(-1);
  }
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  static _base::string_ref _make_string_ref(win32::NTSTATUS c) noexcept
  {
    wchar_t buffer[32768];
    static win32::HMODULE ntdll = win32::GetModuleHandleW(L"NTDLL.DLL");
    win32::DWORD wlen = win32::FormatMessageW(0x00000800 /*FORMAT_MESSAGE_FROM_HMODULE*/ | 0x00001000 /*FORMAT_MESSAGE_FROM_SYSTEM*/ | 0x00000200 /*FORMAT_MESSAGE_IGNORE_INSERTS*/, ntdll, c, (1 << 10) /*MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT)*/, buffer, 32768, nullptr);
    size_t allocation = wlen + (wlen >> 1);
    win32::DWORD bytes;
    if(wlen == 0)
    {
      return _base::string_ref("failed to get message from system");
    }
    for(;;)
    {
      auto *p = static_cast<char *>(malloc(allocation));  // NOLINT
      if(p == nullptr)
      {
        return _base::string_ref("failed to get message from system");
      }
      bytes = win32::WideCharToMultiByte(65001 /*CP_UTF8*/, 0, buffer, (int) (wlen + 1), p, (int) allocation, nullptr, nullptr);
      if(bytes != 0)
      {
        char *end = strchr(p, 0);
        while(end[-1] == 10 || end[-1] == 13)
        {
          --end;
        }
        *end = 0;  // NOLINT
        return _base::atomic_refcounted_string_ref(p, end - p);
      }
      free(p);  // NOLINT
      if(win32::GetLastError() == 0x7a /*ERROR_INSUFFICIENT_BUFFER*/)
      {
        allocation += allocation >> 2;
        continue;
      }
      return _base::string_ref("failed to get message from system");
    }
  }

public:
  /*! AWAITING HUGO JSON CONVERSION TOOL
type alias  value_type. Potential doc page: `value_type &value() &`
*/


  using value_type = win32::NTSTATUS;
  using _base::string_ref;

public:
  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  constexpr explicit _nt_code_domain(typename _base::unique_id_type id = 0x93f3b4487e4af25b) noexcept : _base(id) {}
  _nt_code_domain(const _nt_code_domain &) = default;
  _nt_code_domain(_nt_code_domain &&) = default;
  _nt_code_domain &operator=(const _nt_code_domain &) = default;
  _nt_code_domain &operator=(_nt_code_domain &&) = default;
  ~_nt_code_domain() = default;

  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  static inline constexpr const _nt_code_domain &get();

  virtual string_ref name() const noexcept override { return string_ref("NT domain"); }  // NOLINT
protected:
  virtual bool _do_failure(const status_code<void> &code) const noexcept override  // NOLINT
  {
    assert(code.domain() == *this);
    return static_cast<const nt_code &>(code).value() < 0;  // NOLINT
  }
  virtual bool _do_equivalent(const status_code<void> &code1, const status_code<void> &code2) const noexcept override  // NOLINT
  {
    assert(code1.domain() == *this);
    const auto &c1 = static_cast<const nt_code &>(code1);  // NOLINT
    if(code2.domain() == *this)
    {
      const auto &c2 = static_cast<const nt_code &>(code2);  // NOLINT
      return c1.value() == c2.value();
    }
    if(code2.domain() == generic_code_domain)
    {
      const auto &c2 = static_cast<const generic_code &>(code2);  // NOLINT
      if(static_cast<int>(c2.value()) == _nt_code_to_errno(c1.value()))
      {
        return true;
      }
    }
    if(code2.domain() == win32_code_domain)
    {
      const auto &c2 = static_cast<const win32_code &>(code2);  // NOLINT
      if(c2.value() == _nt_code_to_win32_code(c1.value()))
      {
        return true;
      }
    }
    return false;
  }
  virtual generic_code _generic_code(const status_code<void> &code) const noexcept override  // NOLINT
  {
    assert(code.domain() == *this);
    const auto &c = static_cast<const nt_code &>(code);  // NOLINT
    return generic_code(static_cast<errc>(_nt_code_to_errno(c.value())));
  }
  virtual string_ref _do_message(const status_code<void> &code) const noexcept override  // NOLINT
  {
    assert(code.domain() == *this);
    const auto &c = static_cast<const nt_code &>(code);  // NOLINT
    return _make_string_ref(c.value());
  }
#if defined(_CPPUNWIND) || defined(__EXCEPTIONS) || 0
  SYSTEM_ERROR2_NORETURN virtual void _do_throw_exception(const status_code<void> &code) const override  // NOLINT
  {
    assert(code.domain() == *this);
    const auto &c = static_cast<const nt_code &>(code);  // NOLINT
    throw status_error<_nt_code_domain>(c);
  }
#endif
};
/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
constexpr _nt_code_domain nt_code_domain;
inline constexpr const _nt_code_domain &_nt_code_domain::get()
{
  return nt_code_domain;
}

SYSTEM_ERROR2_NAMESPACE_END

#endif
// NOT "com_code.hpp"
#endif

SYSTEM_ERROR2_NAMESPACE_BEGIN
/*! AWAITING HUGO JSON CONVERSION TOOL
type alias  system_code. Potential doc page: NOT FOUND
*/
using system_code = status_code<erased<intptr_t>>;

#ifndef NDEBUG
static_assert(sizeof(system_code) == 2 * sizeof(void *), "system_code is not exactly two pointers in size!");
static_assert(traits::is_move_relocating<system_code>::value, "system_code is not move relocating!");
#endif

SYSTEM_ERROR2_NAMESPACE_END

#endif
SYSTEM_ERROR2_NAMESPACE_BEGIN

/*! AWAITING HUGO JSON CONVERSION TOOL
type alias  error. Potential doc page: `error_type &error() &`
*/
using error = errored_status_code<erased<system_code::value_type>>;

#ifndef NDEBUG
static_assert(sizeof(error) == 2 * sizeof(void *), "error is not exactly two pointers in size!");
static_assert(traits::is_move_relocating<error>::value, "error is not move relocating!");
#endif

SYSTEM_ERROR2_NAMESPACE_END

#endif
#endif
OUTCOME_V2_NAMESPACE_EXPORT_BEGIN

namespace detail
{
  // Customise _set_error_is_errno
  template <class State> constexpr inline void _set_error_is_errno(State &state, const SYSTEM_ERROR2_NAMESPACE::generic_code & /*unused*/) { state._status |= status_error_is_errno; }
  template <class State> constexpr inline void _set_error_is_errno(State &state, const SYSTEM_ERROR2_NAMESPACE::posix_code & /*unused*/) { state._status |= status_error_is_errno; }
  template <class State> constexpr inline void _set_error_is_errno(State &state, const SYSTEM_ERROR2_NAMESPACE::errc & /*unused*/) { state._status |= status_error_is_errno; }

}  // namespace detail

namespace experimental
{
  using namespace SYSTEM_ERROR2_NAMESPACE;
  using OUTCOME_V2_NAMESPACE::success;
  using OUTCOME_V2_NAMESPACE::failure;

  namespace policy
  {
    using namespace OUTCOME_V2_NAMESPACE::policy;
    template <class T, class EC, class E> struct status_code_throw
    {
      static_assert(!std::is_same<T, T>::value, "policy::status_code_throw not specialised for these types, did you use status_result<T, status_code<DomainType>, E>?");
    };
    template <class T, class DomainType> struct status_code_throw<T, status_code<DomainType>, void> : base
    {
      using _base = base;
      template <class Impl> static constexpr void wide_value_check(Impl &&self)
      {
        if(!base::_has_value(static_cast<Impl &&>(self)))
        {
          if(base::_has_error(static_cast<Impl &&>(self)))
          {
#ifdef __cpp_exceptions
            base::_error(static_cast<Impl &&>(self)).throw_exception();
#else
            OUTCOME_THROW_EXCEPTION("wide value check failed");
#endif
          }
        }
      }
      template <class Impl> static constexpr void wide_error_check(Impl &&self) { _base::narrow_error_check(static_cast<Impl &&>(self)); }
    };
    template <class T, class DomainType> struct status_code_throw<T, errored_status_code<DomainType>, void> : status_code_throw<T, status_code<DomainType>, void>
    {
      status_code_throw() = default;
      using status_code_throw<T, status_code<DomainType>, void>::status_code_throw;
    };

    template <class T, class EC>
    using default_status_result_policy = std::conditional_t<                            //
    std::is_void<EC>::value,                                                            //
    OUTCOME_V2_NAMESPACE::policy::terminate,                                            //
    std::conditional_t<is_status_code<EC>::value || is_errored_status_code<EC>::value,  //
                       status_code_throw<T, EC, void>,                                  //
                       OUTCOME_V2_NAMESPACE::policy::fail_to_compile_observers          //
                       >>;
  }  // namespace policy

  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  template <class R, class S = system_code, class NoValuePolicy = policy::default_status_result_policy<R, S>>  //
  using status_result = basic_result<R, S, NoValuePolicy>;

}  // namespace experimental

OUTCOME_V2_NAMESPACE_END

#endif
// Boost.Outcome #include "boost/exception_ptr.hpp"

SYSTEM_ERROR2_NAMESPACE_BEGIN
template <class DomainType> inline std::exception_ptr basic_outcome_failure_exception_from_error(const status_code<DomainType> &sc)
{
  (void) sc;
#ifdef __cpp_exceptions
  try
  {
    sc.throw_exception();
  }
  catch(...)
  {
    return std::current_exception();
  }
#endif
  return {};
}
SYSTEM_ERROR2_NAMESPACE_END

OUTCOME_V2_NAMESPACE_EXPORT_BEGIN

namespace trait
{
  namespace detail
  {
    // Shortcut this for lower build impact
    template <class DomainType> struct _is_error_code_available<SYSTEM_ERROR2_NAMESPACE::status_code<DomainType>>
    {
      static constexpr bool value = true;
    };
    template <class DomainType> struct _is_error_code_available<SYSTEM_ERROR2_NAMESPACE::errored_status_code<DomainType>>
    {
      static constexpr bool value = true;
    };
  }  // namespace detail














}  // namespace trait


namespace experimental
{
  namespace policy
  {
    template <class T, class EC, class E>
    using default_status_outcome_policy = std::conditional_t<                                                                                                                              //
    std::is_void<EC>::value && std::is_void<E>::value,                                                                                                                                     //
    OUTCOME_V2_NAMESPACE::policy::terminate,                                                                                                                                               //
    std::conditional_t<(is_status_code<EC>::value || is_errored_status_code<EC>::value) && (std::is_void<E>::value || OUTCOME_V2_NAMESPACE::trait::is_exception_ptr_available<E>::value),  //
                       status_code_throw<T, EC, E>,                                                                                                                                        //
                       OUTCOME_V2_NAMESPACE::policy::fail_to_compile_observers                                                                                                             //
                       >>;
  }  // namespace policy

  /*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/


  template <class R, class S = system_code, class P = std::exception_ptr, class NoValuePolicy = policy::default_status_outcome_policy<R, S, P>>  //
  using status_outcome = basic_outcome<R, S, P, NoValuePolicy>;

  namespace policy
  {
    template <class T, class DomainType, class E> struct status_code_throw<T, status_code<DomainType>, E> : base
    {
      using _base = base;
      template <class Impl> static constexpr void wide_value_check(Impl &&self)
      {
        if(!base::_has_value(static_cast<Impl &&>(self)))
        {
          if(base::_has_exception(static_cast<Impl &&>(self)))
          {
            OUTCOME_V2_NAMESPACE::policy::detail::_rethrow_exception<trait::is_exception_ptr_available<E>::value>(base::_exception<T, status_code<DomainType>, E, status_code_throw>(static_cast<Impl &&>(self)));  // NOLINT
          }
          if(base::_has_error(static_cast<Impl &&>(self)))
          {
#ifdef __cpp_exceptions
            base::_error(static_cast<Impl &&>(self)).throw_exception();
#else
            OUTCOME_THROW_EXCEPTION("wide value check failed");
#endif
          }
        }
      }
      template <class Impl> static constexpr void wide_error_check(Impl &&self) { _base::narrow_error_check(static_cast<Impl &&>(self)); }
      template <class Impl> static constexpr void wide_exception_check(Impl &&self) { _base::narrow_exception_check(static_cast<Impl &&>(self)); }
    };
    template <class T, class DomainType, class E> struct status_code_throw<T, errored_status_code<DomainType>, E> : status_code_throw<T, status_code<DomainType>, E>
    {
      status_code_throw() = default;
      using status_code_throw<T, status_code<DomainType>, E>::status_code_throw;
    };
  }  // namespace policy

}  // namespace experimental

OUTCOME_V2_NAMESPACE_END

#endif
/* Try operation macros
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

#ifndef OUTCOME_TRY_HPP
#define OUTCOME_TRY_HPP



namespace std  // NOLINT
{
  namespace experimental
  {
    template <class T, class E> class expected;
    template <class E> class unexpected;
  }  // namespace experimental
}  // namespace std

OUTCOME_V2_NAMESPACE_BEGIN

/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
OUTCOME_TEMPLATE(class T)
OUTCOME_TREQUIRES(OUTCOME_TEXPR(std::declval<T>().as_failure()))
inline decltype(auto) try_operation_return_as(T &&v)
{
  return static_cast<T &&>(v).as_failure();
}
/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
template <class T, class E> inline auto try_operation_return_as(const std::experimental::expected<T, E> &v)
{
  return std::experimental::unexpected<E>(v.error());
}
/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
template <class T, class E> inline auto try_operation_return_as(std::experimental::expected<T, E> &&v)
{
  return std::experimental::unexpected<E>(static_cast<std::experimental::expected<T, E> &&>(v).error());
}

namespace detail
{
  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TEXPR(std::declval<T>().assume_value()))
  inline decltype(auto) try_extract_value(T &&v) { return static_cast<T &&>(v).assume_value(); }

  template <class T, class... Args> inline decltype(auto) try_extract_value(T &&v, Args &&... /*unused*/) { return static_cast<T &&>(v).value(); }
}  // namespace detail

OUTCOME_V2_NAMESPACE_END

#define OUTCOME_TRY_GLUE2(x, y) x##y
#define OUTCOME_TRY_GLUE(x, y) OUTCOME_TRY_GLUE2(x, y)
#define OUTCOME_TRY_UNIQUE_NAME OUTCOME_TRY_GLUE(_outcome_try_unique_name_temporary, __COUNTER__)

#define OUTCOME_TRY_RETURN_ARG_COUNT(_1_, _2_, _3_, _4_, _5_, _6_, _7_, _8_, count, ...) count
#define OUTCOME_TRY_EXPAND_ARGS(args) OUTCOME_TRY_RETURN_ARG_COUNT args
#define OUTCOME_TRY_COUNT_ARGS_MAX8(...) OUTCOME_TRY_EXPAND_ARGS((__VA_ARGS__, 8, 7, 6, 5, 4, 3, 2, 1, 0))
#define OUTCOME_TRY_OVERLOAD_MACRO2(name, count) name##count
#define OUTCOME_TRY_OVERLOAD_MACRO1(name, count) OUTCOME_TRY_OVERLOAD_MACRO2(name, count)
#define OUTCOME_TRY_OVERLOAD_MACRO(name, count) OUTCOME_TRY_OVERLOAD_MACRO1(name, count)
#define OUTCOME_TRY_OVERLOAD_GLUE(x, y) x y
#define OUTCOME_TRY_CALL_OVERLOAD(name, ...) OUTCOME_TRY_OVERLOAD_GLUE(OUTCOME_TRY_OVERLOAD_MACRO(name, OUTCOME_TRY_COUNT_ARGS_MAX8(__VA_ARGS__)), (__VA_ARGS__))

#if !defined(__clang__) && defined(__GNUC__) && __GNUC__ >= 8
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wparentheses"
#endif

#define OUTCOME_TRYV2(unique, ...)                                                                                                                                                                                                                                                                                               auto && (unique) = (__VA_ARGS__);                                                                                                                                                                                                                                                                                              if(!(unique).has_value())                                                                                                                                                                                                                                                                                                      return OUTCOME_V2_NAMESPACE::try_operation_return_as(static_cast<decltype(unique) &&>(unique))



#define OUTCOME_TRY2(unique, v, ...)                                                                                                                                                                                                                                                                                             OUTCOME_TRYV2(unique, __VA_ARGS__);                                                                                                                                                                                                                                                                                            auto && (v) = OUTCOME_V2_NAMESPACE::detail::try_extract_value(static_cast<decltype(unique) &&>(unique))



#if !defined(__clang__) && defined(__GNUC__) && __GNUC__ >= 8
#pragma GCC diagnostic pop
#endif

/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
#define OUTCOME_TRYV(...) OUTCOME_TRYV2(OUTCOME_TRY_UNIQUE_NAME, __VA_ARGS__)

#if defined(__GNUC__) || defined(__clang__)

/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
#define OUTCOME_TRYX(...)                                                                                                                                                                                                                                                                                                        ({                                                                                                                                                                                                                                                                                                                               auto &&res = (__VA_ARGS__);                                                                                                                                                                                                                                                                                                    if(!res.has_value())                                                                                                                                                                                                                                                                                                             return OUTCOME_V2_NAMESPACE::try_operation_return_as(static_cast<decltype(res) &&>(res));                                                                                                                                                                                                                                    OUTCOME_V2_NAMESPACE::detail::try_extract_value(static_cast<decltype(res) &&>(res));                                                                                                                                                                                                                                         })







#endif

/*! AWAITING HUGO JSON CONVERSION TOOL
SIGNATURE NOT RECOGNISED
*/
#define OUTCOME_TRYA(v, ...) OUTCOME_TRY2(OUTCOME_TRY_UNIQUE_NAME, v, __VA_ARGS__)

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

#endif
