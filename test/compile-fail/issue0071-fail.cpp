/* clang-format off
(error: no matching function for call to .+::result|error: no matching constructor for initialization of 'result<udt>'|cannot convert argument 1 from 'int')
clang-format on
*/

#include "../../include/outcome/result.hpp"

int main()
{
  using namespace OUTCOME_V2_NAMESPACE;
  struct udt
  {
    explicit udt(int) {}
  };
  // Must not be possible to implicitly initialise a result<udt>
  result<udt> m(5);
  return 0;
}
