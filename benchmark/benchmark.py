#!/usr/bin/python
# Benchmark Outcome against other stuff
# (C) 2017 Niall Douglas http://www.nedproductions.biz/
# Created: Mar 2017

from __future__ import print_function
import sys, os, subprocess, shlex

class ErrorHandlingSystem(object):
    "Base class for an error handling system"

    def __init__(self):
        pass

    def preamble(self, idx):
        "Preamble written out before each source file"
        return ''

    def function_cont(self, name):
        "Function signature"
        return 'extern int %s(int par)' % name

    def function_final(self):
        "Function implementation for final function zero"
        return r'''{ return par ? -1 : 0; }'''

    def generate_sources(self, no):
        "Generate no source files calling into one another"
        for n in xrange(0, no):
            with open("source%04d.cpp" % n, 'wt') as oh:
                oh.write(self.preamble(n))
                oh.write(r'''extern volatile int counter;
struct RAII { RAII() { ++counter; } ~RAII() { --counter; } };
''')
                if n:
                    oh.write(self.function_cont("funct%04d" % (n-1)) + ';\n')
                oh.write(self.function_cont("funct%04d" % n))
                if n:
                    oh.write(r'''
{
  RAII raii;
  return ''' + ("funct%04d" % (n-1)) + r'''(par + 1);
}
''')
                else:
                    oh.write(self.function_final())
        with open("function.h", 'wt') as oh:
            oh.write(self.function_cont("funct%04d" % (no-1)) + ';\n')
            oh.write("#define FUNCTION funct%04d\n" % (no-1))
            oh.write("#define NESTING %d\n" % (no))

matrix = [
    ('integer-returns', ErrorHandlingSystem),
]

if sys.platform == 'win32':
    compilers = [
    #    ('msvc_noexcept', r'cl /O2 /MD /Z7 /Fe%s'),  actually slower!
        ('msvc19', r'cl /nologo /O2 /MD /Z7 /EHsc /volatile:iso /Fe%s'),
        ('msvc19-ltcg', r'cl /nologo /O2 /GL /MD /Z7 /volatile:iso /EHsc /Fe%s'),
    ]
else:
    compilers = [
        ('gcc62', r'g++-6 -std=c++14 -O3 -g -o %s'),
        ('gcc62-lto', r'g++-6 -std=c++14 -O3 -g -flto -o %s'),
        ('clang40', r'clang++-4.0 -std=c++14 -O3 -g -o %s'),
#        ('clang40-lto', r'clang++-4.0 -std=c++14 -O3 -g -flto -o %s'),  not working yet
    ]

SOURCES=100

with open('results-'+sys.platform+'.csv', 'wt') as resultsh:
    resultsh.write('"Compiler"')
    for m in matrix:
        resultsh.write(',"'+m[0]+'"')
    resultsh.write('\n')
    for compiler in compilers:
        resultsh.write('"'+compiler[0]+'"')
        for m in matrix:
            instance = m[1]()
            try:
                exename = m[0]+'_'+compiler[0]
                print("Working on", exename, "...")
                instance.generate_sources(SOURCES)
                args = shlex.split(compiler[1] % exename)
                args.append("runner.cpp")
                for n in xrange(0, SOURCES):
                    args.append("source%04d.cpp" % n)
                #print(' '.join(args))
                try:
                    print(subprocess.check_output(args))
                except subprocess.CalledProcessError as e:
                    print(e.output)
                    raise
            finally:
                for n in xrange(0, SOURCES):
                    if os.path.exists("source%04d.cpp" % n):
                        os.remove("source%04d.cpp" % n)
                    if os.path.exists("source%04d.obj" % n):
                        os.remove("source%04d.obj" % n)
                os.remove("function.h")
                #if os.path.exists(exename):
                #    os.remove(exename)
                #if os.path.exists(exename+'.exe'):
                #    os.remove(exename+'.exe')
                if os.path.exists("runner.obj"):
                    os.remove("runner.obj")
            if sys.platform != 'win32':
                exename = './' + exename
            result = subprocess.check_output([exename])
            resultsh.write(',' + result.rstrip())
        resultsh.write('\n')
