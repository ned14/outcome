/* Unit testing for outcomes
(C) 2013-2019 Niall Douglas <http://www.nedproductions.biz/> (2 commits)


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

BOOST_OUTCOME_AUTO_TEST_CASE(issues / 0140 / result, "Construction of non copy constructible value_type fails to not compile")
{
  namespace out = OUTCOME_V2_NAMESPACE;

  enum op
  {
    constructed,
    moved,
    copied
  };
  struct NotCopyMoveConstructible
  {
    op v{op::constructed};
    NotCopyMoveConstructible() = default;
    NotCopyMoveConstructible(const NotCopyMoveConstructible &o) = delete;
    NotCopyMoveConstructible(NotCopyMoveConstructible &&) = delete;
    NotCopyMoveConstructible &operator=(const NotCopyMoveConstructible &) = delete;
    NotCopyMoveConstructible &operator=(NotCopyMoveConstructible &&) = delete;
    ~NotCopyMoveConstructible() = default;
  };
  struct NotMoveConstructible
  {
    op v{op::constructed};
    NotMoveConstructible() = default;
    NotMoveConstructible(const NotMoveConstructible & /*unused*/)
        : v(op::copied)
    {
    }
    NotMoveConstructible(NotMoveConstructible &&) = delete;
    NotMoveConstructible &operator=(const NotMoveConstructible &) = delete;
    NotMoveConstructible &operator=(NotMoveConstructible &&) = delete;
    ~NotMoveConstructible() = default;
  };
  struct NotCopyConstructible
  {
    op v{op::constructed};
    NotCopyConstructible() = default;
    NotCopyConstructible(NotCopyConstructible && /*unused*/) noexcept : v(op::moved) {}
    NotCopyConstructible(const NotCopyConstructible & /*unused*/) = delete;
    NotCopyConstructible &operator=(const NotCopyConstructible &) = delete;
    NotCopyConstructible &operator=(NotCopyConstructible &&) = delete;
    ~NotCopyConstructible() = default;
  };

  // Uncopyable and immovable items should be neither copyable nor moveable
  static_assert(!std::is_copy_constructible<out::result<NotCopyMoveConstructible>>::value, "result<NotCopyMoveConstructible> is copy constructible!");
  static_assert(!std::is_move_constructible<out::result<NotCopyMoveConstructible>>::value, "result<NotCopyMoveConstructible> is move constructible!");
  static_assert(!std::is_convertible<const NotCopyMoveConstructible &, NotCopyMoveConstructible>::value, "");
  static_assert(!std::is_convertible<NotCopyMoveConstructible &&, NotCopyMoveConstructible>::value, "");
  static_assert(!std::is_constructible<out::result<NotCopyMoveConstructible>, const NotCopyMoveConstructible &>::value, "result<NotCopyMoveConstructible> is constructible from const NotCopyMoveConstructible&!");
  static_assert(!std::is_constructible<out::result<NotCopyMoveConstructible>, NotCopyMoveConstructible &&>::value, "result<NotCopyMoveConstructible> is constructible from NotCopyMoveConstructible&&!");

  // Immovable items should fall back to copy
  static_assert(!std::is_move_constructible<NotMoveConstructible>::value, "NotMoveConstructible is move constructible!");
  static_assert(std::is_move_constructible<out::result<NotMoveConstructible>>::value, "result<NotMoveConstructible> is not move constructible!");
  static_assert(std::is_constructible<out::result<NotMoveConstructible>, const NotMoveConstructible &>::value, "result<NotMoveConstructible> is not constructible from NotMoveConstructible&&!");

  // Uncopyable items should never move (this was the bug report)
  static_assert(!std::is_copy_constructible<out::result<NotCopyConstructible>>::value, "result<NotCopyConstructible> is copy constructible!");
  static_assert(!std::is_constructible<out::result<NotCopyConstructible>, const NotCopyConstructible &>::value, "result<NotCopyConstructible> is constructible from const NotCopyConstructible&!");

  BOOST_CHECK(true);
}
