   0:	53                   	push   %rbx
   1:	48 89 fb             	mov    %rdi,%rbx
   4:	48 83 ec 20          	sub    $0x20,%rsp
   8:	48 89 e7             	mov    %rsp,%rdi
   b:	e8 00 00 00 00       	callq  10 <_Z5test1v+0x10>
  10:	0f b6 44 24 18       	movzbl 0x18(%rsp),%eax
  15:	3c 01                	cmp    $0x1,%al
  17:	74 3f                	je     58 <_Z5test1v+0x58>
  19:	3c 02                	cmp    $0x2,%al
  1b:	74 53                	je     70 <_Z5test1v+0x70>
  1d:	3c 03                	cmp    $0x3,%al
  1f:	74 0f                	je     30 <_Z5test1v+0x30>
  21:	c6 43 18 00          	movb   $0x0,0x18(%rbx)
  25:	48 83 c4 20          	add    $0x20,%rsp
  29:	48 89 d8             	mov    %rbx,%rax
  2c:	5b                   	pop    %rbx
  2d:	c3                   	retq   
  2e:	66 90                	xchg   %ax,%ax
  30:	48 8b 04 24          	mov    (%rsp),%rax
  34:	c6 43 18 03          	movb   $0x3,0x18(%rbx)
  38:	48 89 e7             	mov    %rsp,%rdi
  3b:	48 c7 04 24 00 00 00 	movq   $0x0,(%rsp)
  42:	00 
  43:	48 89 03             	mov    %rax,(%rbx)
  46:	e8 00 00 00 00       	callq  4b <_Z5test1v+0x4b>
  4b:	48 83 c4 20          	add    $0x20,%rsp
  4f:	48 89 d8             	mov    %rbx,%rax
  52:	5b                   	pop    %rbx
  53:	c3                   	retq   
  54:	0f 1f 40 00          	nopl   0x0(%rax)
  58:	8b 04 24             	mov    (%rsp),%eax
  5b:	c6 43 18 01          	movb   $0x1,0x18(%rbx)
  5f:	8d 04 40             	lea    (%rax,%rax,2),%eax
  62:	89 03                	mov    %eax,(%rbx)
  64:	48 83 c4 20          	add    $0x20,%rsp
  68:	48 89 d8             	mov    %rbx,%rax
  6b:	5b                   	pop    %rbx
  6c:	c3                   	retq   
  6d:	0f 1f 00             	nopl   (%rax)
  70:	48 8b 04 24          	mov    (%rsp),%rax
  74:	c6 43 18 02          	movb   $0x2,0x18(%rbx)
  78:	48 89 03             	mov    %rax,(%rbx)
  7b:	48 8b 44 24 08       	mov    0x8(%rsp),%rax
  80:	48 89 43 08          	mov    %rax,0x8(%rbx)
  84:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  89:	48 89 43 10          	mov    %rax,0x10(%rbx)
  8d:	48 83 c4 20          	add    $0x20,%rsp
  91:	48 89 d8             	mov    %rbx,%rax
  94:	5b                   	pop    %rbx
  95:	c3                   	retq   
  96:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  9d:	00 00 00 
