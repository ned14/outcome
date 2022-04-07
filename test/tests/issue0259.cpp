/* Unit testing for outcomes
(C) 2013-2022 Niall Douglas <http://www.nedproductions.biz/> (1 commit)


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

#include "quickcpplib/boost/test/unit_test.hpp"

BOOST_OUTCOME_AUTO_TEST_CASE(issues / 0259 / test, "move assignable is not calculated correctly")
{
  struct DefaultConstructibleMoveAssignable
  {
    int a;
    DefaultConstructibleMoveAssignable() = default;
    DefaultConstructibleMoveAssignable(int) {}
    DefaultConstructibleMoveAssignable(const DefaultConstructibleMoveAssignable &) = delete;
    DefaultConstructibleMoveAssignable(DefaultConstructibleMoveAssignable &&) = delete;
    DefaultConstructibleMoveAssignable &operator=(const DefaultConstructibleMoveAssignable &) = delete;
    DefaultConstructibleMoveAssignable &operator=(DefaultConstructibleMoveAssignable &&) noexcept { return *this; }
    ~DefaultConstructibleMoveAssignable() = default;
  };
  struct DefaultConstructibleCopyAssignable
  {
    int a;
    DefaultConstructibleCopyAssignable() = default;
    DefaultConstructibleCopyAssignable(int) {}
    DefaultConstructibleCopyAssignable(const DefaultConstructibleCopyAssignable &) = delete;
    DefaultConstructibleCopyAssignable(DefaultConstructibleCopyAssignable &&) = delete;
    DefaultConstructibleCopyAssignable &operator=(const DefaultConstructibleCopyAssignable &) { return *this; }
    DefaultConstructibleCopyAssignable &operator=(DefaultConstructibleCopyAssignable &&) = delete;
    ~DefaultConstructibleCopyAssignable() = default;
  };
  struct NonDefaultConstructibleMoveAssignable
  {
    int a;
    NonDefaultConstructibleMoveAssignable() = delete;
    NonDefaultConstructibleMoveAssignable(int) {}
    NonDefaultConstructibleMoveAssignable(const NonDefaultConstructibleMoveAssignable &) = delete;
    NonDefaultConstructibleMoveAssignable(NonDefaultConstructibleMoveAssignable &&) = delete;
    NonDefaultConstructibleMoveAssignable &operator=(const NonDefaultConstructibleMoveAssignable &) = delete;
    NonDefaultConstructibleMoveAssignable &operator=(NonDefaultConstructibleMoveAssignable &&) noexcept { return *this; }
    ~NonDefaultConstructibleMoveAssignable() = default;
  };
  struct NonDefaultConstructibleCopyAssignable
  {
    int a;
    NonDefaultConstructibleCopyAssignable() = delete;
    NonDefaultConstructibleCopyAssignable(int) {}
    NonDefaultConstructibleCopyAssignable(const NonDefaultConstructibleCopyAssignable &) = delete;
    NonDefaultConstructibleCopyAssignable(NonDefaultConstructibleCopyAssignable &&) = delete;
    NonDefaultConstructibleCopyAssignable &operator=(const NonDefaultConstructibleCopyAssignable &) { return *this; }
    NonDefaultConstructibleCopyAssignable &operator=(NonDefaultConstructibleCopyAssignable &&) = delete;
    ~NonDefaultConstructibleCopyAssignable() = default;
  };

  {
    using type = OUTCOME_V2_NAMESPACE::result<DefaultConstructibleMoveAssignable>;
    type test1(OUTCOME_V2_NAMESPACE::success(5)), test1a(OUTCOME_V2_NAMESPACE::success(6));
    test1 = std::move(test1a);
    static_assert(!std::is_copy_constructible<type>::value, "");
    static_assert(!std::is_move_constructible<type>::value, "");
    static_assert(!std::is_copy_assignable<type>::value, "");
    static_assert(std::is_move_assignable<type>::value, "");
    static_assert(std::is_destructible<type>::value, "");
  }
  {
    using type = OUTCOME_V2_NAMESPACE::result<DefaultConstructibleCopyAssignable>;
    type test1(OUTCOME_V2_NAMESPACE::success(5)), test1a(OUTCOME_V2_NAMESPACE::success(6));
    test1 = std::move(test1a);
    static_assert(!std::is_copy_constructible<type>::value, "");
    static_assert(!std::is_move_constructible<type>::value, "");
    static_assert(std::is_copy_assignable<type>::value, "");
    static_assert(std::is_move_assignable<type>::value, "");
    static_assert(std::is_destructible<type>::value, "");
  }
  {
    using type = OUTCOME_V2_NAMESPACE::result<NonDefaultConstructibleMoveAssignable>;
    type test1(OUTCOME_V2_NAMESPACE::success(5)), test1a(OUTCOME_V2_NAMESPACE::success(6));
    static_assert(!std::is_copy_constructible<type>::value, "");
    static_assert(!std::is_move_constructible<type>::value, "");
    static_assert(!std::is_copy_assignable<type>::value, "");
    static_assert(!std::is_move_assignable<type>::value, "");
    static_assert(std::is_destructible<type>::value, "");
  }
  {
    using type = OUTCOME_V2_NAMESPACE::result<NonDefaultConstructibleCopyAssignable>;
    type test1(OUTCOME_V2_NAMESPACE::success(5)), test1a(OUTCOME_V2_NAMESPACE::success(6));
    static_assert(!std::is_copy_constructible<type>::value, "");
    static_assert(!std::is_move_constructible<type>::value, "");
    static_assert(!std::is_copy_assignable<type>::value, "");
    static_assert(!std::is_move_assignable<type>::value, "");
    static_assert(std::is_destructible<type>::value, "");
  }
  {
    using type = OUTCOME_V2_NAMESPACE::result<void, DefaultConstructibleMoveAssignable>;
    type test1(OUTCOME_V2_NAMESPACE::failure(5)), test1a(OUTCOME_V2_NAMESPACE::failure(6));
    test1 = std::move(test1a);
    static_assert(!std::is_copy_constructible<type>::value, "");
    static_assert(!std::is_move_constructible<type>::value, "");
    static_assert(!std::is_copy_assignable<type>::value, "");
    static_assert(std::is_move_assignable<type>::value, "");
    static_assert(std::is_destructible<type>::value, "");
  }
  {
    using type = OUTCOME_V2_NAMESPACE::result<void, DefaultConstructibleCopyAssignable>;
    type test1(OUTCOME_V2_NAMESPACE::failure(5)), test1a(OUTCOME_V2_NAMESPACE::failure(6));
    test1 = std::move(test1a);
    static_assert(!std::is_copy_constructible<type>::value, "");
    static_assert(!std::is_move_constructible<type>::value, "");
    static_assert(std::is_copy_assignable<type>::value, "");
    static_assert(std::is_move_assignable<type>::value, "");
    static_assert(std::is_destructible<type>::value, "");
  }
  {
    using type = OUTCOME_V2_NAMESPACE::result<DefaultConstructibleMoveAssignable, void>;
    type test1(OUTCOME_V2_NAMESPACE::success(5)), test1a(OUTCOME_V2_NAMESPACE::success(6));
    test1 = std::move(test1a);
    static_assert(!std::is_copy_constructible<type>::value, "");
    static_assert(!std::is_move_constructible<type>::value, "");
    static_assert(!std::is_copy_assignable<type>::value, "");
    static_assert(std::is_move_assignable<type>::value, "");
    static_assert(std::is_destructible<type>::value, "");
  }
  {
    using type = OUTCOME_V2_NAMESPACE::result<DefaultConstructibleCopyAssignable, void>;
    type test1(OUTCOME_V2_NAMESPACE::success(5)), test1a(OUTCOME_V2_NAMESPACE::success(6));
    test1 = std::move(test1a);
    static_assert(!std::is_copy_constructible<type>::value, "");
    static_assert(!std::is_move_constructible<type>::value, "");
    static_assert(std::is_copy_assignable<type>::value, "");
    static_assert(std::is_move_assignable<type>::value, "");
    static_assert(std::is_destructible<type>::value, "");
  }
  {
    using type = OUTCOME_V2_NAMESPACE::outcome<int, double, DefaultConstructibleMoveAssignable>;
    type test1(OUTCOME_V2_NAMESPACE::success(5)), test1a(OUTCOME_V2_NAMESPACE::success(6));
    test1 = std::move(test1a);
    static_assert(!std::is_copy_constructible<type>::value, "");
    static_assert(!std::is_move_constructible<type>::value, "");
    static_assert(!std::is_copy_assignable<type>::value, "");
    static_assert(std::is_move_assignable<type>::value, "");
    static_assert(std::is_destructible<type>::value, "");
  }
  {
    using type = OUTCOME_V2_NAMESPACE::outcome<int, double, DefaultConstructibleCopyAssignable>;
    type test1(OUTCOME_V2_NAMESPACE::success(5)), test1a(OUTCOME_V2_NAMESPACE::success(6));
    test1 = std::move(test1a);
    static_assert(!std::is_copy_constructible<type>::value, "");
    static_assert(!std::is_move_constructible<type>::value, "");
    static_assert(std::is_copy_assignable<type>::value, "");
    static_assert(std::is_move_assignable<type>::value, "");
    static_assert(std::is_destructible<type>::value, "");
  }
  {
    using type = OUTCOME_V2_NAMESPACE::outcome<void, void, DefaultConstructibleMoveAssignable>;
    type test1(OUTCOME_V2_NAMESPACE::success()), test1a(OUTCOME_V2_NAMESPACE::success());
    test1 = std::move(test1a);
    static_assert(!std::is_copy_constructible<type>::value, "");
    static_assert(!std::is_move_constructible<type>::value, "");
    static_assert(!std::is_copy_assignable<type>::value, "");
    static_assert(std::is_move_assignable<type>::value, "");
    static_assert(std::is_destructible<type>::value, "");
  }
  {
    using type = OUTCOME_V2_NAMESPACE::outcome<void, void, DefaultConstructibleCopyAssignable>;
    type test1(OUTCOME_V2_NAMESPACE::success()), test1a(OUTCOME_V2_NAMESPACE::success());
    test1 = std::move(test1a);
    static_assert(!std::is_copy_constructible<type>::value, "");
    static_assert(!std::is_move_constructible<type>::value, "");
    static_assert(std::is_copy_assignable<type>::value, "");
    static_assert(std::is_move_assignable<type>::value, "");
    static_assert(std::is_destructible<type>::value, "");
  }
}
