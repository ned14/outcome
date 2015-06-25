   8:	41 57                	push   %r15
   a:	41 56                	push   %r14
   c:	53                   	push   %rbx
   d:	48 83 ec 20          	sub    $0x20,%rsp
  11:	48 89 fb             	mov    %rdi,%rbx
  14:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  19:	e8 00 00 00 00       	callq  1e <_Z5test1v+0x16>
  1e:	0f b6 44 24 18       	movzbl 0x18(%rsp),%eax
  23:	48 83 f8 04          	cmp    $0x4,%rax
  27:	76 0e                	jbe    37 <_Z5test1v+0x2f>
  29:	c6 43 10 01          	movb   $0x1,0x10(%rbx)
  2d:	0f b6 c0             	movzbl %al,%eax
  30:	83 f8 03             	cmp    $0x3,%eax
  33:	75 1d                	jne    52 <_Z5test1v+0x4a>
  35:	eb 16                	jmp    4d <_Z5test1v+0x45>
  37:	44 8b 74 24 08       	mov    0x8(%rsp),%r14d
  3c:	ff 24 c5 00 00 00 00 	jmpq   *0x0(,%rax,8)
  43:	43 8d 04 76          	lea    (%r14,%r14,2),%eax
  47:	89 03                	mov    %eax,(%rbx)
  49:	c6 43 10 01          	movb   $0x1,0x10(%rbx)
  4d:	c6 44 24 18 00       	movb   $0x0,0x18(%rsp)
  52:	48 89 d8             	mov    %rbx,%rax
  55:	48 83 c4 20          	add    $0x20,%rsp
  59:	5b                   	pop    %rbx
  5a:	41 5e                	pop    %r14
  5c:	41 5f                	pop    %r15
  5e:	c3                   	retq   
  5f:	bf 02 00 00 00       	mov    $0x2,%edi
  64:	e8 00 00 00 00       	callq  69 <_Z5test1v+0x61>
  69:	4c 8b 7c 24 10       	mov    0x10(%rsp),%r15
  6e:	bf 20 00 00 00       	mov    $0x20,%edi
  73:	e8 00 00 00 00       	callq  78 <_Z5test1v+0x70>
  78:	48 89 c3             	mov    %rax,%rbx
  7b:	48 89 df             	mov    %rbx,%rdi
  7e:	44 89 f6             	mov    %r14d,%esi
  81:	4c 89 fa             	mov    %r15,%rdx
  84:	e8 00 00 00 00       	callq  89 <_Z5test1v+0x81>
  89:	be 00 00 00 00       	mov    $0x0,%esi
  8e:	ba 00 00 00 00       	mov    $0x0,%edx
  93:	48 89 df             	mov    %rbx,%rdi
  96:	e8 00 00 00 00       	callq  9b <_Z5test1v+0x93>
  9b:	e8 00 00 00 00       	callq  a0 <_Z5test1v+0x98>
  a0:	49 89 c6             	mov    %rax,%r14
  a3:	48 89 df             	mov    %rbx,%rdi
  a6:	e8 00 00 00 00       	callq  ab <_Z5test1v+0xa3>
  ab:	eb 05                	jmp    b2 <_Z5test1v+0xaa>
  ad:	eb 00                	jmp    af <_Z5test1v+0xa7>
  af:	49 89 c6             	mov    %rax,%r14
  b2:	8a 44 24 18          	mov    0x18(%rsp),%al
  b6:	fe c8                	dec    %al
  b8:	0f b6 c0             	movzbl %al,%eax
  bb:	83 f8 03             	cmp    $0x3,%eax
  be:	77 0c                	ja     cc <_Z5test1v+0xc4>
  c0:	ff 24 c5 00 00 00 00 	jmpq   *0x0(,%rax,8)
  c7:	c6 44 24 18 00       	movb   $0x0,0x18(%rsp)
  cc:	4c 89 f7             	mov    %r14,%rdi
  cf:	e8 00 00 00 00       	callq  d4 <_Z5test1v+0xcc>
  d4:	66 66 66 2e 0f 1f 84 	data32 data32 nopw %cs:0x0(%rax,%rax,1)
  db:	00 00 00 00 00 
