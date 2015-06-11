   0:	41 56                	push   %r14
   2:	53                   	push   %rbx
   3:	48 83 ec 48          	sub    $0x48,%rsp
   7:	c6 44 24 38 00       	movb   $0x0,0x38(%rsp)
   c:	c6 44 24 40 00       	movb   $0x0,0x40(%rsp)
  11:	48 8d 5c 24 08       	lea    0x8(%rsp),%rbx
  16:	4c 8d 74 24 28       	lea    0x28(%rsp),%r14
  1b:	48 89 df             	mov    %rbx,%rdi
  1e:	4c 89 f6             	mov    %r14,%rsi
  21:	e8 00 00 00 00       	callq  26 <_Z5test1v+0x26>
  26:	48 89 df             	mov    %rbx,%rdi
  29:	e8 00 00 00 00       	callq  2e <_Z5test1v+0x2e>
  2e:	4c 89 f7             	mov    %r14,%rdi
  31:	e8 00 00 00 00       	callq  36 <_Z5test1v+0x36>
  36:	48 83 c4 48          	add    $0x48,%rsp
  3a:	5b                   	pop    %rbx
  3b:	41 5e                	pop    %r14
  3d:	c3                   	retq   
  3e:	66 90                	xchg   %ax,%ax
