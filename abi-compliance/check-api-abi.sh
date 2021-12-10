#!/bin/sh
sh ./dump-api-abi.sh test || exit 1
abi-compliance-checker -l Outcome -old abi_dumps/Outcome/$1-gcc7-cxx14/ABI.dump -new abi_dumps/Outcome/X/ABI.dump
