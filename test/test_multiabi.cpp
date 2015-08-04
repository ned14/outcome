// Use the Boost.Test emulation in Boost.BindLib as Boost.Test isn't multi ABI capable.
#define BOOST_MONAD_USE_BOOST_UNIT_TEST 0

#define STRINGIZE2(a) #a
#define STRINGIZE(a, b) STRINGIZE2(a ## b)

// Make unit test names be different
#define BOOST_CATCH_AUTO_TEST_CASE_NAME(name) STRINGIZE(1_, name)

#if 1
// A copy of Monad + unit tests using Boost
#define BOOST_MONAD_USE_BOOST_THREAD 1
#include "unittests.cpp"
#undef BOOST_MONAD_USE_BOOST_THREAD
#endif

#undef BOOST_CATCH_AUTO_TEST_CASE_NAME
#define BOOST_CATCH_AUTO_TEST_CASE_NAME(name) STRINGIZE(2_, name)

#if 0
// A copy of Monad + unit tests using the STL
#define BOOST_MONAD_USE_BOOST_THREAD 0
#include "unittests.cpp"
#endif
