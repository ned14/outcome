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

#include "lib.h"

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  mylib_result r = test_function(5);
  if(is_result_failed(r))
  {
    fprintf(stderr, "FATAL: test_function(5) failed with '%s'\n", result_failure_message(r));
    abort();
  }
  if(r.value != 5)
  {
    fprintf(stderr, "FATAL: test_function(5) did not return 5\n");
    abort();
  }
  r = test_function(-5);
  if(!is_result_failed(r))
  {
    fprintf(stderr, "FATAL: test_function(-5) did not fail\n");
    abort();
  }
  const char *msg = result_failure_message(r);
  printf("test_function(-5) should fail with 'Invalid argument'\nIt failed with '%s'\n", msg);
  if(0 != strcmp(msg, "Invalid argument"))
  {
    abort();
  }
  return 0;
}