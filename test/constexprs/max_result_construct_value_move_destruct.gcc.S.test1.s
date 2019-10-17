     e30:	55                   	push   %rbp
     e31:	53                   	push   %rbx
     e32:	48 83 ec 48          	sub    $0x48,%rsp
     e36:	48 89 e7             	mov    %rsp,%rdi
 c90:	ff 25 1a 13 20 00    	jmpq   *0x20131a(%rip)        # 201fb0 <unknown()>
 c96:	68 09 00 00 00       	pushq  $0x9
 c9b:	e9 50 ff ff ff       	jmpq   bf0 <.plt>
     e3e:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
     e43:	66 0f 6f 04 24       	movdqa (%rsp),%xmm0
     e48:	48 89 44 24 30       	mov    %rax,0x30(%rsp)
     e4d:	0f 29 44 24 20       	movaps %xmm0,0x20(%rsp)
     e52:	8b 44 24 24          	mov    0x24(%rsp),%eax
     e56:	a8 01                	test   $0x1,%al
     e58:	75 56                	jne    eb0 <test1()+0x80>
     e5a:	a8 02                	test   $0x2,%al
     e5c:	75 42                	jne    ea0 <test1()+0x70>
     e5e:	bf 10 00 00 00       	mov    $0x10,%edi
 c00:	ff 25 62 13 20 00    	jmpq   *0x201362(%rip)        # 201f68 <__cxa_allocate_exception@CXXABI_1.3>
 c06:	68 00 00 00 00       	pushq  $0x0
 c0b:	e9 e0 ff ff ff       	jmpq   bf0 <.plt>
     e68:	48 8d 35 f5 01 00 00 	lea    0x1f5(%rip),%rsi        # 1064 <_IO_stdin_used+0x4>
     e6f:	48 89 c7             	mov    %rax,%rdi
     e72:	48 89 c3             	mov    %rax,%rbx
 c50:	ff 25 3a 13 20 00    	jmpq   *0x20133a(%rip)        # 201f90 <std::logic_error::logic_error(char const*)@GLIBCXX_3.4.21>
 c56:	68 05 00 00 00       	pushq  $0x5
 c5b:	e9 90 ff ff ff       	jmpq   bf0 <.plt>
     e7a:	48 8d 05 a7 0e 20 00 	lea    0x200ea7(%rip),%rax        # 201d28 <vtable for outcome_v2_958ce015::bad_result_access+0x10>
     e81:	48 8d 15 58 00 00 00 	lea    0x58(%rip),%rdx        # ee0 <outcome_v2_958ce015::bad_result_access::~bad_result_access()>
     e88:	48 8d 35 71 0e 20 00 	lea    0x200e71(%rip),%rsi        # 201d00 <vtable for __cxxabiv1::__si_class_type_info@CXXABI_1.3>
     e8f:	48 89 df             	mov    %rbx,%rdi
     e92:	48 89 03             	mov    %rax,(%rbx)
 c80:	ff 25 22 13 20 00    	jmpq   *0x201322(%rip)        # 201fa8 <__cxa_throw@CXXABI_1.3>
 c86:	68 08 00 00 00       	pushq  $0x8
 c8b:	e9 60 ff ff ff       	jmpq   bf0 <.plt>
     e9a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
     ea0:	48 8d 7c 24 28       	lea    0x28(%rsp),%rdi
     f20:	41 55                	push   %r13
     f22:	41 54                	push   %r12
     f24:	55                   	push   %rbp
     f25:	53                   	push   %rbx
     f26:	48 89 fb             	mov    %rdi,%rbx
     f29:	bf 20 00 00 00       	mov    $0x20,%edi
     f2e:	48 83 ec 28          	sub    $0x28,%rsp
 c00:	ff 25 62 13 20 00    	jmpq   *0x201362(%rip)        # 201f68 <__cxa_allocate_exception@CXXABI_1.3>
 c06:	68 00 00 00 00       	pushq  $0x0
 c0b:	e9 e0 ff ff ff       	jmpq   bf0 <.plt>
     f37:	4c 8b 6b 08          	mov    0x8(%rbx),%r13
     f3b:	44 8b 23             	mov    (%rbx),%r12d
     f3e:	48 89 c5             	mov    %rax,%rbp
     f41:	48 89 e3             	mov    %rsp,%rbx
     f44:	48 89 df             	mov    %rbx,%rdi
     f47:	49 8b 45 00          	mov    0x0(%r13),%rax
     f4b:	44 89 e2             	mov    %r12d,%edx
     f4e:	4c 89 ee             	mov    %r13,%rsi
     f51:	ff 50 20             	callq  *0x20(%rax)
     f54:	48 89 de             	mov    %rbx,%rsi
     f57:	48 89 ef             	mov    %rbp,%rdi
 c60:	ff 25 32 13 20 00    	jmpq   *0x201332(%rip)        # 201f98 <std::runtime_error::runtime_error(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&)@GLIBCXX_3.4.21>
 c66:	68 06 00 00 00       	pushq  $0x6
 c6b:	e9 80 ff ff ff       	jmpq   bf0 <.plt>
     f5f:	48 8b 3c 24          	mov    (%rsp),%rdi
     f63:	48 83 c3 10          	add    $0x10,%rbx
     f67:	48 39 df             	cmp    %rbx,%rdi
     f6a:	74 05                	je     f71 <outcome_v2_958ce015::policy::outcome_throw_as_system_error_with_payload(std::error_code const&)+0x51>
 c30:	ff 25 4a 13 20 00    	jmpq   *0x20134a(%rip)        # 201f80 <operator delete(void*)@GLIBCXX_3.4>
 c36:	68 03 00 00 00       	pushq  $0x3
 c3b:	e9 b0 ff ff ff       	jmpq   bf0 <.plt>
     f71:	48 8d 05 70 0d 20 00 	lea    0x200d70(%rip),%rax        # 201ce8 <vtable for std::system_error@@GLIBCXX_3.4.11+0x10>
     f78:	48 8b 15 51 10 20 00 	mov    0x201051(%rip),%rdx        # 201fd0 <std::system_error::~system_error()@GLIBCXX_3.4.11>
     f7f:	48 8d 35 3a 0d 20 00 	lea    0x200d3a(%rip),%rsi        # 201cc0 <typeinfo for std::system_error@@GLIBCXX_3.4.11>
     f86:	44 89 65 10          	mov    %r12d,0x10(%rbp)
     f8a:	4c 89 6d 18          	mov    %r13,0x18(%rbp)
     f8e:	48 89 ef             	mov    %rbp,%rdi
     f91:	48 89 45 00          	mov    %rax,0x0(%rbp)
 c80:	ff 25 22 13 20 00    	jmpq   *0x201322(%rip)        # 201fa8 <__cxa_throw@CXXABI_1.3>
 c86:	68 08 00 00 00       	pushq  $0x8
 c8b:	e9 60 ff ff ff       	jmpq   bf0 <.plt>
     f9a:	49 89 c4             	mov    %rax,%r12
     f9d:	48 89 ef             	mov    %rbp,%rdi
 c10:	ff 25 5a 13 20 00    	jmpq   *0x20135a(%rip)        # 201f70 <__cxa_free_exception@CXXABI_1.3>
 c16:	68 01 00 00 00       	pushq  $0x1
 c1b:	e9 d0 ff ff ff       	jmpq   bf0 <.plt>
     fa5:	4c 89 e7             	mov    %r12,%rdi
 ca0:	ff 25 12 13 20 00    	jmpq   *0x201312(%rip)        # 201fb8 <_Unwind_Resume@GCC_3.0>
 ca6:	68 0a 00 00 00       	pushq  $0xa
 cab:	e9 40 ff ff ff       	jmpq   bf0 <.plt>
     fad:	48 8b 3c 24          	mov    (%rsp),%rdi
     fb1:	48 83 c3 10          	add    $0x10,%rbx
     fb5:	49 89 c4             	mov    %rax,%r12
     fb8:	48 39 df             	cmp    %rbx,%rdi
     fbb:	74 e0                	je     f9d <outcome_v2_958ce015::policy::outcome_throw_as_system_error_with_payload(std::error_code const&)+0x7d>
     fbd:	e8 6e fc ff ff       	callq  c30 <operator delete(void*)@plt>
     fc2:	eb d9                	jmp    f9d <outcome_v2_958ce015::policy::outcome_throw_as_system_error_with_payload(std::error_code const&)+0x7d>
     fc4:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
     fce:	66 90                	xchg   %ax,%ax
     eaa:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
     eb0:	8b 44 24 20          	mov    0x20(%rsp),%eax
     eb4:	48 83 c4 48          	add    $0x48,%rsp
     eb8:	5b                   	pop    %rbx
     eb9:	5d                   	pop    %rbp
     eba:	c3                   	retq
     ebb:	48 89 c5             	mov    %rax,%rbp
     ebe:	48 89 df             	mov    %rbx,%rdi
 c10:	ff 25 5a 13 20 00    	jmpq   *0x20135a(%rip)        # 201f70 <__cxa_free_exception@CXXABI_1.3>
 c16:	68 01 00 00 00       	pushq  $0x1
 c1b:	e9 d0 ff ff ff       	jmpq   bf0 <.plt>
     ec6:	48 89 ef             	mov    %rbp,%rdi
 ca0:	ff 25 12 13 20 00    	jmpq   *0x201312(%rip)        # 201fb8 <_Unwind_Resume@GCC_3.0>
 ca6:	68 0a 00 00 00       	pushq  $0xa
 cab:	e9 40 ff ff ff       	jmpq   bf0 <.plt>
     ece:	66 90                	xchg   %ax,%ax
