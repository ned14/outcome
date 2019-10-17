  400bc0:	53                   	push   %rbx
  400bc1:	48 83 ec 20          	sub    $0x20,%rsp
  400bc5:	48 8d 5c 24 08       	lea    0x8(%rsp),%rbx
  400bca:	48 89 df             	mov    %rbx,%rdi
  400bcd:	e8 2e f4 bf ff       	callq  0 <_init-0x4009a8>
  400bd2:	48 89 df             	mov    %rbx,%rdi
  400c20:	41 57                	push   %r15
  400c22:	41 56                	push   %r14
  400c24:	53                   	push   %rbx
  400c25:	48 89 fb             	mov    %rdi,%rbx
  400c28:	8b 43 04             	mov    0x4(%rbx),%eax
  400c2b:	a8 01                	test   $0x1,%al
  400c2d:	74 06                	je     400c35 <void outcome_v2_958ce015::policy::error_code_throw_as_system_error<int, std::error_code, void>::wide_value_check<outcome_v2_958ce015::detail::basic_result_value_observers<outcome_v2_958ce015::detail::basic_result_storage<int, std::error_code, outcome_v2_958ce015::policy::error_code_throw_as_system_error<int, std::error_code, void> >, int, outcome_v2_958ce015::policy::error_code_throw_as_system_error<int, std::error_code, void> > >(outcome_v2_958ce015::detail::basic_result_value_observers<outcome_v2_958ce015::detail::basic_result_storage<int, std::error_code, outcome_v2_958ce015::policy::error_code_throw_as_system_error<int, std::error_code, void> >, int, outcome_v2_958ce015::policy::error_code_throw_as_system_error<int, std::error_code, void> >&&)+0x15>
  400c2f:	5b                   	pop    %rbx
  400c30:	41 5e                	pop    %r14
  400c32:	41 5f                	pop    %r15
  400c34:	c3                   	retq
  400c35:	a8 02                	test   $0x2,%al
  400c37:	75 2c                	jne    400c65 <void outcome_v2_958ce015::policy::error_code_throw_as_system_error<int, std::error_code, void>::wide_value_check<outcome_v2_958ce015::detail::basic_result_value_observers<outcome_v2_958ce015::detail::basic_result_storage<int, std::error_code, outcome_v2_958ce015::policy::error_code_throw_as_system_error<int, std::error_code, void> >, int, outcome_v2_958ce015::policy::error_code_throw_as_system_error<int, std::error_code, void> > >(outcome_v2_958ce015::detail::basic_result_value_observers<outcome_v2_958ce015::detail::basic_result_storage<int, std::error_code, outcome_v2_958ce015::policy::error_code_throw_as_system_error<int, std::error_code, void> >, int, outcome_v2_958ce015::policy::error_code_throw_as_system_error<int, std::error_code, void> >&&)+0x45>
  400c39:	bf 10 00 00 00       	mov    $0x10,%edi
  4009d0:	ff 25 42 16 20 00    	jmpq   *0x201642(%rip)        # 602018 <__cxa_allocate_exception@CXXABI_1.3>
  4009d6:	68 00 00 00 00       	pushq  $0x0
  4009db:	e9 e0 ff ff ff       	jmpq   4009c0 <.plt>
  400c43:	48 89 c3             	mov    %rax,%rbx
  400c46:	be 04 0e 40 00       	mov    $0x400e04,%esi
  400c4b:	48 89 df             	mov    %rbx,%rdi
  400cc0:	53                   	push   %rbx
  400cc1:	48 89 fb             	mov    %rdi,%rbx
  400a20:	ff 25 1a 16 20 00    	jmpq   *0x20161a(%rip)        # 602040 <std::logic_error::logic_error(char const*)@GLIBCXX_3.4.21>
  400a26:	68 05 00 00 00       	pushq  $0x5
  400a2b:	e9 90 ff ff ff       	jmpq   4009c0 <.plt>
  400cc9:	48 c7 03 68 0e 40 00 	movq   $0x400e68,(%rbx)
  400cd0:	5b                   	pop    %rbx
  400cd1:	c3                   	retq
  400cd2:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  400cdc:	0f 1f 40 00          	nopl   0x0(%rax)
  400c53:	be 40 0e 40 00       	mov    $0x400e40,%esi
  400c58:	ba 90 0a 40 00       	mov    $0x400a90,%edx
  400c5d:	48 89 df             	mov    %rbx,%rdi
  400a70:	ff 25 f2 15 20 00    	jmpq   *0x2015f2(%rip)        # 602068 <__cxa_throw@CXXABI_1.3>
  400a76:	68 0a 00 00 00       	pushq  $0xa
  400a7b:	e9 40 ff ff ff       	jmpq   4009c0 <.plt>
  400c65:	bf 20 00 00 00       	mov    $0x20,%edi
  400c6a:	e8 61 fd ff ff       	callq  4009d0 <__cxa_allocate_exception@plt>
  400c6f:	49 89 c6             	mov    %rax,%r14
  400c72:	8b 73 08             	mov    0x8(%rbx),%esi
  400c75:	48 8b 53 10          	mov    0x10(%rbx),%rdx
  400c79:	4c 89 f7             	mov    %r14,%rdi
  400ce0:	55                   	push   %rbp
  400ce1:	41 57                	push   %r15
  400ce3:	41 56                	push   %r14
  400ce5:	53                   	push   %rbx
  400ce6:	48 83 ec 28          	sub    $0x28,%rsp
  400cea:	49 89 d6             	mov    %rdx,%r14
  400ced:	89 f5                	mov    %esi,%ebp
  400cef:	48 89 fb             	mov    %rdi,%rbx
  400cf2:	49 8b 06             	mov    (%r14),%rax
  400cf5:	4c 8d 7c 24 08       	lea    0x8(%rsp),%r15
  400cfa:	4c 89 ff             	mov    %r15,%rdi
  400cfd:	4c 89 f6             	mov    %r14,%rsi
  400d00:	89 ea                	mov    %ebp,%edx
  400d02:	ff 50 20             	callq  *0x20(%rax)
  400d05:	48 89 df             	mov    %rbx,%rdi
  400d08:	4c 89 fe             	mov    %r15,%rsi
  400a30:	ff 25 12 16 20 00    	jmpq   *0x201612(%rip)        # 602048 <std::runtime_error::runtime_error(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> > const&)@GLIBCXX_3.4.21>
  400a36:	68 06 00 00 00       	pushq  $0x6
  400a3b:	e9 80 ff ff ff       	jmpq   4009c0 <.plt>
  400d10:	48 8b 7c 24 08       	mov    0x8(%rsp),%rdi
  400d15:	48 8d 44 24 18       	lea    0x18(%rsp),%rax
  400d1a:	48 39 c7             	cmp    %rax,%rdi
  400d1d:	74 05                	je     400d24 <std::system_error::system_error(std::error_code)+0x44>
  400a00:	ff 25 2a 16 20 00    	jmpq   *0x20162a(%rip)        # 602030 <operator delete(void*)@GLIBCXX_3.4>
  400a06:	68 03 00 00 00       	pushq  $0x3
  400a0b:	e9 b0 ff ff ff       	jmpq   4009c0 <.plt>
  400d24:	48 c7 03 d8 1d 60 00 	movq   $0x601dd8,(%rbx)
  400d2b:	89 6b 10             	mov    %ebp,0x10(%rbx)
  400d2e:	4c 89 73 18          	mov    %r14,0x18(%rbx)
  400d32:	48 83 c4 28          	add    $0x28,%rsp
  400d36:	5b                   	pop    %rbx
  400d37:	41 5e                	pop    %r14
  400d39:	41 5f                	pop    %r15
  400d3b:	5d                   	pop    %rbp
  400d3c:	c3                   	retq
  400d3d:	48 89 c3             	mov    %rax,%rbx
  400d40:	48 8b 7c 24 08       	mov    0x8(%rsp),%rdi
  400d45:	48 8d 44 24 18       	lea    0x18(%rsp),%rax
  400d4a:	48 39 c7             	cmp    %rax,%rdi
  400d4d:	74 05                	je     400d54 <std::system_error::system_error(std::error_code)+0x74>
  400d4f:	e8 ac fc ff ff       	callq  400a00 <operator delete(void*)@plt>
  400d54:	48 89 df             	mov    %rbx,%rdi
  400a80:	ff 25 ea 15 20 00    	jmpq   *0x2015ea(%rip)        # 602070 <_Unwind_Resume@GCC_3.0>
  400a86:	68 0b 00 00 00       	pushq  $0xb
  400a8b:	e9 30 ff ff ff       	jmpq   4009c0 <.plt>
  400d5c:	0f 1f 40 00          	nopl   0x0(%rax)
  400c81:	be 40 1d 60 00       	mov    $0x601d40,%esi
  400c86:	ba 10 0a 40 00       	mov    $0x400a10,%edx
  400c8b:	4c 89 f7             	mov    %r14,%rdi
  400c8e:	e8 dd fd ff ff       	callq  400a70 <__cxa_throw@plt>
  400c93:	49 89 c7             	mov    %rax,%r15
  400c96:	4c 89 f7             	mov    %r14,%rdi
  4009e0:	ff 25 3a 16 20 00    	jmpq   *0x20163a(%rip)        # 602020 <__cxa_free_exception@CXXABI_1.3>
  4009e6:	68 01 00 00 00       	pushq  $0x1
  4009eb:	e9 d0 ff ff ff       	jmpq   4009c0 <.plt>
  400c9e:	4c 89 ff             	mov    %r15,%rdi
  400ca1:	e8 da fd ff ff       	callq  400a80 <_Unwind_Resume@plt>
  400ca6:	49 89 c7             	mov    %rax,%r15
  400ca9:	48 89 df             	mov    %rbx,%rdi
  400cac:	e8 2f fd ff ff       	callq  4009e0 <__cxa_free_exception@plt>
  400cb1:	4c 89 ff             	mov    %r15,%rdi
  400cb4:	e8 c7 fd ff ff       	callq  400a80 <_Unwind_Resume@plt>
  400cb9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
  400bda:	8b 44 24 08          	mov    0x8(%rsp),%eax
  400bde:	48 83 c4 20          	add    $0x20,%rsp
  400be2:	5b                   	pop    %rbx
  400be3:	c3                   	retq
  400be4:	66 66 66 2e 0f 1f 84 	data16 data16 nopw %cs:0x0(%rax,%rax,1)
