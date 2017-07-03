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

BOOST_AUTO_TEST_CASE(issues / 12, "basic_monad's copy assignment gets instantiated even when type T cannot be copied")
{
  using namespace BOOST_OUTCOME_V1_NAMESPACE::experimental;
  const char *s = "hi";
  struct udt  // NOLINT
  {
    const char *_v{nullptr};
    udt() = default;
    constexpr explicit udt(const char *v) noexcept : _v(v) {}
    QUICKCPPLIB_CONSTEXPR udt(udt &&o) noexcept : _v(o._v) { o._v = nullptr; }
    udt(const udt &) = delete;
    QUICKCPPLIB_CONSTEXPR udt &operator=(udt &&o) noexcept
    {
      _v = o._v;
      o._v = nullptr;
      return *this;
    }
    udt &operator=(const udt &) = delete;
    constexpr const char *operator*() const noexcept { return _v; }
  };
  static_assert(expected<udt>::is_move_constructible, "expected<udt> is not move constructible!");
  static_assert(!expected<udt>::is_copy_constructible, "expected<udt> is copy constructible!");
  expected<udt> p(udt{s}), n(make_unexpected(std::error_code(ENOMEM, std::generic_category())));
  n = make_unexpected(std::error_code(EINVAL, std::generic_category()));
}
