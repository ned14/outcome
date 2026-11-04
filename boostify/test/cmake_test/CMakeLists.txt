# Copyright 2021-2026 Alexander Grund
# Copyright 2015-2026 Niall Douglas <http://www.nedproductions.biz/>
#
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt
#
# Checked by the CMake lane of Boost.CI in two ways: with BOOST_CI_INSTALL_TEST=ON
# against an installed Boost, and with it OFF with the Boost source tree added as a
# subdirectory, which is how a consumer embedding Boost's sources uses the library.
# This exists because neither case is covered by the library's own test suite: it
# only proves that the headers are found, the target links and the program runs.

cmake_minimum_required(VERSION 3.5...3.16)

project(cmake_subdir_test LANGUAGES CXX)

if(BOOST_CI_INSTALL_TEST)
    find_package(boost_outcome REQUIRED)
else()
    set(BOOST_INCLUDE_LIBRARIES outcome)
    add_subdirectory(../../../.. deps/boost EXCLUDE_FROM_ALL)
endif()

add_executable(main main.cpp)
target_link_libraries(main Boost::outcome)

enable_testing()
add_test(NAME main COMMAND main)
