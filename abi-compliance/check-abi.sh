#!/bin/sh
rm -rf abi_dumps/Outcome/test/binary_only.dump
sh ./dump-abi.sh test || exit 1
abi-compliance-checker -l Outcome -old abi_dumps/Outcome/$1-gcc7-cxx14/binary_only.dump -new abi_dumps/Outcome/test-gcc7-cxx14/binary_only.dump
