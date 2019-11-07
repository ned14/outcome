  4007c0:	48 83 ec 18          	sub    $0x18,%rsp
  4007c4:	48 89 e7             	mov    %rsp,%rdi
  4007c7:	e8 34 f8 bf ff       	callq  0 <_init-0x400600>
  4007cc:	0f b7 44 24 04       	movzwl 0x4(%rsp),%eax
  4007d1:	89 c1                	mov    %eax,%ecx
  4007d3:	83 c9 08             	or     $0x8,%ecx
  4007d6:	83 f9 09             	cmp    $0x9,%ecx
  4007d9:	75 08                	jne    4007e3 <test1()+0x23>
  4007db:	8b 04 24             	mov    (%rsp),%eax
  4007de:	48 83 c4 18          	add    $0x18,%rsp
  4007e2:	c3                   	retq
  4007e3:	83 c0 fe             	add    $0xfffffffe,%eax
  4007e6:	66 c1 c0 0e          	rol    $0xe,%ax
  4007ea:	0f b7 c0             	movzwl %ax,%eax
  4007ed:	83 f8 07             	cmp    $0x7,%eax
  4007f0:	77 0a                	ja     4007fc <test1()+0x3c>
  4007f2:	bf 72 09 40 00       	mov    $0x400972,%edi
  400840:	55                   	push   %rbp
  400841:	41 56                	push   %r14
  400843:	53                   	push   %rbx
  400844:	48 81 ec 80 00 00 00 	sub    $0x80,%rsp
  40084b:	48 89 fb             	mov    %rdi,%rbx
  40084e:	49 89 e6             	mov    %rsp,%r14
  400851:	be 10 00 00 00       	mov    $0x10,%esi
  400856:	4c 89 f7             	mov    %r14,%rdi
  400670:	ff 25 c2 09 20 00    	jmpq   *0x2009c2(%rip)        # 601038 <backtrace@GLIBC_2.2.5>
  400676:	68 04 00 00 00       	pushq  $0x4
  40067b:	e9 a0 ff ff ff       	jmpq   400620 <.plt>
  40085e:	89 c5                	mov    %eax,%ebp
  400860:	48 8b 3d 19 08 20 00 	mov    0x200819(%rip),%rdi        # 601080 <stderr@@GLIBC_2.2.5>
  400867:	be 8b 09 40 00       	mov    $0x40098b,%esi
  40086c:	31 c0                	xor    %eax,%eax
  40086e:	48 89 da             	mov    %rbx,%rdx
  400660:	ff 25 ca 09 20 00    	jmpq   *0x2009ca(%rip)        # 601030 <fprintf@GLIBC_2.2.5>
  400666:	68 03 00 00 00       	pushq  $0x3
  40066b:	e9 b0 ff ff ff       	jmpq   400620 <.plt>
  400876:	4c 89 f7             	mov    %r14,%rdi
  400879:	89 ee                	mov    %ebp,%esi
  400680:	ff 25 ba 09 20 00    	jmpq   *0x2009ba(%rip)        # 601040 <backtrace_symbols@GLIBC_2.2.5>
  400686:	68 05 00 00 00       	pushq  $0x5
  40068b:	e9 90 ff ff ff       	jmpq   400620 <.plt>
  400880:	49 89 c6             	mov    %rax,%r14
  400883:	4d 85 f6             	test   %r14,%r14
  400886:	74 40                	je     4008c8 <outcome_v2_e34bec51::detail::do_fatal_exit(char const*)+0x88>
  400888:	85 ed                	test   %ebp,%ebp
  40088a:	74 34                	je     4008c0 <outcome_v2_e34bec51::detail::do_fatal_exit(char const*)+0x80>
  40088c:	48 63 ed             	movslq %ebp,%rbp
  40088f:	31 db                	xor    %ebx,%ebx
  400891:	66 66 66 66 66 66 2e 	data16 data16 data16 data16 data16 nopw %cs:0x0(%rax,%rax,1)
  4008a0:	48 8b 3d d9 07 20 00 	mov    0x2007d9(%rip),%rdi        # 601080 <stderr@@GLIBC_2.2.5>
  4008a7:	49 8b 14 de          	mov    (%r14,%rbx,8),%rdx
  4008ab:	be c8 09 40 00       	mov    $0x4009c8,%esi
  4008b0:	31 c0                	xor    %eax,%eax
  4008b2:	e8 a9 fd ff ff       	callq  400660 <fprintf@plt>
  4008b7:	48 83 c3 01          	add    $0x1,%rbx
  4008bb:	48 39 eb             	cmp    %rbp,%rbx
  4008be:	72 e0                	jb     4008a0 <outcome_v2_e34bec51::detail::do_fatal_exit(char const*)+0x60>
  4008c0:	4c 89 f7             	mov    %r14,%rdi
  400650:	ff 25 d2 09 20 00    	jmpq   *0x2009d2(%rip)        # 601028 <free@GLIBC_2.2.5>
  400656:	68 02 00 00 00       	pushq  $0x2
  40065b:	e9 c0 ff ff ff       	jmpq   400620 <.plt>
  400630:	ff 25 e2 09 20 00    	jmpq   *0x2009e2(%rip)        # 601018 <abort@GLIBC_2.2.5>
  400636:	68 00 00 00 00       	pushq  $0x0
  40063b:	e9 e0 ff ff ff       	jmpq   400620 <.plt>
  4008cd:	0f 1f 00             	nopl   (%rax)
  4007fc:	bf 54 09 40 00       	mov    $0x400954,%edi
  400840:	55                   	push   %rbp
  400841:	41 56                	push   %r14
  400843:	53                   	push   %rbx
  400844:	48 81 ec 80 00 00 00 	sub    $0x80,%rsp
  40084b:	48 89 fb             	mov    %rdi,%rbx
  40084e:	49 89 e6             	mov    %rsp,%r14
  400851:	be 10 00 00 00       	mov    $0x10,%esi
  400856:	4c 89 f7             	mov    %r14,%rdi
  400670:	ff 25 c2 09 20 00    	jmpq   *0x2009c2(%rip)        # 601038 <backtrace@GLIBC_2.2.5>
  400676:	68 04 00 00 00       	pushq  $0x4
  40067b:	e9 a0 ff ff ff       	jmpq   400620 <.plt>
  40085e:	89 c5                	mov    %eax,%ebp
  400860:	48 8b 3d 19 08 20 00 	mov    0x200819(%rip),%rdi        # 601080 <stderr@@GLIBC_2.2.5>
  400867:	be 8b 09 40 00       	mov    $0x40098b,%esi
  40086c:	31 c0                	xor    %eax,%eax
  40086e:	48 89 da             	mov    %rbx,%rdx
  400660:	ff 25 ca 09 20 00    	jmpq   *0x2009ca(%rip)        # 601030 <fprintf@GLIBC_2.2.5>
  400666:	68 03 00 00 00       	pushq  $0x3
  40066b:	e9 b0 ff ff ff       	jmpq   400620 <.plt>
  400876:	4c 89 f7             	mov    %r14,%rdi
  400879:	89 ee                	mov    %ebp,%esi
  400680:	ff 25 ba 09 20 00    	jmpq   *0x2009ba(%rip)        # 601040 <backtrace_symbols@GLIBC_2.2.5>
  400686:	68 05 00 00 00       	pushq  $0x5
  40068b:	e9 90 ff ff ff       	jmpq   400620 <.plt>
  400880:	49 89 c6             	mov    %rax,%r14
  400883:	4d 85 f6             	test   %r14,%r14
  400886:	74 40                	je     4008c8 <outcome_v2_e34bec51::detail::do_fatal_exit(char const*)+0x88>
  400888:	85 ed                	test   %ebp,%ebp
  40088a:	74 34                	je     4008c0 <outcome_v2_e34bec51::detail::do_fatal_exit(char const*)+0x80>
  40088c:	48 63 ed             	movslq %ebp,%rbp
  40088f:	31 db                	xor    %ebx,%ebx
  400891:	66 66 66 66 66 66 2e 	data16 data16 data16 data16 data16 nopw %cs:0x0(%rax,%rax,1)
  4008a0:	48 8b 3d d9 07 20 00 	mov    0x2007d9(%rip),%rdi        # 601080 <stderr@@GLIBC_2.2.5>
  4008a7:	49 8b 14 de          	mov    (%r14,%rbx,8),%rdx
  4008ab:	be c8 09 40 00       	mov    $0x4009c8,%esi
  4008b0:	31 c0                	xor    %eax,%eax
  4008b2:	e8 a9 fd ff ff       	callq  400660 <fprintf@plt>
  4008b7:	48 83 c3 01          	add    $0x1,%rbx
  4008bb:	48 39 eb             	cmp    %rbp,%rbx
  4008be:	72 e0                	jb     4008a0 <outcome_v2_e34bec51::detail::do_fatal_exit(char const*)+0x60>
  4008c0:	4c 89 f7             	mov    %r14,%rdi
  400650:	ff 25 d2 09 20 00    	jmpq   *0x2009d2(%rip)        # 601028 <free@GLIBC_2.2.5>
  400656:	68 02 00 00 00       	pushq  $0x2
  40065b:	e9 c0 ff ff ff       	jmpq   400620 <.plt>
  400630:	ff 25 e2 09 20 00    	jmpq   *0x2009e2(%rip)        # 601018 <abort@GLIBC_2.2.5>
  400636:	68 00 00 00 00       	pushq  $0x0
  40063b:	e9 e0 ff ff ff       	jmpq   400620 <.plt>
  4008cd:	0f 1f 00             	nopl   (%rax)
  400806:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
