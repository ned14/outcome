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

BOOST_AUTO_TEST_CASE(works / monad / serialisation, "Tests that the monad serialises and deserialises as intended")
{
  using namespace BOOST_OUTCOME_V1_NAMESPACE;
  outcome<std::string> a("niall"), b(error_code_extended(5, stl11::generic_category())), c(std::make_exception_ptr(std::ios_base::failure("A test failure message")));
  std::cout << "a contains " << a << " and b contains " << b << " and c contains " << c << std::endl;
  std::string buffer("hello");
  std::stringstream ss(buffer);
  ss >> a;
  BOOST_CHECK(a.get() == "hello");
}

