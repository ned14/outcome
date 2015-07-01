   0:	41 56                	push   %r14
   2:	53                   	push   %rbx
   3:	48 83 ec 58          	sub    $0x58,%rsp
   7:	c6 44 24 40 00       	movb   $0x0,0x40(%rsp)
   c:	c6 44 24 48 00       	movb   $0x0,0x48(%rsp)
  11:	c6 44 24 49 00       	movb   $0x0,0x49(%rsp)
  16:	48 c7 44 24 50 00 00 	movq   $0x0,0x50(%rsp)
  1d:	00 00 
  1f:	48 8d 5c 24 08       	lea    0x8(%rsp),%rbx
  24:	4c 8d 74 24 30       	lea    0x30(%rsp),%r14
  29:	48 89 df             	mov    %rbx,%rdi
  2c:	4c 89 f6             	mov    %r14,%rsi
  2f:	e8 00 00 00 00       	callq  34 <_Z5test1v+0x34>
  34:	48 89 df             	mov    %rbx,%rdi
  37:	e8 00 00 00 00       	callq  3c <_Z5test1v+0x3c>
  3c:	4c 89 f7             	mov    %r14,%rdi
  3f:	e8 00 00 00 00       	callq  44 <_Z5test1v+0x44>
  44:	48 83 c4 58          	add    $0x58,%rsp
  48:	5b                   	pop    %rbx
  49:	41 5e                	pop    %r14
  4b:	c3                   	retq   
  4c:	0f 1f 40 00          	nopl   0x0(%rax)
