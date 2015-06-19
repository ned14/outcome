  10:	55                   	push   %rbp
  11:	53                   	push   %rbx
  12:	48 89 fb             	mov    %rdi,%rbx
  15:	48 83 ec 68          	sub    $0x68,%rsp
  19:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
  1e:	e8 00 00 00 00       	callq  23 <_Z5test2v+0x23>
  23:	0f b6 54 24 30       	movzbl 0x30(%rsp),%edx
  28:	c6 44 24 50 00       	movb   $0x0,0x50(%rsp)
  2d:	80 fa 02             	cmp    $0x2,%dl
  30:	0f 84 3a 01 00 00    	je     170 <_Z5test2v+0x170>
  36:	76 68                	jbe    a0 <_Z5test2v+0xa0>
  38:	80 fa 03             	cmp    $0x3,%dl
  3b:	74 13                	je     50 <_Z5test2v+0x50>
  3d:	80 fa 04             	cmp    $0x4,%dl
  40:	75 25                	jne    67 <_Z5test2v+0x67>
  42:	e8 00 00 00 00       	callq  47 <_Z5test2v+0x47>
  47:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  4e:	00 00 
  50:	48 8d 6c 24 40       	lea    0x40(%rsp),%rbp
  55:	48 8d 74 24 20       	lea    0x20(%rsp),%rsi
  5a:	48 89 ef             	mov    %rbp,%rdi
  5d:	e8 00 00 00 00       	callq  62 <_Z5test2v+0x62>
  62:	0f b6 54 24 30       	movzbl 0x30(%rsp),%edx
  67:	84 d2                	test   %dl,%dl
  69:	88 54 24 50          	mov    %dl,0x50(%rsp)
  6d:	74 51                	je     c0 <_Z5test2v+0xc0>
  6f:	80 fa 02             	cmp    $0x2,%dl
  72:	0f 84 11 01 00 00    	je     189 <_Z5test2v+0x189>
  78:	80 fa 03             	cmp    $0x3,%dl
  7b:	0f 84 99 01 00 00    	je     21a <_Z5test2v+0x21a>
  81:	8b 44 24 40          	mov    0x40(%rsp),%eax
  85:	c6 43 10 01          	movb   $0x1,0x10(%rbx)
  89:	8d 04 40             	lea    (%rax,%rax,2),%eax
  8c:	89 03                	mov    %eax,(%rbx)
  8e:	48 83 c4 68          	add    $0x68,%rsp
  92:	48 89 d8             	mov    %rbx,%rax
  95:	5b                   	pop    %rbx
  96:	5d                   	pop    %rbp
  97:	c3                   	retq   
  98:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
  9f:	00 
  a0:	80 fa 01             	cmp    $0x1,%dl
  a3:	75 c2                	jne    67 <_Z5test2v+0x67>
  a5:	8b 44 24 20          	mov    0x20(%rsp),%eax
  a9:	c6 43 10 01          	movb   $0x1,0x10(%rbx)
  ad:	8d 04 40             	lea    (%rax,%rax,2),%eax
  b0:	89 03                	mov    %eax,(%rbx)
  b2:	48 83 c4 68          	add    $0x68,%rsp
  b6:	48 89 d8             	mov    %rbx,%rax
  b9:	5b                   	pop    %rbx
  ba:	5d                   	pop    %rbp
  bb:	c3                   	retq   
  bc:	0f 1f 40 00          	nopl   0x0(%rax)
  c0:	bf 20 00 00 00       	mov    $0x20,%edi
  c5:	e8 00 00 00 00       	callq  ca <_Z5test2v+0xca>
  ca:	80 3d 00 00 00 00 00 	cmpb   $0x0,0x0(%rip)        # d1 <_Z5test2v+0xd1>
  d1:	48 89 c3             	mov    %rax,%rbx
  d4:	74 62                	je     138 <_Z5test2v+0x138>
  d6:	48 8d 54 24 0f       	lea    0xf(%rsp),%rdx
  db:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
  e0:	be 00 00 00 00       	mov    $0x0,%esi
  e5:	e8 00 00 00 00       	callq  ea <_Z5test2v+0xea>
  ea:	48 8d 74 24 10       	lea    0x10(%rsp),%rsi
  ef:	48 89 df             	mov    %rbx,%rdi
  f2:	e8 00 00 00 00       	callq  f7 <_Z5test2v+0xf7>
  f7:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  fc:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
 100:	48 81 ff 00 00 00 00 	cmp    $0x0,%rdi
 107:	0f 85 d3 00 00 00    	jne    1e0 <_Z5test2v+0x1e0>
 10d:	48 c7 03 00 00 00 00 	movq   $0x0,(%rbx)
 114:	c7 43 10 02 00 00 00 	movl   $0x2,0x10(%rbx)
 11b:	ba 00 00 00 00       	mov    $0x0,%edx
 120:	48 c7 43 18 00 00 00 	movq   $0x0,0x18(%rbx)
 127:	00 
 128:	be 00 00 00 00       	mov    $0x0,%esi
 12d:	48 89 df             	mov    %rbx,%rdi
 130:	e8 00 00 00 00       	callq  135 <_Z5test2v+0x135>
 135:	0f 1f 00             	nopl   (%rax)
 138:	bf 00 00 00 00       	mov    $0x0,%edi
 13d:	e8 00 00 00 00       	callq  142 <_Z5test2v+0x142>
 142:	85 c0                	test   %eax,%eax
 144:	74 90                	je     d6 <_Z5test2v+0xd6>
 146:	bf 00 00 00 00       	mov    $0x0,%edi
 14b:	e8 00 00 00 00       	callq  150 <_Z5test2v+0x150>
 150:	ba 00 00 00 00       	mov    $0x0,%edx
 155:	be 00 00 00 00       	mov    $0x0,%esi
 15a:	bf 00 00 00 00       	mov    $0x0,%edi
 15f:	e8 00 00 00 00       	callq  164 <_Z5test2v+0x164>
 164:	e9 6d ff ff ff       	jmpq   d6 <_Z5test2v+0xd6>
 169:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
 170:	48 8b 44 24 20       	mov    0x20(%rsp),%rax
 175:	48 8b 54 24 28       	mov    0x28(%rsp),%rdx
 17a:	c6 44 24 50 02       	movb   $0x2,0x50(%rsp)
 17f:	48 89 44 24 40       	mov    %rax,0x40(%rsp)
 184:	48 89 54 24 48       	mov    %rdx,0x48(%rsp)
 189:	bf 20 00 00 00       	mov    $0x20,%edi
 18e:	e8 00 00 00 00       	callq  193 <_Z5test2v+0x193>
 193:	8b 74 24 40          	mov    0x40(%rsp),%esi
 197:	48 8b 54 24 48       	mov    0x48(%rsp),%rdx
 19c:	48 89 c7             	mov    %rax,%rdi
 19f:	48 89 c5             	mov    %rax,%rbp
 1a2:	e8 00 00 00 00       	callq  1a7 <_Z5test2v+0x1a7>
 1a7:	ba 00 00 00 00       	mov    $0x0,%edx
 1ac:	be 00 00 00 00       	mov    $0x0,%esi
 1b1:	48 89 ef             	mov    %rbp,%rdi
 1b4:	e8 00 00 00 00       	callq  1b9 <_Z5test2v+0x1b9>
 1b9:	48 8d 6c 24 40       	lea    0x40(%rsp),%rbp
 1be:	48 89 c3             	mov    %rax,%rbx
 1c1:	48 89 ef             	mov    %rbp,%rdi
 1c4:	e8 00 00 00 00       	callq  1c9 <_Z5test2v+0x1c9>
 1c9:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
 1ce:	e8 00 00 00 00       	callq  1d3 <_Z5test2v+0x1d3>
 1d3:	48 89 df             	mov    %rbx,%rdi
 1d6:	e8 00 00 00 00       	callq  1db <_Z5test2v+0x1db>
 1db:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
 1e0:	ba 00 00 00 00       	mov    $0x0,%edx
 1e5:	48 85 d2             	test   %rdx,%rdx
 1e8:	74 23                	je     20d <_Z5test2v+0x20d>
 1ea:	ba ff ff ff ff       	mov    $0xffffffff,%edx
 1ef:	f0 0f c1 50 f8       	lock xadd %edx,-0x8(%rax)
 1f4:	89 d0                	mov    %edx,%eax
 1f6:	85 c0                	test   %eax,%eax
 1f8:	0f 8f 0f ff ff ff    	jg     10d <_Z5test2v+0x10d>
 1fe:	48 8d 74 24 0f       	lea    0xf(%rsp),%rsi
 203:	e8 00 00 00 00       	callq  208 <_Z5test2v+0x208>
 208:	e9 00 ff ff ff       	jmpq   10d <_Z5test2v+0x10d>
 20d:	8b 50 f8             	mov    -0x8(%rax),%edx
 210:	8d 4a ff             	lea    -0x1(%rdx),%ecx
 213:	89 48 f8             	mov    %ecx,-0x8(%rax)
 216:	89 d0                	mov    %edx,%eax
 218:	eb dc                	jmp    1f6 <_Z5test2v+0x1f6>
 21a:	48 8d 6c 24 40       	lea    0x40(%rsp),%rbp
 21f:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
 224:	48 89 ee             	mov    %rbp,%rsi
 227:	e8 00 00 00 00       	callq  22c <_Z5test2v+0x22c>
 22c:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
 231:	e8 00 00 00 00       	callq  236 <_Z5test2v+0x236>
 236:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
 23b:	48 89 c3             	mov    %rax,%rbx
 23e:	e8 00 00 00 00       	callq  243 <_Z5test2v+0x243>
 243:	e9 79 ff ff ff       	jmpq   1c1 <_Z5test2v+0x1c1>
 248:	48 89 c5             	mov    %rax,%rbp
 24b:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
 250:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
 254:	48 81 ff 00 00 00 00 	cmp    $0x0,%rdi
 25b:	74 0a                	je     267 <_Z5test2v+0x267>
 25d:	48 8d 74 24 0f       	lea    0xf(%rsp),%rsi
 262:	e8 00 00 00 00       	callq  267 <_Z5test2v+0x267>
 267:	48 89 df             	mov    %rbx,%rdi
 26a:	48 89 eb             	mov    %rbp,%rbx
 26d:	48 8d 6c 24 40       	lea    0x40(%rsp),%rbp
 272:	e8 00 00 00 00       	callq  277 <_Z5test2v+0x277>
 277:	e9 45 ff ff ff       	jmpq   1c1 <_Z5test2v+0x1c1>
 27c:	48 89 c5             	mov    %rax,%rbp
 27f:	eb e6                	jmp    267 <_Z5test2v+0x267>
 281:	48 89 ef             	mov    %rbp,%rdi
 284:	48 89 c3             	mov    %rax,%rbx
 287:	48 8d 6c 24 40       	lea    0x40(%rsp),%rbp
 28c:	e8 00 00 00 00       	callq  291 <_Z5test2v+0x291>
 291:	e9 2b ff ff ff       	jmpq   1c1 <_Z5test2v+0x1c1>
