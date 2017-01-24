//! [error_code_registration]
#include <iostream>
#include <system_error>  // bring in std::error_code et al

// This is the custom error code enum
enum class MathError {
  DivisionByZero,
  NegativeLogarithm,
  NegativeSquareRoot
};

namespace detail
{
  // Define a custom error code category derived from std::error_category
  class MathError_category : public std::error_category
  {
  public:
    // Return a short descriptive name for the category
    virtual const char *name() const noexcept override final { return "MathError"; }
    // Return what each enum means in text
    virtual std::string message(int c) const override final
    {
      switch (static_cast<MathError>(c))
      {
      case MathError::DivisionByZero:
        return "division by zero";
      case MathError::NegativeLogarithm:
        return "logarithm of negative number";
      case MathError::NegativeSquareRoot:
        return "square root of negative number";
      default:
        return "unknown";
      }
    }
    // OPTIONAL: Allow generic error conditions to be compared to me
    virtual std::error_condition default_error_condition(int c) const noexcept override final
    {
      switch (static_cast<MathError>(c))
      {
      case MathError::DivisionByZero:
        return make_error_condition(std::errc::result_out_of_range);
      case MathError::NegativeLogarithm:
        return make_error_condition(std::errc::argument_out_of_domain);
      case MathError::NegativeSquareRoot:
        return make_error_condition(std::errc::argument_out_of_domain);
      default:
        // I have no mapping for this code
        return std::error_condition(c, *this);
      }
    }
  };
}

// Declare a global function returning a static instance of the custom category
extern const detail::MathError_category &MathError_category()
{
  static detail::MathError_category c;
  return c;
}

// Overload the global make_error_code() free function with our
// custom enum. It will be found via ADL by the compiler if needed.
inline std::error_code make_error_code(MathError e)
{
  return std::error_code(static_cast<int>(e), MathError_category());
}

namespace std
{
  // Tell the C++ 11 STL metaprogramming that enum MathError
  // is registered with the standard error code system
  template <> struct is_error_code_enum<MathError> : std::true_type
  {
  };
}

int main(void)
{
  // Note that we can now supply MathError directly to error_code
  std::error_code ec(MathError::NegativeLogarithm);

  std::cout << "MathError::NegativeLogarithm is printed by std::error_code as "
    << ec << " with explanatory message " << ec.message() << std::endl;

  // We can compare MathError containing error codes to generic conditions
  std::cout << "ec is equivalent to std::errc::result_out_of_range = "
    << (ec == std::errc::result_out_of_range) << std::endl;
  std::cout << "ec is equivalent to std::errc::argument_out_of_domain = "
    << (ec == std::errc::argument_out_of_domain) << std::endl;
  return 0;
}
//! [error_code_registration]
