  10:	53                   	push   %rbx
  11:	48 83 ec 40          	sub    $0x40,%rsp
  15:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
  1a:	e8 00 00 00 00       	callq  1f <_Z5test2v+0x1f>
  1f:	0f b6 5c 24 30       	movzbl 0x30(%rsp),%ebx
  24:	84 db                	test   %bl,%bl
  26:	0f 84 83 00 00 00    	je     af <_Z5test2v+0xaf>
  2c:	80 fb 02             	cmp    $0x2,%bl
  2f:	74 6f                	je     a0 <_Z5test2v+0xa0>
  31:	80 fb 03             	cmp    $0x3,%bl
  34:	74 1a                	je     50 <_Z5test2v+0x50>
  36:	e8 00 00 00 00       	callq  3b <_Z5test2v+0x3b>
  3b:	48 89 c2             	mov    %rax,%rdx
  3e:	31 c0                	xor    %eax,%eax
  40:	83 e0 03             	and    $0x3,%eax
  43:	80 fb 03             	cmp    $0x3,%bl
  46:	74 32                	je     7a <_Z5test2v+0x7a>
  48:	48 83 c4 40          	add    $0x40,%rsp
  4c:	5b                   	pop    %rbx
  4d:	c3                   	retq   
  4e:	66 90                	xchg   %ax,%ax
  50:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
  55:	48 c7 44 24 10 00 00 	movq   $0x0,0x10(%rsp)
  5c:	00 00 
  5e:	e8 00 00 00 00       	callq  63 <_Z5test2v+0x63>
  63:	0f b6 5c 24 30       	movzbl 0x30(%rsp),%ebx
  68:	b8 03 00 00 00       	mov    $0x3,%eax
  6d:	48 8d 54 24 10       	lea    0x10(%rsp),%rdx
  72:	83 e0 03             	and    $0x3,%eax
  75:	80 fb 03             	cmp    $0x3,%bl
  78:	75 ce                	jne    48 <_Z5test2v+0x48>
  7a:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
  7f:	48 89 54 24 08       	mov    %rdx,0x8(%rsp)
  84:	48 89 04 24          	mov    %rax,(%rsp)
  88:	e8 00 00 00 00       	callq  8d <_Z5test2v+0x8d>
  8d:	48 8b 04 24          	mov    (%rsp),%rax
  91:	48 8b 54 24 08       	mov    0x8(%rsp),%rdx
  96:	48 83 c4 40          	add    $0x40,%rsp
  9a:	5b                   	pop    %rbx
  9b:	c3                   	retq   
  9c:	0f 1f 40 00          	nopl   0x0(%rax)
  a0:	8b 44 24 20          	mov    0x20(%rsp),%eax
  a4:	48 8b 54 24 28       	mov    0x28(%rsp),%rdx
  a9:	48 83 c4 40          	add    $0x40,%rsp
  ad:	5b                   	pop    %rbx
  ae:	c3                   	retq   
  af:	bf 02 00 00 00       	mov    $0x2,%edi
  b4:	e8 00 00 00 00       	callq  b9 <_Z5test2v+0xb9>
  b9:	80 7c 24 30 03       	cmpb   $0x3,0x30(%rsp)
  be:	48 89 c3             	mov    %rax,%rbx
  c1:	75 0a                	jne    cd <_Z5test2v+0xcd>
  c3:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
  c8:	e8 00 00 00 00       	callq  cd <_Z5test2v+0xcd>
  cd:	48 89 df             	mov    %rbx,%rdi
  d0:	e8 00 00 00 00       	callq  d5 <_Z5test2v+0xd5>
