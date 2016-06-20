  10:	41 54                	push   %r12
  12:	55                   	push   %rbp
  13:	53                   	push   %rbx
  14:	48 89 fb             	mov    %rdi,%rbx
  17:	48 83 ec 60          	sub    $0x60,%rsp
  1b:	48 89 e7             	mov    %rsp,%rdi
  1e:	e8 00 00 00 00       	callq  23 <_Z5test1v+0x13>
  23:	0f b6 54 24 18       	movzbl 0x18(%rsp),%edx
  28:	c6 44 24 38 00       	movb   $0x0,0x38(%rsp)
  2d:	80 fa 02             	cmp    $0x2,%dl
  30:	74 6e                	je     a0 <_Z5test1v+0x90>
  32:	80 fa 03             	cmp    $0x3,%dl
  35:	0f 84 f5 00 00 00    	je     130 <_Z5test1v+0x120>
  3b:	8b 04 24             	mov    (%rsp),%eax
  3e:	80 fa 01             	cmp    $0x1,%dl
  41:	8d 04 40             	lea    (%rax,%rax,2),%eax
  44:	74 41                	je     87 <_Z5test1v+0x77>
  46:	84 d2                	test   %dl,%dl
  48:	88 54 24 38          	mov    %dl,0x38(%rsp)
  4c:	0f 84 27 01 00 00    	je     179 <_Z5test1v+0x169>
  52:	80 fa 02             	cmp    $0x2,%dl
  55:	74 6b                	je     c2 <_Z5test1v+0xb2>
  57:	80 fa 03             	cmp    $0x3,%dl
  5a:	75 24                	jne    80 <_Z5test1v+0x70>
  5c:	48 8d 6c 24 20       	lea    0x20(%rsp),%rbp
  61:	48 8d 7c 24 40       	lea    0x40(%rsp),%rdi
  66:	48 89 ee             	mov    %rbp,%rsi
  69:	e8 00 00 00 00       	callq  6e <_Z5test1v+0x5e>
  6e:	48 8d 7c 24 40       	lea    0x40(%rsp),%rdi
  73:	e8 00 00 00 00       	callq  78 <_Z5test1v+0x68>
  78:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
  7f:	00 
  80:	8b 44 24 20          	mov    0x20(%rsp),%eax
  84:	8d 04 40             	lea    (%rax,%rax,2),%eax
  87:	89 03                	mov    %eax,(%rbx)
  89:	c6 43 18 01          	movb   $0x1,0x18(%rbx)
  8d:	48 83 c4 60          	add    $0x60,%rsp
  91:	48 89 d8             	mov    %rbx,%rax
  94:	5b                   	pop    %rbx
  95:	5d                   	pop    %rbp
  96:	41 5c                	pop    %r12
  98:	c3                   	retq   
  99:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
  a0:	48 8b 04 24          	mov    (%rsp),%rax
  a4:	c6 44 24 38 02       	movb   $0x2,0x38(%rsp)
  a9:	48 89 44 24 20       	mov    %rax,0x20(%rsp)
  ae:	48 8b 44 24 08       	mov    0x8(%rsp),%rax
  b3:	48 89 44 24 28       	mov    %rax,0x28(%rsp)
  b8:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  bd:	48 89 44 24 30       	mov    %rax,0x30(%rsp)
  c2:	bf 20 00 00 00       	mov    $0x20,%edi
  c7:	e8 00 00 00 00       	callq  cc <_Z5test1v+0xbc>
  cc:	48 8b 5c 24 28       	mov    0x28(%rsp),%rbx
  d1:	48 89 c5             	mov    %rax,%rbp
  d4:	44 8b 64 24 20       	mov    0x20(%rsp),%r12d
  d9:	48 8d 7c 24 40       	lea    0x40(%rsp),%rdi
  de:	48 8b 03             	mov    (%rbx),%rax
  e1:	44 89 e2             	mov    %r12d,%edx
  e4:	48 89 de             	mov    %rbx,%rsi
  e7:	ff 50 20             	callq  *0x20(%rax)
  ea:	48 8d 74 24 40       	lea    0x40(%rsp),%rsi
  ef:	48 89 ef             	mov    %rbp,%rdi
  f2:	e8 00 00 00 00       	callq  f7 <_Z5test1v+0xe7>
  f7:	48 8b 7c 24 40       	mov    0x40(%rsp),%rdi
  fc:	48 8d 44 24 50       	lea    0x50(%rsp),%rax
 101:	48 39 c7             	cmp    %rax,%rdi
 104:	74 05                	je     10b <_Z5test1v+0xfb>
 106:	e8 00 00 00 00       	callq  10b <_Z5test1v+0xfb>
 10b:	48 c7 45 00 00 00 00 	movq   $0x0,0x0(%rbp)
 112:	00 
 113:	44 89 65 10          	mov    %r12d,0x10(%rbp)
 117:	ba 00 00 00 00       	mov    $0x0,%edx
 11c:	48 89 5d 18          	mov    %rbx,0x18(%rbp)
 120:	be 00 00 00 00       	mov    $0x0,%esi
 125:	48 89 ef             	mov    %rbp,%rdi
 128:	e8 00 00 00 00       	callq  12d <_Z5test1v+0x11d>
 12d:	0f 1f 00             	nopl   (%rax)
 130:	48 8d 6c 24 20       	lea    0x20(%rsp),%rbp
 135:	48 89 e6             	mov    %rsp,%rsi
 138:	48 89 ef             	mov    %rbp,%rdi
 13b:	e8 00 00 00 00       	callq  140 <_Z5test1v+0x130>
 140:	0f b6 54 24 18       	movzbl 0x18(%rsp),%edx
 145:	e9 fc fe ff ff       	jmpq   46 <_Z5test1v+0x36>
 14a:	48 8d 7c 24 40       	lea    0x40(%rsp),%rdi
 14f:	48 89 c3             	mov    %rax,%rbx
 152:	e8 00 00 00 00       	callq  157 <_Z5test1v+0x147>
 157:	48 89 ef             	mov    %rbp,%rdi
 15a:	e8 00 00 00 00       	callq  15f <_Z5test1v+0x14f>
 15f:	48 89 e7             	mov    %rsp,%rdi
 162:	e8 00 00 00 00       	callq  167 <_Z5test1v+0x157>
 167:	48 89 df             	mov    %rbx,%rdi
 16a:	e8 00 00 00 00       	callq  16f <_Z5test1v+0x15f>
 16f:	48 89 c3             	mov    %rax,%rbx
 172:	48 8d 6c 24 20       	lea    0x20(%rsp),%rbp
 177:	eb de                	jmp    157 <_Z5test1v+0x147>
 179:	bf 02 00 00 00       	mov    $0x2,%edi
 17e:	e8 00 00 00 00       	callq  183 <_Z5test1v+0x173>
 183:	48 8b 7c 24 40       	mov    0x40(%rsp),%rdi
 188:	48 89 c3             	mov    %rax,%rbx
 18b:	48 8d 44 24 50       	lea    0x50(%rsp),%rax
 190:	48 39 c7             	cmp    %rax,%rdi
 193:	74 05                	je     19a <_Z5test1v+0x18a>
 195:	e8 00 00 00 00       	callq  19a <_Z5test1v+0x18a>
 19a:	48 89 ef             	mov    %rbp,%rdi
 19d:	48 8d 6c 24 20       	lea    0x20(%rsp),%rbp
 1a2:	e8 00 00 00 00       	callq  1a7 <_Z5test1v+0x197>
 1a7:	eb ae                	jmp    157 <_Z5test1v+0x147>
 1a9:	48 89 c3             	mov    %rax,%rbx
 1ac:	eb ec                	jmp    19a <_Z5test1v+0x18a>
