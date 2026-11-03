# The stage guards used by the ctest scripts .ci.cmake and .docs.cmake.
#
# These two functions were removed from those scripts and taken from
# quickcpplib instead, on the grounds that quickcpplib's development tree defines
# them in cmakelib/QuickCppLibUtils.cmake and one definition is better than
# three. That definition was never published: the quickcpplib that CI clones is
# upstream's default branch, whose QuickCppLibUtils.cmake has no require_ok() and
# no require_tests(). A ctest script that calls a function which does not exist
# aborts the moment it calls it, with
#
#   CMake Error at .ci.cmake:20 (require_ok):
#     Unknown CMake command "require_ok".
#
# which is how every unit-test job and the documentation job came to fail on all
# three platforms: not in configure, not in build, not in test, but at the first
# stage check after configure - so the job died before it ever reached the thing
# it exists to test. The message also names no error keyword, so the annotation
# step did not surface it and the run said nothing useful.
#
# Keeping the definitions here makes this repository's CI self-contained and
# means the same code path runs on a developer's machine and on a runner. They
# are deliberately unconditional: if the quickcpplib in use also defines them,
# these win, so that "works locally, fails in CI" cannot come back through this
# door. If quickcpplib's versions grow behaviour worth having, delete this file
# and include(QuickCppLibUtils) will supply them again - after they are actually
# upstream.

# Check one stage of a ctest script (.ci.cmake, .docs.cmake): there a failing
# ctest_configure()/ctest_build() only SETS its return variable, so an unchecked
# stage makes a broken build publish green (reviewer P0 r3:BC-01, r2:BC-01).
function(require_ok what rc)
  if(NOT "${rc}" STREQUAL "0")
    message(FATAL_ERROR "FATAL: ${what} failed (return value '${rc}')")
  endif()
endfunction()

# ctest_test() "succeeds" when it ran nothing, so require at least one test.
# ${ARGN} is the selection (e.g. -E <regex>) ctest_test() will apply; `ctest -N`
# alone counts every registered test (reviewer P0 r1:BC-1).
function(require_tests what)
  set(_cfg_args)
  if(DEFINED CTEST_CONFIGURATION_TYPE AND NOT "${CTEST_CONFIGURATION_TYPE}" STREQUAL "")
    set(_cfg_args -C "${CTEST_CONFIGURATION_TYPE}")
  endif()
  set(_sel_args ${_cfg_args} ${ARGN})
  execute_process(COMMAND ${CMAKE_CTEST_COMMAND} -N ${_sel_args}
                  WORKING_DIRECTORY "${CTEST_BINARY_DIRECTORY}"
                  OUTPUT_VARIABLE _list ERROR_QUIET RESULT_VARIABLE _rc)
  set(_n 0)
  if(_list MATCHES "Total Tests: ([0-9]+)")
    set(_n ${CMAKE_MATCH_1})
  endif()
  string(REPLACE ";" " " _cfg_str "${_sel_args}")
  if(NOT "${_rc}" STREQUAL "0" OR _n EQUAL 0)
    message(FATAL_ERROR "FATAL: ${what} has zero tests to run (ctest -N ${_cfg_str} reported ${_n}, rc '${_rc}')")
  endif()
  message(STATUS "${what}: ${_n} test(s) to run")
endfunction()
