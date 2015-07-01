   0:	48 83 ec 28          	sub    $0x28,%rsp
   4:	c6 44 24 18 00       	movb   $0x0,0x18(%rsp)
   9:	c6 44 24 20 00       	movb   $0x0,0x20(%rsp)
   e:	c6 44 24 21 00       	movb   $0x0,0x21(%rsp)
  13:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  18:	e8 00 00 00 00       	callq  1d <_Z5test1v+0x1d>
  1d:	48 83 c4 28          	add    $0x28,%rsp
  21:	c3                   	retq   
  22:	66 66 66 66 66 2e 0f 	data32 data32 data32 data32 nopw %cs:0x0(%rax,%rax,1)
  29:	1f 84 00 00 00 00 00 
