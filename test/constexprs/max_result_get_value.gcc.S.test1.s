  10:	41 54                	push   %r12
  12:	55                   	push   %rbp
  13:	53                   	push   %rbx
  14:	48 83 ec 40          	sub    $0x40,%rsp
  18:	48 89 e7             	mov    %rsp,%rdi
  1b:	e8 00 00 00 00       	callq  20 <_Z5test1v+0x10>
  20:	0f b6 44 24 18       	movzbl 0x18(%rsp),%eax
  25:	84 c0                	test   %al,%al
  27:	74 10                	je     39 <_Z5test1v+0x29>
  29:	3c 02                	cmp    $0x2,%al
  2b:	74 16                	je     43 <_Z5test1v+0x33>
  2d:	8b 04 24             	mov    (%rsp),%eax
  30:	48 83 c4 40          	add    $0x40,%rsp
  34:	5b                   	pop    %rbx
  35:	5d                   	pop    %rbp
  36:	41 5c                	pop    %r12
  38:	c3                   	retq   
  39:	bf 02 00 00 00       	mov    $0x2,%edi
  3e:	e8 00 00 00 00       	callq  43 <_Z5test1v+0x33>
  43:	bf 20 00 00 00       	mov    $0x20,%edi
  48:	e8 00 00 00 00       	callq  4d <_Z5test1v+0x3d>
  4d:	48 8b 6c 24 08       	mov    0x8(%rsp),%rbp
  52:	48 89 c3             	mov    %rax,%rbx
  55:	44 8b 24 24          	mov    (%rsp),%r12d
  59:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
  5e:	48 8b 45 00          	mov    0x0(%rbp),%rax
  62:	44 89 e2             	mov    %r12d,%edx
  65:	48 89 ee             	mov    %rbp,%rsi
  68:	ff 50 20             	callq  *0x20(%rax)
  6b:	48 8d 74 24 20       	lea    0x20(%rsp),%rsi
  70:	48 89 df             	mov    %rbx,%rdi
  73:	e8 00 00 00 00       	callq  78 <_Z5test1v+0x68>
  78:	48 8b 7c 24 20       	mov    0x20(%rsp),%rdi
  7d:	48 8d 44 24 30       	lea    0x30(%rsp),%rax
  82:	48 39 c7             	cmp    %rax,%rdi
  85:	74 05                	je     8c <_Z5test1v+0x7c>
  87:	e8 00 00 00 00       	callq  8c <_Z5test1v+0x7c>
  8c:	ba 00 00 00 00       	mov    $0x0,%edx
  91:	be 00 00 00 00       	mov    $0x0,%esi
  96:	48 89 df             	mov    %rbx,%rdi
  99:	48 c7 03 00 00 00 00 	movq   $0x0,(%rbx)
  a0:	44 89 63 10          	mov    %r12d,0x10(%rbx)
  a4:	48 89 6b 18          	mov    %rbp,0x18(%rbx)
  a8:	e8 00 00 00 00       	callq  ad <_Z5test1v+0x9d>
  ad:	48 8b 7c 24 20       	mov    0x20(%rsp),%rdi
  b2:	48 8d 54 24 30       	lea    0x30(%rsp),%rdx
  b7:	48 89 c5             	mov    %rax,%rbp
  ba:	48 39 d7             	cmp    %rdx,%rdi
  bd:	74 05                	je     c4 <_Z5test1v+0xb4>
  bf:	e8 00 00 00 00       	callq  c4 <_Z5test1v+0xb4>
  c4:	48 89 df             	mov    %rbx,%rdi
  c7:	e8 00 00 00 00       	callq  cc <_Z5test1v+0xbc>
  cc:	48 89 ef             	mov    %rbp,%rdi
  cf:	e8 00 00 00 00       	callq  d4 <_Z5test1v+0xc4>
  d4:	48 89 c5             	mov    %rax,%rbp
  d7:	eb eb                	jmp    c4 <_Z5test1v+0xb4>
