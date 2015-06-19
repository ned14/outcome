   0:	53                   	push   %rbx
   1:	48 89 fb             	mov    %rdi,%rbx
   4:	48 83 ec 20          	sub    $0x20,%rsp
   8:	48 8b 06             	mov    (%rsi),%rax
   b:	48 c7 06 00 00 00 00 	movq   $0x0,(%rsi)
  12:	48 89 e6             	mov    %rsp,%rsi
  15:	c6 44 24 10 03       	movb   $0x3,0x10(%rsp)
  1a:	48 89 04 24          	mov    %rax,(%rsp)
  1e:	e8 00 00 00 00       	callq  23 <_Z5test1NSt15__exception_ptr13exception_ptrE+0x23>
  23:	80 7c 24 10 03       	cmpb   $0x3,0x10(%rsp)
  28:	74 0e                	je     38 <_Z5test1NSt15__exception_ptr13exception_ptrE+0x38>
  2a:	48 83 c4 20          	add    $0x20,%rsp
  2e:	48 89 d8             	mov    %rbx,%rax
  31:	5b                   	pop    %rbx
  32:	c3                   	retq   
  33:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
  38:	48 89 e7             	mov    %rsp,%rdi
  3b:	e8 00 00 00 00       	callq  40 <_Z5test1NSt15__exception_ptr13exception_ptrE+0x40>
  40:	48 83 c4 20          	add    $0x20,%rsp
  44:	48 89 d8             	mov    %rbx,%rax
  47:	5b                   	pop    %rbx
  48:	c3                   	retq   
  49:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
