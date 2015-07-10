   0:	53                   	push   %rbx
   1:	48 83 ec 20          	sub    $0x20,%rsp
   5:	48 8d 5c 24 08       	lea    0x8(%rsp),%rbx
   a:	48 89 df             	mov    %rbx,%rdi
   d:	e8 00 00 00 00       	callq  12 <_Z5test1v+0x12>
  12:	48 89 df             	mov    %rbx,%rdi
  15:	e8 00 00 00 00       	callq  1a <_Z5test1v+0x1a>
  1a:	8b 5c 24 08          	mov    0x8(%rsp),%ebx
  1e:	0f b6 44 24 18       	movzbl 0x18(%rsp),%eax
  23:	83 f8 03             	cmp    $0x3,%eax
  26:	74 0c                	je     34 <_Z5test1v+0x34>
  28:	83 f8 02             	cmp    $0x2,%eax
  2b:	74 11                	je     3e <_Z5test1v+0x3e>
  2d:	83 f8 01             	cmp    $0x1,%eax
  30:	74 0c                	je     3e <_Z5test1v+0x3e>
  32:	eb 0f                	jmp    43 <_Z5test1v+0x43>
  34:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  39:	e8 00 00 00 00       	callq  3e <_Z5test1v+0x3e>
  3e:	c6 44 24 18 00       	movb   $0x0,0x18(%rsp)
  43:	89 d8                	mov    %ebx,%eax
  45:	48 83 c4 20          	add    $0x20,%rsp
  49:	5b                   	pop    %rbx
  4a:	c3                   	retq   
  4b:	48 89 c3             	mov    %rax,%rbx
  4e:	0f b6 44 24 18       	movzbl 0x18(%rsp),%eax
  53:	83 f8 03             	cmp    $0x3,%eax
  56:	74 0c                	je     64 <_Z5test1v+0x64>
  58:	83 f8 02             	cmp    $0x2,%eax
  5b:	74 11                	je     6e <_Z5test1v+0x6e>
  5d:	83 f8 01             	cmp    $0x1,%eax
  60:	74 0c                	je     6e <_Z5test1v+0x6e>
  62:	eb 0f                	jmp    73 <_Z5test1v+0x73>
  64:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  69:	e8 00 00 00 00       	callq  6e <_Z5test1v+0x6e>
  6e:	c6 44 24 18 00       	movb   $0x0,0x18(%rsp)
  73:	48 89 df             	mov    %rbx,%rdi
  76:	e8 00 00 00 00       	callq  7b <_Z5test1v+0x7b>
  7b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
