/* Unit testing for outcomes
(C) 2013-2023 Niall Douglas <http://www.nedproductions.biz/> (1 commit)


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

#pragma clang diagnostic ignored "-Wunneeded-internal-declaration"

namespace
{
  namespace outcome = OUTCOME_V2_NAMESPACE;

  struct MovableError
  {
    MovableError() = default;
    MovableError(MovableError &&) = default;
    MovableError &operator=(MovableError &&) = default;
  };

  std::error_code make_error_code(MovableError const &)
  {
    return {};
  }
  void outcome_throw_as_system_error_with_payload(MovableError) {}

  template <typename T> using MyResult = outcome::result<T, MovableError>;
}  // namespace

BOOST_OUTCOME_AUTO_TEST_CASE(issues / 0291 / test, "move of a non-const available void Result fails to compile")
{
  MyResult<int> f(outcome::success());
  MyResult<void> g(outcome::success());
  std::move(f).value();
  std::move(g).value();
}
