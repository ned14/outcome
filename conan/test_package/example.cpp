#include <iostream>
#include <string>

#include <outcome.hpp>

namespace outcome = OUTCOME_V2_NAMESPACE;

outcome::result<std::string> hello()
{
  return "Hello, World!";
}

int main()
{
  std::cout << hello() << std::endl;
}
