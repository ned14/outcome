#include "../../include/boost/spinlock/future.hpp"

using namespace boost::spinlock::lightweight_futures;
extern option<int> unknown();
extern BOOST_OUTCOME_NOINLINE option<int> test1()
{
  return unknown().next([](option<int> m) { return m.get()*3; });
}
extern BOOST_OUTCOME_NOINLINE void test2()
{
}

int main(void)
{
  option<int> m(test1());
  test2();
  return 0;
}
