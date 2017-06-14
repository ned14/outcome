#include "../../include/boost/outcome.hpp"

#ifdef __GNUC__
#define WEAK __attribute__((weak))
#else
#define WEAK
#endif

using namespace boost::outcome;
extern option<int> unknown() WEAK;
extern QUICKCPPLIB_NOINLINE option<int> test1()
{
  return unknown().next([](option<int> m) { return m.get()*3; });
}
extern QUICKCPPLIB_NOINLINE void test2()
{
}

int main(void)
{
  option<int> m(test1());
  test2();
  return 0;
}
