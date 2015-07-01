   0:	53                   	push   %rbx
   1:	48 83 ec 30          	sub    $0x30,%rsp
   5:	48 89 fb             	mov    %rdi,%rbx
   8:	48 8b 06             	mov    (%rsi),%rax
   b:	48 c7 06 00 00 00 00 	movq   $0x0,(%rsi)
  12:	c6 44 24 28 03       	movb   $0x3,0x28(%rsp)
  17:	48 89 04 24          	mov    %rax,(%rsp)
  1b:	48 c7 44 24 18 00 00 	movq   $0x0,0x18(%rsp)
  22:	00 00 
  24:	c6 44 24 10 03       	movb   $0x3,0x10(%rsp)
  29:	48 8d 34 24          	lea    (%rsp),%rsi
  2d:	e8 00 00 00 00       	callq  32 <_Z5test1NSt15__exception_ptr13exception_ptrE+0x32>
  32:	8a 44 24 10          	mov    0x10(%rsp),%al
  36:	fe c8                	dec    %al
  38:	0f b6 c0             	movzbl %al,%eax
  3b:	83 f8 03             	cmp    $0x3,%eax
  3e:	77 15                	ja     55 <_Z5test1NSt15__exception_ptr13exception_ptrE+0x55>
  40:	ff 24 c5 00 00 00 00 	jmpq   *0x0(,%rax,8)
  47:	48 8d 3c 24          	lea    (%rsp),%rdi
  4b:	e8 00 00 00 00       	callq  50 <_Z5test1NSt15__exception_ptr13exception_ptrE+0x50>
  50:	c6 44 24 10 00       	movb   $0x0,0x10(%rsp)
  55:	8a 44 24 28          	mov    0x28(%rsp),%al
  59:	fe c8                	dec    %al
  5b:	0f b6 c0             	movzbl %al,%eax
  5e:	83 f8 03             	cmp    $0x3,%eax
  61:	77 16                	ja     79 <_Z5test1NSt15__exception_ptr13exception_ptrE+0x79>
  63:	ff 24 c5 00 00 00 00 	jmpq   *0x0(,%rax,8)
  6a:	48 8d 7c 24 18       	lea    0x18(%rsp),%rdi
  6f:	e8 00 00 00 00       	callq  74 <_Z5test1NSt15__exception_ptr13exception_ptrE+0x74>
  74:	c6 44 24 28 00       	movb   $0x0,0x28(%rsp)
  79:	48 89 d8             	mov    %rbx,%rax
  7c:	48 83 c4 30          	add    $0x30,%rsp
  80:	5b                   	pop    %rbx
  81:	c3                   	retq   
  82:	66 66 66 66 66 2e 0f 	data32 data32 data32 data32 nopw %cs:0x0(%rax,%rax,1)
  89:	1f 84 00 00 00 00 00 
