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

#ifdef _MSC_VER
#pragma warning(disable : 4127)  // conditional expression is constant
#endif

#ifdef __cpp_exceptions
// std nothrow traits seem to return random values if exceptions are disabled on MSVC
BOOST_OUTCOME_AUTO_TEST_CASE(works / outcome / noexcept, "Tests that the outcome correctly inherits noexcept from its type R")
{
  using namespace OUTCOME_V2_NAMESPACE;
  {
    using type = outcome<int>;
    BOOST_CHECK(std::is_nothrow_copy_constructible<type>::value);
    BOOST_CHECK(std::is_nothrow_move_constructible<type>::value);
    BOOST_CHECK(std::is_nothrow_copy_assignable<type>::value);
    BOOST_CHECK(std::is_nothrow_move_assignable<type>::value);
    BOOST_CHECK(std::is_nothrow_destructible<type>::value);
  }
  {
    using type = outcome<std::string>;
    BOOST_CHECK(std::is_nothrow_copy_constructible<type>::value == std::is_nothrow_copy_constructible<std::string>::value);
    BOOST_CHECK(std::is_nothrow_move_constructible<type>::value == std::is_nothrow_move_constructible<std::string>::value);
    BOOST_CHECK(std::is_nothrow_copy_assignable<type>::value == std::is_nothrow_copy_assignable<std::string>::value);
    BOOST_CHECK(std::is_nothrow_move_assignable<type>::value == std::is_nothrow_move_assignable<std::string>::value);
    BOOST_CHECK(std::is_nothrow_destructible<type>::value == std::is_nothrow_destructible<std::string>::value);
  }
  {
    struct Except
    {
      int n;
      Except() = delete;
      Except(const Except & /*unused*/) noexcept(false)
          : n(0)
      {
      }
      Except(Except && /*unused*/) noexcept(false)
          : n(0)
      {
      }
      Except &operator=(const Except & /*unused*/) noexcept(false) { return *this; }
      Except &operator=(Except && /*unused*/) noexcept(false) { return *this; }
      ~Except() noexcept(false) { n = 0; }
    };
    using type = outcome<Except>;
    BOOST_CHECK(!std::is_nothrow_copy_constructible<type>::value);
    BOOST_CHECK(!std::is_nothrow_move_constructible<type>::value);
    BOOST_CHECK(!std::is_nothrow_copy_assignable<type>::value);
    BOOST_CHECK(!std::is_nothrow_move_assignable<type>::value);
    BOOST_CHECK(!std::is_nothrow_destructible<type>::value);
  }
}
#endif
