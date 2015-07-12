   0:	53                   	push   %rbx
   1:	48 81 ec 80 00 00 00 	sub    $0x80,%rsp
   8:	c6 44 24 48 00       	movb   $0x0,0x48(%rsp)
   d:	c6 44 24 50 00       	movb   $0x0,0x50(%rsp)
  12:	c6 44 24 51 00       	movb   $0x0,0x51(%rsp)
  17:	0f 57 c0             	xorps  %xmm0,%xmm0
  1a:	0f 11 44 24 68       	movups %xmm0,0x68(%rsp)
  1f:	0f 11 44 24 58       	movups %xmm0,0x58(%rsp)
  24:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
  29:	48 8d 74 24 38       	lea    0x38(%rsp),%rsi
  2e:	e8 00 00 00 00       	callq  33 <_Z5test1v+0x33>
  33:	c7 44 24 0c 05 00 00 	movl   $0x5,0xc(%rsp)
  3a:	00 
  3b:	48 8d 44 24 0c       	lea    0xc(%rsp),%rax
  40:	48 89 44 24 78       	mov    %rax,0x78(%rsp)
  45:	48 8d 7c 24 38       	lea    0x38(%rsp),%rdi
  4a:	48 8d 74 24 78       	lea    0x78(%rsp),%rsi
  4f:	e8 00 00 00 00       	callq  54 <_Z5test1v+0x54>
  54:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
  59:	e8 00 00 00 00       	callq  5e <_Z5test1v+0x5e>
  5e:	89 c3                	mov    %eax,%ebx
  60:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
  65:	e8 00 00 00 00       	callq  6a <_Z5test1v+0x6a>
  6a:	48 8d 7c 24 38       	lea    0x38(%rsp),%rdi
  6f:	e8 00 00 00 00       	callq  74 <_Z5test1v+0x74>
  74:	89 d8                	mov    %ebx,%eax
  76:	48 81 c4 80 00 00 00 	add    $0x80,%rsp
  7d:	5b                   	pop    %rbx
  7e:	c3                   	retq   
  7f:	48 89 c3             	mov    %rax,%rbx
  82:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
  87:	e8 00 00 00 00       	callq  8c <_Z5test1v+0x8c>
  8c:	eb 03                	jmp    91 <_Z5test1v+0x91>
  8e:	48 89 c3             	mov    %rax,%rbx
  91:	48 8d 7c 24 38       	lea    0x38(%rsp),%rdi
  96:	e8 00 00 00 00       	callq  9b <_Z5test1v+0x9b>
  9b:	48 89 df             	mov    %rbx,%rdi
  9e:	e8 00 00 00 00       	callq  a3 <_Z5test1v+0xa3>
  a3:	66 66 66 66 2e 0f 1f 	data32 data32 data32 nopw %cs:0x0(%rax,%rax,1)
  aa:	84 00 00 00 00 00 
