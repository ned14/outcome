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
  26:	0f b6 44 24 30       	movzbl 0x30(%rsp),%eax
  2b:	83 f8 03             	cmp    $0x3,%eax
  2e:	74 0c                	je     3c <_Z5test1St10error_code+0x3c>
  30:	83 f8 02             	cmp    $0x2,%eax
  33:	74 11                	je     46 <_Z5test1St10error_code+0x46>
  35:	83 f8 01             	cmp    $0x1,%eax
  38:	74 0c                	je     46 <_Z5test1St10error_code+0x46>
  3a:	eb 0f                	jmp    4b <_Z5test1St10error_code+0x4b>
  3c:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
  41:	e8 00 00 00 00       	callq  46 <_Z5test1St10error_code+0x46>
  46:	c6 44 24 30 00       	movb   $0x0,0x30(%rsp)
  4b:	89 d8                	mov    %ebx,%eax
  4d:	4c 89 f2             	mov    %r14,%rdx
  50:	48 83 c4 38          	add    $0x38,%rsp
  54:	5b                   	pop    %rbx
  55:	41 5e                	pop    %r14
  57:	c3                   	retq   
  58:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
  5f:	00 
