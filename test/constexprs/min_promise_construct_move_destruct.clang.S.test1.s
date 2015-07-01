   0:	41 56                	push   %r14
   2:	53                   	push   %rbx
   3:	48 83 ec 48          	sub    $0x48,%rsp
   7:	c6 44 24 38 00       	movb   $0x0,0x38(%rsp)
   c:	c6 44 24 40 00       	movb   $0x0,0x40(%rsp)
  11:	c6 44 24 41 00       	movb   $0x0,0x41(%rsp)
  16:	48 8d 5c 24 08       	lea    0x8(%rsp),%rbx
  1b:	4c 8d 74 24 28       	lea    0x28(%rsp),%r14
  20:	48 89 df             	mov    %rbx,%rdi
  23:	4c 89 f6             	mov    %r14,%rsi
  26:	e8 00 00 00 00       	callq  2b <_Z5test1v+0x2b>
  2b:	48 89 df             	mov    %rbx,%rdi
  2e:	e8 00 00 00 00       	callq  33 <_Z5test1v+0x33>
  33:	4c 89 f7             	mov    %r14,%rdi
  36:	e8 00 00 00 00       	callq  3b <_Z5test1v+0x3b>
  3b:	48 83 c4 48          	add    $0x48,%rsp
  3f:	5b                   	pop    %rbx
  40:	41 5e                	pop    %r14
  42:	c3                   	retq   
  43:	66 66 66 66 2e 0f 1f 	data32 data32 data32 nopw %cs:0x0(%rax,%rax,1)
  4a:	84 00 00 00 00 00 
