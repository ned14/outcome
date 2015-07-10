   0:	41 57                	push   %r15
   2:	41 56                	push   %r14
   4:	53                   	push   %rbx
   5:	48 83 ec 20          	sub    $0x20,%rsp
   9:	49 89 fe             	mov    %rdi,%r14
   c:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  11:	e8 00 00 00 00       	callq  16 <_Z5test1v+0x16>
  16:	8b 5c 24 08          	mov    0x8(%rsp),%ebx
  1a:	0f b6 44 24 18       	movzbl 0x18(%rsp),%eax
  1f:	83 f8 02             	cmp    $0x2,%eax
  22:	74 3a                	je     5e <_Z5test1v+0x5e>
  24:	84 c0                	test   %al,%al
  26:	74 2c                	je     54 <_Z5test1v+0x54>
  28:	8d 0c 5b             	lea    (%rbx,%rbx,2),%ecx
  2b:	41 89 0e             	mov    %ecx,(%r14)
  2e:	41 c6 46 10 01       	movb   $0x1,0x10(%r14)
  33:	83 f8 03             	cmp    $0x3,%eax
  36:	74 0a                	je     42 <_Z5test1v+0x42>
  38:	83 f8 02             	cmp    $0x2,%eax
  3b:	74 05                	je     42 <_Z5test1v+0x42>
  3d:	83 f8 01             	cmp    $0x1,%eax
  40:	75 05                	jne    47 <_Z5test1v+0x47>
  42:	c6 44 24 18 00       	movb   $0x0,0x18(%rsp)
  47:	4c 89 f0             	mov    %r14,%rax
  4a:	48 83 c4 20          	add    $0x20,%rsp
  4e:	5b                   	pop    %rbx
  4f:	41 5e                	pop    %r14
  51:	41 5f                	pop    %r15
  53:	c3                   	retq   
  54:	bf 02 00 00 00       	mov    $0x2,%edi
  59:	e8 00 00 00 00       	callq  5e <_Z5test1v+0x5e>
  5e:	4c 8b 7c 24 10       	mov    0x10(%rsp),%r15
  63:	bf 20 00 00 00       	mov    $0x20,%edi
  68:	e8 00 00 00 00       	callq  6d <_Z5test1v+0x6d>
  6d:	49 89 c6             	mov    %rax,%r14
  70:	4c 89 f7             	mov    %r14,%rdi
  73:	89 de                	mov    %ebx,%esi
  75:	4c 89 fa             	mov    %r15,%rdx
  78:	e8 00 00 00 00       	callq  7d <_Z5test1v+0x7d>
  7d:	be 00 00 00 00       	mov    $0x0,%esi
  82:	ba 00 00 00 00       	mov    $0x0,%edx
  87:	4c 89 f7             	mov    %r14,%rdi
  8a:	e8 00 00 00 00       	callq  8f <_Z5test1v+0x8f>
  8f:	48 89 c3             	mov    %rax,%rbx
  92:	4c 89 f7             	mov    %r14,%rdi
  95:	e8 00 00 00 00       	callq  9a <_Z5test1v+0x9a>
  9a:	eb 03                	jmp    9f <_Z5test1v+0x9f>
  9c:	48 89 c3             	mov    %rax,%rbx
  9f:	0f b6 44 24 18       	movzbl 0x18(%rsp),%eax
  a4:	83 f8 03             	cmp    $0x3,%eax
  a7:	74 0a                	je     b3 <_Z5test1v+0xb3>
  a9:	83 f8 02             	cmp    $0x2,%eax
  ac:	74 05                	je     b3 <_Z5test1v+0xb3>
  ae:	83 f8 01             	cmp    $0x1,%eax
  b1:	75 05                	jne    b8 <_Z5test1v+0xb8>
  b3:	c6 44 24 18 00       	movb   $0x0,0x18(%rsp)
  b8:	48 89 df             	mov    %rbx,%rdi
  bb:	e8 00 00 00 00       	callq  c0 replaced
  c0:	c3                   	retq   
  c1:	66 66 66 66 66 66 2e 	data32 data32 data32 data32 data32 nopw %cs:0x0(%rax,%rax,1)
  c8:	0f 1f 84 00 00 00 00 
  cf:	00 

