   2:	53                   	push   %rbx
   3:	48 83 ec 30          	sub    $0x30,%rsp
   7:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
   c:	e8 00 00 00 00       	callq  11 <_Z5test2v+0x11>
  11:	0f b6 5c 24 20       	movzbl 0x20(%rsp),%ebx
  16:	84 db                	test   %bl,%bl
  18:	74 58                	je     72 <_Z5test2v+0x72>
  1a:	80 fb 02             	cmp    $0x2,%bl
  1d:	74 19                	je     38 <_Z5test2v+0x38>
  1f:	e8 00 00 00 00       	callq  24 <_Z5test2v+0x24>
  24:	48 89 c2             	mov    %rax,%rdx
  27:	31 c0                	xor    %eax,%eax
  29:	80 fb 03             	cmp    $0x3,%bl
  2c:	74 22                	je     50 <_Z5test2v+0x50>
  2e:	48 83 c4 30          	add    $0x30,%rsp
  32:	5b                   	pop    %rbx
  33:	c3                   	retq   
  34:	0f 1f 40 00          	nopl   0x0(%rax)
  38:	8b 44 24 10          	mov    0x10(%rsp),%eax
  3c:	48 8b 54 24 18       	mov    0x18(%rsp),%rdx
  41:	48 83 c4 30          	add    $0x30,%rsp
  45:	5b                   	pop    %rbx
  46:	c3                   	retq   
  47:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  4e:	00 00 
  50:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
  55:	48 89 54 24 08       	mov    %rdx,0x8(%rsp)
  5a:	48 89 04 24          	mov    %rax,(%rsp)
  5e:	e8 00 00 00 00       	callq  63 <_Z5test2v+0x63>
  63:	48 8b 04 24          	mov    (%rsp),%rax
  67:	48 8b 54 24 08       	mov    0x8(%rsp),%rdx
  6c:	48 83 c4 30          	add    $0x30,%rsp
  70:	5b                   	pop    %rbx
  71:	c3                   	retq   
  72:	bf 02 00 00 00       	mov    $0x2,%edi
  77:	e8 00 00 00 00       	callq  7c <_Z5test2v+0x7c>
  7c:	80 7c 24 20 03       	cmpb   $0x3,0x20(%rsp)
  81:	48 89 c3             	mov    %rax,%rbx
  84:	75 0a                	jne    90 <_Z5test2v+0x90>
  86:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
  8b:	e8 00 00 00 00       	callq  90 <_Z5test2v+0x90>
  90:	48 89 df             	mov    %rbx,%rdi
  93:	e8 00 00 00 00       	callq  98 <_Z5test2v+0x98>
