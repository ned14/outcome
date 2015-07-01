   0:	41 56                	push   %r14
   2:	53                   	push   %rbx
   3:	48 83 ec 18          	sub    $0x18,%rsp
   7:	48 8d 3c 24          	lea    (%rsp),%rdi
   b:	e8 00 00 00 00       	callq  10 <_Z5test1v+0x10>
  10:	0f b6 4c 24 10       	movzbl 0x10(%rsp),%ecx
  15:	83 f9 02             	cmp    $0x2,%ecx
  18:	74 30                	je     4a <_Z5test1v+0x4a>
  1a:	84 c9                	test   %cl,%cl
  1c:	74 22                	je     40 <_Z5test1v+0x40>
  1e:	8b 04 24             	mov    (%rsp),%eax
  21:	0f b6 c9             	movzbl %cl,%ecx
  24:	83 f9 04             	cmp    $0x4,%ecx
  27:	74 0a                	je     33 <_Z5test1v+0x33>
  29:	83 f9 03             	cmp    $0x3,%ecx
  2c:	74 05                	je     33 <_Z5test1v+0x33>
  2e:	83 f9 01             	cmp    $0x1,%ecx
  31:	75 05                	jne    38 <_Z5test1v+0x38>
  33:	c6 44 24 10 00       	movb   $0x0,0x10(%rsp)
  38:	48 83 c4 18          	add    $0x18,%rsp
  3c:	5b                   	pop    %rbx
  3d:	41 5e                	pop    %r14
  3f:	c3                   	retq   
  40:	bf 02 00 00 00       	mov    $0x2,%edi
  45:	e8 00 00 00 00       	callq  4a <_Z5test1v+0x4a>
  4a:	bf 20 00 00 00       	mov    $0x20,%edi
  4f:	e8 00 00 00 00       	callq  54 <_Z5test1v+0x54>
  54:	48 89 c3             	mov    %rax,%rbx
  57:	8b 34 24             	mov    (%rsp),%esi
  5a:	48 8b 54 24 08       	mov    0x8(%rsp),%rdx
  5f:	48 89 df             	mov    %rbx,%rdi
  62:	e8 00 00 00 00       	callq  67 <_Z5test1v+0x67>
  67:	be 00 00 00 00       	mov    $0x0,%esi
  6c:	ba 00 00 00 00       	mov    $0x0,%edx
  71:	48 89 df             	mov    %rbx,%rdi
  74:	e8 00 00 00 00       	callq  79 <_Z5test1v+0x79>
  79:	49 89 c6             	mov    %rax,%r14
  7c:	48 89 df             	mov    %rbx,%rdi
  7f:	e8 00 00 00 00       	callq  84 <_Z5test1v+0x84>
  84:	eb 03                	jmp    89 <_Z5test1v+0x89>
  86:	49 89 c6             	mov    %rax,%r14
  89:	8a 44 24 10          	mov    0x10(%rsp),%al
  8d:	fe c8                	dec    %al
  8f:	0f b6 c0             	movzbl %al,%eax
  92:	83 f8 03             	cmp    $0x3,%eax
  95:	77 0c                	ja     a3 <_Z5test1v+0xa3>
  97:	ff 24 c5 00 00 00 00 	jmpq   *0x0(,%rax,8)
  9e:	c6 44 24 10 00       	movb   $0x0,0x10(%rsp)
  a3:	4c 89 f7             	mov    %r14,%rdi
  a6:	e8 00 00 00 00       	callq  ab <_Z5test1v+0xab>
  ab:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
