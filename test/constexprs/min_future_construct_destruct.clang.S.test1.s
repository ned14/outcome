   0:	48 83 ec 28          	sub    $0x28,%rsp
   4:	c6 44 24 10 00       	movb   $0x0,0x10(%rsp)
   9:	c6 44 24 18 00       	movb   $0x0,0x18(%rsp)
   e:	c6 44 24 19 00       	movb   $0x0,0x19(%rsp)
  13:	48 c7 44 24 20 00 00 	movq   $0x0,0x20(%rsp)
  1a:	00 00 
  1c:	48 8d 3c 24          	lea    (%rsp),%rdi
  20:	e8 00 00 00 00       	callq  25 <_Z5test1v+0x25>
  25:	48 83 c4 28          	add    $0x28,%rsp
  29:	c3                   	retq   
  2a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
