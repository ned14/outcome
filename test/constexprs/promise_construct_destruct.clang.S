
promise_construct_destruct.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <_Z5test1v>:
   0:	48 83 ec 28          	sub    $0x28,%rsp
   4:	c7 44 24 18 00 00 00 	movl   $0x0,0x18(%rsp)
   b:	00 
   c:	c6 44 24 20 00       	movb   $0x0,0x20(%rsp)
  11:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  16:	e8 00 00 00 00       	callq  1b <_Z5test1v+0x1b>
  1b:	48 83 c4 28          	add    $0x28,%rsp
  1f:	c3                   	retq   

0000000000000020 <_Z5test2v>:
  20:	c3                   	retq   
  21:	66 66 66 66 66 66 2e 	data32 data32 data32 data32 data32 nopw %cs:0x0(%rax,%rax,1)
  28:	0f 1f 84 00 00 00 00 
  2f:	00 

0000000000000030 <main>:
  30:	50                   	push   %rax
  31:	e8 ca ff ff ff       	callq  0 <_Z5test1v>
  36:	31 c0                	xor    %eax,%eax
  38:	5a                   	pop    %rdx
  39:	c3                   	retq   
