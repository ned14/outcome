   0:	55                   	push   %rbp
   1:	53                   	push   %rbx
   2:	48 83 ec 48          	sub    $0x48,%rsp
   6:	48 89 fb             	mov    %rdi,%rbx
   9:	48 8d 3c 24          	lea    (%rsp),%rdi
   d:	e8 00 00 00 00       	callq  12 <_Z5test1v+0x12>
  12:	c6 44 24 38 00       	movb   $0x0,0x38(%rsp)
  17:	0f b6 44 24 18       	movzbl 0x18(%rsp),%eax
  1c:	83 f8 03             	cmp    $0x3,%eax
  1f:	74 28                	je     49 <_Z5test1v+0x49>
  21:	83 f8 02             	cmp    $0x2,%eax
  24:	74 0e                	je     34 <_Z5test1v+0x34>
  26:	83 f8 01             	cmp    $0x1,%eax
  29:	75 30                	jne    5b <_Z5test1v+0x5b>
  2b:	8b 0c 24             	mov    (%rsp),%ecx
  2e:	89 4c 24 20          	mov    %ecx,0x20(%rsp)
  32:	eb 27                	jmp    5b <_Z5test1v+0x5b>
  34:	48 8b 4c 24 10       	mov    0x10(%rsp),%rcx
  39:	48 89 4c 24 30       	mov    %rcx,0x30(%rsp)
  3e:	0f 10 04 24          	movups (%rsp),%xmm0
  42:	0f 29 44 24 20       	movaps %xmm0,0x20(%rsp)
  47:	eb 12                	jmp    5b <_Z5test1v+0x5b>
  49:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
  4e:	48 8d 34 24          	lea    (%rsp),%rsi
  52:	e8 00 00 00 00       	callq  57 <_Z5test1v+0x57>
  57:	8a 44 24 18          	mov    0x18(%rsp),%al
  5b:	88 44 24 38          	mov    %al,0x38(%rsp)
  5f:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
  64:	e8 00 00 00 00       	callq  69 <_Z5test1v+0x69>
  69:	6b 6c 24 20 03       	imul   $0x3,0x20(%rsp),%ebp
  6e:	0f b6 44 24 38       	movzbl 0x38(%rsp),%eax
  73:	83 f8 03             	cmp    $0x3,%eax
  76:	74 0c                	je     84 <_Z5test1v+0x84>
  78:	83 f8 02             	cmp    $0x2,%eax
  7b:	74 11                	je     8e <_Z5test1v+0x8e>
  7d:	83 f8 01             	cmp    $0x1,%eax
  80:	74 0c                	je     8e <_Z5test1v+0x8e>
  82:	eb 0f                	jmp    93 <_Z5test1v+0x93>
  84:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
  89:	e8 00 00 00 00       	callq  8e <_Z5test1v+0x8e>
  8e:	c6 44 24 38 00       	movb   $0x0,0x38(%rsp)
  93:	89 2b                	mov    %ebp,(%rbx)
  95:	c6 43 18 01          	movb   $0x1,0x18(%rbx)
  99:	0f b6 44 24 18       	movzbl 0x18(%rsp),%eax
  9e:	83 f8 03             	cmp    $0x3,%eax
  a1:	74 0c                	je     af <_Z5test1v+0xaf>
  a3:	83 f8 02             	cmp    $0x2,%eax
  a6:	74 10                	je     b8 <_Z5test1v+0xb8>
  a8:	83 f8 01             	cmp    $0x1,%eax
  ab:	74 0b                	je     b8 <_Z5test1v+0xb8>
  ad:	eb 0e                	jmp    bd <_Z5test1v+0xbd>
  af:	48 8d 3c 24          	lea    (%rsp),%rdi
  b3:	e8 00 00 00 00       	callq  b8 <_Z5test1v+0xb8>
  b8:	c6 44 24 18 00       	movb   $0x0,0x18(%rsp)
  bd:	48 89 d8             	mov    %rbx,%rax
  c0:	48 83 c4 48          	add    $0x48,%rsp
  c4:	5b                   	pop    %rbx
  c5:	5d                   	pop    %rbp
  c6:	c3                   	retq   
  c7:	48 89 c3             	mov    %rax,%rbx
  ca:	0f b6 44 24 38       	movzbl 0x38(%rsp),%eax
  cf:	83 f8 03             	cmp    $0x3,%eax
  d2:	74 0c                	je     e0 <_Z5test1v+0xe0>
  d4:	83 f8 02             	cmp    $0x2,%eax
  d7:	74 11                	je     ea <_Z5test1v+0xea>
  d9:	83 f8 01             	cmp    $0x1,%eax
  dc:	74 0c                	je     ea <_Z5test1v+0xea>
  de:	eb 0f                	jmp    ef <_Z5test1v+0xef>
  e0:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
  e5:	e8 00 00 00 00       	callq  ea <_Z5test1v+0xea>
  ea:	c6 44 24 38 00       	movb   $0x0,0x38(%rsp)
  ef:	0f b6 44 24 18       	movzbl 0x18(%rsp),%eax
  f4:	83 f8 03             	cmp    $0x3,%eax
  f7:	74 0c                	je     105 <_Z5test1v+0x105>
  f9:	83 f8 02             	cmp    $0x2,%eax
  fc:	74 10                	je     10e <_Z5test1v+0x10e>
  fe:	83 f8 01             	cmp    $0x1,%eax
 101:	74 0b                	je     10e <_Z5test1v+0x10e>
 103:	eb 0e                	jmp    113 <_Z5test1v+0x113>
 105:	48 8d 3c 24          	lea    (%rsp),%rdi
 109:	e8 00 00 00 00       	callq  10e <_Z5test1v+0x10e>
 10e:	c6 44 24 18 00       	movb   $0x0,0x18(%rsp)
 113:	48 89 df             	mov    %rbx,%rdi
 116:	e8 00 00 00 00       	callq  11b <_Z5test1v+0x11b>
 11b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
