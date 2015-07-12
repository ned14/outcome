   0:	48 83 ec 48          	sub    $0x48,%rsp
   4:	c6 44 24 18 00       	movb   $0x0,0x18(%rsp)
   9:	c6 44 24 20 00       	movb   $0x0,0x20(%rsp)
   e:	c6 44 24 22 00       	movb   $0x0,0x22(%rsp)
  13:	0f 57 c0             	xorps  %xmm0,%xmm0
  16:	0f 11 44 24 38       	movups %xmm0,0x38(%rsp)
  1b:	0f 11 44 24 28       	movups %xmm0,0x28(%rsp)
  20:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  25:	e8 00 00 00 00       	callq  2a <_Z5test1v+0x2a>
  2a:	48 83 c4 48          	add    $0x48,%rsp
  2e:	c3                   	retq   
  2f:	90                   	nop
