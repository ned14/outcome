# CTest script for a CI to submit to CDash a documentation generation run
cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
# Bring in the Boost lite cmake tooling
list(FIND CMAKE_MODULE_PATH "boost-lite" boost_lite_idx)
if(${boost_lite_idx} EQUAL -1)
  if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/../boost-lite/cmake")
    set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/../boost-lite/cmake")
    set(CTEST_BOOSTLITE_SCRIPTS "${CMAKE_CURRENT_SOURCE_DIR}/../boost-lite/scripts")
  elseif(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/include/boost/outcome/boost-lite/cmake")
    set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/include/boost/outcome/boost-lite/cmake")
    set(CTEST_BOOSTLITE_SCRIPTS "${CMAKE_CURRENT_SOURCE_DIR}/include/boost/outcome/boost-lite/scripts")
  else()
    message(FATAL_ERROR "FATAL: A copy of boost-lite cannot be found. Try running 'git submodule update --init --recursive'")
  endif()
endif()
include(BoostLiteUtils)


CONFIGURE_CTEST_SCRIPT_FOR_CDASH("outcome" "cmake_ci")
ctest_empty_binary_directory(${CTEST_BINARY_DIRECTORY})
include(FindGit)
#checked_execute_process("git reset"
#  COMMAND "${GIT_EXECUTABLE}" checkout gh-pages
#  COMMAND "${GIT_EXECUTABLE}" reset --hard ae7119571a3c81cb9a683a21f2759df1d742e998
#  WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/doc/html"
#)

ctest_start("Documentation")
ctest_configure()
ctest_build(TARGET outcome_docs)
#checked_execute_process("git commit"
#  COMMAND "${GIT_EXECUTABLE}" commit -a -m "upd"
#  COMMAND "${GIT_EXECUTABLE}" push -f origin gh-pages
#  WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/doc/html"
#)
ctest_submit()
