# CTest script for a CI to submit to CDash a run of configuration,
# building and testing
cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
# Bring in the Boost lite cmake tooling
list(FIND CMAKE_MODULE_PATH "boost-lite" boost_lite_idx)
if(${boost_lite_idx} EQUAL -1)
  if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/../boost-lite/cmake")
    set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/../boost-lite/cmake")
    set(CTEST_BOOSTLITE_SCRIPTS "${CMAKE_CURRENT_SOURCE_DIR}/../boost-lite/scripts")
  elseif(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/include/boost/outcome/boost-lite/cmake")
    set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/include/boost/outcome/boost-lite/cmake")
    set(CTEST_BOOSTLITE_SCRIPTS "${CMAKE_CURRENT_SOURCE_DIR}/include/boost/outcome/boost-lite/scripts")
  else()
    message(FATAL_ERROR "FATAL: A copy of boost-lite cannot be found. Try running 'git submodule update --init --recursive'")
  endif()
endif()
include(BoostLiteUtils)


CONFIGURE_CTEST_SCRIPT_FOR_CDASH("outcome" "cmake_ci")
ctest_empty_binary_directory(${CTEST_BINARY_DIRECTORY})

ctest_start("Experimental")
ctest_configure()
ctest_build(TARGET outcome_hl--unittests)
ctest_test(RETURN_VALUE retval)
merge_junit_results_into_ctest_xml()
#ctest_upload(FILES )
ctest_submit()
if(NOT retval EQUAL 0)
  message(FATAL_ERROR "FATAL: Running tests exited with ${retval}")
endif()
