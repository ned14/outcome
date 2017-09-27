/* iostream specialisations for result and outcome
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























#ifndef OUTCOME_IOSTREAM_SUPPORT_HPP
#define OUTCOME_IOSTREAM_SUPPORT_HPP
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
//! \brief Major version for cmake and DLL version stamping \ingroup config
#define OUTCOME_VERSION_MAJOR 2
//! \brief Minor version for cmake and DLL version stamping \ingroup config
#define OUTCOME_VERSION_MINOR 0
//! \brief Patch version for cmake and DLL version stamping \ingroup config
#define OUTCOME_VERSION_PATCH 0
//! \brief Revision version for cmake and DLL version stamping \ingroup config
#define OUTCOME_VERSION_REVISION 0 // Revision version for cmake and DLL version stamping

//! \brief Defined between stable releases of Outcome. It means the inline namespace
//! will be permuted per-commit to ensure ABI uniqueness. \ingroup config
#define OUTCOME_UNSTABLE_VERSION
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
#define __cpp_constexpr 201304 // relaxed constexpr
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

#if !defined(__cpp_explicit_conversion) //// renamed from __cpp_explicit_conversions
#define __cpp_explicit_conversion 190000
#endif

#if !defined(__cpp_inheriting_constructors)
#define __cpp_inheriting_constructors 190000
#endif

#if !defined(__cpp_initializer_lists) //// NEW
#define __cpp_initializer_lists 190000
#endif

#if !defined(__cpp_lambdas)
#define __cpp_lambdas 190000
#endif

#if !defined(__cpp_nsdmi)
#define __cpp_nsdmi 190000 //// NEW
#endif

#if !defined(__cpp_range_based_for) //// renamed from __cpp_range_for
#define __cpp_range_based_for 190000
#endif

#if !defined(__cpp_raw_strings)
#define __cpp_raw_strings 190000
#endif

#if !defined(__cpp_ref_qualifiers) //// renamed from __cpp_reference_qualified_functions
#define __cpp_ref_qualifiers 190000
#endif

#if !defined(__cpp_rvalue_references)
#define __cpp_rvalue_references 190000
#endif

#if !defined(__cpp_static_assert)
#define __cpp_static_assert 190000
#endif

#if !defined(__cpp_unicode_characters) //// NEW
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

#endif // _MSC_VER


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

#endif // __GXX_EXPERIMENTAL_CXX0X__

#endif // GCC


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

#endif // __GXX_EXPERIMENTAL_CXX0X__

#endif // clang

#endif
// Note the second line of this file must ALWAYS be the git SHA, third line ALWAYS the git SHA update time
#define QUICKCPPLIB_PREVIOUS_COMMIT_REF c7a2d31274ff5a8d7a1cac6cd6144e9130115e8d
#define QUICKCPPLIB_PREVIOUS_COMMIT_DATE "2017-09-24 18:33:07 +00:00"
#define QUICKCPPLIB_PREVIOUS_COMMIT_UNIQUE c7a2d312
#define QUICKCPPLIB_VERSION_GLUE2(a, b) a##b
#define QUICKCPPLIB_VERSION_GLUE(a, b) QUICKCPPLIB_VERSION_GLUE2(a, b)

// clang-format off













#define QUICKCPPLIB_NAMESPACE quickcpplib::QUICKCPPLIB_VERSION_GLUE(_, QUICKCPPLIB_PREVIOUS_COMMIT_UNIQUE)
#define QUICKCPPLIB_NAMESPACE_BEGIN namespace quickcpplib { namespace QUICKCPPLIB_VERSION_GLUE(_, QUICKCPPLIB_PREVIOUS_COMMIT_UNIQUE) {
#define QUICKCPPLIB_NAMESPACE_END } }

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
#ifdef __has_cpp_attribute
#if __has_cpp_attribute(nodiscard)
#define QUICKCPPLIB_NODISCARD [[nodiscard]]
#endif
#elif defined(__clang__)
#define QUICKCPPLIB_NODISCARD __attribute__((warn_unused_result))
#elif defined(_MSC_VER)
// _Must_inspect_result_ expands into this
#define QUICKCPPLIB_NODISCARD __declspec("SAL_name" "(" "\"_Must_inspect_result_\"" "," "\"\"" "," "\"2\"" ")") __declspec("SAL_begin") __declspec("SAL_post") __declspec("SAL_mustInspect") __declspec("SAL_post") __declspec("SAL_checkReturn") __declspec("SAL_end")








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
#define QUICKCPPLIB_TEXPR(...) requires { (__VA_ARGS__); }

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
#define QUICKCPPLIB_BIND_NAMESPACE_EXPAND8(a, b, c, d, e, f, g, h) QUICKCPPLIB_BIND_NAMESPACE_SELECT_ a QUICKCPPLIB_BIND_NAMESPACE_SELECT b QUICKCPPLIB_BIND_NAMESPACE_SELECT c QUICKCPPLIB_BIND_NAMESPACE_SELECT d QUICKCPPLIB_BIND_NAMESPACE_SELECT e QUICKCPPLIB_BIND_NAMESPACE_SELECT f QUICKCPPLIB_BIND_NAMESPACE_SELECT g QUICKCPPLIB_BIND_NAMESPACE_SELECT h

#define QUICKCPPLIB_BIND_NAMESPACE_EXPAND7(a, b, c, d, e, f, g) QUICKCPPLIB_BIND_NAMESPACE_SELECT_ a QUICKCPPLIB_BIND_NAMESPACE_SELECT b QUICKCPPLIB_BIND_NAMESPACE_SELECT c QUICKCPPLIB_BIND_NAMESPACE_SELECT d QUICKCPPLIB_BIND_NAMESPACE_SELECT e QUICKCPPLIB_BIND_NAMESPACE_SELECT f QUICKCPPLIB_BIND_NAMESPACE_SELECT g
#define QUICKCPPLIB_BIND_NAMESPACE_EXPAND6(a, b, c, d, e, f) QUICKCPPLIB_BIND_NAMESPACE_SELECT_ a QUICKCPPLIB_BIND_NAMESPACE_SELECT b QUICKCPPLIB_BIND_NAMESPACE_SELECT c QUICKCPPLIB_BIND_NAMESPACE_SELECT d QUICKCPPLIB_BIND_NAMESPACE_SELECT e QUICKCPPLIB_BIND_NAMESPACE_SELECT f
#define QUICKCPPLIB_BIND_NAMESPACE_EXPAND5(a, b, c, d, e) QUICKCPPLIB_BIND_NAMESPACE_SELECT_ a QUICKCPPLIB_BIND_NAMESPACE_SELECT b QUICKCPPLIB_BIND_NAMESPACE_SELECT c QUICKCPPLIB_BIND_NAMESPACE_SELECT d QUICKCPPLIB_BIND_NAMESPACE_SELECT e
#define QUICKCPPLIB_BIND_NAMESPACE_EXPAND4(a, b, c, d) QUICKCPPLIB_BIND_NAMESPACE_SELECT_ a QUICKCPPLIB_BIND_NAMESPACE_SELECT b QUICKCPPLIB_BIND_NAMESPACE_SELECT c QUICKCPPLIB_BIND_NAMESPACE_SELECT d
#define QUICKCPPLIB_BIND_NAMESPACE_EXPAND3(a, b, c) QUICKCPPLIB_BIND_NAMESPACE_SELECT_ a QUICKCPPLIB_BIND_NAMESPACE_SELECT b QUICKCPPLIB_BIND_NAMESPACE_SELECT c
#define QUICKCPPLIB_BIND_NAMESPACE_EXPAND2(a, b) QUICKCPPLIB_BIND_NAMESPACE_SELECT_ a QUICKCPPLIB_BIND_NAMESPACE_SELECT b
#define QUICKCPPLIB_BIND_NAMESPACE_EXPAND1(a) QUICKCPPLIB_BIND_NAMESPACE_SELECT_ a
//! Expands into a::b::c:: ...
#define QUICKCPPLIB_BIND_NAMESPACE(...) QUICKCPPLIB_CALL_OVERLOAD(QUICKCPPLIB_BIND_NAMESPACE_EXPAND, __VA_ARGS__)

#define QUICKCPPLIB_BIND_NAMESPACE_BEGIN_NAMESPACE_SELECT2(name, modifier) modifier namespace name {


#define QUICKCPPLIB_BIND_NAMESPACE_BEGIN_NAMESPACE_SELECT1(name) namespace name {


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

#define QUICKCPPLIB_BIND_NAMESPACE_EXPORT_BEGIN_NAMESPACE_SELECT2(name, modifier) modifier namespace name {


#define QUICKCPPLIB_BIND_NAMESPACE_EXPORT_BEGIN_NAMESPACE_SELECT1(name) export namespace name {


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
// Note the second line of this file must ALWAYS be the git SHA, third line ALWAYS the git SHA update time
#define OUTCOME_PREVIOUS_COMMIT_REF 6089de54751fd2be2bffdd99c86ed2385cb70c18
#define OUTCOME_PREVIOUS_COMMIT_DATE "2017-09-25 23:03:18 +00:00"
#define OUTCOME_PREVIOUS_COMMIT_UNIQUE 6089de54
#define OUTCOME_V2 (QUICKCPPLIB_BIND_NAMESPACE_VERSION(outcome_v2, OUTCOME_PREVIOUS_COMMIT_UNIQUE))




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


#ifndef OUTCOME_DO_FATAL_EXIT
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

#ifdef BINDLIB_EXPORTS
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
#include <stdlib.h> // for abort
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
#pragma warning(disable : 6385 6386) // MSVC static analyser can't grok this function. clang's analyser gives it thumbs up.
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
#include <cstdint> // for uint32_t etc
#include <initializer_list>
#include <iosfwd> // for serialisation
#include <type_traits>
#include <utility> // for in_place_type_t

OUTCOME_V2_NAMESPACE_BEGIN

#if __cplusplus >= 201700 || _HAS_CXX17
template <class T> using in_place_type_t = std::in_place_type_t<T>;
using std::in_place_type;
#else
//! Aliases `std::in_place_type_t<T>` if on C++ 17 or later, else defined locally.
template <class T> struct in_place_type_t
{
  explicit in_place_type_t() = default;
};
//! Aliases `std::in_place_type<T>` if on C++ 17 or later, else defined locally.
template <class T> constexpr in_place_type_t<T> in_place_type{};
#endif

namespace detail
{
  // Test if type is an in_place_type_t
  template <class T> struct is_in_place_type_t : std::false_type
  {
  };
  template <class U> struct is_in_place_type_t<in_place_type_t<U>> : std::true_type
  {
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

  using status_bitfield_type = uint32_t;
  static constexpr status_bitfield_type status_have_value = (1 << 0);
  static constexpr status_bitfield_type status_have_error = (1 << 1);
  static constexpr status_bitfield_type status_have_status = (1 << 2);
  // bit 3 unused
  static constexpr status_bitfield_type status_error_is_errno = (1 << 4); // can errno be set from this error?
  static constexpr status_bitfield_type status_have_payload = (1 << 5);
  static constexpr status_bitfield_type status_have_exception = (1 << 6);
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
    status_bitfield_type _status;
    constexpr value_storage_trivial() noexcept : _empty{}, _status(0) {}
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
    value_storage_trivial(const value_storage_trivial &) = default;
    value_storage_trivial(value_storage_trivial &&) = default;
    value_storage_trivial &operator=(const value_storage_trivial &) = default;
    value_storage_trivial &operator=(value_storage_trivial &&) = default;
    constexpr explicit value_storage_trivial(status_bitfield_type status)
        : _empty()
        , _status(status)
    {
    }
    template <class... Args>
    constexpr value_storage_trivial(in_place_type_t<value_type>, Args &&... args) noexcept(std::is_nothrow_constructible<value_type, Args...>::value)
        : _value(std::forward<Args>(args)...)
        , _status(status_have_value)
    {
    }
    template <class U, class... Args>
    constexpr value_storage_trivial(in_place_type_t<value_type>, std::initializer_list<U> il, Args &&... args) noexcept(std::is_nothrow_constructible<value_type, std::initializer_list<U>, Args...>::value)
        : _value(il, std::forward<Args>(args)...)
        , _status(status_have_value)
    {
    }
    template <class U> static constexpr bool enable_converting_constructor = !std::is_same<std::decay_t<U>, value_type>::value && std::is_constructible<value_type, U>::value;
    OUTCOME_TEMPLATE(class U)
    OUTCOME_TREQUIRES(OUTCOME_TPRED(enable_converting_constructor<U>))
    constexpr explicit value_storage_trivial(const value_storage_trivial<U> &o) noexcept(std::is_nothrow_constructible<value_type, U>::value)
        : value_storage_trivial(((o._status & status_have_value) != 0) ? value_storage_trivial(in_place_type<value_type>, o._value) : value_storage_trivial())
    {
      _status = o._status;
    }
    OUTCOME_TEMPLATE(class U)
    OUTCOME_TREQUIRES(OUTCOME_TPRED(enable_converting_constructor<U>))
    constexpr explicit value_storage_trivial(value_storage_trivial<U> &&o) noexcept(std::is_nothrow_constructible<value_type, U>::value)
        : value_storage_trivial(((o._status & status_have_value) != 0) ? value_storage_trivial(in_place_type<value_type>, std::move(o._value)) : value_storage_trivial())
    {
      _status = o._status;
    }
    constexpr void swap(value_storage_trivial &o)
    {
      // storage is trivial, so just use assignment
      using std::swap;
      swap(*this, o);
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
    status_bitfield_type _status;
    value_storage_nontrivial() noexcept : _empty{}, _status(0) {}
    value_storage_nontrivial &operator=(const value_storage_nontrivial &) = default; // if reaches here, copy assignment is trivial
    value_storage_nontrivial &operator=(value_storage_nontrivial &&) = default; // if reaches here, move assignment is trivial
    value_storage_nontrivial(value_storage_nontrivial &&o) noexcept(std::is_nothrow_move_constructible<value_type>::value)
        : _status(o._status)
    {
      if(this->_status & status_have_value)
      {
        this->_status &= ~status_have_value;
        new(&_value) value_type(std::move(o._value));
        _status = o._status;
      }
    }
    value_storage_nontrivial(const value_storage_nontrivial &o) noexcept(std::is_nothrow_copy_constructible<value_type>::value)
        : _status(o._status)
    {
      if(this->_status & status_have_value)
      {
        this->_status &= ~status_have_value;
        new(&_value) value_type(o._value);
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
        new(&_value) value_type;
        _status = o._status;
      }
    }
    explicit value_storage_nontrivial(status_bitfield_type status)
        : _empty()
        , _status(status)
    {
    }
    template <class... Args>
    value_storage_nontrivial(in_place_type_t<value_type>, Args &&... args) noexcept(std::is_nothrow_constructible<value_type, Args...>::value)
        : _value(std::forward<Args>(args)...)
        , _status(status_have_value)
    {
    }
    template <class U, class... Args>
    value_storage_nontrivial(in_place_type_t<value_type>, std::initializer_list<U> il, Args &&... args) noexcept(std::is_nothrow_constructible<value_type, std::initializer_list<U>, Args...>::value)
        : _value(il, std::forward<Args>(args)...)
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
        : value_storage_nontrivial((o._status & status_have_value) != 0 ? value_storage_nontrivial(in_place_type<value_type>, std::move(o._value)) : value_storage_nontrivial())
    {
      _status = o._status;
    }
    OUTCOME_TEMPLATE(class U)
    OUTCOME_TREQUIRES(OUTCOME_TPRED(enable_converting_constructor<U>))
    constexpr explicit value_storage_nontrivial(value_storage_trivial<U> &&o) noexcept(std::is_nothrow_constructible<value_type, U>::value)
        : value_storage_nontrivial((o._status & status_have_value) != 0 ? value_storage_nontrivial(in_place_type<value_type>, std::move(o._value)) : value_storage_nontrivial())
    {
      _status = o._status;
    }
    ~value_storage_nontrivial() noexcept(std::is_nothrow_destructible<T>::value)
    {
      if(this->_status & status_have_value)
      {
        this->_value.~value_type();
        this->_status &= ~status_have_value;
      }
    }
    constexpr void swap(value_storage_nontrivial &o)
    {
      using std::swap;
      if((_status & status_have_value) == 0 && (o._status & status_have_value) == 0)
      {
        swap(_status, o._status);
        return;
      }
      if((_status & status_have_value) != 0 && (o._status & status_have_value) != 0)
      {
        swap(_value, o._value);
        swap(_status, o._status);
        return;
      }
      // One must be empty and the other non-empty, so use move construction
      if((_status & status_have_value) != 0)
      {
        // Move construct me into other
        new(&o._value) value_type(std::move(_value));
        this->_value.~value_type();
        swap(_status, o._status);
      }
      else
      {
        // Move construct other into me
        new(&_value) value_type(std::move(o._value));
        o._value.~value_type();
        swap(_status, o._status);
      }
    }
  };
  template <class Base> struct value_storage_delete_copy_constructor : Base
  {
    using Base::Base;
    using value_type = typename Base::value_type;
    value_storage_delete_copy_constructor() = default;
    value_storage_delete_copy_constructor(const value_storage_delete_copy_constructor &) = delete;
    value_storage_delete_copy_constructor(value_storage_delete_copy_constructor &&) = default;
  };
  template <class Base> struct value_storage_delete_copy_assignment : Base
  {
    using Base::Base;
    using value_type = typename Base::value_type;
    value_storage_delete_copy_assignment() = default;
    value_storage_delete_copy_assignment(const value_storage_delete_copy_assignment &) = default;
    value_storage_delete_copy_assignment(value_storage_delete_copy_assignment &&) = default;
    value_storage_delete_copy_assignment &operator=(const value_storage_delete_copy_assignment &o) = delete;
    value_storage_delete_copy_assignment &operator=(value_storage_delete_copy_assignment &&o) = default;
  };
  template <class Base> struct value_storage_delete_move_assignment : Base
  {
    using Base::Base;
    using value_type = typename Base::value_type;
    value_storage_delete_move_assignment() = default;
    value_storage_delete_move_assignment(const value_storage_delete_move_assignment &) = default;
    value_storage_delete_move_assignment(value_storage_delete_move_assignment &&) = default;
    value_storage_delete_move_assignment &operator=(const value_storage_delete_move_assignment &o) = default;
    value_storage_delete_move_assignment &operator=(value_storage_delete_move_assignment &&o) = delete;
  };
  template <class Base> struct value_storage_delete_move_constructor : Base
  {
    using Base::Base;
    using value_type = typename Base::value_type;
    value_storage_delete_move_constructor() = default;
    value_storage_delete_move_constructor(const value_storage_delete_move_constructor &) = default;
    value_storage_delete_move_constructor(value_storage_delete_move_constructor &&) = delete;
  };
  template <class Base> struct value_storage_nontrivial_move_assignment : Base
  {
    using Base::Base;
    using value_type = typename Base::value_type;
    value_storage_nontrivial_move_assignment() = default;
    value_storage_nontrivial_move_assignment(const value_storage_nontrivial_move_assignment &) = default;
    value_storage_nontrivial_move_assignment(value_storage_nontrivial_move_assignment &&) = default;
    value_storage_nontrivial_move_assignment &operator=(const value_storage_nontrivial_move_assignment &o) = default;
    value_storage_nontrivial_move_assignment &operator=(value_storage_nontrivial_move_assignment &&o) noexcept(std::is_nothrow_move_assignable<value_type>::value)
    {
      if((this->_status & status_have_value) != 0 && (o._status & status_have_value) != 0)
      {
        this->_value = std::move(o._value);
      }
      else if((this->_status & status_have_value) != 0 && (o._status & status_have_value) == 0)
      {
        this->_value.~value_type();
      }
      else if((this->_status & status_have_value) == 0 && (o._status & status_have_value) != 0)
      {
        new(&this->_value) value_type(std::move(o._value));
      }
      this->_status = o._status;
      return *this;
    }
  };
  template <class Base> struct value_storage_nontrivial_copy_assignment : Base
  {
    using Base::Base;
    using value_type = typename Base::value_type;
    value_storage_nontrivial_copy_assignment() = default;
    value_storage_nontrivial_copy_assignment(const value_storage_nontrivial_copy_assignment &) = default;
    value_storage_nontrivial_copy_assignment(value_storage_nontrivial_copy_assignment &&) = default;
    value_storage_nontrivial_copy_assignment &operator=(value_storage_nontrivial_copy_assignment &&o) = default;
    value_storage_nontrivial_copy_assignment &operator=(const value_storage_nontrivial_copy_assignment &o) noexcept(std::is_nothrow_copy_assignable<value_type>::value)
    {
      if((this->_status & status_have_value) != 0 && (o._status & status_have_value) != 0)
      {
        this->_value = o._value;
      }
      else if((this->_status & status_have_value) != 0 && (o._status & status_have_value) == 0)
      {
        this->_value.~value_type();
      }
      else if((this->_status & status_have_value) == 0 && (o._status & status_have_value) != 0)
      {
        new(&this->_value) value_type(o._value);
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
}

OUTCOME_V2_NAMESPACE_END

#endif
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



#include <exception>
#include <system_error>
#include <type_traits>

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



OUTCOME_V2_NAMESPACE_END

#endif
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

//! Thrown when you try to access a vlue in a `result<R, S>` which isn't present.
template <class S> class OUTCOME_SYMBOL_VISIBLE bad_result_access_with : public bad_result_access
{
  S _error;

public:
  bad_result_access_with(S v)
      : bad_result_access("no value")
      , _error(std::move(v))
  {
  }
  //! Observes the error
  const S &error() const & { return _error; }
  //! Observes the error
  S &error() & { return _error; }
  //! Observes the error
  const S &&error() const && { return _error; }
  //! Observes the error
  S &&error() && { return _error; }
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
  /* True if type is the same or constructible. Works around a bug where clang + libstdc++
  pukes on std::is_constructible<filesystem::path, void> (this bug is fixed upstream).
  */


  template <class T, class U, class... Args> struct _is_same_or_constructible
  {
    static constexpr bool value = std::is_constructible<T, U, Args...>::value;
  };
  template <class T> struct _is_same_or_constructible<T, T>
  {
    static constexpr bool value = true;
  };
  template <class T> struct _is_same_or_constructible<T, void>
  {
    static constexpr bool value = false;
  };
  template <> struct _is_same_or_constructible<void, void>
  {
    static constexpr bool value = false;
  };
  template <class T, class U, class... Args> static constexpr bool is_same_or_constructible = _is_same_or_constructible<T, U>::value;
// True if type is nothrow swappable
#if !0 && __cplusplus >= 201700
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

  template <class State, class E> constexpr inline void _set_error_is_errno(State & /*unused*/, E & /*unused*/) {}
  template <class State> constexpr inline void _set_error_is_errno(State &state, const std::error_code &error)
  {
    if(error.category() == std::generic_category()
#ifndef _WIN32
       || error.category() == std::system_category()
#endif
       )
    {
      state._status |= status_error_is_errno;
    }
  }
  template <class State> constexpr inline void _set_error_is_errno(State &state, const std::error_condition &error)
  {
    if(error.category() == std::generic_category()
#ifndef _WIN32
       || error.category() == std::system_category()
#endif
       )
    {
      state._status |= status_error_is_errno;
    }
  }
  template <class State> constexpr inline void _set_error_is_errno(State &state, const std::errc & /*unused*/) { state._status |= status_error_is_errno; }
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
  template <class R, class EC, class NoValuePolicy> //
  OUTCOME_REQUIRES( //
  (!std::is_reference<R>::value //
   && !detail::is_in_place_type_t<std::decay_t<R>>::value //
   && !std::is_array<R>::value //
   && (std::is_void<R>::value || (std::is_object<R>::value //
                                  && std::is_destructible<R>::value)) //
   ) &&
  (!std::is_reference<EC>::value //
   && !detail::is_in_place_type_t<std::decay_t<EC>>::value //
   && !std::is_array<EC>::value //
   && (std::is_void<EC>::value || (std::is_object<EC>::value //
                                   && std::is_destructible<EC>::value)) //
   ) //
  ) //
  class result_storage
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
        : _state{_, std::forward<Args>(args)...}
        , _error()
    {
    }
    template <class U, class... Args>
    constexpr result_storage(in_place_type_t<_value_type> _, std::initializer_list<U> il, Args &&... args) noexcept(std::is_nothrow_constructible<_value_type, std::initializer_list<U>, Args...>::value)
        : _state{_, il, std::forward<Args>(args)...}
        , _error()
    {
    }
    template <class... Args>
    constexpr result_storage(in_place_type_t<_error_type>, Args &&... args) noexcept(std::is_nothrow_constructible<_error_type, Args...>::value)
        : _state{detail::status_have_error}
        , _error{std::forward<Args>(args)...}
    {
      detail::_set_error_is_errno(_state, _error);
    }
    template <class U, class... Args>
    constexpr result_storage(in_place_type_t<_error_type>, std::initializer_list<U> il, Args &&... args) noexcept(std::is_nothrow_constructible<_error_type, std::initializer_list<U>, Args...>::value)
        : _state{detail::status_have_error}
        , _error{il, std::forward<Args>(args)...}
    {
      detail::_set_error_is_errno(_state, _error);
    }
#if OUTCOME_ENABLE_POSITIVE_STATUS
    struct value_status_construction_tag
    {
    };
    template <class T, class U>
    constexpr result_storage(value_status_construction_tag, T &&t, U &&u) noexcept(std::is_nothrow_constructible<_value_type, T>::value &&std::is_nothrow_constructible<_status_type, U>::value)
        : _state{in_place_type<_value_type>, std::forward<T>(t)}
        , _error{std::forward<U>(u)}
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
    */

    constexpr void assume_value() const noexcept { NoValuePolicy::narrow_value_check(this); }
    /// \output_section Wide state observers
    /*! Access value with runtime checks.
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
    */

    constexpr void assume_error() const noexcept { NoValuePolicy::narrow_error_check(this); }
    /// \output_section Wide state observers
    /*! Access error with runtime checks.
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
    constexpr bool operator==(const result_final<T, U, V> &o) const noexcept( //
    noexcept(detail::safe_compare_equal(std::declval<detail::devoid<R>>(), std::declval<detail::devoid<T>>())) //
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





    constexpr bool operator==(const success_type<void> &o) const noexcept
    {
      (void) o;
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





    template <class T> constexpr bool operator==(const failure_type<T, void> &o) const noexcept(noexcept(detail::safe_compare_equal(std::declval<detail::devoid<S>>(), std::declval<detail::devoid<T>>()))) { return detail::safe_compare_equal(this->_error, o.error); }
    /*! True if not equal to the other result.
    \param o The other result to compare to.

    \effects If a valid expression to do so, calls the `operator!=` operation on each
    of the two stored items, returning true if any are not equal. Otherwise returns true.
    \throws Any exception the individual `operator!=` operations might throw.
    */






    template <class T, class U, class V>
    constexpr bool operator!=(const result_final<T, U, V> &o) const noexcept( //
    noexcept(detail::safe_compare_notequal(std::declval<detail::devoid<R>>(), std::declval<detail::devoid<T>>())) //
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





    constexpr bool operator!=(const success_type<void> &o) const noexcept
    {
      (void) o;
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





    template <class T> constexpr bool operator!=(const failure_type<T, void> &o) const noexcept(noexcept(detail::safe_compare_notequal(std::declval<detail::devoid<S>>(), std::declval<detail::devoid<T>>()))) { return detail::safe_compare_notequal(this->_error, o.error); }
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
  /*! Policy which throws `bad_result_access_with<EC>` or `bad_result_access` during wide checks.
  \module Error code interpretation policy
  */


  template <class EC> struct throw_bad_result_access
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
    \effects If result does not have a value, it throws `bad_result_access`.
    */


    template <class Impl> static constexpr void wide_value_check(Impl *self)
    {
      if((self->_state._status & detail::status_have_value) == 0)
      {
        throw bad_result_access_with<EC>(self->_error);
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
  /*! Policy interpreting EC as an enum convertible into the `std::error_code` contract
  and any wide attempt to access the successful state throws the `error_code` wrapped into
  a `std::system_error`
  \module Error code interpretation policy
  */




  template <class EC> struct error_enum_throw_as_system_error
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
          throw std::system_error(make_error_code(self->_error));
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
  using default_result_policy = std::conditional_t< //
  std::is_void<EC>::value, //
  terminate, //
  std::conditional_t< //
  std::is_error_code_enum<EC>::value || std::is_error_condition_enum<EC>::value, //
  error_enum_throw_as_system_error<EC>, //
  std::conditional_t< //
  detail::is_same_or_constructible<std::error_code, EC>, error_code_throw_as_system_error<EC>, //
  std::conditional_t< //
  detail::is_same_or_constructible<std::exception_ptr, EC>, exception_ptr_rethrow<EC>, //
  throw_bad_result_access<EC> //
  >>>>;
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
    // Predicate for the implicit constructors to be available
    static constexpr bool implicit_constructors_enabled = //
    (std::is_same<bool, std::decay_t<value_type>>::value || !is_same_or_constructible<value_type, status_error_type>) //
    &&!is_same_or_constructible<status_error_type, value_type>;

    // Predicate for the value converting constructor to be available.
    template <class T>
    static constexpr bool enable_value_converting_constructor = //
    implicit_constructors_enabled //
    && !is_in_place_type_t<std::decay_t<T>>::value // not in place construction
    && is_same_or_constructible<value_type, T> && !std::is_constructible<status_error_type, T>::value;

    // Predicate for the error converting constructor to be available.
    template <class T>
    static constexpr bool enable_error_converting_constructor = //
    implicit_constructors_enabled //
    && !is_in_place_type_t<std::decay_t<T>>::value // not in place construction
    && !std::is_constructible<value_type, T>::value && is_same_or_constructible<error_type, T>;

    // Predicate for the error condition converting constructor to be available.
    template <class ErrorCondEnum>
    static constexpr bool enable_error_condition_converting_constructor = //
    !is_in_place_type_t<std::decay_t<ErrorCondEnum>>::value // not in place construction
    && std::is_error_condition_enum<ErrorCondEnum>::value // is an error condition enum
    && !std::is_constructible<value_type, ErrorCondEnum>::value && !std::is_constructible<error_type, ErrorCondEnum>::value; // not constructible via any other means

    // Predicate for the converting copy constructor from a compatible input to be available.
    template <class T, class U, class V>
    static constexpr bool enable_compatible_conversion = //
    (std::is_void<T>::value || is_same_or_constructible<value_type, typename result<T, U, V>::value_type>) // if our value types are constructible
    &&(std::is_void<U>::value || is_same_or_constructible<error_type, typename result<T, U, V>::error_type>) // if our error types are constructible
#if OUTCOME_ENABLE_POSITIVE_STATUS
    &&(std::is_void<U>::value || is_same_or_constructible<status_type, typename result<T, U, V>::status_type>) // if our status types are constructible
#endif
    ;

    // Predicate for the implicit converting inplace constructor from a compatible input to be available.
    struct disable_inplace_value_error_constructor;
    template <class... Args>
    using choose_inplace_value_error_constructor = std::conditional_t< //
    std::is_constructible<value_type, Args...>::value && std::is_constructible<error_type, Args...>::value, //
    disable_inplace_value_error_constructor, //
    std::conditional_t< //
    std::is_constructible<value_type, Args...>::value, //
    value_type, //
    std::conditional_t< //
    std::is_constructible<error_type, Args...>::value, //
    error_type, //
    disable_inplace_value_error_constructor>>>;
    template <class... Args>
    static constexpr bool enable_inplace_value_error_constructor = implicit_constructors_enabled //
                                                                   && !std::is_same<choose_inplace_value_error_constructor<Args...>, disable_inplace_value_error_constructor>::value;
  };

  template <class T, class U> constexpr inline const U &extract_value_from_success(const success_type<U> &v) { return v.value; }
  template <class T, class U> constexpr inline U &&extract_value_from_success(success_type<U> &&v) { return std::move(v.value); }
  template <class T> constexpr inline T extract_value_from_success(const success_type<void> & /*unused*/) { return T{}; }

  template <class T, class U, class V> constexpr inline const U &extract_error_from_failure(const failure_type<U, V> &v) { return v.error; }
  template <class T, class U, class V> constexpr inline U &&extract_error_from_failure(failure_type<U, V> &&v) { return std::move(v.error); }
  template <class T, class V> constexpr inline T extract_error_from_failure(const failure_type<void, V> & /*unused*/) { return T{}; }

  template <class T> struct is_result : std::false_type
  {
  };
  template <class R, class S, class T> struct is_result<result<R, S, T>> : std::true_type
  {
  };
}

//! True if a result
template <class T> static constexpr bool is_result_v = detail::is_result<std::decay_t<T>>::value;

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
    static constexpr bool enable_value_converting_constructor = //
    !std::is_same<std::decay_t<T>, result>::value // not my type
    && base::template enable_value_converting_constructor<T>;

    //! Predicate for the error converting constructor to be available.
    template <class T>
    static constexpr bool enable_error_converting_constructor = //
    !std::is_same<std::decay_t<T>, result>::value // not my type
    && base::template enable_error_converting_constructor<T>;

    //! Predicate for the error condition converting constructor to be available.
    template <class ErrorCondEnum>
    static constexpr bool enable_error_condition_converting_constructor = //
    !std::is_same<std::decay_t<ErrorCondEnum>, result>::value // not my type
    && base::template enable_error_condition_converting_constructor<ErrorCondEnum>;

    //! Predicate for the converting copy constructor from a compatible input to be available.
    template <class T, class U, class V>
    static constexpr bool enable_compatible_conversion = //
    !std::is_same<result<T, U, V>, result>::value // not my type
    && base::template enable_compatible_conversion<T, U, V>;

    //! Predicate for the inplace construction of value to be available.
    template <class... Args>
    static constexpr bool enable_inplace_value_constructor = //
    std::is_void<value_type>::value //
    || std::is_constructible<value_type, Args...>::value;

    //! Predicate for the inplace construction of error to be available.
    template <class... Args>
    static constexpr bool enable_inplace_error_constructor = //
    std::is_void<error_type>::value //
    || std::is_constructible<error_type, Args...>::value;

    // Predicate for the implicit converting inplace constructor to be available.
    template <class... Args>
    static constexpr bool enable_inplace_value_error_constructor = //
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
      : base{in_place_type<typename base::value_type>, std::forward<T>(t)}
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












  template <class T, class U, typename enable_value_status_converting_constructor = std::enable_if_t< //
                              !std::is_same<std::decay_t<T>, result>::value // not my type
                              && !detail::is_in_place_type_t<std::decay_t<T>>::value // not in place construction
                              && detail::is_same_or_constructible<value_type, T> && !std::is_constructible<status_type, T>::value && detail::is_same_or_constructible<status_type, U> && !std::is_constructible<value_type, U>::value>>
  constexpr result(T &&t, U &&u, value_status_converting_constructor_tag = value_status_converting_constructor_tag()) noexcept(std::is_nothrow_constructible<value_type, T>::value &&std::is_nothrow_constructible<status_type, U>::value)
      : base{typename base::value_status_construction_tag(), std::forward<T>(t), std::forward<U>(u)}
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
      : base{in_place_type<typename base::error_type>, std::forward<T>(t)}
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
  OUTCOME_TREQUIRES(OUTCOME_TEXPR(error_type(make_error_code(ErrorCondEnum()))), //
                    OUTCOME_TPRED(predicate::template enable_error_condition_converting_constructor<ErrorCondEnum>))
  constexpr result(ErrorCondEnum &&t, error_condition_converting_constructor_tag = error_condition_converting_constructor_tag()) noexcept(noexcept(error_type(make_error_code(std::forward<ErrorCondEnum>(t)))))
      : base{in_place_type<typename base::error_type>, make_error_code(t)}
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
      : base{typename base::compatible_conversion_tag(), o}
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
      : base{typename base::compatible_conversion_tag(), std::move(o)}
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
      : base{in_place_type<value_type_if_enabled>, std::forward<Args>(args)...}
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
      : base{in_place_type<value_type_if_enabled>, il, std::forward<Args>(args)...}
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
      : base{in_place_type<error_type_if_enabled>, std::forward<Args>(args)...}
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
      : base{in_place_type<error_type_if_enabled>, il, std::forward<Args>(args)...}
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
    /* I was a little surprised that the below is needed given that we forward to another constructor.
    But it turns out that ADL only fires on the first constructor for some reason.
    */


    using namespace hooks;
    // hook_result_in_place_construction(in_place_type<typename predicate::template choose_inplace_value_error_constructor<A1, A2, Args...>>, this);
  }

  /// \output_section Tagged constructors
  /*! Implicit tagged constructor of a successful result.
  \param o The compatible success type sugar.

  \effects Initialises the result with a default constructed success type.
  \requires `value_type` to be default constructible, or `void`.
  \throws Any exception the construction of `value_type()` might throw.
  */






  constexpr result(const success_type<void> &o) noexcept(std::is_nothrow_default_constructible<value_type>::value)
      : base{in_place_type<value_type_if_enabled>}
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
      : base{in_place_type<value_type_if_enabled>, detail::extract_value_from_success<value_type>(o)}
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
      : base{in_place_type<value_type_if_enabled>, std::move(detail::extract_value_from_success<value_type>(std::move(o)))}
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
      : base{in_place_type<error_type_if_enabled>, detail::extract_error_from_failure<error_type>(o)}
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
      : base{in_place_type<error_type_if_enabled>, std::move(detail::extract_error_from_failure<error_type>(std::move(o)))}
  {
    using namespace hooks;
    hook_result_move_construction(in_place_type<decltype(o)>, this);
  }

  /// \output_section Swap
  /*! Swaps this result with another result
  \effects Any `R` and/or `S` is swapped along with the metadata tracking them.
  */


  void swap(result &o) noexcept(detail::is_nothrow_swappable<value_type>::value //
                                &&detail::is_nothrow_swappable<status_error_type>::value)
  {
    using std::swap;
#ifdef __cpp_exceptions
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4297) // use of throw in noexcept function
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
    */

    constexpr void assume_payload() const noexcept { NoValuePolicy::narrow_payload_check(this); }
    /// \output_section Wide state observers
    /*! Access payload with runtime checks.
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
    */

    constexpr void assume_exception() const noexcept { NoValuePolicy::narrow_exception_check(this); }
    /// \output_section Wide state observers
    /*! Access exception with runtime checks.
    \requires The outcome to have an exception state, else whatever `NoValuePolicy` says ought to happen.
    */


    constexpr void exception() const { NoValuePolicy::wide_exception_check(this); }
  };

  //! The failure observers implementation of `outcome<R, S, P>`. Only appears separate due to standardese limitations.
  template <class Base, class R, class S, class P, class NoValuePolicy> class outcome_failure_observers : public Base
  {
  public:
    using exception_type = std::exception_ptr;
    using Base::Base;

    /// \output_section Synthesising state observers
    /*! Synthesise exception where possible.
    \returns A synthesised exception type: if excepted, `exception()`; if errored, `std::make_exception_ptr(std::system_error(error()))`;
    otherwise a default constructed exception type.
    */



    exception_type failure() const noexcept
    {
      if((this->_state._status & detail::status_have_exception) != 0)
      {
        return this->exception();
      }
      if((this->_state._status & detail::status_have_error) != 0)
      {
        return std::make_exception_ptr(std::system_error(this->error()));
      }
      return exception_type();
    }
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
  using default_outcome_policy = std::conditional_t< //
  detail::is_same_or_constructible<std::error_code, S> && trait::is_exception_ptr<P>::value, error_code_throw_as_system_error_exception_rethrow<R, S, P>, //
  terminate //
  >;
#else
  template <class R, class S, class P> using default_outcome_policy = terminate;
#endif
}

template <class R, class S = std::error_code, class P = std::exception_ptr, class NoValuePolicy = policy::default_outcome_policy<R, S, P>> OUTCOME_REQUIRES(std::is_void<P>::value || std::is_default_constructible<P>::value) class outcome;

namespace detail
{
  // May be reused by outcome subclasses to save load on the compiler
  template <class value_type, class status_error_type, class error_type, class payload_exception_type, class payload_type, class exception_type> struct outcome_predicates
  {
    using result = result_predicates<value_type, status_error_type, error_type>;
    // Predicate for the implicit constructors to be available
    static constexpr bool implicit_constructors_enabled = //
    (std::is_same<bool, std::decay_t<value_type>>::value || !is_same_or_constructible<value_type, status_error_type>) //
    &&(std::is_same<bool, std::decay_t<value_type>>::value || !is_same_or_constructible<value_type, payload_exception_type>) //
    &&!is_same_or_constructible<status_error_type, value_type> //
    && !is_same_or_constructible<status_error_type, payload_exception_type> //
    && !is_same_or_constructible<payload_exception_type, value_type> //
    && !is_same_or_constructible<payload_exception_type, status_error_type>;

    // Predicate for the value converting constructor to be available.
    template <class T>
    static constexpr bool enable_value_converting_constructor = //
    implicit_constructors_enabled //
    &&result::template enable_value_converting_constructor<T> //
    && !std::is_constructible<exception_type, T>::value;

    // Predicate for the error converting constructor to be available.
    template <class T>
    static constexpr bool enable_error_converting_constructor = //
    implicit_constructors_enabled //
    &&result::template enable_error_converting_constructor<T> //
    && !std::is_constructible<payload_exception_type, T>::value;

    // Predicate for the error + payload/exception constructor to be available.
    template <class T, class U>
    static constexpr bool enable_error_payload_converting_constructor = //
    !is_in_place_type_t<std::decay_t<T>>::value // not in place construction
    && !std::is_constructible<value_type, T>::value && detail::is_same_or_constructible<error_type, T> //
    && detail::is_same_or_constructible<payload_exception_type, U> && !std::is_constructible<value_type, U>::value;

    // Predicate for the error condition converting constructor to be available.
    template <class ErrorCondEnum>
    static constexpr bool enable_error_condition_converting_constructor = result::template enable_error_condition_converting_constructor<ErrorCondEnum> //
                                                                          && !std::is_constructible<payload_exception_type, ErrorCondEnum>::value;

    // Predicate for the exception converting constructor to be available.
    template <class T>
    static constexpr bool enable_exception_converting_constructor = //
    implicit_constructors_enabled //
    && !is_in_place_type_t<std::decay_t<T>>::value // not in place construction
    && !std::is_constructible<value_type, T>::value && !std::is_constructible<status_error_type, T>::value && detail::is_same_or_constructible<exception_type, T>;

    // Predicate for the converting copy constructor from a compatible outcome to be available.
    template <class T, class U, class V, class W>
    static constexpr bool enable_compatible_conversion = //
    (std::is_void<T>::value || detail::is_same_or_constructible<value_type, typename outcome<T, U, V, W>::value_type>) // if our value types are constructible
    &&(std::is_void<U>::value || detail::is_same_or_constructible<error_type, typename outcome<T, U, V, W>::error_type>) // if our error types are constructible
#if OUTCOME_ENABLE_POSITIVE_STATUS
    &&(std::is_void<U>::value || detail::is_same_or_constructible<status_type, typename outcome<T, U, V, W>::status_type>) // if our status types are constructible
#endif
    &&(std::is_void<V>::value || detail::is_same_or_constructible<payload_type, typename outcome<T, U, V, W>::payload_type>) // if our payload types are constructible
    &&(std::is_void<V>::value || detail::is_same_or_constructible<exception_type, typename outcome<T, U, V, W>::exception_type>) // if our exception types are constructible
    ;

    // Predicate for the implicit converting inplace constructor from a compatible input to be available.
    struct disable_inplace_value_error_exception_constructor;
    template <class... Args>
    using choose_inplace_value_error_exception_constructor = std::conditional_t< //
    ((static_cast<int>(std::is_constructible<value_type, Args...>::value) + static_cast<int>(std::is_constructible<error_type, Args...>::value) + static_cast<int>(std::is_constructible<exception_type, Args...>::value)) > 1), //
    disable_inplace_value_error_exception_constructor, //
    std::conditional_t< //
    std::is_constructible<value_type, Args...>::value, //
    value_type, //
    std::conditional_t< //
    std::is_constructible<error_type, Args...>::value, //
    error_type, //
    std::conditional_t< //
    std::is_constructible<exception_type, Args...>::value, //
    exception_type, //
    disable_inplace_value_error_exception_constructor>>>>;
    template <class... Args>
    static constexpr bool enable_inplace_value_error_exception_constructor = //
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

  template <class Base, class R, class S, class P, class NoValuePolicy> using select_outcome_observers_payload_or_exception = std::conditional_t<trait::is_exception_ptr<P>::value, impl::outcome_exception_observers<Base, R, S, P, NoValuePolicy>, impl::outcome_payload_observers<Base, R, S, P, NoValuePolicy>>;
  template <class R, class S, class P, class NoValuePolicy> using select_outcome_impl2 = select_outcome_observers_payload_or_exception<impl::result_final<R, S, NoValuePolicy>, R, S, P, NoValuePolicy>;
  template <class R, class S, class P, class NoValuePolicy>
  using select_outcome_impl = std::conditional_t<std::is_base_of<std::error_code, S>::value && trait::is_exception_ptr<P>::value, impl::outcome_failure_observers<select_outcome_impl2<R, S, P, NoValuePolicy>, R, S, P, NoValuePolicy>, select_outcome_impl2<R, S, P, NoValuePolicy>>;
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

/*! Used to return from functions (i) a value and (a positive status and/or a payload) or
(ii) no value and (a negative status and/or a payload). `constexpr` capable.
\module outcome<R, S, P> implementation
\tparam R The optional type of the successful result (use `void` to disable).
\tparam S The optional type of the status result (use `void` to disable). Must be either `void` or DefaultConstructible.
\tparam P The optional type of the payload/exception result (use `void` to disable). Must be either `void` or DefaultConstructible.
\tparam NoValuePolicy Policy on how to interpret types `S` and `P` when a wide observation of a not present value occurs.
*/







template <class R, class S, class P, class NoValuePolicy> //
OUTCOME_REQUIRES(std::is_void<P>::value || std::is_default_constructible<P>::value) //
class OUTCOME_NODISCARD outcome : public detail::select_outcome_impl<R, S, P, NoValuePolicy>
{
  static_assert(std::is_void<P>::value || std::is_default_constructible<P>::value, "payload_type/exception_type must be default constructible");
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
    using base = detail::outcome_predicates<value_type, status_error_type, error_type, payload_exception_type, payload_type, exception_type>;

    //! Predicate for the value converting constructor to be available.
    template <class T>
    static constexpr bool enable_value_converting_constructor = //
    !std::is_same<std::decay_t<T>, outcome>::value // not my type
    && base::template enable_value_converting_constructor<T>;

    //! Predicate for the error converting constructor to be available.
    template <class T>
    static constexpr bool enable_error_converting_constructor = //
    !std::is_same<std::decay_t<T>, outcome>::value // not my type
    && base::template enable_error_converting_constructor<T>;

    // Predicate for the error + payload/exception constructor to be available.
    template <class T, class U>
    static constexpr bool enable_error_payload_converting_constructor = //
    !std::is_same<std::decay_t<T>, outcome>::value // not my type
    && base::template enable_error_payload_converting_constructor<T, U>;

    //! Predicate for the error condition converting constructor to be available.
    template <class ErrorCondEnum>
    static constexpr bool enable_error_condition_converting_constructor = //
    !std::is_same<std::decay_t<ErrorCondEnum>, outcome>::value // not my type
    && base::template enable_error_condition_converting_constructor<ErrorCondEnum>;

    // Predicate for the exception converting constructor to be available.
    template <class T>
    static constexpr bool enable_exception_converting_constructor = //
    !std::is_same<std::decay_t<T>, outcome>::value // not my type
    && base::template enable_exception_converting_constructor<T>;

    //! Predicate for the converting constructor from a compatible input to be available.
    template <class T, class U, class V, class W>
    static constexpr bool enable_compatible_conversion = //
    !std::is_same<outcome<T, U, V, W>, outcome>::value // not my type
    && base::template enable_compatible_conversion<T, U, V, W>;

    //! Predicate for the inplace construction of value to be available.
    template <class... Args>
    static constexpr bool enable_inplace_value_constructor = //
    std::is_void<value_type>::value //
    || std::is_constructible<value_type, Args...>::value;

    //! Predicate for the inplace construction of error to be available.
    template <class... Args>
    static constexpr bool enable_inplace_error_constructor = //
    std::is_void<error_type>::value //
    || std::is_constructible<error_type, Args...>::value;

    //! Predicate for the inplace construction of exception to be available.
    template <class... Args>
    static constexpr bool enable_inplace_exception_constructor = //
    std::is_void<exception_type>::value //
    || std::is_constructible<exception_type, Args...>::value;

    // Predicate for the implicit converting inplace constructor to be available.
    template <class... Args>
    static constexpr bool enable_inplace_value_error_exception_constructor = //
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
  \requires Type T is constructible to `value_type`, is not constructible to `status_error_type`, is not constructible to `exception_type` and is not `outcome<R, S, P>` and not `in_place_type<>`.
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
#if OUTCOME_ENABLE_POSITIVE_STATUS
  /*! Converting constructor to a successful outcome + status.
\tparam enable_value_status_converting_constructor
\exclude
\param 2
\exclude
\param t The value from which to initialise the `value_type`.
\param u The value from which to initialise the `status_type`.

\effects Initialises the outcome with a `value_type` and an additional `status_type`.
\requires `trait::status_type_is_negative<EC>` must be false; Type `T` is constructible to `value_type`,
is not constructible to `exception_type`, and is not `outcome<R, S, P>` and not `in_place_type<>`;
Type `U` is constructible to `status_type`, is not constructible to `value_type`, and is not constructible to `exception_type`.
\throws Any exception the construction of `value_type(T)` and `status_type(U)` might throw.
*/













  template <class T, class U, typename enable_value_status_converting_constructor = std::enable_if_t< //
                              !std::is_same<std::decay_t<T>, outcome>::value // not my type
                              && !detail::is_in_place_type_t<std::decay_t<T>>::value // not in place construction
                              && detail::is_same_or_constructible<value_type, T> && !std::is_constructible<exception_type, T>::value //
                              && detail::is_same_or_constructible<status_type, U> && !std::is_constructible<exception_type, U>::value>>
  constexpr outcome(T &&t, U &&u, value_status_converting_constructor_tag = value_status_converting_constructor_tag()) noexcept(std::is_nothrow_constructible<value_type, T>::value &&std::is_nothrow_constructible<status_type, U>::value)
      : base{typename base::value_status_construction_tag(), std::forward<T>(t), std::forward<U>(u)}
      , _ptr()
  {
    using namespace hooks;
    hook_outcome_construction(in_place_type<std::pair<value_type, status_type>>, this);
  }
  /*! Converting constructor to a successful outcome + status + payload.
  \tparam enable_value_status_payload_converting_constructor
  \exclude
  \param 3
  \exclude
  \param t The value from which to initialise the `value_type`.
  \param u The value from which to initialise the `status_type`.
  \param v The value from which to initialise the `payload_type`.

  \effects Initialises the outcome with a `value_type`, a `status_type` and a `payload_type`.
  \requires `trait::status_type_is_negative<EC>` must be false; Type `T` is constructible to `value_type`, and is not `outcome<R, S, P>`
  and not `in_place_type<>`;
  Type `U` is constructible to `status_type`;
  Type `V` is constructible to `payload_exception_type`.
  \throws Any exception the construction of `value_type(T)`, `status_type(U)` and `payload_exception_type(V)` might throw.
  */















  template <class T, class U, class V, typename enable_value_status_payload_converting_constructor = std::enable_if_t< //
                                       !std::is_same<std::decay_t<T>, outcome>::value // not my type
                                       && !detail::is_in_place_type_t<std::decay_t<T>>::value // not in place construction
                                       && detail::is_same_or_constructible<value_type, T> //
                                       && detail::is_same_or_constructible<status_type, U> //
                                       && detail::is_same_or_constructible<payload_exception_type, V> //
                                       >>
  constexpr outcome(T &&t, U &&u, V &&v,
                    value_status_payload_converting_constructor_tag = value_status_payload_converting_constructor_tag()) noexcept(std::is_nothrow_constructible<value_type, T>::value &&std::is_nothrow_constructible<status_type, U>::value &&std::is_nothrow_constructible<payload_exception_type, V>::value)
      : base{typename base::value_status_construction_tag(), std::forward<T>(t), std::forward<U>(u)}
      , _ptr(std::forward<V>(v))
  {
    using namespace hooks;
    this->_state._status |= detail::status_have_payload;
    hook_outcome_construction(in_place_type<std::tuple<value_type, status_type, payload_type>>, this);
  }
  /*! Converting constructor to a successful outcome + payload.
  \tparam enable_value_payload_converting_constructor_tag
  \exclude
  \param 2
  \exclude
  \param t The value from which to initialise the `value_type`.
  \param u The value from which to initialise the `payload_type`.

  \effects Initialises the outcome with a `value_type` and a `payload_type`.
  \requires `trait::is_exception_ptr<P>` must be false; Type `T` is constructible to `value_type`, is not constructible to `status_error_type`,
  and is not `outcome<R, S, P>` and not `in_place_type<>`;
  Type `U` is constructible to `payload_type`, and is not constructible to `status_error_type`.
  \throws Any exception the construction of `value_type(T)` and `payload_type(U)` might throw.
  */













  template <class T, class U, typename enable_value_payload_converting_constructor_tag = std::enable_if_t< //
                              !std::is_same<std::decay_t<T>, outcome>::value // not my type
                              && !detail::is_in_place_type_t<std::decay_t<T>>::value // not in place construction
                              && detail::is_same_or_constructible<value_type, T> && !std::is_constructible<status_error_type, T>::value //
                              && detail::is_same_or_constructible<payload_type, U> && !std::is_constructible<status_error_type, U>::value>>
  constexpr outcome(T &&t, U &&u, value_payload_converting_constructor_tag = value_payload_converting_constructor_tag()) noexcept(std::is_nothrow_constructible<value_type, T>::value &&std::is_nothrow_constructible<payload_exception_type, U>::value)
      : base{in_place_type<typename base::value_type>, std::forward<T>(t)}
      , _ptr(std::forward<U>(u))
  {
    using namespace hooks;
    hook_outcome_construction(in_place_type<std::pair<value_type, payload_type>>, this);
  }
#endif
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
  \requires `trait::status_type_is_negative<EC>` must be true; Type T is constructible to `error_type`,
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
  \requires `trait::status_type_is_negative<EC>` must be true; `std::is_error_condition_enum<ErrorCondEnum>` must be true,
  `ErrorCondEnum` is not constructible to `value_type`, `error_type` nor `payload_exception_type`, and is not `outcome<R, S, P>` and not `in_place_type<>`;
  Finally, the expression `error_type(make_error_code(ErrorCondEnum()))` must be valid.
  \throws Any exception the construction of `error_type(make_error_code(t))` might throw.
  */












  OUTCOME_TEMPLATE(class ErrorCondEnum)
  OUTCOME_TREQUIRES(OUTCOME_TEXPR(error_type(make_error_code(ErrorCondEnum()))), //
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
  is not constructible to `value_type`, is not constructible to `status_error_type`, and is not `outcome<R, S, P>` and not `in_place_type<>`.
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
  \requires Both outcome's `value_type`, `error_type`, `status_type`, `payload_type` and `exception_type` need to be constructible, or the source `void`.
  \throws Any exception the construction of `value_type(T)`, `status_error_type(U)` or `payload_exception_type(V)` might throw.
  */








  OUTCOME_TEMPLATE(class T, class U, class V, class W)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_compatible_conversion<T, U, V, W>))
  constexpr explicit outcome(const outcome<T, U, V, W> &o) noexcept(std::is_nothrow_constructible<value_type, T>::value &&std::is_nothrow_constructible<status_error_type, U>::value &&std::is_nothrow_constructible<payload_exception_type, V>::value)
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
  \requires Both outcome's `value_type`, `error_type`, `status_type`, `payload_type` and `exception_type` need to be constructible, or the source `void`.
  \throws Any exception the construction of `value_type(T)`, `status_error_type(U)` or `payload_exception_type(V)` might throw.
  */








  OUTCOME_TEMPLATE(class T, class U, class V, class W)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_compatible_conversion<T, U, V, W>))
  constexpr explicit outcome(outcome<T, U, V, W> &&o) noexcept(std::is_nothrow_constructible<value_type, T>::value &&std::is_nothrow_constructible<status_error_type, U>::value &&std::is_nothrow_constructible<payload_exception_type, V>::value)
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
  \requires Both outcome's `value_type`, `error_type` and `status_type` need to be constructible, or the source `void`.
  \throws Any exception the construction of `value_type(T)`, `status_error_type(U)` or `payload_exception_type()` might throw.
  */








  OUTCOME_TEMPLATE(class T, class U, class V)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(detail::result_predicates<value_type, status_error_type, error_type>::template enable_compatible_conversion<T, U, V>))
  constexpr explicit outcome(const result<T, U, V> &o) noexcept(std::is_nothrow_constructible<value_type, T>::value &&std::is_nothrow_constructible<status_error_type, U>::value &&std::is_nothrow_constructible<payload_exception_type>::value)
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
  \requires Both outcome's `value_type`, `error_type` and `status_type` need to be constructible, or the source `void`.
  \throws Any exception the construction of `value_type(T)`, `status_error_type(U)` or `payload_exception_type()` might throw.
  */








  OUTCOME_TEMPLATE(class T, class U, class V)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(detail::result_predicates<value_type, status_error_type, error_type>::template enable_compatible_conversion<T, U, V>))
  constexpr explicit outcome(result<T, U, V> &&o) noexcept(std::is_nothrow_constructible<value_type, T>::value &&std::is_nothrow_constructible<status_error_type, U>::value &&std::is_nothrow_constructible<payload_exception_type>::value)
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
  \requires `trait::status_type_is_negative<EC>` must be true; `error_type` is void or `Args...` are constructible to `error_type`.
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
  \requires `trait::status_type_is_negative<EC>` must be true; The initializer list + `Args...` are constructible to `error_type`.
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
  constexpr bool operator==(const outcome<T, U, V, W> &o) const noexcept( //
  noexcept(detail::safe_compare_equal(std::declval<detail::devoid<R>>(), std::declval<detail::devoid<T>>())) //
  && noexcept(detail::safe_compare_equal(std::declval<detail::devoid<S>>(), std::declval<detail::devoid<U>>())) //
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
  constexpr bool operator==(const failure_type<T, U, false> &o) const noexcept( //
  noexcept(detail::safe_compare_equal(std::declval<detail::devoid<S>>(), std::declval<detail::devoid<T>>())) //
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
  constexpr bool operator==(const failure_type<T, U, true> &o) const noexcept( //
  noexcept(detail::safe_compare_equal(std::declval<detail::devoid<S>>(), std::declval<detail::devoid<T>>())) //
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
  constexpr bool operator!=(const outcome<T, U, V, W> &o) const noexcept( //
  noexcept(detail::safe_compare_notequal(std::declval<detail::devoid<R>>(), std::declval<detail::devoid<T>>())) //
  && noexcept(detail::safe_compare_notequal(std::declval<detail::devoid<S>>(), std::declval<detail::devoid<U>>())) //
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
  constexpr bool operator!=(const failure_type<T, U, false> &o) const noexcept( //
  noexcept(detail::safe_compare_notequal(std::declval<detail::devoid<S>>(), std::declval<detail::devoid<T>>())) //
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
  constexpr bool operator!=(const failure_type<T, U, true> &o) const noexcept( //
  noexcept(detail::safe_compare_notequal(std::declval<detail::devoid<S>>(), std::declval<detail::devoid<T>>())) //
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


  void swap(outcome &o) noexcept(detail::is_nothrow_swappable<value_type>::value //
                                 &&detail::is_nothrow_swappable<status_error_type>::value //
                                 &&detail::is_nothrow_swappable<payload_exception_type>::value)
  {
    using std::swap;
#ifdef __cpp_exceptions
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4297) // use of throw in noexcept function
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









OUTCOME_TEMPLATE(class T, class U, class V, //
                 class R, class S, class P, class N)
OUTCOME_TREQUIRES(OUTCOME_TEXPR(std::declval<outcome<R, S, P, N>>() == std::declval<result<T, U, V>>()))
constexpr inline bool operator==(const result<T, U, V> &a, const outcome<R, S, P, N> &b) noexcept( //
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









OUTCOME_TEMPLATE(class T, class U, class V, //
                 class R, class S, class P, class N)
OUTCOME_TREQUIRES(OUTCOME_TEXPR(std::declval<outcome<R, S, P, N>>() != std::declval<result<T, U, V>>()))
constexpr inline bool operator!=(const result<T, U, V> &a, const outcome<R, S, P, N> &b) noexcept( //
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
    static_assert(std::is_base_of<std::error_code, S>::value, "error_type must be a base of std::error_code to be used with this policy");
    static_assert(std::is_base_of<std::exception_ptr, P>::value, "exception_type must be a base of std::exception_ptr to be used with this policy");
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
    /*! Performs a narrow check of state, used in the assume_payload() functions.
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
    /*! Performs a narrow check of state, used in the assume_exception() functions.
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
#include <iostream>
#include <sstream>

OUTCOME_V2_NAMESPACE_BEGIN

namespace detail
{
  template <class T> inline std::ostream &operator<<(std::ostream &s, const value_storage_trivial<T> &v)
  {
    s << v._status << " ";
    if((v._status & status_have_value) != 0)
    {
      s << v._value;
    }
    return s;
  }
  inline std::ostream &operator<<(std::ostream &s, const value_storage_trivial<void> &v)
  {
    s << v._status << " ";
    return s;
  }
  template <class T> inline std::ostream &operator<<(std::ostream &s, const value_storage_nontrivial<T> &v)
  {
    s << v._status << " ";
    if((v._status & status_have_value) != 0)
    {
      s << v._value;
    }
    return s;
  }
  template <class T> inline std::istream &operator>>(std::istream &s, value_storage_trivial<T> &v)
  {
    v = value_storage_trivial<T>();
    s >> v._status;
    if((v._status & status_have_value) != 0)
    {
      new(&v._value) decltype(v._value)();
      s >> v._value;
    }
    return s;
  }
  inline std::istream &operator>>(std::istream &s, value_storage_trivial<devoid<void>> &v)
  {
    v = value_storage_trivial<devoid<void>>();
    s >> v._status;
    return s;
  }
  template <class T> inline std::istream &operator>>(std::istream &s, value_storage_nontrivial<T> &v)
  {
    v = value_storage_nontrivial<T>();
    s >> v._status;
    if((v._status & status_have_value) != 0)
    {
      new(&v._value) decltype(v._value)();
      s >> v._value;
    }
    return s;
  }
  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(!std::is_constructible<std::error_code, T>::value))
  inline std::string safe_message(T && /*unused*/) { return {}; }
  inline std::string safe_message(const std::error_code &ec) { return " (" + ec.message() + ")"; }
  template <bool is_exception> struct print_payload_exception
  {
    template <class R, class S, class P, class N> print_payload_exception(std::ostream &s, const outcome<R, S, P, N> &v)
    {
      if(v.has_payload())
      {
        s << v.payload();
      }
    }
  };
  template <> struct print_payload_exception<true>
  {
    template <class R, class S, class P, class N> print_payload_exception(std::ostream &s, const outcome<R, S, P, N> &v)
    {
      if(v.has_exception())
      {
#ifdef __cpp_exceptions
        try
        {
          std::rethrow_exception(v.exception());
        }
        catch(const std::system_error &e)
        {
          s << "std::system_error code " << e.code() << ": " << e.what();
        }
        catch(const std::exception &e)
        {
          s << "std::exception: " << e.what();
        }
        catch(...)
#endif
        {
          s << "unknown exception";
        }
      }
    }
  };
}

//! Deserialise a result
template <class R, class S, class P> inline std::istream &operator>>(std::istream &s, result<R, S, P> &v)
{
  s >> v._state;
  if(v.has_error())
  {
    s >> v._error;
  }
  return s;
}
//! Serialise a result
template <class R, class S, class P> inline std::ostream &operator<<(std::ostream &s, const result<R, S, P> &v)
{
  s << v._state;
  if(v.has_error())
  {
    s << v._error;
  }
  return s;
}
//! Debug print a result
template <class R, class S, class P> inline std::string print(const impl::result_final<R, S, P> &v)
{
  std::stringstream s;
  if(v.has_value())
  {
    s << v.value();
  }
  if(v.has_error())
  {
    s << v.error() << detail::safe_message(v.error());
  }
  return s.str();
}
//! Debug print a result
template <class S, class P> inline std::string print(const impl::result_final<void, S, P> &v)
{
  std::stringstream s;
  if(v.has_value())
  {
    s << "(+void)";
  }
  if(v.has_error())
  {
    s << v.error() << detail::safe_message(v.error());
  }
  return s.str();
}
//! Debug print a result
template <class R, class P> inline std::string print(const impl::result_final<R, void, P> &v)
{
  std::stringstream s;
  if(v.has_value())
  {
    s << v.value();
  }
  if(v.has_error())
  {
    s << "(-void)";
  }
  return s.str();
}
//! Debug print a result
template <class P> inline std::string print(const impl::result_final<void, void, P> &v)
{
  std::stringstream s;
  if(v.has_value())
  {
    s << "(+void)";
  }
  if(v.has_error())
  {
    s << "(-void)";
  }
  return s.str();
}

//! Deserialise an outcome
template <class R, class S, class P, class N> inline std::istream &operator>>(std::istream &s, outcome<R, S, P, N> &v)
{
  static_assert(!trait::is_exception_ptr<P>::value, "Cannot call operator>> on an outcome with an exception_ptr in it");
  s >> v._state;
  if(v.has_error())
  {
    s >> v._error;
  }
  if(v.has_payload())
  {
    s >> v._ptr;
  }
  return s;
}
//! Serialise an outcome
template <class R, class S, class P, class N> inline std::ostream &operator<<(std::ostream &s, const outcome<R, S, P, N> &v)
{
  static_assert(!trait::is_exception_ptr<P>::value, "Cannot call operator<< on an outcome with an exception_ptr in it");
  s << v._state;
  if(v.has_error())
  {
    s << v._error;
  }
  if(v.has_payload())
  {
    s << v._ptr;
  }
  return s;
}
//! Debug print an outcome
template <class R, class S, class P, class N> inline std::string print(const outcome<R, S, P, N> &v)
{
  std::stringstream s;
  int total = static_cast<int>(v.has_value()) + static_cast<int>(v.has_error()) + static_cast<int>(v.has_payload()) + static_cast<int>(v.has_exception());
  if(total > 1)
  {
    s << "{ ";
  }
  s << print(static_cast<const impl::result_final<R, S, N> &>(v));
  if(total > 1)
  {
    s << ", ";
  }
  detail::print_payload_exception<trait::is_exception_ptr<P>::value>(s, v);
  if(total > 1)
  {
    s << " }";
  }
  return s.str();
}
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



OUTCOME_V2_NAMESPACE_BEGIN

/*! Customisation point for changing what the `OUTCOME_TRY` macros
do. This function defaults to returning `std::forward<T>(v).as_failure()`.
\effects Extracts any state apart from value into a `failure_type`.
\requires The input value to have a `.as_failure()` member function.
*/




template <class T> OUTCOME_REQUIRES(requires(T &&v){{v.as_failure()}}) decltype(auto) try_operation_return_as(T &&v)
{
  return std::forward<T>(v).as_failure();
}

OUTCOME_V2_NAMESPACE_END

#define OUTCOME_TRY_GLUE2(x, y) x##y
#define OUTCOME_TRY_GLUE(x, y) OUTCOME_TRY_GLUE2(x, y)
#define OUTCOME_TRY_UNIQUE_NAME OUTCOME_TRY_GLUE(__t, __COUNTER__)

#define OUTCOME_TRYV2(unique, m) auto &&unique = (m); if(!unique.has_value()) return OUTCOME_V2_NAMESPACE::try_operation_return_as(std::forward<decltype(unique)>(unique))



#define OUTCOME_TRY2(unique, v, m) OUTCOME_TRYV2(unique, m); auto &&v = std::forward<decltype(unique)>(unique).value()



/*! If the outcome returned by expression *m* is not valued, propagate any
failure by immediately returning that failure state immediately
*/


#define OUTCOME_TRYV(m) OUTCOME_TRYV2(OUTCOME_TRY_UNIQUE_NAME, m)

#if defined(__GNUC__) || defined(__clang__)

/*! If the outcome returned by expression *m* is not valued, propagate any
failure by immediately returning that failure state immediately, else become the
unwrapped value as an expression. This makes `OUTCOME_TRYX(expr)` an expression
which can be used exactly like the `try` operator in other languages.

\note This macro makes use of a proprietary extension in GCC and clang and is not
portable. The macro is not made available on unsupported compilers,
so you can test for its presence using `#ifdef OUTCOME_TRYX`.
*/








#define OUTCOME_TRYX(m) ({ auto &&res = (m); if(!res.has_value()) return OUTCOME_V2_NAMESPACE::try_operation_return_as(std::forward<decltype(res)>(res)); std::forward<decltype(res)>(res).value(); })







#endif

/*! If the outcome returned by expression *m* is not valued, propagate any
failure by immediately returning that failure immediately, else set *v* to the unwrapped value.
*/


#define OUTCOME_TRY(v, m) OUTCOME_TRY2(OUTCOME_TRY_UNIQUE_NAME, v, m)

#endif
/* Tries to convert an exception ptr into its equivalent error code
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























#ifndef OUTCOME_ERROR_FROM_EXCEPTION_HPP
#define OUTCOME_ERROR_FROM_EXCEPTION_HPP



#include <exception>
#include <system_error>

OUTCOME_V2_NAMESPACE_BEGIN

/*! Utility function which tries to match the exception in the pointer provided
to an equivalent error code. Ought to work for all standard STL types.
\param ep The pointer to an exception to convert. If matched, on exit this is
reset to a null pointer.
\param not_matched The error code to return if we could not match the exception.
Note that a null pointer in returns a null error code.

\effects Rethrows the exception in the pointer, and via a long sequence of `catch`
clauses attempts to match the equivalent error code. If a match is found, the
pointer is reset to null. If a match is not found, *not_matched* is returned instead
and the pointer is left unmodified.
*/











inline std::error_code error_from_exception(std::exception_ptr &&ep = std::current_exception(), std::error_code not_matched = std::make_error_code(std::errc::resource_unavailable_try_again)) noexcept
{
  if(!ep)
  {
    return {};
  }
  try
  {
    std::rethrow_exception(ep);
  }
  catch(const std::invalid_argument & /*unused*/)
  {
    ep = std::exception_ptr();
    return std::make_error_code(std::errc::invalid_argument);
  }
  catch(const std::domain_error & /*unused*/)
  {
    ep = std::exception_ptr();
    return std::make_error_code(std::errc::argument_out_of_domain);
  }
  catch(const std::length_error & /*unused*/)
  {
    ep = std::exception_ptr();
    return std::make_error_code(std::errc::argument_list_too_long);
  }
  catch(const std::out_of_range & /*unused*/)
  {
    ep = std::exception_ptr();
    return std::make_error_code(std::errc::result_out_of_range);
  }
  catch(const std::logic_error & /*unused*/) /* base class for this group */
  {
    ep = std::exception_ptr();
    return std::make_error_code(std::errc::invalid_argument);
  }
  catch(const std::system_error &e) /* also catches ios::failure */
  {
    ep = std::exception_ptr();
    return e.code();
  }
  catch(const std::overflow_error & /*unused*/)
  {
    ep = std::exception_ptr();
    return std::make_error_code(std::errc::value_too_large);
  }
  catch(const std::range_error & /*unused*/)
  {
    ep = std::exception_ptr();
    return std::make_error_code(std::errc::result_out_of_range);
  }
  catch(const std::runtime_error & /*unused*/) /* base class for this group */
  {
    ep = std::exception_ptr();
    return std::make_error_code(std::errc::resource_unavailable_try_again);
  }
  catch(const std::bad_alloc & /*unused*/)
  {
    ep = std::exception_ptr();
    return std::make_error_code(std::errc::not_enough_memory);
  }
  catch(...)
  {
  }
  return not_matched;
}

OUTCOME_V2_NAMESPACE_END

#endif
