#include "../../include/boost/outcome.hpp"

#ifdef __GNUC__
#define WEAK __attribute__((weak))
#else
#define WEAK
#endif

using namespace boost::outcome;
extern outcome<int> unknown() WEAK;
extern QUICKCPPLIB_NOINLINE std::exception_ptr test1()
{
  return unknown().get_exception();
}
extern QUICKCPPLIB_NOINLINE void test2()
{
}

int main(void)
{
  int ret=0;
  if(std::make_exception_ptr(5)!=test1()) ret=1;
  test2();
  return ret;
}
