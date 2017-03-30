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
// Imagine the libraries you depend on each use different mechanisms for returning errors

namespace outcome = BOOST_OUTCOME_V1_NAMESPACE;

namespace Library1
{                                                          // Like the Filesystem and Networking TS,
  auto fun(std::error_code &) noexcept                     // returns errors via lvalue ref to an error_code.
    -> int;                                                // Never throws exceptions.
}

namespace Library2
{                                                          // Throws some exception on error
  auto fun()
    -> int;
}
  
namespace Library3                                         // The Expected proposed for standardisation in C++ 20
{                                                          // Returns an int (expected) or some custom 
  auto fun() noexcept                                      // error code (unexpected). Never throws exceptions.
    -> outcome::expected<int, error_code>; 
}  
  
namespace Library4                                         // Result is an int (not error)
{                                                          // or an outcome::error_code_extended (error)
  auto fun() noexcept                                      // Never throws exceptions.
    -> outcome::result<int>;
}
  
// signalling uniform error Outcome is an int, or an outcome::error_code_extended,
// or a std::exception_ptr

auto my_fun() noexcept
  -> outcome::outcome<int>
{                                                          // all noexcept functions which could call
  try {                                                    // throwing code should always have their
    std::error_code ec;                                    // bodies wrapped in a try...catch
    int i = Library1::fun(ec);
    if (ec)
      return outcome::make_errored_outcome(ec);            // error code returned inside outcome
      
    try {
      i += Library2::fun();
    }
    catch (...) {
      return outcome::make_exceptional_outcome<>();        // exception_ptr returned inside outcome
    }
    
    if (auto rslt1 = Library3::fun())
      i += *rslt1;
    else
      return outcome::make_errored_outcome(rslt1.error()); // error code returned inside outcome
   
    BOOST_OUTCOME_TRY(rslt2, Library4::fun());             // this may return an outcome with an
                                                           // error code, iff fun() reports failure

    return i + rslt2;                                      // return outcome with a value
  }
  catch (...) {
    return outcome::make_exceptional_outcome<>();          // construct from std::current_exception()
  }
};

// using functions' outcome:

int test()
{
  try {
    int i = my_fun().value();                              // throws if not valued
    return i;
  }
  catch (std::exception const& e) {                        // e can be used to retrieve
    return inspect_exception_to_your_liking(e);            // initial error condition
  }
}
//! [simple_example]

int main(void)
{
  return test();
}
