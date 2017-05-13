#!/usr/bin/python3
# File created by Tom Westerhout in May 2017

import sys
import os
import subprocess

import count_opcodes


def _mk_f(format_string : str):
    return lambda s1, s2 : format_string.format(s1, s2)

def _mk_o(initial_ext: str, final_ext : str):
    return lambda s : s.replace("." + initial_ext, "." + final_ext)



_compilers_ = \
    { "posix"   : ["gcc", "clang"]
    , "nt"      : ["msvc", "msvc_clang"]
    }

_compile_info_ = \
    { "gcc"        : (_mk_f("g++-6 -std=c++14 -DBOOST_OUTCOME_ENABLE_ADVANCED=1 -DNDEBUG -I../.. -O3 {} -o {}"), _mk_o("cpp", "out"))
    , "clang"      : (_mk_f("clang++-4.0 -std=c++14 -DBOOST_OUTCOME_ENABLE_ADVANCED=1 -DNDEBUG -I../.. -O3 {} -o {}"), _mk_o("cpp", "out"))
    , "msvc"       : (_mk_f("cl /EHsc /c /DBOOST_OUTCOME_ENABLE_ADVANCED=1 /DNDEBUG /I../.. /O2 /GS- /GR /Gy /Zc:inline /MT "
                           + "/D_UNICODE=1 /DUNICODE=1 {} /Fo{}"), _mk_o("cpp", "obj"))
    , "msvc_clang" : (_mk_f("clang -std=c++14 -c -DBOOST_OUTCOME_ENABLE_ADVANCED=1 -DNDEBUG -I../.. -O3 -fexceptions "
                           + "-D_UNICODE=1 -DUNICODE=1 {} -o {} -fms-compatibility-version=19"), _mk_o("cpp", "out"))
    }

_disassemble_info_ = \
    { "gcc"        : (_mk_f("objdump -C -d {} > {}"), _mk_o("out", "gcc.S"))
    , "clang"      : (_mk_f("objdump -C -d {} > {}"), _mk_o("out", "clang.S"))
    , "msvc"       : (_mk_f("dumpbin /disasm {} > {}"), _mk_o("obj", "msvc.S"))
    , "msvc_clang" : (_mk_f("dumpbin /disasm {} > {}"), _mk_o("out", "msvc_clang.S"))
    }

#
# Contains upper bounds on number of ops in the format
#
# { 'test1' : { 'gcc' : 10, 'clang' : 8, 'msvc' : 123, 'msvc_clang' : 20 }
# , 'test2' : { ... }
# , ...
# }
#
limits = {
"min_monad_bind"                               : { 'gcc' :  5, 'clang' :  5, 'msvc' : 100 },
"min_monad_construct_destruct"                 : { 'gcc' :  5, 'clang' :  5, 'msvc' :  5 },
"min_monad_construct_error_move_destruct"      : { 'gcc' :  5, 'clang' :  5, 'msvc' :  5 },
"min_monad_construct_exception_move_destruct"  : { 'gcc' : 30, 'clang' : 40, 'msvc' : 1000 },
"min_monad_construct_value_move_destruct"      : { 'gcc' :  5, 'clang' :  5, 'msvc' :  5 },
"min_monad_next"                               : { 'gcc' :  5, 'clang' :  5, 'msvc' : 1000 },
"min_option_construct_value_move_destruct"     : { 'gcc' :  5, 'clang' :  5, 'msvc' :  5 },
"min_option_next"                              : { 'gcc' :  5, 'clang' :  5, 'msvc' :  5 },
"min_result_construct_value_move_destruct"     : { 'gcc' :  5, 'clang' :  5, 'msvc' :  5 },
"min_result_next"                              : { 'gcc' :  5, 'clang' :  5, 'msvc' :  5 },
}





#
# Tries to compiler src_file using compiler.
# On success: returns name of the executable. 
# On failure: returns None
#
def compile(src_file : str, compiler : str) -> str:
    if src_file is None:
        return None
    print("[*] Compiling '" + src_file + "' with " + compiler + "...", 
        file=sys.stderr)

    command, output = _compile_info_[compiler]
    try:
        subprocess.check_output(command(src_file, output(src_file)), 
            stderr=subprocess.STDOUT, shell=True)
    except subprocess.CalledProcessError as e:
        print("[-] Error while compiling: " + e.output.decode('utf-8'), 
            file=sys.stderr)
        return None
    return output(src_file)

#
# Tries to disassemble obj_file using a tool corresponding
# to compiler. If disassembling suceeds, deletes the obj_file.
# On success: returns name of the file with asm code. 
# On failure: returns None
#
def disassemble(obj_file : str, compiler : str) -> str:
    if obj_file is None:
        return None
    print("[*] Disassembling '" + obj_file + "' with " + compiler + "...", 
        file=sys.stderr)

    command, output = _disassemble_info_[compiler]
    try:
        subprocess.check_output(command(obj_file, output(obj_file)), 
            stderr=subprocess.STDOUT, shell=True)
    except subprocess.CalledProcessError as e:
        print("[-] Error while dissasembling: " + e.output.decode('utf-8'), 
            file=sys.stderr)
        return None

    try:
        os.remove(obj_file)
    except OSError as e:
        print("[-] Error removing file: " + e.strerror)
        return None
    return output(obj_file)


def test_single(func : str, src_file : str, compiler : str, indent : int):
    asm_file = disassemble(compile(src_file, compiler), compiler)
    assert asm_file is not None 

    test_name = src_file.replace(".cpp", "")
    count, opcodes = count_opcodes.count_opcodes(asm_file, func)
    if count == -1:
        print("[-] No call to " + func + " found.", file=sys.stderr)
        sys.exit(0)
    try:
        os.remove(asm_file)
    except OSError as e:
        print("[-] Error removing file: " + e.strerror)
    
    output = "<![CDATA[\n" + "\n".join(opcodes) + "\n]]>"
    xml_string = '  '*indent + '<testcase name="' + test_name + '.' + \
        compiler + '">\n'
    if test_name in limits and compiler in limits[test_name] and limits[test_name][compiler] < count:
        xml_string += '  '*(indent+1) + '<failure message="Opcodes generated ' + \
            str(count) + ' exceeds limit ' + str(limits[test_name][compiler]) + '"/>\n'
    xml_string += '  '*(indent+2) + '<system-out>\n' + output + '\n' + \
                  '  '*(indent+2) + '</system-out>\n' + \
                  '  '*indent + '</testcase>\n'

    return (test_name, count, xml_string)


def list_src_files():
    return filter(lambda src_file: os.path.isfile(src_file), 
           filter(lambda s: s.endswith(".cpp"), 
               os.listdir()))


def test_all(func : str):
    xml_string = '<?xml version="1.0" encoding="UTF-8"?>\n' + \
                 '<testsuite name="constexpr">\n'
    # holds (compiler, name, count) tuples
    csv_data = []
    for src_file in list_src_files():
        print(src_file)
        for compiler in _compilers_[os.name]:
            name, count, xml_output = test_single(func, 
                src_file, compiler, 1)
            csv_data.append((compiler, name, count))
            xml_string += xml_output
    xml_string += '</testsuite>'

    with open("results." + os.name + ".xml", "wt") as xml_file:
        xml_file.write(xml_string)

    for compiler in _compilers_[os.name]:
        with open(compiler + ".csv", "a+t") as csv_file:
            csv_file.write(','.join( 
                map(lambda t: '"'+t[1]+'"', 
                filter(lambda t: t[0] == compiler, 
                    csv_data))))
            csv_file.write('\n')
            csv_file.write(','.join( 
                map(lambda t: str(t[2]), 
                filter(lambda t: t[0] == compiler, 
                    csv_data))))
            csv_file.write('\n')


test_all('test1')
