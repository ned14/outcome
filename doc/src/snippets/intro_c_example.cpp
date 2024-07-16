/* Example of Outcome
(C) 2024 Niall Douglas <http://www.nedproductions.biz/>

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

#include "../../../include/outcome/experimental/result.h"

#include <stdio.h>

void use_string(const char *foo)
{
  (void) foo;
}

//! [signature]
CXX_DECLARE_RESULT_SYSTEM(result_string, const char *)

CXX_RESULT_SYSTEM(result_string) data_from_file(const char *path);
//! [signature]

int main()
{
  //! [inspect]
  CXX_RESULT_SYSTEM(result_string) rslt = data_from_file("config.cfg");
  if(CXX_RESULT_HAS_VALUE(rslt))
    use_string(rslt.value);  // returns string
  else
    fprintf(stderr, "%s\n", outcome_status_code_message(&rslt.error));
  //! [inspect]
}

//! [implementation]
CXX_DECLARE_RESULT_SYSTEM(result_int, int)

CXX_RESULT_SYSTEM(result_int) process(const char *content);

CXX_RESULT_SYSTEM(result_int) int_from_file(const char *path)
{
  CXX_RESULT_SYSTEM_TRY(const char *str, result_int, /* cleanup on fail */, data_from_file(path));
  // if control gets here data_from_file() has succeeded
  return process(str);  // decltype(str) == string
}
//! [implementation]

CXX_RESULT_SYSTEM(result_int) process(const char *foo)
{
  (void) foo;
  return outcome_make_result_system_result_int_success(1);
}

CXX_RESULT_SYSTEM(result_string) data_from_file(const char *path)
{
  (void) path;
  return outcome_make_result_system_result_string_success("");
}
