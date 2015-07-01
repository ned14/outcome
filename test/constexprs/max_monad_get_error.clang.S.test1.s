   0:	55                   	push   %rbp
   1:	41 56                	push   %r14
   3:	53                   	push   %rbx
   4:	48 83 ec 20          	sub    $0x20,%rsp
   8:	48 8d 3c 24          	lea    (%rsp),%rdi
   c:	e8 00 00 00 00       	callq  11 <_Z5test1v+0x11>
  11:	0f b6 6c 24 10       	movzbl 0x10(%rsp),%ebp
  16:	83 fd 02             	cmp    $0x2,%ebp
  19:	74 64                	je     7f <_Z5test1v+0x7f>
  1b:	40 0f b6 c5          	movzbl %bpl,%eax
  1f:	83 f8 03             	cmp    $0x3,%eax
  22:	75 3f                	jne    63 <_Z5test1v+0x63>
  24:	48 c7 44 24 18 00 00 	movq   $0x0,0x18(%rsp)
  2b:	00 00 
  2d:	48 8d 5c 24 18       	lea    0x18(%rsp),%rbx
  32:	48 89 df             	mov    %rbx,%rdi
  35:	e8 00 00 00 00       	callq  3a <_Z5test1v+0x3a>
  3a:	41 be 03 00 00 00    	mov    $0x3,%r14d
  40:	40 8a 6c 24 10       	mov    0x10(%rsp),%bpl
  45:	40 fe cd             	dec    %bpl
  48:	40 0f b6 c5          	movzbl %bpl,%eax
  4c:	83 f8 03             	cmp    $0x3,%eax
  4f:	77 3c                	ja     8d <_Z5test1v+0x8d>
  51:	ff 24 c5 00 00 00 00 	jmpq   *0x0(,%rax,8)
  58:	48 8d 3c 24          	lea    (%rsp),%rdi
  5c:	e8 00 00 00 00       	callq  61 <_Z5test1v+0x61>
  61:	eb 25                	jmp    88 <_Z5test1v+0x88>
  63:	40 84 ed             	test   %bpl,%bpl
  66:	74 0d                	je     75 <_Z5test1v+0x75>
  68:	45 31 f6             	xor    %r14d,%r14d
  6b:	e8 00 00 00 00       	callq  70 <_Z5test1v+0x70>
  70:	48 89 c3             	mov    %rax,%rbx
  73:	eb d0                	jmp    45 <_Z5test1v+0x45>
  75:	bf 02 00 00 00       	mov    $0x2,%edi
  7a:	e8 00 00 00 00       	callq  7f <_Z5test1v+0x7f>
  7f:	44 8b 34 24          	mov    (%rsp),%r14d
  83:	48 8b 5c 24 08       	mov    0x8(%rsp),%rbx
  88:	c6 44 24 10 00       	movb   $0x0,0x10(%rsp)
  8d:	44 89 f0             	mov    %r14d,%eax
  90:	48 89 da             	mov    %rbx,%rdx
  93:	48 83 c4 20          	add    $0x20,%rsp
  97:	5b                   	pop    %rbx
  98:	41 5e                	pop    %r14
  9a:	5d                   	pop    %rbp
  9b:	c3                   	retq   
  9c:	48 89 c3             	mov    %rax,%rbx
  9f:	8a 44 24 10          	mov    0x10(%rsp),%al
  a3:	fe c8                	dec    %al
  a5:	0f b6 c0             	movzbl %al,%eax
  a8:	83 f8 03             	cmp    $0x3,%eax
  ab:	77 15                	ja     c2 <_Z5test1v+0xc2>
  ad:	ff 24 c5 00 00 00 00 	jmpq   *0x0(,%rax,8)
  b4:	48 8d 3c 24          	lea    (%rsp),%rdi
  b8:	e8 00 00 00 00       	callq  bd <_Z5test1v+0xbd>
  bd:	c6 44 24 10 00       	movb   $0x0,0x10(%rsp)
  c2:	48 89 df             	mov    %rbx,%rdi
  c5:	e8 00 00 00 00       	callq  ca <_Z5test1v+0xca>
  ca:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
