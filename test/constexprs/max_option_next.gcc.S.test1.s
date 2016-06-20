  10:	55                   	push   %rbp
  11:	53                   	push   %rbx
  12:	48 89 fb             	mov    %rdi,%rbx
  15:	48 83 ec 18          	sub    $0x18,%rsp
  19:	48 89 e7             	mov    %rsp,%rdi
  1c:	e8 00 00 00 00       	callq  21 <_Z5test1v+0x11>
  21:	0f b6 44 24 04       	movzbl 0x4(%rsp),%eax
  26:	3c 01                	cmp    $0x1,%al
  28:	75 1e                	jne    48 <_Z5test1v+0x38>
  2a:	8b 2c 24             	mov    (%rsp),%ebp
  2d:	8d 44 6d 00          	lea    0x0(%rbp,%rbp,2),%eax
  31:	c6 43 04 01          	movb   $0x1,0x4(%rbx)
  35:	89 03                	mov    %eax,(%rbx)
  37:	48 83 c4 18          	add    $0x18,%rsp
  3b:	48 89 d8             	mov    %rbx,%rax
  3e:	5b                   	pop    %rbx
  3f:	5d                   	pop    %rbp
  40:	c3                   	retq   
  41:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
  48:	84 c0                	test   %al,%al
  4a:	75 e1                	jne    2d <_Z5test1v+0x1d>
  4c:	bf 02 00 00 00       	mov    $0x2,%edi
  51:	e8 00 00 00 00       	callq  56 <_Z5test1v+0x46>
