/* clang-format off
(error: no matching function for call to .+::outcome<int, int, int>::outcome|error: no matching constructor for initialization of 'outcome<int, int, int>'|cannot convert argument 1 from 'int')
clang-format on
*/

#include "../../include/outcome/outcome.hpp"

int main()
{
  using namespace OUTCOME_V2_NAMESPACE;
  // Must not be possible to initialise an outcome with same R, S and P types
  outcome<int, int, int> m(5);
  return 0;
}
