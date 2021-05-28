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

#include "../../include/outcome/std_result.hpp"
#include "../../include/outcome/try.hpp"
#include "quickcpplib/boost/test/unit_test.hpp"

namespace outcome = OUTCOME_V2_NAMESPACE;

namespace stdalias = std;

enum class error
{
  test,
  abcde
};

class error_category_impl : public std::error_category
{
public:
  const char *name() const noexcept override { return "test"; }

  std::string message(int code) const noexcept override
  {
    switch(static_cast<error>(code))
    {
    case error::test:
      return "test";
    case error::abcde:
      return "abcde";
    }
    return "unknown";
  }
};
const std::error_category &error_category() noexcept
{
  static error_category_impl instance;
  return instance;
}

stdalias::error_code make_error_code(error error) noexcept
{
  return {static_cast<int>(error), error_category()};
}

namespace std
{
  template <> struct is_error_code_enum<error> : true_type
  {
  };
}  // namespace std

template <typename T> using enum_result = outcome::basic_result<T, error, outcome::policy::default_policy<T, error, void>>;

enum_result<int> test()
{
  return 5;
}

outcome::std_result<int> abc()
{
  static_assert(std::is_error_code_enum<error>::value, "custom enum is not marked convertible to error code");
  static_assert(std::is_constructible<stdalias::error_code, error>::value, "error code is not explicitly constructible from custom enum");
  static_assert(std::is_convertible<error, stdalias::error_code>::value, "error code is not implicitly constructible from custom enum");
  stdalias::error_code ec = error::test;  // custom enum is definitely convertible to error code
  OUTCOME_TRY(test());                    // hence this should compile, as implicit conversions work here
  (void) ec;

  // But explicit conversions are required between dissimilar basic_result, implicit conversions are disabled
  static_assert(std::is_constructible<outcome::std_result<int>, enum_result<int>>::value, "basic_result with error code is not explicitly constructible from basic_result with custom enum");
  static_assert(!std::is_convertible<enum_result<int>, outcome::std_result<int>>::value, "basic_result with error code is implicitly constructible from basic_result with custom enum");
  return 5;
}

BOOST_OUTCOME_AUTO_TEST_CASE(issues / 0203 / test, "enum convertible to error code works as designed")
{
  BOOST_CHECK(abc().value() == 5);
}
