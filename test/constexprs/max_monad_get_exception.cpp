#include "../../include/boost/spinlock/future.hpp"

using namespace boost::spinlock::lightweight_futures;
extern monad<int> unknown();
extern BOOST_MONAD_NOINLINE std::exception_ptr test1()
{
  return unknown().get_exception();
}
extern BOOST_MONAD_NOINLINE void test2()
{
}

int main(void)
{
  int ret=0;
  if(std::make_exception_ptr(5)!=test1()) ret=1;
  test2();
  return ret;
}
