#define BOOST_OUTCOME_FUTURE_ENABLE_CONSTEXPR_LOCK_FOLDING

#include "../../include/boost/outcome/future.hpp"

extern BOOST_OUTCOME_NOINLINE void test1()
{
  using namespace boost::outcome::lightweight_futures;
  future<int> p;
  future<int> p2(std::move(p));
}
extern BOOST_OUTCOME_NOINLINE void test2()
{
}

int main(void)
{
  test1();
  test2();
  return 0;
}
