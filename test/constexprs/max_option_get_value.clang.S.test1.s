   0:	50                   	push   %rax
   1:	48 8d 3c 24          	lea    (%rsp),%rdi
   5:	e8 00 00 00 00       	callq  a <_Z5test1v+0xa>
   a:	8a 4c 24 04          	mov    0x4(%rsp),%cl
   e:	84 c9                	test   %cl,%cl
  10:	74 1b                	je     2d <_Z5test1v+0x2d>
  12:	8b 04 24             	mov    (%rsp),%eax
  15:	fe c9                	dec    %cl
  17:	0f b6 c9             	movzbl %cl,%ecx
  1a:	83 f9 03             	cmp    $0x3,%ecx
  1d:	77 0c                	ja     2b <_Z5test1v+0x2b>
  1f:	ff 24 cd 00 00 00 00 	jmpq   *0x0(,%rcx,8)
  26:	c6 44 24 04 00       	movb   $0x0,0x4(%rsp)
  2b:	5a                   	pop    %rdx
  2c:	c3                   	retq   
  2d:	bf 02 00 00 00       	mov    $0x2,%edi
  32:	e8 00 00 00 00       	callq  37 <_Z5test1v+0x37>
  37:	eb d9                	jmp    12 <_Z5test1v+0x12>
  39:	8a 4c 24 04          	mov    0x4(%rsp),%cl
  3d:	fe c9                	dec    %cl
  3f:	0f b6 c9             	movzbl %cl,%ecx
  42:	83 f9 03             	cmp    $0x3,%ecx
  45:	77 0c                	ja     53 <_Z5test1v+0x53>
  47:	ff 24 cd 00 00 00 00 	jmpq   *0x0(,%rcx,8)
  4e:	c6 44 24 04 00       	movb   $0x0,0x4(%rsp)
  53:	48 89 c7             	mov    %rax,%rdi
  56:	e8 00 00 00 00       	callq  5b <_Z5test1v+0x5b>
  5b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
