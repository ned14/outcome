#include "../../include/boost/outcome.hpp"

using namespace boost::outcome;
extern outcome<int> unknown();
extern BOOSTLITE_NOINLINE std::error_code test1()
{
  return unknown().get_error();
}
extern BOOSTLITE_NOINLINE void test2()
{
}

int main(void)
{
  int ret=0;
  if(std::error_code()!=test1()) ret=1;
  test2();
  return ret;
}
