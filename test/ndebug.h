/* Keeping assert() live in the Release test suite
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

#ifndef OUTCOME_TEST_NDEBUG_H
#define OUTCOME_TEST_NDEBUG_H

// The test suite is built Release, whose flags include -DNDEBUG, so every
// assert() in a test file compiled to nothing: those assertions could never
// fail and were never running. Undefining NDEBUG keeps them live.
//
// <cassert>'s definition of assert is fixed at its FIRST inclusion, so this
// header MUST be included before any other header in the test file - otherwise
// some header pulls in <cassert>, assert() stays defined away, and the
// assertions are dead again. That is why every user includes this first, and
// why it is not merged into some other test header.
#undef NDEBUG

#endif
