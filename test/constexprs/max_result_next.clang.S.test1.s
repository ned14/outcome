  400fa0:	41 57                	push   %r15
  400fa2:	41 56                	push   %r14
  400fa4:	53                   	push   %rbx
  400fa5:	48 83 ec 20          	sub    $0x20,%rsp
  400fa9:	48 89 fb             	mov    %rdi,%rbx
  400fac:	48 89 e7             	mov    %rsp,%rdi
  400faf:	e8 4c f0 bf ff       	callq  0 <_init-0x400d08>
  400fb4:	44 8b 34 24          	mov    (%rsp),%r14d
  400fb8:	8a 44 24 18          	mov    0x18(%rsp),%al
  400fbc:	84 c0                	test   %al,%al
  400fbe:	74 36                	je     400ff6 <test1()+0x56>
  400fc0:	3c 02                	cmp    $0x2,%al
  400fc2:	75 3c                	jne    401000 <test1()+0x60>
  400fc4:	4c 8b 7c 24 08       	mov    0x8(%rsp),%r15
  400fc9:	bf 20 00 00 00       	mov    $0x20,%edi
  400e30:	ff 25 5a 12 20 00    	jmpq   *0x20125a(%rip)        # 602090 <_GLOBAL_OFFSET_TABLE_+0x90>
  400e36:	68 0f 00 00 00       	pushq  $0xf
  400e3b:	e9 f0 fe ff ff       	jmpq   400d30 <_init+0x28>
  400fd3:	48 89 c3             	mov    %rax,%rbx
  400fd6:	48 89 df             	mov    %rbx,%rdi
  400fd9:	44 89 f6             	mov    %r14d,%esi
  400fdc:	4c 89 fa             	mov    %r15,%rdx
  4010e0:	55                   	push   %rbp
  4010e1:	41 57                	push   %r15
  4010e3:	41 56                	push   %r14
  4010e5:	53                   	push   %rbx
  4010e6:	48 83 ec 18          	sub    $0x18,%rsp
  4010ea:	49 89 d6             	mov    %rdx,%r14
  4010ed:	41 89 f7             	mov    %esi,%r15d
  4010f0:	48 89 fb             	mov    %rdi,%rbx
  4010f3:	49 8b 06             	mov    (%r14),%rax
  4010f6:	48 8d 6c 24 10       	lea    0x10(%rsp),%rbp
  4010fb:	48 89 ef             	mov    %rbp,%rdi
  4010fe:	4c 89 f6             	mov    %r14,%rsi
  401101:	44 89 fa             	mov    %r15d,%edx
  401104:	ff 50 18             	callq  *0x18(%rax)
  401107:	48 89 df             	mov    %rbx,%rdi
  40110a:	48 89 ee             	mov    %rbp,%rsi
  400d70:	ff 25 ba 12 20 00    	jmpq   *0x2012ba(%rip)        # 602030 <_GLOBAL_OFFSET_TABLE_+0x30>
  400d76:	68 03 00 00 00       	pushq  $0x3
  400d7b:	e9 b0 ff ff ff       	jmpq   400d30 <_init+0x28>
  401112:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  401117:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  40111b:	b9 80 21 60 00       	mov    $0x602180,%ecx
  401120:	48 39 cf             	cmp    %rcx,%rdi
  401123:	75 1a                	jne    40113f <std::system_error::system_error(std::error_code)+0x5f>
  401125:	48 c7 03 08 21 60 00 	movq   $0x602108,(%rbx)
  40112c:	44 89 7b 10          	mov    %r15d,0x10(%rbx)
  401130:	4c 89 73 18          	mov    %r14,0x18(%rbx)
  401134:	48 83 c4 18          	add    $0x18,%rsp
  401138:	5b                   	pop    %rbx
  401139:	41 5e                	pop    %r14
  40113b:	41 5f                	pop    %r15
  40113d:	5d                   	pop    %rbp
  40113e:	c3                   	retq
  40113f:	b9 00 00 00 00       	mov    $0x0,%ecx
  401144:	48 85 c9             	test   %rcx,%rcx
  401147:	74 10                	je     401159 <std::system_error::system_error(std::error_code)+0x79>
  401149:	b9 ff ff ff ff       	mov    $0xffffffff,%ecx
  40114e:	f0 0f c1 48 f8       	lock xadd %ecx,-0x8(%rax)
  401153:	85 c9                	test   %ecx,%ecx
  401155:	7f ce                	jg     401125 <std::system_error::system_error(std::error_code)+0x45>
  401157:	eb 0d                	jmp    401166 <std::system_error::system_error(std::error_code)+0x86>
  401159:	8b 48 f8             	mov    -0x8(%rax),%ecx
  40115c:	8d 51 ff             	lea    -0x1(%rcx),%edx
  40115f:	89 50 f8             	mov    %edx,-0x8(%rax)
  401162:	85 c9                	test   %ecx,%ecx
  401164:	7f bf                	jg     401125 <std::system_error::system_error(std::error_code)+0x45>
  401166:	48 89 e6             	mov    %rsp,%rsi
  400dc0:	ff 25 92 12 20 00    	jmpq   *0x201292(%rip)        # 602058 <_GLOBAL_OFFSET_TABLE_+0x58>
  400dc6:	68 08 00 00 00       	pushq  $0x8
  400dcb:	e9 60 ff ff ff       	jmpq   400d30 <_init+0x28>
  40116e:	eb b5                	jmp    401125 <std::system_error::system_error(std::error_code)+0x45>
  401170:	48 89 c3             	mov    %rax,%rbx
  401173:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  401178:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  40117c:	b9 80 21 60 00       	mov    $0x602180,%ecx
  401181:	48 39 cf             	cmp    %rcx,%rdi
  401184:	74 31                	je     4011b7 <std::system_error::system_error(std::error_code)+0xd7>
  401186:	b9 00 00 00 00       	mov    $0x0,%ecx
  40118b:	48 85 c9             	test   %rcx,%rcx
  40118e:	74 10                	je     4011a0 <std::system_error::system_error(std::error_code)+0xc0>
  401190:	b9 ff ff ff ff       	mov    $0xffffffff,%ecx
  401195:	f0 0f c1 48 f8       	lock xadd %ecx,-0x8(%rax)
  40119a:	85 c9                	test   %ecx,%ecx
  40119c:	7e 0f                	jle    4011ad <std::system_error::system_error(std::error_code)+0xcd>
  40119e:	eb 17                	jmp    4011b7 <std::system_error::system_error(std::error_code)+0xd7>
  4011a0:	8b 48 f8             	mov    -0x8(%rax),%ecx
  4011a3:	8d 51 ff             	lea    -0x1(%rcx),%edx
  4011a6:	89 50 f8             	mov    %edx,-0x8(%rax)
  4011a9:	85 c9                	test   %ecx,%ecx
  4011ab:	7f 0a                	jg     4011b7 <std::system_error::system_error(std::error_code)+0xd7>
  4011ad:	48 8d 74 24 08       	lea    0x8(%rsp),%rsi
  4011b2:	e8 09 fc ff ff       	callq  400dc0 <std::string::_Rep::_M_destroy(std::allocator<char> const&)@plt>
  4011b7:	48 89 df             	mov    %rbx,%rdi
  400e80:	ff 25 32 12 20 00    	jmpq   *0x201232(%rip)        # 6020b8 <_GLOBAL_OFFSET_TABLE_+0xb8>
  400e86:	68 14 00 00 00       	pushq  $0x14
  400e8b:	e9 a0 fe ff ff       	jmpq   400d30 <_init+0x28>
  4011bf:	90                   	nop
  400fe4:	be e0 20 60 00       	mov    $0x6020e0,%esi
  400fe9:	ba f0 0d 40 00       	mov    $0x400df0,%edx
  400fee:	48 89 df             	mov    %rbx,%rdi
  400e50:	ff 25 4a 12 20 00    	jmpq   *0x20124a(%rip)        # 6020a0 <_GLOBAL_OFFSET_TABLE_+0xa0>
  400e56:	68 11 00 00 00       	pushq  $0x11
  400e5b:	e9 d0 fe ff ff       	jmpq   400d30 <_init+0x28>
  400ff6:	bf 02 00 00 00       	mov    $0x2,%edi
  401060:	55                   	push   %rbp
  401061:	53                   	push   %rbx
  401062:	50                   	push   %rax
  401063:	89 fd                	mov    %edi,%ebp
  401065:	bf 20 00 00 00       	mov    $0x20,%edi
  400e30:	ff 25 5a 12 20 00    	jmpq   *0x20125a(%rip)        # 602090 <_GLOBAL_OFFSET_TABLE_+0x90>
  400e36:	68 0f 00 00 00       	pushq  $0xf
  400e3b:	e9 f0 fe ff ff       	jmpq   400d30 <_init+0x28>
  40106f:	48 89 c3             	mov    %rax,%rbx
  401072:	8a 05 40 11 20 00    	mov    0x201140(%rip),%al        # 6021b8 <guard variable for boost::outcome::_1_0_std_std_9274c0d4::monad_category()::c>
  401078:	84 c0                	test   %al,%al
  40107a:	75 2c                	jne    4010a8 <boost::outcome::_1_0_std_std_9274c0d4::policy::result_policy_base<boost::outcome::_1_0_std_std_9274c0d4::policy::basic_monad_storage<boost::outcome::_1_0_std_std_9274c0d4::policy::result_policy<int> >, int, boost::outcome::_1_0_std_std_9274c0d4::error_code_extended, void>::_throw_error(boost::outcome::_1_0_std_std_9274c0d4::monad_errc)+0x48>
  40107c:	bf b8 21 60 00       	mov    $0x6021b8,%edi
  400d60:	ff 25 c2 12 20 00    	jmpq   *0x2012c2(%rip)        # 602028 <_GLOBAL_OFFSET_TABLE_+0x28>
  400d66:	68 02 00 00 00       	pushq  $0x2
  400d6b:	e9 c0 ff ff ff       	jmpq   400d30 <_init+0x28>
  401086:	85 c0                	test   %eax,%eax
  401088:	74 1e                	je     4010a8 <boost::outcome::_1_0_std_std_9274c0d4::policy::result_policy_base<boost::outcome::_1_0_std_std_9274c0d4::policy::basic_monad_storage<boost::outcome::_1_0_std_std_9274c0d4::policy::result_policy<int> >, int, boost::outcome::_1_0_std_std_9274c0d4::error_code_extended, void>::_throw_error(boost::outcome::_1_0_std_std_9274c0d4::monad_errc)+0x48>
  40108a:	bf 40 0d 40 00       	mov    $0x400d40,%edi
  40108f:	be d8 20 60 00       	mov    $0x6020d8,%esi
  401094:	ba d0 20 60 00       	mov    $0x6020d0,%edx
  400db0:	ff 25 9a 12 20 00    	jmpq   *0x20129a(%rip)        # 602050 <_GLOBAL_OFFSET_TABLE_+0x50>
  400db6:	68 07 00 00 00       	pushq  $0x7
  400dbb:	e9 70 ff ff ff       	jmpq   400d30 <_init+0x28>
  40109e:	bf b8 21 60 00       	mov    $0x6021b8,%edi
  400de0:	ff 25 82 12 20 00    	jmpq   *0x201282(%rip)        # 602068 <_GLOBAL_OFFSET_TABLE_+0x68>
  400de6:	68 0a 00 00 00       	pushq  $0xa
  400deb:	e9 40 ff ff ff       	jmpq   400d30 <_init+0x28>
  4010a8:	ba d8 20 60 00       	mov    $0x6020d8,%edx
  4010ad:	48 89 df             	mov    %rbx,%rdi
  4010b0:	89 ee                	mov    %ebp,%esi
  4011c0:	55                   	push   %rbp
  4011c1:	41 57                	push   %r15
  4011c3:	41 56                	push   %r14
  4011c5:	53                   	push   %rbx
  4011c6:	48 83 ec 18          	sub    $0x18,%rsp
  4011ca:	49 89 d6             	mov    %rdx,%r14
  4011cd:	41 89 f7             	mov    %esi,%r15d
  4011d0:	48 89 fb             	mov    %rdi,%rbx
  4011d3:	49 8b 06             	mov    (%r14),%rax
  4011d6:	48 8d 6c 24 10       	lea    0x10(%rsp),%rbp
  4011db:	48 89 ef             	mov    %rbp,%rdi
  4011de:	4c 89 f6             	mov    %r14,%rsi
  4011e1:	44 89 fa             	mov    %r15d,%edx
  4011e4:	ff 50 18             	callq  *0x18(%rax)
  4011e7:	48 89 df             	mov    %rbx,%rdi
  4011ea:	48 89 ee             	mov    %rbp,%rsi
  400d70:	ff 25 ba 12 20 00    	jmpq   *0x2012ba(%rip)        # 602030 <_GLOBAL_OFFSET_TABLE_+0x30>
  400d76:	68 03 00 00 00       	pushq  $0x3
  400d7b:	e9 b0 ff ff ff       	jmpq   400d30 <_init+0x28>
  4011f2:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  4011f7:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  4011fb:	b9 80 21 60 00       	mov    $0x602180,%ecx
  401200:	48 39 cf             	cmp    %rcx,%rdi
  401203:	75 1a                	jne    40121f <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0x5f>
  401205:	44 89 7b 10          	mov    %r15d,0x10(%rbx)
  401209:	4c 89 73 18          	mov    %r14,0x18(%rbx)
  40120d:	48 c7 03 68 15 40 00 	movq   $0x401568,(%rbx)
  401214:	48 83 c4 18          	add    $0x18,%rsp
  401218:	5b                   	pop    %rbx
  401219:	41 5e                	pop    %r14
  40121b:	41 5f                	pop    %r15
  40121d:	5d                   	pop    %rbp
  40121e:	c3                   	retq
  40121f:	b9 00 00 00 00       	mov    $0x0,%ecx
  401224:	48 85 c9             	test   %rcx,%rcx
  401227:	74 10                	je     401239 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0x79>
  401229:	b9 ff ff ff ff       	mov    $0xffffffff,%ecx
  40122e:	f0 0f c1 48 f8       	lock xadd %ecx,-0x8(%rax)
  401233:	85 c9                	test   %ecx,%ecx
  401235:	7f ce                	jg     401205 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0x45>
  401237:	eb 0d                	jmp    401246 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0x86>
  401239:	8b 48 f8             	mov    -0x8(%rax),%ecx
  40123c:	8d 51 ff             	lea    -0x1(%rcx),%edx
  40123f:	89 50 f8             	mov    %edx,-0x8(%rax)
  401242:	85 c9                	test   %ecx,%ecx
  401244:	7f bf                	jg     401205 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0x45>
  401246:	48 89 e6             	mov    %rsp,%rsi
  400dc0:	ff 25 92 12 20 00    	jmpq   *0x201292(%rip)        # 602058 <_GLOBAL_OFFSET_TABLE_+0x58>
  400dc6:	68 08 00 00 00       	pushq  $0x8
  400dcb:	e9 60 ff ff ff       	jmpq   400d30 <_init+0x28>
  40124e:	eb b5                	jmp    401205 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0x45>
  401250:	48 89 c3             	mov    %rax,%rbx
  401253:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  401258:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  40125c:	b9 80 21 60 00       	mov    $0x602180,%ecx
  401261:	48 39 cf             	cmp    %rcx,%rdi
  401264:	74 31                	je     401297 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0xd7>
  401266:	b9 00 00 00 00       	mov    $0x0,%ecx
  40126b:	48 85 c9             	test   %rcx,%rcx
  40126e:	74 10                	je     401280 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0xc0>
  401270:	b9 ff ff ff ff       	mov    $0xffffffff,%ecx
  401275:	f0 0f c1 48 f8       	lock xadd %ecx,-0x8(%rax)
  40127a:	85 c9                	test   %ecx,%ecx
  40127c:	7e 0f                	jle    40128d <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0xcd>
  40127e:	eb 17                	jmp    401297 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0xd7>
  401280:	8b 48 f8             	mov    -0x8(%rax),%ecx
  401283:	8d 51 ff             	lea    -0x1(%rcx),%edx
  401286:	89 50 f8             	mov    %edx,-0x8(%rax)
  401289:	85 c9                	test   %ecx,%ecx
  40128b:	7f 0a                	jg     401297 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0xd7>
  40128d:	48 8d 74 24 08       	lea    0x8(%rsp),%rsi
  401292:	e8 29 fb ff ff       	callq  400dc0 <std::string::_Rep::_M_destroy(std::allocator<char> const&)@plt>
  401297:	48 89 df             	mov    %rbx,%rdi
  400e80:	ff 25 32 12 20 00    	jmpq   *0x201232(%rip)        # 6020b8 <_GLOBAL_OFFSET_TABLE_+0xb8>
  400e86:	68 14 00 00 00       	pushq  $0x14
  400e8b:	e9 a0 fe ff ff       	jmpq   400d30 <_init+0x28>
  40129f:	90                   	nop
  4010b7:	be 50 14 40 00       	mov    $0x401450,%esi
  4010bc:	ba 50 0d 40 00       	mov    $0x400d50,%edx
  4010c1:	48 89 df             	mov    %rbx,%rdi
  400e50:	ff 25 4a 12 20 00    	jmpq   *0x20124a(%rip)        # 6020a0 <_GLOBAL_OFFSET_TABLE_+0xa0>
  400e56:	68 11 00 00 00       	pushq  $0x11
  400e5b:	e9 d0 fe ff ff       	jmpq   400d30 <_init+0x28>
  4010c9:	48 89 c5             	mov    %rax,%rbp
  4010cc:	48 89 df             	mov    %rbx,%rdi
  400e40:	ff 25 52 12 20 00    	jmpq   *0x201252(%rip)        # 602098 <_GLOBAL_OFFSET_TABLE_+0x98>
  400e46:	68 10 00 00 00       	pushq  $0x10
  400e4b:	e9 e0 fe ff ff       	jmpq   400d30 <_init+0x28>
  4010d4:	48 89 ef             	mov    %rbp,%rdi
  4010d7:	e8 a4 fd ff ff       	callq  400e80 <_Unwind_Resume@plt>
  4010dc:	0f 1f 40 00          	nopl   0x0(%rax)
  401000:	43 8d 04 76          	lea    (%r14,%r14,2),%eax
  401004:	89 03                	mov    %eax,(%rbx)
  401006:	c6 43 18 01          	movb   $0x1,0x18(%rbx)
  40100a:	48 89 d8             	mov    %rbx,%rax
  40100d:	48 83 c4 20          	add    $0x20,%rsp
  401011:	5b                   	pop    %rbx
  401012:	41 5e                	pop    %r14
  401014:	41 5f                	pop    %r15
  401016:	c3                   	retq
  401017:	49 89 c6             	mov    %rax,%r14
  40101a:	48 89 df             	mov    %rbx,%rdi
  400e40:	ff 25 52 12 20 00    	jmpq   *0x201252(%rip)        # 602098 <_GLOBAL_OFFSET_TABLE_+0x98>
  400e46:	68 10 00 00 00       	pushq  $0x10
  400e4b:	e9 e0 fe ff ff       	jmpq   400d30 <_init+0x28>
  401022:	4c 89 f7             	mov    %r14,%rdi
  400e80:	ff 25 32 12 20 00    	jmpq   *0x201232(%rip)        # 6020b8 <_GLOBAL_OFFSET_TABLE_+0xb8>
  400e86:	68 14 00 00 00       	pushq  $0x14
  400e8b:	e9 a0 fe ff ff       	jmpq   400d30 <_init+0x28>
  40102a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
