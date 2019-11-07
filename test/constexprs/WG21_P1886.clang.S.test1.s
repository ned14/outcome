  400660:	53                   	push   %rbx
  400661:	48 83 ec 20          	sub    $0x20,%rsp
  400665:	48 89 fb             	mov    %rdi,%rbx
  400668:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  400640:	c7 47 04 02 00 00 00 	movl   $0x2,0x4(%rdi)
  400647:	48 c7 47 08 40 09 40 	movq   $0x400940,0x8(%rdi)
  40064f:	48 c7 47 10 21 00 00 	movq   $0x21,0x10(%rdi)
  400657:	48 89 f8             	mov    %rdi,%rax
  40065a:	c3                   	retq
  40065b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
  400672:	0f b7 44 24 0c       	movzwl 0xc(%rsp),%eax
  400677:	83 c8 08             	or     $0x8,%eax
  40067a:	83 f8 09             	cmp    $0x9,%eax
  40067d:	75 50                	jne    4006cf <test1()+0x6f>
  40067f:	8b 44 24 08          	mov    0x8(%rsp),%eax
  400683:	89 03                	mov    %eax,(%rbx)
  400685:	66 c7 43 04 01 00    	movw   $0x1,0x4(%rbx)
  40068b:	0f 57 c0             	xorps  %xmm0,%xmm0
  40068e:	0f 11 43 06          	movups %xmm0,0x6(%rbx)
  400692:	c7 05 a0 19 20 00 00 	movl   $0x0,0x2019a0(%rip)        # 60203c <foo>
  40069c:	66 c7 43 16 00 00    	movw   $0x0,0x16(%rbx)
  4006a2:	48 8b 7c 24 10       	mov    0x10(%rsp),%rdi
  4006a7:	48 85 ff             	test   %rdi,%rdi
  4006aa:	74 10                	je     4006bc <test1()+0x5c>
  4006ac:	48 8d 74 24 10       	lea    0x10(%rsp),%rsi
  4006b1:	48 8b 07             	mov    (%rdi),%rax
  4006b4:	ba 10 00 00 00       	mov    $0x10,%edx
  4006b9:	ff 50 38             	callq  *0x38(%rax)
  4006bc:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  400750:	c3                   	retq
  400751:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  40075b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
  4006c6:	48 89 d8             	mov    %rbx,%rax
  4006c9:	48 83 c4 20          	add    $0x20,%rsp
  4006cd:	5b                   	pop    %rbx
  4006ce:	c3                   	retq
  4006cf:	0f 10 44 24 10       	movups 0x10(%rsp),%xmm0
  4006d4:	48 c7 44 24 10 00 00 	movq   $0x0,0x10(%rsp)
  4006dd:	c7 43 04 02 00 00 00 	movl   $0x2,0x4(%rbx)
  4006e4:	0f 11 43 08          	movups %xmm0,0x8(%rbx)
  4006e8:	eb d2                	jmp    4006bc <test1()+0x5c>
  4006ea:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
