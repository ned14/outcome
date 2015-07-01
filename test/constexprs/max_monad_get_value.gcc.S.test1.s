   0:	41 54                	push   %r12
   2:	55                   	push   %rbp
   3:	53                   	push   %rbx
   4:	48 83 ec 40          	sub    $0x40,%rsp
   8:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
   d:	e8 00 00 00 00       	callq  12 <_Z5test1v+0x12>
  12:	0f b6 44 24 30       	movzbl 0x30(%rsp),%eax
  17:	84 c0                	test   %al,%al
  19:	74 54                	je     6f <_Z5test1v+0x6f>
  1b:	3c 02                	cmp    $0x2,%al
  1d:	74 5f                	je     7e <_Z5test1v+0x7e>
  1f:	3c 03                	cmp    $0x3,%al
  21:	74 0d                	je     30 <_Z5test1v+0x30>
  23:	8b 44 24 20          	mov    0x20(%rsp),%eax
  27:	48 83 c4 40          	add    $0x40,%rsp
  2b:	5b                   	pop    %rbx
  2c:	5d                   	pop    %rbp
  2d:	41 5c                	pop    %r12
  2f:	c3                   	retq   
  30:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
  35:	48 8d 74 24 20       	lea    0x20(%rsp),%rsi
  3a:	e8 00 00 00 00       	callq  3f <_Z5test1v+0x3f>
  3f:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
  44:	e8 00 00 00 00       	callq  49 <_Z5test1v+0x49>
  49:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
  4e:	48 89 c3             	mov    %rax,%rbx
  51:	e8 00 00 00 00       	callq  56 <_Z5test1v+0x56>
  56:	80 7c 24 30 03       	cmpb   $0x3,0x30(%rsp)
  5b:	75 0a                	jne    67 <_Z5test1v+0x67>
  5d:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
  62:	e8 00 00 00 00       	callq  67 <_Z5test1v+0x67>
  67:	48 89 df             	mov    %rbx,%rdi
  6a:	e8 00 00 00 00       	callq  6f <_Z5test1v+0x6f>
  6f:	bf 02 00 00 00       	mov    $0x2,%edi
  74:	e8 00 00 00 00       	callq  79 <_Z5test1v+0x79>
  79:	48 89 c3             	mov    %rax,%rbx
  7c:	eb d8                	jmp    56 <_Z5test1v+0x56>
  7e:	bf 20 00 00 00       	mov    $0x20,%edi
  83:	e8 00 00 00 00       	callq  88 <_Z5test1v+0x88>
  88:	48 8b 6c 24 28       	mov    0x28(%rsp),%rbp
  8d:	48 89 c3             	mov    %rax,%rbx
  90:	44 8b 64 24 20       	mov    0x20(%rsp),%r12d
  95:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
  9a:	48 8b 45 00          	mov    0x0(%rbp),%rax
  9e:	44 89 e2             	mov    %r12d,%edx
  a1:	48 89 ee             	mov    %rbp,%rsi
  a4:	ff 50 18             	callq  *0x18(%rax)
  a7:	48 8d 74 24 10       	lea    0x10(%rsp),%rsi
  ac:	48 89 df             	mov    %rbx,%rdi
  af:	e8 00 00 00 00       	callq  b4 <_Z5test1v+0xb4>
  b4:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  b9:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  bd:	48 81 ff 00 00 00 00 	cmp    $0x0,%rdi
  c4:	75 34                	jne    fa <_Z5test1v+0xfa>
  c6:	48 c7 03 00 00 00 00 	movq   $0x0,(%rbx)
  cd:	44 89 63 10          	mov    %r12d,0x10(%rbx)
  d1:	ba 00 00 00 00       	mov    $0x0,%edx
  d6:	48 89 6b 18          	mov    %rbp,0x18(%rbx)
  da:	be 00 00 00 00       	mov    $0x0,%esi
  df:	48 89 df             	mov    %rbx,%rdi
  e2:	e8 00 00 00 00       	callq  e7 <_Z5test1v+0xe7>
  e7:	48 89 c5             	mov    %rax,%rbp
  ea:	48 89 df             	mov    %rbx,%rdi
  ed:	48 89 eb             	mov    %rbp,%rbx
  f0:	e8 00 00 00 00       	callq  f5 <_Z5test1v+0xf5>
  f5:	e9 5c ff ff ff       	jmpq   56 <_Z5test1v+0x56>
  fa:	48 8d 74 24 0f       	lea    0xf(%rsp),%rsi
  ff:	e8 00 00 00 00       	callq  104 <_Z5test1v+0x104>
 104:	eb c0                	jmp    c6 <_Z5test1v+0xc6>
 106:	48 89 c5             	mov    %rax,%rbp
 109:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
 10e:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
 112:	48 81 ff 00 00 00 00 	cmp    $0x0,%rdi
 119:	74 cf                	je     ea <_Z5test1v+0xea>
 11b:	48 8d 74 24 0f       	lea    0xf(%rsp),%rsi
 120:	e8 00 00 00 00       	callq  125 <_Z5test1v+0x125>
 125:	eb c3                	jmp    ea <_Z5test1v+0xea>
 127:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
 12e:	00 00 
