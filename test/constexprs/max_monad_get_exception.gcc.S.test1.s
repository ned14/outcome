  401470:	41 55                	push   %r13
  401472:	41 54                	push   %r12
  401474:	55                   	push   %rbp
  401475:	53                   	push   %rbx
  401476:	48 89 fb             	mov    %rdi,%rbx
  401479:	48 83 ec 78          	sub    $0x78,%rsp
  40147d:	48 8d 7c 24 30       	lea    0x30(%rsp),%rdi
  401482:	e8 79 eb bf ff       	callq  0 <_init-0x4010b0>
  401487:	0f b6 44 24 48       	movzbl 0x48(%rsp),%eax
  40148c:	84 c0                	test   %al,%al
  40148e:	0f 85 7c 00 00 00    	jne    401510 <test1()+0xa0>
  401494:	bf 20 00 00 00       	mov    $0x20,%edi
  401210:	ff 25 9a 1e 20 00    	jmpq   *0x201e9a(%rip)        # 6030b0 <_GLOBAL_OFFSET_TABLE_+0xb0>
  401216:	68 13 00 00 00       	pushq  $0x13
  40121b:	e9 b0 fe ff ff       	jmpq   4010d0 <_init+0x20>
  40149e:	48 89 c3             	mov    %rax,%rbx
  4014a1:	0f b6 05 b0 1d 20 00 	movzbl 0x201db0(%rip),%eax        # 603258 <guard variable for boost::outcome::_1_0_std_std_9274c0d4::monad_category()::c>
  4014a8:	84 c0                	test   %al,%al
  4014aa:	0f 84 48 01 00 00    	je     4015f8 <test1()+0x188>
  4014b0:	48 8d 54 24 0b       	lea    0xb(%rsp),%rdx
  4014b5:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
  4014ba:	be dc 19 40 00       	mov    $0x4019dc,%esi
  4011d0:	ff 25 ba 1e 20 00    	jmpq   *0x201eba(%rip)        # 603090 <_GLOBAL_OFFSET_TABLE_+0x90>
  4011d6:	68 0f 00 00 00       	pushq  $0xf
  4011db:	e9 f0 fe ff ff       	jmpq   4010d0 <_init+0x20>
  4014c4:	48 8d 74 24 10       	lea    0x10(%rsp),%rsi
  4014c9:	48 89 df             	mov    %rbx,%rdi
  401110:	ff 25 1a 1f 20 00    	jmpq   *0x201f1a(%rip)        # 603030 <_GLOBAL_OFFSET_TABLE_+0x30>
  401116:	68 03 00 00 00       	pushq  $0x3
  40111b:	e9 b0 ff ff ff       	jmpq   4010d0 <_init+0x20>
  4014d1:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  4014d6:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  4014da:	48 81 ff 20 32 60 00 	cmp    $0x603220,%rdi
  4014e1:	0f 85 71 01 00 00    	jne    401658 <test1()+0x1e8>
  4014e7:	c7 43 10 02 00 00 00 	movl   $0x2,0x10(%rbx)
  4014ee:	48 c7 43 18 20 31 60 	movq   $0x603120,0x18(%rbx)
  4014f6:	ba 50 18 40 00       	mov    $0x401850,%edx
  4014fb:	48 c7 03 10 1b 40 00 	movq   $0x401b10,(%rbx)
  401502:	be 98 1a 40 00       	mov    $0x401a98,%esi
  401507:	48 89 df             	mov    %rbx,%rdi
  401240:	ff 25 82 1e 20 00    	jmpq   *0x201e82(%rip)        # 6030c8 <_GLOBAL_OFFSET_TABLE_+0xc8>
  401246:	68 16 00 00 00       	pushq  $0x16
  40124b:	e9 80 fe ff ff       	jmpq   4010d0 <_init+0x20>
  40150f:	90                   	nop
  401510:	3c 02                	cmp    $0x2,%al
  401512:	0f 85 18 01 00 00    	jne    401630 <test1()+0x1c0>
  401518:	48 8b 6c 24 38       	mov    0x38(%rsp),%rbp
  40151d:	44 8b 64 24 30       	mov    0x30(%rsp),%r12d
  401522:	48 8b 45 00          	mov    0x0(%rbp),%rax
  401526:	48 8b 40 18          	mov    0x18(%rax),%rax
  40152a:	48 3d b0 18 40 00    	cmp    $0x4018b0,%rax
  401530:	0f 85 2a 02 00 00    	jne    401760 <test1()+0x2f0>
  401536:	41 83 fc 02          	cmp    $0x2,%r12d
  40153a:	4c 8d 6c 24 20       	lea    0x20(%rsp),%r13
  40153f:	0f 84 ab 01 00 00    	je     4016f0 <test1()+0x280>
  401545:	41 83 fc 03          	cmp    $0x3,%r12d
  401549:	0f 84 f1 01 00 00    	je     401740 <test1()+0x2d0>
  40154f:	41 83 fc 01          	cmp    $0x1,%r12d
  401553:	0f 84 b7 01 00 00    	je     401710 <test1()+0x2a0>
  401559:	48 8d 54 24 0f       	lea    0xf(%rsp),%rdx
  40155e:	be f7 19 40 00       	mov    $0x4019f7,%esi
  401563:	4c 89 ef             	mov    %r13,%rdi
  4011d0:	ff 25 ba 1e 20 00    	jmpq   *0x201eba(%rip)        # 603090 <_GLOBAL_OFFSET_TABLE_+0x90>
  4011d6:	68 0f 00 00 00       	pushq  $0xf
  4011db:	e9 f0 fe ff ff       	jmpq   4010d0 <_init+0x20>
  40156b:	48 8d 7c 24 50       	lea    0x50(%rsp),%rdi
  401570:	4c 89 ee             	mov    %r13,%rsi
  401110:	ff 25 1a 1f 20 00    	jmpq   *0x201f1a(%rip)        # 603030 <_GLOBAL_OFFSET_TABLE_+0x30>
  401116:	68 03 00 00 00       	pushq  $0x3
  40111b:	e9 b0 ff ff ff       	jmpq   4010d0 <_init+0x20>
  401578:	48 8b 44 24 20       	mov    0x20(%rsp),%rax
  40157d:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  401581:	48 81 ff 20 32 60 00 	cmp    $0x603220,%rdi
  401588:	0f 85 ea 01 00 00    	jne    401778 <test1()+0x308>
  40158e:	bf 20 00 00 00       	mov    $0x20,%edi
  401593:	48 89 6c 24 68       	mov    %rbp,0x68(%rsp)
  401598:	48 c7 44 24 50 68 31 	movq   $0x603168,0x50(%rsp)
  4015a1:	44 89 64 24 60       	mov    %r12d,0x60(%rsp)
  401210:	ff 25 9a 1e 20 00    	jmpq   *0x201e9a(%rip)        # 6030b0 <_GLOBAL_OFFSET_TABLE_+0xb0>
  401216:	68 13 00 00 00       	pushq  $0x13
  40121b:	e9 b0 fe ff ff       	jmpq   4010d0 <_init+0x20>
  4015ab:	48 89 c5             	mov    %rax,%rbp
  4015ae:	48 c7 00 a0 31 60 00 	movq   $0x6031a0,(%rax)
  4015b5:	48 8d 44 24 50       	lea    0x50(%rsp),%rax
  4015ba:	48 8d 7d 08          	lea    0x8(%rbp),%rdi
  4015be:	48 8d 70 08          	lea    0x8(%rax),%rsi
  401150:	ff 25 fa 1e 20 00    	jmpq   *0x201efa(%rip)        # 603050 <_GLOBAL_OFFSET_TABLE_+0x50>
  401156:	68 07 00 00 00       	pushq  $0x7
  40115b:	e9 70 ff ff ff       	jmpq   4010d0 <_init+0x20>
  4015c7:	48 8b 54 24 68       	mov    0x68(%rsp),%rdx
  4015cc:	48 8b 44 24 60       	mov    0x60(%rsp),%rax
  4015d1:	be 40 31 60 00       	mov    $0x603140,%esi
  4015d6:	48 c7 45 00 68 31 60 	movq   $0x603168,0x0(%rbp)
  4015de:	48 89 ef             	mov    %rbp,%rdi
  4015e1:	48 89 55 18          	mov    %rdx,0x18(%rbp)
  4015e5:	48 89 45 10          	mov    %rax,0x10(%rbp)
  4015e9:	ba b0 11 40 00       	mov    $0x4011b0,%edx
  401240:	ff 25 82 1e 20 00    	jmpq   *0x201e82(%rip)        # 6030c8 <_GLOBAL_OFFSET_TABLE_+0xc8>
  401246:	68 16 00 00 00       	pushq  $0x16
  40124b:	e9 80 fe ff ff       	jmpq   4010d0 <_init+0x20>
  4015f3:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
  4015f8:	bf 58 32 60 00       	mov    $0x603258,%edi
  401100:	ff 25 22 1f 20 00    	jmpq   *0x201f22(%rip)        # 603028 <_GLOBAL_OFFSET_TABLE_+0x28>
  401106:	68 02 00 00 00       	pushq  $0x2
  40110b:	e9 c0 ff ff ff       	jmpq   4010d0 <_init+0x20>
  401602:	85 c0                	test   %eax,%eax
  401604:	0f 84 a6 fe ff ff    	je     4014b0 <test1()+0x40>
  40160a:	bf 58 32 60 00       	mov    $0x603258,%edi
  401190:	ff 25 da 1e 20 00    	jmpq   *0x201eda(%rip)        # 603070 <_GLOBAL_OFFSET_TABLE_+0x70>
  401196:	68 0b 00 00 00       	pushq  $0xb
  40119b:	e9 30 ff ff ff       	jmpq   4010d0 <_init+0x20>
  401614:	ba 18 31 60 00       	mov    $0x603118,%edx
  401619:	be 20 31 60 00       	mov    $0x603120,%esi
  40161e:	bf 80 18 40 00       	mov    $0x401880,%edi
  401160:	ff 25 f2 1e 20 00    	jmpq   *0x201ef2(%rip)        # 603058 <_GLOBAL_OFFSET_TABLE_+0x58>
  401166:	68 08 00 00 00       	pushq  $0x8
  40116b:	e9 60 ff ff ff       	jmpq   4010d0 <_init+0x20>
  401628:	e9 83 fe ff ff       	jmpq   4014b0 <test1()+0x40>
  40162d:	0f 1f 00             	nopl   (%rax)
  401630:	3c 03                	cmp    $0x3,%al
  401632:	74 68                	je     40169c <test1()+0x22c>
  401634:	48 89 df             	mov    %rbx,%rdi
  4011a0:	ff 25 d2 1e 20 00    	jmpq   *0x201ed2(%rip)        # 603078 <_GLOBAL_OFFSET_TABLE_+0x78>
  4011a6:	68 0c 00 00 00       	pushq  $0xc
  4011ab:	e9 20 ff ff ff       	jmpq   4010d0 <_init+0x20>
  40163c:	80 7c 24 48 03       	cmpb   $0x3,0x48(%rsp)
  401641:	74 4d                	je     401690 <test1()+0x220>
  401643:	48 83 c4 78          	add    $0x78,%rsp
  401647:	48 89 d8             	mov    %rbx,%rax
  40164a:	5b                   	pop    %rbx
  40164b:	5d                   	pop    %rbp
  40164c:	41 5c                	pop    %r12
  40164e:	41 5d                	pop    %r13
  401650:	c3                   	retq
  401651:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
  401658:	ba 00 00 00 00       	mov    $0x0,%edx
  40165d:	48 85 d2             	test   %rdx,%rdx
  401660:	0f 84 ca 00 00 00    	je     401730 <test1()+0x2c0>
  401666:	ba ff ff ff ff       	mov    $0xffffffff,%edx
  40166b:	f0 0f c1 50 f8       	lock xadd %edx,-0x8(%rax)
  401670:	85 d2                	test   %edx,%edx
  401672:	0f 8f 6f fe ff ff    	jg     4014e7 <test1()+0x77>
  401678:	48 8d 74 24 50       	lea    0x50(%rsp),%rsi
  401170:	ff 25 ea 1e 20 00    	jmpq   *0x201eea(%rip)        # 603060 <_GLOBAL_OFFSET_TABLE_+0x60>
  401176:	68 09 00 00 00       	pushq  $0x9
  40117b:	e9 50 ff ff ff       	jmpq   4010d0 <_init+0x20>
  401682:	e9 60 fe ff ff       	jmpq   4014e7 <test1()+0x77>
  401687:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  401690:	48 8d 7c 24 30       	lea    0x30(%rsp),%rdi
  401200:	ff 25 a2 1e 20 00    	jmpq   *0x201ea2(%rip)        # 6030a8 <_GLOBAL_OFFSET_TABLE_+0xa8>
  401206:	68 12 00 00 00       	pushq  $0x12
  40120b:	e9 c0 fe ff ff       	jmpq   4010d0 <_init+0x20>
  40169a:	eb a7                	jmp    401643 <test1()+0x1d3>
  40169c:	48 8d 74 24 30       	lea    0x30(%rsp),%rsi
  4016a1:	48 89 df             	mov    %rbx,%rdi
  401250:	ff 25 7a 1e 20 00    	jmpq   *0x201e7a(%rip)        # 6030d0 <_GLOBAL_OFFSET_TABLE_+0xd0>
  401256:	68 17 00 00 00       	pushq  $0x17
  40125b:	e9 70 fe ff ff       	jmpq   4010d0 <_init+0x20>
  4016a9:	eb 91                	jmp    40163c <test1()+0x1cc>
  4016ab:	48 89 c3             	mov    %rax,%rbx
  4016ae:	80 7c 24 48 03       	cmpb   $0x3,0x48(%rsp)
  4016b3:	75 0a                	jne    4016bf <test1()+0x24f>
  4016b5:	48 8d 7c 24 30       	lea    0x30(%rsp),%rdi
  401200:	ff 25 a2 1e 20 00    	jmpq   *0x201ea2(%rip)        # 6030a8 <_GLOBAL_OFFSET_TABLE_+0xa8>
  401206:	68 12 00 00 00       	pushq  $0x12
  40120b:	e9 c0 fe ff ff       	jmpq   4010d0 <_init+0x20>
  4016bf:	48 89 df             	mov    %rbx,%rdi
  4012b0:	ff 25 4a 1e 20 00    	jmpq   *0x201e4a(%rip)        # 603100 <_GLOBAL_OFFSET_TABLE_+0x100>
  4012b6:	68 1d 00 00 00       	pushq  $0x1d
  4012bb:	e9 10 fe ff ff       	jmpq   4010d0 <_init+0x20>
  4016c7:	48 89 c7             	mov    %rax,%rdi
  401290:	ff 25 5a 1e 20 00    	jmpq   *0x201e5a(%rip)        # 6030f0 <_GLOBAL_OFFSET_TABLE_+0xf0>
  401296:	68 1b 00 00 00       	pushq  $0x1b
  40129b:	e9 30 fe ff ff       	jmpq   4010d0 <_init+0x20>
  4016cf:	48 89 df             	mov    %rbx,%rdi
  4011e0:	ff 25 b2 1e 20 00    	jmpq   *0x201eb2(%rip)        # 603098 <_GLOBAL_OFFSET_TABLE_+0x98>
  4011e6:	68 10 00 00 00       	pushq  $0x10
  4011eb:	e9 e0 fe ff ff       	jmpq   4010d0 <_init+0x20>
  401270:	ff 25 6a 1e 20 00    	jmpq   *0x201e6a(%rip)        # 6030e0 <_GLOBAL_OFFSET_TABLE_+0xe0>
  401276:	68 19 00 00 00       	pushq  $0x19
  40127b:	e9 50 fe ff ff       	jmpq   4010d0 <_init+0x20>
  4016dc:	48 8d 7c 24 50       	lea    0x50(%rsp),%rdi
  4011b0:	ff 25 ca 1e 20 00    	jmpq   *0x201eca(%rip)        # 603080 <_GLOBAL_OFFSET_TABLE_+0x80>
  4011b6:	68 0d 00 00 00       	pushq  $0xd
  4011bb:	e9 10 ff ff ff       	jmpq   4010d0 <_init+0x20>
  4016e6:	e9 51 ff ff ff       	jmpq   40163c <test1()+0x1cc>
  4016eb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
  4016f0:	48 8d 54 24 0d       	lea    0xd(%rsp),%rdx
  4016f5:	be dc 19 40 00       	mov    $0x4019dc,%esi
  4016fa:	4c 89 ef             	mov    %r13,%rdi
  4011d0:	ff 25 ba 1e 20 00    	jmpq   *0x201eba(%rip)        # 603090 <_GLOBAL_OFFSET_TABLE_+0x90>
  4011d6:	68 0f 00 00 00       	pushq  $0xf
  4011db:	e9 f0 fe ff ff       	jmpq   4010d0 <_init+0x20>
  401702:	e9 64 fe ff ff       	jmpq   40156b <test1()+0xfb>
  401707:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  401710:	48 8d 54 24 0c       	lea    0xc(%rsp),%rdx
  401715:	be d0 19 40 00       	mov    $0x4019d0,%esi
  40171a:	4c 89 ef             	mov    %r13,%rdi
  4011d0:	ff 25 ba 1e 20 00    	jmpq   *0x201eba(%rip)        # 603090 <_GLOBAL_OFFSET_TABLE_+0x90>
  4011d6:	68 0f 00 00 00       	pushq  $0xf
  4011db:	e9 f0 fe ff ff       	jmpq   4010d0 <_init+0x20>
  401722:	e9 44 fe ff ff       	jmpq   40156b <test1()+0xfb>
  401727:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  401730:	8b 50 f8             	mov    -0x8(%rax),%edx
  401733:	8d 4a ff             	lea    -0x1(%rdx),%ecx
  401736:	89 48 f8             	mov    %ecx,-0x8(%rax)
  401739:	e9 32 ff ff ff       	jmpq   401670 <test1()+0x200>
  40173e:	66 90                	xchg   %ax,%ax
  401740:	48 8d 54 24 0e       	lea    0xe(%rsp),%rdx
  401745:	be e5 19 40 00       	mov    $0x4019e5,%esi
  40174a:	4c 89 ef             	mov    %r13,%rdi
  4011d0:	ff 25 ba 1e 20 00    	jmpq   *0x201eba(%rip)        # 603090 <_GLOBAL_OFFSET_TABLE_+0x90>
  4011d6:	68 0f 00 00 00       	pushq  $0xf
  4011db:	e9 f0 fe ff ff       	jmpq   4010d0 <_init+0x20>
  401752:	e9 14 fe ff ff       	jmpq   40156b <test1()+0xfb>
  401757:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  401760:	4c 8d 6c 24 20       	lea    0x20(%rsp),%r13
  401765:	44 89 e2             	mov    %r12d,%edx
  401768:	48 89 ee             	mov    %rbp,%rsi
  40176b:	4c 89 ef             	mov    %r13,%rdi
  40176e:	ff d0                	callq  *%rax
  401770:	e9 f6 fd ff ff       	jmpq   40156b <test1()+0xfb>
  401775:	0f 1f 00             	nopl   (%rax)
  401778:	ba 00 00 00 00       	mov    $0x0,%edx
  40177d:	48 85 d2             	test   %rdx,%rdx
  401780:	74 21                	je     4017a3 <test1()+0x333>
  401782:	ba ff ff ff ff       	mov    $0xffffffff,%edx
  401787:	f0 0f c1 50 f8       	lock xadd %edx,-0x8(%rax)
  40178c:	85 d2                	test   %edx,%edx
  40178e:	0f 8f fa fd ff ff    	jg     40158e <test1()+0x11e>
  401794:	48 8d 74 24 10       	lea    0x10(%rsp),%rsi
  401170:	ff 25 ea 1e 20 00    	jmpq   *0x201eea(%rip)        # 603060 <_GLOBAL_OFFSET_TABLE_+0x60>
  401176:	68 09 00 00 00       	pushq  $0x9
  40117b:	e9 50 ff ff ff       	jmpq   4010d0 <_init+0x20>
  40179e:	e9 eb fd ff ff       	jmpq   40158e <test1()+0x11e>
  4017a3:	8b 50 f8             	mov    -0x8(%rax),%edx
  4017a6:	8d 4a ff             	lea    -0x1(%rdx),%ecx
  4017a9:	89 48 f8             	mov    %ecx,-0x8(%rax)
  4017ac:	eb de                	jmp    40178c <test1()+0x31c>
  4017ae:	48 89 c5             	mov    %rax,%rbp
  4017b1:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  4017b6:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  4017ba:	48 81 ff 20 32 60 00 	cmp    $0x603220,%rdi
  4017c1:	74 0a                	je     4017cd <test1()+0x35d>
  4017c3:	48 8d 74 24 50       	lea    0x50(%rsp),%rsi
  4012d0:	b8 00 00 00 00       	mov    $0x0,%eax
  4012d5:	48 85 c0             	test   %rax,%rax
  4012d8:	74 0a                	je     4012e4 <std::string::_Rep::_M_dispose(std::allocator<char> const&) [clone .part.0]+0x14>
  4012da:	83 c8 ff             	or     $0xffffffff,%eax
  4012dd:	f0 0f c1 47 10       	lock xadd %eax,0x10(%rdi)
  4012e2:	eb 09                	jmp    4012ed <std::string::_Rep::_M_dispose(std::allocator<char> const&) [clone .part.0]+0x1d>
  4012e4:	8b 47 10             	mov    0x10(%rdi),%eax
  4012e7:	8d 50 ff             	lea    -0x1(%rax),%edx
  4012ea:	89 57 10             	mov    %edx,0x10(%rdi)
  4012ed:	85 c0                	test   %eax,%eax
  4012ef:	7f 05                	jg     4012f6 <std::string::_Rep::_M_dispose(std::allocator<char> const&) [clone .part.0]+0x26>
  4012f1:	e9 7a fe ff ff       	jmpq   401170 <std::string::_Rep::_M_destroy(std::allocator<char> const&)@plt>
  4012f6:	c3                   	retq
  4012f7:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  4017cd:	48 89 df             	mov    %rbx,%rdi
  4017d0:	48 89 eb             	mov    %rbp,%rbx
  401230:	ff 25 8a 1e 20 00    	jmpq   *0x201e8a(%rip)        # 6030c0 <_GLOBAL_OFFSET_TABLE_+0xc0>
  401236:	68 15 00 00 00       	pushq  $0x15
  40123b:	e9 90 fe ff ff       	jmpq   4010d0 <_init+0x20>
  4017d8:	e9 d1 fe ff ff       	jmpq   4016ae <test1()+0x23e>
  4017dd:	48 89 c3             	mov    %rax,%rbx
  4017e0:	48 8b 44 24 20       	mov    0x20(%rsp),%rax
  4017e5:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  4017e9:	48 81 ff 20 32 60 00 	cmp    $0x603220,%rdi
  4017f0:	0f 84 b8 fe ff ff    	je     4016ae <test1()+0x23e>
  4017f6:	48 8d 74 24 10       	lea    0x10(%rsp),%rsi
  4012d0:	b8 00 00 00 00       	mov    $0x0,%eax
  4012d5:	48 85 c0             	test   %rax,%rax
  4012d8:	74 0a                	je     4012e4 <std::string::_Rep::_M_dispose(std::allocator<char> const&) [clone .part.0]+0x14>
  4012da:	83 c8 ff             	or     $0xffffffff,%eax
  4012dd:	f0 0f c1 47 10       	lock xadd %eax,0x10(%rdi)
  4012e2:	eb 09                	jmp    4012ed <std::string::_Rep::_M_dispose(std::allocator<char> const&) [clone .part.0]+0x1d>
  4012e4:	8b 47 10             	mov    0x10(%rdi),%eax
  4012e7:	8d 50 ff             	lea    -0x1(%rax),%edx
  4012ea:	89 57 10             	mov    %edx,0x10(%rdi)
  4012ed:	85 c0                	test   %eax,%eax
  4012ef:	7f 05                	jg     4012f6 <std::string::_Rep::_M_dispose(std::allocator<char> const&) [clone .part.0]+0x26>
  4012f1:	e9 7a fe ff ff       	jmpq   401170 <std::string::_Rep::_M_destroy(std::allocator<char> const&)@plt>
  4012f6:	c3                   	retq
  4012f7:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  401800:	e9 a9 fe ff ff       	jmpq   4016ae <test1()+0x23e>
  401805:	48 89 ef             	mov    %rbp,%rdi
  401808:	49 89 c4             	mov    %rax,%r12
  401220:	ff 25 92 1e 20 00    	jmpq   *0x201e92(%rip)        # 6030b8 <_GLOBAL_OFFSET_TABLE_+0xb8>
  401226:	68 14 00 00 00       	pushq  $0x14
  40122b:	e9 a0 fe ff ff       	jmpq   4010d0 <_init+0x20>
  401810:	48 89 ef             	mov    %rbp,%rdi
  401230:	ff 25 8a 1e 20 00    	jmpq   *0x201e8a(%rip)        # 6030c0 <_GLOBAL_OFFSET_TABLE_+0xc0>
  401236:	68 15 00 00 00       	pushq  $0x15
  40123b:	e9 90 fe ff ff       	jmpq   4010d0 <_init+0x20>
  401818:	4c 89 e0             	mov    %r12,%rax
  40181b:	e9 a7 fe ff ff       	jmpq   4016c7 <test1()+0x257>
  401820:	48 89 c5             	mov    %rax,%rbp
  401823:	eb a8                	jmp    4017cd <test1()+0x35d>
  401825:	66 66 2e 0f 1f 84 00 	data32 nopw %cs:0x0(%rax,%rax,1)
