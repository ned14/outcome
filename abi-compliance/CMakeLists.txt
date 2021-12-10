cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

project(outcome-abi-test VERSION 1.0 LANGUAGES CXX)
set(OUTCOME_FORCE_ENABLE_PP_TARGETS TRUE)
add_subdirectory(.. outcome EXCLUDE_FROM_ALL)

add_library(outcome-abi-lib-${LABEL} SHARED "src/main.cpp")
target_link_libraries(outcome-abi-lib-${LABEL} PUBLIC outcome::hl)
add_dependencies(outcome-abi-lib-${LABEL} outcome_hl-pp-abi)
