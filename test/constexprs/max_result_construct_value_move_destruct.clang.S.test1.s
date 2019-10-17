  400bc0:	48 83 ec 38          	sub    $0x38,%rsp
  400bc4:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
  400bc9:	e8 32 f4 bf ff       	callq  0 <_init-0x4009a8>
  400bce:	48 8b 44 24 30       	mov    0x30(%rsp),%rax
  400bd3:	48 89 44 24 10       	mov    %rax,0x10(%rsp)
  400bd8:	0f 10 44 24 20       	movups 0x20(%rsp),%xmm0
  400bdd:	0f 29 04 24          	movaps %xmm0,(%rsp)
  400be1:	48 89 e7             	mov    %rsp,%rdi
  400c30:	41 57                	push   %r15
  400c32:	41 56                	push   %r14
  400c34:	53                   	push   %rbx
  400c35:	48 89 fb             	mov    %rdi,%rbx
  400c38:	8b 43 04             	mov    0x4(%rbx),%eax
  400c3b:	a8 01                	test   $0x1,%al
  400c3d:	74 06                	je     400c45 <void outcome_v2_958ce015::policy::error_code_throw_as_system_error<int, std::error_code, void>::wide_value_check<outcome_v2_958ce015::detail::basic_result_value_observers<outcome_v2_958ce015::detail::basic_result_storage<int, std::error_code, outcome_v2_958ce015::policy::error_code_throw_as_system_error<int, std::error_code, void> >, int, outcome_v2_958ce015::policy::error_code_throw_as_system_error<int, std::error_code, void> > >(outcome_v2_958ce015::detail::basic_result_value_observers<outcome_v2_958ce015::detail::basic_result_storage<int, std::error_code, outcome_v2_958ce015::policy::error_code_throw_as_system_error<int, std::error_code, void> >, int, outcome_v2_958ce015::policy::error_code_throw_as_system_error<int, std::error_code, void> >&&)+0x15>
  400c3f:	5b                   	pop    %rbx
  400c40:	41 5e                	pop    %r14
  400c42:	41 5f                	pop    %r15
  400c44:	c3                   	retq
  400c45:	a8 02                	test   $0x2,%al
  400c47:	75 2c                	jne    400c75 <void outcome_v2_958ce015::policy::error_code_throw_as_system_error<int, std::error_code, void>::wide_value_check<outcome_v2_958ce015::detail::basic_result_value_observers<outcome_v2_958ce015::detail::basic_result_storage<int, std::error_code, outcome_v2_958ce015::policy::error_code_throw_as_system_error<int, std::error_code, void> >, int, outcome_v2_958ce015::policy::error_code_throw_as_system_error<int, std::error_code, void> > >(outcome_v2_958ce015::detail::basic_result_value_observers<outcome_v2_958ce015::detail::basic_result_storage<int, std::error_code, outcome_v2_958ce015::policy::error_code_throw_as_system_error<int, std::error_code, void> >, int, outcome_v2_958ce015::policy::error_code_throw_as_system_error<int, std::error_code, void> >&&)+0x45>
  400c49:	bf 10 00 00 00       	mov    $0x10,%edi
  4009d0:	ff 25 42 16 20 00    	jmpq   *0x201642(%rip)        # 602018 <__cxa_allocate_exception@CXXABI_1.3>
  4009d6:	68 00 00 00 00       	pushq  $0x0
  4009db:	e9 e0 ff ff ff       	jmpq   4009c0 <.plt>
  400c53:	48 89 c3             	mov    %rax,%rbx
  400c56:	be 14 0e 40 00       	mov    $0x400e14,%esi
  400c5b:	48 89 df             	mov    %rbx,%rdi
  400cd0:	53                   	push   %rbx
  400cd1:	48 89 fb             	mov    %rdi,%rbx
  400a20:	ff 25 1a 16 20 00    	jmpq   *0x20161a(%rip)        # 602040 <std::logic_error::logic_error(char const*)@GLIBCXX_3.4.21>
  400a26:	68 05 00 00 00       	pushq  $0x5
  400a2b:	e9 90 ff ff ff       	jmpq   4009c0 <.plt>
  400cd9:	48 c7 03 78 0e 40 00 	movq   $0x400e78,(%rbx)
  400ce0:	5b                   	pop    %rbx
  400ce1:	c3                   	retq
  400ce2:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  400cec:	0f 1f 40 00          	nopl   0x0(%rax)
  400c63:	be 50 0e 40 00       	mov    $0x400e50,%esi
  400c68:	ba 90 0a 40 00       	mov    $0x400a90,%edx
  400c6d:	48 89 df             	mov    %rbx,%rdi
  400a70:	ff 25 f2 15 20 00    	jmpq   *0x2015f2(%rip)        # 602068 <__cxa_throw@CXXABI_1.3>
  400a76:	68 0a 00 00 00       	pushq  $0xa
  400a7b:	e9 40 ff ff ff       	jmpq   4009c0 <.plt>
  400c75:	bf 20 00 00 00       	mov    $0x20,%edi
  400c7a:	e8 51 fd ff ff       	callq  4009d0 <__cxa_allocate_exception@plt>
  400c7f:	49 89 c6             	mov    %rax,%r14
  400c82:	8b 73 08             	mov    0x8(%rbx),%esi
  400c85:	48 8b 53 10          	mov    0x10(%rbx),%rdx
  400c89:	4c 89 f7             	mov    %r14,%rdi
  400cf0:	55                   	push   %rbp
  400cf1:	41 57                	push   %r15
  400cf3:	41 56                	push   %r14
  400cf5:	53                   	push   %rbx
  400cf6:	48 83 ec 28          	sub    $0x28,%rsp
  400cfa:	49 89 d6             	mov    %rdx,%r14
  400cfd:	89 f5                	mov    %esi,%ebp
  400cff:	48 89 fb             	mov    %rdi,%rbx
  400d02:	49 8b 06             	mov    (%r14),%rax
  400d05:	4c 8d 7c 24 08       	lea    0x8(%rsp),%r15
  400d0a:	4c 89 ff             	mov    %r15,%rdi
  400d0d:	4c 89 f6             	mov    %r14,%rsi
  400d10:	89 ea                	mov    %ebp,%edx
  400d12:	ff 50 20             	callq  *0x20(%rax)
  400d15:	48 89 df             	mov    %rbx,%rdi
  400d18:	4c 89 fe             	mov    %r15,%rsi
  400a30:	ff 25 12 16 20 00    	jmpq   *0x201612(%rip)        # 602048 <std::runtime_error::runtime_error(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&)@GLIBCXX_3.4.21>
  400a36:	68 06 00 00 00       	pushq  $0x6
  400a3b:	e9 80 ff ff ff       	jmpq   4009c0 <.plt>
  400d20:	48 8b 7c 24 08       	mov    0x8(%rsp),%rdi
  400d25:	48 8d 44 24 18       	lea    0x18(%rsp),%rax
  400d2a:	48 39 c7             	cmp    %rax,%rdi
  400d2d:	74 05                	je     400d34 <std::system_error::system_error(std::error_code)+0x44>
  400a00:	ff 25 2a 16 20 00    	jmpq   *0x20162a(%rip)        # 602030 <operator delete(void*)@GLIBCXX_3.4>
  400a06:	68 03 00 00 00       	pushq  $0x3
  400a0b:	e9 b0 ff ff ff       	jmpq   4009c0 <.plt>
  400d34:	48 c7 03 d8 1d 60 00 	movq   $0x601dd8,(%rbx)
  400d3b:	89 6b 10             	mov    %ebp,0x10(%rbx)
  400d3e:	4c 89 73 18          	mov    %r14,0x18(%rbx)
  400d42:	48 83 c4 28          	add    $0x28,%rsp
  400d46:	5b                   	pop    %rbx
  400d47:	41 5e                	pop    %r14
  400d49:	41 5f                	pop    %r15
  400d4b:	5d                   	pop    %rbp
  400d4c:	c3                   	retq
  400d4d:	48 89 c3             	mov    %rax,%rbx
  400d50:	48 8b 7c 24 08       	mov    0x8(%rsp),%rdi
  400d55:	48 8d 44 24 18       	lea    0x18(%rsp),%rax
  400d5a:	48 39 c7             	cmp    %rax,%rdi
  400d5d:	74 05                	je     400d64 <std::system_error::system_error(std::error_code)+0x74>
  400d5f:	e8 9c fc ff ff       	callq  400a00 <operator delete(void*)@plt>
  400d64:	48 89 df             	mov    %rbx,%rdi
  400a80:	ff 25 ea 15 20 00    	jmpq   *0x2015ea(%rip)        # 602070 <_Unwind_Resume@GCC_3.0>
  400a86:	68 0b 00 00 00       	pushq  $0xb
  400a8b:	e9 30 ff ff ff       	jmpq   4009c0 <.plt>
  400d6c:	0f 1f 40 00          	nopl   0x0(%rax)
  400c91:	be 40 1d 60 00       	mov    $0x601d40,%esi
  400c96:	ba 10 0a 40 00       	mov    $0x400a10,%edx
  400c9b:	4c 89 f7             	mov    %r14,%rdi
  400c9e:	e8 cd fd ff ff       	callq  400a70 <__cxa_throw@plt>
  400ca3:	49 89 c7             	mov    %rax,%r15
  400ca6:	4c 89 f7             	mov    %r14,%rdi
  4009e0:	ff 25 3a 16 20 00    	jmpq   *0x20163a(%rip)        # 602020 <__cxa_free_exception@CXXABI_1.3>
  4009e6:	68 01 00 00 00       	pushq  $0x1
  4009eb:	e9 d0 ff ff ff       	jmpq   4009c0 <.plt>
  400cae:	4c 89 ff             	mov    %r15,%rdi
  400cb1:	e8 ca fd ff ff       	callq  400a80 <_Unwind_Resume@plt>
  400cb6:	49 89 c7             	mov    %rax,%r15
  400cb9:	48 89 df             	mov    %rbx,%rdi
  400cbc:	e8 1f fd ff ff       	callq  4009e0 <__cxa_free_exception@plt>
  400cc1:	4c 89 ff             	mov    %r15,%rdi
  400cc4:	e8 b7 fd ff ff       	callq  400a80 <_Unwind_Resume@plt>
  400cc9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
  400be9:	8b 04 24             	mov    (%rsp),%eax
  400bec:	48 83 c4 38          	add    $0x38,%rsp
  400bf0:	c3                   	retq
  400bf1:	66 66 66 66 66 66 2e 	data16 data16 data16 data16 data16 nopw %cs:0x0(%rax,%rax,1)
