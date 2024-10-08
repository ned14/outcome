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

static int is_result_equivalent(mylib_result r, int errcode)
{
  return outcome_status_code_equal_generic(&r, errcode);
}

static const char *result_failure_message(mylib_result r)
{
  return outcome_status_code_message(&r);
}

extern MYLIB_DECL mylib_result test_function(int x);

#endif
