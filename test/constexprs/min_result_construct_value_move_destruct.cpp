#include "../../include/boost/spinlock/future.hpp"

extern BOOST_OUTCOME_NOINLINE int test1()
{
  using namespace boost::spinlock::lightweight_futures;
  result<int> m1(5);
  result<int> m2(std::move(m1));
  return std::move(m2).get();
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
