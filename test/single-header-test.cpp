#undef __cpp_modules
#include "../single-header/outcome.hpp"

int main()
{
  using namespace OUTCOME_V2_NAMESPACE;
  result<int> f(5);
  outcome<void> m(in_place_type<void>);
  return 0;
}
