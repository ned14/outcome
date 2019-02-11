/* Example of Outcome
(C) 2017 Niall Douglas <http://www.nedproductions.biz/> (149 commits)


Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License in the accompanying file
Licence.txt or at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.


Distributed under the Boost Software License, Version 1.0.
(See accompanying file Licence.txt or copy at
http://www.boost.org/LICENSE_1_0.txt)
*/

#include <boost/outcome.hpp>
#include <boost/asio/associated_executor.hpp>
#include <boost/asio/associated_allocator.hpp>
#include <boost/asio/async_result.hpp>
#include <boost/asio/detail/handler_alloc_helpers.hpp>
#include <boost/asio/detail/handler_invoke_helpers.hpp>
#include <boost/system/error_code.hpp>

#include <vector>

namespace asio = boost::asio;
namespace outcome = boost::outcome_v2;

using byte = char;

int old()
{
  //! [old-use-case]
  // Dynamically allocate a buffer to read into. This must be move-only
  // so it can be attached to the completion handler, hence the unique_ptr.
  auto buffer = std::make_unique<std::unique_ptr<std::vector<byte>>>(1024);  

  // Begin an asynchronous socket read, upon completion invoke
  // the lambda function specified
  asio::async_read(socket,
    asio::buffer(buffer->data(), buffer->size()),
    
    // Retain lifetime of the i/o buffer until completion
    [buffer](const error_code &ec, size_t bytes) {
      // Handle the buffer read
      if(ec)
      {
        std::cerr << "Buffer read failed with " << ec << std::endl;
        return;
      }
      std::cout << "Read " << bytes << " bytes into buffer" << std::endl;
      
      // buffer will be dynamically freed now
  });
  //! [old-use-case]
}

int new_()
{
  //! [new-use-case]
  // As coroutines suspend the calling thread whilst an asynchronous
  // operation executes, we can use stack allocation instead of dynamic
  // allocation
  char buffer[1024];
  
  // Get an ASIO completion token for the current coroutine (requires
  // Coroutines TS)
  auto token = co_await asio::experimental::this_coro::token();

  // Asynchronously read data, suspending this coroutine until completion,
  // returning the bytes of the data read into the result.
  try
  {
    std::size_t read = co_await asio::async_read(socket, buffer, token);
    std::cout << "Read " << bytes << " bytes into buffer" << std::endl;
  }
  catch(const std::system_error &e)
  {
    std::cerr << "Buffer read failed with " << e << std::endl;
  }
  //! [new-use-case]
}

int outcome()
{
  //! [outcome-use-case]
  // Asynchronously read data, suspending this coroutine until completion,
  // returning the bytes of the data read into the result, or any failure.
  outcome::result<std::size_t> read = //
    co_await asio::async_read(socket, buffers, as_result(token));
  
  // Usage is exactly like ordinary Outcome. Note the lack of exception throw!
  if(read.has_error())
  {
    std::cerr << "Buffer read failed with " << read.error() << std::endl;
    return;
  }
  std::cout << "Read " << bytes.value() << " bytes into buffer" << std::endl;
  //! [outcome-use-case]
}

int main(void)
{
  return 0;
}
