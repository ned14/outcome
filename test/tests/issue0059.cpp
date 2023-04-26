/* Unit testing for outcomes
(C) 2013-2019 Niall Douglas <http://www.nedproductions.biz/> (8 commits)


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

BOOST_OUTCOME_AUTO_TEST_CASE(issues / 0059 / test, "result<NonMovable> supported?")
{
#if (defined(_MSC_VER) && !defined(__clang__)) || __cplusplus >= 201700
  using namespace OUTCOME_V2_NAMESPACE;
  struct udt
  {
    const char *_v{nullptr};
    udt() = delete;
    constexpr udt(const char *v) noexcept : _v(v) {}  // NOLINT
    udt(udt &&o) = delete;
    udt(const udt &) = delete;
    udt &operator=(udt &&o) = delete;
    udt &operator=(const udt &) = delete;
    ~udt() = default;
    constexpr const char *operator*() const noexcept { return _v; }
  };
  const char *niall = "niall";
  auto f = [niall]() -> result<void> {
    auto g = [niall]() -> result<udt> { return {niall}; };
    OUTCOME_TRY((auto &&, v), g());  // this must never copy nor move
    BOOST_CHECK(*v == niall);
    return success();
  };
  (void) f();
#endif
}
