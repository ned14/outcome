/* Shared CTest skip for tests which compile to nothing in this configuration
(C) 2013-2025 Niall Douglas <http://www.nedproductions.biz/>


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

#ifndef OUTCOME_TEST_SKIP_TEST_HPP
#define OUTCOME_TEST_SKIP_TEST_HPP

#include "../../include/outcome/config.hpp"
#include "quickcpplib/boost/test/unit_test.hpp"

#include <cstdio>
#include <cstdlib>

// A test whose body compiles away in this configuration (no exceptions, no
// coroutines, no POSIX status-code backend, ...) used to compile to a binary
// that registered ZERO test cases and exited 0, which CTest records as PASSED -
// that is how the exceptions-disabled matrix was once a false green (reviewer
// P0 r8:tests-T1, r7:T1, r6:T1). Such a file instead registers a case which
// prints the marker below and exits 77, which CMakeLists.txt turns into
// SKIPPED with SKIP_RETURN_CODE 77.
//
// 77 must be the exact exit status: CTest only skips on that status, so a
// genuine failure (any other non-zero code) is still reported as Failed.
// SKIP_REGULAR_EXPRESSION was tried first and is wrong - CTest applies it
// BEFORE the exit status, so a test that both emitted the marker and failed was
// reported Skipped (P0 r1:T9).
#define SKIP_TEST_IF_DISABLED(reason)                       \
  do                                                       \
  {                                                        \
    std::printf("SKIPPED-NO-EXCEPTIONS: %s\n", (reason)); \
    std::exit(77);                                         \
  } while(false)

#endif
