/* Example of Outcome
(C) 2017-2019 Niall Douglas <http://www.nedproductions.biz/> (3 commits), Krzemienski <sg0897542@global.ad.sabre.com> (3 commits) and Andrzej Krzemienski <akrzemi1@gmail.com> (3 commits)


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
#include <iostream>

namespace outcome = OUTCOME_V2_NAMESPACE;

//! [decl_f_g]
auto f() -> int;  // throws on failure
auto g() noexcept -> outcome::result<int>;
//! [decl_f_g]

auto f() -> int
{
  throw std::runtime_error{"failure"};
}

auto g() noexcept -> outcome::result<int>
{
  return 1;
}

namespace old
{
    auto h() noexcept -> outcome::outcome<int>;
}

//! [def_h]
auto old::h() noexcept -> outcome::outcome<int>
{
  OUTCOME_TRY(auto i, (g()));             // #1
    
  try {
    return i + f();
  }
  catch (...) {
    return std::current_exception(); // #2
  }
}
//! [def_h]

//! [def_z]
auto z() -> int // throws on failure
{
  if (outcome::outcome<int> o = old::h())
    return o.value();
  else if (o.has_exception())
    std::rethrow_exception(o.exception());
  else
    throw std::system_error{o.error()};
}
//! [def_z]

int main()
try {
  return z();
}
catch(std::runtime_error const& e) {
  std::cerr << e.what() << std::endl;
  return 1;
}