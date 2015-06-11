   0:	53                   	push   %rbx
   1:	48 83 ec 20          	sub    $0x20,%rsp
   5:	c7 44 24 08 05 00 00 	movl   $0x5,0x8(%rsp)
   c:	00 
   d:	c6 44 24 18 01       	movb   $0x1,0x18(%rsp)
  12:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  17:	e8 00 00 00 00       	callq  1c <_Z5test1v+0x1c>
  1c:	8b 5c 24 08          	mov    0x8(%rsp),%ebx
  20:	8a 44 24 18          	mov    0x18(%rsp),%al
  24:	fe c8                	dec    %al
  26:	0f b6 c0             	movzbl %al,%eax
  29:	83 f8 03             	cmp    $0x3,%eax
  2c:	77 21                	ja     4f <_Z5test1v+0x4f>
  2e:	ff 24 c5 00 00 00 00 	jmpq   *0x0(,%rax,8)
  35:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  3a:	e8 00 00 00 00       	callq  3f <_Z5test1v+0x3f>
  3f:	eb 09                	jmp    4a <_Z5test1v+0x4a>
  41:	48 c7 44 24 08 00 00 	movq   $0x0,0x8(%rsp)
  48:	00 00 
  4a:	c6 44 24 18 00       	movb   $0x0,0x18(%rsp)
  4f:	89 d8                	mov    %ebx,%eax
  51:	48 83 c4 20          	add    $0x20,%rsp
  55:	5b                   	pop    %rbx
  56:	c3                   	retq   
  57:	48 89 c3             	mov    %rax,%rbx
  5a:	8a 44 24 18          	mov    0x18(%rsp),%al
  5e:	fe c8                	dec    %al
  60:	0f b6 c0             	movzbl %al,%eax
  63:	83 f8 03             	cmp    $0x3,%eax
  66:	77 21                	ja     89 <_Z5test1v+0x89>
  68:	ff 24 c5 00 00 00 00 	jmpq   *0x0(,%rax,8)
  6f:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  74:	e8 00 00 00 00       	callq  79 <_Z5test1v+0x79>
  79:	eb 09                	jmp    84 <_Z5test1v+0x84>
  7b:	48 c7 44 24 08 00 00 	movq   $0x0,0x8(%rsp)
  82:	00 00 
  84:	c6 44 24 18 00       	movb   $0x0,0x18(%rsp)
  89:	48 89 df             	mov    %rbx,%rdi
  8c:	e8 00 00 00 00       	callq  91 <_Z5test1v+0x91>
  91:	66 66 66 66 66 66 2e 	data32 data32 data32 data32 data32 nopw %cs:0x0(%rax,%rax,1)
  98:	0f 1f 84 00 00 00 00 
  9f:	00 
