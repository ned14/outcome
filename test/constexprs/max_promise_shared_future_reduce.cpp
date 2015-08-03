#include "../../include/boost/spinlock/future.hpp"

extern BOOST_MONAD_NOINLINE int test1()
{
  using namespace boost::spinlock::lightweight_futures;
  promise<int> p;
  shared_future<int> f(p.get_future());
  p.set_value(5);
  return f.get();
}
extern BOOST_MONAD_NOINLINE void test2()
{
}

int main(void)
{
  int ret=0;
  if(5!=test1()) ret=1;
  test2();
  return ret;
}
