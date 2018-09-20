/* Include the default amount of outcome
(C) 2018 Niall Douglas <http://www.nedproductions.biz/> (59 commits)
File Created: Mar 2018


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























#ifndef OUTCOME_STD_RESULT_HPP
#define OUTCOME_STD_RESULT_HPP
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
#ifndef QUICKCPPLIB_DISABLE_ABI_PERMUTATION
// Note the second line of this file must ALWAYS be the git SHA, third line ALWAYS the git SHA update time
#define QUICKCPPLIB_PREVIOUS_COMMIT_REF 74be03b78dc003b66252545b05a788a565946d33
#define QUICKCPPLIB_PREVIOUS_COMMIT_DATE "2018-07-03 08:34:47 +00:00"
#define QUICKCPPLIB_PREVIOUS_COMMIT_UNIQUE 74be03b7
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
#if defined(OUTCOME_UNSTABLE_VERSION)
// Note the second line of this file must ALWAYS be the git SHA, third line ALWAYS the git SHA update time
#define OUTCOME_PREVIOUS_COMMIT_REF 97cad4a622e2c0720c06345c5e6b458130c76d2d
#define OUTCOME_PREVIOUS_COMMIT_DATE "2018-09-14 17:09:24 +00:00"
#define OUTCOME_PREVIOUS_COMMIT_UNIQUE 97cad4a6
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


#include <cstdint> // for uint32_t etc
#include <initializer_list>
#include <iosfwd> // for future serialisation
#include <new> // for placement in moves etc
#include <type_traits>

#if __cplusplus >= 201700 || (defined(_MSC_VER) && _HAS_CXX17)
#include <utility> // for in_place_type_t

OUTCOME_V2_NAMESPACE_BEGIN
template <class T> using in_place_type_t = std::in_place_type_t<T>;
using std::in_place_type;
OUTCOME_V2_NAMESPACE_END
#else
OUTCOME_V2_NAMESPACE_BEGIN
//! Aliases `std::in_place_type_t<T>` if on C++ 17 or later, else defined locally.
template <class T> struct in_place_type_t
{
  explicit in_place_type_t() = default;
};
//! Aliases `std::in_place_type<T>` if on C++ 17 or later, else defined locally.
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
  using rebind_type4 = std::conditional_t< //
  std::is_volatile<Input>::value, //
  std::add_volatile_t<rebind_type5<Output, std::remove_volatile_t<Input>>>, //
  rebind_type5<Output, Input>>;
  template <class Output, class Input>
  using rebind_type3 = std::conditional_t< //
  std::is_const<Input>::value, //
  std::add_const_t<rebind_type4<Output, std::remove_const_t<Input>>>, //
  rebind_type4<Output, Input>>;
  template <class Output, class Input>
  using rebind_type2 = std::conditional_t< //
  std::is_lvalue_reference<Input>::value, //
  std::add_lvalue_reference_t<rebind_type3<Output, std::remove_reference_t<Input>>>, //
  rebind_type3<Output, Input>>;
  template <class Output, class Input>
  using rebind_type = std::conditional_t< //
  std::is_rvalue_reference<Input>::value, //
  std::add_rvalue_reference_t<rebind_type2<Output, std::remove_reference_t<Input>>>, //
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

// True if type is nothrow swappable
#if !0 && (_HAS_CXX17 || __cplusplus >= 201700)
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
  } // namespace _is_nothrow_swappable
  template <class T> using is_nothrow_swappable = _is_nothrow_swappable::is_nothrow_swappable<T>;
#endif
} // namespace detail
OUTCOME_V2_NAMESPACE_END


#ifndef OUTCOME_THROW_EXCEPTION
#ifdef __cpp_exceptions
#define OUTCOME_THROW_EXCEPTION(expr) throw expr
#else

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
#elif !defined(__ANDROID__)
#include <execinfo.h>
#endif
#include <cstdio>
#include <cstdlib>
OUTCOME_V2_NAMESPACE_BEGIN
namespace detail
{
  QUICKCPPLIB_NORETURN inline void do_fatal_exit(const char *expr)
  {
#if !defined(__ANDROID__)
    void *bt[16];
    size_t btlen = backtrace(bt, sizeof(bt) / sizeof(bt[0])); // NOLINT
#endif
    fprintf(stderr, "FATAL: Outcome throws exception %s with exceptions disabled\n", expr); // NOLINT
#if !defined(__ANDROID__)
    char **bts = backtrace_symbols(bt, btlen); // NOLINT
    if(bts != nullptr)
    {
      for(size_t n = 0; n < btlen; n++)
      {
        fprintf(stderr, "  %s\n", bts[n]); // NOLINT
      }
      free(bts); // NOLINT
    }
#endif
    abort();
  }
} // namespace detail
OUTCOME_V2_NAMESPACE_END
#define OUTCOME_THROW_EXCEPTION(expr) OUTCOME_V2_NAMESPACE::detail::do_fatal_exit(#expr)

#endif
#endif

#ifndef BOOST_OUTCOME_AUTO_TEST_CASE
#define BOOST_OUTCOME_AUTO_TEST_CASE(a, b) BOOST_AUTO_TEST_CASE(a, b)
#endif

#endif
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

/*! Type sugar for implicitly constructing a `basic_result<>` with a successful state.
*/

template <class T> struct success_type
{
  //! The type of the successful state.
  using value_type = T;

private:
  //! The value of the successful state.
  value_type _value;

public:
  /// \output_section Default, copy/move constructors and assignment
  //! Default constructor
  success_type() = default;
  //! Copy constructor
  success_type(const success_type &) = default;
  //! Move constructor
  success_type(success_type &&) = default; // NOLINT
  //! Copy assignment
  success_type &operator=(const success_type &) = default;
  //! Move assignment
  success_type &operator=(success_type &&) = default; // NOLINT
  //! Destructor
  ~success_type() = default;
  /*! Initialising constructor

  \requires That `U` is not `success_type`.
  */



  OUTCOME_TEMPLATE(class U)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(!std::is_same<success_type, std::decay_t<U>>::value))
  constexpr explicit success_type(U &&v)
      : _value(static_cast<U &&>(v))
  {
  }

  /// \output_section Observers
  /*! Access value.
  \returns Reference to the held `value_type` according to overload.
  \group success_type_value
  */



  constexpr value_type &value() & { return _value; }
  /// \group success_type_value
  constexpr const value_type &value() const & { return _value; }
  /// \group success_type_value
  constexpr value_type &&value() && { return static_cast<value_type &&>(_value); }
  /// \group success_type_value
  constexpr const value_type &&value() const && { return static_cast<value_type &&>(_value); }
};
/*! Type sugar for implicitly constructing a `basic_result<>` with a successful state.
*/

template <> struct success_type<void>
{
  //! The type of the successful state.
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

/*! Type sugar for implicitly constructing a `basic_result<>` with a failure state of error code and exception.
*/

template <class EC, class E = void> struct failure_type
{
  //! The type of the error code
  using error_type = EC;
  //! The type of the exception
  using exception_type = E;

private:
  bool _have_error, _have_exception;
  //! The error code
  error_type _error;
  //! The exception
  exception_type _exception;

  struct error_init_tag
  {
  };
  struct exception_init_tag
  {
  };

public:
  /// \output_section Default, copy/move constructors and assignment
  //! Default constructor
  failure_type() = default;
  //! Copy constructor
  failure_type(const failure_type &) = default;
  //! Move constructor
  failure_type(failure_type &&) = default; // NOLINT
  //! Copy assignment
  failure_type &operator=(const failure_type &) = default;
  //! Move assignment
  failure_type &operator=(failure_type &&) = default; // NOLINT
  //! Destructor
  ~failure_type() = default;
  //! Initialising constructor
  template <class U, class V>
  constexpr explicit failure_type(U &&u, V &&v)
      : _have_error(true)
      , _have_exception(true)
      , _error(static_cast<U &&>(u))
      , _exception(static_cast<V &&>(v))
  {
  }
  /*! Initialising constructor for `error_type` only.
  */

  template <class U>
  constexpr explicit failure_type(in_place_type_t<error_type> /*unused*/, U &&u, error_init_tag /*unused*/ = error_init_tag())
      : _have_error(true)
      , _have_exception(false)
      , _error(static_cast<U &&>(u))
      , _exception()
  {
  }
  /*! Initialising constructor for `exception_type` only.
  */

  template <class U>
  constexpr explicit failure_type(in_place_type_t<exception_type> /*unused*/, U &&u, exception_init_tag /*unused*/ = exception_init_tag())
      : _have_error(false)
      , _have_exception(true)
      , _error()
      , _exception(static_cast<U &&>(u))
  {
  }

  /// \output_section Observers
  //! True if has error
  constexpr bool has_error() const { return _have_error; }
  //! True if has exception
  constexpr bool has_exception() const { return _have_exception; }

  /*! Access error.
  \returns Reference to the held `error_type` according to overload.
  \group failure_type_error
  */



  constexpr error_type &error() & { return _error; }
  /// \group failure_type_error
  constexpr const error_type &error() const & { return _error; }
  /// \group failure_type_error
  constexpr error_type &&error() && { return static_cast<error_type &&>(_error); }
  /// \group failure_type_error
  constexpr const error_type &&error() const && { return static_cast<error_type &&>(_error); }

  /*! Access exception.
  \returns Reference to the held `exception_type` according to overload.
  \group failure_type_exception
  */



  constexpr exception_type &exception() & { return _exception; }
  /// \group failure_type_exception
  constexpr const exception_type &exception() const & { return _exception; }
  /// \group failure_type_exception
  constexpr exception_type &&exception() && { return static_cast<exception_type &&>(_exception); }
  /// \group failure_type_exception
  constexpr const exception_type &&exception() const && { return static_cast<exception_type &&>(_exception); }
};
/*! Type sugar for implicitly constructing a `basic_result<>` with a failure state of error code.
*/

template <class EC> struct failure_type<EC, void>
{
  //! The type of the error code
  using error_type = EC;
  //! The type of the exception
  using exception_type = void;

private:
  //! The error code
  error_type _error;

public:
  /// \output_section Default, copy/move constructors and assignment
  //! Default constructor
  failure_type() = default;
  //! Copy constructor
  failure_type(const failure_type &) = default;
  //! Move constructor
  failure_type(failure_type &&) = default; // NOLINT
  //! Copy assignment
  failure_type &operator=(const failure_type &) = default;
  //! Move assignment
  failure_type &operator=(failure_type &&) = default; // NOLINT
  //! Destructor
  ~failure_type() = default;
  /*! Initialising constructor

  \requires That `U` is not `failure_type`.
  */



  OUTCOME_TEMPLATE(class U)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(!std::is_same<failure_type, std::decay_t<U>>::value))
  constexpr explicit failure_type(U &&u)
      : _error(static_cast<U &&>(u))
  {
  }

  /// \output_section Observers
  /*! Access error.
  \returns Reference to the held `error_type` according to overload.
  \group failure_type_error2
  */



  constexpr error_type &error() & { return _error; }
  /// \group failure_type_error2
  constexpr const error_type &error() const & { return _error; }
  /// \group failure_type_error2
  constexpr error_type &&error() && { return static_cast<error_type &&>(_error); }
  /// \group failure_type_error2
  constexpr const error_type &&error() const && { return static_cast<error_type &&>(_error); }
};
/*! Type sugar for implicitly constructing a `basic_result<>` with a failure state of exception.
*/

template <class E> struct failure_type<void, E>
{
  //! The type of the error code
  using error_type = void;
  //! The type of the exception
  using exception_type = E;

private:
  //! The exception
  exception_type _exception;

public:
  /// \output_section Default, copy/move constructors and assignment
  //! Default constructor
  failure_type() = default;
  //! Copy constructor
  failure_type(const failure_type &) = default;
  //! Move constructor
  failure_type(failure_type &&) = default; // NOLINT
  //! Copy assignment
  failure_type &operator=(const failure_type &) = default;
  //! Move assignment
  failure_type &operator=(failure_type &&) = default; // NOLINT
  //! Destructor
  ~failure_type() = default;
  /*! Initialising constructor

  \requires That `V` is not `failure_type`.
  */



  OUTCOME_TEMPLATE(class V)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(!std::is_same<failure_type, std::decay_t<V>>::value))
  constexpr explicit failure_type(V &&v)
      : _exception(static_cast<V &&>(v))
  {
  }

  /// \output_section Observers
  /*! Access exception.
  \returns Reference to the held `exception_type` according to overload.
  \group failure_type_exception2
  */



  constexpr exception_type &exception() & { return _exception; }
  /// \group failure_type_exception2
  constexpr const exception_type &exception() const & { return _exception; }
  /// \group failure_type_exception2
  constexpr exception_type &&exception() && { return static_cast<exception_type &&>(_exception); }
  /// \group failure_type_exception2
  constexpr const exception_type &&exception() const && { return static_cast<exception_type &&>(_exception); }
};
/*! Returns type sugar for implicitly constructing a `basic_result<T>` with a failure state.
\effects Copies or moves the failure state supplied into the returned type sugar.
*/


template <class EC> inline constexpr failure_type<std::decay_t<EC>> failure(EC &&v)
{
  return failure_type<std::decay_t<EC>>{static_cast<EC &&>(v)};
}
/*! Returns type sugar for implicitly constructing a `basic_result<T>` with a failure state.
\effects Copies or moves the failure state supplied into the returned type sugar.
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
} // namespace detail

//! True if the type is a success type
template <class T> static constexpr bool is_success_type = detail::is_success_type<std::decay_t<T>>::value;

//! True if the type is a failure type
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

//! Namespace for traits
namespace trait
{
  /*! Requirements predicate for permitting type to be used in `basic_result`/`basic_outcome`.

  - Is not a reference.
  - Is not an `in_place_type_t<>`.
  - Is not a `success_type<>`.
  - Is not a `failure_type<>`.
  - Is not an array.
  - Is `void`, or else is an Object and is Destructible.
  */








  template <class R> //
  static constexpr bool type_can_be_used_in_basic_result = //
  (!std::is_reference<R>::value //
   && !OUTCOME_V2_NAMESPACE::detail::is_in_place_type_t<std::decay_t<R>>::value //
   && !is_success_type<R> //
   && !is_failure_type<R> //
   && !std::is_array<R>::value //
   && (std::is_void<R>::value || (std::is_object<R>::value //
                                  && std::is_destructible<R>::value)) //
   );

  /*! Trait for whether a type is an error type or not. This is specialised by
  later code to enable implicit conversion for when the value type is `bool` and the
  error type is convertible to `bool`, something which ordinarily would disable
  all implicit constructors.
  */




  template <class E> struct is_error_type
  {
    static constexpr bool value = false;
  };

  /*! Trait for whether a type is an error type enum or not. This is specialised by
  later code to enable implicit conversion from such enum types.
  \tparam E The error type.
  \tparam Enum The enum type.
  */




  template <class E, class Enum> struct is_error_type_enum
  {
    static constexpr bool value = false;
  };

  /*! Trait for whether a free function `make_error_code(T)` returning a `std::error_code` exists or not.
  Also returns true if `std::error_code` is convertible from T.
  */


  template <class T> struct has_error_code;

  /*! Trait for whether a free function `make_exception_ptr(T)` returning a `std::exception_ptr` exists or not.
  Also returns true if `std::exception_ptr` is convertible from T.
  */


  template <class T> struct has_exception_ptr;

} // namespace trait

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
  static constexpr status_bitfield_type status_error_is_errno = (1U << 4U); // can errno be set from this error?
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
    value_storage_trivial(const value_storage_trivial &) = default; // NOLINT
    value_storage_trivial(value_storage_trivial &&) = default; // NOLINT
    value_storage_trivial &operator=(const value_storage_trivial &) = default; // NOLINT
    value_storage_trivial &operator=(value_storage_trivial &&) = default; // NOLINT
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
        : value_storage_trivial(((o._status & status_have_value) != 0) ? value_storage_trivial(in_place_type<value_type>, o._value) : value_storage_trivial()) // NOLINT
    {
      _status = o._status;
    }
    OUTCOME_TEMPLATE(class U)
    OUTCOME_TREQUIRES(OUTCOME_TPRED(enable_converting_constructor<U>))
    constexpr explicit value_storage_trivial(value_storage_trivial<U> &&o) noexcept(std::is_nothrow_constructible<value_type, U>::value)
        : value_storage_trivial(((o._status & status_have_value) != 0) ? value_storage_trivial(in_place_type<value_type>, static_cast<U &&>(o._value)) : value_storage_trivial()) // NOLINT
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
    value_storage_nontrivial &operator=(const value_storage_nontrivial &) = default; // if reaches here, copy assignment is trivial
    value_storage_nontrivial &operator=(value_storage_nontrivial &&) = default; // NOLINT if reaches here, move assignment is trivial
    value_storage_nontrivial(value_storage_nontrivial &&o) noexcept(std::is_nothrow_move_constructible<value_type>::value) // NOLINT
    : _status(o._status)
    {
      if(this->_status & status_have_value)
      {
        this->_status &= ~status_have_value;
        new(&_value) value_type(static_cast<value_type &&>(o._value)); // NOLINT
        _status = o._status;
      }
    }
    value_storage_nontrivial(const value_storage_nontrivial &o) noexcept(std::is_nothrow_copy_constructible<value_type>::value)
        : _status(o._status)
    {
      if(this->_status & status_have_value)
      {
        this->_status &= ~status_have_value;
        new(&_value) value_type(o._value); // NOLINT
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
        new(&_value) value_type; // NOLINT
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
        : _value(static_cast<Args &&>(args)...) // NOLINT
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
        this->_value.~value_type(); // NOLINT
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
        swap(_value, o._value); // NOLINT
        swap(_status, o._status);
        return;
      }
      // One must be empty and the other non-empty, so use move construction
      if((_status & status_have_value) != 0)
      {
        // Move construct me into other
        new(&o._value) value_type(static_cast<value_type &&>(_value)); // NOLINT
        this->_value.~value_type(); // NOLINT
        swap(_status, o._status);
      }
      else
      {
        // Move construct other into me
        new(&_value) value_type(static_cast<value_type &&>(o._value)); // NOLINT
        o._value.~value_type(); // NOLINT
        swap(_status, o._status);
      }
    }
  };
  template <class Base> struct value_storage_delete_copy_constructor : Base // NOLINT
  {
    using Base::Base;
    using value_type = typename Base::value_type;
    value_storage_delete_copy_constructor() = default;
    value_storage_delete_copy_constructor(const value_storage_delete_copy_constructor &) = delete;
    value_storage_delete_copy_constructor(value_storage_delete_copy_constructor &&) = default; // NOLINT
  };
  template <class Base> struct value_storage_delete_copy_assignment : Base // NOLINT
  {
    using Base::Base;
    using value_type = typename Base::value_type;
    value_storage_delete_copy_assignment() = default;
    value_storage_delete_copy_assignment(const value_storage_delete_copy_assignment &) = default;
    value_storage_delete_copy_assignment(value_storage_delete_copy_assignment &&) = default; // NOLINT
    value_storage_delete_copy_assignment &operator=(const value_storage_delete_copy_assignment &o) = delete;
    value_storage_delete_copy_assignment &operator=(value_storage_delete_copy_assignment &&o) = default; // NOLINT
  };
  template <class Base> struct value_storage_delete_move_assignment : Base // NOLINT
  {
    using Base::Base;
    using value_type = typename Base::value_type;
    value_storage_delete_move_assignment() = default;
    value_storage_delete_move_assignment(const value_storage_delete_move_assignment &) = default;
    value_storage_delete_move_assignment(value_storage_delete_move_assignment &&) = default; // NOLINT
    value_storage_delete_move_assignment &operator=(const value_storage_delete_move_assignment &o) = default;
    value_storage_delete_move_assignment &operator=(value_storage_delete_move_assignment &&o) = delete;
  };
  template <class Base> struct value_storage_delete_move_constructor : Base // NOLINT
  {
    using Base::Base;
    using value_type = typename Base::value_type;
    value_storage_delete_move_constructor() = default;
    value_storage_delete_move_constructor(const value_storage_delete_move_constructor &) = default;
    value_storage_delete_move_constructor(value_storage_delete_move_constructor &&) = delete;
  };
  template <class Base> struct value_storage_nontrivial_move_assignment : Base // NOLINT
  {
    using Base::Base;
    using value_type = typename Base::value_type;
    value_storage_nontrivial_move_assignment() = default;
    value_storage_nontrivial_move_assignment(const value_storage_nontrivial_move_assignment &) = default;
    value_storage_nontrivial_move_assignment(value_storage_nontrivial_move_assignment &&) = default; // NOLINT
    value_storage_nontrivial_move_assignment &operator=(const value_storage_nontrivial_move_assignment &o) = default;
    value_storage_nontrivial_move_assignment &operator=(value_storage_nontrivial_move_assignment &&o) noexcept(std::is_nothrow_move_assignable<value_type>::value) // NOLINT
    {
      if((this->_status & status_have_value) != 0 && (o._status & status_have_value) != 0)
      {
        this->_value = static_cast<value_type &&>(o._value); // NOLINT
      }
      else if((this->_status & status_have_value) != 0 && (o._status & status_have_value) == 0)
      {
        this->_value.~value_type(); // NOLINT
      }
      else if((this->_status & status_have_value) == 0 && (o._status & status_have_value) != 0)
      {
        new(&this->_value) value_type(static_cast<value_type &&>(o._value)); // NOLINT
      }
      this->_status = o._status;
      return *this;
    }
  };
  template <class Base> struct value_storage_nontrivial_copy_assignment : Base // NOLINT
  {
    using Base::Base;
    using value_type = typename Base::value_type;
    value_storage_nontrivial_copy_assignment() = default;
    value_storage_nontrivial_copy_assignment(const value_storage_nontrivial_copy_assignment &) = default;
    value_storage_nontrivial_copy_assignment(value_storage_nontrivial_copy_assignment &&) = default; // NOLINT
    value_storage_nontrivial_copy_assignment &operator=(value_storage_nontrivial_copy_assignment &&o) = default; // NOLINT
    value_storage_nontrivial_copy_assignment &operator=(const value_storage_nontrivial_copy_assignment &o) noexcept(std::is_nothrow_copy_assignable<value_type>::value)
    {
      if((this->_status & status_have_value) != 0 && (o._status & status_have_value) != 0)
      {
        this->_value = o._value; // NOLINT
      }
      else if((this->_status & status_have_value) != 0 && (o._status & status_have_value) == 0)
      {
        this->_value.~value_type(); // NOLINT
      }
      else if((this->_status & status_have_value) == 0 && (o._status & status_have_value) != 0)
      {
        new(&this->_value) value_type(o._value); // NOLINT
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
} // namespace detail

OUTCOME_V2_NAMESPACE_END

#endif
OUTCOME_V2_NAMESPACE_EXPORT_BEGIN

namespace detail
{
  template <class State, class E> constexpr inline void _set_error_is_errno(State & /*unused*/, const E & /*unused*/) {}
  template <class R, class S, class NoValuePolicy> class basic_result_final;
}

//! Namespace containing hooks used for intercepting and manipulating `basic_result`/`basic_outcome`
namespace hooks
{
  //! Get the sixteen bits of spare storage in a `basic_result` or `basic_outcome`.
  template <class R, class S, class NoValuePolicy> constexpr inline uint16_t spare_storage(const detail::basic_result_final<R, S, NoValuePolicy> *r) noexcept;
  //! Sets the sixteen bits of spare storage in a `basic_result` or `basic_outcome`.
  template <class R, class S, class NoValuePolicy> constexpr inline void set_spare_storage(detail::basic_result_final<R, S, NoValuePolicy> *r, uint16_t v) noexcept;
} // namespace hooks

namespace policy
{
  namespace detail
  {
    struct base;
  } // namespace detail
} // namespace policy

namespace detail
{
  //! The base implementation type of `basic_result<R, EC, NoValuePolicy>`.
  template <class R, class EC, class NoValuePolicy> //
  OUTCOME_REQUIRES(trait::type_can_be_used_in_basic_result<R> &&trait::type_can_be_used_in_basic_result<EC> && (std::is_void<EC>::value || std::is_default_constructible<EC>::value)) //
  class basic_result_storage
  {
    static_assert(trait::type_can_be_used_in_basic_result<R>, "The type R cannot be used in a basic_result");
    static_assert(trait::type_can_be_used_in_basic_result<EC>, "The type S cannot be used in a basic_result");
    static_assert(std::is_void<EC>::value || std::is_default_constructible<EC>::value, "The type S must be void or default constructible");

    friend NoValuePolicy;
    friend struct policy::detail::base;
    template <class T, class U, class V> friend class basic_result_storage;
    template <class T, class U, class V> friend class basic_result_final;
    template <class T, class U, class V> friend constexpr inline uint16_t hooks::spare_storage(const detail::basic_result_final<T, U, V> *r) noexcept; // NOLINT
    template <class T, class U, class V> friend constexpr inline void hooks::set_spare_storage(detail::basic_result_final<T, U, V> *r, uint16_t v) noexcept; // NOLINT

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

  protected:
    basic_result_storage() = default;
    basic_result_storage(const basic_result_storage &) = default; // NOLINT
    basic_result_storage(basic_result_storage &&) = default; // NOLINT
    basic_result_storage &operator=(const basic_result_storage &) = default; // NOLINT
    basic_result_storage &operator=(basic_result_storage &&) = default; // NOLINT
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
} // namespace detail
OUTCOME_V2_NAMESPACE_END

#endif
OUTCOME_V2_NAMESPACE_EXPORT_BEGIN

//! Namespace for injected convertibility
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
  } // namespace detail
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
  } // namespace detail

  /*! Default converter for types matching the `ValueOrError` concept.
  You can partially or fully specialise this converter for your own user defined types by
  injecting specialisations into the `convert` namespace.
  */



  template <class T, class U> struct value_or_error
  {
    //! False to indicate that this converter wants `basic_result`/`basic_outcome` to reject all other `basic_result`
    static constexpr bool enable_result_inputs = false;
    //! False to indicate that this converter wants `basic_outcome` to reject all other `basic_outcome`
    static constexpr bool enable_outcome_inputs = false;
    /*! Default converter for types matching the `ValueOrError` concept.
    \requires `std::decay_t<X>` to be the same type as `U`;
    `ValueOrError<U>` to be true, `U`'s `value_type` be constructible into `T`'s `value_type`
    and `U`'s `error_type` be constructible into `T`'s `error_type`.
    */




    OUTCOME_TEMPLATE(class X)
    OUTCOME_TREQUIRES(OUTCOME_TPRED(std::is_same<U, std::decay_t<X>>::value //
                                    &&ValueOrError<U> //
                                    && (std::is_void<typename std::decay_t<X>::value_type>::value || OUTCOME_V2_NAMESPACE::detail::is_explicitly_constructible<typename T::value_type, typename std::decay_t<X>::value_type>) //
                                    &&(std::is_void<typename std::decay_t<X>::error_type>::value || OUTCOME_V2_NAMESPACE::detail::is_explicitly_constructible<typename T::error_type, typename std::decay_t<X>::error_type>) ))
    constexpr T operator()(X &&v) { return v.has_value() ? detail::make_type<T, typename T::value_type>::value(static_cast<X &&>(v)) : detail::make_type<T, typename U::error_type>::error(static_cast<X &&>(v)); }
  };
} // namespace convert

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
  //! The error observers implementation of `basic_result<R, EC, NoValuePolicy>`.
  template <class Base, class EC, class NoValuePolicy> class basic_result_error_observers : public Base
  {
  public:
    using error_type = EC;
    using Base::Base;

    /// \output_section Narrow state observers
    /*! Access error without runtime checks.
    \preconditions The basic_result to have a failed state, otherwise it is undefined behaviour.
    \returns Reference to the held `error_type` according to overload.
    \group assume_error
    */




    constexpr error_type &assume_error() & noexcept
    {
      NoValuePolicy::narrow_error_check(static_cast<basic_result_error_observers &>(*this));
      return this->_error;
    }
    /// \group assume_error
    constexpr const error_type &assume_error() const &noexcept
    {
      NoValuePolicy::narrow_error_check(static_cast<const basic_result_error_observers &>(*this));
      return this->_error;
    }
    /// \group assume_error
    constexpr error_type &&assume_error() && noexcept
    {
      NoValuePolicy::narrow_error_check(static_cast<basic_result_error_observers &&>(*this));
      return static_cast<error_type &&>(this->_error);
    }
    /// \group assume_error
    constexpr const error_type &&assume_error() const &&noexcept
    {
      NoValuePolicy::narrow_error_check(static_cast<const basic_result_error_observers &&>(*this));
      return static_cast<const error_type &&>(this->_error);
    }

    /// \output_section Wide state observers
    /*! Access error with runtime checks.
    \returns Reference to the held `error_type` according to overload.
    \requires The basic_result to have a failed state, else whatever `NoValuePolicy` says ought to happen.
    \group error
    */




    constexpr error_type &error() &
    {
      NoValuePolicy::wide_error_check(static_cast<basic_result_error_observers &>(*this));
      return this->_error;
    }
    /// \group error
    constexpr const error_type &error() const &
    {
      NoValuePolicy::wide_error_check(static_cast<const basic_result_error_observers &>(*this));
      return this->_error;
    }
    /// \group error
    constexpr error_type &&error() &&
    {
      NoValuePolicy::wide_error_check(static_cast<basic_result_error_observers &&>(*this));
      return static_cast<error_type &&>(this->_error);
    }
    /// \group error
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
    /// \output_section Narrow state observers
    /*! Access error without runtime checks.
    */

    constexpr void assume_error() const noexcept { NoValuePolicy::narrow_error_check(*this); }
    /// \output_section Wide state observers
    /*! Access error with runtime checks.
    \requires The basic_result to have a failed state, else whatever `NoValuePolicy` says ought to happen.
    */


    constexpr void error() const { NoValuePolicy::wide_error_check(*this); }
  };
} // namespace detail
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
  //! The value observers implementation of `basic_result<R, EC, NoValuePolicy>`.
  template <class Base, class R, class NoValuePolicy> class basic_result_value_observers : public Base
  {
  public:
    using value_type = R;
    using Base::Base;

    /// \output_section Narrow state observers
    /*! Access value without runtime checks.
    \preconditions The basic_result to have a successful state, otherwise it is undefined behaviour.
    \returns Reference to the held `value_type` according to overload.
    \group assume_value
    */




    constexpr value_type &assume_value() & noexcept
    {
      NoValuePolicy::narrow_value_check(static_cast<basic_result_value_observers &>(*this));
      return this->_state._value; // NOLINT
    }
    /// \group assume_value
    constexpr const value_type &assume_value() const &noexcept
    {
      NoValuePolicy::narrow_value_check(static_cast<const basic_result_value_observers &>(*this));
      return this->_state._value; // NOLINT
    }
    /// \group assume_value
    constexpr value_type &&assume_value() && noexcept
    {
      NoValuePolicy::narrow_value_check(static_cast<basic_result_value_observers &&>(*this));
      return static_cast<value_type &&>(this->_state._value); // NOLINT
    }
    /// \group assume_value
    constexpr const value_type &&assume_value() const &&noexcept
    {
      NoValuePolicy::narrow_value_check(static_cast<const basic_result_value_observers &&>(*this));
      return static_cast<const value_type &&>(this->_state._value); // NOLINT
    }

    /// \output_section Wide state observers
    /*! Access value with runtime checks.
    \returns Reference to the held `value_type` according to overload.
    \requires The basic_result to have a successful state, else whatever `NoValuePolicy` says ought to happen.
    \group value
    */




    constexpr value_type &value() &
    {
      NoValuePolicy::wide_value_check(static_cast<basic_result_value_observers &>(*this));
      return this->_state._value; // NOLINT
    }
    /// \group value
    constexpr const value_type &value() const &
    {
      NoValuePolicy::wide_value_check(static_cast<const basic_result_value_observers &>(*this));
      return this->_state._value; // NOLINT
    }
    /// \group value
    constexpr value_type &&value() &&
    {
      NoValuePolicy::wide_value_check(static_cast<basic_result_value_observers &&>(*this));
      return static_cast<value_type &&>(this->_state._value); // NOLINT
    }
    /// \group value
    constexpr const value_type &&value() const &&
    {
      NoValuePolicy::wide_value_check(static_cast<const basic_result_value_observers &&>(*this));
      return static_cast<const value_type &&>(this->_state._value); // NOLINT
    }
  };
  template <class Base, class NoValuePolicy> class basic_result_value_observers<Base, void, NoValuePolicy> : public Base
  {
  public:
    using Base::Base;

    /// \output_section Narrow state observers
    /*! Access value without runtime checks.
    */

    constexpr void assume_value() const noexcept { NoValuePolicy::narrow_value_check(*this); }
    /// \output_section Wide state observers
    /*! Access value with runtime checks.
    \requires The basic_result to have a successful state, else whatever `NoValuePolicy` says ought to happen.
    */


    constexpr void value() const { NoValuePolicy::wide_value_check(*this); }
  };
} // namespace detail

OUTCOME_V2_NAMESPACE_END

#endif
OUTCOME_V2_NAMESPACE_EXPORT_BEGIN

namespace detail
{
  template <class R, class EC, class NoValuePolicy> using select_basic_result_impl = basic_result_error_observers<basic_result_value_observers<basic_result_storage<R, EC, NoValuePolicy>, R, NoValuePolicy>, EC, NoValuePolicy>;

  //! The assembled implementation type of `basic_result<R, S, NoValuePolicy>`.
  template <class R, class S, class NoValuePolicy>
  class basic_result_final



  : public select_basic_result_impl<R, S, NoValuePolicy>

  {
    using base = select_basic_result_impl<R, S, NoValuePolicy>;

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
    /*! Checks if has exception.
    \returns True if has exception.
    */


    constexpr bool has_exception() const noexcept { return (this->_state._status & detail::status_have_exception) != 0; }
    /*! Checks if has error or exception.
    \returns True if has error or exception.
    */


    constexpr bool has_failure() const noexcept { return (this->_state._status & detail::status_have_error) != 0 && (this->_state._status & detail::status_have_exception) != 0; }

    /// \output_section Comparison operators
    /*! True if equal to the other basic_result.
    \param o The other basic_result to compare to.

    \requires That both `value_type`'s have an `operator==` available;
    that both `error_type`'s have an `operator==` available.
    \effects Calls the `operator==` operation on any common stored state.
    Otherwise returns false. Ignores spare storage.
    \throws Any exception the individual `operator==` operations might throw.
    */








    OUTCOME_TEMPLATE(class T, class U, class V)
    OUTCOME_TREQUIRES(OUTCOME_TEXPR(std::declval<detail::devoid<R>>() == std::declval<detail::devoid<T>>()), //
                      OUTCOME_TEXPR(std::declval<detail::devoid<S>>() == std::declval<detail::devoid<U>>()))
    constexpr bool operator==(const basic_result_final<T, U, V> &o) const noexcept( //
    noexcept(std::declval<detail::devoid<R>>() == std::declval<detail::devoid<T>>()) && noexcept(std::declval<detail::devoid<S>>() == std::declval<detail::devoid<U>>()))
    {
      if((this->_state._status & detail::status_have_value) != 0 && (o._state._status & detail::status_have_value) != 0)
      {
        return this->_state._value == o._state._value;
      }
      if((this->_state._status & detail::status_have_error) != 0 && (o._state._status & detail::status_have_error) != 0)
      {
        return this->_error == o._error;
      }
      return false;
    }
    /*! True if equal to the success type sugar.
    \param o The success type sugar to compare to.

    \requires That both `value_type`'s have an `operator==` available.
    \effects Calls the `operator==` operation on any common stored state.
    Otherwise returns false. Ignores spare storage.
    \throws Any exception the individual `operator==` operations might throw.
    */







    OUTCOME_TEMPLATE(class T)
    OUTCOME_TREQUIRES(OUTCOME_TEXPR(std::declval<R>() == std::declval<T>()))
    constexpr bool operator==(const success_type<T> &o) const noexcept( //
    noexcept(std::declval<R>() == std::declval<T>()))
    {
      if((this->_state._status & detail::status_have_value) != 0)
      {
        return this->_state._value == o.value();
      }
      return false;
    }
    /*! True if equal to the success type sugar.
    \param o The success type sugar to compare to.

    \effects True if the result is valued.
    */




    constexpr bool operator==(const success_type<void> &o) const noexcept
    {
      (void) o;
      return (this->_state._status & detail::status_have_value) != 0;
    }
    /*! True if equal to the failure type sugar.
    \param o The failure type sugar to compare to.

    \requires That both `error_type`'s have an `operator==` available.
    \effects Calls the `operator==` operation on any common stored state.
    Otherwise returns false. Ignores spare storage.
    \throws Any exception the individual `operator==` operations might throw.
    */







    OUTCOME_TEMPLATE(class T)
    OUTCOME_TREQUIRES(OUTCOME_TEXPR(std::declval<S>() == std::declval<T>()))
    constexpr bool operator==(const failure_type<T, void> &o) const noexcept( //
    noexcept(std::declval<S>() == std::declval<T>()))
    {
      if((this->_state._status & detail::status_have_error) != 0)
      {
        return this->_error == o.error();
      }
      return false;
    }
    /*! True if not equal to the other basic_result.
    \param o The other basic_result to compare to.

    \requires That both `value_type`'s have an `operator!=` available;
    that both `error_type`'s have an `operator!=` available.
    \effects Calls the `operator!=` operation on any common stored state.
    Otherwise returns true. Ignores spare storage.
    \throws Any exception the individual `operator!=` operations might throw.
    */








    OUTCOME_TEMPLATE(class T, class U, class V)
    OUTCOME_TREQUIRES(OUTCOME_TEXPR(std::declval<detail::devoid<R>>() != std::declval<detail::devoid<T>>()), //
                      OUTCOME_TEXPR(std::declval<detail::devoid<S>>() != std::declval<detail::devoid<U>>()))
    constexpr bool operator!=(const basic_result_final<T, U, V> &o) const noexcept( //
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
    /*! True if not equal to the success type sugar.
    \param o The success type sugar to compare to.

    \requires That both `value_type`'s have an `operator!=` available.
    \effects Calls the `operator!=` operation on any common stored state.
    Otherwise returns true. Ignores spare storage.
    \throws Any exception the individual `operator!=` operations might throw.
    */







    OUTCOME_TEMPLATE(class T)
    OUTCOME_TREQUIRES(OUTCOME_TEXPR(std::declval<R>() != std::declval<T>()))
    constexpr bool operator!=(const success_type<T> &o) const noexcept( //
    noexcept(std::declval<R>() != std::declval<T>()))
    {
      if((this->_state._status & detail::status_have_value) != 0)
      {
        return this->_state._value != o.value();
      }
      return false;
    }
    /*! True if not equal to the success type sugar.
    \param o The success type sugar to compare to.

    \effects False if the result is valued.
    */




    constexpr bool operator!=(const success_type<void> &o) const noexcept
    {
      (void) o;
      return (this->_state._status & detail::status_have_value) == 0;
    }
    /*! True if not equal to the failure type sugar.
    \param o The failure type sugar to compare to.

    \requires That both `error_type`'s have an `operator!=` available.
    \effects Calls the `operator!=` operation on any common stored state.
    Otherwise returns true. Ignores spare storage.
    \throws Any exception the individual `operator!=` operations might throw.
    */







    OUTCOME_TEMPLATE(class T)
    OUTCOME_TREQUIRES(OUTCOME_TEXPR(std::declval<S>() != std::declval<T>()))
    constexpr bool operator!=(const failure_type<T, void> &o) const noexcept( //
    noexcept(std::declval<S>() != std::declval<T>()))
    {
      if((this->_state._status & detail::status_have_error) != 0)
      {
        return this->_error != o.error();
      }
      return true;
    }
  };
  /*! True if the basic_result is equal to the success type sugar.
  \param a The success type sugar to compare.
  \param b The basic_result to compare.

  \effects If a valid expression to do so, calls the `operator==` operation on the successful item returning true if equal. Otherwise returns false.
  \remarks Implemented as `b == a`.
  \throws Any exception the `operator==` operation might throw.
  */







  template <class T, class U, class V, class W> constexpr inline bool operator==(const success_type<W> &a, const basic_result_final<T, U, V> &b) noexcept(noexcept(b == a)) { return b == a; }
  /*! True if the basic_result is equal to the failure type sugar.
  \param a The failure type sugar to compare.
  \param b The basic_result to compare.

  \effects If a valid expression to do so, calls the `operator==` operation on the failure item returning true if equal. Otherwise returns false.
  \remarks Implemented as `b == a`.
  \throws Any exception the `operator==` operation might throw.
  */







  template <class T, class U, class V, class W> constexpr inline bool operator==(const failure_type<W, void> &a, const basic_result_final<T, U, V> &b) noexcept(noexcept(b == a)) { return b == a; }
  /*! True if the basic_result is not equal to the success type sugar.
  \param a The success type sugar to compare.
  \param b The basic_result to compare.

  \effects If a valid expression to do so, calls the `operator!=` operation on the successful item returning true if not equal. Otherwise returns false.
  \remarks Implemented as `b != a`.
  \throws Any exception the `operator!=` operation might throw.
  */







  template <class T, class U, class V, class W> constexpr inline bool operator!=(const success_type<W> &a, const basic_result_final<T, U, V> &b) noexcept(noexcept(b == a)) { return b != a; }
  /*! True if the basic_result is not equal to the failure type sugar.
  \param a The failure type sugar to compare.
  \param b The basic_result to compare.

  \effects If a valid expression to do so, calls the `operator!=` operation on the failure item returning true if not equal. Otherwise returns false.
  \remarks Implemented as `b != a`.
  \throws Any exception the `operator!=` operation might throw.
  */







  template <class T, class U, class V, class W> constexpr inline bool operator!=(const failure_type<W, void> &a, const basic_result_final<T, U, V> &b) noexcept(noexcept(b == a)) { return b != a; }
} // namespace detail

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























#ifndef OUTCOME_POLICY_DETAIL_COMMON_HPP
#define OUTCOME_POLICY_DETAIL_COMMON_HPP



#include <cassert>

OUTCOME_V2_NAMESPACE_EXPORT_BEGIN

namespace policy
{
  namespace detail
  {
    struct base
    {
    private:
      template <class Impl>
      static constexpr
#ifdef _MSC_VER
      __declspec(noreturn)
#elif defined(__GNUC__) || defined(__clang__)
        __attribute__((noreturn))
#endif
      void _ub(Impl && /*unused*/)
      {
        assert(false);
#if defined(__GNUC__) || defined(__clang__)
        __builtin_unreachable();
#endif
      }

    public:
      /*! Performs a narrow check of state, used in the assume_value() functions.
      \effects None.
      */


      template <class Impl> static constexpr void narrow_value_check(Impl &&self) noexcept
      {
        if((self._state._status & OUTCOME_V2_NAMESPACE::detail::status_have_value) == 0)
        {
          _ub(self);
        }
      }
      /*! Performs a narrow check of state, used in the assume_error() functions
      \effects None.
      */


      template <class Impl> static constexpr void narrow_error_check(Impl &&self) noexcept
      {
        if((self._state._status & OUTCOME_V2_NAMESPACE::detail::status_have_error) == 0)
        {
          _ub(self);
        }
      }
      /*! Performs a narrow check of state, used in the assume_exception() functions
      \effects None.
      */


      template <class Impl> static constexpr void narrow_exception_check(Impl &&self) noexcept
      {
        if((self._state._status & OUTCOME_V2_NAMESPACE::detail::status_have_exception) == 0)
        {
          _ub(self);
        }
      }
    };
  } // namespace detail
} // namespace policy

OUTCOME_V2_NAMESPACE_END

#endif
OUTCOME_V2_NAMESPACE_EXPORT_BEGIN

namespace policy
{
  /*! Policy which treats wide checks as narrow checks.

  Can be used in both `result` and `outcome`.
  */



  struct all_narrow : detail::base
  {
    /*! Performs a wide check of state, used in the value() functions. Calls `narrow_value_check()` and does nothing else.
    \effects None.
    */


    template <class Impl> static constexpr void wide_value_check(Impl &&self) { detail::base::narrow_value_check(static_cast<Impl &&>(self)); }
    /*! Performs a wide check of state, used in the error() functions. Calls `narrow_error_check()` and does nothing else.
    \effects None.
    */


    template <class Impl> static constexpr void wide_error_check(Impl &&self) { detail::base::narrow_error_check(static_cast<Impl &&>(self)); }
    /*! Performs a wide check of state, used in the exception() functions. Calls `narrow_exception_check()` and does nothing else.
    \effects None.
    */


    template <class Impl> static constexpr void wide_exception_check(Impl &&self) { detail::base::narrow_exception_check(static_cast<Impl &&>(self)); }
  };
} // namespace policy

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
  /*! Policy implementing any wide attempt to access the successful state as calling `std::abort`

  Can be used in both `result` and `outcome`.
  */



  struct terminate : detail::base
  {
    /*! Performs a wide check of state, used in the value() functions.
    \effects If result does not have a value, calls `std::terminate()`.
    */


    template <class Impl> static constexpr void wide_value_check(Impl &&self)
    {
      if((self._state._status & OUTCOME_V2_NAMESPACE::detail::status_have_value) == 0)
      {
        std::abort();
      }
    }
    /*! Performs a wide check of state, used in the error() functions
    \effects If result does not have an error, calls `std::terminate()`.
    */


    template <class Impl> static constexpr void wide_error_check(Impl &&self) noexcept
    {
      if((self._state._status & OUTCOME_V2_NAMESPACE::detail::status_have_error) == 0)
      {
        std::abort();
      }
    }
    /*! Performs a wide check of state, used in the exception() functions
    \effects If outcome does not have an exception, calls `std::terminate()`.
    */


    template <class Impl> static constexpr void wide_exception_check(Impl &&self)
    {
      if((self._state._status & OUTCOME_V2_NAMESPACE::detail::status_have_exception) == 0)
      {
        std::abort();
      }
    }
  };
} // namespace policy

OUTCOME_V2_NAMESPACE_END

#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation" // Standardese markup confuses clang
#endif

OUTCOME_V2_NAMESPACE_EXPORT_BEGIN

template <class R, class S, class NoValuePolicy> //
#if !defined(__GNUC__) || __GNUC__ >= 8 // GCC's constraints implementation is buggy
OUTCOME_REQUIRES(trait::type_can_be_used_in_basic_result<R> &&trait::type_can_be_used_in_basic_result<S> && (std::is_void<S>::value || std::is_default_constructible<S>::value)) //
#endif
class basic_result;

namespace detail
{
  // These are reused by basic_outcome to save load on the compiler
  template <class value_type, class error_type> struct result_predicates
  {
    // Predicate for the implicit constructors to be available
    static constexpr bool implicit_constructors_enabled = //
    !(trait::is_error_type<std::decay_t<value_type>>::value && trait::is_error_type<std::decay_t<error_type>>::value) // both value and error types are not whitelisted error types
    && ((!detail::is_implicitly_constructible<value_type, error_type> && !detail::is_implicitly_constructible<error_type, value_type>) // if value and error types cannot be constructed into one another
        || (trait::is_error_type<std::decay_t<error_type>>::value // if error type is a whitelisted error type
            && !detail::is_implicitly_constructible<error_type, value_type> // AND which cannot be constructed from the value type
            && std::is_integral<value_type>::value)); // AND the value type is some integral type

    // Predicate for the value converting constructor to be available. Weakened to allow result<int, C enum>.
    template <class T>
    static constexpr bool enable_value_converting_constructor = //
    implicit_constructors_enabled //
    && !is_in_place_type_t<std::decay_t<T>>::value // not in place construction
    && !trait::is_error_type_enum<error_type, std::decay_t<T>>::value // not an enum valid for my error type
    && ((detail::is_implicitly_constructible<value_type, T> && !detail::is_implicitly_constructible<error_type, T>) // is unambiguously for value type
        || (std::is_same<value_type, std::decay_t<T>>::value // OR is my value type exactly
            && detail::is_implicitly_constructible<value_type, T>) ); // and my value type is constructible from this ref form of T


    // Predicate for the error converting constructor to be available. Weakened to allow result<int, C enum>.
    template <class T>
    static constexpr bool enable_error_converting_constructor = //
    implicit_constructors_enabled //
    && !is_in_place_type_t<std::decay_t<T>>::value // not in place construction
    && !trait::is_error_type_enum<error_type, std::decay_t<T>>::value // not an enum valid for my error type
    && ((!detail::is_implicitly_constructible<value_type, T> && detail::is_implicitly_constructible<error_type, T>) // is unambiguously for error type
        || (std::is_same<error_type, std::decay_t<T>>::value // OR is my error type exactly
            && detail::is_implicitly_constructible<error_type, T>) ); // and my error type is constructible from this ref form of T

    // Predicate for the error condition converting constructor to be available.
    template <class ErrorCondEnum>
    static constexpr bool enable_error_condition_converting_constructor = //
    !is_in_place_type_t<std::decay_t<ErrorCondEnum>>::value // not in place construction
    && trait::is_error_type_enum<error_type, std::decay_t<ErrorCondEnum>>::value // is an error condition enum
    /*&& !detail::is_implicitly_constructible<value_type, ErrorCondEnum> && !detail::is_implicitly_constructible<error_type, ErrorCondEnum>*/; // not constructible via any other means

    // Predicate for the converting copy constructor from a compatible input to be available.
    template <class T, class U, class V>
    static constexpr bool enable_compatible_conversion = //
    (std::is_void<T>::value || detail::is_explicitly_constructible<value_type, typename basic_result<T, U, V>::value_type>) // if our value types are constructible
    &&(std::is_void<U>::value || detail::is_explicitly_constructible<error_type, typename basic_result<T, U, V>::error_type>) // if our error types are constructible
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
} // namespace detail

//! True if a `basic_result`
template <class T> using is_basic_result = detail::is_basic_result<std::decay_t<T>>;
//! True if a `basic_result`
template <class T> static constexpr bool is_basic_result_v = detail::is_basic_result<std::decay_t<T>>::value;

//! Namespace for ADL discovered hooks into events in `result` and `outcome`.
namespace hooks
{
  /*! The default instantiation hook implementation called when a `result` is first created
  by conversion from one of its possible types. Does nothing.
  \param 1 Some `result<...>` being constructed.
  \param 2 The source data.

  WARNING: The compiler is permitted to elide calls to constructors, and thus this hook may not get called when you think it should!
  */






  template <class T, class U> constexpr inline void hook_result_construction(T * /*unused*/, U && /*unused*/) noexcept {}
  /*! The default instantiation hook implementation called when a `result` is created by copying
  from another `result`. Does nothing.
  \param 1 Some `result<...>` being constructed.
  \param 2 The source data.

  WARNING: The compiler is permitted to elide calls to constructors, and thus this hook may not get called when you think it should!
  */






  template <class T, class U> constexpr inline void hook_result_copy_construction(T * /*unused*/, U && /*unused*/) noexcept {}
  /*! The default instantiation hook implementation called when a `result` is created by moving
  from another `result`. Does nothing.
  \param 1 Some `result<...>` being constructed.
  \param 2 The source data.

  WARNING: The compiler is permitted to elide calls to constructors, and thus this hook may not get called when you think it should!
  */






  template <class T, class U> constexpr inline void hook_result_move_construction(T * /*unused*/, U && /*unused*/) noexcept {}
  /*! The default instantiation hook implementation called when a `result` is created by in place
  construction. Does nothing.
  \param 1 Some `result<...>` being constructed.
  \param 2 The type of in place construction occurring.
  \param 3 The source data.

  WARNING: The compiler is permitted to elide calls to constructors, and thus this hook may not get called when you think it should!
  */







  template <class T, class U, class... Args> constexpr inline void hook_result_in_place_construction(T * /*unused*/, in_place_type_t<U> /*unused*/, Args &&... /*unused*/) noexcept {}

  //! Retrieves the 16 bits of spare storage in result/outcome.
  template <class R, class S, class NoValuePolicy> constexpr inline uint16_t spare_storage(const detail::basic_result_final<R, S, NoValuePolicy> *r) noexcept { return (r->_state._status >> detail::status_2byte_shift) & 0xffff; }
  //! Sets the 16 bits of spare storage in result/outcome.
  template <class R, class S, class NoValuePolicy> constexpr inline void set_spare_storage(detail::basic_result_final<R, S, NoValuePolicy> *r, uint16_t v) noexcept { r->_state._status |= (v << detail::status_2byte_shift); }
} // namespace hooks

/*! Used to return from functions either (i) a successful value (ii) a cause of failure. `constexpr` capable.

\tparam R The optional type of the successful result (use `void` to disable). Cannot be a reference, a `in_place_type_t<>`, `success<>`, `failure<>`, an array, a function or non-destructible.
\tparam S The optional type of the failure result (use `void` to disable). Must be either `void` or `DefaultConstructible`. Cannot be a reference, a `in_place_type_t<>`, `success<>`, `failure<>`, an array, a function or non-destructible.
\tparam NoValuePolicy Policy on how to interpret type `S` when a wide observation of a not present value occurs.

Any `R` (`value_type`) state can be observed using the member functions `.value()` and `.assume_value()`. Any `S` (`error_type`) state can be
observed using the member functions `.error()` and `.assume_error()`.
*/








template <class R, class S, class NoValuePolicy> //
#if !defined(__GNUC__) || __GNUC__ >= 8 // GCC's constraints implementation is buggy
OUTCOME_REQUIRES(trait::type_can_be_used_in_basic_result<R> &&trait::type_can_be_used_in_basic_result<S> && (std::is_void<S>::value || std::is_default_constructible<S>::value)) //
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
  /// \output_section Member types
  //! The success type.
  using value_type = R;
  //! The failure type.
  using error_type = S;

  //! Used to disable in place type construction when `value_type` and `error_type` are ambiguous.
  using value_type_if_enabled = typename base::_value_type;
  //! Used to disable in place type construction when `value_type` and `error_type` are ambiguous.
  using error_type_if_enabled = typename base::_error_type;

  //! Used to rebind this result to a different result type.
  template <class T, class U = S, class V = NoValuePolicy> using rebind = basic_result<T, U, V>;

protected:
  //! Requirement predicates for result.
  struct predicate
  {
    using base = detail::result_predicates<value_type, error_type>;

    // Predicate for any constructors to be available at all
    static constexpr bool constructors_enabled = !std::is_same<std::decay_t<value_type>, std::decay_t<error_type>>::value;

    // Predicate for implicit constructors to be available at all
    static constexpr bool implicit_constructors_enabled = constructors_enabled && base::implicit_constructors_enabled;

    //! Predicate for the value converting constructor to be available.
    template <class T>
    static constexpr bool enable_value_converting_constructor = //
    constructors_enabled //
    && !std::is_same<std::decay_t<T>, basic_result>::value // not my type
    && base::template enable_value_converting_constructor<T>;

    //! Predicate for the error converting constructor to be available.
    template <class T>
    static constexpr bool enable_error_converting_constructor = //
    constructors_enabled //
    && !std::is_same<std::decay_t<T>, basic_result>::value // not my type
    && base::template enable_error_converting_constructor<T>;

    //! Predicate for the error condition converting constructor to be available.
    template <class ErrorCondEnum>
    static constexpr bool enable_error_condition_converting_constructor = //
    constructors_enabled //
    && !std::is_same<std::decay_t<ErrorCondEnum>, basic_result>::value // not my type
    && base::template enable_error_condition_converting_constructor<ErrorCondEnum>;

    //! Predicate for the converting copy constructor from a compatible input to be available.
    template <class T, class U, class V>
    static constexpr bool enable_compatible_conversion = //
    constructors_enabled //
    && !std::is_same<basic_result<T, U, V>, basic_result>::value // not my type
    && base::template enable_compatible_conversion<T, U, V>;

    //! Predicate for the inplace construction of value to be available.
    template <class... Args>
    static constexpr bool enable_inplace_value_constructor = //
    constructors_enabled //
    && (std::is_void<value_type>::value //
        || std::is_constructible<value_type, Args...>::value);

    //! Predicate for the inplace construction of error to be available.
    template <class... Args>
    static constexpr bool enable_inplace_error_constructor = //
    constructors_enabled //
    && (std::is_void<error_type>::value //
        || std::is_constructible<error_type, Args...>::value);

    // Predicate for the implicit converting inplace constructor to be available.
    template <class... Args>
    static constexpr bool enable_inplace_value_error_constructor = //
    constructors_enabled //
    &&base::template enable_inplace_value_error_constructor<Args...>;
    template <class... Args> using choose_inplace_value_error_constructor = typename base::template choose_inplace_value_error_constructor<Args...>;
  };

public:
  /// \output_section Default, copy/move constructors and assignment
  //! Default construction is not permitted.
  basic_result() = delete;
  //! Move construction available if `value_type` and `error_type` implement it.
  basic_result(basic_result && /*unused*/) = default; // NOLINT
  //! Copy construction available if `value_type` and `error_type` implement it.
  basic_result(const basic_result & /*unused*/) = default;
  //! Move assignment available if `value_type` and `error_type` implement it.
  basic_result &operator=(basic_result && /*unused*/) = default; // NOLINT
  //! Copy assignment available if `value_type` and `error_type` implement it.
  basic_result &operator=(const basic_result & /*unused*/) = default;
  ~basic_result() = default;

  /// \output_section Disabling constructors
  /*! Disabling constructor for when all constructors are disabled.
  \tparam 2
  \exclude

  \requires `value_type` and `error_type` to be the same type.
  \effects Declares a catch-all constructor which is deleted to give a clear error message to the user
  that identical `value_type` and `error_type` is not supported, whilst also preserving compile-time introspection.
  */







  OUTCOME_TEMPLATE(class Arg, class... Args)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(!predicate::constructors_enabled && (sizeof...(Args) >= 0)))
  basic_result(Arg && /*unused*/, Args &&... /*unused*/) = delete; // NOLINT basic_result<T, T> is NOT SUPPORTED, see docs!

  /*! Disabling implicit constructor for when implicit constructors are disabled.
  \tparam 1
  \exclude

  \requires `value_type` and `error_type` to be ambiguous.
  \effects Declares a value type constructor which is deleted to give a clear error message to the user
  that `value_type` and `error_type` are ambiguous, whilst also preserving compile-time introspection.
  */







  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED((predicate::constructors_enabled && !predicate::implicit_constructors_enabled //
                                   && (detail::is_implicitly_constructible<value_type, T> || detail::is_implicitly_constructible<error_type, T>) )))
  basic_result(T && /*unused*/, implicit_constructors_disabled_tag /*unused*/ = implicit_constructors_disabled_tag()) = delete; // NOLINT Implicit constructors disabled, use explicit in_place_type<T>, success() or failure(). see docs!

  /// \output_section Converting constructors
  /*! Implicit converting constructor to a successful basic_result.
  \tparam 1
  \exclude
  \param 1
  \exclude
  \param t The value from which to initialise the `value_type`.

  \effects Initialises the basic_result with a `value_type`.
  \requires Type T is implicitly constructible to `value_type`, is not implicitly constructible to `error_type`, and is not `basic_result<R, S>` and not `in_place_type<>`.
  \throws Any exception the construction of `value_type(T)` might throw.
  */










  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_value_converting_constructor<T>))
  constexpr basic_result(T &&t, value_converting_constructor_tag /*unused*/ = value_converting_constructor_tag()) noexcept(std::is_nothrow_constructible<value_type, T>::value) // NOLINT
  : base{in_place_type<typename base::value_type>, static_cast<T &&>(t)}
  {
    using namespace hooks;
    hook_result_construction(this, static_cast<T &&>(t));
  }
  /*! Implicit converting constructor to a failure basic_result.
  \tparam 1
  \exclude
  \param 1
  \exclude
  \param t The value from which to initialise the `error_type`.

  \effects Initialises the basic_result with a `error_type`.
  \requires Type T is implicitly constructible to `error_type`,
  is not implicitly constructible to `value_type`, and is not `basic_result<R, S>` and not `in_place_type<>`.
  \throws Any exception the construction of `error_type(T)` might throw.
  */











  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_error_converting_constructor<T>))
  constexpr basic_result(T &&t, error_converting_constructor_tag /*unused*/ = error_converting_constructor_tag()) noexcept(std::is_nothrow_constructible<error_type, T>::value) // NOLINT
  : base{in_place_type<typename base::error_type>, static_cast<T &&>(t)}
  {
    using namespace hooks;
    hook_result_construction(this, static_cast<T &&>(t));
  }
  /*! Implicit special error condition converting constructor to a failure basic_result.
  \tparam 1
  \exclude
  \tparam 2
  \exclude
  \param 1
  \exclude
  \param t The error condition from which to initialise the `error_type`.

  \effects Initialises the basic_result with a `error_type` constructed via `make_error_code(t)`.
  \requires `std::is_error_condition_enum<ErrorCondEnum>` must be true,
  `ErrorCondEnum` is not implicitly constructible to `value_type` nor `error_type`, and is not `basic_result<R, S>` and not `in_place_type<>`;
  Finally, the expression `error_type(make_error_code(ErrorCondEnum()))` must be valid.
  \throws Any exception the construction of `error_type(make_error_code(t))` might throw.
  */














  OUTCOME_TEMPLATE(class ErrorCondEnum)
  OUTCOME_TREQUIRES(OUTCOME_TEXPR(error_type(make_error_code(ErrorCondEnum()))), //
                    OUTCOME_TPRED(predicate::template enable_error_condition_converting_constructor<ErrorCondEnum>))
  constexpr basic_result(ErrorCondEnum &&t, error_condition_converting_constructor_tag /*unused*/ = error_condition_converting_constructor_tag()) noexcept(noexcept(error_type(make_error_code(static_cast<ErrorCondEnum &&>(t))))) // NOLINT
  : base{in_place_type<typename base::error_type>, make_error_code(t)}
  {
    using namespace hooks;
    hook_result_construction(this, static_cast<ErrorCondEnum &&>(t));
  }

  /*! Explicit converting constructor from a compatible `ValueOrError` type.
  \tparam 1
  \exclude
  \tparam 2
  \exclude
  \param 1
  \exclude
  \param o The input for which a `convert::value_or_error<basic_result, std::decay_t<T>>{}(std::forward<T>(o))` is available.

  \effects Initialises the basic_result with the contents of the compatible input.
  \requires That `convert::value_or_error<basic_result, std::decay_t<T>>{}(std::forward<T>(o))` be available. The
  default implementation will consume `T`'s matching the `ValueOrError` concept type.
  `ValueOrError` concept matches any type with a `value_type`,
  an `error_type`, a `.value()`, an `.error()` and a `.has_value()`.
  */














  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(convert::value_or_error<basic_result, std::decay_t<T>>::enable_result_inputs || !is_basic_result_v<T>), //
                    OUTCOME_TEXPR(convert::value_or_error<basic_result, std::decay_t<T>>{}(std::declval<T>())))
  constexpr explicit basic_result(T &&o, explicit_valueorerror_converting_constructor_tag /*unused*/ = explicit_valueorerror_converting_constructor_tag()) // NOLINT
  : basic_result{convert::value_or_error<basic_result, std::decay_t<T>>{}(static_cast<T &&>(o))}
  {
  }
  /*! Explicit converting copy constructor from a compatible basic_result type.
  \tparam 3
  \exclude
  \param o The compatible basic_result.

  \effects Initialises the basic_result with a copy of the compatible basic_result.
  \requires Both basic_result's `value_type` and `error_type` need to be constructible, or the source can be `void`.
  \throws Any exception the construction of `value_type(T)` and `error_type(U)` might throw.
  */








  OUTCOME_TEMPLATE(class T, class U, class V)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_compatible_conversion<T, U, V>))
  constexpr explicit basic_result(const basic_result<T, U, V> &o) noexcept(std::is_nothrow_constructible<value_type, T>::value &&std::is_nothrow_constructible<error_type, U>::value)
      : base{typename base::compatible_conversion_tag(), o}
  {
    using namespace hooks;
    hook_result_copy_construction(this, o);
  }
  /*! Explicit converting move constructor from a compatible basic_result type.
  \tparam 3
  \exclude
  \param o The compatible basic_result.

  \effects Initialises the basic_result with a move of the compatible basic_result.
  \requires Both basic_result's `value_type` and `error_type` need to be constructible, or the source can be `void`.
  \throws Any exception the construction of `value_type(T)` and `error_type(U)` might throw.
  */








  OUTCOME_TEMPLATE(class T, class U, class V)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_compatible_conversion<T, U, V>))
  constexpr explicit basic_result(basic_result<T, U, V> &&o) noexcept(std::is_nothrow_constructible<value_type, T>::value &&std::is_nothrow_constructible<error_type, U>::value)
      : base{typename base::compatible_conversion_tag(), static_cast<basic_result<T, U, V> &&>(o)}
  {
    using namespace hooks;
    hook_result_move_construction(this, static_cast<basic_result<T, U, V> &&>(o));
  }

  /// \output_section In place constructors
  /*! Explicit inplace constructor to a successful basic_result.
  \tparam 1
  \exclude
  \param _ Tag type to indicate we are doing in place construction of `value_type`.
  \param args Arguments with which to in place construct.

  \effects Initialises the basic_result with a `value_type`.
  \requires `value_type` is void or `Args...` are constructible to `value_type`.
  \throws Any exception the construction of `value_type(Args...)` might throw.
  */









  OUTCOME_TEMPLATE(class... Args)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_inplace_value_constructor<Args...>))
  constexpr explicit basic_result(in_place_type_t<value_type_if_enabled> _, Args &&... args) noexcept(std::is_nothrow_constructible<value_type, Args...>::value)
      : base{_, static_cast<Args &&>(args)...}
  {
    using namespace hooks;
    hook_result_in_place_construction(this, in_place_type<value_type>, static_cast<Args &&>(args)...);
  }
  /*! Explicit inplace constructor to a successful basic_result.
  \tparam 2
  \exclude
  \param _ Tag type to indicate we are doing in place construction of `value_type`.
  \param il An initializer list with which to in place construct.
  \param args Arguments with which to in place construct.

  \effects Initialises the basic_result with a `value_type`.
  \requires The initializer list + `Args...` are constructible to `value_type`.
  \throws Any exception the construction of `value_type(il, Args...)` might throw.
  */










  OUTCOME_TEMPLATE(class U, class... Args)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_inplace_value_constructor<std::initializer_list<U>, Args...>))
  constexpr explicit basic_result(in_place_type_t<value_type_if_enabled> _, std::initializer_list<U> il, Args &&... args) noexcept(std::is_nothrow_constructible<value_type, std::initializer_list<U>, Args...>::value)
      : base{_, il, static_cast<Args &&>(args)...}
  {
    using namespace hooks;
    hook_result_in_place_construction(this, in_place_type<value_type>, il, static_cast<Args &&>(args)...);
  }
  /*! Explicit inplace constructor to a failure basic_result.
  \tparam 1
  \exclude
  \param _ Tag type to indicate we are doing in place construction of `error_type`.
  \param args Arguments with which to in place construct.

  \effects Initialises the basic_result with a `error_type`.
  \requires `error_type` is void or `Args...` are constructible to `error_type`.
  \throws Any exception the construction of `error_type(Args...)` might throw.
  */









  OUTCOME_TEMPLATE(class... Args)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_inplace_error_constructor<Args...>))
  constexpr explicit basic_result(in_place_type_t<error_type_if_enabled> _, Args &&... args) noexcept(std::is_nothrow_constructible<error_type, Args...>::value)
      : base{_, static_cast<Args &&>(args)...}
  {
    using namespace hooks;
    hook_result_in_place_construction(this, in_place_type<error_type>, static_cast<Args &&>(args)...);
  }
  /*! Explicit inplace constructor to a failure basic_result.
  \tparam 2
  \exclude
  \param _ Tag type to indicate we are doing in place construction of `error_type`.
  \param il An initializer list with which to in place construct.
  \param args Arguments with which to in place construct.

  \effects Initialises the basic_result with a `error_type`.
  \requires The initializer list + `Args...` are constructible to `error_type`.
  \throws Any exception the construction of `error_type(il, Args...)` might throw.
  */










  OUTCOME_TEMPLATE(class U, class... Args)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_inplace_error_constructor<std::initializer_list<U>, Args...>))
  constexpr explicit basic_result(in_place_type_t<error_type_if_enabled> _, std::initializer_list<U> il, Args &&... args) noexcept(std::is_nothrow_constructible<error_type, std::initializer_list<U>, Args...>::value)
      : base{_, il, static_cast<Args &&>(args)...}
  {
    using namespace hooks;
    hook_result_in_place_construction(this, in_place_type<error_type>, il, static_cast<Args &&>(args)...);
  }
  /*! Implicit inplace constructor to successful or failure basic_result.
  \tparam 3
  \exclude
  \param args Arguments with which to in place construct.

  \effects Calls the appropriate `in_place_type_t<...>` constructor depending on constructibility of args.
  \requires That the args can construct exactly one of `value_type` or `error_type`.
  \throws Any exception the `in_place_type_t<...>` constructor might throw.
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

  /// \output_section Tagged constructors
  /*! Implicit tagged constructor of a successful basic_result.
  \param o The compatible success type sugar.

  \effects Initialises the basic_result with a default constructed success type.
  \requires `value_type` to be default constructible, or `void`.
  \throws Any exception the construction of `value_type()` might throw.
  */






  constexpr basic_result(const success_type<void> &o) noexcept(std::is_nothrow_default_constructible<value_type>::value) // NOLINT
  : base{in_place_type<value_type_if_enabled>}
  {
    using namespace hooks;
    hook_result_copy_construction(this, o);
  }
  /*! Implicit tagged constructor of a successful basic_result.
  \tparam 1
  \exclude
  \param o The compatible success type sugar.

  \effects Initialises the basic_result with a copy of the value in the type sugar.
  \requires Both basic_result and success' `value_type` need to be constructible, or the source can be `void`.
  \throws Any exception the construction of `value_type(T)` might throw.
  */








  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_compatible_conversion<T, void, void>))
  constexpr basic_result(const success_type<T> &o) noexcept(std::is_nothrow_constructible<value_type, T>::value) // NOLINT
  : base{in_place_type<value_type_if_enabled>, detail::extract_value_from_success<value_type>(o)}
  {
    using namespace hooks;
    hook_result_copy_construction(this, o);
  }
  /*! Implicit tagged constructor of a successful basic_result.
  \tparam 1
  \exclude
  \param o The compatible success type sugar.

  \effects Initialises the basic_result with a move of the value in the type sugar.
  \requires Both basic_result and success' `value_type` need to be constructible. The source cannot be `void`.
  \throws Any exception the construction of `value_type(T)` might throw.
  */








  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(!std::is_void<T>::value && predicate::template enable_compatible_conversion<T, void, void>))
  constexpr basic_result(success_type<T> &&o) noexcept(std::is_nothrow_constructible<value_type, T>::value) // NOLINT
  : base{in_place_type<value_type_if_enabled>, detail::extract_value_from_success<value_type>(static_cast<success_type<T> &&>(o))}
  {
    using namespace hooks;
    hook_result_move_construction(this, static_cast<success_type<T> &&>(o));
  }
  /*! Implicit tagged constructor of a failure basic_result.
  \tparam 1
  \exclude
  \param o The compatible failure type sugar.

  \effects Initialises the basic_result with a copy of the error in the type sugar.
  \requires Both basic_result and failure's `error_type` need to be constructible, or the source can be `void`.
  \throws Any exception the construction of `error_type(T)` might throw.
  */








  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_compatible_conversion<void, T, void>))
  constexpr basic_result(const failure_type<T> &o) noexcept(std::is_nothrow_constructible<error_type, T>::value) // NOLINT
  : base{in_place_type<error_type_if_enabled>, detail::extract_error_from_failure<error_type>(o)}
  {
    using namespace hooks;
    hook_result_copy_construction(this, o);
  }
  /*! Implicit tagged constructor of a failure basic_result.
  \tparam 1
  \exclude
  \param o The compatible failure type sugar.

  \effects Initialises the basic_result with a move of the error in the type sugar.
  \requires Both basic_result and failure's `error_type` need to be constructible, or the source can be `void`.
  \throws Any exception the construction of `error_type(T)` might throw.
  */








  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_compatible_conversion<void, T, void>))
  constexpr basic_result(failure_type<T> &&o) noexcept(std::is_nothrow_constructible<error_type, T>::value) // NOLINT
  : base{in_place_type<error_type_if_enabled>, detail::extract_error_from_failure<error_type>(static_cast<failure_type<T> &&>(o))}
  {
    using namespace hooks;
    hook_result_move_construction(this, static_cast<failure_type<T> &&>(o));
  }

  /// \output_section Swap
  /*! Swaps this basic_result with another basic_result
  \effects Any `R` and/or `S` is swapped along with the metadata tracking them.
  \throws If the swap of value or error can throw, the throwing swap is done first.
  */



  void swap(basic_result &o) noexcept(detail::is_nothrow_swappable<value_type>::value &&std::is_nothrow_move_constructible<value_type>::value //
                                      &&detail::is_nothrow_swappable<error_type>::value &&std::is_nothrow_move_constructible<error_type>::value)
  {
    using std::swap;
    // If value swap can throw, do it first
    if(!noexcept(this->_state.swap(o._state)))
    {
      this->_state.swap(o._state);
      swap(this->_error, o._error);
    }
    else
    {
      swap(this->_error, o._error);
      this->_state.swap(o._state);
    }
  }

  /// \output_section Converters
  /*! Returns this basic_result as a `failure_type` with any errored state copied.
  \requires This basic_result to have a failed state, else whatever `assume_error()` would do.
  */


  auto as_failure() const & { return failure(this->assume_error()); }
  /*! Returns this basic_result as a `failure_type` with any errored state moved.
  \requires This basic_result to have a failed state, else whatever `assume_error()` would do.
  */


  auto as_failure() && { return failure(static_cast<basic_result &&>(*this).assume_error()); }
};

/*! Specialise swap for basic_result.
\effects Calls `a.swap(b)`.
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























#ifndef OUTCOME_TRAIT_STD_ERROR_CODE_HPP
#define OUTCOME_TRAIT_STD_ERROR_CODE_HPP



#include <system_error>

OUTCOME_V2_NAMESPACE_BEGIN

namespace detail
{
  // Customise _set_error_is_errno
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

} // namespace detail

//! Namespace for policies
namespace policy
{
  namespace detail
  {
    struct std_error_code_passthrough
    {
    };
    /* Pass through `make_error_code` function for anything implicitly convertible to `std::error_code`.
    \requires `T` is implicitly convertible to `std::error_code`.
    */


    OUTCOME_TEMPLATE(class T)
    OUTCOME_TREQUIRES(OUTCOME_TPRED(std::is_convertible<T, std::error_code>::value))
    constexpr inline decltype(auto) make_error_code(T &&v, std_error_code_passthrough /*unused*/ = {}) { return std::forward<T>(v); }

    template <size_t N, class T> constexpr inline void get(const T & /*unused*/);
    struct tuple_passthrough
    {
    };
    /* Pass through `make_error_code` function for any pair or tuple returning the first item.
    \requires That `make_error_code(std::get<0>(std::declval<T>()))` is a valid expression.
    */


    OUTCOME_TEMPLATE(class T)
    OUTCOME_TREQUIRES(OUTCOME_TEXPR(make_error_code(get<0>(std::declval<T>()))))
    constexpr inline decltype(auto) make_error_code(T &&v, tuple_passthrough /* unused */ = {}) { return make_error_code(get<0>(std::forward<T>(v))); }

    // Try ADL, if not use fall backs above
    template <class T> constexpr inline decltype(auto) error_code(T &&v) { return make_error_code(std::forward<T>(v)); }

    struct std_enum_overload_tag
    {
    };
  } // namespace detail

  //! Used by policies to extract a `std::error_code` from some input `T` via ADL discovery of some `make_error_code(T)` function.
  template <class T> constexpr inline decltype(auto) error_code(T &&v) { return detail::error_code(std::forward<T>(v)); }

  //! Override to define what the policies which throw a system error with payload ought to do for some particular `result.error()`.
  // inline void outcome_throw_as_system_error_with_payload(...) = delete;  // To use the error_code_throw_as_system_error policy with a custom Error type, you must define a outcome_throw_as_system_error_with_payload() free function to say how to handle the payload
  inline void outcome_throw_as_system_error_with_payload(const std::error_code &error) { OUTCOME_THROW_EXCEPTION(std::system_error(error)); }
  OUTCOME_TEMPLATE(class Error)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(std::is_error_code_enum<std::decay_t<Error>>::value || std::is_error_condition_enum<std::decay_t<Error>>::value))
  inline void outcome_throw_as_system_error_with_payload(Error &&error, detail::std_enum_overload_tag = detail::std_enum_overload_tag()) { OUTCOME_THROW_EXCEPTION(std::system_error(error_code(error))); }
} // namespace policy

//! Namespace for traits
namespace trait
{
  namespace detail
  {
    template <class T> using devoid = OUTCOME_V2_NAMESPACE::detail::devoid<T>;

    constexpr inline void make_error_code(...);
    // Also enable for any pair or tuple whose first item satisfies make_error_code()
    template <size_t N, class T> constexpr inline void get(const T & /*unused*/);
    template <class T, //
              class R = decltype(make_error_code(get<0>(std::declval<T>()))) //
              >
    constexpr inline R make_error_code(T &&);

    template <class T, typename V = std::decay_t<decltype(make_error_code(std::declval<devoid<T>>()))>> struct has_error_code
    {
      static constexpr bool value = false;
    };
    template <> struct has_error_code<std::error_code, void>
    {
      static constexpr bool value = true;
    };
    template <class T> struct has_error_code<T, std::error_code>
    {
      static constexpr bool value = true;
    };
  } // namespace detail

  /*! Trait for whether a free function `make_error_code(T)` returning a `std::error_code` exists or not.
  Also returns true if `std::error_code` is convertible from T.
  */


  template <class T> struct has_error_code : detail::has_error_code<std::decay_t<T>>
  {
  };
  /*! Trait for whether a free function `make_error_code(T)` returning a `std::error_code` exists or not.
  Also returns true if `std::error_code` is convertible from T.
  */


  template <class T> constexpr bool has_error_code_v = has_error_code<std::decay_t<T>>::value;

  // std::error_code is an error type
  template <> struct is_error_type<std::error_code>
  {
    static constexpr bool value = true;
  };
  // For std::error_code, std::is_error_condition_enum<> is the trait we want.
  template <class Enum> struct is_error_type_enum<std::error_code, Enum>
  {
    static constexpr bool value = std::is_error_condition_enum<Enum>::value;
  };

} // namespace trait

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























#ifndef OUTCOME_TRAIT_STD_EXCEPTION_HPP
#define OUTCOME_TRAIT_STD_EXCEPTION_HPP



#include <exception>

OUTCOME_V2_NAMESPACE_BEGIN

//! Namespace for policies
namespace policy
{
  namespace detail
  {
    /* Pass through `make_exception_ptr` function for `std::exception_ptr`.
    */

    inline std::exception_ptr make_exception_ptr(std::exception_ptr v) { return v; }

    // Try ADL, if not use fall backs above
    template <class T> constexpr inline decltype(auto) exception_ptr(T &&v) { return make_exception_ptr(std::forward<T>(v)); }
  } // namespace detail

  //! Used by policies to extract a `std::exception_ptr` from some input `T` via ADL discovery of some `make_exception_ptr(T)` function.
  template <class T> constexpr inline decltype(auto) exception_ptr(T &&v) { return detail::exception_ptr(std::forward<T>(v)); }

  namespace detail
  {
    template <bool has_error_payload> struct _rethrow_exception
    {
      template <class Exception> explicit _rethrow_exception(Exception && /*unused*/) // NOLINT
      {
      }
    };
    template <> struct _rethrow_exception<true>
    {
      template <class Exception> explicit _rethrow_exception(Exception &&excpt) // NOLINT
      {
        // ADL
        rethrow_exception(policy::exception_ptr(std::forward<Exception>(excpt)));
      }
    };
  } // namespace detail
} // namespace policy

//! Namespace for traits
namespace trait
{
  namespace detail
  {
    template <class T> using devoid = OUTCOME_V2_NAMESPACE::detail::devoid<T>;

    constexpr inline void make_exception_ptr(...);
    template <class T, typename V = std::decay_t<decltype(make_exception_ptr(std::declval<devoid<T>>()))>> struct has_exception_ptr
    {
      static constexpr bool value = false;
    };
    template <> struct has_exception_ptr<std::exception_ptr, void>
    {
      static constexpr bool value = true;
    };
    template <class T> struct has_exception_ptr<T, std::exception_ptr>
    {
      static constexpr bool value = true;
    };
  } // namespace detail

  /*! Trait for whether a free function `make_exception_ptr(T)` returning a `std::exception_ptr` exists or not.
  Also returns true if `std::exception_ptr` is convertible from T.
  */


  template <class T> struct has_exception_ptr : detail::has_exception_ptr<std::decay_t<T>>
  {
  };
  /*! Trait for whether a free function `make_exception_ptr(T)` returning a `std::exception_ptr` exists or not.
  Also returns true if `std::exception_ptr` is convertible from T.
  */


  template <class T> constexpr bool has_exception_ptr_v = has_exception_ptr<std::decay_t<T>>::value;

  // std::exception_ptr is an error type
  template <> struct is_error_type<std::exception_ptr>
  {
    static constexpr bool value = true;
  };

} // namespace trait

OUTCOME_V2_NAMESPACE_END

#endif
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

#define OUTCOME_FAIL_TO_COMPILE_OBSERVERS_MESSAGE "Attempt to wide observe value, error or " "exception for a result/outcome given an EC or E type which is not void, and for whom " "trait::has_error_code_v<EC>, trait::has_exception_ptr_v<EC>, and trait::has_exception_ptr_v<E> " "are all false. Please specify a NoValuePolicy to tell result/outcome what to do, or else use " "a more specific convenience type alias such as unchecked<T, E> to indicate you want the wide " "observers to be narrow, or checked<T, E> to indicate you always want an exception throw etc."







namespace policy
{
  /*! Policy which refuses to compile the wide checks with an error message. Used by `default_policy`
  to enforce disabling of wide observers.

  Can be used in both `result` and `outcome`.
  */




  struct fail_to_compile_observers : detail::base
  {
    /*! Performs a wide check of state, used in the value() functions. Fails to compile with a static assertion.
    \effects None.
    */


    template <class Impl> static constexpr void wide_value_check(Impl && /* unused */) { static_assert(!std::is_same<Impl, Impl>::value, "Attempt to wide observe value, error or " "exception for a result/outcome given an EC or E type which is not void, and for whom " "trait::has_error_code_v<EC>, trait::has_exception_ptr_v<EC>, and trait::has_exception_ptr_v<E> " "are all false. Please specify a NoValuePolicy to tell result/outcome what to do, or else use " "a more specific convenience type alias such as unchecked<T, E> to indicate you want the wide " "observers to be narrow, or checked<T, E> to indicate you always want an exception throw etc."); }
    /*! Performs a wide check of state, used in the error() functions. Fails to compile with a static assertion.
    \effects None.
    */


    template <class Impl> static constexpr void wide_error_check(Impl && /* unused */) { static_assert(!std::is_same<Impl, Impl>::value, "Attempt to wide observe value, error or " "exception for a result/outcome given an EC or E type which is not void, and for whom " "trait::has_error_code_v<EC>, trait::has_exception_ptr_v<EC>, and trait::has_exception_ptr_v<E> " "are all false. Please specify a NoValuePolicy to tell result/outcome what to do, or else use " "a more specific convenience type alias such as unchecked<T, E> to indicate you want the wide " "observers to be narrow, or checked<T, E> to indicate you always want an exception throw etc."); }
    /*! Performs a wide check of state, used in the exception() functions. Fails to compile with a static assertion.
    \effects None.
    */


    template <class Impl> static constexpr void wide_exception_check(Impl && /* unused */) { static_assert(!std::is_same<Impl, Impl>::value, "Attempt to wide observe value, error or " "exception for a result/outcome given an EC or E type which is not void, and for whom " "trait::has_error_code_v<EC>, trait::has_exception_ptr_v<EC>, and trait::has_exception_ptr_v<E> " "are all false. Please specify a NoValuePolicy to tell result/outcome what to do, or else use " "a more specific convenience type alias such as unchecked<T, E> to indicate you want the wide " "observers to be narrow, or checked<T, E> to indicate you always want an exception throw etc."); }
  };
} // namespace policy

#undef OUTCOME_FAIL_TO_COMPILE_OBSERVERS_MESSAGE

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























#ifndef OUTCOME_POLICY_RESULT_ERROR_CODE_THROW_AS_SYSTEM_ERROR_HPP
#define OUTCOME_POLICY_RESULT_ERROR_CODE_THROW_AS_SYSTEM_ERROR_HPP
/* Exception types throwable
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























#ifndef OUTCOME_BAD_ACCESS_HPP
#define OUTCOME_BAD_ACCESS_HPP



#include <stdexcept>

OUTCOME_V2_NAMESPACE_EXPORT_BEGIN

//! Thrown when you try to access state in a `result<R, S>` which isn't present.
class OUTCOME_SYMBOL_VISIBLE bad_result_access : public std::logic_error
{
public:
  explicit bad_result_access(const char *what)
      : std::logic_error(what)
  {
  }
};

//! Thrown when you try to access a value in a `result<R, S>` which isn't present.
template <class S> class OUTCOME_SYMBOL_VISIBLE bad_result_access_with : public bad_result_access
{
  S _error;

public:
  explicit bad_result_access_with(S v)
      : bad_result_access("no value")
      , _error(std::move(v))
  {
  }
  //! Observes the error
  //! \group result_error
  const S &error() const & { return _error; }
  //! \group result_error
  S &error() & { return _error; }
  //! \group result_error
  const S &&error() const && { return _error; }
  //! \group result_error
  S &&error() && { return _error; }
};

//! Thrown when you try to access state in a `outcome<T, EC, E>` which isn't present.
class OUTCOME_SYMBOL_VISIBLE bad_outcome_access : public std::logic_error
{
public:
  explicit bad_outcome_access(const char *what)
      : std::logic_error(what)
  {
  }
};

OUTCOME_V2_NAMESPACE_END

#endif
#include <system_error>

OUTCOME_V2_NAMESPACE_EXPORT_BEGIN

namespace policy
{
  template <class T, class EC, class E> struct error_code_throw_as_system_error;
  /*! Policy interpreting `EC` as a type for which `trait::has_error_code_v<EC>` is true.
  Any wide attempt to access the successful state where there is none calls an
  ADL discovered free function `outcome_throw_as_system_error_with_payload(.error())`.
  */



  template <class T, class EC> struct error_code_throw_as_system_error<T, EC, void> : detail::base
  {
    /*! Performs a wide check of state, used in the value() functions.
    \effects See description of class for effects.
    */


    template <class Impl> static constexpr void wide_value_check(Impl &&self)
    {
      if((self._state._status & OUTCOME_V2_NAMESPACE::detail::status_have_value) == 0)
      {
        if((self._state._status & OUTCOME_V2_NAMESPACE::detail::status_have_error) != 0)
        {
          // ADL discovered
          outcome_throw_as_system_error_with_payload(std::forward<Impl>(self)._error);
        }
        OUTCOME_THROW_EXCEPTION(bad_result_access("no value"));
      }
    }
    /*! Performs a wide check of state, used in the error() functions
    \effects If result does not have an error, it throws `bad_result_access`.
    */


    template <class Impl> static constexpr void wide_error_check(Impl &&self)
    {
      if((self._state._status & OUTCOME_V2_NAMESPACE::detail::status_have_error) == 0)
      {
        OUTCOME_THROW_EXCEPTION(bad_result_access("no error"));
      }
    }
  };
} // namespace policy

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























#ifndef OUTCOME_POLICY_RESULT_EXCEPTION_PTR_RETHROW_HPP
#define OUTCOME_POLICY_RESULT_EXCEPTION_PTR_RETHROW_HPP




OUTCOME_V2_NAMESPACE_EXPORT_BEGIN

namespace policy
{
  /*! Policy interpreting `EC` or `E` as a type for which `trait::has_exception_ptr_v<EC|E>` is true.
  Any wide attempt to access the successful state where there is none causes:
  `rethrow_exception(policy::exception_ptr(.error()|.exception()))` appropriately.
  */



  template <class T, class EC, class E> struct exception_ptr_rethrow;
  template <class T, class EC> struct exception_ptr_rethrow<T, EC, void> : detail::base
  {
    /*! Performs a wide check of state, used in the value() functions
    \effects If result does not have a value, if it has an error it rethrows that error via `rethrow_exception()`, else it throws `bad_result_access`.
    */


    template <class Impl> static constexpr void wide_value_check(Impl &&self)
    {
      if((self._state._status & OUTCOME_V2_NAMESPACE::detail::status_have_value) == 0)
      {
        if((self._state._status & OUTCOME_V2_NAMESPACE::detail::status_have_error) != 0)
        {
          // ADL
          rethrow_exception(policy::exception_ptr(std::forward<Impl>(self)._error));
        }
        OUTCOME_THROW_EXCEPTION(bad_result_access("no value"));
      }
    }
    /*! Performs a wide check of state, used in the value() functions
    \effects If result does not have a value, if it has an error it throws that error, else it throws `bad_result_access`.
    */


    template <class Impl> static constexpr void wide_error_check(Impl &&self)
    {
      if((self._state._status & OUTCOME_V2_NAMESPACE::detail::status_have_error) == 0)
      {
        OUTCOME_THROW_EXCEPTION(bad_result_access("no error"));
      }
    }
  };
} // namespace policy

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























#ifndef OUTCOME_POLICY_THROW_BAD_RESULT_ACCESS_HPP
#define OUTCOME_POLICY_THROW_BAD_RESULT_ACCESS_HPP




OUTCOME_V2_NAMESPACE_EXPORT_BEGIN

namespace policy
{
  /*! Policy which throws `bad_result_access_with<EC>` or `bad_result_access` during wide checks.

  Can be used in `result` only.
  */



  template <class EC> struct throw_bad_result_access : detail::base
  {
    /*! Performs a wide check of state, used in the value() functions.
    \effects If result does not have a value, it throws `bad_result_access_with<EC>`.
    */


    template <class Impl> static constexpr void wide_value_check(Impl &&self)
    {
      if((self._state._status & OUTCOME_V2_NAMESPACE::detail::status_have_value) == 0)
      {
        OUTCOME_THROW_EXCEPTION(bad_result_access_with<EC>(std::forward<Impl>(self)._error));
      }
    }
    /*! Performs a wide check of state, used in the error() functions
    \effects If result does not have an error, it throws `bad_result_access`.
    */


    template <class Impl> static constexpr void wide_error_check(Impl &&self)
    {
      if((self._state._status & OUTCOME_V2_NAMESPACE::detail::status_have_error) == 0)
      {
        OUTCOME_THROW_EXCEPTION(bad_result_access("no error"));
      }
    }
    /*! Performs a wide check of state, used in the exception() functions
    \effects If result does not have an exception, it throws `bad_outcome_access`.
    */


    template <class Impl> static constexpr void wide_exception_check(Impl &&self)
    {
      if((self._state._status & OUTCOME_V2_NAMESPACE::detail::status_have_exception) == 0)
      {
        OUTCOME_THROW_EXCEPTION(bad_outcome_access("no exception"));
      }
    }
  };
} // namespace policy

OUTCOME_V2_NAMESPACE_END

#endif
OUTCOME_V2_NAMESPACE_EXPORT_BEGIN

//! Namespace for policies
namespace policy
{
  /*! Default policy selector.
  */

  template <class T, class EC, class E>
  using default_policy = std::conditional_t< //
  std::is_void<EC>::value && std::is_void<E>::value,
  terminate, //
  std::conditional_t< //
  trait::has_error_code_v<EC>, error_code_throw_as_system_error<T, EC, E>, //
  std::conditional_t< //
  trait::has_exception_ptr_v<EC> || trait::has_exception_ptr_v<E>, exception_ptr_rethrow<T, EC, E>, //
  fail_to_compile_observers //
  >>>;
} // namespace policy

/*! `basic_result` defaulted to use `std::error_code` and a `NoValuePolicy` appropriate for `std` types.

`NoValuePolicy` defaults to a policy selected according to the characteristics of type `S`:

1. If `.value()` called when there is no `value_type` but there is an `error_type`:
- If \verbatim {{<api "success_failure/#unexposed-entity-outcome-v2-xxx-trait-has-error-code-v" "trait::has_error_code_v<S>">}} \end is true,
then `throw std::system_error(error()|make_error_code(error()))` [\verbatim {{<api "policies/result_error_code_throw_as_system_error" "policy::error_code_throw_as_system_error<S>">}} \end]
- If \verbatim {{<api "success_failure/#unexposed-entity-outcome-v2-xxx-trait-has-exception-ptr-v" "trait::has_exception_ptr_v<S>">}} \end is true, then `std::rethrow_exception(error()|make_exception_ptr(error()))`
[\verbatim {{<api "policies/result_exception_ptr_rethrow/" "policy::exception_ptr_rethrow<R, S, void>">}} \end]
- If `S` is `void`, call `std::terminate()` [\verbatim {{<api "policies/terminate/" "policy::terminate">}} \end]
- If `S` is none of the above, then it is undefined behaviour [\verbatim {{<api "policies/all_narrow/" "policy::all_narrow">}} \end]
2. If `.error()` called when there is no `error_type`:
- If `trait::has_error_code_v<S>`, or if `trait::has_exception_ptr_v<S>`,
or if `S` is `void`, do `throw bad_result_access()`
- If `S` is none of the above, then it is undefined behaviour [`policy::all_narrow`]
*/















template <class R, class S = std::error_code, class NoValuePolicy = policy::default_policy<R, S, void>> //
using std_result = basic_result<R, S, NoValuePolicy>;

/*! An "unchecked" edition of `result<T, E>` which does no special handling of specific `E` types at all.
Attempting to access `T` when there is an `E` results in nothing happening at all, it is treated with a narrow
contract (i.e. undefined behaviour).
*/



template <class R, class S = std::error_code> using std_unchecked = std_result<R, S, policy::all_narrow>;

/*! A "checked" edition of `result<T, E>` which resembles fairly closely a `std::expected<T, E>`.
Attempting to access `T` when there is an `E` results in `bad_result_access<E>` being thrown. Nothing else.

Note that this approximates the proposed `expected<T, E>` up for standardisation, see the FAQ for more
detail.
*/





template <class R, class S = std::error_code> using std_checked = std_result<R, S, policy::throw_bad_result_access<S>>;

OUTCOME_V2_NAMESPACE_END

#endif
OUTCOME_V2_NAMESPACE_EXPORT_BEGIN

/*! In standalone Outcome, this aliases `std_result<>`. In Boost.Outcome, this aliases `boost_result<>`.
*/

template <class R, class S = std::error_code, class NoValuePolicy = policy::default_policy<R, S, void>> //
using result = std_result<R, S, NoValuePolicy>;

/*! In standalone Outcome, this aliases `std_unchecked<>`. In Boost.Outcome, this aliases `boost_checked<>`.
*/

template <class R, class S = std::error_code> using unchecked = result<R, S, policy::all_narrow>;

/*! In standalone Outcome, this aliases `std_checked<>`. In Boost.Outcome, this aliases `boost_checked<>`.
*/

template <class R, class S = std::error_code> using checked = result<R, S, policy::throw_bad_result_access<S>>;

OUTCOME_V2_NAMESPACE_END

#endif
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























#ifndef OUTCOME_STD_OUTCOME_HPP
#define OUTCOME_STD_OUTCOME_HPP
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
  //! The exception observers implementation of `basic_outcome<R, S, P>`.
  template <class Base, class R, class S, class P, class NoValuePolicy> class basic_outcome_exception_observers : public Base
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

  // Exception observers not present
  template <class Base, class R, class S, class NoValuePolicy> class basic_outcome_exception_observers<Base, R, S, void, NoValuePolicy> : public Base
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

} // namespace detail

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
  }
  template <class S, class P> inline void basic_outcome_failure_exception_from_error(...) = delete; // No specialisation for these error and exception types available!

  //! The failure observers implementation of `basic_outcome<R, S, P>`.
  template <class Base, class R, class S, class P, class NoValuePolicy> class basic_outcome_failure_observers : public Base
  {
  public:
    using exception_type = P;
    using Base::Base;

    /// \output_section Synthesising state observers
    /*! Synthesise exception where possible.
    \requires `trait::has_error_code_v<S>` and `trait::has_exception_ptr_v<P>` to be true, else it does not appear.
    \returns A synthesised exception type: if excepted, `exception()`; if errored, `xxx::make_exception_ptr(xxx::system_error(error()))`;
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
        return basic_outcome_failure_exception_from_error(this->error(), adl::search_detail_adl());
      }
      return exception_type();
    }
  };

} // namespace detail

OUTCOME_V2_NAMESPACE_END

#endif
#ifdef __clang__
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdocumentation" // Standardese markup confuses clang
#endif

OUTCOME_V2_NAMESPACE_EXPORT_BEGIN

template <class R, class S, class P, class NoValuePolicy> //
OUTCOME_REQUIRES(trait::type_can_be_used_in_basic_result<P> && (std::is_void<P>::value || std::is_default_constructible<P>::value)) //
class basic_outcome;

namespace detail
{
  // May be reused by basic_outcome subclasses to save load on the compiler
  template <class value_type, class error_type, class exception_type> struct outcome_predicates
  {
    using result = result_predicates<value_type, error_type>;

    // Predicate for the implicit constructors to be available
    static constexpr bool implicit_constructors_enabled = //
    result::implicit_constructors_enabled //
    && !detail::is_implicitly_constructible<value_type, exception_type> //
    && !detail::is_implicitly_constructible<error_type, exception_type> //
    && !detail::is_implicitly_constructible<exception_type, value_type> //
    && !detail::is_implicitly_constructible<exception_type, error_type>;

    // Predicate for the value converting constructor to be available.
    template <class T>
    static constexpr bool enable_value_converting_constructor = //
    implicit_constructors_enabled //
    &&result::template enable_value_converting_constructor<T> //
    && !detail::is_implicitly_constructible<exception_type, T>; // deliberately less tolerant of ambiguity than result's edition

    // Predicate for the error converting constructor to be available.
    template <class T>
    static constexpr bool enable_error_converting_constructor = //
    implicit_constructors_enabled //
    &&result::template enable_error_converting_constructor<T> //
    && !detail::is_implicitly_constructible<exception_type, T>; // deliberately less tolerant of ambiguity than result's edition

    // Predicate for the error condition converting constructor to be available.
    template <class ErrorCondEnum>
    static constexpr bool enable_error_condition_converting_constructor = result::template enable_error_condition_converting_constructor<ErrorCondEnum> //
                                                                          && !detail::is_implicitly_constructible<exception_type, ErrorCondEnum>;

    // Predicate for the exception converting constructor to be available.
    template <class T>
    static constexpr bool enable_exception_converting_constructor = //
    implicit_constructors_enabled //
    && !is_in_place_type_t<std::decay_t<T>>::value // not in place construction
    && !detail::is_implicitly_constructible<value_type, T> && !detail::is_implicitly_constructible<error_type, T> && detail::is_implicitly_constructible<exception_type, T>;

    // Predicate for the error + exception converting constructor to be available.
    template <class T, class U>
    static constexpr bool enable_error_exception_converting_constructor = //
    implicit_constructors_enabled //
    && !is_in_place_type_t<std::decay_t<T>>::value // not in place construction
    && !detail::is_implicitly_constructible<value_type, T> && detail::is_implicitly_constructible<error_type, T> //
    && !detail::is_implicitly_constructible<value_type, U> && detail::is_implicitly_constructible<exception_type, U>;

    // Predicate for the converting copy constructor from a compatible outcome to be available.
    template <class T, class U, class V, class W>
    static constexpr bool enable_compatible_conversion = //
    (std::is_void<T>::value || detail::is_explicitly_constructible<value_type, typename basic_outcome<T, U, V, W>::value_type>) // if our value types are constructible
    &&(std::is_void<U>::value || detail::is_explicitly_constructible<error_type, typename basic_outcome<T, U, V, W>::error_type>) // if our error types are constructible
    &&(std::is_void<V>::value || detail::is_explicitly_constructible<exception_type, typename basic_outcome<T, U, V, W>::exception_type>) // if our exception types are constructible
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

  // Select whether to use basic_outcome_failure_observers or not
  template <class Base, class R, class S, class P, class NoValuePolicy>
  using select_basic_outcome_failure_observers = //
  std::conditional_t<trait::has_error_code<S>::value && trait::has_exception_ptr<P>::value, basic_outcome_failure_observers<Base, R, S, P, NoValuePolicy>, Base>;

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
} // namespace detail

//! True if an outcome
template <class T> using is_basic_outcome = detail::is_basic_outcome<std::decay_t<T>>;
//! True if an outcome
template <class T> static constexpr bool is_basic_outcome_v = detail::is_basic_outcome<std::decay_t<T>>::value;

namespace hooks
{
  /*! The default instantiation hook implementation called when a `outcome` is first created
  by conversion from one of its possible types. Does nothing.
  \param 1 Some `outcome<...>` being constructed.
  \param 2 The source data.

  WARNING: The compiler is permitted to elide calls to constructors, and thus this hook may not get called when you think it should!
  */






  template <class T, class... U> constexpr inline void hook_outcome_construction(T * /*unused*/, U &&... /*unused*/) noexcept {}
  /*! The default instantiation hook implementation called when a `outcome` is created by copying
  from another `outcome` or `result`. Does nothing.
  \param 1 Some `outcome<...>` being constructed.
  \param 2 The source data.

  WARNING: The compiler is permitted to elide calls to constructors, and thus this hook may not get called when you think it should!
  */






  template <class T, class U> constexpr inline void hook_outcome_copy_construction(T * /*unused*/, U && /*unused*/) noexcept {}
  /*! The default instantiation hook implementation called when a `outcome` is created by moving
  from another `outcome` or `result`. Does nothing.
  \param 1 Some `outcome<...>` being constructed.
  \param 2 The source data.

  WARNING: The compiler is permitted to elide calls to constructors, and thus this hook may not get called when you think it should!
  */






  template <class T, class U> constexpr inline void hook_outcome_move_construction(T * /*unused*/, U && /*unused*/) noexcept {}
  /*! The default instantiation hook implementation called when a `outcome` is created by in place
  construction. Does nothing.
  \param 1 Some `outcome<...>` being constructed.
  \param 2 The type of in place construction occurring.
  \param 3 The source data.

  WARNING: The compiler is permitted to elide calls to constructors, and thus this hook may not get called when you think it should!
  */







  template <class T, class U, class... Args> constexpr inline void hook_outcome_in_place_construction(T * /*unused*/, in_place_type_t<U> /*unused*/, Args &&... /*unused*/) noexcept {}

  //! Used in hook implementations to override the exception to something other than what was constructed.
  template <class R, class S, class P, class NoValuePolicy, class U> constexpr inline void override_outcome_exception(basic_outcome<R, S, P, NoValuePolicy> *o, U &&v) noexcept;
} // namespace hooks

/*! Used to return from functions one of (i) a successful value (ii) a cause of failure (ii) a different cause of failure. `constexpr` capable.

\tparam R The optional type of the successful result (use `void` to disable). Cannot be a reference, a `in_place_type_t<>`, `success<>`, `failure<>`, an array, a function or non-destructible.
\tparam S The optional type of the first failure result (use `void` to disable). Must be either `void` or `DefaultConstructible`. Cannot be a reference, a `in_place_type_t<>`, `success<>`, `failure<>`, an array, a function or non-destructible.
\tparam P The optional type of the second failure result (use `void` to disable). Must be either `void` or `DefaultConstructible`. Cannot be a reference, a `in_place_type_t<>`, `success<>`, `failure<>`, an array, a function or non-destructible.
\tparam NoValuePolicy Policy on how to interpret types `S` and `P` when a wide observation of a not present value occurs.

This is an extension of `basic_result<R, S>` and it allows an alternative failure to be stored of type `P`, which can be observed
with the member functions `.exception()` and `.assume_exception()`. The `P` state takes precedence during no-value observation
over any `S` state, and it is possible to store `S + P` simultaneously such that `basic_outcome` could have any one the states:

1. `R` (`value_type`)
2. `S` (`error_type`)
3. `P` (`exception_type`)
4. `S + P` (`error_type + exception_type`)
*/















template <class R, class S, class P, class NoValuePolicy> //
OUTCOME_REQUIRES(trait::type_can_be_used_in_basic_result<P> && (std::is_void<P>::value || std::is_default_constructible<P>::value)) //
class OUTCOME_NODISCARD basic_outcome





: public detail::select_basic_outcome_failure_observers<detail::basic_outcome_exception_observers<detail::basic_result_final<R, S, NoValuePolicy>, R, S, P, NoValuePolicy>, R, S, P, NoValuePolicy>

{
  static_assert(trait::type_can_be_used_in_basic_result<P>, "The exception_type cannot be used");
  static_assert(std::is_void<P>::value || std::is_default_constructible<P>::value, "exception_type must be void or default constructible");
  using base = detail::select_basic_outcome_failure_observers<detail::basic_outcome_exception_observers<detail::basic_result_final<R, S, NoValuePolicy>, R, S, P, NoValuePolicy>, R, S, P, NoValuePolicy>;
  friend NoValuePolicy;
  friend detail::basic_outcome_exception_observers<detail::basic_result_final<R, S, NoValuePolicy>, R, S, P, NoValuePolicy>;
  template <class T, class U, class V, class W> friend class basic_outcome;
  template <class T, class U, class V, class W, class X> friend constexpr inline void hooks::override_outcome_exception(basic_outcome<T, U, V, W> *o, X &&v) noexcept; // NOLINT

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
  /// \output_section Member types
  //! The success type.
  using value_type = R;
  //! The failure type.
  using error_type = S;
  //! The exception type
  using exception_type = P;

  //! Used to rebind this outcome to a different outcome type
  template <class T, class U = S, class V = P, class W = NoValuePolicy> using rebind = basic_outcome<T, U, V, W>;

protected:
  //! Requirement predicates for outcome.
  struct predicate
  {
    using base = detail::outcome_predicates<value_type, error_type, exception_type>;

    // Predicate for any constructors to be available at all
    static constexpr bool constructors_enabled = (!std::is_same<std::decay_t<value_type>, std::decay_t<error_type>>::value //
                                                  && !std::is_same<std::decay_t<value_type>, std::decay_t<exception_type>>::value //
                                                  && !std::is_same<std::decay_t<error_type>, std::decay_t<exception_type>>::value) //
                                                 || (std::is_void<value_type>::value && std::is_void<error_type>::value) //
                                                 || (std::is_void<value_type>::value && std::is_void<exception_type>::value) //
                                                 || (std::is_void<error_type>::value && std::is_void<exception_type>::value);

    // Predicate for implicit constructors to be available at all
    static constexpr bool implicit_constructors_enabled = constructors_enabled && base::implicit_constructors_enabled;

    //! Predicate for the value converting constructor to be available.
    template <class T>
    static constexpr bool enable_value_converting_constructor = //
    constructors_enabled //
    && !std::is_same<std::decay_t<T>, basic_outcome>::value // not my type
    && base::template enable_value_converting_constructor<T>;

    //! Predicate for the error converting constructor to be available.
    template <class T>
    static constexpr bool enable_error_converting_constructor = //
    constructors_enabled //
    && !std::is_same<std::decay_t<T>, basic_outcome>::value // not my type
    && base::template enable_error_converting_constructor<T>;

    //! Predicate for the error condition converting constructor to be available.
    template <class ErrorCondEnum>
    static constexpr bool enable_error_condition_converting_constructor = //
    constructors_enabled //
    && !std::is_same<std::decay_t<ErrorCondEnum>, basic_outcome>::value // not my type
    && base::template enable_error_condition_converting_constructor<ErrorCondEnum>;

    // Predicate for the exception converting constructor to be available.
    template <class T>
    static constexpr bool enable_exception_converting_constructor = //
    constructors_enabled //
    && !std::is_same<std::decay_t<T>, basic_outcome>::value // not my type
    && base::template enable_exception_converting_constructor<T>;

    // Predicate for the error + exception converting constructor to be available.
    template <class T, class U>
    static constexpr bool enable_error_exception_converting_constructor = //
    constructors_enabled //
    && !std::is_same<std::decay_t<T>, basic_outcome>::value // not my type
    && base::template enable_error_exception_converting_constructor<T, U>;

    //! Predicate for the converting constructor from a compatible input to be available.
    template <class T, class U, class V, class W>
    static constexpr bool enable_compatible_conversion = //
    constructors_enabled //
    && !std::is_same<basic_outcome<T, U, V, W>, basic_outcome>::value // not my type
    && base::template enable_compatible_conversion<T, U, V, W>;

    //! Predicate for the inplace construction of value to be available.
    template <class... Args>
    static constexpr bool enable_inplace_value_constructor = //
    constructors_enabled //
    && (std::is_void<value_type>::value //
        || std::is_constructible<value_type, Args...>::value);

    //! Predicate for the inplace construction of error to be available.
    template <class... Args>
    static constexpr bool enable_inplace_error_constructor = //
    constructors_enabled //
    && (std::is_void<error_type>::value //
        || std::is_constructible<error_type, Args...>::value);

    //! Predicate for the inplace construction of exception to be available.
    template <class... Args>
    static constexpr bool enable_inplace_exception_constructor = //
    constructors_enabled //
    && (std::is_void<exception_type>::value //
        || std::is_constructible<exception_type, Args...>::value);

    // Predicate for the implicit converting inplace constructor to be available.
    template <class... Args>
    static constexpr bool enable_inplace_value_error_exception_constructor = //
    base::template enable_inplace_value_error_exception_constructor<Args...>;
    template <class... Args> using choose_inplace_value_error_exception_constructor = typename base::template choose_inplace_value_error_exception_constructor<Args...>;
  };

public:
  //! Used to disable in place type construction when `value_type` is ambiguous with `error_type` or `exception_type`.
  using value_type_if_enabled = std::conditional_t<std::is_same<value_type, error_type>::value || std::is_same<value_type, exception_type>::value, disable_in_place_value_type, value_type>;
  //! Used to disable in place type construction when `error_type` is ambiguous with `value_type` or `exception_type`.
  using error_type_if_enabled = std::conditional_t<std::is_same<error_type, value_type>::value || std::is_same<error_type, exception_type>::value, disable_in_place_error_type, error_type>;
  //! Used to disable in place type construction when `exception_type` is ambiguous with `value_type` or `error_type`.
  using exception_type_if_enabled = std::conditional_t<std::is_same<exception_type, value_type>::value || std::is_same<exception_type, error_type>::value, disable_in_place_exception_type, exception_type>;

protected:
  detail::devoid<exception_type> _ptr;

public:
  /// \output_section Disabling constructors
  /*! Disabling constructor for when all constructors are disabled.
  \tparam 2
  \exclude

  \requires Any one of `value_type`, `error_type` and `exception_type` to be the same type.
  \effects Declares a catch-all constructor which is deleted to give a clear error message to the user
  that identical `value_type`, `error_type` or `exception_type` is not supported, whilst also preserving compile-time introspection.
  */







  OUTCOME_TEMPLATE(class Arg, class... Args)
  OUTCOME_TREQUIRES(OUTCOME_TPRED((!predicate::constructors_enabled && sizeof...(Args) >= 0)))
  basic_outcome(Arg && /*unused*/, Args &&... /*unused*/) = delete; // NOLINT basic_outcome<> with any of the same type is NOT SUPPORTED, see docs!

  /*! Disabling implicit constructor for when implicit constructors are disabled.
  \tparam 1
  \exclude

  \requires Any one of `value_type`, `error_type` and `exception_type` to be ambiguous.
  \effects Declares a value type constructor which is deleted to give a clear error message to the user
  that `value_type` or `error_type` or `exception_type` are ambiguous, whilst also preserving compile-time introspection.
  */







  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED((predicate::constructors_enabled && !predicate::implicit_constructors_enabled //
                                   && (detail::is_implicitly_constructible<value_type, T> || detail::is_implicitly_constructible<error_type, T> || detail::is_implicitly_constructible<exception_type, T>) )))
  basic_outcome(T && /*unused*/, implicit_constructors_disabled_tag /*unused*/ = implicit_constructors_disabled_tag()) = delete; // NOLINT Implicit constructors disabled, use explicit in_place_type<T>, success() or failure(). see docs!

  /// \output_section Converting constructors
  /*! Converting constructor to a successful outcome.
  \tparam 1
  \exclude
  \param 1
  \exclude
  \param t The value from which to initialise the `value_type`.

  \effects Initialises the outcome with a `value_type`.
  \requires Type T is implicitly constructible to `value_type`, is not implicitly constructible to `error_type`, is not implicitly constructible to `exception_type` and is not `outcome<R, S, P>` and not `in_place_type<>`.
  \throws Any exception the construction of `value_type(T)` might throw.
  */










  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_value_converting_constructor<T>))
  constexpr basic_outcome(T &&t, value_converting_constructor_tag /*unused*/ = value_converting_constructor_tag()) noexcept(std::is_nothrow_constructible<value_type, T>::value) // NOLINT
  : base{in_place_type<typename base::_value_type>, static_cast<T &&>(t)},
    _ptr()
  {
    using namespace hooks;
    hook_outcome_construction(this, static_cast<T &&>(t));
  }
  /*! Converting constructor to an errored outcome.
  \tparam 1
  \exclude
  \param 1
  \exclude
  \param t The value from which to initialise the `error_type`.

  \effects Initialises the outcome with a `error_type`.
  \requires Type T is implicitly constructible to `error_type`,
  is not implicitly constructible to `value_type`, is not implicitly constructible to `exception_type`, and is not `outcome<R, S, P>` and not `in_place_type<>`.
  \throws Any exception the construction of `error_type(T)` might throw.
  */











  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_error_converting_constructor<T>))
  constexpr basic_outcome(T &&t, error_converting_constructor_tag /*unused*/ = error_converting_constructor_tag()) noexcept(std::is_nothrow_constructible<error_type, T>::value) // NOLINT
  : base{in_place_type<typename base::_error_type>, static_cast<T &&>(t)},
    _ptr()
  {
    using namespace hooks;
    hook_outcome_construction(this, static_cast<T &&>(t));
  }
  /*! Special error condition converting constructor to an errored outcome.
  \tparam 1
  \exclude
  \tparam 2
  \exclude
  \param 1
  \exclude
  \param t The error condition from which to initialise the `error_type`.

  \effects Initialises the outcome with a `error_type` constructed via `make_error_code(t)`.
  \requires `std::is_error_condition_enum<ErrorCondEnum>` must be true,
  `ErrorCondEnum` is not implicitly constructible to `value_type`, `error_type` nor `exception_type`, and is not `outcome<R, S, P>` and not `in_place_type<>`;
  Finally, the expression `error_type(make_error_code(ErrorCondEnum()))` must be valid.
  \throws Any exception the construction of `error_type(make_error_code(t))` might throw.
  */














  OUTCOME_TEMPLATE(class ErrorCondEnum)
  OUTCOME_TREQUIRES(OUTCOME_TEXPR(error_type(make_error_code(ErrorCondEnum()))), //
                    OUTCOME_TPRED(predicate::template enable_error_condition_converting_constructor<ErrorCondEnum>))
  constexpr basic_outcome(ErrorCondEnum &&t, error_condition_converting_constructor_tag /*unused*/ = error_condition_converting_constructor_tag()) noexcept(noexcept(error_type(make_error_code(static_cast<ErrorCondEnum &&>(t))))) // NOLINT
  : base{in_place_type<typename base::_error_type>, make_error_code(t)}
  {
    using namespace hooks;
    hook_outcome_construction(this, static_cast<ErrorCondEnum &&>(t));
  }
  /*! Converting constructor to an excepted outcome.
  \tparam 1
  \exclude
  \param 1
  \exclude
  \param t The value from which to initialise the `exception_type`.

  \effects Initialises the outcome with a `exception_type`.
  \requires Type T is implicitly constructible to `exception_type`,
  is not implicitly constructible to `value_type`, is not implicitly constructible to `error_type`, and is not `outcome<R, S, P>` and not `in_place_type<>`.
  \throws Any exception the construction of `exception_type(T)` might throw.
  */











  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_exception_converting_constructor<T>))
  constexpr basic_outcome(T &&t, exception_converting_constructor_tag /*unused*/ = exception_converting_constructor_tag()) noexcept(std::is_nothrow_constructible<exception_type, T>::value) // NOLINT
  : base(),
    _ptr(static_cast<T &&>(t))
  {
    using namespace hooks;
    this->_state._status |= detail::status_have_exception;
    hook_outcome_construction(this, static_cast<T &&>(t));
  }
  /*! Converting constructor to an errored + excepted outcome.
  \tparam 2
  \exclude
  \param 2
  \exclude
  \param a The value from which to initialise the `errot_type`.
  \param b The value from which to initialise the `exception_type`.

  \effects Initialises the outcome with `error_type` and `exception_type`.
  \requires Type T is implicitly constructible to `error_type`, type U is implicitly constructible to `exception_type`,
  neither is implicitly constructible to `value_type`, and is not `outcome<R, S, P>` and not `in_place_type<>`.
  \throws Any exception the construction of `error_type(T)` or `exception_type(U)` might throw.
  */












  OUTCOME_TEMPLATE(class T, class U)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(predicate::template enable_error_exception_converting_constructor<T, U>))
  constexpr basic_outcome(T &&a, U &&b, error_exception_converting_constructor_tag /*unused*/ = error_exception_converting_constructor_tag()) noexcept(std::is_nothrow_constructible<error_type, T>::value &&std::is_nothrow_constructible<exception_type, U>::value) // NOLINT
  : base{in_place_type<typename base::_error_type>, static_cast<T &&>(a)},
    _ptr(static_cast<U &&>(b))
  {
    using namespace hooks;
    this->_state._status |= detail::status_have_exception;
    hook_outcome_construction(this, static_cast<T &&>(a), static_cast<U &&>(b));
  }

  /*! Explicit converting constructor from a compatible `ValueOrError` type.
  \tparam 1
  \exclude
  \tparam 2
  \exclude
  \tparam 3
  \exclude
  \param 1
  \exclude
  \param o The input for which a `convert::value_or_error<outcome, std::decay_t<T>>{}(std::forward<T>(o))` is available.

  \effects Initialises the outcome with the contents of the compatible input.
  \requires That `convert::value_or_error<outcome, std::decay_t<T>>{}(std::forward<T>(o))` be available. The
  default implementation will consume `T`'s matching the `ValueOrError` concept type.
  `ValueOrError` concept matches any type with a `value_type`,
  an `error_type`, a `.value()`, an `.error()` and a `.has_value()`.
  */
















  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(convert::value_or_error<basic_outcome, std::decay_t<T>>::enable_result_inputs || !is_basic_result_v<T>), //
                    OUTCOME_TPRED(convert::value_or_error<basic_outcome, std::decay_t<T>>::enable_outcome_inputs || !is_basic_outcome_v<T>), //
                    OUTCOME_TEXPR(convert::value_or_error<basic_outcome, std::decay_t<T>>{}(std::declval<T>())))
  constexpr explicit basic_outcome(T &&o, explicit_valueorerror_converting_constructor_tag /*unused*/ = explicit_valueorerror_converting_constructor_tag()) // NOLINT
  : basic_outcome{convert::value_or_error<basic_outcome, std::decay_t<T>>{}(static_cast<T &&>(o))}
  {
  }
  /*! Explicit converting copy constructor from a compatible outcome type.
  \tparam 4
  \exclude
  \param o The compatible outcome.

  \effects Initialises the outcome with a copy of the compatible outcome.
  \requires Both outcome's `value_type`, `error_type`, and `exception_type` need to be constructible, or the source `void`.
  \throws Any exception the construction of `value_type(T)`, `error_type(U)` or `exception_type(V)` might throw.
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
  /*! Explicit converting move constructor from a compatible outcome type.
  \tparam 4
  \exclude
  \param o The compatible outcome.

  \effects Initialises the outcome with a move of the compatible outcome.
  \requires Both outcome's `value_type`, `error_type`, and `exception_type` need to be constructible, or the source `void`.
  \throws Any exception the construction of `value_type(T)`, `error_type(U)` or `exception_type(V)` might throw.
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
  /*! Explicit converting copy constructor from a compatible result type.
  \tparam 3
  \exclude
  \param o The compatible result.

  \effects Initialises the outcome with a copy of the compatible result.
  \requires Both outcome's `value_type` and `error_type` need to be constructible, or the source `void`.
  \throws Any exception the construction of `value_type(T)`, `error_type(U)` or `exception_type()` might throw.
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
  /*! Explicit converting move constructor from a compatible result type.
  \tparam 3
  \exclude
  \param o The compatible result.

  \effects Initialises the outcome with a move of the compatible result.
  \requires Both outcome's `value_type` and `error_type` need to be constructible, or the source `void`.
  \throws Any exception the construction of `value_type(T)`, `error_type(U)` or `exception_type()` might throw.
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
  constexpr explicit basic_outcome(in_place_type_t<value_type_if_enabled> _, Args &&... args) noexcept(std::is_nothrow_constructible<value_type, Args...>::value)
      : base{_, static_cast<Args &&>(args)...}
      , _ptr()
  {
    using namespace hooks;
    hook_outcome_in_place_construction(this, in_place_type<value_type>, static_cast<Args &&>(args)...);
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
  constexpr explicit basic_outcome(in_place_type_t<value_type_if_enabled> _, std::initializer_list<U> il, Args &&... args) noexcept(std::is_nothrow_constructible<value_type, std::initializer_list<U>, Args...>::value)
      : base{_, il, static_cast<Args &&>(args)...}
      , _ptr()
  {
    using namespace hooks;
    hook_outcome_in_place_construction(this, in_place_type<value_type>, il, static_cast<Args &&>(args)...);
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
  constexpr explicit basic_outcome(in_place_type_t<error_type_if_enabled> _, Args &&... args) noexcept(std::is_nothrow_constructible<error_type, Args...>::value)
      : base{_, static_cast<Args &&>(args)...}
      , _ptr()
  {
    using namespace hooks;
    hook_outcome_in_place_construction(this, in_place_type<error_type>, static_cast<Args &&>(args)...);
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
  constexpr explicit basic_outcome(in_place_type_t<error_type_if_enabled> _, std::initializer_list<U> il, Args &&... args) noexcept(std::is_nothrow_constructible<error_type, std::initializer_list<U>, Args...>::value)
      : base{_, il, static_cast<Args &&>(args)...}
      , _ptr()
  {
    using namespace hooks;
    hook_outcome_in_place_construction(this, in_place_type<error_type>, il, static_cast<Args &&>(args)...);
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
  constexpr explicit basic_outcome(in_place_type_t<exception_type_if_enabled> /*unused*/, Args &&... args) noexcept(std::is_nothrow_constructible<exception_type, Args...>::value)
      : base()
      , _ptr(static_cast<Args &&>(args)...)
  {
    using namespace hooks;
    this->_state._status |= detail::status_have_exception;
    hook_outcome_in_place_construction(this, in_place_type<exception_type>, static_cast<Args &&>(args)...);
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
  constexpr explicit basic_outcome(in_place_type_t<exception_type_if_enabled> /*unused*/, std::initializer_list<U> il, Args &&... args) noexcept(std::is_nothrow_constructible<exception_type, std::initializer_list<U>, Args...>::value)
      : base()
      , _ptr(il, static_cast<Args &&>(args)...)
  {
    using namespace hooks;
    this->_state._status |= detail::status_have_exception;
    hook_outcome_in_place_construction(this, in_place_type<exception_type>, il, static_cast<Args &&>(args)...);
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
  constexpr basic_outcome(A1 &&a1, A2 &&a2, Args &&... args) noexcept(noexcept(typename predicate::template choose_inplace_value_error_exception_constructor<A1, A2, Args...>(std::declval<A1>(), std::declval<A2>(), std::declval<Args>()...)))
      : basic_outcome(in_place_type<typename predicate::template choose_inplace_value_error_exception_constructor<A1, A2, Args...>>, static_cast<A1 &&>(a1), static_cast<A2 &&>(a2), static_cast<Args &&>(args)...)
  {
  }

  /// \output_section Tagged constructors
  /*! Implicit tagged constructor of a successful outcome.
  \param o The compatible success type sugar.

  \effects Initialises the outcome with a default constructed success type.
  \requires  `value_type` to be default constructible, or `void`.
  \throws Any exception the construction of `value_type()` might throw.
  */






  constexpr basic_outcome(const success_type<void> &o) noexcept(std::is_nothrow_default_constructible<value_type>::value) // NOLINT
  : base{in_place_type<typename base::_value_type>}
  {
    using namespace hooks;
    hook_outcome_copy_construction(this, o);
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
  constexpr basic_outcome(const success_type<T> &o) noexcept(std::is_nothrow_constructible<value_type, T>::value) // NOLINT
  : base{in_place_type<typename base::_value_type>, detail::extract_value_from_success<value_type>(o)}
  {
    using namespace hooks;
    hook_outcome_copy_construction(this, o);
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
  constexpr basic_outcome(success_type<T> &&o) noexcept(std::is_nothrow_constructible<value_type, T>::value) // NOLINT
  : base{in_place_type<typename base::_value_type>, detail::extract_value_from_success<value_type>(static_cast<success_type<T> &&>(o))}
  {
    using namespace hooks;
    hook_outcome_move_construction(this, static_cast<success_type<T> &&>(o));
  }

  /*! Implicit tagged constructor of a failure outcome.
  \tparam 1
  \exclude
  \param o The compatible failure type sugar.

  \effects Initialises the outcome with a copy of the error in the type sugar.
  \requires Outcome's `error_type` needs to be constructible from failure's `error_type`.
  \throws Any exception the construction of `error_type(T)` might throw.
  */








  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(!std::is_void<T>::value && predicate::template enable_compatible_conversion<void, T, void, void>))
  constexpr basic_outcome(const failure_type<T> &o, error_failure_tag /*unused*/ = error_failure_tag()) noexcept(std::is_nothrow_constructible<error_type, T>::value) // NOLINT
  : base{in_place_type<typename base::_error_type>, detail::extract_error_from_failure<error_type>(o)},
    _ptr()
  {
    using namespace hooks;
    hook_outcome_copy_construction(this, o);
  }
  /*! Implicit tagged constructor of a failure outcome.
  \tparam 1
  \exclude
  \param o The compatible failure type sugar.

  \effects Initialises the outcome with a copy of the exception in the type sugar.
  \requires Outcome's `exception_type` needs to be constructible from failure's `error_type`.
  \throws Any exception the construction of `exception_type(T)` might throw.
  */








  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(!std::is_void<T>::value && predicate::template enable_compatible_conversion<void, void, T, void>))
  constexpr basic_outcome(const failure_type<T> &o, exception_failure_tag /*unused*/ = exception_failure_tag()) noexcept(std::is_nothrow_constructible<exception_type, T>::value) // NOLINT
  : base(),
    _ptr(detail::extract_exception_from_failure<exception_type>(o))
  {
    this->_state._status |= detail::status_have_exception;
    using namespace hooks;
    hook_outcome_copy_construction(this, o);
  }
  /*! Implicit tagged constructor of a failure outcome.
  \tparam 2
  \exclude
  \param o The compatible failure type sugar.

  \effects Initialises the outcome with a copy of the error and exception in the type sugar.
  \requires Both outcome and failure's `error_type` and `exception_type` need to be constructible, or the source can be `void`.
  \throws Any exception the construction of `error_type(T)` and `exception_type(U)` might throw.
  */








  OUTCOME_TEMPLATE(class T, class U)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(!std::is_void<U>::value && predicate::template enable_compatible_conversion<void, T, U, void>))
  constexpr basic_outcome(const failure_type<T, U> &o) noexcept(std::is_nothrow_constructible<error_type, T>::value &&std::is_nothrow_constructible<exception_type, U>::value) // NOLINT
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

  /*! Implicit tagged constructor of a failure outcome.
  \tparam 1
  \exclude
  \param o The compatible failure type sugar.

  \effects Initialises the outcome with a move of the error in the type sugar.
  \requires Outcome's `error_type` needs to be constructible from failure's `error_type`.
  \throws Any exception the construction of `error_type(T)` might throw.
  */








  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(!std::is_void<T>::value && predicate::template enable_compatible_conversion<void, T, void, void>))
  constexpr basic_outcome(failure_type<T> &&o, error_failure_tag /*unused*/ = error_failure_tag()) noexcept(std::is_nothrow_constructible<error_type, T>::value) // NOLINT
  : base{in_place_type<typename base::_error_type>, detail::extract_error_from_failure<error_type>(static_cast<failure_type<T> &&>(o))},
    _ptr()
  {
    using namespace hooks;
    hook_outcome_copy_construction(this, o);
  }
  /*! Implicit tagged constructor of a failure outcome.
  \tparam 1
  \exclude
  \param o The compatible failure type sugar.

  \effects Initialises the outcome with a move of the exception in the type sugar.
  \requires Outcome's `exception_type` needs to be constructible from failure's `error_type`.
  \throws Any exception the construction of `exception_type(T)` might throw.
  */








  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(!std::is_void<T>::value && predicate::template enable_compatible_conversion<void, void, T, void>))
  constexpr basic_outcome(failure_type<T> &&o, exception_failure_tag /*unused*/ = exception_failure_tag()) noexcept(std::is_nothrow_constructible<exception_type, T>::value) // NOLINT
  : base(),
    _ptr(detail::extract_exception_from_failure<exception_type>(static_cast<failure_type<T> &&>(o)))
  {
    this->_state._status |= detail::status_have_exception;
    using namespace hooks;
    hook_outcome_copy_construction(this, o);
  }
  /*! Implicit tagged constructor of a failure outcome.
  \tparam 2
  \exclude
  \param o The compatible failure type sugar.

  \effects Initialises the outcome with a move of the error and exception in the type sugar.
  \requires Both outcome and failure's `error_type` and `exception_type` need to be constructible, or the source can be `void`.
  \throws Any exception the construction of `error_type(T)` and `exception_type(U)` might throw.
  */








  OUTCOME_TEMPLATE(class T, class U)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(!std::is_void<U>::value && predicate::template enable_compatible_conversion<void, T, U, void>))
  constexpr basic_outcome(failure_type<T, U> &&o) noexcept(std::is_nothrow_constructible<error_type, T>::value &&std::is_nothrow_constructible<exception_type, U>::value) // NOLINT
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

  /// \output_section Comparison operators
  using base::operator==;
  using base::operator!=;
  /*! True if equal to the other outcome.
  \param o The other outcome to compare to.

  \requires That both `value_type`'s have an `operator==` available;
  that both `error_type`'s have an `operator==` available;
  that both `exception_type`'s have an `operator==` available.
  \effects Calls the `operator==` operation on any common stored state.
  Otherwise returns false. Ignores spare storage.
  \throws Any exception the individual `operator==` operations might throw.
  */









  OUTCOME_TEMPLATE(class T, class U, class V, class W)
  OUTCOME_TREQUIRES(OUTCOME_TEXPR(std::declval<detail::devoid<value_type>>() == std::declval<detail::devoid<T>>()), //
                    OUTCOME_TEXPR(std::declval<detail::devoid<error_type>>() == std::declval<detail::devoid<U>>()), //
                    OUTCOME_TEXPR(std::declval<detail::devoid<exception_type>>() == std::declval<detail::devoid<V>>()))
  constexpr bool operator==(const basic_outcome<T, U, V, W> &o) const noexcept( //
  noexcept(std::declval<detail::devoid<value_type>>() == std::declval<detail::devoid<T>>()) //
  && noexcept(std::declval<detail::devoid<error_type>>() == std::declval<detail::devoid<U>>()) //
  && noexcept(std::declval<detail::devoid<exception_type>>() == std::declval<detail::devoid<V>>()))
  {
    if((this->_state._status & detail::status_have_value) != 0 && (o._state._status & detail::status_have_value) != 0)
    {
      return this->_state._value == o._state._value;
    }
    if((this->_state._status & detail::status_have_error) != 0 && (o._state._status & detail::status_have_error) != 0 //
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
  /*! True if equal to the failure type sugar.
  \param o The failure type sugar to compare to.

  \requires That both `error_type`'s have an `operator==` available;
  that both `exception_type`'s have an `operator==` available.
  \effects Calls the `operator==` operation on any common stored state.
  Otherwise returns false. Ignores spare storage.
  \throws Any exception the individual `operator==` operations might throw.
  */








  OUTCOME_TEMPLATE(class T, class U)
  OUTCOME_TREQUIRES(OUTCOME_TEXPR(std::declval<error_type>() == std::declval<T>()), //
                    OUTCOME_TEXPR(std::declval<exception_type>() == std::declval<U>()))
  constexpr bool operator==(const failure_type<T, U> &o) const noexcept( //
  noexcept(std::declval<error_type>() == std::declval<T>()) && noexcept(std::declval<exception_type>() == std::declval<U>()))
  {
    if((this->_state._status & detail::status_have_error) != 0 && (o._state._status & detail::status_have_error) != 0 //
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
  /*! True if not equal to the other outcome.
  \param o The other outcome to compare to.

  \requires That both `value_type`'s have an `operator!=` available;
  that both `error_type`'s have an `operator!=` available;
  that both `exception_type`'s have an `operator!=` available.
  \effects Calls the `operator!=` operation on any common stored state.
  Otherwise returns true. Ignores spare storage.
  \throws Any exception the individual `operator!=` operations might throw.
  */









  OUTCOME_TEMPLATE(class T, class U, class V, class W)
  OUTCOME_TREQUIRES(OUTCOME_TEXPR(std::declval<detail::devoid<value_type>>() != std::declval<detail::devoid<T>>()), //
                    OUTCOME_TEXPR(std::declval<detail::devoid<error_type>>() != std::declval<detail::devoid<U>>()), //
                    OUTCOME_TEXPR(std::declval<detail::devoid<exception_type>>() != std::declval<detail::devoid<V>>()))
  constexpr bool operator!=(const basic_outcome<T, U, V, W> &o) const noexcept( //
  noexcept(std::declval<detail::devoid<value_type>>() != std::declval<detail::devoid<T>>()) //
  && noexcept(std::declval<detail::devoid<error_type>>() != std::declval<detail::devoid<U>>()) //
  && noexcept(std::declval<detail::devoid<exception_type>>() != std::declval<detail::devoid<V>>()))
  {
    if((this->_state._status & detail::status_have_value) != 0 && (o._state._status & detail::status_have_value) != 0)
    {
      return this->_state._value != o._state._value;
    }
    if((this->_state._status & detail::status_have_error) != 0 && (o._state._status & detail::status_have_error) != 0 //
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
  /*! True if not equal to the failure type sugar.
  \param o The failure type sugar to compare to.

  \requires That both `error_type`'s have an `operator!=` available;
  that both `exception_type`'s have an `operator!=` available.
  \effects Calls the `operator!=` operation on any common stored state.
  Otherwise returns true. Ignores spare storage.
  \throws Any exception the individual `operator!=` operations might throw.
  */








  OUTCOME_TEMPLATE(class T, class U)
  OUTCOME_TREQUIRES(OUTCOME_TEXPR(std::declval<error_type>() != std::declval<T>()), //
                    OUTCOME_TEXPR(std::declval<exception_type>() != std::declval<U>()))
  constexpr bool operator!=(const failure_type<T, U> &o) const noexcept( //
  noexcept(std::declval<error_type>() == std::declval<T>()) && noexcept(std::declval<exception_type>() == std::declval<U>()))
  {
    if((this->_state._status & detail::status_have_error) != 0 && (o._state._status & detail::status_have_error) != 0 //
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

  /// \output_section Swap
  /*! Swaps this result with another result
  \effects Any `R` and/or `S` is swapped along with the metadata tracking them.
  \throws If the swap of value or error or exception can throw, the throwing swap is done first.
  If more than one of those can throw, the object is left in an indeterminate state should a throw occur.
  */




  void swap(basic_outcome &o) noexcept(detail::is_nothrow_swappable<value_type>::value &&std::is_nothrow_move_constructible<value_type>::value //
                                       &&detail::is_nothrow_swappable<error_type>::value &&std::is_nothrow_move_constructible<error_type>::value //
                                       &&detail::is_nothrow_swappable<exception_type>::value &&std::is_nothrow_move_constructible<exception_type>::value)
  {
    using std::swap;
    constexpr bool value_throws = !noexcept(this->_state.swap(o._state));
    constexpr bool error_throws = !noexcept(swap(this->_ptr, o._ptr));
    constexpr bool exception_throws = !noexcept(swap(this->_ptr, o._ptr));
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4127) // conditional expression is constant
#endif
    // Do throwing swap first
    if(value_throws && !error_throws && !exception_throws)
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
      this->_state.swap(o._state);
      swap(this->_error, o._error);
      swap(this->_ptr, o._ptr);
    }
#ifdef _MSC_VER
#pragma warning(pop)
#endif
  }

  /// \output_section Converters
  /*! Returns this outcome as a `failure_type` with any errored and/or excepted state copied.
  \requires This outcome to have a failed state, else whatever `assume_error()` would do.
  */


  failure_type<error_type, exception_type> as_failure() const &
  {
    if(this->has_error() && this->has_exception())
    {
      return failure_type<error_type, exception_type>(this->assume_error(), _ptr);
    }
    if(this->has_exception())
    {
      return failure_type<error_type, exception_type>(in_place_type<exception_type>, _ptr);
    }
    return failure_type<error_type, exception_type>(in_place_type<error_type>, this->assume_error());
  }

  /*! Returns this outcome as a `failure_type` with any errored and/or excepted state moved.
  \requires This outcome to have a failed state, else whatever `assume_error()` would do.
  */


  failure_type<error_type, exception_type> as_failure() &&
  {
    if(this->has_error() && this->has_exception())
    {
      return failure_type<error_type, exception_type>(static_cast<S &&>(this->assume_error()), static_cast<P &&>(_ptr));
    }
    if(this->has_exception())
    {
      return failure_type<error_type, exception_type>(in_place_type<exception_type>, static_cast<P &&>(_ptr));
    }
    return failure_type<error_type, exception_type>(in_place_type<error_type>, static_cast<S &&>(this->assume_error()));
  }
};

/*! True if the result is equal to the outcome
\tparam 7
\exclude
\param a The result to compare.
\param b The outcome to compare.

\remarks Implemented as `b == a`.
\requires That the expression `b == a` is a valid expression.
\throws Any exception that `b == a` might throw.
*/









OUTCOME_TEMPLATE(class T, class U, class V, //
                 class R, class S, class P, class N)
OUTCOME_TREQUIRES(OUTCOME_TEXPR(std::declval<basic_outcome<R, S, P, N>>() == std::declval<basic_result<T, U, V>>()))
constexpr inline bool operator==(const basic_result<T, U, V> &a, const basic_outcome<R, S, P, N> &b) noexcept( //
noexcept(std::declval<basic_outcome<R, S, P, N>>() == std::declval<basic_result<T, U, V>>()))
{
  return b == a;
}
/*! True if the result is not equal to the outcome
\tparam 7
\exclude
\param a The result to compare.
\param b The outcome to compare.

\remarks Implemented as `b != a`.
\requires That the expression `b != a` is a valid expression.
\throws Any exception that `b != a` might throw.
*/









OUTCOME_TEMPLATE(class T, class U, class V, //
                 class R, class S, class P, class N)
OUTCOME_TREQUIRES(OUTCOME_TEXPR(std::declval<basic_outcome<R, S, P, N>>() != std::declval<basic_result<T, U, V>>()))
constexpr inline bool operator!=(const basic_result<T, U, V> &a, const basic_outcome<R, S, P, N> &b) noexcept( //
noexcept(std::declval<basic_outcome<R, S, P, N>>() != std::declval<basic_result<T, U, V>>()))
{
  return b != a;
}
/*! Specialise swap for outcome.
\effects Calls `a.swap(b)`.
*/


template <class R, class S, class P, class N> inline void swap(basic_outcome<R, S, P, N> &a, basic_outcome<R, S, P, N> &b) noexcept(noexcept(a.swap(b)))
{
  a.swap(b);
}

namespace hooks
{
  /*! Used to set/override an exception during a construction hook implementation.
  \param o The outcome you wish to change.
  \param v Exception to be set.

  \effects Sets the exception of the outcome to the given value.
  */





  template <class R, class S, class P, class NoValuePolicy, class U> constexpr inline void override_outcome_exception(basic_outcome<R, S, P, NoValuePolicy> *o, U &&v) noexcept
  {
    o->_ptr = static_cast<U &&>(v);
    o->_state._status |= detail::status_have_exception;
  }
} // namespace hooks

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

namespace detail
{
  template <class Base, class R, class S, class P, class NoValuePolicy> inline constexpr typename basic_outcome_exception_observers<Base, R, S, P, NoValuePolicy>::exception_type &basic_outcome_exception_observers<Base, R, S, P, NoValuePolicy>::assume_exception() & noexcept
  {
    basic_outcome<R, S, P, NoValuePolicy> &self = static_cast<basic_outcome<R, S, P, NoValuePolicy> &>(*this); // NOLINT
    NoValuePolicy::narrow_exception_check(self);
    return self._ptr;
  }
  template <class Base, class R, class S, class P, class NoValuePolicy> inline constexpr const typename basic_outcome_exception_observers<Base, R, S, P, NoValuePolicy>::exception_type &basic_outcome_exception_observers<Base, R, S, P, NoValuePolicy>::assume_exception() const &noexcept
  {
    const basic_outcome<R, S, P, NoValuePolicy> &self = static_cast<const basic_outcome<R, S, P, NoValuePolicy> &>(*this); // NOLINT
    NoValuePolicy::narrow_exception_check(self);
    return self._ptr;
  }
  template <class Base, class R, class S, class P, class NoValuePolicy> inline constexpr typename basic_outcome_exception_observers<Base, R, S, P, NoValuePolicy>::exception_type &&basic_outcome_exception_observers<Base, R, S, P, NoValuePolicy>::assume_exception() && noexcept
  {
    basic_outcome<R, S, P, NoValuePolicy> &&self = static_cast<basic_outcome<R, S, P, NoValuePolicy> &&>(*this); // NOLINT
    NoValuePolicy::narrow_exception_check(self);
    return static_cast<P &&>(self._ptr);
  }
  template <class Base, class R, class S, class P, class NoValuePolicy> inline constexpr const typename basic_outcome_exception_observers<Base, R, S, P, NoValuePolicy>::exception_type &&basic_outcome_exception_observers<Base, R, S, P, NoValuePolicy>::assume_exception() const &&noexcept
  {
    const basic_outcome<R, S, P, NoValuePolicy> &&self = static_cast<const basic_outcome<R, S, P, NoValuePolicy> &&>(*this); // NOLINT
    NoValuePolicy::narrow_exception_check(self);
    return static_cast<P &&>(self._ptr);
  }

  template <class Base, class R, class S, class P, class NoValuePolicy> inline constexpr typename basic_outcome_exception_observers<Base, R, S, P, NoValuePolicy>::exception_type &basic_outcome_exception_observers<Base, R, S, P, NoValuePolicy>::exception() &
  {
    basic_outcome<R, S, P, NoValuePolicy> &self = static_cast<basic_outcome<R, S, P, NoValuePolicy> &>(*this); // NOLINT
    NoValuePolicy::wide_exception_check(self);
    return self._ptr;
  }
  template <class Base, class R, class S, class P, class NoValuePolicy> inline constexpr const typename basic_outcome_exception_observers<Base, R, S, P, NoValuePolicy>::exception_type &basic_outcome_exception_observers<Base, R, S, P, NoValuePolicy>::exception() const &
  {
    const basic_outcome<R, S, P, NoValuePolicy> &self = static_cast<const basic_outcome<R, S, P, NoValuePolicy> &>(*this); // NOLINT
    NoValuePolicy::wide_exception_check(self);
    return self._ptr;
  }
  template <class Base, class R, class S, class P, class NoValuePolicy> inline constexpr typename basic_outcome_exception_observers<Base, R, S, P, NoValuePolicy>::exception_type &&basic_outcome_exception_observers<Base, R, S, P, NoValuePolicy>::exception() &&
  {
    basic_outcome<R, S, P, NoValuePolicy> &&self = static_cast<basic_outcome<R, S, P, NoValuePolicy> &&>(*this); // NOLINT
    NoValuePolicy::wide_exception_check(self);
    return static_cast<P &&>(self._ptr);
  }
  template <class Base, class R, class S, class P, class NoValuePolicy> inline constexpr const typename basic_outcome_exception_observers<Base, R, S, P, NoValuePolicy>::exception_type &&basic_outcome_exception_observers<Base, R, S, P, NoValuePolicy>::exception() const &&
  {
    const basic_outcome<R, S, P, NoValuePolicy> &&self = static_cast<const basic_outcome<R, S, P, NoValuePolicy> &&>(*this); // NOLINT
    NoValuePolicy::wide_exception_check(self);
    return static_cast<P &&>(self._ptr);
  }
} // namespace detail

OUTCOME_V2_NAMESPACE_END

#endif
#endif
OUTCOME_V2_NAMESPACE_EXPORT_BEGIN

namespace detail
{
  namespace adl
  {
    inline std::exception_ptr basic_outcome_failure_exception_from_error(const std::error_code &ec, search_detail_adl /*unused*/) { return std::make_exception_ptr(std::system_error(ec)); }
  }
}

/*! `basic_outcome` defaulted to use `std::error_code`, `std::exception_ptr` and a `NoValuePolicy` appropriate for `std` types.

`NoValuePolicy` defaults to a policy selected according to the characteristics of types `S` and `P`:

1. If `.value()` called when there is no `value_type` but there is an `exception_type`:
   - If \verbatim {{<api "success_failure/#unexposed-entity-outcome-v2-xxx-trait-has-exception-ptr-v" "trait::has_exception_ptr_v<P>" >}} \end is true,
then `std::rethrow_exception(exception()|make_exception_ptr(exception()))`
[\verbatim {{<api "policies/outcome_exception_ptr_rethrow/" "policy::exception_ptr_rethrow<R, S, P>">}} \end]
2. If `.value()` called when there is no `value_type` but there is an `error_type`:
   - If \verbatim {{<api "success_failure/#unexposed-entity-outcome-v2-xxx-trait-has-error-code-v" "trait::has_error_code_v<S>" >}} \end is true,
then `throw std::system_error(error()|make_error_code(error()))`
[\verbatim {{<api "policies/outcome_error_code_throw_as_system_error/" "policy::error_code_throw_as_system_error<S>">}} \end]
   - If `trait::has_exception_ptr_v<S>`, then `std::rethrow_exception(error()|make_exception_ptr(error()))`
[\verbatim {{<api "policies/result_exception_ptr_rethrow/" "policy::exception_ptr_rethrow<R, S, void>">}} \end]
   - If `S` is `void`, call `std::terminate()` [\verbatim {{<api "policies/terminate/" "policy::terminate">}} \end]
   - If `S` is none of the above, then it is undefined behaviour [\verbatim {{<api "policies/all_narrow/" "policy::all_narrow">}} \end]
3. If `.exception()` called when there is no `exception_type`:
   - If `trait::has_exception_ptr_v<P>`,
or if `P` is `void`, do `throw bad_outcome_access()`
   - If `P` is none of the above, then it is undefined behaviour [`policy::all_narrow`]
4. If `.error()` called when there is no `error_type`:
   - If `trait::has_error_code_v<S>`, or if `trait::has_exception_ptr_v<S>`,
or if `S` is `void`, do `throw bad_outcome_access()`
   - If `S` is none of the above, then it is undefined behaviour [`policy::all_narrow`]
*/
























template <class R, class S = std::error_code, class P = std::exception_ptr, class NoValuePolicy = policy::default_policy<R, S, P>> //
using std_outcome = basic_outcome<R, S, P, NoValuePolicy>;

OUTCOME_V2_NAMESPACE_END
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























#ifndef OUTCOME_POLICY_OUTCOME_ERROR_CODE_THROW_AS_SYSTEM_ERROR_HPP
#define OUTCOME_POLICY_OUTCOME_ERROR_CODE_THROW_AS_SYSTEM_ERROR_HPP



OUTCOME_V2_NAMESPACE_EXPORT_BEGIN

namespace policy
{
  /*! Policy interpreting `EC` as a type for which `trait::has_error_code_v<EC>` is true.
  Any wide attempt to access the successful state where there is none causes
  an attempt to rethrow `E` if `trait::has_exception_ptr_v<E>` is true, else:

  1. If `trait::has_error_payload_v<EC>` is true, it calls an
  ADL discovered free function `outcome_throw_as_system_error_with_payload(.error())`.
  2. If `trait::has_error_payload_v<EC>` is false, it calls `OUTCOME_THROW_EXCEPTION(std::system_error(policy::error_code(.error())))`
  */







  template <class T, class EC, class E> struct error_code_throw_as_system_error : detail::base
  {
    /*! Performs a wide check of state, used in the value() functions.
    \effects See description of class for effects.
    */


    template <class Impl> static constexpr void wide_value_check(Impl &&self)
    {
      if((self._state._status & OUTCOME_V2_NAMESPACE::detail::status_have_value) == 0)
      {
        if((self._state._status & OUTCOME_V2_NAMESPACE::detail::status_have_exception) != 0)
        {
          using Outcome = OUTCOME_V2_NAMESPACE::detail::rebind_type<basic_outcome<T, EC, E, error_code_throw_as_system_error>, decltype(self)>;
          Outcome _self = static_cast<Outcome>(self); // NOLINT
          detail::_rethrow_exception<trait::has_exception_ptr_v<E>>{std::forward<Outcome>(_self)._ptr};
        }
        if((self._state._status & OUTCOME_V2_NAMESPACE::detail::status_have_error) != 0)
        {
          // ADL discovered
          outcome_throw_as_system_error_with_payload(std::forward<Impl>(self)._error);
        }
        OUTCOME_THROW_EXCEPTION(bad_outcome_access("no value"));
      }
    }
    /*! Performs a wide check of state, used in the error() functions
    \effects If result does not have an error, it throws `bad_outcome_access`.
    */


    template <class Impl> static constexpr void wide_error_check(Impl &&self)
    {
      if((self._state._status & OUTCOME_V2_NAMESPACE::detail::status_have_error) == 0)
      {
        OUTCOME_THROW_EXCEPTION(bad_outcome_access("no error"));
      }
    }
    /*! Performs a wide check of state, used in the exception() functions
    \effects If result does not have an exception, it throws `bad_outcome_access`.
    */


    template <class Impl> static constexpr void wide_exception_check(Impl &&self)
    {
      if((self._state._status & OUTCOME_V2_NAMESPACE::detail::status_have_exception) == 0)
      {
        OUTCOME_THROW_EXCEPTION(bad_outcome_access("no exception"));
      }
    }
  };
} // namespace policy

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























#ifndef OUTCOME_POLICY_OUTCOME_EXCEPTION_PTR_RETHROW_HPP
#define OUTCOME_POLICY_OUTCOME_EXCEPTION_PTR_RETHROW_HPP



OUTCOME_V2_NAMESPACE_EXPORT_BEGIN

namespace policy
{
  /*! Policy interpreting `EC` or `E` as a type for which `trait::has_exception_ptr_v<EC|E>` is true.
  Any wide attempt to access the successful state where there is none causes:
  `std::rethrow_exception(policy::exception_ptr(.error()|.exception()))` appropriately.
  */



  template <class T, class EC, class E> struct exception_ptr_rethrow : detail::base
  {
    /*! Performs a wide check of state, used in the value() functions
    \effects If outcome does not have a value, if it has an exception it rethrows that exception via `std::rethrow_exception()`,
    if it has an error it rethrows that error via `std::rethrow_exception()`, else it throws `bad_outcome_access`.
    */



    template <class Impl> static constexpr void wide_value_check(Impl &&self)
    {
      if((self._state._status & OUTCOME_V2_NAMESPACE::detail::status_have_value) == 0)
      {
        if((self._state._status & OUTCOME_V2_NAMESPACE::detail::status_have_exception) != 0)
        {
          using Outcome = OUTCOME_V2_NAMESPACE::detail::rebind_type<basic_outcome<T, EC, E, exception_ptr_rethrow>, decltype(self)>;
          Outcome _self = static_cast<Outcome>(self); // NOLINT
          detail::_rethrow_exception<trait::has_exception_ptr_v<E>>{std::forward<Outcome>(_self)._ptr};
        }
        if((self._state._status & OUTCOME_V2_NAMESPACE::detail::status_have_error) != 0)
        {
          detail::_rethrow_exception<trait::has_exception_ptr_v<EC>>{std::forward<Impl>(self)._error};
        }
        OUTCOME_THROW_EXCEPTION(bad_outcome_access("no value"));
      }
    }
    /*! Performs a wide check of state, used in the error() functions
    \effects If outcome does not have an error, it throws `bad_outcome_access`.
    */


    template <class Impl> static constexpr void wide_error_check(Impl &&self)
    {
      if((self._state._status & OUTCOME_V2_NAMESPACE::detail::status_have_error) == 0)
      {
        OUTCOME_THROW_EXCEPTION(bad_outcome_access("no error"));
      }
    }
    /*! Performs a wide check of state, used in the exception() functions
    \effects If result does not have an exception, it throws `bad_outcome_access`.
    */


    template <class Impl> static constexpr void wide_exception_check(Impl &&self)
    {
      if((self._state._status & OUTCOME_V2_NAMESPACE::detail::status_have_exception) == 0)
      {
        OUTCOME_THROW_EXCEPTION(bad_outcome_access("no exception"));
      }
    }
  };
} // namespace policy

OUTCOME_V2_NAMESPACE_END

#endif
#endif
OUTCOME_V2_NAMESPACE_EXPORT_BEGIN

/*! In standalone Outcome, this aliases `std_outcome<>`. In Boost.Outcome, this aliases `boost_outcome<>`.
*/

template <class R, class S = std::error_code, class P = std::exception_ptr, class NoValuePolicy = policy::default_policy<R, S, P>> //
using outcome = std_outcome<R, S, P, NoValuePolicy>;

OUTCOME_V2_NAMESPACE_END

#endif
#include <iostream>
#include <sstream>

OUTCOME_V2_NAMESPACE_BEGIN

namespace detail
{
  template <class T> typename std::add_lvalue_reference<T>::type lvalueref() noexcept;

  template <class T> inline std::ostream &operator<<(std::ostream &s, const value_storage_trivial<T> &v)
  {
    s << v._status << " ";
    if((v._status & status_have_value) != 0)
    {
      s << v._value; // NOLINT
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
      s << v._value; // NOLINT
    }
    return s;
  }
  template <class T> inline std::istream &operator>>(std::istream &s, value_storage_trivial<T> &v)
  {
    v = value_storage_trivial<T>();
    s >> v._status;
    if((v._status & status_have_value) != 0)
    {
      new(&v._value) decltype(v._value)(); // NOLINT
      s >> v._value; // NOLINT
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
      new(&v._value) decltype(v._value)(); // NOLINT
      s >> v._value; // NOLINT
    }
    return s;
  }
  OUTCOME_TEMPLATE(class T)
  OUTCOME_TREQUIRES(OUTCOME_TPRED(!std::is_constructible<std::error_code, T>::value))
  inline std::string safe_message(T && /*unused*/) { return {}; }
  inline std::string safe_message(const std::error_code &ec) { return " (" + ec.message() + ")"; }
} // namespace detail

/*! Deserialise a result. Format is `status_unsigned [value][error]`. Spare storage is preserved.
\tparam 3
\exclude
\tparam 4
\exclude

\requires That `R` and `S` implement `operator>>`.
*/







OUTCOME_TEMPLATE(class R, class S, class P)
OUTCOME_TREQUIRES(OUTCOME_TEXPR(detail::lvalueref<std::istream>() >> detail::lvalueref<R>()), OUTCOME_TEXPR(detail::lvalueref<std::istream>() >> detail::lvalueref<S>()))
inline std::istream &operator>>(std::istream &s, result<R, S, P> &v)
{
  s >> v._iostreams_state();
  if(v.has_error())
  {
    s >> v.assume_error();
  }
  return s;
}
/*! Serialise a result. Format is `status_unsigned [value][error]`. Spare storage is preserved.
If you are printing to a human readable destination, use `print()` instead.
\tparam 3
\exclude
\tparam 4
\exclude

\requires That `R` and `S` implement `operator<<`.
*/








OUTCOME_TEMPLATE(class R, class S, class P)
OUTCOME_TREQUIRES(OUTCOME_TEXPR(detail::lvalueref<std::ostream>() << detail::lvalueref<R>()), OUTCOME_TEXPR(detail::lvalueref<std::ostream>() << detail::lvalueref<S>()))
inline std::ostream &operator<<(std::ostream &s, const result<R, S, P> &v)
{
  s << v._iostreams_state();
  if(v.has_error())
  {
    s << v.assume_error();
  }
  return s;
}
/*! Debug print a result into a form suitable for human reading. Format is `value|error`. If the
error type is `error_code`, appends `" (ec.message())"` afterwards.
*/


template <class R, class S, class P> inline std::string print(const detail::basic_result_final<R, S, P> &v)
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
/*! Debug print a result into a form suitable for human reading. Format is `(+void)|error`. If the
error type is `error_code`, appends `" (ec.message())"` afterwards.
*/


template <class S, class P> inline std::string print(const detail::basic_result_final<void, S, P> &v)
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
/*! Debug print a result into a form suitable for human reading. Format is `value|(-void)`.
*/

template <class R, class P> inline std::string print(const detail::basic_result_final<R, void, P> &v)
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
/*! Debug print a result into a form suitable for human reading. Format is `(+void)|(-void)`.
*/

template <class P> inline std::string print(const detail::basic_result_final<void, void, P> &v)
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

/*! Deserialise an outcome. Format is `status_unsigned [value][error][exception]`. Spare storage is preserved.
\tparam 4
\exclude
\tparam 5
\exclude
\tparam 6
\exclude

\requires That `R`, `S` and `P` implement `operator>>`.
*/









OUTCOME_TEMPLATE(class R, class S, class P, class N)
OUTCOME_TREQUIRES(OUTCOME_TEXPR(detail::lvalueref<std::istream>() >> detail::lvalueref<R>()), OUTCOME_TEXPR(detail::lvalueref<std::istream>() >> detail::lvalueref<S>()), OUTCOME_TEXPR(detail::lvalueref<std::istream>() >> detail::lvalueref<P>()))
inline std::istream &operator>>(std::istream &s, outcome<R, S, P, N> &v)
{
  s >> v._iostreams_state();
  if(v.has_error())
  {
    s >> v.assume_error();
  }
  if(v.has_exception())
  {
    s >> v.assume_exception();
  }
  return s;
}
/*! Serialise an outcome. Format is `status_unsigned [value][error][exception]`. Spare storage is preserved.
If you are printing to a human readable destination, use `print()` instead.
\tparam 4
\exclude
\tparam 5
\exclude
\tparam 6
\exclude

\requires That `R`, `S` and `P` implement `operator<<`.
*/










OUTCOME_TEMPLATE(class R, class S, class P, class N)
OUTCOME_TREQUIRES(OUTCOME_TEXPR(detail::lvalueref<std::ostream>() << detail::lvalueref<R>()), OUTCOME_TEXPR(detail::lvalueref<std::ostream>() << detail::lvalueref<S>()), OUTCOME_TEXPR(detail::lvalueref<std::ostream>() << detail::lvalueref<P>()))
inline std::ostream &operator<<(std::ostream &s, const outcome<R, S, P, N> &v)
{
  s << v._iostreams_state();
  if(v.has_error())
  {
    s << v.assume_error();
  }
  if(v.has_exception())
  {
    s << v.assume_exception();
  }
  return s;
}
/*! Debug print an outcome into a form suitable for human reading. Format is one of:

1. `value|error|exception`
2. `{ error, exception }`

If the error type is `error_code`, appends `" (ec.message())"` after the error.
Exception type is printed as one of:

1. `std::system_error code code(): what()`
2. `std::exception: what()`
3. `unknown exception`
*/











template <class R, class S, class P, class N> inline std::string print(const outcome<R, S, P, N> &v)
{
  std::stringstream s;
  int total = static_cast<int>(v.has_value()) + static_cast<int>(v.has_error()) + static_cast<int>(v.has_exception());
  if(total > 1)
  {
    s << "{ ";
  }
  s << print(static_cast<const detail::basic_result_final<R, S, N> &>(v));
  if(total > 1)
  {
    s << ", ";
  }
  if(v.has_exception())
  {
#ifdef __cpp_exceptions
    try
    {
      rethrow_exception(v.exception());
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



namespace std
{
  namespace experimental
  {
    template <class T, class E> class expected;
    template <class E> class unexpected;
  } // namespace experimental
} // namespace std

OUTCOME_V2_NAMESPACE_BEGIN

/*! Customisation point for changing what the `OUTCOME_TRY` macros
do. This function defaults to returning `std::forward<T>(v).as_failure()`.
\effects Extracts any state apart from value into a `failure_type`.
\requires The input value to have a `.as_failure()` member function.
*/




OUTCOME_TEMPLATE(class T)
OUTCOME_TREQUIRES(OUTCOME_TEXPR(std::declval<T>().as_failure()))
inline decltype(auto) try_operation_return_as(T &&v)
{
  return static_cast<T &&>(v).as_failure();
}
/*! Customisation point for changing what the `OUTCOME_TRY` macros do.
\effects Returns by copy a `std::experimental::unexpected<E>` from an input `std::experimental::expected<T, E>`.
*/


template <class T, class E> inline auto try_operation_return_as(const std::experimental::expected<T, E> &v)
{
  return std::experimental::unexpected<E>(v.error());
}
/*! Customisation point for changing what the `OUTCOME_TRY` macros do.
\effects Returns by move a `std::experimental::unexpected<E>` from an input `std::experimental::expected<T, E>`.
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
} // namespace detail

OUTCOME_V2_NAMESPACE_END

//! \exclude
#define OUTCOME_TRY_GLUE2(x, y) x##y
//! \exclude
#define OUTCOME_TRY_GLUE(x, y) OUTCOME_TRY_GLUE2(x, y)
//! \exclude
#define OUTCOME_TRY_UNIQUE_NAME OUTCOME_TRY_GLUE(_outcome_try_unique_name_temporary, __COUNTER__)

//! \exclude
#define OUTCOME_TRY_RETURN_ARG_COUNT(_1_, _2_, _3_, _4_, _5_, _6_, _7_, _8_, count, ...) count
//! \exclude
#define OUTCOME_TRY_EXPAND_ARGS(args) OUTCOME_TRY_RETURN_ARG_COUNT args
//! \exclude
#define OUTCOME_TRY_COUNT_ARGS_MAX8(...) OUTCOME_TRY_EXPAND_ARGS((__VA_ARGS__, 8, 7, 6, 5, 4, 3, 2, 1, 0))
//! \exclude
#define OUTCOME_TRY_OVERLOAD_MACRO2(name, count) name##count
//! \exclude
#define OUTCOME_TRY_OVERLOAD_MACRO1(name, count) OUTCOME_TRY_OVERLOAD_MACRO2(name, count)
//! \exclude
#define OUTCOME_TRY_OVERLOAD_MACRO(name, count) OUTCOME_TRY_OVERLOAD_MACRO1(name, count)
//! \exclude
#define OUTCOME_TRY_OVERLOAD_GLUE(x, y) x y
//! \exclude
#define OUTCOME_TRY_CALL_OVERLOAD(name, ...) OUTCOME_TRY_OVERLOAD_GLUE(OUTCOME_TRY_OVERLOAD_MACRO(name, OUTCOME_TRY_COUNT_ARGS_MAX8(__VA_ARGS__)), (__VA_ARGS__))


//! \exclude
#define OUTCOME_TRYV2(unique, ...) auto && (unique) = (__VA_ARGS__); if(!(unique).has_value()) return OUTCOME_V2_NAMESPACE::try_operation_return_as(static_cast<decltype(unique) &&>(unique))



//! \exclude
#define OUTCOME_TRY2(unique, v, ...) OUTCOME_TRYV2(unique, __VA_ARGS__); auto && (v) = OUTCOME_V2_NAMESPACE::detail::try_extract_value(static_cast<decltype(unique) &&>(unique))



/*! If the `outcome`/`result`/`std::experimental::expected` returned by expression ... is not valued, propagate any
failure by immediately returning that failure state immediately
*/


#define OUTCOME_TRYV(...) OUTCOME_TRYV2(OUTCOME_TRY_UNIQUE_NAME, __VA_ARGS__)

#if defined(__GNUC__) || defined(__clang__)

/*! If the `outcome`/`result`/`std::experimental::expected` returned by expression ... is not valued, propagate any
failure by immediately returning that failure state immediately, else become the
unwrapped value as an expression. This makes `OUTCOME_TRYX(expr)` an expression
which can be used exactly like the `try` operator in other languages.

\remarks This macro makes use of a proprietary extension in GCC and clang and is not
portable. The macro is not made available on unsupported compilers,
so you can test for its presence using `#ifdef OUTCOME_TRYX`.
*/








#define OUTCOME_TRYX(...) ({ auto &&res = (__VA_ARGS__); if(!res.has_value()) return OUTCOME_V2_NAMESPACE::try_operation_return_as(static_cast<decltype(res) &&>(res)); OUTCOME_V2_NAMESPACE::detail::try_extract_value(static_cast<decltype(res) &&>(res)); })







#endif

/*! If the `outcome`/`result`/`std::experimental::expected` returned by expression ... is not valued, propagate any
failure by immediately returning that failure immediately, else set *auto &&v* to the unwrapped value.
*/


#define OUTCOME_TRYA(v, ...) OUTCOME_TRY2(OUTCOME_TRY_UNIQUE_NAME, v, __VA_ARGS__)

//! \exclude
#define OUTCOME_TRY_INVOKE_TRY8(a, b, c, d, e, f, g, h) OUTCOME_TRYA(a, b, c, d, e, f, g, h)
//! \exclude
#define OUTCOME_TRY_INVOKE_TRY7(a, b, c, d, e, f, g) OUTCOME_TRYA(a, b, c, d, e, f, g)
//! \exclude
#define OUTCOME_TRY_INVOKE_TRY6(a, b, c, d, e, f) OUTCOME_TRYA(a, b, c, d, e, f)
//! \exclude
#define OUTCOME_TRY_INVOKE_TRY5(a, b, c, d, e) OUTCOME_TRYA(a, b, c, d, e)
//! \exclude
#define OUTCOME_TRY_INVOKE_TRY4(a, b, c, d) OUTCOME_TRYA(a, b, c, d)
//! \exclude
#define OUTCOME_TRY_INVOKE_TRY3(a, b, c) OUTCOME_TRYA(a, b, c)
//! \exclude
#define OUTCOME_TRY_INVOKE_TRY2(a, b) OUTCOME_TRYA(a, b)
//! \exclude
#define OUTCOME_TRY_INVOKE_TRY1(a) OUTCOME_TRYV(a)
/*! This uses C macro overloading to select between `OUTCOME_TRYV(...)` and `OUTCOME_TRYA(v, ...)`
based on whether there is one or two or more arguments to the macro.

It can surprise people as template parameters are not recognised by the C preprocessor. For example:

```c++
OUTCOME_TRY(foo<int, long>());
```

Here the programmer obviously intends this to be an `OUTCOME_TRYV(...)`, but the C macro overload
mechanism will perceive this as setting the variable `foo<int,` to the result of the function call
`long>()`. This will fail to compile.

One solution is to simply wrap all function calls with brackets so the C preprocessor breaks
them correctly e.g.

```c++
OUTCOME_TRY((foo<int, long>()));
OUTCOME_TRY(foovalue, (foo<int, long>()));
```

This solution also avoids ever exceeding eight C macro input parameters, as overloading is
only implemented up to eight parameters.

The other solution is to call `OUTCOME_TRYV` or `OUTCOME_TRYA` directly as appropriate.
*/

























#define OUTCOME_TRY(...) OUTCOME_TRY_CALL_OVERLOAD(OUTCOME_TRY_INVOKE_TRY, __VA_ARGS__)

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























#ifndef OUTCOME_UTILS_HPP
#define OUTCOME_UTILS_HPP



#include <exception>
#include <system_error>

OUTCOME_V2_NAMESPACE_BEGIN

#ifdef __cpp_exceptions
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

/*! Utility function which tries to throw the equivalent STL exception type for
some given error code, not including `system_error`.
\param ec The error code to try to convert into a STL exception throw.
\param msg Optional custom message for the STL exception type.

\effects If the input error code has a category of `generic_category()` (all platforms)
or `system_category()` (POSIX only), throw the STL exception type matching
the `errno` domained code if one is available. For example, `ENOMEM` would cause
`std::bad_alloc()` to be thrown.
*/









inline void try_throw_std_exception_from_error(std::error_code ec, const std::string &msg = std::string{})
{
  if(!ec || (ec.category() != std::generic_category()
#ifndef _WIN32
             && ec.category() != std::system_category()
#endif
             ))
  {
    return;
  }
  switch(ec.value())
  {
  case EINVAL:
    throw msg.empty() ? std::invalid_argument("invalid argument") : std::invalid_argument(msg);
  case EDOM:
    throw msg.empty() ? std::domain_error("domain error") : std::domain_error(msg);
  case E2BIG:
    throw msg.empty() ? std::length_error("length error") : std::length_error(msg);
  case ERANGE:
    throw msg.empty() ? std::out_of_range("out of range") : std::out_of_range(msg);
  case EOVERFLOW:
    throw msg.empty() ? std::overflow_error("overflow error") : std::overflow_error(msg);
  case ENOMEM:
    throw std::bad_alloc();
  }
}
#endif

OUTCOME_V2_NAMESPACE_END

#endif
