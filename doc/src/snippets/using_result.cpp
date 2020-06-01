/* Documentation snippet
(C) 2017-2019 Niall Douglas <http://www.nedproductions.biz/> (7 commits), Andrzej Krzemienski <akrzemi1@gmail.com> (4 commits) and Krzemienski <sg0897542@global.ad.sabre.com> (2 commits)
File Created: Mar 2017


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
#include <algorithm>
#include <ctype.h>
#include <string>
#include <system_error>

//! [namespace]
namespace outcome = OUTCOME_V2_NAMESPACE;
//! [namespace]

//! [convert_decl]
outcome::result<int> convert(const std::string& str) noexcept;
//! [convert_decl]

//! [enum]
enum class ConversionErrc
{
  Success     = 0, // 0 should not represent an error
  EmptyString = 1, // (for rationale, see tutorial on error codes)
  IllegalChar = 2,
  TooLong     = 3,
};

// all boilerplate necessary to plug ConversionErrc
// into std::error_code framework
//! [enum]

std::error_code make_error_code(ConversionErrc);

namespace std {
    template <> struct is_error_code_enum<ConversionErrc> : true_type {};
}

//! [convert]
outcome::result<int> convert(const std::string& str) noexcept
{
  if (str.empty())
    return ConversionErrc::EmptyString;

  if (!std::all_of(str.begin(), str.end(), ::isdigit))
    return ConversionErrc::IllegalChar;

  if (str.length() > 9)
    return ConversionErrc::TooLong;

  return atoi(str.c_str());
}
//! [convert]

namespace
{
  struct ConversionErrorCategory : std::error_category
  {
    const char* name() const noexcept override { return "bad-convert"; }
    std::string message(int ev) const override;
  };

  std::string ConversionErrorCategory::message(int ev) const
  {
    switch (static_cast<ConversionErrc>(ev))
    {
    case ConversionErrc::Success:
      return "conversion successful";
    case ConversionErrc::EmptyString:
      return "empty string provided";
    case ConversionErrc::IllegalChar:
      return "non-digit char provided";
    case ConversionErrc::TooLong:
      return "converted int would be too large";
    }
      return "(UNCHARTED)";
  }

  const ConversionErrorCategory globalConversionErrorCategory {};
}

std::error_code make_error_code(ConversionErrc e)
{
  return std::error_code{static_cast<int>(e), globalConversionErrorCategory};
}

void explicit_construction()
{
//! [explicit]
outcome::result<int> r {outcome::in_place_type<std::error_code>, ConversionErrc::EmptyString};
outcome::result<int> s {outcome::in_place_type<int>, 1};
//! [explicit]
}

void factory_construction()
{
//! [factory]
outcome::result<int> r = outcome::failure(ConversionErrc::EmptyString);
outcome::result<int> s = outcome::success(1);
//! [factory]
}

struct BigInt
{
  static outcome::result<BigInt> fromString(const std::string& s);
  explicit BigInt(const std::string&) {}
  BigInt half() const { return BigInt{""}; }
  friend std::ostream& operator<<(std::ostream& o, const BigInt&) { return o << "big int half"; }
};

//! [from_string]
/*static*/ outcome::result<BigInt> BigInt::fromString(const std::string& s)
//! [from_string]
{
    return BigInt{s};
}

//! [half_decl]
outcome::result<void> print_half(const std::string& text);
//! [half_decl]

//! [half_impl]
outcome::result<void> print_half(const std::string& text)
{
  if (outcome::result<int> r = convert(text))         // #1
  {
    std::cout << (r.value() / 2) << std::endl;        // #2
  }
  else
  {
    if (r.error() == ConversionErrc::TooLong)         // #3
    {
      OUTCOME_TRY(auto i, BigInt::fromString(text));  // #4
      std::cout << i.half() << std::endl;
    }
    else
    {
      return r.as_failure();                          // #5
    }
  }
  return outcome::success();                          // #6
}
//! [half_impl]

//! [tryv]
outcome::result<void> test()
{
  OUTCOME_TRY ((print_half("2")));
  OUTCOME_TRY ((print_half("X")));
  OUTCOME_TRY ((print_half("4"))); // will not execute
  return outcome::success();
}
//! [tryv]

int main()
{
  if (outcome::result<void> r = print_half("1299999999999999999999999999"))
  {
    std::cout << "ok" << std::endl;
  }
  else
  {
    std::cout << r.error() << std::endl;
  }

  (void)test();
}
