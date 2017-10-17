#include "../../../include/outcome.hpp"
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

struct Resource
{
  double use(int i) { return i * 0.01; } 
};

//! [fun_2fun]    
namespace Layer2NX
{  
  auto fun() noexcept -> outcome::outcome<double> 
  {
    Resource* resource = new (std::nothrow) Resource;
    if (!resource)
        return std::errc::not_enough_memory;
      
    outcome::outcome<int> fr = Layer2NX::f();
    if (!fr) {
      delete resource;
      return fr.as_failure();                // #1
    }
    
    double ans = resource->use(fr.value());
    
    outcome::result<int> gr = Layer2NX::g();
    if (!gr) {
      delete resource;
      return gr.as_failure();                // #2
    }
    
    ans += resource->use(gr.value());
    
    delete resource;
    return ans;
  }
}
//! [fun_2fun]
 
//! [fun_2fun2]    
namespace Layer2NX
{  
  auto fun2() noexcept -> outcome::outcome<double> 
  {
    std::unique_ptr<Resource> resource {new (std::nothrow) Resource};
    if (!resource)
      return std::errc::not_enough_memory;
    
    OUTCOME_TRY (fr, Layer2NX::f());
    double ans = resource->use(fr);
    
    OUTCOME_TRY (gr, Layer2NX::g());
    ans += resource->use(gr);
    
    return ans;
  }
}
//! [fun_2fun2]

//! [fun_3run]
namespace Layer3
{
  auto run() -> double // may throw
  {
    if (outcome::outcome<double> o = Layer2NX::fun())
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