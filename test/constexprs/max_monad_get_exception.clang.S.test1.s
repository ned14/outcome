   8:	41 56                	push   %r14
   a:	53                   	push   %rbx
   b:	48 83 ec 18          	sub    $0x18,%rsp
   f:	49 89 fe             	mov    %rdi,%r14
  12:	48 8d 1c 24          	lea    (%rsp),%rbx
  16:	48 89 df             	mov    %rbx,%rdi
  19:	e8 00 00 00 00       	callq  1e <_Z5test1v+0x16>
  1e:	4c 89 f7             	mov    %r14,%rdi
  21:	48 89 de             	mov    %rbx,%rsi
  24:	e8 00 00 00 00       	callq  29 <_Z5test1v+0x21>
  29:	8a 44 24 10          	mov    0x10(%rsp),%al
  2d:	fe c8                	dec    %al
  2f:	0f b6 c0             	movzbl %al,%eax
  32:	83 f8 03             	cmp    $0x3,%eax
  35:	77 15                	ja     4c <_Z5test1v+0x44>
  37:	ff 24 c5 00 00 00 00 	jmpq   *0x0(,%rax,8)
  3e:	48 8d 3c 24          	lea    (%rsp),%rdi
  42:	e8 00 00 00 00       	callq  47 <_Z5test1v+0x3f>
  47:	c6 44 24 10 00       	movb   $0x0,0x10(%rsp)
  4c:	4c 89 f0             	mov    %r14,%rax
  4f:	48 83 c4 18          	add    $0x18,%rsp
  53:	5b                   	pop    %rbx
  54:	41 5e                	pop    %r14
  56:	c3                   	retq   
  57:	48 89 c3             	mov    %rax,%rbx
  5a:	8a 44 24 10          	mov    0x10(%rsp),%al
  5e:	fe c8                	dec    %al
  60:	0f b6 c0             	movzbl %al,%eax
  63:	83 f8 03             	cmp    $0x3,%eax
  66:	77 15                	ja     7d <_Z5test1v+0x75>
  68:	ff 24 c5 00 00 00 00 	jmpq   *0x0(,%rax,8)
  6f:	48 8d 3c 24          	lea    (%rsp),%rdi
  73:	e8 00 00 00 00       	callq  78 <_Z5test1v+0x70>
  78:	c6 44 24 10 00       	movb   $0x0,0x10(%rsp)
  7d:	48 89 df             	mov    %rbx,%rdi
  80:	e8 00 00 00 00       	callq  85 <_Z5test1v+0x7d>
  85:	66 66 2e 0f 1f 84 00 	data32 nopw %cs:0x0(%rax,%rax,1)
  8c:	00 00 00 00 
