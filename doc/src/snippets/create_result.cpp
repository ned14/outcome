#include "../include/outcome/outcome.hpp"
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
  EmptyString = 1; // 0 is never an error
  IllegalChar = 2;
  TooLong     = 3;
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
      const char* name() const noexcept override { return "bad-convet"; }
      std::string message(int ev) const override;
    };
    
    std::string ConversionErrorCategory::message(int ev) const
    {
        switch (static_cast<ConversionErrc>(ev))
        {
            case ConversionErrc::EmptyInput:
                return "empty string provided";
            case ConversionErrc::InvalidChar:
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

int main()
{
//! [explicit]	
outcome::result<int> r {outcome::in_place_type<std::error_code>, ConversionErrc::EmptyString};
outcome::result<int> s {outcome::in_place_type<int>, 1};
//! [explicit]
}