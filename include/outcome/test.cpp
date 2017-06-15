#include "result.hpp"

int main(void)
{
  outcome::error_code_extended ec(std::make_error_code(std::errc::invalid_argument));
  outcome::result<int> a(5);
  outcome::result<int> b(std::make_error_code(std::errc::invalid_argument));
  b.assume_value();
  a.assume_error();
  b.value();
  return 0;
}
