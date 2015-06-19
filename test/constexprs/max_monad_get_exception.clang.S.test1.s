   0:	41 56                	push   %r14
   2:	53                   	push   %rbx
   3:	48 83 ec 18          	sub    $0x18,%rsp
   7:	49 89 fe             	mov    %rdi,%r14
   a:	48 8d 1c 24          	lea    (%rsp),%rbx
   e:	48 89 df             	mov    %rbx,%rdi
  11:	e8 00 00 00 00       	callq  16 <_Z5test1v+0x16>
  16:	4c 89 f7             	mov    %r14,%rdi
  19:	48 89 de             	mov    %rbx,%rsi
  1c:	e8 00 00 00 00       	callq  21 <_Z5test1v+0x21>
  21:	8a 44 24 10          	mov    0x10(%rsp),%al
  25:	fe c8                	dec    %al
  27:	0f b6 c0             	movzbl %al,%eax
  2a:	83 f8 03             	cmp    $0x3,%eax
  2d:	77 1f                	ja     4e <_Z5test1v+0x4e>
  2f:	ff 24 c5 00 00 00 00 	jmpq   *0x0(,%rax,8)
  36:	48 8d 3c 24          	lea    (%rsp),%rdi
  3a:	e8 00 00 00 00       	callq  3f <_Z5test1v+0x3f>
  3f:	eb 08                	jmp    49 <_Z5test1v+0x49>
  41:	48 c7 04 24 00 00 00 	movq   $0x0,(%rsp)
  48:	00 
  49:	c6 44 24 10 00       	movb   $0x0,0x10(%rsp)
  4e:	4c 89 f0             	mov    %r14,%rax
  51:	48 83 c4 18          	add    $0x18,%rsp
  55:	5b                   	pop    %rbx
  56:	41 5e                	pop    %r14
  58:	c3                   	retq   
  59:	48 89 c3             	mov    %rax,%rbx
  5c:	8a 44 24 10          	mov    0x10(%rsp),%al
  60:	fe c8                	dec    %al
  62:	0f b6 c0             	movzbl %al,%eax
  65:	83 f8 03             	cmp    $0x3,%eax
  68:	77 1f                	ja     89 <_Z5test1v+0x89>
  6a:	ff 24 c5 00 00 00 00 	jmpq   *0x0(,%rax,8)
  71:	48 8d 3c 24          	lea    (%rsp),%rdi
  75:	e8 00 00 00 00       	callq  7a <_Z5test1v+0x7a>
  7a:	eb 08                	jmp    84 <_Z5test1v+0x84>
  7c:	48 c7 04 24 00 00 00 	movq   $0x0,(%rsp)
  83:	00 
  84:	c6 44 24 10 00       	movb   $0x0,0x10(%rsp)
  89:	48 89 df             	mov    %rbx,%rdi
  8c:	e8 00 00 00 00       	callq  91 <_Z5test1v+0x91>
  91:	66 66 66 66 66 66 2e 	data32 data32 data32 data32 data32 nopw %cs:0x0(%rax,%rax,1)
  98:	0f 1f 84 00 00 00 00 
  9f:	00 
