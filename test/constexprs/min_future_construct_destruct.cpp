#include "../../include/boost/spinlock/future.hpp"

extern BOOST_MONAD_NOINLINE void test1()
{
  using namespace boost::spinlock::lightweight_futures;
  future<int> p;  
}
extern BOOST_MONAD_NOINLINE void test2()
{
}

int main(void)
{
  test1();
  test2();
  return 0;
}
