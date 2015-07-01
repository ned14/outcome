   0:	41 56                	push   %r14
   2:	53                   	push   %rbx
   3:	48 83 ec 38          	sub    $0x38,%rsp
   7:	89 7c 24 20          	mov    %edi,0x20(%rsp)
   b:	48 89 74 24 28       	mov    %rsi,0x28(%rsp)
  10:	c6 44 24 30 02       	movb   $0x2,0x30(%rsp)
  15:	0f 10 44 24 20       	movups 0x20(%rsp),%xmm0
  1a:	0f 29 04 24          	movaps %xmm0,(%rsp)
  1e:	8b 1c 24             	mov    (%rsp),%ebx
  21:	4c 8b 74 24 08       	mov    0x8(%rsp),%r14
  26:	8a 44 24 30          	mov    0x30(%rsp),%al
  2a:	fe c8                	dec    %al
  2c:	0f b6 c0             	movzbl %al,%eax
  2f:	83 f8 03             	cmp    $0x3,%eax
  32:	77 16                	ja     4a <_Z5test1St10error_code+0x4a>
  34:	ff 24 c5 00 00 00 00 	jmpq   *0x0(,%rax,8)
  3b:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
  40:	e8 00 00 00 00       	callq  45 <_Z5test1St10error_code+0x45>
  45:	c6 44 24 30 00       	movb   $0x0,0x30(%rsp)
  4a:	89 d8                	mov    %ebx,%eax
  4c:	4c 89 f2             	mov    %r14,%rdx
  4f:	48 83 c4 38          	add    $0x38,%rsp
  53:	5b                   	pop    %rbx
  54:	41 5e                	pop    %r14
  56:	c3                   	retq   
  57:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  5e:	00 00 
