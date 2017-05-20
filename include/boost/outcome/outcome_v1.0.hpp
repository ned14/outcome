
#define BOOST_OUTCOME_VERSION_MAJOR 1

#define BOOST_OUTCOME_VERSION_MINOR 0

#define BOOST_OUTCOME_VERSION_PATCH 0

#define BOOST_OUTCOME_VERSION_REVISION 0



#define BOOST_OUTCOME_UNSTABLE_VERSION

#define BOOST_OUTCOME_VERSION_GLUE2(a, b, c) a ## b ## c
#define BOOST_OUTCOME_VERSION_GLUE(a, b, c) BOOST_OUTCOME_VERSION_GLUE2(a, b, c)

#if defined(_MSC_VER) && !defined(__clang__)
#define BOOST_OUTCOME_HEADERS_VERSION BOOST_OUTCOME_VERSION_GLUE(BOOST_OUTCOME_VERSION_MAJOR, ., BOOST_OUTCOME_VERSION_MINOR)
#elif 1
#define BOOST_OUTCOME_HEADERS_VERSION BOOST_OUTCOME_VERSION_MAJOR.BOOST_OUTCOME_VERSION_MINOR
#endif

#define BOOST_OUTCOME_NAMESPACE_VERSION BOOST_OUTCOME_VERSION_GLUE(BOOST_OUTCOME_VERSION_MAJOR, _, BOOST_OUTCOME_VERSION_MINOR)
#undef BOOST_OUTCOME_HEADERS_PATH
#undef BOOST_OUTCOME_HEADERS_PATH2
#define BOOST_OUTCOME_HEADERS_PATH4(a) #a
#define BOOST_OUTCOME_HEADERS_PATH3(a) BOOST_OUTCOME_HEADERS_PATH4(a)






















#if defined(_MSC_VER) && !defined(__clang__)
#define BOOST_OUTCOME_HEADERS_PATH2 BOOST_OUTCOME_VERSION_GLUE(v, BOOST_OUTCOME_HEADERS_VERSION, /monad.hpp)
#elif 1
#define BOOST_OUTCOME_HEADERS_PATH2 BOOST_OUTCOME_VERSION_GLUE(v, BOOST_OUTCOME_HEADERS_VERSION,)/monad.hpp
#endif

#define BOOST_OUTCOME_HEADERS_PATH4(a) #a
#define BOOST_OUTCOME_HEADERS_PATH3(a) BOOST_OUTCOME_HEADERS_PATH4(a)

#define BOOST_OUTCOME_HEADERS_PATH BOOST_OUTCOME_HEADERS_PATH3(BOOST_OUTCOME_HEADERS_PATH2)
#ifndef BOOST_OUTCOME_MONAD_HPP
#define BOOST_OUTCOME_MONAD_HPP

































#define BOOST_OUTCOME_INCLUDE_ALL
#ifndef BOOST_OUTCOME_CONFIG_HPP
#define BOOST_OUTCOME_CONFIG_HPP
#ifndef BOOSTLITE_CONFIG_HPP
#define BOOSTLITE_CONFIG_HPP
#define BOOSTLITE_PREVIOUS_COMMIT_REF ed8678b7b2c17f1064301e3f713a6593fe91f7f1
#define BOOSTLITE_PREVIOUS_COMMIT_DATE "2017-05-03 00:05:42 +00:00"
#define BOOSTLITE_PREVIOUS_COMMIT_UNIQUE ed8678b7
#ifndef BOOSTLITE_HAS_FEATURE_H
#define BOOSTLITE_HAS_FEATURE_H

#if __cplusplus >= 201103























































#if !defined(__cpp_alias_templates)
#define __cpp_alias_templates 190000
#endif

#if !defined(__cpp_attributes)
#define __cpp_attributes 190000
#endif

#if !defined(__cpp_constexpr)
#if __cplusplus >= 201402
#define __cpp_constexpr 201304
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

#if !defined(__cpp_explicit_conversion)
#define __cpp_explicit_conversion 190000
#endif

#if !defined(__cpp_inheriting_constructors)
#define __cpp_inheriting_constructors 190000
#endif

#if !defined(__cpp_initializer_lists)
#define __cpp_initializer_lists 190000
#endif

#if !defined(__cpp_lambdas)
#define __cpp_lambdas 190000
#endif

#if !defined(__cpp_nsdmi)
#define __cpp_nsdmi 190000
#endif

#if !defined(__cpp_range_based_for)
#define __cpp_range_based_for 190000
#endif

#if !defined(__cpp_raw_strings)
#define __cpp_raw_strings 190000
#endif

#if !defined(__cpp_ref_qualifiers)
#define __cpp_ref_qualifiers 190000
#endif

#if !defined(__cpp_rvalue_references)
#define __cpp_rvalue_references 190000
#endif

#if !defined(__cpp_static_assert)
#define __cpp_static_assert 190000
#endif

#if !defined(__cpp_unicode_characters)
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







#if defined(_MSC_VER) && !defined(__clang__)

#if !defined(__cpp_exceptions) && defined(_CPPUNWIND)
#define __cpp_exceptions 190000
#endif

#if !defined(__cpp_rtti) && defined(_CPPRTTI)
#define __cpp_rtti 190000
#endif




#if !defined(__cpp_alias_templates) && _MSC_VER >= 1800
#define __cpp_alias_templates 190000
#endif

#if !defined(__cpp_attributes)
#define __cpp_attributes 190000
#endif

#if !defined(__cpp_constexpr) && _MSC_FULL_VER >= 190023506
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





#if !defined(__cpp_user_defined_literals) && _MSC_VER >= 1900
#define __cpp_user_defined_literals 190000
#endif

#if !defined(__cpp_variadic_templates) && _MSC_VER >= 1800
#define __cpp_variadic_templates 190000
#endif








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

#endif



#if (defined(__GNUC__) && !defined(__clang__))

#define BOOSTLITE_GCC (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 + __GNUC_PATCHLEVEL__)

#if !defined(__cpp_exceptions) && defined(__EXCEPTIONS)
#define __cpp_exceptions 190000
#endif

#if !defined(__cpp_rtti) && defined(__GXX_RTTI)
#define __cpp_rtti 190000
#endif



#if defined(__GXX_EXPERIMENTAL_CXX0X__)

#if !defined(__cpp_alias_templates) && (BOOSTLITE_GCC >= 40700)
#define __cpp_alias_templates 190000
#endif

#if !defined(__cpp_attributes) && (BOOSTLITE_GCC >= 40800)
#define __cpp_attributes 190000
#endif

#if !defined(__cpp_constexpr) && (BOOSTLITE_GCC >= 40600)
#define __cpp_constexpr 190000
#endif

#if !defined(__cpp_decltype) && (BOOSTLITE_GCC >= 40300)
#define __cpp_decltype 190000
#endif

#if !defined(__cpp_delegating_constructors) && (BOOSTLITE_GCC >= 40700)
#define __cpp_delegating_constructors 190000
#endif

#if !defined(__cpp_explicit_conversion) && (BOOSTLITE_GCC >= 40500)
#define __cpp_explicit_conversion 190000
#endif

#if !defined(__cpp_inheriting_constructors) && (BOOSTLITE_GCC >= 40800)
#define __cpp_inheriting_constructors 190000
#endif

#if !defined(__cpp_initializer_lists) && (BOOSTLITE_GCC >= 40800)
#define __cpp_initializer_lists 190000
#endif

#if !defined(__cpp_lambdas) && (BOOSTLITE_GCC >= 40500)
#define __cpp_lambdas 190000
#endif

#if !defined(__cpp_nsdmi) && (BOOSTLITE_GCC >= 40700)
#define __cpp_nsdmi 190000
#endif

#if !defined(__cpp_range_based_for) && (BOOSTLITE_GCC >= 40600)
#define __cpp_range_based_for 190000
#endif

#if !defined(__cpp_raw_strings) && (BOOSTLITE_GCC >= 40500)
#define __cpp_raw_strings 190000
#endif

#if !defined(__cpp_ref_qualifiers) && (BOOSTLITE_GCC >= 40801)
#define __cpp_ref_qualifiers 190000
#endif


#if !defined(__cpp_rvalue_references) && defined(__cpp_rvalue_reference)
#define __cpp_rvalue_references __cpp_rvalue_reference
#endif

#if !defined(__cpp_static_assert) && (BOOSTLITE_GCC >= 40300)
#define __cpp_static_assert 190000
#endif

#if !defined(__cpp_unicode_characters) && (BOOSTLITE_GCC >= 40500)
#define __cpp_unicode_characters 190000
#endif

#if !defined(__cpp_unicode_literals) && (BOOSTLITE_GCC >= 40500)
#define __cpp_unicode_literals 190000
#endif

#if !defined(__cpp_user_defined_literals) && (BOOSTLITE_GCC >= 40700)
#define __cpp_user_defined_literals 190000
#endif

#if !defined(__cpp_variadic_templates) && (BOOSTLITE_GCC >= 40400)
#define __cpp_variadic_templates 190000
#endif





#endif

#endif




#if defined(__clang__)

#define BOOSTLITE_CLANG (__clang_major__ * 10000 + __clang_minor__ * 100 + __clang_patchlevel__)

#if !defined(__cpp_exceptions) && (defined(__EXCEPTIONS) || defined(_CPPUNWIND))
#define __cpp_exceptions 190000
#endif

#if !defined(__cpp_rtti) && (defined(__GXX_RTTI) || defined(_CPPRTTI))
#define __cpp_rtti 190000
#endif



#if defined(__GXX_EXPERIMENTAL_CXX0X__)

#if !defined(__cpp_alias_templates) && (BOOSTLITE_CLANG >= 30000)
#define __cpp_alias_templates 190000
#endif

#if !defined(__cpp_attributes) && (BOOSTLITE_CLANG >= 30300)
#define __cpp_attributes 190000
#endif

#if !defined(__cpp_constexpr) && (BOOSTLITE_CLANG >= 30100)
#define __cpp_constexpr 190000
#endif

#if !defined(__cpp_decltype) && (BOOSTLITE_CLANG >= 20900)
#define __cpp_decltype 190000
#endif

#if !defined(__cpp_delegating_constructors) && (BOOSTLITE_CLANG >= 30000)
#define __cpp_delegating_constructors 190000
#endif

#if !defined(__cpp_explicit_conversion) && (BOOSTLITE_CLANG >= 30000)
#define __cpp_explicit_conversion 190000
#endif

#if !defined(__cpp_inheriting_constructors) && (BOOSTLITE_CLANG >= 30300)
#define __cpp_inheriting_constructors 190000
#endif

#if !defined(__cpp_initializer_lists) && (BOOSTLITE_CLANG >= 30100)
#define __cpp_initializer_lists 190000
#endif

#if !defined(__cpp_lambdas) && (BOOSTLITE_CLANG >= 30100)
#define __cpp_lambdas 190000
#endif

#if !defined(__cpp_nsdmi) && (BOOSTLITE_CLANG >= 30000)
#define __cpp_nsdmi 190000
#endif

#if !defined(__cpp_range_based_for) && (BOOSTLITE_CLANG >= 30000)
#define __cpp_range_based_for 190000
#endif


#if !defined(__cpp_raw_strings) && defined(__cpp_raw_string_literals)
#define __cpp_raw_strings __cpp_raw_string_literals
#endif
#if !defined(__cpp_raw_strings) && (BOOSTLITE_CLANG >= 30000)
#define __cpp_raw_strings 190000
#endif

#if !defined(__cpp_ref_qualifiers) && (BOOSTLITE_CLANG >= 20900)
#define __cpp_ref_qualifiers 190000
#endif


#if !defined(__cpp_rvalue_references) && defined(__cpp_rvalue_reference)
#define __cpp_rvalue_references __cpp_rvalue_reference
#endif
#if !defined(__cpp_rvalue_references) && (BOOSTLITE_CLANG >= 20900)
#define __cpp_rvalue_references 190000
#endif

#if !defined(__cpp_static_assert) && (BOOSTLITE_CLANG >= 20900)
#define __cpp_static_assert 190000
#endif

#if !defined(__cpp_unicode_characters) && (BOOSTLITE_CLANG >= 30000)
#define __cpp_unicode_characters 190000
#endif

#if !defined(__cpp_unicode_literals) && (BOOSTLITE_CLANG >= 30000)
#define __cpp_unicode_literals 190000
#endif


#if !defined(__cpp_user_defined_literals) && defined(__cpp_user_literals)
#define __cpp_user_defined_literals __cpp_user_literals
#endif
#if !defined(__cpp_user_defined_literals) && (BOOSTLITE_CLANG >= 30100)
#define __cpp_user_defined_literals 190000
#endif

#if !defined(__cpp_variadic_templates) && (BOOSTLITE_CLANG >= 20900)
#define __cpp_variadic_templates 190000
#endif





#endif

#endif

#endif
#define BOOSTLITE_VERSION_GLUE2(a, b) a##b
#define BOOSTLITE_VERSION_GLUE(a, b) BOOSTLITE_VERSION_GLUE2(a, b)















#define BOOSTLITE_NAMESPACE boost_lite::BOOSTLITE_VERSION_GLUE(_, BOOSTLITE_PREVIOUS_COMMIT_UNIQUE)
#define BOOSTLITE_NAMESPACE_BEGIN namespace boost_lite { inline namespace BOOSTLITE_VERSION_GLUE(_, BOOSTLITE_PREVIOUS_COMMIT_UNIQUE) {
#define BOOSTLITE_NAMESPACE_END } }



#ifdef _MSC_VER
#define BOOSTLITE_BIND_MESSAGE_PRAGMA2(x) __pragma(message(x))
#define BOOSTLITE_BIND_MESSAGE_PRAGMA(x) BOOSTLITE_BIND_MESSAGE_PRAGMA2(x)
#define BOOSTLITE_BIND_MESSAGE_PREFIX(type) __FILE__ "(" BOOSTLITE_BIND_STRINGIZE2(__LINE__) "): " type ": "
#define BOOSTLITE_BIND_MESSAGE_(type, prefix, msg) BOOSTLITE_BIND_MESSAGE_PRAGMA(prefix msg)
#else
#define BOOSTLITE_BIND_MESSAGE_PRAGMA2(x) _Pragma(#x)
#define BOOSTLITE_BIND_MESSAGE_PRAGMA(type, x) BOOSTLITE_BIND_MESSAGE_PRAGMA2(type x)
#define BOOSTLITE_BIND_MESSAGE_(type, prefix, msg) BOOSTLITE_BIND_MESSAGE_PRAGMA(type, msg)
#endif

#define BOOSTLITE_MESSAGE(msg) BOOSTLITE_BIND_MESSAGE_(message, BOOSTLITE_BIND_MESSAGE_PREFIX("message"), msg)

#define BOOSTLITE_NOTE(msg) BOOSTLITE_BIND_MESSAGE_(message, BOOSTLITE_BIND_MESSAGE_PREFIX("note"), msg)

#define BOOSTLITE_WARNING(msg) BOOSTLITE_BIND_MESSAGE_(GCC warning, BOOSTLITE_BIND_MESSAGE_PREFIX("warning"), msg)

#define BOOSTLITE_ERROR(msg) BOOSTLITE_BIND_MESSAGE_(GCC error, BOOSTLITE_BIND_MESSAGE_PREFIX("error"), msg)
















#define BOOSTLITE_ANNOTATE_RWLOCK_CREATE(p)
#define BOOSTLITE_ANNOTATE_RWLOCK_DESTROY(p)
#define BOOSTLITE_ANNOTATE_RWLOCK_ACQUIRED(p, s)
#define BOOSTLITE_ANNOTATE_RWLOCK_RELEASED(p, s)
#define BOOSTLITE_ANNOTATE_IGNORE_READS_BEGIN()
#define BOOSTLITE_ANNOTATE_IGNORE_READS_END()
#define BOOSTLITE_ANNOTATE_IGNORE_WRITES_BEGIN()
#define BOOSTLITE_ANNOTATE_IGNORE_WRITES_END()
#define BOOSTLITE_DRD_IGNORE_VAR(x)
#define BOOSTLITE_DRD_STOP_IGNORING_VAR(x)
#define BOOSTLITE_RUNNING_ON_VALGRIND (0)


#ifndef BOOSTLITE_IN_THREAD_SANITIZER
#if defined(__has_feature)
#if __has_feature(thread_sanitizer)
#define BOOSTLITE_IN_THREAD_SANITIZER 1
#endif
#elif defined(__SANITIZE_ADDRESS__)
#define BOOSTLITE_IN_THREAD_SANITIZER 1
#endif
#endif
#ifndef BOOSTLITE_IN_THREAD_SANITIZER
#define BOOSTLITE_IN_THREAD_SANITIZER 0
#endif

#if BOOSTLITE_IN_THREAD_SANITIZER
#define BOOSTLITE_DISABLE_THREAD_SANITIZE __attribute__((no_sanitize_thread))
#else
#define BOOSTLITE_DISABLE_THREAD_SANITIZE
#endif

#ifndef BOOSTLITE_SMT_PAUSE
#if !defined(__clang__) && defined(_MSC_VER) && _MSC_VER >= 1310 && (defined(_M_IX86) || defined(_M_X64))
extern "C" void _mm_pause();
#pragma intrinsic(_mm_pause)
#define BOOSTLITE_SMT_PAUSE _mm_pause();
#elif !defined(__c2__) && defined(__GNUC__) && (defined(__i386__) || defined(__x86_64__))
#define BOOSTLITE_SMT_PAUSE __asm__ __volatile__("rep; nop" : : : "memory");
#endif
#endif


#ifndef BOOSTLITE_CONSTEXPR
#if __cpp_constexpr >= 201304
#define BOOSTLITE_CONSTEXPR constexpr
#endif
#endif
#ifndef BOOSTLITE_CONSTEXPR
#define BOOSTLITE_CONSTEXPR
#endif

#ifndef BOOSTLITE_FORCEINLINE
#if defined(_MSC_VER)
#define BOOSTLITE_FORCEINLINE __forceinline
#elif defined(__GNUC__)
#define BOOSTLITE_FORCEINLINE __attribute__((always_inline))
#else
#define BOOSTLITE_FORCEINLINE
#endif
#endif

#ifndef BOOSTLITE_NOINLINE
#if defined(_MSC_VER)
#define BOOSTLITE_NOINLINE __declspec(noinline)
#elif defined(__GNUC__)
#define BOOSTLITE_NOINLINE __attribute__((noinline))
#else
#define BOOSTLITE_NOINLINE
#endif
#endif

#if !defined(BOOSTLITE_NORETURN)
#ifdef __cpp_attributes
#define BOOSTLITE_NORETURN [[noreturn]]
#elif defined(_MSC_VER)
#define BOOSTLITE_NORETURN __declspec(noreturn)
#elif defined(__GNUC__)
#define BOOSTLITE_NORETURN __attribute__((__noreturn__))
#else
#define BOOSTLITE_NORETURN
#endif
#endif

#ifndef BOOSTLITE_NODISCARD
#ifdef __has_cpp_attribute
#if __has_cpp_attribute(nodiscard)
#define BOOSTLITE_NODISCARD [[nodiscard]]
#endif
#elif defined(__clang__)
#define BOOSTLITE_NODISCARD __attribute__((warn_unused_result))
#elif defined(_MSC_VER)

#define BOOSTLITE_NODISCARD __declspec("SAL_name" "(" "\"_Must_inspect_result_\"" "," "\"\"" "," "\"2\"" ")") __declspec("SAL_begin") __declspec("SAL_post") __declspec("SAL_mustInspect") __declspec("SAL_post") __declspec("SAL_checkReturn") __declspec("SAL_end")








#endif
#endif
#ifndef BOOSTLITE_NODISCARD
#define BOOSTLITE_NODISCARD
#endif

#ifndef BOOSTLITE_SYMBOL_VISIBLE
#if defined(_MSC_VER)
#define BOOSTLITE_SYMBOL_VISIBLE
#elif defined(__GNUC__)
#define BOOSTLITE_SYMBOL_VISIBLE __attribute__((visibility("default")))
#else
#define BOOSTLITE_SYMBOL_VISIBLE
#endif
#endif

#ifndef BOOSTLITE_SYMBOL_EXPORT
#if defined(_MSC_VER)
#define BOOSTLITE_SYMBOL_EXPORT __declspec(dllexport)
#elif defined(__GNUC__)
#define BOOSTLITE_SYMBOL_EXPORT __attribute__((visibility("default")))
#else
#define BOOSTLITE_SYMBOL_EXPORT
#endif
#endif

#ifndef BOOSTLITE_SYMBOL_IMPORT
#if defined(_MSC_VER)
#define BOOSTLITE_SYMBOL_IMPORT __declspec(dllimport)
#elif defined(__GNUC__)
#define BOOSTLITE_SYMBOL_IMPORT
#else
#define BOOSTLITE_SYMBOL_IMPORT
#endif
#endif

#ifndef BOOSTLITE_THREAD_LOCAL
#if __cplusplus >= 201103
#define BOOSTLITE_THREAD_LOCAL thread_local
#elif defined(_MSC_VER)
#define BOOSTLITE_THREAD_LOCAL __declspec(thread)
#elif defined(__GNUC__)
#define BOOSTLITE_THREAD_LOCAL __thread
#else
#error Unknown compiler, cannot set BOOSTLITE_THREAD_LOCAL
#endif
#endif

#endif
#ifndef __cpp_attributes
#error Boost.Outcome needs attributes support in the compiler
#endif
#ifndef __cpp_variadic_templates
#error Boost.Outcome needs variadic template support in the compiler
#endif
#ifndef __cpp_constexpr
#error Boost.Outcome needs constexpr (C++ 11) support in the compiler
#endif
#ifndef __cpp_variable_templates
#error Boost.Outcome needs variable template support in the compiler
#endif
#ifndef __cpp_generic_lambdas
#error Boost.Outcome needs generic lambda support in the compiler
#endif
#ifndef BOOSTLITE_BIND_IMPORT_HPP
#define BOOSTLITE_BIND_IMPORT_HPP
#ifndef BOOSTLITE_PREPROCESSOR_MACRO_OVERLOAD_H
#define BOOSTLITE_PREPROCESSOR_MACRO_OVERLOAD_H

#define BOOSTLITE_GLUE(x, y) x y

#define BOOSTLITE_RETURN_ARG_COUNT(_1_, _2_, _3_, _4_, _5_, _6_, _7_, _8_, count, ...) count
#define BOOSTLITE_EXPAND_ARGS(args) BOOSTLITE_RETURN_ARG_COUNT args
#define BOOSTLITE_COUNT_ARGS_MAX8(...) BOOSTLITE_EXPAND_ARGS((__VA_ARGS__, 8, 7, 6, 5, 4, 3, 2, 1, 0))

#define BOOSTLITE_OVERLOAD_MACRO2(name, count) name##count
#define BOOSTLITE_OVERLOAD_MACRO1(name, count) BOOSTLITE_OVERLOAD_MACRO2(name, count)
#define BOOSTLITE_OVERLOAD_MACRO(name, count) BOOSTLITE_OVERLOAD_MACRO1(name, count)

#define BOOSTLITE_CALL_OVERLOAD(name, ...) BOOSTLITE_GLUE(BOOSTLITE_OVERLOAD_MACRO(name, BOOSTLITE_COUNT_ARGS_MAX8(__VA_ARGS__)), (__VA_ARGS__))

#define BOOSTLITE_GLUE_(x, y) x y

#define BOOSTLITE_RETURN_ARG_COUNT_(_1_, _2_, _3_, _4_, _5_, _6_, _7_, _8_, count, ...) count
#define BOOSTLITE_EXPAND_ARGS_(args) BOOSTLITE_RETURN_ARG_COUNT_ args
#define BOOSTLITE_COUNT_ARGS_MAX8_(...) BOOSTLITE_EXPAND_ARGS_((__VA_ARGS__, 8, 7, 6, 5, 4, 3, 2, 1, 0))

#define BOOSTLITE_OVERLOAD_MACRO2_(name, count) name##count
#define BOOSTLITE_OVERLOAD_MACRO1_(name, count) BOOSTLITE_OVERLOAD_MACRO2_(name, count)
#define BOOSTLITE_OVERLOAD_MACRO_(name, count) BOOSTLITE_OVERLOAD_MACRO1_(name, count)

#define BOOSTLITE_CALL_OVERLOAD_(name, ...) BOOSTLITE_GLUE_(BOOSTLITE_OVERLOAD_MACRO_(name, BOOSTLITE_COUNT_ARGS_MAX8_(__VA_ARGS__)), (__VA_ARGS__))

#endif
#define BOOSTLITE_BIND_STRINGIZE(a) #a
#define BOOSTLITE_BIND_STRINGIZE2(a) BOOSTLITE_BIND_STRINGIZE(a)
#define BOOSTLITE_BIND_NAMESPACE_VERSION8(a, b, c, d, e, f, g, h) a##_##b##_##c##_##d##_##e##_##f##_##g##_##h
#define BOOSTLITE_BIND_NAMESPACE_VERSION7(a, b, c, d, e, f, g) a##_##b##_##c##_##d##_##e##_##f##_##g
#define BOOSTLITE_BIND_NAMESPACE_VERSION6(a, b, c, d, e, f) a##_##b##_##c##_##d##_##e##_##f
#define BOOSTLITE_BIND_NAMESPACE_VERSION5(a, b, c, d, e) a##_##b##_##c##_##d##_##e
#define BOOSTLITE_BIND_NAMESPACE_VERSION4(a, b, c, d) a##_##b##_##c##_##d
#define BOOSTLITE_BIND_NAMESPACE_VERSION3(a, b, c) a##_##b##_##c
#define BOOSTLITE_BIND_NAMESPACE_VERSION2(a, b) a##_##b
#define BOOSTLITE_BIND_NAMESPACE_VERSION1(a) a

#define BOOSTLITE_BIND_NAMESPACE_VERSION(...) BOOSTLITE_CALL_OVERLOAD(BOOSTLITE_BIND_NAMESPACE_VERSION, __VA_ARGS__)

#define BOOSTLITE_BIND_NAMESPACE_SELECT_2(name, modifier) name
#define BOOSTLITE_BIND_NAMESPACE_SELECT2(name, modifier) ::name
#define BOOSTLITE_BIND_NAMESPACE_SELECT_1(name) name
#define BOOSTLITE_BIND_NAMESPACE_SELECT1(name) ::name
#define BOOSTLITE_BIND_NAMESPACE_SELECT_(...) BOOSTLITE_CALL_OVERLOAD_(BOOSTLITE_BIND_NAMESPACE_SELECT_, __VA_ARGS__)
#define BOOSTLITE_BIND_NAMESPACE_SELECT(...) BOOSTLITE_CALL_OVERLOAD_(BOOSTLITE_BIND_NAMESPACE_SELECT, __VA_ARGS__)
#define BOOSTLITE_BIND_NAMESPACE_EXPAND8(a, b, c, d, e, f, g, h) BOOSTLITE_BIND_NAMESPACE_SELECT_ a BOOSTLITE_BIND_NAMESPACE_SELECT b BOOSTLITE_BIND_NAMESPACE_SELECT c BOOSTLITE_BIND_NAMESPACE_SELECT d BOOSTLITE_BIND_NAMESPACE_SELECT e BOOSTLITE_BIND_NAMESPACE_SELECT f BOOSTLITE_BIND_NAMESPACE_SELECT g BOOSTLITE_BIND_NAMESPACE_SELECT h
#define BOOSTLITE_BIND_NAMESPACE_EXPAND7(a, b, c, d, e, f, g) BOOSTLITE_BIND_NAMESPACE_SELECT_ a BOOSTLITE_BIND_NAMESPACE_SELECT b BOOSTLITE_BIND_NAMESPACE_SELECT c BOOSTLITE_BIND_NAMESPACE_SELECT d BOOSTLITE_BIND_NAMESPACE_SELECT e BOOSTLITE_BIND_NAMESPACE_SELECT f BOOSTLITE_BIND_NAMESPACE_SELECT g
#define BOOSTLITE_BIND_NAMESPACE_EXPAND6(a, b, c, d, e, f) BOOSTLITE_BIND_NAMESPACE_SELECT_ a BOOSTLITE_BIND_NAMESPACE_SELECT b BOOSTLITE_BIND_NAMESPACE_SELECT c BOOSTLITE_BIND_NAMESPACE_SELECT d BOOSTLITE_BIND_NAMESPACE_SELECT e BOOSTLITE_BIND_NAMESPACE_SELECT f
#define BOOSTLITE_BIND_NAMESPACE_EXPAND5(a, b, c, d, e) BOOSTLITE_BIND_NAMESPACE_SELECT_ a BOOSTLITE_BIND_NAMESPACE_SELECT b BOOSTLITE_BIND_NAMESPACE_SELECT c BOOSTLITE_BIND_NAMESPACE_SELECT d BOOSTLITE_BIND_NAMESPACE_SELECT e
#define BOOSTLITE_BIND_NAMESPACE_EXPAND4(a, b, c, d) BOOSTLITE_BIND_NAMESPACE_SELECT_ a BOOSTLITE_BIND_NAMESPACE_SELECT b BOOSTLITE_BIND_NAMESPACE_SELECT c BOOSTLITE_BIND_NAMESPACE_SELECT d
#define BOOSTLITE_BIND_NAMESPACE_EXPAND3(a, b, c) BOOSTLITE_BIND_NAMESPACE_SELECT_ a BOOSTLITE_BIND_NAMESPACE_SELECT b BOOSTLITE_BIND_NAMESPACE_SELECT c
#define BOOSTLITE_BIND_NAMESPACE_EXPAND2(a, b) BOOSTLITE_BIND_NAMESPACE_SELECT_ a BOOSTLITE_BIND_NAMESPACE_SELECT b
#define BOOSTLITE_BIND_NAMESPACE_EXPAND1(a) BOOSTLITE_BIND_NAMESPACE_SELECT_ a

#define BOOSTLITE_BIND_NAMESPACE(...) BOOSTLITE_CALL_OVERLOAD(BOOSTLITE_BIND_NAMESPACE_EXPAND, __VA_ARGS__)

#define BOOSTLITE_BIND_NAMESPACE_BEGIN_NAMESPACE_SELECT2(name, modifier) modifier namespace name {


#define BOOSTLITE_BIND_NAMESPACE_BEGIN_NAMESPACE_SELECT1(name) namespace name {


#define BOOSTLITE_BIND_NAMESPACE_BEGIN_NAMESPACE_SELECT(...) BOOSTLITE_CALL_OVERLOAD_(BOOSTLITE_BIND_NAMESPACE_BEGIN_NAMESPACE_SELECT, __VA_ARGS__)
#define BOOSTLITE_BIND_NAMESPACE_BEGIN_EXPAND8(a, b, c, d, e, f, g, h) BOOSTLITE_BIND_NAMESPACE_BEGIN_NAMESPACE_SELECT a BOOSTLITE_BIND_NAMESPACE_BEGIN_EXPAND7(b, c, d, e, f, g, h)
#define BOOSTLITE_BIND_NAMESPACE_BEGIN_EXPAND7(a, b, c, d, e, f, g) BOOSTLITE_BIND_NAMESPACE_BEGIN_NAMESPACE_SELECT a BOOSTLITE_BIND_NAMESPACE_BEGIN_EXPAND6(b, c, d, e, f, g)
#define BOOSTLITE_BIND_NAMESPACE_BEGIN_EXPAND6(a, b, c, d, e, f) BOOSTLITE_BIND_NAMESPACE_BEGIN_NAMESPACE_SELECT a BOOSTLITE_BIND_NAMESPACE_BEGIN_EXPAND5(b, c, d, e, f)
#define BOOSTLITE_BIND_NAMESPACE_BEGIN_EXPAND5(a, b, c, d, e) BOOSTLITE_BIND_NAMESPACE_BEGIN_NAMESPACE_SELECT a BOOSTLITE_BIND_NAMESPACE_BEGIN_EXPAND4(b, c, d, e)
#define BOOSTLITE_BIND_NAMESPACE_BEGIN_EXPAND4(a, b, c, d) BOOSTLITE_BIND_NAMESPACE_BEGIN_NAMESPACE_SELECT a BOOSTLITE_BIND_NAMESPACE_BEGIN_EXPAND3(b, c, d)
#define BOOSTLITE_BIND_NAMESPACE_BEGIN_EXPAND3(a, b, c) BOOSTLITE_BIND_NAMESPACE_BEGIN_NAMESPACE_SELECT a BOOSTLITE_BIND_NAMESPACE_BEGIN_EXPAND2(b, c)
#define BOOSTLITE_BIND_NAMESPACE_BEGIN_EXPAND2(a, b) BOOSTLITE_BIND_NAMESPACE_BEGIN_NAMESPACE_SELECT a BOOSTLITE_BIND_NAMESPACE_BEGIN_EXPAND1(b)
#define BOOSTLITE_BIND_NAMESPACE_BEGIN_EXPAND1(a) BOOSTLITE_BIND_NAMESPACE_BEGIN_NAMESPACE_SELECT a


#define BOOSTLITE_BIND_NAMESPACE_BEGIN(...) BOOSTLITE_CALL_OVERLOAD(BOOSTLITE_BIND_NAMESPACE_BEGIN_EXPAND, __VA_ARGS__)

#define BOOSTLITE_BIND_NAMESPACE_EXPORT_BEGIN_NAMESPACE_SELECT2(name, modifier) modifier namespace name {


#define BOOSTLITE_BIND_NAMESPACE_EXPORT_BEGIN_NAMESPACE_SELECT1(name) export namespace name {


#define BOOSTLITE_BIND_NAMESPACE_EXPORT_BEGIN_NAMESPACE_SELECT(...) BOOSTLITE_CALL_OVERLOAD_(BOOSTLITE_BIND_NAMESPACE_EXPORT_BEGIN_NAMESPACE_SELECT, __VA_ARGS__)
#define BOOSTLITE_BIND_NAMESPACE_EXPORT_BEGIN_EXPAND8(a, b, c, d, e, f, g, h) BOOSTLITE_BIND_NAMESPACE_EXPORT_BEGIN_NAMESPACE_SELECT a BOOSTLITE_BIND_NAMESPACE_EXPORT_BEGIN_EXPAND7(b, c, d, e, f, g, h)
#define BOOSTLITE_BIND_NAMESPACE_EXPORT_BEGIN_EXPAND7(a, b, c, d, e, f, g) BOOSTLITE_BIND_NAMESPACE_EXPORT_BEGIN_NAMESPACE_SELECT a BOOSTLITE_BIND_NAMESPACE_EXPORT_BEGIN_EXPAND6(b, c, d, e, f, g)
#define BOOSTLITE_BIND_NAMESPACE_EXPORT_BEGIN_EXPAND6(a, b, c, d, e, f) BOOSTLITE_BIND_NAMESPACE_EXPORT_BEGIN_NAMESPACE_SELECT a BOOSTLITE_BIND_NAMESPACE_EXPORT_BEGIN_EXPAND5(b, c, d, e, f)
#define BOOSTLITE_BIND_NAMESPACE_EXPORT_BEGIN_EXPAND5(a, b, c, d, e) BOOSTLITE_BIND_NAMESPACE_EXPORT_BEGIN_NAMESPACE_SELECT a BOOSTLITE_BIND_NAMESPACE_EXPORT_BEGIN_EXPAND4(b, c, d, e)
#define BOOSTLITE_BIND_NAMESPACE_EXPORT_BEGIN_EXPAND4(a, b, c, d) BOOSTLITE_BIND_NAMESPACE_EXPORT_BEGIN_NAMESPACE_SELECT a BOOSTLITE_BIND_NAMESPACE_EXPORT_BEGIN_EXPAND3(b, c, d)
#define BOOSTLITE_BIND_NAMESPACE_EXPORT_BEGIN_EXPAND3(a, b, c) BOOSTLITE_BIND_NAMESPACE_EXPORT_BEGIN_NAMESPACE_SELECT a BOOSTLITE_BIND_NAMESPACE_EXPORT_BEGIN_EXPAND2(b, c)
#define BOOSTLITE_BIND_NAMESPACE_EXPORT_BEGIN_EXPAND2(a, b) BOOSTLITE_BIND_NAMESPACE_EXPORT_BEGIN_NAMESPACE_SELECT a BOOSTLITE_BIND_NAMESPACE_EXPORT_BEGIN_EXPAND1(b)
#define BOOSTLITE_BIND_NAMESPACE_EXPORT_BEGIN_EXPAND1(a) BOOSTLITE_BIND_NAMESPACE_EXPORT_BEGIN_NAMESPACE_SELECT a


#define BOOSTLITE_BIND_NAMESPACE_EXPORT_BEGIN(...) BOOSTLITE_CALL_OVERLOAD(BOOSTLITE_BIND_NAMESPACE_EXPORT_BEGIN_EXPAND, __VA_ARGS__)

#define BOOSTLITE_BIND_NAMESPACE_END_NAMESPACE_SELECT2(name, modifier) }
#define BOOSTLITE_BIND_NAMESPACE_END_NAMESPACE_SELECT1(name) }
#define BOOSTLITE_BIND_NAMESPACE_END_NAMESPACE_SELECT(...) BOOSTLITE_CALL_OVERLOAD_(BOOSTLITE_BIND_NAMESPACE_END_NAMESPACE_SELECT, __VA_ARGS__)
#define BOOSTLITE_BIND_NAMESPACE_END_EXPAND8(a, b, c, d, e, f, g, h) BOOSTLITE_BIND_NAMESPACE_END_NAMESPACE_SELECT a BOOSTLITE_BIND_NAMESPACE_END_EXPAND7(b, c, d, e, f, g, h)
#define BOOSTLITE_BIND_NAMESPACE_END_EXPAND7(a, b, c, d, e, f, g) BOOSTLITE_BIND_NAMESPACE_END_NAMESPACE_SELECT a BOOSTLITE_BIND_NAMESPACE_END_EXPAND6(b, c, d, e, f, g)
#define BOOSTLITE_BIND_NAMESPACE_END_EXPAND6(a, b, c, d, e, f) BOOSTLITE_BIND_NAMESPACE_END_NAMESPACE_SELECT a BOOSTLITE_BIND_NAMESPACE_END_EXPAND5(b, c, d, e, f)
#define BOOSTLITE_BIND_NAMESPACE_END_EXPAND5(a, b, c, d, e) BOOSTLITE_BIND_NAMESPACE_END_NAMESPACE_SELECT a BOOSTLITE_BIND_NAMESPACE_END_EXPAND4(b, c, d, e)
#define BOOSTLITE_BIND_NAMESPACE_END_EXPAND4(a, b, c, d) BOOSTLITE_BIND_NAMESPACE_END_NAMESPACE_SELECT a BOOSTLITE_BIND_NAMESPACE_END_EXPAND3(b, c, d)
#define BOOSTLITE_BIND_NAMESPACE_END_EXPAND3(a, b, c) BOOSTLITE_BIND_NAMESPACE_END_NAMESPACE_SELECT a BOOSTLITE_BIND_NAMESPACE_END_EXPAND2(b, c)
#define BOOSTLITE_BIND_NAMESPACE_END_EXPAND2(a, b) BOOSTLITE_BIND_NAMESPACE_END_NAMESPACE_SELECT a BOOSTLITE_BIND_NAMESPACE_END_EXPAND1(b)
#define BOOSTLITE_BIND_NAMESPACE_END_EXPAND1(a) BOOSTLITE_BIND_NAMESPACE_END_NAMESPACE_SELECT a


#define BOOSTLITE_BIND_NAMESPACE_END(...) BOOSTLITE_CALL_OVERLOAD(BOOSTLITE_BIND_NAMESPACE_END_EXPAND, __VA_ARGS__)


#define BOOSTLITE_BIND_DECLARE(decl, desc) static const char *boost_bindlib_out[] = {#decl, desc};

#endif
#undef BOOST_OUTCOME_V1_STL11_IMPL
#undef BOOST_OUTCOME_V1_ERROR_CODE_IMPL
#undef BOOST_OUTCOME_V1
#undef BOOST_OUTCOME_V1_NAMESPACE
#undef BOOST_OUTCOME_V1_NAMESPACE_BEGIN
#undef BOOST_OUTCOME_V1_NAMESPACE_END












#define BOOST_OUTCOME_V1_STL11_IMPL std









#define BOOST_OUTCOME_V1_ERROR_CODE_IMPL std
#define BOOST_OUTCOME_PREVIOUS_COMMIT_REF b507c466b259b740c7106b3e71704e3d42500f45
#define BOOST_OUTCOME_PREVIOUS_COMMIT_DATE "2017-05-20 01:15:19 +00:00"
#define BOOST_OUTCOME_PREVIOUS_COMMIT_UNIQUE b507c466
#define BOOST_OUTCOME_V1 (boost), (outcome), (BOOSTLITE_BIND_NAMESPACE_VERSION(, BOOST_OUTCOME_NAMESPACE_VERSION, BOOST_OUTCOME_V1_STL11_IMPL, BOOST_OUTCOME_V1_ERROR_CODE_IMPL, BOOST_OUTCOME_PREVIOUS_COMMIT_UNIQUE), inline)


































































#define BOOST_OUTCOME_V1_NAMESPACE BOOSTLITE_BIND_NAMESPACE(BOOST_OUTCOME_V1)
#define BOOST_OUTCOME_V1_NAMESPACE_BEGIN BOOSTLITE_BIND_NAMESPACE_BEGIN(BOOST_OUTCOME_V1)
#define BOOST_OUTCOME_V1_NAMESPACE_EXPORT_BEGIN BOOSTLITE_BIND_NAMESPACE_BEGIN(BOOST_OUTCOME_V1)
#define BOOST_OUTCOME_V1_NAMESPACE_END BOOSTLITE_BIND_NAMESPACE_END(BOOST_OUTCOME_V1)


#undef BOOST_OUTCOME_NEED_DEFINE
#undef BOOST_OUTCOME_NEED_DEFINE_DESCRIPTION

#ifndef BOOST_OUTCOME_NEED_DEFINE_00
#define BOOST_OUTCOME_NEED_DEFINE_DESCRIPTION "BOOST_OUTCOME_USE_BOOST_THREAD=0 BOOST_OUTCOME_USE_BOOST_ERROR_CODE=0"
#define BOOST_OUTCOME_NEED_DEFINE_00
#define BOOST_OUTCOME_NEED_DEFINE 1
#endif




















#ifdef BOOST_OUTCOME_NEED_DEFINE
#undef BOOST_OUTCOME_MONAD_H
#undef BOOST_OUTCOME_VALUE_STORAGE_H
#ifndef BOOSTLITE_BIND_STD_SYSTEM_ERROR_HPP
#define BOOSTLITE_BIND_STD_SYSTEM_ERROR_HPP

#include <system_error>
namespace boost_lite { namespace bind { namespace std { namespace system_error {
extern const char *boost_bindlib_in;

#ifdef BOOST_STL11_SYSTEM_ERROR_MAP_NO_IS_ERROR_CONDITION_ENUM
#undef BOOST_STL11_SYSTEM_ERROR_MAP_NO_IS_ERROR_CONDITION_ENUM
#else
template<class _Tp> using is_error_condition_enum = ::std::is_error_condition_enum<_Tp>;
#endif


#ifdef BOOST_STL11_SYSTEM_ERROR_MAP_NO_ERRC
#undef BOOST_STL11_SYSTEM_ERROR_MAP_NO_ERRC
#else
using errc = ::std::errc;
#endif


#ifdef BOOST_STL11_SYSTEM_ERROR_MAP_NO_SYSTEM_ERROR
#undef BOOST_STL11_SYSTEM_ERROR_MAP_NO_SYSTEM_ERROR
#else
using system_error = ::std::system_error;
#endif


#ifdef BOOST_STL11_SYSTEM_ERROR_MAP_NO_ERROR_CONDITION
#undef BOOST_STL11_SYSTEM_ERROR_MAP_NO_ERROR_CONDITION
#else
using error_condition = ::std::error_condition;
#endif


#ifdef BOOST_STL11_SYSTEM_ERROR_MAP_NO_ERROR_CODE
#undef BOOST_STL11_SYSTEM_ERROR_MAP_NO_ERROR_CODE
#else
using error_code = ::std::error_code;
#endif


#ifdef BOOST_STL11_SYSTEM_ERROR_MAP_NO_SYSTEM_CATEGORY
#undef BOOST_STL11_SYSTEM_ERROR_MAP_NO_SYSTEM_CATEGORY
#else
using ::std::system_category;
#endif


#ifdef BOOST_STL11_SYSTEM_ERROR_MAP_NO_IS_ERROR_CODE_ENUM
#undef BOOST_STL11_SYSTEM_ERROR_MAP_NO_IS_ERROR_CODE_ENUM
#else
template<class _Tp> using is_error_code_enum = ::std::is_error_code_enum<_Tp>;
#endif


#ifdef BOOST_STL11_SYSTEM_ERROR_MAP_NO_ERROR_CATEGORY
#undef BOOST_STL11_SYSTEM_ERROR_MAP_NO_ERROR_CATEGORY
#else
using error_category = ::std::error_category;
#endif


#ifdef BOOST_STL11_SYSTEM_ERROR_MAP_NO_GENERIC_CATEGORY
#undef BOOST_STL11_SYSTEM_ERROR_MAP_NO_GENERIC_CATEGORY
#else
using ::std::generic_category;
#endif

} } } }

#endif
namespace boost { namespace outcome { inline namespace _1_0_std_std_b507c466 {
namespace stl11
{
  using namespace boost_lite::bind::std::system_error;
}
} } }



#if __cpp_constexpr >= 201304
#define BOOST_OUTCOME_CONSTEXPR constexpr
#else
#define BOOST_OUTCOME_CONSTEXPR
#endif

#include <cassert>
#ifndef BOOST_OUTCOME_DISABLE_IOSTREAMS
#include <ostream>
#endif


#ifdef _WIN32
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
#if defined(__cplusplus) && (!defined(BOOST_BINDLIB_HEADERS_ONLY) || BOOST_BINDLIB_HEADERS_ONLY == 1) && !0
#define EXECINFO_DECL inline
#else
#define EXECINFO_DECL extern __declspec(dllimport)
#endif
#endif

#ifdef __cplusplus
extern "C" {
#endif


EXECINFO_DECL _Check_return_ size_t backtrace(_Out_writes_(len) void **bt, _In_ size_t len);


EXECINFO_DECL _Check_return_ _Ret_writes_maybenull_(len) char **backtrace_symbols(_In_reads_(len) void *const *bt, _In_ size_t len);



#ifdef __cplusplus
}

#if (!defined(BOOSTLITE_HEADERS_ONLY) || BOOSTLITE_HEADERS_ONLY == 1) && !0
#define BOOSTLITE_INCLUDED_BY_HEADER 1
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
      if(!SymInitialize((void *) (size_t) -1 , NULL, 1))
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
#pragma warning(disable : 6385 6386)
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

        ret[n] = (char *) ((char *) p - (char *) ret);
        if(!SymGetLineFromAddr64 || !SymGetLineFromAddr64((void *) (size_t) -1 , (size_t) bt[n], &displ, &ihl))
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
          int plen = WideCharToMultiByte(65001 , 0, ihl.FileName, -1, p, (int) (end - p), NULL, NULL);
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



#ifdef __cplusplus
}
#endif
#undef BOOSTLITE_INCLUDED_BY_HEADER
#endif

#endif

#endif
#else
#include <execinfo.h>
#endif

#ifndef BOOST_OUTCOME_THROW
#ifdef __cpp_exceptions
#define BOOST_OUTCOME_THROW(expr) throw expr
#else
#include <stdio.h>
namespace boost { namespace outcome { inline namespace _1_0_std_std_b507c466 {
namespace detail
{
  BOOSTLITE_NORETURN inline void do_fatal_exit(const char *expr)
  {
    void *bt[16];
    size_t btlen = backtrace(bt, sizeof(bt) / sizeof(bt[0]));
    fprintf(stderr, "FATAL: Boost.Outcome throws exception %s with exceptions disabled\n", expr);
    char **bts = backtrace_symbols(bt, btlen);
    if(bts)
    {
      for(size_t n = 0; n < btlen; n++)
        fprintf(stderr, "  %s\n", bts[n]);
      free(bts);
    }
    std::terminate();
  }
}
} } }

#define BOOST_OUTCOME_THROW(expr) BOOST_OUTCOME_V1_NAMESPACE::detail::do_fatal_exit(#expr)
#endif
#endif

#ifndef BOOST_OUTCOME_THROW_DESERIALISATION_FAILURE

#define BOOST_OUTCOME_THROW_DESERIALISATION_FAILURE(m, expr) BOOST_OUTCOME_THROW(expr)
#endif

#ifndef BOOST_OUTCOME_THROW_BAD_OUTCOME



#define BOOST_OUTCOME_THROW_BAD_OUTCOME(ec, expr) BOOST_OUTCOME_THROW(expr), false
#endif

#ifndef BOOST_OUTCOME_THROW_SYSTEM_ERROR

#define BOOST_OUTCOME_THROW_SYSTEM_ERROR(ec, expr) BOOST_OUTCOME_THROW(expr)
#endif

#ifndef BOOST_OUTCOME_RETHROW_EXCEPTION
#ifdef __cpp_exceptions
#define BOOST_OUTCOME_RETHROW_EXCEPTION(ex) std::rethrow_exception(ex)
#else

#define BOOST_OUTCOME_RETHROW_EXCEPTION(ex) BOOST_OUTCOME_THROW(std::rethrow_exception(ex))
#endif
#endif

#ifndef BOOST_OUTCOME_THROW_BAD_EXPECTED_ACCESS

#define BOOST_OUTCOME_THROW_BAD_EXPECTED_ACCESS(...) BOOST_OUTCOME_THROW(experimental::make_bad_expected_access(__VA_ARGS__))
#endif


#endif

#endif
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4714)
#pragma warning(disable : 4996)
#endif
#ifndef BOOST_OUTCOME_MONAD_ERROR_H
#define BOOST_OUTCOME_MONAD_ERROR_H



namespace boost { namespace outcome { inline namespace _1_0_std_std_b507c466 {


enum class bad_outcome_errc
{

  no_state = 2,
  exception_present = 3,
};

namespace _detail
{
  class bad_outcome_category : public stl11::error_category
  {
  public:
    virtual const char *name() const noexcept { return "basic_monad"; }
    virtual std::string message(int c) const
    {
      switch(c)
      {
      case 1:
        return "already set";
      case 2:
        return "no state";
      case 3:
        return "exception present";
      default:
        return "unknown";
      }
    }
  };
}





inline const _detail::bad_outcome_category &bad_outcome_category()
{
  static _detail::bad_outcome_category c;
  return c;
}


class BOOSTLITE_SYMBOL_VISIBLE bad_outcome : public stl11::system_error
{
public:
  bad_outcome(stl11::error_code ec)
      : std::system_error(ec)
  {
  }
};


inline stl11::error_code make_error_code(bad_outcome_errc e)
{
  return stl11::error_code(static_cast<int>(e), bad_outcome_category());
}


inline stl11::error_condition make_error_condition(bad_outcome_errc e)
{
  return stl11::error_condition(static_cast<int>(e), bad_outcome_category());
}

} } }

















namespace std
{

  template <> struct is_error_code_enum<boost ::outcome ::_1_0_std_std_b507c466::bad_outcome_errc> : std::true_type
  {
  };

  template <> struct is_error_condition_enum<boost ::outcome ::_1_0_std_std_b507c466::bad_outcome_errc> : std::true_type
  {
  };
}


#endif
#ifndef BOOST_OUTCOME_ERROR_CODE_EXTENDED_H
#define BOOST_OUTCOME_ERROR_CODE_EXTENDED_H
#ifndef BOOSTLITE_RINGBUFFER_LOG_HPP
#define BOOSTLITE_RINGBUFFER_LOG_HPP

#ifndef BOOSTLITE_RINGBUFFER_LOG_DEFAULT_ENTRIES_DEBUG
#define BOOSTLITE_RINGBUFFER_LOG_DEFAULT_ENTRIES_DEBUG 4096
#endif

#ifndef BOOSTLITE_RINGBUFFER_LOG_DEFAULT_ENTRIES_NDEBUG
#define BOOSTLITE_RINGBUFFER_LOG_DEFAULT_ENTRIES_NDEBUG 256
#endif

#ifdef NDEBUG
#define BOOSTLITE_RINGBUFFER_LOG_DEFAULT_ENTRIES BOOSTLITE_RINGBUFFER_LOG_DEFAULT_ENTRIES_NDEBUG
#else
#define BOOSTLITE_RINGBUFFER_LOG_DEFAULT_ENTRIES BOOSTLITE_RINGBUFFER_LOG_DEFAULT_ENTRIES_DEBUG
#endif


#if defined(_MSC_VER) && defined(__clang__)
#pragma clang diagnostic ignored "-Wdeprecated-declarations"
#endif




#include <array>
#include <atomic>
#include <chrono>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <iomanip>
#include <ostream>
#include <sstream>
#include <system_error>
#include <type_traits>

#ifdef _WIN32

#else
#include <execinfo.h>
#endif

namespace boost_lite { inline namespace _ed8678b7 {

namespace ringbuffer_log
{
  template <class Policy> class ringbuffer_log;

  enum class level : unsigned char
  {
    none = 0,
    fatal,
    error,
    warn,
    info,
    debug,
    all
  };


  template <class T> inline const char *last190(const T &v)
  {
    size_t size = v.size();
    return size <= 190 ? v.data() : v.data() + (size - 190);
  }
  namespace simple_ringbuffer_log_policy_detail
  {
    using level_ = level;
    struct value_type
    {
      uint64_t counter;
      uint64_t timestamp;
      union {
        uint32_t code32[2];
        uint64_t code64;
      };
      union {
        uint64_t backtrace[5];
        char function[40];
      };
      uint8_t level : 4;
      uint8_t using_code64 : 1;
      uint8_t using_backtrace : 1;
      char message[191];

    private:
      static std::chrono::high_resolution_clock::time_point _first_item()
      {
        static std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
        return now;
      }

    public:
      value_type() { memset(this, 0, sizeof(*this)); }
      value_type(level_ _level, const char *_message, uint32_t _code1, uint32_t _code2, const char *_function = nullptr, unsigned lineno = 0)
          : counter((size_t) -1)
          , timestamp(std::chrono::duration_cast<std::chrono::nanoseconds>((_first_item(), std::chrono::high_resolution_clock::now() - _first_item())).count())
          , code32{_code1, _code2}
          , level(static_cast<uint8_t>(_level))
          , using_code64(false)
          , using_backtrace(!_function)
      {
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4996)
#endif
        strncpy(message, _message, sizeof(message));
        if(_function)
        {
          if(_function[0])
          {
            strncpy(function, _function, sizeof(function));
            char temp[32], *e = function;
            for(size_t n = 0; n < sizeof(function) && *e != 0; n++, e++)
              ;
#ifdef _MSC_VER
            _ultoa_s(lineno, temp, 10);
#else
            snprintf(temp, sizeof(temp), "%u", lineno);
#endif
            temp[31] = 0;
            ptrdiff_t len = strlen(temp);
            if(function + sizeof(function) - e >= len + 2)
            {
              *e++ = ':';
              memcpy(e, temp, len);
            }
          }
        }
        else
        {
          constexpr size_t items = 1 + sizeof(backtrace) / sizeof(backtrace[0]);
          void *temp[items];
          memset(temp, 0, sizeof(temp));
          (void) ::backtrace(temp, items);
          memcpy(backtrace, temp + 1, sizeof(backtrace));
        }
#ifdef _MSC_VER
#pragma warning(pop)
#endif
      }
      bool operator==(const value_type &o) const noexcept { return memcmp(this, &o, sizeof(*this)) == 0; }
      bool operator!=(const value_type &o) const noexcept { return memcmp(this, &o, sizeof(*this)) != 0; }
      bool operator<(const value_type &o) const noexcept { return memcmp(this, &o, sizeof(*this)) < 0; }
      bool operator>(const value_type &o) const noexcept { return memcmp(this, &o, sizeof(*this)) > 0; }
      bool operator<=(const value_type &o) const noexcept { return memcmp(this, &o, sizeof(*this)) <= 0; }
      bool operator>=(const value_type &o) const noexcept { return memcmp(this, &o, sizeof(*this)) >= 0; }
    };
    static_assert(sizeof(value_type) == 256, "value_type is not 256 bytes long!");


    inline std::ostream &operator<<(std::ostream &s, const value_type &v)
    {
      s << "+" << std::setfill('0') << std::setw(16) << v.timestamp << " " << std::setfill(' ') << std::setw(1);
      switch(v.level)
      {
      case 0:
        s << "none:  ";
        break;
      case 1:
        s << "fatal: ";
        break;
      case 2:
        s << "error: ";
        break;
      case 3:
        s << "warn:  ";
        break;
      case 4:
        s << "info:  ";
        break;
      case 5:
        s << "debug: ";
        break;
      case 6:
        s << "all:   ";
        break;
      default:
        s << "unknown: ";
        break;
      }
      if(v.using_code64)
        s << "{ " << v.code64 << " } ";
      else
        s << "{ " << v.code32[0] << ", " << v.code32[1] << " } ";
      char temp[256];
      memcpy(temp, v.message, sizeof(v.message));
      temp[sizeof(v.message)] = 0;
      s << temp << " @ ";
      if(v.using_backtrace)
      {
        char **symbols = backtrace_symbols((void **) v.backtrace, sizeof(v.backtrace) / sizeof(v.backtrace[0]));
        if(!symbols)
          s << "BACKTRACE FAILED!";
        else
        {
          for(size_t n = 0; n < sizeof(v.backtrace) / sizeof(v.backtrace[0]); n++)
          {
            if(symbols[n])
            {
              if(n)
                s << ", ";
              s << symbols[n];
            }
          }
          free(symbols);
        }
      }
      else
      {
        memcpy(temp, v.function, sizeof(v.function));
        temp[sizeof(v.function)] = 0;
        s << temp;
      }
      return s << "\n";
    }

    inline std::ostream &csv(std::ostream &s, const value_type &v)
    {

      s << v.timestamp << "," << (unsigned) v.level << "," << (unsigned) v.using_code64 << "," << (unsigned) v.using_backtrace << ",";
      if(v.using_code64)
        s << v.code64 << ",0,\"";
      else
        s << v.code32[0] << "," << v.code32[1] << ",\"";
      char temp[256];
      memcpy(temp, v.message, sizeof(v.message));
      temp[sizeof(v.message)] = 0;
      s << temp << "\",\"";
      if(v.using_backtrace)
      {
        char **symbols = backtrace_symbols((void **) v.backtrace, sizeof(v.backtrace) / sizeof(v.backtrace[0]));
        if(!symbols)
          s << "BACKTRACE FAILED!";
        else
        {
          for(size_t n = 0; n < sizeof(v.backtrace) / sizeof(v.backtrace[0]); n++)
          {
            if(symbols[n])
            {
              if(n)
                s << ";";
              s << symbols[n];
            }
          }
          free(symbols);
        }
      }
      else
      {
        memcpy(temp, v.function, sizeof(v.function));
        temp[sizeof(v.function)] = 0;
        s << temp;
      }
      return s << "\"\n";
    }
  }










  template <size_t Bytes = BOOSTLITE_RINGBUFFER_LOG_DEFAULT_ENTRIES * 256> struct simple_ringbuffer_log_policy
  {

    using value_type = simple_ringbuffer_log_policy_detail::value_type;

    static constexpr size_t max_items = Bytes / sizeof(value_type);

    using container_type = std::array<value_type, max_items>;
  };




















  template <class Policy> class ringbuffer_log
  {
    friend Policy;

  public:



    using container_type = typename Policy::container_type;

    static constexpr size_t max_items = Policy::max_items;


    using value_type = typename container_type::value_type;

    using size_type = typename container_type::size_type;

    using difference_type = typename container_type::difference_type;

    using reference = typename container_type::reference;

    using const_reference = typename container_type::const_reference;

    using pointer = typename container_type::pointer;

    using const_pointer = typename container_type::const_pointer;

  protected:
    template <class Parent, class Pointer, class Reference> class iterator_;
    template <class Parent, class Pointer, class Reference> class iterator_ : public std::iterator<std::random_access_iterator_tag, value_type, difference_type, pointer, reference>
    {
      friend class ringbuffer_log;
      template <class Parent_, class Pointer_, class Reference_> friend class iterator_;
      Parent *_parent;
      size_type _counter, _togo;

      constexpr iterator_(Parent *parent, size_type counter, size_type items)
          : _parent(parent)
          , _counter(counter)
          , _togo(items)
      {
      }

    public:
      constexpr iterator_()
          : _parent(nullptr)
          , _counter(0)
          , _togo(0)
      {
      }
      constexpr iterator_(const iterator_ &) noexcept = default;
      constexpr iterator_(iterator_ &&) noexcept = default;
      iterator_ &operator=(const iterator_ &) noexcept = default;
      iterator_ &operator=(iterator_ &&) noexcept = default;

      template <class Parent_, class Pointer_, class Reference_, typename = typename std::enable_if<!std::is_const<Pointer_>::value && !std::is_const<Reference_>::value>::type> constexpr iterator_(const iterator_<Parent_, Pointer_, Reference_> &o) noexcept : _parent(o._parent), _counter(o._counter), _togo(o._togo) {}
      iterator_ &operator++() noexcept
      {
        if(_parent && _togo)
        {
          --_counter;
          --_togo;
        }
        return *this;
      }
      void swap(iterator_ &o) noexcept
      {
        std::swap(_parent, o._parent);
        std::swap(_counter, o._counter);
        std::swap(_togo, o._togo);
      }
      Pointer operator->() const noexcept
      {
        if(!_parent || !_togo)
          return nullptr;
        return &_parent->_store[_parent->counter_to_idx(_counter)];
      }
      bool operator==(const iterator_ &o) const noexcept { return _parent == o._parent && _counter == o._counter && _togo == o._togo; }
      bool operator!=(const iterator_ &o) const noexcept { return _parent != o._parent || _counter != o._counter || _togo != o._togo; }
      Reference operator*() const noexcept
      {
        if(!_parent || !_togo)
        {
          static value_type v;
          return v;
        }
        return _parent->_store[_parent->counter_to_idx(_counter)];
      }
      iterator_ operator++(int) noexcept
      {
        iterator_ ret(*this);
        if(_parent && _togo)
        {
          --_counter;
          --_togo;
        }
        return ret;
      }
      iterator_ &operator--() noexcept
      {
        if(_parent && _togo < _parent->size())
        {
          ++_counter;
          ++_togo;
        }
        return *this;
      }
      iterator_ operator--(int) noexcept
      {
        iterator_ ret(*this);
        if(_parent && _togo < _parent->size())
        {
          ++_counter;
          ++_togo;
        }
        return ret;
      }
      bool operator<(const iterator_ &o) const noexcept { return _parent == o._parent && _parent->counter_to_idx(_counter) < o._parent->counter_to_idx(o._counter); }
      bool operator>(const iterator_ &o) const noexcept { return _parent == o._parent && _parent->counter_to_idx(_counter) > o._parent->counter_to_idx(o._counter); }
      bool operator<=(const iterator_ &o) const noexcept { return _parent == o._parent && _parent->counter_to_idx(_counter) <= o._parent->counter_to_idx(o._counter); }
      bool operator>=(const iterator_ &o) const noexcept { return _parent == o._parent && _parent->counter_to_idx(_counter) >= o._parent->counter_to_idx(o._counter); }
      iterator_ &operator+=(size_type v) const noexcept
      {
        if(_parent && _togo)
        {
          if(v > _togo)
            v = _togo;
          _counter -= v;
          _togo -= v;
        }
        return *this;
      }
      iterator_ operator+(size_type v) const noexcept
      {
        iterator_ ret(*this);
        if(_parent && _togo)
        {
          if(v > _togo)
            v = _togo;
          ret._counter -= v;
          ret._togo -= v;
        }
        return ret;
      }
      iterator_ &operator-=(size_type v) const noexcept
      {
        if(_parent && _togo < _parent->size())
        {
          if(v > _parent->size() - _togo)
            v = _parent->size() - _togo;
          _counter += v;
          _togo += v;
        }
        return *this;
      }
      iterator_ operator-(size_type v) const noexcept
      {
        iterator_ ret(*this);
        if(_parent && _togo < _parent->size())
        {
          if(v > _parent->size() - _togo)
            v = _parent->size() - _togo;
          ret._counter += v;
          ret._togo += v;
        }
        return ret;
      }
      difference_type operator-(const iterator_ &o) const noexcept { return (difference_type)(o._counter - _counter); }
      Reference operator[](size_type v) const noexcept { return _parent->_store[_parent->counter_to_idx(_counter + v)]; }
    };
    template <class Parent, class Pointer, class Reference> friend class iterator_;

  public:

    using iterator = iterator_<ringbuffer_log, pointer, reference>;

    using const_iterator = iterator_<const ringbuffer_log, const_pointer, const_reference>;

    using reverse_iterator = std::reverse_iterator<iterator>;

    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

  protected:
    container_type _store;
    level _level;
    std::atomic<size_type> _counter;
    std::ostream *_immediate;

    size_type counter_to_idx(size_type counter) const noexcept { return max_items ? (counter % max_items) : (counter % _store.size()); }
  public:

    template <class... Args>
    ringbuffer_log(level starting_level, Args &&... args)
        : _store(std::forward<Args>(args)...)
        , _level(starting_level)
        , _counter(0)
        , _immediate(nullptr)
    {
    }

    ringbuffer_log(const ringbuffer_log &) = delete;

    ringbuffer_log(ringbuffer_log &&) = delete;

    ringbuffer_log &operator=(const ringbuffer_log &) = delete;

    ringbuffer_log &operator=(ringbuffer_log &&) = delete;

    void swap(ringbuffer_log &o) noexcept
    {
      std::swap(_store, o._store);
      std::swap(_level, o._level);
      std::swap(_counter, o._counter);
      std::swap(_immediate, o._immediate);
    }


    level log_level() const noexcept { return _level; }

    void log_level(level new_level) noexcept { _level = new_level; }


    bool empty() const noexcept { return _counter.load(std::memory_order_relaxed) == 0; }

    size_type size() const noexcept
    {
      size_type ret = _counter.load(std::memory_order_relaxed);
      if(_store.size() < ret)
        ret = _store.size();
      return ret;
    }

    size_type max_size() const noexcept { return max_items ? max_items : _store.size(); }

    std::ostream *immediate() const noexcept { return _immediate; }

    void immediate(std::ostream *s) noexcept { _immediate = s; }


    struct unique_id
    {
      size_type value;
      constexpr unique_id(size_type _value)
          : value(_value)
      {
      }
    };

    bool valid(unique_id id) const noexcept
    {
      size_type counter = _counter.load(std::memory_order_relaxed);
      size_type size = counter;
      if(_store.size() < size)
        size = _store.size();
      return id.value < counter && id.value >= counter - size;
    }


    reference front() noexcept { return _store[counter_to_idx(_counter.load(std::memory_order_relaxed) - 1)]; }

    const_reference front() const noexcept { return _store[counter_to_idx(_counter.load(std::memory_order_relaxed) - 1)]; }
#ifdef __cpp_exceptions

    reference at(size_type pos)
    {
      if(pos >= size())
        throw std::out_of_range("index exceeds size");
      return _store[counter_to_idx(_counter.load(std::memory_order_relaxed) - 1 - pos)];
    }

    reference at(unique_id id)
    {
      if(!valid(id))
        throw std::out_of_range("index exceeds size");
      return _store[counter_to_idx(id.value)];
    }

    const_reference at(size_type pos) const
    {
      if(pos >= size())
        throw std::out_of_range("index exceeds size");
      return _store[counter_to_idx(_counter.load(std::memory_order_relaxed) - 1 - pos)];
    }

    const_reference at(unique_id id) const
    {
      if(!valid(id))
        throw std::out_of_range("index exceeds size");
      return _store[counter_to_idx(id.value)];
    }
#endif

    reference operator[](size_type pos) noexcept { return _store[counter_to_idx(_counter.load(std::memory_order_relaxed) - 1 - pos)]; }

    reference operator[](unique_id id) noexcept { return _store[counter_to_idx(id.value)]; }

    const_reference operator[](size_type pos) const noexcept { return _store[counter_to_idx(_counter.load(std::memory_order_relaxed) - 1 - pos)]; }

    const_reference operator[](unique_id id) const noexcept { return _store[counter_to_idx(id.value)]; }

    reference back() noexcept
    {
      size_type counter = _counter.load(std::memory_order_relaxed);
      size_type size = counter;
      if(_store.size() < size)
        size = _store.size();
      return _store[counter_to_idx(counter - size)];
    }

    const_reference back() const noexcept
    {
      size_type counter = _counter.load(std::memory_order_relaxed);
      size_type size = counter;
      if(_store.size() < size)
        size = _store.size();
      return _store[counter_to_idx(counter - size)];
    }


    iterator begin() noexcept
    {
      size_type counter = _counter.load(std::memory_order_relaxed);
      size_type size = counter;
      if(_store.size() < size)
        size = _store.size();
      return iterator(this, counter - 1, size);
    }

    const_iterator begin() const noexcept
    {
      size_type counter = _counter.load(std::memory_order_relaxed);
      size_type size = counter;
      if(_store.size() < size)
        size = _store.size();
      return const_iterator(this, counter - 1, size);
    }

    const_iterator cbegin() const noexcept
    {
      size_type counter = _counter.load(std::memory_order_relaxed);
      size_type size = counter;
      if(_store.size() < size)
        size = _store.size();
      return const_iterator(this, counter - 1, size);
    }

    iterator end() noexcept
    {
      size_type counter = _counter.load(std::memory_order_relaxed);
      size_type size = counter;
      if(_store.size() < size)
        size = _store.size();
      return iterator(this, counter - 1 - size, 0);
    }

    const_iterator end() const noexcept
    {
      size_type counter = _counter.load(std::memory_order_relaxed);
      size_type size = counter;
      if(_store.size() < size)
        size = _store.size();
      return const_iterator(this, counter - 1 - size, 0);
    }

    const_iterator cend() const noexcept
    {
      size_type counter = _counter.load(std::memory_order_relaxed);
      size_type size = counter;
      if(_store.size() < size)
        size = _store.size();
      return const_iterator(this, counter - 1 - size, 0);
    }


    void clear() noexcept
    {
      _counter.store(0, std::memory_order_relaxed);
      std::fill(_store.begin(), _store.end(), value_type());
    }

    size_type push_back(value_type &&v) noexcept
    {
      if(static_cast<level>(v.level) <= _level)
      {
        if(_immediate)
          *_immediate << v << std::endl;
        size_type thisitem = _counter++;
        v.counter = thisitem;
        _store[counter_to_idx(thisitem)] = std::move(v);
        return thisitem;
      }
      return (size_type) -1;
    }

    template <class... Args> size_type emplace_back(level __level, Args &&... args) noexcept
    {
      if(__level <= _level)
      {
        value_type v(__level, std::forward<Args>(args)...);
        if(_immediate)
          *_immediate << v << std::endl;
        size_type thisitem = _counter++;
        v.counter = thisitem;
        _store[counter_to_idx(thisitem)] = std::move(v);
        return thisitem;
      }
      return (size_type) -1;
    }
  };


  template <class Policy> inline std::ostream &operator<<(std::ostream &s, const ringbuffer_log<Policy> &l)
  {
    for(const auto &i : l)
    {
      s << i;
    }
    return s;
  }


  template <class Policy> inline std::string csv(const ringbuffer_log<Policy> &l)
  {
    std::stringstream s;

    s << "timestamp,level,using_code64,using_backtrace,code0,code1,message,backtrace\n";
    for(const auto &i : l)
    {
      csv(s, i);
    }
    return s.str();
  }


  template <size_t Bytes = BOOSTLITE_RINGBUFFER_LOG_DEFAULT_ENTRIES * 256> using simple_ringbuffer_log = ringbuffer_log<simple_ringbuffer_log_policy<Bytes>>;
}

} }



#define BOOSTLITE_RINGBUFFERLOG_ITEM_FUNCTION(log, level, message, code1, code2) (log).emplace_back((level), (message), (code1), (code2), __func__, __LINE__)

#define BOOSTLITE_RINGBUFFERLOG_ITEM_BACKTRACE(log, level, message, code1, code2) (log).emplace_back((level), (message), (code1), (code2), nullptr)

#ifndef BOOSTLITE_RINGBUFFERLOG_LEVEL
#if defined(_DEBUG) || defined(DEBUG)
#define BOOSTLITE_RINGBUFFERLOG_LEVEL 5
#else
#define BOOSTLITE_RINGBUFFERLOG_LEVEL 2
#endif
#endif

#if BOOSTLITE_RINGBUFFERLOG_LEVEL >= 1

#define BOOSTLITE_RINGBUFFERLOG_FATAL_FUNCTION(log, message, code1, code2) BOOSTLITE_RINGBUFFERLOG_ITEM_FUNCTION((log), ringbuffer_log::level::fatal, (message), (code1), (code2))

#define BOOSTLITE_RINGBUFFERLOG_FATAL_BACKTRACE(log, message, code1, code2) BOOSTLITE_RINGBUFFERLOG_ITEM_BACKTRACE((log), ringbuffer_log::level::fatal, (message), (code1), (code2))
#else
#define BOOSTLITE_RINGBUFFERLOG_FATAL_FUNCTION(log, message, code1, code2)
#define BOOSTLITE_RINGBUFFERLOG_FATAL_BACKTRACE(log, message, code1, code2)
#endif

#if BOOSTLITE_RINGBUFFERLOG_LEVEL >= 2

#define BOOSTLITE_RINGBUFFERLOG_ERROR_FUNCTION(log, message, code1, code2) BOOSTLITE_RINGBUFFERLOG_ITEM_FUNCTION((log), ringbuffer_log::level::error, (message), (code1), (code2))

#define BOOSTLITE_RINGBUFFERLOG_ERROR_BACKTRACE(log, message, code1, code2) BOOSTLITE_RINGBUFFERLOG_ITEM_BACKTRACE((log), ringbuffer_log::level::error, (message), (code1), (code2))
#else
#define BOOSTLITE_RINGBUFFERLOG_ERROR_FUNCTION(log, message, code1, code2)
#define BOOSTLITE_RINGBUFFERLOG_ERROR_BACKTRACE(log, message, code1, code2)
#endif

#if BOOSTLITE_RINGBUFFERLOG_LEVEL >= 3

#define BOOSTLITE_RINGBUFFERLOG_WARN_FUNCTION(log, message, code1, code2) BOOSTLITE_RINGBUFFERLOG_ITEM_FUNCTION((log), ringbuffer_log::level::warn, (message), (code1), (code2))

#define BOOSTLITE_RINGBUFFERLOG_WARN_BACKTRACE(log, message, code1, code2) BOOSTLITE_RINGBUFFERLOG_ITEM_BACKTRACE((log), ringbuffer_log::level::warn, (message), (code1), (code2))
#else
#define BOOSTLITE_RINGBUFFERLOG_WARN_FUNCTION(log, message, code1, code2)
#define BOOSTLITE_RINGBUFFERLOG_WARN_BACKTRACE(log, message, code1, code2)
#endif

#if BOOSTLITE_RINGBUFFERLOG_LEVEL >= 4

#define BOOSTLITE_RINGBUFFERLOG_INFO_FUNCTION(log, message, code1, code2) BOOSTLITE_RINGBUFFERLOG_ITEM_FUNCTION((log), ringbuffer_log::level::info, (message), (code1), (code2))

#define BOOSTLITE_RINGBUFFERLOG_INFO_BACKTRACE(log, message, code1, code2) BOOSTLITE_RINGBUFFERLOG_ITEM_BACKTRACE((log), ringbuffer_log::level::info, (message), (code1), (code2))
#else
#define BOOSTLITE_RINGBUFFERLOG_INFO_FUNCTION(log, message, code1, code2)
#define BOOSTLITE_RINGBUFFERLOG_INFO_BACKTRACE(log, message, code1, code2)
#endif

#if BOOSTLITE_RINGBUFFERLOG_LEVEL >= 5

#define BOOSTLITE_RINGBUFFERLOG_DEBUG_FUNCTION(log, message, code1, code2) BOOSTLITE_RINGBUFFERLOG_ITEM_FUNCTION((log), ringbuffer_log::level::debug, (message), (code1), (code2))

#define BOOSTLITE_RINGBUFFERLOG_DEBUG_BACKTRACE(log, message, code1, code2) BOOSTLITE_RINGBUFFERLOG_ITEM_BACKTRACE((log), ringbuffer_log::level::debug, (message), (code1), (code2))
#else
#define BOOSTLITE_RINGBUFFERLOG_DEBUG_FUNCTION(log, message, code1, code2)
#define BOOSTLITE_RINGBUFFERLOG_DEBUG_BACKTRACE(log, message, code1, code2)
#endif

#if BOOSTLITE_RINGBUFFERLOG_LEVEL >= 6

#define BOOSTLITE_RINGBUFFERLOG_ALL_FUNCTION(log, message, code1, code2) BOOSTLITE_RINGBUFFERLOG_ITEM_FUNCTION((log), ringbuffer_log::level::all, (message), (code1), (code2))

#define BOOSTLITE_RINGBUFFERLOG_ALL_BACKTRACE(log, message, code1, code2) BOOSTLITE_RINGBUFFERLOG_ITEM_BACKTRACE((log), ringbuffer_log::level::all, (message), (code1), (code2))
#else
#define BOOSTLITE_RINGBUFFERLOG_ALL_FUNCTION(log, message, code1, code2)
#define BOOSTLITE_RINGBUFFERLOG_ALL_BACKTRACE(log, message, code1, code2)
#endif

#endif
#ifndef BOOST_OUTCOME_DEFAULT_EXTENDED_ERROR_CODE_LOG_SIZE
#define BOOST_OUTCOME_DEFAULT_EXTENDED_ERROR_CODE_LOG_SIZE 4096
#endif

namespace boost { namespace outcome { inline namespace _1_0_std_std_b507c466 {


inline boost_lite::ringbuffer_log::simple_ringbuffer_log<BOOST_OUTCOME_DEFAULT_EXTENDED_ERROR_CODE_LOG_SIZE> &extended_error_code_log()
{
  static boost_lite::ringbuffer_log::simple_ringbuffer_log<BOOST_OUTCOME_DEFAULT_EXTENDED_ERROR_CODE_LOG_SIZE> log(boost_lite::ringbuffer_log::level::error);
  return log;
}



namespace deatomiced_categories
{
  namespace detail
  {
    BOOSTLITE_NOINLINE inline const std::error_category &_generic_category()
    {
      const std::error_category &c = stl11::generic_category();
      return c;
    }

    BOOSTLITE_NOINLINE inline const std::error_category &_system_category()
    {
      const std::error_category &c = stl11::system_category();
      return c;
    }
  }

  inline const std::error_category &generic_category()
  {
    const std::error_category &c = detail::_generic_category();
    return c;
  }


  inline const std::error_category &system_category()
  {
    const std::error_category &c = detail::_system_category();
    return c;
  }
}

#ifndef BOOST_OUTCOME_ERROR_CODE_EXTENDED_CREATION_HOOK
#define BOOST_OUTCOME_ERROR_CODE_EXTENDED_CREATION_HOOK
#endif





class error_code_extended : public stl11::error_code
{
  friend inline std::ostream &operator<<(std::ostream &s, const error_code_extended &ec);
  using unique_id = boost_lite::ringbuffer_log::simple_ringbuffer_log<4096>::unique_id;
  size_t _unique_id;
public:

  error_code_extended()
      : _unique_id((size_t) -1)
  {
    BOOST_OUTCOME_ERROR_CODE_EXTENDED_CREATION_HOOK;
  }

  error_code_extended(int ec, const stl11::error_category &cat, const char *msg = nullptr, unsigned code1 = 0, unsigned code2 = 0, bool backtrace = false)
      : error_code_extended(stl11::error_code(ec, cat), msg, code1, code2, backtrace)
  {
  }

  template <class ErrorCodeEnum, typename = typename std::enable_if<stl11::is_error_code_enum<ErrorCodeEnum>::value>::type>
  error_code_extended(ErrorCodeEnum e)
      : stl11::error_code(e)
      , _unique_id((size_t) -1)
  {
    BOOST_OUTCOME_ERROR_CODE_EXTENDED_CREATION_HOOK;
  }

  explicit error_code_extended(const stl11::error_code &e, const char *msg = nullptr, unsigned code1 = 0, unsigned code2 = 0, bool backtrace = false)
      : error_code_extended(stl11::error_code(e), msg, code1, code2, backtrace)
  {
  }

  explicit error_code_extended(stl11::error_code &&e, const char *msg = nullptr, unsigned code1 = 0, unsigned code2 = 0, bool backtrace = false)
      : stl11::error_code(std::move(e))
      , _unique_id(msg ? extended_error_code_log().emplace_back(boost_lite::ringbuffer_log::level::error, msg, code1, code2, backtrace ? nullptr : "", 0) : (size_t) -1)
  {
    BOOST_OUTCOME_ERROR_CODE_EXTENDED_CREATION_HOOK;
  }

  void assign(int ec, const stl11::error_category &cat, const char *msg = nullptr, unsigned code1 = 0, unsigned code2 = 0, bool backtrace = false) { *this = error_code_extended(ec, cat, msg, code1, code2, backtrace); }

  void clear()
  {
    stl11::error_code::clear();
    _unique_id = (size_t) -1;
  }

  size_t extended_message(char *buffer, size_t len, unsigned &code1, unsigned &code2) const noexcept
  {
    auto &log = extended_error_code_log();
    if(!log.valid(unique_id(_unique_id)))
      return 0;
    auto &item = log[unique_id(_unique_id)];
    strncpy(buffer, item.message, len - 1);
    buffer[len - 1] = 0;
    code1 = item.code32[0];
    code2 = item.code32[1];
    if(!log.valid(unique_id(_unique_id)))
    {
      buffer[0] = 0;
      return 0;
    }
    return strlen(buffer);
  }

  size_t raw_backtrace(void **buffer, size_t len) const noexcept
  {
    auto &log = extended_error_code_log();
    if(!log.valid(unique_id(_unique_id)))
      return 0;
    auto &item = log[unique_id(_unique_id)];
    size_t written = 0;
    void **_backtrace = (void **) item.backtrace;
    for(size_t n = 0; n < len && n < sizeof(item.backtrace) / sizeof(item.backtrace[0]); n++)
    {
      buffer[n] = _backtrace[n];
      written++;
    }
    return written;
  }

  char **backtrace() const noexcept
  {
    auto &log = extended_error_code_log();
    if(!log.valid(unique_id(_unique_id)))
      return 0;
    auto &item = log[unique_id(_unique_id)];
    char **ret = nullptr;
    if(!item.using_backtrace)
    {
      ret = (char **) calloc(2 * sizeof(char *) + sizeof(item.function) + 1, 1);
      if(!ret)
        return nullptr;
      ret[0] = (char *) ret + 2 * sizeof(char *);
      strncpy(ret[0], item.function, sizeof(item.function));
      return ret;
    }
    else
      ret = backtrace_symbols((void **) item.backtrace, sizeof(item.backtrace) / sizeof(item.backtrace[0]));
    if(!log.valid(unique_id(_unique_id)))
    {
      free(ret);
      return 0;
    }
    return ret;
  }
};
#ifndef BOOST_OUTCOME_DISABLE_IOSTREAMS
inline std::ostream &operator<<(std::ostream &s, const error_code_extended &ec)
{
  s << ec.category().name() << " code " << ec.value() << ": " << ec.message();
  auto &log = extended_error_code_log();
  if(log.valid(error_code_extended::unique_id(ec._unique_id)))
  {
    auto &item = log[error_code_extended::unique_id(ec._unique_id)];
    s << " { " << item.message << ", " << item.code32[0] << ", " << item.code32[1] << " }";
  }
  return s;
}
#endif

} } }

#endif
#ifndef BOOST_OUTCOME_VALUE_STORAGE_H
#define BOOST_OUTCOME_VALUE_STORAGE_H



namespace boost { namespace outcome { inline namespace _1_0_std_std_b507c466 {


struct empty_t
{
  constexpr empty_t() {}
};


constexpr empty_t empty = empty_t();


struct value_t
{
  constexpr value_t() {}
};


constexpr value_t value = value_t();


struct error_t
{
  constexpr error_t() {}
};


constexpr error_t error = error_t();


struct exception_t
{
  constexpr exception_t() {}
};


constexpr exception_t exception = exception_t();


template <class _value_type> static constexpr bool enable_single_byte_value_storage = false;







#if defined(__GNUC__) && !defined(__clang__) && __GNUC__ < 7
#define BOOST_OUTCOME_DISABLE_DEFAULT_SINGLE_BYTE_VALUE_STORAGE
#endif
#ifndef BOOST_OUTCOME_DISABLE_DEFAULT_SINGLE_BYTE_VALUE_STORAGE
template <> constexpr bool enable_single_byte_value_storage<void> = true;
template <> constexpr bool enable_single_byte_value_storage<bool> = true;
#endif

namespace detail
{

  template <class _value_type> struct _enable_single_byte_value_storage
  {
    static constexpr bool value = enable_single_byte_value_storage<_value_type>;
  };

  template <bool enable, class P, class T, class S> struct do_change_state
  {
    BOOST_OUTCOME_CONSTEXPR do_change_state(P * , T && , S ) {}
    void dismiss() {}
  };
  template <class P, class T, class S> struct do_change_state<true, P, T, S>
  {

    P *_parent;
    T _old, *_prev;
    S _state;
    bool _success;
    BOOST_OUTCOME_CONSTEXPR do_change_state(P *parent, T &&existing, S state)
        : _parent(parent)
        , _old(std::move(existing))
        , _prev(&existing)
        , _state(state)
        , _success(false)
    {
    }
    void dismiss() { _success = true; }
    ~do_change_state()
    {
      if(!_success)
      {

        new(_prev) T(std::move(_old));
        _parent->type = _state;
      }
    }
  };
  template <bool disable, class P, class T, class U> void change_state(P *self, T &&existing, U &op)
  {
    auto state = self->type;
    do_change_state<!disable && ((std::is_move_constructible<T>::value && std::is_nothrow_move_constructible<T>::value) || (!std::is_move_constructible<T>::value && std::is_copy_constructible<T>::value && std::is_nothrow_copy_constructible<T>::value)), P, T, decltype(state)> restore(self, std::move(existing), state);
    op();
    restore.dismiss();
  }
#define BOOST_OUTCOME_VALUE_STORAGE_IMPL value_storage_impl_trivial
#define BOOST_OUTCOME_VALUE_STORAGE_NON_TRIVIAL_DESTRUCTOR 0
template <class _value_type, class _error_type, class _exception_type, bool use_single_byte = _enable_single_byte_value_storage<_value_type>::value> class value_storage_impl_trivial
{


  struct no_value_type
  {
  };
  struct no_error_type
  {
  };
  struct no_exception_type
  {
  };
  struct empty_type
  {
  };
  template <class U, class V> using devoid = typename std::conditional<!std::is_void<U>::value, U, V>::type;
  friend inline std::ostream &operator<<(std::ostream &s, const no_value_type &) { return s << "void"; }
public:
  static constexpr bool has_value_type = !std::is_void<_value_type>::value;
  static constexpr bool has_error_type = !std::is_void<_error_type>::value;
  static constexpr bool has_exception_type = !std::is_void<_exception_type>::value;
  static constexpr bool is_referenceable = true;
  static constexpr bool is_trivially_destructible = !0;
  typedef devoid<_value_type, no_value_type> value_type;
  typedef devoid<_error_type, no_error_type> error_type;
  typedef devoid<_exception_type, no_exception_type> exception_type;
  struct storage_type
  {
    enum storage_type_t : unsigned char
    {
      empty,
      value,
      error,
      exception
    };
  };
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4624)
#endif
  union {
    empty_type _empty;
    value_type value;
    error_type error;
    exception_type exception;
  };
#ifdef _MSC_VER
#pragma warning(pop)
#endif
  unsigned char type;


  static constexpr bool is_copy_constructible = (!has_value_type || std::is_copy_constructible<value_type>::value) && (!has_error_type || std::is_copy_constructible<error_type>::value) && (!has_exception_type || std::is_copy_constructible<exception_type>::value);
  static constexpr bool is_move_constructible = (!has_value_type || std::is_move_constructible<value_type>::value) && (!has_error_type || std::is_move_constructible<error_type>::value) && (!has_exception_type || std::is_move_constructible<exception_type>::value);
  static constexpr bool is_copy_assignable = (!has_value_type || std::is_copy_assignable<value_type>::value) && (!has_error_type || std::is_copy_assignable<error_type>::value) && (!has_exception_type || std::is_copy_assignable<exception_type>::value);
  static constexpr bool is_move_assignable = (!has_value_type || std::is_move_assignable<value_type>::value) && (!has_error_type || std::is_move_assignable<error_type>::value) && (!has_exception_type || std::is_move_assignable<exception_type>::value);

  static constexpr bool is_nothrow_copy_constructible = (!has_value_type || std::is_nothrow_copy_constructible<value_type>::value) && (!has_error_type || std::is_nothrow_copy_constructible<error_type>::value) && (!has_exception_type || std::is_nothrow_copy_constructible<exception_type>::value);
  static constexpr bool is_nothrow_move_constructible = (!has_value_type || std::is_nothrow_move_constructible<value_type>::value) && (!has_error_type || std::is_nothrow_move_constructible<error_type>::value) && (!has_exception_type || std::is_nothrow_move_constructible<exception_type>::value);
  static constexpr bool is_nothrow_copy_assignable = (!has_value_type || std::is_nothrow_copy_assignable<value_type>::value) && (!has_error_type || std::is_nothrow_copy_assignable<error_type>::value) && (!has_exception_type || std::is_nothrow_copy_assignable<exception_type>::value);
  static constexpr bool is_nothrow_move_assignable = (!has_value_type || std::is_nothrow_move_assignable<value_type>::value) && (!has_error_type || std::is_nothrow_move_assignable<error_type>::value) && (!has_exception_type || std::is_nothrow_move_assignable<exception_type>::value);
  static constexpr bool is_nothrow_destructible = std::is_nothrow_destructible<value_type>::value && std::is_nothrow_destructible<exception_type>::value && std::is_nothrow_destructible<error_type>::value;

  constexpr value_storage_impl_trivial() noexcept : _empty(empty_type()), type(storage_type::empty) {}
  constexpr value_storage_impl_trivial(empty_t) noexcept : _empty(empty_type()), type(storage_type::empty) {}
  constexpr value_storage_impl_trivial(value_t) noexcept(std::is_nothrow_default_constructible<value_type>::value)
      : value(value_type())
      , type(storage_type::value)
  {
  }
  constexpr value_storage_impl_trivial(error_t) noexcept(std::is_nothrow_default_constructible<error_type>::value)
      : error(error_type())
      , type(storage_type::error)
  {
  }
  constexpr value_storage_impl_trivial(exception_t) noexcept(std::is_nothrow_default_constructible<exception_type>::value)
      : exception(exception_type())
      , type(storage_type::exception)
  {
  }
  constexpr value_storage_impl_trivial(const value_type &v) noexcept(std::is_nothrow_copy_constructible<value_type>::value)
      : value(v)
      , type(storage_type::value)
  {
  }
  constexpr value_storage_impl_trivial(const error_type &v) noexcept(std::is_nothrow_copy_constructible<error_type>::value)
      : error(v)
      , type(storage_type::error)
  {
  }
  constexpr value_storage_impl_trivial(const exception_type &v) noexcept(std::is_nothrow_copy_constructible<exception_type>::value)
      : exception(v)
      , type(storage_type::exception)
  {
  }
  constexpr value_storage_impl_trivial(value_type &&v) noexcept(std::is_nothrow_move_constructible<value_type>::value)
      : value(std::move(v))
      , type(storage_type::value)
  {
  }
  constexpr value_storage_impl_trivial(error_type &&v) noexcept(std::is_nothrow_move_constructible<error_type>::value)
      : error(std::move(v))
      , type(storage_type::error)
  {
  }
  constexpr value_storage_impl_trivial(exception_type &&v) noexcept(std::is_nothrow_move_constructible<exception_type>::value)
      : exception(std::move(v))
      , type(storage_type::exception)
  {
  }
  struct emplace_t
  {
  };
  template <class... Args>
  constexpr explicit value_storage_impl_trivial(emplace_t, Args &&... args)
#if !defined(_MSC_VER) || _MSC_VER > 190022816
  noexcept(std::is_nothrow_constructible<value_type, Args...>::value)
#endif
      : value(std::forward<Args>(args)...)
      , type(storage_type::value)
  {
  }










  BOOST_OUTCOME_CONSTEXPR value_storage_impl_trivial(const value_storage_impl_trivial &o) noexcept(is_nothrow_copy_constructible)
      : _empty(empty_type())
      , type(storage_type::empty)
  {
    switch(o.type)
    {
    case storage_type::empty:
      break;
    case storage_type::value:
      new(&value) value_type(o.value);
      break;
    case storage_type::error:
      new(&error) error_type(o.error);
      break;
    case storage_type::exception:
      new(&exception) exception_type(o.exception);
      break;
    }
    type = o.type;
  }
  BOOST_OUTCOME_CONSTEXPR value_storage_impl_trivial(value_storage_impl_trivial &&o) noexcept(is_nothrow_move_constructible)
      : _empty(empty_type())
      , type(storage_type::empty)
  {
    switch(o.type)
    {
    case storage_type::empty:
      break;
    case storage_type::value:
      new(&value) value_type(std::move(o.value));
      break;
    case storage_type::error:
      new(&error) error_type(std::move(o.error));
      break;
    case storage_type::exception:
      new(&exception) exception_type(std::move(o.exception));
      break;
    }
    type = o.type;
  }
  BOOST_OUTCOME_CONSTEXPR value_storage_impl_trivial &operator=(const value_storage_impl_trivial &o) noexcept(is_nothrow_copy_assignable)
  {
    if(type == o.type)
    {

      switch(o.type)
      {
      case storage_type::empty:
        break;
      case storage_type::value:
        value = o.value;
        break;
      case storage_type::error:
        error = o.error;
        break;
      case storage_type::exception:
        exception = o.exception;
        break;
      }
    }
    else
    {
      auto do_op = [&] {
        clear();
        new(this) value_storage_impl_trivial(o);
      };
      switch(type)
      {
      case storage_type::empty:
        do_op();
        break;
      case storage_type::value:
        detail::change_state<is_nothrow_move_constructible>(this, std::move(value), do_op);
        break;
      case storage_type::error:
        detail::change_state<is_nothrow_move_constructible>(this, std::move(error), do_op);
        break;
      case storage_type::exception:
        detail::change_state<is_nothrow_move_constructible>(this, std::move(exception), do_op);
        break;
      }
    }
    return *this;
  }
  BOOST_OUTCOME_CONSTEXPR value_storage_impl_trivial &operator=(value_storage_impl_trivial &&o) noexcept(is_nothrow_move_assignable)
  {
    if(type == o.type)
    {

      switch(o.type)
      {
      case storage_type::empty:
        break;
      case storage_type::value:
        value = std::move(o.value);
        break;
      case storage_type::error:
        error = std::move(o.error);
        break;
      case storage_type::exception:
        exception = std::move(o.exception);
        break;
      }
    }
    else
    {
      auto do_op = [&] {
        clear();
        new(this) value_storage_impl_trivial(std::move(o));
      };
      switch(type)
      {
      case storage_type::empty:
        do_op();
        break;
      case storage_type::value:
        detail::change_state<is_nothrow_move_constructible>(this, std::move(value), do_op);
        break;
      case storage_type::error:
        detail::change_state<is_nothrow_move_constructible>(this, std::move(error), do_op);
        break;
      case storage_type::exception:
        detail::change_state<is_nothrow_move_constructible>(this, std::move(exception), do_op);
        break;
      }
    }
    return *this;
  }

  template <class... Args> BOOST_OUTCOME_CONSTEXPR void emplace_value(Args &&... args)
  {
    auto do_op = [&] {
      clear();
      new(&value) value_type(std::forward<Args>(args)...);
      type = storage_type::value;
    };
    switch(type)
    {
    case storage_type::empty:
      do_op();
      break;
    case storage_type::value:
      detail::change_state<is_nothrow_move_constructible>(this, std::move(value), do_op);
      break;
    case storage_type::error:
      detail::change_state<is_nothrow_move_constructible>(this, std::move(error), do_op);
      break;
    case storage_type::exception:
      detail::change_state<is_nothrow_move_constructible>(this, std::move(exception), do_op);
      break;
    }
  }
  template <class... Args> BOOST_OUTCOME_CONSTEXPR void emplace_error(Args &&... args)
  {
    auto do_op = [&] {
      clear();
      new(&error) error_type(std::forward<Args>(args)...);
      type = storage_type::error;
    };
    switch(type)
    {
    case storage_type::empty:
      do_op();
      break;
    case storage_type::value:
      detail::change_state<is_nothrow_move_constructible>(this, std::move(value), do_op);
      break;
    case storage_type::error:
      detail::change_state<is_nothrow_move_constructible>(this, std::move(error), do_op);
      break;
    case storage_type::exception:
      detail::change_state<is_nothrow_move_constructible>(this, std::move(exception), do_op);
      break;
    }
  }
  template <class... Args> BOOST_OUTCOME_CONSTEXPR void emplace_exception(Args &&... args)
  {
    auto do_op = [&] {
      clear();
      new(&exception) exception_type(std::forward<Args>(args)...);
      type = storage_type::exception;
    };
    switch(type)
    {
    case storage_type::empty:
      do_op();
      break;
    case storage_type::value:
      detail::change_state<is_nothrow_move_constructible>(this, std::move(value), do_op);
      break;
    case storage_type::error:
      detail::change_state<is_nothrow_move_constructible>(this, std::move(error), do_op);
      break;
    case storage_type::exception:
      detail::change_state<is_nothrow_move_constructible>(this, std::move(exception), do_op);
      break;
    }
  }
  BOOST_OUTCOME_CONSTEXPR void clear() noexcept(is_nothrow_destructible)
  {
    switch(type)
    {
    case storage_type::empty:
      break;
    case storage_type::value:
      value.~value_type();
      type = storage_type::empty;
      break;
    case storage_type::error:
      error.~error_type();
      type = storage_type::empty;
      break;
    case storage_type::exception:
      exception.~exception_type();
      type = storage_type::empty;
      break;
    }
  }
};

#ifndef BOOST_OUTCOME_VALUE_STORAGE_IMPL_PACKED_INITIALISER
#if defined(__BYTE_ORDER__)
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#define BOOST_OUTCOME_VALUE_STORAGE_IMPL_PACKED_INITIALISER(t, v) ((((unsigned char) (v)) & 0x3f) | ((((t) &0x3)) << 6))
#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#error Unsure if endianness affects bits in a byte, you need to test and send a pull request on github
#endif
#endif
#ifndef BOOST_OUTCOME_VALUE_STORAGE_IMPL_PACKED_INITIALISER
#ifdef _MSC_VER
#define BOOST_OUTCOME_VALUE_STORAGE_IMPL_PACKED_INITIALISER(t, v) ((((unsigned char) (v)) & 0x3f) | ((((t) &0x3)) << 6))
#else
#error Could not figure out the endianness of this platform
#endif
#endif
#endif
template <class _value_type> class value_storage_impl_trivial<_value_type, void, void, true>
{
  static_assert(std::is_integral<_value_type>::value || std::is_void<_value_type>::value, "Types enabled for packed storage using enable_single_byte_value_storage must be integral types.");


  struct no_error_type
  {
  };
  struct no_exception_type
  {
  };
  struct empty_type
  {
  };
  template <class U, class V> using devoid = typename std::conditional<!std::is_void<U>::value, U, V>::type;

public:
  static constexpr bool has_value_type = !std::is_void<_value_type>::value;
  static constexpr bool has_error_type = false;
  static constexpr bool has_exception_type = false;
  static constexpr bool is_referenceable = false;
  static constexpr bool is_trivially_destructible = !0;
  typedef devoid<_value_type, unsigned char> value_type;
  typedef no_error_type error_type;
  typedef no_exception_type exception_type;
  struct storage_type
  {
    enum storage_type_t : unsigned char
    {
      empty,
      value,
      error,
      exception
    };
  };
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4624 4201)
#endif
  union {
    empty_type _empty;
    unsigned char _value_raw;
    struct
    {
      unsigned char value : 6;
      unsigned char type : 2;
    };
    error_type error;
    exception_type exception;
  };
#ifdef _MSC_VER
#pragma warning(pop)
#endif


  static constexpr bool is_copy_constructible = (!has_value_type || std::is_copy_constructible<value_type>::value) && (!has_error_type || std::is_copy_constructible<error_type>::value) && (!has_exception_type || std::is_copy_constructible<exception_type>::value);
  static constexpr bool is_move_constructible = (!has_value_type || std::is_move_constructible<value_type>::value) && (!has_error_type || std::is_move_constructible<error_type>::value) && (!has_exception_type || std::is_move_constructible<exception_type>::value);
  static constexpr bool is_copy_assignable = (!has_value_type || std::is_copy_assignable<value_type>::value) && (!has_error_type || std::is_copy_assignable<error_type>::value) && (!has_exception_type || std::is_copy_assignable<exception_type>::value);
  static constexpr bool is_move_assignable = (!has_value_type || std::is_move_assignable<value_type>::value) && (!has_error_type || std::is_move_assignable<error_type>::value) && (!has_exception_type || std::is_move_assignable<exception_type>::value);

  static constexpr bool is_nothrow_copy_constructible = (!has_value_type || std::is_nothrow_copy_constructible<value_type>::value) && (!has_error_type || std::is_nothrow_copy_constructible<error_type>::value) && (!has_exception_type || std::is_nothrow_copy_constructible<exception_type>::value);
  static constexpr bool is_nothrow_move_constructible = (!has_value_type || std::is_nothrow_move_constructible<value_type>::value) && (!has_error_type || std::is_nothrow_move_constructible<error_type>::value) && (!has_exception_type || std::is_nothrow_move_constructible<exception_type>::value);
  static constexpr bool is_nothrow_copy_assignable = (!has_value_type || std::is_nothrow_copy_assignable<value_type>::value) && (!has_error_type || std::is_nothrow_copy_assignable<error_type>::value) && (!has_exception_type || std::is_nothrow_copy_assignable<exception_type>::value);
  static constexpr bool is_nothrow_move_assignable = (!has_value_type || std::is_nothrow_move_assignable<value_type>::value) && (!has_error_type || std::is_nothrow_move_assignable<error_type>::value) && (!has_exception_type || std::is_nothrow_move_assignable<exception_type>::value);
  static constexpr bool is_nothrow_destructible = std::is_nothrow_destructible<value_type>::value && std::is_nothrow_destructible<exception_type>::value && std::is_nothrow_destructible<error_type>::value;

  constexpr value_storage_impl_trivial()
      : _value_raw(BOOST_OUTCOME_VALUE_STORAGE_IMPL_PACKED_INITIALISER(storage_type::empty, 0))
  {
  }
  constexpr value_storage_impl_trivial(empty_t) noexcept : _value_raw(BOOST_OUTCOME_VALUE_STORAGE_IMPL_PACKED_INITIALISER(storage_type::empty, 0)) {}
  constexpr value_storage_impl_trivial(value_t) noexcept(std::is_nothrow_default_constructible<value_type>::value)
      : _value_raw(BOOST_OUTCOME_VALUE_STORAGE_IMPL_PACKED_INITIALISER(storage_type::value, 0))
  {
  }
  constexpr value_storage_impl_trivial(error_t) noexcept(std::is_nothrow_default_constructible<error_type>::value)
      : _value_raw(BOOST_OUTCOME_VALUE_STORAGE_IMPL_PACKED_INITIALISER(storage_type::error, 0))
  {
  }
  constexpr value_storage_impl_trivial(exception_t) noexcept(std::is_nothrow_default_constructible<exception_type>::value)
      : _value_raw(BOOST_OUTCOME_VALUE_STORAGE_IMPL_PACKED_INITIALISER(storage_type::exception, 0))
  {
  }
  constexpr value_storage_impl_trivial(const value_type &v) noexcept(std::is_nothrow_copy_constructible<value_type>::value)
      : _value_raw(BOOST_OUTCOME_VALUE_STORAGE_IMPL_PACKED_INITIALISER(storage_type::value, v))
  {
  }
  constexpr value_storage_impl_trivial(const error_type &) noexcept(std::is_nothrow_copy_constructible<error_type>::value)
      : _value_raw(BOOST_OUTCOME_VALUE_STORAGE_IMPL_PACKED_INITIALISER(storage_type::error, 0))
  {
  }
  constexpr value_storage_impl_trivial(const exception_type &) noexcept(std::is_nothrow_copy_constructible<exception_type>::value)
      : _value_raw(BOOST_OUTCOME_VALUE_STORAGE_IMPL_PACKED_INITIALISER(storage_type::exception, 0))
  {
  }
  constexpr value_storage_impl_trivial(value_type &&v) noexcept(std::is_nothrow_move_constructible<value_type>::value)
      : _value_raw(BOOST_OUTCOME_VALUE_STORAGE_IMPL_PACKED_INITIALISER(storage_type::value, v))
  {
  }
  constexpr value_storage_impl_trivial(error_type &&) noexcept(std::is_nothrow_move_constructible<error_type>::value)
      : _value_raw(BOOST_OUTCOME_VALUE_STORAGE_IMPL_PACKED_INITIALISER(storage_type::error, 0))
  {
  }
  constexpr value_storage_impl_trivial(exception_type &&) noexcept(std::is_nothrow_move_constructible<exception_type>::value)
      : _value_raw(BOOST_OUTCOME_VALUE_STORAGE_IMPL_PACKED_INITIALISER(storage_type::exception, 0))
  {
  }
  struct emplace_t
  {
  };
  template <class... Args>
  BOOST_OUTCOME_CONSTEXPR explicit value_storage_impl_trivial(emplace_t, Args &&... args) noexcept(std::is_nothrow_constructible<value_type, Args...>::value)
      : value(std::forward<Args>(args)...)
  {
    type = storage_type::value;
  }



  template <class... Args> BOOST_OUTCOME_CONSTEXPR void emplace_value(Args &&... args)
  {
    clear();
    value = value_type(std::forward<Args>(args)...);
    type = storage_type::value;
  }
  BOOST_OUTCOME_CONSTEXPR void clear() noexcept(is_nothrow_destructible)
  {
    switch(type)
    {
    case storage_type::empty:
      break;
    default:
      type = storage_type::empty;
      break;
    }
  }
};
#undef BOOST_OUTCOME_VALUE_STORAGE_IMPL
#undef BOOST_OUTCOME_VALUE_STORAGE_NON_TRIVIAL_DESTRUCTOR

#define BOOST_OUTCOME_VALUE_STORAGE_IMPL value_storage_impl_nontrivial
#define BOOST_OUTCOME_VALUE_STORAGE_NON_TRIVIAL_DESTRUCTOR 1
template <class _value_type, class _error_type, class _exception_type, bool use_single_byte = _enable_single_byte_value_storage<_value_type>::value> class value_storage_impl_nontrivial
{


  struct no_value_type
  {
  };
  struct no_error_type
  {
  };
  struct no_exception_type
  {
  };
  struct empty_type
  {
  };
  template <class U, class V> using devoid = typename std::conditional<!std::is_void<U>::value, U, V>::type;
  friend inline std::ostream &operator<<(std::ostream &s, const no_value_type &) { return s << "void"; }
public:
  static constexpr bool has_value_type = !std::is_void<_value_type>::value;
  static constexpr bool has_error_type = !std::is_void<_error_type>::value;
  static constexpr bool has_exception_type = !std::is_void<_exception_type>::value;
  static constexpr bool is_referenceable = true;
  static constexpr bool is_trivially_destructible = !1;
  typedef devoid<_value_type, no_value_type> value_type;
  typedef devoid<_error_type, no_error_type> error_type;
  typedef devoid<_exception_type, no_exception_type> exception_type;
  struct storage_type
  {
    enum storage_type_t : unsigned char
    {
      empty,
      value,
      error,
      exception
    };
  };
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4624)
#endif
  union {
    empty_type _empty;
    value_type value;
    error_type error;
    exception_type exception;
  };
#ifdef _MSC_VER
#pragma warning(pop)
#endif
  unsigned char type;


  static constexpr bool is_copy_constructible = (!has_value_type || std::is_copy_constructible<value_type>::value) && (!has_error_type || std::is_copy_constructible<error_type>::value) && (!has_exception_type || std::is_copy_constructible<exception_type>::value);
  static constexpr bool is_move_constructible = (!has_value_type || std::is_move_constructible<value_type>::value) && (!has_error_type || std::is_move_constructible<error_type>::value) && (!has_exception_type || std::is_move_constructible<exception_type>::value);
  static constexpr bool is_copy_assignable = (!has_value_type || std::is_copy_assignable<value_type>::value) && (!has_error_type || std::is_copy_assignable<error_type>::value) && (!has_exception_type || std::is_copy_assignable<exception_type>::value);
  static constexpr bool is_move_assignable = (!has_value_type || std::is_move_assignable<value_type>::value) && (!has_error_type || std::is_move_assignable<error_type>::value) && (!has_exception_type || std::is_move_assignable<exception_type>::value);

  static constexpr bool is_nothrow_copy_constructible = (!has_value_type || std::is_nothrow_copy_constructible<value_type>::value) && (!has_error_type || std::is_nothrow_copy_constructible<error_type>::value) && (!has_exception_type || std::is_nothrow_copy_constructible<exception_type>::value);
  static constexpr bool is_nothrow_move_constructible = (!has_value_type || std::is_nothrow_move_constructible<value_type>::value) && (!has_error_type || std::is_nothrow_move_constructible<error_type>::value) && (!has_exception_type || std::is_nothrow_move_constructible<exception_type>::value);
  static constexpr bool is_nothrow_copy_assignable = (!has_value_type || std::is_nothrow_copy_assignable<value_type>::value) && (!has_error_type || std::is_nothrow_copy_assignable<error_type>::value) && (!has_exception_type || std::is_nothrow_copy_assignable<exception_type>::value);
  static constexpr bool is_nothrow_move_assignable = (!has_value_type || std::is_nothrow_move_assignable<value_type>::value) && (!has_error_type || std::is_nothrow_move_assignable<error_type>::value) && (!has_exception_type || std::is_nothrow_move_assignable<exception_type>::value);
  static constexpr bool is_nothrow_destructible = std::is_nothrow_destructible<value_type>::value && std::is_nothrow_destructible<exception_type>::value && std::is_nothrow_destructible<error_type>::value;

  constexpr value_storage_impl_nontrivial() noexcept : _empty(empty_type()), type(storage_type::empty) {}
  constexpr value_storage_impl_nontrivial(empty_t) noexcept : _empty(empty_type()), type(storage_type::empty) {}
  constexpr value_storage_impl_nontrivial(value_t) noexcept(std::is_nothrow_default_constructible<value_type>::value)
      : value(value_type())
      , type(storage_type::value)
  {
  }
  constexpr value_storage_impl_nontrivial(error_t) noexcept(std::is_nothrow_default_constructible<error_type>::value)
      : error(error_type())
      , type(storage_type::error)
  {
  }
  constexpr value_storage_impl_nontrivial(exception_t) noexcept(std::is_nothrow_default_constructible<exception_type>::value)
      : exception(exception_type())
      , type(storage_type::exception)
  {
  }
  constexpr value_storage_impl_nontrivial(const value_type &v) noexcept(std::is_nothrow_copy_constructible<value_type>::value)
      : value(v)
      , type(storage_type::value)
  {
  }
  constexpr value_storage_impl_nontrivial(const error_type &v) noexcept(std::is_nothrow_copy_constructible<error_type>::value)
      : error(v)
      , type(storage_type::error)
  {
  }
  constexpr value_storage_impl_nontrivial(const exception_type &v) noexcept(std::is_nothrow_copy_constructible<exception_type>::value)
      : exception(v)
      , type(storage_type::exception)
  {
  }
  constexpr value_storage_impl_nontrivial(value_type &&v) noexcept(std::is_nothrow_move_constructible<value_type>::value)
      : value(std::move(v))
      , type(storage_type::value)
  {
  }
  constexpr value_storage_impl_nontrivial(error_type &&v) noexcept(std::is_nothrow_move_constructible<error_type>::value)
      : error(std::move(v))
      , type(storage_type::error)
  {
  }
  constexpr value_storage_impl_nontrivial(exception_type &&v) noexcept(std::is_nothrow_move_constructible<exception_type>::value)
      : exception(std::move(v))
      , type(storage_type::exception)
  {
  }
  struct emplace_t
  {
  };
  template <class... Args>
  constexpr explicit value_storage_impl_nontrivial(emplace_t, Args &&... args)
#if !defined(_MSC_VER) || _MSC_VER > 190022816
  noexcept(std::is_nothrow_constructible<value_type, Args...>::value)
#endif
      : value(std::forward<Args>(args)...)
      , type(storage_type::value)
  {
  }

  ~value_storage_impl_nontrivial()
#if defined(__c2__) || (!defined(_MSC_VER) || (_MSC_FULL_VER != 191025017 && _MSC_FULL_VER != 191025019 ))
  noexcept(is_nothrow_destructible)
#endif
  {
    clear();
  }


  BOOST_OUTCOME_CONSTEXPR value_storage_impl_nontrivial(const value_storage_impl_nontrivial &o) noexcept(is_nothrow_copy_constructible)
      : _empty(empty_type())
      , type(storage_type::empty)
  {
    switch(o.type)
    {
    case storage_type::empty:
      break;
    case storage_type::value:
      new(&value) value_type(o.value);
      break;
    case storage_type::error:
      new(&error) error_type(o.error);
      break;
    case storage_type::exception:
      new(&exception) exception_type(o.exception);
      break;
    }
    type = o.type;
  }
  BOOST_OUTCOME_CONSTEXPR value_storage_impl_nontrivial(value_storage_impl_nontrivial &&o) noexcept(is_nothrow_move_constructible)
      : _empty(empty_type())
      , type(storage_type::empty)
  {
    switch(o.type)
    {
    case storage_type::empty:
      break;
    case storage_type::value:
      new(&value) value_type(std::move(o.value));
      break;
    case storage_type::error:
      new(&error) error_type(std::move(o.error));
      break;
    case storage_type::exception:
      new(&exception) exception_type(std::move(o.exception));
      break;
    }
    type = o.type;
  }
  BOOST_OUTCOME_CONSTEXPR value_storage_impl_nontrivial &operator=(const value_storage_impl_nontrivial &o) noexcept(is_nothrow_copy_assignable)
  {
    if(type == o.type)
    {

      switch(o.type)
      {
      case storage_type::empty:
        break;
      case storage_type::value:
        value = o.value;
        break;
      case storage_type::error:
        error = o.error;
        break;
      case storage_type::exception:
        exception = o.exception;
        break;
      }
    }
    else
    {
      auto do_op = [&] {
        clear();
        new(this) value_storage_impl_nontrivial(o);
      };
      switch(type)
      {
      case storage_type::empty:
        do_op();
        break;
      case storage_type::value:
        detail::change_state<is_nothrow_move_constructible>(this, std::move(value), do_op);
        break;
      case storage_type::error:
        detail::change_state<is_nothrow_move_constructible>(this, std::move(error), do_op);
        break;
      case storage_type::exception:
        detail::change_state<is_nothrow_move_constructible>(this, std::move(exception), do_op);
        break;
      }
    }
    return *this;
  }
  BOOST_OUTCOME_CONSTEXPR value_storage_impl_nontrivial &operator=(value_storage_impl_nontrivial &&o) noexcept(is_nothrow_move_assignable)
  {
    if(type == o.type)
    {

      switch(o.type)
      {
      case storage_type::empty:
        break;
      case storage_type::value:
        value = std::move(o.value);
        break;
      case storage_type::error:
        error = std::move(o.error);
        break;
      case storage_type::exception:
        exception = std::move(o.exception);
        break;
      }
    }
    else
    {
      auto do_op = [&] {
        clear();
        new(this) value_storage_impl_nontrivial(std::move(o));
      };
      switch(type)
      {
      case storage_type::empty:
        do_op();
        break;
      case storage_type::value:
        detail::change_state<is_nothrow_move_constructible>(this, std::move(value), do_op);
        break;
      case storage_type::error:
        detail::change_state<is_nothrow_move_constructible>(this, std::move(error), do_op);
        break;
      case storage_type::exception:
        detail::change_state<is_nothrow_move_constructible>(this, std::move(exception), do_op);
        break;
      }
    }
    return *this;
  }

  template <class... Args> BOOST_OUTCOME_CONSTEXPR void emplace_value(Args &&... args)
  {
    auto do_op = [&] {
      clear();
      new(&value) value_type(std::forward<Args>(args)...);
      type = storage_type::value;
    };
    switch(type)
    {
    case storage_type::empty:
      do_op();
      break;
    case storage_type::value:
      detail::change_state<is_nothrow_move_constructible>(this, std::move(value), do_op);
      break;
    case storage_type::error:
      detail::change_state<is_nothrow_move_constructible>(this, std::move(error), do_op);
      break;
    case storage_type::exception:
      detail::change_state<is_nothrow_move_constructible>(this, std::move(exception), do_op);
      break;
    }
  }
  template <class... Args> BOOST_OUTCOME_CONSTEXPR void emplace_error(Args &&... args)
  {
    auto do_op = [&] {
      clear();
      new(&error) error_type(std::forward<Args>(args)...);
      type = storage_type::error;
    };
    switch(type)
    {
    case storage_type::empty:
      do_op();
      break;
    case storage_type::value:
      detail::change_state<is_nothrow_move_constructible>(this, std::move(value), do_op);
      break;
    case storage_type::error:
      detail::change_state<is_nothrow_move_constructible>(this, std::move(error), do_op);
      break;
    case storage_type::exception:
      detail::change_state<is_nothrow_move_constructible>(this, std::move(exception), do_op);
      break;
    }
  }
  template <class... Args> BOOST_OUTCOME_CONSTEXPR void emplace_exception(Args &&... args)
  {
    auto do_op = [&] {
      clear();
      new(&exception) exception_type(std::forward<Args>(args)...);
      type = storage_type::exception;
    };
    switch(type)
    {
    case storage_type::empty:
      do_op();
      break;
    case storage_type::value:
      detail::change_state<is_nothrow_move_constructible>(this, std::move(value), do_op);
      break;
    case storage_type::error:
      detail::change_state<is_nothrow_move_constructible>(this, std::move(error), do_op);
      break;
    case storage_type::exception:
      detail::change_state<is_nothrow_move_constructible>(this, std::move(exception), do_op);
      break;
    }
  }
  BOOST_OUTCOME_CONSTEXPR void clear() noexcept(is_nothrow_destructible)
  {
    switch(type)
    {
    case storage_type::empty:
      break;
    case storage_type::value:
      value.~value_type();
      type = storage_type::empty;
      break;
    case storage_type::error:
      error.~error_type();
      type = storage_type::empty;
      break;
    case storage_type::exception:
      exception.~exception_type();
      type = storage_type::empty;
      break;
    }
  }
};

#ifndef BOOST_OUTCOME_VALUE_STORAGE_IMPL_PACKED_INITIALISER
#if defined(__BYTE_ORDER__)
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
#define BOOST_OUTCOME_VALUE_STORAGE_IMPL_PACKED_INITIALISER(t, v) ((((unsigned char) (v)) & 0x3f) | ((((t) &0x3)) << 6))
#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#error Unsure if endianness affects bits in a byte, you need to test and send a pull request on github
#endif
#endif
#ifndef BOOST_OUTCOME_VALUE_STORAGE_IMPL_PACKED_INITIALISER
#ifdef _MSC_VER
#define BOOST_OUTCOME_VALUE_STORAGE_IMPL_PACKED_INITIALISER(t, v) ((((unsigned char) (v)) & 0x3f) | ((((t) &0x3)) << 6))
#else
#error Could not figure out the endianness of this platform
#endif
#endif
#endif
template <class _value_type> class value_storage_impl_nontrivial<_value_type, void, void, true>
{
  static_assert(std::is_integral<_value_type>::value || std::is_void<_value_type>::value, "Types enabled for packed storage using enable_single_byte_value_storage must be integral types.");


  struct no_error_type
  {
  };
  struct no_exception_type
  {
  };
  struct empty_type
  {
  };
  template <class U, class V> using devoid = typename std::conditional<!std::is_void<U>::value, U, V>::type;

public:
  static constexpr bool has_value_type = !std::is_void<_value_type>::value;
  static constexpr bool has_error_type = false;
  static constexpr bool has_exception_type = false;
  static constexpr bool is_referenceable = false;
  static constexpr bool is_trivially_destructible = !1;
  typedef devoid<_value_type, unsigned char> value_type;
  typedef no_error_type error_type;
  typedef no_exception_type exception_type;
  struct storage_type
  {
    enum storage_type_t : unsigned char
    {
      empty,
      value,
      error,
      exception
    };
  };
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4624 4201)
#endif
  union {
    empty_type _empty;
    unsigned char _value_raw;
    struct
    {
      unsigned char value : 6;
      unsigned char type : 2;
    };
    error_type error;
    exception_type exception;
  };
#ifdef _MSC_VER
#pragma warning(pop)
#endif


  static constexpr bool is_copy_constructible = (!has_value_type || std::is_copy_constructible<value_type>::value) && (!has_error_type || std::is_copy_constructible<error_type>::value) && (!has_exception_type || std::is_copy_constructible<exception_type>::value);
  static constexpr bool is_move_constructible = (!has_value_type || std::is_move_constructible<value_type>::value) && (!has_error_type || std::is_move_constructible<error_type>::value) && (!has_exception_type || std::is_move_constructible<exception_type>::value);
  static constexpr bool is_copy_assignable = (!has_value_type || std::is_copy_assignable<value_type>::value) && (!has_error_type || std::is_copy_assignable<error_type>::value) && (!has_exception_type || std::is_copy_assignable<exception_type>::value);
  static constexpr bool is_move_assignable = (!has_value_type || std::is_move_assignable<value_type>::value) && (!has_error_type || std::is_move_assignable<error_type>::value) && (!has_exception_type || std::is_move_assignable<exception_type>::value);

  static constexpr bool is_nothrow_copy_constructible = (!has_value_type || std::is_nothrow_copy_constructible<value_type>::value) && (!has_error_type || std::is_nothrow_copy_constructible<error_type>::value) && (!has_exception_type || std::is_nothrow_copy_constructible<exception_type>::value);
  static constexpr bool is_nothrow_move_constructible = (!has_value_type || std::is_nothrow_move_constructible<value_type>::value) && (!has_error_type || std::is_nothrow_move_constructible<error_type>::value) && (!has_exception_type || std::is_nothrow_move_constructible<exception_type>::value);
  static constexpr bool is_nothrow_copy_assignable = (!has_value_type || std::is_nothrow_copy_assignable<value_type>::value) && (!has_error_type || std::is_nothrow_copy_assignable<error_type>::value) && (!has_exception_type || std::is_nothrow_copy_assignable<exception_type>::value);
  static constexpr bool is_nothrow_move_assignable = (!has_value_type || std::is_nothrow_move_assignable<value_type>::value) && (!has_error_type || std::is_nothrow_move_assignable<error_type>::value) && (!has_exception_type || std::is_nothrow_move_assignable<exception_type>::value);
  static constexpr bool is_nothrow_destructible = std::is_nothrow_destructible<value_type>::value && std::is_nothrow_destructible<exception_type>::value && std::is_nothrow_destructible<error_type>::value;

  constexpr value_storage_impl_nontrivial()
      : _value_raw(BOOST_OUTCOME_VALUE_STORAGE_IMPL_PACKED_INITIALISER(storage_type::empty, 0))
  {
  }
  constexpr value_storage_impl_nontrivial(empty_t) noexcept : _value_raw(BOOST_OUTCOME_VALUE_STORAGE_IMPL_PACKED_INITIALISER(storage_type::empty, 0)) {}
  constexpr value_storage_impl_nontrivial(value_t) noexcept(std::is_nothrow_default_constructible<value_type>::value)
      : _value_raw(BOOST_OUTCOME_VALUE_STORAGE_IMPL_PACKED_INITIALISER(storage_type::value, 0))
  {
  }
  constexpr value_storage_impl_nontrivial(error_t) noexcept(std::is_nothrow_default_constructible<error_type>::value)
      : _value_raw(BOOST_OUTCOME_VALUE_STORAGE_IMPL_PACKED_INITIALISER(storage_type::error, 0))
  {
  }
  constexpr value_storage_impl_nontrivial(exception_t) noexcept(std::is_nothrow_default_constructible<exception_type>::value)
      : _value_raw(BOOST_OUTCOME_VALUE_STORAGE_IMPL_PACKED_INITIALISER(storage_type::exception, 0))
  {
  }
  constexpr value_storage_impl_nontrivial(const value_type &v) noexcept(std::is_nothrow_copy_constructible<value_type>::value)
      : _value_raw(BOOST_OUTCOME_VALUE_STORAGE_IMPL_PACKED_INITIALISER(storage_type::value, v))
  {
  }
  constexpr value_storage_impl_nontrivial(const error_type &) noexcept(std::is_nothrow_copy_constructible<error_type>::value)
      : _value_raw(BOOST_OUTCOME_VALUE_STORAGE_IMPL_PACKED_INITIALISER(storage_type::error, 0))
  {
  }
  constexpr value_storage_impl_nontrivial(const exception_type &) noexcept(std::is_nothrow_copy_constructible<exception_type>::value)
      : _value_raw(BOOST_OUTCOME_VALUE_STORAGE_IMPL_PACKED_INITIALISER(storage_type::exception, 0))
  {
  }
  constexpr value_storage_impl_nontrivial(value_type &&v) noexcept(std::is_nothrow_move_constructible<value_type>::value)
      : _value_raw(BOOST_OUTCOME_VALUE_STORAGE_IMPL_PACKED_INITIALISER(storage_type::value, v))
  {
  }
  constexpr value_storage_impl_nontrivial(error_type &&) noexcept(std::is_nothrow_move_constructible<error_type>::value)
      : _value_raw(BOOST_OUTCOME_VALUE_STORAGE_IMPL_PACKED_INITIALISER(storage_type::error, 0))
  {
  }
  constexpr value_storage_impl_nontrivial(exception_type &&) noexcept(std::is_nothrow_move_constructible<exception_type>::value)
      : _value_raw(BOOST_OUTCOME_VALUE_STORAGE_IMPL_PACKED_INITIALISER(storage_type::exception, 0))
  {
  }
  struct emplace_t
  {
  };
  template <class... Args>
  BOOST_OUTCOME_CONSTEXPR explicit value_storage_impl_nontrivial(emplace_t, Args &&... args) noexcept(std::is_nothrow_constructible<value_type, Args...>::value)
      : value(std::forward<Args>(args)...)
  {
    type = storage_type::value;
  }

  ~value_storage_impl_nontrivial() noexcept(is_nothrow_destructible) { clear(); }

  template <class... Args> BOOST_OUTCOME_CONSTEXPR void emplace_value(Args &&... args)
  {
    clear();
    value = value_type(std::forward<Args>(args)...);
    type = storage_type::value;
  }
  BOOST_OUTCOME_CONSTEXPR void clear() noexcept(is_nothrow_destructible)
  {
    switch(type)
    {
    case storage_type::empty:
      break;
    default:
      type = storage_type::empty;
      break;
    }
  }
};
#undef BOOST_OUTCOME_VALUE_STORAGE_IMPL
#undef BOOST_OUTCOME_VALUE_STORAGE_NON_TRIVIAL_DESTRUCTOR

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 6287)
#endif
  template <class _value_type, class _error_type, class _exception_type>
  static constexpr bool can_have_trivial_destructor = (std::is_literal_type<_value_type>::value || std::is_trivially_destructible<_value_type>::value) && (std::is_literal_type<_error_type>::value || std::is_trivially_destructible<_error_type>::value) &&
                                                      (std::is_literal_type<_exception_type>::value || std::is_trivially_destructible<_exception_type>::value);
#ifdef _MSC_VER
#pragma warning(pop)
#endif
  template <bool enable> struct emplace_value_if
  {
    template <class U, class V> BOOST_OUTCOME_CONSTEXPR emplace_value_if(U *v, V &&o) { v->emplace_value(std::forward<V>(o)); }
  };
  template <> struct emplace_value_if<false>
  {
    template <class U, class V> BOOST_OUTCOME_CONSTEXPR emplace_value_if(U *v, V &&) { v->emplace_value(); }
  };
  template <bool enable> struct emplace_error_if
  {
    template <class U, class V> BOOST_OUTCOME_CONSTEXPR emplace_error_if(U *v, V &&o) { v->emplace_error(std::forward<V>(o)); }
  };
  template <> struct emplace_error_if<false>
  {
    template <class U, class V> BOOST_OUTCOME_CONSTEXPR emplace_error_if(U *v, V &&) { v->emplace_error(); }
  };
  template <bool enable> struct emplace_exception_if
  {
    template <class U, class V> BOOST_OUTCOME_CONSTEXPR emplace_exception_if(U *v, V &&o) { v->emplace_exception(std::forward<V>(o)); }
  };
  template <> struct emplace_exception_if<false>
  {
    template <class U, class V> BOOST_OUTCOME_CONSTEXPR emplace_exception_if(U *v, V &&) { v->emplace_exception(); }
  };

  template <bool enable, class U, class V> struct compare_if_impl
  {
    bool operator()(const U &v, const V &o) const { return v == o; }
  };
  template <class U, class V> struct compare_if_impl<false, U, V>
  {
    bool operator()(const U &, const V &) const { return false; }
  };
  template <bool enable, class U, class V> inline bool compare_if(const U &v, const V &o) { return compare_if_impl<enable, U, V>()(v, o); }
}














template <class _value_type, class _error_type, class _exception_type>
class value_storage : public std::conditional<detail::can_have_trivial_destructor<_value_type, _error_type, _exception_type>, detail::value_storage_impl_trivial<_value_type, _error_type, _exception_type>, detail::value_storage_impl_nontrivial<_value_type, _error_type, _exception_type>>::type
{
  using base = typename std::conditional<detail::can_have_trivial_destructor<_value_type, _error_type, _exception_type>, detail::value_storage_impl_trivial<_value_type, _error_type, _exception_type>, detail::value_storage_impl_nontrivial<_value_type, _error_type, _exception_type>>::type;

public:
  static constexpr bool has_value_type = base::has_value_type;
  static constexpr bool has_error_type = base::has_error_type;
  static constexpr bool has_exception_type = base::has_exception_type;
  using value_type = typename base::value_type;
  using error_type = typename base::error_type;
  using exception_type = typename base::exception_type;
  using storage_type = typename base::storage_type;
  using base::clear;
  static_assert(!std::is_same<value_type, error_type>::value, "value_type and error_type cannot be the same type");
  static_assert(!std::is_same<value_type, exception_type>::value, "value_type and exception_type cannot be the same type");
  static_assert(!std::is_same<error_type, exception_type>::value, "error_type and exception_type cannot be the same type");





  static constexpr bool is_nothrow_move_constructible = base::is_nothrow_move_constructible;
  static constexpr bool is_nothrow_copy_constructible = base::is_nothrow_copy_constructible;
  static constexpr bool is_nothrow_move_assignable = base::is_nothrow_move_assignable;
  static constexpr bool is_nothrow_copy_assignable = base::is_nothrow_copy_assignable;
  static constexpr bool is_nothrow_destructible = base::is_nothrow_destructible;

#if (defined(_MSC_VER) && _MSC_FULL_VER > 191025019 ) || __clang_major__ >= 4 || (__clang_major__ == 3 && __clang_minor__ >= 8)
  template <class _value_type2> static constexpr bool value_type_is_constructible_from = std::is_same<_value_type, _value_type2>::value || std::is_void<_value_type2>::value || std::is_constructible<_value_type, _value_type2>::value;
  template <class _error_type2> static constexpr bool error_type_is_constructible_from = std::is_void<_error_type2>::value || std::is_same<_error_type, _error_type2>::value || std::is_constructible<_error_type, _error_type2>::value;
  template <class _exception_type2> static constexpr bool exception_type_is_constructible_from = std::is_void<_exception_type2>::value || std::is_same<_exception_type, _exception_type2>::value || std::is_constructible<_exception_type, _exception_type2>::value;

  template <class _value_type2, class _error_type2, class _exception_type2> static constexpr bool is_constructible_from = value_type_is_constructible_from<_value_type2> &&error_type_is_constructible_from<_error_type2> &&exception_type_is_constructible_from<_exception_type2>;

  template <class _value_type2> static constexpr bool value_type_is_comparable_to = std::is_void<_value_type2>::value || value_type_is_constructible_from<_value_type2>;
  template <class _error_type2> static constexpr bool error_type_is_comparable_to = error_type_is_constructible_from<_error_type2>;
  template <class _exception_type2> static constexpr bool exception_type_is_comparable_to = exception_type_is_constructible_from<_exception_type2>;

  template <class _value_type2, class _error_type2, class _exception_type2> static constexpr bool is_comparable_to = value_type_is_comparable_to<_value_type2> &&error_type_is_comparable_to<_error_type2> &&exception_type_is_comparable_to<_exception_type2>;

  template <class _value_type2, class _error_type2, class _exception_type2> using _is_constructible_from = typename std::conditional<is_constructible_from<_value_type2, _error_type2, _exception_type2>, std::true_type, std::false_type>::type;
  template <class _value_type2, class _error_type2, class _exception_type2> using _is_comparable_to = typename std::conditional<is_comparable_to<_value_type2, _error_type2, _exception_type2>, std::true_type, std::false_type>::type;
#else
  template <class _value_type2, class _error_type2, class _exception_type2>
  using _is_constructible_from = typename std::conditional<(std::is_same<_value_type, _value_type2>::value || std::is_void<_value_type2>::value || std::is_constructible<_value_type, _value_type2>::value) &&
                                                           (std::is_void<_error_type2>::value || std::is_same<_error_type, _error_type2>::value || std::is_constructible<_error_type, _error_type2>::value) &&
                                                           (std::is_void<_exception_type2>::value || std::is_same<_exception_type, _exception_type2>::value || std::is_constructible<_exception_type, _exception_type2>::value),
                                                           std::true_type, std::false_type>::type;
  template <class _value_type2, class _error_type2, class _exception_type2> using _is_comparable_to = typename std::conditional<std::is_void<_value_type2>::value || _is_constructible_from<_value_type2, _error_type2, _exception_type2>::value, std::true_type, std::false_type>::type;
#endif

  constexpr value_storage() = default;
  constexpr value_storage(const value_storage &) = default;
  constexpr value_storage(value_storage &&) = default;
  BOOST_OUTCOME_CONSTEXPR value_storage &operator=(const value_storage &) = default;
  BOOST_OUTCOME_CONSTEXPR value_storage &operator=(value_storage &&) = default;
  constexpr value_storage(empty_t _) noexcept : base(_) {}
  constexpr value_storage(value_t _) noexcept(std::is_nothrow_default_constructible<value_type>::value)
      : base(_)
  {
  }
  constexpr value_storage(error_t _) noexcept(std::is_nothrow_default_constructible<error_type>::value)
      : base(_)
  {
  }
  constexpr value_storage(exception_t _) noexcept(std::is_nothrow_default_constructible<exception_type>::value)
      : base(_)
  {
  }
  constexpr value_storage(const value_type &v) noexcept(std::is_nothrow_copy_constructible<value_type>::value)
      : base(v)
  {
  }
  constexpr value_storage(const error_type &v) noexcept(std::is_nothrow_copy_constructible<error_type>::value)
      : base(v)
  {
  }
  constexpr value_storage(const exception_type &v) noexcept(std::is_nothrow_copy_constructible<exception_type>::value)
      : base(v)
  {
  }
  constexpr value_storage(value_type &&v) noexcept(std::is_nothrow_move_constructible<value_type>::value)
      : base(std::move(v))
  {
  }
  constexpr value_storage(error_type &&v) noexcept(std::is_nothrow_move_constructible<error_type>::value)
      : base(std::move(v))
  {
  }
  constexpr value_storage(exception_type &&v) noexcept(std::is_nothrow_move_constructible<exception_type>::value)
      : base(std::move(v))
  {
  }
  using emplace_t = typename base::emplace_t;
  template <class... Args>
  constexpr explicit value_storage(emplace_t _, Args &&... args)
#if !defined(_MSC_VER) || _MSC_VER > 190022816
  noexcept(std::is_nothrow_constructible<value_type, Args...>::value)
#endif
      : base(_, std::forward<Args>(args)...)
  {
  }
  template <class _value_type2, class _error_type2, class _exception_type2, typename = typename std::enable_if<_is_constructible_from<_value_type2, _error_type2, _exception_type2>::value>::type>
  BOOST_OUTCOME_CONSTEXPR explicit value_storage(const value_storage<_value_type2, _error_type2, _exception_type2> &o)
      : base()
  {
    switch(o.type)
    {
    case storage_type::empty:
      break;
    case storage_type::value:
      detail::emplace_value_if<has_value_type && value_storage<_value_type2, _error_type2, _exception_type2>::has_value_type>(this, o.value);
      break;
    case storage_type::error:
      detail::emplace_error_if<has_error_type && value_storage<_value_type2, _error_type2, _exception_type2>::has_error_type>(this, o.error);
      break;
    case storage_type::exception:
      detail::emplace_exception_if<has_exception_type && value_storage<_value_type2, _error_type2, _exception_type2>::has_exception_type>(this, o.exception);
      break;
    }
  }
  template <class _value_type2, class _error_type2, class _exception_type2, typename = typename std::enable_if<base::is_referenceable && _is_constructible_from<_value_type2, _error_type2, _exception_type2>::value>::type>
  BOOST_OUTCOME_CONSTEXPR explicit value_storage(value_storage<_value_type2, _error_type2, _exception_type2> &&o)
      : base()
  {
    switch(o.type)
    {
    case storage_type::empty:
      break;
    case storage_type::value:
      detail::emplace_value_if<has_value_type && value_storage<_value_type2, _error_type2, _exception_type2>::has_value_type>(this, std::move(o.value));
      break;
    case storage_type::error:
      detail::emplace_error_if<has_error_type && value_storage<_value_type2, _error_type2, _exception_type2>::has_error_type>(this, std::move(o.error));
      break;
    case storage_type::exception:
      detail::emplace_exception_if<has_exception_type && value_storage<_value_type2, _error_type2, _exception_type2>::has_exception_type>(this, std::move(o.exception));
      break;
    }
  }
  struct valueless_t
  {
  };
  template <class _value_type2, class _error_type2, class _exception_type2, typename = typename std::enable_if<base::is_referenceable && _is_constructible_from<_value_type2, _error_type2, _exception_type2>::value>::type>
  BOOST_OUTCOME_CONSTEXPR explicit value_storage(valueless_t, value_storage<_value_type2, _error_type2, _exception_type2> &&o)
      : base()
  {
    switch(o.type)
    {
    case storage_type::empty:
      break;
    case storage_type::value:
      break;
    case storage_type::error:
      detail::emplace_error_if<has_error_type && value_storage<_value_type2, _error_type2, _exception_type2>::has_error_type>(this, std::move(o.error));
      break;
    case storage_type::exception:
      detail::emplace_exception_if<has_exception_type && value_storage<_value_type2, _error_type2, _exception_type2>::has_exception_type>(this, std::move(o.exception));
      break;
    }
  }
  BOOST_OUTCOME_CONSTEXPR void set_state(value_storage &&o) noexcept(is_nothrow_destructible &&is_nothrow_move_constructible)
  {
    clear();
    new(this) value_storage(std::move(o));
  }

  void swap(value_storage &o) noexcept(is_nothrow_move_constructible)
  {
    if(this->type == o.type)
    {
      switch(this->type)
      {
      case storage_type::empty:
        break;
      case storage_type::value:
        std::swap(this->value, o.value);
        break;
      case storage_type::error:
        std::swap(this->error, o.error);
        break;
      case storage_type::exception:
        std::swap(this->exception, o.exception);
        break;
      }
    }
    else
    {
      value_storage temp(std::move(o));
#if defined(__cpp_exceptions)
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4297)
#endif
#if defined(__GNUC__) && !defined(__clang__) && __GNUC__ >= 6
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wterminate"
#endif
      try
      {
        try
        {
          o = std::move(*this);
          try
          {
            *this = std::move(temp);
          }
          catch(...)
          {
            *this = std::move(o);
            throw;
          }
        }
        catch(...)
        {
          o = std::move(temp);
          throw;
        }
      }
      catch(...)
      {

        if(is_nothrow_move_constructible)
          std::terminate();
        else
          throw;
      }
#if defined(__GNUC__) && !defined(__clang__) && __GNUC__ >= 6
#pragma GCC diagnostic pop
#endif
#ifdef _MSC_VER
#pragma warning(pop)
#endif
#else
      o = std::move(*this);
      *this = std::move(temp);
#endif
    }
  }
  template <class _value_type2, class _error_type2, class _exception_type2, typename = typename std::enable_if<_is_comparable_to<_value_type2, _error_type2, _exception_type2>::value>::type> BOOST_OUTCOME_CONSTEXPR bool operator==(const value_storage<_value_type2, _error_type2, _exception_type2> &o) const
  {
    if(this->type != o.type)
      return false;
    switch(this->type)
    {
    case storage_type::empty:
      return true;
    case storage_type::value:
      return (!has_value_type && !value_storage<_value_type2, _error_type2, _exception_type2>::has_value_type) || detail::compare_if < has_value_type && value_storage<_value_type2, _error_type2, _exception_type2>::has_value_type > (this->value, o.value);
    case storage_type::error:
      return detail::compare_if < has_error_type && value_storage<_value_type2, _error_type2, _exception_type2>::has_error_type > (this->error, o.error);
    case storage_type::exception:
      return detail::compare_if < has_exception_type && value_storage<_value_type2, _error_type2, _exception_type2>::has_exception_type > (this->exception, o.exception);
    }
    return false;
  }
  template <class _value_type2, class _error_type2, class _exception_type2, typename = typename std::enable_if<_is_comparable_to<_value_type2, _error_type2, _exception_type2>::value>::type> BOOST_OUTCOME_CONSTEXPR bool operator!=(const value_storage<_value_type2, _error_type2, _exception_type2> &o) const
  {
    return !(*this == o);
  }
};

} } }

#ifndef BOOST_OUTCOME_DISABLE_IOSTREAMS
namespace std
{

  template <class _value_type, class _error_type, class _exception_type> inline istream &operator>>(istream &s, boost ::outcome ::_1_0_std_std_b507c466::value_storage<_value_type, _error_type, _exception_type> &v)
  {
    using namespace boost ::outcome ::_1_0_std_std_b507c466;
    switch(v.type)
    {
    case value_storage<_value_type, _error_type, _exception_type>::storage_type::value:
      return s >> v.value;
    default:
      BOOST_OUTCOME_THROW_DESERIALISATION_FAILURE(v, ios_base::failure("Set the type of lightweight_futures::value_storage to a value_type before deserialising into it"));
    }
  }

  template <class _value_type> inline ostream &operator<<(ostream &s, const boost ::outcome ::_1_0_std_std_b507c466::value_storage<_value_type, void, void> &v)
  {
    using namespace boost ::outcome ::_1_0_std_std_b507c466;
    using _error_type = void;
    using _exception_type = void;
    switch(v.type)
    {
    case value_storage<_value_type, _error_type, _exception_type>::storage_type::empty:
      return s << "(empty)";
    case value_storage<_value_type, _error_type, _exception_type>::storage_type::value:
      return s << v.value;
    default:
      return s << "(unknown)";
    }
  }
  template <class _value_type, class _error_type> inline ostream &operator<<(ostream &s, const boost ::outcome ::_1_0_std_std_b507c466::value_storage<_value_type, _error_type, void> &v)
  {
    using namespace boost ::outcome ::_1_0_std_std_b507c466;
    using _exception_type = void;
    switch(v.type)
    {
    case value_storage<_value_type, _error_type, _exception_type>::storage_type::empty:
      return s << "(empty)";
    case value_storage<_value_type, _error_type, _exception_type>::storage_type::value:
      return s << v.value;
    case value_storage<_value_type, _error_type, _exception_type>::storage_type::error:
      return s << v.error;
    default:
      return s << "(unknown)";
    }
  }
  template <class _value_type, class _error_type, class _exception_type> inline ostream &operator<<(ostream &s, const boost ::outcome ::_1_0_std_std_b507c466::value_storage<_value_type, _error_type, _exception_type> &v)
  {
    using namespace boost ::outcome ::_1_0_std_std_b507c466;
    switch(v.type)
    {
    case value_storage<_value_type, _error_type, _exception_type>::storage_type::empty:
      return s << "(empty)";
    case value_storage<_value_type, _error_type, _exception_type>::storage_type::value:
      return s << v.value;
    case value_storage<_value_type, _error_type, _exception_type>::storage_type::error:
      return s << v.error;
    case value_storage<_value_type, _error_type, _exception_type>::storage_type::exception:
#ifdef __cpp_exceptions
      try
      {
        rethrow_exception(v.exception);
      }
      catch(const system_error &e)
      {
        return s << "std::system_error code " << e.code() << ": " << e.what();
      }




      catch(const exception &e)
      {
        return s << "std::exception: " << e.what();
      }
      catch(...)
#endif
      {
        return s << "unknown exception";
      }
    default:
      return s << "(unknown)";
    }
  }
}
#endif

#endif
#ifndef BOOST_BINDLIB_TRIBOOL_H
#define BOOST_BINDLIB_TRIBOOL_H







#include <istream>

namespace boost_lite { inline namespace _ed8678b7 {

namespace tribool
{















  enum class tribool : signed char
  {
    false_ = -1,
    true_ = 1,
    other = 0,
    indeterminate = 0,
    unknown = 0
  };

  constexpr inline tribool make_tribool(int v) noexcept { return v > 0 ? tribool::true_ : v < 0 ? tribool::false_ : tribool::other; }

  constexpr inline tribool operator~(tribool v) noexcept { return static_cast<tribool>(-static_cast<signed char>(v)); }

  constexpr inline tribool operator&(tribool a, tribool b) noexcept { return (a == tribool::true_ && b == tribool::true_) ? tribool::true_ : (a == tribool::false_ || b == tribool::false_) ? tribool::false_ : tribool::other; }

  constexpr inline tribool operator|(tribool a, tribool b) noexcept { return (a == tribool::true_ || b == tribool::true_) ? tribool::true_ : (a == tribool::other || b == tribool::other) ? tribool::other : tribool::false_; }




  constexpr inline bool operator&&(tribool a, tribool b) noexcept { return (a == tribool::true_ && b == tribool::true_); }

  constexpr inline bool operator||(tribool a, tribool b) noexcept { return (a == tribool::true_ || b == tribool::true_); }


  constexpr inline bool true_(tribool a) noexcept { return a == tribool::true_; }

  constexpr inline bool false_(tribool a) noexcept { return a == tribool::false_; }

  constexpr inline bool other(tribool a) noexcept { return a == tribool::indeterminate; }

  constexpr inline bool indeterminate(tribool a) noexcept { return a == tribool::indeterminate; }

  constexpr inline bool unknown(tribool a) noexcept { return a == tribool::indeterminate; }
}
} }

namespace std
{
  inline istream &operator>>(istream &s, boost_lite::_ed8678b7::tribool::tribool &a)
  {
    char c;
    s >> c;
    a = (c == '1') ? boost_lite::_ed8678b7::tribool::tribool::true_ : (c == '0') ? boost_lite::_ed8678b7::tribool::tribool::false_ : boost_lite::_ed8678b7::tribool::tribool::other;
    return s;
  }
  inline ostream &operator<<(ostream &s, boost_lite::_ed8678b7::tribool::tribool a)
  {
    char c = (a == boost_lite::_ed8678b7::tribool::tribool::true_) ? '1' : (a == boost_lite::_ed8678b7::tribool::tribool::false_) ? '0' : '?';
    return s << c;
  }
}

#endif
namespace boost { namespace outcome { inline namespace _1_0_std_std_b507c466 {

template <class implementation_policy> class basic_monad;

namespace detail
{
  template <class M> struct is_monad : std::false_type
  {
  };
  template <class Impl> struct is_monad<basic_monad<Impl>> : std::true_type
  {
  };

  template <class M> struct tagged_valueless
  {
    M value;
  };
  template <class M> tagged_valueless<M> tag_valueless(M &&m) { return tagged_valueless<M>{std::forward<M>(m)}; }
}








struct in_place_t
{
  constexpr in_place_t() {}
};

constexpr in_place_t in_place;


template <class M> static constexpr bool is_monad = detail::is_monad<typename std::decay<M>::type>::value;










template <class implementation_policy> class BOOSTLITE_NODISCARD basic_monad : public implementation_policy::base

{

  friend implementation_policy;

  friend typename implementation_policy::template rebind_policy<void>;

  template <class U> friend class basic_monad;
#ifndef BOOST_OUTCOME_DISABLE_IOSTREAMS

  friend inline std::istream &operator>>(std::istream &s, basic_monad &v) { return s >> v._storage; }
  friend inline std::ostream &operator<<(std::ostream &s, const basic_monad &v) { return s << v._storage; }
#endif

protected:
  struct from_value_storage_type_t
  {
  };
  typedef value_storage<typename implementation_policy::value_type, typename implementation_policy::error_type, typename implementation_policy::exception_type> value_storage_type;
  constexpr explicit basic_monad(from_value_storage_type_t, value_storage_type &&s)
      : implementation_policy::base(std::move(s))
  {
  }

public:

  static constexpr bool has_value_type = value_storage_type::has_value_type;

  static constexpr bool has_error_type = value_storage_type::has_error_type;

  static constexpr bool has_exception_type = value_storage_type::has_exception_type;

  typedef typename implementation_policy::implementation_type implementation_type;

  typedef typename value_storage_type::value_type value_type;

  typedef typename implementation_policy::value_type raw_value_type;

  typedef typename value_storage_type::error_type error_type;

  typedef typename implementation_policy::error_type raw_error_type;

  typedef typename value_storage_type::exception_type exception_type;

  typedef typename implementation_policy::exception_type raw_exception_type;

  struct empty_type
  {
    typedef implementation_type parent_type;
  };

  template <typename U> using rebind = typename implementation_policy::template rebind<U>;

private:
  struct implicit_conversion_from_void_disabled
  {
  };
  using void_rebound = typename std::conditional<has_value_type, rebind<void>, implicit_conversion_from_void_disabled>::type;

public:

  static constexpr bool is_default_constructible = implementation_policy::is_default_constructible;

  static constexpr bool is_nothrow_default_constructible = implementation_policy::is_nothrow_default_constructible;

  static constexpr bool is_copy_constructible = value_storage_type::is_copy_constructible;

  static constexpr bool is_nothrow_copy_constructible = value_storage_type::is_nothrow_copy_constructible;

  static constexpr bool is_move_constructible = value_storage_type::is_move_constructible;

  static constexpr bool is_nothrow_move_constructible = value_storage_type::is_nothrow_move_constructible;

  static constexpr bool is_copy_assignable = value_storage_type::is_copy_assignable;

  static constexpr bool is_nothrow_copy_assignable = value_storage_type::is_nothrow_copy_assignable;

  static constexpr bool is_move_assignable = value_storage_type::is_move_assignable;

  static constexpr bool is_nothrow_move_assignable = value_storage_type::is_nothrow_move_assignable;

  static constexpr bool is_nothrow_destructible = value_storage_type::is_nothrow_destructible;

  static constexpr bool is_trivially_destructible = value_storage_type::is_trivially_destructible;
#if 0 || defined(__c2__) || (!defined(_MSC_VER) || _MSC_FULL_VER > 191025019 )

  template <class OtherMonad> static constexpr bool is_constructible = value_storage_type::template is_constructible_from<typename OtherMonad::raw_value_type, typename OtherMonad::raw_error_type, typename OtherMonad::raw_exception_type>;

  template <class OtherMonad> static constexpr bool is_comparable = value_storage_type::template is_comparable_to<typename OtherMonad::raw_value_type, typename OtherMonad::raw_error_type, typename OtherMonad::raw_exception_type>;
#endif


  template <class OtherMonad> using _is_constructible = typename value_storage_type::template _is_constructible_from<typename OtherMonad::raw_value_type, typename OtherMonad::raw_error_type, typename OtherMonad::raw_exception_type>;
  template <class OtherMonad> using _is_comparable = typename value_storage_type::template _is_comparable_to<typename OtherMonad::raw_value_type, typename OtherMonad::raw_error_type, typename OtherMonad::raw_exception_type>;


#define BOOST_OUTCOME_BASIC_MONAD_NAME basic_monad
public:



constexpr basic_monad() noexcept(is_nothrow_default_constructible)
    : implementation_policy::base(typename implementation_policy::base::passthru_t())
{
}

constexpr basic_monad(empty_type) noexcept : implementation_policy::base(typename implementation_policy::base::passthru_t())
{
}

constexpr basic_monad(empty_t _) noexcept : implementation_policy::base(typename implementation_policy::base::passthru_t(), _)
{
}

constexpr basic_monad(value_t _) noexcept(std::is_nothrow_default_constructible<value_type>::value)
    : implementation_policy::base(typename implementation_policy::base::passthru_t(), _)
{
}















constexpr basic_monad(const value_type &v) noexcept(std::is_nothrow_copy_constructible<value_type>::value)
    : implementation_policy::base(typename implementation_policy::base::passthru_t(), v)
{
}



constexpr basic_monad(value_type &&v) noexcept(std::is_nothrow_move_constructible<value_type>::value)
    : implementation_policy::base(typename implementation_policy::base::passthru_t(), std::move(v))
{
}







template <class Arg, class... Args>
constexpr explicit basic_monad(in_place_t, Arg &&arg, Args &&... args) noexcept(std::is_nothrow_constructible<value_type, Arg, Args...>::value)
    : implementation_policy::base(typename implementation_policy::base::passthru_t(), typename value_storage_type::emplace_t(), std::forward<Arg>(arg), std::forward<Args>(args)...)
{
}


template <class U>
constexpr basic_monad(in_place_t, std::initializer_list<U> l) noexcept(std::is_nothrow_constructible<value_type, std::initializer_list<U>>::value)
    : implementation_policy::base(typename implementation_policy::base::passthru_t(), typename value_storage_type::emplace_t(), std::move(l))
{
}

constexpr basic_monad(const void_rebound &v) noexcept(std::is_nothrow_copy_constructible<error_type>::value)
    : implementation_policy::base(typename implementation_policy::base::passthru_t(), v)
{
}

constexpr basic_monad(void_rebound &&v) noexcept(std::is_nothrow_move_constructible<error_type>::value)
    : implementation_policy::base(typename implementation_policy::base::passthru_t(), std::move(v))
{
}


constexpr basic_monad(const error_type &v) noexcept(std::is_nothrow_copy_constructible<error_type>::value)
    : implementation_policy::base(typename implementation_policy::base::passthru_t(), v)
{
}

constexpr basic_monad(error_type &&v) noexcept(std::is_nothrow_move_constructible<error_type>::value)
    : implementation_policy::base(typename implementation_policy::base::passthru_t(), std::move(v))
{
}

constexpr basic_monad(const exception_type &v) noexcept(std::is_nothrow_copy_constructible<exception_type>::value)
    : implementation_policy::base(typename implementation_policy::base::passthru_t(), v)
{
}

constexpr basic_monad(exception_type &&v) noexcept(std::is_nothrow_move_constructible<exception_type>::value)
    : implementation_policy::base(typename implementation_policy::base::passthru_t(), std::move(v))
{
}

private:
struct explicit_conversion_from_different_policy
{
};

public:




template <class Policy, typename = typename std::enable_if<std::is_same<typename implementation_policy::value_type, typename Policy::value_type>::value || std::is_void<typename Policy::value_type>::value || std::is_constructible<typename implementation_policy::value_type, typename Policy::value_type>::value>::type,
          typename = typename std::enable_if<std::is_same<typename implementation_policy::error_type, typename Policy::error_type>::value || std::is_constructible<typename implementation_policy::error_type, typename Policy::error_type>::value>::type,
          typename = typename std::enable_if<std::is_same<typename implementation_policy::exception_type, typename Policy::exception_type>::value || std::is_constructible<typename implementation_policy::exception_type, typename Policy::exception_type>::value>::type>
constexpr explicit basic_monad(basic_monad<Policy> &&o, explicit_conversion_from_different_policy = explicit_conversion_from_different_policy())
    : implementation_policy::base(typename implementation_policy::base::passthru_t(), std::move(o))
{
}





template <class Policy, typename = typename std::enable_if<!std::is_void<typename Policy::value_type>::value && _is_constructible<basic_monad<Policy>>::value>::type>
constexpr explicit basic_monad(const basic_monad<Policy> &o, explicit_conversion_from_different_policy = explicit_conversion_from_different_policy())
    : implementation_policy::base(typename implementation_policy::base::passthru_t(), o)
{
}

private:
struct implicit_conversion_from_different_policy
{
};

public:





template <class Policy, typename = typename std::enable_if<std::is_void<typename Policy::value_type>::value && _is_constructible<basic_monad<Policy>>::value>::type>
constexpr basic_monad(const basic_monad<Policy> &o, implicit_conversion_from_different_policy = implicit_conversion_from_different_policy())
    : implementation_policy::base(typename implementation_policy::base::passthru_t(), o)
{
}

constexpr basic_monad(basic_monad &&o) noexcept(is_nothrow_move_constructible)
    : implementation_policy::base(typename implementation_policy::base::passthru_t(), std::move(o))
{
}

constexpr basic_monad(const basic_monad &o) noexcept(is_nothrow_copy_constructible)
    : implementation_policy::base(typename implementation_policy::base::passthru_t(), o)
{
}

BOOST_OUTCOME_CONSTEXPR basic_monad &operator=(basic_monad &&) = default;

BOOST_OUTCOME_CONSTEXPR basic_monad &operator=(const basic_monad &) = default;

#undef BOOST_OUTCOME_BASIC_MONAD_NAME
  template <class OtherMonad>
  constexpr basic_monad(detail::tagged_valueless<OtherMonad> &&v) noexcept(std::is_nothrow_move_constructible<error_type>::value)
      : implementation_policy::base(typename implementation_policy::base::passthru_t(), std::move(v))
  {
  }


  constexpr explicit operator bool() const noexcept { return has_value(); }

  constexpr explicit operator boost_lite::tribool::tribool() const noexcept { return has_value() ? boost_lite::tribool::tribool::true_ : empty() ? boost_lite::tribool::tribool::unknown : boost_lite::tribool::tribool::false_; }

  constexpr bool empty() const noexcept { return implementation_policy::base::_storage.type == value_storage_type::storage_type::empty; }

  constexpr bool has_value() const noexcept { return implementation_policy::base::_storage.type == value_storage_type::storage_type::value; }

  constexpr bool has_error() const noexcept { return implementation_policy::base::_storage.type == value_storage_type::storage_type::error; }




  constexpr bool has_exception(bool only_exception = false) const noexcept { return implementation_policy::base::_storage.type == value_storage_type::storage_type::exception || (!only_exception && implementation_policy::base::_storage.type == value_storage_type::storage_type::error); }


  BOOST_OUTCOME_CONSTEXPR value_type &get_or(value_type &v) & noexcept { return has_value() ? implementation_policy::base::_storage.value : v; }

  BOOST_OUTCOME_CONSTEXPR value_type &value_or(value_type &v) & noexcept { return has_value() ? implementation_policy::base::_storage.value : v; }

  constexpr const value_type &get_or(const value_type &v) const &noexcept { return has_value() ? implementation_policy::base::_storage.value : v; }

  constexpr const value_type &value_or(const value_type &v) const &noexcept { return has_value() ? implementation_policy::base::_storage.value : v; }

  BOOST_OUTCOME_CONSTEXPR value_type &&get_or(value_type &&v) && noexcept { return has_value() ? std::move(implementation_policy::base::_storage.value) : std::move(v); }

  BOOST_OUTCOME_CONSTEXPR value_type &&value_or(value_type &&v) && noexcept { return has_value() ? std::move(implementation_policy::base::_storage.value) : std::move(v); }

  BOOST_OUTCOME_CONSTEXPR const value_type &&get_or(const value_type &&v) const &&noexcept { return has_value() ? std::move(implementation_policy::base::_storage.value) : std::move(v); }

  BOOST_OUTCOME_CONSTEXPR const value_type &&value_or(const value_type &&v) const &&noexcept { return has_value() ? std::move(implementation_policy::base::_storage.value) : std::move(v); }

  BOOST_OUTCOME_CONSTEXPR void set_state(value_storage_type &&v) { implementation_policy::base::_storage.set_state(std::move(v)); }

  BOOST_OUTCOME_CONSTEXPR void set_value(const value_type &v) { implementation_policy::base::_storage.emplace_value(v); }

  BOOST_OUTCOME_CONSTEXPR void set_value(value_type &&v) { implementation_policy::base::_storage.emplace_value(std::move(v)); }

  BOOST_OUTCOME_CONSTEXPR void set_value() { implementation_policy::base::_storage.emplace_value(value_type()); }

  template <class... Args> BOOST_OUTCOME_CONSTEXPR void emplace(Args &&... args) { implementation_policy::base::_storage.emplace_value(std::forward<Args>(args)...); }


  BOOST_OUTCOME_CONSTEXPR void swap(basic_monad &o) noexcept(is_nothrow_move_constructible) { implementation_policy::base::_storage.swap(o._storage); }

  BOOST_OUTCOME_CONSTEXPR void clear() noexcept(is_nothrow_destructible) { implementation_policy::base::_storage.clear(); }


  const value_storage_type &__storage() const noexcept { return this->_storage; }





























































































































































































































};

template <class Policy1, class Policy2> constexpr inline typename std::enable_if<basic_monad<Policy1>::template _is_comparable<basic_monad<Policy2>>::value, bool>::type operator==(const basic_monad<Policy1> &a, const basic_monad<Policy2> &b)
{
  return a.__storage() == b.__storage();
}

template <class Policy1, class Policy2> constexpr inline typename std::enable_if<!basic_monad<Policy1>::template _is_comparable<basic_monad<Policy2>>::value && basic_monad<Policy2>::template _is_comparable<basic_monad<Policy1>>::value, bool>::type operator==(const basic_monad<Policy1> &a, const basic_monad<Policy2> &b)
{
  return b.__storage() == a.__storage();
}

template <class Policy1, class Policy2> constexpr inline typename std::enable_if<basic_monad<Policy1>::template _is_comparable<basic_monad<Policy2>>::value, bool>::type operator!=(const basic_monad<Policy1> &a, const basic_monad<Policy2> &b)
{
  return a.__storage() != b.__storage();
}

template <class Policy1, class Policy2> constexpr inline typename std::enable_if<!basic_monad<Policy1>::template _is_comparable<basic_monad<Policy2>>::value && basic_monad<Policy2>::template _is_comparable<basic_monad<Policy1>>::value, bool>::type operator!=(const basic_monad<Policy1> &a, const basic_monad<Policy2> &b)
{
  return b.__storage() != a.__storage();
}

namespace policy
{





  template <class _implementation_policy> struct basic_monad_storage
  {
    template <class P> friend struct basic_monad_storage;

  protected:
    typedef _implementation_policy implementation_policy;
    typedef value_storage<typename implementation_policy::value_type, typename implementation_policy::error_type, typename implementation_policy::exception_type> value_storage_type;
    value_storage_type _storage;

  public:

    typedef typename implementation_policy::implementation_type implementation_type;

    typedef typename value_storage_type::value_type value_type;

    typedef typename value_storage_type::error_type error_type;

    typedef typename value_storage_type::exception_type exception_type;

    constexpr basic_monad_storage() = default;
    constexpr basic_monad_storage(const basic_monad_storage &) = default;
    constexpr basic_monad_storage(basic_monad_storage &&) = default;
    BOOST_OUTCOME_CONSTEXPR basic_monad_storage &operator=(const basic_monad_storage &) = default;
    BOOST_OUTCOME_CONSTEXPR basic_monad_storage &operator=(basic_monad_storage &&) = default;
    template <class Policy>
    constexpr basic_monad_storage(detail::tagged_valueless<basic_monad<Policy>> &&o)
        : _storage(typename value_storage_type::valueless_t(), std::move(o.value._storage))
    {
    }
    template <class Policy>
    constexpr basic_monad_storage(basic_monad_storage<Policy> &&o)
        : _storage(std::move(o._storage))
    {
    }
    template <class Policy>
    constexpr basic_monad_storage(const basic_monad_storage<Policy> &o)
        : _storage(o._storage)
    {
    }
    constexpr explicit basic_monad_storage(value_storage_type &&v)
        : _storage(std::move(v))
    {
    }
    constexpr basic_monad_storage(empty_t _)
        : _storage(_)
    {
    }
    constexpr basic_monad_storage(value_t _)
        : _storage(_)
    {
    }
    constexpr basic_monad_storage(error_t _)
        : _storage(_)
    {
    }
    constexpr basic_monad_storage(exception_t _)
        : _storage(_)
    {
    }
    constexpr basic_monad_storage(const value_type &v)
        : _storage(v)
    {
    }
    constexpr basic_monad_storage(value_type &&v)
        : _storage(std::move(v))
    {
    }
    constexpr basic_monad_storage(const error_type &v)
        : _storage(v)
    {
    }
    constexpr basic_monad_storage(error_type &&v)
        : _storage(std::move(v))
    {
    }
    constexpr basic_monad_storage(const exception_type &v)
        : _storage(v)
    {
    }
    constexpr basic_monad_storage(exception_type &&v)
        : _storage(std::move(v))
    {
    }
    template <class... Args>
    constexpr basic_monad_storage(typename value_storage_type::emplace_t _, Args &&... args)
        : _storage(_, std::forward<Args>(args)...)
    {
    }

    constexpr bool is_ready() const noexcept { return _storage.type != value_storage_type::storage_type::empty; }
    constexpr bool empty() const noexcept { return _storage.type == value_storage_type::storage_type::empty; }
    constexpr bool has_value() const noexcept { return _storage.type == value_storage_type::storage_type::value; }
    constexpr bool has_error() const noexcept { return _storage.type == value_storage_type::storage_type::error; }
    constexpr bool has_exception(bool only_exception = false) const noexcept { return _storage.type == value_storage_type::storage_type::exception || (!only_exception && _storage.type == value_storage_type::storage_type::error); }
  };
  template <bool enable, class T> struct move_if
  {
    template <class U> constexpr typename std::remove_reference<U>::type &&operator()(U &&v) const { return static_cast<typename std::remove_reference<U>::type &&>(v); }
  };
  template <class T> struct move_if<false, T>
  {
    constexpr T operator()(T v) const { return v; }
  };
}

namespace policy
{
}

#define BOOST_OUTCOME_MONAD_NAME monad
#define BOOST_OUTCOME_MONAD_POLICY_ERROR_TYPE error_code_extended
#define BOOST_OUTCOME_MONAD_POLICY_EXCEPTION_TYPE std::exception_ptr
#define BOOST_OUTCOME_GLUE2(a, b) a##b
#define BOOST_OUTCOME_GLUE(a, b) BOOST_OUTCOME_GLUE2(a, b)

#define BOOST_OUTCOME_MONAD_POLICY_NAME BOOST_OUTCOME_GLUE(BOOST_OUTCOME_MONAD_NAME, _policy)


#define BOOST_OUTCOME_MONAD_POLICY_BASE_NAME BOOST_OUTCOME_GLUE(BOOST_OUTCOME_MONAD_NAME, _policy_base)


namespace policy
{
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4800)
#pragma warning(disable : 4702)
#endif

  template <class monad_storage, class value_type, class error_type = void, class exception_type = void> struct monad_policy_base : public monad_storage
  {
  protected:
    monad_policy_base() = delete;
    monad_policy_base(const monad_policy_base &) = delete;
    monad_policy_base(monad_policy_base &&) = delete;
    monad_policy_base &operator=(const monad_policy_base &) = default;
    monad_policy_base &operator=(monad_policy_base &&) = default;
    struct passthru_t
    {
    };
    template <class... Args>
    constexpr monad_policy_base(passthru_t, Args &&... args)
        : monad_storage(std::forward<Args>(args)...)
    {
    }

    static BOOST_OUTCOME_CONSTEXPR bool _throw_error(bad_outcome_errc ec) { return BOOST_OUTCOME_THROW_BAD_OUTCOME(ec, bad_outcome(ec)); }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void _pre_get_value() const
    {
      if(!monad_storage::is_ready())
        _throw_error(bad_outcome_errc::no_state);

      if(monad_storage::has_error() || monad_storage::has_exception())
      {

        if(monad_storage::has_error())
          BOOST_OUTCOME_THROW_SYSTEM_ERROR(monad_storage::_storage.error, stl11::system_error(monad_storage::_storage.error));


        if(monad_storage::has_exception())
          BOOST_OUTCOME_RETHROW_EXCEPTION(monad_storage::_storage.exception);

      }

    }

    using lvalue_type = typename std::conditional<monad_storage::value_storage_type::is_referenceable, value_type &, value_type>::type;
    using const_lvalue_type = typename std::conditional<monad_storage::value_storage_type::is_referenceable, const value_type &, value_type>::type;
    using rvalue_type = typename std::conditional<monad_storage::value_storage_type::is_referenceable, value_type &&, value_type>::type;
    using const_rvalue_type = typename std::conditional<monad_storage::value_storage_type::is_referenceable, const value_type &&, value_type>::type;

  public:

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const auto *operator-> () const
    {
      _pre_get_value();
      return &monad_storage::_storage.value;
    }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE auto *operator-> ()
    {
      _pre_get_value();
      return &monad_storage::_storage.value;
    }


    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE lvalue_type operator*() &
    {
      _pre_get_value();
      return monad_storage::_storage.value;
    }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE lvalue_type get() &
    {
      _pre_get_value();
      return monad_storage::_storage.value;
    }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE lvalue_type value() &
    {
      _pre_get_value();
      return monad_storage::_storage.value;
    }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const_lvalue_type operator*() const &
    {
      _pre_get_value();
      return monad_storage::_storage.value;
    }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const_lvalue_type get() const &
    {
      _pre_get_value();
      return monad_storage::_storage.value;
    }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const_lvalue_type value() const &
    {
      _pre_get_value();
      return monad_storage::_storage.value;
    }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE rvalue_type operator*() &&
    {
      _pre_get_value();
      return move_if<monad_storage::value_storage_type::is_referenceable, value_type>()(monad_storage::_storage.value);
    }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE rvalue_type get() &&
    {
      _pre_get_value();
      return move_if<monad_storage::value_storage_type::is_referenceable, value_type>()(monad_storage::_storage.value);
    }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE rvalue_type value() &&
    {
      _pre_get_value();
      return move_if<monad_storage::value_storage_type::is_referenceable, value_type>()(monad_storage::_storage.value);
    }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const_rvalue_type operator*() const &&
    {
      _pre_get_value();
      return move_if<monad_storage::value_storage_type::is_referenceable, value_type>()(monad_storage::_storage.value);
    }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const_rvalue_type get() const &&
    {
      _pre_get_value();
      return move_if<monad_storage::value_storage_type::is_referenceable, value_type>()(monad_storage::_storage.value);
    }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const_rvalue_type value() const &&
    {
      _pre_get_value();
      return move_if<monad_storage::value_storage_type::is_referenceable, value_type>()(monad_storage::_storage.value);
    }


    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE error_type get_error() const
    {
      if(!monad_storage::is_ready())
      {
        if(!_throw_error(bad_outcome_errc::no_state))
          return error_type();
      }
      if(monad_storage::has_error())
        return monad_storage::_storage.error;

      if(monad_storage::has_exception())
        return error_type((int) bad_outcome_errc::exception_present, bad_outcome_category());

      return error_type();
    }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE error_type error() const { return get_error(); }

    BOOST_OUTCOME_CONSTEXPR error_type error_or(error_type e) const noexcept { return monad_storage::has_error() ? monad_storage::_storage.error : std::move(e); }

    BOOST_OUTCOME_CONSTEXPR void set_error(error_type v) { monad_storage::_storage.emplace_error(std::move(v)); }



    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE exception_type get_exception() const
    {
      if(!monad_storage::is_ready())
      {
        if(!_throw_error(bad_outcome_errc::no_state))
          return exception_type();
      }
      if(!monad_storage::has_error() && !monad_storage::has_exception())
        return exception_type();
      if(monad_storage::has_error())
        return std::make_exception_ptr(stl11::system_error(monad_storage::_storage.error));
      if(monad_storage::has_exception())
        return monad_storage::_storage.exception;
      return exception_type();
    }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE exception_type exception() const { return get_exception(); }

    BOOST_OUTCOME_CONSTEXPR exception_type exception_or(exception_type e) const noexcept { return monad_storage::has_exception() ? monad_storage::_storage.exception : std::move(e); }

    BOOST_OUTCOME_CONSTEXPR void set_exception(exception_type v) { monad_storage::_storage.emplace_exception(std::move(v)); }

    template <typename E, typename = typename std::enable_if<std::is_same<E, E>::value && !std::is_void<exception_type>::value>::type> BOOST_OUTCOME_CONSTEXPR void set_exception(E &&e) { set_exception(make_exception_type(std::forward<E>(e))); }

  };
  template <class monad_storage, class error_type, class exception_type> struct monad_policy_base<monad_storage, void, error_type, exception_type> : public monad_storage
  {
  protected:
    monad_policy_base() = delete;
    monad_policy_base(const monad_policy_base &) = delete;
    monad_policy_base(monad_policy_base &&) = delete;
    monad_policy_base &operator=(const monad_policy_base &) = default;
    monad_policy_base &operator=(monad_policy_base &&) = default;
    struct passthru_t
    {
    };
    template <class... Args>
    constexpr monad_policy_base(passthru_t, Args &&... args)
        : monad_storage(std::forward<Args>(args)...)
    {
    }

    static BOOST_OUTCOME_CONSTEXPR bool _throw_error(bad_outcome_errc ec) { return BOOST_OUTCOME_THROW_BAD_OUTCOME(ec, bad_outcome(ec)); }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void _pre_get_value() const
    {
      if(!monad_storage::is_ready())
        _throw_error(bad_outcome_errc::no_state);

      if(monad_storage::has_error() || monad_storage::has_exception())
      {

        if(monad_storage::has_error())
          BOOST_OUTCOME_THROW_SYSTEM_ERROR(monad_storage::_storage.error, stl11::system_error(monad_storage::_storage.error));


        if(monad_storage::has_exception())
          BOOST_OUTCOME_RETHROW_EXCEPTION(monad_storage::_storage.exception);

      }

    }

  public:
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void operator*() & { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void get() & { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void value() & { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void operator*() const & { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void get() const & { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void value() const & { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void operator*() && { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void get() && { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void value() && { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void operator*() const && { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void get() const && { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void value() const && { _pre_get_value(); }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE error_type get_error() const
    {
      if(!monad_storage::is_ready())
      {
        if(!_throw_error(bad_outcome_errc::no_state))
          return error_type();
      }
      if(monad_storage::has_error())
        return monad_storage::_storage.error;

      if(monad_storage::has_exception())
        return error_type((int) bad_outcome_errc::exception_present, bad_outcome_category());

      return error_type();
    }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE error_type error() const { return get_error(); }
    BOOST_OUTCOME_CONSTEXPR error_type error_or(error_type e) const noexcept { return monad_storage::has_error() ? monad_storage::_storage.error : std::move(e); }
    BOOST_OUTCOME_CONSTEXPR void set_error(error_type v) { monad_storage::_storage.emplace_error(std::move(v)); }


    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE exception_type get_exception() const
    {
      if(!monad_storage::is_ready())
      {
        if(!_throw_error(bad_outcome_errc::no_state))
          return exception_type();
      }
      if(!monad_storage::has_error() && !monad_storage::has_exception())
        return exception_type();
      if(monad_storage::has_error())
        return std::make_exception_ptr(stl11::system_error(monad_storage::_storage.error));
      if(monad_storage::has_exception())
        return monad_storage::_storage.exception;
      return exception_type();
    }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE exception_type exception() const { return get_exception(); }
    BOOST_OUTCOME_CONSTEXPR exception_type exception_or(exception_type e) const noexcept { return monad_storage::has_exception() ? monad_storage::_storage.exception : std::move(e); }
    BOOST_OUTCOME_CONSTEXPR void set_exception(exception_type v) { monad_storage::_storage.emplace_exception(std::move(v)); }
    template <typename E, typename = typename std::enable_if<std::is_same<E, E>::value && !std::is_void<exception_type>::value>::type> BOOST_OUTCOME_CONSTEXPR void set_exception(E &&e) { set_exception(make_exception_type(std::forward<E>(e))); }

  };


  template <typename R> struct monad_policy
  {

    typedef basic_monad<monad_policy> implementation_type;

    typedef R value_type;


    typedef error_code_extended error_type;





    typedef std::exception_ptr exception_type;





    static constexpr bool is_default_constructible = true;

    static constexpr bool is_nothrow_default_constructible = true;


    typedef monad_policy_base<basic_monad_storage<monad_policy>, value_type, error_type, exception_type> base;


    template <typename U> using rebind = basic_monad<monad_policy<U>>;

    template <typename U> using rebind_policy = monad_policy<U>;
  };
  template <> struct monad_policy<void>
  {

    typedef basic_monad<monad_policy> implementation_type;

    typedef void value_type;


    typedef error_code_extended error_type;





    typedef std::exception_ptr exception_type;





    static constexpr bool is_default_constructible = true;

    static constexpr bool is_nothrow_default_constructible = true;


    typedef monad_policy_base<basic_monad_storage<monad_policy>, value_type, error_type, exception_type> base;


    template <typename U> using rebind = basic_monad<monad_policy<U>>;

    template <typename U> using rebind_policy = monad_policy<U>;
  };
#ifdef _MSC_VER
#pragma warning(pop)
#endif
}

#undef BOOST_OUTCOME_GLUE
#undef BOOST_OUTCOME_GLUE2
#undef BOOST_OUTCOME_PROMISE_NAME
#undef BOOST_OUTCOME_MONAD_NAME
#undef BOOST_OUTCOME_MONAD_POLICY_NAME
#undef BOOST_OUTCOME_MONAD_POLICY_ERROR_TYPE
#undef BOOST_OUTCOME_MONAD_POLICY_EXCEPTION_TYPE
#define BOOST_OUTCOME_MONAD_NAME result
#define BOOST_OUTCOME_MONAD_POLICY_ERROR_TYPE error_code_extended
#define BOOST_OUTCOME_GLUE2(a, b) a##b
#define BOOST_OUTCOME_GLUE(a, b) BOOST_OUTCOME_GLUE2(a, b)

#define BOOST_OUTCOME_MONAD_POLICY_NAME BOOST_OUTCOME_GLUE(BOOST_OUTCOME_MONAD_NAME, _policy)





namespace policy
{
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4800)
#pragma warning(disable : 4702)
#endif

  template <class monad_storage, class value_type, class error_type = void, class exception_type = void> struct result_policy_base : public monad_storage
  {
  protected:
    result_policy_base() = delete;
    result_policy_base(const result_policy_base &) = delete;
    result_policy_base(result_policy_base &&) = delete;
    result_policy_base &operator=(const result_policy_base &) = default;
    result_policy_base &operator=(result_policy_base &&) = default;
    struct passthru_t
    {
    };
    template <class... Args>
    constexpr result_policy_base(passthru_t, Args &&... args)
        : monad_storage(std::forward<Args>(args)...)
    {
    }

    static BOOST_OUTCOME_CONSTEXPR bool _throw_error(bad_outcome_errc ec) { return BOOST_OUTCOME_THROW_BAD_OUTCOME(ec, bad_outcome(ec)); }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void _pre_get_value() const
    {
      if(!monad_storage::is_ready())
        _throw_error(bad_outcome_errc::no_state);

      if(monad_storage::has_error() || monad_storage::has_exception())
      {

        if(monad_storage::has_error())
          BOOST_OUTCOME_THROW_SYSTEM_ERROR(monad_storage::_storage.error, stl11::system_error(monad_storage::_storage.error));





      }

    }

    using lvalue_type = typename std::conditional<monad_storage::value_storage_type::is_referenceable, value_type &, value_type>::type;
    using const_lvalue_type = typename std::conditional<monad_storage::value_storage_type::is_referenceable, const value_type &, value_type>::type;
    using rvalue_type = typename std::conditional<monad_storage::value_storage_type::is_referenceable, value_type &&, value_type>::type;
    using const_rvalue_type = typename std::conditional<monad_storage::value_storage_type::is_referenceable, const value_type &&, value_type>::type;

  public:

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const auto *operator-> () const
    {
      _pre_get_value();
      return &monad_storage::_storage.value;
    }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE auto *operator-> ()
    {
      _pre_get_value();
      return &monad_storage::_storage.value;
    }


    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE lvalue_type operator*() &
    {
      _pre_get_value();
      return monad_storage::_storage.value;
    }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE lvalue_type get() &
    {
      _pre_get_value();
      return monad_storage::_storage.value;
    }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE lvalue_type value() &
    {
      _pre_get_value();
      return monad_storage::_storage.value;
    }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const_lvalue_type operator*() const &
    {
      _pre_get_value();
      return monad_storage::_storage.value;
    }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const_lvalue_type get() const &
    {
      _pre_get_value();
      return monad_storage::_storage.value;
    }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const_lvalue_type value() const &
    {
      _pre_get_value();
      return monad_storage::_storage.value;
    }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE rvalue_type operator*() &&
    {
      _pre_get_value();
      return move_if<monad_storage::value_storage_type::is_referenceable, value_type>()(monad_storage::_storage.value);
    }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE rvalue_type get() &&
    {
      _pre_get_value();
      return move_if<monad_storage::value_storage_type::is_referenceable, value_type>()(monad_storage::_storage.value);
    }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE rvalue_type value() &&
    {
      _pre_get_value();
      return move_if<monad_storage::value_storage_type::is_referenceable, value_type>()(monad_storage::_storage.value);
    }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const_rvalue_type operator*() const &&
    {
      _pre_get_value();
      return move_if<monad_storage::value_storage_type::is_referenceable, value_type>()(monad_storage::_storage.value);
    }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const_rvalue_type get() const &&
    {
      _pre_get_value();
      return move_if<monad_storage::value_storage_type::is_referenceable, value_type>()(monad_storage::_storage.value);
    }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const_rvalue_type value() const &&
    {
      _pre_get_value();
      return move_if<monad_storage::value_storage_type::is_referenceable, value_type>()(monad_storage::_storage.value);
    }


    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE error_type get_error() const
    {
      if(!monad_storage::is_ready())
      {
        if(!_throw_error(bad_outcome_errc::no_state))
          return error_type();
      }
      if(monad_storage::has_error())
        return monad_storage::_storage.error;




      return error_type();
    }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE error_type error() const { return get_error(); }

    BOOST_OUTCOME_CONSTEXPR error_type error_or(error_type e) const noexcept { return monad_storage::has_error() ? monad_storage::_storage.error : std::move(e); }

    BOOST_OUTCOME_CONSTEXPR void set_error(error_type v) { monad_storage::_storage.emplace_error(std::move(v)); }



























  };
  template <class monad_storage, class error_type, class exception_type> struct result_policy_base<monad_storage, void, error_type, exception_type> : public monad_storage
  {
  protected:
    result_policy_base() = delete;
    result_policy_base(const result_policy_base &) = delete;
    result_policy_base(result_policy_base &&) = delete;
    result_policy_base &operator=(const result_policy_base &) = default;
    result_policy_base &operator=(result_policy_base &&) = default;
    struct passthru_t
    {
    };
    template <class... Args>
    constexpr result_policy_base(passthru_t, Args &&... args)
        : monad_storage(std::forward<Args>(args)...)
    {
    }

    static BOOST_OUTCOME_CONSTEXPR bool _throw_error(bad_outcome_errc ec) { return BOOST_OUTCOME_THROW_BAD_OUTCOME(ec, bad_outcome(ec)); }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void _pre_get_value() const
    {
      if(!monad_storage::is_ready())
        _throw_error(bad_outcome_errc::no_state);

      if(monad_storage::has_error() || monad_storage::has_exception())
      {

        if(monad_storage::has_error())
          BOOST_OUTCOME_THROW_SYSTEM_ERROR(monad_storage::_storage.error, stl11::system_error(monad_storage::_storage.error));





      }

    }

  public:
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void operator*() & { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void get() & { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void value() & { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void operator*() const & { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void get() const & { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void value() const & { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void operator*() && { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void get() && { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void value() && { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void operator*() const && { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void get() const && { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void value() const && { _pre_get_value(); }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE error_type get_error() const
    {
      if(!monad_storage::is_ready())
      {
        if(!_throw_error(bad_outcome_errc::no_state))
          return error_type();
      }
      if(monad_storage::has_error())
        return monad_storage::_storage.error;




      return error_type();
    }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE error_type error() const { return get_error(); }
    BOOST_OUTCOME_CONSTEXPR error_type error_or(error_type e) const noexcept { return monad_storage::has_error() ? monad_storage::_storage.error : std::move(e); }
    BOOST_OUTCOME_CONSTEXPR void set_error(error_type v) { monad_storage::_storage.emplace_error(std::move(v)); }






















  };


  template <typename R> struct result_policy
  {

    typedef basic_monad<result_policy> implementation_type;

    typedef R value_type;


    typedef error_code_extended error_type;







    typedef void exception_type;



    static constexpr bool is_default_constructible = true;

    static constexpr bool is_nothrow_default_constructible = true;


    typedef result_policy_base<basic_monad_storage<result_policy>, value_type, error_type, exception_type> base;


    template <typename U> using rebind = basic_monad<result_policy<U>>;

    template <typename U> using rebind_policy = result_policy<U>;
  };
  template <> struct result_policy<void>
  {

    typedef basic_monad<result_policy> implementation_type;

    typedef void value_type;


    typedef error_code_extended error_type;







    typedef void exception_type;



    static constexpr bool is_default_constructible = true;

    static constexpr bool is_nothrow_default_constructible = true;


    typedef result_policy_base<basic_monad_storage<result_policy>, value_type, error_type, exception_type> base;


    template <typename U> using rebind = basic_monad<result_policy<U>>;

    template <typename U> using rebind_policy = result_policy<U>;
  };
#ifdef _MSC_VER
#pragma warning(pop)
#endif
}

#undef BOOST_OUTCOME_GLUE
#undef BOOST_OUTCOME_GLUE2
#undef BOOST_OUTCOME_PROMISE_NAME
#undef BOOST_OUTCOME_MONAD_NAME
#undef BOOST_OUTCOME_MONAD_POLICY_NAME
#undef BOOST_OUTCOME_MONAD_POLICY_ERROR_TYPE
#undef BOOST_OUTCOME_MONAD_POLICY_EXCEPTION_TYPE
#define BOOST_OUTCOME_MONAD_NAME option
#define BOOST_OUTCOME_GLUE2(a, b) a##b
#define BOOST_OUTCOME_GLUE(a, b) BOOST_OUTCOME_GLUE2(a, b)

#define BOOST_OUTCOME_MONAD_POLICY_NAME BOOST_OUTCOME_GLUE(BOOST_OUTCOME_MONAD_NAME, _policy)





namespace policy
{
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4800)
#pragma warning(disable : 4702)
#endif

  template <class monad_storage, class value_type, class error_type = void, class exception_type = void> struct option_policy_base : public monad_storage
  {
  protected:
    option_policy_base() = delete;
    option_policy_base(const option_policy_base &) = delete;
    option_policy_base(option_policy_base &&) = delete;
    option_policy_base &operator=(const option_policy_base &) = default;
    option_policy_base &operator=(option_policy_base &&) = default;
    struct passthru_t
    {
    };
    template <class... Args>
    constexpr option_policy_base(passthru_t, Args &&... args)
        : monad_storage(std::forward<Args>(args)...)
    {
    }

    static BOOST_OUTCOME_CONSTEXPR bool _throw_error(bad_outcome_errc ec) { return BOOST_OUTCOME_THROW_BAD_OUTCOME(ec, bad_outcome(ec)); }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void _pre_get_value() const
    {
      if(!monad_storage::is_ready())
        _throw_error(bad_outcome_errc::no_state);













    }

    using lvalue_type = typename std::conditional<monad_storage::value_storage_type::is_referenceable, value_type &, value_type>::type;
    using const_lvalue_type = typename std::conditional<monad_storage::value_storage_type::is_referenceable, const value_type &, value_type>::type;
    using rvalue_type = typename std::conditional<monad_storage::value_storage_type::is_referenceable, value_type &&, value_type>::type;
    using const_rvalue_type = typename std::conditional<monad_storage::value_storage_type::is_referenceable, const value_type &&, value_type>::type;

  public:

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const auto *operator-> () const
    {
      _pre_get_value();
      return &monad_storage::_storage.value;
    }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE auto *operator-> ()
    {
      _pre_get_value();
      return &monad_storage::_storage.value;
    }


    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE lvalue_type operator*() &
    {
      _pre_get_value();
      return monad_storage::_storage.value;
    }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE lvalue_type get() &
    {
      _pre_get_value();
      return monad_storage::_storage.value;
    }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE lvalue_type value() &
    {
      _pre_get_value();
      return monad_storage::_storage.value;
    }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const_lvalue_type operator*() const &
    {
      _pre_get_value();
      return monad_storage::_storage.value;
    }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const_lvalue_type get() const &
    {
      _pre_get_value();
      return monad_storage::_storage.value;
    }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const_lvalue_type value() const &
    {
      _pre_get_value();
      return monad_storage::_storage.value;
    }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE rvalue_type operator*() &&
    {
      _pre_get_value();
      return move_if<monad_storage::value_storage_type::is_referenceable, value_type>()(monad_storage::_storage.value);
    }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE rvalue_type get() &&
    {
      _pre_get_value();
      return move_if<monad_storage::value_storage_type::is_referenceable, value_type>()(monad_storage::_storage.value);
    }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE rvalue_type value() &&
    {
      _pre_get_value();
      return move_if<monad_storage::value_storage_type::is_referenceable, value_type>()(monad_storage::_storage.value);
    }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const_rvalue_type operator*() const &&
    {
      _pre_get_value();
      return move_if<monad_storage::value_storage_type::is_referenceable, value_type>()(monad_storage::_storage.value);
    }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const_rvalue_type get() const &&
    {
      _pre_get_value();
      return move_if<monad_storage::value_storage_type::is_referenceable, value_type>()(monad_storage::_storage.value);
    }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const_rvalue_type value() const &&
    {
      _pre_get_value();
      return move_if<monad_storage::value_storage_type::is_referenceable, value_type>()(monad_storage::_storage.value);
    }


















































  };
  template <class monad_storage, class error_type, class exception_type> struct option_policy_base<monad_storage, void, error_type, exception_type> : public monad_storage
  {
  protected:
    option_policy_base() = delete;
    option_policy_base(const option_policy_base &) = delete;
    option_policy_base(option_policy_base &&) = delete;
    option_policy_base &operator=(const option_policy_base &) = default;
    option_policy_base &operator=(option_policy_base &&) = default;
    struct passthru_t
    {
    };
    template <class... Args>
    constexpr option_policy_base(passthru_t, Args &&... args)
        : monad_storage(std::forward<Args>(args)...)
    {
    }

    static BOOST_OUTCOME_CONSTEXPR bool _throw_error(bad_outcome_errc ec) { return BOOST_OUTCOME_THROW_BAD_OUTCOME(ec, bad_outcome(ec)); }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void _pre_get_value() const
    {
      if(!monad_storage::is_ready())
        _throw_error(bad_outcome_errc::no_state);













    }

  public:
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void operator*() & { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void get() & { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void value() & { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void operator*() const & { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void get() const & { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void value() const & { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void operator*() && { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void get() && { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void value() && { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void operator*() const && { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void get() const && { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void value() const && { _pre_get_value(); }









































  };


  template <typename R> struct option_policy
  {

    typedef basic_monad<option_policy> implementation_type;

    typedef R value_type;




    typedef void error_type;





    typedef void exception_type;



    static constexpr bool is_default_constructible = true;

    static constexpr bool is_nothrow_default_constructible = true;


    typedef option_policy_base<basic_monad_storage<option_policy>, value_type, error_type, exception_type> base;


    template <typename U> using rebind = basic_monad<option_policy<U>>;

    template <typename U> using rebind_policy = option_policy<U>;
  };
  template <> struct option_policy<void>
  {

    typedef basic_monad<option_policy> implementation_type;

    typedef void value_type;




    typedef void error_type;





    typedef void exception_type;



    static constexpr bool is_default_constructible = true;

    static constexpr bool is_nothrow_default_constructible = true;


    typedef option_policy_base<basic_monad_storage<option_policy>, value_type, error_type, exception_type> base;


    template <typename U> using rebind = basic_monad<option_policy<U>>;

    template <typename U> using rebind_policy = option_policy<U>;
  };
#ifdef _MSC_VER
#pragma warning(pop)
#endif
}

#undef BOOST_OUTCOME_GLUE
#undef BOOST_OUTCOME_GLUE2
#undef BOOST_OUTCOME_PROMISE_NAME
#undef BOOST_OUTCOME_MONAD_NAME
#undef BOOST_OUTCOME_MONAD_POLICY_NAME
#undef BOOST_OUTCOME_MONAD_POLICY_ERROR_TYPE
#undef BOOST_OUTCOME_MONAD_POLICY_EXCEPTION_TYPE
template <typename R> using outcome = basic_monad<policy::monad_policy<R>>;


template <class T> constexpr inline outcome<T> make_outcome(T &&v)
{
  return outcome<T>(std::move(v));
}

template <class T> constexpr inline outcome<T> make_outcome(const T &v)
{
  return outcome<T>(v);
}

template <class T = void> inline outcome<T> make_outcome(error_code_extended v)
{
  return outcome<T>(std::move(v));
}

template <class T = void> inline outcome<T> make_outcome(std::error_code v)
{
  return outcome<T>(error_code_extended(std::move(v)));
}

template <class T = void> inline outcome<T> make_outcome(std::exception_ptr v)
{
  return outcome<T>(std::move(v));
}

template <class T = void> constexpr inline outcome<T> make_outcome()
{
  return outcome<T>();
}

template <class T = void> constexpr inline outcome<T> make_empty_outcome()
{
  return outcome<T>();
}

template <class T> constexpr inline outcome<T> make_valued_outcome(T &&v)
{
  return outcome<T>(std::move(v));
}

template <class T> constexpr inline outcome<T> make_valued_outcome(const T &v)
{
  return outcome<T>(v);
}

template <class T = void> constexpr inline outcome<T> make_valued_outcome()
{
  static_assert(!std::is_same<T, T>::value, "Empty make_valued_outcome<T> not specialised");
  return outcome<T>();
}
template <> inline outcome<void> make_valued_outcome<void>()
{
  return outcome<void>(value);
}

template <class T = void> inline outcome<T> make_errored_outcome(error_code_extended v)
{
  return outcome<T>(std::move(v));
}

template <class T = void> inline outcome<T> make_errored_outcome(std::error_code v)
{
  return outcome<T>(error_code_extended(std::move(v)));
}







template <class T = void, class ErrorCondEnum, typename = typename std::enable_if<stl11::is_error_condition_enum<ErrorCondEnum>::value>::type> inline outcome<T> make_errored_outcome(ErrorCondEnum v)
{
  return outcome<T>(error_code_extended(make_error_code(v)));
}

template <class T = void> inline outcome<T> make_errored_outcome(int e, const char *extended = nullptr)
{
  return outcome<T>(error_code_extended(e, deatomiced_categories::generic_category(), extended));
}
#if defined(_WIN32) || 0

template <class T = void> constexpr inline outcome<T> make_errored_outcome(unsigned long e, const char *extended = nullptr)
{
  return outcome<T>(error_code_extended(e, deatomiced_categories::system_category(), extended));
}
#endif

template <class T = void> inline outcome<T> make_exceptional_outcome(std::exception_ptr v = std::current_exception())
{
  return outcome<T>(std::move(v));
}












template <typename R> using result = basic_monad<policy::result_policy<R>>;


template <class T> constexpr inline result<T> make_result(T &&v)
{
  return result<T>(std::move(v));
}

template <class T> constexpr inline result<T> make_result(const T &v)
{
  return result<T>(v);
}

template <class T = void> inline result<T> make_result(error_code_extended v)
{
  return result<T>(std::move(v));
}

template <class T = void> inline result<T> make_result(std::error_code v)
{
  return result<T>(error_code_extended(std::move(v)));
}

template <class T = void> constexpr inline result<T> make_result()
{
  return result<T>();
}

template <class T = void> constexpr inline result<T> make_empty_result()
{
  return result<T>();
}

template <class T> constexpr inline result<T> make_valued_result(T &&v)
{
  return result<T>(std::move(v));
}

template <class T> constexpr inline result<T> make_valued_result(const T &v)
{
  return result<T>(v);
}

template <class T = void> constexpr inline result<T> make_valued_result()
{
  static_assert(!std::is_same<T, T>::value, "Empty make_valued_result<T> not specialised");
  return result<T>();
}
template <> inline result<void> make_valued_result<void>()
{
  return result<void>(value);
}

template <class T = void> inline result<T> make_errored_result(error_code_extended v)
{
  return result<T>(std::move(v));
}

template <class T = void> inline result<T> make_errored_result(std::error_code v)
{
  return result<T>(error_code_extended(std::move(v)));
}







template <class T = void, class ErrorCondEnum, typename = typename std::enable_if<stl11::is_error_condition_enum<ErrorCondEnum>::value>::type> inline result<T> make_errored_result(ErrorCondEnum v)
{
  return result<T>(error_code_extended(make_error_code(v)));
}

template <class T = void> constexpr inline result<T> make_errored_result(int e, const char *extended = nullptr)
{
  return result<T>(error_code_extended(e, deatomiced_categories::generic_category(), extended));
}
#if defined(_WIN32) || 0

template <class T = void> constexpr inline result<T> make_errored_result(unsigned long e, const char *extended = nullptr)
{
  return result<T>(error_code_extended(e, deatomiced_categories::system_category(), extended));
}
#endif













template <typename R> using option = basic_monad<policy::option_policy<R>>;


template <class T> constexpr inline option<T> make_option(T &&v)
{
  return option<T>(std::move(v));
}

template <class T> constexpr inline option<T> make_option(const T &v)
{
  return option<T>(v);
}

template <class T = void> constexpr inline option<T> make_option()
{
  return option<T>();
}

template <class T = void> constexpr inline option<T> make_empty_option()
{
  return option<T>();
}

template <class T> constexpr inline option<T> make_valued_option(T &&v)
{
  return option<T>(std::move(v));
}

template <class T> constexpr inline option<T> make_valued_option(const T &v)
{
  return option<T>(v);
}

template <class T = void> constexpr inline option<T> make_valued_option()
{
  static_assert(!std::is_same<T, T>::value, "Empty make_valued_option<T> not specialised");
  return option<T>();
}
template <> constexpr inline option<void> make_valued_option<void>()
{
  return option<void>(value);
}



template <class T> constexpr inline outcome<T> as_outcome(result<T> &&v)
{
  return outcome<T>(std::move(v));
}

template <class T> constexpr inline outcome<T> as_outcome(const result<T> &v)
{
  return outcome<T>(v);
}

template <class T> constexpr inline outcome<T> as_outcome(option<T> &&v)
{
  return outcome<T>(std::move(v));
}

template <class T> constexpr inline outcome<T> as_outcome(const option<T> &v)
{
  return outcome<T>(v);
}

template <class T> constexpr inline result<T> as_result(option<T> &&v)
{
  return result<T>(std::move(v));
}

template <class T> constexpr inline result<T> as_result(const option<T> &v)
{
  return result<T>(v);
}


template <class T> inline outcome<void> as_void(const outcome<T> &v)
{
  if(v.has_exception())
    return v.get_exception();
  if(v.has_error())
    return v.get_error();
  if(v.has_value())
    return make_valued_outcome<void>();
  return make_empty_outcome<void>();
}

template <class T> inline result<void> as_void(const result<T> &v)
{
  if(v.has_error())
    return v.get_error();
  if(v.has_value())
    return make_valued_result<void>();
  return make_empty_result<void>();
}

template <class T> BOOSTLITE_CONSTEXPR inline option<void> as_void(const option<T> &v)
{
  if(v.has_value())
    return make_valued_option<void>();
  return make_empty_option<void>();
}


#ifndef BOOST_OUTCOME_LEAN_AND_MEAN










#ifndef BOOST_OUTCOME_EXPECTED_DEFAULT_ERROR_TYPE

#define BOOST_OUTCOME_EXPECTED_DEFAULT_ERROR_TYPE std::error_code
#endif

namespace experimental
{

  constexpr in_place_t in_place;





  class bad_expected_access_base : public std::logic_error
  {
  public:

    using error_type = void;

    bad_expected_access_base(const char *what)
        : std::logic_error(what)
    {
    }
  };

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4814)
#endif




  template <class E = BOOST_OUTCOME_EXPECTED_DEFAULT_ERROR_TYPE> class bad_expected_access : public bad_expected_access_base
  {
    E _error;

  public:

    using error_type = E;

    explicit bad_expected_access(const error_type &e) noexcept : bad_expected_access_base("Bad expected access of value when error was present"), _error(e) {}

    const error_type &error() const &noexcept { return _error; }

    error_type &error() & noexcept { return _error; }

    const error_type &&error() const &&noexcept { return _error; }

    error_type &&error() && noexcept { return _error; }
  };

  template <> class bad_expected_access<void> : public bad_expected_access_base
  {
  public:

    using error_type = void;

    explicit bad_expected_access() noexcept : bad_expected_access_base("Bad expected access of value when valueless due to exception") {}
  };
  template <class E> inline bad_expected_access<E> make_bad_expected_access(const E &v) noexcept { return bad_expected_access<E>(v); }
  inline bad_expected_access<void> make_bad_expected_access() noexcept { return bad_expected_access<void>(); }
#ifdef _MSC_VER
#pragma warning(pop)
#endif
}
namespace policy
{
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable : 4800)
#pragma warning(disable : 4702)
#endif

  template <class monad_storage, class value_type, class error_type> struct expected_policy_base : public monad_storage
  {
    static_assert(!std::is_constructible<value_type, error_type>::value, "value_type cannot be constructible from error_type (Outcome requirement)");
    static_assert(!std::is_constructible<error_type, value_type>::value, "error_type cannot be constructible from value_type (Outcome requirement)");

  protected:
    expected_policy_base() = delete;
    expected_policy_base(const expected_policy_base &) = delete;
    expected_policy_base(expected_policy_base &&) = delete;
    expected_policy_base &operator=(const expected_policy_base &) = default;
    expected_policy_base &operator=(expected_policy_base &&) = default;
    struct passthru_t
    {
    };
    template <class... Args>
    constexpr expected_policy_base(passthru_t, Args &&... args)
        : monad_storage(std::forward<Args>(args)...)
    {
    }

    constexpr expected_policy_base(passthru_t)
        : monad_storage(value_t())
    {
    }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void _pre_get_value() const
    {
      if(!monad_storage::is_ready())
        BOOST_OUTCOME_THROW_BAD_EXPECTED_ACCESS();
      if(monad_storage::has_error() || monad_storage::has_exception())
      {
        if(monad_storage::has_error())
          BOOST_OUTCOME_THROW_BAD_EXPECTED_ACCESS(monad_storage::_storage.error);
#ifdef BOOST_OUTCOME_EXPECTED_POLICY_EXCEPTION_TYPE
        if(monad_storage::has_exception())
          BOOST_OUTCOME_RETHROW_EXCEPTION(monad_storage::_storage.exception);
#endif
      }
    }

    using lvalue_type = typename std::conditional<monad_storage::value_storage_type::is_referenceable, value_type &, value_type>::type;
    using const_lvalue_type = typename std::conditional<monad_storage::value_storage_type::is_referenceable, const value_type &, value_type>::type;
    using rvalue_type = typename std::conditional<monad_storage::value_storage_type::is_referenceable, value_type &&, value_type>::type;
    using const_rvalue_type = typename std::conditional<monad_storage::value_storage_type::is_referenceable, const value_type &&, value_type>::type;

  public:

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const auto *operator-> () const { return &monad_storage::_storage.value; }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE auto *operator-> () { return &monad_storage::_storage.value; }


    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE lvalue_type operator*() & { return monad_storage::_storage.value; }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE lvalue_type get() &
    {
      _pre_get_value();
      return monad_storage::_storage.value;
    }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE lvalue_type value() &
    {
      _pre_get_value();
      return monad_storage::_storage.value;
    }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const_lvalue_type operator*() const & { return monad_storage::_storage.value; }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const_lvalue_type get() const &
    {
      _pre_get_value();
      return monad_storage::_storage.value;
    }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const_lvalue_type value() const &
    {
      _pre_get_value();
      return monad_storage::_storage.value;
    }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE rvalue_type operator*() && { return move_if<monad_storage::value_storage_type::is_referenceable, value_type>()(monad_storage::_storage.value); }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE rvalue_type get() &&
    {
      _pre_get_value();
      return move_if<monad_storage::value_storage_type::is_referenceable, value_type>()(monad_storage::_storage.value);
    }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE rvalue_type value() &&
    {
      _pre_get_value();
      return move_if<monad_storage::value_storage_type::is_referenceable, value_type>()(monad_storage::_storage.value);
    }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const_rvalue_type operator*() const && { return move_if<monad_storage::value_storage_type::is_referenceable, value_type>()(monad_storage::_storage.value); }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const_rvalue_type get() const &&
    {
      _pre_get_value();
      return move_if<monad_storage::value_storage_type::is_referenceable, value_type>()(monad_storage::_storage.value);
    }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const_rvalue_type value() const &&
    {
      _pre_get_value();
      return move_if<monad_storage::value_storage_type::is_referenceable, value_type>()(monad_storage::_storage.value);
    }


    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE error_type &get_error() & { return monad_storage::_storage.error; }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE error_type &error() & { return monad_storage::_storage.error; }

    BOOST_OUTCOME_CONSTEXPR error_type &error_or(error_type &e) & noexcept { return monad_storage::has_error() ? monad_storage::_storage.error : e; }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const error_type &get_error() const & { return monad_storage::_storage.error; }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const error_type &error() const & { return monad_storage::_storage.error; }

    BOOST_OUTCOME_CONSTEXPR const error_type &error_or(const error_type &e) const &noexcept { return monad_storage::has_error() ? monad_storage::_storage.error : e; }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE error_type &&get_error() && { return std::move(monad_storage::_storage.error); }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE error_type &&error() && { return std::move(monad_storage::_storage.error); }

    BOOST_OUTCOME_CONSTEXPR error_type &&error_or(error_type &&e) && noexcept { return std::move(monad_storage::has_error() ? monad_storage::_storage.error : e); }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const error_type &&get_error() const && { return std::move(monad_storage::_storage.error); }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const error_type &&error() const && { return std::move(monad_storage::_storage.error); }

    BOOST_OUTCOME_CONSTEXPR const error_type &&error_or(const error_type &&e) const &&noexcept { return std::move(monad_storage::has_error() ? monad_storage::_storage.error : e); }


    BOOST_OUTCOME_CONSTEXPR void set_error(error_type v) { monad_storage::_storage.emplace_error(std::move(v)); }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const error_type &get_unexpected() const { return get_error(); }
  };

  template <class monad_storage, class error_type> struct expected_policy_base_valueless : public monad_storage
  {
  protected:
    expected_policy_base_valueless() = delete;
    expected_policy_base_valueless(const expected_policy_base_valueless &) = delete;
    expected_policy_base_valueless(expected_policy_base_valueless &&) = delete;
    expected_policy_base_valueless &operator=(const expected_policy_base_valueless &) = default;
    expected_policy_base_valueless &operator=(expected_policy_base_valueless &&) = default;
    struct passthru_t
    {
    };
    template <class... Args>
    constexpr expected_policy_base_valueless(passthru_t, Args &&... args)
        : monad_storage(std::forward<Args>(args)...)
    {
    }

    constexpr expected_policy_base_valueless(passthru_t)
        : monad_storage(value_t())
    {
    }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void _pre_get_value() const
    {
      if(!monad_storage::is_ready())
        BOOST_OUTCOME_THROW_BAD_EXPECTED_ACCESS();
      if(monad_storage::has_error() || monad_storage::has_exception())
      {
        if(monad_storage::has_error())
          BOOST_OUTCOME_THROW_BAD_EXPECTED_ACCESS(monad_storage::_storage.error);
#ifdef BOOST_OUTCOME_EXPECTED_POLICY_EXCEPTION_TYPE
        if(monad_storage::has_exception())
          BOOST_OUTCOME_RETHROW_EXCEPTION(monad_storage::_storage.exception);
#endif
      }
    }

  public:
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void operator*() & {}
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void get() & { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void value() & { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void operator*() const & {}
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void get() const & { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void value() const & { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void operator*() && {}
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void get() && { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void value() && { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void operator*() const && {}
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void get() const && { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void value() const && { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE error_type &get_error() & { return monad_storage::_storage.error; }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE error_type &error() & { return monad_storage::_storage.error; }
    BOOST_OUTCOME_CONSTEXPR error_type &error_or(error_type &e) & noexcept { return monad_storage::has_error() ? monad_storage::_storage.error : e; }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const error_type &get_error() const & { return monad_storage::_storage.error; }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const error_type &error() const & { return monad_storage::_storage.error; }
    BOOST_OUTCOME_CONSTEXPR const error_type &error_or(const error_type &e) const &noexcept { return monad_storage::has_error() ? monad_storage::_storage.error : e; }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE error_type &&get_error() && { return std::move(monad_storage::_storage.error); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE error_type &&error() && { return std::move(monad_storage::_storage.error); }
    BOOST_OUTCOME_CONSTEXPR error_type &&error_or(error_type &&e) && noexcept { return std::move(monad_storage::has_error() ? monad_storage::_storage.error : e); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const error_type &&get_error() const && { return std::move(monad_storage::_storage.error); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const error_type &&error() const && { return std::move(monad_storage::_storage.error); }
    BOOST_OUTCOME_CONSTEXPR const error_type &&error_or(const error_type &&e) const &&noexcept { return std::move(monad_storage::has_error() ? monad_storage::_storage.error : e); }

    BOOST_OUTCOME_CONSTEXPR void set_error(error_type v) { monad_storage::_storage.emplace_error(std::move(v)); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const error_type &get_unexpected() const { return get_error(); }
  };

  template <class monad_storage, class value_type> struct expected_policy_base<monad_storage, value_type, void> : public monad_storage
  {

  protected:
    expected_policy_base() = delete;
    expected_policy_base(const expected_policy_base &) = delete;
    expected_policy_base(expected_policy_base &&) = delete;
    expected_policy_base &operator=(const expected_policy_base &) = default;
    expected_policy_base &operator=(expected_policy_base &&) = default;
    struct passthru_t
    {
    };
    template <class... Args>
    constexpr expected_policy_base(passthru_t, Args &&... args)
        : monad_storage(std::forward<Args>(args)...)
    {
    }

    constexpr expected_policy_base(passthru_t)
        : monad_storage(value_t())
    {
    }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void _pre_get_value() const
    {
      if(!monad_storage::is_ready())
        BOOST_OUTCOME_THROW_BAD_EXPECTED_ACCESS();
      if(monad_storage::has_error() || monad_storage::has_exception())
      {
        if(monad_storage::has_error())
          BOOST_OUTCOME_THROW_BAD_EXPECTED_ACCESS(monad_storage::_storage.error);
#ifdef BOOST_OUTCOME_EXPECTED_POLICY_EXCEPTION_TYPE
        if(monad_storage::has_exception())
          BOOST_OUTCOME_RETHROW_EXCEPTION(monad_storage::_storage.exception);
#endif
      }
    }

    using lvalue_type = typename std::conditional<monad_storage::value_storage_type::is_referenceable, value_type &, value_type>::type;
    using const_lvalue_type = typename std::conditional<monad_storage::value_storage_type::is_referenceable, const value_type &, value_type>::type;
    using rvalue_type = typename std::conditional<monad_storage::value_storage_type::is_referenceable, value_type &&, value_type>::type;
    using const_rvalue_type = typename std::conditional<monad_storage::value_storage_type::is_referenceable, const value_type &&, value_type>::type;

  public:
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const auto *operator-> () const { return &monad_storage::_storage.value; }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE auto *operator-> () { return &monad_storage::_storage.value; }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE lvalue_type operator*() & { return monad_storage::_storage.value; }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE lvalue_type get() &
    {
      _pre_get_value();
      return monad_storage::_storage.value;
    }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE lvalue_type value() &
    {
      _pre_get_value();
      return monad_storage::_storage.value;
    }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const_lvalue_type operator*() const & { return monad_storage::_storage.value; }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const_lvalue_type get() const &
    {
      _pre_get_value();
      return monad_storage::_storage.value;
    }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const_lvalue_type value() const &
    {
      _pre_get_value();
      return monad_storage::_storage.value;
    }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE rvalue_type operator*() && { return move_if<monad_storage::value_storage_type::is_referenceable, value_type>()(monad_storage::_storage.value); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE rvalue_type get() &&
    {
      _pre_get_value();
      return move_if<monad_storage::value_storage_type::is_referenceable, value_type>()(monad_storage::_storage.value);
    }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE rvalue_type value() &&
    {
      _pre_get_value();
      return move_if<monad_storage::value_storage_type::is_referenceable, value_type>()(monad_storage::_storage.value);
    }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const_rvalue_type operator*() const && { return move_if<monad_storage::value_storage_type::is_referenceable, value_type>()(monad_storage::_storage.value); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const_rvalue_type get() const &&
    {
      _pre_get_value();
      return move_if<monad_storage::value_storage_type::is_referenceable, value_type>()(monad_storage::_storage.value);
    }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE const_rvalue_type value() const &&
    {
      _pre_get_value();
      return move_if<monad_storage::value_storage_type::is_referenceable, value_type>()(monad_storage::_storage.value);
    }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void get_error() const {}
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void error() const {}
    BOOST_OUTCOME_CONSTEXPR void set_error() { monad_storage::_storage.emplace_error(); }
  };

  template <class monad_storage> struct expected_policy_base<monad_storage, void, void> : public monad_storage
  {

  protected:
    expected_policy_base() = delete;
    expected_policy_base(const expected_policy_base &) = delete;
    expected_policy_base(expected_policy_base &&) = delete;
    expected_policy_base &operator=(const expected_policy_base &) = default;
    expected_policy_base &operator=(expected_policy_base &&) = default;
    struct passthru_t
    {
    };
    template <class... Args>
    constexpr expected_policy_base(passthru_t, Args &&... args)
        : monad_storage(std::forward<Args>(args)...)
    {
    }

    constexpr expected_policy_base(passthru_t)
        : monad_storage(value_t())
    {
    }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void _pre_get_value() const
    {
      if(!monad_storage::is_ready())
        BOOST_OUTCOME_THROW_BAD_EXPECTED_ACCESS();
      if(monad_storage::has_error() || monad_storage::has_exception())
      {
        if(monad_storage::has_error())
          BOOST_OUTCOME_THROW_BAD_EXPECTED_ACCESS(monad_storage::_storage.error);
#ifdef BOOST_OUTCOME_EXPECTED_POLICY_EXCEPTION_TYPE
        if(monad_storage::has_exception())
          BOOST_OUTCOME_RETHROW_EXCEPTION(monad_storage::_storage.exception);
#endif
      }
    }

  public:
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void operator*() & {}
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void get() & { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void value() & { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void operator*() const & {}
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void get() const & { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void value() const & { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void operator*() && {}
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void get() && { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void value() && { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void operator*() const && {}
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void get() const && { _pre_get_value(); }
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void value() const && { _pre_get_value(); }

    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void get_error() const {}
    BOOST_OUTCOME_CONSTEXPR BOOSTLITE_FORCEINLINE void error() const {}
    BOOST_OUTCOME_CONSTEXPR void set_error() { monad_storage::_storage.emplace_error(); }
  };


  template <typename R, typename EC> struct expected_policy
  {

    typedef basic_monad<expected_policy> implementation_type;

    typedef R value_type;

    typedef EC error_type;

#ifdef BOOST_OUTCOME_EXPECTED_POLICY_EXCEPTION_TYPE
    typedef BOOST_OUTCOME_EXPECTED_POLICY_EXCEPTION_TYPE exception_type;
#else
    typedef void exception_type;
#endif


    static constexpr bool is_default_constructible = std::is_default_constructible<value_type>::value;

    static constexpr bool is_nothrow_default_constructible = std::is_nothrow_default_constructible<value_type>::value;


    typedef expected_policy_base<basic_monad_storage<expected_policy>, value_type, error_type> base;


    template <typename U> using rebind = basic_monad<expected_policy<U, EC>>;

    template <typename U> using rebind_policy = expected_policy<U, EC>;
  };

  template <typename EC> struct expected_policy<void, EC>
  {

    typedef basic_monad<expected_policy> implementation_type;

    typedef void value_type;

    typedef EC error_type;

#ifdef BOOST_OUTCOME_EXPECTED_POLICY_EXCEPTION_TYPE
    typedef BOOST_OUTCOME_EXPECTED_POLICY_EXCEPTION_TYPE exception_type;
#else
    typedef void exception_type;
#endif


    static constexpr bool is_default_constructible = true;

    static constexpr bool is_nothrow_default_constructible = true;


    typedef expected_policy_base_valueless<basic_monad_storage<expected_policy>, error_type> base;


    template <typename U> using rebind = basic_monad<expected_policy<U, EC>>;

    template <typename U> using rebind_policy = expected_policy<U, EC>;
  };

  template <> struct expected_policy<void, void>
  {

    typedef basic_monad<expected_policy> implementation_type;

    typedef void value_type;

    typedef void error_type;

#ifdef BOOST_OUTCOME_EXPECTED_POLICY_EXCEPTION_TYPE
    typedef BOOST_OUTCOME_EXPECTED_POLICY_EXCEPTION_TYPE exception_type;
#else
    typedef void exception_type;
#endif


    static constexpr bool is_default_constructible = true;

    static constexpr bool is_nothrow_default_constructible = true;


    typedef expected_policy_base<basic_monad_storage<expected_policy>, void, void> base;


    template <typename U> using rebind = basic_monad<expected_policy<U, void>>;

    template <typename U> using rebind_policy = expected_policy<U, void>;
  };
#ifdef _MSC_VER
#pragma warning(pop)
#endif
}
namespace experimental
{












  template <typename R, typename E = BOOST_OUTCOME_EXPECTED_DEFAULT_ERROR_TYPE> using expected = basic_monad<policy::expected_policy<R, E>>;


  template <typename E> using unexpected_type = basic_monad<policy::expected_policy<void, E>>;

  using unexpect_t = error_t;

  constexpr unexpect_t unexpect = unexpect_t();



  inline expected<void> make_expected() { return expected<void>(); }

  template <class T, typename E = BOOST_OUTCOME_EXPECTED_DEFAULT_ERROR_TYPE> constexpr inline expected<T, E> make_expected(T &&v) { return expected<T, E>(std::move(v)); }

  template <class T, typename E = BOOST_OUTCOME_EXPECTED_DEFAULT_ERROR_TYPE> constexpr inline expected<T, E> make_expected(const T &v) { return expected<T, E>(v); }

  template <class E> constexpr inline unexpected_type<typename std::decay<E>::type> make_unexpected(E &&v) { return unexpected_type<typename std::decay<E>::type>(std::move(v)); }

  template <class E> constexpr inline unexpected_type<E> make_unexpected(const E &v) { return unexpected_type<E>(v); }

  template <class T, class E> constexpr inline expected<T, E> make_expected_from_error(E &&v) { return expected<T, E>(std::move(v)); }

  template <class T, class E> constexpr inline expected<T, E> make_expected_from_error(const E &v) { return expected<T, E>(v); }

  template <class T, class E, class U, typename = typename std::enable_if<!std::is_same<E, U>::value && std::is_constructible<E, U>::value>::type> constexpr inline expected<T, E> make_expected_from_error(U &&v) { return expected<T, E>(std::forward<U>(v)); }





  template <class T, class E> inline expected<void, E> as_void(const expected<T, E> &v)
  {
    if(v.has_error())
      return expected<void, E>(v.get_error());
    if(v.has_value())
      return expected<void, E>();
    return expected<void, E>(empty);
  }

}


using experimental::as_void;


#endif

} } }

namespace std
{

  template <class Impl> inline void swap(boost ::outcome ::_1_0_std_std_b507c466::basic_monad<Impl> &a, boost ::outcome ::_1_0_std_std_b507c466::basic_monad<Impl> &b) { a.swap(b); }
}

#define BOOST_OUTCOME__GLUE2(x, y) x##y
#define BOOST_OUTCOME__GLUE(x, y) BOOST_OUTCOME__GLUE2(x, y)
#define BOOST_OUTCOME_UNIQUE_NAME BOOST_OUTCOME__GLUE(__t, __COUNTER__)


#define BOOST_OUTCOME_TRYV2(unique, m) auto &&unique = (m); if(!unique.has_value()) return BOOST_OUTCOME_V1_NAMESPACE::detail::tag_valueless(BOOST_OUTCOME_V1_NAMESPACE::as_void(unique));



#define BOOST_OUTCOME_TRY2(unique, v, m) BOOST_OUTCOME_TRYV2(unique, m); auto v(std::move(std::move(unique).get()))









#define BOOST_OUTCOME_TRYV(m) BOOST_OUTCOME_TRYV2(BOOST_OUTCOME_UNIQUE_NAME, m)


#if 0 || defined(__GNUC__) || defined(__clang__)










#define BOOST_OUTCOME_TRYX(m) ({ auto &&res = (m); if(!res.has_value()) return BOOST_OUTCOME_V1_NAMESPACE::detail::tag_valueless(BOOST_OUTCOME_V1_NAMESPACE::as_void(res)); std::move(res.value()); })









#endif







#define BOOST_OUTCOME_TRY(v, m) BOOST_OUTCOME_TRY2(BOOST_OUTCOME_UNIQUE_NAME, v, m)








#define BOOST_OUTCOME_CATCH_EXCEPTION_TO_RESULT catch(const std::invalid_argument &e) { return BOOST_OUTCOME_V1_NAMESPACE::detail::tag_valueless(BOOST_OUTCOME_V1_NAMESPACE::make_errored_result<void>(EINVAL, e.what())); } catch(const std::domain_error &e) { return BOOST_OUTCOME_V1_NAMESPACE::detail::tag_valueless(BOOST_OUTCOME_V1_NAMESPACE::make_errored_result<void>(EDOM, e.what())); } catch(const std::length_error &e) { return BOOST_OUTCOME_V1_NAMESPACE::detail::tag_valueless(BOOST_OUTCOME_V1_NAMESPACE::make_errored_result<void>(E2BIG, e.what())); } catch(const std::out_of_range &e) { return BOOST_OUTCOME_V1_NAMESPACE::detail::tag_valueless(BOOST_OUTCOME_V1_NAMESPACE::make_errored_result<void>(ERANGE, e.what())); } catch(const std::logic_error &e) { return BOOST_OUTCOME_V1_NAMESPACE::detail::tag_valueless(BOOST_OUTCOME_V1_NAMESPACE::make_errored_result<void>(EINVAL, e.what())); } catch(const std::system_error &e) { return BOOST_OUTCOME_V1_NAMESPACE::detail::tag_valueless(BOOST_OUTCOME_V1_NAMESPACE::make_errored_result<void>(BOOST_OUTCOME_V1_NAMESPACE::error_code_extended(e.code(), e.what()))); } catch(const std::overflow_error &e) { return BOOST_OUTCOME_V1_NAMESPACE::detail::tag_valueless(BOOST_OUTCOME_V1_NAMESPACE::make_errored_result<void>(EOVERFLOW, e.what())); } catch(const std::range_error &e) { return BOOST_OUTCOME_V1_NAMESPACE::detail::tag_valueless(BOOST_OUTCOME_V1_NAMESPACE::make_errored_result<void>(ERANGE, e.what())); } catch(const std::runtime_error &e) { return BOOST_OUTCOME_V1_NAMESPACE::detail::tag_valueless(BOOST_OUTCOME_V1_NAMESPACE::make_errored_result<void>(EAGAIN, e.what())); } catch(const std::bad_alloc &e) { return BOOST_OUTCOME_V1_NAMESPACE::detail::tag_valueless(BOOST_OUTCOME_V1_NAMESPACE::make_errored_result<void>(ENOMEM, e.what())); } catch(const std::exception &e) { return BOOST_OUTCOME_V1_NAMESPACE::detail::tag_valueless(BOOST_OUTCOME_V1_NAMESPACE::make_errored_result<void>(EINVAL, e.what())); }
































































#define BOOST_OUTCOME_CATCH_ALL_EXCEPTION_TO_RESULT BOOST_OUTCOME_CATCH_EXCEPTION_TO_RESULT catch(...) { return BOOST_OUTCOME_V1_NAMESPACE::detail::tag_valueless(BOOST_OUTCOME_V1_NAMESPACE::make_errored_result<void>(EAGAIN, "unknown exception")); }








#ifdef _MSC_VER
#pragma warning(pop)
#endif


#endif
#undef BOOST_OUTCOME_HEADERS_PATH
#undef BOOST_OUTCOME_HEADERS_PATH2
