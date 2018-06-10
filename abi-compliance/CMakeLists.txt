cmake_minimum_required(VERSION 3.1 FATAL_ERROR)

project(outcome-abi-test VERSION 1.0 LANGUAGES CXX)
add_subdirectory(.. outcome EXCLUDE_FROM_ALL)

add_library(outcome-abi-lib SHARED "src/main.cpp")
target_link_libraries(outcome-abi-lib PUBLIC outcome::hl)

# Hack for sibling config
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/../../.quickcpplib_use_siblings")
  target_include_directories(outcome-abi-lib PRIVATE "../..")
  target_include_directories(outcome-abi-lib PRIVATE "../../.quickcpplib_use_siblings")
  target_include_directories(outcome-abi-lib PRIVATE "../../.quickcpplib_use_siblings/a")
  target_include_directories(outcome-abi-lib PRIVATE "../../.quickcpplib_use_siblings/a/a")
endif()
