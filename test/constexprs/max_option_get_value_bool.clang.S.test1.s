   0:	50                   	push   %rax
   1:	48 8d 3c 24          	lea    (%rsp),%rdi
   5:	e8 00 00 00 00       	callq  a <_Z5test1v+0xa>
   a:	0f b6 04 24          	movzbl (%rsp),%eax
   e:	83 f8 3f             	cmp    $0x3f,%eax
  11:	76 0a                	jbe    1d <_Z5test1v+0x1d>
  13:	a8 3f                	test   $0x3f,%al
  15:	0f 95 c0             	setne  %al
  18:	0f b6 c0             	movzbl %al,%eax
  1b:	59                   	pop    %rcx
  1c:	c3                   	retq   
  1d:	bf 02 00 00 00       	mov    $0x2,%edi
  22:	e8 00 00 00 00       	callq  27 <_Z5test1v+0x27>
  27:	eb ea                	jmp    13 <_Z5test1v+0x13>
  29:	0f b6 0c 24          	movzbl (%rsp),%ecx
  2d:	83 f9 40             	cmp    $0x40,%ecx
  30:	72 06                	jb     38 <_Z5test1v+0x38>
  32:	80 e1 3f             	and    $0x3f,%cl
  35:	88 0c 24             	mov    %cl,(%rsp)
  38:	48 89 c7             	mov    %rax,%rdi
  3b:	e8 00 00 00 00       	callq  40 replaced
  40:	c3                   	retq   
  41:	66 66 66 66 66 66 2e 	data16 data16 data16 data16 data16 nopw %cs:0x0(%rax,%rax,1)
  48:	0f 1f 84 00 00 00 00 
  4f:	00 

