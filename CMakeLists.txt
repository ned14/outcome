# Outcome cmake
# (C) 2016-2023 Niall Douglas <http://www.nedproductions.biz/>
# File Created: June 2016
# 
# 
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License in the accompanying file
# Licence.txt or at
# 
#     http://www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
# 
# 
# Distributed under the Boost Software License, Version 1.0.
#     (See accompanying file Licence.txt or copy at
#           http://www.boost.org/LICENSE_1_0.txt)

cmake_minimum_required(VERSION 3.9 FATAL_ERROR)

set(OUTCOME_DEPENDENCY_QUICKCPPLIB_GIT_TAG "master" CACHE STRING "Which git tag to use for the QuickCppLib dependency")
if(NOT OUTCOME_DEPENDENCY_QUICKCPPLIB_GIT_TAG STREQUAL "master")
  # Don't reuse the bootstrapped git clone as the dependency itself
  if(CMAKE_BINARY_DIR)
    set(CTEST_QUICKCPPLIB_CLONE_DIR "${CMAKE_BINARY_DIR}/quickcpplib-bootstrap")
  else()
    set(CTEST_QUICKCPPLIB_CLONE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/quickcpplib-bootstrap")
  endif()
endif()
set(OUTCOME_DEPENDENCY_STATUS_CODE_GIT_TAG "master" CACHE STRING "Which git tag to use for the status-code dependency")
option(OUTCOME_BUNDLE_EMBEDDED_STATUS_CODE "Whether to bundle an embedded copy of SG14 status-code with Outcome. Used by various package managers such as vcpkg." ON)

include(cmake/QuickCppLibBootstrap.cmake)
include(QuickCppLibRequireOutOfSourceBuild)
include(QuickCppLibUtils)
include(QuickCppLibPolicies)

# Parse the version we tell cmake directly from the version header file
ParseProjectVersionFromHpp("${CMAKE_CURRENT_SOURCE_DIR}/include/outcome/detail/version.hpp" VERSIONSTRING)
# Sets the usual PROJECT_NAME etc
project(outcome VERSION ${VERSIONSTRING} LANGUAGES C CXX)
# Also set a *cmake* namespace for this project
set(PROJECT_NAMESPACE)

# Setup this cmake environment for this project
include(QuickCppLibSetupProject)

option(OUTCOME_BUNDLE_EMBEDDED_QUICKCPPLIB "Whether to bundle an embedded copy of QuickCppLib with Outcome. Used by various package managers such as vcpkg." OFF)
option(OUTCOME_ENABLE_DEPENDENCY_SMOKE_TEST "Whether to build executables which are smoke tests that Outcome is fully working. Used by various package managers such as vcpkg." OFF)
option(OUTCOME_ENABLE_CXX_MODULES "Whether to enable the building of an Outcome C++ module" OFF)
set(UNIT_TESTS_CXX_VERSION "latest" CACHE STRING "The version of C++ to use in the unit tests")

if(NOT outcome_IS_DEPENDENCY)
  # This file should be updated with the last git SHA next commit
  UpdateRevisionHppFromGit("${CMAKE_CURRENT_SOURCE_DIR}/include/outcome/detail/revision.hpp")
  # Need to also possibly update the .natvis file
#  file(STRINGS "${CMAKE_CURRENT_SOURCE_DIR}/include/outcome/detail/revision.hpp" namespace_permuter REGEX "OUTCOME_PREVIOUS_COMMIT_UNIQUE (.+)")
#  if(NOT namespace_permuter MATCHES "OUTCOME_PREVIOUS_COMMIT_UNIQUE (.+)")
#    indented_message(FATAL_ERROR "FATAL: ${CMAKE_CURRENT_SOURCE_DIR}/include/outcome/detail/revision.hpp was not parseable")
#  endif()
#  set(namespace_permuter "${CMAKE_MATCH_1}")
#  file(READ "${CMAKE_CURRENT_SOURCE_DIR}/include/outcome/outcome.natvis" natvis_contents)
#  string(REGEX REPLACE "outcome_v2_([0-9a-f]+)" "outcome_v2_${namespace_permuter}" new_natvis_contents "${natvis_contents}")
#  if(NOT natvis_contents STREQUAL new_natvis_contents)
#    file(WRITE "${CMAKE_CURRENT_SOURCE_DIR}/include/outcome/outcome.natvis" "${new_natvis_contents}")
#  endif()
endif()
# Find my library dependencies
if(OUTCOME_BUNDLE_EMBEDDED_QUICKCPPLIB AND CTEST_QUICKCPPLIB_CLONE_DIR)
  file(COPY "${CTEST_QUICKCPPLIB_CLONE_DIR}/repo/" DESTINATION "${CMAKE_BINARY_DIR}/quickcpplib")
  find_quickcpplib_library(quickcpplib
    GIT_REPOSITORY "https://github.com/ned14/quickcpplib.git"
    REQUIRED
    IS_HEADER_ONLY
    INBUILD
    INCLUDE_ALL
  )
else()
  find_quickcpplib_library(quickcpplib
    GIT_REPOSITORY "https://github.com/ned14/quickcpplib.git"
    GIT_TAG "${OUTCOME_DEPENDENCY_QUICKCPPLIB_GIT_TAG}"
    REQUIRED
    IS_HEADER_ONLY
  )
endif()
if(OUTCOME_BUNDLE_EMBEDDED_STATUS_CODE)
  ensure_git_subrepo("${CMAKE_CURRENT_SOURCE_DIR}/include/outcome/experimental/status-code/include" "https://github.com/ned14/status-code.git")
else()
  find_quickcpplib_library(status-code
    GIT_REPOSITORY "https://github.com/ned14/status-code.git"
    GIT_TAG "${OUTCOME_DEPENDENCY_STATUS_CODE_GIT_TAG}"
    REQUIRED
    IS_HEADER_ONLY
  )
  list_filter(${PROJECT_NAME}_HEADERS EXCLUDE REGEX include/outcome/experimental/status-code/)
endif()

# Make an interface only library so dependent CMakeLists can bring in this header-only library
include(QuickCppLibMakeHeaderOnlyLibrary)

# If we have standard concepts, enable those for both myself and all inclusions
apply_cxx_concepts_to(INTERFACE outcome_hl REQUIRE_STD_CONCEPTS)

# Make preprocessed edition of this library target
if(NOT outcome_IS_DEPENDENCY OR OUTCOME_FORCE_ENABLE_PP_TARGETS)
  if(NOT PYTHONINTERP_FOUND)
    indented_message(WARNING "NOT rebuilding preprocessed edition of library due to python not being installed")
  else()
    function(make_single_header target name)
      add_partial_preprocess(${target}
                            "${name}"
                            "${CMAKE_CURRENT_SOURCE_DIR}/include/outcome/detail/revision.hpp"
                            ${ARGN}
                            -I ../quickcpplib/include
                            --passthru-defines --passthru-unfound-includes --passthru-unknown-exprs
                            --passthru-comments --line-directive --compress # --debug
                            -U __cpp_modules
                            -U QUICKCPPLIB_ENABLE_VALGRIND
                            -U DOXYGEN_SHOULD_SKIP_THIS -U DOXYGEN_IS_IN_THE_HOUSE
                            -U STANDARDESE_IS_IN_THE_HOUSE
                            -U OUTCOME_UNSTABLE_VERSION -U OUTCOME_ENABLE_ABI_PERMUTATION
                            -D QUICKCPPLIB_DISABLE_ABI_PERMUTATION=1
                            WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
                            )
      if(NOT CMAKE_VERSION VERSION_LESS 3.3)
        add_dependencies(outcome_hl ${target})
      endif()
    endfunction()
    make_single_header(outcome_hl-pp-std
                       "${CMAKE_CURRENT_SOURCE_DIR}/single-header/outcome.hpp"
                       "${CMAKE_CURRENT_SOURCE_DIR}/include/outcome.hpp")
    make_single_header(outcome_hl-pp-basic
                       "${CMAKE_CURRENT_SOURCE_DIR}/single-header/outcome-basic.hpp"
                       "${CMAKE_CURRENT_SOURCE_DIR}/include/outcome/basic_outcome.hpp"
                       "${CMAKE_CURRENT_SOURCE_DIR}/include/outcome/try.hpp")
    make_single_header(outcome_hl-pp-experimental
                       "${CMAKE_CURRENT_SOURCE_DIR}/single-header/outcome-experimental.hpp"
                       "${CMAKE_CURRENT_SOURCE_DIR}/include/outcome/experimental/status_outcome.hpp"
                       "${CMAKE_CURRENT_SOURCE_DIR}/include/outcome/experimental/status-code/include/status-code/nested_status_code.hpp"
                       "${CMAKE_CURRENT_SOURCE_DIR}/include/outcome/try.hpp")
  endif()
endif()

# Set the standard definitions for these libraries and bring in the all_* helper functions
include(QuickCppLibApplyDefaultDefinitions)
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
if(TARGET quickcpplib::hl)
  target_link_libraries(outcome_hl INTERFACE quickcpplib::hl)
endif()
if(TARGET status-code::hl)
  target_link_libraries(outcome_hl INTERFACE status-code::hl)
  all_compile_definitions(PUBLIC OUTCOME_USE_SYSTEM_STATUS_CODE=1)
endif()

if(OUTCOME_ENABLE_CXX_MODULES)
  # Right now this is very hacky, as cmake doesn't support building C++ Modules yet
  add_custom_target(outcome_module
    COMMAND "${CMAKE_CXX_COMPILER}" /std:c++latest /EHsc $<$<CONFIG:Debug>:/MDd> $<$<NOT:$<CONFIG:Debug>>:/MD> /fp:precise /c "${CMAKE_CURRENT_SOURCE_DIR}/include/outcome.ixx" "-I${CMAKE_CURRENT_SOURCE_DIR}/../quickcpplib/include" "-I${CMAKE_BINARY_DIR}/quickcpplib/include"
  )
  all_compile_definitions(PUBLIC
    OUTCOME_ENABLE_CXX_MODULES=1
  )
endif()

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/test" AND NOT outcome_IS_DEPENDENCY AND (NOT DEFINED BUILD_TESTING OR BUILD_TESTING))
  # For all possible configurations of this library, add each test
  list_filter(outcome_TESTS EXCLUDE REGEX "constexprs")
  set(outcome_TESTS_DISABLE_PRECOMPILE_HEADERS
    "outcome_hl--coroutine-support"
    "outcome_hl--core-result"
    "outcome_hl--fileopen"
    "outcome_hl--hooks"
    "outcome_hl--outcome-int-int-1"
    "outcome_hl--result-int-int-1"
    "outcome_hl--result-int-int-2"
  )
  include(QuickCppLibMakeStandardTests)
  
  # Enable Coroutines for the coroutines support test
  foreach(target ${outcome_TEST_TARGETS})
    if(${target} MATCHES "coroutine-support")
      apply_cxx_coroutines_to(PRIVATE ${target})
    endif()
    # MSVC's concepts implementation blow up unless permissive is off
    if(MSVC AND NOT CLANG)
      target_compile_options(${target} PRIVATE /permissive-)
    endif()
  endforeach()
  
  # Duplicate all tests into C++ exceptions disabled forms
  set(noexcept_tests)
  set(first_test_target_noexcept)
  set(first_test_target_permissive)
  foreach(testsource ${outcome_TESTS})
    if(testsource MATCHES ".+/(.+)[.](c|cpp|cxx)$")
      set(testname ${CMAKE_MATCH_1})
      if(NOT testname MATCHES "expected-pass")
        set(target_name "outcome_hl--${testname}-noexcept")
        add_executable(${target_name} "${testsource}")
        if(NOT first_test_target_noexcept)
          set(first_test_target_noexcept ${target_name})
        elseif(${target_name} MATCHES "coroutine-support|fileopen|hooks|core-result")
          set_target_properties(${target_name} PROPERTIES DISABLE_PRECOMPILE_HEADERS On)
        elseif(COMMAND target_precompile_headers)
          target_precompile_headers(${target_name} REUSE_FROM ${first_test_target_noexcept})
        endif()
        add_dependencies(_hl ${target_name})
        list(APPEND noexcept_tests ${target_name})
        if(MSVC AND NOT CLANG)
          # Disable warnings "C++ exception handler used" and "noexcept used with no exception handling"
          target_compile_options(${target_name} PRIVATE /wd4530 /wd4577)
#          target_compile_options(${target_name} PRIVATE /permissive-)  # test bug report #142
        endif()
        target_compile_definitions(${target_name} PRIVATE SYSTEM_ERROR2_NOT_POSIX=1 "SYSTEM_ERROR2_FATAL=::abort()")
        target_link_libraries(${target_name} PRIVATE outcome::hl)
        if(${target_name} MATCHES "coroutine-support")
          apply_cxx_coroutines_to(PRIVATE ${target_name})
        endif()
        set_target_properties(${target_name} PROPERTIES
          RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
          POSITION_INDEPENDENT_CODE ON
          CXX_EXCEPTIONS OFF
          CXX_RTTI OFF
        )
        add_test(NAME ${target_name} CONFIGURATIONS Debug Release RelWithDebInfo MinSizeRel
          COMMAND $<TARGET_FILE:${target_name}> --reporter junit --out $<TARGET_FILE:${target_name}>.junit.xml
        )
        if(MSVC AND NOT CLANG)
          set(target_name "outcome_hl--${testname}-permissive")
          add_executable(${target_name} "${testsource}")
          if(NOT first_test_target_permissive)
            set(first_test_target_permissive ${target_name})
          elseif(${target_name} MATCHES "coroutine-support|fileopen|core-result")
            set_target_properties(${target_name} PROPERTIES DISABLE_PRECOMPILE_HEADERS On)
          elseif(COMMAND target_precompile_headers)
            target_precompile_headers(${target_name} REUSE_FROM ${first_test_target_permissive})
          endif()
          add_dependencies(_hl ${target_name})
          target_link_libraries(${target_name} PRIVATE outcome::hl)
          target_compile_options(${target_name} PRIVATE /permissive)
          if(${target_name} MATCHES "coroutine-support")
            apply_cxx_coroutines_to(PRIVATE ${target_name})
          endif()
          set_target_properties(${target_name} PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
            POSITION_INDEPENDENT_CODE ON
          )
          if(OUTCOME_ENABLE_CXX_MODULES)
            set(target_name "outcome_hl--${testname}-modules")
            add_executable(${target_name} "${testsource}")
            add_dependencies(${target_name} outcome_module)
            target_link_libraries(${target_name} PRIVATE outcome::hl)
            target_compile_options(${target_name} PRIVATE /experimental:module /std:c++latest)
            target_compile_definitions(${target_name} PRIVATE __cpp_modules=202001L)
            set_target_properties(${target_name} PROPERTIES
              RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
              POSITION_INDEPENDENT_CODE ON
              DISABLE_PRECOMPILE_HEADERS On
            )
          endif()
        endif()
      endif()
    endif()
  endforeach()
  add_custom_target(${PROJECT_NAME}-noexcept COMMENT "Building all tests with C++ exceptions disabled ...")
  add_dependencies(${PROJECT_NAME}-noexcept ${noexcept_tests})
  
  # Turn on latest C++ where possible for the test suite
  if(UNIT_TESTS_CXX_VERSION STREQUAL "latest")
    set(LATEST_CXX_FEATURE)
    foreach(feature ${CMAKE_CXX_COMPILE_FEATURES})
      if(feature STREQUAL "cxx_std_23")
        set(LATEST_CXX_FEATURE "cxx_std_23")
        indented_message(STATUS "NOTE: This compiler claims to support C++ 23, enabling for unit test suite")
      endif()
    endforeach()
    if(NOT LATEST_CXX_FEATURE)
      foreach(feature ${CMAKE_CXX_COMPILE_FEATURES})
        if(feature STREQUAL "cxx_std_20")
          set(LATEST_CXX_FEATURE "cxx_std_20")
          indented_message(STATUS "NOTE: This compiler claims to support C++ 20, enabling for unit test suite")
        endif()
      endforeach()
    endif()
    if(NOT LATEST_CXX_FEATURE)
      foreach(feature ${CMAKE_CXX_COMPILE_FEATURES})
        if(feature STREQUAL "cxx_std_17")
          set(LATEST_CXX_FEATURE "cxx_std_17")
          indented_message(STATUS "NOTE: This compiler claims to support C++ 17, enabling for unit test suite")
        endif()
      endforeach()
    endif()
  elseif(UNIT_TESTS_CXX_VERSION)
    set(LATEST_CXX_FEATURE "cxx_std_${UNIT_TESTS_CXX_VERSION}")
  endif()
  if(LATEST_CXX_FEATURE)
    # Turn on latest C++ where possible for the test suite
    if(ENABLE_CXX_MODULES)
      target_compile_features(outcome_hl_ixx PUBLIC ${LATEST_CXX_FEATURE})
    endif()
    foreach(test_target ${outcome_TEST_TARGETS} ${outcome_EXAMPLE_TARGETS})
      target_compile_features(${test_target} PUBLIC ${LATEST_CXX_FEATURE})
    endforeach()
  endif()
  
  # Add in the documentation snippets
  foreach(feature ${CMAKE_CXX_COMPILE_FEATURES})
    if(feature STREQUAL cxx_std_17)
      file(GLOB example_srcs RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}"
           "${CMAKE_CURRENT_SOURCE_DIR}/doc/src/snippets/*.c"
           "${CMAKE_CURRENT_SOURCE_DIR}/doc/src/snippets/*.cpp"
           )
      set(example_bins)
      foreach(example_src ${example_srcs})
        if(example_src MATCHES ".+/(.+)[.](c|cpp|cxx)$")
          set(example_bin "${PROJECT_NAME}-snippets_${CMAKE_MATCH_1}")
          add_executable(${example_bin} EXCLUDE_FROM_ALL "${example_src}")
          list(APPEND example_bins ${example_bin})
          target_link_libraries(${example_bin} PRIVATE outcome::hl)
          set_target_properties(${example_bin} PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
            POSITION_INDEPENDENT_CODE ON
          )
          if(example_src MATCHES "[.]c$")
            set_target_properties(${example_bin} PROPERTIES DISABLE_PRECOMPILE_HEADERS On)
          else()
            target_compile_features(${example_bin} PUBLIC cxx_std_17)
            if(CMAKE_SYSTEM_NAME MATCHES "Linux")
              target_link_libraries(${example_bin} PRIVATE stdc++fs)
            elseif(CMAKE_SYSTEM_NAME MATCHES "FreeBSD" OR APPLE)
              target_link_libraries(${example_bin} PRIVATE c++experimental)
            endif()
          endif()
        endif()
      endforeach()
      add_custom_target(${PROJECT_NAME}-snippets COMMENT "Building all documentation snippets ...")
      add_dependencies(${PROJECT_NAME}-snippets ${example_bins})
    endif()
  endforeach()
endif()

# Turn on pedantic warnings for all tests, examples and snippets
if(NOT MSVC)
  foreach(target ${outcome_TEST_TARGETS} ${outcome_EXAMPLE_TARGETS} ${example_bins})
    target_compile_options(${target} PUBLIC "-Wpedantic")
  endforeach()
endif()

if(OUTCOME_ENABLE_DEPENDENCY_SMOKE_TEST)
  set(OUTCOME_SMOKE_TESTS)
  add_executable(outcome-dependency-smoke-test_1 "test/tests/core-result.cpp")
  list(APPEND OUTCOME_SMOKE_TESTS outcome-dependency-smoke-test_1)
  add_executable(outcome-dependency-smoke-test_2 "test/tests/experimental-core-result-status.cpp")
  list(APPEND OUTCOME_SMOKE_TESTS outcome-dependency-smoke-test_2)
  foreach(target ${OUTCOME_SMOKE_TESTS})
    target_link_libraries(${target} PRIVATE outcome::hl)
    set_target_properties(${target} PROPERTIES
      RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
      DISABLE_PRECOMPILE_HEADERS On
    )
    add_test(NAME ${target} CONFIGURATIONS Debug Release RelWithDebInfo MinSizeRel
      COMMAND $<TARGET_FILE:${target}> --reporter junit --out $<TARGET_FILE:${target}>.junit.xml
    )
  endforeach()
endif()

# Cache this library's auto scanned sources for later reuse
include(QuickCppLibCacheLibrarySources)

# Dependencies needed to consume our cmake package
set(PROJECT_PACKAGE_DEPENDENCIES "include(CMakeFindDependencyMacro)")
if(TARGET quickcpplib::hl)
  string(APPEND PROJECT_PACKAGE_DEPENDENCIES "\nfind_dependency(quickcpplib)")
endif()
if(TARGET status-code::hl)
  string(APPEND PROJECT_PACKAGE_DEPENDENCIES "\nfind_dependency(status-code)")
endif()

# Make available this library for install and export
include(QuickCppLibMakeInstall)
include(QuickCppLibMakeExport)
