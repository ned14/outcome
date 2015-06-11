   0:	48 83 ec 28          	sub    $0x28,%rsp
   4:	c7 44 24 18 00 00 00 	movl   $0x0,0x18(%rsp)
   b:	00 
   c:	c6 44 24 20 00       	movb   $0x0,0x20(%rsp)
  11:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  16:	e8 00 00 00 00       	callq  1b <_Z5test1v+0x1b>
  1b:	48 83 c4 28          	add    $0x28,%rsp
  1f:	c3                   	retq   
