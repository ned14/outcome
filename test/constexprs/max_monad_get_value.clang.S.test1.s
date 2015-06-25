   8:	53                   	push   %rbx
   9:	48 83 ec 20          	sub    $0x20,%rsp
   d:	48 8d 5c 24 08       	lea    0x8(%rsp),%rbx
  12:	48 89 df             	mov    %rbx,%rdi
  15:	e8 00 00 00 00       	callq  1a <_Z5test1v+0x12>
  1a:	48 89 df             	mov    %rbx,%rdi
  1d:	e8 00 00 00 00       	callq  22 <_Z5test1v+0x1a>
  22:	8b 5c 24 08          	mov    0x8(%rsp),%ebx
  26:	8a 44 24 18          	mov    0x18(%rsp),%al
  2a:	fe c8                	dec    %al
  2c:	0f b6 c0             	movzbl %al,%eax
  2f:	83 f8 03             	cmp    $0x3,%eax
  32:	77 16                	ja     4a <_Z5test1v+0x42>
  34:	ff 24 c5 00 00 00 00 	jmpq   *0x0(,%rax,8)
  3b:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  40:	e8 00 00 00 00       	callq  45 <_Z5test1v+0x3d>
  45:	c6 44 24 18 00       	movb   $0x0,0x18(%rsp)
  4a:	89 d8                	mov    %ebx,%eax
  4c:	48 83 c4 20          	add    $0x20,%rsp
  50:	5b                   	pop    %rbx
  51:	c3                   	retq   
  52:	48 89 c3             	mov    %rax,%rbx
  55:	8a 44 24 18          	mov    0x18(%rsp),%al
  59:	fe c8                	dec    %al
  5b:	0f b6 c0             	movzbl %al,%eax
  5e:	83 f8 03             	cmp    $0x3,%eax
  61:	77 16                	ja     79 <_Z5test1v+0x71>
  63:	ff 24 c5 00 00 00 00 	jmpq   *0x0(,%rax,8)
  6a:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  6f:	e8 00 00 00 00       	callq  74 <_Z5test1v+0x6c>
  74:	c6 44 24 18 00       	movb   $0x0,0x18(%rsp)
  79:	48 89 df             	mov    %rbx,%rdi
  7c:	e8 00 00 00 00       	callq  81 <_Z5test1v+0x79>
  81:	66 66 66 66 66 66 2e 	data32 data32 data32 data32 data32 nopw %cs:0x0(%rax,%rax,1)
  88:	0f 1f 84 00 00 00 00 
  8f:	00 
