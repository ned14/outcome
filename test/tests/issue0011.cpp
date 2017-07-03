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

#ifdef __cpp_exceptions
BOOST_AUTO_TEST_CASE(issues / 11, "Changing state should never cause an empty state")
{
  using namespace BOOST_OUTCOME_V1_NAMESPACE::experimental;
  const char *a = "hi", *b = "bye";
  // A value type which behaves normally
  struct value  // NOLINT
  {
    const char *_v{nullptr};
    value() = default;
    constexpr explicit value(const char *v) noexcept : _v(v) {}
    value(value &&o) noexcept : _v(o._v) { o._v = nullptr; }
    value(const value &) = default;
    value &operator=(value &&o) noexcept
    {
      _v = o._v;
      o._v = nullptr;
      return *this;
    }
    value &operator=(const value &o) = default;
    constexpr const char *operator*() const noexcept { return _v; }
  };
  // An error type which throws on move
  struct error  // NOLINT
  {
    const char *_v{nullptr};
    error() = default;
    constexpr explicit error(const char *v) noexcept : _v(v) {}
    error(error &&o)  // NOLINT
    {
      if(o._v == nullptr)
      {
        throw std::runtime_error("error move constructor");
      }
    }
    error(const error & /*unused*/) { throw std::runtime_error("error copy constructor"); }
    error &operator=(error && /*unused*/) { throw std::runtime_error("error move assignment"); }  // NOLINT
    error &operator=(const error & /*unused*/) { throw std::runtime_error("error copy assignment"); }
    constexpr const char *operator*() const noexcept { return _v; }
  };
  {
    expected<value, error> x(in_place, a), y(error{b});
    BOOST_CHECK(x && *x.value() == a);
    BOOST_CHECK(!y && *y.error() == nullptr);
    try
    {
      x = y;  // invokes copy constructor as changing state
      BOOST_REQUIRE(false);
    }
    catch(const std::runtime_error &e)
    {
      BOOST_CHECK(std::string(e.what()) == "error copy constructor");
    }
    BOOST_CHECK(x && *x.value() == a);
    BOOST_CHECK(!y && *y.error() == nullptr);
  }
  {
    expected<value, error> x(in_place, a), y(error{b});
    BOOST_CHECK(x && *x.value() == a);
    BOOST_CHECK(!y && *y.error() == nullptr);
    try
    {
      x = std::move(y);  // invokes move constructor as changing state
      BOOST_REQUIRE(false);
    }
    catch(const std::runtime_error &e)
    {
      BOOST_CHECK(std::string(e.what()) == "error move constructor");
    }
    BOOST_CHECK(x && *x.value() == a);
    BOOST_CHECK(!y && *y.error() == nullptr);  // NOLINT
  }
}
#endif

