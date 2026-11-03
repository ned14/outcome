# Outcome cmake
# (C) 2016-2024 Niall Douglas <http://www.nedproductions.biz/>
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

cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

set(outcome_LINK_TARGETS)
foreach(type STATIC SHARED)
  foreach(visibility default hidden)
    set(target outcome-link-test-c-result-type_${type}-vis_${visibility})
    add_library(${target}-lib ${type}
      "experimental-c-result/lib.c"
      "experimental-c-result/lib.cpp")
    target_compile_definitions(${target}-lib PRIVATE MYLIB_SOURCE=1)
    set_target_properties(${target}-lib PROPERTIES
      RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
      POSITION_INDEPENDENT_CODE ON
      C_VISIBILITY_PRESET "${visibility}"
      CXX_VISIBILITY_PRESET "${visibility}"
      DISABLE_PRECOMPILE_HEADERS On
    )
    target_link_libraries(${target}-lib PRIVATE outcome::hl)
    list(APPEND outcome_LINK_TARGETS ${target}-lib)

    add_executable(${target} "experimental-c-result/main.c")
    set_target_properties(${target} PROPERTIES
      RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
      POSITION_INDEPENDENT_CODE ON
      C_VISIBILITY_PRESET "${visibility}"
      CXX_VISIBILITY_PRESET "${visibility}"
      DISABLE_PRECOMPILE_HEADERS On
    )
    target_link_libraries(${target} PRIVATE ${target}-lib outcome::hl)
    # These executables assert the library's behaviour AT RUNTIME (main.c aborts
    # on a wrong result). Nothing used to run them - they were only linked - so
    # their assertions were dead and a broken C ABI still produced a green build.
    add_test(NAME ${target} COMMAND $<TARGET_FILE:${target}>)
    if(target MATCHES ".*-type_SHARED-vis_hidden" OR (WIN32 AND target MATCHES ".*-type_SHARED.*"))
      # The shared library won't export the C++ helper machinery if visibility is hidden,
      # so without including a copy of the C++ helpers it would correctly fail to link.
      add_library(${target}-cxx-helpers OBJECT "experimental-c-result/lib.cpp")
      target_link_libraries(${target}-cxx-helpers PRIVATE outcome::hl)
      target_link_libraries(${target} PRIVATE ${target}-cxx-helpers)
    endif()
    list(APPEND outcome_LINK_TARGETS ${target})
  endforeach()
endforeach()

# One target to build them all. These arrow at the C ABI from C, so they are not
# dependencies of _hl (which is the C++ test tree), and a CI that builds only
# _hl leaves all four executables missing - ctest then reports them "Not Run",
# which reads like four failures and is really a build that never happened.
add_custom_target(outcome-link-tests COMMENT "Building all link tests ...")
add_dependencies(outcome-link-tests ${outcome_LINK_TARGETS})
