#!/usr/bin/python3
# Parse x64 assembler dumps and figure out how many opcodes something takes
# (C) 2015 Niall Douglas http://www.nedprod.com/
# File created: June 2015

import sys

# Map of function name to opcodes
functions={}
isObjDump=False
isDumpBin=False

if len(sys.argv)<2:
    print('Usage: '+sys.argv[0]+' <assembler file containing test1()>', file=sys.stderr)
    sys.exit(1)

# objdump has format:
# 0000000000000000 <_Z5test1v>:
# callq  23 <_Z5test1v+0x23>

# dumpbin has format:
# ?test1@@YAHXZ (int __cdecl test1(void)):
# call        ?get_future@?$promise@H@lightweight_futures@v1_std@spinlock@boost@@QEAA?AV?$future@H@2345@XZ

thisfunction=None
with open(sys.argv[1], 'rt') as ih:
    for line in ih:
        if thisfunction is None:
            if line[:4]=='0000':
                isObjDump=True
                thisfunction=line[18:-3]
                thisfunctionopcodes=""
                #print("New objdump function "+thisfunction)
            elif line[0]=='?':
                isDumpBin=True
                thisfunction=line[:line.find(' ')]
                thisfunctionopcodes=""
                #print("New dumpbin function "+thisfunction)
        elif len(line)==1:
            functions[thisfunction]=thisfunctionopcodes
            thisfunction=None
        else:
            thisfunctionopcodes+=line
if thisfunction is not None:
    functions[thisfunction]=thisfunctionopcodes

opcodes=None
for function, _opcodes in functions.items():
    if function[:8]=='?test1@@':
        opcodes=_opcodes
        break
    if function[:8]=='_Z5test1':
        opcodes=_opcodes
        break
if opcodes is None:
    print("-1")
    sys.exit(0)

done=False
while not done:
    done=True
    #print("Function "+function+" has "+str(opcodes.count('\n'))+" lines")
    callop=opcodes.find(" call " if isDumpBin else "\tcallq ")
    while callop!=-1:
        if isObjDump:
            idx=opcodes.find('<', callop)
            calltarget=opcodes[idx+1:opcodes.find('+', idx)]
        if isDumpBin:
            idx=opcodes.find('?', callop);
            calltarget=opcodes[idx:opcodes.find('\n', idx)]
        #print("   contains call to "+calltarget+" which has found="+str(calltarget in functions))
        if calltarget != function and calltarget in functions:
            done=False
            expansion=functions[calltarget]
            # Replace calltarget string
            opcodes=opcodes[:idx]+"replaced\n"+expansion+opcodes[opcodes.find('\n', idx):]
            
        callop=opcodes.find(" call " if isDumpBin else "\tcallq ", callop+1)
    functions[function]=opcodes

#print("\n\n")
#for function, opcodes in functions.items():
#    print("Function "+function+" has "+str(opcodes.count('\n'))+" opcodes")

with open(sys.argv[1]+'.test1.s', "wt") as oh:
    oh.write(opcodes)
    # Count instructions
    count=0
    for line in opcodes.splitlines():
        if isObjDump:
            # If the line has two tab chars, it's an instruction
            if line.count('\t')>1:
                count+=1
        if isDumpBin:
            # If the line is two spaces and some zeros, it's an instruction
            if line[:6]=='  0000':
                count+=1
    print(str(count))
    