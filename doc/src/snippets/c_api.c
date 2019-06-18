/* Example of Outcome used with C APIs
(C) 2017-2019 Niall Douglas <http://www.nedproductions.biz/> (4 commits)


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

#define _CRT_SECURE_NO_WARNINGS 1

#include <errno.h>

#include <stdio.h>
#include <string.h>  // for strerror
// This header in Experimental Outcome is pure C, it provides a suite of C helper macros
#include "../../../include/outcome/experimental/result.h"

//! [preamble]
// Declare our C++ function's returning result type. Only needs to be done once.
// This declares an `status_result<size_t, system_code>` which is an alias to
// `basic_result<size_t, status_code<erased<intptr_t>>>`.
//
// The first parameter is some unique identifier for this type which will be used
// whenever we reference this type in the future.
CXX_DECLARE_RESULT_SYSTEM(to_string_rettype, size_t);

// Tell C about our extern C++ function `to_string()`
extern CXX_RESULT_SYSTEM(to_string_rettype) _Z9to_stringPcmi(char *buffer, size_t bufferlen, int v);
//! [preamble]

//! [example]
void print(int v)
{
  char buffer[4];
  CXX_RESULT_SYSTEM(to_string_rettype) res;

  res = _Z9to_stringPcmi(buffer, sizeof(buffer), v);
  if(CXX_RESULT_HAS_VALUE(res))
  {
    printf("to_string(%d) fills buffer with '%s' of %zu characters\n", v, buffer, res.value);
    return;
  }
  // Is the error returned in the POSIX domain and thus an errno?
  if(CXX_RESULT_ERROR_IS_ERRNO(res))
  {
    fprintf(stderr, "to_string(%d) failed with error code %d (%s)\n", v, (int) res.error.value, strerror((int) res.error.value));
    return;
  }
  fprintf(stderr, "to_string(%d) failed with unknown error code %lld\n", v, (long long) res.error.value);
}

int main(void)
{
  print(9);
  print(99);
  print(999);
  print(9999);
  return 0;
}
//! [example]

extern CXX_RESULT_SYSTEM(to_string_rettype) _Z9to_stringPcmi(char *buffer, size_t bufferlen, int v)
{
  // Fake a C++ function so it'll compile and run
  CXX_RESULT_SYSTEM(to_string_rettype) ret;
  memset(&ret, 0, sizeof(ret));
  char temp[256];
  sprintf(temp, "%d", v);
  size_t len = strlen(temp);
  if(len > bufferlen - 1)
  {
    ret.flags |= 18U;
    ret.error.value = ENOBUFS;
    return ret;
  }
  memcpy(buffer, temp, len + 1);
  ret.flags |= 1U;
  ret.value = len;
  return ret;
}