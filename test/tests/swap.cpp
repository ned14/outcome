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
#include "quickcpplib/boost/test/unit_test.hpp"

/* Should be this:

78 move constructor count = 2
65 move assignment count = 3
78 move assignment count = 1
65 move constructor count = 2
78 move assignment count = 0
65 move assignment count = 1

78 move constructor count = 1
65 move assignment count = 2
78 move assignment count = 0
65 move assignment count = 1
78 move assignment count = 0

78 move constructor count = 2
65 move assignment count = 3
78 move assignment count = 1
65 move constructor count = 2
78 move assignment count = 0
65 move assignment count = 1

78 move constructor count = 1
65 move assignment count = 2
78 move assignment count = 0
65 move assignment count = 1
78 move assignment count = 0

78 move constructor count = 2
65 move assignment count = 3
78 move assignment count = 1
65 move constructor count = 2
78 move assignment count = 0
65 move assignment count = 1

78 move constructor count = 1
65 move assignment count = 2
78 move assignment count = 0
65 move assignment count = 1
78 move assignment count = 0

78 move constructor count = 2
65 move assignment count = 3
78 move assignment count = 1
65 move constructor count = 2
78 move assignment count = 0
65 move assignment count = 1

78 move constructor count = 1
65 move assignment count = 2
78 move assignment count = 0
65 move assignment count = 1
78 move assignment count = 0
*/

#ifdef __cpp_exceptions
#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable: 4297)  // function assumed not to throw an exception but does
#endif
#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wterminate"
#endif
template <bool mc, bool ma> struct Throwy
{
  int count{0}, inc{0}, id{0};
  Throwy() = default;
  Throwy(int c, int d, int i = 1) noexcept
      : count(c)
      , inc(i)
      , id(d)
  {
  }
  Throwy(const Throwy &) = delete;
  Throwy &operator=(const Throwy &) = delete;
  Throwy(Throwy &&o) noexcept(!mc)
      : count(o.count - o.inc)
      , inc(o.inc)
      , id(o.id)  // NOLINT
  {
    if(mc)
    {
      std::cout << "   " << id << " move constructor count = " << count << std::endl;
      if(!count)
      {
        std::cout << "      " << id << " move constructor throws!" << std::endl;
        throw std::bad_alloc();
      }
    }
    o.count = 0;
    o.inc = 0;
    o.id = 0;
  }
  Throwy &operator=(Throwy &&o) noexcept(!ma)
  {
    count = o.count - o.inc;
    if(ma)
    {
      std::cout << "   " << o.id << " move assignment count = " << count << std::endl;
      if(!count)
      {
        std::cout << "      " << o.id << " move assignment throws!" << std::endl;
        throw std::bad_alloc();
      }
    }
    inc = o.inc;
    id = o.id;
    o.count = 0;
    o.inc = 0;
    o.id = 0;
    return *this;
  }
  ~Throwy() = default;
};
#if defined(__GNUC__) && !defined(__clang__)
#pragma GCC diagnostic pop
#endif
#ifdef _MSC_VER
#pragma warning(pop)
#endif
enum class ErrorCode
{
  dummy
};
enum class ErrorCode2
{
  dummy
};
template <bool mc, bool ma> using resulty1 = OUTCOME_V2_NAMESPACE::result<Throwy<mc, ma>, ErrorCode, OUTCOME_V2_NAMESPACE::policy::all_narrow>;
template <bool mc, bool ma> using resulty2 = OUTCOME_V2_NAMESPACE::result<ErrorCode, Throwy<mc, ma>, OUTCOME_V2_NAMESPACE::policy::all_narrow>;
template <bool mc, bool ma> using outcomey1 = OUTCOME_V2_NAMESPACE::outcome<ErrorCode, Throwy<mc, ma>, ErrorCode2, OUTCOME_V2_NAMESPACE::policy::all_narrow>;
template <bool mc, bool ma> using outcomey2 = OUTCOME_V2_NAMESPACE::outcome<ErrorCode, ErrorCode2, Throwy<mc, ma>, OUTCOME_V2_NAMESPACE::policy::all_narrow>;
#endif

BOOST_OUTCOME_AUTO_TEST_CASE(works / outcome / swap, "Tests that the outcome swaps as intended")
{
  using namespace OUTCOME_V2_NAMESPACE;
  {  // Does swap actually swap?
    outcome<std::string> a("niall"), b("douglas");
    BOOST_CHECK(a.value() == "niall");
    BOOST_CHECK(b.value() == "douglas");
    swap(a, b);
    BOOST_CHECK(a.value() == "douglas");
    BOOST_CHECK(b.value() == "niall");
    a = std::errc::not_enough_memory;
    swap(a, b);
    BOOST_CHECK(a.value() == "niall");
    BOOST_CHECK(b.error() == std::errc::not_enough_memory);
    BOOST_CHECK(!a.has_lost_consistency());
    BOOST_CHECK(!b.has_lost_consistency());
  }
#ifdef __cpp_exceptions
  {  // Is noexcept propagated?
    using nothrow_t = Throwy<false, false>;
    using nothrow = resulty1<false, false>;
    static_assert(std::is_nothrow_move_constructible<nothrow_t>::value, "throwy not correct!");
    static_assert(std::is_nothrow_move_assignable<nothrow_t>::value, "throwy not correct!");
    static_assert(std::is_nothrow_move_constructible<nothrow>::value, "type not correct!");
    static_assert(std::is_nothrow_move_assignable<nothrow>::value, "type not correct!");

    static_assert(detail::is_nothrow_swappable<nothrow_t>::value, "is_nothrow_swappable is not correct!");

    static_assert(noexcept(nothrow(0, 0)), "type has a throwing value constructor!");
    nothrow a(1, 78), b(1, 65);
    a.swap(b);
    static_assert(noexcept(a.swap(b)), "type has a throwing swap!");
  }
  {  // Is noexcept propagated?
    using nothrow_t = Throwy<false, false>;
    using nothrow = resulty2<false, false>;
    static_assert(std::is_nothrow_move_constructible<nothrow_t>::value, "throwy not correct!");
    static_assert(std::is_nothrow_move_assignable<nothrow_t>::value, "throwy not correct!");
    static_assert(std::is_nothrow_move_constructible<nothrow>::value, "type not correct!");
    static_assert(std::is_nothrow_move_assignable<nothrow>::value, "type not correct!");

    static_assert(detail::is_nothrow_swappable<nothrow_t>::value, "is_nothrow_swappable is not correct!");

    static_assert(noexcept(nothrow(0, 0)), "type has a throwing value constructor!");
    nothrow a(1, 78), b(1, 65);
    a.swap(b);
    static_assert(noexcept(a.swap(b)), "type has a throwing swap!");
  }

  {  // Does swap implement the strong guarantee?
    using throwy_t = Throwy<true, true>;
    using throwy = resulty1<true, true>;
    static_assert(!std::is_nothrow_move_constructible<throwy_t>::value, "throwy not correct!");
    static_assert(!std::is_nothrow_move_assignable<throwy_t>::value, "throwy not correct!");
    static_assert(!std::is_nothrow_move_constructible<throwy>::value, "type not correct!");
    static_assert(!std::is_nothrow_move_assignable<throwy>::value, "type not correct!");

    static_assert(!detail::is_nothrow_swappable<throwy_t>::value, "is_nothrow_swappable is not correct!");

    std::cout << "Result value first swap succeeds, second swap second move assignment throws:" << std::endl;
    {
      throwy a(3, 78), b(4, 65);
      a.swap(b);
      static_assert(!noexcept(a.swap(b)), "type has a non-throwing swap!");
      BOOST_CHECK(a.value().id == 65);
      BOOST_CHECK(b.value().id == 78);
      try
      {
        a.swap(b);  // fails on first assignment
        BOOST_REQUIRE(false);
      }
      catch(const std::bad_alloc & /*unused*/)
      {
        BOOST_CHECK(a.value().id == 65);  // ensure it is perfectly restored
        BOOST_CHECK(b.value().id == 78);
      }
      BOOST_CHECK(!a.has_lost_consistency());
      BOOST_CHECK(!b.has_lost_consistency());
    }
    std::cout << "\nResult value second move assignment throws, on recover second move assignment throws:" << std::endl;
    {
      throwy a(2, 78), b(3, 65);  // fails on second assignment, cannot restore
      try
      {
        a.swap(b);
        BOOST_REQUIRE(false);
      }
      catch(const std::bad_alloc & /*unused*/)
      {
        BOOST_CHECK(a.has_lost_consistency());  // both must be marked tainted
        BOOST_CHECK(b.has_lost_consistency());
      }
    }
  }
  std::cout << "\nResult error first swap succeeds, second swap first move assignment throws:" << std::endl;
  {  // Does swap implement the strong guarantee?
    using throwy_t = Throwy<true, true>;
    using throwy = resulty2<true, true>;
    static_assert(!std::is_nothrow_move_constructible<throwy_t>::value, "throwy not correct!");
    static_assert(!std::is_nothrow_move_assignable<throwy_t>::value, "throwy not correct!");
    static_assert(!std::is_nothrow_move_constructible<throwy>::value, "type not correct!");
    static_assert(!std::is_nothrow_move_assignable<throwy>::value, "type not correct!");

    static_assert(!detail::is_nothrow_swappable<throwy_t>::value, "is_nothrow_swappable is not correct!");

    {
      throwy a(3, 78), b(4, 65);
      a.swap(b);
      static_assert(!noexcept(a.swap(b)), "type has a non-throwing swap!");
      BOOST_CHECK(a.error().id == 65);
      BOOST_CHECK(b.error().id == 78);
      try
      {
        a.swap(b);  // fails on first assignment
        BOOST_REQUIRE(false);
      }
      catch(const std::bad_alloc & /*unused*/)
      {
        BOOST_CHECK(a.error().id == 65);  // ensure it is perfectly restored
        BOOST_CHECK(b.error().id == 78);
      }
      BOOST_CHECK(!a.has_lost_consistency());
      BOOST_CHECK(!b.has_lost_consistency());
    }
    std::cout << "\nResult error second move assignment throws, on recover second move assignment throws:" << std::endl;
    {
      throwy a(2, 78), b(3, 65);  // fails on second assignment, cannot restore
      try
      {
        a.swap(b);
        BOOST_REQUIRE(false);
      }
      catch(const std::bad_alloc & /*unused*/)
      {
        BOOST_CHECK(a.has_lost_consistency());  // both must be marked tainted
        BOOST_CHECK(b.has_lost_consistency());
      }
    }
  }

  {  // Is noexcept propagated?
    using nothrow_t = Throwy<false, false>;
    using nothrow = outcomey1<false, false>;
    static_assert(std::is_nothrow_move_constructible<nothrow_t>::value, "throwy not correct!");
    static_assert(std::is_nothrow_move_assignable<nothrow_t>::value, "throwy not correct!");
    static_assert(std::is_nothrow_move_constructible<nothrow>::value, "type not correct!");
    static_assert(std::is_nothrow_move_assignable<nothrow>::value, "type not correct!");

    static_assert(detail::is_nothrow_swappable<nothrow_t>::value, "is_nothrow_swappable is not correct!");

    static_assert(noexcept(nothrow(0, 0)), "type has a throwing value constructor!");
    nothrow a(1, 78), b(1, 65);
    a.swap(b);
    static_assert(noexcept(a.swap(b)), "type has a throwing swap!");
  }
  {  // Is noexcept propagated?
    using nothrow_t = Throwy<false, false>;
    using nothrow = outcomey1<false, false>;
    static_assert(std::is_nothrow_move_constructible<nothrow_t>::value, "throwy not correct!");
    static_assert(std::is_nothrow_move_assignable<nothrow_t>::value, "throwy not correct!");
    static_assert(std::is_nothrow_move_constructible<nothrow>::value, "type not correct!");
    static_assert(std::is_nothrow_move_assignable<nothrow>::value, "type not correct!");

    static_assert(detail::is_nothrow_swappable<nothrow_t>::value, "is_nothrow_swappable is not correct!");

    static_assert(noexcept(nothrow(0, 0)), "type has a throwing value constructor!");
    nothrow a(1, 78), b(1, 65);
    a.swap(b);
    static_assert(noexcept(a.swap(b)), "type has a throwing swap!");
  }

  std::cout << "\n\nOutcome value first swap succeeds, second swap first move assignment throws:" << std::endl;
  {  // Does swap implement the strong guarantee?
    using throwy_t = Throwy<true, true>;
    using throwy = outcomey1<true, true>;
    static_assert(!std::is_nothrow_move_constructible<throwy_t>::value, "throwy not correct!");
    static_assert(!std::is_nothrow_move_assignable<throwy_t>::value, "throwy not correct!");
    static_assert(!std::is_nothrow_move_constructible<throwy>::value, "type not correct!");
    static_assert(!std::is_nothrow_move_assignable<throwy>::value, "type not correct!");

    static_assert(!detail::is_nothrow_swappable<throwy_t>::value, "is_nothrow_swappable is not correct!");

    {
      throwy a(3, 78), b(4, 65);
      a.swap(b);
      static_assert(!noexcept(a.swap(b)), "type has a non-throwing swap!");
      BOOST_CHECK(a.error().id == 65);
      BOOST_CHECK(b.error().id == 78);
      try
      {
        a.swap(b);  // fails on first assignment
        BOOST_REQUIRE(false);
      }
      catch(const std::bad_alloc & /*unused*/)
      {
        BOOST_CHECK(a.error().id == 65);  // ensure it is perfectly restored
        BOOST_CHECK(b.error().id == 78);
      }
      BOOST_CHECK(!a.has_lost_consistency());
      BOOST_CHECK(!b.has_lost_consistency());
    }
    std::cout << "\nOutcome value second move assignment throws, on recover second move assignment throws:" << std::endl;
    {
      throwy a(2, 78), b(3, 65);  // fails on second assignment, cannot restore
      try
      {
        a.swap(b);
        BOOST_REQUIRE(false);
      }
      catch(const std::bad_alloc & /*unused*/)
      {
        BOOST_CHECK(a.has_lost_consistency());  // both must be marked tainted
        BOOST_CHECK(b.has_lost_consistency());
      }
    }
  }
  std::cout << "\nOutcome error first swap succeeds, second swap first move assignment throws:" << std::endl;
  {  // Does swap implement the strong guarantee?
    using throwy_t = Throwy<true, true>;
    using throwy = outcomey2<true, true>;
    static_assert(!std::is_nothrow_move_constructible<throwy_t>::value, "throwy not correct!");
    static_assert(!std::is_nothrow_move_assignable<throwy_t>::value, "throwy not correct!");
    static_assert(!std::is_nothrow_move_constructible<throwy>::value, "type not correct!");
    static_assert(!std::is_nothrow_move_assignable<throwy>::value, "type not correct!");

    static_assert(!detail::is_nothrow_swappable<throwy_t>::value, "is_nothrow_swappable is not correct!");

    {
      throwy a(3, 78), b(4, 65);
      a.swap(b);
      static_assert(!noexcept(a.swap(b)), "type has a non-throwing swap!");
      BOOST_CHECK(a.exception().id == 65);
      BOOST_CHECK(b.exception().id == 78);
      try
      {
        a.swap(b);  // fails on first assignment
        BOOST_REQUIRE(false);
      }
      catch(const std::bad_alloc & /*unused*/)
      {
        BOOST_CHECK(a.exception().id == 65);  // ensure it is perfectly restored
        BOOST_CHECK(b.exception().id == 78);
      }
      BOOST_CHECK(!a.has_lost_consistency());
      BOOST_CHECK(!b.has_lost_consistency());
    }
    std::cout << "\nOutcome error second move assignment throws, on recover second move assignment throws:" << std::endl;
    {
      throwy a(2, 78), b(3, 65);  // fails on second assignment, cannot restore
      try
      {
        a.swap(b);
        BOOST_REQUIRE(false);
      }
      catch(const std::bad_alloc & /*unused*/)
      {
        BOOST_CHECK(a.has_lost_consistency());  // both must be marked tainted
        BOOST_CHECK(b.has_lost_consistency());
      }
    }
    std::cout << std::endl;
  }
#endif
}
