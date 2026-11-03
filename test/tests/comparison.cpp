/* Unit testing for outcomes
(C) 2013-2019 Niall Douglas <http://www.nedproductions.biz/> (6 commits)


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

#ifdef _MSC_VER
#pragma warning(disable : 4127)  // conditional expression is constant
#pragma warning(disable : 4244)  // conversion from int to short
#endif

#include "../../include/outcome.hpp"
#include "quickcpplib/boost/test/unit_test.hpp"

// The body only builds under the condition below. Guarding INSIDE the case left the
// configurations that do not satisfy it registering a case with zero assertions, which
// CTest recorded as PASSED (reviewer P0 r1:T6). Guard the whole case instead and let
// those configurations report SKIPPED.
#if !defined(__APPLE__) || defined(__cpp_exceptions)
BOOST_OUTCOME_AUTO_TEST_CASE(works / outcome / comparison, "Tests that the outcome can compare to compatible outcomes")
{
  using namespace OUTCOME_V2_NAMESPACE;
  auto p = std::make_exception_ptr(std::runtime_error("hi"));
  // value comparison
  {
    outcome<int> a(1), b(2), c(2);
    BOOST_CHECK(a == a);
    BOOST_CHECK(b == b);
    BOOST_CHECK(c == c);
    BOOST_CHECK(a != b);
    BOOST_CHECK(b == c);
  }
  // homogeneous outcome comparison
  {
    outcome<int> a(1), b(2), c(std::errc::invalid_argument), d(p);
    BOOST_CHECK(a == a);
    BOOST_CHECK(a != b);
    BOOST_CHECK(a != c);
    BOOST_CHECK(a != d);
    BOOST_CHECK(b == b);
    BOOST_CHECK(b != c);
    BOOST_CHECK(b != d);
    BOOST_CHECK(c == c);
    BOOST_CHECK(c != d);
    BOOST_CHECK(d == d);
    outcome<int> e(std::errc::invalid_argument), f(p);
    BOOST_CHECK(c == e);
    BOOST_CHECK(d == f);
  }
  // heterogeneous outcome comparison, so outcome<int> to outcome<double> etc
  {
    outcome<int> a(1);
    outcome<double> b(1);
    outcome<unsigned short> c(1);
    BOOST_CHECK(a == b);
    BOOST_CHECK(a == c);
    BOOST_CHECK(b == a);
    BOOST_CHECK(b == c);
    BOOST_CHECK(c == a);
    BOOST_CHECK(c == b);
    // outcome<void> e(in_place_type<void>);
    outcome<unsigned short> f(std::errc::invalid_argument);
    outcome<double> g(p);
    // BOOST_CHECK(a != e);
    BOOST_CHECK(a != f);
    BOOST_CHECK(a != g);
    // BOOST_CHECK(e != f);
    BOOST_CHECK(f != g);
  }
  // upconverting outcome comparison, so outcome<int>==result<int> etc
  {
    outcome<int> a(1);
    result<int> b(1);
    BOOST_CHECK(a == b);
    BOOST_CHECK(b == a);
    // result<void> e(in_place_type<void>), f(std::errc::invalid_argument);
    // BOOST_CHECK(a != e);
    // BOOST_CHECK(a != f);
  }
  // Should I do outcome<int>(5) == 5? Unsure if it's wise
}
#else
#include "skip_test.hpp"

BOOST_OUTCOME_AUTO_TEST_CASE(works / outcome / comparison, "Tests that the outcome can compare to compatible outcomes")
// Two arguments, not three: BOOST_OUTCOME_AUTO_TEST_CASE forwards to
// BOOST_AUTO_TEST_CASE, which takes a name and a description and no more. The
// skip reason used to be passed as a third argument here, which no compiler
// accepts ("too many arguments provided to function-like macro invocation"),
// so this branch could not be built anywhere - and the exceptions-disabled
// duplicate of this file is the only thing that ever builds it on Apple, which
// is where the macOS job failed. The reason lives in the SKIP_TEST_IF_DISABLED
// message below, as it does in the ten other files which skip the same way.
{
  SKIP_TEST_IF_DISABLED("test/tests/comparison.cpp does not build in this configuration");
}
#endif
