   0:	55                   	push   %rbp
   1:	53                   	push   %rbx
   2:	48 83 ec 48          	sub    $0x48,%rsp
   6:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
   b:	e8 00 00 00 00       	callq  10 <_Z5test1v+0x10>
  10:	0f b6 44 24 30       	movzbl 0x30(%rsp),%eax
  15:	84 c0                	test   %al,%al
  17:	74 1f                	je     38 <_Z5test1v+0x38>
  19:	3c 02                	cmp    $0x2,%al
  1b:	0f 84 41 01 00 00    	je     162 <_Z5test1v+0x162>
  21:	3c 03                	cmp    $0x3,%al
  23:	0f 84 d4 00 00 00    	je     fd <_Z5test1v+0xfd>
  29:	8b 44 24 20          	mov    0x20(%rsp),%eax
  2d:	48 83 c4 48          	add    $0x48,%rsp
  31:	5b                   	pop    %rbx
  32:	5d                   	pop    %rbp
  33:	c3                   	retq   
  34:	0f 1f 40 00          	nopl   0x0(%rax)
  38:	bf 20 00 00 00       	mov    $0x20,%edi
  3d:	e8 00 00 00 00       	callq  42 <_Z5test1v+0x42>
  42:	80 3d 00 00 00 00 00 	cmpb   $0x0,0x0(%rip)        # 49 <_Z5test1v+0x49>
  49:	48 89 c3             	mov    %rax,%rbx
  4c:	74 62                	je     b0 <_Z5test1v+0xb0>
  4e:	48 8d 54 24 0f       	lea    0xf(%rsp),%rdx
  53:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
  58:	be 00 00 00 00       	mov    $0x0,%esi
  5d:	e8 00 00 00 00       	callq  62 <_Z5test1v+0x62>
  62:	48 8d 74 24 10       	lea    0x10(%rsp),%rsi
  67:	48 89 df             	mov    %rbx,%rdi
  6a:	e8 00 00 00 00       	callq  6f <_Z5test1v+0x6f>
  6f:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  74:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  78:	48 81 ff 00 00 00 00 	cmp    $0x0,%rdi
  7f:	0f 85 a3 00 00 00    	jne    128 <_Z5test1v+0x128>
  85:	48 c7 03 00 00 00 00 	movq   $0x0,(%rbx)
  8c:	c7 43 10 02 00 00 00 	movl   $0x2,0x10(%rbx)
  93:	ba 00 00 00 00       	mov    $0x0,%edx
  98:	48 c7 43 18 00 00 00 	movq   $0x0,0x18(%rbx)
  9f:	00 
  a0:	be 00 00 00 00       	mov    $0x0,%esi
  a5:	48 89 df             	mov    %rbx,%rdi
  a8:	e8 00 00 00 00       	callq  ad <_Z5test1v+0xad>
  ad:	0f 1f 00             	nopl   (%rax)
  b0:	bf 00 00 00 00       	mov    $0x0,%edi
  b5:	e8 00 00 00 00       	callq  ba <_Z5test1v+0xba>
  ba:	85 c0                	test   %eax,%eax
  bc:	74 90                	je     4e <_Z5test1v+0x4e>
  be:	bf 00 00 00 00       	mov    $0x0,%edi
  c3:	e8 00 00 00 00       	callq  c8 <_Z5test1v+0xc8>
  c8:	ba 00 00 00 00       	mov    $0x0,%edx
  cd:	be 00 00 00 00       	mov    $0x0,%esi
  d2:	bf 00 00 00 00       	mov    $0x0,%edi
  d7:	e8 00 00 00 00       	callq  dc <_Z5test1v+0xdc>
  dc:	e9 6d ff ff ff       	jmpq   4e <_Z5test1v+0x4e>
  e1:	48 89 c3             	mov    %rax,%rbx
  e4:	80 7c 24 30 03       	cmpb   $0x3,0x30(%rsp)
  e9:	75 0a                	jne    f5 <_Z5test1v+0xf5>
  eb:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
  f0:	e8 00 00 00 00       	callq  f5 <_Z5test1v+0xf5>
  f5:	48 89 df             	mov    %rbx,%rdi
  f8:	e8 00 00 00 00       	callq  fd <_Z5test1v+0xfd>
  fd:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
 102:	48 8d 74 24 20       	lea    0x20(%rsp),%rsi
 107:	e8 00 00 00 00       	callq  10c <_Z5test1v+0x10c>
 10c:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
 111:	e8 00 00 00 00       	callq  116 <_Z5test1v+0x116>
 116:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
 11b:	48 89 c3             	mov    %rax,%rbx
 11e:	e8 00 00 00 00       	callq  123 <_Z5test1v+0x123>
 123:	eb bf                	jmp    e4 <_Z5test1v+0xe4>
 125:	0f 1f 00             	nopl   (%rax)
 128:	ba 00 00 00 00       	mov    $0x0,%edx
 12d:	48 85 d2             	test   %rdx,%rdx
 130:	74 23                	je     155 <_Z5test1v+0x155>
 132:	ba ff ff ff ff       	mov    $0xffffffff,%edx
 137:	f0 0f c1 50 f8       	lock xadd %edx,-0x8(%rax)
 13c:	89 d0                	mov    %edx,%eax
 13e:	85 c0                	test   %eax,%eax
 140:	0f 8f 3f ff ff ff    	jg     85 <_Z5test1v+0x85>
 146:	48 8d 74 24 0f       	lea    0xf(%rsp),%rsi
 14b:	e8 00 00 00 00       	callq  150 <_Z5test1v+0x150>
 150:	e9 30 ff ff ff       	jmpq   85 <_Z5test1v+0x85>
 155:	8b 50 f8             	mov    -0x8(%rax),%edx
 158:	8d 4a ff             	lea    -0x1(%rdx),%ecx
 15b:	89 48 f8             	mov    %ecx,-0x8(%rax)
 15e:	89 d0                	mov    %edx,%eax
 160:	eb dc                	jmp    13e <_Z5test1v+0x13e>
 162:	bf 20 00 00 00       	mov    $0x20,%edi
 167:	e8 00 00 00 00       	callq  16c <_Z5test1v+0x16c>
 16c:	8b 74 24 20          	mov    0x20(%rsp),%esi
 170:	48 8b 54 24 28       	mov    0x28(%rsp),%rdx
 175:	48 89 c7             	mov    %rax,%rdi
 178:	48 89 c5             	mov    %rax,%rbp
 17b:	e8 00 00 00 00       	callq  180 <_Z5test1v+0x180>
 180:	ba 00 00 00 00       	mov    $0x0,%edx
 185:	be 00 00 00 00       	mov    $0x0,%esi
 18a:	48 89 ef             	mov    %rbp,%rdi
 18d:	e8 00 00 00 00       	callq  192 <_Z5test1v+0x192>
 192:	48 89 c5             	mov    %rax,%rbp
 195:	48 89 df             	mov    %rbx,%rdi
 198:	48 89 eb             	mov    %rbp,%rbx
 19b:	e8 00 00 00 00       	callq  1a0 <_Z5test1v+0x1a0>
 1a0:	e9 3f ff ff ff       	jmpq   e4 <_Z5test1v+0xe4>
 1a5:	48 89 c5             	mov    %rax,%rbp
 1a8:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
 1ad:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
 1b1:	48 81 ff 00 00 00 00 	cmp    $0x0,%rdi
 1b8:	74 db                	je     195 <_Z5test1v+0x195>
 1ba:	48 8d 74 24 0f       	lea    0xf(%rsp),%rsi
 1bf:	e8 00 00 00 00       	callq  1c4 <_Z5test1v+0x1c4>
 1c4:	eb cf                	jmp    195 <_Z5test1v+0x195>
 1c6:	48 89 ef             	mov    %rbp,%rdi
 1c9:	48 89 c3             	mov    %rax,%rbx
 1cc:	e8 00 00 00 00       	callq  1d1 <_Z5test1v+0x1d1>
 1d1:	e9 0e ff ff ff       	jmpq   e4 <_Z5test1v+0xe4>
 1d6:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
 1dd:	00 00 00 
