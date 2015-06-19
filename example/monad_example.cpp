#include "../include/boost/spinlock/monad.hpp"
#include <iostream>

using namespace boost::spinlock::lightweight_futures;

template<class T> monad<T> do_test(monad<T> m)
{
  std::cout << "The value of my input monad is ";
  if(m)
    std::cout << m.get() << std::endl;
  else
    std::cout << (m.has_error() ? "errored" : m.has_exception() ? "excepted" : "empty") << std::endl;
  
  std::cout << "  or via bind(), my value is ";
  auto o(m.bind([](T v) { std::cout << v; return v; })
          .bind([](std::error_code e) { std::cout << "errored"; return e; })
          .bind([](std::exception_ptr e) { std::cout << "excepted"; return e; })
          .bind([](typename decltype(m)::empty_type) { std::cout << "empty"; }));
  std::cout << std::endl;
  return o;
}

int main(void)
{
  do_test(make_monad(5));
  do_test(make_monad<std::string>());
  do_test(make_monad<int>(std::error_code(5, std::generic_category())));
  do_test(make_monad<double>(std::make_exception_ptr(std::logic_error("bad dog"))));
  return 0;
}
