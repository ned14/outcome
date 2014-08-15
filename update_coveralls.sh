#!/bin/bash -x
# Adapted from https://github.com/purpleKarrot/Karrot/blob/develop/test/coveralls.in
# which itself was adapted from https://github.com/berenm/cmake-extra/blob/master/coveralls-upload.in

if [ "$1" = "" ]; then
  echo Your forgot the source directory parameter!
  exit 1
fi

if [ 0 -eq $(find -iname *.gcda | wc -l) ]
then
  exit 0
fi

gcov-4.8 --source-prefix $1 --preserve-paths --relative-only $(find -iname *.gcda) 1>/dev/null || exit 0

#env
cat >coverage.json <<EOF
{
  "service_name": "jenkins",
  "service_number": "${BUILD_NUMBER}",
  "service_build_url": "${BUILD_URL}",
  "service_branch": "${GIT_BRANCH}",
#  "service_pull_request", "",
  "repo_token": "${COVERALLS_REPO_TOKEN}",
  "run_at": "$(date --iso-8601=s)",
  "source_files": [
EOF

for file in $(find * -iname '*.gcov' -print | egrep 'spinlock' )
#| egrep -v 'valgrind|SpookyV2')
do
  cat >>coverage.json <<EOF
    {
      "name": "$(echo ${file} | sed -re 's%#%\/%g; s%.gcov$%%')",
      "source": $(tail -n +3 ${file} | cut -d ':' -f 3- | python json_encode.py),
      "coverage": [$(tail -n +3 ${file} | cut -d ':' -f 1 | sed -re 's%^ +%%g; s%-%null%g; s%^[#=]+$%0%;' | tr $'\n' ',' | sed -re 's%,$%%')]
    },
EOF
done

#cat coverage.json
mv coverage.json coverage.json.tmp
cat >coverage.json <(head -n -1 coverage.json.tmp) <(echo -e "    }\n  ]\n}")
rm *.gcov coverage.json.tmp

head coverage.json
#echo
curl -F json_file=@coverage.json https://coveralls.io/api/v1/jobs
#head coverage.json
