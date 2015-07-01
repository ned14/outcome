   0:	53                   	push   %rbx
   1:	48 83 ec 30          	sub    $0x30,%rsp
   5:	48 89 fb             	mov    %rdi,%rbx
   8:	89 34 24             	mov    %esi,(%rsp)
   b:	c6 44 24 10 01       	movb   $0x1,0x10(%rsp)
  10:	89 74 24 18          	mov    %esi,0x18(%rsp)
  14:	c6 44 24 28 01       	movb   $0x1,0x28(%rsp)
  19:	48 8d 7c 24 18       	lea    0x18(%rsp),%rdi
  1e:	e8 00 00 00 00       	callq  23 <_Z5test1i+0x23>
  23:	6b 44 24 18 03       	imul   $0x3,0x18(%rsp),%eax
  28:	89 03                	mov    %eax,(%rbx)
  2a:	c6 43 10 01          	movb   $0x1,0x10(%rbx)
  2e:	8a 44 24 28          	mov    0x28(%rsp),%al
  32:	fe c8                	dec    %al
  34:	0f b6 c0             	movzbl %al,%eax
  37:	83 f8 03             	cmp    $0x3,%eax
  3a:	77 16                	ja     52 <_Z5test1i+0x52>
  3c:	ff 24 c5 00 00 00 00 	jmpq   *0x0(,%rax,8)
  43:	48 8d 7c 24 18       	lea    0x18(%rsp),%rdi
  48:	e8 00 00 00 00       	callq  4d <_Z5test1i+0x4d>
  4d:	c6 44 24 28 00       	movb   $0x0,0x28(%rsp)
  52:	8a 44 24 10          	mov    0x10(%rsp),%al
  56:	fe c8                	dec    %al
  58:	0f b6 c0             	movzbl %al,%eax
  5b:	83 f8 03             	cmp    $0x3,%eax
  5e:	77 15                	ja     75 <_Z5test1i+0x75>
  60:	ff 24 c5 00 00 00 00 	jmpq   *0x0(,%rax,8)
  67:	48 8d 3c 24          	lea    (%rsp),%rdi
  6b:	e8 00 00 00 00       	callq  70 <_Z5test1i+0x70>
  70:	c6 44 24 10 00       	movb   $0x0,0x10(%rsp)
  75:	48 89 d8             	mov    %rbx,%rax
  78:	48 83 c4 30          	add    $0x30,%rsp
  7c:	5b                   	pop    %rbx
  7d:	c3                   	retq   
  7e:	48 89 c3             	mov    %rax,%rbx
  81:	8a 44 24 28          	mov    0x28(%rsp),%al
  85:	fe c8                	dec    %al
  87:	0f b6 c0             	movzbl %al,%eax
  8a:	83 f8 03             	cmp    $0x3,%eax
  8d:	77 16                	ja     a5 <_Z5test1i+0xa5>
  8f:	ff 24 c5 00 00 00 00 	jmpq   *0x0(,%rax,8)
  96:	48 8d 7c 24 18       	lea    0x18(%rsp),%rdi
  9b:	e8 00 00 00 00       	callq  a0 <_Z5test1i+0xa0>
  a0:	c6 44 24 28 00       	movb   $0x0,0x28(%rsp)
  a5:	8a 44 24 10          	mov    0x10(%rsp),%al
  a9:	fe c8                	dec    %al
  ab:	0f b6 c0             	movzbl %al,%eax
  ae:	83 f8 03             	cmp    $0x3,%eax
  b1:	77 15                	ja     c8 <_Z5test1i+0xc8>
  b3:	ff 24 c5 00 00 00 00 	jmpq   *0x0(,%rax,8)
  ba:	48 8d 3c 24          	lea    (%rsp),%rdi
  be:	e8 00 00 00 00       	callq  c3 <_Z5test1i+0xc3>
  c3:	c6 44 24 10 00       	movb   $0x0,0x10(%rsp)
  c8:	48 89 df             	mov    %rbx,%rdi
  cb:	e8 00 00 00 00       	callq  d0 replaced
  d0:	c3                   	retq   
  d1:	66 66 66 66 66 66 2e 	data32 data32 data32 data32 data32 nopw %cs:0x0(%rax,%rax,1)
  d8:	0f 1f 84 00 00 00 00 
  df:	00 

