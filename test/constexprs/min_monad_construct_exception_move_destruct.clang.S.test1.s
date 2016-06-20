   0:	53                   	push   %rbx
   1:	48 83 ec 40          	sub    $0x40,%rsp
   5:	48 89 fb             	mov    %rdi,%rbx
   8:	48 8b 06             	mov    (%rsi),%rax
   b:	48 c7 06 00 00 00 00 	movq   $0x0,(%rsi)
  12:	c6 44 24 38 03       	movb   $0x3,0x38(%rsp)
  17:	48 89 04 24          	mov    %rax,(%rsp)
  1b:	48 c7 44 24 20 00 00 	movq   $0x0,0x20(%rsp)
  22:	00 00 
  24:	c6 44 24 18 03       	movb   $0x3,0x18(%rsp)
  29:	48 8d 34 24          	lea    (%rsp),%rsi
  2d:	e8 00 00 00 00       	callq  32 <_Z5test1NSt15__exception_ptr13exception_ptrE+0x32>
  32:	0f b6 44 24 18       	movzbl 0x18(%rsp),%eax
  37:	83 f8 03             	cmp    $0x3,%eax
  3a:	74 0c                	je     48 <_Z5test1NSt15__exception_ptr13exception_ptrE+0x48>
  3c:	83 f8 02             	cmp    $0x2,%eax
  3f:	74 10                	je     51 <_Z5test1NSt15__exception_ptr13exception_ptrE+0x51>
  41:	83 f8 01             	cmp    $0x1,%eax
  44:	74 0b                	je     51 <_Z5test1NSt15__exception_ptr13exception_ptrE+0x51>
  46:	eb 0e                	jmp    56 <_Z5test1NSt15__exception_ptr13exception_ptrE+0x56>
  48:	48 8d 3c 24          	lea    (%rsp),%rdi
  4c:	e8 00 00 00 00       	callq  51 <_Z5test1NSt15__exception_ptr13exception_ptrE+0x51>
  51:	c6 44 24 18 00       	movb   $0x0,0x18(%rsp)
  56:	0f b6 44 24 38       	movzbl 0x38(%rsp),%eax
  5b:	83 f8 03             	cmp    $0x3,%eax
  5e:	74 0c                	je     6c <_Z5test1NSt15__exception_ptr13exception_ptrE+0x6c>
  60:	83 f8 02             	cmp    $0x2,%eax
  63:	74 11                	je     76 <_Z5test1NSt15__exception_ptr13exception_ptrE+0x76>
  65:	83 f8 01             	cmp    $0x1,%eax
  68:	74 0c                	je     76 <_Z5test1NSt15__exception_ptr13exception_ptrE+0x76>
  6a:	eb 0f                	jmp    7b <_Z5test1NSt15__exception_ptr13exception_ptrE+0x7b>
  6c:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
  71:	e8 00 00 00 00       	callq  76 <_Z5test1NSt15__exception_ptr13exception_ptrE+0x76>
  76:	c6 44 24 38 00       	movb   $0x0,0x38(%rsp)
  7b:	48 89 d8             	mov    %rbx,%rax
  7e:	48 83 c4 40          	add    $0x40,%rsp
  82:	5b                   	pop    %rbx
  83:	c3                   	retq   
  84:	48 89 c3             	mov    %rax,%rbx
  87:	0f b6 44 24 18       	movzbl 0x18(%rsp),%eax
  8c:	83 f8 03             	cmp    $0x3,%eax
  8f:	74 0c                	je     9d <_Z5test1NSt15__exception_ptr13exception_ptrE+0x9d>
  91:	83 f8 02             	cmp    $0x2,%eax
  94:	74 10                	je     a6 <_Z5test1NSt15__exception_ptr13exception_ptrE+0xa6>
  96:	83 f8 01             	cmp    $0x1,%eax
  99:	74 0b                	je     a6 <_Z5test1NSt15__exception_ptr13exception_ptrE+0xa6>
  9b:	eb 0e                	jmp    ab <_Z5test1NSt15__exception_ptr13exception_ptrE+0xab>
  9d:	48 8d 3c 24          	lea    (%rsp),%rdi
  a1:	e8 00 00 00 00       	callq  a6 <_Z5test1NSt15__exception_ptr13exception_ptrE+0xa6>
  a6:	c6 44 24 18 00       	movb   $0x0,0x18(%rsp)
  ab:	0f b6 44 24 38       	movzbl 0x38(%rsp),%eax
  b0:	83 f8 03             	cmp    $0x3,%eax
  b3:	74 0c                	je     c1 <_Z5test1NSt15__exception_ptr13exception_ptrE+0xc1>
  b5:	83 f8 02             	cmp    $0x2,%eax
  b8:	74 11                	je     cb <_Z5test1NSt15__exception_ptr13exception_ptrE+0xcb>
  ba:	83 f8 01             	cmp    $0x1,%eax
  bd:	74 0c                	je     cb <_Z5test1NSt15__exception_ptr13exception_ptrE+0xcb>
  bf:	eb 0f                	jmp    d0 <_Z5test1NSt15__exception_ptr13exception_ptrE+0xd0>
  c1:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
  c6:	e8 00 00 00 00       	callq  cb <_Z5test1NSt15__exception_ptr13exception_ptrE+0xcb>
  cb:	c6 44 24 38 00       	movb   $0x0,0x38(%rsp)
  d0:	48 89 df             	mov    %rbx,%rdi
  d3:	e8 00 00 00 00       	callq  d8 <_Z5test1NSt15__exception_ptr13exception_ptrE+0xd8>
  d8:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
  df:	00 
