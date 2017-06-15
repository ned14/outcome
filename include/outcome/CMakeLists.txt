cmake_minimum_required(VERSION 3.1)
add_executable(test_outcome 
  error_code_extended.hpp
  result.hpp
  outcome.hpp
  test.cpp
)
target_compile_features(test_outcome PUBLIC cxx_std_14)
