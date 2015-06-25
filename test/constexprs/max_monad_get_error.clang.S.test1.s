   8:	55                   	push   %rbp
   9:	41 56                	push   %r14
   b:	53                   	push   %rbx
   c:	48 83 ec 20          	sub    $0x20,%rsp
  10:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  15:	e8 00 00 00 00       	callq  1a <_Z5test1v+0x12>
  1a:	0f b6 5c 24 18       	movzbl 0x18(%rsp),%ebx
  1f:	83 fb 02             	cmp    $0x2,%ebx
  22:	75 1c                	jne    40 <_Z5test1v+0x38>
  24:	8b 6c 24 08          	mov    0x8(%rsp),%ebp
  28:	4c 8b 74 24 10       	mov    0x10(%rsp),%r14
  2d:	c6 44 24 18 00       	movb   $0x0,0x18(%rsp)
  32:	89 e8                	mov    %ebp,%eax
  34:	4c 89 f2             	mov    %r14,%rdx
  37:	48 83 c4 20          	add    $0x20,%rsp
  3b:	5b                   	pop    %rbx
  3c:	41 5e                	pop    %r14
  3e:	5d                   	pop    %rbp
  3f:	c3                   	retq   
  40:	84 db                	test   %bl,%bl
  42:	74 2a                	je     6e <_Z5test1v+0x66>
  44:	e8 00 00 00 00       	callq  49 <_Z5test1v+0x41>
  49:	49 89 c6             	mov    %rax,%r14
  4c:	31 ed                	xor    %ebp,%ebp
  4e:	0f b6 c3             	movzbl %bl,%eax
  51:	83 f8 04             	cmp    $0x4,%eax
  54:	74 d7                	je     2d <_Z5test1v+0x25>
  56:	83 f8 03             	cmp    $0x3,%eax
  59:	75 0c                	jne    67 <_Z5test1v+0x5f>
  5b:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  60:	e8 00 00 00 00       	callq  65 <_Z5test1v+0x5d>
  65:	eb c6                	jmp    2d <_Z5test1v+0x25>
  67:	83 f8 01             	cmp    $0x1,%eax
  6a:	74 c1                	je     2d <_Z5test1v+0x25>
  6c:	eb c4                	jmp    32 <_Z5test1v+0x2a>
  6e:	bf 02 00 00 00       	mov    $0x2,%edi
  73:	e8 00 00 00 00       	callq  78 <_Z5test1v+0x70>
  78:	eb aa                	jmp    24 <_Z5test1v+0x1c>
  7a:	48 89 c3             	mov    %rax,%rbx
  7d:	8a 44 24 18          	mov    0x18(%rsp),%al
  81:	fe c8                	dec    %al
  83:	0f b6 c0             	movzbl %al,%eax
  86:	83 f8 03             	cmp    $0x3,%eax
  89:	77 16                	ja     a1 <_Z5test1v+0x99>
  8b:	ff 24 c5 00 00 00 00 	jmpq   *0x0(,%rax,8)
  92:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  97:	e8 00 00 00 00       	callq  9c <_Z5test1v+0x94>
  9c:	c6 44 24 18 00       	movb   $0x0,0x18(%rsp)
  a1:	48 89 df             	mov    %rbx,%rdi
  a4:	e8 00 00 00 00       	callq  a9 <_Z5test1v+0xa1>
  a9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
