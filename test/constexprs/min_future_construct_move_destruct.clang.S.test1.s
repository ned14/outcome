   0:	41 56                	push   %r14
   2:	53                   	push   %rbx
   3:	48 83 ec 58          	sub    $0x58,%rsp
   7:	c6 44 24 40 00       	movb   $0x0,0x40(%rsp)
   c:	c6 44 24 48 00       	movb   $0x0,0x48(%rsp)
  11:	48 c7 44 24 50 00 00 	movq   $0x0,0x50(%rsp)
  18:	00 00 
  1a:	48 8d 5c 24 08       	lea    0x8(%rsp),%rbx
  1f:	4c 8d 74 24 30       	lea    0x30(%rsp),%r14
  24:	48 89 df             	mov    %rbx,%rdi
  27:	4c 89 f6             	mov    %r14,%rsi
  2a:	e8 00 00 00 00       	callq  2f <_Z5test1v+0x2f>
  2f:	48 89 df             	mov    %rbx,%rdi
  32:	e8 00 00 00 00       	callq  37 <_Z5test1v+0x37>
  37:	4c 89 f7             	mov    %r14,%rdi
  3a:	e8 00 00 00 00       	callq  3f <_Z5test1v+0x3f>
  3f:	48 83 c4 58          	add    $0x58,%rsp
  43:	5b                   	pop    %rbx
  44:	41 5e                	pop    %r14
  46:	c3                   	retq   
  47:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  4e:	00 00 
