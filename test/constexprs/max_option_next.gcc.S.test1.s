   0:	55                   	push   %rbp
   1:	53                   	push   %rbx
   2:	48 89 fb             	mov    %rdi,%rbx
   5:	48 83 ec 18          	sub    $0x18,%rsp
   9:	48 89 e7             	mov    %rsp,%rdi
   c:	e8 00 00 00 00       	callq  11 <_Z5test1v+0x11>
  11:	0f b6 54 24 04       	movzbl 0x4(%rsp),%edx
  16:	80 fa 01             	cmp    $0x1,%dl
  19:	74 2d                	je     48 <_Z5test1v+0x48>
  1b:	80 fa 04             	cmp    $0x4,%dl
  1e:	74 20                	je     40 <_Z5test1v+0x40>
  20:	84 d2                	test   %dl,%dl
  22:	74 29                	je     4d <_Z5test1v+0x4d>
  24:	8d 44 6d 00          	lea    0x0(%rbp,%rbp,2),%eax
  28:	c6 43 04 01          	movb   $0x1,0x4(%rbx)
  2c:	89 03                	mov    %eax,(%rbx)
  2e:	48 83 c4 18          	add    $0x18,%rsp
  32:	48 89 d8             	mov    %rbx,%rax
  35:	5b                   	pop    %rbx
  36:	5d                   	pop    %rbp
  37:	c3                   	retq   
  38:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
  3f:	00 
  40:	e8 00 00 00 00       	callq  45 <_Z5test1v+0x45>
  45:	0f 1f 00             	nopl   (%rax)
  48:	8b 2c 24             	mov    (%rsp),%ebp
  4b:	eb d7                	jmp    24 <_Z5test1v+0x24>
  4d:	bf 02 00 00 00       	mov    $0x2,%edi
  52:	e8 00 00 00 00       	callq  57 <_Z5test1v+0x57>
  57:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  5e:	00 00 
