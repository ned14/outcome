cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
# Bring in the Boost lite cmake tooling
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/include/boost/outcome/boost-lite/cmake")
include(BoostLiteRequireOutOfSourceBuild)
include(BoostLiteUtils)  # for ParseProjectVersionFromHpp and UpdateRevisionHppFromGit

# Parse the version we tell cmake directly from the version header file
ParseProjectVersionFromHpp("${CMAKE_CURRENT_SOURCE_DIR}/include/boost/outcome/version.hpp" VERSIONSTRING)
# Sets the usual PROJECT_NAME etc
project(outcome VERSION ${VERSIONSTRING} LANGUAGES CXX)
# Also set a *cmake* namespace for this project
set(PROJECT_NAMESPACE boost::)
include(CTest)

# Update this header file with the current git SHA and last timestamp
UpdateRevisionHppFromGit("${CMAKE_CURRENT_SOURCE_DIR}/include/boost/outcome/revision.hpp")
# Make an interface only library so dependent CMakeLists can bring in this header-only library
include(BoostLiteMakeHeaderOnlyLibrary)

# Set the standard definitions for these libraries and bring in the all_* helper functions
include(BoostLiteApplyDefaultDefinitions)
# Set the C++ features this library requires
all_compile_features(PUBLIC
  # cxx_exceptions                        ## Annoyingly not supported by cmake 3.4
  cxx_alias_templates
  cxx_variadic_templates
  cxx_noexcept
  cxx_constexpr
  cxx_thread_local
  #cxx_init_captures                      ## Not supported yet by cmake 3.4
  cxx_attributes
  cxx_variable_templates
)

# For all possible configurations of this library, add each test
list_filter(outcome_TESTS EXCLUDE REGEX "test_multiabi.cpp")
include(BoostLiteMakeStandardTests)
foreach(test_target ${outcome_TEST_TARGETS})
  target_compile_definitions(${test_target} PUBLIC BOOST_OUTCOME_ENABLE_OPERATORS=1)
endforeach()
