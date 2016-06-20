   0:	41 56                	push   %r14
   2:	53                   	push   %rbx
   3:	48 83 ec 28          	sub    $0x28,%rsp
   7:	41 89 f6             	mov    %esi,%r14d
   a:	48 89 fb             	mov    %rdi,%rbx
   d:	44 89 74 24 08       	mov    %r14d,0x8(%rsp)
  12:	c6 44 24 20 01       	movb   $0x1,0x20(%rsp)
  17:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  1c:	e8 00 00 00 00       	callq  21 <_Z5test1i+0x21>
  21:	43 8d 04 76          	lea    (%r14,%r14,2),%eax
  25:	89 03                	mov    %eax,(%rbx)
  27:	c6 43 18 01          	movb   $0x1,0x18(%rbx)
  2b:	48 89 d8             	mov    %rbx,%rax
  2e:	48 83 c4 28          	add    $0x28,%rsp
  32:	5b                   	pop    %rbx
  33:	41 5e                	pop    %r14
  35:	c3                   	retq   
  36:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  3d:	00 00 00 
