#include "../../include/boost/outcome.hpp"

using namespace boost::outcome;

extern QUICKCPPLIB_NOINLINE result<int> test1(int n)
{
  return result<int>(n).next([](result<int> m) { return m.get()*3; });
}
extern QUICKCPPLIB_NOINLINE void test2()
{
}

int main(void)
{
  result<int> m(test1(5));
  test2();
  return m.get()!=15;
}
