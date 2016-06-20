  10:	41 54                	push   %r12
  12:	55                   	push   %rbp
  13:	53                   	push   %rbx
  14:	48 89 fb             	mov    %rdi,%rbx
  17:	48 83 ec 60          	sub    $0x60,%rsp
  1b:	48 89 e7             	mov    %rsp,%rdi
  1e:	e8 00 00 00 00       	callq  23 <_Z5test1v+0x13>
  23:	0f b6 44 24 18       	movzbl 0x18(%rsp),%eax
  28:	3c 01                	cmp    $0x1,%al
  2a:	0f 84 b0 00 00 00    	je     e0 <_Z5test1v+0xd0>
  30:	3c 02                	cmp    $0x2,%al
  32:	0f 85 88 00 00 00    	jne    c0 <_Z5test1v+0xb0>
  38:	48 8b 04 24          	mov    (%rsp),%rax
  3c:	8b 2c 24             	mov    (%rsp),%ebp
  3f:	48 89 44 24 20       	mov    %rax,0x20(%rsp)
  44:	48 8b 44 24 08       	mov    0x8(%rsp),%rax
  49:	48 89 44 24 28       	mov    %rax,0x28(%rsp)
  4e:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  53:	48 89 44 24 30       	mov    %rax,0x30(%rsp)
  58:	bf 20 00 00 00       	mov    $0x20,%edi
  5d:	e8 00 00 00 00       	callq  62 <_Z5test1v+0x52>
  62:	4c 8b 64 24 28       	mov    0x28(%rsp),%r12
  67:	48 89 c3             	mov    %rax,%rbx
  6a:	89 ea                	mov    %ebp,%edx
  6c:	48 8d 7c 24 40       	lea    0x40(%rsp),%rdi
  71:	49 8b 04 24          	mov    (%r12),%rax
  75:	4c 89 e6             	mov    %r12,%rsi
  78:	ff 50 20             	callq  *0x20(%rax)
  7b:	48 8d 74 24 40       	lea    0x40(%rsp),%rsi
  80:	48 89 df             	mov    %rbx,%rdi
  83:	e8 00 00 00 00       	callq  88 <_Z5test1v+0x78>
  88:	48 8b 7c 24 40       	mov    0x40(%rsp),%rdi
  8d:	48 8d 44 24 50       	lea    0x50(%rsp),%rax
  92:	48 39 c7             	cmp    %rax,%rdi
  95:	74 05                	je     9c <_Z5test1v+0x8c>
  97:	e8 00 00 00 00       	callq  9c <_Z5test1v+0x8c>
  9c:	48 c7 03 00 00 00 00 	movq   $0x0,(%rbx)
  a3:	89 6b 10             	mov    %ebp,0x10(%rbx)
  a6:	ba 00 00 00 00       	mov    $0x0,%edx
  ab:	4c 89 63 18          	mov    %r12,0x18(%rbx)
  af:	be 00 00 00 00       	mov    $0x0,%esi
  b4:	48 89 df             	mov    %rbx,%rdi
  b7:	e8 00 00 00 00       	callq  bc <_Z5test1v+0xac>
  bc:	0f 1f 40 00          	nopl   0x0(%rax)
  c0:	84 c0                	test   %al,%al
  c2:	74 21                	je     e5 <_Z5test1v+0xd5>
  c4:	3c 02                	cmp    $0x2,%al
  c6:	74 90                	je     58 <_Z5test1v+0x48>
  c8:	8d 44 6d 00          	lea    0x0(%rbp,%rbp,2),%eax
  cc:	c6 43 18 01          	movb   $0x1,0x18(%rbx)
  d0:	89 03                	mov    %eax,(%rbx)
  d2:	48 83 c4 60          	add    $0x60,%rsp
  d6:	48 89 d8             	mov    %rbx,%rax
  d9:	5b                   	pop    %rbx
  da:	5d                   	pop    %rbp
  db:	41 5c                	pop    %r12
  dd:	c3                   	retq   
  de:	66 90                	xchg   %ax,%ax
  e0:	8b 2c 24             	mov    (%rsp),%ebp
  e3:	eb e3                	jmp    c8 <_Z5test1v+0xb8>
  e5:	bf 02 00 00 00       	mov    $0x2,%edi
  ea:	e8 00 00 00 00       	callq  ef <_Z5test1v+0xdf>
  ef:	48 89 c5             	mov    %rax,%rbp
  f2:	48 89 df             	mov    %rbx,%rdi
  f5:	e8 00 00 00 00       	callq  fa <_Z5test1v+0xea>
  fa:	48 89 ef             	mov    %rbp,%rdi
  fd:	e8 00 00 00 00       	callq  102 <_Z5test1v+0xf2>
 102:	48 8b 7c 24 40       	mov    0x40(%rsp),%rdi
 107:	48 8d 54 24 50       	lea    0x50(%rsp),%rdx
 10c:	48 89 c5             	mov    %rax,%rbp
 10f:	48 39 d7             	cmp    %rdx,%rdi
 112:	74 de                	je     f2 <_Z5test1v+0xe2>
 114:	e8 00 00 00 00       	callq  119 <_Z5test1v+0x109>
 119:	eb d7                	jmp    f2 <_Z5test1v+0xe2>
