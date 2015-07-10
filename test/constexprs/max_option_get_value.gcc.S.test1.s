  10:	48 83 ec 18          	sub    $0x18,%rsp
  14:	48 89 e7             	mov    %rsp,%rdi
  17:	e8 00 00 00 00       	callq  1c <_Z5test2v+0x1c>
  1c:	80 7c 24 04 00       	cmpb   $0x0,0x4(%rsp)
  21:	74 08                	je     2b <_Z5test2v+0x2b>
  23:	8b 04 24             	mov    (%rsp),%eax
  26:	48 83 c4 18          	add    $0x18,%rsp
  2a:	c3                   	retq   
  2b:	bf 02 00 00 00       	mov    $0x2,%edi
  30:	e8 00 00 00 00       	callq  35 <_Z5test2v+0x35>
