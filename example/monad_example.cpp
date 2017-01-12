#define BOOST_OUTCOME_ENABLE_ADVANCED 1
#include "../include/boost/outcome.hpp"
#include <iostream>

#ifndef BOOST_OUTCOME_ENABLE_ADVANCED
#error Failed
#endif

using namespace BOOST_OUTCOME_V1_NAMESPACE;

//! [monad_bind_example]
template<class T> outcome<T> do_test(outcome<T> m)
{
  std::cout << "The value of my input monad is ";
  if(m)
    std::cout << m.value() << std::endl;
  else
    std::cout << (m.has_error() ? "errored" : m.has_exception() ? "excepted" : "empty") << std::endl;
  
  std::cout << "  or via bind(), my value is ";
  auto o(m >> [](T v) { std::cout << v; return v; }
           >> [](error_code_extended e) { std::cout << "errored"; return e; }
           >> [](std::exception_ptr e) { std::cout << "excepted"; return e; }
           >> [](typename decltype(m)::empty_type) { std::cout << "empty"; });
  std::cout << std::endl;
  return o;
}
//! [monad_bind_example]

int main(void)
{
  do_test(make_outcome(5));
  do_test(make_outcome<std::string>());
  do_test(make_outcome<int>(error_code_extended(5, std::generic_category())));
  do_test(make_outcome<double>(std::make_exception_ptr(std::logic_error("bad dog"))));
  return 0;
}
