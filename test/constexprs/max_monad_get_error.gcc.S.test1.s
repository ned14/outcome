  10:	53                   	push   %rbx
  11:	48 83 ec 30          	sub    $0x30,%rsp
  15:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
  1a:	e8 00 00 00 00       	callq  1f <_Z5test1v+0xf>
  1f:	0f b6 5c 24 28       	movzbl 0x28(%rsp),%ebx
  24:	84 db                	test   %bl,%bl
  26:	0f 84 b4 00 00 00    	je     e0 <_Z5test1v+0xd0>
  2c:	80 fb 02             	cmp    $0x2,%bl
  2f:	74 57                	je     88 <_Z5test1v+0x78>
  31:	80 fb 03             	cmp    $0x3,%bl
  34:	74 1a                	je     50 <_Z5test1v+0x40>
  36:	e8 00 00 00 00       	callq  3b <_Z5test1v+0x2b>
  3b:	48 89 c2             	mov    %rax,%rdx
  3e:	31 c0                	xor    %eax,%eax
  40:	83 e0 03             	and    $0x3,%eax
  43:	80 fb 03             	cmp    $0x3,%bl
  46:	74 1b                	je     63 <_Z5test1v+0x53>
  48:	48 83 c4 30          	add    $0x30,%rsp
  4c:	5b                   	pop    %rbx
  4d:	c3                   	retq   
  4e:	66 90                	xchg   %ax,%ax
  50:	80 3d 00 00 00 00 00 	cmpb   $0x0,0x0(%rip)        # 57 <_Z5test1v+0x47>
  57:	74 47                	je     a0 <_Z5test1v+0x90>
  59:	b8 03 00 00 00       	mov    $0x3,%eax
  5e:	ba 00 00 00 00       	mov    $0x0,%edx
  63:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
  68:	48 89 54 24 08       	mov    %rdx,0x8(%rsp)
  6d:	48 89 04 24          	mov    %rax,(%rsp)
  71:	e8 00 00 00 00       	callq  76 <_Z5test1v+0x66>
  76:	48 8b 04 24          	mov    (%rsp),%rax
  7a:	48 8b 54 24 08       	mov    0x8(%rsp),%rdx
  7f:	48 83 c4 30          	add    $0x30,%rsp
  83:	5b                   	pop    %rbx
  84:	c3                   	retq   
  85:	0f 1f 00             	nopl   (%rax)
  88:	8b 44 24 10          	mov    0x10(%rsp),%eax
  8c:	48 8b 54 24 18       	mov    0x18(%rsp),%rdx
  91:	48 83 c4 30          	add    $0x30,%rsp
  95:	5b                   	pop    %rbx
  96:	c3                   	retq   
  97:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  9e:	00 00 
  a0:	bf 00 00 00 00       	mov    $0x0,%edi
  a5:	e8 00 00 00 00       	callq  aa <_Z5test1v+0x9a>
  aa:	85 c0                	test   %eax,%eax
  ac:	74 1e                	je     cc <_Z5test1v+0xbc>
  ae:	bf 00 00 00 00       	mov    $0x0,%edi
  b3:	e8 00 00 00 00       	callq  b8 <_Z5test1v+0xa8>
  b8:	ba 00 00 00 00       	mov    $0x0,%edx
  bd:	be 00 00 00 00       	mov    $0x0,%esi
  c2:	bf 00 00 00 00       	mov    $0x0,%edi
  c7:	e8 00 00 00 00       	callq  cc <_Z5test1v+0xbc>
  cc:	0f b6 5c 24 28       	movzbl 0x28(%rsp),%ebx
  d1:	ba 00 00 00 00       	mov    $0x0,%edx
  d6:	b8 03 00 00 00       	mov    $0x3,%eax
  db:	e9 60 ff ff ff       	jmpq   40 <_Z5test1v+0x30>
  e0:	bf 02 00 00 00       	mov    $0x2,%edi
  e5:	e8 00 00 00 00       	callq  ea <_Z5test1v+0xda>
  ea:	80 7c 24 28 03       	cmpb   $0x3,0x28(%rsp)
  ef:	48 89 c3             	mov    %rax,%rbx
  f2:	75 0a                	jne    fe <_Z5test1v+0xee>
  f4:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
  f9:	e8 00 00 00 00       	callq  fe <_Z5test1v+0xee>
  fe:	48 89 df             	mov    %rbx,%rdi
 101:	e8 00 00 00 00       	callq  106 <_Z5test1v+0xf6>
