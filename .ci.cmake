# CTest script for a CI to submit to CDash a run of configuration,
# building and testing

set(CTEST_PROJECT_NAME "outcome")
set(CTEST_SOURCE_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")
set(CTEST_BINARY_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/cmake_ci")
set(CTEST_CONFIGURATION_TYPE Release)
if(WIN32)
  set(CTEST_CMAKE_GENERATOR "Visual Studio 14 2015 Win64")
  set(CTEST_CMAKE_CI_BIN_DIR "cmake_ci/bin/${CTEST_CONFIGURATION_TYPE}")
  set(CTEST_SITE $ENV{COMPUTERNAME})
else()
  set(CTEST_CMAKE_GENERATOR "Unix Makefiles")
  set(CTEST_CMAKE_CI_BIN_DIR "cmake_ci/bin")
  set(CTEST_SITE $ENV{NAME})
endif()
set(CTEST_BUILD_NAME "${CMAKE_SYSTEM}-${CMAKE_SYSTEM_PROCESSOR}")

#ctest_empty_binary_directory(${CTEST_BINARY_DIRECTORY})
find_program(CTEST_PYTHON_COMMAND NAMES python)
if(EXISTS "../boost-lite/scripts/merge_junit_results.py")
  set(CTEST_BOOSTLITE_SCRIPTS "../boost-lite/scripts")
elseif(EXISTS "include/boost/outcome/boost-lite/scripts/merge_junit_results.py")
  set(CTEST_BOOSTLITE_SCRIPTS "include/boost/outcome/boost-lite/scripts")
else()
  message(FATAL_ERROR "FATAL: boost-lite/scripts/merge_junit_results.py not found!")
endif()

ctest_start("Experimental")
ctest_configure()
ctest_build()
ctest_test()
# Merge all the junit XML files from the testing into one junit XML file
execute_process(COMMAND "${CTEST_PYTHON_COMMAND}" "${CTEST_BOOSTLITE_SCRIPTS}/merge_junit_results.py" "${CTEST_BINARY_DIRECTORY}/merged_junit_results.xml" "${CTEST_CMAKE_CI_BIN_DIR}/*.junit.xml"
  RESULT_VARIABLE result
)
message(STATUS "Merging junit XML results into a single junit XML returned with status ${result}")
# Figure out where this iteration's Test.xml lives
file(READ "${CTEST_BINARY_DIRECTORY}/Testing/TAG" tag_file)
string(REGEX MATCH "[^\n]*" xml_dir "${tag_file}")
set(CTEST_XML_DIR "${CTEST_BINARY_DIRECTORY}/Testing/${xml_dir}")
# Add the combined junit XML file into our Test.xml
execute_process(COMMAND "${CTEST_PYTHON_COMMAND}" "${CTEST_BOOSTLITE_SCRIPTS}/add_junit_results_to_ctest.py" "${CTEST_XML_DIR}/Test.xml" "${CTEST_BINARY_DIRECTORY}/merged_junit_results.xml"
  RESULT_VARIABLE result
)
message(STATUS "Merging junit XML results into the CTest XML returned with status ${result}")
#ctest_upload(FILES )
ctest_submit()
