#include "../include/boost/outcome.hpp"

namespace Library1 {
  int fun(std::error_code &) noexcept { return 5; }
}
namespace Library2 {
  int fun() { return 5; }
}
namespace Library3 {
  using error_code = boost::outcome::error_code_extended;
  boost::outcome::expected<int, Library3::error_code> fun() noexcept { return 5; }
}
namespace Library4 {
  boost::outcome::result<int> fun() noexcept { return 5; }
}

int inspect_exception_to_your_liking(const std::exception &) { return 5; }

//! [simple_example]
// Imagine the libraries you depend on each use different
// mechanisms for returning errors

namespace outcome = BOOST_OUTCOME_V1_NAMESPACE;

// Like the Filesystem and Networking TS, returns errors via
// lvalue ref to an error_code. Never throws exceptions.
auto Library1::fun(std::error_code &) noexcept
  -> int;

// Throws some exception on error
auto Library2::fun()
  -> int;

// The Expected proposed for standardisation in C++ 20
// Returns an int (expected) or some custom error code (unexpected)
// Never throws exceptions.
auto Library3::fun() noexcept
  -> outcome::expected<int, Library3::error_code>;

// Result is an int (not error) or an outcome::error_code_extended (error)
// Never throws exceptions.
auto Library4::fun() noexcept
  -> outcome::result<int>;

  
// signalling uniform error
// Outcome is an int, or an outcome::error_code_extended,
// or a std::exception_ptr

auto my_fun()
  -> outcome::outcome<int>
{
  try
  {
    std::error_code ec;
    int i = Library1::fun(ec);

    if (ec)
      return outcome::make_errored_outcome(ec);

    try {
      i += Library2::fun();
    }
    BOOST_OUTCOME_CATCH_EXCEPTION_TO_RESULT

    if (outcome::expected<int, Library3::error_code> rslt1 = Library3::fun())
      i += *rslt1;
    else
      return outcome::make_errored_outcome(rslt1.error());
   
    BOOST_OUTCOME_TRY(rslt2, Library4::fun());
    return i + rslt2;
  }
  catch(...)
  {
    // Defaults to constructing from std::current_exception()
    return outcome::make_exceptional_outcome<>();
  }
};

// using functions' outcome:

int test()
{
  try {
    int i = my_fun().value();  // throws if not valued
    return i;
  }
  catch(std::exception const& e) {
    return inspect_exception_to_your_liking(e);
  }
}
//! [simple_example]

int main(void)
{
  return test();
}
