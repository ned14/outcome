#include "../../include/boost/spinlock/future.hpp"

__attribute((noinline)) void test1()
{
  using namespace boost::spinlock::lightweight_futures;
  promise<int> p;  
}
__attribute((noinline)) void test2()
{
}

int main(void)
{
  test1();
  test2();
  return 0;
}
