   0:	50                   	push   %rax
   1:	48 8d 3c 24          	lea    (%rsp),%rdi
   5:	e8 00 00 00 00       	callq  a <_Z5test1v+0xa>
   a:	0f b6 4c 24 04       	movzbl 0x4(%rsp),%ecx
   f:	85 c9                	test   %ecx,%ecx
  11:	74 19                	je     2c <_Z5test1v+0x2c>
  13:	8b 04 24             	mov    (%rsp),%eax
  16:	83 f9 03             	cmp    $0x3,%ecx
  19:	74 0a                	je     25 <_Z5test1v+0x25>
  1b:	83 f9 02             	cmp    $0x2,%ecx
  1e:	74 05                	je     25 <_Z5test1v+0x25>
  20:	83 f9 01             	cmp    $0x1,%ecx
  23:	75 05                	jne    2a <_Z5test1v+0x2a>
  25:	c6 44 24 04 00       	movb   $0x0,0x4(%rsp)
  2a:	5a                   	pop    %rdx
  2b:	c3                   	retq   
  2c:	bf 02 00 00 00       	mov    $0x2,%edi
  31:	e8 00 00 00 00       	callq  36 <_Z5test1v+0x36>
  36:	eb db                	jmp    13 <_Z5test1v+0x13>
  38:	0f b6 4c 24 04       	movzbl 0x4(%rsp),%ecx
  3d:	83 f9 03             	cmp    $0x3,%ecx
  40:	74 0a                	je     4c <_Z5test1v+0x4c>
  42:	83 f9 02             	cmp    $0x2,%ecx
  45:	74 05                	je     4c <_Z5test1v+0x4c>
  47:	83 f9 01             	cmp    $0x1,%ecx
  4a:	75 05                	jne    51 <_Z5test1v+0x51>
  4c:	c6 44 24 04 00       	movb   $0x0,0x4(%rsp)
  51:	48 89 c7             	mov    %rax,%rdi
  54:	e8 00 00 00 00       	callq  59 <_Z5test1v+0x59>
  59:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
