//! [expected_example]
#include "../include/boost/outcome.hpp"

#include <cfloat>
#include <cmath>
#include <iostream>

namespace outcome = BOOST_OUTCOME_V1_NAMESPACE;

// Replicates example usage of Result<T, E> from http://rustbyexample.com/std/result.html
namespace checked
{
  // Mathematical "errors" we want to catch
  enum class MathError {
    DivisionByZero,
    NegativeLogarithm,
    NegativeSquareRoot
  };
  
  using MathResult = outcome::expected<double, MathError>;
  static inline MathResult MathResultOk(double x) { return outcome::make_expected<double, MathError>(x); }
  static inline MathResult MathResultErr(MathError e) { return outcome::make_expected_from_error<double, MathError>(e); }
  
  MathResult div(double x, double y) noexcept
  {
    if(::fabs(y) < FLT_EPSILON)
    {
      // This operation would fail, instead let's return the reason of
      // the failure wrapped in E
      return MathResultErr(MathError::DivisionByZero);
    }
    else
    {
      // This operation is valid, return the result wrapped in T
      return MathResultOk(x / y);
    }
  }

  MathResult sqrt(double x) noexcept
  {
    if(x < 0.0)
      return MathResultErr(MathError::NegativeSquareRoot);
    return MathResultOk(::sqrt(x));
  }

  MathResult ln(double x) noexcept
  {
    if(x < 0.0)
      return MathResultErr(MathError::NegativeLogarithm);
    return MathResultOk(::log(x));
  }
}

double op(double x, double y)
{
  // Outcome provides a .match() extension, but this is 100% standard Expected
  // Also using outcome::result<T> instead of expected<T, E> would enable
  // intelligent printing of the error code to std::cerr
  checked::MathResult ratio = checked::div(x, y);
  if(!ratio)
  {
    std::cerr << "PANIC: MatchResult::DivisionByZero" << std::endl;
    std::terminate();
  }
  checked::MathResult ln = checked::ln(*ratio);
  if(!ln)
  {
    std::cerr << "PANIC: MatchResult::NegativeLogarithm" << std::endl;
    std::terminate();
  }
  checked::MathResult sqrt = checked::sqrt(*ln);
  if(!sqrt)
  {
    std::cerr << "PANIC: MatchResult::NegativeSquareRoot" << std::endl;
    std::terminate();
  }
  return sqrt.value();
}

int main(void)
{
  // Will this fail?
  std::cout << op(1.0, 10.0) << std::endl;
  return 0;
}
//! [expected_example]
