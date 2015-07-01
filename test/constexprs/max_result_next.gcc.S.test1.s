   0:	41 54                	push   %r12
   2:	55                   	push   %rbp
   3:	53                   	push   %rbx
   4:	48 89 fb             	mov    %rdi,%rbx
   7:	48 83 ec 60          	sub    $0x60,%rsp
   b:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
  10:	e8 00 00 00 00       	callq  15 <_Z5test1v+0x15>
  15:	0f b6 54 24 30       	movzbl 0x30(%rsp),%edx
  1a:	80 fa 02             	cmp    $0x2,%dl
  1d:	74 49                	je     68 <_Z5test1v+0x68>
  1f:	80 fa 04             	cmp    $0x4,%dl
  22:	74 3c                	je     60 <_Z5test1v+0x60>
  24:	80 fa 01             	cmp    $0x1,%dl
  27:	74 27                	je     50 <_Z5test1v+0x50>
  29:	84 d2                	test   %dl,%dl
  2b:	0f 84 b1 00 00 00    	je     e2 <_Z5test1v+0xe2>
  31:	80 fa 02             	cmp    $0x2,%dl
  34:	74 4a                	je     80 <_Z5test1v+0x80>
  36:	8d 44 6d 00          	lea    0x0(%rbp,%rbp,2),%eax
  3a:	c6 43 10 01          	movb   $0x1,0x10(%rbx)
  3e:	89 03                	mov    %eax,(%rbx)
  40:	48 83 c4 60          	add    $0x60,%rsp
  44:	48 89 d8             	mov    %rbx,%rax
  47:	5b                   	pop    %rbx
  48:	5d                   	pop    %rbp
  49:	41 5c                	pop    %r12
  4b:	c3                   	retq   
  4c:	0f 1f 40 00          	nopl   0x0(%rax)
  50:	8b 6c 24 20          	mov    0x20(%rsp),%ebp
  54:	eb e0                	jmp    36 <_Z5test1v+0x36>
  56:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  5d:	00 00 00 
  60:	e8 00 00 00 00       	callq  65 <_Z5test1v+0x65>
  65:	0f 1f 00             	nopl   (%rax)
  68:	48 8b 44 24 20       	mov    0x20(%rsp),%rax
  6d:	48 8b 54 24 28       	mov    0x28(%rsp),%rdx
  72:	8b 6c 24 20          	mov    0x20(%rsp),%ebp
  76:	48 89 44 24 40       	mov    %rax,0x40(%rsp)
  7b:	48 89 54 24 48       	mov    %rdx,0x48(%rsp)
  80:	bf 20 00 00 00       	mov    $0x20,%edi
  85:	e8 00 00 00 00       	callq  8a <_Z5test1v+0x8a>
  8a:	4c 8b 64 24 48       	mov    0x48(%rsp),%r12
  8f:	48 89 c3             	mov    %rax,%rbx
  92:	89 ea                	mov    %ebp,%edx
  94:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
  99:	49 8b 04 24          	mov    (%r12),%rax
  9d:	4c 89 e6             	mov    %r12,%rsi
  a0:	ff 50 18             	callq  *0x18(%rax)
  a3:	48 8d 74 24 10       	lea    0x10(%rsp),%rsi
  a8:	48 89 df             	mov    %rbx,%rdi
  ab:	e8 00 00 00 00       	callq  b0 <_Z5test1v+0xb0>
  b0:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  b5:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  b9:	48 81 ff 00 00 00 00 	cmp    $0x0,%rdi
  c0:	75 5e                	jne    120 <_Z5test1v+0x120>
  c2:	48 c7 03 00 00 00 00 	movq   $0x0,(%rbx)
  c9:	89 6b 10             	mov    %ebp,0x10(%rbx)
  cc:	ba 00 00 00 00       	mov    $0x0,%edx
  d1:	4c 89 63 18          	mov    %r12,0x18(%rbx)
  d5:	be 00 00 00 00       	mov    $0x0,%esi
  da:	48 89 df             	mov    %rbx,%rdi
  dd:	e8 00 00 00 00       	callq  e2 <_Z5test1v+0xe2>
  e2:	bf 02 00 00 00       	mov    $0x2,%edi
  e7:	e8 00 00 00 00       	callq  ec <_Z5test1v+0xec>
  ec:	48 89 c5             	mov    %rax,%rbp
  ef:	48 89 df             	mov    %rbx,%rdi
  f2:	e8 00 00 00 00       	callq  f7 <_Z5test1v+0xf7>
  f7:	48 89 ef             	mov    %rbp,%rdi
  fa:	e8 00 00 00 00       	callq  ff <_Z5test1v+0xff>
  ff:	48 89 c5             	mov    %rax,%rbp
 102:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
 107:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
 10b:	48 81 ff 00 00 00 00 	cmp    $0x0,%rdi
 112:	74 db                	je     ef <_Z5test1v+0xef>
 114:	48 8d 74 24 0f       	lea    0xf(%rsp),%rsi
 119:	e8 00 00 00 00       	callq  11e <_Z5test1v+0x11e>
 11e:	eb cf                	jmp    ef <_Z5test1v+0xef>
 120:	48 8d 74 24 0f       	lea    0xf(%rsp),%rsi
 125:	e8 00 00 00 00       	callq  12a <_Z5test1v+0x12a>
 12a:	eb 96                	jmp    c2 <_Z5test1v+0xc2>
 12c:	0f 1f 40 00          	nopl   0x0(%rax)
