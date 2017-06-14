  400ef0:	41 56                	push   %r14
  400ef2:	53                   	push   %rbx
  400ef3:	50                   	push   %rax
  400ef4:	48 89 fb             	mov    %rdi,%rbx
  400ef7:	48 89 e7             	mov    %rsp,%rdi
  400efa:	e8 01 f1 bf ff       	callq  0 <_init-0x400c70>
  400eff:	4c 8b 34 24          	mov    (%rsp),%r14
  400f03:	48 b8 00 00 00 00 ff 	movabs $0xff00000000,%rax
  400f0d:	49 85 c6             	test   %rax,%r14
  400f10:	75 0a                	jne    400f1c <test1()+0x2c>
  400f12:	bf 02 00 00 00       	mov    $0x2,%edi
  400f60:	55                   	push   %rbp
  400f61:	53                   	push   %rbx
  400f62:	50                   	push   %rax
  400f63:	89 fd                	mov    %edi,%ebp
  400f65:	bf 20 00 00 00       	mov    $0x20,%edi
  400d80:	ff 25 02 13 20 00    	jmpq   *0x201302(%rip)        # 602088 <_GLOBAL_OFFSET_TABLE_+0x88>
  400d86:	68 0e 00 00 00       	pushq  $0xe
  400d8b:	e9 00 ff ff ff       	jmpq   400c90 <_init+0x20>
  400f6f:	48 89 c3             	mov    %rax,%rbx
  400f72:	8a 05 20 12 20 00    	mov    0x201220(%rip),%al        # 602198 <guard variable for boost::outcome::_1_0_std_std_9274c0d4::monad_category()::c>
  400f78:	84 c0                	test   %al,%al
  400f7a:	75 2c                	jne    400fa8 <boost::outcome::_1_0_std_std_9274c0d4::policy::option_policy_base<boost::outcome::_1_0_std_std_9274c0d4::policy::basic_monad_storage<boost::outcome::_1_0_std_std_9274c0d4::policy::option_policy<int> >, int, void, void>::_throw_error(boost::outcome::_1_0_std_std_9274c0d4::monad_errc)+0x48>
  400f7c:	bf 98 21 60 00       	mov    $0x602198,%edi
  400cc0:	ff 25 62 13 20 00    	jmpq   *0x201362(%rip)        # 602028 <_GLOBAL_OFFSET_TABLE_+0x28>
  400cc6:	68 02 00 00 00       	pushq  $0x2
  400ccb:	e9 c0 ff ff ff       	jmpq   400c90 <_init+0x20>
  400f86:	85 c0                	test   %eax,%eax
  400f88:	74 1e                	je     400fa8 <boost::outcome::_1_0_std_std_9274c0d4::policy::option_policy_base<boost::outcome::_1_0_std_std_9274c0d4::policy::basic_monad_storage<boost::outcome::_1_0_std_std_9274c0d4::policy::option_policy<int> >, int, void, void>::_throw_error(boost::outcome::_1_0_std_std_9274c0d4::monad_errc)+0x48>
  400f8a:	bf a0 0c 40 00       	mov    $0x400ca0,%edi
  400f8f:	be d0 20 60 00       	mov    $0x6020d0,%esi
  400f94:	ba c8 20 60 00       	mov    $0x6020c8,%edx
  400d10:	ff 25 3a 13 20 00    	jmpq   *0x20133a(%rip)        # 602050 <_GLOBAL_OFFSET_TABLE_+0x50>
  400d16:	68 07 00 00 00       	pushq  $0x7
  400d1b:	e9 70 ff ff ff       	jmpq   400c90 <_init+0x20>
  400f9e:	bf 98 21 60 00       	mov    $0x602198,%edi
  400d40:	ff 25 22 13 20 00    	jmpq   *0x201322(%rip)        # 602068 <_GLOBAL_OFFSET_TABLE_+0x68>
  400d46:	68 0a 00 00 00       	pushq  $0xa
  400d4b:	e9 40 ff ff ff       	jmpq   400c90 <_init+0x20>
  400fa8:	ba d0 20 60 00       	mov    $0x6020d0,%edx
  400fad:	48 89 df             	mov    %rbx,%rdi
  400fb0:	89 ee                	mov    %ebp,%esi
  400fe0:	55                   	push   %rbp
  400fe1:	41 57                	push   %r15
  400fe3:	41 56                	push   %r14
  400fe5:	53                   	push   %rbx
  400fe6:	48 83 ec 18          	sub    $0x18,%rsp
  400fea:	49 89 d6             	mov    %rdx,%r14
  400fed:	41 89 f7             	mov    %esi,%r15d
  400ff0:	48 89 fb             	mov    %rdi,%rbx
  400ff3:	49 8b 06             	mov    (%r14),%rax
  400ff6:	48 8d 6c 24 10       	lea    0x10(%rsp),%rbp
  400ffb:	48 89 ef             	mov    %rbp,%rdi
  400ffe:	4c 89 f6             	mov    %r14,%rsi
  401001:	44 89 fa             	mov    %r15d,%edx
  401004:	ff 50 18             	callq  *0x18(%rax)
  401007:	48 89 df             	mov    %rbx,%rdi
  40100a:	48 89 ee             	mov    %rbp,%rsi
  400cd0:	ff 25 5a 13 20 00    	jmpq   *0x20135a(%rip)        # 602030 <_GLOBAL_OFFSET_TABLE_+0x30>
  400cd6:	68 03 00 00 00       	pushq  $0x3
  400cdb:	e9 b0 ff ff ff       	jmpq   400c90 <_init+0x20>
  401012:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  401017:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  40101b:	b9 60 21 60 00       	mov    $0x602160,%ecx
  401020:	48 39 cf             	cmp    %rcx,%rdi
  401023:	75 1a                	jne    40103f <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0x5f>
  401025:	44 89 7b 10          	mov    %r15d,0x10(%rbx)
  401029:	4c 89 73 18          	mov    %r14,0x18(%rbx)
  40102d:	48 c7 03 88 13 40 00 	movq   $0x401388,(%rbx)
  401034:	48 83 c4 18          	add    $0x18,%rsp
  401038:	5b                   	pop    %rbx
  401039:	41 5e                	pop    %r14
  40103b:	41 5f                	pop    %r15
  40103d:	5d                   	pop    %rbp
  40103e:	c3                   	retq
  40103f:	b9 00 00 00 00       	mov    $0x0,%ecx
  401044:	48 85 c9             	test   %rcx,%rcx
  401047:	74 10                	je     401059 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0x79>
  401049:	b9 ff ff ff ff       	mov    $0xffffffff,%ecx
  40104e:	f0 0f c1 48 f8       	lock xadd %ecx,-0x8(%rax)
  401053:	85 c9                	test   %ecx,%ecx
  401055:	7f ce                	jg     401025 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0x45>
  401057:	eb 0d                	jmp    401066 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0x86>
  401059:	8b 48 f8             	mov    -0x8(%rax),%ecx
  40105c:	8d 51 ff             	lea    -0x1(%rcx),%edx
  40105f:	89 50 f8             	mov    %edx,-0x8(%rax)
  401062:	85 c9                	test   %ecx,%ecx
  401064:	7f bf                	jg     401025 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0x45>
  401066:	48 89 e6             	mov    %rsp,%rsi
  400d20:	ff 25 32 13 20 00    	jmpq   *0x201332(%rip)        # 602058 <_GLOBAL_OFFSET_TABLE_+0x58>
  400d26:	68 08 00 00 00       	pushq  $0x8
  400d2b:	e9 60 ff ff ff       	jmpq   400c90 <_init+0x20>
  40106e:	eb b5                	jmp    401025 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0x45>
  401070:	48 89 c3             	mov    %rax,%rbx
  401073:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  401078:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  40107c:	b9 60 21 60 00       	mov    $0x602160,%ecx
  401081:	48 39 cf             	cmp    %rcx,%rdi
  401084:	74 31                	je     4010b7 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0xd7>
  401086:	b9 00 00 00 00       	mov    $0x0,%ecx
  40108b:	48 85 c9             	test   %rcx,%rcx
  40108e:	74 10                	je     4010a0 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0xc0>
  401090:	b9 ff ff ff ff       	mov    $0xffffffff,%ecx
  401095:	f0 0f c1 48 f8       	lock xadd %ecx,-0x8(%rax)
  40109a:	85 c9                	test   %ecx,%ecx
  40109c:	7e 0f                	jle    4010ad <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0xcd>
  40109e:	eb 17                	jmp    4010b7 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0xd7>
  4010a0:	8b 48 f8             	mov    -0x8(%rax),%ecx
  4010a3:	8d 51 ff             	lea    -0x1(%rcx),%edx
  4010a6:	89 50 f8             	mov    %edx,-0x8(%rax)
  4010a9:	85 c9                	test   %ecx,%ecx
  4010ab:	7f 0a                	jg     4010b7 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0xd7>
  4010ad:	48 8d 74 24 08       	lea    0x8(%rsp),%rsi
  4010b2:	e8 69 fc ff ff       	callq  400d20 <std::string::_Rep::_M_destroy(std::allocator<char> const&)@plt>
  4010b7:	48 89 df             	mov    %rbx,%rdi
  400dd0:	ff 25 da 12 20 00    	jmpq   *0x2012da(%rip)        # 6020b0 <_GLOBAL_OFFSET_TABLE_+0xb0>
  400dd6:	68 13 00 00 00       	pushq  $0x13
  400ddb:	e9 b0 fe ff ff       	jmpq   400c90 <_init+0x20>
  4010bf:	90                   	nop
  400fb7:	be 70 12 40 00       	mov    $0x401270,%esi
  400fbc:	ba b0 0c 40 00       	mov    $0x400cb0,%edx
  400fc1:	48 89 df             	mov    %rbx,%rdi
  400da0:	ff 25 f2 12 20 00    	jmpq   *0x2012f2(%rip)        # 602098 <_GLOBAL_OFFSET_TABLE_+0x98>
  400da6:	68 10 00 00 00       	pushq  $0x10
  400dab:	e9 e0 fe ff ff       	jmpq   400c90 <_init+0x20>
  400fc9:	48 89 c5             	mov    %rax,%rbp
  400fcc:	48 89 df             	mov    %rbx,%rdi
  400d90:	ff 25 fa 12 20 00    	jmpq   *0x2012fa(%rip)        # 602090 <_GLOBAL_OFFSET_TABLE_+0x90>
  400d96:	68 0f 00 00 00       	pushq  $0xf
  400d9b:	e9 f0 fe ff ff       	jmpq   400c90 <_init+0x20>
  400fd4:	48 89 ef             	mov    %rbp,%rdi
  400fd7:	e8 f4 fd ff ff       	callq  400dd0 <_Unwind_Resume@plt>
  400fdc:	0f 1f 40 00          	nopl   0x0(%rax)
  400f1c:	43 8d 04 76          	lea    (%r14,%r14,2),%eax
  400f20:	89 03                	mov    %eax,(%rbx)
  400f22:	c6 43 04 01          	movb   $0x1,0x4(%rbx)
  400f26:	48 89 d8             	mov    %rbx,%rax
  400f29:	48 83 c4 08          	add    $0x8,%rsp
  400f2d:	5b                   	pop    %rbx
  400f2e:	41 5e                	pop    %r14
  400f30:	c3                   	retq
  400f31:	66 66 66 66 66 66 2e 	data32 data32 data32 data32 data32 nopw %cs:0x0(%rax,%rax,1)
