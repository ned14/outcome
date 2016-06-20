   0:	55                   	push   %rbp
   1:	53                   	push   %rbx
   2:	48 83 ec 48          	sub    $0x48,%rsp
   6:	48 89 fb             	mov    %rdi,%rbx
   9:	48 8d 3c 24          	lea    (%rsp),%rdi
   d:	e8 00 00 00 00       	callq  12 <_Z5test1v+0x12>
  12:	c6 44 24 38 00       	movb   $0x0,0x38(%rsp)
  17:	0f b6 6c 24 18       	movzbl 0x18(%rsp),%ebp
  1c:	83 fd 02             	cmp    $0x2,%ebp
  1f:	74 0e                	je     2f <_Z5test1v+0x2f>
  21:	83 fd 01             	cmp    $0x1,%ebp
  24:	75 1c                	jne    42 <_Z5test1v+0x42>
  26:	8b 04 24             	mov    (%rsp),%eax
  29:	89 44 24 20          	mov    %eax,0x20(%rsp)
  2d:	eb 13                	jmp    42 <_Z5test1v+0x42>
  2f:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  34:	48 89 44 24 30       	mov    %rax,0x30(%rsp)
  39:	0f 10 04 24          	movups (%rsp),%xmm0
  3d:	0f 29 44 24 20       	movaps %xmm0,0x20(%rsp)
  42:	40 88 6c 24 38       	mov    %bpl,0x38(%rsp)
  47:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
  4c:	e8 00 00 00 00       	callq  51 <_Z5test1v+0x51>
  51:	6b 44 24 20 03       	imul   $0x3,0x20(%rsp),%eax
  56:	83 fd 03             	cmp    $0x3,%ebp
  59:	74 0a                	je     65 <_Z5test1v+0x65>
  5b:	83 fd 02             	cmp    $0x2,%ebp
  5e:	74 05                	je     65 <_Z5test1v+0x65>
  60:	83 fd 01             	cmp    $0x1,%ebp
  63:	75 05                	jne    6a <_Z5test1v+0x6a>
  65:	c6 44 24 38 00       	movb   $0x0,0x38(%rsp)
  6a:	89 03                	mov    %eax,(%rbx)
  6c:	c6 43 18 01          	movb   $0x1,0x18(%rbx)
  70:	0f b6 44 24 18       	movzbl 0x18(%rsp),%eax
  75:	83 f8 03             	cmp    $0x3,%eax
  78:	74 0a                	je     84 <_Z5test1v+0x84>
  7a:	83 f8 02             	cmp    $0x2,%eax
  7d:	74 05                	je     84 <_Z5test1v+0x84>
  7f:	83 f8 01             	cmp    $0x1,%eax
  82:	75 05                	jne    89 <_Z5test1v+0x89>
  84:	c6 44 24 18 00       	movb   $0x0,0x18(%rsp)
  89:	48 89 d8             	mov    %rbx,%rax
  8c:	48 83 c4 48          	add    $0x48,%rsp
  90:	5b                   	pop    %rbx
  91:	5d                   	pop    %rbp
  92:	c3                   	retq   
  93:	83 fd 03             	cmp    $0x3,%ebp
  96:	74 0a                	je     a2 <_Z5test1v+0xa2>
  98:	83 fd 02             	cmp    $0x2,%ebp
  9b:	74 05                	je     a2 <_Z5test1v+0xa2>
  9d:	83 fd 01             	cmp    $0x1,%ebp
  a0:	75 05                	jne    a7 <_Z5test1v+0xa7>
  a2:	c6 44 24 38 00       	movb   $0x0,0x38(%rsp)
  a7:	0f b6 4c 24 18       	movzbl 0x18(%rsp),%ecx
  ac:	83 f9 03             	cmp    $0x3,%ecx
  af:	74 0a                	je     bb <_Z5test1v+0xbb>
  b1:	83 f9 02             	cmp    $0x2,%ecx
  b4:	74 05                	je     bb <_Z5test1v+0xbb>
  b6:	83 f9 01             	cmp    $0x1,%ecx
  b9:	75 05                	jne    c0 <_Z5test1v+0xc0>
  bb:	c6 44 24 18 00       	movb   $0x0,0x18(%rsp)
  c0:	48 89 c7             	mov    %rax,%rdi
  c3:	e8 00 00 00 00       	callq  c8 <_Z5test1v+0xc8>
  c8:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
  cf:	00 
