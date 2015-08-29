#include "../../include/boost/outcome/future.hpp"

using namespace boost::outcome;

extern BOOST_OUTCOME_NOINLINE outcome<int> test1(int n)
{
  return outcome<int>(n).next([](outcome<int> m) { return m.get()*3; });
}
extern BOOST_OUTCOME_NOINLINE void test2()
{
}

int main(void)
{
  outcome<int> m(test1(5));
  test2();
  return m.get()!=15;
}
