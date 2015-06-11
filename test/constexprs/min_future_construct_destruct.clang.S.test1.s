   0:	48 83 ec 28          	sub    $0x28,%rsp
   4:	c6 44 24 10 00       	movb   $0x0,0x10(%rsp)
   9:	c6 44 24 18 00       	movb   $0x0,0x18(%rsp)
   e:	48 c7 44 24 20 00 00 	movq   $0x0,0x20(%rsp)
  15:	00 00 
  17:	48 8d 3c 24          	lea    (%rsp),%rdi
  1b:	e8 00 00 00 00       	callq  20 <_Z5test1v+0x20>
  20:	48 83 c4 28          	add    $0x28,%rsp
  24:	c3                   	retq   
  25:	66 66 2e 0f 1f 84 00 	data32 nopw %cs:0x0(%rax,%rax,1)
  2c:	00 00 00 00 
