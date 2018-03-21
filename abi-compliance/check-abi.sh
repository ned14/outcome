#!/bin/sh
rm -rf test.dump
./dump-abi.sh || exit 1
abi-compliance-checker -l Outcome -old $1 -new test.dump
