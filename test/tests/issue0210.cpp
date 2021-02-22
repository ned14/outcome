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
#include "../../include/outcome/try.hpp"
#include "quickcpplib/boost/test/unit_test.hpp"

namespace issues210
{
  namespace outcome = OUTCOME_V2_NAMESPACE;

  struct error
  {
    std::error_code code;
  };

  // say that my custom error code type is error code compatible
  inline std::error_code make_error_code(error error) noexcept { return error.code; }

  template <typename T> using custom_result = outcome::basic_result<T, error, outcome::policy::default_policy<T, error, void>>;

  // source of custom result type with error code compatible error type
  inline custom_result<int> funcA(int x) { return x; }

  // Is the custom result type explicitly constructible to an ordinary result type?
  inline outcome::result<int> funcB(int x) { return outcome::result<int>(funcA(x)); }

  // Does the custom result type TRY-convert to an ordinary result type?
  inline outcome::result<int> func1(int x)
  {
    OUTCOME_TRY(auto &&y, funcA(x));
    return funcB(y);
  }

  // Is the custom result type explicitly constructible to an ordinary outcome type?
  inline outcome::outcome<int> funcC(int x) { return outcome::outcome<int>(funcA(x)); }

  // Does the custom result type TRY-convert to an ordinary outcome type?
  inline outcome::outcome<int> func2(int x)
  {
    OUTCOME_TRY(auto &&y, funcA(x));
    return funcC(y);
  }
}  // namespace issues210


BOOST_OUTCOME_AUTO_TEST_CASE(issues / 0210 / test, "result<int, E> with error code compatible custom E does not TRY into a result<int, std::error_code> function")
{
  BOOST_CHECK(issues210::func1(5).value() == 5);
  BOOST_CHECK(issues210::func2(5).value() == 5);
}
