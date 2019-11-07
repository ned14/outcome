 9c0:	48 83 ec 28          	sub    $0x28,%rsp
 9c4:	48 89 e7             	mov    %rsp,%rdi
 840:	ff 25 82 17 20 00    	jmpq   *0x201782(%rip)        # 201fc8 <unknown()>
 846:	68 07 00 00 00       	pushq  $0x7
 84b:	e9 70 ff ff ff       	jmpq   7c0 <.plt>
 9cc:	0f b7 54 24 04       	movzwl 0x4(%rsp),%edx
 9d1:	8b 04 24             	mov    (%rsp),%eax
 9d4:	89 d1                	mov    %edx,%ecx
 9d6:	83 e1 f7             	and    $0xfffffff7,%ecx
 9d9:	66 83 f9 01          	cmp    $0x1,%cx
 9dd:	75 05                	jne    9e4 <test1()+0x24>
 9df:	48 83 c4 28          	add    $0x28,%rsp
 9e3:	c3                   	retq
 9e4:	66 83 fa 1e          	cmp    $0x1e,%dx
 9e8:	76 0c                	jbe    9f6 <test1()+0x36>
 9ea:	48 8d 3d 9d 01 00 00 	lea    0x19d(%rip),%rdi        # b8e <_IO_stdin_used+0x4e>
 a20:	41 55                	push   %r13
 a22:	41 54                	push   %r12
 a24:	be 10 00 00 00       	mov    $0x10,%esi
 a29:	55                   	push   %rbp
 a2a:	53                   	push   %rbx
 a2b:	49 89 fc             	mov    %rdi,%r12
 a2e:	48 81 ec 88 00 00 00 	sub    $0x88,%rsp
 a35:	48 89 e5             	mov    %rsp,%rbp
 a38:	48 89 ef             	mov    %rbp,%rdi
 800:	ff 25 a2 17 20 00    	jmpq   *0x2017a2(%rip)        # 201fa8 <backtrace@GLIBC_2.2.5>
 806:	68 03 00 00 00       	pushq  $0x3
 80b:	e9 b0 ff ff ff       	jmpq   7c0 <.plt>
 a40:	48 8b 3d d9 15 20 00 	mov    0x2015d9(%rip),%rdi        # 202020 <stderr@@GLIBC_2.2.5>
 a47:	48 8d 15 fa 00 00 00 	lea    0xfa(%rip),%rdx        # b48 <_IO_stdin_used+0x8>
 a4e:	89 c3                	mov    %eax,%ebx
 a50:	4c 89 e1             	mov    %r12,%rcx
 a53:	be 01 00 00 00       	mov    $0x1,%esi
 a58:	31 c0                	xor    %eax,%eax
 830:	ff 25 8a 17 20 00    	jmpq   *0x20178a(%rip)        # 201fc0 <__fprintf_chk@GLIBC_2.3.4>
 836:	68 06 00 00 00       	pushq  $0x6
 83b:	e9 80 ff ff ff       	jmpq   7c0 <.plt>
 a5f:	89 de                	mov    %ebx,%esi
 a61:	48 89 ef             	mov    %rbp,%rdi
 810:	ff 25 9a 17 20 00    	jmpq   *0x20179a(%rip)        # 201fb0 <backtrace_symbols@GLIBC_2.2.5>
 816:	68 04 00 00 00       	pushq  $0x4
 81b:	e9 a0 ff ff ff       	jmpq   7c0 <.plt>
 a69:	48 85 c0             	test   %rax,%rax
 a6c:	74 4c                	je     aba <outcome_v2_e34bec51::detail::do_fatal_exit(char const*)+0x9a>
 a6e:	49 89 c5             	mov    %rax,%r13
 a71:	48 63 c3             	movslq %ebx,%rax
 a74:	48 85 c0             	test   %rax,%rax
 a77:	74 39                	je     ab2 <outcome_v2_e34bec51::detail::do_fatal_exit(char const*)+0x92>
 a79:	4d 8d 64 c5 00       	lea    0x0(%r13,%rax,8),%r12
 a7e:	48 8d 2d 03 01 00 00 	lea    0x103(%rip),%rbp        # b88 <_IO_stdin_used+0x48>
 a85:	4c 89 eb             	mov    %r13,%rbx
 a88:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
 a90:	48 8b 0b             	mov    (%rbx),%rcx
 a93:	48 8b 3d 86 15 20 00 	mov    0x201586(%rip),%rdi        # 202020 <stderr@@GLIBC_2.2.5>
 a9a:	31 c0                	xor    %eax,%eax
 a9c:	48 89 ea             	mov    %rbp,%rdx
 a9f:	be 01 00 00 00       	mov    $0x1,%esi
 aa4:	48 83 c3 08          	add    $0x8,%rbx
 aa8:	e8 83 fd ff ff       	callq  830 <__fprintf_chk@plt>
 aad:	4c 39 e3             	cmp    %r12,%rbx
 ab0:	75 de                	jne    a90 <outcome_v2_e34bec51::detail::do_fatal_exit(char const*)+0x70>
 ab2:	4c 89 ef             	mov    %r13,%rdi
 7f0:	ff 25 aa 17 20 00    	jmpq   *0x2017aa(%rip)        # 201fa0 <free@GLIBC_2.2.5>
 7f6:	68 02 00 00 00       	pushq  $0x2
 7fb:	e9 c0 ff ff ff       	jmpq   7c0 <.plt>
 7d0:	ff 25 ba 17 20 00    	jmpq   *0x2017ba(%rip)        # 201f90 <abort@GLIBC_2.2.5>
 7d6:	68 00 00 00 00       	pushq  $0x0
 7db:	e9 e0 ff ff ff       	jmpq   7c0 <.plt>
 abf:	90                   	nop
 9f6:	b8 44 44 44 44       	mov    $0x44444444,%eax
 9fb:	48 0f a3 d0          	bt     %rdx,%rax
 9ff:	73 e9                	jae    9ea <test1()+0x2a>
 a01:	48 8d 3d a4 01 00 00 	lea    0x1a4(%rip),%rdi        # bac <_IO_stdin_used+0x6c>
 a20:	41 55                	push   %r13
 a22:	41 54                	push   %r12
 a24:	be 10 00 00 00       	mov    $0x10,%esi
 a29:	55                   	push   %rbp
 a2a:	53                   	push   %rbx
 a2b:	49 89 fc             	mov    %rdi,%r12
 a2e:	48 81 ec 88 00 00 00 	sub    $0x88,%rsp
 a35:	48 89 e5             	mov    %rsp,%rbp
 a38:	48 89 ef             	mov    %rbp,%rdi
 800:	ff 25 a2 17 20 00    	jmpq   *0x2017a2(%rip)        # 201fa8 <backtrace@GLIBC_2.2.5>
 806:	68 03 00 00 00       	pushq  $0x3
 80b:	e9 b0 ff ff ff       	jmpq   7c0 <.plt>
 a40:	48 8b 3d d9 15 20 00 	mov    0x2015d9(%rip),%rdi        # 202020 <stderr@@GLIBC_2.2.5>
 a47:	48 8d 15 fa 00 00 00 	lea    0xfa(%rip),%rdx        # b48 <_IO_stdin_used+0x8>
 a4e:	89 c3                	mov    %eax,%ebx
 a50:	4c 89 e1             	mov    %r12,%rcx
 a53:	be 01 00 00 00       	mov    $0x1,%esi
 a58:	31 c0                	xor    %eax,%eax
 830:	ff 25 8a 17 20 00    	jmpq   *0x20178a(%rip)        # 201fc0 <__fprintf_chk@GLIBC_2.3.4>
 836:	68 06 00 00 00       	pushq  $0x6
 83b:	e9 80 ff ff ff       	jmpq   7c0 <.plt>
 a5f:	89 de                	mov    %ebx,%esi
 a61:	48 89 ef             	mov    %rbp,%rdi
 810:	ff 25 9a 17 20 00    	jmpq   *0x20179a(%rip)        # 201fb0 <backtrace_symbols@GLIBC_2.2.5>
 816:	68 04 00 00 00       	pushq  $0x4
 81b:	e9 a0 ff ff ff       	jmpq   7c0 <.plt>
 a69:	48 85 c0             	test   %rax,%rax
 a6c:	74 4c                	je     aba <outcome_v2_e34bec51::detail::do_fatal_exit(char const*)+0x9a>
 a6e:	49 89 c5             	mov    %rax,%r13
 a71:	48 63 c3             	movslq %ebx,%rax
 a74:	48 85 c0             	test   %rax,%rax
 a77:	74 39                	je     ab2 <outcome_v2_e34bec51::detail::do_fatal_exit(char const*)+0x92>
 a79:	4d 8d 64 c5 00       	lea    0x0(%r13,%rax,8),%r12
 a7e:	48 8d 2d 03 01 00 00 	lea    0x103(%rip),%rbp        # b88 <_IO_stdin_used+0x48>
 a85:	4c 89 eb             	mov    %r13,%rbx
 a88:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
 a90:	48 8b 0b             	mov    (%rbx),%rcx
 a93:	48 8b 3d 86 15 20 00 	mov    0x201586(%rip),%rdi        # 202020 <stderr@@GLIBC_2.2.5>
 a9a:	31 c0                	xor    %eax,%eax
 a9c:	48 89 ea             	mov    %rbp,%rdx
 a9f:	be 01 00 00 00       	mov    $0x1,%esi
 aa4:	48 83 c3 08          	add    $0x8,%rbx
 aa8:	e8 83 fd ff ff       	callq  830 <__fprintf_chk@plt>
 aad:	4c 39 e3             	cmp    %r12,%rbx
 ab0:	75 de                	jne    a90 <outcome_v2_e34bec51::detail::do_fatal_exit(char const*)+0x70>
 ab2:	4c 89 ef             	mov    %r13,%rdi
 7f0:	ff 25 aa 17 20 00    	jmpq   *0x2017aa(%rip)        # 201fa0 <free@GLIBC_2.2.5>
 7f6:	68 02 00 00 00       	pushq  $0x2
 7fb:	e9 c0 ff ff ff       	jmpq   7c0 <.plt>
 7d0:	ff 25 ba 17 20 00    	jmpq   *0x2017ba(%rip)        # 201f90 <abort@GLIBC_2.2.5>
 7d6:	68 00 00 00 00       	pushq  $0x0
 7db:	e9 e0 ff ff ff       	jmpq   7c0 <.plt>
 abf:	90                   	nop
 a0d:	0f 1f 00             	nopl   (%rax)
