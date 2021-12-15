cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

if(NOT DEFINED LABEL)
  set(LABEL default)
endif()

project(outcome-abi-test VERSION 1.0 LANGUAGES CXX)
set(OUTCOME_FORCE_ENABLE_PP_TARGETS TRUE)
add_subdirectory(.. outcome EXCLUDE_FROM_ALL)

add_library(outcome-abi-lib-${LABEL} SHARED "src/main.cpp")
target_link_libraries(outcome-abi-lib-${LABEL} PUBLIC outcome::hl)
add_dependencies(outcome-abi-lib-${LABEL} outcome_hl-pp-std)
target_compile_definitions(outcome-abi-lib-${LABEL} PUBLIC OUTCOME_DISABLE_ABI_PERMUTATION=1)
if(NOT MSVC)
  target_compile_options(outcome-abi-lib-${LABEL} PUBLIC -Og)
endif()
