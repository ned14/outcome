#include "../../include/boost/outcome.hpp"

using namespace boost::outcome;
extern result<int> unknown();
extern BOOSTLITE_NOINLINE result<int> test1()
{
  return unknown().next([](result<int> m) { return m.get()*3; });
}
extern BOOSTLITE_NOINLINE void test2()
{
}

int main(void)
{
  result<int> m(test1());
  test2();
  return 0;
}
