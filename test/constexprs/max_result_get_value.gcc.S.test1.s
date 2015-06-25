   2:	55                   	push   %rbp
   3:	53                   	push   %rbx
   4:	48 83 ec 28          	sub    $0x28,%rsp
   8:	48 89 e7             	mov    %rsp,%rdi
   b:	e8 00 00 00 00       	callq  10 <_Z5test2v+0x10>
  10:	0f b6 44 24 10       	movzbl 0x10(%rsp),%eax
  15:	84 c0                	test   %al,%al
  17:	74 0e                	je     27 <_Z5test2v+0x27>
  19:	3c 02                	cmp    $0x2,%al
  1b:	74 14                	je     31 <_Z5test2v+0x31>
  1d:	8b 04 24             	mov    (%rsp),%eax
  20:	48 83 c4 28          	add    $0x28,%rsp
  24:	5b                   	pop    %rbx
  25:	5d                   	pop    %rbp
  26:	c3                   	retq   
  27:	bf 02 00 00 00       	mov    $0x2,%edi
  2c:	e8 00 00 00 00       	callq  31 <_Z5test2v+0x31>
  31:	bf 20 00 00 00       	mov    $0x20,%edi
  36:	e8 00 00 00 00       	callq  3b <_Z5test2v+0x3b>
  3b:	8b 34 24             	mov    (%rsp),%esi
  3e:	48 8b 54 24 08       	mov    0x8(%rsp),%rdx
  43:	48 89 c7             	mov    %rax,%rdi
  46:	48 89 c3             	mov    %rax,%rbx
  49:	e8 00 00 00 00       	callq  4e <_Z5test2v+0x4e>
  4e:	ba 00 00 00 00       	mov    $0x0,%edx
  53:	be 00 00 00 00       	mov    $0x0,%esi
  58:	48 89 df             	mov    %rbx,%rdi
  5b:	e8 00 00 00 00       	callq  60 <_Z5test2v+0x60>
  60:	48 89 c5             	mov    %rax,%rbp
  63:	48 89 df             	mov    %rbx,%rdi
  66:	e8 00 00 00 00       	callq  6b <_Z5test2v+0x6b>
  6b:	48 89 ef             	mov    %rbp,%rdi
  6e:	e8 00 00 00 00       	callq  73 <_Z5test2v+0x73>
