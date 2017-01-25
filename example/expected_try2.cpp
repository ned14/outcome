//! [expected_try2]
#include "../include/boost/outcome.hpp"

#include <cfloat>
#include <cmath>
#include <iostream>

namespace outcome = BOOST_OUTCOME_V1_NAMESPACE;

// Restrict expected<T, E>
template<class T> using result = outcome::expected<T, std::error_code>;
// Restrict bad_expected_access too
using bad_result_access = outcome::bad_expected_access<std::error_code>;

result<double> div(double x, double y) noexcept
{
  if (::fabs(y) < FLT_EPSILON)
  {
    // This operation would fail, instead let's return the reason of
    // the failure wrapped in E
    return outcome::make_unexpected(std::make_error_code(std::errc::result_out_of_range));
  }
  else
  {
    // This operation is valid, return the result wrapped in T
    return x / y;
  }
}

result<long long> div10mul3(double y) noexcept
{
  // If calling div() fails, return the same error immediately,
  // else unpack the T into result
  BOOST_OUTCOME_TRY(result, div(10.0, y));
  return (long long)(result * 3.0);
}

int main(void)
{
  try
  {
    std::cout << div10mul3(1.0).value() << std::endl;
  }
  // NOTE: We restricted bad_expected_access above so this is much
  //       less likely to become accidentally wrong as code evolves
  catch (const bad_result_access &e)
  {
    // Also note we can always print the error code because E is
    // always an error_code
    std::cout << "div10mul3().value() failed due to " << e.error() << std::endl;
  }
  return 0;
}
//! [expected_try2]
