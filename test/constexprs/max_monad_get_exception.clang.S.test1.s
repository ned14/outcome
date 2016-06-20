   0:	41 56                	push   %r14
   2:	53                   	push   %rbx
   3:	48 83 ec 28          	sub    $0x28,%rsp
   7:	49 89 fe             	mov    %rdi,%r14
   a:	48 8d 5c 24 08       	lea    0x8(%rsp),%rbx
   f:	48 89 df             	mov    %rbx,%rdi
  12:	e8 00 00 00 00       	callq  17 <_Z5test1v+0x17>
  17:	4c 89 f7             	mov    %r14,%rdi
  1a:	48 89 de             	mov    %rbx,%rsi
  1d:	e8 00 00 00 00       	callq  22 <_Z5test1v+0x22>
  22:	0f b6 44 24 20       	movzbl 0x20(%rsp),%eax
  27:	83 f8 03             	cmp    $0x3,%eax
  2a:	74 0c                	je     38 <_Z5test1v+0x38>
  2c:	83 f8 02             	cmp    $0x2,%eax
  2f:	74 11                	je     42 <_Z5test1v+0x42>
  31:	83 f8 01             	cmp    $0x1,%eax
  34:	74 0c                	je     42 <_Z5test1v+0x42>
  36:	eb 0f                	jmp    47 <_Z5test1v+0x47>
  38:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  3d:	e8 00 00 00 00       	callq  42 <_Z5test1v+0x42>
  42:	c6 44 24 20 00       	movb   $0x0,0x20(%rsp)
  47:	4c 89 f0             	mov    %r14,%rax
  4a:	48 83 c4 28          	add    $0x28,%rsp
  4e:	5b                   	pop    %rbx
  4f:	41 5e                	pop    %r14
  51:	c3                   	retq   
  52:	48 89 c3             	mov    %rax,%rbx
  55:	0f b6 44 24 20       	movzbl 0x20(%rsp),%eax
  5a:	83 f8 03             	cmp    $0x3,%eax
  5d:	74 0c                	je     6b <_Z5test1v+0x6b>
  5f:	83 f8 02             	cmp    $0x2,%eax
  62:	74 11                	je     75 <_Z5test1v+0x75>
  64:	83 f8 01             	cmp    $0x1,%eax
  67:	74 0c                	je     75 <_Z5test1v+0x75>
  69:	eb 0f                	jmp    7a <_Z5test1v+0x7a>
  6b:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  70:	e8 00 00 00 00       	callq  75 <_Z5test1v+0x75>
  75:	c6 44 24 20 00       	movb   $0x0,0x20(%rsp)
  7a:	48 89 df             	mov    %rbx,%rdi
  7d:	e8 00 00 00 00       	callq  82 <_Z5test1v+0x82>
  82:	66 66 66 66 66 2e 0f 	data16 data16 data16 data16 nopw %cs:0x0(%rax,%rax,1)
  89:	1f 84 00 00 00 00 00 
