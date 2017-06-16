#ifndef OUTCOME_ERROR_CODE_EXTENDED_HPP
#define OUTCOME_ERROR_CODE_EXTENDED_HPP

#include <system_error>

namespace outcome
{
  class error_code_extended : public std::error_code
  {
    size_t _idx;

  public:
    using std::error_code::error_code;
    error_code_extended() = default;
    error_code_extended(std::error_code ec)
        : std::error_code(ec)
    {
    }
  };
}
#endif
