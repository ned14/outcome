   0:	41 56                	push   %r14
   2:	53                   	push   %rbx
   3:	48 83 ec 58          	sub    $0x58,%rsp
   7:	c7 44 24 40 00 00 00 	movl   $0x0,0x40(%rsp)
   e:	00 
   f:	c6 44 24 48 00       	movb   $0x0,0x48(%rsp)
  14:	48 c7 44 24 50 00 00 	movq   $0x0,0x50(%rsp)
  1b:	00 00 
  1d:	48 8d 5c 24 08       	lea    0x8(%rsp),%rbx
  22:	4c 8d 74 24 30       	lea    0x30(%rsp),%r14
  27:	48 89 df             	mov    %rbx,%rdi
  2a:	4c 89 f6             	mov    %r14,%rsi
  2d:	e8 00 00 00 00       	callq  32 <_Z5test1v+0x32>
  32:	48 89 df             	mov    %rbx,%rdi
  35:	e8 00 00 00 00       	callq  3a <_Z5test1v+0x3a>
  3a:	4c 89 f7             	mov    %r14,%rdi
  3d:	e8 00 00 00 00       	callq  42 <_Z5test1v+0x42>
  42:	48 83 c4 58          	add    $0x58,%rsp
  46:	5b                   	pop    %rbx
  47:	41 5e                	pop    %r14
  49:	c3                   	retq   
  4a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
