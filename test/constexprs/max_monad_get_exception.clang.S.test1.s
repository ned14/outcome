   0:	41 56                	push   %r14
   2:	53                   	push   %rbx
   3:	48 83 ec 38          	sub    $0x38,%rsp
   7:	48 89 fb             	mov    %rdi,%rbx
   a:	48 8d 3c 24          	lea    (%rsp),%rdi
   e:	e8 00 00 00 00       	callq  13 <_Z5test1v+0x13>
  13:	0f b6 44 24 10       	movzbl 0x10(%rsp),%eax
  18:	83 f8 02             	cmp    $0x2,%eax
  1b:	74 16                	je     33 <_Z5test1v+0x33>
  1d:	0f b6 c8             	movzbl %al,%ecx
  20:	83 f9 03             	cmp    $0x3,%ecx
  23:	75 67                	jne    8c <_Z5test1v+0x8c>
  25:	48 8d 34 24          	lea    (%rsp),%rsi
  29:	48 89 df             	mov    %rbx,%rdi
  2c:	e8 00 00 00 00       	callq  31 <_Z5test1v+0x31>
  31:	eb 2a                	jmp    5d <_Z5test1v+0x5d>
  33:	8b 34 24             	mov    (%rsp),%esi
  36:	48 8b 54 24 08       	mov    0x8(%rsp),%rdx
  3b:	48 8d 7c 24 18       	lea    0x18(%rsp),%rdi
  40:	e8 00 00 00 00       	callq  45 <_Z5test1v+0x45>
  45:	4c 8d 74 24 18       	lea    0x18(%rsp),%r14
  4a:	48 89 df             	mov    %rbx,%rdi
  4d:	4c 89 f6             	mov    %r14,%rsi
  50:	e8 00 00 00 00       	callq  55 <_Z5test1v+0x55>
  55:	4c 89 f7             	mov    %r14,%rdi
  58:	e8 00 00 00 00       	callq  5d <_Z5test1v+0x5d>
  5d:	0f b6 44 24 10       	movzbl 0x10(%rsp),%eax
  62:	83 f8 03             	cmp    $0x3,%eax
  65:	74 0c                	je     73 <_Z5test1v+0x73>
  67:	83 f8 02             	cmp    $0x2,%eax
  6a:	74 10                	je     7c <_Z5test1v+0x7c>
  6c:	83 f8 01             	cmp    $0x1,%eax
  6f:	74 0b                	je     7c <_Z5test1v+0x7c>
  71:	eb 0e                	jmp    81 <_Z5test1v+0x81>
  73:	48 8d 3c 24          	lea    (%rsp),%rdi
  77:	e8 00 00 00 00       	callq  7c <_Z5test1v+0x7c>
  7c:	c6 44 24 10 00       	movb   $0x0,0x10(%rsp)
  81:	48 89 d8             	mov    %rbx,%rax
  84:	48 83 c4 38          	add    $0x38,%rsp
  88:	5b                   	pop    %rbx
  89:	41 5e                	pop    %r14
  8b:	c3                   	retq   
  8c:	84 c0                	test   %al,%al
  8e:	74 0a                	je     9a <_Z5test1v+0x9a>
  90:	48 89 df             	mov    %rbx,%rdi
  93:	e8 00 00 00 00       	callq  98 <_Z5test1v+0x98>
  98:	eb c3                	jmp    5d <_Z5test1v+0x5d>
  9a:	bf 02 00 00 00       	mov    $0x2,%edi
  9f:	e8 00 00 00 00       	callq  a4 <_Z5test1v+0xa4>
  a4:	eb ea                	jmp    90 <_Z5test1v+0x90>
  a6:	48 89 c3             	mov    %rax,%rbx
  a9:	0f b6 44 24 10       	movzbl 0x10(%rsp),%eax
  ae:	83 f8 03             	cmp    $0x3,%eax
  b1:	74 0c                	je     bf <_Z5test1v+0xbf>
  b3:	83 f8 02             	cmp    $0x2,%eax
  b6:	74 10                	je     c8 <_Z5test1v+0xc8>
  b8:	83 f8 01             	cmp    $0x1,%eax
  bb:	74 0b                	je     c8 <_Z5test1v+0xc8>
  bd:	eb 0e                	jmp    cd <_Z5test1v+0xcd>
  bf:	48 8d 3c 24          	lea    (%rsp),%rdi
  c3:	e8 00 00 00 00       	callq  c8 <_Z5test1v+0xc8>
  c8:	c6 44 24 10 00       	movb   $0x0,0x10(%rsp)
  cd:	48 89 df             	mov    %rbx,%rdi
  d0:	e8 00 00 00 00       	callq  d5 <_Z5test1v+0xd5>
  d5:	66 66 2e 0f 1f 84 00 	data32 nopw %cs:0x0(%rax,%rax,1)
  dc:	00 00 00 00 
