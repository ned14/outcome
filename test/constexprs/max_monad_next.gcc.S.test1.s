  10:	55                   	push   %rbp
  11:	53                   	push   %rbx
  12:	48 89 fb             	mov    %rdi,%rbx
  15:	48 83 ec 58          	sub    $0x58,%rsp
  19:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
  1e:	e8 00 00 00 00       	callq  23 <_Z5test2v+0x23>
  23:	0f b6 54 24 20       	movzbl 0x20(%rsp),%edx
  28:	c6 44 24 40 00       	movb   $0x0,0x40(%rsp)
  2d:	80 fa 02             	cmp    $0x2,%dl
  30:	74 7e                	je     b0 <_Z5test2v+0xb0>
  32:	80 fa 03             	cmp    $0x3,%dl
  35:	0f 84 c5 00 00 00    	je     100 <_Z5test2v+0x100>
  3b:	80 fa 01             	cmp    $0x1,%dl
  3e:	74 50                	je     90 <_Z5test2v+0x90>
  40:	84 d2                	test   %dl,%dl
  42:	88 54 24 40          	mov    %dl,0x40(%rsp)
  46:	0f 84 ff 00 00 00    	je     14b <_Z5test2v+0x14b>
  4c:	80 fa 02             	cmp    $0x2,%dl
  4f:	74 78                	je     c9 <_Z5test2v+0xc9>
  51:	80 fa 03             	cmp    $0x3,%dl
  54:	75 1a                	jne    70 <_Z5test2v+0x70>
  56:	48 8d 6c 24 30       	lea    0x30(%rsp),%rbp
  5b:	48 89 e7             	mov    %rsp,%rdi
  5e:	48 89 ee             	mov    %rbp,%rsi
  61:	e8 00 00 00 00       	callq  66 <_Z5test2v+0x66>
  66:	48 89 e7             	mov    %rsp,%rdi
  69:	e8 00 00 00 00       	callq  6e <_Z5test2v+0x6e>
  6e:	66 90                	xchg   %ax,%ax
  70:	8b 44 24 30          	mov    0x30(%rsp),%eax
  74:	c6 43 10 01          	movb   $0x1,0x10(%rbx)
  78:	8d 04 40             	lea    (%rax,%rax,2),%eax
  7b:	89 03                	mov    %eax,(%rbx)
  7d:	48 83 c4 58          	add    $0x58,%rsp
  81:	48 89 d8             	mov    %rbx,%rax
  84:	5b                   	pop    %rbx
  85:	5d                   	pop    %rbp
  86:	c3                   	retq   
  87:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  8e:	00 00 
  90:	8b 44 24 10          	mov    0x10(%rsp),%eax
  94:	c6 43 10 01          	movb   $0x1,0x10(%rbx)
  98:	8d 04 40             	lea    (%rax,%rax,2),%eax
  9b:	89 03                	mov    %eax,(%rbx)
  9d:	48 83 c4 58          	add    $0x58,%rsp
  a1:	48 89 d8             	mov    %rbx,%rax
  a4:	5b                   	pop    %rbx
  a5:	5d                   	pop    %rbp
  a6:	c3                   	retq   
  a7:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  ae:	00 00 
  b0:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  b5:	48 8b 54 24 18       	mov    0x18(%rsp),%rdx
  ba:	c6 44 24 40 02       	movb   $0x2,0x40(%rsp)
  bf:	48 89 44 24 30       	mov    %rax,0x30(%rsp)
  c4:	48 89 54 24 38       	mov    %rdx,0x38(%rsp)
  c9:	bf 20 00 00 00       	mov    $0x20,%edi
  ce:	e8 00 00 00 00       	callq  d3 <_Z5test2v+0xd3>
  d3:	8b 74 24 30          	mov    0x30(%rsp),%esi
  d7:	48 8b 54 24 38       	mov    0x38(%rsp),%rdx
  dc:	48 89 c7             	mov    %rax,%rdi
  df:	48 89 c5             	mov    %rax,%rbp
  e2:	e8 00 00 00 00       	callq  e7 <_Z5test2v+0xe7>
  e7:	ba 00 00 00 00       	mov    $0x0,%edx
  ec:	be 00 00 00 00       	mov    $0x0,%esi
  f1:	48 89 ef             	mov    %rbp,%rdi
  f4:	e8 00 00 00 00       	callq  f9 <_Z5test2v+0xf9>
  f9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
 100:	48 8d 6c 24 30       	lea    0x30(%rsp),%rbp
 105:	48 8d 74 24 10       	lea    0x10(%rsp),%rsi
 10a:	48 89 ef             	mov    %rbp,%rdi
 10d:	e8 00 00 00 00       	callq  112 <_Z5test2v+0x112>
 112:	0f b6 54 24 20       	movzbl 0x20(%rsp),%edx
 117:	e9 24 ff ff ff       	jmpq   40 <_Z5test2v+0x40>
 11c:	48 89 e7             	mov    %rsp,%rdi
 11f:	48 89 c3             	mov    %rax,%rbx
 122:	e8 00 00 00 00       	callq  127 <_Z5test2v+0x127>
 127:	48 89 ef             	mov    %rbp,%rdi
 12a:	e8 00 00 00 00       	callq  12f <_Z5test2v+0x12f>
 12f:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
 134:	e8 00 00 00 00       	callq  139 <_Z5test2v+0x139>
 139:	48 89 df             	mov    %rbx,%rdi
 13c:	e8 00 00 00 00       	callq  141 <_Z5test2v+0x141>
 141:	48 89 c3             	mov    %rax,%rbx
 144:	48 8d 6c 24 30       	lea    0x30(%rsp),%rbp
 149:	eb dc                	jmp    127 <_Z5test2v+0x127>
 14b:	bf 02 00 00 00       	mov    $0x2,%edi
 150:	e8 00 00 00 00       	callq  155 <_Z5test2v+0x155>
 155:	48 89 ef             	mov    %rbp,%rdi
 158:	48 89 c3             	mov    %rax,%rbx
 15b:	48 8d 6c 24 30       	lea    0x30(%rsp),%rbp
 160:	e8 00 00 00 00       	callq  165 <_Z5test2v+0x165>
 165:	eb c0                	jmp    127 <_Z5test2v+0x127>
