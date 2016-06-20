   0:	53                   	push   %rbx
   1:	48 83 ec 20          	sub    $0x20,%rsp
   5:	48 8d 1c 24          	lea    (%rsp),%rbx
   9:	48 89 df             	mov    %rbx,%rdi
   c:	e8 00 00 00 00       	callq  11 <_Z5test1v+0x11>
  11:	48 89 df             	mov    %rbx,%rdi
  14:	e8 00 00 00 00       	callq  19 <_Z5test1v+0x19>
  19:	8b 04 24             	mov    (%rsp),%eax
  1c:	0f b6 4c 24 18       	movzbl 0x18(%rsp),%ecx
  21:	83 f9 03             	cmp    $0x3,%ecx
  24:	74 0a                	je     30 <_Z5test1v+0x30>
  26:	83 f9 02             	cmp    $0x2,%ecx
  29:	74 05                	je     30 <_Z5test1v+0x30>
  2b:	83 f9 01             	cmp    $0x1,%ecx
  2e:	75 05                	jne    35 <_Z5test1v+0x35>
  30:	c6 44 24 18 00       	movb   $0x0,0x18(%rsp)
  35:	48 83 c4 20          	add    $0x20,%rsp
  39:	5b                   	pop    %rbx
  3a:	c3                   	retq   
  3b:	0f b6 4c 24 18       	movzbl 0x18(%rsp),%ecx
  40:	83 f9 03             	cmp    $0x3,%ecx
  43:	74 0a                	je     4f <_Z5test1v+0x4f>
  45:	83 f9 02             	cmp    $0x2,%ecx
  48:	74 05                	je     4f <_Z5test1v+0x4f>
  4a:	83 f9 01             	cmp    $0x1,%ecx
  4d:	75 05                	jne    54 <_Z5test1v+0x54>
  4f:	c6 44 24 18 00       	movb   $0x0,0x18(%rsp)
  54:	48 89 c7             	mov    %rax,%rdi
  57:	e8 00 00 00 00       	callq  5c <_Z5test1v+0x5c>
  5c:	0f 1f 40 00          	nopl   0x0(%rax)
