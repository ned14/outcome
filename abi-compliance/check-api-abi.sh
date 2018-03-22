#!/bin/sh
sh ./dump-api-abi.sh || exit 1
abi-compliance-checker -l Outcome -old $1 -new abi_dumps/Outcome/X/ABI.dump
