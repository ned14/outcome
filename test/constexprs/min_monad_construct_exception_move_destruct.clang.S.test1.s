   8:	53                   	push   %rbx
   9:	48 83 ec 30          	sub    $0x30,%rsp
   d:	48 89 fb             	mov    %rdi,%rbx
  10:	48 8b 06             	mov    (%rsi),%rax
  13:	48 c7 06 00 00 00 00 	movq   $0x0,(%rsi)
  1a:	c6 44 24 28 03       	movb   $0x3,0x28(%rsp)
  1f:	48 89 04 24          	mov    %rax,(%rsp)
  23:	48 c7 44 24 18 00 00 	movq   $0x0,0x18(%rsp)
  2a:	00 00 
  2c:	c6 44 24 10 03       	movb   $0x3,0x10(%rsp)
  31:	48 8d 34 24          	lea    (%rsp),%rsi
  35:	e8 00 00 00 00       	callq  3a <_Z5test1NSt15__exception_ptr13exception_ptrE+0x32>
  3a:	8a 44 24 10          	mov    0x10(%rsp),%al
  3e:	fe c8                	dec    %al
  40:	0f b6 c0             	movzbl %al,%eax
  43:	83 f8 03             	cmp    $0x3,%eax
  46:	77 15                	ja     5d <_Z5test1NSt15__exception_ptr13exception_ptrE+0x55>
  48:	ff 24 c5 00 00 00 00 	jmpq   *0x0(,%rax,8)
  4f:	48 8d 3c 24          	lea    (%rsp),%rdi
  53:	e8 00 00 00 00       	callq  58 <_Z5test1NSt15__exception_ptr13exception_ptrE+0x50>
  58:	c6 44 24 10 00       	movb   $0x0,0x10(%rsp)
  5d:	8a 44 24 28          	mov    0x28(%rsp),%al
  61:	fe c8                	dec    %al
  63:	0f b6 c0             	movzbl %al,%eax
  66:	83 f8 03             	cmp    $0x3,%eax
  69:	77 16                	ja     81 <_Z5test1NSt15__exception_ptr13exception_ptrE+0x79>
  6b:	ff 24 c5 00 00 00 00 	jmpq   *0x0(,%rax,8)
  72:	48 8d 7c 24 18       	lea    0x18(%rsp),%rdi
  77:	e8 00 00 00 00       	callq  7c <_Z5test1NSt15__exception_ptr13exception_ptrE+0x74>
  7c:	c6 44 24 28 00       	movb   $0x0,0x28(%rsp)
  81:	48 89 d8             	mov    %rbx,%rax
  84:	48 83 c4 30          	add    $0x30,%rsp
  88:	5b                   	pop    %rbx
  89:	c3                   	retq   
  8a:	48 89 c3             	mov    %rax,%rbx
  8d:	8a 44 24 10          	mov    0x10(%rsp),%al
  91:	fe c8                	dec    %al
  93:	0f b6 c0             	movzbl %al,%eax
  96:	83 f8 03             	cmp    $0x3,%eax
  99:	77 15                	ja     b0 <_Z5test1NSt15__exception_ptr13exception_ptrE+0xa8>
  9b:	ff 24 c5 00 00 00 00 	jmpq   *0x0(,%rax,8)
  a2:	48 8d 3c 24          	lea    (%rsp),%rdi
  a6:	e8 00 00 00 00       	callq  ab <_Z5test1NSt15__exception_ptr13exception_ptrE+0xa3>
  ab:	c6 44 24 10 00       	movb   $0x0,0x10(%rsp)
  b0:	8a 44 24 28          	mov    0x28(%rsp),%al
  b4:	fe c8                	dec    %al
  b6:	0f b6 c0             	movzbl %al,%eax
  b9:	83 f8 03             	cmp    $0x3,%eax
  bc:	77 16                	ja     d4 <_Z5test1NSt15__exception_ptr13exception_ptrE+0xcc>
  be:	ff 24 c5 00 00 00 00 	jmpq   *0x0(,%rax,8)
  c5:	48 8d 7c 24 18       	lea    0x18(%rsp),%rdi
  ca:	e8 00 00 00 00       	callq  cf <_Z5test1NSt15__exception_ptr13exception_ptrE+0xc7>
  cf:	c6 44 24 28 00       	movb   $0x0,0x28(%rsp)
  d4:	48 89 df             	mov    %rbx,%rdi
  d7:	e8 00 00 00 00       	callq  dc <_Z5test1NSt15__exception_ptr13exception_ptrE+0xd4>
  dc:	0f 1f 40 00          	nopl   0x0(%rax)
