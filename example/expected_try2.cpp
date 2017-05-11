//! [expected_try2]
#include "../include/boost/outcome.hpp"

#include <cfloat>
#include <cmath>
#include <iostream>

namespace outcome = BOOST_OUTCOME_V1_NAMESPACE;

class MathError1 : public std::error_code {
public:
  enum valid_errors {
    DivisionByZero,
    NegativeLogarithm,
    NegativeSquareRoot
  };
  MathError1() = default;
  // Only allow my construction from my enum
  inline MathError1(valid_errors c);
};

class MathError2 : public std::error_code {
public:
  enum valid_errors {
    NegativeSquareRoot,
    NegativeLogarithm,
    DivisionByZero
  };
  MathError2() = default;
  // Only allow my construction from my enum
  inline MathError2(valid_errors c);
};

namespace detail
{
  class MathError1_category : public std::error_category
  {
  public:
    virtual const char *name() const noexcept override final { return "MathError1"; }
    virtual std::string message(int c) const override final
    {
      switch (c)
      {
      case MathError1::DivisionByZero:
        return "division by zero";
      case MathError1::NegativeLogarithm:
        return "logarithm of negative number";
      case MathError1::NegativeSquareRoot:
        return "square root of negative number";
      default:
        return "unknown";
      }
    }
    virtual std::error_condition default_error_condition(int c) const noexcept override final
    {
      switch (c)
      {
      case MathError1::DivisionByZero:
        return make_error_condition(std::errc::result_out_of_range);
      case MathError1::NegativeLogarithm:
        return make_error_condition(std::errc::argument_out_of_domain);
      case MathError1::NegativeSquareRoot:
        return make_error_condition(std::errc::argument_out_of_domain);
      default:
        // I have no mapping for this code
        return std::error_condition(c, *this);
      }
    }
  };
  class MathError2_category : public std::error_category
  {
  public:
    virtual const char *name() const noexcept override final { return "MathError2"; }
    virtual std::string message(int c) const override final
    {
      switch (c)
      {
      case MathError2::NegativeSquareRoot:
        return "square root of negative number";
      case MathError2::NegativeLogarithm:
        return "logarithm of negative number";
      case MathError2::DivisionByZero:
        return "division by zero";
      default:
        return "unknown";
      }
    }
    virtual std::error_condition default_error_condition(int c) const noexcept override final
    {
      switch (c)
      {
      case MathError2::NegativeSquareRoot:
        return make_error_condition(std::errc::argument_out_of_domain);
      case MathError2::NegativeLogarithm:
        return make_error_condition(std::errc::argument_out_of_domain);
      case MathError2::DivisionByZero:
        return make_error_condition(std::errc::result_out_of_range);
      default:
        // I have no mapping for this code
        return std::error_condition(c, *this);
      }
    }
  };
}

extern const detail::MathError1_category &MathError1_category()
{
  static detail::MathError1_category c;
  return c;
}

extern const detail::MathError2_category &MathError2_category()
{
  static detail::MathError2_category c;
  return c;
}

inline MathError1::MathError1(MathError1::valid_errors e) : std::error_code(e, MathError1_category()) {}
inline MathError2::MathError2(MathError2::valid_errors e) : std::error_code(e, MathError2_category()) {}

inline MathError1 make_error_code(MathError1::valid_errors e)
{
  return MathError1(e);
}
inline MathError2 make_error_code(MathError2::valid_errors e)
{
  return MathError2(e);
}

namespace std
{
  template <> struct is_error_code_enum<MathError1::valid_errors> : std::true_type
  {
  };
  template <> struct is_error_code_enum<MathError2::valid_errors> : std::true_type
  {
  };
}


outcome::expected<double /*, std::error_code */> div(double x, double y) noexcept
{
  if (::fabs(y) < DBL_EPSILON)
  {
    // This operation would fail, instead let's return the reason of
    // the failure wrapped in E
    return outcome::make_unexpected<std::error_code>(MathError1::DivisionByZero);
  }
  else
  {
    // This operation is valid, return the result wrapped in T
    return x / y;
  }
}

outcome::expected<long long /*, std::error_code */> div10mul3(double y) noexcept
{
  // If calling div() fails, return the same error immediately,
  // else unpack the T into r. REQUIRES type E to be identical!
  BOOST_OUTCOME_TRY(r, div(10.0, y));
  if (r < 0.0)
  {
    return outcome::make_unexpected<std::error_code>(MathError2::NegativeSquareRoot);
  }
  return (long long)(sqrt(r * 3.0));
}

int main(void)
{
  try
  {
    std::cout << div10mul3(1.0).value() << std::endl;
  }
  // NOTE: Much less likely to become stale accidentally
  catch (const outcome::bad_expected_access</* std::error_code */> &e)
  {
    // Also note we can always print the error code because E is
    // always an error_code
    std::cout << "div10mul3().value() failed due to " << e.error() << std::endl;
  }
  return 0;
}
//! [expected_try2]
