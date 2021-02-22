/* Unit testing for outcomes
(C) 2013-2019 Niall Douglas <http://www.nedproductions.biz/> (7 commits)


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
#pragma warning(disable : 4702)  // unreachable code
#endif

#include "../../include/outcome.hpp"
#include "quickcpplib/boost/test/unit_test.hpp"

BOOST_OUTCOME_AUTO_TEST_CASE(works / outcome / udts, "Tests that the outcome works as intended with user-defined types")
{
  using namespace OUTCOME_V2_NAMESPACE;
  // No default constructor, no copy/move, no assignment
  {
    struct udt
    {
      int a;
      explicit udt(int _a)
          : a(_a)
      {
      }
      udt() = delete;
      udt(const udt &) = delete;
      udt(udt &&) = delete;
      udt &operator=(const udt &) = delete;
      udt &operator=(udt &&) = delete;
      ~udt() = default;
    };
    outcome<udt> foo(in_place_type<udt>, 5);
    BOOST_CHECK(5 == foo.value().a);
  }
#ifdef __cpp_exceptions
  // Emplace construct, throws during move and copy
  {
    struct udt
    {
      std::string a;
      explicit udt(std::string _a)
          : a(std::move(_a))
      {
      }
      udt() = delete;
      udt(const udt & /*unused*/) { throw std::logic_error("copy"); }
      udt(udt && /*unused*/) noexcept(false) { throw std::logic_error("move"); }  // NOLINT
      udt &operator=(const udt & /*unused*/) { throw std::logic_error("copy"); }
      udt &operator=(udt && /*unused*/) noexcept(false) { throw std::logic_error("move"); }  // NOLINT
      ~udt() { a.clear(); }
    };
    static_assert(!std::is_default_constructible<udt>::value, "udt is default constructible");
    static_assert(std::is_copy_constructible<udt>::value, "udt is not copy constructible");
    static_assert(std::is_move_constructible<udt>::value, "udt is not move constructible");
    static_assert(!std::is_default_constructible<outcome<udt>>::value, "outcome<udt> is default constructible");
    static_assert(std::is_copy_constructible<outcome<udt>>::value, "outcome<udt> is not copy constructible");
    static_assert(std::is_move_constructible<outcome<udt>>::value, "outcome<udt> is not move constructible");
    // Emplace constructs
    outcome<udt> foo(in_place_type<udt>, "niall");
    BOOST_CHECK("niall" == foo.value().a);
    try
    {
      auto foo2(foo);  // NOLINT
      BOOST_CHECK(false);
    }
    catch(const std::logic_error &e)
    {
      BOOST_CHECK(!strcmp(e.what(), "copy"));
    }
    catch(...)
    {
      BOOST_CHECK(false);
    }
    BOOST_CHECK("niall" == foo.value().a);
    try
    {
      auto foo2(std::move(foo));
      BOOST_CHECK(false);
    }
    catch(const std::logic_error &e)
    {
      BOOST_CHECK(!strcmp(e.what(), "move"));
    }
    catch(...)
    {
      BOOST_CHECK(false);
    }
    BOOST_CHECK("niall" == foo.value().a);  // NOLINT
    // Does throwing during copy assignment work?
    {
      outcome<udt> foo2(in_place_type<udt>, "douglas");
      try
      {
        foo2 = foo;
        BOOST_CHECK(false);
      }
      catch(const std::logic_error &e)
      {
        BOOST_CHECK(!strcmp(e.what(), "copy"));
        BOOST_CHECK(foo2.value().a == "douglas");
      }
      catch(...)
      {
        BOOST_CHECK(false);
      }
      BOOST_CHECK("niall" == foo.value().a);
    }
    // Does throwing during move assignment work?
    {
      outcome<udt> foo2(in_place_type<udt>, "douglas");
      try
      {
        foo2 = std::move(foo);
        BOOST_CHECK(false);
      }
      catch(const std::logic_error &e)
      {
        BOOST_CHECK(!strcmp(e.what(), "move"));
        BOOST_CHECK(foo2.value().a == "douglas");
      }
      catch(...)
      {
        BOOST_CHECK(false);
      }
      BOOST_CHECK("niall" == foo.value().a);  // NOLINT
    }
  }
#endif
}
