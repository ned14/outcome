 9a0:	48 83 ec 28          	sub    $0x28,%rsp
 9a4:	48 89 e7             	mov    %rsp,%rdi
 840:	ff 25 82 17 20 00    	jmpq   *0x201782(%rip)        # 201fc8 <unknown()>
 846:	68 07 00 00 00       	pushq  $0x7
 84b:	e9 70 ff ff ff       	jmpq   7c0 <.plt>
 9ac:	0f b7 44 24 04       	movzwl 0x4(%rsp),%eax
 9b1:	a8 01                	test   $0x1,%al
 9b3:	75 13                	jne    9c8 <test1()+0x28>
 9b5:	a8 02                	test   $0x2,%al
 9b7:	74 17                	je     9d0 <test1()+0x30>
 9b9:	48 8d 3d 9e 01 00 00 	lea    0x19e(%rip),%rdi        # b5e <_IO_stdin_used+0x4e>
 9f0:	41 56                	push   %r14
 9f2:	be 10 00 00 00       	mov    $0x10,%esi
 9f7:	41 55                	push   %r13
 9f9:	41 54                	push   %r12
 9fb:	49 89 fc             	mov    %rdi,%r12
 9fe:	55                   	push   %rbp
 9ff:	53                   	push   %rbx
 a00:	48 83 c4 80          	add    $0xffffffffffffff80,%rsp
 a04:	49 89 e5             	mov    %rsp,%r13
 a07:	4c 89 ef             	mov    %r13,%rdi
 800:	ff 25 a2 17 20 00    	jmpq   *0x2017a2(%rip)        # 201fa8 <backtrace@GLIBC_2.2.5>
 806:	68 03 00 00 00       	pushq  $0x3
 80b:	e9 b0 ff ff ff       	jmpq   7c0 <.plt>
 a0f:	48 8b 3d 0a 16 20 00 	mov    0x20160a(%rip),%rdi        # 202020 <stderr@@GLIBC_2.2.5>
 a16:	4c 89 e1             	mov    %r12,%rcx
 a19:	be 01 00 00 00       	mov    $0x1,%esi
 a1e:	4c 63 f0             	movslq %eax,%r14
 a21:	48 8d 15 f0 00 00 00 	lea    0xf0(%rip),%rdx        # b18 <_IO_stdin_used+0x8>
 a28:	31 c0                	xor    %eax,%eax
 830:	ff 25 8a 17 20 00    	jmpq   *0x20178a(%rip)        # 201fc0 <__fprintf_chk@GLIBC_2.3.4>
 836:	68 06 00 00 00       	pushq  $0x6
 83b:	e9 80 ff ff ff       	jmpq   7c0 <.plt>
 a2f:	44 89 f6             	mov    %r14d,%esi
 a32:	4c 89 ef             	mov    %r13,%rdi
 810:	ff 25 9a 17 20 00    	jmpq   *0x20179a(%rip)        # 201fb0 <backtrace_symbols@GLIBC_2.2.5>
 816:	68 04 00 00 00       	pushq  $0x4
 81b:	e9 a0 ff ff ff       	jmpq   7c0 <.plt>
 a3a:	48 85 c0             	test   %rax,%rax
 a3d:	74 43                	je     a82 <outcome_v2_3f877000::detail::do_fatal_exit(char const*)+0x92>
 a3f:	49 89 c5             	mov    %rax,%r13
 a42:	4d 85 f6             	test   %r14,%r14
 a45:	74 33                	je     a7a <outcome_v2_3f877000::detail::do_fatal_exit(char const*)+0x8a>
 a47:	48 89 c3             	mov    %rax,%rbx
 a4a:	4e 8d 24 f0          	lea    (%rax,%r14,8),%r12
 a4e:	48 8d 2d 03 01 00 00 	lea    0x103(%rip),%rbp        # b58 <_IO_stdin_used+0x48>
 a55:	0f 1f 00             	nopl   (%rax)
 a58:	48 8b 0b             	mov    (%rbx),%rcx
 a5b:	48 8b 3d be 15 20 00 	mov    0x2015be(%rip),%rdi        # 202020 <stderr@@GLIBC_2.2.5>
 a62:	48 89 ea             	mov    %rbp,%rdx
 a65:	31 c0                	xor    %eax,%eax
 a67:	be 01 00 00 00       	mov    $0x1,%esi
 a6c:	48 83 c3 08          	add    $0x8,%rbx
 a70:	e8 bb fd ff ff       	callq  830 <__fprintf_chk@plt>
 a75:	4c 39 e3             	cmp    %r12,%rbx
 a78:	75 de                	jne    a58 <outcome_v2_3f877000::detail::do_fatal_exit(char const*)+0x68>
 a7a:	4c 89 ef             	mov    %r13,%rdi
 7f0:	ff 25 aa 17 20 00    	jmpq   *0x2017aa(%rip)        # 201fa0 <free@GLIBC_2.2.5>
 7f6:	68 02 00 00 00       	pushq  $0x2
 7fb:	e9 c0 ff ff ff       	jmpq   7c0 <.plt>
 7d0:	ff 25 ba 17 20 00    	jmpq   *0x2017ba(%rip)        # 201f90 <abort@GLIBC_2.2.5>
 7d6:	68 00 00 00 00       	pushq  $0x0
 7db:	e9 e0 ff ff ff       	jmpq   7c0 <.plt>
 a87:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
 9c5:	0f 1f 00             	nopl   (%rax)
 9c8:	8b 04 24             	mov    (%rsp),%eax
 9cb:	48 83 c4 28          	add    $0x28,%rsp
 9cf:	c3                   	retq
 9d0:	48 8d 3d a0 01 00 00 	lea    0x1a0(%rip),%rdi        # b77 <_IO_stdin_used+0x67>
 9f0:	41 56                	push   %r14
 9f2:	be 10 00 00 00       	mov    $0x10,%esi
 9f7:	41 55                	push   %r13
 9f9:	41 54                	push   %r12
 9fb:	49 89 fc             	mov    %rdi,%r12
 9fe:	55                   	push   %rbp
 9ff:	53                   	push   %rbx
 a00:	48 83 c4 80          	add    $0xffffffffffffff80,%rsp
 a04:	49 89 e5             	mov    %rsp,%r13
 a07:	4c 89 ef             	mov    %r13,%rdi
 800:	ff 25 a2 17 20 00    	jmpq   *0x2017a2(%rip)        # 201fa8 <backtrace@GLIBC_2.2.5>
 806:	68 03 00 00 00       	pushq  $0x3
 80b:	e9 b0 ff ff ff       	jmpq   7c0 <.plt>
 a0f:	48 8b 3d 0a 16 20 00 	mov    0x20160a(%rip),%rdi        # 202020 <stderr@@GLIBC_2.2.5>
 a16:	4c 89 e1             	mov    %r12,%rcx
 a19:	be 01 00 00 00       	mov    $0x1,%esi
 a1e:	4c 63 f0             	movslq %eax,%r14
 a21:	48 8d 15 f0 00 00 00 	lea    0xf0(%rip),%rdx        # b18 <_IO_stdin_used+0x8>
 a28:	31 c0                	xor    %eax,%eax
 830:	ff 25 8a 17 20 00    	jmpq   *0x20178a(%rip)        # 201fc0 <__fprintf_chk@GLIBC_2.3.4>
 836:	68 06 00 00 00       	pushq  $0x6
 83b:	e9 80 ff ff ff       	jmpq   7c0 <.plt>
 a2f:	44 89 f6             	mov    %r14d,%esi
 a32:	4c 89 ef             	mov    %r13,%rdi
 810:	ff 25 9a 17 20 00    	jmpq   *0x20179a(%rip)        # 201fb0 <backtrace_symbols@GLIBC_2.2.5>
 816:	68 04 00 00 00       	pushq  $0x4
 81b:	e9 a0 ff ff ff       	jmpq   7c0 <.plt>
 a3a:	48 85 c0             	test   %rax,%rax
 a3d:	74 43                	je     a82 <outcome_v2_3f877000::detail::do_fatal_exit(char const*)+0x92>
 a3f:	49 89 c5             	mov    %rax,%r13
 a42:	4d 85 f6             	test   %r14,%r14
 a45:	74 33                	je     a7a <outcome_v2_3f877000::detail::do_fatal_exit(char const*)+0x8a>
 a47:	48 89 c3             	mov    %rax,%rbx
 a4a:	4e 8d 24 f0          	lea    (%rax,%r14,8),%r12
 a4e:	48 8d 2d 03 01 00 00 	lea    0x103(%rip),%rbp        # b58 <_IO_stdin_used+0x48>
 a55:	0f 1f 00             	nopl   (%rax)
 a58:	48 8b 0b             	mov    (%rbx),%rcx
 a5b:	48 8b 3d be 15 20 00 	mov    0x2015be(%rip),%rdi        # 202020 <stderr@@GLIBC_2.2.5>
 a62:	48 89 ea             	mov    %rbp,%rdx
 a65:	31 c0                	xor    %eax,%eax
 a67:	be 01 00 00 00       	mov    $0x1,%esi
 a6c:	48 83 c3 08          	add    $0x8,%rbx
 a70:	e8 bb fd ff ff       	callq  830 <__fprintf_chk@plt>
 a75:	4c 39 e3             	cmp    %r12,%rbx
 a78:	75 de                	jne    a58 <outcome_v2_3f877000::detail::do_fatal_exit(char const*)+0x68>
 a7a:	4c 89 ef             	mov    %r13,%rdi
 7f0:	ff 25 aa 17 20 00    	jmpq   *0x2017aa(%rip)        # 201fa0 <free@GLIBC_2.2.5>
 7f6:	68 02 00 00 00       	pushq  $0x2
 7fb:	e9 c0 ff ff ff       	jmpq   7c0 <.plt>
 7d0:	ff 25 ba 17 20 00    	jmpq   *0x2017ba(%rip)        # 201f90 <abort@GLIBC_2.2.5>
 7d6:	68 00 00 00 00       	pushq  $0x0
 7db:	e9 e0 ff ff ff       	jmpq   7c0 <.plt>
 a87:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
 9dc:	0f 1f 40 00          	nopl   0x0(%rax)
