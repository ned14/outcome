  10:	53                   	push   %rbx
  11:	48 89 fb             	mov    %rdi,%rbx
  14:	48 83 ec 40          	sub    $0x40,%rsp
  18:	48 8b 06             	mov    (%rsi),%rax
  1b:	48 c7 06 00 00 00 00 	movq   $0x0,(%rsi)
  22:	48 8d 74 24 20       	lea    0x20(%rsp),%rsi
  27:	c6 44 24 10 03       	movb   $0x3,0x10(%rsp)
  2c:	48 c7 04 24 00 00 00 	movq   $0x0,(%rsp)
  33:	00 
  34:	c6 44 24 30 03       	movb   $0x3,0x30(%rsp)
  39:	48 89 44 24 20       	mov    %rax,0x20(%rsp)
  3e:	e8 00 00 00 00       	callq  43 <_Z5test2v+0x43>
  43:	80 7c 24 30 03       	cmpb   $0x3,0x30(%rsp)
  48:	74 16                	je     60 <_Z5test2v+0x60>
  4a:	80 7c 24 10 03       	cmpb   $0x3,0x10(%rsp)
  4f:	74 20                	je     71 <_Z5test2v+0x71>
  51:	48 83 c4 40          	add    $0x40,%rsp
  55:	48 89 d8             	mov    %rbx,%rax
  58:	5b                   	pop    %rbx
  59:	c3                   	retq   
  5a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
  60:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
  65:	e8 00 00 00 00       	callq  6a <_Z5test2v+0x6a>
  6a:	80 7c 24 10 03       	cmpb   $0x3,0x10(%rsp)
  6f:	75 e0                	jne    51 <_Z5test2v+0x51>
  71:	48 89 e7             	mov    %rsp,%rdi
  74:	e8 00 00 00 00       	callq  79 <_Z5test2v+0x79>
  79:	48 83 c4 40          	add    $0x40,%rsp
  7d:	48 89 d8             	mov    %rbx,%rax
  80:	5b                   	pop    %rbx
  81:	c3                   	retq   
