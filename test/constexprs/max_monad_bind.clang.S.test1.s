  400630:	53                   	push   %rbx
  400631:	48 83 ec 20          	sub    $0x20,%rsp
  400635:	48 89 fb             	mov    %rdi,%rbx
  400638:	48 89 e7             	mov    %rsp,%rdi
  40063b:	e8 c0 f9 bf ff       	callq  0 <_init-0x4004d0>
  400640:	8a 44 24 18          	mov    0x18(%rsp),%al
  400644:	3c 03                	cmp    $0x3,%al
  400646:	74 14                	je     40065c <test1()+0x2c>
  400648:	3c 02                	cmp    $0x2,%al
  40064a:	74 2d                	je     400679 <test1()+0x49>
  40064c:	3c 01                	cmp    $0x1,%al
  40064e:	75 44                	jne    400694 <test1()+0x64>
  400650:	6b 04 24 03          	imul   $0x3,(%rsp),%eax
  400654:	89 03                	mov    %eax,(%rbx)
  400656:	c6 43 18 01          	movb   $0x1,0x18(%rbx)
  40065a:	eb 31                	jmp    40068d <test1()+0x5d>
  40065c:	48 8b 04 24          	mov    (%rsp),%rax
  400660:	48 89 03             	mov    %rax,(%rbx)
  400663:	48 c7 04 24 00 00 00 	movq   $0x0,(%rsp)
  40066b:	c6 43 18 03          	movb   $0x3,0x18(%rbx)
  40066f:	48 89 e7             	mov    %rsp,%rdi
  400520:	ff 25 02 0b 20 00    	jmpq   *0x200b02(%rip)        # 601028 <_GLOBAL_OFFSET_TABLE_+0x28>
  400526:	68 02 00 00 00       	pushq  $0x2
  40052b:	e9 c0 ff ff ff       	jmpq   4004f0 <_init+0x20>
  400677:	eb 14                	jmp    40068d <test1()+0x5d>
  400679:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  40067e:	48 89 43 10          	mov    %rax,0x10(%rbx)
  400682:	0f 10 04 24          	movups (%rsp),%xmm0
  400686:	0f 11 03             	movups %xmm0,(%rbx)
  400689:	c6 43 18 02          	movb   $0x2,0x18(%rbx)
  40068d:	c6 44 24 18 00       	movb   $0x0,0x18(%rsp)
  400692:	eb 0a                	jmp    40069e <test1()+0x6e>
  400694:	0f 57 c0             	xorps  %xmm0,%xmm0
  400697:	0f 11 43 10          	movups %xmm0,0x10(%rbx)
  40069b:	0f 11 03             	movups %xmm0,(%rbx)
  40069e:	48 89 d8             	mov    %rbx,%rax
  4006a1:	48 83 c4 20          	add    $0x20,%rsp
  4006a5:	5b                   	pop    %rbx
  4006a6:	c3                   	retq
  4006a7:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
