/* Example of Outcome
(C) 2017 Niall Douglas <http://www.nedproductions.biz/> (149 commits)


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

#include "../../../include/outcome.hpp"
#include <string>
using std::string;
namespace outcome = OUTCOME_V2_NAMESPACE;

struct string_view
{
  string_view(const char*) {}
  operator string() { return {}; }
};

struct LibError : std::runtime_error
{
  explicit LibError(std::error_code, string_view s) : std::runtime_error(s) {}
};

void use_string(string) {}

//! [signature]
auto read_data_from_file(string_view path) noexcept
  -> outcome::result<string>;
//! [signature]

int main() {
//! [inspect]
if (auto rslt = read_data_from_file("config.cfg"))
  use_string(rslt.value());                   // returns string
else
  throw LibError{rslt.error(), "config.cfg"}; // returns error_code
//! [inspect]
}

//! [implementation]
auto process(const string& content) noexcept
  -> outcome::result<int>;

auto get_int_from_file(string_view path) noexcept
  -> outcome::result<int>
{
  OUTCOME_TRY(str, read_data_from_file(path));
  // if control gets here read_data_from_file() has succeeded
  return process(str);  // decltype(str) == string
}
//! [implementation]

auto process(const string&) noexcept
  -> outcome::result<int>
{
  return outcome::success(1);
}

auto read_data_from_file(string_view) noexcept
  -> outcome::result<string>
{
  return outcome::success("1");
}
