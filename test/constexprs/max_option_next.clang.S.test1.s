   0:	53                   	push   %rbx
   1:	48 83 ec 10          	sub    $0x10,%rsp
   5:	48 89 fb             	mov    %rdi,%rbx
   8:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
   d:	e8 00 00 00 00       	callq  12 <_Z5test1v+0x12>
  12:	8a 44 24 0c          	mov    0xc(%rsp),%al
  16:	84 c0                	test   %al,%al
  18:	75 2e                	jne    48 <_Z5test1v+0x48>
  1a:	bf 02 00 00 00       	mov    $0x2,%edi
  1f:	e8 00 00 00 00       	callq  24 <_Z5test1v+0x24>
  24:	eb 2a                	jmp    50 <_Z5test1v+0x50>
  26:	8a 4c 24 0c          	mov    0xc(%rsp),%cl
  2a:	fe c9                	dec    %cl
  2c:	0f b6 c9             	movzbl %cl,%ecx
  2f:	83 f9 03             	cmp    $0x3,%ecx
  32:	77 0c                	ja     40 <_Z5test1v+0x40>
  34:	ff 24 cd 00 00 00 00 	jmpq   *0x0(,%rcx,8)
  3b:	c6 44 24 0c 00       	movb   $0x0,0xc(%rsp)
  40:	48 89 c7             	mov    %rax,%rdi
  43:	e8 00 00 00 00       	callq  48 <_Z5test1v+0x48>
  48:	0f b6 c0             	movzbl %al,%eax
  4b:	83 f8 04             	cmp    $0x4,%eax
  4e:	74 28                	je     78 <_Z5test1v+0x78>
  50:	6b 4c 24 08 03       	imul   $0x3,0x8(%rsp),%ecx
  55:	89 0b                	mov    %ecx,(%rbx)
  57:	c6 43 04 01          	movb   $0x1,0x4(%rbx)
  5b:	83 f8 03             	cmp    $0x3,%eax
  5e:	74 0a                	je     6a <_Z5test1v+0x6a>
  60:	83 f8 02             	cmp    $0x2,%eax
  63:	74 05                	je     6a <_Z5test1v+0x6a>
  65:	83 f8 01             	cmp    $0x1,%eax
  68:	75 05                	jne    6f <_Z5test1v+0x6f>
  6a:	c6 44 24 0c 00       	movb   $0x0,0xc(%rsp)
  6f:	48 89 d8             	mov    %rbx,%rax
  72:	48 83 c4 10          	add    $0x10,%rsp
  76:	5b                   	pop    %rbx
  77:	c3                   	retq   
  78:	e8 00 00 00 00       	callq  7d <_Z5test1v+0x7d>
  7d:	0f 1f 00             	nopl   (%rax)
