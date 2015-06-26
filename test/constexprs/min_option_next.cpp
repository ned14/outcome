#include "../../include/boost/spinlock/future.hpp"

using namespace boost::spinlock::lightweight_futures;

extern BOOST_SPINLOCK_NOINLINE option<int> test1(int n)
{
  return option<int>(n).next([](option<int> m) { return m.get()*3; });
}
extern BOOST_SPINLOCK_NOINLINE void test2()
{
}

int main(void)
{
  option<int> m(test1(5));
  test2();
  return m.get()!=15;
}
