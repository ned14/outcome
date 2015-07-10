  10:	41 55                	push   %r13
  12:	41 54                	push   %r12
  14:	55                   	push   %rbp
  15:	53                   	push   %rbx
  16:	48 89 fb             	mov    %rdi,%rbx
  19:	48 83 ec 68          	sub    $0x68,%rsp
  1d:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
  22:	e8 00 00 00 00       	callq  27 <_Z5test2v+0x27>
  27:	0f b6 44 24 30       	movzbl 0x30(%rsp),%eax
  2c:	84 c0                	test   %al,%al
  2e:	0f 84 f5 01 00 00    	je     229 <_Z5test2v+0x229>
  34:	3c 02                	cmp    $0x2,%al
  36:	74 58                	je     90 <_Z5test2v+0x90>
  38:	3c 03                	cmp    $0x3,%al
  3a:	74 24                	je     60 <_Z5test2v+0x60>
  3c:	48 89 df             	mov    %rbx,%rdi
  3f:	e8 00 00 00 00       	callq  44 <_Z5test2v+0x44>
  44:	80 7c 24 30 03       	cmpb   $0x3,0x30(%rsp)
  49:	74 29                	je     74 <_Z5test2v+0x74>
  4b:	48 83 c4 68          	add    $0x68,%rsp
  4f:	48 89 d8             	mov    %rbx,%rax
  52:	5b                   	pop    %rbx
  53:	5d                   	pop    %rbp
  54:	41 5c                	pop    %r12
  56:	41 5d                	pop    %r13
  58:	c3                   	retq   
  59:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
  60:	48 8d 74 24 20       	lea    0x20(%rsp),%rsi
  65:	48 89 df             	mov    %rbx,%rdi
  68:	e8 00 00 00 00       	callq  6d <_Z5test2v+0x6d>
  6d:	80 7c 24 30 03       	cmpb   $0x3,0x30(%rsp)
  72:	75 d7                	jne    4b <_Z5test2v+0x4b>
  74:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
  79:	e8 00 00 00 00       	callq  7e <_Z5test2v+0x7e>
  7e:	48 83 c4 68          	add    $0x68,%rsp
  82:	48 89 d8             	mov    %rbx,%rax
  85:	5b                   	pop    %rbx
  86:	5d                   	pop    %rbp
  87:	41 5c                	pop    %r12
  89:	41 5d                	pop    %r13
  8b:	c3                   	retq   
  8c:	0f 1f 40 00          	nopl   0x0(%rax)
  90:	4c 8b 64 24 28       	mov    0x28(%rsp),%r12
  95:	8b 6c 24 20          	mov    0x20(%rsp),%ebp
  99:	4c 8d 6c 24 10       	lea    0x10(%rsp),%r13
  9e:	49 8b 04 24          	mov    (%r12),%rax
  a2:	48 8b 40 18          	mov    0x18(%rax),%rax
  a6:	48 3d 00 00 00 00    	cmp    $0x0,%rax
  ac:	0f 85 2e 01 00 00    	jne    1e0 <_Z5test2v+0x1e0>
  b2:	83 fd 02             	cmp    $0x2,%ebp
  b5:	0f 84 d5 00 00 00    	je     190 <_Z5test2v+0x190>
  bb:	83 fd 03             	cmp    $0x3,%ebp
  be:	0f 84 ec 00 00 00    	je     1b0 <_Z5test2v+0x1b0>
  c4:	83 fd 01             	cmp    $0x1,%ebp
  c7:	0f 84 fa 00 00 00    	je     1c7 <_Z5test2v+0x1c7>
  cd:	48 8d 54 24 0f       	lea    0xf(%rsp),%rdx
  d2:	be 00 00 00 00       	mov    $0x0,%esi
  d7:	4c 89 ef             	mov    %r13,%rdi
  da:	e8 00 00 00 00       	callq  df <_Z5test2v+0xdf>
  df:	48 8d 7c 24 40       	lea    0x40(%rsp),%rdi
  e4:	4c 89 ee             	mov    %r13,%rsi
  e7:	e8 00 00 00 00       	callq  ec <_Z5test2v+0xec>
  ec:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  f1:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  f5:	48 81 ff 00 00 00 00 	cmp    $0x0,%rdi
  fc:	0f 85 ed 00 00 00    	jne    1ef <_Z5test2v+0x1ef>
 102:	bf 20 00 00 00       	mov    $0x20,%edi
 107:	89 6c 24 50          	mov    %ebp,0x50(%rsp)
 10b:	48 c7 44 24 40 00 00 	movq   $0x0,0x40(%rsp)
 112:	00 00 
 114:	4c 89 64 24 58       	mov    %r12,0x58(%rsp)
 119:	e8 00 00 00 00       	callq  11e <_Z5test2v+0x11e>
 11e:	48 89 c5             	mov    %rax,%rbp
 121:	48 c7 00 00 00 00 00 	movq   $0x0,(%rax)
 128:	48 8d 44 24 40       	lea    0x40(%rsp),%rax
 12d:	48 8d 7d 08          	lea    0x8(%rbp),%rdi
 131:	48 8d 70 08          	lea    0x8(%rax),%rsi
 135:	e8 00 00 00 00       	callq  13a <_Z5test2v+0x13a>
 13a:	48 8b 54 24 58       	mov    0x58(%rsp),%rdx
 13f:	48 8b 44 24 50       	mov    0x50(%rsp),%rax
 144:	be 00 00 00 00       	mov    $0x0,%esi
 149:	48 c7 45 00 00 00 00 	movq   $0x0,0x0(%rbp)
 150:	00 
 151:	48 89 ef             	mov    %rbp,%rdi
 154:	48 89 55 18          	mov    %rdx,0x18(%rbp)
 158:	48 89 45 10          	mov    %rax,0x10(%rbp)
 15c:	ba 00 00 00 00       	mov    $0x0,%edx
 161:	e8 00 00 00 00       	callq  166 <_Z5test2v+0x166>
 166:	48 89 c7             	mov    %rax,%rdi
 169:	e8 00 00 00 00       	callq  16e <_Z5test2v+0x16e>
 16e:	48 89 df             	mov    %rbx,%rdi
 171:	e8 00 00 00 00       	callq  176 <_Z5test2v+0x176>
 176:	e8 00 00 00 00       	callq  17b <_Z5test2v+0x17b>
 17b:	48 8d 7c 24 40       	lea    0x40(%rsp),%rdi
 180:	e8 00 00 00 00       	callq  185 <_Z5test2v+0x185>
 185:	e9 ba fe ff ff       	jmpq   44 <_Z5test2v+0x44>
 18a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
 190:	48 8d 54 24 0d       	lea    0xd(%rsp),%rdx
 195:	be 00 00 00 00       	mov    $0x0,%esi
 19a:	4c 89 ef             	mov    %r13,%rdi
 19d:	e8 00 00 00 00       	callq  1a2 <_Z5test2v+0x1a2>
 1a2:	e9 38 ff ff ff       	jmpq   df <_Z5test2v+0xdf>
 1a7:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
 1ae:	00 00 
 1b0:	48 8d 54 24 0e       	lea    0xe(%rsp),%rdx
 1b5:	be 00 00 00 00       	mov    $0x0,%esi
 1ba:	4c 89 ef             	mov    %r13,%rdi
 1bd:	e8 00 00 00 00       	callq  1c2 <_Z5test2v+0x1c2>
 1c2:	e9 18 ff ff ff       	jmpq   df <_Z5test2v+0xdf>
 1c7:	48 8d 54 24 0c       	lea    0xc(%rsp),%rdx
 1cc:	be 00 00 00 00       	mov    $0x0,%esi
 1d1:	4c 89 ef             	mov    %r13,%rdi
 1d4:	e8 00 00 00 00       	callq  1d9 <_Z5test2v+0x1d9>
 1d9:	e9 01 ff ff ff       	jmpq   df <_Z5test2v+0xdf>
 1de:	66 90                	xchg   %ax,%ax
 1e0:	89 ea                	mov    %ebp,%edx
 1e2:	4c 89 e6             	mov    %r12,%rsi
 1e5:	4c 89 ef             	mov    %r13,%rdi
 1e8:	ff d0                	callq  *%rax
 1ea:	e9 f0 fe ff ff       	jmpq   df <_Z5test2v+0xdf>
 1ef:	ba 00 00 00 00       	mov    $0x0,%edx
 1f4:	48 85 d2             	test   %rdx,%rdx
 1f7:	74 23                	je     21c <_Z5test2v+0x21c>
 1f9:	ba ff ff ff ff       	mov    $0xffffffff,%edx
 1fe:	f0 0f c1 50 f8       	lock xadd %edx,-0x8(%rax)
 203:	89 d0                	mov    %edx,%eax
 205:	85 c0                	test   %eax,%eax
 207:	0f 8f f5 fe ff ff    	jg     102 <_Z5test2v+0x102>
 20d:	48 8d 74 24 0f       	lea    0xf(%rsp),%rsi
 212:	e8 00 00 00 00       	callq  217 <_Z5test2v+0x217>
 217:	e9 e6 fe ff ff       	jmpq   102 <_Z5test2v+0x102>
 21c:	8b 50 f8             	mov    -0x8(%rax),%edx
 21f:	8d 4a ff             	lea    -0x1(%rdx),%ecx
 222:	89 48 f8             	mov    %ecx,-0x8(%rax)
 225:	89 d0                	mov    %edx,%eax
 227:	eb dc                	jmp    205 <_Z5test2v+0x205>
 229:	bf 02 00 00 00       	mov    $0x2,%edi
 22e:	e8 00 00 00 00       	callq  233 <_Z5test2v+0x233>
 233:	48 89 c3             	mov    %rax,%rbx
 236:	80 7c 24 30 03       	cmpb   $0x3,0x30(%rsp)
 23b:	75 0a                	jne    247 <_Z5test2v+0x247>
 23d:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
 242:	e8 00 00 00 00       	callq  247 <_Z5test2v+0x247>
 247:	48 89 df             	mov    %rbx,%rdi
 24a:	e8 00 00 00 00       	callq  24f <_Z5test2v+0x24f>
 24f:	48 89 ef             	mov    %rbp,%rdi
 252:	49 89 c4             	mov    %rax,%r12
 255:	e8 00 00 00 00       	callq  25a <_Z5test2v+0x25a>
 25a:	48 89 ef             	mov    %rbp,%rdi
 25d:	e8 00 00 00 00       	callq  262 <_Z5test2v+0x262>
 262:	4c 89 e0             	mov    %r12,%rax
 265:	e9 fc fe ff ff       	jmpq   166 <_Z5test2v+0x166>
 26a:	48 89 c3             	mov    %rax,%rbx
 26d:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
 272:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
 276:	48 81 ff 00 00 00 00 	cmp    $0x0,%rdi
 27d:	74 b7                	je     236 <_Z5test2v+0x236>
 27f:	48 8d 74 24 0f       	lea    0xf(%rsp),%rsi
 284:	e8 00 00 00 00       	callq  289 <_Z5test2v+0x289>
 289:	eb ab                	jmp    236 <_Z5test2v+0x236>
