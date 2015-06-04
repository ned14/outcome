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

done=False
while not done:
    done=True
    for function, opcodes in functions.items():
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
    if '?test1@@YAXXZ' in functions:
        opcodes=functions['?test1@@YAXXZ']
    elif '?test1@@YAHXZ' in functions:
        opcodes=functions['?test1@@YAHXZ']
    else:
        opcodes=functions['_Z5test1v']
    oh.write(opcodes)
    print(str(opcodes.count('\n')))
    
