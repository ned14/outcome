   2:	53                   	push   %rbx
   3:	48 89 fb             	mov    %rdi,%rbx
   6:	48 83 ec 40          	sub    $0x40,%rsp
   a:	48 8b 06             	mov    (%rsi),%rax
   d:	48 c7 06 00 00 00 00 	movq   $0x0,(%rsi)
  14:	48 8d 74 24 20       	lea    0x20(%rsp),%rsi
  19:	c6 44 24 10 03       	movb   $0x3,0x10(%rsp)
  1e:	48 c7 04 24 00 00 00 	movq   $0x0,(%rsp)
  25:	00 
  26:	c6 44 24 30 03       	movb   $0x3,0x30(%rsp)
  2b:	48 89 44 24 20       	mov    %rax,0x20(%rsp)
  30:	e8 00 00 00 00       	callq  35 <_Z5test2v+0x35>
  35:	80 7c 24 30 03       	cmpb   $0x3,0x30(%rsp)
  3a:	74 14                	je     50 <_Z5test2v+0x50>
  3c:	80 7c 24 10 03       	cmpb   $0x3,0x10(%rsp)
  41:	74 1e                	je     61 <_Z5test2v+0x61>
  43:	48 83 c4 40          	add    $0x40,%rsp
  47:	48 89 d8             	mov    %rbx,%rax
  4a:	5b                   	pop    %rbx
  4b:	c3                   	retq   
  4c:	0f 1f 40 00          	nopl   0x0(%rax)
  50:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
  55:	e8 00 00 00 00       	callq  5a <_Z5test2v+0x5a>
  5a:	80 7c 24 10 03       	cmpb   $0x3,0x10(%rsp)
  5f:	75 e2                	jne    43 <_Z5test2v+0x43>
  61:	48 89 e7             	mov    %rsp,%rdi
  64:	e8 00 00 00 00       	callq  69 <_Z5test2v+0x69>
  69:	48 83 c4 40          	add    $0x40,%rsp
  6d:	48 89 d8             	mov    %rbx,%rax
  70:	5b                   	pop    %rbx
  71:	c3                   	retq   
