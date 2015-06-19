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
  2a:	77 21                	ja     4d <_Z5test1v+0x4d>
  2c:	ff 24 c5 00 00 00 00 	jmpq   *0x0(,%rax,8)
  33:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  38:	e8 00 00 00 00       	callq  3d <_Z5test1v+0x3d>
  3d:	eb 09                	jmp    48 <_Z5test1v+0x48>
  3f:	48 c7 44 24 08 00 00 	movq   $0x0,0x8(%rsp)
  46:	00 00 
  48:	c6 44 24 18 00       	movb   $0x0,0x18(%rsp)
  4d:	89 d8                	mov    %ebx,%eax
  4f:	48 83 c4 20          	add    $0x20,%rsp
  53:	5b                   	pop    %rbx
  54:	c3                   	retq   
  55:	48 89 c3             	mov    %rax,%rbx
  58:	8a 44 24 18          	mov    0x18(%rsp),%al
  5c:	fe c8                	dec    %al
  5e:	0f b6 c0             	movzbl %al,%eax
  61:	83 f8 03             	cmp    $0x3,%eax
  64:	77 21                	ja     87 <_Z5test1v+0x87>
  66:	ff 24 c5 00 00 00 00 	jmpq   *0x0(,%rax,8)
  6d:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  72:	e8 00 00 00 00       	callq  77 <_Z5test1v+0x77>
  77:	eb 09                	jmp    82 <_Z5test1v+0x82>
  79:	48 c7 44 24 08 00 00 	movq   $0x0,0x8(%rsp)
  80:	00 00 
  82:	c6 44 24 18 00       	movb   $0x0,0x18(%rsp)
  87:	48 89 df             	mov    %rbx,%rdi
  8a:	e8 00 00 00 00       	callq  8f <_Z5test1v+0x8f>
  8f:	90                   	nop
