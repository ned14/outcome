   0:	53                   	push   %rbx
   1:	48 83 ec 20          	sub    $0x20,%rsp
   5:	48 8d 5c 24 08       	lea    0x8(%rsp),%rbx
   a:	48 89 df             	mov    %rbx,%rdi
   d:	e8 00 00 00 00       	callq  12 <_Z5test1v+0x12>
  12:	48 89 df             	mov    %rbx,%rdi
  15:	e8 00 00 00 00       	callq  1a <_Z5test1v+0x1a>
  1a:	8b 5c 24 08          	mov    0x8(%rsp),%ebx
  1e:	8a 44 24 18          	mov    0x18(%rsp),%al
  22:	fe c8                	dec    %al
  24:	0f b6 c0             	movzbl %al,%eax
  27:	83 f8 03             	cmp    $0x3,%eax
  2a:	77 16                	ja     42 <_Z5test1v+0x42>
  2c:	ff 24 c5 00 00 00 00 	jmpq   *0x0(,%rax,8)
  33:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  38:	e8 00 00 00 00       	callq  3d <_Z5test1v+0x3d>
  3d:	c6 44 24 18 00       	movb   $0x0,0x18(%rsp)
  42:	89 d8                	mov    %ebx,%eax
  44:	48 83 c4 20          	add    $0x20,%rsp
  48:	5b                   	pop    %rbx
  49:	c3                   	retq   
  4a:	48 89 c3             	mov    %rax,%rbx
  4d:	8a 44 24 18          	mov    0x18(%rsp),%al
  51:	fe c8                	dec    %al
  53:	0f b6 c0             	movzbl %al,%eax
  56:	83 f8 03             	cmp    $0x3,%eax
  59:	77 16                	ja     71 <_Z5test1v+0x71>
  5b:	ff 24 c5 00 00 00 00 	jmpq   *0x0(,%rax,8)
  62:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  67:	e8 00 00 00 00       	callq  6c <_Z5test1v+0x6c>
  6c:	c6 44 24 18 00       	movb   $0x0,0x18(%rsp)
  71:	48 89 df             	mov    %rbx,%rdi
  74:	e8 00 00 00 00       	callq  79 <_Z5test1v+0x79>
  79:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
