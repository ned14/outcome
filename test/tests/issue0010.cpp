/* Unit testing for outcomes
(C) 2013-2017 Niall Douglas <http://www.nedproductions.biz/> (149 commits)


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

#include "../../include/outcome/outcome.hpp"
#include "../quickcpplib/include/boost/test/unit_test.hpp"

BOOST_AUTO_TEST_CASE(issues / 10, "Expected's operator->(), operator*() and .error() throw exceptions when they should not")
{
  using namespace BOOST_OUTCOME_V1_NAMESPACE::experimental;
  const char *a = "hi", *b = "bye";
  struct udt1  // NOLINT
  {
    const char *_v{nullptr};
    udt1() = default;
    constexpr explicit udt1(const char *v) noexcept : _v(v) {}
    QUICKCPPLIB_CONSTEXPR udt1(udt1 &&o) noexcept : _v(o._v) { o._v = nullptr; }
    udt1(const udt1 &) = default;
    QUICKCPPLIB_CONSTEXPR udt1 &operator=(udt1 &&o) noexcept
    {
      _v = o._v;
      o._v = nullptr;
      return *this;
    }
    udt1 &operator=(const udt1 &) = delete;
    constexpr const char *operator*() const noexcept { return _v; }
  };
  struct udt2  // NOLINT
  {
    const char *_v{nullptr};
    udt2() = default;
    constexpr explicit udt2(const char *v) noexcept : _v(v) {}
    QUICKCPPLIB_CONSTEXPR udt2(udt2 &&o) noexcept : _v(o._v) { o._v = nullptr; }
    udt2(const udt2 &) = default;
    QUICKCPPLIB_CONSTEXPR udt2 &operator=(udt2 &&o) noexcept
    {
      _v = o._v;
      o._v = nullptr;
      return *this;
    }
    udt1 &operator=(const udt1 &) = delete;
    constexpr const char *operator*() const noexcept { return _v; }
  };
  expected<udt1, udt2> p(udt1{a});
  expected<udt1, udt2> n(make_unexpected(udt2(b)));
  // State check
  BOOST_CHECK(p.has_value());
  BOOST_CHECK(!n.has_value());
  // These should behave as expected (!)
  BOOST_CHECK_NO_THROW(p.value());
  BOOST_CHECK_THROW(n.value(), const bad_expected_access<udt2> &);
  // And state is not destroyed
  BOOST_CHECK(p.has_value() && **p == a);
  BOOST_CHECK(!n.has_value() && *n.error() == b);
  // LEWG Expected requires these to work as if reinterpret_cast irrespective of state
  BOOST_CHECK_NO_THROW(p.error());  // error from valued state
  BOOST_CHECK_NO_THROW(*n);         // value from errored state
  // LEWG Expected provides rvalue ref semantics for operator*(), error() and error_or()
  udt1 a1(std::move(*p));
  BOOST_CHECK(*a1 == a);
  BOOST_CHECK(**p == nullptr);
  udt2 e2(std::move(n).error());
  BOOST_CHECK(*e2 == b);
  BOOST_CHECK(*n.error() == nullptr);  // NOLINT
  n.set_error(udt2(b));
  e2 = std::move(n).error_or(udt2(a));
  BOOST_CHECK(*e2 == b);
  BOOST_CHECK(*n.error() == nullptr);  // NOLINT
}

