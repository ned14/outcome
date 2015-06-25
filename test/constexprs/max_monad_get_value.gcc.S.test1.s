   2:	55                   	push   %rbp
   3:	53                   	push   %rbx
   4:	48 83 ec 38          	sub    $0x38,%rsp
   8:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
   d:	e8 00 00 00 00       	callq  12 <_Z5test2v+0x12>
  12:	0f b6 44 24 20       	movzbl 0x20(%rsp),%eax
  17:	84 c0                	test   %al,%al
  19:	74 13                	je     2e <_Z5test2v+0x2e>
  1b:	3c 02                	cmp    $0x2,%al
  1d:	74 57                	je     76 <_Z5test2v+0x76>
  1f:	3c 03                	cmp    $0x3,%al
  21:	74 31                	je     54 <_Z5test2v+0x54>
  23:	8b 44 24 10          	mov    0x10(%rsp),%eax
  27:	48 83 c4 38          	add    $0x38,%rsp
  2b:	5b                   	pop    %rbx
  2c:	5d                   	pop    %rbp
  2d:	c3                   	retq   
  2e:	bf 02 00 00 00       	mov    $0x2,%edi
  33:	e8 00 00 00 00       	callq  38 <_Z5test2v+0x38>
  38:	48 89 c3             	mov    %rax,%rbx
  3b:	80 7c 24 20 03       	cmpb   $0x3,0x20(%rsp)
  40:	75 0a                	jne    4c <_Z5test2v+0x4c>
  42:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
  47:	e8 00 00 00 00       	callq  4c <_Z5test2v+0x4c>
  4c:	48 89 df             	mov    %rbx,%rdi
  4f:	e8 00 00 00 00       	callq  54 <_Z5test2v+0x54>
  54:	48 8d 74 24 10       	lea    0x10(%rsp),%rsi
  59:	48 89 e7             	mov    %rsp,%rdi
  5c:	e8 00 00 00 00       	callq  61 <_Z5test2v+0x61>
  61:	48 89 e7             	mov    %rsp,%rdi
  64:	e8 00 00 00 00       	callq  69 <_Z5test2v+0x69>
  69:	48 89 e7             	mov    %rsp,%rdi
  6c:	48 89 c3             	mov    %rax,%rbx
  6f:	e8 00 00 00 00       	callq  74 <_Z5test2v+0x74>
  74:	eb c5                	jmp    3b <_Z5test2v+0x3b>
  76:	bf 20 00 00 00       	mov    $0x20,%edi
  7b:	e8 00 00 00 00       	callq  80 <_Z5test2v+0x80>
  80:	8b 74 24 10          	mov    0x10(%rsp),%esi
  84:	48 8b 54 24 18       	mov    0x18(%rsp),%rdx
  89:	48 89 c7             	mov    %rax,%rdi
  8c:	48 89 c3             	mov    %rax,%rbx
  8f:	e8 00 00 00 00       	callq  94 <_Z5test2v+0x94>
  94:	ba 00 00 00 00       	mov    $0x0,%edx
  99:	be 00 00 00 00       	mov    $0x0,%esi
  9e:	48 89 df             	mov    %rbx,%rdi
  a1:	e8 00 00 00 00       	callq  a6 <_Z5test2v+0xa6>
  a6:	48 89 c5             	mov    %rax,%rbp
  a9:	48 89 df             	mov    %rbx,%rdi
  ac:	e8 00 00 00 00       	callq  b1 <_Z5test2v+0xb1>
  b1:	48 89 eb             	mov    %rbp,%rbx
  b4:	eb 85                	jmp    3b <_Z5test2v+0x3b>
