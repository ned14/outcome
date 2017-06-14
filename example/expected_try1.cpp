//! [expected_try1]
#include "../include/boost/outcome.hpp"

#include <cfloat>
#include <cmath>
#include <iostream>

namespace outcome = BOOST_OUTCOME_V1_NAMESPACE;

// Custom error code domain 1
enum class MathError1 {
  DivisionByZero,
  NegativeLogarithm,
  NegativeSquareRoot
};
// Custom error code domain 2
enum class MathError2 {
  NegativeSquareRoot,
  NegativeLogarithm,
  DivisionByZero
};

using MathResult1 = outcome::experimental::expected<double, MathError1>;
using MathResult2 = outcome::experimental::expected<long long, MathError2>;

MathResult1 div(double x, double y) noexcept
{
  if (::fabs(y) < DBL_EPSILON)
  {
    // This operation would fail, instead let's return the reason of
    // the failure wrapped in E
    return outcome::experimental::make_unexpected(MathError1::DivisionByZero);
  }
  else
  {
    // This operation is valid, return the result wrapped in T
    return x / y;
  }
}

MathResult2 div10mul3(double y) noexcept
{
  MathResult1 result = div(10.0, y);
  // If successful, return the result
  if (result)
  {
    if(result.value() < 0)
      return outcome::experimental::make_unexpected(MathError2::NegativeSquareRoot);
    return (long long)(result.value() * 3.0);
  }
  // NOTE: If it failed, convert the MathError1 error code domain into
  //       the MathError2 error code domain
  switch (result.error())
  {
    case MathError1::DivisionByZero:
      return MathError2::DivisionByZero;
    case MathError1::NegativeLogarithm:
      return MathError2::NegativeLogarithm;
    case MathError1::NegativeSquareRoot:
      return MathError2::NegativeSquareRoot;
  }
}

int main(void)
{
  try
  {
    std::cout << div10mul3(1.0).value() << std::endl;
  }
  // NOTE: the C++ exception type thrown by Expected embeds a copy
  //       of type E and therefore its template signature must
  //       be the correct type E. If we accidentally used MathError1
  //       here the exception would not be caught!
  catch (const outcome::experimental::bad_expected_access<MathError2> &e)
  {
    std::cout << "div10mul3().value() threw an exception" << std::endl;
  }
  return 0;
}
//! [expected_try1]
