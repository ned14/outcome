#!/bin/bash

if [ "$DRONE_JOB_UUID" = "b6589fc6ab" ] ; then
    if [ ! -f "boost/bootstrap.sh" ]; then wget -O boost.tar.bz2 https://dl.bintray.com/boostorg/release/1.71.0/source/boost_1_71_0.tar.bz2; tar xf boost.tar.bz2 -C boost; mv boost/boost_1_71_0 .; rm -rf boost; mv boost_1_71_0 boost; ls -l; ls -l boost; cd boost; ./bootstrap.sh; cd ..; fi;
    rm -rf bin.v2/libs/outcome
    rm -rf boost/boost/outcome
    rm -rf boost/libs/outcome
    ln -s ../.. boost/libs/outcome
    ls -l boost/libs/outcome/
fi

