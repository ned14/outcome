  400ef0:	50                   	push   %rax
  400ef1:	48 89 e7             	mov    %rsp,%rdi
  400ef4:	e8 07 f1 bf ff       	callq  0 <_init-0x400c70>
  400ef9:	8a 0c 24             	mov    (%rsp),%cl
  400efc:	80 f9 3f             	cmp    $0x3f,%cl
  400eff:	77 0d                	ja     400f0e <test1()+0x1e>
  400f01:	bf 02 00 00 00       	mov    $0x2,%edi
  400f50:	55                   	push   %rbp
  400f51:	53                   	push   %rbx
  400f52:	50                   	push   %rax
  400f53:	89 fd                	mov    %edi,%ebp
  400f55:	bf 20 00 00 00       	mov    $0x20,%edi
  400d80:	ff 25 02 13 20 00    	jmpq   *0x201302(%rip)        # 602088 <_GLOBAL_OFFSET_TABLE_+0x88>
  400d86:	68 0e 00 00 00       	pushq  $0xe
  400d8b:	e9 00 ff ff ff       	jmpq   400c90 <_init+0x20>
  400f5f:	48 89 c3             	mov    %rax,%rbx
  400f62:	8a 05 30 12 20 00    	mov    0x201230(%rip),%al        # 602198 <guard variable for boost::outcome::_1_0_std_std_9274c0d4::monad_category()::c>
  400f68:	84 c0                	test   %al,%al
  400f6a:	75 2c                	jne    400f98 <boost::outcome::_1_0_std_std_9274c0d4::policy::option_policy_base<boost::outcome::_1_0_std_std_9274c0d4::policy::basic_monad_storage<boost::outcome::_1_0_std_std_9274c0d4::policy::option_policy<bool> >, bool, void, void>::_throw_error(boost::outcome::_1_0_std_std_9274c0d4::monad_errc)+0x48>
  400f6c:	bf 98 21 60 00       	mov    $0x602198,%edi
  400cc0:	ff 25 62 13 20 00    	jmpq   *0x201362(%rip)        # 602028 <_GLOBAL_OFFSET_TABLE_+0x28>
  400cc6:	68 02 00 00 00       	pushq  $0x2
  400ccb:	e9 c0 ff ff ff       	jmpq   400c90 <_init+0x20>
  400f76:	85 c0                	test   %eax,%eax
  400f78:	74 1e                	je     400f98 <boost::outcome::_1_0_std_std_9274c0d4::policy::option_policy_base<boost::outcome::_1_0_std_std_9274c0d4::policy::basic_monad_storage<boost::outcome::_1_0_std_std_9274c0d4::policy::option_policy<bool> >, bool, void, void>::_throw_error(boost::outcome::_1_0_std_std_9274c0d4::monad_errc)+0x48>
  400f7a:	bf a0 0c 40 00       	mov    $0x400ca0,%edi
  400f7f:	be d0 20 60 00       	mov    $0x6020d0,%esi
  400f84:	ba c8 20 60 00       	mov    $0x6020c8,%edx
  400d10:	ff 25 3a 13 20 00    	jmpq   *0x20133a(%rip)        # 602050 <_GLOBAL_OFFSET_TABLE_+0x50>
  400d16:	68 07 00 00 00       	pushq  $0x7
  400d1b:	e9 70 ff ff ff       	jmpq   400c90 <_init+0x20>
  400f8e:	bf 98 21 60 00       	mov    $0x602198,%edi
  400d40:	ff 25 22 13 20 00    	jmpq   *0x201322(%rip)        # 602068 <_GLOBAL_OFFSET_TABLE_+0x68>
  400d46:	68 0a 00 00 00       	pushq  $0xa
  400d4b:	e9 40 ff ff ff       	jmpq   400c90 <_init+0x20>
  400f98:	ba d0 20 60 00       	mov    $0x6020d0,%edx
  400f9d:	48 89 df             	mov    %rbx,%rdi
  400fa0:	89 ee                	mov    %ebp,%esi
  400fd0:	55                   	push   %rbp
  400fd1:	41 57                	push   %r15
  400fd3:	41 56                	push   %r14
  400fd5:	53                   	push   %rbx
  400fd6:	48 83 ec 18          	sub    $0x18,%rsp
  400fda:	49 89 d6             	mov    %rdx,%r14
  400fdd:	41 89 f7             	mov    %esi,%r15d
  400fe0:	48 89 fb             	mov    %rdi,%rbx
  400fe3:	49 8b 06             	mov    (%r14),%rax
  400fe6:	48 8d 6c 24 10       	lea    0x10(%rsp),%rbp
  400feb:	48 89 ef             	mov    %rbp,%rdi
  400fee:	4c 89 f6             	mov    %r14,%rsi
  400ff1:	44 89 fa             	mov    %r15d,%edx
  400ff4:	ff 50 18             	callq  *0x18(%rax)
  400ff7:	48 89 df             	mov    %rbx,%rdi
  400ffa:	48 89 ee             	mov    %rbp,%rsi
  400cd0:	ff 25 5a 13 20 00    	jmpq   *0x20135a(%rip)        # 602030 <_GLOBAL_OFFSET_TABLE_+0x30>
  400cd6:	68 03 00 00 00       	pushq  $0x3
  400cdb:	e9 b0 ff ff ff       	jmpq   400c90 <_init+0x20>
  401002:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  401007:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  40100b:	b9 60 21 60 00       	mov    $0x602160,%ecx
  401010:	48 39 cf             	cmp    %rcx,%rdi
  401013:	75 1a                	jne    40102f <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0x5f>
  401015:	44 89 7b 10          	mov    %r15d,0x10(%rbx)
  401019:	4c 89 73 18          	mov    %r14,0x18(%rbx)
  40101d:	48 c7 03 78 13 40 00 	movq   $0x401378,(%rbx)
  401024:	48 83 c4 18          	add    $0x18,%rsp
  401028:	5b                   	pop    %rbx
  401029:	41 5e                	pop    %r14
  40102b:	41 5f                	pop    %r15
  40102d:	5d                   	pop    %rbp
  40102e:	c3                   	retq
  40102f:	b9 00 00 00 00       	mov    $0x0,%ecx
  401034:	48 85 c9             	test   %rcx,%rcx
  401037:	74 10                	je     401049 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0x79>
  401039:	b9 ff ff ff ff       	mov    $0xffffffff,%ecx
  40103e:	f0 0f c1 48 f8       	lock xadd %ecx,-0x8(%rax)
  401043:	85 c9                	test   %ecx,%ecx
  401045:	7f ce                	jg     401015 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0x45>
  401047:	eb 0d                	jmp    401056 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0x86>
  401049:	8b 48 f8             	mov    -0x8(%rax),%ecx
  40104c:	8d 51 ff             	lea    -0x1(%rcx),%edx
  40104f:	89 50 f8             	mov    %edx,-0x8(%rax)
  401052:	85 c9                	test   %ecx,%ecx
  401054:	7f bf                	jg     401015 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0x45>
  401056:	48 89 e6             	mov    %rsp,%rsi
  400d20:	ff 25 32 13 20 00    	jmpq   *0x201332(%rip)        # 602058 <_GLOBAL_OFFSET_TABLE_+0x58>
  400d26:	68 08 00 00 00       	pushq  $0x8
  400d2b:	e9 60 ff ff ff       	jmpq   400c90 <_init+0x20>
  40105e:	eb b5                	jmp    401015 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0x45>
  401060:	48 89 c3             	mov    %rax,%rbx
  401063:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  401068:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  40106c:	b9 60 21 60 00       	mov    $0x602160,%ecx
  401071:	48 39 cf             	cmp    %rcx,%rdi
  401074:	74 31                	je     4010a7 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0xd7>
  401076:	b9 00 00 00 00       	mov    $0x0,%ecx
  40107b:	48 85 c9             	test   %rcx,%rcx
  40107e:	74 10                	je     401090 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0xc0>
  401080:	b9 ff ff ff ff       	mov    $0xffffffff,%ecx
  401085:	f0 0f c1 48 f8       	lock xadd %ecx,-0x8(%rax)
  40108a:	85 c9                	test   %ecx,%ecx
  40108c:	7e 0f                	jle    40109d <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0xcd>
  40108e:	eb 17                	jmp    4010a7 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0xd7>
  401090:	8b 48 f8             	mov    -0x8(%rax),%ecx
  401093:	8d 51 ff             	lea    -0x1(%rcx),%edx
  401096:	89 50 f8             	mov    %edx,-0x8(%rax)
  401099:	85 c9                	test   %ecx,%ecx
  40109b:	7f 0a                	jg     4010a7 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0xd7>
  40109d:	48 8d 74 24 08       	lea    0x8(%rsp),%rsi
  4010a2:	e8 79 fc ff ff       	callq  400d20 <std::string::_Rep::_M_destroy(std::allocator<char> const&)@plt>
  4010a7:	48 89 df             	mov    %rbx,%rdi
  400dd0:	ff 25 da 12 20 00    	jmpq   *0x2012da(%rip)        # 6020b0 <_GLOBAL_OFFSET_TABLE_+0xb0>
  400dd6:	68 13 00 00 00       	pushq  $0x13
  400ddb:	e9 b0 fe ff ff       	jmpq   400c90 <_init+0x20>
  4010af:	90                   	nop
  400fa7:	be 60 12 40 00       	mov    $0x401260,%esi
  400fac:	ba b0 0c 40 00       	mov    $0x400cb0,%edx
  400fb1:	48 89 df             	mov    %rbx,%rdi
  400da0:	ff 25 f2 12 20 00    	jmpq   *0x2012f2(%rip)        # 602098 <_GLOBAL_OFFSET_TABLE_+0x98>
  400da6:	68 10 00 00 00       	pushq  $0x10
  400dab:	e9 e0 fe ff ff       	jmpq   400c90 <_init+0x20>
  400fb9:	48 89 c5             	mov    %rax,%rbp
  400fbc:	48 89 df             	mov    %rbx,%rdi
  400d90:	ff 25 fa 12 20 00    	jmpq   *0x2012fa(%rip)        # 602090 <_GLOBAL_OFFSET_TABLE_+0x90>
  400d96:	68 0f 00 00 00       	pushq  $0xf
  400d9b:	e9 f0 fe ff ff       	jmpq   400c90 <_init+0x20>
  400fc4:	48 89 ef             	mov    %rbp,%rdi
  400fc7:	e8 04 fe ff ff       	callq  400dd0 <_Unwind_Resume@plt>
  400fcc:	0f 1f 40 00          	nopl   0x0(%rax)
  400f0b:	8a 0c 24             	mov    (%rsp),%cl
  400f0e:	31 c0                	xor    %eax,%eax
  400f10:	f6 c1 3f             	test   $0x3f,%cl
  400f13:	0f 95 c0             	setne  %al
  400f16:	59                   	pop    %rcx
  400f17:	c3                   	retq
  400f18:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
