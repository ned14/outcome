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

#include "../../include/outcome.hpp"
#include "quickcpplib/boost/test/unit_test.hpp"

BOOST_OUTCOME_AUTO_TEST_CASE(issues / 0061 / result, "result<T1, E1> does not compare to incompatible result<T2, E2>")
{
  using namespace OUTCOME_V2_NAMESPACE;
  struct udt1
  {
    const char *_v{nullptr};
    udt1() = default;
    constexpr udt1(const char *v) noexcept : _v(v) {}  // NOLINT
    udt1(udt1 &&o) = delete;
    udt1(const udt1 &) = delete;
    udt1 &operator=(udt1 &&o) = delete;
    udt1 &operator=(const udt1 &) = delete;
    ~udt1() = default;
    constexpr const char *operator*() const noexcept { return _v; }
  };
  struct udt2
  {
    const char *_v{nullptr};
    udt2() = default;
    constexpr explicit udt2(const char *v) noexcept : _v(v) {}
    udt2(udt2 &&o) = delete;
    udt2(const udt2 &) = delete;
    udt2 &operator=(udt2 &&o) = delete;
    udt2 &operator=(const udt2 &) = delete;
    ~udt2() = default;
    constexpr const char *operator*() const noexcept { return _v; }
    bool operator==(const udt1 &o) const noexcept { return _v == *o; }
    bool operator!=(const udt1 &o) const noexcept { return _v != *o; }
  };
  using result1 = result<int, udt1>;
  using result2 = result<int, udt2>;

  result1 a(5);
  result2 b(5);
  BOOST_CHECK(b == a);     // udt2 will compare to udt1
  BOOST_CHECK(!(b != a));  // udt2 will compare to udt1

  result<void> c = success();
  result<void> d = success();
  BOOST_CHECK(c == d);
  BOOST_CHECK(!(c != d));

  BOOST_CHECK(a == success());
  BOOST_CHECK(success() == a);
  BOOST_CHECK(b != failure("foo"));
  BOOST_CHECK(failure("foo") != b);
}

BOOST_OUTCOME_AUTO_TEST_CASE(issues / 0061 / outcome, "outcome<T1, E1, P1> does not compare to incompatible outcome<T2, E2, P2>")
{
  using namespace OUTCOME_V2_NAMESPACE;
  struct udt1
  {
    const char *_v{nullptr};
    udt1() = default;
    constexpr udt1(const char *v) noexcept : _v(v) {}  // NOLINT
    udt1(udt1 &&o) = delete;
    udt1(const udt1 &) = delete;
    udt1 &operator=(udt1 &&o) = delete;
    udt1 &operator=(const udt1 &) = delete;
    ~udt1() = default;
    constexpr const char *operator*() const noexcept { return _v; }
  };
  struct udt2
  {
    const char *_v{nullptr};
    udt2() = default;
    constexpr explicit udt2(const char *v) noexcept : _v(v) {}
    udt2(udt2 &&o) = delete;
    udt2(const udt2 &) = delete;
    udt2 &operator=(udt2 &&o) = delete;
    udt2 &operator=(const udt2 &) = delete;
    ~udt2() = default;
    constexpr const char *operator*() const noexcept { return _v; }
    bool operator==(const udt1 &o) const noexcept { return _v == *o; }
    bool operator!=(const udt1 &o) const noexcept { return _v != *o; }
  };
  using outcome1 = outcome<int, udt1>;
  using outcome2 = outcome<int, udt2>;

  outcome1 a(5), _a(6);
  outcome2 b(5);
  BOOST_CHECK(b == a);     // udt2 will compare to udt1
  BOOST_CHECK(!(b != a));  // udt2 will compare to udt1

  outcome<void> c = success();
  outcome<void> d = success();
  BOOST_CHECK(c == d);
  BOOST_CHECK(!(c != d));

  BOOST_CHECK(a == success());
  BOOST_CHECK(success() == a);
  BOOST_CHECK(b != failure("foo"));
  BOOST_CHECK(failure("foo") != b);
}
