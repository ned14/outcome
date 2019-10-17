  4008d0:	53                   	push   %rbx
  4008d1:	48 83 ec 20          	sub    $0x20,%rsp
  4008d5:	48 89 fb             	mov    %rdi,%rbx
  4008d8:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  4008b0:	c7 47 04 02 00 00 00 	movl   $0x2,0x4(%rdi)
  4008b7:	48 c7 47 08 f0 0c 40 	movq   $0x400cf0,0x8(%rdi)
  4008bf:	48 c7 47 10 21 00 00 	movq   $0x21,0x10(%rdi)
  4008c7:	48 89 f8             	mov    %rdi,%rax
  4008ca:	c3                   	retq
  4008cb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
  4008e2:	f6 44 24 0c 01       	testb  $0x1,0xc(%rsp)
  4008e7:	74 4b                	je     400934 <test1()+0x64>
  4008e9:	8b 44 24 08          	mov    0x8(%rsp),%eax
  4008ed:	89 03                	mov    %eax,(%rbx)
  4008ef:	0f 57 c0             	xorps  %xmm0,%xmm0
  4008f2:	0f 11 43 08          	movups %xmm0,0x8(%rbx)
  4008f6:	c7 05 6c 17 20 00 00 	movl   $0x0,0x20176c(%rip)        # 60206c <foo>
  400900:	48 8b 7c 24 10       	mov    0x10(%rsp),%rdi
  400905:	c7 43 04 01 00 00 00 	movl   $0x1,0x4(%rbx)
  40090c:	48 85 ff             	test   %rdi,%rdi
  40090f:	74 10                	je     400921 <test1()+0x51>
  400911:	48 8d 74 24 10       	lea    0x10(%rsp),%rsi
  400916:	48 8b 07             	mov    (%rdi),%rax
  400919:	ba 10 00 00 00       	mov    $0x10,%edx
  40091e:	ff 50 38             	callq  *0x38(%rax)
  400921:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  4009a0:	c3                   	retq
  4009a1:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  4009ab:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
  40092b:	48 89 d8             	mov    %rbx,%rax
  40092e:	48 83 c4 20          	add    $0x20,%rsp
  400932:	5b                   	pop    %rbx
  400933:	c3                   	retq
  400934:	0f 10 44 24 10       	movups 0x10(%rsp),%xmm0
  400939:	48 c7 44 24 10 00 00 	movq   $0x0,0x10(%rsp)
  400942:	0f 11 43 08          	movups %xmm0,0x8(%rbx)
  400946:	c7 43 04 02 00 00 00 	movl   $0x2,0x4(%rbx)
  40094d:	eb d2                	jmp    400921 <test1()+0x51>
  40094f:	90                   	nop
