#include "../../include/boost/spinlock/future.hpp"

using namespace boost::spinlock::lightweight_futures;
extern monad<int> unknown();
extern BOOST_SPINLOCK_NOINLINE monad<int> test1()
{
  return unknown().then([](monad<int> m) { return m.get()*3; });
}
extern BOOST_SPINLOCK_NOINLINE void test2()
{
}

int main(void)
{
  monad<int> m(test1());
  test2();
  return 0;
}
