# Distributed under the Boost Software License, Version 1.0.
# https://www.boost.org/LICENSE_1_0.txt

include(BoostTest OPTIONAL RESULT_VARIABLE HAVE_BOOST_TEST)
if(NOT HAVE_BOOST_TEST)
  return()
endif()

set(BOOST_TEST_LINK_LIBRARIES Boost::outcome)

boost_test(TYPE compile-fail SOURCES "compile-fail/issue0071-fail.cpp")
boost_test(TYPE compile-fail SOURCES "compile-fail/outcome-int-int-1.cpp")
boost_test(TYPE compile-fail SOURCES "compile-fail/result-int-int-1.cpp")
boost_test(TYPE compile-fail SOURCES "compile-fail/result-int-int-2.cpp")

set(BOOST_TEST_LINK_LIBRARIES Boost::outcome Boost::unit_test_framework)
set(BOOST_TEST_COMPILE_DEFINITIONS BOOST_TEST_MODULE=Outcome)

boost_test(TYPE run SOURCES "tests/comparison.cpp")
boost_test(TYPE run SOURCES "tests/constexpr.cpp")
boost_test(TYPE run SOURCES "tests/containers.cpp")
boost_test(TYPE run SOURCES "tests/core-outcome.cpp")
boost_test(TYPE run SOURCES "tests/core-result.cpp")
boost_test(TYPE run SOURCES "tests/default-construction.cpp")
boost_test(TYPE run SOURCES "tests/experimental-core-outcome-status.cpp")
boost_test(TYPE run SOURCES "tests/experimental-core-result-status.cpp")
boost_test(TYPE run SOURCES "tests/experimental-p0709a.cpp")
boost_test(TYPE run SOURCES "tests/fileopen.cpp")
boost_test(TYPE run SOURCES "tests/hooks.cpp")
boost_test(TYPE run SOURCES "tests/issue0007.cpp")
boost_test(TYPE run SOURCES "tests/issue0009.cpp")
boost_test(TYPE run SOURCES "tests/issue0010.cpp")
boost_test(TYPE run SOURCES "tests/issue0012.cpp")
boost_test(TYPE run SOURCES "tests/issue0016.cpp")
boost_test(TYPE run SOURCES "tests/issue0059.cpp")
boost_test(TYPE run SOURCES "tests/issue0061.cpp")
boost_test(TYPE run SOURCES "tests/issue0064.cpp")
boost_test(TYPE run SOURCES "tests/issue0065.cpp")
boost_test(TYPE run SOURCES "tests/issue0071.cpp")
boost_test(TYPE run SOURCES "tests/issue0095.cpp")
boost_test(TYPE run SOURCES "tests/issue0115.cpp")
boost_test(TYPE run SOURCES "tests/issue0116.cpp")
boost_test(TYPE run SOURCES "tests/issue0140.cpp")
boost_test(TYPE run SOURCES "tests/issue0182.cpp")
boost_test(TYPE run SOURCES "tests/issue0203.cpp")
boost_test(TYPE run SOURCES "tests/issue0210.cpp")
boost_test(TYPE run SOURCES "tests/issue0220.cpp")
boost_test(TYPE run SOURCES "tests/issue0244.cpp")
boost_test(TYPE run SOURCES "tests/issue0247.cpp")
boost_test(TYPE run SOURCES "tests/issue0259.cpp")
# issue0255 is C++20-only, so it would register zero cases (a false green) in this
# lane below C++20; the B2 lane runs it at every standard instead.
boost_test(TYPE run SOURCES "tests/noexcept-propagation.cpp")
boost_test(TYPE run SOURCES "tests/propagate.cpp")
boost_test(TYPE run SOURCES "tests/serialisation.cpp")
boost_test(TYPE run SOURCES "tests/success-failure.cpp")
boost_test(TYPE run SOURCES "tests/swap.cpp")
boost_test(TYPE run SOURCES "tests/udts.cpp")
boost_test(TYPE run SOURCES "tests/value-or-error.cpp")

boost_test(TYPE run SOURCES "expected-pass.cpp")

# Several tests cannot exercise anything in every configuration (issue0059 below
# C++17, the no-exceptions-only ones when exceptions are on, ...). They print a
# marker and exit 77 rather than registering a case which asserts nothing, which
# CTest records as PASSED (see tests/skip_test.hpp). CTest only honours that on
# 77, so every test registered here maps it to SKIPPED; a genuine failure of any
# other exit code is still reported as Failed. The B2 lane has no such concept,
# so test/Jamfile.v2 disables those cases per cxxstd instead.
# `get_cmake_property` does not expose this one (it reads variables and a fixed
# list of special properties); `get_directory_property` does, and unlike
# `get_property(... DIRECTORY ...)` it exists back to CMake 2.6, which matters
# because Boost.CI tests a 3.10 floor. Guard anyway: a test may not have been
# registered at all.
get_directory_property(__outcome_tests TESTS)
foreach(__outcome_test IN LISTS __outcome_tests)
  if(TEST ${__outcome_test})
    set_tests_properties(${__outcome_test} PROPERTIES SKIP_RETURN_CODE 77)
  endif()
endforeach()
