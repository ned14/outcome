# CTest script for a CI to submit to CDash a documentation generation run
cmake_minimum_required(VERSION 3.10...4.0 FATAL_ERROR)
include(cmake/QuickCppLibBootstrap.cmake)
include(QuickCppLibUtils)


# require_ok() lives in cmake/QuickCppLibCiGuards.cmake, not in quickcpplib: this
# job PUBLISHES the documentation site, so an unchecked configure or snippet
# build would be a green Documentation job with a published broken site
# (reviewer P0 .docs.cmake:24), and the quickcpplib that CI clones does not
# define the function at all. See that file.
include("${CMAKE_CURRENT_LIST_DIR}/cmake/QuickCppLibCiGuards.cmake")

CONFIGURE_CTEST_SCRIPT_FOR_CDASH("outcome" "cmake_ci")
ctest_empty_binary_directory(${CTEST_BINARY_DIRECTORY})
include(FindGit)
set(CTEST_GIT_COMMAND "${GIT_EXECUTABLE}")
find_program(HUGO_EXECUTABLE "hugo")
if(NOT HUGO_EXECUTABLE)
  # Without hugo the site rebuild below is the only thing standing between a
  # green job and an unchanged gh-pages; say so instead of failing obscurely.
  message(FATAL_ERROR "FATAL: hugo was not found, so the documentation site cannot be rebuilt")
endif()
#checked_execute_process("git reset"
#  COMMAND "${GIT_EXECUTABLE}" checkout gh-pages
#  COMMAND "${GIT_EXECUTABLE}" reset --hard ae7119571a3c81cb9a683a21f2759df1d742e998
#  WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/doc/html"
#)

ctest_start("Documentation")
# Update.xml is a CDash nicety, not a gate; the checkout has already pinned the
# revision. Report where the update got to rather than leaving CTest's bare
# "Update command failed" in the log, where it reads like a second failure.
ctest_update(RETURN_VALUE update_ret)
if(NOT "${update_ret}" STREQUAL "0")
  message(STATUS "ctest_update() could not refresh from the remote (return '${update_ret}'), so the checked-out revision is what gets built")
endif()
checked_execute_process("git reset"
  COMMAND "${GIT_EXECUTABLE}" checkout gh-pages
  WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/doc/html"
)
ctest_configure(RETURN_VALUE configure_ret)
require_ok("configure" "${configure_ret}")
ctest_build(TARGET outcome-snippets RETURN_VALUE snippets_ret)
require_ok("build of outcome-snippets" "${snippets_ret}")
#checked_execute_process("git commit"
#  COMMAND "${GIT_EXECUTABLE}" commit -a -m "upd"
#  COMMAND "${GIT_EXECUTABLE}" push -f origin gh-pages
#  WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/doc/html"
#)
checked_execute_process("rebuild docs"
  COMMAND "${HUGO_EXECUTABLE}"
  WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/doc/src"
)
# Uploading to CDash is reporting, not gating: the site has already been rebuilt
# above, and a CDash outage must not fail a documentation run that succeeded.
ctest_submit(CAPTURE_CMAKE_ERROR submit_err)
if(NOT "${submit_err}" STREQUAL "0")
  message(STATUS "ctest_submit() could not upload the results to CDash (return '${submit_err}')")
endif()
