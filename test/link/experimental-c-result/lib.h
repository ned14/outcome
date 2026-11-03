/* Link testing for outcomes
(C) 2024 Niall Douglas <http://www.nedproductions.biz/> (6 commits)


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

#ifndef OUTCOME_TEST_LINK_EXPERIMENTAL_C_RESULT_H
#define OUTCOME_TEST_LINK_EXPERIMENTAL_C_RESULT_H

#include <outcome/experimental/result.h>

#if MYLIB_SOURCE
#ifdef _MSC_VER
#define MYLIB_DECL __declspec(dllexport)
#else
#define MYLIB_DECL __attribute__((visibility("default")))
#endif
#else
#define MYLIB_DECL
#endif

CXX_DECLARE_RESULT_SYSTEM(mylib, intptr_t);

typedef CXX_RESULT_SYSTEM(mylib) mylib_result;

static int is_result_ok(mylib_result r)
{
  return CXX_RESULT_HAS_VALUE(r);
}

static int is_result_failed(mylib_result r)
{
  return CXX_RESULT_HAS_ERROR(r);
}

static mylib_result make_success_result(intptr_t v)
{
  return CXX_MAKE_RESULT_SYSTEM_SUCCESS(mylib, v);
}

static mylib_result make_failure_result(int v)
{
  return CXX_MAKE_RESULT_SYSTEM_FAILURE_SYSTEM(mylib, v);
}

// The C status-code helpers take a pointer to the STATUS CODE, not to the whole
// result: the result's layout is {value, flags, error}, so passing &r makes them
// read offset 0 (the dead value word) and the domain pointer comes out null,
// which surfaces as the message "(empty)" (and as a crash when that word holds
// something non-null). Every documented user passes &r.error - see
// doc/src/snippets/c_api2.cpp and test/tests/experimental-c-result.cpp.
static int is_result_equivalent(mylib_result r, int errcode)
{
  return outcome_status_code_equal_generic(&r.error, errcode);
}

static const char *result_failure_message(mylib_result r)
{
  return outcome_status_code_message(&r.error);
}

extern MYLIB_DECL mylib_result test_function(int x);

// The same C API with a value type which is NOT pointer sized. The failure makers
// used to pun every result against an intptr_t-shaped struct, so this result's
// status word landed at offset 8 instead of its own 4 and the error came back from
// a garbage domain pointer (an assert in a debug build, a SIGSEGV in an NDEBUG
// one). A 4 byte value type is the shape a C API is most likely to use.
CXX_DECLARE_RESULT_SYSTEM(mylib_i32, int);

typedef CXX_RESULT_SYSTEM(mylib_i32) mylib_i32_result;

static mylib_i32_result make_success_result_i32(int v)
{
  return CXX_MAKE_RESULT_SYSTEM_SUCCESS(mylib_i32, v);
}

static mylib_i32_result make_failure_result_i32(int v)
{
  return CXX_MAKE_RESULT_SYSTEM_FAILURE_SYSTEM(mylib_i32, v);
}

static int is_result_failed_i32(mylib_i32_result r)
{
  return CXX_RESULT_HAS_ERROR(r);
}

static const char *result_failure_message_i32(mylib_i32_result r)
{
  return outcome_status_code_message(&r.error);
}

extern MYLIB_DECL mylib_i32_result test_function_i32(int x);

// ... and once more with a ONE BYTE value type. sizeof(R) % 4 == 1 is the shape
// whose status word the C result struct used to describe at the wrong offset (a 4
// byte `unsigned flags` at align_up(sizeof(R), 4) where status_result<R> keeps its
// status word at align_up(sizeof(R), 2)), so this is the case where a C compiler's
// own offsetof and the C++ pun disagree if the description is wrong. It is compiled
// by a C compiler on purpose: the layout a C caller sees is the one that matters.
CXX_DECLARE_RESULT_SYSTEM(mylib_chr, char);

typedef CXX_RESULT_SYSTEM(mylib_chr) mylib_chr_result;

static mylib_chr_result make_success_result_chr(char v)
{
  return CXX_MAKE_RESULT_SYSTEM_SUCCESS(mylib_chr, v);
}

static mylib_chr_result make_failure_result_chr(int v)
{
  return CXX_MAKE_RESULT_SYSTEM_FAILURE_SYSTEM(mylib_chr, v);
}

static int is_result_failed_chr(mylib_chr_result r)
{
  return CXX_RESULT_HAS_ERROR(r);
}

static const char *result_failure_message_chr(mylib_chr_result r)
{
  return outcome_status_code_message(&r.error);
}

extern MYLIB_DECL mylib_chr_result test_function_chr(int x);

#endif
