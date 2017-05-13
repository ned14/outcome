  4011a0:	55                   	push   %rbp
  4011a1:	53                   	push   %rbx
  4011a2:	48 89 fb             	mov    %rdi,%rbx
  4011a5:	48 83 ec 68          	sub    $0x68,%rsp
  4011a9:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
  4011ae:	e8 4d ee bf ff       	callq  0 <_init-0x400e80>
  4011b3:	0f b6 54 24 38       	movzbl 0x38(%rsp),%edx
  4011b8:	c6 44 24 58 00       	movb   $0x0,0x58(%rsp)
  4011bd:	80 fa 02             	cmp    $0x2,%dl
  4011c0:	0f 84 fa 00 00 00    	je     4012c0 <test1()+0x120>
  4011c6:	80 fa 03             	cmp    $0x3,%dl
  4011c9:	0f 84 59 01 00 00    	je     401328 <test1()+0x188>
  4011cf:	80 fa 01             	cmp    $0x1,%dl
  4011d2:	0f 84 c8 00 00 00    	je     4012a0 <test1()+0x100>
  4011d8:	84 d2                	test   %dl,%dl
  4011da:	88 54 24 58          	mov    %dl,0x58(%rsp)
  4011de:	74 40                	je     401220 <test1()+0x80>
  4011e0:	80 fa 02             	cmp    $0x2,%dl
  4011e3:	0f 85 0d 02 00 00    	jne    4013f6 <test1()+0x256>
  4011e9:	bf 20 00 00 00       	mov    $0x20,%edi
  400fb0:	ff 25 e2 10 20 00    	jmpq   *0x2010e2(%rip)        # 602098 <_GLOBAL_OFFSET_TABLE_+0x98>
  400fb6:	68 10 00 00 00       	pushq  $0x10
  400fbb:	e9 e0 fe ff ff       	jmpq   400ea0 <_init+0x20>
  4011f3:	8b 74 24 40          	mov    0x40(%rsp),%esi
  4011f7:	48 8b 54 24 48       	mov    0x48(%rsp),%rdx
  4011fc:	48 89 c7             	mov    %rax,%rdi
  4011ff:	48 89 c5             	mov    %rax,%rbp
  401530:	41 55                	push   %r13
  401532:	41 54                	push   %r12
  401534:	49 89 f5             	mov    %rsi,%r13
  401537:	55                   	push   %rbp
  401538:	53                   	push   %rbx
  401539:	48 89 d5             	mov    %rdx,%rbp
  40153c:	48 89 fb             	mov    %rdi,%rbx
  40153f:	48 83 ec 28          	sub    $0x28,%rsp
  401543:	48 8b 02             	mov    (%rdx),%rax
  401546:	4c 8d 64 24 10       	lea    0x10(%rsp),%r12
  40154b:	48 8b 40 18          	mov    0x18(%rax),%rax
  40154f:	48 3d b0 14 40 00    	cmp    $0x4014b0,%rax
  401555:	0f 85 95 00 00 00    	jne    4015f0 <std::system_error::system_error(std::error_code)+0xc0>
  40155b:	83 fe 02             	cmp    $0x2,%esi
  40155e:	48 8d 54 24 0f       	lea    0xf(%rsp),%rdx
  401563:	74 7b                	je     4015e0 <std::system_error::system_error(std::error_code)+0xb0>
  401565:	83 fe 03             	cmp    $0x3,%esi
  401568:	74 4e                	je     4015b8 <std::system_error::system_error(std::error_code)+0x88>
  40156a:	83 fe 01             	cmp    $0x1,%esi
  40156d:	74 61                	je     4015d0 <std::system_error::system_error(std::error_code)+0xa0>
  40156f:	be 57 17 40 00       	mov    $0x401757,%esi
  401574:	4c 89 e7             	mov    %r12,%rdi
  400f80:	ff 25 fa 10 20 00    	jmpq   *0x2010fa(%rip)        # 602080 <_GLOBAL_OFFSET_TABLE_+0x80>
  400f86:	68 0d 00 00 00       	pushq  $0xd
  400f8b:	e9 10 ff ff ff       	jmpq   400ea0 <_init+0x20>
  40157c:	4c 89 e6             	mov    %r12,%rsi
  40157f:	48 89 df             	mov    %rbx,%rdi
  400ee0:	ff 25 4a 11 20 00    	jmpq   *0x20114a(%rip)        # 602030 <_GLOBAL_OFFSET_TABLE_+0x30>
  400ee6:	68 03 00 00 00       	pushq  $0x3
  400eeb:	e9 b0 ff ff ff       	jmpq   400ea0 <_init+0x20>
  401587:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  40158c:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  401590:	48 81 ff a0 21 60 00 	cmp    $0x6021a0,%rdi
  401597:	75 67                	jne    401600 <std::system_error::system_error(std::error_code)+0xd0>
  401599:	48 c7 03 28 21 60 00 	movq   $0x602128,(%rbx)
  4015a0:	4c 89 6b 10          	mov    %r13,0x10(%rbx)
  4015a4:	48 89 6b 18          	mov    %rbp,0x18(%rbx)
  4015a8:	48 83 c4 28          	add    $0x28,%rsp
  4015ac:	5b                   	pop    %rbx
  4015ad:	5d                   	pop    %rbp
  4015ae:	41 5c                	pop    %r12
  4015b0:	41 5d                	pop    %r13
  4015b2:	c3                   	retq
  4015b3:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
  4015b8:	be 45 17 40 00       	mov    $0x401745,%esi
  4015bd:	4c 89 e7             	mov    %r12,%rdi
  4015c0:	e8 bb f9 ff ff       	callq  400f80 <std::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string(char const*, std::allocator<char> const&)@plt>
  4015c5:	eb b5                	jmp    40157c <std::system_error::system_error(std::error_code)+0x4c>
  4015c7:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  4015d0:	be 30 17 40 00       	mov    $0x401730,%esi
  4015d5:	4c 89 e7             	mov    %r12,%rdi
  4015d8:	e8 a3 f9 ff ff       	callq  400f80 <std::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string(char const*, std::allocator<char> const&)@plt>
  4015dd:	eb 9d                	jmp    40157c <std::system_error::system_error(std::error_code)+0x4c>
  4015df:	90                   	nop
  4015e0:	be 3c 17 40 00       	mov    $0x40173c,%esi
  4015e5:	4c 89 e7             	mov    %r12,%rdi
  4015e8:	e8 93 f9 ff ff       	callq  400f80 <std::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string(char const*, std::allocator<char> const&)@plt>
  4015ed:	eb 8d                	jmp    40157c <std::system_error::system_error(std::error_code)+0x4c>
  4015ef:	90                   	nop
  4015f0:	89 f2                	mov    %esi,%edx
  4015f2:	4c 89 e7             	mov    %r12,%rdi
  4015f5:	48 89 ee             	mov    %rbp,%rsi
  4015f8:	ff d0                	callq  *%rax
  4015fa:	eb 80                	jmp    40157c <std::system_error::system_error(std::error_code)+0x4c>
  4015fc:	0f 1f 40 00          	nopl   0x0(%rax)
  401600:	ba 00 00 00 00       	mov    $0x0,%edx
  401605:	48 85 d2             	test   %rdx,%rdx
  401608:	74 26                	je     401630 <std::system_error::system_error(std::error_code)+0x100>
  40160a:	ba ff ff ff ff       	mov    $0xffffffff,%edx
  40160f:	f0 0f c1 50 f8       	lock xadd %edx,-0x8(%rax)
  401614:	85 d2                	test   %edx,%edx
  401616:	7f 81                	jg     401599 <std::system_error::system_error(std::error_code)+0x69>
  401618:	48 8d 74 24 0f       	lea    0xf(%rsp),%rsi
  400f30:	ff 25 22 11 20 00    	jmpq   *0x201122(%rip)        # 602058 <_GLOBAL_OFFSET_TABLE_+0x58>
  400f36:	68 08 00 00 00       	pushq  $0x8
  400f3b:	e9 60 ff ff ff       	jmpq   400ea0 <_init+0x20>
  401622:	e9 72 ff ff ff       	jmpq   401599 <std::system_error::system_error(std::error_code)+0x69>
  401627:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  401630:	8b 50 f8             	mov    -0x8(%rax),%edx
  401633:	8d 4a ff             	lea    -0x1(%rdx),%ecx
  401636:	89 48 f8             	mov    %ecx,-0x8(%rax)
  401639:	eb d9                	jmp    401614 <std::system_error::system_error(std::error_code)+0xe4>
  40163b:	48 89 c3             	mov    %rax,%rbx
  40163e:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  401643:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  401647:	48 81 ff a0 21 60 00 	cmp    $0x6021a0,%rdi
  40164e:	74 0a                	je     40165a <std::system_error::system_error(std::error_code)+0x12a>
  401650:	48 8d 74 24 0f       	lea    0xf(%rsp),%rsi
  401040:	b8 00 00 00 00       	mov    $0x0,%eax
  401045:	48 85 c0             	test   %rax,%rax
  401048:	74 0a                	je     401054 <std::string::_Rep::_M_dispose(std::allocator<char> const&) [clone .part.1]+0x14>
  40104a:	83 c8 ff             	or     $0xffffffff,%eax
  40104d:	f0 0f c1 47 10       	lock xadd %eax,0x10(%rdi)
  401052:	eb 09                	jmp    40105d <std::string::_Rep::_M_dispose(std::allocator<char> const&) [clone .part.1]+0x1d>
  401054:	8b 47 10             	mov    0x10(%rdi),%eax
  401057:	8d 50 ff             	lea    -0x1(%rax),%edx
  40105a:	89 57 10             	mov    %edx,0x10(%rdi)
  40105d:	85 c0                	test   %eax,%eax
  40105f:	7f 05                	jg     401066 <std::string::_Rep::_M_dispose(std::allocator<char> const&) [clone .part.1]+0x26>
  401061:	e9 ca fe ff ff       	jmpq   400f30 <std::string::_Rep::_M_destroy(std::allocator<char> const&)@plt>
  401066:	c3                   	retq
  401067:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  40165a:	48 89 df             	mov    %rbx,%rdi
  401010:	ff 25 b2 10 20 00    	jmpq   *0x2010b2(%rip)        # 6020c8 <_GLOBAL_OFFSET_TABLE_+0xc8>
  401016:	68 16 00 00 00       	pushq  $0x16
  40101b:	e9 80 fe ff ff       	jmpq   400ea0 <_init+0x20>
  401662:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  40166c:	0f 1f 40 00          	nopl   0x0(%rax)
  401207:	ba 60 0f 40 00       	mov    $0x400f60,%edx
  40120c:	be 00 21 60 00       	mov    $0x602100,%esi
  401211:	48 89 ef             	mov    %rbp,%rdi
  400fd0:	ff 25 d2 10 20 00    	jmpq   *0x2010d2(%rip)        # 6020a8 <_GLOBAL_OFFSET_TABLE_+0xa8>
  400fd6:	68 12 00 00 00       	pushq  $0x12
  400fdb:	e9 c0 fe ff ff       	jmpq   400ea0 <_init+0x20>
  401219:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
  401220:	bf 20 00 00 00       	mov    $0x20,%edi
  400fb0:	ff 25 e2 10 20 00    	jmpq   *0x2010e2(%rip)        # 602098 <_GLOBAL_OFFSET_TABLE_+0x98>
  400fb6:	68 10 00 00 00       	pushq  $0x10
  400fbb:	e9 e0 fe ff ff       	jmpq   400ea0 <_init+0x20>
  40122a:	48 89 c3             	mov    %rax,%rbx
  40122d:	0f b6 05 a4 0f 20 00 	movzbl 0x200fa4(%rip),%eax        # 6021d8 <guard variable for boost::outcome::_1_0_std_std_9274c0d4::monad_category()::c>
  401234:	84 c0                	test   %al,%al
  401236:	0f 84 b4 00 00 00    	je     4012f0 <test1()+0x150>
  40123c:	48 8d 54 24 0f       	lea    0xf(%rsp),%rdx
  401241:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
  401246:	be 3c 17 40 00       	mov    $0x40173c,%esi
  400f80:	ff 25 fa 10 20 00    	jmpq   *0x2010fa(%rip)        # 602080 <_GLOBAL_OFFSET_TABLE_+0x80>
  400f86:	68 0d 00 00 00       	pushq  $0xd
  400f8b:	e9 10 ff ff ff       	jmpq   400ea0 <_init+0x20>
  401250:	48 8d 74 24 10       	lea    0x10(%rsp),%rsi
  401255:	48 89 df             	mov    %rbx,%rdi
  400ee0:	ff 25 4a 11 20 00    	jmpq   *0x20114a(%rip)        # 602030 <_GLOBAL_OFFSET_TABLE_+0x30>
  400ee6:	68 03 00 00 00       	pushq  $0x3
  400eeb:	e9 b0 ff ff ff       	jmpq   400ea0 <_init+0x20>
  40125d:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  401262:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  401266:	48 81 ff a0 21 60 00 	cmp    $0x6021a0,%rdi
  40126d:	0f 85 05 01 00 00    	jne    401378 <test1()+0x1d8>
  401273:	c7 43 10 02 00 00 00 	movl   $0x2,0x10(%rbx)
  40127a:	48 c7 43 18 f0 20 60 	movq   $0x6020f0,0x18(%rbx)
  401282:	ba 50 14 40 00       	mov    $0x401450,%edx
  401287:	48 c7 03 70 18 40 00 	movq   $0x401870,(%rbx)
  40128e:	be f8 17 40 00       	mov    $0x4017f8,%esi
  401293:	48 89 df             	mov    %rbx,%rdi
  400fd0:	ff 25 d2 10 20 00    	jmpq   *0x2010d2(%rip)        # 6020a8 <_GLOBAL_OFFSET_TABLE_+0xa8>
  400fd6:	68 12 00 00 00       	pushq  $0x12
  400fdb:	e9 c0 fe ff ff       	jmpq   400ea0 <_init+0x20>
  40129b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
  4012a0:	8b 44 24 20          	mov    0x20(%rsp),%eax
  4012a4:	c6 43 18 01          	movb   $0x1,0x18(%rbx)
  4012a8:	8d 04 40             	lea    (%rax,%rax,2),%eax
  4012ab:	89 03                	mov    %eax,(%rbx)
  4012ad:	48 83 c4 68          	add    $0x68,%rsp
  4012b1:	48 89 d8             	mov    %rbx,%rax
  4012b4:	5b                   	pop    %rbx
  4012b5:	5d                   	pop    %rbp
  4012b6:	c3                   	retq
  4012b7:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  4012c0:	48 8b 44 24 20       	mov    0x20(%rsp),%rax
  4012c5:	c6 44 24 58 02       	movb   $0x2,0x58(%rsp)
  4012ca:	48 89 44 24 40       	mov    %rax,0x40(%rsp)
  4012cf:	48 8b 44 24 28       	mov    0x28(%rsp),%rax
  4012d4:	48 89 44 24 48       	mov    %rax,0x48(%rsp)
  4012d9:	48 8b 44 24 30       	mov    0x30(%rsp),%rax
  4012de:	48 89 44 24 50       	mov    %rax,0x50(%rsp)
  4012e3:	e9 01 ff ff ff       	jmpq   4011e9 <test1()+0x49>
  4012e8:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
  4012f0:	bf d8 21 60 00       	mov    $0x6021d8,%edi
  400ed0:	ff 25 52 11 20 00    	jmpq   *0x201152(%rip)        # 602028 <_GLOBAL_OFFSET_TABLE_+0x28>
  400ed6:	68 02 00 00 00       	pushq  $0x2
  400edb:	e9 c0 ff ff ff       	jmpq   400ea0 <_init+0x20>
  4012fa:	85 c0                	test   %eax,%eax
  4012fc:	0f 84 3a ff ff ff    	je     40123c <test1()+0x9c>
  401302:	bf d8 21 60 00       	mov    $0x6021d8,%edi
  400f50:	ff 25 12 11 20 00    	jmpq   *0x201112(%rip)        # 602068 <_GLOBAL_OFFSET_TABLE_+0x68>
  400f56:	68 0a 00 00 00       	pushq  $0xa
  400f5b:	e9 40 ff ff ff       	jmpq   400ea0 <_init+0x20>
  40130c:	ba e8 20 60 00       	mov    $0x6020e8,%edx
  401311:	be f0 20 60 00       	mov    $0x6020f0,%esi
  401316:	bf 80 14 40 00       	mov    $0x401480,%edi
  400f20:	ff 25 2a 11 20 00    	jmpq   *0x20112a(%rip)        # 602050 <_GLOBAL_OFFSET_TABLE_+0x50>
  400f26:	68 07 00 00 00       	pushq  $0x7
  400f2b:	e9 70 ff ff ff       	jmpq   400ea0 <_init+0x20>
  401320:	e9 17 ff ff ff       	jmpq   40123c <test1()+0x9c>
  401325:	0f 1f 00             	nopl   (%rax)
  401328:	48 8d 6c 24 40       	lea    0x40(%rsp),%rbp
  40132d:	48 8d 74 24 20       	lea    0x20(%rsp),%rsi
  401332:	48 89 ef             	mov    %rbp,%rdi
  400fe0:	ff 25 ca 10 20 00    	jmpq   *0x2010ca(%rip)        # 6020b0 <_GLOBAL_OFFSET_TABLE_+0xb0>
  400fe6:	68 13 00 00 00       	pushq  $0x13
  400feb:	e9 b0 fe ff ff       	jmpq   400ea0 <_init+0x20>
  40133a:	0f b6 54 24 38       	movzbl 0x38(%rsp),%edx
  40133f:	84 d2                	test   %dl,%dl
  401341:	88 54 24 58          	mov    %dl,0x58(%rsp)
  401345:	0f 85 95 fe ff ff    	jne    4011e0 <test1()+0x40>
  40134b:	e9 d0 fe ff ff       	jmpq   401220 <test1()+0x80>
  401350:	48 8d 6c 24 40       	lea    0x40(%rsp),%rbp
  401355:	48 89 c3             	mov    %rax,%rbx
  401358:	48 89 ef             	mov    %rbp,%rdi
  401670:	0f b6 47 18          	movzbl 0x18(%rdi),%eax
  401674:	3c 02                	cmp    $0x2,%al
  401676:	74 10                	je     401688 <boost::outcome::_1_0_std_std_9274c0d4::detail::value_storage_impl_nontrivial<int, boost::outcome::_1_0_std_std_9274c0d4::error_code_extended, std::__exception_ptr::exception_ptr, false>::clear()+0x18>
  401678:	3c 03                	cmp    $0x3,%al
  40167a:	74 14                	je     401690 <boost::outcome::_1_0_std_std_9274c0d4::detail::value_storage_impl_nontrivial<int, boost::outcome::_1_0_std_std_9274c0d4::error_code_extended, std::__exception_ptr::exception_ptr, false>::clear()+0x20>
  40167c:	3c 01                	cmp    $0x1,%al
  40167e:	74 08                	je     401688 <boost::outcome::_1_0_std_std_9274c0d4::detail::value_storage_impl_nontrivial<int, boost::outcome::_1_0_std_std_9274c0d4::error_code_extended, std::__exception_ptr::exception_ptr, false>::clear()+0x18>
  401680:	f3 c3                	repz retq
  401682:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
  401688:	c6 47 18 00          	movb   $0x0,0x18(%rdi)
  40168c:	c3                   	retq
  40168d:	0f 1f 00             	nopl   (%rax)
  401690:	53                   	push   %rbx
  401691:	48 89 fb             	mov    %rdi,%rbx
  400fa0:	ff 25 ea 10 20 00    	jmpq   *0x2010ea(%rip)        # 602090 <_GLOBAL_OFFSET_TABLE_+0x90>
  400fa6:	68 0f 00 00 00       	pushq  $0xf
  400fab:	e9 f0 fe ff ff       	jmpq   400ea0 <_init+0x20>
  401699:	c6 43 18 00          	movb   $0x0,0x18(%rbx)
  40169d:	5b                   	pop    %rbx
  40169e:	c3                   	retq
  40169f:	90                   	nop
  401360:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
  401670:	0f b6 47 18          	movzbl 0x18(%rdi),%eax
  401674:	3c 02                	cmp    $0x2,%al
  401676:	74 10                	je     401688 <boost::outcome::_1_0_std_std_9274c0d4::detail::value_storage_impl_nontrivial<int, boost::outcome::_1_0_std_std_9274c0d4::error_code_extended, std::__exception_ptr::exception_ptr, false>::clear()+0x18>
  401678:	3c 03                	cmp    $0x3,%al
  40167a:	74 14                	je     401690 <boost::outcome::_1_0_std_std_9274c0d4::detail::value_storage_impl_nontrivial<int, boost::outcome::_1_0_std_std_9274c0d4::error_code_extended, std::__exception_ptr::exception_ptr, false>::clear()+0x20>
  40167c:	3c 01                	cmp    $0x1,%al
  40167e:	74 08                	je     401688 <boost::outcome::_1_0_std_std_9274c0d4::detail::value_storage_impl_nontrivial<int, boost::outcome::_1_0_std_std_9274c0d4::error_code_extended, std::__exception_ptr::exception_ptr, false>::clear()+0x18>
  401680:	f3 c3                	repz retq
  401682:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
  401688:	c6 47 18 00          	movb   $0x0,0x18(%rdi)
  40168c:	c3                   	retq
  40168d:	0f 1f 00             	nopl   (%rax)
  401690:	53                   	push   %rbx
  401691:	48 89 fb             	mov    %rdi,%rbx
  400fa0:	ff 25 ea 10 20 00    	jmpq   *0x2010ea(%rip)        # 602090 <_GLOBAL_OFFSET_TABLE_+0x90>
  400fa6:	68 0f 00 00 00       	pushq  $0xf
  400fab:	e9 f0 fe ff ff       	jmpq   400ea0 <_init+0x20>
  401699:	c6 43 18 00          	movb   $0x0,0x18(%rbx)
  40169d:	5b                   	pop    %rbx
  40169e:	c3                   	retq
  40169f:	90                   	nop
  40136a:	48 89 df             	mov    %rbx,%rdi
  401010:	ff 25 b2 10 20 00    	jmpq   *0x2010b2(%rip)        # 6020c8 <_GLOBAL_OFFSET_TABLE_+0xc8>
  401016:	68 16 00 00 00       	pushq  $0x16
  40101b:	e9 80 fe ff ff       	jmpq   400ea0 <_init+0x20>
  401372:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
  401378:	ba 00 00 00 00       	mov    $0x0,%edx
  40137d:	48 85 d2             	test   %rdx,%rdx
  401380:	74 21                	je     4013a3 <test1()+0x203>
  401382:	ba ff ff ff ff       	mov    $0xffffffff,%edx
  401387:	f0 0f c1 50 f8       	lock xadd %edx,-0x8(%rax)
  40138c:	85 d2                	test   %edx,%edx
  40138e:	0f 8f df fe ff ff    	jg     401273 <test1()+0xd3>
  401394:	48 8d 74 24 0f       	lea    0xf(%rsp),%rsi
  400f30:	ff 25 22 11 20 00    	jmpq   *0x201122(%rip)        # 602058 <_GLOBAL_OFFSET_TABLE_+0x58>
  400f36:	68 08 00 00 00       	pushq  $0x8
  400f3b:	e9 60 ff ff ff       	jmpq   400ea0 <_init+0x20>
  40139e:	e9 d0 fe ff ff       	jmpq   401273 <test1()+0xd3>
  4013a3:	8b 50 f8             	mov    -0x8(%rax),%edx
  4013a6:	8d 4a ff             	lea    -0x1(%rdx),%ecx
  4013a9:	89 48 f8             	mov    %ecx,-0x8(%rax)
  4013ac:	eb de                	jmp    40138c <test1()+0x1ec>
  4013ae:	48 89 c5             	mov    %rax,%rbp
  4013b1:	48 89 df             	mov    %rbx,%rdi
  4013b4:	48 89 eb             	mov    %rbp,%rbx
  4013b7:	48 8d 6c 24 40       	lea    0x40(%rsp),%rbp
  400fc0:	ff 25 da 10 20 00    	jmpq   *0x2010da(%rip)        # 6020a0 <_GLOBAL_OFFSET_TABLE_+0xa0>
  400fc6:	68 11 00 00 00       	pushq  $0x11
  400fcb:	e9 d0 fe ff ff       	jmpq   400ea0 <_init+0x20>
  4013c1:	eb 95                	jmp    401358 <test1()+0x1b8>
  4013c3:	48 89 ef             	mov    %rbp,%rdi
  4013c6:	48 89 c3             	mov    %rax,%rbx
  4013c9:	48 8d 6c 24 40       	lea    0x40(%rsp),%rbp
  400fc0:	ff 25 da 10 20 00    	jmpq   *0x2010da(%rip)        # 6020a0 <_GLOBAL_OFFSET_TABLE_+0xa0>
  400fc6:	68 11 00 00 00       	pushq  $0x11
  400fcb:	e9 d0 fe ff ff       	jmpq   400ea0 <_init+0x20>
  4013d3:	eb 83                	jmp    401358 <test1()+0x1b8>
  4013d5:	48 89 c5             	mov    %rax,%rbp
  4013d8:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  4013dd:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  4013e1:	48 81 ff a0 21 60 00 	cmp    $0x6021a0,%rdi
  4013e8:	74 c7                	je     4013b1 <test1()+0x211>
  4013ea:	48 8d 74 24 0f       	lea    0xf(%rsp),%rsi
  401040:	b8 00 00 00 00       	mov    $0x0,%eax
  401045:	48 85 c0             	test   %rax,%rax
  401048:	74 0a                	je     401054 <std::string::_Rep::_M_dispose(std::allocator<char> const&) [clone .part.1]+0x14>
  40104a:	83 c8 ff             	or     $0xffffffff,%eax
  40104d:	f0 0f c1 47 10       	lock xadd %eax,0x10(%rdi)
  401052:	eb 09                	jmp    40105d <std::string::_Rep::_M_dispose(std::allocator<char> const&) [clone .part.1]+0x1d>
  401054:	8b 47 10             	mov    0x10(%rdi),%eax
  401057:	8d 50 ff             	lea    -0x1(%rax),%edx
  40105a:	89 57 10             	mov    %edx,0x10(%rdi)
  40105d:	85 c0                	test   %eax,%eax
  40105f:	7f 05                	jg     401066 <std::string::_Rep::_M_dispose(std::allocator<char> const&) [clone .part.1]+0x26>
  401061:	e9 ca fe ff ff       	jmpq   400f30 <std::string::_Rep::_M_destroy(std::allocator<char> const&)@plt>
  401066:	c3                   	retq
  401067:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  4013f4:	eb bb                	jmp    4013b1 <test1()+0x211>
  4013f6:	80 fa 03             	cmp    $0x3,%dl
  4013f9:	74 17                	je     401412 <test1()+0x272>
  4013fb:	8b 44 24 40          	mov    0x40(%rsp),%eax
  4013ff:	c6 43 18 01          	movb   $0x1,0x18(%rbx)
  401403:	8d 04 40             	lea    (%rax,%rax,2),%eax
  401406:	89 03                	mov    %eax,(%rbx)
  401408:	48 83 c4 68          	add    $0x68,%rsp
  40140c:	48 89 d8             	mov    %rbx,%rax
  40140f:	5b                   	pop    %rbx
  401410:	5d                   	pop    %rbp
  401411:	c3                   	retq
  401412:	48 8d 6c 24 40       	lea    0x40(%rsp),%rbp
  401417:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
  40141c:	48 89 ee             	mov    %rbp,%rsi
  400fe0:	ff 25 ca 10 20 00    	jmpq   *0x2010ca(%rip)        # 6020b0 <_GLOBAL_OFFSET_TABLE_+0xb0>
  400fe6:	68 13 00 00 00       	pushq  $0x13
  400feb:	e9 b0 fe ff ff       	jmpq   400ea0 <_init+0x20>
  401424:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
  401020:	ff 25 aa 10 20 00    	jmpq   *0x2010aa(%rip)        # 6020d0 <_GLOBAL_OFFSET_TABLE_+0xd0>
  401026:	68 17 00 00 00       	pushq  $0x17
  40102b:	e9 70 fe ff ff       	jmpq   400ea0 <_init+0x20>
  40142e:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
  401433:	48 89 c3             	mov    %rax,%rbx
  400fa0:	ff 25 ea 10 20 00    	jmpq   *0x2010ea(%rip)        # 602090 <_GLOBAL_OFFSET_TABLE_+0x90>
  400fa6:	68 0f 00 00 00       	pushq  $0xf
  400fab:	e9 f0 fe ff ff       	jmpq   400ea0 <_init+0x20>
  40143b:	e9 18 ff ff ff       	jmpq   401358 <test1()+0x1b8>
