/* Unit testing for outcomes
(C) 2013-2019 Niall Douglas <http://www.nedproductions.biz/> (9 commits)


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

BOOST_OUTCOME_AUTO_TEST_CASE(issues / 0010 / test, "Expected's operator->(), operator*() and .error() throw exceptions when they should not")
{
  using namespace OUTCOME_V2_NAMESPACE;
  const char *a = "hi", *b = "bye";
  struct udt1  // NOLINT
  {
    const char *_v{nullptr};
    udt1() = default;
    constexpr explicit udt1(const char *v) noexcept : _v(v) {}
    constexpr udt1(udt1 &&o) noexcept : _v(o._v) { o._v = nullptr; }
    udt1(const udt1 &) = default;
    constexpr udt1 &operator=(udt1 &&o) noexcept
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
    constexpr udt2(udt2 &&o) noexcept : _v(o._v) { o._v = nullptr; }
    udt2(const udt2 &) = default;
    constexpr udt2 &operator=(udt2 &&o) noexcept
    {
      _v = o._v;
      o._v = nullptr;
      return *this;
    }
    udt1 &operator=(const udt1 &) = delete;
    constexpr const char *operator*() const noexcept { return _v; }
  };
  result<udt1, udt2> p(udt1{a});
  result<udt1, udt2> n(udt2{b});
  // State check
  BOOST_CHECK(p.has_value());
  BOOST_CHECK(!n.has_value());
  // These should behave as expected (!)
  // BOOST_CHECK_NO_THROW(p.value());
  // BOOST_CHECK_NO_THROW(n.value());
  // And state is not destroyed
  BOOST_CHECK(p.has_value() && *p.assume_value() == a);
  BOOST_CHECK(!n.has_value() && *n.assume_error() == b);
  // LEWG Expected provides rvalue ref semantics for operator*(), error() and error_or()
  udt1 a1(std::move(p.assume_value()));
  BOOST_CHECK(*a1 == a);
  BOOST_CHECK(*p.assume_value() == nullptr);
  udt2 e2(std::move(n).assume_error());
  BOOST_CHECK(*e2 == b);
  BOOST_CHECK(*n.assume_error() == nullptr);  // NOLINT
}
