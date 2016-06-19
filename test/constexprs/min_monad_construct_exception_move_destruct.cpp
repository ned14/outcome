#include "../../include/boost/outcome.hpp"

extern BOOST_NOINLINE std::exception_ptr test1(std::exception_ptr ec)
{
  using namespace boost::outcome;
  outcome<int> m1(std::move(ec));
  outcome<int> m2(std::move(m1));
  return m2.get_exception();
}
extern BOOST_NOINLINE void test2()
{
}

int main(void)
{
  int ret=0;
  if(std::exception_ptr()!=test1(std::exception_ptr())) ret=1;
  test2();
  return ret;
}
