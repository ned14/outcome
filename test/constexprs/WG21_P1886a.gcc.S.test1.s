 880:	41 54                	push   %r12
 882:	49 89 fc             	mov    %rdi,%r12
 885:	53                   	push   %rbx
 886:	48 83 ec 28          	sub    $0x28,%rsp
 88a:	48 89 e7             	mov    %rsp,%rdi
 850:	41 54                	push   %r12
 852:	49 89 fc             	mov    %rdi,%r12
 6c0:	ff 25 ea 08 20 00    	jmpq   *0x2008ea(%rip)        # 200fb0 <std::_V2::generic_category()@GLIBCXX_3.4.21>
 6c6:	68 00 00 00 00       	pushq  $0x0
 6cb:	e9 e0 ff ff ff       	jmpq   6b0 <.plt>
 85a:	49 89 44 24 10       	mov    %rax,0x10(%r12)
 85f:	48 b8 12 00 00 00 21 	movabs $0x2100000012,%rax
 869:	49 89 44 24 04       	mov    %rax,0x4(%r12)
 86e:	4c 89 e0             	mov    %r12,%rax
 871:	41 5c                	pop    %r12
 873:	c3                   	retq
 874:	66 90                	xchg   %ax,%ax
 876:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
 892:	f6 44 24 04 01       	testb  $0x1,0x4(%rsp)
 897:	74 3f                	je     8d8 <test1()+0x58>
 899:	41 c7 44 24 04 01 00 	movl   $0x1,0x4(%r12)
 8a2:	8b 04 24             	mov    (%rsp),%eax
 8a5:	41 c7 44 24 08 00 00 	movl   $0x0,0x8(%r12)
 8ae:	41 89 04 24          	mov    %eax,(%r12)
 8b2:	c7 05 58 07 20 00 00 	movl   $0x0,0x200758(%rip)        # 201014 <foo>
 6d0:	ff 25 e2 08 20 00    	jmpq   *0x2008e2(%rip)        # 200fb8 <std::_V2::system_category()@GLIBCXX_3.4.21>
 6d6:	68 01 00 00 00       	pushq  $0x1
 6db:	e9 d0 ff ff ff       	jmpq   6b0 <.plt>
 8c1:	49 89 44 24 10       	mov    %rax,0x10(%r12)
 8c6:	48 83 c4 28          	add    $0x28,%rsp
 8ca:	4c 89 e0             	mov    %r12,%rax
 8cd:	5b                   	pop    %rbx
 8ce:	41 5c                	pop    %r12
 8d0:	c3                   	retq
 8d1:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
 8d8:	48 8b 5c 24 10       	mov    0x10(%rsp),%rbx
 8dd:	8b 44 24 08          	mov    0x8(%rsp),%eax
 8e1:	41 c7 44 24 04 02 00 	movl   $0x2,0x4(%r12)
 8ea:	41 89 44 24 08       	mov    %eax,0x8(%r12)
 8ef:	49 89 5c 24 10       	mov    %rbx,0x10(%r12)
 6c0:	ff 25 ea 08 20 00    	jmpq   *0x2008ea(%rip)        # 200fb0 <std::_V2::generic_category()@GLIBCXX_3.4.21>
 6c6:	68 00 00 00 00       	pushq  $0x0
 6cb:	e9 e0 ff ff ff       	jmpq   6b0 <.plt>
 8f9:	48 39 c3             	cmp    %rax,%rbx
 8fc:	74 0a                	je     908 <test1()+0x88>
 6d0:	ff 25 e2 08 20 00    	jmpq   *0x2008e2(%rip)        # 200fb8 <std::_V2::system_category()@GLIBCXX_3.4.21>
 6d6:	68 01 00 00 00       	pushq  $0x1
 6db:	e9 d0 ff ff ff       	jmpq   6b0 <.plt>
 903:	48 39 c3             	cmp    %rax,%rbx
 906:	75 be                	jne    8c6 <test1()+0x46>
 908:	b8 12 00 00 00       	mov    $0x12,%eax
 90d:	66 41 89 44 24 04    	mov    %ax,0x4(%r12)
 913:	eb b1                	jmp    8c6 <test1()+0x46>
 915:	90                   	nop
 916:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
