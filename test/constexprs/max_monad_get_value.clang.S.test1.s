   0:	53                   	push   %rbx
   1:	48 83 ec 20          	sub    $0x20,%rsp
   5:	48 8d 1c 24          	lea    (%rsp),%rbx
   9:	48 89 df             	mov    %rbx,%rdi
   c:	e8 00 00 00 00       	callq  11 <_Z5test1v+0x11>
  11:	48 89 df             	mov    %rbx,%rdi
  14:	e8 00 00 00 00       	callq  19 <_Z5test1v+0x19>
  19:	8b 1c 24             	mov    (%rsp),%ebx
  1c:	0f b6 44 24 18       	movzbl 0x18(%rsp),%eax
  21:	83 f8 03             	cmp    $0x3,%eax
  24:	74 0c                	je     32 <_Z5test1v+0x32>
  26:	83 f8 02             	cmp    $0x2,%eax
  29:	74 10                	je     3b <_Z5test1v+0x3b>
  2b:	83 f8 01             	cmp    $0x1,%eax
  2e:	74 0b                	je     3b <_Z5test1v+0x3b>
  30:	eb 0e                	jmp    40 <_Z5test1v+0x40>
  32:	48 8d 3c 24          	lea    (%rsp),%rdi
  36:	e8 00 00 00 00       	callq  3b <_Z5test1v+0x3b>
  3b:	c6 44 24 18 00       	movb   $0x0,0x18(%rsp)
  40:	89 d8                	mov    %ebx,%eax
  42:	48 83 c4 20          	add    $0x20,%rsp
  46:	5b                   	pop    %rbx
  47:	c3                   	retq   
  48:	48 89 c3             	mov    %rax,%rbx
  4b:	0f b6 44 24 18       	movzbl 0x18(%rsp),%eax
  50:	83 f8 03             	cmp    $0x3,%eax
  53:	74 0c                	je     61 <_Z5test1v+0x61>
  55:	83 f8 02             	cmp    $0x2,%eax
  58:	74 10                	je     6a <_Z5test1v+0x6a>
  5a:	83 f8 01             	cmp    $0x1,%eax
  5d:	74 0b                	je     6a <_Z5test1v+0x6a>
  5f:	eb 0e                	jmp    6f <_Z5test1v+0x6f>
  61:	48 8d 3c 24          	lea    (%rsp),%rdi
  65:	e8 00 00 00 00       	callq  6a <_Z5test1v+0x6a>
  6a:	c6 44 24 18 00       	movb   $0x0,0x18(%rsp)
  6f:	48 89 df             	mov    %rbx,%rdi
  72:	e8 00 00 00 00       	callq  77 <_Z5test1v+0x77>
  77:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  7e:	00 00 
