   0:	53                   	push   %rbx
   1:	48 83 ec 40          	sub    $0x40,%rsp
   5:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
   a:	e8 00 00 00 00       	callq  f <_Z5test1v+0xf>
   f:	0f b6 5c 24 30       	movzbl 0x30(%rsp),%ebx
  14:	84 db                	test   %bl,%bl
  16:	0f 84 83 00 00 00    	je     9f <_Z5test1v+0x9f>
  1c:	80 fb 02             	cmp    $0x2,%bl
  1f:	74 6f                	je     90 <_Z5test1v+0x90>
  21:	80 fb 03             	cmp    $0x3,%bl
  24:	74 1a                	je     40 <_Z5test1v+0x40>
  26:	e8 00 00 00 00       	callq  2b <_Z5test1v+0x2b>
  2b:	48 89 c2             	mov    %rax,%rdx
  2e:	31 c0                	xor    %eax,%eax
  30:	83 e0 03             	and    $0x3,%eax
  33:	80 fb 03             	cmp    $0x3,%bl
  36:	74 32                	je     6a <_Z5test1v+0x6a>
  38:	48 83 c4 40          	add    $0x40,%rsp
  3c:	5b                   	pop    %rbx
  3d:	c3                   	retq   
  3e:	66 90                	xchg   %ax,%ax
  40:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
  45:	48 c7 44 24 10 00 00 	movq   $0x0,0x10(%rsp)
  4c:	00 00 
  4e:	e8 00 00 00 00       	callq  53 <_Z5test1v+0x53>
  53:	0f b6 5c 24 30       	movzbl 0x30(%rsp),%ebx
  58:	b8 03 00 00 00       	mov    $0x3,%eax
  5d:	48 8d 54 24 10       	lea    0x10(%rsp),%rdx
  62:	83 e0 03             	and    $0x3,%eax
  65:	80 fb 03             	cmp    $0x3,%bl
  68:	75 ce                	jne    38 <_Z5test1v+0x38>
  6a:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
  6f:	48 89 54 24 08       	mov    %rdx,0x8(%rsp)
  74:	48 89 04 24          	mov    %rax,(%rsp)
  78:	e8 00 00 00 00       	callq  7d <_Z5test1v+0x7d>
  7d:	48 8b 04 24          	mov    (%rsp),%rax
  81:	48 8b 54 24 08       	mov    0x8(%rsp),%rdx
  86:	48 83 c4 40          	add    $0x40,%rsp
  8a:	5b                   	pop    %rbx
  8b:	c3                   	retq   
  8c:	0f 1f 40 00          	nopl   0x0(%rax)
  90:	8b 44 24 20          	mov    0x20(%rsp),%eax
  94:	48 8b 54 24 28       	mov    0x28(%rsp),%rdx
  99:	48 83 c4 40          	add    $0x40,%rsp
  9d:	5b                   	pop    %rbx
  9e:	c3                   	retq   
  9f:	bf 02 00 00 00       	mov    $0x2,%edi
  a4:	e8 00 00 00 00       	callq  a9 <_Z5test1v+0xa9>
  a9:	80 7c 24 30 03       	cmpb   $0x3,0x30(%rsp)
  ae:	48 89 c3             	mov    %rax,%rbx
  b1:	75 0a                	jne    bd <_Z5test1v+0xbd>
  b3:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
  b8:	e8 00 00 00 00       	callq  bd <_Z5test1v+0xbd>
  bd:	48 89 df             	mov    %rbx,%rdi
  c0:	e8 00 00 00 00       	callq  c5 <_Z5test1v+0xc5>
  c5:	66 66 2e 0f 1f 84 00 	data32 nopw %cs:0x0(%rax,%rax,1)
  cc:	00 00 00 00 
