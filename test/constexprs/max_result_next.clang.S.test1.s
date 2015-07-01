   0:	41 57                	push   %r15
   2:	41 56                	push   %r14
   4:	53                   	push   %rbx
   5:	48 83 ec 20          	sub    $0x20,%rsp
   9:	48 89 fb             	mov    %rdi,%rbx
   c:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  11:	e8 00 00 00 00       	callq  16 <_Z5test1v+0x16>
  16:	0f b6 44 24 18       	movzbl 0x18(%rsp),%eax
  1b:	48 83 f8 04          	cmp    $0x4,%rax
  1f:	76 0e                	jbe    2f <_Z5test1v+0x2f>
  21:	c6 43 10 01          	movb   $0x1,0x10(%rbx)
  25:	0f b6 c0             	movzbl %al,%eax
  28:	83 f8 03             	cmp    $0x3,%eax
  2b:	75 1d                	jne    4a <_Z5test1v+0x4a>
  2d:	eb 16                	jmp    45 <_Z5test1v+0x45>
  2f:	44 8b 74 24 08       	mov    0x8(%rsp),%r14d
  34:	ff 24 c5 00 00 00 00 	jmpq   *0x0(,%rax,8)
  3b:	43 8d 04 76          	lea    (%r14,%r14,2),%eax
  3f:	89 03                	mov    %eax,(%rbx)
  41:	c6 43 10 01          	movb   $0x1,0x10(%rbx)
  45:	c6 44 24 18 00       	movb   $0x0,0x18(%rsp)
  4a:	48 89 d8             	mov    %rbx,%rax
  4d:	48 83 c4 20          	add    $0x20,%rsp
  51:	5b                   	pop    %rbx
  52:	41 5e                	pop    %r14
  54:	41 5f                	pop    %r15
  56:	c3                   	retq   
  57:	bf 02 00 00 00       	mov    $0x2,%edi
  5c:	e8 00 00 00 00       	callq  61 <_Z5test1v+0x61>
  61:	4c 8b 7c 24 10       	mov    0x10(%rsp),%r15
  66:	bf 20 00 00 00       	mov    $0x20,%edi
  6b:	e8 00 00 00 00       	callq  70 <_Z5test1v+0x70>
  70:	48 89 c3             	mov    %rax,%rbx
  73:	48 89 df             	mov    %rbx,%rdi
  76:	44 89 f6             	mov    %r14d,%esi
  79:	4c 89 fa             	mov    %r15,%rdx
  7c:	e8 00 00 00 00       	callq  81 <_Z5test1v+0x81>
  81:	be 00 00 00 00       	mov    $0x0,%esi
  86:	ba 00 00 00 00       	mov    $0x0,%edx
  8b:	48 89 df             	mov    %rbx,%rdi
  8e:	e8 00 00 00 00       	callq  93 <_Z5test1v+0x93>
  93:	e8 00 00 00 00       	callq  98 <_Z5test1v+0x98>
  98:	49 89 c6             	mov    %rax,%r14
  9b:	48 89 df             	mov    %rbx,%rdi
  9e:	e8 00 00 00 00       	callq  a3 <_Z5test1v+0xa3>
  a3:	eb 05                	jmp    aa <_Z5test1v+0xaa>
  a5:	eb 00                	jmp    a7 <_Z5test1v+0xa7>
  a7:	49 89 c6             	mov    %rax,%r14
  aa:	8a 44 24 18          	mov    0x18(%rsp),%al
  ae:	fe c8                	dec    %al
  b0:	0f b6 c0             	movzbl %al,%eax
  b3:	83 f8 03             	cmp    $0x3,%eax
  b6:	77 0c                	ja     c4 <_Z5test1v+0xc4>
  b8:	ff 24 c5 00 00 00 00 	jmpq   *0x0(,%rax,8)
  bf:	c6 44 24 18 00       	movb   $0x0,0x18(%rsp)
  c4:	4c 89 f7             	mov    %r14,%rdi
  c7:	e8 00 00 00 00       	callq  cc <_Z5test1v+0xcc>
  cc:	0f 1f 40 00          	nopl   0x0(%rax)
