   8:	50                   	push   %rax
   9:	48 8d 3c 24          	lea    (%rsp),%rdi
   d:	e8 00 00 00 00       	callq  12 <_Z5test1v+0xa>
  12:	8a 4c 24 04          	mov    0x4(%rsp),%cl
  16:	84 c9                	test   %cl,%cl
  18:	74 1b                	je     35 <_Z5test1v+0x2d>
  1a:	8b 04 24             	mov    (%rsp),%eax
  1d:	fe c9                	dec    %cl
  1f:	0f b6 c9             	movzbl %cl,%ecx
  22:	83 f9 03             	cmp    $0x3,%ecx
  25:	77 0c                	ja     33 <_Z5test1v+0x2b>
  27:	ff 24 cd 00 00 00 00 	jmpq   *0x0(,%rcx,8)
  2e:	c6 44 24 04 00       	movb   $0x0,0x4(%rsp)
  33:	5a                   	pop    %rdx
  34:	c3                   	retq   
  35:	bf 02 00 00 00       	mov    $0x2,%edi
  3a:	e8 00 00 00 00       	callq  3f <_Z5test1v+0x37>
  3f:	eb d9                	jmp    1a <_Z5test1v+0x12>
  41:	8a 4c 24 04          	mov    0x4(%rsp),%cl
  45:	fe c9                	dec    %cl
  47:	0f b6 c9             	movzbl %cl,%ecx
  4a:	83 f9 03             	cmp    $0x3,%ecx
  4d:	77 0c                	ja     5b <_Z5test1v+0x53>
  4f:	ff 24 cd 00 00 00 00 	jmpq   *0x0(,%rcx,8)
  56:	c6 44 24 04 00       	movb   $0x0,0x4(%rsp)
  5b:	48 89 c7             	mov    %rax,%rdi
  5e:	e8 00 00 00 00       	callq  63 <_Z5test1v+0x5b>
  63:	66 66 66 66 2e 0f 1f 	data32 data32 data32 nopw %cs:0x0(%rax,%rax,1)
  6a:	84 00 00 00 00 00 
