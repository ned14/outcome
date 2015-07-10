   0:	55                   	push   %rbp
   1:	53                   	push   %rbx
   2:	48 83 ec 38          	sub    $0x38,%rsp
   6:	48 89 fb             	mov    %rdi,%rbx
   9:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
   e:	e8 00 00 00 00       	callq  13 <_Z5test1v+0x13>
  13:	c6 44 24 30 00       	movb   $0x0,0x30(%rsp)
  18:	0f b6 44 24 18       	movzbl 0x18(%rsp),%eax
  1d:	83 f8 03             	cmp    $0x3,%eax
  20:	74 11                	je     33 <_Z5test1v+0x33>
  22:	83 f8 02             	cmp    $0x2,%eax
  25:	75 21                	jne    48 <_Z5test1v+0x48>
  27:	0f 10 44 24 08       	movups 0x8(%rsp),%xmm0
  2c:	0f 29 44 24 20       	movaps %xmm0,0x20(%rsp)
  31:	eb 22                	jmp    55 <_Z5test1v+0x55>
  33:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
  38:	48 8d 74 24 08       	lea    0x8(%rsp),%rsi
  3d:	e8 00 00 00 00       	callq  42 <_Z5test1v+0x42>
  42:	8a 44 24 18          	mov    0x18(%rsp),%al
  46:	eb 0d                	jmp    55 <_Z5test1v+0x55>
  48:	83 f8 01             	cmp    $0x1,%eax
  4b:	75 08                	jne    55 <_Z5test1v+0x55>
  4d:	8b 4c 24 08          	mov    0x8(%rsp),%ecx
  51:	89 4c 24 20          	mov    %ecx,0x20(%rsp)
  55:	88 44 24 30          	mov    %al,0x30(%rsp)
  59:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
  5e:	e8 00 00 00 00       	callq  63 <_Z5test1v+0x63>
  63:	6b 6c 24 20 03       	imul   $0x3,0x20(%rsp),%ebp
  68:	0f b6 44 24 30       	movzbl 0x30(%rsp),%eax
  6d:	83 f8 03             	cmp    $0x3,%eax
  70:	74 0c                	je     7e <_Z5test1v+0x7e>
  72:	83 f8 02             	cmp    $0x2,%eax
  75:	74 11                	je     88 <_Z5test1v+0x88>
  77:	83 f8 01             	cmp    $0x1,%eax
  7a:	74 0c                	je     88 <_Z5test1v+0x88>
  7c:	eb 0f                	jmp    8d <_Z5test1v+0x8d>
  7e:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
  83:	e8 00 00 00 00       	callq  88 <_Z5test1v+0x88>
  88:	c6 44 24 30 00       	movb   $0x0,0x30(%rsp)
  8d:	89 2b                	mov    %ebp,(%rbx)
  8f:	c6 43 10 01          	movb   $0x1,0x10(%rbx)
  93:	0f b6 44 24 18       	movzbl 0x18(%rsp),%eax
  98:	83 f8 03             	cmp    $0x3,%eax
  9b:	74 0c                	je     a9 <_Z5test1v+0xa9>
  9d:	83 f8 02             	cmp    $0x2,%eax
  a0:	74 11                	je     b3 <_Z5test1v+0xb3>
  a2:	83 f8 01             	cmp    $0x1,%eax
  a5:	74 0c                	je     b3 <_Z5test1v+0xb3>
  a7:	eb 0f                	jmp    b8 <_Z5test1v+0xb8>
  a9:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  ae:	e8 00 00 00 00       	callq  b3 <_Z5test1v+0xb3>
  b3:	c6 44 24 18 00       	movb   $0x0,0x18(%rsp)
  b8:	48 89 d8             	mov    %rbx,%rax
  bb:	48 83 c4 38          	add    $0x38,%rsp
  bf:	5b                   	pop    %rbx
  c0:	5d                   	pop    %rbp
  c1:	c3                   	retq   
  c2:	48 89 c3             	mov    %rax,%rbx
  c5:	0f b6 44 24 30       	movzbl 0x30(%rsp),%eax
  ca:	83 f8 03             	cmp    $0x3,%eax
  cd:	74 0c                	je     db <_Z5test1v+0xdb>
  cf:	83 f8 02             	cmp    $0x2,%eax
  d2:	74 11                	je     e5 <_Z5test1v+0xe5>
  d4:	83 f8 01             	cmp    $0x1,%eax
  d7:	74 0c                	je     e5 <_Z5test1v+0xe5>
  d9:	eb 0f                	jmp    ea <_Z5test1v+0xea>
  db:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
  e0:	e8 00 00 00 00       	callq  e5 <_Z5test1v+0xe5>
  e5:	c6 44 24 30 00       	movb   $0x0,0x30(%rsp)
  ea:	0f b6 44 24 18       	movzbl 0x18(%rsp),%eax
  ef:	83 f8 03             	cmp    $0x3,%eax
  f2:	74 0c                	je     100 <_Z5test1v+0x100>
  f4:	83 f8 02             	cmp    $0x2,%eax
  f7:	74 11                	je     10a <_Z5test1v+0x10a>
  f9:	83 f8 01             	cmp    $0x1,%eax
  fc:	74 0c                	je     10a <_Z5test1v+0x10a>
  fe:	eb 0f                	jmp    10f <_Z5test1v+0x10f>
 100:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
 105:	e8 00 00 00 00       	callq  10a <_Z5test1v+0x10a>
 10a:	c6 44 24 18 00       	movb   $0x0,0x18(%rsp)
 10f:	48 89 df             	mov    %rbx,%rdi
 112:	e8 00 00 00 00       	callq  117 <_Z5test1v+0x117>
 117:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
 11e:	00 00 
