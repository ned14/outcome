   0:	55                   	push   %rbp
   1:	41 56                	push   %r14
   3:	53                   	push   %rbx
   4:	48 83 ec 20          	sub    $0x20,%rsp
   8:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
   d:	e8 00 00 00 00       	callq  12 <_Z5test1v+0x12>
  12:	0f b6 5c 24 18       	movzbl 0x18(%rsp),%ebx
  17:	83 fb 02             	cmp    $0x2,%ebx
  1a:	75 1c                	jne    38 <_Z5test1v+0x38>
  1c:	8b 6c 24 08          	mov    0x8(%rsp),%ebp
  20:	4c 8b 74 24 10       	mov    0x10(%rsp),%r14
  25:	c6 44 24 18 00       	movb   $0x0,0x18(%rsp)
  2a:	89 e8                	mov    %ebp,%eax
  2c:	4c 89 f2             	mov    %r14,%rdx
  2f:	48 83 c4 20          	add    $0x20,%rsp
  33:	5b                   	pop    %rbx
  34:	41 5e                	pop    %r14
  36:	5d                   	pop    %rbp
  37:	c3                   	retq   
  38:	84 db                	test   %bl,%bl
  3a:	74 35                	je     71 <_Z5test1v+0x71>
  3c:	e8 00 00 00 00       	callq  41 <_Z5test1v+0x41>
  41:	49 89 c6             	mov    %rax,%r14
  44:	31 ed                	xor    %ebp,%ebp
  46:	0f b6 c3             	movzbl %bl,%eax
  49:	83 f8 04             	cmp    $0x4,%eax
  4c:	74 11                	je     5f <_Z5test1v+0x5f>
  4e:	83 f8 03             	cmp    $0x3,%eax
  51:	75 17                	jne    6a <_Z5test1v+0x6a>
  53:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  58:	e8 00 00 00 00       	callq  5d <_Z5test1v+0x5d>
  5d:	eb c6                	jmp    25 <_Z5test1v+0x25>
  5f:	48 c7 44 24 08 00 00 	movq   $0x0,0x8(%rsp)
  66:	00 00 
  68:	eb bb                	jmp    25 <_Z5test1v+0x25>
  6a:	83 f8 01             	cmp    $0x1,%eax
  6d:	74 b6                	je     25 <_Z5test1v+0x25>
  6f:	eb b9                	jmp    2a <_Z5test1v+0x2a>
  71:	e8 00 00 00 00       	callq  76 <_Z5test1v+0x76>
  76:	eb a4                	jmp    1c <_Z5test1v+0x1c>
  78:	48 89 c3             	mov    %rax,%rbx
  7b:	8a 44 24 18          	mov    0x18(%rsp),%al
  7f:	fe c8                	dec    %al
  81:	0f b6 c0             	movzbl %al,%eax
  84:	83 f8 03             	cmp    $0x3,%eax
  87:	77 21                	ja     aa <_Z5test1v+0xaa>
  89:	ff 24 c5 00 00 00 00 	jmpq   *0x0(,%rax,8)
  90:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  95:	e8 00 00 00 00       	callq  9a <_Z5test1v+0x9a>
  9a:	eb 09                	jmp    a5 <_Z5test1v+0xa5>
  9c:	48 c7 44 24 08 00 00 	movq   $0x0,0x8(%rsp)
  a3:	00 00 
  a5:	c6 44 24 18 00       	movb   $0x0,0x18(%rsp)
  aa:	48 89 df             	mov    %rbx,%rdi
  ad:	e8 00 00 00 00       	callq  b2 <_Z5test1v+0xb2>
  b2:	66 66 66 66 66 2e 0f 	data32 data32 data32 data32 nopw %cs:0x0(%rax,%rax,1)
  b9:	1f 84 00 00 00 00 00 
