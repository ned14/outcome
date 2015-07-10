   0:	48 83 ec 38          	sub    $0x38,%rsp
   4:	c6 44 24 20 00       	movb   $0x0,0x20(%rsp)
   9:	c6 44 24 28 00       	movb   $0x0,0x28(%rsp)
   e:	c6 44 24 29 00       	movb   $0x0,0x29(%rsp)
  13:	48 c7 44 24 30 00 00 	movq   $0x0,0x30(%rsp)
  1a:	00 00 
  1c:	48 c7 44 24 08 00 00 	movq   $0x0,0x8(%rsp)
  23:	00 00 
  25:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  2a:	e8 00 00 00 00       	callq  2f <_Z5test1v+0x2f>
  2f:	48 83 c4 38          	add    $0x38,%rsp
  33:	c3                   	retq   
  34:	66 66 66 2e 0f 1f 84 	data32 data32 nopw %cs:0x0(%rax,%rax,1)
  3b:	00 00 00 00 00 
