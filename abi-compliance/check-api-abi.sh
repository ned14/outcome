#!/bin/sh
sh ./dump-api-abi.sh test || exit 1
cd abi_dumps/Outcome
tar xf $1.tar.bz2
cd ../..
RETCODE=0
#abi-compliance-checker -l Outcome -old abi_dumps/Outcome/$1-gcc7-cxx14/ABI.dump -new abi_dumps/Outcome/X/ABI.dump || RETCODE=1
abi-compliance-checker -l Outcome -old abi_dumps/Outcome/$1-gcc9-cxx17/ABI.dump -new abi_dumps/Outcome/X/ABI.dump || RETCODE=1
exit $RETCODE
