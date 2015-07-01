   0:	41 54                	push   %r12
   2:	55                   	push   %rbp
   3:	53                   	push   %rbx
   4:	48 83 ec 40          	sub    $0x40,%rsp
   8:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
   d:	e8 00 00 00 00       	callq  12 <_Z5test1v+0x12>
  12:	0f b6 44 24 30       	movzbl 0x30(%rsp),%eax
  17:	84 c0                	test   %al,%al
  19:	74 11                	je     2c <_Z5test1v+0x2c>
  1b:	3c 02                	cmp    $0x2,%al
  1d:	74 17                	je     36 <_Z5test1v+0x36>
  1f:	8b 44 24 20          	mov    0x20(%rsp),%eax
  23:	48 83 c4 40          	add    $0x40,%rsp
  27:	5b                   	pop    %rbx
  28:	5d                   	pop    %rbp
  29:	41 5c                	pop    %r12
  2b:	c3                   	retq   
  2c:	bf 02 00 00 00       	mov    $0x2,%edi
  31:	e8 00 00 00 00       	callq  36 <_Z5test1v+0x36>
  36:	bf 20 00 00 00       	mov    $0x20,%edi
  3b:	e8 00 00 00 00       	callq  40 <_Z5test1v+0x40>
  40:	48 8b 6c 24 28       	mov    0x28(%rsp),%rbp
  45:	48 89 c3             	mov    %rax,%rbx
  48:	44 8b 64 24 20       	mov    0x20(%rsp),%r12d
  4d:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
  52:	48 8b 45 00          	mov    0x0(%rbp),%rax
  56:	44 89 e2             	mov    %r12d,%edx
  59:	48 89 ee             	mov    %rbp,%rsi
  5c:	ff 50 18             	callq  *0x18(%rax)
  5f:	48 8d 74 24 10       	lea    0x10(%rsp),%rsi
  64:	48 89 df             	mov    %rbx,%rdi
  67:	e8 00 00 00 00       	callq  6c <_Z5test1v+0x6c>
  6c:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  71:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  75:	48 81 ff 00 00 00 00 	cmp    $0x0,%rdi
  7c:	75 34                	jne    b2 <_Z5test1v+0xb2>
  7e:	ba 00 00 00 00       	mov    $0x0,%edx
  83:	be 00 00 00 00       	mov    $0x0,%esi
  88:	48 89 df             	mov    %rbx,%rdi
  8b:	48 c7 03 00 00 00 00 	movq   $0x0,(%rbx)
  92:	44 89 63 10          	mov    %r12d,0x10(%rbx)
  96:	48 89 6b 18          	mov    %rbp,0x18(%rbx)
  9a:	e8 00 00 00 00       	callq  9f <_Z5test1v+0x9f>
  9f:	48 89 c5             	mov    %rax,%rbp
  a2:	48 89 df             	mov    %rbx,%rdi
  a5:	e8 00 00 00 00       	callq  aa <_Z5test1v+0xaa>
  aa:	48 89 ef             	mov    %rbp,%rdi
  ad:	e8 00 00 00 00       	callq  b2 <_Z5test1v+0xb2>
  b2:	48 8d 74 24 0f       	lea    0xf(%rsp),%rsi
  b7:	e8 00 00 00 00       	callq  bc <_Z5test1v+0xbc>
  bc:	eb c0                	jmp    7e <_Z5test1v+0x7e>
  be:	48 89 c5             	mov    %rax,%rbp
  c1:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  c6:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  ca:	48 81 ff 00 00 00 00 	cmp    $0x0,%rdi
  d1:	74 cf                	je     a2 <_Z5test1v+0xa2>
  d3:	48 8d 74 24 0f       	lea    0xf(%rsp),%rsi
  d8:	e8 00 00 00 00       	callq  dd <_Z5test1v+0xdd>
  dd:	eb c3                	jmp    a2 <_Z5test1v+0xa2>
  df:	90                   	nop
