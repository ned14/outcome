  10:	41 54                	push   %r12
  12:	55                   	push   %rbp
  13:	53                   	push   %rbx
  14:	48 83 ec 40          	sub    $0x40,%rsp
  18:	48 89 e7             	mov    %rsp,%rdi
  1b:	e8 00 00 00 00       	callq  20 <_Z5test1v+0x10>
  20:	0f b6 44 24 18       	movzbl 0x18(%rsp),%eax
  25:	84 c0                	test   %al,%al
  27:	74 52                	je     7b <_Z5test1v+0x6b>
  29:	3c 02                	cmp    $0x2,%al
  2b:	74 5d                	je     8a <_Z5test1v+0x7a>
  2d:	3c 03                	cmp    $0x3,%al
  2f:	74 0f                	je     40 <_Z5test1v+0x30>
  31:	8b 04 24             	mov    (%rsp),%eax
  34:	48 83 c4 40          	add    $0x40,%rsp
  38:	5b                   	pop    %rbx
  39:	5d                   	pop    %rbp
  3a:	41 5c                	pop    %r12
  3c:	c3                   	retq   
  3d:	0f 1f 00             	nopl   (%rax)
  40:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
  45:	48 89 e6             	mov    %rsp,%rsi
  48:	e8 00 00 00 00       	callq  4d <_Z5test1v+0x3d>
  4d:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
  52:	e8 00 00 00 00       	callq  57 <_Z5test1v+0x47>
  57:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
  5c:	48 89 c3             	mov    %rax,%rbx
  5f:	e8 00 00 00 00       	callq  64 <_Z5test1v+0x54>
  64:	80 7c 24 18 03       	cmpb   $0x3,0x18(%rsp)
  69:	75 08                	jne    73 <_Z5test1v+0x63>
  6b:	48 89 e7             	mov    %rsp,%rdi
  6e:	e8 00 00 00 00       	callq  73 <_Z5test1v+0x63>
  73:	48 89 df             	mov    %rbx,%rdi
  76:	e8 00 00 00 00       	callq  7b <_Z5test1v+0x6b>
  7b:	bf 02 00 00 00       	mov    $0x2,%edi
  80:	e8 00 00 00 00       	callq  85 <_Z5test1v+0x75>
  85:	48 89 c3             	mov    %rax,%rbx
  88:	eb da                	jmp    64 <_Z5test1v+0x54>
  8a:	bf 20 00 00 00       	mov    $0x20,%edi
  8f:	e8 00 00 00 00       	callq  94 <_Z5test1v+0x84>
  94:	48 8b 6c 24 08       	mov    0x8(%rsp),%rbp
  99:	48 89 c3             	mov    %rax,%rbx
  9c:	44 8b 24 24          	mov    (%rsp),%r12d
  a0:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
  a5:	48 8b 45 00          	mov    0x0(%rbp),%rax
  a9:	44 89 e2             	mov    %r12d,%edx
  ac:	48 89 ee             	mov    %rbp,%rsi
  af:	ff 50 20             	callq  *0x20(%rax)
  b2:	48 8d 74 24 20       	lea    0x20(%rsp),%rsi
  b7:	48 89 df             	mov    %rbx,%rdi
  ba:	e8 00 00 00 00       	callq  bf <_Z5test1v+0xaf>
  bf:	48 8b 7c 24 20       	mov    0x20(%rsp),%rdi
  c4:	48 8d 44 24 30       	lea    0x30(%rsp),%rax
  c9:	48 39 c7             	cmp    %rax,%rdi
  cc:	74 05                	je     d3 <_Z5test1v+0xc3>
  ce:	e8 00 00 00 00       	callq  d3 <_Z5test1v+0xc3>
  d3:	48 c7 03 00 00 00 00 	movq   $0x0,(%rbx)
  da:	44 89 63 10          	mov    %r12d,0x10(%rbx)
  de:	ba 00 00 00 00       	mov    $0x0,%edx
  e3:	48 89 6b 18          	mov    %rbp,0x18(%rbx)
  e7:	be 00 00 00 00       	mov    $0x0,%esi
  ec:	48 89 df             	mov    %rbx,%rdi
  ef:	e8 00 00 00 00       	callq  f4 <_Z5test1v+0xe4>
  f4:	48 8b 7c 24 20       	mov    0x20(%rsp),%rdi
  f9:	48 8d 54 24 30       	lea    0x30(%rsp),%rdx
  fe:	48 89 c5             	mov    %rax,%rbp
 101:	48 39 d7             	cmp    %rdx,%rdi
 104:	74 05                	je     10b <_Z5test1v+0xfb>
 106:	e8 00 00 00 00       	callq  10b <_Z5test1v+0xfb>
 10b:	48 89 df             	mov    %rbx,%rdi
 10e:	48 89 eb             	mov    %rbp,%rbx
 111:	e8 00 00 00 00       	callq  116 <_Z5test1v+0x106>
 116:	e9 49 ff ff ff       	jmpq   64 <_Z5test1v+0x54>
 11b:	48 89 c5             	mov    %rax,%rbp
 11e:	eb eb                	jmp    10b <_Z5test1v+0xfb>
