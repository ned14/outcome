   0:	53                   	push   %rbx
   1:	48 81 ec 90 00 00 00 	sub    $0x90,%rsp
   8:	c6 44 24 50 00       	movb   $0x0,0x50(%rsp)
   d:	c6 44 24 58 00       	movb   $0x0,0x58(%rsp)
  12:	c6 44 24 5a 00       	movb   $0x0,0x5a(%rsp)
  17:	0f 57 c0             	xorps  %xmm0,%xmm0
  1a:	0f 11 44 24 70       	movups %xmm0,0x70(%rsp)
  1f:	0f 11 44 24 60       	movups %xmm0,0x60(%rsp)
  24:	48 c7 84 24 80 00 00 	movq   $0x0,0x80(%rsp)
  2b:	00 00 00 00 00 
  30:	48 c7 44 24 38 00 00 	movq   $0x0,0x38(%rsp)
  37:	00 00 
  39:	c7 44 24 34 05 00 00 	movl   $0x5,0x34(%rsp)
  40:	00 
  41:	48 8d 44 24 34       	lea    0x34(%rsp),%rax
  46:	48 89 84 24 88 00 00 	mov    %rax,0x88(%rsp)
  4d:	00 
  4e:	48 8d 7c 24 38       	lea    0x38(%rsp),%rdi
  53:	48 8d b4 24 88 00 00 	lea    0x88(%rsp),%rsi
  5a:	00 
  5b:	e8 00 00 00 00       	callq  60 <_Z5test1v+0x60>
  60:	48 8d 3c 24          	lea    (%rsp),%rdi
  64:	48 8d 74 24 38       	lea    0x38(%rsp),%rsi
  69:	e8 00 00 00 00       	callq  6e <_Z5test1v+0x6e>
  6e:	48 8d 3c 24          	lea    (%rsp),%rdi
  72:	e8 00 00 00 00       	callq  77 <_Z5test1v+0x77>
  77:	89 c3                	mov    %eax,%ebx
  79:	48 8d 3c 24          	lea    (%rsp),%rdi
  7d:	e8 00 00 00 00       	callq  82 <_Z5test1v+0x82>
  82:	48 8d 7c 24 38       	lea    0x38(%rsp),%rdi
  87:	e8 00 00 00 00       	callq  8c <_Z5test1v+0x8c>
  8c:	89 d8                	mov    %ebx,%eax
  8e:	48 81 c4 90 00 00 00 	add    $0x90,%rsp
  95:	5b                   	pop    %rbx
  96:	c3                   	retq   
  97:	48 89 c3             	mov    %rax,%rbx
  9a:	eb 0c                	jmp    a8 <_Z5test1v+0xa8>
  9c:	48 89 c3             	mov    %rax,%rbx
  9f:	48 8d 3c 24          	lea    (%rsp),%rdi
  a3:	e8 00 00 00 00       	callq  a8 <_Z5test1v+0xa8>
  a8:	48 8d 7c 24 38       	lea    0x38(%rsp),%rdi
  ad:	e8 00 00 00 00       	callq  b2 <_Z5test1v+0xb2>
  b2:	48 89 df             	mov    %rbx,%rdi
  b5:	e8 00 00 00 00       	callq  ba <_Z5test1v+0xba>
  ba:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
