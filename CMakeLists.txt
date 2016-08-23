cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
# If necessary bring in the Boost lite cmake tooling
list(FIND CMAKE_MODULE_PATH "boost-lite" boost_lite_idx)
if(${boost_lite_idx} EQUAL -1)
  if(EXISTS "${CMAKE_SOURCE_DIR}/../boost-lite/cmake")
    set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/../boost-lite/cmake")
  elseif(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/include/boost/outcome/boost-lite/cmake")
    set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/include/boost/outcome/boost-lite/cmake")
  else()
    message(FATAL_ERROR "FATAL: A copy of boost-lite cannot be found. Try running 'git submodule update --init --recursive'")
  endif()
endif()
include(BoostLiteRequireOutOfSourceBuild)
include(BoostLiteUtils)
include(BoostLitePolicies)

# Parse the version we tell cmake directly from the version header file
ParseProjectVersionFromHpp("${CMAKE_CURRENT_SOURCE_DIR}/include/boost/outcome/version.hpp" VERSIONSTRING)
# Sets the usual PROJECT_NAME etc
project(outcome VERSION ${VERSIONSTRING} LANGUAGES CXX)
# Also set a *cmake* namespace for this project
set(PROJECT_NAMESPACE boost--)
# This file should be updated with the last git SHA next commit
UpdateRevisionHppFromGit("${CMAKE_CURRENT_SOURCE_DIR}/include/boost/outcome/revision.hpp")
# Setup this cmake environment for this project
include(BoostLiteSetupProject)
# Find my library dependencies
find_boostish_library(boost-lite "include/boost/outcome" 1.0 REQUIRED)

# Make an interface only library so dependent CMakeLists can bring in this header-only library
include(BoostLiteMakeHeaderOnlyLibrary)

# Create a custom doxygen generation target
include(BoostLiteMakeDoxygen)
# Set the standard definitions for these libraries and bring in the all_* helper functions
include(BoostLiteApplyDefaultDefinitions)
# Set the C++ features this library requires
all_compile_features(PUBLIC
  # cxx_exceptions                        ## Annoyingly not supported by cmake 3.6
  cxx_alias_templates
  cxx_variadic_templates
  cxx_noexcept
  cxx_constexpr
  cxx_thread_local
  cxx_lambda_init_captures
  cxx_attributes
  cxx_generic_lambdas
)
if(NOT MSVC OR CMAKE_VERSION VERSION_GREATER 3.59)
  all_compile_features(PUBLIC
    cxx_variable_templates
  )
endif()
# Set the library dependencies this library has
target_link_libraries(outcome_hl INTERFACE boost-lite_hl)

# For all possible configurations of this library, add each test
list_filter(outcome_TESTS EXCLUDE REGEX "test_multiabi.cpp")
include(BoostLiteMakeStandardTests)
if(TARGET outcome_hl_pch)
  target_compile_definitions(outcome_hl_pch PUBLIC BOOST_OUTCOME_ENABLE_OPERATORS=1)
endif()
foreach(test_target ${outcome_TEST_TARGETS})
  target_compile_definitions(${test_target} PUBLIC BOOST_OUTCOME_ENABLE_OPERATORS=1)
endforeach()

# Make available this library for install and export
include(BoostLiteMakeInstall)
include(BoostLiteMakeExport)
