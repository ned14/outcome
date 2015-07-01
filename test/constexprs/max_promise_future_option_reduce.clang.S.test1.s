   0:	53                   	push   %rbx
   1:	48 83 ec 40          	sub    $0x40,%rsp
   5:	c6 44 24 30 00       	movb   $0x0,0x30(%rsp)
   a:	c6 44 24 38 00       	movb   $0x0,0x38(%rsp)
   f:	c6 44 24 39 00       	movb   $0x0,0x39(%rsp)
  14:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  19:	48 8d 74 24 28       	lea    0x28(%rsp),%rsi
  1e:	e8 00 00 00 00       	callq  23 <_Z5test1v+0x23>
  23:	c7 44 24 04 05 00 00 	movl   $0x5,0x4(%rsp)
  2a:	00 
  2b:	48 8d 7c 24 28       	lea    0x28(%rsp),%rdi
  30:	48 8d 74 24 04       	lea    0x4(%rsp),%rsi
  35:	e8 00 00 00 00       	callq  3a <_Z5test1v+0x3a>
  3a:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  3f:	e8 00 00 00 00       	callq  44 <_Z5test1v+0x44>
  44:	89 c3                	mov    %eax,%ebx
  46:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  4b:	e8 00 00 00 00       	callq  50 <_Z5test1v+0x50>
  50:	48 8d 7c 24 28       	lea    0x28(%rsp),%rdi
  55:	e8 00 00 00 00       	callq  5a <_Z5test1v+0x5a>
  5a:	89 d8                	mov    %ebx,%eax
  5c:	48 83 c4 40          	add    $0x40,%rsp
  60:	5b                   	pop    %rbx
  61:	c3                   	retq   
  62:	48 89 c3             	mov    %rax,%rbx
  65:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  6a:	e8 00 00 00 00       	callq  6f <_Z5test1v+0x6f>
  6f:	eb 03                	jmp    74 <_Z5test1v+0x74>
  71:	48 89 c3             	mov    %rax,%rbx
  74:	48 8d 7c 24 28       	lea    0x28(%rsp),%rdi
  79:	e8 00 00 00 00       	callq  7e <_Z5test1v+0x7e>
  7e:	48 89 df             	mov    %rbx,%rdi
  81:	e8 00 00 00 00       	callq  86 <_Z5test1v+0x86>
  86:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  8d:	00 00 00 
