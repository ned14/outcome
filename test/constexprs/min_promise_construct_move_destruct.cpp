#define BOOST_MONAD_FUTURE_ENABLE_CONSTEXPR_LOCK_FOLDING

#include "../../include/boost/spinlock/future.hpp"

extern BOOST_MONAD_NOINLINE void test1()
{
  using namespace boost::spinlock::lightweight_futures;
  promise<int> p;  
  promise<int> p2(std::move(p));  
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
