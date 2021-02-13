/* Unit testing for outcomes
(C) 2013-2021 Niall Douglas <http://www.nedproductions.biz/> (1 commit)


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

#include "../../include/outcome/result.hpp"
#include "../../include/outcome/try.hpp"
#include "quickcpplib/boost/test/unit_test.hpp"

namespace issues244
{
  namespace outcome = OUTCOME_V2_NAMESPACE;

  static int counter = 0;
  static std::vector<int> default_constructor, copy_constructor, move_constructor, destructor;
  struct Foo
  {
    int x{2};
    explicit Foo(int v)
        : x(v)
    {
      std::cout << "   Default constructor " << ++counter << std::endl;
      default_constructor.push_back(counter);
    }
    Foo(const Foo &o) noexcept
        : x(o.x)
    {
      std::cout << "   Copy constructor " << ++counter << std::endl;
      copy_constructor.push_back(counter);
    }
    Foo(Foo &&o) noexcept
        : x(o.x)
    {
      std::cout << "   Move constructor " << ++counter << std::endl;
      move_constructor.push_back(counter);
    }
    ~Foo()
    {
      std::cout << "   Destructor " << ++counter << std::endl;
      destructor.push_back(counter);
    }
  };
  struct Immovable
  {
    int x{2};
    explicit Immovable(int v)
        : x(v)
    {
    }
      Immovable(const Immovable &) = delete;
    Immovable(Immovable &&) = delete;
  };

  outcome::result<Foo> get_foo() noexcept { return outcome::result<Foo>(outcome::in_place_type<Foo>, 5); }

  template <typename T> T &&filterR(T &&v) { return static_cast<T &&>(v); }
  template <typename T> const T &filterL(T &&v) { return v; }
}  // namespace issues244


BOOST_OUTCOME_AUTO_TEST_CASE(issues / 0244 / test, "TRY/TRYX has dangling reference if xvalues are emitted from tried expression")
{
  using namespace issues244;
  auto check = [](const char *desc, auto &&f) {
    counter = 0;
    default_constructor.clear();
    copy_constructor.clear();
    move_constructor.clear();
    destructor.clear();
    std::cout << "\n" << desc << std::endl;
    auto r = f();
    std::cout << "   Check integer " << ++counter << std::endl;
    BOOST_REQUIRE(r);
    BOOST_CHECK(r.value() == 5);
    if(!copy_constructor.empty())
    {
      BOOST_CHECK(copy_constructor.front() < destructor.front());
    }
    else if(!move_constructor.empty())
    {
      BOOST_CHECK(move_constructor.front() < destructor.front());
    }
  };

  /*
   Default constructor 1    (bind expression prvalue to unique rvalue)
   Move constructor 2       (move from unique rvalue to v value)
   After TRY 3
   Destructor 4             (destruct v value)
   Destructor 5             (destruct lifetime extended unique rvalue)
   Check integer 6
  */
  check("prvalue from expression with lifetime extension is moved into value", []() -> outcome::result<int> {
    OUTCOME_TRY(auto v, get_foo());
    std::cout << "   After TRY " << ++counter << std::endl;
    return v.x;
  });
  /*
   Default constructor 1    (bind expression prvalue to unique rvalue)
                            (bind unique rvalue to v rvalue)
   After TRY 2
   Destructor 3             (destruct lifetime extended unique rvalue)
   Check integer 4
  */
  check("prvalue from expression with lifetime extension is bound into rvalue", []() -> outcome::result<int> {
    OUTCOME_TRY(auto &&v, get_foo());
    std::cout << "   After TRY " << ++counter << std::endl;
    return v.x;
  });

  /*
   Default constructor 1
   Move constructor 2       (move expression xvalue into unique value)
   Destructor 3             (destruct expression xvalue)
   Move constructor 4       (move from unique value to v value)
   After TRY 5
   Destructor 6             (destruct v value)
   Destructor 7             (destruct unique value)
   Check integer 8
  */
  check("xvalue from expression without lifetime extension is moved into temporary and then moved into value", []() -> outcome::result<int> {
    OUTCOME_TRY(auto v, filterR(get_foo()));
    std::cout << "   After TRY " << ++counter << std::endl;
    return v.x;
  });
  /*
   Default constructor 1
   Move constructor 2       (move expression xvalue into unique value)
   Destructor 3             (destruct expression xvalue)
   After TRY 4
   Destructor 5             (destruct unique value)
   Check integer 6
  */
  check("xvalue from expression without lifetime extension is moved into temporary and then bound into rvalue", []() -> outcome::result<int> {
    OUTCOME_TRY(auto &&v, filterR(get_foo()));
    std::cout << "   After TRY " << ++counter << std::endl;
    return v.x;
  });

  /*
   Default constructor 1
   Copy constructor 2       (copy expression lvalue into unique value)
   Destructor 3             (destruct expression lvalue)
   Copy constructor 4       (copy from unique value to v value)
   After TRY 5
   Destructor 6             (destruct v value)
   Destructor 7             (destruct unique value)
   Check integer 8
  */
  check("lvalue from expression without lifetime extension is moved into temporary and then moved into value", []() -> outcome::result<int> {
    OUTCOME_TRY(auto v, filterL(get_foo()));
    std::cout << "   After TRY " << ++counter << std::endl;
    return v.x;
  });
  /*
   Default constructor 1
   Copy constructor 2       (copy expression lvalue into unique value)
   Destructor 3             (destruct expression lvalue)
   After TRY 4
   Destructor 5             (destruct unique value)
   Check integer 6
  */
  check("lvalue from expression without lifetime extension is moved into temporary and then bound into rvalue", []() -> outcome::result<int> {
    OUTCOME_TRY(auto &&v, filterL(get_foo()));
    std::cout << "   After TRY " << ++counter << std::endl;
    return v.x;
  });


  check("TRY lvalue passthrough", []() -> outcome::result<int> {
    const auto &x = outcome::result<Immovable>(outcome::in_place_type<Immovable>, 5);
    // Normally a lvalue input triggers value unique, which would fail to compile here
    OUTCOME_TRY((auto &, v), x);
    return v.x;
  });

  // Force use of rvalue refs for unique and bound value
  check("TRY rvalue passthrough", []() -> outcome::result<int> {
    auto &&x = outcome::result<Immovable>(outcome::in_place_type<Immovable>, 5);
    // Normally an xvalue input triggers value unique, which would fail to compile here
    OUTCOME_TRY((auto &&, v), x);
    return v.x;
  });

  // Force use of lvalue refs for unique and bound value
  check("TRY prvalue as lvalue passthrough", []() -> outcome::result<int> {
    outcome::result<Immovable> i(outcome::in_place_type<Immovable>, 5);
    OUTCOME_TRY((auto &, v), i);
    return v.x;
  });

  // Force use of rvalue refs for unique and bound value
  check("TRY prvalue as rvalue passthrough", []() -> outcome::result<int> {
    outcome::result<Immovable> i(outcome::in_place_type<Immovable>, 5);
    OUTCOME_TRY((auto &&, v), i);
    return v.x;
  });


  check("TRYV lvalue passthrough", []() -> outcome::result<int> {
    const auto &x = outcome::result<Immovable>(outcome::in_place_type<Immovable>, 5);
    // Normally a lvalue input triggers value unique, which would fail to compile here
    OUTCOME_TRYV2(auto &, x);
    return 5;
  });

  // Force use of rvalue refs for unique and bound value
  check("TRYV rvalue passthrough", []() -> outcome::result<int> {
    auto &&x = outcome::result<Immovable>(outcome::in_place_type<Immovable>, 5);
    // Normally an xvalue input triggers value unique, which would fail to compile here
    OUTCOME_TRYV2(auto &&, x);
    return 5;
  });

  // Force use of lvalue refs for unique and bound value
  check("TRYV prvalue as lvalue passthrough", []() -> outcome::result<int> {
    outcome::result<Immovable> i(outcome::in_place_type<Immovable>, 5);
    OUTCOME_TRYV2(auto &, i);
    return 5;
  });

  // Force use of rvalue refs for unique and bound value
  check("TRYV prvalue as rvalue passthrough", []() -> outcome::result<int> {
    outcome::result<Immovable> i(outcome::in_place_type<Immovable>, 5);
    OUTCOME_TRYV2(auto &, i);
    return 5;
  });
}
