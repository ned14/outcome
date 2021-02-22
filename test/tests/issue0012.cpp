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

BOOST_OUTCOME_AUTO_TEST_CASE(issues / 0012 / test, "outcome's copy assignment gets instantiated even when type T cannot be copied")
{
  using namespace OUTCOME_V2_NAMESPACE;
  const char *s = "hi";
  struct udt  // NOLINT
  {
    const char *_v{nullptr};
    udt() = default;
    constexpr explicit udt(const char *v) noexcept : _v(v) {}
    constexpr udt(udt &&o) noexcept : _v(o._v) { o._v = nullptr; }
    udt(const udt &) = delete;
    constexpr udt &operator=(udt &&o) noexcept
    {
      _v = o._v;
      o._v = nullptr;
      return *this;
    }
    udt &operator=(const udt &) = delete;
    constexpr const char *operator*() const noexcept { return _v; }
  };
  static_assert(std::is_move_constructible<outcome<udt>>::value, "expected<udt> is not move constructible!");
  static_assert(!std::is_copy_constructible<outcome<udt>>::value, "expected<udt> is copy constructible!");
  outcome<udt> p(udt{s}), n(std::error_code(ENOMEM, std::generic_category()));
  n = std::error_code(EINVAL, std::generic_category());
  BOOST_CHECK(n.error().value() == EINVAL);
}
