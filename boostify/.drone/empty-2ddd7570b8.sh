#!/bin/bash

set -ex
export TRAVIS_BUILD_DIR=$(pwd)
export DRONE_BUILD_DIR=$(pwd)
export TRAVIS_BRANCH=$DRONE_BRANCH
export VCS_COMMIT_ID=$DRONE_COMMIT
export GIT_COMMIT=$DRONE_COMMIT
export PATH=~/.local/bin:/usr/local/bin:$PATH

echo '==================================> BEFORE_INSTALL'

. .drone/before-install.sh

echo '==================================> INSTALL'



echo '==================================> BEFORE_SCRIPT'

. $DRONE_BUILD_DIR/.drone/before-script.sh

echo '==================================> SCRIPT'

if [ "$CXX" = "g++" ]; then FLAGS="$FLAGS toolset=gcc-6"; fi;
if [ "$CXX" = "clang++" ]; then FLAGS="$FLAGS toolset=clang-5.0 cxxflags=--std=c++14"; fi;
cd boost
./b2 headers
./b2 libs/outcome/test $FLAGS
rm -rf bin.v2/libs/outcome
rm -rf boost/libs/outcome

echo '==================================> AFTER_SUCCESS'

. $DRONE_BUILD_DIR/.drone/after-success.sh
