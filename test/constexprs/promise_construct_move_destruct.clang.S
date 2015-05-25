
promise_construct_move_destruct.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <_Z5test1v>:
   0:	41 56                	push   %r14
   2:	53                   	push   %rbx
   3:	48 83 ec 48          	sub    $0x48,%rsp
   7:	c7 44 24 38 00 00 00 	movl   $0x0,0x38(%rsp)
   e:	00 
   f:	c6 44 24 40 00       	movb   $0x0,0x40(%rsp)
  14:	48 8d 5c 24 08       	lea    0x8(%rsp),%rbx
  19:	4c 8d 74 24 28       	lea    0x28(%rsp),%r14
  1e:	48 89 df             	mov    %rbx,%rdi
  21:	4c 89 f6             	mov    %r14,%rsi
  24:	e8 00 00 00 00       	callq  29 <_Z5test1v+0x29>
  29:	48 89 df             	mov    %rbx,%rdi
  2c:	e8 00 00 00 00       	callq  31 <_Z5test1v+0x31>
  31:	4c 89 f7             	mov    %r14,%rdi
  34:	e8 00 00 00 00       	callq  39 <_Z5test1v+0x39>
  39:	48 83 c4 48          	add    $0x48,%rsp
  3d:	5b                   	pop    %rbx
  3e:	41 5e                	pop    %r14
  40:	c3                   	retq   
  41:	66 66 66 66 66 66 2e 	data32 data32 data32 data32 data32 nopw %cs:0x0(%rax,%rax,1)
  48:	0f 1f 84 00 00 00 00 
  4f:	00 

0000000000000050 <_Z5test2v>:
  50:	c3                   	retq   
  51:	66 66 66 66 66 66 2e 	data32 data32 data32 data32 data32 nopw %cs:0x0(%rax,%rax,1)
  58:	0f 1f 84 00 00 00 00 
  5f:	00 

0000000000000060 <main>:
  60:	50                   	push   %rax
  61:	e8 9a ff ff ff       	callq  0 <_Z5test1v>
  66:	31 c0                	xor    %eax,%eax
  68:	5a                   	pop    %rdx
  69:	c3                   	retq   
