   8:	53                   	push   %rbx
   9:	48 83 ec 10          	sub    $0x10,%rsp
   d:	48 89 fb             	mov    %rdi,%rbx
  10:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  15:	e8 00 00 00 00       	callq  1a <_Z5test1v+0x12>
  1a:	8a 44 24 0c          	mov    0xc(%rsp),%al
  1e:	84 c0                	test   %al,%al
  20:	75 2e                	jne    50 <_Z5test1v+0x48>
  22:	bf 02 00 00 00       	mov    $0x2,%edi
  27:	e8 00 00 00 00       	callq  2c <_Z5test1v+0x24>
  2c:	eb 2a                	jmp    58 <_Z5test1v+0x50>
  2e:	8a 4c 24 0c          	mov    0xc(%rsp),%cl
  32:	fe c9                	dec    %cl
  34:	0f b6 c9             	movzbl %cl,%ecx
  37:	83 f9 03             	cmp    $0x3,%ecx
  3a:	77 0c                	ja     48 <_Z5test1v+0x40>
  3c:	ff 24 cd 00 00 00 00 	jmpq   *0x0(,%rcx,8)
  43:	c6 44 24 0c 00       	movb   $0x0,0xc(%rsp)
  48:	48 89 c7             	mov    %rax,%rdi
  4b:	e8 00 00 00 00       	callq  50 <_Z5test1v+0x48>
  50:	0f b6 c0             	movzbl %al,%eax
  53:	83 f8 04             	cmp    $0x4,%eax
  56:	74 28                	je     80 <_Z5test1v+0x78>
  58:	6b 4c 24 08 03       	imul   $0x3,0x8(%rsp),%ecx
  5d:	89 0b                	mov    %ecx,(%rbx)
  5f:	c6 43 04 01          	movb   $0x1,0x4(%rbx)
  63:	83 f8 03             	cmp    $0x3,%eax
  66:	74 0a                	je     72 <_Z5test1v+0x6a>
  68:	83 f8 02             	cmp    $0x2,%eax
  6b:	74 05                	je     72 <_Z5test1v+0x6a>
  6d:	83 f8 01             	cmp    $0x1,%eax
  70:	75 05                	jne    77 <_Z5test1v+0x6f>
  72:	c6 44 24 0c 00       	movb   $0x0,0xc(%rsp)
  77:	48 89 d8             	mov    %rbx,%rax
  7a:	48 83 c4 10          	add    $0x10,%rsp
  7e:	5b                   	pop    %rbx
  7f:	c3                   	retq   
  80:	e8 00 00 00 00       	callq  85 <_Z5test1v+0x7d>
  85:	66 66 2e 0f 1f 84 00 	data32 nopw %cs:0x0(%rax,%rax,1)
  8c:	00 00 00 00 
