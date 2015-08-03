#include "../../include/boost/spinlock/future.hpp"

using namespace boost::spinlock::lightweight_futures;
extern monad<int> unknown();
extern BOOST_MONAD_NOINLINE std::error_code test1()
{
  return unknown().get_error();
}
extern BOOST_MONAD_NOINLINE void test2()
{
}

int main(void)
{
  int ret=0;
  if(std::error_code()!=test1()) ret=1;
  test2();
  return ret;
}
