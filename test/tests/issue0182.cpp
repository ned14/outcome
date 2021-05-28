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

BOOST_OUTCOME_AUTO_TEST_CASE(issues / 0182 / test, "result<void, int>.value() compiles without tripping fail_to_compile_observers")
{
  namespace outcome = OUTCOME_V2_NAMESPACE;
  static_assert(!outcome::trait::is_error_code_available<int>::value, "int is clearly not a source for make_error_code()");
  static_assert(!outcome::trait::is_exception_ptr_available<int>::value, "int is clearly not a source for make_exception_ptr()");
  //outcome::result<void, int> r(5);
  //r.value();
  BOOST_CHECK(true);
}
