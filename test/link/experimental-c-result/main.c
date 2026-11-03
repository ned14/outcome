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

// The C ABI's "system" status code is the PLATFORM's: win32_code on Windows,
// posix_code elsewhere (CXX_MAKE_RESULT_SYSTEM_FAILURE_SYSTEM goes through
// OUTCOME_C_RESULT_SYSTEM_CODE). So EINVAL is 22 everywhere but the message is the
// OS's own text - "The device does not recognize the command." on Windows, since
// ERROR_BAD_COMMAND is 22 - and comparing against POSIX's "Invalid argument"
// aborted all four of these executables on the Windows lane, which is the lane
// where they first ran. What the test is actually guarding is that the C view of
// the status code has a live domain at the right offset: when it does not, the
// message reads "(empty)" (and crashes when that word holds a pointer). So off
// Windows the exact POSIX text is still required, and on Windows the requirement
// is a real message which is not that fallback.
static int failure_message_is_expected(const char *msg)
{
#ifdef _WIN32
  return msg != NULL && msg[0] != '\0' && 0 != strcmp(msg, "(empty)");
#else
  return msg != NULL && 0 == strcmp(msg, "Invalid argument");
#endif
}

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
  printf("test_function(-5) should fail with EINVAL\nIt failed with '%s'\n", msg);
  if(!failure_message_is_expected(msg))
  {
    abort();
  }

  // The same again for a 4 byte value type: the C result makers used to write the
  // status code at an intptr_t result's flags offset whatever the caller's value
  // type was, which for an int result corrupted the error.
  mylib_i32_result r32 = test_function_i32(5);
  if(is_result_failed_i32(r32))
  {
    fprintf(stderr, "FATAL: test_function_i32(5) failed with '%s'\n", result_failure_message_i32(r32));
    abort();
  }
  if(r32.value != 5)
  {
    fprintf(stderr, "FATAL: test_function_i32(5) did not return 5\n");
    abort();
  }
  // A value whose upper bits are set must survive the round trip.
  r32 = make_success_result_i32((int) 0x7fedcba9);
  if(r32.value != (int) 0x7fedcba9)
  {
    fprintf(stderr, "FATAL: an int result did not carry 0x7fedcba9 (got 0x%x)\n", (unsigned) r32.value);
    abort();
  }
  r32 = test_function_i32(-5);
  if(!is_result_failed_i32(r32))
  {
    fprintf(stderr, "FATAL: test_function_i32(-5) did not fail\n");
    abort();
  }
  const char *msg32 = result_failure_message_i32(r32);
  printf("test_function_i32(-5) should fail with EINVAL\nIt failed with '%s'\n", msg32);
  if(!failure_message_is_expected(msg32))
  {
    abort();
  }
    // The same again for a 1 byte value type, the shape whose status word offset the
  // C result description used to get wrong for the C++ side.
  mylib_chr_result rchr = test_function_chr(42);
  if(is_result_failed_chr(rchr))
  {
    fprintf(stderr, "FATAL: test_function_chr(42) failed with '%s'\n", result_failure_message_chr(rchr));
    abort();
  }
  if(rchr.value != 42)
  {
    fprintf(stderr, "FATAL: test_function_chr(42) did not return 42 (got %d)\n", (int) rchr.value);
    abort();
  }
  rchr = test_function_chr(-42);
  if(!is_result_failed_chr(rchr))
  {
    fprintf(stderr, "FATAL: test_function_chr(-42) did not fail\n");
    abort();
  }
  const char *msgchr = result_failure_message_chr(rchr);
  printf("test_function_chr(-42) should fail with EINVAL\nIt failed with '%s'\n", msgchr);
  if(!failure_message_is_expected(msgchr))
  {
    abort();
  }
  return 0;
}
