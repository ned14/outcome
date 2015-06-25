   2:	48 83 ec 18          	sub    $0x18,%rsp
   6:	48 89 e7             	mov    %rsp,%rdi
   9:	e8 00 00 00 00       	callq  e <_Z5test2v+0xe>
   e:	80 7c 24 04 00       	cmpb   $0x0,0x4(%rsp)
  13:	74 08                	je     1d <_Z5test2v+0x1d>
  15:	8b 04 24             	mov    (%rsp),%eax
  18:	48 83 c4 18          	add    $0x18,%rsp
  1c:	c3                   	retq   
  1d:	bf 02 00 00 00       	mov    $0x2,%edi
  22:	e8 00 00 00 00       	callq  27 <_Z5test2v+0x27>
