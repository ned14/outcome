  400680:	53                   	push   %rbx
  400681:	48 83 ec 20          	sub    $0x20,%rsp
  400685:	48 89 fb             	mov    %rdi,%rbx
  400688:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  400660:	48 89 f8             	mov    %rdi,%rax
  400663:	c7 47 04 02 00 00 00 	movl   $0x2,0x4(%rdi)
  40066a:	48 c7 47 08 48 09 40 	movq   $0x400948,0x8(%rdi)
  400672:	48 c7 47 10 21 00 00 	movq   $0x21,0x10(%rdi)
  40067a:	c3                   	retq
  40067b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
  400692:	0f b7 44 24 0c       	movzwl 0xc(%rsp),%eax
  400697:	a8 01                	test   $0x1,%al
  400699:	74 4b                	je     4006e6 <test1()+0x66>
  40069b:	c7 05 97 19 20 00 00 	movl   $0x0,0x201997(%rip)        # 60203c <foo>
  4006a5:	8b 44 24 08          	mov    0x8(%rsp),%eax
  4006a9:	89 03                	mov    %eax,(%rbx)
  4006ab:	c7 43 04 01 00 00 00 	movl   $0x1,0x4(%rbx)
  4006b2:	0f 57 c0             	xorps  %xmm0,%xmm0
  4006b5:	0f 11 43 08          	movups %xmm0,0x8(%rbx)
  4006b9:	48 8b 7c 24 10       	mov    0x10(%rsp),%rdi
  4006be:	48 85 ff             	test   %rdi,%rdi
  4006c1:	74 10                	je     4006d3 <test1()+0x53>
  4006c3:	48 8d 74 24 10       	lea    0x10(%rsp),%rsi
  4006c8:	48 8b 07             	mov    (%rdi),%rax
  4006cb:	ba 10 00 00 00       	mov    $0x10,%edx
  4006d0:	ff 50 38             	callq  *0x38(%rax)
  4006d3:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  400760:	c3                   	retq
  400761:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  40076b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
  4006dd:	48 89 d8             	mov    %rbx,%rax
  4006e0:	48 83 c4 20          	add    $0x20,%rsp
  4006e4:	5b                   	pop    %rbx
  4006e5:	c3                   	retq
  4006e6:	0f 10 44 24 10       	movups 0x10(%rsp),%xmm0
  4006eb:	48 c7 44 24 10 00 00 	movq   $0x0,0x10(%rsp)
  4006f4:	c7 43 04 02 00 00 00 	movl   $0x2,0x4(%rbx)
  4006fb:	0f 11 43 08          	movups %xmm0,0x8(%rbx)
  4006ff:	eb d2                	jmp    4006d3 <test1()+0x53>
  400701:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  40070b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
