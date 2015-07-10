  10:	41 54                	push   %r12
  12:	55                   	push   %rbp
  13:	53                   	push   %rbx
  14:	48 83 ec 40          	sub    $0x40,%rsp
  18:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
  1d:	e8 00 00 00 00       	callq  22 <_Z5test2v+0x22>
  22:	0f b6 44 24 30       	movzbl 0x30(%rsp),%eax
  27:	84 c0                	test   %al,%al
  29:	74 11                	je     3c <_Z5test2v+0x3c>
  2b:	3c 02                	cmp    $0x2,%al
  2d:	74 17                	je     46 <_Z5test2v+0x46>
  2f:	8b 44 24 20          	mov    0x20(%rsp),%eax
  33:	48 83 c4 40          	add    $0x40,%rsp
  37:	5b                   	pop    %rbx
  38:	5d                   	pop    %rbp
  39:	41 5c                	pop    %r12
  3b:	c3                   	retq   
  3c:	bf 02 00 00 00       	mov    $0x2,%edi
  41:	e8 00 00 00 00       	callq  46 <_Z5test2v+0x46>
  46:	bf 20 00 00 00       	mov    $0x20,%edi
  4b:	e8 00 00 00 00       	callq  50 <_Z5test2v+0x50>
  50:	48 8b 6c 24 28       	mov    0x28(%rsp),%rbp
  55:	48 89 c3             	mov    %rax,%rbx
  58:	44 8b 64 24 20       	mov    0x20(%rsp),%r12d
  5d:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
  62:	48 8b 45 00          	mov    0x0(%rbp),%rax
  66:	44 89 e2             	mov    %r12d,%edx
  69:	48 89 ee             	mov    %rbp,%rsi
  6c:	ff 50 18             	callq  *0x18(%rax)
  6f:	48 8d 74 24 10       	lea    0x10(%rsp),%rsi
  74:	48 89 df             	mov    %rbx,%rdi
  77:	e8 00 00 00 00       	callq  7c <_Z5test2v+0x7c>
  7c:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  81:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  85:	48 81 ff 00 00 00 00 	cmp    $0x0,%rdi
  8c:	75 34                	jne    c2 <_Z5test2v+0xc2>
  8e:	ba 00 00 00 00       	mov    $0x0,%edx
  93:	be 00 00 00 00       	mov    $0x0,%esi
  98:	48 89 df             	mov    %rbx,%rdi
  9b:	48 c7 03 00 00 00 00 	movq   $0x0,(%rbx)
  a2:	44 89 63 10          	mov    %r12d,0x10(%rbx)
  a6:	48 89 6b 18          	mov    %rbp,0x18(%rbx)
  aa:	e8 00 00 00 00       	callq  af <_Z5test2v+0xaf>
  af:	48 89 c5             	mov    %rax,%rbp
  b2:	48 89 df             	mov    %rbx,%rdi
  b5:	e8 00 00 00 00       	callq  ba <_Z5test2v+0xba>
  ba:	48 89 ef             	mov    %rbp,%rdi
  bd:	e8 00 00 00 00       	callq  c2 <_Z5test2v+0xc2>
  c2:	48 8d 74 24 0f       	lea    0xf(%rsp),%rsi
  c7:	e8 00 00 00 00       	callq  cc <_Z5test2v+0xcc>
  cc:	eb c0                	jmp    8e <_Z5test2v+0x8e>
  ce:	48 89 c5             	mov    %rax,%rbp
  d1:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  d6:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  da:	48 81 ff 00 00 00 00 	cmp    $0x0,%rdi
  e1:	74 cf                	je     b2 <_Z5test2v+0xb2>
  e3:	48 8d 74 24 0f       	lea    0xf(%rsp),%rsi
  e8:	e8 00 00 00 00       	callq  ed <_Z5test2v+0xed>
  ed:	eb c3                	jmp    b2 <_Z5test2v+0xb2>
