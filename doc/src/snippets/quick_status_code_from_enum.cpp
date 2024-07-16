/* Example use of std::error implicit conversion
(C) 2024 Niall Douglas <http://www.nedproductions.biz/> (5 commits)
File Created: Sept 2018


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

#include "../../../include/outcome/experimental/status-code/include/status-code/quick_status_code_from_enum.hpp"
#include "../../../include/outcome/experimental/status_result.hpp"
#include "outcome/experimental/status-code/include/status-code/config.hpp"


//! [preamble]
// My custom enum type
enum class custom_failure
{
  not_found,
  bad_argument
};

// Tell `status_code` to stamp out a custom code domain for this enum type
SYSTEM_ERROR2_NAMESPACE_BEGIN
template <> struct quick_status_code_from_enum<custom_failure> : quick_status_code_from_enum_defaults<custom_failure>
{
  // Text name of the enum
  static constexpr const auto domain_name = "My custom failure";
  // Unique UUID for the enum. PLEASE use https://www.random.org/cgi-bin/randbyte?nbytes=16&format=h
  static constexpr const auto domain_uuid = "{be201f65-3962-dd0e-1266-a72e63776a42}";
  // Map of each enum value to its text string, and list of semantically equivalent errc's
  static const std::initializer_list<mapping> &value_mappings()
  {
    static const std::initializer_list<mapping> v = {
    // Format is: { enum value, "string representation", { list of errc mappings ... } }
    {custom_failure::not_found, "item not found", {errc::no_such_file_or_directory}},  //
    {custom_failure::bad_argument, "invoked wrong", {errc::invalid_argument}},         //
    };
    return v;
  }
  // Completely optional definition of mixin for the status code synthesised from `Enum`. It can be omitted.
  template <class Base> struct mixin : Base
  {
    using Base::Base;
    constexpr int custom_method() const { return 42; }
  };
};
SYSTEM_ERROR2_NAMESPACE_END
//! [preamble]

//! [implicit_construction]
// This is the status code generated for your custom enum type. It will implicitly construct from
// values of enum custom_failure.
using custom_failure_code = SYSTEM_ERROR2_NAMESPACE::quick_status_code_from_enum_code<custom_failure>;

namespace outcome_e = OUTCOME_V2_NAMESPACE::experimental;

// You don't usually need to use the status code type explicitly, because this "just works":
outcome_e::status_result<int> positive_only(int x)
{
  if(x < 0)
  {
    // Outcome's result sees that status_code will implicitly construct from this enum,
    // and it returns an errored result
    return custom_failure::bad_argument;
  }
  return x;
}

// Semantic comparisons work
bool test(int x)
{
  if(auto r = positive_only(x); !r)
  {
    if(r.error() == outcome_e::errc::invalid_argument)
    {
      std::cerr << "Positive numbers only!" << std::endl;
      return false;
    }
  }
  return true;
}
//! [implicit_construction]

int main(void)
{
  if(!test(0))
    abort();
  if(test(-1))
    abort();
  return 0;
}
