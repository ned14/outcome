  4013f0:	55                   	push   %rbp
  4013f1:	41 56                	push   %r14
  4013f3:	53                   	push   %rbx
  4013f4:	48 83 ec 50          	sub    $0x50,%rsp
  4013f8:	48 89 fb             	mov    %rdi,%rbx
  4013fb:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
  401400:	e8 fb eb bf ff       	callq  0 <_init-0x4010c0>
  401405:	8a 44 24 28          	mov    0x28(%rsp),%al
  401409:	84 c0                	test   %al,%al
  40140b:	75 16                	jne    401423 <test1()+0x33>
  40140d:	bf 02 00 00 00       	mov    $0x2,%edi
  401650:	55                   	push   %rbp
  401651:	53                   	push   %rbx
  401652:	50                   	push   %rax
  401653:	89 fd                	mov    %edi,%ebp
  401655:	bf 20 00 00 00       	mov    $0x20,%edi
  401230:	ff 25 82 1e 20 00    	jmpq   *0x201e82(%rip)        # 6030b8 <_GLOBAL_OFFSET_TABLE_+0xb8>
  401236:	68 14 00 00 00       	pushq  $0x14
  40123b:	e9 a0 fe ff ff       	jmpq   4010e0 <_init+0x20>
  40165f:	48 89 c3             	mov    %rax,%rbx
  401662:	8a 05 f0 1b 20 00    	mov    0x201bf0(%rip),%al        # 603258 <guard variable for boost::outcome::_1_0_std_std_9274c0d4::monad_category()::c>
  401668:	84 c0                	test   %al,%al
  40166a:	75 2c                	jne    401698 <boost::outcome::_1_0_std_std_9274c0d4::policy::monad_policy_base<boost::outcome::_1_0_std_std_9274c0d4::policy::basic_monad_storage<boost::outcome::_1_0_std_std_9274c0d4::policy::monad_policy<int> >, int, boost::outcome::_1_0_std_std_9274c0d4::error_code_extended, std::__exception_ptr::exception_ptr>::_throw_error(boost::outcome::_1_0_std_std_9274c0d4::monad_errc)+0x48>
  40166c:	bf 58 32 60 00       	mov    $0x603258,%edi
  401110:	ff 25 12 1f 20 00    	jmpq   *0x201f12(%rip)        # 603028 <_GLOBAL_OFFSET_TABLE_+0x28>
  401116:	68 02 00 00 00       	pushq  $0x2
  40111b:	e9 c0 ff ff ff       	jmpq   4010e0 <_init+0x20>
  401676:	85 c0                	test   %eax,%eax
  401678:	74 1e                	je     401698 <boost::outcome::_1_0_std_std_9274c0d4::policy::monad_policy_base<boost::outcome::_1_0_std_std_9274c0d4::policy::basic_monad_storage<boost::outcome::_1_0_std_std_9274c0d4::policy::monad_policy<int> >, int, boost::outcome::_1_0_std_std_9274c0d4::error_code_extended, std::__exception_ptr::exception_ptr>::_throw_error(boost::outcome::_1_0_std_std_9274c0d4::monad_errc)+0x48>
  40167a:	bf f0 10 40 00       	mov    $0x4010f0,%edi
  40167f:	be 28 31 60 00       	mov    $0x603128,%esi
  401684:	ba 20 31 60 00       	mov    $0x603120,%edx
  401170:	ff 25 e2 1e 20 00    	jmpq   *0x201ee2(%rip)        # 603058 <_GLOBAL_OFFSET_TABLE_+0x58>
  401176:	68 08 00 00 00       	pushq  $0x8
  40117b:	e9 60 ff ff ff       	jmpq   4010e0 <_init+0x20>
  40168e:	bf 58 32 60 00       	mov    $0x603258,%edi
  4011a0:	ff 25 ca 1e 20 00    	jmpq   *0x201eca(%rip)        # 603070 <_GLOBAL_OFFSET_TABLE_+0x70>
  4011a6:	68 0b 00 00 00       	pushq  $0xb
  4011ab:	e9 30 ff ff ff       	jmpq   4010e0 <_init+0x20>
  401698:	ba 28 31 60 00       	mov    $0x603128,%edx
  40169d:	48 89 df             	mov    %rbx,%rdi
  4016a0:	89 ee                	mov    %ebp,%esi
  401760:	55                   	push   %rbp
  401761:	41 57                	push   %r15
  401763:	41 56                	push   %r14
  401765:	53                   	push   %rbx
  401766:	48 83 ec 18          	sub    $0x18,%rsp
  40176a:	49 89 d6             	mov    %rdx,%r14
  40176d:	41 89 f7             	mov    %esi,%r15d
  401770:	48 89 fb             	mov    %rdi,%rbx
  401773:	49 8b 06             	mov    (%r14),%rax
  401776:	48 8d 6c 24 10       	lea    0x10(%rsp),%rbp
  40177b:	48 89 ef             	mov    %rbp,%rdi
  40177e:	4c 89 f6             	mov    %r14,%rsi
  401781:	44 89 fa             	mov    %r15d,%edx
  401784:	ff 50 18             	callq  *0x18(%rax)
  401787:	48 89 df             	mov    %rbx,%rdi
  40178a:	48 89 ee             	mov    %rbp,%rsi
  401120:	ff 25 0a 1f 20 00    	jmpq   *0x201f0a(%rip)        # 603030 <_GLOBAL_OFFSET_TABLE_+0x30>
  401126:	68 03 00 00 00       	pushq  $0x3
  40112b:	e9 b0 ff ff ff       	jmpq   4010e0 <_init+0x20>
  401792:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  401797:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  40179b:	b9 20 32 60 00       	mov    $0x603220,%ecx
  4017a0:	48 39 cf             	cmp    %rcx,%rdi
  4017a3:	75 1a                	jne    4017bf <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0x5f>
  4017a5:	44 89 7b 10          	mov    %r15d,0x10(%rbx)
  4017a9:	4c 89 73 18          	mov    %r14,0x18(%rbx)
  4017ad:	48 c7 03 18 1b 40 00 	movq   $0x401b18,(%rbx)
  4017b4:	48 83 c4 18          	add    $0x18,%rsp
  4017b8:	5b                   	pop    %rbx
  4017b9:	41 5e                	pop    %r14
  4017bb:	41 5f                	pop    %r15
  4017bd:	5d                   	pop    %rbp
  4017be:	c3                   	retq
  4017bf:	b9 00 00 00 00       	mov    $0x0,%ecx
  4017c4:	48 85 c9             	test   %rcx,%rcx
  4017c7:	74 10                	je     4017d9 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0x79>
  4017c9:	b9 ff ff ff ff       	mov    $0xffffffff,%ecx
  4017ce:	f0 0f c1 48 f8       	lock xadd %ecx,-0x8(%rax)
  4017d3:	85 c9                	test   %ecx,%ecx
  4017d5:	7f ce                	jg     4017a5 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0x45>
  4017d7:	eb 0d                	jmp    4017e6 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0x86>
  4017d9:	8b 48 f8             	mov    -0x8(%rax),%ecx
  4017dc:	8d 51 ff             	lea    -0x1(%rcx),%edx
  4017df:	89 50 f8             	mov    %edx,-0x8(%rax)
  4017e2:	85 c9                	test   %ecx,%ecx
  4017e4:	7f bf                	jg     4017a5 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0x45>
  4017e6:	48 89 e6             	mov    %rsp,%rsi
  401180:	ff 25 da 1e 20 00    	jmpq   *0x201eda(%rip)        # 603060 <_GLOBAL_OFFSET_TABLE_+0x60>
  401186:	68 09 00 00 00       	pushq  $0x9
  40118b:	e9 50 ff ff ff       	jmpq   4010e0 <_init+0x20>
  4017ee:	eb b5                	jmp    4017a5 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0x45>
  4017f0:	48 89 c3             	mov    %rax,%rbx
  4017f3:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  4017f8:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  4017fc:	b9 20 32 60 00       	mov    $0x603220,%ecx
  401801:	48 39 cf             	cmp    %rcx,%rdi
  401804:	74 31                	je     401837 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0xd7>
  401806:	b9 00 00 00 00       	mov    $0x0,%ecx
  40180b:	48 85 c9             	test   %rcx,%rcx
  40180e:	74 10                	je     401820 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0xc0>
  401810:	b9 ff ff ff ff       	mov    $0xffffffff,%ecx
  401815:	f0 0f c1 48 f8       	lock xadd %ecx,-0x8(%rax)
  40181a:	85 c9                	test   %ecx,%ecx
  40181c:	7e 0f                	jle    40182d <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0xcd>
  40181e:	eb 17                	jmp    401837 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0xd7>
  401820:	8b 48 f8             	mov    -0x8(%rax),%ecx
  401823:	8d 51 ff             	lea    -0x1(%rcx),%edx
  401826:	89 50 f8             	mov    %edx,-0x8(%rax)
  401829:	85 c9                	test   %ecx,%ecx
  40182b:	7f 0a                	jg     401837 <boost::outcome::_1_0_std_std_9274c0d4::monad_error::monad_error(std::error_code)+0xd7>
  40182d:	48 8d 74 24 08       	lea    0x8(%rsp),%rsi
  401832:	e8 49 f9 ff ff       	callq  401180 <std::string::_Rep::_M_destroy(std::allocator<char> const&)@plt>
  401837:	48 89 df             	mov    %rbx,%rdi
  4012d0:	ff 25 32 1e 20 00    	jmpq   *0x201e32(%rip)        # 603108 <_GLOBAL_OFFSET_TABLE_+0x108>
  4012d6:	68 1e 00 00 00       	pushq  $0x1e
  4012db:	e9 00 fe ff ff       	jmpq   4010e0 <_init+0x20>
  40183f:	90                   	nop
  4016a7:	be 00 1a 40 00       	mov    $0x401a00,%esi
  4016ac:	ba 00 11 40 00       	mov    $0x401100,%edx
  4016b1:	48 89 df             	mov    %rbx,%rdi
  401260:	ff 25 6a 1e 20 00    	jmpq   *0x201e6a(%rip)        # 6030d0 <_GLOBAL_OFFSET_TABLE_+0xd0>
  401266:	68 17 00 00 00       	pushq  $0x17
  40126b:	e9 70 fe ff ff       	jmpq   4010e0 <_init+0x20>
  4016b9:	48 89 c5             	mov    %rax,%rbp
  4016bc:	48 89 df             	mov    %rbx,%rdi
  401250:	ff 25 72 1e 20 00    	jmpq   *0x201e72(%rip)        # 6030c8 <_GLOBAL_OFFSET_TABLE_+0xc8>
  401256:	68 16 00 00 00       	pushq  $0x16
  40125b:	e9 80 fe ff ff       	jmpq   4010e0 <_init+0x20>
  4016c4:	48 89 ef             	mov    %rbp,%rdi
  4016c7:	e8 04 fc ff ff       	callq  4012d0 <_Unwind_Resume@plt>
  4016cc:	0f 1f 40 00          	nopl   0x0(%rax)
  401417:	84 c0                	test   %al,%al
  401419:	0f 84 85 00 00 00    	je     4014a4 <test1()+0xb4>
  40141f:	8a 44 24 28          	mov    0x28(%rsp),%al
  401423:	89 c1                	mov    %eax,%ecx
  401425:	80 e1 fe             	and    $0xfe,%cl
  401428:	80 f9 02             	cmp    $0x2,%cl
  40142b:	75 77                	jne    4014a4 <test1()+0xb4>
  40142d:	3c 03                	cmp    $0x3,%al
  40142f:	0f 84 a3 00 00 00    	je     4014d8 <test1()+0xe8>
  401435:	3c 02                	cmp    $0x2,%al
  401437:	75 6b                	jne    4014a4 <test1()+0xb4>
  401439:	44 8b 74 24 10       	mov    0x10(%rsp),%r14d
  40143e:	48 8b 6c 24 18       	mov    0x18(%rsp),%rbp
  401443:	48 8b 45 00          	mov    0x0(%rbp),%rax
  401447:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  40144c:	48 89 ee             	mov    %rbp,%rsi
  40144f:	44 89 f2             	mov    %r14d,%edx
  401452:	ff 50 18             	callq  *0x18(%rax)
  401455:	48 8d 7c 24 30       	lea    0x30(%rsp),%rdi
  40145a:	48 8d 74 24 08       	lea    0x8(%rsp),%rsi
  401120:	ff 25 0a 1f 20 00    	jmpq   *0x201f0a(%rip)        # 603030 <_GLOBAL_OFFSET_TABLE_+0x30>
  401126:	68 03 00 00 00       	pushq  $0x3
  40112b:	e9 b0 ff ff ff       	jmpq   4010e0 <_init+0x20>
  401464:	48 8b 44 24 08       	mov    0x8(%rsp),%rax
  401469:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  40146d:	b9 20 32 60 00       	mov    $0x603220,%ecx
  401472:	48 39 cf             	cmp    %rcx,%rdi
  401475:	75 70                	jne    4014e7 <test1()+0xf7>
  401477:	48 c7 44 24 30 68 31 	movq   $0x603168,0x30(%rsp)
  401480:	44 89 74 24 40       	mov    %r14d,0x40(%rsp)
  401485:	48 89 6c 24 48       	mov    %rbp,0x48(%rsp)
  40148a:	48 8d 6c 24 30       	lea    0x30(%rsp),%rbp
  40148f:	48 89 df             	mov    %rbx,%rdi
  401492:	48 89 ee             	mov    %rbp,%rsi
  4016d0:	41 57                	push   %r15
  4016d2:	41 56                	push   %r14
  4016d4:	53                   	push   %rbx
  4016d5:	49 89 f7             	mov    %rsi,%r15
  4016d8:	49 89 fe             	mov    %rdi,%r14
  4016db:	bf 20 00 00 00       	mov    $0x20,%edi
  401230:	ff 25 82 1e 20 00    	jmpq   *0x201e82(%rip)        # 6030b8 <_GLOBAL_OFFSET_TABLE_+0xb8>
  401236:	68 14 00 00 00       	pushq  $0x14
  40123b:	e9 a0 fe ff ff       	jmpq   4010e0 <_init+0x20>
  4016e5:	48 89 c3             	mov    %rax,%rbx
  4016e8:	48 c7 03 a0 31 60 00 	movq   $0x6031a0,(%rbx)
  4016ef:	48 8d 7b 08          	lea    0x8(%rbx),%rdi
  4016f3:	49 8d 77 08          	lea    0x8(%r15),%rsi
  401160:	ff 25 ea 1e 20 00    	jmpq   *0x201eea(%rip)        # 603050 <_GLOBAL_OFFSET_TABLE_+0x50>
  401166:	68 07 00 00 00       	pushq  $0x7
  40116b:	e9 70 ff ff ff       	jmpq   4010e0 <_init+0x20>
  4016fc:	48 c7 03 68 31 60 00 	movq   $0x603168,(%rbx)
  401703:	41 0f 10 47 10       	movups 0x10(%r15),%xmm0
  401708:	0f 11 43 10          	movups %xmm0,0x10(%rbx)
  40170c:	be 40 31 60 00       	mov    $0x603140,%esi
  401711:	ba c0 11 40 00       	mov    $0x4011c0,%edx
  401716:	48 89 df             	mov    %rbx,%rdi
  401260:	ff 25 6a 1e 20 00    	jmpq   *0x201e6a(%rip)        # 6030d0 <_GLOBAL_OFFSET_TABLE_+0xd0>
  401266:	68 17 00 00 00       	pushq  $0x17
  40126b:	e9 70 fe ff ff       	jmpq   4010e0 <_init+0x20>
  40171e:	49 89 c7             	mov    %rax,%r15
  401721:	eb 13                	jmp    401736 <std::__exception_ptr::exception_ptr std::make_exception_ptr<std::system_error>(std::system_error)+0x66>
  401723:	49 89 c7             	mov    %rax,%r15
  401726:	48 89 df             	mov    %rbx,%rdi
  401240:	ff 25 7a 1e 20 00    	jmpq   *0x201e7a(%rip)        # 6030c0 <_GLOBAL_OFFSET_TABLE_+0xc0>
  401246:	68 15 00 00 00       	pushq  $0x15
  40124b:	e9 90 fe ff ff       	jmpq   4010e0 <_init+0x20>
  40172e:	48 89 df             	mov    %rbx,%rdi
  401250:	ff 25 72 1e 20 00    	jmpq   *0x201e72(%rip)        # 6030c8 <_GLOBAL_OFFSET_TABLE_+0xc8>
  401256:	68 16 00 00 00       	pushq  $0x16
  40125b:	e9 80 fe ff ff       	jmpq   4010e0 <_init+0x20>
  401736:	4c 89 ff             	mov    %r15,%rdi
  4012b0:	ff 25 42 1e 20 00    	jmpq   *0x201e42(%rip)        # 6030f8 <_GLOBAL_OFFSET_TABLE_+0xf8>
  4012b6:	68 1c 00 00 00       	pushq  $0x1c
  4012bb:	e9 20 fe ff ff       	jmpq   4010e0 <_init+0x20>
  40173e:	4c 89 f7             	mov    %r14,%rdi
  4011f0:	ff 25 a2 1e 20 00    	jmpq   *0x201ea2(%rip)        # 603098 <_GLOBAL_OFFSET_TABLE_+0x98>
  4011f6:	68 10 00 00 00       	pushq  $0x10
  4011fb:	e9 e0 fe ff ff       	jmpq   4010e0 <_init+0x20>
  401290:	ff 25 52 1e 20 00    	jmpq   *0x201e52(%rip)        # 6030e8 <_GLOBAL_OFFSET_TABLE_+0xe8>
  401296:	68 1a 00 00 00       	pushq  $0x1a
  40129b:	e9 40 fe ff ff       	jmpq   4010e0 <_init+0x20>
  40174b:	4c 89 f0             	mov    %r14,%rax
  40174e:	5b                   	pop    %rbx
  40174f:	41 5e                	pop    %r14
  401751:	41 5f                	pop    %r15
  401753:	c3                   	retq
  401754:	48 89 c7             	mov    %rax,%rdi
  401840:	50                   	push   %rax
  401841:	e8 6a fa ff ff       	callq  4012b0 <__cxa_begin_catch@plt>
  401200:	ff 25 9a 1e 20 00    	jmpq   *0x201e9a(%rip)        # 6030a0 <_GLOBAL_OFFSET_TABLE_+0xa0>
  401206:	68 11 00 00 00       	pushq  $0x11
  40120b:	e9 d0 fe ff ff       	jmpq   4010e0 <_init+0x20>
  40184b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
  40175c:	0f 1f 40 00          	nopl   0x0(%rax)
  40149a:	48 89 ef             	mov    %rbp,%rdi
  4011c0:	ff 25 ba 1e 20 00    	jmpq   *0x201eba(%rip)        # 603080 <_GLOBAL_OFFSET_TABLE_+0x80>
  4011c6:	68 0d 00 00 00       	pushq  $0xd
  4011cb:	e9 10 ff ff ff       	jmpq   4010e0 <_init+0x20>
  4014a2:	eb 08                	jmp    4014ac <test1()+0xbc>
  4014a4:	48 89 df             	mov    %rbx,%rdi
  4011b0:	ff 25 c2 1e 20 00    	jmpq   *0x201ec2(%rip)        # 603078 <_GLOBAL_OFFSET_TABLE_+0x78>
  4011b6:	68 0c 00 00 00       	pushq  $0xc
  4011bb:	e9 20 ff ff ff       	jmpq   4010e0 <_init+0x20>
  4014ac:	8a 44 24 28          	mov    0x28(%rsp),%al
  4014b0:	89 c1                	mov    %eax,%ecx
  4014b2:	fe c9                	dec    %cl
  4014b4:	80 f9 02             	cmp    $0x2,%cl
  4014b7:	72 0e                	jb     4014c7 <test1()+0xd7>
  4014b9:	3c 03                	cmp    $0x3,%al
  4014bb:	75 0f                	jne    4014cc <test1()+0xdc>
  4014bd:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
  401220:	ff 25 8a 1e 20 00    	jmpq   *0x201e8a(%rip)        # 6030b0 <_GLOBAL_OFFSET_TABLE_+0xb0>
  401226:	68 13 00 00 00       	pushq  $0x13
  40122b:	e9 b0 fe ff ff       	jmpq   4010e0 <_init+0x20>
  4014c7:	c6 44 24 28 00       	movb   $0x0,0x28(%rsp)
  4014cc:	48 89 d8             	mov    %rbx,%rax
  4014cf:	48 83 c4 50          	add    $0x50,%rsp
  4014d3:	5b                   	pop    %rbx
  4014d4:	41 5e                	pop    %r14
  4014d6:	5d                   	pop    %rbp
  4014d7:	c3                   	retq
  4014d8:	48 8d 74 24 10       	lea    0x10(%rsp),%rsi
  4014dd:	48 89 df             	mov    %rbx,%rdi
  401270:	ff 25 62 1e 20 00    	jmpq   *0x201e62(%rip)        # 6030d8 <_GLOBAL_OFFSET_TABLE_+0xd8>
  401276:	68 18 00 00 00       	pushq  $0x18
  40127b:	e9 60 fe ff ff       	jmpq   4010e0 <_init+0x20>
  4014e5:	eb c5                	jmp    4014ac <test1()+0xbc>
  4014e7:	b9 00 00 00 00       	mov    $0x0,%ecx
  4014ec:	48 85 c9             	test   %rcx,%rcx
  4014ef:	74 14                	je     401505 <test1()+0x115>
  4014f1:	b9 ff ff ff ff       	mov    $0xffffffff,%ecx
  4014f6:	f0 0f c1 48 f8       	lock xadd %ecx,-0x8(%rax)
  4014fb:	85 c9                	test   %ecx,%ecx
  4014fd:	0f 8f 74 ff ff ff    	jg     401477 <test1()+0x87>
  401503:	eb 11                	jmp    401516 <test1()+0x126>
  401505:	8b 48 f8             	mov    -0x8(%rax),%ecx
  401508:	8d 51 ff             	lea    -0x1(%rcx),%edx
  40150b:	89 50 f8             	mov    %edx,-0x8(%rax)
  40150e:	85 c9                	test   %ecx,%ecx
  401510:	0f 8f 61 ff ff ff    	jg     401477 <test1()+0x87>
  401516:	48 89 e6             	mov    %rsp,%rsi
  401180:	ff 25 da 1e 20 00    	jmpq   *0x201eda(%rip)        # 603060 <_GLOBAL_OFFSET_TABLE_+0x60>
  401186:	68 09 00 00 00       	pushq  $0x9
  40118b:	e9 50 ff ff ff       	jmpq   4010e0 <_init+0x20>
  40151e:	e9 54 ff ff ff       	jmpq   401477 <test1()+0x87>
  401523:	48 89 c3             	mov    %rax,%rbx
  401526:	48 8b 44 24 08       	mov    0x8(%rsp),%rax
  40152b:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  40152f:	b9 20 32 60 00       	mov    $0x603220,%ecx
  401534:	48 39 cf             	cmp    %rcx,%rdi
  401537:	74 34                	je     40156d <test1()+0x17d>
  401539:	b9 00 00 00 00       	mov    $0x0,%ecx
  40153e:	48 85 c9             	test   %rcx,%rcx
  401541:	74 10                	je     401553 <test1()+0x163>
  401543:	b9 ff ff ff ff       	mov    $0xffffffff,%ecx
  401548:	f0 0f c1 48 f8       	lock xadd %ecx,-0x8(%rax)
  40154d:	85 c9                	test   %ecx,%ecx
  40154f:	7e 0f                	jle    401560 <test1()+0x170>
  401551:	eb 1a                	jmp    40156d <test1()+0x17d>
  401553:	8b 48 f8             	mov    -0x8(%rax),%ecx
  401556:	8d 51 ff             	lea    -0x1(%rcx),%edx
  401559:	89 50 f8             	mov    %edx,-0x8(%rax)
  40155c:	85 c9                	test   %ecx,%ecx
  40155e:	7f 0d                	jg     40156d <test1()+0x17d>
  401560:	48 89 e6             	mov    %rsp,%rsi
  401180:	ff 25 da 1e 20 00    	jmpq   *0x201eda(%rip)        # 603060 <_GLOBAL_OFFSET_TABLE_+0x60>
  401186:	68 09 00 00 00       	pushq  $0x9
  40118b:	e9 50 ff ff ff       	jmpq   4010e0 <_init+0x20>
  401568:	eb 03                	jmp    40156d <test1()+0x17d>
  40156a:	48 89 c3             	mov    %rax,%rbx
  40156d:	8a 44 24 28          	mov    0x28(%rsp),%al
  401571:	89 c1                	mov    %eax,%ecx
  401573:	fe c9                	dec    %cl
  401575:	80 f9 02             	cmp    $0x2,%cl
  401578:	72 0e                	jb     401588 <test1()+0x198>
  40157a:	3c 03                	cmp    $0x3,%al
  40157c:	75 0f                	jne    40158d <test1()+0x19d>
  40157e:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
  401220:	ff 25 8a 1e 20 00    	jmpq   *0x201e8a(%rip)        # 6030b0 <_GLOBAL_OFFSET_TABLE_+0xb0>
  401226:	68 13 00 00 00       	pushq  $0x13
  40122b:	e9 b0 fe ff ff       	jmpq   4010e0 <_init+0x20>
  401588:	c6 44 24 28 00       	movb   $0x0,0x28(%rsp)
  40158d:	48 89 df             	mov    %rbx,%rdi
  4012d0:	ff 25 32 1e 20 00    	jmpq   *0x201e32(%rip)        # 603108 <_GLOBAL_OFFSET_TABLE_+0x108>
  4012d6:	68 1e 00 00 00       	pushq  $0x1e
  4012db:	e9 00 fe ff ff       	jmpq   4010e0 <_init+0x20>
  401595:	66 66 2e 0f 1f 84 00 	data32 nopw %cs:0x0(%rax,%rax,1)
