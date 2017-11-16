# CTest script for a CI to submit to CDash a documentation generation run
cmake_minimum_required(VERSION 3.1 FATAL_ERROR)
include(cmake/QuickCppLibBootstrap.cmake)
include(QuickCppLibUtils)


CONFIGURE_CTEST_SCRIPT_FOR_CDASH("outcome" "cmake_ci")
ctest_empty_binary_directory(${CTEST_BINARY_DIRECTORY})
include(FindGit)
set(CTEST_GIT_COMMAND "${GIT_EXECUTABLE}")
find_program(HUGO_EXECUTABLE "hugo")
#checked_execute_process("git reset"
#  COMMAND "${GIT_EXECUTABLE}" checkout gh-pages
#  COMMAND "${GIT_EXECUTABLE}" reset --hard ae7119571a3c81cb9a683a21f2759df1d742e998
#  WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/doc/html"
#)

ctest_start("Documentation")
ctest_update()
checked_execute_process("git reset"
  COMMAND "${GIT_EXECUTABLE}" checkout gh-pages
  WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/doc/html"
)
ctest_configure()
ctest_build(TARGET outcome-snippets)
#checked_execute_process("git commit"
#  COMMAND "${GIT_EXECUTABLE}" commit -a -m "upd"
#  COMMAND "${GIT_EXECUTABLE}" push -f origin gh-pages
#  WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/doc/html"
#)
checked_execute_process("rebuild docs"
  COMMAND "${HUGO_EXECUTABLE}"
  WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/doc/src"
)
ctest_submit()
