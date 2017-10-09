#include "../include/outcome/outcome.hpp"
#include <iostream>

namespace outcome = OUTCOME_V2_NAMESPACE;

//! [fun_1f]
namespace Layer1
{
  auto f() -> int; // may throw
}  
//! [fun_1f]

namespace Layer1
{    
  auto f() -> int { throw std::runtime_error{"XXX"}; }
}

//! [fun_2g]
namespace Layer2NX
{
  auto g() noexcept -> outcome::result<int> ;
}
//! [fun_2g]

namespace Layer2NX
{
  auto g() noexcept -> outcome::result<int> 
  {
    return 1;
  }
}

//! [fun_2f]
namespace Layer2NX
{   
  auto f() noexcept -> outcome::outcome<int> 
  try {
    return Layer1::f();
  }
  catch (...) {
    return std::current_exception();
  }
}    
//! [fun_2f]

//! [fun_2fun]    
namespace Layer2NX
{  
  auto fun() noexcept -> outcome::outcome<int> 
  {
    int * i = new int{0};
    OUTCOME_TRY (fr, Layer2NX::f());
    *i += fr;
    OUTCOME_TRY (gr, Layer2NX::g());
    *i += gr;
    int ans = *i;
    delete i;
    return ans;
  }
}
//! [fun_2fun]

//! [fun_3run]
namespace Layer3
{
  auto run() -> int // may throw
  {
    if (outcome::outcome<int> o = Layer2NX::fun())
      return o.value();
    else if (o.has_exception())
      std::rethrow_exception(o.exception());
    else
      throw std::system_error{o.error()};
  }    
}
//! [fun_3run]

int main()
try {
  return Layer3::run();
}
catch(std::exception const& e)
{
  std::cerr << e.what() << std::endl;
  return -1;
}