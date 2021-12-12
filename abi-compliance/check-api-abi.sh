#!/bin/sh
sh ./dump-api-abi.sh test || exit 1
RETCODE=0
#abi-compliance-checker -l Outcome -old abi_dumps/Outcome/$1-gcc7-cxx14/ABI.dump -new abi_dumps/Outcome/X/ABI.dump || RETCODE=1
abi-compliance-checker -l Outcome -old abi_dumps/Outcome/$1-gcc9-cxx17/ABI.dump -new abi_dumps/Outcome/X/ABI.dump || RETCODE=1
exit $RETCODE
