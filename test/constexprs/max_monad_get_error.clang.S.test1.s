  400fe0:	55                   	push   %rbp
  400fe1:	53                   	push   %rbx
  400fe2:	48 83 ec 28          	sub    $0x28,%rsp
  400fe6:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  400feb:	e8 10 f0 bf ff       	callq  0 <_init-0x400d38>
  400ff0:	8a 44 24 20          	mov    0x20(%rsp),%al
  400ff4:	84 c0                	test   %al,%al
  400ff6:	74 13                	je     40100b <test1()+0x2b>
  400ff8:	3c 03                	cmp    $0x3,%al
  400ffa:	74 25                	je     401021 <test1()+0x41>
  400ffc:	3c 02                	cmp    $0x2,%al
  400ffe:	75 37                	jne    401037 <test1()+0x57>
  401000:	8b 6c 24 08          	mov    0x8(%rsp),%ebp
  401004:	48 8b 5c 24 10       	mov    0x10(%rsp),%rbx
  401009:	eb 36                	jmp    401041 <test1()+0x61>
  40100b:	bf 02 00 00 00       	mov    $0x2,%edi
  401100:	55                   	push   %rbp
  401101:	53                   	push   %rbx
  401102:	50                   	push   %rax
  401103:	89 fd                	mov    %edi,%ebp
  401105:	bf 20 00 00 00       	mov    $0x20,%edi
  400e70:	ff 25 22 12 20 00    	jmpq   *0x201222(%rip)        # 602098 <_GLOBAL_OFFSET_TABLE_+0x98>
  400e76:	68 10 00 00 00       	pushq  $0x10
  400e7b:	e9 e0 fe ff ff       	jmpq   400d60 <_init+0x28>
  40110f:	48 89 c3             	mov    %rax,%rbx
  401112:	8a 05 a0 10 20 00    	mov    0x2010a0(%rip),%al        # 6021b8 <guard variable for boost::outcome::_1_0_std_std_9274c0d4::monad_category()::c>
  401118:	84 c0                	test   %al,%al
  40111a:	75 2c                	jne    401148 <boost::outcome::_1_0_std_std_9274c0d4::policy::monad_policy_base<boost::outcome::_1_0_std_std_9274c0d4::policy::basic_monad_storage<boost::outcome::_1_0_std_std_9274c0d4::policy::monad_policy<int> >, int, boost::outcome::_1_0_std_std_9274c0d4::error_code_extended, std::__exception_ptr::exception_ptr>::_throw_error(boost::outcome::_1_0_std_std_9274c0d4::monad_errc)+0x48>
  40111c:	bf b8 21 60 00       	mov    $0x6021b8,%edi
  400d90:	ff 25 92 12 20 00    	jmpq   *0x201292(%rip)        # 602028 <_GLOBAL_OFFSET_TABLE_+0x28>
  400d96:	68 02 00 00 00       	pushq  $0x2
  400d9b:	e9 c0 ff ff ff       	jmpq   400d60 <_init+0x28>
  401126:	85 c0                	test   %eax,%eax
  401128:	74 1e                	je     401148 <boost::outcome::_1_0_std_std_9274c0d4::policy::monad_policy_base<boost::outcome::_1_0_std_std_9274c0d4::policy::basic_monad_storage<boost::outcome::_1_0_std_std_9274c0d4::policy::monad_policy<int> >, int, boost::outcome::_1_0_std_std_9274c0d4::error_code_extended, std::__exception_ptr::exception_ptr>::_throw_error(boost::outcome::_1_0_std_std_9274c0d4::monad_errc)+0x48>
  40112a:	bf 70 0d 40 00       	mov    $0x400d70,%edi
  40112f:	be e0 20 60 00       	mov    $0x6020e0,%esi
  401134:	ba d8 20 60 00       	mov    $0x6020d8,%edx
  400de0:	ff 25 6a 12 20 00    	jmpq   *0x20126a(%rip)        # 602050 <_GLOBAL_OFFSET_TABLE_+0x50>
  400de6:	68 07 00 00 00       	pushq  $0x7
  400deb:	e9 70 ff ff ff       	jmpq   400d60 <_init+0x28>
  40113e:	bf b8 21 60 00       	mov    $0x6021b8,%edi
  400e10:	ff 25 52 12 20 00    	jmpq   *0x201252(%rip)        # 602068 <_GLOBAL_OFFSET_TABLE_+0x68>
  400e16:	68 0a 00 00 00       	pushq  $0xa
  400e1b:	e9 40 ff ff ff       	jmpq   400d60 <_init+0x28>
  401148:	ba e0 20 60 00       	mov    $0x6020e0,%edx
  40114d:	48 89 df             	mov    %rbx,%rdi
  401150:	89 ee                	mov    %ebp,%esi
  401180:	55                   	push   %rbp
  401181:	41 57                	push   %r15
  401183:	41 56                	push   %r14
  401185:	53                   	push   %rbx
  401186:	48 83 ec 18          	sub    $0x18,%rsp
  40118a:	49 89 d6             	mov    %rdx,%r14
  40118d:	41 89 f7             	mov    %esi,%r15d
  401190:	48 89 fb             	mov    %rdi,%rbx
  401193:	49 8b 06             	mov    (%r14),%rax
  401196:	48 8d 6c 24 10       	lea    0x10(%rsp),%rbp
  40119b:	48 89 ef             	mov    %rbp,%rdi
  40119e:	4c 89 f6             	mov    %r14,%rsi
  4011a1:	44 89 fa             	mov    %r15d,%edx
  4011a4:	ff 50 18             	callq  *0x18(%rax)
  4011a7:	48 89 df             	mov    %rbx,%rdi
  4011aa:	48 89 ee             	mov    %rbp,%rsi
  400da0:	ff 25 8a 12 20 00    	jmpq   *0x20128a(%rip)        # 602030 <_GLOBAL_OFFSET_TABLE_+0x30>
  400da6:	68 03 00 00 00       	pushq  $0x3
  400dab:	e9 b0 ff ff ff       	jmpq   400d60 <_init+0x28>
  4011b2:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  4011b7:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  4011bb:	b9 80 21 60 00       	mov    $0x602180,%ecx
  4011c0:	48 39 cf             	cmp    %rcx,%rdi
  4011c3:	75 1a                	jne    4011df <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0x5f>
  4011c5:	44 89 7b 10          	mov    %r15d,0x10(%rbx)
  4011c9:	4c 89 73 18          	mov    %r14,0x18(%rbx)
  4011cd:	48 c7 03 38 14 40 00 	movq   $0x401438,(%rbx)
  4011d4:	48 83 c4 18          	add    $0x18,%rsp
  4011d8:	5b                   	pop    %rbx
  4011d9:	41 5e                	pop    %r14
  4011db:	41 5f                	pop    %r15
  4011dd:	5d                   	pop    %rbp
  4011de:	c3                   	retq
  4011df:	b9 00 00 00 00       	mov    $0x0,%ecx
  4011e4:	48 85 c9             	test   %rcx,%rcx
  4011e7:	74 10                	je     4011f9 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0x79>
  4011e9:	b9 ff ff ff ff       	mov    $0xffffffff,%ecx
  4011ee:	f0 0f c1 48 f8       	lock xadd %ecx,-0x8(%rax)
  4011f3:	85 c9                	test   %ecx,%ecx
  4011f5:	7f ce                	jg     4011c5 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0x45>
  4011f7:	eb 0d                	jmp    401206 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0x86>
  4011f9:	8b 48 f8             	mov    -0x8(%rax),%ecx
  4011fc:	8d 51 ff             	lea    -0x1(%rcx),%edx
  4011ff:	89 50 f8             	mov    %edx,-0x8(%rax)
  401202:	85 c9                	test   %ecx,%ecx
  401204:	7f bf                	jg     4011c5 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0x45>
  401206:	48 89 e6             	mov    %rsp,%rsi
  400df0:	ff 25 62 12 20 00    	jmpq   *0x201262(%rip)        # 602058 <_GLOBAL_OFFSET_TABLE_+0x58>
  400df6:	68 08 00 00 00       	pushq  $0x8
  400dfb:	e9 60 ff ff ff       	jmpq   400d60 <_init+0x28>
  40120e:	eb b5                	jmp    4011c5 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0x45>
  401210:	48 89 c3             	mov    %rax,%rbx
  401213:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  401218:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  40121c:	b9 80 21 60 00       	mov    $0x602180,%ecx
  401221:	48 39 cf             	cmp    %rcx,%rdi
  401224:	74 31                	je     401257 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0xd7>
  401226:	b9 00 00 00 00       	mov    $0x0,%ecx
  40122b:	48 85 c9             	test   %rcx,%rcx
  40122e:	74 10                	je     401240 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0xc0>
  401230:	b9 ff ff ff ff       	mov    $0xffffffff,%ecx
  401235:	f0 0f c1 48 f8       	lock xadd %ecx,-0x8(%rax)
  40123a:	85 c9                	test   %ecx,%ecx
  40123c:	7e 0f                	jle    40124d <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0xcd>
  40123e:	eb 17                	jmp    401257 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0xd7>
  401240:	8b 48 f8             	mov    -0x8(%rax),%ecx
  401243:	8d 51 ff             	lea    -0x1(%rcx),%edx
  401246:	89 50 f8             	mov    %edx,-0x8(%rax)
  401249:	85 c9                	test   %ecx,%ecx
  40124b:	7f 0a                	jg     401257 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0xd7>
  40124d:	48 8d 74 24 08       	lea    0x8(%rsp),%rsi
  401252:	e8 99 fb ff ff       	callq  400df0 <std::string::_Rep::_M_destroy(std::allocator<char> const&)@plt>
  401257:	48 89 df             	mov    %rbx,%rdi
  400ec0:	ff 25 fa 11 20 00    	jmpq   *0x2011fa(%rip)        # 6020c0 <_GLOBAL_OFFSET_TABLE_+0xc0>
  400ec6:	68 15 00 00 00       	pushq  $0x15
  400ecb:	e9 90 fe ff ff       	jmpq   400d60 <_init+0x28>
  40125f:	90                   	nop
  401157:	be 10 14 40 00       	mov    $0x401410,%esi
  40115c:	ba 80 0d 40 00       	mov    $0x400d80,%edx
  401161:	48 89 df             	mov    %rbx,%rdi
  400e90:	ff 25 12 12 20 00    	jmpq   *0x201212(%rip)        # 6020a8 <_GLOBAL_OFFSET_TABLE_+0xa8>
  400e96:	68 12 00 00 00       	pushq  $0x12
  400e9b:	e9 c0 fe ff ff       	jmpq   400d60 <_init+0x28>
  401169:	48 89 c5             	mov    %rax,%rbp
  40116c:	48 89 df             	mov    %rbx,%rdi
  400e80:	ff 25 1a 12 20 00    	jmpq   *0x20121a(%rip)        # 6020a0 <_GLOBAL_OFFSET_TABLE_+0xa0>
  400e86:	68 11 00 00 00       	pushq  $0x11
  400e8b:	e9 d0 fe ff ff       	jmpq   400d60 <_init+0x28>
  401174:	48 89 ef             	mov    %rbp,%rdi
  401177:	e8 44 fd ff ff       	callq  400ec0 <_Unwind_Resume@plt>
  40117c:	0f 1f 40 00          	nopl   0x0(%rax)
  401015:	84 c0                	test   %al,%al
  401017:	74 1e                	je     401037 <test1()+0x57>
  401019:	8a 44 24 20          	mov    0x20(%rsp),%al
  40101d:	3c 03                	cmp    $0x3,%al
  40101f:	75 db                	jne    400ffc <test1()+0x1c>
  401021:	8a 05 91 11 20 00    	mov    0x201191(%rip),%al        # 6021b8 <guard variable for boost::outcome::_1_0_std_std_9274c0d4::monad_category()::c>
  401027:	bd 03 00 00 00       	mov    $0x3,%ebp
  40102c:	84 c0                	test   %al,%al
  40102e:	74 3d                	je     40106d <test1()+0x8d>
  401030:	bb e0 20 60 00       	mov    $0x6020e0,%ebx
  401035:	eb 0a                	jmp    401041 <test1()+0x61>
  401037:	31 ed                	xor    %ebp,%ebp
  400e50:	ff 25 32 12 20 00    	jmpq   *0x201232(%rip)        # 602088 <_GLOBAL_OFFSET_TABLE_+0x88>
  400e56:	68 0e 00 00 00       	pushq  $0xe
  400e5b:	e9 00 ff ff ff       	jmpq   400d60 <_init+0x28>
  40103e:	48 89 c3             	mov    %rax,%rbx
  401041:	8a 44 24 20          	mov    0x20(%rsp),%al
  401045:	89 c1                	mov    %eax,%ecx
  401047:	fe c9                	dec    %cl
  401049:	80 f9 02             	cmp    $0x2,%cl
  40104c:	72 0e                	jb     40105c <test1()+0x7c>
  40104e:	3c 03                	cmp    $0x3,%al
  401050:	75 0f                	jne    401061 <test1()+0x81>
  401052:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  400e60:	ff 25 2a 12 20 00    	jmpq   *0x20122a(%rip)        # 602090 <_GLOBAL_OFFSET_TABLE_+0x90>
  400e66:	68 0f 00 00 00       	pushq  $0xf
  400e6b:	e9 f0 fe ff ff       	jmpq   400d60 <_init+0x28>
  40105c:	c6 44 24 20 00       	movb   $0x0,0x20(%rsp)
  401061:	89 e8                	mov    %ebp,%eax
  401063:	48 89 da             	mov    %rbx,%rdx
  401066:	48 83 c4 28          	add    $0x28,%rsp
  40106a:	5b                   	pop    %rbx
  40106b:	5d                   	pop    %rbp
  40106c:	c3                   	retq
  40106d:	bf b8 21 60 00       	mov    $0x6021b8,%edi
  400d90:	ff 25 92 12 20 00    	jmpq   *0x201292(%rip)        # 602028 <_GLOBAL_OFFSET_TABLE_+0x28>
  400d96:	68 02 00 00 00       	pushq  $0x2
  400d9b:	e9 c0 ff ff ff       	jmpq   400d60 <_init+0x28>
  401077:	bb e0 20 60 00       	mov    $0x6020e0,%ebx
  40107c:	85 c0                	test   %eax,%eax
  40107e:	74 c1                	je     401041 <test1()+0x61>
  401080:	bf 70 0d 40 00       	mov    $0x400d70,%edi
  401085:	be e0 20 60 00       	mov    $0x6020e0,%esi
  40108a:	ba d8 20 60 00       	mov    $0x6020d8,%edx
  400de0:	ff 25 6a 12 20 00    	jmpq   *0x20126a(%rip)        # 602050 <_GLOBAL_OFFSET_TABLE_+0x50>
  400de6:	68 07 00 00 00       	pushq  $0x7
  400deb:	e9 70 ff ff ff       	jmpq   400d60 <_init+0x28>
  401094:	bf b8 21 60 00       	mov    $0x6021b8,%edi
  400e10:	ff 25 52 12 20 00    	jmpq   *0x201252(%rip)        # 602068 <_GLOBAL_OFFSET_TABLE_+0x68>
  400e16:	68 0a 00 00 00       	pushq  $0xa
  400e1b:	e9 40 ff ff ff       	jmpq   400d60 <_init+0x28>
  40109e:	eb a1                	jmp    401041 <test1()+0x61>
  4010a0:	48 89 c3             	mov    %rax,%rbx
  4010a3:	8a 44 24 20          	mov    0x20(%rsp),%al
  4010a7:	89 c1                	mov    %eax,%ecx
  4010a9:	fe c9                	dec    %cl
  4010ab:	80 f9 02             	cmp    $0x2,%cl
  4010ae:	72 0e                	jb     4010be <test1()+0xde>
  4010b0:	3c 03                	cmp    $0x3,%al
  4010b2:	75 0f                	jne    4010c3 <test1()+0xe3>
  4010b4:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  400e60:	ff 25 2a 12 20 00    	jmpq   *0x20122a(%rip)        # 602090 <_GLOBAL_OFFSET_TABLE_+0x90>
  400e66:	68 0f 00 00 00       	pushq  $0xf
  400e6b:	e9 f0 fe ff ff       	jmpq   400d60 <_init+0x28>
  4010be:	c6 44 24 20 00       	movb   $0x0,0x20(%rsp)
  4010c3:	48 89 df             	mov    %rbx,%rdi
  400ec0:	ff 25 fa 11 20 00    	jmpq   *0x2011fa(%rip)        # 6020c0 <_GLOBAL_OFFSET_TABLE_+0xc0>
  400ec6:	68 15 00 00 00       	pushq  $0x15
  400ecb:	e9 90 fe ff ff       	jmpq   400d60 <_init+0x28>
  4010cb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
