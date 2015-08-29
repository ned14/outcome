#include "../../include/boost/spinlock/future.hpp"

using namespace boost::spinlock::lightweight_futures;
extern monad<int> unknown();
extern BOOST_OUTCOME_NOINLINE monad<int> test1()
{
  return unknown().bind([](int m) { return m*3; });
}
extern BOOST_OUTCOME_NOINLINE void test2()
{
}

int main(void)
{
  monad<int> m(test1());
  test2();
  return 0;
}
