/* clang-format off
(error: no matching function for call to .+::basic_result<int, int>::basic_result(.+::in_place_type_t<int>&)|error: no matching constructor for initialization of 'result<int, int>'|cannot convert argument 1 from '.+::in_place_type_t<int>')
clang-format on
*/

#include "../../include/outcome/std_result.hpp"

int main()
{
  using namespace OUTCOME_V2_NAMESPACE;
  // Must not be possible to initialise a result with same R and S types
  result<int, int> m(in_place_type<int>);
  return 0;
}
