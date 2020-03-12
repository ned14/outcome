/* Unit testing for outcomes
(C) 2013-2020 Niall Douglas <http://www.nedproductions.biz/> (1 commit)


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

#include "../../include/outcome/experimental/status_result.hpp"
#include "../../include/outcome/try.hpp"
#include "quickcpplib/boost/test/unit_test.hpp"

#ifndef SYSTEM_ERROR2_NOT_POSIX
namespace issues220
{
  namespace outcome_e = OUTCOME_V2_NAMESPACE::experimental;

  template <class T, class E = outcome_e::error> using Result = outcome_e::status_result<T, E>;

  template <class T> using PosixResult = outcome_e::status_result<T, outcome_e::posix_code>;

  Result<int> convert(const PosixResult<int> &posix_result) { return Result<int>(posix_result); }
}  // namespace issues220
#endif


BOOST_OUTCOME_AUTO_TEST_CASE(issues / 0220 / test, "ubsan reports reference binding to null pointer")
{
#ifndef SYSTEM_ERROR2_NOT_POSIX
  using namespace issues220;
  BOOST_CHECK(convert(PosixResult<int>(0)).value() == 0);
#endif
}
