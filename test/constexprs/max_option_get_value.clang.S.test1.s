  400ef0:	50                   	push   %rax
  400ef1:	48 89 e7             	mov    %rsp,%rdi
  400ef4:	e8 07 f1 bf ff       	callq  0 <_init-0x400c70>
  400ef9:	80 7c 24 04 00       	cmpb   $0x0,0x4(%rsp)
  400efe:	75 0a                	jne    400f0a <test1()+0x1a>
  400f00:	bf 02 00 00 00       	mov    $0x2,%edi
  400f40:	55                   	push   %rbp
  400f41:	53                   	push   %rbx
  400f42:	50                   	push   %rax
  400f43:	89 fd                	mov    %edi,%ebp
  400f45:	bf 20 00 00 00       	mov    $0x20,%edi
  400d80:	ff 25 02 13 20 00    	jmpq   *0x201302(%rip)        # 602088 <_GLOBAL_OFFSET_TABLE_+0x88>
  400d86:	68 0e 00 00 00       	pushq  $0xe
  400d8b:	e9 00 ff ff ff       	jmpq   400c90 <_init+0x20>
  400f4f:	48 89 c3             	mov    %rax,%rbx
  400f52:	8a 05 40 12 20 00    	mov    0x201240(%rip),%al        # 602198 <guard variable for boost::outcome::_1_0_std_std_9274c0d4::monad_category()::c>
  400f58:	84 c0                	test   %al,%al
  400f5a:	75 2c                	jne    400f88 <boost::outcome::_1_0_std_std_9274c0d4::policy::option_policy_base<boost::outcome::_1_0_std_std_9274c0d4::policy::basic_monad_storage<boost::outcome::_1_0_std_std_9274c0d4::policy::option_policy<int> >, int, void, void>::_throw_error(boost::outcome::_1_0_std_std_9274c0d4::monad_errc)+0x48>
  400f5c:	bf 98 21 60 00       	mov    $0x602198,%edi
  400cc0:	ff 25 62 13 20 00    	jmpq   *0x201362(%rip)        # 602028 <_GLOBAL_OFFSET_TABLE_+0x28>
  400cc6:	68 02 00 00 00       	pushq  $0x2
  400ccb:	e9 c0 ff ff ff       	jmpq   400c90 <_init+0x20>
  400f66:	85 c0                	test   %eax,%eax
  400f68:	74 1e                	je     400f88 <boost::outcome::_1_0_std_std_9274c0d4::policy::option_policy_base<boost::outcome::_1_0_std_std_9274c0d4::policy::basic_monad_storage<boost::outcome::_1_0_std_std_9274c0d4::policy::option_policy<int> >, int, void, void>::_throw_error(boost::outcome::_1_0_std_std_9274c0d4::monad_errc)+0x48>
  400f6a:	bf a0 0c 40 00       	mov    $0x400ca0,%edi
  400f6f:	be d0 20 60 00       	mov    $0x6020d0,%esi
  400f74:	ba c8 20 60 00       	mov    $0x6020c8,%edx
  400d10:	ff 25 3a 13 20 00    	jmpq   *0x20133a(%rip)        # 602050 <_GLOBAL_OFFSET_TABLE_+0x50>
  400d16:	68 07 00 00 00       	pushq  $0x7
  400d1b:	e9 70 ff ff ff       	jmpq   400c90 <_init+0x20>
  400f7e:	bf 98 21 60 00       	mov    $0x602198,%edi
  400d40:	ff 25 22 13 20 00    	jmpq   *0x201322(%rip)        # 602068 <_GLOBAL_OFFSET_TABLE_+0x68>
  400d46:	68 0a 00 00 00       	pushq  $0xa
  400d4b:	e9 40 ff ff ff       	jmpq   400c90 <_init+0x20>
  400f88:	ba d0 20 60 00       	mov    $0x6020d0,%edx
  400f8d:	48 89 df             	mov    %rbx,%rdi
  400f90:	89 ee                	mov    %ebp,%esi
  400fc0:	55                   	push   %rbp
  400fc1:	41 57                	push   %r15
  400fc3:	41 56                	push   %r14
  400fc5:	53                   	push   %rbx
  400fc6:	48 83 ec 18          	sub    $0x18,%rsp
  400fca:	49 89 d6             	mov    %rdx,%r14
  400fcd:	41 89 f7             	mov    %esi,%r15d
  400fd0:	48 89 fb             	mov    %rdi,%rbx
  400fd3:	49 8b 06             	mov    (%r14),%rax
  400fd6:	48 8d 6c 24 10       	lea    0x10(%rsp),%rbp
  400fdb:	48 89 ef             	mov    %rbp,%rdi
  400fde:	4c 89 f6             	mov    %r14,%rsi
  400fe1:	44 89 fa             	mov    %r15d,%edx
  400fe4:	ff 50 18             	callq  *0x18(%rax)
  400fe7:	48 89 df             	mov    %rbx,%rdi
  400fea:	48 89 ee             	mov    %rbp,%rsi
  400cd0:	ff 25 5a 13 20 00    	jmpq   *0x20135a(%rip)        # 602030 <_GLOBAL_OFFSET_TABLE_+0x30>
  400cd6:	68 03 00 00 00       	pushq  $0x3
  400cdb:	e9 b0 ff ff ff       	jmpq   400c90 <_init+0x20>
  400ff2:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  400ff7:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  400ffb:	b9 60 21 60 00       	mov    $0x602160,%ecx
  401000:	48 39 cf             	cmp    %rcx,%rdi
  401003:	75 1a                	jne    40101f <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0x5f>
  401005:	44 89 7b 10          	mov    %r15d,0x10(%rbx)
  401009:	4c 89 73 18          	mov    %r14,0x18(%rbx)
  40100d:	48 c7 03 68 13 40 00 	movq   $0x401368,(%rbx)
  401014:	48 83 c4 18          	add    $0x18,%rsp
  401018:	5b                   	pop    %rbx
  401019:	41 5e                	pop    %r14
  40101b:	41 5f                	pop    %r15
  40101d:	5d                   	pop    %rbp
  40101e:	c3                   	retq
  40101f:	b9 00 00 00 00       	mov    $0x0,%ecx
  401024:	48 85 c9             	test   %rcx,%rcx
  401027:	74 10                	je     401039 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0x79>
  401029:	b9 ff ff ff ff       	mov    $0xffffffff,%ecx
  40102e:	f0 0f c1 48 f8       	lock xadd %ecx,-0x8(%rax)
  401033:	85 c9                	test   %ecx,%ecx
  401035:	7f ce                	jg     401005 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0x45>
  401037:	eb 0d                	jmp    401046 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0x86>
  401039:	8b 48 f8             	mov    -0x8(%rax),%ecx
  40103c:	8d 51 ff             	lea    -0x1(%rcx),%edx
  40103f:	89 50 f8             	mov    %edx,-0x8(%rax)
  401042:	85 c9                	test   %ecx,%ecx
  401044:	7f bf                	jg     401005 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0x45>
  401046:	48 89 e6             	mov    %rsp,%rsi
  400d20:	ff 25 32 13 20 00    	jmpq   *0x201332(%rip)        # 602058 <_GLOBAL_OFFSET_TABLE_+0x58>
  400d26:	68 08 00 00 00       	pushq  $0x8
  400d2b:	e9 60 ff ff ff       	jmpq   400c90 <_init+0x20>
  40104e:	eb b5                	jmp    401005 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0x45>
  401050:	48 89 c3             	mov    %rax,%rbx
  401053:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  401058:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  40105c:	b9 60 21 60 00       	mov    $0x602160,%ecx
  401061:	48 39 cf             	cmp    %rcx,%rdi
  401064:	74 31                	je     401097 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0xd7>
  401066:	b9 00 00 00 00       	mov    $0x0,%ecx
  40106b:	48 85 c9             	test   %rcx,%rcx
  40106e:	74 10                	je     401080 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0xc0>
  401070:	b9 ff ff ff ff       	mov    $0xffffffff,%ecx
  401075:	f0 0f c1 48 f8       	lock xadd %ecx,-0x8(%rax)
  40107a:	85 c9                	test   %ecx,%ecx
  40107c:	7e 0f                	jle    40108d <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0xcd>
  40107e:	eb 17                	jmp    401097 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0xd7>
  401080:	8b 48 f8             	mov    -0x8(%rax),%ecx
  401083:	8d 51 ff             	lea    -0x1(%rcx),%edx
  401086:	89 50 f8             	mov    %edx,-0x8(%rax)
  401089:	85 c9                	test   %ecx,%ecx
  40108b:	7f 0a                	jg     401097 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0xd7>
  40108d:	48 8d 74 24 08       	lea    0x8(%rsp),%rsi
  401092:	e8 89 fc ff ff       	callq  400d20 <std::string::_Rep::_M_destroy(std::allocator<char> const&)@plt>
  401097:	48 89 df             	mov    %rbx,%rdi
  400dd0:	ff 25 da 12 20 00    	jmpq   *0x2012da(%rip)        # 6020b0 <_GLOBAL_OFFSET_TABLE_+0xb0>
  400dd6:	68 13 00 00 00       	pushq  $0x13
  400ddb:	e9 b0 fe ff ff       	jmpq   400c90 <_init+0x20>
  40109f:	90                   	nop
  400f97:	be 50 12 40 00       	mov    $0x401250,%esi
  400f9c:	ba b0 0c 40 00       	mov    $0x400cb0,%edx
  400fa1:	48 89 df             	mov    %rbx,%rdi
  400da0:	ff 25 f2 12 20 00    	jmpq   *0x2012f2(%rip)        # 602098 <_GLOBAL_OFFSET_TABLE_+0x98>
  400da6:	68 10 00 00 00       	pushq  $0x10
  400dab:	e9 e0 fe ff ff       	jmpq   400c90 <_init+0x20>
  400fa9:	48 89 c5             	mov    %rax,%rbp
  400fac:	48 89 df             	mov    %rbx,%rdi
  400d90:	ff 25 fa 12 20 00    	jmpq   *0x2012fa(%rip)        # 602090 <_GLOBAL_OFFSET_TABLE_+0x90>
  400d96:	68 0f 00 00 00       	pushq  $0xf
  400d9b:	e9 f0 fe ff ff       	jmpq   400c90 <_init+0x20>
  400fb4:	48 89 ef             	mov    %rbp,%rdi
  400fb7:	e8 14 fe ff ff       	callq  400dd0 <_Unwind_Resume@plt>
  400fbc:	0f 1f 40 00          	nopl   0x0(%rax)
  400f0a:	8b 04 24             	mov    (%rsp),%eax
  400f0d:	59                   	pop    %rcx
  400f0e:	c3                   	retq
  400f0f:	90                   	nop
