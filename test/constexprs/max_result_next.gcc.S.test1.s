  10:	41 54                	push   %r12
  12:	55                   	push   %rbp
  13:	53                   	push   %rbx
  14:	48 89 fb             	mov    %rdi,%rbx
  17:	48 83 ec 60          	sub    $0x60,%rsp
  1b:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
  20:	e8 00 00 00 00       	callq  25 <_Z5test2v+0x25>
  25:	0f b6 44 24 30       	movzbl 0x30(%rsp),%eax
  2a:	3c 01                	cmp    $0x1,%al
  2c:	0f 84 ae 00 00 00    	je     e0 <_Z5test2v+0xe0>
  32:	3c 02                	cmp    $0x2,%al
  34:	0f 85 86 00 00 00    	jne    c0 <_Z5test2v+0xc0>
  3a:	48 8b 44 24 20       	mov    0x20(%rsp),%rax
  3f:	48 8b 54 24 28       	mov    0x28(%rsp),%rdx
  44:	8b 6c 24 20          	mov    0x20(%rsp),%ebp
  48:	48 89 44 24 40       	mov    %rax,0x40(%rsp)
  4d:	48 89 54 24 48       	mov    %rdx,0x48(%rsp)
  52:	bf 20 00 00 00       	mov    $0x20,%edi
  57:	e8 00 00 00 00       	callq  5c <_Z5test2v+0x5c>
  5c:	4c 8b 64 24 48       	mov    0x48(%rsp),%r12
  61:	48 89 c3             	mov    %rax,%rbx
  64:	89 ea                	mov    %ebp,%edx
  66:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
  6b:	49 8b 04 24          	mov    (%r12),%rax
  6f:	4c 89 e6             	mov    %r12,%rsi
  72:	ff 50 18             	callq  *0x18(%rax)
  75:	48 8d 74 24 10       	lea    0x10(%rsp),%rsi
  7a:	48 89 df             	mov    %rbx,%rdi
  7d:	e8 00 00 00 00       	callq  82 <_Z5test2v+0x82>
  82:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  87:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  8b:	48 81 ff 00 00 00 00 	cmp    $0x0,%rdi
  92:	0f 85 8c 00 00 00    	jne    124 <_Z5test2v+0x124>
  98:	48 c7 03 00 00 00 00 	movq   $0x0,(%rbx)
  9f:	89 6b 10             	mov    %ebp,0x10(%rbx)
  a2:	ba 00 00 00 00       	mov    $0x0,%edx
  a7:	4c 89 63 18          	mov    %r12,0x18(%rbx)
  ab:	be 00 00 00 00       	mov    $0x0,%esi
  b0:	48 89 df             	mov    %rbx,%rdi
  b3:	e8 00 00 00 00       	callq  b8 <_Z5test2v+0xb8>
  b8:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
  bf:	00 
  c0:	84 c0                	test   %al,%al
  c2:	74 22                	je     e6 <_Z5test2v+0xe6>
  c4:	3c 02                	cmp    $0x2,%al
  c6:	74 8a                	je     52 <_Z5test2v+0x52>
  c8:	8d 44 6d 00          	lea    0x0(%rbp,%rbp,2),%eax
  cc:	c6 43 10 01          	movb   $0x1,0x10(%rbx)
  d0:	89 03                	mov    %eax,(%rbx)
  d2:	48 83 c4 60          	add    $0x60,%rsp
  d6:	48 89 d8             	mov    %rbx,%rax
  d9:	5b                   	pop    %rbx
  da:	5d                   	pop    %rbp
  db:	41 5c                	pop    %r12
  dd:	c3                   	retq   
  de:	66 90                	xchg   %ax,%ax
  e0:	8b 6c 24 20          	mov    0x20(%rsp),%ebp
  e4:	eb e2                	jmp    c8 <_Z5test2v+0xc8>
  e6:	bf 02 00 00 00       	mov    $0x2,%edi
  eb:	e8 00 00 00 00       	callq  f0 <_Z5test2v+0xf0>
  f0:	48 89 c5             	mov    %rax,%rbp
  f3:	48 89 df             	mov    %rbx,%rdi
  f6:	e8 00 00 00 00       	callq  fb <_Z5test2v+0xfb>
  fb:	48 89 ef             	mov    %rbp,%rdi
  fe:	e8 00 00 00 00       	callq  103 <_Z5test2v+0x103>
 103:	48 89 c5             	mov    %rax,%rbp
 106:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
 10b:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
 10f:	48 81 ff 00 00 00 00 	cmp    $0x0,%rdi
 116:	74 db                	je     f3 <_Z5test2v+0xf3>
 118:	48 8d 74 24 0f       	lea    0xf(%rsp),%rsi
 11d:	e8 00 00 00 00       	callq  122 <_Z5test2v+0x122>
 122:	eb cf                	jmp    f3 <_Z5test2v+0xf3>
 124:	48 8d 74 24 0f       	lea    0xf(%rsp),%rsi
 129:	e8 00 00 00 00       	callq  12e <_Z5test2v+0x12e>
 12e:	e9 65 ff ff ff       	jmpq   98 <_Z5test2v+0x98>
