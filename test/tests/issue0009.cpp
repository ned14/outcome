/* Unit testing for outcomes
(C) 2013-2019 Niall Douglas <http://www.nedproductions.biz/> (5 commits)


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

#include "../../include/outcome.hpp"
#include "../../include/outcome/try.hpp"
#include "quickcpplib/boost/test/unit_test.hpp"

// The body only builds under the condition below. Guarding INSIDE the case left the
// configurations that do not satisfy it registering a case with zero assertions, which
// CTest recorded as PASSED (reviewer P0 r1:T6). Guard the whole case instead and let
// those configurations report SKIPPED.
#ifdef OUTCOME_TRYX
BOOST_OUTCOME_AUTO_TEST_CASE(issues / 0009 / test, "Alternative TRY macros?")
{
#pragma GCC diagnostic ignored "-Wpedantic"
  using namespace OUTCOME_V2_NAMESPACE;
  struct udt  // NOLINT
  {
    explicit udt(int /*unused*/) {}
    //    udt() = delete;
    udt(const udt &) = default;
    udt(udt &&) = default;
  };
  auto f = []() -> result<udt>
  {
    auto g = [] { return result<int>(5); };
    return udt(OUTCOME_TRYX(g()));
  };
  // This case started life as a compile-only test ("does OUTCOME_TRYX work inside
  // a lambda?"), so its body contained NO assertion: the binary printed
  // "1 passed" while checking nothing, which is indistinguishable from a real
  // pass (P0 r1:T6). Assert the observable outcome.
  auto r = f();
  BOOST_CHECK(r.has_value());
  BOOST_CHECK(!r.has_error());
}
#else
#include "skip_test.hpp"

BOOST_OUTCOME_AUTO_TEST_CASE(issues / 0009 / test, "Alternative TRY macros?")
// Two arguments: BOOST_AUTO_TEST_CASE takes a name and a description only, so
// the third (skip reason) argument this used to carry made the branch
// unbuildable. See the same fix in comparison.cpp.
{
  SKIP_TEST_IF_DISABLED("test/tests/issue0009.cpp does not build in this configuration");
}
#endif
