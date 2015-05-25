
monad_construct_destruct.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <_Z5test1v>:
   0:	c3                   	retq   
   1:	66 66 66 66 66 66 2e 	data32 data32 data32 data32 data32 nopw %cs:0x0(%rax,%rax,1)
   8:	0f 1f 84 00 00 00 00 
   f:	00 

0000000000000010 <_Z5test2v>:
  10:	c3                   	retq   
  11:	66 66 66 66 66 66 2e 	data32 data32 data32 data32 data32 nopw %cs:0x0(%rax,%rax,1)
  18:	0f 1f 84 00 00 00 00 
  1f:	00 

0000000000000020 <main>:
  20:	50                   	push   %rax
  21:	e8 da ff ff ff       	callq  0 <_Z5test1v>
  26:	31 c0                	xor    %eax,%eax
  28:	5a                   	pop    %rdx
  29:	c3                   	retq   
