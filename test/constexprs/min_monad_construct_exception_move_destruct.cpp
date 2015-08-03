#include "../../include/boost/spinlock/future.hpp"

extern BOOST_MONAD_NOINLINE std::exception_ptr test1(std::exception_ptr ec)
{
  using namespace boost::spinlock::lightweight_futures;
  monad<int> m1(std::move(ec));
  monad<int> m2(std::move(m1));
  return m2.get_exception();
}
extern BOOST_MONAD_NOINLINE void test2()
{
}

int main(void)
{
  int ret=0;
  if(std::exception_ptr()!=test1(std::exception_ptr())) ret=1;
  test2();
  return ret;
}
