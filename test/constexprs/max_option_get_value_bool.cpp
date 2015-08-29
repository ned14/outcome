#include "../../include/boost/spinlock/future.hpp"

using namespace boost::spinlock::lightweight_futures;
extern option<bool> unknown();
extern BOOST_OUTCOME_NOINLINE int test1()
{
  return unknown().get();
}
extern BOOST_OUTCOME_NOINLINE void test2()
{
}

int main(void)
{
  int ret=0;
  if(5!=test1()) ret=1;
  test2();
  return ret;
}
