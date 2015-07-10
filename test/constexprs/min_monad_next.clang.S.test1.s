   0:	55                   	push   %rbp
   1:	53                   	push   %rbx
   2:	48 83 ec 38          	sub    $0x38,%rsp
   6:	48 89 fb             	mov    %rdi,%rbx
   9:	89 74 24 08          	mov    %esi,0x8(%rsp)
   d:	c6 44 24 18 01       	movb   $0x1,0x18(%rsp)
  12:	89 74 24 20          	mov    %esi,0x20(%rsp)
  16:	c6 44 24 30 01       	movb   $0x1,0x30(%rsp)
  1b:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
  20:	e8 00 00 00 00       	callq  25 <_Z5test1i+0x25>
  25:	6b 6c 24 20 03       	imul   $0x3,0x20(%rsp),%ebp
  2a:	0f b6 44 24 30       	movzbl 0x30(%rsp),%eax
  2f:	83 f8 03             	cmp    $0x3,%eax
  32:	74 0c                	je     40 <_Z5test1i+0x40>
  34:	83 f8 02             	cmp    $0x2,%eax
  37:	74 11                	je     4a <_Z5test1i+0x4a>
  39:	83 f8 01             	cmp    $0x1,%eax
  3c:	74 0c                	je     4a <_Z5test1i+0x4a>
  3e:	eb 0f                	jmp    4f <_Z5test1i+0x4f>
  40:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
  45:	e8 00 00 00 00       	callq  4a <_Z5test1i+0x4a>
  4a:	c6 44 24 30 00       	movb   $0x0,0x30(%rsp)
  4f:	89 2b                	mov    %ebp,(%rbx)
  51:	c6 43 10 01          	movb   $0x1,0x10(%rbx)
  55:	0f b6 44 24 18       	movzbl 0x18(%rsp),%eax
  5a:	83 f8 03             	cmp    $0x3,%eax
  5d:	74 0c                	je     6b <_Z5test1i+0x6b>
  5f:	83 f8 02             	cmp    $0x2,%eax
  62:	74 11                	je     75 <_Z5test1i+0x75>
  64:	83 f8 01             	cmp    $0x1,%eax
  67:	74 0c                	je     75 <_Z5test1i+0x75>
  69:	eb 0f                	jmp    7a <_Z5test1i+0x7a>
  6b:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  70:	e8 00 00 00 00       	callq  75 <_Z5test1i+0x75>
  75:	c6 44 24 18 00       	movb   $0x0,0x18(%rsp)
  7a:	48 89 d8             	mov    %rbx,%rax
  7d:	48 83 c4 38          	add    $0x38,%rsp
  81:	5b                   	pop    %rbx
  82:	5d                   	pop    %rbp
  83:	c3                   	retq   
  84:	48 89 c3             	mov    %rax,%rbx
  87:	0f b6 44 24 30       	movzbl 0x30(%rsp),%eax
  8c:	83 f8 03             	cmp    $0x3,%eax
  8f:	74 0c                	je     9d <_Z5test1i+0x9d>
  91:	83 f8 02             	cmp    $0x2,%eax
  94:	74 11                	je     a7 <_Z5test1i+0xa7>
  96:	83 f8 01             	cmp    $0x1,%eax
  99:	74 0c                	je     a7 <_Z5test1i+0xa7>
  9b:	eb 0f                	jmp    ac <_Z5test1i+0xac>
  9d:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
  a2:	e8 00 00 00 00       	callq  a7 <_Z5test1i+0xa7>
  a7:	c6 44 24 30 00       	movb   $0x0,0x30(%rsp)
  ac:	0f b6 44 24 18       	movzbl 0x18(%rsp),%eax
  b1:	83 f8 03             	cmp    $0x3,%eax
  b4:	74 0c                	je     c2 <_Z5test1i+0xc2>
  b6:	83 f8 02             	cmp    $0x2,%eax
  b9:	74 11                	je     cc <_Z5test1i+0xcc>
  bb:	83 f8 01             	cmp    $0x1,%eax
  be:	74 0c                	je     cc <_Z5test1i+0xcc>
  c0:	eb 0f                	jmp    d1 <_Z5test1i+0xd1>
  c2:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  c7:	e8 00 00 00 00       	callq  cc <_Z5test1i+0xcc>
  cc:	c6 44 24 18 00       	movb   $0x0,0x18(%rsp)
  d1:	48 89 df             	mov    %rbx,%rdi
  d4:	e8 00 00 00 00       	callq  d9 <_Z5test1i+0xd9>
  d9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
