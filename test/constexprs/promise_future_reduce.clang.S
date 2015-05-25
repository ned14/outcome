
promise_future_reduce.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <_Z5test1v>:
   0:	53                   	push   %rbx
   1:	48 83 ec 50          	sub    $0x50,%rsp
   5:	c7 44 24 40 00 00 00 	movl   $0x0,0x40(%rsp)
   c:	00 
   d:	c6 44 24 48 00       	movb   $0x0,0x48(%rsp)
  12:	c7 44 24 2c 05 00 00 	movl   $0x5,0x2c(%rsp)
  19:	00 
  1a:	48 8d 5c 24 30       	lea    0x30(%rsp),%rbx
  1f:	48 8d 74 24 2c       	lea    0x2c(%rsp),%rsi
  24:	48 89 df             	mov    %rbx,%rdi
  27:	e8 00 00 00 00       	callq  2c <_Z5test1v+0x2c>
  2c:	48 8d 3c 24          	lea    (%rsp),%rdi
  30:	48 89 de             	mov    %rbx,%rsi
  33:	e8 00 00 00 00       	callq  38 <_Z5test1v+0x38>
  38:	48 8d 3c 24          	lea    (%rsp),%rdi
  3c:	e8 00 00 00 00       	callq  41 <_Z5test1v+0x41>
  41:	89 c3                	mov    %eax,%ebx
  43:	48 8d 3c 24          	lea    (%rsp),%rdi
  47:	e8 00 00 00 00       	callq  4c <_Z5test1v+0x4c>
  4c:	48 8d 7c 24 30       	lea    0x30(%rsp),%rdi
  51:	e8 00 00 00 00       	callq  56 <_Z5test1v+0x56>
  56:	89 d8                	mov    %ebx,%eax
  58:	48 83 c4 50          	add    $0x50,%rsp
  5c:	5b                   	pop    %rbx
  5d:	c3                   	retq   
  5e:	48 89 c3             	mov    %rax,%rbx
  61:	eb 0c                	jmp    6f <_Z5test1v+0x6f>
  63:	48 89 c3             	mov    %rax,%rbx
  66:	48 8d 3c 24          	lea    (%rsp),%rdi
  6a:	e8 00 00 00 00       	callq  6f <_Z5test1v+0x6f>
  6f:	48 8d 7c 24 30       	lea    0x30(%rsp),%rdi
  74:	e8 00 00 00 00       	callq  79 <_Z5test1v+0x79>
  79:	48 89 df             	mov    %rbx,%rdi
  7c:	e8 00 00 00 00       	callq  81 <_Z5test1v+0x81>
  81:	66 66 66 66 66 66 2e 	data32 data32 data32 data32 data32 nopw %cs:0x0(%rax,%rax,1)
  88:	0f 1f 84 00 00 00 00 
  8f:	00 

0000000000000090 <_Z5test2v>:
  90:	c3                   	retq   
  91:	66 66 66 66 66 66 2e 	data32 data32 data32 data32 data32 nopw %cs:0x0(%rax,%rax,1)
  98:	0f 1f 84 00 00 00 00 
  9f:	00 

00000000000000a0 <main>:
  a0:	50                   	push   %rax
  a1:	e8 5a ff ff ff       	callq  0 <_Z5test1v>
  a6:	83 f8 05             	cmp    $0x5,%eax
  a9:	0f 95 c0             	setne  %al
  ac:	0f b6 c0             	movzbl %al,%eax
  af:	5a                   	pop    %rdx
  b0:	c3                   	retq   
