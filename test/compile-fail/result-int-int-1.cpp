/* clang-format off
(error: no matching function for call to .+::result<int, int>::result|error: no matching constructor for initialization of 'result<int, int>'|cannot convert argument 1 from 'int')
clang-format on
*/

#include "../../include/outcome/std_result.hpp"

int main()
{
  using namespace OUTCOME_V2_NAMESPACE;
  // Must not be possible to initialise a result with same R and S types
  result<int, int> m(5);
  return 0;
}
