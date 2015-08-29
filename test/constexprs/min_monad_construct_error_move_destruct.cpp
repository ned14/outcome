#include "../../include/boost/outcome/future.hpp"

extern BOOST_OUTCOME_NOINLINE std::error_code test1(std::error_code ec)
{
  using namespace boost::outcome;
  outcome<int> m1(std::move(ec));
  outcome<int> m2(std::move(m1));
  return m2.get_error();
}
extern BOOST_OUTCOME_NOINLINE void test2()
{
}

int main(void)
{
  int ret=0;
  if(std::error_code()!=test1(std::error_code())) ret=1;
  test2();
  return ret;
}
