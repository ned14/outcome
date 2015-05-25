
future_construct_destruct.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <_Z5test1v>:
   0:	48 83 ec 28          	sub    $0x28,%rsp
   4:	c7 44 24 10 00 00 00 	movl   $0x0,0x10(%rsp)
   b:	00 
   c:	c6 44 24 18 00       	movb   $0x0,0x18(%rsp)
  11:	48 c7 44 24 20 00 00 	movq   $0x0,0x20(%rsp)
  18:	00 00 
  1a:	48 8d 3c 24          	lea    (%rsp),%rdi
  1e:	e8 00 00 00 00       	callq  23 <_Z5test1v+0x23>
  23:	48 83 c4 28          	add    $0x28,%rsp
  27:	c3                   	retq   
  28:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
  2f:	00 

0000000000000030 <_Z5test2v>:
  30:	c3                   	retq   
  31:	66 66 66 66 66 66 2e 	data32 data32 data32 data32 data32 nopw %cs:0x0(%rax,%rax,1)
  38:	0f 1f 84 00 00 00 00 
  3f:	00 

0000000000000040 <main>:
  40:	50                   	push   %rax
  41:	e8 ba ff ff ff       	callq  0 <_Z5test1v>
  46:	31 c0                	xor    %eax,%eax
  48:	5a                   	pop    %rdx
  49:	c3                   	retq   
