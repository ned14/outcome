  401110:	55                   	push   %rbp
  401111:	41 56                	push   %r14
  401113:	53                   	push   %rbx
  401114:	48 83 ec 60          	sub    $0x60,%rsp
  401118:	48 89 fb             	mov    %rdi,%rbx
  40111b:	48 8d 7c 24 38       	lea    0x38(%rsp),%rdi
  401120:	e8 db ee bf ff       	callq  0 <_init-0x400e50>
  401125:	c6 44 24 28 00       	movb   $0x0,0x28(%rsp)
  40112a:	8a 44 24 50          	mov    0x50(%rsp),%al
  40112e:	3c 01                	cmp    $0x1,%al
  401130:	0f 84 9b 00 00 00    	je     4011d1 <test1()+0xc1>
  401136:	3c 03                	cmp    $0x3,%al
  401138:	0f 84 a5 00 00 00    	je     4011e3 <test1()+0xd3>
  40113e:	3c 02                	cmp    $0x2,%al
  401140:	0f 85 b0 00 00 00    	jne    4011f6 <test1()+0xe6>
  401146:	48 8b 44 24 48       	mov    0x48(%rsp),%rax
  40114b:	48 89 44 24 20       	mov    %rax,0x20(%rsp)
  401150:	0f 10 44 24 38       	movups 0x38(%rsp),%xmm0
  401155:	0f 29 44 24 10       	movaps %xmm0,0x10(%rsp)
  40115a:	c6 44 24 28 02       	movb   $0x2,0x28(%rsp)
  40115f:	bf 20 00 00 00       	mov    $0x20,%edi
  400f80:	ff 25 12 11 20 00    	jmpq   *0x201112(%rip)        # 602098 <_GLOBAL_OFFSET_TABLE_+0x98>
  400f86:	68 10 00 00 00       	pushq  $0x10
  400f8b:	e9 e0 fe ff ff       	jmpq   400e70 <_init+0x20>
  401169:	48 89 c3             	mov    %rax,%rbx
  40116c:	44 8b 74 24 10       	mov    0x10(%rsp),%r14d
  401171:	48 8b 6c 24 18       	mov    0x18(%rsp),%rbp
  401176:	48 8b 45 00          	mov    0x0(%rbp),%rax
  40117a:	48 8d 7c 24 30       	lea    0x30(%rsp),%rdi
  40117f:	48 89 ee             	mov    %rbp,%rsi
  401182:	44 89 f2             	mov    %r14d,%edx
  401185:	ff 50 18             	callq  *0x18(%rax)
  401188:	48 8d 74 24 30       	lea    0x30(%rsp),%rsi
  40118d:	48 89 df             	mov    %rbx,%rdi
  400eb0:	ff 25 7a 11 20 00    	jmpq   *0x20117a(%rip)        # 602030 <_GLOBAL_OFFSET_TABLE_+0x30>
  400eb6:	68 03 00 00 00       	pushq  $0x3
  400ebb:	e9 b0 ff ff ff       	jmpq   400e70 <_init+0x20>
  401195:	48 8b 44 24 30       	mov    0x30(%rsp),%rax
  40119a:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  40119e:	b9 a0 21 60 00       	mov    $0x6021a0,%ecx
  4011a3:	48 39 cf             	cmp    %rcx,%rdi
  4011a6:	0f 84 e4 00 00 00    	je     401290 <test1()+0x180>
  4011ac:	b9 00 00 00 00       	mov    $0x0,%ecx
  4011b1:	48 85 c9             	test   %rcx,%rcx
  4011b4:	0f 84 bf 00 00 00    	je     401279 <test1()+0x169>
  4011ba:	b9 ff ff ff ff       	mov    $0xffffffff,%ecx
  4011bf:	f0 0f c1 48 f8       	lock xadd %ecx,-0x8(%rax)
  4011c4:	85 c9                	test   %ecx,%ecx
  4011c6:	0f 8e ba 00 00 00    	jle    401286 <test1()+0x176>
  4011cc:	e9 bf 00 00 00       	jmpq   401290 <test1()+0x180>
  4011d1:	8b 44 24 38          	mov    0x38(%rsp),%eax
  4011d5:	89 44 24 10          	mov    %eax,0x10(%rsp)
  4011d9:	c6 44 24 28 01       	movb   $0x1,0x28(%rsp)
  4011de:	8d 2c 40             	lea    (%rax,%rax,2),%ebp
  4011e1:	eb 5f                	jmp    401242 <test1()+0x132>
  4011e3:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
  4011e8:	48 8d 74 24 38       	lea    0x38(%rsp),%rsi
  400fb0:	ff 25 fa 10 20 00    	jmpq   *0x2010fa(%rip)        # 6020b0 <_GLOBAL_OFFSET_TABLE_+0xb0>
  400fb6:	68 13 00 00 00       	pushq  $0x13
  400fbb:	e9 b0 fe ff ff       	jmpq   400e70 <_init+0x20>
  4011f2:	8a 44 24 50          	mov    0x50(%rsp),%al
  4011f6:	88 44 24 28          	mov    %al,0x28(%rsp)
  4011fa:	84 c0                	test   %al,%al
  4011fc:	75 0e                	jne    40120c <test1()+0xfc>
  4011fe:	bf 02 00 00 00       	mov    $0x2,%edi
  4013d0:	55                   	push   %rbp
  4013d1:	53                   	push   %rbx
  4013d2:	50                   	push   %rax
  4013d3:	89 fd                	mov    %edi,%ebp
  4013d5:	bf 20 00 00 00       	mov    $0x20,%edi
  400f80:	ff 25 12 11 20 00    	jmpq   *0x201112(%rip)        # 602098 <_GLOBAL_OFFSET_TABLE_+0x98>
  400f86:	68 10 00 00 00       	pushq  $0x10
  400f8b:	e9 e0 fe ff ff       	jmpq   400e70 <_init+0x20>
  4013df:	48 89 c3             	mov    %rax,%rbx
  4013e2:	8a 05 f0 0d 20 00    	mov    0x200df0(%rip),%al        # 6021d8 <guard variable for boost::outcome::_1_0_std_std_9274c0d4::monad_category()::c>
  4013e8:	84 c0                	test   %al,%al
  4013ea:	75 2c                	jne    401418 <boost::outcome::_1_0_std_std_9274c0d4::policy::monad_policy_base<boost::outcome::_1_0_std_std_9274c0d4::policy::basic_monad_storage<boost::outcome::_1_0_std_std_9274c0d4::policy::monad_policy<int> >, int, boost::outcome::_1_0_std_std_9274c0d4::error_code_extended, std::__exception_ptr::exception_ptr>::_throw_error(boost::outcome::_1_0_std_std_9274c0d4::monad_errc)+0x48>
  4013ec:	bf d8 21 60 00       	mov    $0x6021d8,%edi
  400ea0:	ff 25 82 11 20 00    	jmpq   *0x201182(%rip)        # 602028 <_GLOBAL_OFFSET_TABLE_+0x28>
  400ea6:	68 02 00 00 00       	pushq  $0x2
  400eab:	e9 c0 ff ff ff       	jmpq   400e70 <_init+0x20>
  4013f6:	85 c0                	test   %eax,%eax
  4013f8:	74 1e                	je     401418 <boost::outcome::_1_0_std_std_9274c0d4::policy::monad_policy_base<boost::outcome::_1_0_std_std_9274c0d4::policy::basic_monad_storage<boost::outcome::_1_0_std_std_9274c0d4::policy::monad_policy<int> >, int, boost::outcome::_1_0_std_std_9274c0d4::error_code_extended, std::__exception_ptr::exception_ptr>::_throw_error(boost::outcome::_1_0_std_std_9274c0d4::monad_errc)+0x48>
  4013fa:	bf 80 0e 40 00       	mov    $0x400e80,%edi
  4013ff:	be f0 20 60 00       	mov    $0x6020f0,%esi
  401404:	ba e8 20 60 00       	mov    $0x6020e8,%edx
  400ef0:	ff 25 5a 11 20 00    	jmpq   *0x20115a(%rip)        # 602050 <_GLOBAL_OFFSET_TABLE_+0x50>
  400ef6:	68 07 00 00 00       	pushq  $0x7
  400efb:	e9 70 ff ff ff       	jmpq   400e70 <_init+0x20>
  40140e:	bf d8 21 60 00       	mov    $0x6021d8,%edi
  400f20:	ff 25 42 11 20 00    	jmpq   *0x201142(%rip)        # 602068 <_GLOBAL_OFFSET_TABLE_+0x68>
  400f26:	68 0a 00 00 00       	pushq  $0xa
  400f2b:	e9 40 ff ff ff       	jmpq   400e70 <_init+0x20>
  401418:	ba f0 20 60 00       	mov    $0x6020f0,%edx
  40141d:	48 89 df             	mov    %rbx,%rdi
  401420:	89 ee                	mov    %ebp,%esi
  401450:	55                   	push   %rbp
  401451:	41 57                	push   %r15
  401453:	41 56                	push   %r14
  401455:	53                   	push   %rbx
  401456:	48 83 ec 18          	sub    $0x18,%rsp
  40145a:	49 89 d6             	mov    %rdx,%r14
  40145d:	41 89 f7             	mov    %esi,%r15d
  401460:	48 89 fb             	mov    %rdi,%rbx
  401463:	49 8b 06             	mov    (%r14),%rax
  401466:	48 8d 6c 24 10       	lea    0x10(%rsp),%rbp
  40146b:	48 89 ef             	mov    %rbp,%rdi
  40146e:	4c 89 f6             	mov    %r14,%rsi
  401471:	44 89 fa             	mov    %r15d,%edx
  401474:	ff 50 18             	callq  *0x18(%rax)
  401477:	48 89 df             	mov    %rbx,%rdi
  40147a:	48 89 ee             	mov    %rbp,%rsi
  400eb0:	ff 25 7a 11 20 00    	jmpq   *0x20117a(%rip)        # 602030 <_GLOBAL_OFFSET_TABLE_+0x30>
  400eb6:	68 03 00 00 00       	pushq  $0x3
  400ebb:	e9 b0 ff ff ff       	jmpq   400e70 <_init+0x20>
  401482:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  401487:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  40148b:	b9 a0 21 60 00       	mov    $0x6021a0,%ecx
  401490:	48 39 cf             	cmp    %rcx,%rdi
  401493:	75 1a                	jne    4014af <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0x5f>
  401495:	44 89 7b 10          	mov    %r15d,0x10(%rbx)
  401499:	4c 89 73 18          	mov    %r14,0x18(%rbx)
  40149d:	48 c7 03 f8 17 40 00 	movq   $0x4017f8,(%rbx)
  4014a4:	48 83 c4 18          	add    $0x18,%rsp
  4014a8:	5b                   	pop    %rbx
  4014a9:	41 5e                	pop    %r14
  4014ab:	41 5f                	pop    %r15
  4014ad:	5d                   	pop    %rbp
  4014ae:	c3                   	retq
  4014af:	b9 00 00 00 00       	mov    $0x0,%ecx
  4014b4:	48 85 c9             	test   %rcx,%rcx
  4014b7:	74 10                	je     4014c9 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0x79>
  4014b9:	b9 ff ff ff ff       	mov    $0xffffffff,%ecx
  4014be:	f0 0f c1 48 f8       	lock xadd %ecx,-0x8(%rax)
  4014c3:	85 c9                	test   %ecx,%ecx
  4014c5:	7f ce                	jg     401495 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0x45>
  4014c7:	eb 0d                	jmp    4014d6 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0x86>
  4014c9:	8b 48 f8             	mov    -0x8(%rax),%ecx
  4014cc:	8d 51 ff             	lea    -0x1(%rcx),%edx
  4014cf:	89 50 f8             	mov    %edx,-0x8(%rax)
  4014d2:	85 c9                	test   %ecx,%ecx
  4014d4:	7f bf                	jg     401495 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0x45>
  4014d6:	48 89 e6             	mov    %rsp,%rsi
  400f00:	ff 25 52 11 20 00    	jmpq   *0x201152(%rip)        # 602058 <_GLOBAL_OFFSET_TABLE_+0x58>
  400f06:	68 08 00 00 00       	pushq  $0x8
  400f0b:	e9 60 ff ff ff       	jmpq   400e70 <_init+0x20>
  4014de:	eb b5                	jmp    401495 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0x45>
  4014e0:	48 89 c3             	mov    %rax,%rbx
  4014e3:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  4014e8:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  4014ec:	b9 a0 21 60 00       	mov    $0x6021a0,%ecx
  4014f1:	48 39 cf             	cmp    %rcx,%rdi
  4014f4:	74 31                	je     401527 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0xd7>
  4014f6:	b9 00 00 00 00       	mov    $0x0,%ecx
  4014fb:	48 85 c9             	test   %rcx,%rcx
  4014fe:	74 10                	je     401510 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0xc0>
  401500:	b9 ff ff ff ff       	mov    $0xffffffff,%ecx
  401505:	f0 0f c1 48 f8       	lock xadd %ecx,-0x8(%rax)
  40150a:	85 c9                	test   %ecx,%ecx
  40150c:	7e 0f                	jle    40151d <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0xcd>
  40150e:	eb 17                	jmp    401527 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0xd7>
  401510:	8b 48 f8             	mov    -0x8(%rax),%ecx
  401513:	8d 51 ff             	lea    -0x1(%rcx),%edx
  401516:	89 50 f8             	mov    %edx,-0x8(%rax)
  401519:	85 c9                	test   %ecx,%ecx
  40151b:	7f 0a                	jg     401527 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0xd7>
  40151d:	48 8d 74 24 08       	lea    0x8(%rsp),%rsi
  401522:	e8 d9 f9 ff ff       	callq  400f00 <std::string::_Rep::_M_destroy(std::allocator<char> const&)@plt>
  401527:	48 89 df             	mov    %rbx,%rdi
  400fe0:	ff 25 e2 10 20 00    	jmpq   *0x2010e2(%rip)        # 6020c8 <_GLOBAL_OFFSET_TABLE_+0xc8>
  400fe6:	68 16 00 00 00       	pushq  $0x16
  400feb:	e9 80 fe ff ff       	jmpq   400e70 <_init+0x20>
  40152f:	90                   	nop
  401427:	be e0 16 40 00       	mov    $0x4016e0,%esi
  40142c:	ba 90 0e 40 00       	mov    $0x400e90,%edx
  401431:	48 89 df             	mov    %rbx,%rdi
  400fa0:	ff 25 02 11 20 00    	jmpq   *0x201102(%rip)        # 6020a8 <_GLOBAL_OFFSET_TABLE_+0xa8>
  400fa6:	68 12 00 00 00       	pushq  $0x12
  400fab:	e9 c0 fe ff ff       	jmpq   400e70 <_init+0x20>
  401439:	48 89 c5             	mov    %rax,%rbp
  40143c:	48 89 df             	mov    %rbx,%rdi
  400f90:	ff 25 0a 11 20 00    	jmpq   *0x20110a(%rip)        # 6020a0 <_GLOBAL_OFFSET_TABLE_+0xa0>
  400f96:	68 11 00 00 00       	pushq  $0x11
  400f9b:	e9 d0 fe ff ff       	jmpq   400e70 <_init+0x20>
  401444:	48 89 ef             	mov    %rbp,%rdi
  401447:	e8 94 fb ff ff       	callq  400fe0 <_Unwind_Resume@plt>
  40144c:	0f 1f 40 00          	nopl   0x0(%rax)
  401208:	8a 44 24 28          	mov    0x28(%rsp),%al
  40120c:	89 c1                	mov    %eax,%ecx
  40120e:	80 e1 fe             	and    $0xfe,%cl
  401211:	80 f9 02             	cmp    $0x2,%cl
  401214:	75 10                	jne    401226 <test1()+0x116>
  401216:	3c 03                	cmp    $0x3,%al
  401218:	0f 84 93 00 00 00    	je     4012b1 <test1()+0x1a1>
  40121e:	3c 02                	cmp    $0x2,%al
  401220:	0f 84 39 ff ff ff    	je     40115f <test1()+0x4f>
  401226:	6b 6c 24 10 03       	imul   $0x3,0x10(%rsp),%ebp
  40122b:	89 c1                	mov    %eax,%ecx
  40122d:	fe c9                	dec    %cl
  40122f:	80 f9 02             	cmp    $0x2,%cl
  401232:	72 0e                	jb     401242 <test1()+0x132>
  401234:	3c 03                	cmp    $0x3,%al
  401236:	75 0f                	jne    401247 <test1()+0x137>
  401238:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
  400f70:	ff 25 1a 11 20 00    	jmpq   *0x20111a(%rip)        # 602090 <_GLOBAL_OFFSET_TABLE_+0x90>
  400f76:	68 0f 00 00 00       	pushq  $0xf
  400f7b:	e9 f0 fe ff ff       	jmpq   400e70 <_init+0x20>
  401242:	c6 44 24 28 00       	movb   $0x0,0x28(%rsp)
  401247:	89 2b                	mov    %ebp,(%rbx)
  401249:	c6 43 18 01          	movb   $0x1,0x18(%rbx)
  40124d:	8a 44 24 50          	mov    0x50(%rsp),%al
  401251:	89 c1                	mov    %eax,%ecx
  401253:	fe c9                	dec    %cl
  401255:	80 f9 02             	cmp    $0x2,%cl
  401258:	72 0e                	jb     401268 <test1()+0x158>
  40125a:	3c 03                	cmp    $0x3,%al
  40125c:	75 0f                	jne    40126d <test1()+0x15d>
  40125e:	48 8d 7c 24 38       	lea    0x38(%rsp),%rdi
  400f70:	ff 25 1a 11 20 00    	jmpq   *0x20111a(%rip)        # 602090 <_GLOBAL_OFFSET_TABLE_+0x90>
  400f76:	68 0f 00 00 00       	pushq  $0xf
  400f7b:	e9 f0 fe ff ff       	jmpq   400e70 <_init+0x20>
  401268:	c6 44 24 50 00       	movb   $0x0,0x50(%rsp)
  40126d:	48 89 d8             	mov    %rbx,%rax
  401270:	48 83 c4 60          	add    $0x60,%rsp
  401274:	5b                   	pop    %rbx
  401275:	41 5e                	pop    %r14
  401277:	5d                   	pop    %rbp
  401278:	c3                   	retq
  401279:	8b 48 f8             	mov    -0x8(%rax),%ecx
  40127c:	8d 51 ff             	lea    -0x1(%rcx),%edx
  40127f:	89 50 f8             	mov    %edx,-0x8(%rax)
  401282:	85 c9                	test   %ecx,%ecx
  401284:	7f 0a                	jg     401290 <test1()+0x180>
  401286:	48 8d 74 24 08       	lea    0x8(%rsp),%rsi
  400f00:	ff 25 52 11 20 00    	jmpq   *0x201152(%rip)        # 602058 <_GLOBAL_OFFSET_TABLE_+0x58>
  400f06:	68 08 00 00 00       	pushq  $0x8
  400f0b:	e9 60 ff ff ff       	jmpq   400e70 <_init+0x20>
  401290:	48 c7 03 28 21 60 00 	movq   $0x602128,(%rbx)
  401297:	44 89 73 10          	mov    %r14d,0x10(%rbx)
  40129b:	48 89 6b 18          	mov    %rbp,0x18(%rbx)
  40129f:	be 00 21 60 00       	mov    $0x602100,%esi
  4012a4:	ba 30 0f 40 00       	mov    $0x400f30,%edx
  4012a9:	48 89 df             	mov    %rbx,%rdi
  400fa0:	ff 25 02 11 20 00    	jmpq   *0x201102(%rip)        # 6020a8 <_GLOBAL_OFFSET_TABLE_+0xa8>
  400fa6:	68 12 00 00 00       	pushq  $0x12
  400fab:	e9 c0 fe ff ff       	jmpq   400e70 <_init+0x20>
  4012b1:	48 8d 5c 24 58       	lea    0x58(%rsp),%rbx
  4012b6:	48 8d 74 24 10       	lea    0x10(%rsp),%rsi
  4012bb:	48 89 df             	mov    %rbx,%rdi
  400fb0:	ff 25 fa 10 20 00    	jmpq   *0x2010fa(%rip)        # 6020b0 <_GLOBAL_OFFSET_TABLE_+0xb0>
  400fb6:	68 13 00 00 00       	pushq  $0x13
  400fbb:	e9 b0 fe ff ff       	jmpq   400e70 <_init+0x20>
  4012c3:	48 89 df             	mov    %rbx,%rdi
  400ff0:	ff 25 da 10 20 00    	jmpq   *0x2010da(%rip)        # 6020d0 <_GLOBAL_OFFSET_TABLE_+0xd0>
  400ff6:	68 17 00 00 00       	pushq  $0x17
  400ffb:	e9 70 fe ff ff       	jmpq   400e70 <_init+0x20>
  4012cb:	49 89 c6             	mov    %rax,%r14
  4012ce:	48 8d 7c 24 58       	lea    0x58(%rsp),%rdi
  400f70:	ff 25 1a 11 20 00    	jmpq   *0x20111a(%rip)        # 602090 <_GLOBAL_OFFSET_TABLE_+0x90>
  400f76:	68 0f 00 00 00       	pushq  $0xf
  400f7b:	e9 f0 fe ff ff       	jmpq   400e70 <_init+0x20>
  4012d8:	eb 59                	jmp    401333 <test1()+0x223>
  4012da:	49 89 c6             	mov    %rax,%r14
  4012dd:	48 8b 44 24 30       	mov    0x30(%rsp),%rax
  4012e2:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  4012e6:	b9 a0 21 60 00       	mov    $0x6021a0,%ecx
  4012eb:	48 39 cf             	cmp    %rcx,%rdi
  4012ee:	74 36                	je     401326 <test1()+0x216>
  4012f0:	b9 00 00 00 00       	mov    $0x0,%ecx
  4012f5:	48 85 c9             	test   %rcx,%rcx
  4012f8:	74 10                	je     40130a <test1()+0x1fa>
  4012fa:	b9 ff ff ff ff       	mov    $0xffffffff,%ecx
  4012ff:	f0 0f c1 48 f8       	lock xadd %ecx,-0x8(%rax)
  401304:	85 c9                	test   %ecx,%ecx
  401306:	7e 0f                	jle    401317 <test1()+0x207>
  401308:	eb 1c                	jmp    401326 <test1()+0x216>
  40130a:	8b 48 f8             	mov    -0x8(%rax),%ecx
  40130d:	8d 51 ff             	lea    -0x1(%rcx),%edx
  401310:	89 50 f8             	mov    %edx,-0x8(%rax)
  401313:	85 c9                	test   %ecx,%ecx
  401315:	7f 0f                	jg     401326 <test1()+0x216>
  401317:	48 8d 74 24 08       	lea    0x8(%rsp),%rsi
  400f00:	ff 25 52 11 20 00    	jmpq   *0x201152(%rip)        # 602058 <_GLOBAL_OFFSET_TABLE_+0x58>
  400f06:	68 08 00 00 00       	pushq  $0x8
  400f0b:	e9 60 ff ff ff       	jmpq   400e70 <_init+0x20>
  401321:	eb 03                	jmp    401326 <test1()+0x216>
  401323:	49 89 c6             	mov    %rax,%r14
  401326:	48 89 df             	mov    %rbx,%rdi
  400f90:	ff 25 0a 11 20 00    	jmpq   *0x20110a(%rip)        # 6020a0 <_GLOBAL_OFFSET_TABLE_+0xa0>
  400f96:	68 11 00 00 00       	pushq  $0x11
  400f9b:	e9 d0 fe ff ff       	jmpq   400e70 <_init+0x20>
  40132e:	eb 03                	jmp    401333 <test1()+0x223>
  401330:	49 89 c6             	mov    %rax,%r14
  401333:	8a 44 24 28          	mov    0x28(%rsp),%al
  401337:	89 c1                	mov    %eax,%ecx
  401339:	fe c9                	dec    %cl
  40133b:	80 f9 02             	cmp    $0x2,%cl
  40133e:	72 0e                	jb     40134e <test1()+0x23e>
  401340:	3c 03                	cmp    $0x3,%al
  401342:	75 0f                	jne    401353 <test1()+0x243>
  401344:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
  400f70:	ff 25 1a 11 20 00    	jmpq   *0x20111a(%rip)        # 602090 <_GLOBAL_OFFSET_TABLE_+0x90>
  400f76:	68 0f 00 00 00       	pushq  $0xf
  400f7b:	e9 f0 fe ff ff       	jmpq   400e70 <_init+0x20>
  40134e:	c6 44 24 28 00       	movb   $0x0,0x28(%rsp)
  401353:	8a 44 24 50          	mov    0x50(%rsp),%al
  401357:	89 c1                	mov    %eax,%ecx
  401359:	fe c9                	dec    %cl
  40135b:	80 f9 02             	cmp    $0x2,%cl
  40135e:	72 0e                	jb     40136e <test1()+0x25e>
  401360:	3c 03                	cmp    $0x3,%al
  401362:	75 0f                	jne    401373 <test1()+0x263>
  401364:	48 8d 7c 24 38       	lea    0x38(%rsp),%rdi
  400f70:	ff 25 1a 11 20 00    	jmpq   *0x20111a(%rip)        # 602090 <_GLOBAL_OFFSET_TABLE_+0x90>
  400f76:	68 0f 00 00 00       	pushq  $0xf
  400f7b:	e9 f0 fe ff ff       	jmpq   400e70 <_init+0x20>
  40136e:	c6 44 24 50 00       	movb   $0x0,0x50(%rsp)
  401373:	4c 89 f7             	mov    %r14,%rdi
  400fe0:	ff 25 e2 10 20 00    	jmpq   *0x2010e2(%rip)        # 6020c8 <_GLOBAL_OFFSET_TABLE_+0xc8>
  400fe6:	68 16 00 00 00       	pushq  $0x16
  400feb:	e9 80 fe ff ff       	jmpq   400e70 <_init+0x20>
  40137b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
