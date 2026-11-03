#!/bin/bash
# ABI stability gate (libabigail).
#
# abidiff's exit status is a BIT MASK, not an error number
# (/usr/include/libabigail/abg-tools-utils.h):
#
#   0  ABIDIFF_OK                        no ABI change at all
#   1  ABIDIFF_ERROR                     the comparison itself failed
#   2  ABIDIFF_USAGE_ERROR               bad command line
#   4  ABIDIFF_ABI_CHANGE                a COMPATIBLE ABI change - allowed here
#   8  ABIDIFF_ABI_INCOMPATIBLE_CHANGE   the break this gate exists to catch
#
# Only the compatible-change bit is ignored. The mask is spelled out below
# instead of being written as a bare `& 11`, because an unexplained magic
# number reads as "errors are masked" to anyone auditing this file (reviewer
# finding r1:bc-11 concluded exactly that; the mask is in fact deliberate).
set -u

REF=${1:?usage: check-abigail.sh <reference-dump-tag>}

# Bits that must fail the gate: ERROR | USAGE_ERROR | INCOMPATIBLE_CHANGE.
ABIDIFF_GATE_MASK=11
# The one bit that must NOT: a compatible change.
ABIDIFF_COMPATIBLE=4

rm -f abi_dumps/Outcome/test-gcc13-cxx17/abigail.xml
rm -f abi_dumps/Outcome/test-gcc13-cxx20/abigail.xml
sh ./dump-abigail.sh test || exit 1
cd abi_dumps/Outcome || exit 1
tar xf "${REF}.tar.bz2" || exit 1
cd ../.. || exit 1

RETCODE=0

check_one() {
  local std=$1
  abidiff --stats --deleted-fns --changed-fns --deleted-vars --changed-vars \
    "abi_dumps/Outcome/${REF}-gcc13-${std}/abigail.xml" \
    "abi_dumps/Outcome/test-gcc13-${std}/abigail.xml"
  local rc=$?
  local gating=$((rc & ABIDIFF_GATE_MASK))
  if [ "${gating}" -ne 0 ]; then
    echo "ABI check FAILED for ${std}: abidiff exit ${rc}, gating bits ${gating}"
    RETCODE=1
  elif [ "${rc}" -ne 0 ]; then
    echo "ABI check OK for ${std}: abidiff exit ${rc} (compatible changes only, bit ${ABIDIFF_COMPATIBLE})"
  else
    echo "ABI check OK for ${std}: no ABI change"
  fi
}

check_one cxx17
check_one cxx20
echo "Check returns ${RETCODE}"
exit ${RETCODE}
