/* Unit testing for outcomes
(C) 2013-2019 Niall Douglas <http://www.nedproductions.biz/> (1 commit)


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

BOOST_OUTCOME_AUTO_TEST_CASE(issues / 0115 / outcome, "Initialization from `failure_type` drops default-constructed values")
{
  namespace out = OUTCOME_V2_NAMESPACE;

  out::outcome<int> o1 = std::error_code{};
  BOOST_CHECK(o1.has_error());
  BOOST_CHECK(!o1.has_exception());

  out::outcome<int> o2 = out::failure(std::error_code{});
  BOOST_CHECK(o2.has_error());
  BOOST_CHECK(!o2.has_exception());

  out::outcome<int> o3(std::error_code{}, std::exception_ptr{});
  BOOST_CHECK(o3.has_error());
  BOOST_CHECK(o3.has_exception());

  out::outcome<int> o4 = out::failure(std::error_code{}, std::exception_ptr{});
  BOOST_CHECK(o4.has_error());
  BOOST_CHECK(o4.has_exception());

  out::outcome<int> o5 = out::failure(std::exception_ptr{});
  BOOST_CHECK(!o5.has_error());
  BOOST_CHECK(o5.has_exception());
}
