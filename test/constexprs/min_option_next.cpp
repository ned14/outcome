/* Canned codegen quality test sequences
(C) 2017 Niall Douglas <http://www.nedproductions.biz/> (59 commits)
*/

#include "../../include/boost/outcome.hpp"

using namespace boost::outcome;

extern QUICKCPPLIB_NOINLINE option<int> test1(int n)
{
  return option<int>(n).next([](option<int> m) { return m.get()*3; });
}
extern QUICKCPPLIB_NOINLINE void test2()
{
}

int main(void)
{
  option<int> m(test1(5));
  test2();
  return m.get()!=15;
}
