   0:	48 83 ec 28          	sub    $0x28,%rsp
   4:	c7 44 24 08 05 00 00 	movl   $0x5,0x8(%rsp)
   b:	00 
   c:	c6 44 24 20 01       	movb   $0x1,0x20(%rsp)
  11:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  16:	e8 00 00 00 00       	callq  1b <_Z5test1v+0x1b>
  1b:	b8 05 00 00 00       	mov    $0x5,%eax
  20:	48 83 c4 28          	add    $0x28,%rsp
  24:	c3                   	retq   
  25:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
  2c:	00 00 00 00 
