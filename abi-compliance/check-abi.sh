#!/bin/sh
rm -rf abi_dumps/Outcome/test-gcc7-cxx14/binary_only.dump
rm -rf abi_dumps/Outcome/test-gcc9-cxx17/binary_only.dump
sh ./dump-abi.sh test || exit 1
RETCODE=0
abi-compliance-checker -l Outcome -old abi_dumps/Outcome/$1-gcc7-cxx14/binary_only.dump -new abi_dumps/Outcome/test-gcc7-cxx14/binary_only.dump || RETCODE=1
abi-compliance-checker -l Outcome -old abi_dumps/Outcome/$1-gcc9-cxx17/binary_only.dump -new abi_dumps/Outcome/test-gcc9-cxx17/binary_only.dump || RETCODE=1
exit $RETCODE
