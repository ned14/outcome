# CTest script for a CI to submit to CDash a run of configuration,
# building and testing
cmake_minimum_required(VERSION 3.10...4.0 FATAL_ERROR)
include(cmake/QuickCppLibBootstrap.cmake)
include(QuickCppLibUtils)
# require_ok() and require_tests(): unchecked stages would turn a broken
# configure/build/test into a green job (reviewer findings r4:BC1, r5:BC-1,
# r9:BC-1). They live in this repository rather than in quickcpplib, because the
# quickcpplib these jobs clone does not define them - see that file for the
# failure that cost.
include("${CMAKE_CURRENT_LIST_DIR}/cmake/QuickCppLibCiGuards.cmake")

# CONFIGURE_CTEST_SCRIPT_FOR_CDASH() searches for a program named "python" and
# nothing else, and the runners ship python3 only, so the junit merge below ran
# "CTEST_PYTHON_COMMAND-NOTFOUND": it reported "no such file or directory", no
# merged_junit_results.xml was ever written, and the job which publishes it had
# nothing to publish. Setting the variable first wins, because find_program()
# does nothing when its cache entry already holds a path.
find_program(CTEST_PYTHON_COMMAND NAMES python3 python)
if(NOT CTEST_PYTHON_COMMAND)
  message(FATAL_ERROR "FATAL: no python interpreter was found, so the junit results cannot be merged into the artefact CI publishes")
endif()

CONFIGURE_CTEST_SCRIPT_FOR_CDASH("outcome" "prebuilt")
list(APPEND CTEST_CONFIGURE_OPTIONS -DCMAKE_BUILD_TYPE=${CTEST_CONFIGURATION_TYPE})
ctest_empty_binary_directory(${CTEST_BINARY_DIRECTORY})
include(FindGit)
set(CTEST_GIT_COMMAND "${GIT_EXECUTABLE}")

ctest_start("Experimental")
# Update.xml is a CDash nicety, not a gate: the checkout has already pinned the
# revision to build. Report where the update got to instead of leaving CTest's
# bare "Update command failed" in the log, where it reads like a second, fatal
# failure.
ctest_update(RETURN_VALUE update_ret)
if(NOT "${update_ret}" STREQUAL "0")
  message(STATUS "ctest_update() could not refresh from the remote (return '${update_ret}'), so the checked-out revision is what gets built")
endif()
ctest_configure(OPTIONS "${CTEST_CONFIGURE_OPTIONS}" RETURN_VALUE configure_ret)
require_ok("configure" "${configure_ret}")
ctest_build(TARGET _hl RETURN_VALUE build_ret)
require_ok("build of _hl" "${build_ret}")
# The C ABI link tests are executables in their own right, not dependencies of
# _hl, so building _hl alone left all four of them unbuilt and ctest reported
# them "Not Run" - four red tests for a build that never happened.
ctest_build(TARGET outcome-link-tests RETURN_VALUE link_build_ret)
require_ok("build of outcome-link-tests" "${link_build_ret}")
if(NOT WIN32 AND NOT APPLE)
  ctest_build(TARGET outcome-snippets RETURN_VALUE snippets_ret)
  require_ok("build of outcome-snippets" "${snippets_ret}")
endif()
require_tests("default test stage")
ctest_test(RETURN_VALUE retval)
set(retval2 0)
set(retval3 0)
# The sanitizer configurations have their own target tree and their own
# CTEST_CONFIGURATION_TYPE; that is deliberate. What is not acceptable is
# running them unbuilt, or "passing" because they ran nothing.
if(("$ENV{CXX}" MATCHES "clang"))
  ctest_build(TARGET _hl-asan RETURN_VALUE asan_build_ret)
  require_ok("build of _hl-asan" "${asan_build_ret}")
  set(CTEST_CONFIGURATION_TYPE "asan")
  require_tests("asan test stage")
  ctest_test(RETURN_VALUE retval2)
  ctest_build(TARGET _hl-ubsan RETURN_VALUE ubsan_build_ret)
  require_ok("build of _hl-ubsan" "${ubsan_build_ret}")
  set(CTEST_CONFIGURATION_TYPE "ubsan")
  require_tests("ubsan test stage")
  ctest_test(RETURN_VALUE retval3)
endif()
# The gate on the test results comes before the CDash upload, because a failing
# ctest_submit() aborts the rest of the script: with the upload first, a CDash
# outage would skip this check and a failed suite would report green.
# The junit artefact is written BEFORE the gate below, because a failing suite must
# still publish its results: FATAL_ERROR ends the script, so a merge after the gate
# only ever runs on success and the publishing job has nothing to read exactly when
# it matters.
merge_junit_results_into_ctest_xml()
if(NOT retval EQUAL 0 OR NOT retval2 EQUAL 0 OR NOT retval3 EQUAL 0)
  # Name what did not pass, not just the number that did. ctest_test() returns -1,
  # not a count, when a test was "Not Run" - a test whose executable was never
  # built, or whose REQUIRED_FILES is not there - and the job log which says which
  # one is unreachable from here, so "exited with -1" was all the Windows lane could
  # say. LastTestsFailed holds the names, numbered by test index, failures and
  # not-run entries alike; the file is tag-suffixed in script mode.
  file(GLOB failed_test_logs "${CTEST_BINARY_DIRECTORY}/Testing/Temporary/LastTestsFailed*.log")
  list(SORT failed_test_logs)
  if(failed_test_logs)
    list(GET failed_test_logs -1 newest_failed_log)
    file(STRINGS "${newest_failed_log}" failed_tests)
    list(LENGTH failed_tests failed_count)
    # One line, complete: an annotation budget of ten is spent quickly and the
    # names are the whole point of this.
    string(REPLACE ";" ", " failed_test_names "${failed_tests}")
    message("NOT PASSED: ${failed_count} test(s) of the last stage - ${failed_test_names}")
  else()
    message("NOT PASSED: ctest wrote no LastTestsFailed log, so it did not get as far as running the tests")
  endif()
  message(FATAL_ERROR "FATAL: Running tests exited with ${retval} ${retval2} ${retval3}")
endif()
#ctest_upload(FILES )
# Uploading to CDash is reporting, not gating: it must not be able to turn a
# green test run red, and it must not be able to hide the check above. The
# junit artefact CI publishes is written by the merge above, not by the upload.
ctest_submit(CAPTURE_CMAKE_ERROR submit_err)
if(NOT "${submit_err}" STREQUAL "0")
  message(STATUS "ctest_submit() could not upload the results to CDash (return '${submit_err}'); the tests above are what decides this job")
endif()
