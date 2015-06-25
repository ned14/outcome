   8:	53                   	push   %rbx
   9:	48 83 ec 50          	sub    $0x50,%rsp
   d:	c6 44 24 40 00       	movb   $0x0,0x40(%rsp)
  12:	c6 44 24 48 00       	movb   $0x0,0x48(%rsp)
  17:	c7 44 24 2c 05 00 00 	movl   $0x5,0x2c(%rsp)
  1e:	00 
  1f:	48 8d 5c 24 30       	lea    0x30(%rsp),%rbx
  24:	48 8d 74 24 2c       	lea    0x2c(%rsp),%rsi
  29:	48 89 df             	mov    %rbx,%rdi
  2c:	e8 00 00 00 00       	callq  31 <_Z5test1v+0x29>
  31:	48 8d 3c 24          	lea    (%rsp),%rdi
  35:	48 89 de             	mov    %rbx,%rsi
  38:	e8 00 00 00 00       	callq  3d <_Z5test1v+0x35>
  3d:	48 8d 3c 24          	lea    (%rsp),%rdi
  41:	e8 00 00 00 00       	callq  46 <_Z5test1v+0x3e>
  46:	89 c3                	mov    %eax,%ebx
  48:	48 8d 3c 24          	lea    (%rsp),%rdi
  4c:	e8 00 00 00 00       	callq  51 <_Z5test1v+0x49>
  51:	48 8d 7c 24 30       	lea    0x30(%rsp),%rdi
  56:	e8 00 00 00 00       	callq  5b <_Z5test1v+0x53>
  5b:	89 d8                	mov    %ebx,%eax
  5d:	48 83 c4 50          	add    $0x50,%rsp
  61:	5b                   	pop    %rbx
  62:	c3                   	retq   
  63:	48 89 c3             	mov    %rax,%rbx
  66:	eb 0c                	jmp    74 <_Z5test1v+0x6c>
  68:	48 89 c3             	mov    %rax,%rbx
  6b:	48 8d 3c 24          	lea    (%rsp),%rdi
  6f:	e8 00 00 00 00       	callq  74 <_Z5test1v+0x6c>
  74:	48 8d 7c 24 30       	lea    0x30(%rsp),%rdi
  79:	e8 00 00 00 00       	callq  7e <_Z5test1v+0x76>
  7e:	48 89 df             	mov    %rbx,%rdi
  81:	e8 00 00 00 00       	callq  86 <_Z5test1v+0x7e>
  86:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  8d:	00 00 00 
