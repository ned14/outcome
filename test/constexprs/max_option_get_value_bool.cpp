#include "../../include/boost/outcome.hpp"

using namespace boost::outcome;
extern option<bool> unknown();
extern BOOST_NOINLINE int test1()
{
  return unknown().get();
}
extern BOOST_NOINLINE void test2()
{
}

int main(void)
{
  int ret=0;
  if(5!=test1()) ret=1;
  test2();
  return ret;
}
