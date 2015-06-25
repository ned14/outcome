   8:	53                   	push   %rbx
   9:	48 83 ec 30          	sub    $0x30,%rsp
   d:	48 89 fb             	mov    %rdi,%rbx
  10:	89 34 24             	mov    %esi,(%rsp)
  13:	c6 44 24 10 01       	movb   $0x1,0x10(%rsp)
  18:	89 74 24 18          	mov    %esi,0x18(%rsp)
  1c:	c6 44 24 28 01       	movb   $0x1,0x28(%rsp)
  21:	48 8d 7c 24 18       	lea    0x18(%rsp),%rdi
  26:	e8 00 00 00 00       	callq  2b <_Z5test1i+0x23>
  2b:	6b 44 24 18 03       	imul   $0x3,0x18(%rsp),%eax
  30:	89 03                	mov    %eax,(%rbx)
  32:	c6 43 10 01          	movb   $0x1,0x10(%rbx)
  36:	8a 44 24 28          	mov    0x28(%rsp),%al
  3a:	fe c8                	dec    %al
  3c:	0f b6 c0             	movzbl %al,%eax
  3f:	83 f8 03             	cmp    $0x3,%eax
  42:	77 16                	ja     5a <_Z5test1i+0x52>
  44:	ff 24 c5 00 00 00 00 	jmpq   *0x0(,%rax,8)
  4b:	48 8d 7c 24 18       	lea    0x18(%rsp),%rdi
  50:	e8 00 00 00 00       	callq  55 <_Z5test1i+0x4d>
  55:	c6 44 24 28 00       	movb   $0x0,0x28(%rsp)
  5a:	8a 44 24 10          	mov    0x10(%rsp),%al
  5e:	fe c8                	dec    %al
  60:	0f b6 c0             	movzbl %al,%eax
  63:	83 f8 03             	cmp    $0x3,%eax
  66:	77 15                	ja     7d <_Z5test1i+0x75>
  68:	ff 24 c5 00 00 00 00 	jmpq   *0x0(,%rax,8)
  6f:	48 8d 3c 24          	lea    (%rsp),%rdi
  73:	e8 00 00 00 00       	callq  78 <_Z5test1i+0x70>
  78:	c6 44 24 10 00       	movb   $0x0,0x10(%rsp)
  7d:	48 89 d8             	mov    %rbx,%rax
  80:	48 83 c4 30          	add    $0x30,%rsp
  84:	5b                   	pop    %rbx
  85:	c3                   	retq   
  86:	48 89 c3             	mov    %rax,%rbx
  89:	8a 44 24 28          	mov    0x28(%rsp),%al
  8d:	fe c8                	dec    %al
  8f:	0f b6 c0             	movzbl %al,%eax
  92:	83 f8 03             	cmp    $0x3,%eax
  95:	77 16                	ja     ad <_Z5test1i+0xa5>
  97:	ff 24 c5 00 00 00 00 	jmpq   *0x0(,%rax,8)
  9e:	48 8d 7c 24 18       	lea    0x18(%rsp),%rdi
  a3:	e8 00 00 00 00       	callq  a8 <_Z5test1i+0xa0>
  a8:	c6 44 24 28 00       	movb   $0x0,0x28(%rsp)
  ad:	8a 44 24 10          	mov    0x10(%rsp),%al
  b1:	fe c8                	dec    %al
  b3:	0f b6 c0             	movzbl %al,%eax
  b6:	83 f8 03             	cmp    $0x3,%eax
  b9:	77 15                	ja     d0 <_Z5test1i+0xc8>
  bb:	ff 24 c5 00 00 00 00 	jmpq   *0x0(,%rax,8)
  c2:	48 8d 3c 24          	lea    (%rsp),%rdi
  c6:	e8 00 00 00 00       	callq  cb <_Z5test1i+0xc3>
  cb:	c6 44 24 10 00       	movb   $0x0,0x10(%rsp)
  d0:	48 89 df             	mov    %rbx,%rdi
  d3:	e8 00 00 00 00       	callq  d8 <_Z5test1i+0xd0>
  d8:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
  df:	00 
