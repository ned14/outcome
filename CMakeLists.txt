cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
include(cmake/QuickCppLibBootstrap.cmake)
include(QuickCppLibRequireOutOfSourceBuild)
include(QuickCppLibUtils)
include(QuickCppLibPolicies)

# Parse the version we tell cmake directly from the version header file
ParseProjectVersionFromHpp("${CMAKE_CURRENT_SOURCE_DIR}/include/outcome/version.hpp" VERSIONSTRING)
# Sets the usual PROJECT_NAME etc
project(outcome VERSION ${VERSIONSTRING} LANGUAGES C CXX)
# Also set a *cmake* namespace for this project
set(PROJECT_NAMESPACE)

# Setup this cmake environment for this project
include(QuickCppLibSetupProject)
if(NOT CLANG AND CMAKE_COMPILER_IS_GNUCC AND CMAKE_CXX_COMPILER_VERSION VERSION_GREATER 5.9)
  option(ENABLE_CXX_CONCEPTS "Enable the Concepts TS in the compiler (defaults to ON if GCC)" ON)
else()
  option(ENABLE_CXX_CONCEPTS "Enable the Concepts TS in the compiler (defaults to ON if GCC)" OFF)
endif()

if(NOT PROJECT_IS_DEPENDENCY)
  # This file should be updated with the last git SHA next commit
  UpdateRevisionHppFromGit("${CMAKE_CURRENT_SOURCE_DIR}/include/outcome/revision.hpp")
endif()
# Find my library dependencies
find_quickcpplib_library(quickcpplib 1.0 REQUIRED)

# Make an interface only library so dependent CMakeLists can bring in this header-only library
include(QuickCppLibMakeHeaderOnlyLibrary)

# Make preprocessed edition of this library target
if(NOT PROJECT_IS_DEPENDENCY)
  if(NOT PYTHONINTERP_FOUND)
    indented_message(WARNING "NOT rebuilding preprocessed edition of library due to python not being installed")
  else()
    # See if the ply package is installed so pcpp can run
    execute_process(COMMAND python -c "import ply" RESULT_VARIABLE python_has_ply)
    if(NOT python_has_ply EQUAL 0)
      indented_message(WARNING "NOT rebuilding preprocessed edition of library due to installed python not having the ply package installed. "
        "Do 'pip install ply' to fix. NOTE that doxygen docs will NOT build without the precompiled edition.")
    else()
      function(make_single_header target name)
        add_partial_preprocess(${target}
                              "${name}"
                              ${ARGN}
                              -I ..
                              --passthru-defines --passthru-unfound-includes --passthru-unknown-exprs
                              --passthru-comments --line-directive # --debug
                              -U QUICKCPPLIB_ENABLE_VALGRIND
                              -U DOXYGEN_SHOULD_SKIP_THIS -U DOXYGEN_IS_IN_THE_HOUSE
                              -U STANDARDESE_IS_IN_THE_HOUSE
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
                         "${CMAKE_CURRENT_SOURCE_DIR}/single-header/basic.hpp"
                         "${CMAKE_CURRENT_SOURCE_DIR}/include/outcome/basic_outcome.hpp"
                         "${CMAKE_CURRENT_SOURCE_DIR}/include/outcome/try.hpp")
      make_single_header(outcome_hl-pp-abi
                         "${CMAKE_CURRENT_SOURCE_DIR}/single-header/abi.hpp"
                         "${CMAKE_CURRENT_SOURCE_DIR}/include/outcome/basic_outcome.hpp"
                         -D OUTCOME_DISABLE_ABI_PERMUTATION=1
                         -D QUICKCPPLIB_DISABLE_ABI_PERMUTATION=1
                         -U OUTCOME_UNSTABLE_VERSION)
    endif()
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
target_link_libraries(outcome_hl INTERFACE quickcpplib::hl)

# On POSIX we need to patch linking to stdc++fs into the docs examples 
#if(DOXYGEN_FOUND AND GCC)
#  target_link_libraries(outcome-example_find_regex_expected stdc++fs)
#  target_link_libraries(outcome-example_find_regex_result stdc++fs)
#endif()

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/test" AND NOT PROJECT_IS_DEPENDENCY)
  # For all possible configurations of this library, add each test
  list_filter(outcome_TESTS EXCLUDE REGEX "constexprs")
  include(QuickCppLibMakeStandardTests)
  
  # Duplicate all tests into C++ exceptions disabled forms
  set(noexcept_tests)
  foreach(testsource ${outcome_TESTS})
    if(testsource MATCHES ".+/(.+)[.](c|cpp|cxx)$")
      set(testname ${CMAKE_MATCH_1})
      if(NOT testname MATCHES "expected-pass")
        set(target_name "outcome_hl--${testname}-noexcept")
        add_executable(${target_name} "${testsource}")
        list(APPEND noexcept_tests ${target_name})
        if(MSVC AND NOT CLANG)
          # Disable warnings "C++ exception handler used" and "noexcept used with no exception handling"
          target_compile_options(${target_name} PRIVATE /wd4530 /wd4577)
        endif()
        target_link_libraries(${target_name} PRIVATE outcome::hl)
        set_target_properties(${target_name} PROPERTIES
          RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
          POSITION_INDEPENDENT_CODE ON
          CXX_EXCEPTIONS OFF
          CXX_RTTI OFF
        )
        add_test(NAME ${target_name} CONFIGURATIONS Debug Release RelWithDebInfo MinSizeRel
          COMMAND $<TARGET_FILE:${target_name}> --reporter junit --out $<TARGET_FILE:${target_name}>.junit.xml
        )
      endif()
    endif()
  endforeach()
  add_custom_target(${PROJECT_NAME}-noexcept COMMENT "Building all tests with C++ exceptions disabled ...")
  add_dependencies(${PROJECT_NAME}-noexcept ${noexcept_tests})
  
  # Turn on C++ 17 and Concepts where possible for the test suite
  foreach(feature ${CMAKE_CXX_COMPILE_FEATURES})
    if(feature STREQUAL "cxx_std_17")
      foreach(test_target ${outcome_TEST_TARGETS} ${outcome_EXAMPLE_TARGETS})
        target_compile_features(${test_target} PUBLIC cxx_std_17)
        if(ENABLE_CXX_CONCEPTS)
          target_compile_options(${test_target} PUBLIC -fconcepts)
        endif()
      endforeach()
    endif()
  endforeach()
  
  # Add in the documentation snippets
  foreach(feature ${CMAKE_CXX_COMPILE_FEATURES})
    if(feature STREQUAL cxx_std_17)
      file(GLOB_RECURSE example_srcs RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}"
           "${CMAKE_CURRENT_SOURCE_DIR}/doc/src/snippets/*.cpp"
           )
      set(example_bins)
      foreach(example_src ${example_srcs})
        if(example_src MATCHES ".+/(.+)[.](c|cpp|cxx)$")
          set(example_bin "${PROJECT_NAME}-snippets_${CMAKE_MATCH_1}")
          add_executable(${example_bin} EXCLUDE_FROM_ALL "${example_src}")
          list(APPEND example_bins ${example_bin})
          set_target_properties(${example_bin} PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
            POSITION_INDEPENDENT_CODE ON
          )
          target_compile_features(${example_bin} PUBLIC cxx_std_17)
          if(ENABLE_CXX_CONCEPTS)
            target_compile_options(${example_bin} PUBLIC -fconcepts)
          endif()
          if(CMAKE_SYSTEM_NAME MATCHES "Linux")
            target_link_libraries(${example_bin} stdc++fs)
          elseif(CMAKE_SYSTEM_NAME MATCHES "FreeBSD" OR APPLE)
            target_link_libraries(${example_bin} c++experimental)
          endif()
        endif()
      endforeach()
      add_custom_target(${PROJECT_NAME}-snippets COMMENT "Building all documentation snippets ...")
      add_dependencies(${PROJECT_NAME}-snippets ${example_bins})
    endif()
  endforeach()
endif()

# Cache this library's auto scanned sources for later reuse
include(QuickCppLibCacheLibrarySources)

# Make available this library for install and export
include(QuickCppLibMakeInstall)
include(QuickCppLibMakeExport)
