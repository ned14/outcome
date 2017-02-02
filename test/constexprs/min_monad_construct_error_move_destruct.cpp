#include "../../include/boost/outcome.hpp"

extern BOOSTLITE_NOINLINE std::error_code test1(boost::outcome::error_code_extended ec)
{
  using namespace boost::outcome;
  outcome<int> m1(std::move(ec));
  outcome<int> m2(std::move(m1));
  return m2.get_error();
}
extern BOOSTLITE_NOINLINE void test2()
{
}

int main(void)
{
  int ret = 0;
  if(boost::outcome::error_code_extended() != test1(boost::outcome::error_code_extended()))
    ret = 1;
  test2();
  return ret;
}
