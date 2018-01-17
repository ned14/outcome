#!/usr/bin/python
# -*- coding: utf-8 -*-
#
# Munges the output from Standardese to generate the reference API
# docs in the Outcome website
# (C) 2017 Niall Douglas http://www.nedprod.com/
# Created: Dec 2017

from __future__ import print_function
import os, subprocess, shutil, re, sys

items = {
    'doc_outcome.md' : ("outcome<R, S, P>", 10, ''),
    'doc_result.md' : ("result<R, S>", 20, ''),
    'doc_try.md' : ("Try operations", 30, ''),
    'doc_success_failure.md' : ("Success/Failure", 40, ''),
    'doc_utils.md' : ("Utilities", 50, ''),
    'doc_convert.md' : ("Interoperation", 60, ''),
    'doc_bad_access.md' : ("Exceptions", 70, ''),
    'doc_iostream_support.md' : ("iostream support", 80, ''),
    'doc_result_c.md' : ("C API", 90, ''),
    
    'doc_common.md' : None,
    'doc_outcome_exception_observers.md' : None,
    'doc_outcome_exception_observers_impl.md' : None,
    'doc_outcome_failure_observers.md' : None,
    'doc_result_error_observers.md' : None,
    'doc_result_final.md' : None,
    'doc_result_storage.md' : None,
    'doc_result_value_observers.md' : None,
    'doc_value_storage.md' : None,

    'doc_all_narrow.md' : ("All narrow (hard UB)", 10, 'policies'),
    'doc_outcome_error_code_throw_as_system_error.md' : ("error_code throw as system_error (Outcome)", 20, 'policies'),
    'doc_result_error_code_throw_as_system_error.md' : ("error_code throw as system_error (Result)", 30, 'policies'),
    'doc_outcome_exception_ptr_rethrow.md' : ("exception_ptr rethrow (Outcome)", 40, 'policies'),
    'doc_result_exception_ptr_rethrow.md' : ("exception_ptr rethrow (Result)", 50, 'policies'),
    'doc_terminate.md' : ("Termimate", 60, 'policies'),
    'doc_throw_bad_result_access.md' : ("Throw bad_result_access", 70, 'policies'),
}

replacements = {
#    'detail::result_final' : 'result_or_outcome',
}
for item in items:
    if items[item] is not None:
        replacements[item] = os.path.join(items[item][2], item[4:-3])

def title(item):
    return items[item][0]

def weight(item):
    return str(items[item][1])

def section(item):
    return items[item][2]
    
aref_re = re.compile(r'''<a href="(.*?)">(.*?)</a>''')
aref2_re = re.compile(r'''\[(.*)]\((.*)\)''')
def strip_arefs(content, item):
    idx = 0
    while True:
        match = aref_re.search(content, idx)
        if not match:
            break
        link = match.group(1)
        if link[0] != '#':
            if '#' in link:
                link = link[:link.find('#')]
            if link not in items or items[link] is None:
                print("Removing due to not existing", match.group(0))
                content = content[:match.start(0)] + content[match.start(2):match.end(2)] + content[match.end(0):]
            else:
                if items[item][2] != '' and items[link][2] == '':
                    content = content[:match.start(1)] + '../../' + content[match.start(1):]
                else:
                    content = content[:match.start(1)] + '../' + content[match.start(1):]
        idx = match.start(0) + 1
    idx = 0
    while True:
        match = aref2_re.search(content, idx)
        if not match:
            break
        link = match.group(2)
        if link[0] != '#':
            if '#' in link:
                link = link[:link.find('#')]
            if link not in items or items[link] is None:
                print("Removing due to not existing", match.group(0))
                content = content[:match.start(0)] + content[match.start(1):match.end(1)] + content[match.end(0):]
        idx = match.start(0) + 1
    return content
    
indented_span_re = re.compile(r'''( +)<span''')
def strip_indent_before_spans(content):
    while True:
        match = re.search(indented_span_re, content)
        if not match:
            return content
        spaces = match.group(1)
        hardspaces = '&nbsp;'
        for x in range(0, len(spaces) - 1):
            hardspaces += '&nbsp;'
        content = content[:match.start(1)] + hardspaces + content[match.end(1):]
        
def repair_verbatims(content):
    if r'''\\verbatim''' not in content:
        return content
    while True:
        idx1 = content.find(r'''\\verbatim''')
        if idx1 == -1:
            return content
        idx2 = content.find(r'''\\end''', idx1)
        so = content[idx1+10:idx2].lstrip().rstrip()
        s = so.replace('\\', '')
        s = s.replace(r'“', '"')
        s = s.replace(r'”', '"')
        content = content[:idx1] + s + content[idx2+4:]
        print('Fixing up Standardese failure to expand \\verbatim:\n   ', so, '\n   ', s)

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
  '--input.blacklist_namespace=detail',
  '--input.blacklist_dir=detail',
#  '--input.exclude_namespace=detail',
  '--input.require_comment=0',
  '--output.format=commonmark_html',
  '--output.entity_index_order=namespace_external',
  '--output.show_complex_noexcept=0',
  '-I../../../../include/outcome', '-I../../../../..',
  '../../../../include/outcome/bad_access.hpp',
  '../../../../include/outcome/convert.hpp',
  '../../../../include/outcome/iostream_support.hpp',
  '../../../../include/outcome/outcome.hpp',
  '../../../../include/outcome/result.h',
  '../../../../include/outcome/result.hpp',
  '../../../../include/outcome/success_failure.hpp',
  '../../../../include/outcome/try.hpp',
  '../../../../include/outcome/utils.hpp',
]
args += ['../../../../include/outcome/detail/' + x for x in os.listdir('../../../../include/outcome/detail')]
args += ['../../../../include/outcome/policy/' + x for x in os.listdir('../../../../include/outcome/policy')]
print(args)
subprocess.check_call(args)

# Every doc_* file needs front matter
docs = {}
for item in os.listdir('.'):
    if item.startswith('doc_'):
        if items[item] is not None:
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
                    contents = strip_indent_before_spans(contents)
                    contents = repair_verbatims(contents)
                    contents = strip_arefs(contents, item)
                    for replacement in replacements:
                        s = section(item)
                        r = replacements[replacement]
                        if s: r = r[len(s)+1:]
                        contents = contents.replace(replacement, r)
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
        contents = strip_arefs(contents, item)
        for replacement in replacements:
            r = replacements[replacement]
            contents = contents.replace(replacement, r)
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
