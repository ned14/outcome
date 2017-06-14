# CTest script for a CI to submit to CDash a run of configuration,
# building and testing
cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
include(cmake/QuickCppLibBootstrap.cmake)
include(BoostLiteUtils)


CONFIGURE_CTEST_SCRIPT_FOR_CDASH("outcome" "cmake_ci")
ctest_empty_binary_directory(${CTEST_BINARY_DIRECTORY})
include(FindGit)
set(CTEST_GIT_COMMAND "${GIT_EXECUTABLE}")

ctest_start("Experimental")
ctest_update()
ctest_configure()
ctest_build()
ctest_test(RETURN_VALUE retval)
merge_junit_results_into_ctest_xml()
#ctest_upload(FILES )
ctest_submit()
if(NOT retval EQUAL 0)
  message(FATAL_ERROR "FATAL: Running tests exited with ${retval}")
endif()
