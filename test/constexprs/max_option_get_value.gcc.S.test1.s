   0:	48 83 ec 18          	sub    $0x18,%rsp
   4:	48 89 e7             	mov    %rsp,%rdi
   7:	e8 00 00 00 00       	callq  c <_Z5test1v+0xc>
   c:	80 7c 24 04 00       	cmpb   $0x0,0x4(%rsp)
  11:	74 08                	je     1b <_Z5test1v+0x1b>
  13:	8b 04 24             	mov    (%rsp),%eax
  16:	48 83 c4 18          	add    $0x18,%rsp
  1a:	c3                   	retq   
  1b:	bf 02 00 00 00       	mov    $0x2,%edi
  20:	e8 00 00 00 00       	callq  25 <_Z5test1v+0x25>
  25:	66 66 2e 0f 1f 84 00 	data32 nopw %cs:0x0(%rax,%rax,1)
  2c:	00 00 00 00 
