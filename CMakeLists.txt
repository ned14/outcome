cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
# If necessary bring in the Boost lite cmake tooling
list(FIND CMAKE_MODULE_PATH "boost-lite" boost_lite_idx)
if(${boost_lite_idx} EQUAL -1)
  if(EXISTS "${CMAKE_SOURCE_DIR}/../.use_boostish_siblings")
    set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/../boost-lite/cmake")
  elseif(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/../.use_boostish_siblings")
    set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/../boost-lite/cmake")
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
project(outcome VERSION ${VERSIONSTRING} LANGUAGES C CXX)
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
  cxx_alias_templates
  cxx_variadic_templates
  cxx_noexcept
  cxx_constexpr
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

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/test" AND NOT PROJECT_IS_DEPENDENCY)
  # For all possible configurations of this library, add each test
  list_filter(outcome_TESTS EXCLUDE REGEX "test_multiabi.cpp")
  include(BoostLiteMakeStandardTests)
  if(TARGET outcome_hl_pch)
    target_compile_definitions(outcome_hl_pch PUBLIC BOOST_OUTCOME_ENABLE_ADVANCED=1)
  endif()
  foreach(test_target ${outcome_TEST_TARGETS} ${outcome_EXAMPLE_TARGETS})
    target_compile_definitions(${test_target} PUBLIC BOOST_OUTCOME_ENABLE_ADVANCED=1)
  endforeach()

  # Add the unit tests but with exceptions and RTTI disabled
  add_executable(outcome_hl--unittests_noexcept "test/unittests.cpp")
  set_target_properties(outcome_hl--unittests_noexcept PROPERTIES EXCLUDE_FROM_ALL ON)
  add_dependencies(_hl outcome_hl--unittests_noexcept)
  if(WIN32)
    target_compile_definitions(outcome_hl--unittests_noexcept PUBLIC _UNICODE)
  endif()
  list(APPEND outcome_TEST_TARGETS outcome_hl--unittests_noexcept)
  set_target_properties(outcome_hl--unittests_noexcept PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    POSITION_INDEPENDENT_CODE ON
    CXX_EXCEPTIONS OFF
    CXX_RTTI OFF
    CXX_STANDARD 14
  )
  add_test(NAME outcome_hl--unittests_noexcept CONFIGURATIONS Debug Release RelWithDebInfo MinSizeRel
    COMMAND $<TARGET_FILE:outcome_hl--unittests_noexcept> --reporter junit --out $<TARGET_FILE:outcome_hl--unittests_noexcept>.junit.xml
  )
endif()

# Make available this library for install and export
include(BoostLiteMakeInstall)
include(BoostLiteMakeExport)
