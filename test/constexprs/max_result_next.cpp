#include "../../include/boost/outcome.hpp"

#ifdef __GNUC__
#define WEAK __attribute__((weak))
#else
#define WEAK
#endif

using namespace boost::outcome;
extern result<int> unknown() WEAK;
extern QUICKCPPLIB_NOINLINE result<int> test1()
{
  return unknown().next([](result<int> m) { return m.get()*3; });
}
extern QUICKCPPLIB_NOINLINE void test2()
{
}

int main(void)
{
  result<int> m(test1());
  test2();
  return 0;
}
