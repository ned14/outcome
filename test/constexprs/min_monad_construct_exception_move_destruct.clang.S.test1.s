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
  32:	0f b6 44 24 10       	movzbl 0x10(%rsp),%eax
  37:	83 f8 03             	cmp    $0x3,%eax
  3a:	74 0c                	je     48 <_Z5test1NSt15__exception_ptr13exception_ptrE+0x48>
  3c:	83 f8 02             	cmp    $0x2,%eax
  3f:	74 10                	je     51 <_Z5test1NSt15__exception_ptr13exception_ptrE+0x51>
  41:	83 f8 01             	cmp    $0x1,%eax
  44:	74 0b                	je     51 <_Z5test1NSt15__exception_ptr13exception_ptrE+0x51>
  46:	eb 0e                	jmp    56 <_Z5test1NSt15__exception_ptr13exception_ptrE+0x56>
  48:	48 8d 3c 24          	lea    (%rsp),%rdi
  4c:	e8 00 00 00 00       	callq  51 <_Z5test1NSt15__exception_ptr13exception_ptrE+0x51>
  51:	c6 44 24 10 00       	movb   $0x0,0x10(%rsp)
  56:	0f b6 44 24 28       	movzbl 0x28(%rsp),%eax
  5b:	83 f8 03             	cmp    $0x3,%eax
  5e:	74 0c                	je     6c <_Z5test1NSt15__exception_ptr13exception_ptrE+0x6c>
  60:	83 f8 02             	cmp    $0x2,%eax
  63:	74 11                	je     76 <_Z5test1NSt15__exception_ptr13exception_ptrE+0x76>
  65:	83 f8 01             	cmp    $0x1,%eax
  68:	74 0c                	je     76 <_Z5test1NSt15__exception_ptr13exception_ptrE+0x76>
  6a:	eb 0f                	jmp    7b <_Z5test1NSt15__exception_ptr13exception_ptrE+0x7b>
  6c:	48 8d 7c 24 18       	lea    0x18(%rsp),%rdi
  71:	e8 00 00 00 00       	callq  76 <_Z5test1NSt15__exception_ptr13exception_ptrE+0x76>
  76:	c6 44 24 28 00       	movb   $0x0,0x28(%rsp)
  7b:	48 89 d8             	mov    %rbx,%rax
  7e:	48 83 c4 30          	add    $0x30,%rsp
  82:	5b                   	pop    %rbx
  83:	c3                   	retq   
  84:	66 66 66 2e 0f 1f 84 	data32 data32 nopw %cs:0x0(%rax,%rax,1)
  8b:	00 00 00 00 00 
