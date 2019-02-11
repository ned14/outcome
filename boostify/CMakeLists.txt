# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at https://www.boost.org/LICENSE_1_0.txt

cmake_minimum_required(VERSION 3.5)
project(BoostOutcome LANGUAGES CXX)

add_library(boost_outcome INTERFACE)
add_library(Boost::outcome ALIAS boost_outcome)

target_include_directories(boost_outcome PUBLIC include)

target_link_libraries(boost_outcome PUBLIC
  Boost::config
  Boost::exception
  Boost::system
)
