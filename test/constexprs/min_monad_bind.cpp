#include "../../include/boost/spinlock/future.hpp"

using namespace boost::spinlock::lightweight_futures;

extern BOOST_SPINLOCK_NOINLINE monad<int> test1(int n)
{
  return monad<int>(n).bind([](int m) { return m*3; });
}
extern BOOST_SPINLOCK_NOINLINE void test2()
{
}

int main(void)
{
  monad<int> m(test1(5));
  test2();
  return m.get()!=15;
}
