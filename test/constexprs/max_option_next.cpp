#include "../../include/boost/outcome.hpp"

using namespace boost::outcome;
extern option<int> unknown();
extern BOOSTLITE_NOINLINE option<int> test1()
{
  return unknown().next([](option<int> m) { return m.get()*3; });
}
extern BOOSTLITE_NOINLINE void test2()
{
}

int main(void)
{
  option<int> m(test1());
  test2();
  return 0;
}
