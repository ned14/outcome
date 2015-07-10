   0:	53                   	push   %rbx
   1:	48 83 ec 30          	sub    $0x30,%rsp
   5:	c7 44 24 18 05 00 00 	movl   $0x5,0x18(%rsp)
   c:	00 
   d:	c6 44 24 28 01       	movb   $0x1,0x28(%rsp)
  12:	c7 04 24 05 00 00 00 	movl   $0x5,(%rsp)
  19:	c6 44 24 10 01       	movb   $0x1,0x10(%rsp)
  1e:	48 8d 3c 24          	lea    (%rsp),%rdi
  22:	e8 00 00 00 00       	callq  27 <_Z5test1v+0x27>
  27:	8b 1c 24             	mov    (%rsp),%ebx
  2a:	0f b6 44 24 10       	movzbl 0x10(%rsp),%eax
  2f:	83 f8 03             	cmp    $0x3,%eax
  32:	74 0c                	je     40 <_Z5test1v+0x40>
  34:	83 f8 02             	cmp    $0x2,%eax
  37:	74 10                	je     49 <_Z5test1v+0x49>
  39:	83 f8 01             	cmp    $0x1,%eax
  3c:	74 0b                	je     49 <_Z5test1v+0x49>
  3e:	eb 0e                	jmp    4e <_Z5test1v+0x4e>
  40:	48 8d 3c 24          	lea    (%rsp),%rdi
  44:	e8 00 00 00 00       	callq  49 <_Z5test1v+0x49>
  49:	c6 44 24 10 00       	movb   $0x0,0x10(%rsp)
  4e:	0f b6 44 24 28       	movzbl 0x28(%rsp),%eax
  53:	83 f8 03             	cmp    $0x3,%eax
  56:	74 0c                	je     64 <_Z5test1v+0x64>
  58:	83 f8 02             	cmp    $0x2,%eax
  5b:	74 11                	je     6e <_Z5test1v+0x6e>
  5d:	83 f8 01             	cmp    $0x1,%eax
  60:	74 0c                	je     6e <_Z5test1v+0x6e>
  62:	eb 0f                	jmp    73 <_Z5test1v+0x73>
  64:	48 8d 7c 24 18       	lea    0x18(%rsp),%rdi
  69:	e8 00 00 00 00       	callq  6e <_Z5test1v+0x6e>
  6e:	c6 44 24 28 00       	movb   $0x0,0x28(%rsp)
  73:	89 d8                	mov    %ebx,%eax
  75:	48 83 c4 30          	add    $0x30,%rsp
  79:	5b                   	pop    %rbx
  7a:	c3                   	retq   
  7b:	48 89 c3             	mov    %rax,%rbx
  7e:	0f b6 44 24 10       	movzbl 0x10(%rsp),%eax
  83:	83 f8 03             	cmp    $0x3,%eax
  86:	74 0c                	je     94 <_Z5test1v+0x94>
  88:	83 f8 02             	cmp    $0x2,%eax
  8b:	74 10                	je     9d <_Z5test1v+0x9d>
  8d:	83 f8 01             	cmp    $0x1,%eax
  90:	74 0b                	je     9d <_Z5test1v+0x9d>
  92:	eb 0e                	jmp    a2 <_Z5test1v+0xa2>
  94:	48 8d 3c 24          	lea    (%rsp),%rdi
  98:	e8 00 00 00 00       	callq  9d <_Z5test1v+0x9d>
  9d:	c6 44 24 10 00       	movb   $0x0,0x10(%rsp)
  a2:	0f b6 44 24 28       	movzbl 0x28(%rsp),%eax
  a7:	83 f8 03             	cmp    $0x3,%eax
  aa:	74 0c                	je     b8 <_Z5test1v+0xb8>
  ac:	83 f8 02             	cmp    $0x2,%eax
  af:	74 11                	je     c2 <_Z5test1v+0xc2>
  b1:	83 f8 01             	cmp    $0x1,%eax
  b4:	74 0c                	je     c2 <_Z5test1v+0xc2>
  b6:	eb 0f                	jmp    c7 <_Z5test1v+0xc7>
  b8:	48 8d 7c 24 18       	lea    0x18(%rsp),%rdi
  bd:	e8 00 00 00 00       	callq  c2 <_Z5test1v+0xc2>
  c2:	c6 44 24 28 00       	movb   $0x0,0x28(%rsp)
  c7:	48 89 df             	mov    %rbx,%rdi
  ca:	e8 00 00 00 00       	callq  cf <_Z5test1v+0xcf>
  cf:	90                   	nop
