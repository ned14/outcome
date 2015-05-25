
monad_construct_value_destruct.o:     file format elf64-x86-64


Disassembly of section .text:

0000000000000000 <_Z5test1v>:
   0:	53                   	push   %rbx
   1:	48 83 ec 20          	sub    $0x20,%rsp
   5:	c7 44 24 08 05 00 00 	movl   $0x5,0x8(%rsp)
   c:	00 
   d:	c7 44 24 18 01 00 00 	movl   $0x1,0x18(%rsp)
  14:	00 
  15:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  1a:	e8 00 00 00 00       	callq  1f <_Z5test1v+0x1f>
  1f:	89 c3                	mov    %eax,%ebx
  21:	8b 44 24 18          	mov    0x18(%rsp),%eax
  25:	ff c8                	dec    %eax
  27:	83 f8 03             	cmp    $0x3,%eax
  2a:	77 24                	ja     50 <_Z5test1v+0x50>
  2c:	ff 24 c5 00 00 00 00 	jmpq   *0x0(,%rax,8)
  33:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  38:	e8 00 00 00 00       	callq  3d <_Z5test1v+0x3d>
  3d:	eb 09                	jmp    48 <_Z5test1v+0x48>
  3f:	48 c7 44 24 08 00 00 	movq   $0x0,0x8(%rsp)
  46:	00 00 
  48:	c7 44 24 18 00 00 00 	movl   $0x0,0x18(%rsp)
  4f:	00 
  50:	89 d8                	mov    %ebx,%eax
  52:	48 83 c4 20          	add    $0x20,%rsp
  56:	5b                   	pop    %rbx
  57:	c3                   	retq   
  58:	48 89 c3             	mov    %rax,%rbx
  5b:	8b 44 24 18          	mov    0x18(%rsp),%eax
  5f:	ff c8                	dec    %eax
  61:	83 f8 03             	cmp    $0x3,%eax
  64:	77 24                	ja     8a <_Z5test1v+0x8a>
  66:	ff 24 c5 00 00 00 00 	jmpq   *0x0(,%rax,8)
  6d:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  72:	e8 00 00 00 00       	callq  77 <_Z5test1v+0x77>
  77:	eb 09                	jmp    82 <_Z5test1v+0x82>
  79:	48 c7 44 24 08 00 00 	movq   $0x0,0x8(%rsp)
  80:	00 00 
  82:	c7 44 24 18 00 00 00 	movl   $0x0,0x18(%rsp)
  89:	00 
  8a:	48 89 df             	mov    %rbx,%rdi
  8d:	e8 00 00 00 00       	callq  92 <_Z5test1v+0x92>
  92:	66 66 66 66 66 2e 0f 	data32 data32 data32 data32 nopw %cs:0x0(%rax,%rax,1)
  99:	1f 84 00 00 00 00 00 

00000000000000a0 <_Z5test2v>:
  a0:	c3                   	retq   
  a1:	66 66 66 66 66 66 2e 	data32 data32 data32 data32 data32 nopw %cs:0x0(%rax,%rax,1)
  a8:	0f 1f 84 00 00 00 00 
  af:	00 

00000000000000b0 <main>:
  b0:	50                   	push   %rax
  b1:	e8 4a ff ff ff       	callq  0 <_Z5test1v>
  b6:	83 f8 05             	cmp    $0x5,%eax
  b9:	0f 95 c0             	setne  %al
  bc:	0f b6 c0             	movzbl %al,%eax
  bf:	5a                   	pop    %rdx
  c0:	c3                   	retq   
