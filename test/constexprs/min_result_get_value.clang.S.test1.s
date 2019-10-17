  400c20:	48 83 ec 18          	sub    $0x18,%rsp
  400c24:	48 b8 05 00 00 00 01 	movabs $0x100000005,%rax
  400c2e:	48 89 04 24          	mov    %rax,(%rsp)
  400c32:	c7 44 24 08 00 00 00 	movl   $0x0,0x8(%rsp)
  400a30:	ff 25 ea 15 20 00    	jmpq   *0x2015ea(%rip)        # 602020 <std::_V2::system_category()@GLIBCXX_3.4.21>
  400a36:	68 01 00 00 00       	pushq  $0x1
  400a3b:	e9 d0 ff ff ff       	jmpq   400a10 <.plt>
  400c3f:	48 89 44 24 10       	mov    %rax,0x10(%rsp)
  400c44:	48 89 e7             	mov    %rsp,%rdi
  400c90:	41 57                	push   %r15
  400c92:	41 56                	push   %r14
  400c94:	53                   	push   %rbx
  400c95:	48 89 fb             	mov    %rdi,%rbx
  400c98:	8b 43 04             	mov    0x4(%rbx),%eax
  400c9b:	a8 01                	test   $0x1,%al
  400c9d:	74 06                	je     400ca5 <void outcome_v2_958ce015::policy::error_code_throw_as_system_error<int, std::error_code, void>::wide_value_check<outcome_v2_958ce015::detail::basic_result_value_observers<outcome_v2_958ce015::detail::basic_result_storage<int, std::error_code, outcome_v2_958ce015::policy::error_code_throw_as_system_error<int, std::error_code, void> >, int, outcome_v2_958ce015::policy::error_code_throw_as_system_error<int, std::error_code, void> >&>(outcome_v2_958ce015::detail::basic_result_value_observers<outcome_v2_958ce015::detail::basic_result_storage<int, std::error_code, outcome_v2_958ce015::policy::error_code_throw_as_system_error<int, std::error_code, void> >, int, outcome_v2_958ce015::policy::error_code_throw_as_system_error<int, std::error_code, void> >&)+0x15>
  400c9f:	5b                   	pop    %rbx
  400ca0:	41 5e                	pop    %r14
  400ca2:	41 5f                	pop    %r15
  400ca4:	c3                   	retq
  400ca5:	a8 02                	test   $0x2,%al
  400ca7:	75 2c                	jne    400cd5 <void outcome_v2_958ce015::policy::error_code_throw_as_system_error<int, std::error_code, void>::wide_value_check<outcome_v2_958ce015::detail::basic_result_value_observers<outcome_v2_958ce015::detail::basic_result_storage<int, std::error_code, outcome_v2_958ce015::policy::error_code_throw_as_system_error<int, std::error_code, void> >, int, outcome_v2_958ce015::policy::error_code_throw_as_system_error<int, std::error_code, void> >&>(outcome_v2_958ce015::detail::basic_result_value_observers<outcome_v2_958ce015::detail::basic_result_storage<int, std::error_code, outcome_v2_958ce015::policy::error_code_throw_as_system_error<int, std::error_code, void> >, int, outcome_v2_958ce015::policy::error_code_throw_as_system_error<int, std::error_code, void> >&)+0x45>
  400ca9:	bf 10 00 00 00       	mov    $0x10,%edi
  400a20:	ff 25 f2 15 20 00    	jmpq   *0x2015f2(%rip)        # 602018 <__cxa_allocate_exception@CXXABI_1.3>
  400a26:	68 00 00 00 00       	pushq  $0x0
  400a2b:	e9 e0 ff ff ff       	jmpq   400a10 <.plt>
  400cb3:	48 89 c3             	mov    %rax,%rbx
  400cb6:	be 74 0e 40 00       	mov    $0x400e74,%esi
  400cbb:	48 89 df             	mov    %rbx,%rdi
  400d30:	53                   	push   %rbx
  400d31:	48 89 fb             	mov    %rdi,%rbx
  400a80:	ff 25 c2 15 20 00    	jmpq   *0x2015c2(%rip)        # 602048 <std::logic_error::logic_error(char const*)@GLIBCXX_3.4.21>
  400a86:	68 06 00 00 00       	pushq  $0x6
  400a8b:	e9 80 ff ff ff       	jmpq   400a10 <.plt>
  400d39:	48 c7 03 d8 0e 40 00 	movq   $0x400ed8,(%rbx)
  400d40:	5b                   	pop    %rbx
  400d41:	c3                   	retq
  400d42:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  400d4c:	0f 1f 40 00          	nopl   0x0(%rax)
  400cc3:	be b0 0e 40 00       	mov    $0x400eb0,%esi
  400cc8:	ba f0 0a 40 00       	mov    $0x400af0,%edx
  400ccd:	48 89 df             	mov    %rbx,%rdi
  400ad0:	ff 25 9a 15 20 00    	jmpq   *0x20159a(%rip)        # 602070 <__cxa_throw@CXXABI_1.3>
  400ad6:	68 0b 00 00 00       	pushq  $0xb
  400adb:	e9 30 ff ff ff       	jmpq   400a10 <.plt>
  400cd5:	bf 20 00 00 00       	mov    $0x20,%edi
  400cda:	e8 41 fd ff ff       	callq  400a20 <__cxa_allocate_exception@plt>
  400cdf:	49 89 c6             	mov    %rax,%r14
  400ce2:	8b 73 08             	mov    0x8(%rbx),%esi
  400ce5:	48 8b 53 10          	mov    0x10(%rbx),%rdx
  400ce9:	4c 89 f7             	mov    %r14,%rdi
  400d50:	55                   	push   %rbp
  400d51:	41 57                	push   %r15
  400d53:	41 56                	push   %r14
  400d55:	53                   	push   %rbx
  400d56:	48 83 ec 28          	sub    $0x28,%rsp
  400d5a:	49 89 d6             	mov    %rdx,%r14
  400d5d:	89 f5                	mov    %esi,%ebp
  400d5f:	48 89 fb             	mov    %rdi,%rbx
  400d62:	49 8b 06             	mov    (%r14),%rax
  400d65:	4c 8d 7c 24 08       	lea    0x8(%rsp),%r15
  400d6a:	4c 89 ff             	mov    %r15,%rdi
  400d6d:	4c 89 f6             	mov    %r14,%rsi
  400d70:	89 ea                	mov    %ebp,%edx
  400d72:	ff 50 20             	callq  *0x20(%rax)
  400d75:	48 89 df             	mov    %rbx,%rdi
  400d78:	4c 89 fe             	mov    %r15,%rsi
  400a90:	ff 25 ba 15 20 00    	jmpq   *0x2015ba(%rip)        # 602050 <std::runtime_error::runtime_error(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&)@GLIBCXX_3.4.21>
  400a96:	68 07 00 00 00       	pushq  $0x7
  400a9b:	e9 70 ff ff ff       	jmpq   400a10 <.plt>
  400d80:	48 8b 7c 24 08       	mov    0x8(%rsp),%rdi
  400d85:	48 8d 44 24 18       	lea    0x18(%rsp),%rax
  400d8a:	48 39 c7             	cmp    %rax,%rdi
  400d8d:	74 05                	je     400d94 <std::system_error::system_error(std::error_code)+0x44>
  400a60:	ff 25 d2 15 20 00    	jmpq   *0x2015d2(%rip)        # 602038 <operator delete(void*)@GLIBCXX_3.4>
  400a66:	68 04 00 00 00       	pushq  $0x4
  400a6b:	e9 a0 ff ff ff       	jmpq   400a10 <.plt>
  400d94:	48 c7 03 d8 1d 60 00 	movq   $0x601dd8,(%rbx)
  400d9b:	89 6b 10             	mov    %ebp,0x10(%rbx)
  400d9e:	4c 89 73 18          	mov    %r14,0x18(%rbx)
  400da2:	48 83 c4 28          	add    $0x28,%rsp
  400da6:	5b                   	pop    %rbx
  400da7:	41 5e                	pop    %r14
  400da9:	41 5f                	pop    %r15
  400dab:	5d                   	pop    %rbp
  400dac:	c3                   	retq
  400dad:	48 89 c3             	mov    %rax,%rbx
  400db0:	48 8b 7c 24 08       	mov    0x8(%rsp),%rdi
  400db5:	48 8d 44 24 18       	lea    0x18(%rsp),%rax
  400dba:	48 39 c7             	cmp    %rax,%rdi
  400dbd:	74 05                	je     400dc4 <std::system_error::system_error(std::error_code)+0x74>
  400dbf:	e8 9c fc ff ff       	callq  400a60 <operator delete(void*)@plt>
  400dc4:	48 89 df             	mov    %rbx,%rdi
  400ae0:	ff 25 92 15 20 00    	jmpq   *0x201592(%rip)        # 602078 <_Unwind_Resume@GCC_3.0>
  400ae6:	68 0c 00 00 00       	pushq  $0xc
  400aeb:	e9 20 ff ff ff       	jmpq   400a10 <.plt>
  400dcc:	0f 1f 40 00          	nopl   0x0(%rax)
  400cf1:	be 40 1d 60 00       	mov    $0x601d40,%esi
  400cf6:	ba 70 0a 40 00       	mov    $0x400a70,%edx
  400cfb:	4c 89 f7             	mov    %r14,%rdi
  400cfe:	e8 cd fd ff ff       	callq  400ad0 <__cxa_throw@plt>
  400d03:	49 89 c7             	mov    %rax,%r15
  400d06:	4c 89 f7             	mov    %r14,%rdi
  400a40:	ff 25 e2 15 20 00    	jmpq   *0x2015e2(%rip)        # 602028 <__cxa_free_exception@CXXABI_1.3>
  400a46:	68 02 00 00 00       	pushq  $0x2
  400a4b:	e9 c0 ff ff ff       	jmpq   400a10 <.plt>
  400d0e:	4c 89 ff             	mov    %r15,%rdi
  400d11:	e8 ca fd ff ff       	callq  400ae0 <_Unwind_Resume@plt>
  400d16:	49 89 c7             	mov    %rax,%r15
  400d19:	48 89 df             	mov    %rbx,%rdi
  400d1c:	e8 1f fd ff ff       	callq  400a40 <__cxa_free_exception@plt>
  400d21:	4c 89 ff             	mov    %r15,%rdi
  400d24:	e8 b7 fd ff ff       	callq  400ae0 <_Unwind_Resume@plt>
  400d29:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
  400c4c:	8b 04 24             	mov    (%rsp),%eax
  400c4f:	48 83 c4 18          	add    $0x18,%rsp
  400c53:	c3                   	retq
  400c54:	66 66 66 2e 0f 1f 84 	data16 data16 nopw %cs:0x0(%rax,%rax,1)
