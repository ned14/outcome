#include <condition_variable>
#include <deque>
#include <future>
#include <mutex>
#include <thread>
#include <vector>

#include "../include/boost/outcome.hpp"
namespace outcome = BOOST_OUTCOME_V1_NAMESPACE;

//! [io_service_expected]
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
  std::deque<std::packaged_task<outcome::experimental::expected<void>(size_t)>> _work;
  std::condition_variable _newwork;
public:

  // Call the i/o handler at some future point in some future thread,
  // returning immediately
  outcome::experimental::expected<std::future<outcome::experimental::expected<void>>, std::exception_ptr>
    post(std::function<io_handler> f) noexcept
  {
    try
    {
      // Make a packaged task rebinding the completion handler
      std::packaged_task<outcome::experimental::expected<void>(size_t)>
        rebound([f = std::move(f)](size_t bytes_transferred)
        ->outcome::experimental::expected<void>
      {
        // Note we let exception throws be handled by the packaged_task

        std::error_code ec;
        // Call the handler, if he returns an error code return that,
        // if he throws return the exception thrown
        f(ec, bytes_transferred);
        if (ec)
          return outcome::experimental::make_unexpected(ec);
        return {};
        
        
        

        
      });
      // Fetching the future can throw a STL exception
      std::future<outcome::experimental::expected<void>> f(rebound.get_future());
      {
        std::lock_guard<decltype(_lock)> g(_lock);
        // Extending the deque can throw a STL exception
        _work.push_back(std::move(rebound));
        _newwork.notify_one();
      }
      return std::move(f);
    }
    catch (...)
    {
      // Return the exception thrown
      return outcome::experimental::make_unexpected(std::current_exception());
    }
  }

  /* Call the i/o handler in some thread, returning when it completes.
  Note that ASIO's io_service calls this dispatch(), but the Executors
  proposal calls it execute()
  */
  outcome::experimental::expected<void, outcome::experimental::expected<std::error_code, std::exception_ptr>>
    execute(std::function<io_handler> f) noexcept
  {
    try
    {
      // If post() returns a failure in its result, then this will throw
      std::future<outcome::experimental::expected<void>> fut = post(std::move(f)).value();
      // Might rethrow any exception thrown by the handler, that will get caught below
      outcome::experimental::expected<void> v = fut.get();
      // If the handler succeeded, return success, else return its error code
      if (v)
        return {};
      return outcome::experimental::make_unexpected(v.error());
    }
    catch (const outcome::experimental::bad_expected_access<std::exception_ptr> &e)
    {
      // This called when post() failed internally to do the dispatch
      return outcome::experimental::make_unexpected(outcome::experimental::make_unexpected(e.error()));
    }
    catch (...)
    {
      // Return the exception thrown
      return outcome::experimental::make_unexpected(outcome::experimental::make_unexpected(std::current_exception()));
    }
  }

  // If there are handlers pending, execute up to one of them
  size_t run_one() noexcept
  {
    std::unique_lock<decltype(_lock)> g(_lock);
    if (_work.empty())
      return 0;

    std::packaged_task<outcome::experimental::expected<void>(size_t)>
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
      // Call myself again
      auto ret = ios->post(std::ref(*this));
      if (!ret)
        std::rethrow_exception(ret.error());
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
    auto ret = ios.post(works[n]);
    if (!ret)
      std::rethrow_exception(ret.error());
  }
  for (auto &i : threads)
    i.join();
  return 0;
}
//! [io_service_expected]
