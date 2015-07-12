   0:	53                   	push   %rbx
   1:	48 81 ec 80 00 00 00 	sub    $0x80,%rsp
   8:	c6 44 24 48 00       	movb   $0x0,0x48(%rsp)
   d:	c6 44 24 50 00       	movb   $0x0,0x50(%rsp)
  12:	c6 44 24 52 00       	movb   $0x0,0x52(%rsp)
  17:	0f 57 c0             	xorps  %xmm0,%xmm0
  1a:	0f 11 44 24 68       	movups %xmm0,0x68(%rsp)
  1f:	0f 11 44 24 58       	movups %xmm0,0x58(%rsp)
  24:	c7 44 24 34 05 00 00 	movl   $0x5,0x34(%rsp)
  2b:	00 
  2c:	48 8d 44 24 34       	lea    0x34(%rsp),%rax
  31:	48 89 44 24 78       	mov    %rax,0x78(%rsp)
  36:	48 8d 7c 24 38       	lea    0x38(%rsp),%rdi
  3b:	48 8d 74 24 78       	lea    0x78(%rsp),%rsi
  40:	e8 00 00 00 00       	callq  45 <_Z5test1v+0x45>
  45:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  4a:	48 8d 74 24 38       	lea    0x38(%rsp),%rsi
  4f:	e8 00 00 00 00       	callq  54 <_Z5test1v+0x54>
  54:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  59:	e8 00 00 00 00       	callq  5e <_Z5test1v+0x5e>
  5e:	89 c3                	mov    %eax,%ebx
  60:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  65:	e8 00 00 00 00       	callq  6a <_Z5test1v+0x6a>
  6a:	48 8d 7c 24 38       	lea    0x38(%rsp),%rdi
  6f:	e8 00 00 00 00       	callq  74 <_Z5test1v+0x74>
  74:	89 d8                	mov    %ebx,%eax
  76:	48 81 c4 80 00 00 00 	add    $0x80,%rsp
  7d:	5b                   	pop    %rbx
  7e:	c3                   	retq   
  7f:	48 89 c3             	mov    %rax,%rbx
  82:	eb 0d                	jmp    91 <_Z5test1v+0x91>
  84:	48 89 c3             	mov    %rax,%rbx
  87:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  8c:	e8 00 00 00 00       	callq  91 <_Z5test1v+0x91>
  91:	48 8d 7c 24 38       	lea    0x38(%rsp),%rdi
  96:	e8 00 00 00 00       	callq  9b <_Z5test1v+0x9b>
  9b:	48 89 df             	mov    %rbx,%rdi
  9e:	e8 00 00 00 00       	callq  a3 <_Z5test1v+0xa3>
  a3:	66 66 66 66 2e 0f 1f 	data32 data32 data32 nopw %cs:0x0(%rax,%rax,1)
  aa:	84 00 00 00 00 00 
