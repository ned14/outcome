   2:	55                   	push   %rbp
   3:	53                   	push   %rbx
   4:	48 89 fb             	mov    %rdi,%rbx
   7:	48 83 ec 18          	sub    $0x18,%rsp
   b:	48 89 e7             	mov    %rsp,%rdi
   e:	e8 00 00 00 00       	callq  13 <_Z5test2v+0x13>
  13:	0f b6 54 24 04       	movzbl 0x4(%rsp),%edx
  18:	80 fa 01             	cmp    $0x1,%dl
  1b:	74 2b                	je     48 <_Z5test2v+0x48>
  1d:	80 fa 04             	cmp    $0x4,%dl
  20:	74 1e                	je     40 <_Z5test2v+0x40>
  22:	84 d2                	test   %dl,%dl
  24:	74 27                	je     4d <_Z5test2v+0x4d>
  26:	8d 44 6d 00          	lea    0x0(%rbp,%rbp,2),%eax
  2a:	c6 43 04 01          	movb   $0x1,0x4(%rbx)
  2e:	89 03                	mov    %eax,(%rbx)
  30:	48 83 c4 18          	add    $0x18,%rsp
  34:	48 89 d8             	mov    %rbx,%rax
  37:	5b                   	pop    %rbx
  38:	5d                   	pop    %rbp
  39:	c3                   	retq   
  3a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
  40:	e8 00 00 00 00       	callq  45 <_Z5test2v+0x45>
  45:	0f 1f 00             	nopl   (%rax)
  48:	8b 2c 24             	mov    (%rsp),%ebp
  4b:	eb d9                	jmp    26 <_Z5test2v+0x26>
  4d:	bf 02 00 00 00       	mov    $0x2,%edi
  52:	e8 00 00 00 00       	callq  57 <_Z5test2v+0x57>
