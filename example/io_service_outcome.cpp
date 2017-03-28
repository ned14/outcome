#include <condition_variable>
#include <deque>
#include <future>
#include <mutex>
#include <thread>
#include <vector>

#include "../include/boost/outcome.hpp"
namespace outcome = BOOST_OUTCOME_V1_NAMESPACE;

//! [io_service_outcome]
/* This is an implementation of a futures based Executor as proposed by
P0443R1 http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2017/p0443r1.html
using the ASIO/Networking TS io_service as a model.

ASIO propagates exception throws by handlers out of the corresponding run().
Executors don't do that, and neither does this implementation.
*/
class io_service
{
public:
  //! The type of the i/o handler, same as ASIO
  using io_handler = void(std::error_code &ec, size_t bytes_transferred);
private:
  std::mutex _lock;
  std::deque<std::packaged_task<outcome::outcome<void>(size_t)>> _work;
  std::condition_variable _newwork;
public:

  // Call the i/o handler at some future point in some future thread,
  // returning immediately
  outcome::result<std::future<outcome::outcome<void>>>
    post(std::function<io_handler> f) noexcept
  {
    try
    {
      // Make a packaged task rebinding the completion handler
      std::packaged_task<outcome::outcome<void>(size_t)>
        rebound([f = std::move(f)](size_t bytes_transferred)
        ->outcome::outcome<void>
      {
        try
        {
          std::error_code ec;
          // Call the handler, if he returns an error code return that,
          // if he throws return the exception thrown
          f(ec, bytes_transferred);
          if (ec)
            return outcome::make_errored_outcome<>(ec);
          return outcome::make_ready_outcome();
        }
        catch (...)
        {
          return outcome::make_exceptional_outcome<>();
        }
      });
      // Fetching the future can throw a STL exception
      std::future<outcome::outcome<void>> f(rebound.get_future());
      {
        std::lock_guard<decltype(_lock)> g(_lock);
        // Extending the deque can throw a STL exception
        _work.push_back(std::move(rebound));
        _newwork.notify_one();
      }
      return std::move(f);
    }
    // Catch all STL exception throws and return a corresponding result
    BOOST_OUTCOME_CATCH_ALL_EXCEPTION_TO_RESULT
    
    
    
  }

  /* Call the i/o handler in some thread, returning when it completes.
  Note that ASIO's io_service calls this dispatch(), but the Executors
  proposal calls it execute()
  */
  outcome::outcome<void>
    execute(std::function<io_handler> f) noexcept
  {
    try
    {
      // If post() returns a failure in its result, then this will throw
      // a system_error with that error code
      // The future.get() may throw too.
      return post(std::move(f)).value().get();
    }
    // Convert all STL exception throws into the equivalent error code
    // such that the returned outcome will be errored, not excepted.
    // Note if the result returned by post() was errored it will have
    // been thrown as a system_error, this will convert it back to its
    // original error code.
    BOOST_OUTCOME_CATCH_EXCEPTION_TO_RESULT
    catch (...)
    {
      // For any non-STL exception throws, return as an excepted outcome
      return outcome::make_exceptional_outcome<>();
    }


    
  }

  // If there are handlers pending, execute up to one of them
  size_t run_one() noexcept
  {
    std::unique_lock<decltype(_lock)> g(_lock);
    if (_work.empty())
      return 0;

    std::packaged_task<outcome::outcome<void>(size_t)>
      mywork(std::move(_work.front()));
    _work.pop_front();
    g.unlock();
    // Call the completion handler with some arbitrary bytes_transferred
    mywork(78);
    return 1;
  }

  // If there is no work, sleep until work arrives, else execute as much
  // work as possible
  size_t run() noexcept
  {
    {
      std::unique_lock<decltype(_lock)> g(_lock);
      if (_work.empty())
      {
        _newwork.wait(g);  // allow spurious wakeups
      }
    }
    size_t executed = 0;
    while (run_one())
      executed++;
    return executed;
  }
};

struct work
{
  io_service *ios;
  size_t count;
  constexpr work(io_service &_ios) : ios(&_ios), count(0) {}
  void operator()(std::error_code &ec, size_t bytes_transferred)
  {
    ++count;
    if (count < 10000000)
    {
      // Call myself again. Note I can simply call value() to
      // cause the result to throw a system_error with any error code
      ios->post(std::ref(*this)).value();
      
    }
  }
};

int main(void)
{
  io_service ios;
  std::vector<work> works(std::thread::hardware_concurrency(), work(ios));
  std::vector<std::thread> threads;
  for (size_t n = 0; n < std::thread::hardware_concurrency(); n++)
  {
    threads.push_back(std::thread([&ios] {
      ios.run();
    }));
  }
  std::this_thread::sleep_for(std::chrono::seconds(1));
  for (size_t n = 0; n < std::thread::hardware_concurrency(); n++)
  {
    // Note I can simply call value() to cause the result to throw
    // a system_error with any error code
    ios.post(works[n]).value();
  }
  for (auto &i : threads)
    i.join();
  return 0;
}
//! [io_service_outcome]
