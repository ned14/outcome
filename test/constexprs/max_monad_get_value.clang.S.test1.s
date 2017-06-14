  401110:	55                   	push   %rbp
  401111:	41 56                	push   %r14
  401113:	53                   	push   %rbx
  401114:	48 83 ec 30          	sub    $0x30,%rsp
  401118:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
  40111d:	e8 de ee bf ff       	callq  0 <_init-0x400e50>
  401122:	8a 44 24 28          	mov    0x28(%rsp),%al
  401126:	84 c0                	test   %al,%al
  401128:	75 0e                	jne    401138 <test1()+0x28>
  40112a:	bf 02 00 00 00       	mov    $0x2,%edi
  4012f0:	55                   	push   %rbp
  4012f1:	53                   	push   %rbx
  4012f2:	50                   	push   %rax
  4012f3:	89 fd                	mov    %edi,%ebp
  4012f5:	bf 20 00 00 00       	mov    $0x20,%edi
  400f80:	ff 25 12 11 20 00    	jmpq   *0x201112(%rip)        # 602098 <_GLOBAL_OFFSET_TABLE_+0x98>
  400f86:	68 10 00 00 00       	pushq  $0x10
  400f8b:	e9 e0 fe ff ff       	jmpq   400e70 <_init+0x20>
  4012ff:	48 89 c3             	mov    %rax,%rbx
  401302:	8a 05 d0 0e 20 00    	mov    0x200ed0(%rip),%al        # 6021d8 <guard variable for boost::outcome::_1_0_std_std_9274c0d4::monad_category()::c>
  401308:	84 c0                	test   %al,%al
  40130a:	75 2c                	jne    401338 <boost::outcome::_1_0_std_std_9274c0d4::policy::monad_policy_base<boost::outcome::_1_0_std_std_9274c0d4::policy::basic_monad_storage<boost::outcome::_1_0_std_std_9274c0d4::policy::monad_policy<int> >, int, boost::outcome::_1_0_std_std_9274c0d4::error_code_extended, std::__exception_ptr::exception_ptr>::_throw_error(boost::outcome::_1_0_std_std_9274c0d4::monad_errc)+0x48>
  40130c:	bf d8 21 60 00       	mov    $0x6021d8,%edi
  400ea0:	ff 25 82 11 20 00    	jmpq   *0x201182(%rip)        # 602028 <_GLOBAL_OFFSET_TABLE_+0x28>
  400ea6:	68 02 00 00 00       	pushq  $0x2
  400eab:	e9 c0 ff ff ff       	jmpq   400e70 <_init+0x20>
  401316:	85 c0                	test   %eax,%eax
  401318:	74 1e                	je     401338 <boost::outcome::_1_0_std_std_9274c0d4::policy::monad_policy_base<boost::outcome::_1_0_std_std_9274c0d4::policy::basic_monad_storage<boost::outcome::_1_0_std_std_9274c0d4::policy::monad_policy<int> >, int, boost::outcome::_1_0_std_std_9274c0d4::error_code_extended, std::__exception_ptr::exception_ptr>::_throw_error(boost::outcome::_1_0_std_std_9274c0d4::monad_errc)+0x48>
  40131a:	bf 80 0e 40 00       	mov    $0x400e80,%edi
  40131f:	be f0 20 60 00       	mov    $0x6020f0,%esi
  401324:	ba e8 20 60 00       	mov    $0x6020e8,%edx
  400ef0:	ff 25 5a 11 20 00    	jmpq   *0x20115a(%rip)        # 602050 <_GLOBAL_OFFSET_TABLE_+0x50>
  400ef6:	68 07 00 00 00       	pushq  $0x7
  400efb:	e9 70 ff ff ff       	jmpq   400e70 <_init+0x20>
  40132e:	bf d8 21 60 00       	mov    $0x6021d8,%edi
  400f20:	ff 25 42 11 20 00    	jmpq   *0x201142(%rip)        # 602068 <_GLOBAL_OFFSET_TABLE_+0x68>
  400f26:	68 0a 00 00 00       	pushq  $0xa
  400f2b:	e9 40 ff ff ff       	jmpq   400e70 <_init+0x20>
  401338:	ba f0 20 60 00       	mov    $0x6020f0,%edx
  40133d:	48 89 df             	mov    %rbx,%rdi
  401340:	89 ee                	mov    %ebp,%esi
  401370:	55                   	push   %rbp
  401371:	41 57                	push   %r15
  401373:	41 56                	push   %r14
  401375:	53                   	push   %rbx
  401376:	48 83 ec 18          	sub    $0x18,%rsp
  40137a:	49 89 d6             	mov    %rdx,%r14
  40137d:	41 89 f7             	mov    %esi,%r15d
  401380:	48 89 fb             	mov    %rdi,%rbx
  401383:	49 8b 06             	mov    (%r14),%rax
  401386:	48 8d 6c 24 10       	lea    0x10(%rsp),%rbp
  40138b:	48 89 ef             	mov    %rbp,%rdi
  40138e:	4c 89 f6             	mov    %r14,%rsi
  401391:	44 89 fa             	mov    %r15d,%edx
  401394:	ff 50 18             	callq  *0x18(%rax)
  401397:	48 89 df             	mov    %rbx,%rdi
  40139a:	48 89 ee             	mov    %rbp,%rsi
  400eb0:	ff 25 7a 11 20 00    	jmpq   *0x20117a(%rip)        # 602030 <_GLOBAL_OFFSET_TABLE_+0x30>
  400eb6:	68 03 00 00 00       	pushq  $0x3
  400ebb:	e9 b0 ff ff ff       	jmpq   400e70 <_init+0x20>
  4013a2:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  4013a7:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  4013ab:	b9 a0 21 60 00       	mov    $0x6021a0,%ecx
  4013b0:	48 39 cf             	cmp    %rcx,%rdi
  4013b3:	75 1a                	jne    4013cf <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0x5f>
  4013b5:	44 89 7b 10          	mov    %r15d,0x10(%rbx)
  4013b9:	4c 89 73 18          	mov    %r14,0x18(%rbx)
  4013bd:	48 c7 03 18 17 40 00 	movq   $0x401718,(%rbx)
  4013c4:	48 83 c4 18          	add    $0x18,%rsp
  4013c8:	5b                   	pop    %rbx
  4013c9:	41 5e                	pop    %r14
  4013cb:	41 5f                	pop    %r15
  4013cd:	5d                   	pop    %rbp
  4013ce:	c3                   	retq
  4013cf:	b9 00 00 00 00       	mov    $0x0,%ecx
  4013d4:	48 85 c9             	test   %rcx,%rcx
  4013d7:	74 10                	je     4013e9 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0x79>
  4013d9:	b9 ff ff ff ff       	mov    $0xffffffff,%ecx
  4013de:	f0 0f c1 48 f8       	lock xadd %ecx,-0x8(%rax)
  4013e3:	85 c9                	test   %ecx,%ecx
  4013e5:	7f ce                	jg     4013b5 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0x45>
  4013e7:	eb 0d                	jmp    4013f6 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0x86>
  4013e9:	8b 48 f8             	mov    -0x8(%rax),%ecx
  4013ec:	8d 51 ff             	lea    -0x1(%rcx),%edx
  4013ef:	89 50 f8             	mov    %edx,-0x8(%rax)
  4013f2:	85 c9                	test   %ecx,%ecx
  4013f4:	7f bf                	jg     4013b5 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0x45>
  4013f6:	48 89 e6             	mov    %rsp,%rsi
  400f00:	ff 25 52 11 20 00    	jmpq   *0x201152(%rip)        # 602058 <_GLOBAL_OFFSET_TABLE_+0x58>
  400f06:	68 08 00 00 00       	pushq  $0x8
  400f0b:	e9 60 ff ff ff       	jmpq   400e70 <_init+0x20>
  4013fe:	eb b5                	jmp    4013b5 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0x45>
  401400:	48 89 c3             	mov    %rax,%rbx
  401403:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  401408:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  40140c:	b9 a0 21 60 00       	mov    $0x6021a0,%ecx
  401411:	48 39 cf             	cmp    %rcx,%rdi
  401414:	74 31                	je     401447 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0xd7>
  401416:	b9 00 00 00 00       	mov    $0x0,%ecx
  40141b:	48 85 c9             	test   %rcx,%rcx
  40141e:	74 10                	je     401430 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0xc0>
  401420:	b9 ff ff ff ff       	mov    $0xffffffff,%ecx
  401425:	f0 0f c1 48 f8       	lock xadd %ecx,-0x8(%rax)
  40142a:	85 c9                	test   %ecx,%ecx
  40142c:	7e 0f                	jle    40143d <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0xcd>
  40142e:	eb 17                	jmp    401447 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0xd7>
  401430:	8b 48 f8             	mov    -0x8(%rax),%ecx
  401433:	8d 51 ff             	lea    -0x1(%rcx),%edx
  401436:	89 50 f8             	mov    %edx,-0x8(%rax)
  401439:	85 c9                	test   %ecx,%ecx
  40143b:	7f 0a                	jg     401447 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0xd7>
  40143d:	48 8d 74 24 08       	lea    0x8(%rsp),%rsi
  401442:	e8 b9 fa ff ff       	callq  400f00 <std::string::_Rep::_M_destroy(std::allocator<char> const&)@plt>
  401447:	48 89 df             	mov    %rbx,%rdi
  400fe0:	ff 25 e2 10 20 00    	jmpq   *0x2010e2(%rip)        # 6020c8 <_GLOBAL_OFFSET_TABLE_+0xc8>
  400fe6:	68 16 00 00 00       	pushq  $0x16
  400feb:	e9 80 fe ff ff       	jmpq   400e70 <_init+0x20>
  40144f:	90                   	nop
  401347:	be 00 16 40 00       	mov    $0x401600,%esi
  40134c:	ba 90 0e 40 00       	mov    $0x400e90,%edx
  401351:	48 89 df             	mov    %rbx,%rdi
  400fa0:	ff 25 02 11 20 00    	jmpq   *0x201102(%rip)        # 6020a8 <_GLOBAL_OFFSET_TABLE_+0xa8>
  400fa6:	68 12 00 00 00       	pushq  $0x12
  400fab:	e9 c0 fe ff ff       	jmpq   400e70 <_init+0x20>
  401359:	48 89 c5             	mov    %rax,%rbp
  40135c:	48 89 df             	mov    %rbx,%rdi
  400f90:	ff 25 0a 11 20 00    	jmpq   *0x20110a(%rip)        # 6020a0 <_GLOBAL_OFFSET_TABLE_+0xa0>
  400f96:	68 11 00 00 00       	pushq  $0x11
  400f9b:	e9 d0 fe ff ff       	jmpq   400e70 <_init+0x20>
  401364:	48 89 ef             	mov    %rbp,%rdi
  401367:	e8 74 fc ff ff       	callq  400fe0 <_Unwind_Resume@plt>
  40136c:	0f 1f 40 00          	nopl   0x0(%rax)
  401134:	8a 44 24 28          	mov    0x28(%rsp),%al
  401138:	89 c1                	mov    %eax,%ecx
  40113a:	80 e1 fe             	and    $0xfe,%cl
  40113d:	80 f9 02             	cmp    $0x2,%cl
  401140:	75 08                	jne    40114a <test1()+0x3a>
  401142:	3c 03                	cmp    $0x3,%al
  401144:	74 2f                	je     401175 <test1()+0x65>
  401146:	3c 02                	cmp    $0x2,%al
  401148:	74 43                	je     40118d <test1()+0x7d>
  40114a:	8b 5c 24 10          	mov    0x10(%rsp),%ebx
  40114e:	89 c1                	mov    %eax,%ecx
  401150:	fe c9                	dec    %cl
  401152:	80 f9 02             	cmp    $0x2,%cl
  401155:	72 0e                	jb     401165 <test1()+0x55>
  401157:	3c 03                	cmp    $0x3,%al
  401159:	75 0f                	jne    40116a <test1()+0x5a>
  40115b:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
  400f70:	ff 25 1a 11 20 00    	jmpq   *0x20111a(%rip)        # 602090 <_GLOBAL_OFFSET_TABLE_+0x90>
  400f76:	68 0f 00 00 00       	pushq  $0xf
  400f7b:	e9 f0 fe ff ff       	jmpq   400e70 <_init+0x20>
  401165:	c6 44 24 28 00       	movb   $0x0,0x28(%rsp)
  40116a:	89 d8                	mov    %ebx,%eax
  40116c:	48 83 c4 30          	add    $0x30,%rsp
  401170:	5b                   	pop    %rbx
  401171:	41 5e                	pop    %r14
  401173:	5d                   	pop    %rbp
  401174:	c3                   	retq
  401175:	48 89 e3             	mov    %rsp,%rbx
  401178:	48 8d 74 24 10       	lea    0x10(%rsp),%rsi
  40117d:	48 89 df             	mov    %rbx,%rdi
  400fb0:	ff 25 fa 10 20 00    	jmpq   *0x2010fa(%rip)        # 6020b0 <_GLOBAL_OFFSET_TABLE_+0xb0>
  400fb6:	68 13 00 00 00       	pushq  $0x13
  400fbb:	e9 b0 fe ff ff       	jmpq   400e70 <_init+0x20>
  401185:	48 89 df             	mov    %rbx,%rdi
  400ff0:	ff 25 da 10 20 00    	jmpq   *0x2010da(%rip)        # 6020d0 <_GLOBAL_OFFSET_TABLE_+0xd0>
  400ff6:	68 17 00 00 00       	pushq  $0x17
  400ffb:	e9 70 fe ff ff       	jmpq   400e70 <_init+0x20>
  40118d:	bf 20 00 00 00       	mov    $0x20,%edi
  400f80:	ff 25 12 11 20 00    	jmpq   *0x201112(%rip)        # 602098 <_GLOBAL_OFFSET_TABLE_+0x98>
  400f86:	68 10 00 00 00       	pushq  $0x10
  400f8b:	e9 e0 fe ff ff       	jmpq   400e70 <_init+0x20>
  401197:	48 89 c3             	mov    %rax,%rbx
  40119a:	44 8b 74 24 10       	mov    0x10(%rsp),%r14d
  40119f:	48 8b 6c 24 18       	mov    0x18(%rsp),%rbp
  4011a4:	48 8b 45 00          	mov    0x0(%rbp),%rax
  4011a8:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  4011ad:	48 89 ee             	mov    %rbp,%rsi
  4011b0:	44 89 f2             	mov    %r14d,%edx
  4011b3:	ff 50 18             	callq  *0x18(%rax)
  4011b6:	48 8d 74 24 08       	lea    0x8(%rsp),%rsi
  4011bb:	48 89 df             	mov    %rbx,%rdi
  400eb0:	ff 25 7a 11 20 00    	jmpq   *0x20117a(%rip)        # 602030 <_GLOBAL_OFFSET_TABLE_+0x30>
  400eb6:	68 03 00 00 00       	pushq  $0x3
  400ebb:	e9 b0 ff ff ff       	jmpq   400e70 <_init+0x20>
  4011c3:	48 8b 44 24 08       	mov    0x8(%rsp),%rax
  4011c8:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  4011cc:	b9 a0 21 60 00       	mov    $0x6021a0,%ecx
  4011d1:	48 39 cf             	cmp    %rcx,%rdi
  4011d4:	74 2f                	je     401205 <test1()+0xf5>
  4011d6:	b9 00 00 00 00       	mov    $0x0,%ecx
  4011db:	48 85 c9             	test   %rcx,%rcx
  4011de:	74 10                	je     4011f0 <test1()+0xe0>
  4011e0:	b9 ff ff ff ff       	mov    $0xffffffff,%ecx
  4011e5:	f0 0f c1 48 f8       	lock xadd %ecx,-0x8(%rax)
  4011ea:	85 c9                	test   %ecx,%ecx
  4011ec:	7e 0f                	jle    4011fd <test1()+0xed>
  4011ee:	eb 15                	jmp    401205 <test1()+0xf5>
  4011f0:	8b 48 f8             	mov    -0x8(%rax),%ecx
  4011f3:	8d 51 ff             	lea    -0x1(%rcx),%edx
  4011f6:	89 50 f8             	mov    %edx,-0x8(%rax)
  4011f9:	85 c9                	test   %ecx,%ecx
  4011fb:	7f 08                	jg     401205 <test1()+0xf5>
  4011fd:	48 89 e6             	mov    %rsp,%rsi
  400f00:	ff 25 52 11 20 00    	jmpq   *0x201152(%rip)        # 602058 <_GLOBAL_OFFSET_TABLE_+0x58>
  400f06:	68 08 00 00 00       	pushq  $0x8
  400f0b:	e9 60 ff ff ff       	jmpq   400e70 <_init+0x20>
  401205:	48 c7 03 28 21 60 00 	movq   $0x602128,(%rbx)
  40120c:	44 89 73 10          	mov    %r14d,0x10(%rbx)
  401210:	48 89 6b 18          	mov    %rbp,0x18(%rbx)
  401214:	be 00 21 60 00       	mov    $0x602100,%esi
  401219:	ba 30 0f 40 00       	mov    $0x400f30,%edx
  40121e:	48 89 df             	mov    %rbx,%rdi
  400fa0:	ff 25 02 11 20 00    	jmpq   *0x201102(%rip)        # 6020a8 <_GLOBAL_OFFSET_TABLE_+0xa8>
  400fa6:	68 12 00 00 00       	pushq  $0x12
  400fab:	e9 c0 fe ff ff       	jmpq   400e70 <_init+0x20>
  401226:	49 89 c6             	mov    %rax,%r14
  401229:	48 8b 44 24 08       	mov    0x8(%rsp),%rax
  40122e:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  401232:	b9 a0 21 60 00       	mov    $0x6021a0,%ecx
  401237:	48 39 cf             	cmp    %rcx,%rdi
  40123a:	74 34                	je     401270 <test1()+0x160>
  40123c:	b9 00 00 00 00       	mov    $0x0,%ecx
  401241:	48 85 c9             	test   %rcx,%rcx
  401244:	74 10                	je     401256 <test1()+0x146>
  401246:	b9 ff ff ff ff       	mov    $0xffffffff,%ecx
  40124b:	f0 0f c1 48 f8       	lock xadd %ecx,-0x8(%rax)
  401250:	85 c9                	test   %ecx,%ecx
  401252:	7e 0f                	jle    401263 <test1()+0x153>
  401254:	eb 1a                	jmp    401270 <test1()+0x160>
  401256:	8b 48 f8             	mov    -0x8(%rax),%ecx
  401259:	8d 51 ff             	lea    -0x1(%rcx),%edx
  40125c:	89 50 f8             	mov    %edx,-0x8(%rax)
  40125f:	85 c9                	test   %ecx,%ecx
  401261:	7f 0d                	jg     401270 <test1()+0x160>
  401263:	48 89 e6             	mov    %rsp,%rsi
  400f00:	ff 25 52 11 20 00    	jmpq   *0x201152(%rip)        # 602058 <_GLOBAL_OFFSET_TABLE_+0x58>
  400f06:	68 08 00 00 00       	pushq  $0x8
  400f0b:	e9 60 ff ff ff       	jmpq   400e70 <_init+0x20>
  40126b:	eb 03                	jmp    401270 <test1()+0x160>
  40126d:	49 89 c6             	mov    %rax,%r14
  401270:	48 89 df             	mov    %rbx,%rdi
  400f90:	ff 25 0a 11 20 00    	jmpq   *0x20110a(%rip)        # 6020a0 <_GLOBAL_OFFSET_TABLE_+0xa0>
  400f96:	68 11 00 00 00       	pushq  $0x11
  400f9b:	e9 d0 fe ff ff       	jmpq   400e70 <_init+0x20>
  401278:	eb 10                	jmp    40128a <test1()+0x17a>
  40127a:	49 89 c6             	mov    %rax,%r14
  40127d:	48 89 e7             	mov    %rsp,%rdi
  400f70:	ff 25 1a 11 20 00    	jmpq   *0x20111a(%rip)        # 602090 <_GLOBAL_OFFSET_TABLE_+0x90>
  400f76:	68 0f 00 00 00       	pushq  $0xf
  400f7b:	e9 f0 fe ff ff       	jmpq   400e70 <_init+0x20>
  401285:	eb 03                	jmp    40128a <test1()+0x17a>
  401287:	49 89 c6             	mov    %rax,%r14
  40128a:	8a 44 24 28          	mov    0x28(%rsp),%al
  40128e:	89 c1                	mov    %eax,%ecx
  401290:	fe c9                	dec    %cl
  401292:	80 f9 02             	cmp    $0x2,%cl
  401295:	72 0e                	jb     4012a5 <test1()+0x195>
  401297:	3c 03                	cmp    $0x3,%al
  401299:	75 0f                	jne    4012aa <test1()+0x19a>
  40129b:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
  400f70:	ff 25 1a 11 20 00    	jmpq   *0x20111a(%rip)        # 602090 <_GLOBAL_OFFSET_TABLE_+0x90>
  400f76:	68 0f 00 00 00       	pushq  $0xf
  400f7b:	e9 f0 fe ff ff       	jmpq   400e70 <_init+0x20>
  4012a5:	c6 44 24 28 00       	movb   $0x0,0x28(%rsp)
  4012aa:	4c 89 f7             	mov    %r14,%rdi
  400fe0:	ff 25 e2 10 20 00    	jmpq   *0x2010e2(%rip)        # 6020c8 <_GLOBAL_OFFSET_TABLE_+0xc8>
  400fe6:	68 16 00 00 00       	pushq  $0x16
  400feb:	e9 80 fe ff ff       	jmpq   400e70 <_init+0x20>
  4012b2:	66 66 66 66 66 2e 0f 	data32 data32 data32 data32 nopw %cs:0x0(%rax,%rax,1)
