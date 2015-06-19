   0:	53                   	push   %rbx
   1:	48 83 ec 20          	sub    $0x20,%rsp
   5:	48 89 fb             	mov    %rdi,%rbx
   8:	48 8b 06             	mov    (%rsi),%rax
   b:	48 89 44 24 08       	mov    %rax,0x8(%rsp)
  10:	48 c7 06 00 00 00 00 	movq   $0x0,(%rsi)
  17:	c6 44 24 18 03       	movb   $0x3,0x18(%rsp)
  1c:	48 8d 74 24 08       	lea    0x8(%rsp),%rsi
  21:	e8 00 00 00 00       	callq  26 <_Z5test1NSt15__exception_ptr13exception_ptrE+0x26>
  26:	8a 44 24 18          	mov    0x18(%rsp),%al
  2a:	fe c8                	dec    %al
  2c:	0f b6 c0             	movzbl %al,%eax
  2f:	83 f8 03             	cmp    $0x3,%eax
  32:	77 21                	ja     55 <_Z5test1NSt15__exception_ptr13exception_ptrE+0x55>
  34:	ff 24 c5 00 00 00 00 	jmpq   *0x0(,%rax,8)
  3b:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  40:	e8 00 00 00 00       	callq  45 <_Z5test1NSt15__exception_ptr13exception_ptrE+0x45>
  45:	eb 09                	jmp    50 <_Z5test1NSt15__exception_ptr13exception_ptrE+0x50>
  47:	48 c7 44 24 08 00 00 	movq   $0x0,0x8(%rsp)
  4e:	00 00 
  50:	c6 44 24 18 00       	movb   $0x0,0x18(%rsp)
  55:	48 89 d8             	mov    %rbx,%rax
  58:	48 83 c4 20          	add    $0x20,%rsp
  5c:	5b                   	pop    %rbx
  5d:	c3                   	retq   
  5e:	48 89 c3             	mov    %rax,%rbx
  61:	8a 44 24 18          	mov    0x18(%rsp),%al
  65:	fe c8                	dec    %al
  67:	0f b6 c0             	movzbl %al,%eax
  6a:	83 f8 03             	cmp    $0x3,%eax
  6d:	77 21                	ja     90 <_Z5test1NSt15__exception_ptr13exception_ptrE+0x90>
  6f:	ff 24 c5 00 00 00 00 	jmpq   *0x0(,%rax,8)
  76:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  7b:	e8 00 00 00 00       	callq  80 <_Z5test1NSt15__exception_ptr13exception_ptrE+0x80>
  80:	eb 09                	jmp    8b <_Z5test1NSt15__exception_ptr13exception_ptrE+0x8b>
  82:	48 c7 44 24 08 00 00 	movq   $0x0,0x8(%rsp)
  89:	00 00 
  8b:	c6 44 24 18 00       	movb   $0x0,0x18(%rsp)
  90:	48 89 df             	mov    %rbx,%rdi
  93:	e8 00 00 00 00       	callq  98 <_Z5test1NSt15__exception_ptr13exception_ptrE+0x98>
  98:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
  9f:	00 
