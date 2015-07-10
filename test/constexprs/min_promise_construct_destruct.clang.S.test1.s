   0:	48 83 ec 58          	sub    $0x58,%rsp
   4:	c6 44 24 20 00       	movb   $0x0,0x20(%rsp)
   9:	c6 44 24 28 00       	movb   $0x0,0x28(%rsp)
   e:	c6 44 24 2a 00       	movb   $0x0,0x2a(%rsp)
  13:	0f 57 c0             	xorps  %xmm0,%xmm0
  16:	0f 11 44 24 40       	movups %xmm0,0x40(%rsp)
  1b:	0f 11 44 24 30       	movups %xmm0,0x30(%rsp)
  20:	48 c7 44 24 50 00 00 	movq   $0x0,0x50(%rsp)
  27:	00 00 
  29:	48 c7 44 24 08 00 00 	movq   $0x0,0x8(%rsp)
  30:	00 00 
  32:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  37:	e8 00 00 00 00       	callq  3c <_Z5test1v+0x3c>
  3c:	48 83 c4 58          	add    $0x58,%rsp
  40:	c3                   	retq   
  41:	66 66 66 66 66 66 2e 	data32 data32 data32 data32 data32 nopw %cs:0x0(%rax,%rax,1)
  48:	0f 1f 84 00 00 00 00 
  4f:	00 
