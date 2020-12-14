/* Example of Outcome
(C) 2017-2019 Niall Douglas <http://www.nedproductions.biz/> (4 commits), Andrzej Krzemienski <akrzemi1@gmail.com> (3 commits), akrzemi1 <akrzemi1@gmail.com> (1 commit) and Andrzej Krzemieński <akrzemi1@gmail.com> (1 commit)


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
outcome::result<string> data_from_file(string_view path) noexcept;
//! [signature]

int main() {
//! [inspect]
if (outcome::result<string> rslt = data_from_file("config.cfg"))
  use_string(rslt.value());                   // returns string
else
  throw LibError{rslt.error(), "config.cfg"}; // returns error_code
//! [inspect]
}

//! [implementation]
outcome::result<int> process(const string& content) noexcept;

outcome::result<int> int_from_file(string_view path) noexcept
{
  OUTCOME_TRY(auto str, data_from_file(path));
  // if control gets here data_from_file() has succeeded
  return process(str);  // decltype(str) == string
}
//! [implementation]

outcome::result<int> process(const string&) noexcept
{
  return outcome::success(1);
}

outcome::result<string> data_from_file(string_view) noexcept
{
  return outcome::success("1");
}
