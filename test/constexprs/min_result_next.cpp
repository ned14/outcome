#include "../../include/boost/spinlock/future.hpp"

using namespace boost::spinlock::lightweight_futures;

extern BOOST_OUTCOME_NOINLINE result<int> test1(int n)
{
  return result<int>(n).next([](result<int> m) { return m.get()*3; });
}
extern BOOST_OUTCOME_NOINLINE void test2()
{
}

int main(void)
{
  result<int> m(test1(5));
  test2();
  return m.get()!=15;
}
