#include "../../include/boost/spinlock/future.hpp"

extern BOOST_SPINLOCK_NOINLINE std::exception_ptr test1(std::exception_ptr e)
{
  using namespace boost::spinlock::lightweight_futures;
  monad<int> m(std::move(e));
  return m.get_exception();
}
extern BOOST_SPINLOCK_NOINLINE void test2()
{
}

int main(void)
{
  int ret=0;
  auto e=std::make_exception_ptr(5);
  if(e!=test1(e)) ret=1;
  test2();
  return ret;
}
