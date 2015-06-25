   8:	41 56                	push   %r14
   a:	53                   	push   %rbx
   b:	48 83 ec 18          	sub    $0x18,%rsp
   f:	48 8d 3c 24          	lea    (%rsp),%rdi
  13:	e8 00 00 00 00       	callq  18 <_Z5test1v+0x10>
  18:	0f b6 4c 24 10       	movzbl 0x10(%rsp),%ecx
  1d:	83 f9 02             	cmp    $0x2,%ecx
  20:	74 30                	je     52 <_Z5test1v+0x4a>
  22:	84 c9                	test   %cl,%cl
  24:	74 22                	je     48 <_Z5test1v+0x40>
  26:	8b 04 24             	mov    (%rsp),%eax
  29:	0f b6 c9             	movzbl %cl,%ecx
  2c:	83 f9 04             	cmp    $0x4,%ecx
  2f:	74 0a                	je     3b <_Z5test1v+0x33>
  31:	83 f9 03             	cmp    $0x3,%ecx
  34:	74 05                	je     3b <_Z5test1v+0x33>
  36:	83 f9 01             	cmp    $0x1,%ecx
  39:	75 05                	jne    40 <_Z5test1v+0x38>
  3b:	c6 44 24 10 00       	movb   $0x0,0x10(%rsp)
  40:	48 83 c4 18          	add    $0x18,%rsp
  44:	5b                   	pop    %rbx
  45:	41 5e                	pop    %r14
  47:	c3                   	retq   
  48:	bf 02 00 00 00       	mov    $0x2,%edi
  4d:	e8 00 00 00 00       	callq  52 <_Z5test1v+0x4a>
  52:	bf 20 00 00 00       	mov    $0x20,%edi
  57:	e8 00 00 00 00       	callq  5c <_Z5test1v+0x54>
  5c:	48 89 c3             	mov    %rax,%rbx
  5f:	8b 34 24             	mov    (%rsp),%esi
  62:	48 8b 54 24 08       	mov    0x8(%rsp),%rdx
  67:	48 89 df             	mov    %rbx,%rdi
  6a:	e8 00 00 00 00       	callq  6f <_Z5test1v+0x67>
  6f:	be 00 00 00 00       	mov    $0x0,%esi
  74:	ba 00 00 00 00       	mov    $0x0,%edx
  79:	48 89 df             	mov    %rbx,%rdi
  7c:	e8 00 00 00 00       	callq  81 <_Z5test1v+0x79>
  81:	49 89 c6             	mov    %rax,%r14
  84:	48 89 df             	mov    %rbx,%rdi
  87:	e8 00 00 00 00       	callq  8c <_Z5test1v+0x84>
  8c:	eb 03                	jmp    91 <_Z5test1v+0x89>
  8e:	49 89 c6             	mov    %rax,%r14
  91:	8a 44 24 10          	mov    0x10(%rsp),%al
  95:	fe c8                	dec    %al
  97:	0f b6 c0             	movzbl %al,%eax
  9a:	83 f8 03             	cmp    $0x3,%eax
  9d:	77 0c                	ja     ab <_Z5test1v+0xa3>
  9f:	ff 24 c5 00 00 00 00 	jmpq   *0x0(,%rax,8)
  a6:	c6 44 24 10 00       	movb   $0x0,0x10(%rsp)
  ab:	4c 89 f7             	mov    %r14,%rdi
  ae:	e8 00 00 00 00       	callq  b3 <_Z5test1v+0xab>
  b3:	66 66 66 66 2e 0f 1f 	data32 data32 data32 nopw %cs:0x0(%rax,%rax,1)
  ba:	84 00 00 00 00 00 
