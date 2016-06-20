   0:	53                   	push   %rbx
   1:	48 83 ec 10          	sub    $0x10,%rsp
   5:	48 89 fb             	mov    %rdi,%rbx
   8:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
   d:	e8 00 00 00 00       	callq  12 <_Z5test1v+0x12>
  12:	0f b6 44 24 0c       	movzbl 0xc(%rsp),%eax
  17:	85 c0                	test   %eax,%eax
  19:	74 28                	je     43 <_Z5test1v+0x43>
  1b:	6b 4c 24 08 03       	imul   $0x3,0x8(%rsp),%ecx
  20:	89 0b                	mov    %ecx,(%rbx)
  22:	c6 43 04 01          	movb   $0x1,0x4(%rbx)
  26:	83 f8 03             	cmp    $0x3,%eax
  29:	74 0a                	je     35 <_Z5test1v+0x35>
  2b:	83 f8 02             	cmp    $0x2,%eax
  2e:	74 05                	je     35 <_Z5test1v+0x35>
  30:	83 f8 01             	cmp    $0x1,%eax
  33:	75 05                	jne    3a <_Z5test1v+0x3a>
  35:	c6 44 24 0c 00       	movb   $0x0,0xc(%rsp)
  3a:	48 89 d8             	mov    %rbx,%rax
  3d:	48 83 c4 10          	add    $0x10,%rsp
  41:	5b                   	pop    %rbx
  42:	c3                   	retq   
  43:	bf 02 00 00 00       	mov    $0x2,%edi
  48:	e8 00 00 00 00       	callq  4d <_Z5test1v+0x4d>
  4d:	eb cc                	jmp    1b <_Z5test1v+0x1b>
  4f:	0f b6 4c 24 0c       	movzbl 0xc(%rsp),%ecx
  54:	83 f9 03             	cmp    $0x3,%ecx
  57:	74 0a                	je     63 <_Z5test1v+0x63>
  59:	83 f9 02             	cmp    $0x2,%ecx
  5c:	74 05                	je     63 <_Z5test1v+0x63>
  5e:	83 f9 01             	cmp    $0x1,%ecx
  61:	75 05                	jne    68 <_Z5test1v+0x68>
  63:	c6 44 24 0c 00       	movb   $0x0,0xc(%rsp)
  68:	48 89 c7             	mov    %rax,%rdi
  6b:	e8 00 00 00 00       	callq  70 replaced
  70:	c3                   	retq   
  71:	66 66 66 66 66 66 2e 	data16 data16 data16 data16 data16 nopw %cs:0x0(%rax,%rax,1)
  78:	0f 1f 84 00 00 00 00 
  7f:	00 

