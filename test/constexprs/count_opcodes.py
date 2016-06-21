#!/usr/bin/python3
# Parse x64 assembler dumps and figure out how many opcodes something takes
# (C) 2015 Niall Douglas http://www.nedprod.com/
# File created: June 2015

import sys, os
debug=False
inputfile=None #'max_monad_bind.msvc_clang.S'

try:
    os.remove(sys.argv[1]+'.test1.s')
except:
    pass

# Map of function offset (objdump)/name (dumpbin) to opcodes
functions={}
isObjDump=False
isDumpBin=False

if inputfile is None:
    if len(sys.argv)<2:
        print('Usage: '+sys.argv[0]+' <assembler file containing test1()>', file=sys.stderr)
        sys.exit(1)
    inputfile=sys.argv[1]

# objdump has format:
# 0000000000000000 <_Z5test1v>:
# callq  23 <_Z5test1v+0x23>

# dumpbin has format:
# ?test1@@YAHXZ (int __cdecl test1(void)):
# call        ?get_future@?$promise@H@lightweight_futures@v1_std@spinlock@boost@@QEAA?AV?$future@H@2345@XZ

thisfunction=None
linecount=0
with open(inputfile, 'rt') as ih:
    for line in ih:
        line2=line.rstrip()
        linecount=linecount+1
        #print("Line "+str(linecount)+" is '"+line2+"'")
        while True:
            if thisfunction is None:
                if len(line2)==0:
                    pass
                elif line[:4]=='0000':
                    isObjDump=True
                    thisfunction=line[18:-3]
                    thisfunctionopcodes=""
                    if debug:
                        print("\nLine "+str(linecount)+" new objdump function "+thisfunction)
                elif line2[0]!=' ' and line2[0]!='$' and line2[-1]==':':
                    isDumpBin=True
                    thisfunction=line[:line.find(' ')]
                    thisfunctionopcodes=""
                    if debug:
                        print("\nLine "+str(linecount)+" new dumpbin function "+thisfunction)
            elif len(line2)==0 or (line2[0]!=' ' and line2[0]!='$' and line2[-1]==':'):
                if debug:
                    print("Storing function "+str(thisfunction)+" with "+str(thisfunctionopcodes.count('\n'))+" lines")
                functions[thisfunction]=thisfunctionopcodes
                thisfunction=None
                continue
            else:
                thisfunctionopcodes+=line
            break
if thisfunction is not None:
    functions[thisfunction]=thisfunctionopcodes

opcodes=None
for function, _opcodes in functions.items():
    if function[:8]=='?test1@@' or (function[:8]=='_Z5test1' and not '-0x' in function):
        opcodes=_opcodes
        break
if opcodes is None:
    print("-1")
    sys.exit(0)

done=False
loops=0
while not done:
    done=True
    if debug:
        print("Function "+function+" has "+str(opcodes.count('\n'))+" lines")
    callop=opcodes.find(" call " if isDumpBin else "callq ")
    while callop!=-1:
        loops+=1
        if loops > 1000:
#            print(opcodes)
            assert loops <= 1000
        if isObjDump:
            idx=opcodes.find('<', callop)
            offset=opcodes.find('+', idx)
            if opcodes[idx+1:offset].startswith('_Z5test1'):
                idx=-1
            elif offset!=-1:
                calltarget=opcodes[idx+1:offset]
            else:
                calltarget=opcodes[idx+1:opcodes.find('>', idx)]
        if isDumpBin:
            idx=opcodes.find('?', callop);
            calltarget=opcodes[idx:opcodes.find('\n', idx)]
            if calltarget.startswith('?test1@@'):
                idx=-1
        if idx!=-1:
            if debug:
                print("   contains call to "+str(calltarget)+" which has found="+str(calltarget in functions))
            if calltarget in functions:
                done=False
                expansion=functions[calltarget]
                # Replace calltarget string
                opcodes=opcodes[:idx]+"replaced\n"+expansion+opcodes[opcodes.find('\n', idx):]
                #print(opcodes)

        callop=opcodes.find(" call " if isDumpBin else "callq ", callop+1)
    functions[function]=opcodes

#print("\n\n")
#for function, opcodes in functions.items():
#    print("Function "+function+" has "+str(opcodes.count('\n'))+" opcodes")

with open(inputfile+'.test1.s', "wt") as oh:
    oh.write(opcodes)
    # Count instructions
    count=0
    for line in opcodes.splitlines():
        if isObjDump:
            # If the line has two tab chars, it's an instruction
            if line.startswith('  ') and "data32" not in line and "nopw" not in line and "retq" not in line:
                count+=1
        if isDumpBin:
            # If the line is two spaces and some zeros, it's an instruction
            if line[:6]=='  0000' and "ret" not in line:
                count+=1
    print(str(count))

