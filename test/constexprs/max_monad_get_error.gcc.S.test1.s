   0:	55                   	push   %rbp
   1:	53                   	push   %rbx
   2:	48 83 ec 58          	sub    $0x58,%rsp
   6:	48 8d 7c 24 30       	lea    0x30(%rsp),%rdi
   b:	e8 00 00 00 00       	callq  10 <_Z5test1v+0x10>
  10:	0f b6 5c 24 40       	movzbl 0x40(%rsp),%ebx
  15:	84 db                	test   %bl,%bl
  17:	74 37                	je     50 <_Z5test1v+0x50>
  19:	80 fb 02             	cmp    $0x2,%bl
  1c:	74 22                	je     40 <_Z5test1v+0x40>
  1e:	e8 00 00 00 00       	callq  23 <_Z5test1v+0x23>
  23:	48 89 c2             	mov    %rax,%rdx
  26:	31 c0                	xor    %eax,%eax
  28:	80 fb 03             	cmp    $0x3,%bl
  2b:	0f 84 9f 00 00 00    	je     d0 <_Z5test1v+0xd0>
  31:	48 83 c4 58          	add    $0x58,%rsp
  35:	5b                   	pop    %rbx
  36:	5d                   	pop    %rbp
  37:	c3                   	retq   
  38:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
  3f:	00 
  40:	8b 44 24 30          	mov    0x30(%rsp),%eax
  44:	48 8b 54 24 38       	mov    0x38(%rsp),%rdx
  49:	48 83 c4 58          	add    $0x58,%rsp
  4d:	5b                   	pop    %rbx
  4e:	5d                   	pop    %rbp
  4f:	c3                   	retq   
  50:	bf 20 00 00 00       	mov    $0x20,%edi
  55:	e8 00 00 00 00       	callq  5a <_Z5test1v+0x5a>
  5a:	80 3d 00 00 00 00 00 	cmpb   $0x0,0x0(%rip)        # 61 <_Z5test1v+0x61>
  61:	48 89 c3             	mov    %rax,%rbx
  64:	0f 84 8e 00 00 00    	je     f8 <_Z5test1v+0xf8>
  6a:	48 8d 54 24 1f       	lea    0x1f(%rsp),%rdx
  6f:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
  74:	be 00 00 00 00       	mov    $0x0,%esi
  79:	e8 00 00 00 00       	callq  7e <_Z5test1v+0x7e>
  7e:	48 8d 74 24 20       	lea    0x20(%rsp),%rsi
  83:	48 89 df             	mov    %rbx,%rdi
  86:	e8 00 00 00 00       	callq  8b <_Z5test1v+0x8b>
  8b:	48 8b 44 24 20       	mov    0x20(%rsp),%rax
  90:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  94:	48 81 ff 00 00 00 00 	cmp    $0x0,%rdi
  9b:	0f 85 af 00 00 00    	jne    150 <_Z5test1v+0x150>
  a1:	48 c7 03 00 00 00 00 	movq   $0x0,(%rbx)
  a8:	c7 43 10 02 00 00 00 	movl   $0x2,0x10(%rbx)
  af:	ba 00 00 00 00       	mov    $0x0,%edx
  b4:	48 c7 43 18 00 00 00 	movq   $0x0,0x18(%rbx)
  bb:	00 
  bc:	be 00 00 00 00       	mov    $0x0,%esi
  c1:	48 89 df             	mov    %rbx,%rdi
  c4:	e8 00 00 00 00       	callq  c9 <_Z5test1v+0xc9>
  c9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
  d0:	48 8d 7c 24 30       	lea    0x30(%rsp),%rdi
  d5:	48 89 54 24 08       	mov    %rdx,0x8(%rsp)
  da:	48 89 04 24          	mov    %rax,(%rsp)
  de:	e8 00 00 00 00       	callq  e3 <_Z5test1v+0xe3>
  e3:	48 8b 04 24          	mov    (%rsp),%rax
  e7:	48 8b 54 24 08       	mov    0x8(%rsp),%rdx
  ec:	48 83 c4 58          	add    $0x58,%rsp
  f0:	5b                   	pop    %rbx
  f1:	5d                   	pop    %rbp
  f2:	c3                   	retq   
  f3:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
  f8:	bf 00 00 00 00       	mov    $0x0,%edi
  fd:	e8 00 00 00 00       	callq  102 <_Z5test1v+0x102>
 102:	85 c0                	test   %eax,%eax
 104:	0f 84 60 ff ff ff    	je     6a <_Z5test1v+0x6a>
 10a:	bf 00 00 00 00       	mov    $0x0,%edi
 10f:	e8 00 00 00 00       	callq  114 <_Z5test1v+0x114>
 114:	ba 00 00 00 00       	mov    $0x0,%edx
 119:	be 00 00 00 00       	mov    $0x0,%esi
 11e:	bf 00 00 00 00       	mov    $0x0,%edi
 123:	e8 00 00 00 00       	callq  128 <_Z5test1v+0x128>
 128:	e9 3d ff ff ff       	jmpq   6a <_Z5test1v+0x6a>
 12d:	48 89 c3             	mov    %rax,%rbx
 130:	80 7c 24 40 03       	cmpb   $0x3,0x40(%rsp)
 135:	75 0a                	jne    141 <_Z5test1v+0x141>
 137:	48 8d 7c 24 30       	lea    0x30(%rsp),%rdi
 13c:	e8 00 00 00 00       	callq  141 <_Z5test1v+0x141>
 141:	48 89 df             	mov    %rbx,%rdi
 144:	e8 00 00 00 00       	callq  149 <_Z5test1v+0x149>
 149:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
 150:	ba 00 00 00 00       	mov    $0x0,%edx
 155:	48 85 d2             	test   %rdx,%rdx
 158:	74 23                	je     17d <_Z5test1v+0x17d>
 15a:	ba ff ff ff ff       	mov    $0xffffffff,%edx
 15f:	f0 0f c1 50 f8       	lock xadd %edx,-0x8(%rax)
 164:	89 d0                	mov    %edx,%eax
 166:	85 c0                	test   %eax,%eax
 168:	0f 8f 33 ff ff ff    	jg     a1 <_Z5test1v+0xa1>
 16e:	48 8d 74 24 1f       	lea    0x1f(%rsp),%rsi
 173:	e8 00 00 00 00       	callq  178 <_Z5test1v+0x178>
 178:	e9 24 ff ff ff       	jmpq   a1 <_Z5test1v+0xa1>
 17d:	8b 50 f8             	mov    -0x8(%rax),%edx
 180:	8d 4a ff             	lea    -0x1(%rdx),%ecx
 183:	89 48 f8             	mov    %ecx,-0x8(%rax)
 186:	89 d0                	mov    %edx,%eax
 188:	eb dc                	jmp    166 <_Z5test1v+0x166>
 18a:	48 89 c5             	mov    %rax,%rbp
 18d:	48 89 df             	mov    %rbx,%rdi
 190:	48 89 eb             	mov    %rbp,%rbx
 193:	e8 00 00 00 00       	callq  198 <_Z5test1v+0x198>
 198:	eb 96                	jmp    130 <_Z5test1v+0x130>
 19a:	48 8b 4c 24 20       	mov    0x20(%rsp),%rcx
 19f:	48 89 c5             	mov    %rax,%rbp
 1a2:	48 8d 79 e8          	lea    -0x18(%rcx),%rdi
 1a6:	48 81 ff 00 00 00 00 	cmp    $0x0,%rdi
 1ad:	74 de                	je     18d <_Z5test1v+0x18d>
 1af:	ba 00 00 00 00       	mov    $0x0,%edx
 1b4:	48 8d 77 10          	lea    0x10(%rdi),%rsi
 1b8:	48 85 d2             	test   %rdx,%rdx
 1bb:	74 17                	je     1d4 <_Z5test1v+0x1d4>
 1bd:	83 ca ff             	or     $0xffffffff,%edx
 1c0:	f0 0f c1 16          	lock xadd %edx,(%rsi)
 1c4:	85 d2                	test   %edx,%edx
 1c6:	7f c5                	jg     18d <_Z5test1v+0x18d>
 1c8:	48 8d 74 24 1f       	lea    0x1f(%rsp),%rsi
 1cd:	e8 00 00 00 00       	callq  1d2 <_Z5test1v+0x1d2>
 1d2:	eb b9                	jmp    18d <_Z5test1v+0x18d>
 1d4:	8b 51 f8             	mov    -0x8(%rcx),%edx
 1d7:	8d 72 ff             	lea    -0x1(%rdx),%esi
 1da:	89 71 f8             	mov    %esi,-0x8(%rcx)
 1dd:	eb e5                	jmp    1c4 <_Z5test1v+0x1c4>
 1df:	90                   	nop
