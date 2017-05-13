  400660:	53                   	push   %rbx
  400661:	48 89 fb             	mov    %rdi,%rbx
  400664:	48 83 ec 20          	sub    $0x20,%rsp
  400668:	48 89 e7             	mov    %rsp,%rdi
  40066b:	e8 90 f9 bf ff       	callq  0 <_init-0x4004d8>
  400670:	0f b6 44 24 18       	movzbl 0x18(%rsp),%eax
  400675:	3c 01                	cmp    $0x1,%al
  400677:	74 3f                	je     4006b8 <test1()+0x58>
  400679:	3c 02                	cmp    $0x2,%al
  40067b:	74 53                	je     4006d0 <test1()+0x70>
  40067d:	3c 03                	cmp    $0x3,%al
  40067f:	74 0f                	je     400690 <test1()+0x30>
  400681:	c6 43 18 00          	movb   $0x0,0x18(%rbx)
  400685:	48 83 c4 20          	add    $0x20,%rsp
  400689:	48 89 d8             	mov    %rbx,%rax
  40068c:	5b                   	pop    %rbx
  40068d:	c3                   	retq
  40068e:	66 90                	xchg   %ax,%ax
  400690:	48 8b 04 24          	mov    (%rsp),%rax
  400694:	c6 43 18 03          	movb   $0x3,0x18(%rbx)
  400698:	48 89 e7             	mov    %rsp,%rdi
  40069b:	48 c7 04 24 00 00 00 	movq   $0x0,(%rsp)
  4006a3:	48 89 03             	mov    %rax,(%rbx)
  400530:	ff 25 f2 0a 20 00    	jmpq   *0x200af2(%rip)        # 601028 <_GLOBAL_OFFSET_TABLE_+0x28>
  400536:	68 02 00 00 00       	pushq  $0x2
  40053b:	e9 c0 ff ff ff       	jmpq   400500 <_init+0x28>
  4006ab:	48 83 c4 20          	add    $0x20,%rsp
  4006af:	48 89 d8             	mov    %rbx,%rax
  4006b2:	5b                   	pop    %rbx
  4006b3:	c3                   	retq
  4006b4:	0f 1f 40 00          	nopl   0x0(%rax)
  4006b8:	8b 04 24             	mov    (%rsp),%eax
  4006bb:	c6 43 18 01          	movb   $0x1,0x18(%rbx)
  4006bf:	8d 04 40             	lea    (%rax,%rax,2),%eax
  4006c2:	89 03                	mov    %eax,(%rbx)
  4006c4:	48 83 c4 20          	add    $0x20,%rsp
  4006c8:	48 89 d8             	mov    %rbx,%rax
  4006cb:	5b                   	pop    %rbx
  4006cc:	c3                   	retq
  4006cd:	0f 1f 00             	nopl   (%rax)
  4006d0:	48 8b 04 24          	mov    (%rsp),%rax
  4006d4:	c6 43 18 02          	movb   $0x2,0x18(%rbx)
  4006d8:	48 89 03             	mov    %rax,(%rbx)
  4006db:	48 8b 44 24 08       	mov    0x8(%rsp),%rax
  4006e0:	48 89 43 08          	mov    %rax,0x8(%rbx)
  4006e4:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  4006e9:	48 89 43 10          	mov    %rax,0x10(%rbx)
  4006ed:	48 83 c4 20          	add    $0x20,%rsp
  4006f1:	48 89 d8             	mov    %rbx,%rax
  4006f4:	5b                   	pop    %rbx
  4006f5:	c3                   	retq
  4006f6:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
