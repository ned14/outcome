   2:	55                   	push   %rbp
   3:	53                   	push   %rbx
   4:	48 89 fb             	mov    %rdi,%rbx
   7:	48 83 ec 48          	sub    $0x48,%rsp
   b:	48 89 e7             	mov    %rsp,%rdi
   e:	e8 00 00 00 00       	callq  13 <_Z5test2v+0x13>
  13:	0f b6 54 24 10       	movzbl 0x10(%rsp),%edx
  18:	80 fa 02             	cmp    $0x2,%dl
  1b:	74 3b                	je     58 <_Z5test2v+0x58>
  1d:	80 fa 04             	cmp    $0x4,%dl
  20:	74 2e                	je     50 <_Z5test2v+0x50>
  22:	80 fa 01             	cmp    $0x1,%dl
  25:	74 21                	je     48 <_Z5test2v+0x48>
  27:	84 d2                	test   %dl,%dl
  29:	74 71                	je     9c <_Z5test2v+0x9c>
  2b:	80 fa 02             	cmp    $0x2,%dl
  2e:	74 3e                	je     6e <_Z5test2v+0x6e>
  30:	8d 44 6d 00          	lea    0x0(%rbp,%rbp,2),%eax
  34:	c6 43 10 01          	movb   $0x1,0x10(%rbx)
  38:	89 03                	mov    %eax,(%rbx)
  3a:	48 83 c4 48          	add    $0x48,%rsp
  3e:	48 89 d8             	mov    %rbx,%rax
  41:	5b                   	pop    %rbx
  42:	5d                   	pop    %rbp
  43:	c3                   	retq   
  44:	0f 1f 40 00          	nopl   0x0(%rax)
  48:	8b 2c 24             	mov    (%rsp),%ebp
  4b:	eb e3                	jmp    30 <_Z5test2v+0x30>
  4d:	0f 1f 00             	nopl   (%rax)
  50:	e8 00 00 00 00       	callq  55 <_Z5test2v+0x55>
  55:	0f 1f 00             	nopl   (%rax)
  58:	48 8b 04 24          	mov    (%rsp),%rax
  5c:	48 8b 54 24 08       	mov    0x8(%rsp),%rdx
  61:	8b 2c 24             	mov    (%rsp),%ebp
  64:	48 89 44 24 20       	mov    %rax,0x20(%rsp)
  69:	48 89 54 24 28       	mov    %rdx,0x28(%rsp)
  6e:	bf 20 00 00 00       	mov    $0x20,%edi
  73:	e8 00 00 00 00       	callq  78 <_Z5test2v+0x78>
  78:	48 8b 54 24 28       	mov    0x28(%rsp),%rdx
  7d:	89 ee                	mov    %ebp,%esi
  7f:	48 89 c7             	mov    %rax,%rdi
  82:	48 89 c3             	mov    %rax,%rbx
  85:	e8 00 00 00 00       	callq  8a <_Z5test2v+0x8a>
  8a:	ba 00 00 00 00       	mov    $0x0,%edx
  8f:	be 00 00 00 00       	mov    $0x0,%esi
  94:	48 89 df             	mov    %rbx,%rdi
  97:	e8 00 00 00 00       	callq  9c <_Z5test2v+0x9c>
  9c:	bf 02 00 00 00       	mov    $0x2,%edi
  a1:	e8 00 00 00 00       	callq  a6 <_Z5test2v+0xa6>
  a6:	48 89 c5             	mov    %rax,%rbp
  a9:	48 89 df             	mov    %rbx,%rdi
  ac:	e8 00 00 00 00       	callq  b1 <_Z5test2v+0xb1>
  b1:	48 89 ef             	mov    %rbp,%rdi
  b4:	e8 00 00 00 00       	callq  b9 <_Z5test2v+0xb9>
