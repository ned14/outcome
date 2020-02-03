  400830:	48 83 ec 18          	sub    $0x18,%rsp
  400834:	48 89 e7             	mov    %rsp,%rdi
  400700:	ff 25 4a 09 20 00    	jmpq   *0x20094a(%rip)        # 601050 <unknown()>
  400706:	68 07 00 00 00       	pushq  $0x7
  40070b:	e9 70 ff ff ff       	jmpq   400680 <.plt>
  40083c:	0f b7 44 24 04       	movzwl 0x4(%rsp),%eax
  400841:	a8 01                	test   $0x1,%al
  400843:	74 08                	je     40084d <test1()+0x1d>
  400845:	8b 04 24             	mov    (%rsp),%eax
  400848:	48 83 c4 18          	add    $0x18,%rsp
  40084c:	c3                   	retq
  40084d:	a8 02                	test   $0x2,%al
  40084f:	75 0a                	jne    40085b <test1()+0x2b>
  400851:	bf b4 09 40 00       	mov    $0x4009b4,%edi
  4008a0:	55                   	push   %rbp
  4008a1:	41 56                	push   %r14
  4008a3:	53                   	push   %rbx
  4008a4:	48 81 ec 80 00 00 00 	sub    $0x80,%rsp
  4008ab:	48 89 fb             	mov    %rdi,%rbx
  4008ae:	49 89 e6             	mov    %rsp,%r14
  4008b1:	4c 89 f7             	mov    %r14,%rdi
  4008b4:	be 10 00 00 00       	mov    $0x10,%esi
  4006d0:	ff 25 62 09 20 00    	jmpq   *0x200962(%rip)        # 601038 <backtrace@GLIBC_2.2.5>
  4006d6:	68 04 00 00 00       	pushq  $0x4
  4006db:	e9 a0 ff ff ff       	jmpq   400680 <.plt>
  4008be:	89 c5                	mov    %eax,%ebp
  4008c0:	48 8b 3d b9 07 20 00 	mov    0x2007b9(%rip),%rdi        # 601080 <stderr@@GLIBC_2.2.5>
  4008c7:	be eb 09 40 00       	mov    $0x4009eb,%esi
  4008cc:	48 89 da             	mov    %rbx,%rdx
  4008cf:	31 c0                	xor    %eax,%eax
  4006c0:	ff 25 6a 09 20 00    	jmpq   *0x20096a(%rip)        # 601030 <fprintf@GLIBC_2.2.5>
  4006c6:	68 03 00 00 00       	pushq  $0x3
  4006cb:	e9 b0 ff ff ff       	jmpq   400680 <.plt>
  4008d6:	4c 89 f7             	mov    %r14,%rdi
  4008d9:	89 ee                	mov    %ebp,%esi
  4006e0:	ff 25 5a 09 20 00    	jmpq   *0x20095a(%rip)        # 601040 <backtrace_symbols@GLIBC_2.2.5>
  4006e6:	68 05 00 00 00       	pushq  $0x5
  4006eb:	e9 90 ff ff ff       	jmpq   400680 <.plt>
  4008e0:	48 85 c0             	test   %rax,%rax
  4008e3:	74 43                	je     400928 <outcome_v2_3f877000::detail::do_fatal_exit(char const*)+0x88>
  4008e5:	49 89 c6             	mov    %rax,%r14
  4008e8:	85 ed                	test   %ebp,%ebp
  4008ea:	74 34                	je     400920 <outcome_v2_3f877000::detail::do_fatal_exit(char const*)+0x80>
  4008ec:	48 63 ed             	movslq %ebp,%rbp
  4008ef:	31 db                	xor    %ebx,%ebx
  4008f1:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  4008fb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
  400900:	48 8b 3d 79 07 20 00 	mov    0x200779(%rip),%rdi        # 601080 <stderr@@GLIBC_2.2.5>
  400907:	49 8b 14 de          	mov    (%r14,%rbx,8),%rdx
  40090b:	be 28 0a 40 00       	mov    $0x400a28,%esi
  400910:	31 c0                	xor    %eax,%eax
  400912:	e8 a9 fd ff ff       	callq  4006c0 <fprintf@plt>
  400917:	48 83 c3 01          	add    $0x1,%rbx
  40091b:	48 39 eb             	cmp    %rbp,%rbx
  40091e:	72 e0                	jb     400900 <outcome_v2_3f877000::detail::do_fatal_exit(char const*)+0x60>
  400920:	4c 89 f7             	mov    %r14,%rdi
  4006b0:	ff 25 72 09 20 00    	jmpq   *0x200972(%rip)        # 601028 <free@GLIBC_2.2.5>
  4006b6:	68 02 00 00 00       	pushq  $0x2
  4006bb:	e9 c0 ff ff ff       	jmpq   400680 <.plt>
  400690:	ff 25 82 09 20 00    	jmpq   *0x200982(%rip)        # 601018 <abort@GLIBC_2.2.5>
  400696:	68 00 00 00 00       	pushq  $0x0
  40069b:	e9 e0 ff ff ff       	jmpq   400680 <.plt>
  40092d:	0f 1f 00             	nopl   (%rax)
  40085b:	bf d2 09 40 00       	mov    $0x4009d2,%edi
  4008a0:	55                   	push   %rbp
  4008a1:	41 56                	push   %r14
  4008a3:	53                   	push   %rbx
  4008a4:	48 81 ec 80 00 00 00 	sub    $0x80,%rsp
  4008ab:	48 89 fb             	mov    %rdi,%rbx
  4008ae:	49 89 e6             	mov    %rsp,%r14
  4008b1:	4c 89 f7             	mov    %r14,%rdi
  4008b4:	be 10 00 00 00       	mov    $0x10,%esi
  4006d0:	ff 25 62 09 20 00    	jmpq   *0x200962(%rip)        # 601038 <backtrace@GLIBC_2.2.5>
  4006d6:	68 04 00 00 00       	pushq  $0x4
  4006db:	e9 a0 ff ff ff       	jmpq   400680 <.plt>
  4008be:	89 c5                	mov    %eax,%ebp
  4008c0:	48 8b 3d b9 07 20 00 	mov    0x2007b9(%rip),%rdi        # 601080 <stderr@@GLIBC_2.2.5>
  4008c7:	be eb 09 40 00       	mov    $0x4009eb,%esi
  4008cc:	48 89 da             	mov    %rbx,%rdx
  4008cf:	31 c0                	xor    %eax,%eax
  4006c0:	ff 25 6a 09 20 00    	jmpq   *0x20096a(%rip)        # 601030 <fprintf@GLIBC_2.2.5>
  4006c6:	68 03 00 00 00       	pushq  $0x3
  4006cb:	e9 b0 ff ff ff       	jmpq   400680 <.plt>
  4008d6:	4c 89 f7             	mov    %r14,%rdi
  4008d9:	89 ee                	mov    %ebp,%esi
  4006e0:	ff 25 5a 09 20 00    	jmpq   *0x20095a(%rip)        # 601040 <backtrace_symbols@GLIBC_2.2.5>
  4006e6:	68 05 00 00 00       	pushq  $0x5
  4006eb:	e9 90 ff ff ff       	jmpq   400680 <.plt>
  4008e0:	48 85 c0             	test   %rax,%rax
  4008e3:	74 43                	je     400928 <outcome_v2_3f877000::detail::do_fatal_exit(char const*)+0x88>
  4008e5:	49 89 c6             	mov    %rax,%r14
  4008e8:	85 ed                	test   %ebp,%ebp
  4008ea:	74 34                	je     400920 <outcome_v2_3f877000::detail::do_fatal_exit(char const*)+0x80>
  4008ec:	48 63 ed             	movslq %ebp,%rbp
  4008ef:	31 db                	xor    %ebx,%ebx
  4008f1:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  4008fb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
  400900:	48 8b 3d 79 07 20 00 	mov    0x200779(%rip),%rdi        # 601080 <stderr@@GLIBC_2.2.5>
  400907:	49 8b 14 de          	mov    (%r14,%rbx,8),%rdx
  40090b:	be 28 0a 40 00       	mov    $0x400a28,%esi
  400910:	31 c0                	xor    %eax,%eax
  400912:	e8 a9 fd ff ff       	callq  4006c0 <fprintf@plt>
  400917:	48 83 c3 01          	add    $0x1,%rbx
  40091b:	48 39 eb             	cmp    %rbp,%rbx
  40091e:	72 e0                	jb     400900 <outcome_v2_3f877000::detail::do_fatal_exit(char const*)+0x60>
  400920:	4c 89 f7             	mov    %r14,%rdi
  4006b0:	ff 25 72 09 20 00    	jmpq   *0x200972(%rip)        # 601028 <free@GLIBC_2.2.5>
  4006b6:	68 02 00 00 00       	pushq  $0x2
  4006bb:	e9 c0 ff ff ff       	jmpq   400680 <.plt>
  400690:	ff 25 82 09 20 00    	jmpq   *0x200982(%rip)        # 601018 <abort@GLIBC_2.2.5>
  400696:	68 00 00 00 00       	pushq  $0x0
  40069b:	e9 e0 ff ff ff       	jmpq   400680 <.plt>
  40092d:	0f 1f 00             	nopl   (%rax)
  400865:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  40086f:	90                   	nop
