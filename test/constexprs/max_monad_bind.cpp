/* Canned codegen quality test sequences
(C) 2017 Niall Douglas <http://www.nedproductions.biz/> (59 commits)
*/

#include "../../include/boost/outcome.hpp"

#ifdef __GNUC__
#define WEAK __attribute__((weak))
#else
#define WEAK
#endif

using namespace boost::outcome;
extern outcome<int> unknown() WEAK;
extern QUICKCPPLIB_NOINLINE outcome<int> test1()
{
  return unknown().bind([](int m) { return m * 3; });
}
extern QUICKCPPLIB_NOINLINE void test2()
{
}

int main(void)
{
  outcome<int> m(test1());
  test2();
  return 0;
}
