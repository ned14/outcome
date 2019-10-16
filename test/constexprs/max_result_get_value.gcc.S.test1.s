     e30:	55                   	push   %rbp
     e31:	53                   	push   %rbx
     e32:	48 83 ec 28          	sub    $0x28,%rsp
     e36:	48 89 e3             	mov    %rsp,%rbx
     e39:	48 89 df             	mov    %rbx,%rdi
 c90:	ff 25 1a 13 20 00    	jmpq   *0x20131a(%rip)        # 201fb0 <unknown()>
 c96:	68 09 00 00 00       	pushq  $0x9
 c9b:	e9 50 ff ff ff       	jmpq   bf0 <.plt>
     e41:	8b 44 24 04          	mov    0x4(%rsp),%eax
     e45:	a8 01                	test   $0x1,%al
     e47:	75 57                	jne    ea0 <test1()+0x70>
     e49:	a8 02                	test   $0x2,%al
     e4b:	75 43                	jne    e90 <test1()+0x60>
     e4d:	bf 10 00 00 00       	mov    $0x10,%edi
 c00:	ff 25 62 13 20 00    	jmpq   *0x201362(%rip)        # 201f68 <__cxa_allocate_exception@CXXABI_1.3>
 c06:	68 00 00 00 00       	pushq  $0x0
 c0b:	e9 e0 ff ff ff       	jmpq   bf0 <.plt>
     e57:	48 8d 35 e6 01 00 00 	lea    0x1e6(%rip),%rsi        # 1044 <_IO_stdin_used+0x4>
     e5e:	48 89 c7             	mov    %rax,%rdi
     e61:	48 89 c3             	mov    %rax,%rbx
 c50:	ff 25 3a 13 20 00    	jmpq   *0x20133a(%rip)        # 201f90 <std::logic_error::logic_error(char const*)@GLIBCXX_3.4.21>
 c56:	68 05 00 00 00       	pushq  $0x5
 c5b:	e9 90 ff ff ff       	jmpq   bf0 <.plt>
     e69:	48 8d 05 b8 0e 20 00 	lea    0x200eb8(%rip),%rax        # 201d28 <vtable for outcome_v2_9202a625::bad_result_access+0x10>
     e70:	48 8d 15 59 00 00 00 	lea    0x59(%rip),%rdx        # ed0 <outcome_v2_9202a625::bad_result_access::~bad_result_access()>
     e77:	48 8d 35 82 0e 20 00 	lea    0x200e82(%rip),%rsi        # 201d00 <vtable for __cxxabiv1::__si_class_type_info@CXXABI_1.3>
     e7e:	48 89 df             	mov    %rbx,%rdi
     e81:	48 89 03             	mov    %rax,(%rbx)
 c80:	ff 25 22 13 20 00    	jmpq   *0x201322(%rip)        # 201fa8 <__cxa_throw@CXXABI_1.3>
 c86:	68 08 00 00 00       	pushq  $0x8
 c8b:	e9 60 ff ff ff       	jmpq   bf0 <.plt>
     e89:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
     e90:	48 8d 7b 08          	lea    0x8(%rbx),%rdi
     f10:	41 55                	push   %r13
     f12:	41 54                	push   %r12
     f14:	55                   	push   %rbp
     f15:	53                   	push   %rbx
     f16:	48 89 fb             	mov    %rdi,%rbx
     f19:	bf 20 00 00 00       	mov    $0x20,%edi
     f1e:	48 83 ec 28          	sub    $0x28,%rsp
 c00:	ff 25 62 13 20 00    	jmpq   *0x201362(%rip)        # 201f68 <__cxa_allocate_exception@CXXABI_1.3>
 c06:	68 00 00 00 00       	pushq  $0x0
 c0b:	e9 e0 ff ff ff       	jmpq   bf0 <.plt>
     f27:	4c 8b 6b 08          	mov    0x8(%rbx),%r13
     f2b:	44 8b 23             	mov    (%rbx),%r12d
     f2e:	48 89 c5             	mov    %rax,%rbp
     f31:	48 89 e3             	mov    %rsp,%rbx
     f34:	48 89 df             	mov    %rbx,%rdi
     f37:	49 8b 45 00          	mov    0x0(%r13),%rax
     f3b:	44 89 e2             	mov    %r12d,%edx
     f3e:	4c 89 ee             	mov    %r13,%rsi
     f41:	ff 50 20             	callq  *0x20(%rax)
     f44:	48 89 de             	mov    %rbx,%rsi
     f47:	48 89 ef             	mov    %rbp,%rdi
 c60:	ff 25 32 13 20 00    	jmpq   *0x201332(%rip)        # 201f98 <std::runtime_error::runtime_error(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&)@GLIBCXX_3.4.21>
 c66:	68 06 00 00 00       	pushq  $0x6
 c6b:	e9 80 ff ff ff       	jmpq   bf0 <.plt>
     f4f:	48 8b 3c 24          	mov    (%rsp),%rdi
     f53:	48 83 c3 10          	add    $0x10,%rbx
     f57:	48 39 df             	cmp    %rbx,%rdi
     f5a:	74 05                	je     f61 <outcome_v2_9202a625::policy::outcome_throw_as_system_error_with_payload(std::error_code const&)+0x51>
 c30:	ff 25 4a 13 20 00    	jmpq   *0x20134a(%rip)        # 201f80 <operator delete(void*)@GLIBCXX_3.4>
 c36:	68 03 00 00 00       	pushq  $0x3
 c3b:	e9 b0 ff ff ff       	jmpq   bf0 <.plt>
     f61:	48 8d 05 80 0d 20 00 	lea    0x200d80(%rip),%rax        # 201ce8 <vtable for std::system_error@@GLIBCXX_3.4.11+0x10>
     f68:	48 8b 15 61 10 20 00 	mov    0x201061(%rip),%rdx        # 201fd0 <std::system_error::~system_error()@GLIBCXX_3.4.11>
     f6f:	48 8d 35 4a 0d 20 00 	lea    0x200d4a(%rip),%rsi        # 201cc0 <typeinfo for std::system_error@@GLIBCXX_3.4.11>
     f76:	44 89 65 10          	mov    %r12d,0x10(%rbp)
     f7a:	4c 89 6d 18          	mov    %r13,0x18(%rbp)
     f7e:	48 89 ef             	mov    %rbp,%rdi
     f81:	48 89 45 00          	mov    %rax,0x0(%rbp)
 c80:	ff 25 22 13 20 00    	jmpq   *0x201322(%rip)        # 201fa8 <__cxa_throw@CXXABI_1.3>
 c86:	68 08 00 00 00       	pushq  $0x8
 c8b:	e9 60 ff ff ff       	jmpq   bf0 <.plt>
     f8a:	49 89 c4             	mov    %rax,%r12
     f8d:	48 89 ef             	mov    %rbp,%rdi
 c10:	ff 25 5a 13 20 00    	jmpq   *0x20135a(%rip)        # 201f70 <__cxa_free_exception@CXXABI_1.3>
 c16:	68 01 00 00 00       	pushq  $0x1
 c1b:	e9 d0 ff ff ff       	jmpq   bf0 <.plt>
     f95:	4c 89 e7             	mov    %r12,%rdi
 ca0:	ff 25 12 13 20 00    	jmpq   *0x201312(%rip)        # 201fb8 <_Unwind_Resume@GCC_3.0>
 ca6:	68 0a 00 00 00       	pushq  $0xa
 cab:	e9 40 ff ff ff       	jmpq   bf0 <.plt>
     f9d:	48 8b 3c 24          	mov    (%rsp),%rdi
     fa1:	48 83 c3 10          	add    $0x10,%rbx
     fa5:	49 89 c4             	mov    %rax,%r12
     fa8:	48 39 df             	cmp    %rbx,%rdi
     fab:	74 e0                	je     f8d <outcome_v2_9202a625::policy::outcome_throw_as_system_error_with_payload(std::error_code const&)+0x7d>
     fad:	e8 7e fc ff ff       	callq  c30 <operator delete(void*)@plt>
     fb2:	eb d9                	jmp    f8d <outcome_v2_9202a625::policy::outcome_throw_as_system_error_with_payload(std::error_code const&)+0x7d>
     fb4:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
     fbe:	66 90                	xchg   %ax,%ax
     e99:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
     ea0:	8b 04 24             	mov    (%rsp),%eax
     ea3:	48 83 c4 28          	add    $0x28,%rsp
     ea7:	5b                   	pop    %rbx
     ea8:	5d                   	pop    %rbp
     ea9:	c3                   	retq
     eaa:	48 89 c5             	mov    %rax,%rbp
     ead:	48 89 df             	mov    %rbx,%rdi
 c10:	ff 25 5a 13 20 00    	jmpq   *0x20135a(%rip)        # 201f70 <__cxa_free_exception@CXXABI_1.3>
 c16:	68 01 00 00 00       	pushq  $0x1
 c1b:	e9 d0 ff ff ff       	jmpq   bf0 <.plt>
     eb5:	48 89 ef             	mov    %rbp,%rdi
 ca0:	ff 25 12 13 20 00    	jmpq   *0x201312(%rip)        # 201fb8 <_Unwind_Resume@GCC_3.0>
 ca6:	68 0a 00 00 00       	pushq  $0xa
 cab:	e9 40 ff ff ff       	jmpq   bf0 <.plt>
     ebd:	0f 1f 00             	nopl   (%rax)
