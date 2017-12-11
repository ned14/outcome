#!/usr/bin/python
# Munges the output from Standardese to generate the reference API
# docs in the Outcome website
# (C) 2017 Niall Douglas http://www.nedprod.com/
# Created: Dec 2017

from __future__ import print_function
import os, subprocess, shutil

items = {
    'doc_outcome.md' : ("outcome<R, S, P>", 10, ''),
    'doc_result.md' : ("result<R, S>", 20, ''),
    'doc_try.md' : ("Try operations", 30, ''),
    'doc_success_failure.md' : ("Success/Failure", 40, ''),
    'doc_utils.md' : ("Utilities", 50, ''),
    'doc_convert.md' : ("Interoperation", 60, ''),
    'doc_bad_access.md' : ("Exceptions", 70, ''),
    'doc_iostream_support.md' : ("iostream support", 80, ''),
    'doc_result_h.md' : ("C API", 90, ''),

    'doc_all_narrow.md' : ("All narrow (hard UB)", 10, 'policies'),
    'doc_outcome_error_code_throw_as_system_error.md' : ("error_code throw as system_error (Outcome)", 20, 'policies'),
    'doc_result_error_code_throw_as_system_error.md' : ("error_code throw as system_error (Result)", 30, 'policies'),
    'doc_outcome_exception_ptr_rethrow.md' : ("exception_ptr rethrow (Outcome)", 40, 'policies'),
    'doc_result_exception_ptr_rethrow.md' : ("exception_ptr rethrow (Result)", 50, 'policies'),
    'doc_terminate.md' : ("Termimate", 60, 'policies'),
    'doc_throw_bad_result_access.md' : ("Throw bad_result_access", 70, 'policies'),
}

replacements = {
    'detail::result_final' : 'result_or_outcome',
}

def title(item):
    return items[item][0]

def weight(item):
    return str(items[item][1])

def section(item):
    return items[item][2]

def which(program):
    def is_exe(fpath):
        return os.path.exists(fpath) and os.access(fpath, os.X_OK) and os.path.isfile(fpath)

    def ext_candidates(fpath):
        yield fpath
        for ext in os.environ.get("PATHEXT", "").split(os.pathsep):
            yield fpath + ext

    fpath, fname = os.path.split(program)
    if fpath:
        if is_exe(program):
            return program
    else:
        for path in os.environ["PATH"].split(os.pathsep):
            exe_file = os.path.join(path, program)
            for candidate in ext_candidates(exe_file):
                if is_exe(candidate):
                    return candidate

    return None
os.chdir(os.path.dirname(__file__))
standardese_path = which('standardese')
if standardese_path is None and os.path.exists('../standardese'):
    standardese_path = os.path.abspath('../standardese')
shutil.rmtree("doc/src/content/reference")
os.makedirs("doc/src/content/reference/policies")
os.chdir("doc/src/content/reference")
args = [standardese_path, '-D', '_cpp_exceptions=1', '-D', 'STANDARDESE_IS_IN_THE_HOUSE=1',
  '--input.blacklist_namespace', 'detail',
  '--input.require_comment=0',
  '--output.format=commonmark_html',
  '--output.entity_index_order=namespace_external',
  '-I../../../../include/outcome', '-I../../../../..',
  '../../../../include/outcome/bad_access.hpp',
  '../../../../include/outcome/convert.hpp',
  '../../../../include/outcome/iostream_support.hpp',
  '../../../../include/outcome/outcome.hpp',
  '../../../../include/outcome/result.h',
  '../../../../include/outcome/result.hpp',
  '../../../../include/outcome/success_failure.hpp',
  '../../../../include/outcome/try.hpp',
  '../../../../include/outcome/utils.hpp'
]
args += ['../../../../include/outcome/policy/' + x for x in os.listdir('../../../../include/outcome/policy')]
print(args)
subprocess.check_call(args)

# Every doc_* file needs front matter
docs = {}
for item in os.listdir('.'):
    if item.startswith('doc_'):
        if item == 'doc_common.md': continue
        doc = os.path.join(section(item), item[4:])
        with open(doc, 'wt') as oh:
            with open(item, 'rt') as ih:
                oh.write(r'''+++
title = "''' + title(item) + r'''"
weight = ''' + weight(item) + r'''
+++
''')
                contents = ih.read()
                contents = contents.replace(item, '')
                for replacement in replacements:
                    contents = contents.replace(replacement, replacements[replacement])
                oh.write(contents)
        docs[item] = doc
        os.remove(item)
# Write an index
with open('_index.md', 'wt') as oh:
    with open('standardese_entities.md', 'rt') as ih:
        oh.write(r'''+++
title = "API reference"
weight = 20
+++
''')
        contents = ih.read()
        for doc in docs:
            contents = contents.replace(doc, docs[doc][:-3])
            for replacement in replacements:
                contents = contents.replace(replacement, replacements[replacement])
        oh.write(contents)
with open('policies/_index.md', 'wt') as oh:
    oh.write(r'''+++
title = "Policies"
weight = 100
+++
{{% children description="false" depth="1" %}}
''')
os.remove('standardese_entities.md')
os.remove('standardese_files.md')
os.remove('standardese_modules.md')
