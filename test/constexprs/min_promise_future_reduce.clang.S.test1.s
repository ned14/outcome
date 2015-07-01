   0:	53                   	push   %rbx
   1:	48 83 ec 50          	sub    $0x50,%rsp
   5:	c6 44 24 40 00       	movb   $0x0,0x40(%rsp)
   a:	c6 44 24 48 00       	movb   $0x0,0x48(%rsp)
   f:	c6 44 24 49 00       	movb   $0x0,0x49(%rsp)
  14:	c7 44 24 2c 05 00 00 	movl   $0x5,0x2c(%rsp)
  1b:	00 
  1c:	48 8d 7c 24 30       	lea    0x30(%rsp),%rdi
  21:	48 8d 74 24 2c       	lea    0x2c(%rsp),%rsi
  26:	e8 00 00 00 00       	callq  2b <_Z5test1v+0x2b>
  2b:	48 8d 3c 24          	lea    (%rsp),%rdi
  2f:	48 8d 74 24 30       	lea    0x30(%rsp),%rsi
  34:	e8 00 00 00 00       	callq  39 <_Z5test1v+0x39>
  39:	48 8d 3c 24          	lea    (%rsp),%rdi
  3d:	e8 00 00 00 00       	callq  42 <_Z5test1v+0x42>
  42:	89 c3                	mov    %eax,%ebx
  44:	48 8d 3c 24          	lea    (%rsp),%rdi
  48:	e8 00 00 00 00       	callq  4d <_Z5test1v+0x4d>
  4d:	48 8d 7c 24 30       	lea    0x30(%rsp),%rdi
  52:	e8 00 00 00 00       	callq  57 <_Z5test1v+0x57>
  57:	89 d8                	mov    %ebx,%eax
  59:	48 83 c4 50          	add    $0x50,%rsp
  5d:	5b                   	pop    %rbx
  5e:	c3                   	retq   
  5f:	48 89 c3             	mov    %rax,%rbx
  62:	eb 0c                	jmp    70 <_Z5test1v+0x70>
  64:	48 89 c3             	mov    %rax,%rbx
  67:	48 8d 3c 24          	lea    (%rsp),%rdi
  6b:	e8 00 00 00 00       	callq  70 <_Z5test1v+0x70>
  70:	48 8d 7c 24 30       	lea    0x30(%rsp),%rdi
  75:	e8 00 00 00 00       	callq  7a <_Z5test1v+0x7a>
  7a:	48 89 df             	mov    %rbx,%rdi
  7d:	e8 00 00 00 00       	callq  82 <_Z5test1v+0x82>
  82:	66 66 66 66 66 2e 0f 	data32 data32 data32 data32 nopw %cs:0x0(%rax,%rax,1)
  89:	1f 84 00 00 00 00 00 
