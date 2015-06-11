   0:	48 83 ec 28          	sub    $0x28,%rsp
   4:	c6 44 24 18 00       	movb   $0x0,0x18(%rsp)
   9:	c6 44 24 20 00       	movb   $0x0,0x20(%rsp)
   e:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  13:	e8 00 00 00 00       	callq  18 <_Z5test1v+0x18>
  18:	48 83 c4 28          	add    $0x28,%rsp
  1c:	c3                   	retq   
  1d:	0f 1f 00             	nopl   (%rax)
