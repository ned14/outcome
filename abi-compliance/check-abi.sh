#!/bin/sh
rm -rf abi_dumps/Outcome/test-gcc13-cxx17/binary_only.dump
rm -rf abi_dumps/Outcome/test-gcc13-cxx20/binary_only.dump
sh ./dump-abi.sh test || exit 1
cd abi_dumps/Outcome
tar xf $1.tar.bz2
cd ../..
RETCODE=0
abi-compliance-checker -l Outcome -old abi_dumps/Outcome/$1-gcc13-cxx17/binary_only.dump -new abi_dumps/Outcome/test-gcc13-cxx17/binary_only.dump || RETCODE=1
abi-compliance-checker -l Outcome -old abi_dumps/Outcome/$1-gcc13-cxx20/binary_only.dump -new abi_dumps/Outcome/test-gcc13-cxx20/binary_only.dump || RETCODE=1
exit $RETCODE
