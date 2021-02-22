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

#if __cplusplus >= 201700 || _HAS_CXX17
// Match LiteralType, even on C++ 17 and later
template <class T> struct is_literal_type
{
  static constexpr bool value =   //
  std::is_void<T>::value          //
  || std::is_scalar<T>::value     //
  || std::is_reference<T>::value  //
  // leave out is_array for simplicity
  || (std::is_class<T>::value && std::is_trivially_destructible<T>::value
      // how does one detect if a type has at least one constexpr constructor without Reflection???
      )  // leave out union for simplicity
  ;
};
#else
template <class T> using is_literal_type = std::is_literal_type<T>;
#endif

BOOST_OUTCOME_AUTO_TEST_CASE(works / outcome / constexpr, "Tests that outcome works as intended in a constexpr evaluation context")
{
  using namespace OUTCOME_V2_NAMESPACE;

  static_assert(is_literal_type<result<int, void, void>>::value, "result<int, void, void> is not a literal type!");
  static_assert(is_literal_type<outcome<int, void, void>>::value, "outcome<int, void, void> is not a literal type!");

  // Unfortunately result<T> can never be a literal type as error_code can never be literal
  //
  // It can however be trivially destructible as error_code is trivially destructible. That
  // makes possible lots of compiler optimisations
  static_assert(std::is_trivially_destructible<result<int>>::value, "result<int> is not trivially destructible!");
  static_assert(std::is_trivially_destructible<result<void>>::value, "result<void> is not trivially destructible!");

  // outcome<T> default has no trivial operations, but if configured it can become so
  static_assert(std::is_trivially_destructible<outcome<int, std::error_code, void>>::value,
                "outcome<int, std::error_code, void> is not trivially destructible!");

  {
    // Test compatible results can be constructed from one another
    constexpr result<int, long> g(in_place_type<int>, 5);
    constexpr result<long, int> g2(g);
    static_assert(g.has_value(), "");
    static_assert(!g.has_error(), "");
    static_assert(g.assume_value() == 5, "");  // value() with UDT E won't compile
    static_assert(g2.has_value(), "");
    static_assert(!g2.has_error(), "");
    static_assert(g2.assume_value() == 5, "");  // value() with UDT E won't compile
    constexpr result<void, int> g3(in_place_type<void>);
    constexpr result<long, int> g4(g3);
    constexpr result<int, void> g5(in_place_type<void>);
    constexpr result<long, int> g6(g5);
    (void) g4;
    (void) g6;

    // Test void
    constexpr result<void, int> h(in_place_type<void>);
    static_assert(h.has_value(), "");
    constexpr result<int, void> h2(in_place_type<void>);
    static_assert(!h2.has_value(), "");
    static_assert(h2.has_error(), "");

    // Test const
    constexpr result<const int, void> i(5);
    constexpr result<const int, void> i2(i);
    (void) i2;
  }
  {
    // Test compatible outcomes can be constructed from one another
    constexpr outcome<int, long, char *> g(in_place_type<int>, 5);
    constexpr outcome<long, int, const char *> g2(g);
    static_assert(g.has_value(), "");
    static_assert(!g.has_error(), "");
    static_assert(!g.has_exception(), "");
    static_assert(g.assume_value() == 5, "");  // value() with UDT E won't compile
    static_assert(g2.has_value(), "");
    static_assert(!g2.has_error(), "");
    static_assert(!g2.has_exception(), "");
    static_assert(g2.assume_value() == 5, "");  // value() with UDT E won't compile
    constexpr outcome<void, int, char *> g3(in_place_type<void>);
    constexpr outcome<long, int, const char *> g4(g3);
    constexpr outcome<int, void, char *> g5(in_place_type<void>);
    constexpr outcome<long, int, const char *> g6(g5);
    (void) g4;
    (void) g6;
  }
}
