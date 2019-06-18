# Outcome cmake
# (C) 2016-2019 Niall Douglas <http://www.nedproductions.biz/>
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

cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
# If necessary bring in the quickcpplib cmake tooling
set(quickcpplib_done OFF)
foreach(item ${CMAKE_MODULE_PATH})
  if(item MATCHES "quickcpplib/cmakelib")
    set(quickcpplib_done ON)
  endif()
endforeach()
if(NOT quickcpplib_done)
  # CMAKE_SOURCE_DIR is the very topmost parent cmake project
  # CMAKE_CURRENT_SOURCE_DIR is the current cmake subproject
  
  # If there is a magic .quickcpplib_use_siblings directory above the topmost project, use sibling edition
  if(EXISTS "${CMAKE_SOURCE_DIR}/../.quickcpplib_use_siblings")
    set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/../quickcpplib/cmakelib")
    set(CTEST_QUICKCPPLIB_SCRIPTS "${CMAKE_SOURCE_DIR}/../quickcpplib/scripts")
  elseif(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/../.quickcpplib_use_siblings")
    set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/../quickcpplib/cmakelib")
    set(CTEST_QUICKCPPLIB_SCRIPTS "${CMAKE_CURRENT_SOURCE_DIR}/../quickcpplib/scripts")
  elseif(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/.gitmodules")
    # Read in .gitmodules and look for myself
    file(READ "${CMAKE_CURRENT_SOURCE_DIR}/.gitmodules" GITMODULESCONTENTS)
    if(GITMODULESCONTENTS MATCHES ".*\\n?\\[submodule \"([^\"]+\\/quickcpplib)\"\\]")
      set(quickcpplibpath "${CMAKE_MATCH_1}")
      if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${quickcpplibpath}/cmake")
        set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/${quickcpplibpath}/cmakelib")
        set(CTEST_QUICKCPPLIB_SCRIPTS "${CMAKE_CURRENT_SOURCE_DIR}/${quickcpplibpath}/scripts")
      else()
        message(WARNING "WARNING: ${quickcpplibpath}/cmake does not exist, attempting git submodule update --init --recursive ...")
        include(FindGit)
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
          WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
        )
        if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/${quickcpplibpath}/cmake")
          set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/${quickcpplibpath}/cmakelib")
          set(CTEST_QUICKCPPLIB_SCRIPTS "${CMAKE_CURRENT_SOURCE_DIR}/${quickcpplibpath}/scripts")
        else()
          message(FATAL_ERROR "FATAL: ${quickcpplibpath}/cmake does not exist and git submodule update --init --recursive did not make it available, bailing out")
        endif()
      endif()
    else()
      message(FATAL_ERROR "FATAL: A copy of quickcpplib cannot be found, and cannot find a quickcpplib submodule in this git repository")
    endif()
  else()
    message(FATAL_ERROR "FATAL: A copy of quickcpplib cannot be found, and there are no git submodules to search")
  endif()
endif()
message(STATUS "CMAKE_MODULE_PATH = ${CMAKE_MODULE_PATH}")
