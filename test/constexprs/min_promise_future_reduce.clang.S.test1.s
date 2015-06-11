   0:	53                   	push   %rbx
   1:	48 83 ec 50          	sub    $0x50,%rsp
   5:	c6 44 24 40 00       	movb   $0x0,0x40(%rsp)
   a:	c6 44 24 48 00       	movb   $0x0,0x48(%rsp)
   f:	c7 44 24 2c 05 00 00 	movl   $0x5,0x2c(%rsp)
  16:	00 
  17:	48 8d 5c 24 30       	lea    0x30(%rsp),%rbx
  1c:	48 8d 74 24 2c       	lea    0x2c(%rsp),%rsi
  21:	48 89 df             	mov    %rbx,%rdi
  24:	e8 00 00 00 00       	callq  29 <_Z5test1v+0x29>
  29:	48 8d 3c 24          	lea    (%rsp),%rdi
  2d:	48 89 de             	mov    %rbx,%rsi
  30:	e8 00 00 00 00       	callq  35 <_Z5test1v+0x35>
  35:	48 8d 3c 24          	lea    (%rsp),%rdi
  39:	e8 00 00 00 00       	callq  3e <_Z5test1v+0x3e>
  3e:	89 c3                	mov    %eax,%ebx
  40:	48 8d 3c 24          	lea    (%rsp),%rdi
  44:	e8 00 00 00 00       	callq  49 <_Z5test1v+0x49>
  49:	48 8d 7c 24 30       	lea    0x30(%rsp),%rdi
  4e:	e8 00 00 00 00       	callq  53 <_Z5test1v+0x53>
  53:	89 d8                	mov    %ebx,%eax
  55:	48 83 c4 50          	add    $0x50,%rsp
  59:	5b                   	pop    %rbx
  5a:	c3                   	retq   
  5b:	48 89 c3             	mov    %rax,%rbx
  5e:	eb 0c                	jmp    6c <_Z5test1v+0x6c>
  60:	48 89 c3             	mov    %rax,%rbx
  63:	48 8d 3c 24          	lea    (%rsp),%rdi
  67:	e8 00 00 00 00       	callq  6c <_Z5test1v+0x6c>
  6c:	48 8d 7c 24 30       	lea    0x30(%rsp),%rdi
  71:	e8 00 00 00 00       	callq  76 <_Z5test1v+0x76>
  76:	48 89 df             	mov    %rbx,%rdi
  79:	e8 00 00 00 00       	callq  7e <_Z5test1v+0x7e>
  7e:	66 90                	xchg   %ax,%ax
