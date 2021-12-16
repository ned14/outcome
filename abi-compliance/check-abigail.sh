#!/bin/bash
rm -rf abi_dumps/Outcome/test-gcc7-cxx14/abigail.xml
rm -rf abi_dumps/Outcome/test-gcc9-cxx17/abigail.xml
sh ./dump-abigail.sh test || exit 1
cd abi_dumps/Outcome
tar xf $1.tar.bz2
cd ../..
RETCODE=0
abidiff --stats --deleted-fns --changed-fns --deleted-vars --changed-vars abi_dumps/Outcome/$1-gcc7-cxx14/abigail.xml abi_dumps/Outcome/test-gcc7-cxx14/abigail.xml 
(( RETCODE=$RETCODE || ($? & 11) ))
echo Check returns $RETCODE
abidiff --stats --deleted-fns --changed-fns --deleted-vars --changed-vars abi_dumps/Outcome/$1-gcc9-cxx17/abigail.xml abi_dumps/Outcome/test-gcc9-cxx17/abigail.xml 
(( RETCODE=$RETCODE || ($? & 11) ))
echo Check returns $RETCODE
exit $RETCODE
