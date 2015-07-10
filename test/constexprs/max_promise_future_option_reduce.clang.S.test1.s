   0:	53                   	push   %rbx
   1:	48 83 ec 70          	sub    $0x70,%rsp
   5:	c6 44 24 34 00       	movb   $0x0,0x34(%rsp)
   a:	66 c7 44 24 38 00 00 	movw   $0x0,0x38(%rsp)
  11:	0f 57 c0             	xorps  %xmm0,%xmm0
  14:	0f 11 44 24 50       	movups %xmm0,0x50(%rsp)
  19:	0f 11 44 24 40       	movups %xmm0,0x40(%rsp)
  1e:	48 c7 44 24 60 00 00 	movq   $0x0,0x60(%rsp)
  25:	00 00 
  27:	48 c7 44 24 28 00 00 	movq   $0x0,0x28(%rsp)
  2e:	00 00 
  30:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  35:	48 8d 74 24 28       	lea    0x28(%rsp),%rsi
  3a:	e8 00 00 00 00       	callq  3f <_Z5test1v+0x3f>
  3f:	c7 44 24 04 05 00 00 	movl   $0x5,0x4(%rsp)
  46:	00 
  47:	48 8d 44 24 04       	lea    0x4(%rsp),%rax
  4c:	48 89 44 24 68       	mov    %rax,0x68(%rsp)
  51:	48 8d 7c 24 28       	lea    0x28(%rsp),%rdi
  56:	48 8d 74 24 68       	lea    0x68(%rsp),%rsi
  5b:	e8 00 00 00 00       	callq  60 <_Z5test1v+0x60>
  60:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  65:	e8 00 00 00 00       	callq  6a <_Z5test1v+0x6a>
  6a:	89 c3                	mov    %eax,%ebx
  6c:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  71:	e8 00 00 00 00       	callq  76 <_Z5test1v+0x76>
  76:	48 8d 7c 24 28       	lea    0x28(%rsp),%rdi
  7b:	e8 00 00 00 00       	callq  80 <_Z5test1v+0x80>
  80:	89 d8                	mov    %ebx,%eax
  82:	48 83 c4 70          	add    $0x70,%rsp
  86:	5b                   	pop    %rbx
  87:	c3                   	retq   
  88:	48 89 c3             	mov    %rax,%rbx
  8b:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  90:	e8 00 00 00 00       	callq  95 <_Z5test1v+0x95>
  95:	eb 03                	jmp    9a <_Z5test1v+0x9a>
  97:	48 89 c3             	mov    %rax,%rbx
  9a:	48 8d 7c 24 28       	lea    0x28(%rsp),%rdi
  9f:	e8 00 00 00 00       	callq  a4 <_Z5test1v+0xa4>
  a4:	48 89 df             	mov    %rbx,%rdi
  a7:	e8 00 00 00 00       	callq  ac <_Z5test1v+0xac>
  ac:	0f 1f 40 00          	nopl   0x0(%rax)
