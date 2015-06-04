#include "../../include/boost/spinlock/future.hpp"

extern BOOST_SPINLOCK_NOINLINE int test1()
{
  using namespace boost::spinlock::lightweight_futures;
  monad<int, true> m(5);
  return std::move(m).get();
}
extern BOOST_SPINLOCK_NOINLINE void test2()
{
}

int main(void)
{
  int ret=0;
  if(5!=test1()) ret=1;
  test2();
  return ret;
}
