/* Canned codegen quality test sequences
(C) 2017 Niall Douglas <http://www.nedproductions.biz/> (59 commits)
*/

#include "../../include/boost/outcome.hpp"

extern QUICKCPPLIB_NOINLINE void test1()
{
  using namespace boost::outcome;
  outcome<int> m;
}
extern QUICKCPPLIB_NOINLINE void test2()
{
}

int main(void)
{
  test1();
  test2();
  return 0;
}
