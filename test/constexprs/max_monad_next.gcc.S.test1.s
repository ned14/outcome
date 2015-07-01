  10:	55                   	push   %rbp
  11:	53                   	push   %rbx
  12:	48 89 fb             	mov    %rdi,%rbx
  15:	48 83 ec 58          	sub    $0x58,%rsp
  19:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
  1e:	e8 00 00 00 00       	callq  23 <_Z5test2v+0x23>
  23:	0f b6 54 24 20       	movzbl 0x20(%rsp),%edx
  28:	c6 44 24 40 00       	movb   $0x0,0x40(%rsp)
  2d:	80 fa 02             	cmp    $0x2,%dl
  30:	0f 84 9a 00 00 00    	je     d0 <_Z5test2v+0xd0>
  36:	76 78                	jbe    b0 <_Z5test2v+0xb0>
  38:	80 fa 03             	cmp    $0x3,%dl
  3b:	74 13                	je     50 <_Z5test2v+0x50>
  3d:	80 fa 04             	cmp    $0x4,%dl
  40:	75 25                	jne    67 <_Z5test2v+0x67>
  42:	e8 00 00 00 00       	callq  47 <_Z5test2v+0x47>
  47:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  4e:	00 00 
  50:	48 8d 6c 24 30       	lea    0x30(%rsp),%rbp
  55:	48 8d 74 24 10       	lea    0x10(%rsp),%rsi
  5a:	48 89 ef             	mov    %rbp,%rdi
  5d:	e8 00 00 00 00       	callq  62 <_Z5test2v+0x62>
  62:	0f b6 54 24 20       	movzbl 0x20(%rsp),%edx
  67:	84 d2                	test   %dl,%dl
  69:	88 54 24 40          	mov    %dl,0x40(%rsp)
  6d:	0f 84 d5 00 00 00    	je     148 <_Z5test2v+0x148>
  73:	80 fa 02             	cmp    $0x2,%dl
  76:	74 71                	je     e9 <_Z5test2v+0xe9>
  78:	80 fa 03             	cmp    $0x3,%dl
  7b:	75 1b                	jne    98 <_Z5test2v+0x98>
  7d:	48 8d 6c 24 30       	lea    0x30(%rsp),%rbp
  82:	48 89 e7             	mov    %rsp,%rdi
  85:	48 89 ee             	mov    %rbp,%rsi
  88:	e8 00 00 00 00       	callq  8d <_Z5test2v+0x8d>
  8d:	48 89 e7             	mov    %rsp,%rdi
  90:	e8 00 00 00 00       	callq  95 <_Z5test2v+0x95>
  95:	0f 1f 00             	nopl   (%rax)
  98:	8b 44 24 30          	mov    0x30(%rsp),%eax
  9c:	c6 43 10 01          	movb   $0x1,0x10(%rbx)
  a0:	8d 04 40             	lea    (%rax,%rax,2),%eax
  a3:	89 03                	mov    %eax,(%rbx)
  a5:	48 83 c4 58          	add    $0x58,%rsp
  a9:	48 89 d8             	mov    %rbx,%rax
  ac:	5b                   	pop    %rbx
  ad:	5d                   	pop    %rbp
  ae:	c3                   	retq   
  af:	90                   	nop
  b0:	80 fa 01             	cmp    $0x1,%dl
  b3:	75 b2                	jne    67 <_Z5test2v+0x67>
  b5:	8b 44 24 10          	mov    0x10(%rsp),%eax
  b9:	c6 43 10 01          	movb   $0x1,0x10(%rbx)
  bd:	8d 04 40             	lea    (%rax,%rax,2),%eax
  c0:	89 03                	mov    %eax,(%rbx)
  c2:	48 83 c4 58          	add    $0x58,%rsp
  c6:	48 89 d8             	mov    %rbx,%rax
  c9:	5b                   	pop    %rbx
  ca:	5d                   	pop    %rbp
  cb:	c3                   	retq   
  cc:	0f 1f 40 00          	nopl   0x0(%rax)
  d0:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  d5:	48 8b 54 24 18       	mov    0x18(%rsp),%rdx
  da:	c6 44 24 40 02       	movb   $0x2,0x40(%rsp)
  df:	48 89 44 24 30       	mov    %rax,0x30(%rsp)
  e4:	48 89 54 24 38       	mov    %rdx,0x38(%rsp)
  e9:	bf 20 00 00 00       	mov    $0x20,%edi
  ee:	e8 00 00 00 00       	callq  f3 <_Z5test2v+0xf3>
  f3:	8b 74 24 30          	mov    0x30(%rsp),%esi
  f7:	48 8b 54 24 38       	mov    0x38(%rsp),%rdx
  fc:	48 89 c7             	mov    %rax,%rdi
  ff:	48 89 c5             	mov    %rax,%rbp
 102:	e8 00 00 00 00       	callq  107 <_Z5test2v+0x107>
 107:	ba 00 00 00 00       	mov    $0x0,%edx
 10c:	be 00 00 00 00       	mov    $0x0,%esi
 111:	48 89 ef             	mov    %rbp,%rdi
 114:	e8 00 00 00 00       	callq  119 <_Z5test2v+0x119>
 119:	48 89 e7             	mov    %rsp,%rdi
 11c:	48 89 c3             	mov    %rax,%rbx
 11f:	e8 00 00 00 00       	callq  124 <_Z5test2v+0x124>
 124:	48 89 ef             	mov    %rbp,%rdi
 127:	e8 00 00 00 00       	callq  12c <_Z5test2v+0x12c>
 12c:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
 131:	e8 00 00 00 00       	callq  136 <_Z5test2v+0x136>
 136:	48 89 df             	mov    %rbx,%rdi
 139:	e8 00 00 00 00       	callq  13e <_Z5test2v+0x13e>
 13e:	48 89 c3             	mov    %rax,%rbx
 141:	48 8d 6c 24 30       	lea    0x30(%rsp),%rbp
 146:	eb dc                	jmp    124 <_Z5test2v+0x124>
 148:	bf 02 00 00 00       	mov    $0x2,%edi
 14d:	e8 00 00 00 00       	callq  152 <_Z5test2v+0x152>
 152:	48 89 ef             	mov    %rbp,%rdi
 155:	48 89 c3             	mov    %rax,%rbx
 158:	48 8d 6c 24 30       	lea    0x30(%rsp),%rbp
 15d:	e8 00 00 00 00       	callq  162 <_Z5test2v+0x162>
 162:	eb c0                	jmp    124 <_Z5test2v+0x124>
