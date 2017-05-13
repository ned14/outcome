  401190:	55                   	push   %rbp
  401191:	53                   	push   %rbx
  401192:	48 83 ec 48          	sub    $0x48,%rsp
  401196:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
  40119b:	e8 60 ee bf ff       	callq  0 <_init-0x400e80>
  4011a0:	0f b6 44 24 38       	movzbl 0x38(%rsp),%eax
  4011a5:	84 c0                	test   %al,%al
  4011a7:	75 7f                	jne    401228 <test1()+0x98>
  4011a9:	bf 20 00 00 00       	mov    $0x20,%edi
  400fb0:	ff 25 e2 10 20 00    	jmpq   *0x2010e2(%rip)        # 602098 <_GLOBAL_OFFSET_TABLE_+0x98>
  400fb6:	68 10 00 00 00       	pushq  $0x10
  400fbb:	e9 e0 fe ff ff       	jmpq   400ea0 <_init+0x20>
  4011b3:	48 89 c3             	mov    %rax,%rbx
  4011b6:	0f b6 05 1b 10 20 00 	movzbl 0x20101b(%rip),%eax        # 6021d8 <guard variable for boost::outcome::_1_0_std_std_9274c0d4::monad_category()::c>
  4011bd:	84 c0                	test   %al,%al
  4011bf:	0f 84 9b 00 00 00    	je     401260 <test1()+0xd0>
  4011c5:	48 8d 54 24 0f       	lea    0xf(%rsp),%rdx
  4011ca:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
  4011cf:	be 3c 16 40 00       	mov    $0x40163c,%esi
  400f80:	ff 25 fa 10 20 00    	jmpq   *0x2010fa(%rip)        # 602080 <_GLOBAL_OFFSET_TABLE_+0x80>
  400f86:	68 0d 00 00 00       	pushq  $0xd
  400f8b:	e9 10 ff ff ff       	jmpq   400ea0 <_init+0x20>
  4011d9:	48 8d 74 24 10       	lea    0x10(%rsp),%rsi
  4011de:	48 89 df             	mov    %rbx,%rdi
  400ee0:	ff 25 4a 11 20 00    	jmpq   *0x20114a(%rip)        # 602030 <_GLOBAL_OFFSET_TABLE_+0x30>
  400ee6:	68 03 00 00 00       	pushq  $0x3
  400eeb:	e9 b0 ff ff ff       	jmpq   400ea0 <_init+0x20>
  4011e6:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  4011eb:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  4011ef:	48 81 ff a0 21 60 00 	cmp    $0x6021a0,%rdi
  4011f6:	0f 85 b4 00 00 00    	jne    4012b0 <test1()+0x120>
  4011fc:	c7 43 10 02 00 00 00 	movl   $0x2,0x10(%rbx)
  401203:	48 c7 43 18 f0 20 60 	movq   $0x6020f0,0x18(%rbx)
  40120b:	ba 80 13 40 00       	mov    $0x401380,%edx
  401210:	48 c7 03 70 17 40 00 	movq   $0x401770,(%rbx)
  401217:	be f8 16 40 00       	mov    $0x4016f8,%esi
  40121c:	48 89 df             	mov    %rbx,%rdi
  400fd0:	ff 25 d2 10 20 00    	jmpq   *0x2010d2(%rip)        # 6020a8 <_GLOBAL_OFFSET_TABLE_+0xa8>
  400fd6:	68 12 00 00 00       	pushq  $0x12
  400fdb:	e9 c0 fe ff ff       	jmpq   400ea0 <_init+0x20>
  401224:	0f 1f 40 00          	nopl   0x0(%rax)
  401228:	3c 02                	cmp    $0x2,%al
  40122a:	75 6c                	jne    401298 <test1()+0x108>
  40122c:	bf 20 00 00 00       	mov    $0x20,%edi
  400fb0:	ff 25 e2 10 20 00    	jmpq   *0x2010e2(%rip)        # 602098 <_GLOBAL_OFFSET_TABLE_+0x98>
  400fb6:	68 10 00 00 00       	pushq  $0x10
  400fbb:	e9 e0 fe ff ff       	jmpq   400ea0 <_init+0x20>
  401236:	8b 74 24 20          	mov    0x20(%rsp),%esi
  40123a:	48 8b 54 24 28       	mov    0x28(%rsp),%rdx
  40123f:	48 89 c7             	mov    %rax,%rdi
  401242:	48 89 c3             	mov    %rax,%rbx
  401460:	41 55                	push   %r13
  401462:	41 54                	push   %r12
  401464:	49 89 f5             	mov    %rsi,%r13
  401467:	55                   	push   %rbp
  401468:	53                   	push   %rbx
  401469:	48 89 d5             	mov    %rdx,%rbp
  40146c:	48 89 fb             	mov    %rdi,%rbx
  40146f:	48 83 ec 28          	sub    $0x28,%rsp
  401473:	48 8b 02             	mov    (%rdx),%rax
  401476:	4c 8d 64 24 10       	lea    0x10(%rsp),%r12
  40147b:	48 8b 40 18          	mov    0x18(%rax),%rax
  40147f:	48 3d e0 13 40 00    	cmp    $0x4013e0,%rax
  401485:	0f 85 95 00 00 00    	jne    401520 <std::system_error::system_error(std::error_code)+0xc0>
  40148b:	83 fe 02             	cmp    $0x2,%esi
  40148e:	48 8d 54 24 0f       	lea    0xf(%rsp),%rdx
  401493:	74 7b                	je     401510 <std::system_error::system_error(std::error_code)+0xb0>
  401495:	83 fe 03             	cmp    $0x3,%esi
  401498:	74 4e                	je     4014e8 <std::system_error::system_error(std::error_code)+0x88>
  40149a:	83 fe 01             	cmp    $0x1,%esi
  40149d:	74 61                	je     401500 <std::system_error::system_error(std::error_code)+0xa0>
  40149f:	be 57 16 40 00       	mov    $0x401657,%esi
  4014a4:	4c 89 e7             	mov    %r12,%rdi
  400f80:	ff 25 fa 10 20 00    	jmpq   *0x2010fa(%rip)        # 602080 <_GLOBAL_OFFSET_TABLE_+0x80>
  400f86:	68 0d 00 00 00       	pushq  $0xd
  400f8b:	e9 10 ff ff ff       	jmpq   400ea0 <_init+0x20>
  4014ac:	4c 89 e6             	mov    %r12,%rsi
  4014af:	48 89 df             	mov    %rbx,%rdi
  400ee0:	ff 25 4a 11 20 00    	jmpq   *0x20114a(%rip)        # 602030 <_GLOBAL_OFFSET_TABLE_+0x30>
  400ee6:	68 03 00 00 00       	pushq  $0x3
  400eeb:	e9 b0 ff ff ff       	jmpq   400ea0 <_init+0x20>
  4014b7:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  4014bc:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  4014c0:	48 81 ff a0 21 60 00 	cmp    $0x6021a0,%rdi
  4014c7:	75 67                	jne    401530 <std::system_error::system_error(std::error_code)+0xd0>
  4014c9:	48 c7 03 28 21 60 00 	movq   $0x602128,(%rbx)
  4014d0:	4c 89 6b 10          	mov    %r13,0x10(%rbx)
  4014d4:	48 89 6b 18          	mov    %rbp,0x18(%rbx)
  4014d8:	48 83 c4 28          	add    $0x28,%rsp
  4014dc:	5b                   	pop    %rbx
  4014dd:	5d                   	pop    %rbp
  4014de:	41 5c                	pop    %r12
  4014e0:	41 5d                	pop    %r13
  4014e2:	c3                   	retq
  4014e3:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
  4014e8:	be 45 16 40 00       	mov    $0x401645,%esi
  4014ed:	4c 89 e7             	mov    %r12,%rdi
  4014f0:	e8 8b fa ff ff       	callq  400f80 <std::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string(char const*, std::allocator<char> const&)@plt>
  4014f5:	eb b5                	jmp    4014ac <std::system_error::system_error(std::error_code)+0x4c>
  4014f7:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  401500:	be 30 16 40 00       	mov    $0x401630,%esi
  401505:	4c 89 e7             	mov    %r12,%rdi
  401508:	e8 73 fa ff ff       	callq  400f80 <std::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string(char const*, std::allocator<char> const&)@plt>
  40150d:	eb 9d                	jmp    4014ac <std::system_error::system_error(std::error_code)+0x4c>
  40150f:	90                   	nop
  401510:	be 3c 16 40 00       	mov    $0x40163c,%esi
  401515:	4c 89 e7             	mov    %r12,%rdi
  401518:	e8 63 fa ff ff       	callq  400f80 <std::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string(char const*, std::allocator<char> const&)@plt>
  40151d:	eb 8d                	jmp    4014ac <std::system_error::system_error(std::error_code)+0x4c>
  40151f:	90                   	nop
  401520:	89 f2                	mov    %esi,%edx
  401522:	4c 89 e7             	mov    %r12,%rdi
  401525:	48 89 ee             	mov    %rbp,%rsi
  401528:	ff d0                	callq  *%rax
  40152a:	eb 80                	jmp    4014ac <std::system_error::system_error(std::error_code)+0x4c>
  40152c:	0f 1f 40 00          	nopl   0x0(%rax)
  401530:	ba 00 00 00 00       	mov    $0x0,%edx
  401535:	48 85 d2             	test   %rdx,%rdx
  401538:	74 26                	je     401560 <std::system_error::system_error(std::error_code)+0x100>
  40153a:	ba ff ff ff ff       	mov    $0xffffffff,%edx
  40153f:	f0 0f c1 50 f8       	lock xadd %edx,-0x8(%rax)
  401544:	85 d2                	test   %edx,%edx
  401546:	7f 81                	jg     4014c9 <std::system_error::system_error(std::error_code)+0x69>
  401548:	48 8d 74 24 0f       	lea    0xf(%rsp),%rsi
  400f30:	ff 25 22 11 20 00    	jmpq   *0x201122(%rip)        # 602058 <_GLOBAL_OFFSET_TABLE_+0x58>
  400f36:	68 08 00 00 00       	pushq  $0x8
  400f3b:	e9 60 ff ff ff       	jmpq   400ea0 <_init+0x20>
  401552:	e9 72 ff ff ff       	jmpq   4014c9 <std::system_error::system_error(std::error_code)+0x69>
  401557:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  401560:	8b 50 f8             	mov    -0x8(%rax),%edx
  401563:	8d 4a ff             	lea    -0x1(%rdx),%ecx
  401566:	89 48 f8             	mov    %ecx,-0x8(%rax)
  401569:	eb d9                	jmp    401544 <std::system_error::system_error(std::error_code)+0xe4>
  40156b:	48 89 c3             	mov    %rax,%rbx
  40156e:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  401573:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  401577:	48 81 ff a0 21 60 00 	cmp    $0x6021a0,%rdi
  40157e:	74 0a                	je     40158a <std::system_error::system_error(std::error_code)+0x12a>
  401580:	48 8d 74 24 0f       	lea    0xf(%rsp),%rsi
  401040:	b8 00 00 00 00       	mov    $0x0,%eax
  401045:	48 85 c0             	test   %rax,%rax
  401048:	74 0a                	je     401054 <std::string::_Rep::_M_dispose(std::allocator<char> const&) [clone .part.0]+0x14>
  40104a:	83 c8 ff             	or     $0xffffffff,%eax
  40104d:	f0 0f c1 47 10       	lock xadd %eax,0x10(%rdi)
  401052:	eb 09                	jmp    40105d <std::string::_Rep::_M_dispose(std::allocator<char> const&) [clone .part.0]+0x1d>
  401054:	8b 47 10             	mov    0x10(%rdi),%eax
  401057:	8d 50 ff             	lea    -0x1(%rax),%edx
  40105a:	89 57 10             	mov    %edx,0x10(%rdi)
  40105d:	85 c0                	test   %eax,%eax
  40105f:	7f 05                	jg     401066 <std::string::_Rep::_M_dispose(std::allocator<char> const&) [clone .part.0]+0x26>
  401061:	e9 ca fe ff ff       	jmpq   400f30 <std::string::_Rep::_M_destroy(std::allocator<char> const&)@plt>
  401066:	c3                   	retq
  401067:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  40158a:	48 89 df             	mov    %rbx,%rdi
  401010:	ff 25 b2 10 20 00    	jmpq   *0x2010b2(%rip)        # 6020c8 <_GLOBAL_OFFSET_TABLE_+0xc8>
  401016:	68 16 00 00 00       	pushq  $0x16
  40101b:	e9 80 fe ff ff       	jmpq   400ea0 <_init+0x20>
  401592:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  40159c:	0f 1f 40 00          	nopl   0x0(%rax)
  40124a:	ba 60 0f 40 00       	mov    $0x400f60,%edx
  40124f:	be 00 21 60 00       	mov    $0x602100,%esi
  401254:	48 89 df             	mov    %rbx,%rdi
  400fd0:	ff 25 d2 10 20 00    	jmpq   *0x2010d2(%rip)        # 6020a8 <_GLOBAL_OFFSET_TABLE_+0xa8>
  400fd6:	68 12 00 00 00       	pushq  $0x12
  400fdb:	e9 c0 fe ff ff       	jmpq   400ea0 <_init+0x20>
  40125c:	0f 1f 40 00          	nopl   0x0(%rax)
  401260:	bf d8 21 60 00       	mov    $0x6021d8,%edi
  400ed0:	ff 25 52 11 20 00    	jmpq   *0x201152(%rip)        # 602028 <_GLOBAL_OFFSET_TABLE_+0x28>
  400ed6:	68 02 00 00 00       	pushq  $0x2
  400edb:	e9 c0 ff ff ff       	jmpq   400ea0 <_init+0x20>
  40126a:	85 c0                	test   %eax,%eax
  40126c:	0f 84 53 ff ff ff    	je     4011c5 <test1()+0x35>
  401272:	bf d8 21 60 00       	mov    $0x6021d8,%edi
  400f50:	ff 25 12 11 20 00    	jmpq   *0x201112(%rip)        # 602068 <_GLOBAL_OFFSET_TABLE_+0x68>
  400f56:	68 0a 00 00 00       	pushq  $0xa
  400f5b:	e9 40 ff ff ff       	jmpq   400ea0 <_init+0x20>
  40127c:	ba e8 20 60 00       	mov    $0x6020e8,%edx
  401281:	be f0 20 60 00       	mov    $0x6020f0,%esi
  401286:	bf b0 13 40 00       	mov    $0x4013b0,%edi
  400f20:	ff 25 2a 11 20 00    	jmpq   *0x20112a(%rip)        # 602050 <_GLOBAL_OFFSET_TABLE_+0x50>
  400f26:	68 07 00 00 00       	pushq  $0x7
  400f2b:	e9 70 ff ff ff       	jmpq   400ea0 <_init+0x20>
  401290:	e9 30 ff ff ff       	jmpq   4011c5 <test1()+0x35>
  401295:	0f 1f 00             	nopl   (%rax)
  401298:	3c 03                	cmp    $0x3,%al
  40129a:	74 3f                	je     4012db <test1()+0x14b>
  40129c:	8b 44 24 20          	mov    0x20(%rsp),%eax
  4012a0:	48 83 c4 48          	add    $0x48,%rsp
  4012a4:	5b                   	pop    %rbx
  4012a5:	5d                   	pop    %rbp
  4012a6:	c3                   	retq
  4012a7:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  4012b0:	ba 00 00 00 00       	mov    $0x0,%edx
  4012b5:	48 85 d2             	test   %rdx,%rdx
  4012b8:	74 66                	je     401320 <test1()+0x190>
  4012ba:	ba ff ff ff ff       	mov    $0xffffffff,%edx
  4012bf:	f0 0f c1 50 f8       	lock xadd %edx,-0x8(%rax)
  4012c4:	85 d2                	test   %edx,%edx
  4012c6:	0f 8f 30 ff ff ff    	jg     4011fc <test1()+0x6c>
  4012cc:	48 8d 74 24 0f       	lea    0xf(%rsp),%rsi
  400f30:	ff 25 22 11 20 00    	jmpq   *0x201122(%rip)        # 602058 <_GLOBAL_OFFSET_TABLE_+0x58>
  400f36:	68 08 00 00 00       	pushq  $0x8
  400f3b:	e9 60 ff ff ff       	jmpq   400ea0 <_init+0x20>
  4012d6:	e9 21 ff ff ff       	jmpq   4011fc <test1()+0x6c>
  4012db:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
  4012e0:	48 8d 74 24 20       	lea    0x20(%rsp),%rsi
  400fe0:	ff 25 ca 10 20 00    	jmpq   *0x2010ca(%rip)        # 6020b0 <_GLOBAL_OFFSET_TABLE_+0xb0>
  400fe6:	68 13 00 00 00       	pushq  $0x13
  400feb:	e9 b0 fe ff ff       	jmpq   400ea0 <_init+0x20>
  4012ea:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
  401020:	ff 25 aa 10 20 00    	jmpq   *0x2010aa(%rip)        # 6020d0 <_GLOBAL_OFFSET_TABLE_+0xd0>
  401026:	68 17 00 00 00       	pushq  $0x17
  40102b:	e9 70 fe ff ff       	jmpq   400ea0 <_init+0x20>
  4012f4:	48 89 c3             	mov    %rax,%rbx
  4012f7:	80 7c 24 38 03       	cmpb   $0x3,0x38(%rsp)
  4012fc:	75 0a                	jne    401308 <test1()+0x178>
  4012fe:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
  400fa0:	ff 25 ea 10 20 00    	jmpq   *0x2010ea(%rip)        # 602090 <_GLOBAL_OFFSET_TABLE_+0x90>
  400fa6:	68 0f 00 00 00       	pushq  $0xf
  400fab:	e9 f0 fe ff ff       	jmpq   400ea0 <_init+0x20>
  401308:	48 89 df             	mov    %rbx,%rdi
  401010:	ff 25 b2 10 20 00    	jmpq   *0x2010b2(%rip)        # 6020c8 <_GLOBAL_OFFSET_TABLE_+0xc8>
  401016:	68 16 00 00 00       	pushq  $0x16
  40101b:	e9 80 fe ff ff       	jmpq   400ea0 <_init+0x20>
  401310:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
  401315:	48 89 c3             	mov    %rax,%rbx
  400fa0:	ff 25 ea 10 20 00    	jmpq   *0x2010ea(%rip)        # 602090 <_GLOBAL_OFFSET_TABLE_+0x90>
  400fa6:	68 0f 00 00 00       	pushq  $0xf
  400fab:	e9 f0 fe ff ff       	jmpq   400ea0 <_init+0x20>
  40131d:	eb d8                	jmp    4012f7 <test1()+0x167>
  40131f:	90                   	nop
  401320:	8b 50 f8             	mov    -0x8(%rax),%edx
  401323:	8d 4a ff             	lea    -0x1(%rdx),%ecx
  401326:	89 48 f8             	mov    %ecx,-0x8(%rax)
  401329:	eb 99                	jmp    4012c4 <test1()+0x134>
  40132b:	48 89 c5             	mov    %rax,%rbp
  40132e:	48 89 df             	mov    %rbx,%rdi
  401331:	48 89 eb             	mov    %rbp,%rbx
  400fc0:	ff 25 da 10 20 00    	jmpq   *0x2010da(%rip)        # 6020a0 <_GLOBAL_OFFSET_TABLE_+0xa0>
  400fc6:	68 11 00 00 00       	pushq  $0x11
  400fcb:	e9 d0 fe ff ff       	jmpq   400ea0 <_init+0x20>
  401339:	eb bc                	jmp    4012f7 <test1()+0x167>
  40133b:	eb ee                	jmp    40132b <test1()+0x19b>
  40133d:	48 89 c5             	mov    %rax,%rbp
  401340:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  401345:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  401349:	48 81 ff a0 21 60 00 	cmp    $0x6021a0,%rdi
  401350:	74 dc                	je     40132e <test1()+0x19e>
  401352:	48 8d 74 24 0f       	lea    0xf(%rsp),%rsi
  401040:	b8 00 00 00 00       	mov    $0x0,%eax
  401045:	48 85 c0             	test   %rax,%rax
  401048:	74 0a                	je     401054 <std::string::_Rep::_M_dispose(std::allocator<char> const&) [clone .part.0]+0x14>
  40104a:	83 c8 ff             	or     $0xffffffff,%eax
  40104d:	f0 0f c1 47 10       	lock xadd %eax,0x10(%rdi)
  401052:	eb 09                	jmp    40105d <std::string::_Rep::_M_dispose(std::allocator<char> const&) [clone .part.0]+0x1d>
  401054:	8b 47 10             	mov    0x10(%rdi),%eax
  401057:	8d 50 ff             	lea    -0x1(%rax),%edx
  40105a:	89 57 10             	mov    %edx,0x10(%rdi)
  40105d:	85 c0                	test   %eax,%eax
  40105f:	7f 05                	jg     401066 <std::string::_Rep::_M_dispose(std::allocator<char> const&) [clone .part.0]+0x26>
  401061:	e9 ca fe ff ff       	jmpq   400f30 <std::string::_Rep::_M_destroy(std::allocator<char> const&)@plt>
  401066:	c3                   	retq
  401067:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  40135c:	eb d0                	jmp    40132e <test1()+0x19e>
  40135e:	66 90                	xchg   %ax,%ax
