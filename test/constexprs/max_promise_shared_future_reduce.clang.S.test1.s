   0:	55                   	push   %rbp
   1:	53                   	push   %rbx
   2:	48 81 ec 88 00 00 00 	sub    $0x88,%rsp
   9:	c6 44 24 50 00       	movb   $0x0,0x50(%rsp)
   e:	c6 44 24 58 00       	movb   $0x0,0x58(%rsp)
  13:	c6 44 24 59 00       	movb   $0x0,0x59(%rsp)
  18:	0f 57 c0             	xorps  %xmm0,%xmm0
  1b:	0f 11 44 24 70       	movups %xmm0,0x70(%rsp)
  20:	0f 11 44 24 60       	movups %xmm0,0x60(%rsp)
  25:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  2a:	48 8d 74 24 40       	lea    0x40(%rsp),%rsi
  2f:	e8 00 00 00 00       	callq  34 <_Z5test1v+0x34>
  34:	48 8d 7c 24 30       	lea    0x30(%rsp),%rdi
  39:	48 8d 74 24 08       	lea    0x8(%rsp),%rsi
  3e:	e8 00 00 00 00       	callq  43 <_Z5test1v+0x43>
  43:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  48:	e8 00 00 00 00       	callq  4d <_Z5test1v+0x4d>
  4d:	c7 44 24 04 05 00 00 	movl   $0x5,0x4(%rsp)
  54:	00 
  55:	48 8d 44 24 04       	lea    0x4(%rsp),%rax
  5a:	48 89 84 24 80 00 00 	mov    %rax,0x80(%rsp)
  61:	00 
  62:	48 8d 7c 24 40       	lea    0x40(%rsp),%rdi
  67:	48 8d b4 24 80 00 00 	lea    0x80(%rsp),%rsi
  6e:	00 
  6f:	e8 00 00 00 00       	callq  74 <_Z5test1v+0x74>
  74:	48 8b 7c 24 30       	mov    0x30(%rsp),%rdi
  79:	48 85 ff             	test   %rdi,%rdi
  7c:	0f 84 9a 00 00 00    	je     11c <_Z5test1v+0x11c>
  82:	e8 00 00 00 00       	callq  87 <_Z5test1v+0x87>
  87:	89 c5                	mov    %eax,%ebp
  89:	48 8b 5c 24 38       	mov    0x38(%rsp),%rbx
  8e:	48 85 db             	test   %rbx,%rbx
  91:	74 5c                	je     ef <_Z5test1v+0xef>
  93:	48 8d 43 08          	lea    0x8(%rbx),%rax
  97:	b9 00 00 00 00       	mov    $0x0,%ecx
  9c:	48 85 c9             	test   %rcx,%rcx
  9f:	74 0b                	je     ac <_Z5test1v+0xac>
  a1:	b9 ff ff ff ff       	mov    $0xffffffff,%ecx
  a6:	f0 0f c1 08          	lock xadd %ecx,(%rax)
  aa:	eb 07                	jmp    b3 <_Z5test1v+0xb3>
  ac:	8b 08                	mov    (%rax),%ecx
  ae:	8d 51 ff             	lea    -0x1(%rcx),%edx
  b1:	89 10                	mov    %edx,(%rax)
  b3:	83 f9 01             	cmp    $0x1,%ecx
  b6:	75 37                	jne    ef <_Z5test1v+0xef>
  b8:	48 8b 03             	mov    (%rbx),%rax
  bb:	48 89 df             	mov    %rbx,%rdi
  be:	ff 50 10             	callq  *0x10(%rax)
  c1:	48 8d 43 0c          	lea    0xc(%rbx),%rax
  c5:	b9 00 00 00 00       	mov    $0x0,%ecx
  ca:	48 85 c9             	test   %rcx,%rcx
  cd:	74 0b                	je     da <_Z5test1v+0xda>
  cf:	b9 ff ff ff ff       	mov    $0xffffffff,%ecx
  d4:	f0 0f c1 08          	lock xadd %ecx,(%rax)
  d8:	eb 07                	jmp    e1 <_Z5test1v+0xe1>
  da:	8b 08                	mov    (%rax),%ecx
  dc:	8d 51 ff             	lea    -0x1(%rcx),%edx
  df:	89 10                	mov    %edx,(%rax)
  e1:	83 f9 01             	cmp    $0x1,%ecx
  e4:	75 09                	jne    ef <_Z5test1v+0xef>
  e6:	48 8b 03             	mov    (%rbx),%rax
  e9:	48 89 df             	mov    %rbx,%rdi
  ec:	ff 50 18             	callq  *0x18(%rax)
  ef:	48 8d 7c 24 40       	lea    0x40(%rsp),%rdi
  f4:	e8 00 00 00 00       	callq  f9 <_Z5test1v+0xf9>
  f9:	89 e8                	mov    %ebp,%eax
  fb:	48 81 c4 88 00 00 00 	add    $0x88,%rsp
 102:	5b                   	pop    %rbx
 103:	5d                   	pop    %rbp
 104:	c3                   	retq   
 105:	48 89 c3             	mov    %rax,%rbx
 108:	e9 89 00 00 00       	jmpq   196 <_Z5test1v+0x196>
 10d:	48 89 c3             	mov    %rax,%rbx
 110:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
 115:	e8 00 00 00 00       	callq  11a <_Z5test1v+0x11a>
 11a:	eb 7a                	jmp    196 <_Z5test1v+0x196>
 11c:	bf 02 00 00 00       	mov    $0x2,%edi
 121:	e8 00 00 00 00       	callq  126 <_Z5test1v+0x126>
 126:	e9 57 ff ff ff       	jmpq   82 <_Z5test1v+0x82>
 12b:	48 89 c3             	mov    %rax,%rbx
 12e:	48 8b 6c 24 38       	mov    0x38(%rsp),%rbp
 133:	48 85 ed             	test   %rbp,%rbp
 136:	74 5e                	je     196 <_Z5test1v+0x196>
 138:	48 8d 45 08          	lea    0x8(%rbp),%rax
 13c:	b9 00 00 00 00       	mov    $0x0,%ecx
 141:	48 85 c9             	test   %rcx,%rcx
 144:	74 0b                	je     151 <_Z5test1v+0x151>
 146:	b9 ff ff ff ff       	mov    $0xffffffff,%ecx
 14b:	f0 0f c1 08          	lock xadd %ecx,(%rax)
 14f:	eb 07                	jmp    158 <_Z5test1v+0x158>
 151:	8b 08                	mov    (%rax),%ecx
 153:	8d 51 ff             	lea    -0x1(%rcx),%edx
 156:	89 10                	mov    %edx,(%rax)
 158:	83 f9 01             	cmp    $0x1,%ecx
 15b:	75 39                	jne    196 <_Z5test1v+0x196>
 15d:	48 8b 45 00          	mov    0x0(%rbp),%rax
 161:	48 89 ef             	mov    %rbp,%rdi
 164:	ff 50 10             	callq  *0x10(%rax)
 167:	48 8d 45 0c          	lea    0xc(%rbp),%rax
 16b:	b9 00 00 00 00       	mov    $0x0,%ecx
 170:	48 85 c9             	test   %rcx,%rcx
 173:	74 0b                	je     180 <_Z5test1v+0x180>
 175:	b9 ff ff ff ff       	mov    $0xffffffff,%ecx
 17a:	f0 0f c1 08          	lock xadd %ecx,(%rax)
 17e:	eb 07                	jmp    187 <_Z5test1v+0x187>
 180:	8b 08                	mov    (%rax),%ecx
 182:	8d 51 ff             	lea    -0x1(%rcx),%edx
 185:	89 10                	mov    %edx,(%rax)
 187:	83 f9 01             	cmp    $0x1,%ecx
 18a:	75 0a                	jne    196 <_Z5test1v+0x196>
 18c:	48 8b 45 00          	mov    0x0(%rbp),%rax
 190:	48 89 ef             	mov    %rbp,%rdi
 193:	ff 50 18             	callq  *0x18(%rax)
 196:	48 8d 7c 24 40       	lea    0x40(%rsp),%rdi
 19b:	e8 00 00 00 00       	callq  1a0 <_Z5test1v+0x1a0>
 1a0:	48 89 df             	mov    %rbx,%rdi
 1a3:	e8 00 00 00 00       	callq  1a8 <_Z5test1v+0x1a8>
 1a8:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
 1af:	00 
