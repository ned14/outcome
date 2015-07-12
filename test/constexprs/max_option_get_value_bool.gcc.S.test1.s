  10:	48 83 ec 18          	sub    $0x18,%rsp
  14:	48 8d 7c 24 0f       	lea    0xf(%rsp),%rdi
  19:	e8 00 00 00 00       	callq  1e <_Z5test2v+0x1e>
  1e:	0f b6 44 24 0f       	movzbl 0xf(%rsp),%eax
  23:	a8 c0                	test   $0xc0,%al
  25:	74 0d                	je     34 <_Z5test2v+0x34>
  27:	a8 3f                	test   $0x3f,%al
  29:	0f 95 c0             	setne  %al
  2c:	48 83 c4 18          	add    $0x18,%rsp
  30:	0f b6 c0             	movzbl %al,%eax
  33:	c3                   	retq   
  34:	bf 02 00 00 00       	mov    $0x2,%edi
  39:	e8 00 00 00 00       	callq  3e <_Z5test2v+0x3e>
