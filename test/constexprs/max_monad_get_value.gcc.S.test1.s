  10:	41 54                	push   %r12
  12:	55                   	push   %rbp
  13:	53                   	push   %rbx
  14:	48 83 ec 40          	sub    $0x40,%rsp
  18:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
  1d:	e8 00 00 00 00       	callq  22 <_Z5test2v+0x22>
  22:	0f b6 44 24 30       	movzbl 0x30(%rsp),%eax
  27:	84 c0                	test   %al,%al
  29:	74 54                	je     7f <_Z5test2v+0x7f>
  2b:	3c 02                	cmp    $0x2,%al
  2d:	74 5f                	je     8e <_Z5test2v+0x8e>
  2f:	3c 03                	cmp    $0x3,%al
  31:	74 0d                	je     40 <_Z5test2v+0x40>
  33:	8b 44 24 20          	mov    0x20(%rsp),%eax
  37:	48 83 c4 40          	add    $0x40,%rsp
  3b:	5b                   	pop    %rbx
  3c:	5d                   	pop    %rbp
  3d:	41 5c                	pop    %r12
  3f:	c3                   	retq   
  40:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
  45:	48 8d 74 24 20       	lea    0x20(%rsp),%rsi
  4a:	e8 00 00 00 00       	callq  4f <_Z5test2v+0x4f>
  4f:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
  54:	e8 00 00 00 00       	callq  59 <_Z5test2v+0x59>
  59:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
  5e:	48 89 c3             	mov    %rax,%rbx
  61:	e8 00 00 00 00       	callq  66 <_Z5test2v+0x66>
  66:	80 7c 24 30 03       	cmpb   $0x3,0x30(%rsp)
  6b:	75 0a                	jne    77 <_Z5test2v+0x77>
  6d:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
  72:	e8 00 00 00 00       	callq  77 <_Z5test2v+0x77>
  77:	48 89 df             	mov    %rbx,%rdi
  7a:	e8 00 00 00 00       	callq  7f <_Z5test2v+0x7f>
  7f:	bf 02 00 00 00       	mov    $0x2,%edi
  84:	e8 00 00 00 00       	callq  89 <_Z5test2v+0x89>
  89:	48 89 c3             	mov    %rax,%rbx
  8c:	eb d8                	jmp    66 <_Z5test2v+0x66>
  8e:	bf 20 00 00 00       	mov    $0x20,%edi
  93:	e8 00 00 00 00       	callq  98 <_Z5test2v+0x98>
  98:	48 8b 6c 24 28       	mov    0x28(%rsp),%rbp
  9d:	48 89 c3             	mov    %rax,%rbx
  a0:	44 8b 64 24 20       	mov    0x20(%rsp),%r12d
  a5:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
  aa:	48 8b 45 00          	mov    0x0(%rbp),%rax
  ae:	44 89 e2             	mov    %r12d,%edx
  b1:	48 89 ee             	mov    %rbp,%rsi
  b4:	ff 50 18             	callq  *0x18(%rax)
  b7:	48 8d 74 24 10       	lea    0x10(%rsp),%rsi
  bc:	48 89 df             	mov    %rbx,%rdi
  bf:	e8 00 00 00 00       	callq  c4 <_Z5test2v+0xc4>
  c4:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  c9:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  cd:	48 81 ff 00 00 00 00 	cmp    $0x0,%rdi
  d4:	75 34                	jne    10a <_Z5test2v+0x10a>
  d6:	48 c7 03 00 00 00 00 	movq   $0x0,(%rbx)
  dd:	44 89 63 10          	mov    %r12d,0x10(%rbx)
  e1:	ba 00 00 00 00       	mov    $0x0,%edx
  e6:	48 89 6b 18          	mov    %rbp,0x18(%rbx)
  ea:	be 00 00 00 00       	mov    $0x0,%esi
  ef:	48 89 df             	mov    %rbx,%rdi
  f2:	e8 00 00 00 00       	callq  f7 <_Z5test2v+0xf7>
  f7:	48 89 c5             	mov    %rax,%rbp
  fa:	48 89 df             	mov    %rbx,%rdi
  fd:	48 89 eb             	mov    %rbp,%rbx
 100:	e8 00 00 00 00       	callq  105 <_Z5test2v+0x105>
 105:	e9 5c ff ff ff       	jmpq   66 <_Z5test2v+0x66>
 10a:	48 8d 74 24 0f       	lea    0xf(%rsp),%rsi
 10f:	e8 00 00 00 00       	callq  114 <_Z5test2v+0x114>
 114:	eb c0                	jmp    d6 <_Z5test2v+0xd6>
 116:	48 89 c5             	mov    %rax,%rbp
 119:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
 11e:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
 122:	48 81 ff 00 00 00 00 	cmp    $0x0,%rdi
 129:	74 cf                	je     fa <_Z5test2v+0xfa>
 12b:	48 8d 74 24 0f       	lea    0xf(%rsp),%rsi
 130:	e8 00 00 00 00       	callq  135 <_Z5test2v+0x135>
 135:	eb c3                	jmp    fa <_Z5test2v+0xfa>
