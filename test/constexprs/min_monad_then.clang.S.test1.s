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
  3a:	77 21                	ja     5d <_Z5test1i+0x5d>
  3c:	ff 24 c5 00 00 00 00 	jmpq   *0x0(,%rax,8)
  43:	48 8d 7c 24 18       	lea    0x18(%rsp),%rdi
  48:	e8 00 00 00 00       	callq  4d <_Z5test1i+0x4d>
  4d:	eb 09                	jmp    58 <_Z5test1i+0x58>
  4f:	48 c7 44 24 18 00 00 	movq   $0x0,0x18(%rsp)
  56:	00 00 
  58:	c6 44 24 28 00       	movb   $0x0,0x28(%rsp)
  5d:	8a 44 24 10          	mov    0x10(%rsp),%al
  61:	fe c8                	dec    %al
  63:	0f b6 c0             	movzbl %al,%eax
  66:	83 f8 03             	cmp    $0x3,%eax
  69:	77 1f                	ja     8a <_Z5test1i+0x8a>
  6b:	ff 24 c5 00 00 00 00 	jmpq   *0x0(,%rax,8)
  72:	48 8d 3c 24          	lea    (%rsp),%rdi
  76:	e8 00 00 00 00       	callq  7b <_Z5test1i+0x7b>
  7b:	eb 08                	jmp    85 <_Z5test1i+0x85>
  7d:	48 c7 04 24 00 00 00 	movq   $0x0,(%rsp)
  84:	00 
  85:	c6 44 24 10 00       	movb   $0x0,0x10(%rsp)
  8a:	48 89 d8             	mov    %rbx,%rax
  8d:	48 83 c4 30          	add    $0x30,%rsp
  91:	5b                   	pop    %rbx
  92:	c3                   	retq   
  93:	48 89 c3             	mov    %rax,%rbx
  96:	8a 44 24 28          	mov    0x28(%rsp),%al
  9a:	fe c8                	dec    %al
  9c:	0f b6 c0             	movzbl %al,%eax
  9f:	83 f8 03             	cmp    $0x3,%eax
  a2:	77 21                	ja     c5 <_Z5test1i+0xc5>
  a4:	ff 24 c5 00 00 00 00 	jmpq   *0x0(,%rax,8)
  ab:	48 8d 7c 24 18       	lea    0x18(%rsp),%rdi
  b0:	e8 00 00 00 00       	callq  b5 <_Z5test1i+0xb5>
  b5:	eb 09                	jmp    c0 <_Z5test1i+0xc0>
  b7:	48 c7 44 24 18 00 00 	movq   $0x0,0x18(%rsp)
  be:	00 00 
  c0:	c6 44 24 28 00       	movb   $0x0,0x28(%rsp)
  c5:	8a 44 24 10          	mov    0x10(%rsp),%al
  c9:	fe c8                	dec    %al
  cb:	0f b6 c0             	movzbl %al,%eax
  ce:	83 f8 03             	cmp    $0x3,%eax
  d1:	77 1f                	ja     f2 <_Z5test1i+0xf2>
  d3:	ff 24 c5 00 00 00 00 	jmpq   *0x0(,%rax,8)
  da:	48 8d 3c 24          	lea    (%rsp),%rdi
  de:	e8 00 00 00 00       	callq  e3 <_Z5test1i+0xe3>
  e3:	eb 08                	jmp    ed <_Z5test1i+0xed>
  e5:	48 c7 04 24 00 00 00 	movq   $0x0,(%rsp)
  ec:	00 
  ed:	c6 44 24 10 00       	movb   $0x0,0x10(%rsp)
  f2:	48 89 df             	mov    %rbx,%rdi
  f5:	e8 00 00 00 00       	callq  fa <_Z5test1i+0xfa>
  fa:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
