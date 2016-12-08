#include "../include/boost/outcome.hpp"
#include <string>
#include <iostream>

//! [simple_example]
namespace bo = BOOST_OUTCOME_V1_NAMESPACE;

// Returns either an int, an error code or an exception ptr.
// One might model the error code as a programmer expected
// failure e.g. name not found, whereas the exception ptr
// might mean catastrophic unexpected failure e.g. storage
// is missing. Typically you abort on exception, but handle
// errors. Note the noexcept, this means that calling this
// function will NEVER invert execution flow unexpectedly.
bo::outcome<int> getConfigParam(std::string name) noexcept;

extern void runWithMax(int);

int main()
{
  // Get what the user has set for the MaxValue parameter
  auto oi = getConfigParam("MaxValue");
  // Did it return a valid integer?
  if(oi)
    runWithMax(*oi);
  // Did it return a catastrophic failure?
  else if(oi.has_exception())
    std::rethrow_exception(oi.exception());
  // Did it return an expected failure?
  else
    std::cerr << "getConfigParam reports error " << oi.error() << std::endl;
}
//! [simple_example]

bo::outcome<int> getConfigParam(std::string name) noexcept
{
  return 5;
}
extern void runWithMax(int)
{
}
