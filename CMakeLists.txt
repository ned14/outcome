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
    indented_message(WARNING "NOT rebuilding precompiled edition of library due to python not being installed")
  else()
    # See if the ply package is installed so pcpp can run
    execute_process(COMMAND python -c "import ply" RESULT_VARIABLE python_has_ply)
    if(NOT python_has_ply EQUAL 0)
      indented_message(WARNING "NOT rebuilding precompiled edition of library due to installed python not having the ply package installed. "
        "Do 'pip install ply' to fix. NOTE that doxygen docs will NOT build without the precompiled edition.")
    else()
      add_partial_preprocess(outcome_hl-pp
                            "${CMAKE_CURRENT_SOURCE_DIR}/single-header/${PROJECT_NAME}.hpp"
                            "${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}.hpp"
                            -I .
                            --passthru-defines --passthru-unfound-includes --passthru-unknown-exprs
                            --passthru-comments --line-directive # --debug
                            -U QUICKCPPLIB_ENABLE_VALGRIND
                            -U DOXYGEN_SHOULD_SKIP_THIS -U DOXYGEN_IS_IN_THE_HOUSE
                            -U STANDARDESE_IS_IN_THE_HOUSE
                            WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
                            )
      if(NOT CMAKE_VERSION VERSION_LESS 3.3)
        add_dependencies(outcome_hl outcome_hl-pp)
      endif()
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
  foreach(feature ${CMAKE_CXX_COMPILE_FEATURES})
    if(feature STREQUAL cxx_std_17)
      foreach(test_target ${outcome_TEST_TARGETS} ${outcome_EXAMPLE_TARGETS})
        target_compile_features(${test_target} PUBLIC cxx_std_17)
        if(ENABLE_CXX_CONCEPTS)
          target_compile_options(${test_target} PUBLIC -fconcepts)
        endif()
      endforeach()
    endif()
  endforeach()

  # If we are on a compiler capable of it, add in a test of the WG21 proposed result implementation
  if(ENABLE_CXX_CONCEPTS)
    include(CheckCXXSourceCompiles)
    set(CMAKE_REQUIRED_FLAGS "-std=c++17")
    check_cxx_source_compiles("
template <class T> struct success
{
  using value_type = T;
  value_type value;
};
template <class T> success(T /*unused*/)->success<T>;
success()->success<void>;
int main() {
  auto v = success{5};
  return 0;
}
" CXX_HAS_TEMPLATE_DEDUCTION_GUIDES)
    if(CXX_HAS_TEMPLATE_DEDUCTION_GUIDES)
      add_executable(wg21-reference-result "test/tests/core-result.cpp")
      target_compile_features(wg21-reference-result PRIVATE cxx_std_17)
      target_compile_definitions(wg21-reference-result PRIVATE TESTING_WG21_EXPERIMENTAL_RESULT)
      target_compile_options(wg21-reference-result PRIVATE -fconcepts)
      set_target_properties(wg21-reference-result PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
      )
      add_test(NAME wg21-reference-result
        COMMAND $<TARGET_FILE:wg21-reference-result>
      )
    endif()
  endif()
endif()

# Cache this library's auto scanned sources for later reuse
include(QuickCppLibCacheLibrarySources)

# Make available this library for install and export
include(QuickCppLibMakeInstall)
include(QuickCppLibMakeExport)
