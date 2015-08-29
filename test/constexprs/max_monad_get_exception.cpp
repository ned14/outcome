#include "../../include/boost/outcome/future.hpp"

using namespace boost::outcome;
extern outcome<int> unknown();
extern BOOST_OUTCOME_NOINLINE std::exception_ptr test1()
{
  return unknown().get_exception();
}
extern BOOST_OUTCOME_NOINLINE void test2()
{
}

int main(void)
{
  int ret=0;
  if(std::make_exception_ptr(5)!=test1()) ret=1;
  test2();
  return ret;
}
