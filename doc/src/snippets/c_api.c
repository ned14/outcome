/* Example of Outcome used with C APIs
(C) 2017 Niall Douglas <http://www.nedproductions.biz/> (149 commits)


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

//! [program]
#include <stdio.h>
#include <string.h>  // for strerror
// This header in Outcome is pure C, it provides a suite of C helper macros
#include "../../../include/outcome/result.h"

// Declare our C++ function's returning result type. Only needs to be done once.
CXX_DECLARE_RESULT_EC(size_t, size_t);

// Tell C about our C++ function
extern CXX_RESULT_EC(size_t) to_string(char *buffer, size_t bufferlen, int v);

void print(int v)
{
  char buffer[4];
  CXX_RESULT_EC(size_t) res;

  res = to_string(buffer, sizeof(buffer), v);
  if(CXX_RESULT_HAS_VALUE(res))
  {
    printf("to_string(%d) fills buffer with '%s' of %zu characters\n", v, buffer, res.value);
    return;
  }
  // Is the error returned in the std::generic_category domain and thus an errno?
  if(CXX_RESULT_ERROR_IS_ERRNO(res))
  {
    // If you get a weird compile error here, note that CXX_RESULT_ERROR()
    // uses C11 generics, you need a C11 compiler for it to work. If you don't
    // have a C11 compiler, res.error or res.error.code can be used directly.
    fprintf(stderr, "to_string(%d) failed with error code %d (%s)\n", v, CXX_RESULT_ERROR(res), strerror(CXX_RESULT_ERROR(res)));
    return;
  }
  fprintf(stderr, "to_string(%d) failed with unknown error code %d\n", v, CXX_RESULT_ERROR(res));
}

int main(void)
{
  print(9);
  print(99);
  print(999);
  print(9999);
  return 0;
}
