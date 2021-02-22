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

BOOST_OUTCOME_AUTO_TEST_CASE(issues / 0016 / test, "Default constructor of T is sometimes compiled when T has no default constructor")
{
  using namespace OUTCOME_V2_NAMESPACE;
  struct udt
  {
    const char *_v{nullptr};
    udt() = delete;
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
    ~udt() = default;
    constexpr const char *operator*() const noexcept { return _v; }
  };
  result<udt> n(std::error_code(ENOMEM, std::generic_category()));
  (void) n;
}
