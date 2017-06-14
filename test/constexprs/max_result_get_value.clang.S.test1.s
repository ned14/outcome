  400fa0:	41 56                	push   %r14
  400fa2:	53                   	push   %rbx
  400fa3:	48 83 ec 28          	sub    $0x28,%rsp
  400fa7:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  400fac:	e8 4f f0 bf ff       	callq  0 <_init-0x400d08>
  400fb1:	8a 44 24 20          	mov    0x20(%rsp),%al
  400fb5:	84 c0                	test   %al,%al
  400fb7:	75 0e                	jne    400fc7 <test1()+0x27>
  400fb9:	bf 02 00 00 00       	mov    $0x2,%edi
  401050:	55                   	push   %rbp
  401051:	53                   	push   %rbx
  401052:	50                   	push   %rax
  401053:	89 fd                	mov    %edi,%ebp
  401055:	bf 20 00 00 00       	mov    $0x20,%edi
  400e30:	ff 25 5a 12 20 00    	jmpq   *0x20125a(%rip)        # 602090 <_GLOBAL_OFFSET_TABLE_+0x90>
  400e36:	68 0f 00 00 00       	pushq  $0xf
  400e3b:	e9 f0 fe ff ff       	jmpq   400d30 <_init+0x28>
  40105f:	48 89 c3             	mov    %rax,%rbx
  401062:	8a 05 50 11 20 00    	mov    0x201150(%rip),%al        # 6021b8 <guard variable for boost::outcome::_1_0_std_std_9274c0d4::monad_category()::c>
  401068:	84 c0                	test   %al,%al
  40106a:	75 2c                	jne    401098 <boost::outcome::_1_0_std_std_9274c0d4::policy::result_policy_base<boost::outcome::_1_0_std_std_9274c0d4::policy::basic_monad_storage<boost::outcome::_1_0_std_std_9274c0d4::policy::result_policy<int> >, int, boost::outcome::_1_0_std_std_9274c0d4::error_code_extended, void>::_throw_error(boost::outcome::_1_0_std_std_9274c0d4::monad_errc)+0x48>
  40106c:	bf b8 21 60 00       	mov    $0x6021b8,%edi
  400d60:	ff 25 c2 12 20 00    	jmpq   *0x2012c2(%rip)        # 602028 <_GLOBAL_OFFSET_TABLE_+0x28>
  400d66:	68 02 00 00 00       	pushq  $0x2
  400d6b:	e9 c0 ff ff ff       	jmpq   400d30 <_init+0x28>
  401076:	85 c0                	test   %eax,%eax
  401078:	74 1e                	je     401098 <boost::outcome::_1_0_std_std_9274c0d4::policy::result_policy_base<boost::outcome::_1_0_std_std_9274c0d4::policy::basic_monad_storage<boost::outcome::_1_0_std_std_9274c0d4::policy::result_policy<int> >, int, boost::outcome::_1_0_std_std_9274c0d4::error_code_extended, void>::_throw_error(boost::outcome::_1_0_std_std_9274c0d4::monad_errc)+0x48>
  40107a:	bf 40 0d 40 00       	mov    $0x400d40,%edi
  40107f:	be d8 20 60 00       	mov    $0x6020d8,%esi
  401084:	ba d0 20 60 00       	mov    $0x6020d0,%edx
  400db0:	ff 25 9a 12 20 00    	jmpq   *0x20129a(%rip)        # 602050 <_GLOBAL_OFFSET_TABLE_+0x50>
  400db6:	68 07 00 00 00       	pushq  $0x7
  400dbb:	e9 70 ff ff ff       	jmpq   400d30 <_init+0x28>
  40108e:	bf b8 21 60 00       	mov    $0x6021b8,%edi
  400de0:	ff 25 82 12 20 00    	jmpq   *0x201282(%rip)        # 602068 <_GLOBAL_OFFSET_TABLE_+0x68>
  400de6:	68 0a 00 00 00       	pushq  $0xa
  400deb:	e9 40 ff ff ff       	jmpq   400d30 <_init+0x28>
  401098:	ba d8 20 60 00       	mov    $0x6020d8,%edx
  40109d:	48 89 df             	mov    %rbx,%rdi
  4010a0:	89 ee                	mov    %ebp,%esi
  4011b0:	55                   	push   %rbp
  4011b1:	41 57                	push   %r15
  4011b3:	41 56                	push   %r14
  4011b5:	53                   	push   %rbx
  4011b6:	48 83 ec 18          	sub    $0x18,%rsp
  4011ba:	49 89 d6             	mov    %rdx,%r14
  4011bd:	41 89 f7             	mov    %esi,%r15d
  4011c0:	48 89 fb             	mov    %rdi,%rbx
  4011c3:	49 8b 06             	mov    (%r14),%rax
  4011c6:	48 8d 6c 24 10       	lea    0x10(%rsp),%rbp
  4011cb:	48 89 ef             	mov    %rbp,%rdi
  4011ce:	4c 89 f6             	mov    %r14,%rsi
  4011d1:	44 89 fa             	mov    %r15d,%edx
  4011d4:	ff 50 18             	callq  *0x18(%rax)
  4011d7:	48 89 df             	mov    %rbx,%rdi
  4011da:	48 89 ee             	mov    %rbp,%rsi
  400d70:	ff 25 ba 12 20 00    	jmpq   *0x2012ba(%rip)        # 602030 <_GLOBAL_OFFSET_TABLE_+0x30>
  400d76:	68 03 00 00 00       	pushq  $0x3
  400d7b:	e9 b0 ff ff ff       	jmpq   400d30 <_init+0x28>
  4011e2:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  4011e7:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  4011eb:	b9 80 21 60 00       	mov    $0x602180,%ecx
  4011f0:	48 39 cf             	cmp    %rcx,%rdi
  4011f3:	75 1a                	jne    40120f <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0x5f>
  4011f5:	44 89 7b 10          	mov    %r15d,0x10(%rbx)
  4011f9:	4c 89 73 18          	mov    %r14,0x18(%rbx)
  4011fd:	48 c7 03 58 15 40 00 	movq   $0x401558,(%rbx)
  401204:	48 83 c4 18          	add    $0x18,%rsp
  401208:	5b                   	pop    %rbx
  401209:	41 5e                	pop    %r14
  40120b:	41 5f                	pop    %r15
  40120d:	5d                   	pop    %rbp
  40120e:	c3                   	retq
  40120f:	b9 00 00 00 00       	mov    $0x0,%ecx
  401214:	48 85 c9             	test   %rcx,%rcx
  401217:	74 10                	je     401229 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0x79>
  401219:	b9 ff ff ff ff       	mov    $0xffffffff,%ecx
  40121e:	f0 0f c1 48 f8       	lock xadd %ecx,-0x8(%rax)
  401223:	85 c9                	test   %ecx,%ecx
  401225:	7f ce                	jg     4011f5 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0x45>
  401227:	eb 0d                	jmp    401236 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0x86>
  401229:	8b 48 f8             	mov    -0x8(%rax),%ecx
  40122c:	8d 51 ff             	lea    -0x1(%rcx),%edx
  40122f:	89 50 f8             	mov    %edx,-0x8(%rax)
  401232:	85 c9                	test   %ecx,%ecx
  401234:	7f bf                	jg     4011f5 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0x45>
  401236:	48 89 e6             	mov    %rsp,%rsi
  400dc0:	ff 25 92 12 20 00    	jmpq   *0x201292(%rip)        # 602058 <_GLOBAL_OFFSET_TABLE_+0x58>
  400dc6:	68 08 00 00 00       	pushq  $0x8
  400dcb:	e9 60 ff ff ff       	jmpq   400d30 <_init+0x28>
  40123e:	eb b5                	jmp    4011f5 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0x45>
  401240:	48 89 c3             	mov    %rax,%rbx
  401243:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  401248:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  40124c:	b9 80 21 60 00       	mov    $0x602180,%ecx
  401251:	48 39 cf             	cmp    %rcx,%rdi
  401254:	74 31                	je     401287 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0xd7>
  401256:	b9 00 00 00 00       	mov    $0x0,%ecx
  40125b:	48 85 c9             	test   %rcx,%rcx
  40125e:	74 10                	je     401270 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0xc0>
  401260:	b9 ff ff ff ff       	mov    $0xffffffff,%ecx
  401265:	f0 0f c1 48 f8       	lock xadd %ecx,-0x8(%rax)
  40126a:	85 c9                	test   %ecx,%ecx
  40126c:	7e 0f                	jle    40127d <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0xcd>
  40126e:	eb 17                	jmp    401287 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0xd7>
  401270:	8b 48 f8             	mov    -0x8(%rax),%ecx
  401273:	8d 51 ff             	lea    -0x1(%rcx),%edx
  401276:	89 50 f8             	mov    %edx,-0x8(%rax)
  401279:	85 c9                	test   %ecx,%ecx
  40127b:	7f 0a                	jg     401287 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0xd7>
  40127d:	48 8d 74 24 08       	lea    0x8(%rsp),%rsi
  401282:	e8 39 fb ff ff       	callq  400dc0 <std::string::_Rep::_M_destroy(std::allocator<char> const&)@plt>
  401287:	48 89 df             	mov    %rbx,%rdi
  400e80:	ff 25 32 12 20 00    	jmpq   *0x201232(%rip)        # 6020b8 <_GLOBAL_OFFSET_TABLE_+0xb8>
  400e86:	68 14 00 00 00       	pushq  $0x14
  400e8b:	e9 a0 fe ff ff       	jmpq   400d30 <_init+0x28>
  40128f:	90                   	nop
  4010a7:	be 40 14 40 00       	mov    $0x401440,%esi
  4010ac:	ba 50 0d 40 00       	mov    $0x400d50,%edx
  4010b1:	48 89 df             	mov    %rbx,%rdi
  400e50:	ff 25 4a 12 20 00    	jmpq   *0x20124a(%rip)        # 6020a0 <_GLOBAL_OFFSET_TABLE_+0xa0>
  400e56:	68 11 00 00 00       	pushq  $0x11
  400e5b:	e9 d0 fe ff ff       	jmpq   400d30 <_init+0x28>
  4010b9:	48 89 c5             	mov    %rax,%rbp
  4010bc:	48 89 df             	mov    %rbx,%rdi
  400e40:	ff 25 52 12 20 00    	jmpq   *0x201252(%rip)        # 602098 <_GLOBAL_OFFSET_TABLE_+0x98>
  400e46:	68 10 00 00 00       	pushq  $0x10
  400e4b:	e9 e0 fe ff ff       	jmpq   400d30 <_init+0x28>
  4010c4:	48 89 ef             	mov    %rbp,%rdi
  4010c7:	e8 b4 fd ff ff       	callq  400e80 <_Unwind_Resume@plt>
  4010cc:	0f 1f 40 00          	nopl   0x0(%rax)
  400fc3:	8a 44 24 20          	mov    0x20(%rsp),%al
  400fc7:	3c 02                	cmp    $0x2,%al
  400fc9:	74 0c                	je     400fd7 <test1()+0x37>
  400fcb:	8b 44 24 08          	mov    0x8(%rsp),%eax
  400fcf:	48 83 c4 28          	add    $0x28,%rsp
  400fd3:	5b                   	pop    %rbx
  400fd4:	41 5e                	pop    %r14
  400fd6:	c3                   	retq
  400fd7:	bf 20 00 00 00       	mov    $0x20,%edi
  400e30:	ff 25 5a 12 20 00    	jmpq   *0x20125a(%rip)        # 602090 <_GLOBAL_OFFSET_TABLE_+0x90>
  400e36:	68 0f 00 00 00       	pushq  $0xf
  400e3b:	e9 f0 fe ff ff       	jmpq   400d30 <_init+0x28>
  400fe1:	48 89 c3             	mov    %rax,%rbx
  400fe4:	8b 74 24 08          	mov    0x8(%rsp),%esi
  400fe8:	48 8b 54 24 10       	mov    0x10(%rsp),%rdx
  400fed:	48 89 df             	mov    %rbx,%rdi
  4010d0:	55                   	push   %rbp
  4010d1:	41 57                	push   %r15
  4010d3:	41 56                	push   %r14
  4010d5:	53                   	push   %rbx
  4010d6:	48 83 ec 18          	sub    $0x18,%rsp
  4010da:	49 89 d6             	mov    %rdx,%r14
  4010dd:	41 89 f7             	mov    %esi,%r15d
  4010e0:	48 89 fb             	mov    %rdi,%rbx
  4010e3:	49 8b 06             	mov    (%r14),%rax
  4010e6:	48 8d 6c 24 10       	lea    0x10(%rsp),%rbp
  4010eb:	48 89 ef             	mov    %rbp,%rdi
  4010ee:	4c 89 f6             	mov    %r14,%rsi
  4010f1:	44 89 fa             	mov    %r15d,%edx
  4010f4:	ff 50 18             	callq  *0x18(%rax)
  4010f7:	48 89 df             	mov    %rbx,%rdi
  4010fa:	48 89 ee             	mov    %rbp,%rsi
  400d70:	ff 25 ba 12 20 00    	jmpq   *0x2012ba(%rip)        # 602030 <_GLOBAL_OFFSET_TABLE_+0x30>
  400d76:	68 03 00 00 00       	pushq  $0x3
  400d7b:	e9 b0 ff ff ff       	jmpq   400d30 <_init+0x28>
  401102:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  401107:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  40110b:	b9 80 21 60 00       	mov    $0x602180,%ecx
  401110:	48 39 cf             	cmp    %rcx,%rdi
  401113:	75 1a                	jne    40112f <std::system_error::system_error(std::error_code)+0x5f>
  401115:	48 c7 03 08 21 60 00 	movq   $0x602108,(%rbx)
  40111c:	44 89 7b 10          	mov    %r15d,0x10(%rbx)
  401120:	4c 89 73 18          	mov    %r14,0x18(%rbx)
  401124:	48 83 c4 18          	add    $0x18,%rsp
  401128:	5b                   	pop    %rbx
  401129:	41 5e                	pop    %r14
  40112b:	41 5f                	pop    %r15
  40112d:	5d                   	pop    %rbp
  40112e:	c3                   	retq
  40112f:	b9 00 00 00 00       	mov    $0x0,%ecx
  401134:	48 85 c9             	test   %rcx,%rcx
  401137:	74 10                	je     401149 <std::system_error::system_error(std::error_code)+0x79>
  401139:	b9 ff ff ff ff       	mov    $0xffffffff,%ecx
  40113e:	f0 0f c1 48 f8       	lock xadd %ecx,-0x8(%rax)
  401143:	85 c9                	test   %ecx,%ecx
  401145:	7f ce                	jg     401115 <std::system_error::system_error(std::error_code)+0x45>
  401147:	eb 0d                	jmp    401156 <std::system_error::system_error(std::error_code)+0x86>
  401149:	8b 48 f8             	mov    -0x8(%rax),%ecx
  40114c:	8d 51 ff             	lea    -0x1(%rcx),%edx
  40114f:	89 50 f8             	mov    %edx,-0x8(%rax)
  401152:	85 c9                	test   %ecx,%ecx
  401154:	7f bf                	jg     401115 <std::system_error::system_error(std::error_code)+0x45>
  401156:	48 89 e6             	mov    %rsp,%rsi
  400dc0:	ff 25 92 12 20 00    	jmpq   *0x201292(%rip)        # 602058 <_GLOBAL_OFFSET_TABLE_+0x58>
  400dc6:	68 08 00 00 00       	pushq  $0x8
  400dcb:	e9 60 ff ff ff       	jmpq   400d30 <_init+0x28>
  40115e:	eb b5                	jmp    401115 <std::system_error::system_error(std::error_code)+0x45>
  401160:	48 89 c3             	mov    %rax,%rbx
  401163:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  401168:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  40116c:	b9 80 21 60 00       	mov    $0x602180,%ecx
  401171:	48 39 cf             	cmp    %rcx,%rdi
  401174:	74 31                	je     4011a7 <std::system_error::system_error(std::error_code)+0xd7>
  401176:	b9 00 00 00 00       	mov    $0x0,%ecx
  40117b:	48 85 c9             	test   %rcx,%rcx
  40117e:	74 10                	je     401190 <std::system_error::system_error(std::error_code)+0xc0>
  401180:	b9 ff ff ff ff       	mov    $0xffffffff,%ecx
  401185:	f0 0f c1 48 f8       	lock xadd %ecx,-0x8(%rax)
  40118a:	85 c9                	test   %ecx,%ecx
  40118c:	7e 0f                	jle    40119d <std::system_error::system_error(std::error_code)+0xcd>
  40118e:	eb 17                	jmp    4011a7 <std::system_error::system_error(std::error_code)+0xd7>
  401190:	8b 48 f8             	mov    -0x8(%rax),%ecx
  401193:	8d 51 ff             	lea    -0x1(%rcx),%edx
  401196:	89 50 f8             	mov    %edx,-0x8(%rax)
  401199:	85 c9                	test   %ecx,%ecx
  40119b:	7f 0a                	jg     4011a7 <std::system_error::system_error(std::error_code)+0xd7>
  40119d:	48 8d 74 24 08       	lea    0x8(%rsp),%rsi
  4011a2:	e8 19 fc ff ff       	callq  400dc0 <std::string::_Rep::_M_destroy(std::allocator<char> const&)@plt>
  4011a7:	48 89 df             	mov    %rbx,%rdi
  400e80:	ff 25 32 12 20 00    	jmpq   *0x201232(%rip)        # 6020b8 <_GLOBAL_OFFSET_TABLE_+0xb8>
  400e86:	68 14 00 00 00       	pushq  $0x14
  400e8b:	e9 a0 fe ff ff       	jmpq   400d30 <_init+0x28>
  4011af:	90                   	nop
  400ff5:	be e0 20 60 00       	mov    $0x6020e0,%esi
  400ffa:	ba f0 0d 40 00       	mov    $0x400df0,%edx
  400fff:	48 89 df             	mov    %rbx,%rdi
  400e50:	ff 25 4a 12 20 00    	jmpq   *0x20124a(%rip)        # 6020a0 <_GLOBAL_OFFSET_TABLE_+0xa0>
  400e56:	68 11 00 00 00       	pushq  $0x11
  400e5b:	e9 d0 fe ff ff       	jmpq   400d30 <_init+0x28>
  401007:	49 89 c6             	mov    %rax,%r14
  40100a:	48 89 df             	mov    %rbx,%rdi
  400e40:	ff 25 52 12 20 00    	jmpq   *0x201252(%rip)        # 602098 <_GLOBAL_OFFSET_TABLE_+0x98>
  400e46:	68 10 00 00 00       	pushq  $0x10
  400e4b:	e9 e0 fe ff ff       	jmpq   400d30 <_init+0x28>
  401012:	4c 89 f7             	mov    %r14,%rdi
  400e80:	ff 25 32 12 20 00    	jmpq   *0x201232(%rip)        # 6020b8 <_GLOBAL_OFFSET_TABLE_+0xb8>
  400e86:	68 14 00 00 00       	pushq  $0x14
  400e8b:	e9 a0 fe ff ff       	jmpq   400d30 <_init+0x28>
  40101a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
