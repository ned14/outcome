/* Example of Outcome used with C APIs
(C) 2024 Niall Douglas <http://www.nedproductions.biz/> (4 commits)


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

// This header in Experimental Outcome is pure C, it provides a suite of C helper macros
#include "../../../include/outcome/experimental/result.h"

#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

//! [preamble]
// Declare to C a Result with a happy value of intptr_t
CXX_DECLARE_RESULT_SYSTEM(result_int, intptr_t)

// Save oneself typing out CXX_RESULT_SYSTEM(result_int) all the time
typedef CXX_RESULT_SYSTEM(result_int) result;

// Our custom C enum
enum c_enum
{
  c_enum_not_found,
  c_enum_bad_argument
};

// Make a custom status code domain for this C enum
CXX_DECLARE_RESULT_SYSTEM_FROM_ENUM(result_int,                                // The C Result type declared above
                                    c_enum,                                    // The C enum we wish to wrap
                                    "{74ceb994-7622-3a21-07f0-b016aa705585}",  // Unique UUID for this domain
                                    // Mappings of C enum values to textual description and semantic equivalances to generic codes
                                    {c_enum::c_enum_not_found, "item not found", {errc::no_such_file_or_directory}},
                                    {c_enum::c_enum_bad_argument, "invoked wrong", {errc::invalid_argument}})

// Make helper macros
#define SUCCESS(v) CXX_MAKE_RESULT_SYSTEM_SUCCESS(result_int, (v))
#define FAILURE(v) CXX_MAKE_RESULT_SYSTEM_FROM_ENUM(result_int, c_enum, (v))
//! [preamble]

//! [using]
result positive_only(int x)
{
  if(x < 0)
  {
    return FAILURE(c_enum_bad_argument);
  }
  return SUCCESS(x);
}

bool test(int x)
{
  result r = positive_only(x);
  if(CXX_RESULT_HAS_ERROR(r))
  {
    if(outcome_status_code_equal_generic(&r.error, EINVAL))
    {
      fprintf(stderr, "Positive numbers only!\n");
      return false;
    }
  }
  return true;
}
//! [using]

//! [try]
result test2(int x)
{
  CXX_RESULT_SYSTEM_TRY(int v,                                        // what to set to value if successful
                        fprintf(stderr, "Positive numbers only!\n"),  // what cleanup to run if unsuccessful
                        positive_only(x));
  return SUCCESS(v + 1);
}
//! [try]

int main(void)
{
  if(!test(0))
    abort();
  if(test(-1))
    abort();
  return 0;
}
