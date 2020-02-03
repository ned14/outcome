  400730:	41 56                	push   %r14
  400732:	53                   	push   %rbx
  400733:	48 83 ec 18          	sub    $0x18,%rsp
  400737:	48 89 fb             	mov    %rdi,%rbx
  40073a:	48 89 e7             	mov    %rsp,%rdi
  400710:	53                   	push   %rbx
  400711:	48 89 fb             	mov    %rdi,%rbx
  4005b0:	ff 25 62 0a 20 00    	jmpq   *0x200a62(%rip)        # 601018 <std::_V2::generic_category()@GLIBCXX_3.4.21>
  4005b6:	68 00 00 00 00       	pushq  $0x0
  4005bb:	e9 e0 ff ff ff       	jmpq   4005a0 <.plt>
  400719:	48 b9 12 00 00 00 21 	movabs $0x2100000012,%rcx
  400723:	48 89 4b 04          	mov    %rcx,0x4(%rbx)
  400727:	48 89 43 10          	mov    %rax,0x10(%rbx)
  40072b:	48 89 d8             	mov    %rbx,%rax
  40072e:	5b                   	pop    %rbx
  40072f:	c3                   	retq
  400742:	0f b7 44 24 04       	movzwl 0x4(%rsp),%eax
  400747:	a8 01                	test   $0x1,%al
  400749:	74 33                	je     40077e <test1()+0x4e>
  40074b:	c7 05 03 09 20 00 00 	movl   $0x0,0x200903(%rip)        # 601058 <foo>
  400755:	8b 04 24             	mov    (%rsp),%eax
  400758:	89 03                	mov    %eax,(%rbx)
  40075a:	48 c7 43 04 01 00 00 	movq   $0x1,0x4(%rbx)
  4005c0:	ff 25 5a 0a 20 00    	jmpq   *0x200a5a(%rip)        # 601020 <std::_V2::system_category()@GLIBCXX_3.4.21>
  4005c6:	68 01 00 00 00       	pushq  $0x1
  4005cb:	e9 d0 ff ff ff       	jmpq   4005a0 <.plt>
  400767:	48 89 43 10          	mov    %rax,0x10(%rbx)
  40076b:	48 89 e7             	mov    %rsp,%rdi
  4007f0:	c3                   	retq
  4007f1:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  4007fb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
  400773:	48 89 d8             	mov    %rbx,%rax
  400776:	48 83 c4 18          	add    $0x18,%rsp
  40077a:	5b                   	pop    %rbx
  40077b:	41 5e                	pop    %r14
  40077d:	c3                   	retq
  40077e:	8b 44 24 08          	mov    0x8(%rsp),%eax
  400782:	4c 8b 74 24 10       	mov    0x10(%rsp),%r14
  400787:	c7 43 04 02 00 00 00 	movl   $0x2,0x4(%rbx)
  40078e:	89 43 08             	mov    %eax,0x8(%rbx)
  400791:	4c 89 73 10          	mov    %r14,0x10(%rbx)
  4005b0:	ff 25 62 0a 20 00    	jmpq   *0x200a62(%rip)        # 601018 <std::_V2::generic_category()@GLIBCXX_3.4.21>
  4005b6:	68 00 00 00 00       	pushq  $0x0
  4005bb:	e9 e0 ff ff ff       	jmpq   4005a0 <.plt>
  40079a:	49 39 c6             	cmp    %rax,%r14
  40079d:	74 0a                	je     4007a9 <test1()+0x79>
  4005c0:	ff 25 5a 0a 20 00    	jmpq   *0x200a5a(%rip)        # 601020 <std::_V2::system_category()@GLIBCXX_3.4.21>
  4005c6:	68 01 00 00 00       	pushq  $0x1
  4005cb:	e9 d0 ff ff ff       	jmpq   4005a0 <.plt>
  4007a4:	49 39 c6             	cmp    %rax,%r14
  4007a7:	75 c2                	jne    40076b <test1()+0x3b>
  4007a9:	66 c7 43 04 12 00    	movw   $0x12,0x4(%rbx)
  4007af:	eb ba                	jmp    40076b <test1()+0x3b>
  4007b1:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  4007bb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
