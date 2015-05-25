
monad_construct_value_destruct.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <_Z5test1v>:
   0:	b8 05 00 00 00       	mov    $0x5,%eax
   5:	c3                   	retq   
   6:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
   d:	00 00 00 

0000000000000010 <_Z5test2v>:
  10:	f3 c3                	repz retq 
