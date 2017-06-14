  401010:	55                   	push   %rbp
  401011:	53                   	push   %rbx
  401012:	48 89 fb             	mov    %rdi,%rbx
  401015:	48 83 ec 68          	sub    $0x68,%rsp
  401019:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
  40101e:	e8 dd ef bf ff       	callq  0 <_init-0x400d38>
  401023:	48 8b 44 24 20       	mov    0x20(%rsp),%rax
  401028:	48 89 44 24 40       	mov    %rax,0x40(%rsp)
  40102d:	48 8b 44 24 28       	mov    0x28(%rsp),%rax
  401032:	48 89 44 24 48       	mov    %rax,0x48(%rsp)
  401037:	48 8b 44 24 30       	mov    0x30(%rsp),%rax
  40103c:	48 89 44 24 50       	mov    %rax,0x50(%rsp)
  401041:	48 8b 44 24 38       	mov    0x38(%rsp),%rax
  401046:	48 89 44 24 58       	mov    %rax,0x58(%rsp)
  40104b:	0f b6 44 24 38       	movzbl 0x38(%rsp),%eax
  401050:	84 c0                	test   %al,%al
  401052:	74 54                	je     4010a8 <test1()+0x98>
  401054:	3c 02                	cmp    $0x2,%al
  401056:	8b 6c 24 20          	mov    0x20(%rsp),%ebp
  40105a:	75 34                	jne    401090 <test1()+0x80>
  40105c:	bf 20 00 00 00       	mov    $0x20,%edi
  400e60:	ff 25 2a 12 20 00    	jmpq   *0x20122a(%rip)        # 602090 <_GLOBAL_OFFSET_TABLE_+0x90>
  400e66:	68 0f 00 00 00       	pushq  $0xf
  400e6b:	e9 f0 fe ff ff       	jmpq   400d60 <_init+0x28>
  401066:	48 8b 54 24 48       	mov    0x48(%rsp),%rdx
  40106b:	89 ee                	mov    %ebp,%esi
  40106d:	48 89 c7             	mov    %rax,%rdi
  401070:	48 89 c3             	mov    %rax,%rbx
  4012c0:	41 55                	push   %r13
  4012c2:	41 54                	push   %r12
  4012c4:	49 89 f5             	mov    %rsi,%r13
  4012c7:	55                   	push   %rbp
  4012c8:	53                   	push   %rbx
  4012c9:	48 89 d5             	mov    %rdx,%rbp
  4012cc:	48 89 fb             	mov    %rdi,%rbx
  4012cf:	48 83 ec 28          	sub    $0x28,%rsp
  4012d3:	48 8b 02             	mov    (%rdx),%rax
  4012d6:	4c 8d 64 24 10       	lea    0x10(%rsp),%r12
  4012db:	48 8b 40 18          	mov    0x18(%rax),%rax
  4012df:	48 3d 40 12 40 00    	cmp    $0x401240,%rax
  4012e5:	0f 85 95 00 00 00    	jne    401380 <std::system_error::system_error(std::error_code)+0xc0>
  4012eb:	83 fe 02             	cmp    $0x2,%esi
  4012ee:	48 8d 54 24 0f       	lea    0xf(%rsp),%rdx
  4012f3:	74 7b                	je     401370 <std::system_error::system_error(std::error_code)+0xb0>
  4012f5:	83 fe 03             	cmp    $0x3,%esi
  4012f8:	74 4e                	je     401348 <std::system_error::system_error(std::error_code)+0x88>
  4012fa:	83 fe 01             	cmp    $0x1,%esi
  4012fd:	74 61                	je     401360 <std::system_error::system_error(std::error_code)+0xa0>
  4012ff:	be b7 14 40 00       	mov    $0x4014b7,%esi
  401304:	4c 89 e7             	mov    %r12,%rdi
  400e40:	ff 25 3a 12 20 00    	jmpq   *0x20123a(%rip)        # 602080 <_GLOBAL_OFFSET_TABLE_+0x80>
  400e46:	68 0d 00 00 00       	pushq  $0xd
  400e4b:	e9 10 ff ff ff       	jmpq   400d60 <_init+0x28>
  40130c:	4c 89 e6             	mov    %r12,%rsi
  40130f:	48 89 df             	mov    %rbx,%rdi
  400da0:	ff 25 8a 12 20 00    	jmpq   *0x20128a(%rip)        # 602030 <_GLOBAL_OFFSET_TABLE_+0x30>
  400da6:	68 03 00 00 00       	pushq  $0x3
  400dab:	e9 b0 ff ff ff       	jmpq   400d60 <_init+0x28>
  401317:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  40131c:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  401320:	48 81 ff 80 21 60 00 	cmp    $0x602180,%rdi
  401327:	75 67                	jne    401390 <std::system_error::system_error(std::error_code)+0xd0>
  401329:	48 c7 03 08 21 60 00 	movq   $0x602108,(%rbx)
  401330:	4c 89 6b 10          	mov    %r13,0x10(%rbx)
  401334:	48 89 6b 18          	mov    %rbp,0x18(%rbx)
  401338:	48 83 c4 28          	add    $0x28,%rsp
  40133c:	5b                   	pop    %rbx
  40133d:	5d                   	pop    %rbp
  40133e:	41 5c                	pop    %r12
  401340:	41 5d                	pop    %r13
  401342:	c3                   	retq
  401343:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
  401348:	be a5 14 40 00       	mov    $0x4014a5,%esi
  40134d:	4c 89 e7             	mov    %r12,%rdi
  401350:	e8 eb fa ff ff       	callq  400e40 <std::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string(char const*, std::allocator<char> const&)@plt>
  401355:	eb b5                	jmp    40130c <std::system_error::system_error(std::error_code)+0x4c>
  401357:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  401360:	be 90 14 40 00       	mov    $0x401490,%esi
  401365:	4c 89 e7             	mov    %r12,%rdi
  401368:	e8 d3 fa ff ff       	callq  400e40 <std::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string(char const*, std::allocator<char> const&)@plt>
  40136d:	eb 9d                	jmp    40130c <std::system_error::system_error(std::error_code)+0x4c>
  40136f:	90                   	nop
  401370:	be 9c 14 40 00       	mov    $0x40149c,%esi
  401375:	4c 89 e7             	mov    %r12,%rdi
  401378:	e8 c3 fa ff ff       	callq  400e40 <std::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string(char const*, std::allocator<char> const&)@plt>
  40137d:	eb 8d                	jmp    40130c <std::system_error::system_error(std::error_code)+0x4c>
  40137f:	90                   	nop
  401380:	89 f2                	mov    %esi,%edx
  401382:	4c 89 e7             	mov    %r12,%rdi
  401385:	48 89 ee             	mov    %rbp,%rsi
  401388:	ff d0                	callq  *%rax
  40138a:	eb 80                	jmp    40130c <std::system_error::system_error(std::error_code)+0x4c>
  40138c:	0f 1f 40 00          	nopl   0x0(%rax)
  401390:	ba 00 00 00 00       	mov    $0x0,%edx
  401395:	48 85 d2             	test   %rdx,%rdx
  401398:	74 26                	je     4013c0 <std::system_error::system_error(std::error_code)+0x100>
  40139a:	ba ff ff ff ff       	mov    $0xffffffff,%edx
  40139f:	f0 0f c1 50 f8       	lock xadd %edx,-0x8(%rax)
  4013a4:	85 d2                	test   %edx,%edx
  4013a6:	7f 81                	jg     401329 <std::system_error::system_error(std::error_code)+0x69>
  4013a8:	48 8d 74 24 0f       	lea    0xf(%rsp),%rsi
  400df0:	ff 25 62 12 20 00    	jmpq   *0x201262(%rip)        # 602058 <_GLOBAL_OFFSET_TABLE_+0x58>
  400df6:	68 08 00 00 00       	pushq  $0x8
  400dfb:	e9 60 ff ff ff       	jmpq   400d60 <_init+0x28>
  4013b2:	e9 72 ff ff ff       	jmpq   401329 <std::system_error::system_error(std::error_code)+0x69>
  4013b7:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  4013c0:	8b 50 f8             	mov    -0x8(%rax),%edx
  4013c3:	8d 4a ff             	lea    -0x1(%rdx),%ecx
  4013c6:	89 48 f8             	mov    %ecx,-0x8(%rax)
  4013c9:	eb d9                	jmp    4013a4 <std::system_error::system_error(std::error_code)+0xe4>
  4013cb:	48 89 c3             	mov    %rax,%rbx
  4013ce:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  4013d3:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  4013d7:	48 81 ff 80 21 60 00 	cmp    $0x602180,%rdi
  4013de:	74 0a                	je     4013ea <std::system_error::system_error(std::error_code)+0x12a>
  4013e0:	48 8d 74 24 0f       	lea    0xf(%rsp),%rsi
  400ed0:	b8 00 00 00 00       	mov    $0x0,%eax
  400ed5:	48 85 c0             	test   %rax,%rax
  400ed8:	74 0a                	je     400ee4 <std::string::_Rep::_M_dispose(std::allocator<char> const&) [clone .part.1]+0x14>
  400eda:	83 c8 ff             	or     $0xffffffff,%eax
  400edd:	f0 0f c1 47 10       	lock xadd %eax,0x10(%rdi)
  400ee2:	eb 09                	jmp    400eed <std::string::_Rep::_M_dispose(std::allocator<char> const&) [clone .part.1]+0x1d>
  400ee4:	8b 47 10             	mov    0x10(%rdi),%eax
  400ee7:	8d 50 ff             	lea    -0x1(%rax),%edx
  400eea:	89 57 10             	mov    %edx,0x10(%rdi)
  400eed:	85 c0                	test   %eax,%eax
  400eef:	7f 05                	jg     400ef6 <std::string::_Rep::_M_dispose(std::allocator<char> const&) [clone .part.1]+0x26>
  400ef1:	e9 fa fe ff ff       	jmpq   400df0 <std::string::_Rep::_M_destroy(std::allocator<char> const&)@plt>
  400ef6:	c3                   	retq
  400ef7:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  4013ea:	48 89 df             	mov    %rbx,%rdi
  400eb0:	ff 25 02 12 20 00    	jmpq   *0x201202(%rip)        # 6020b8 <_GLOBAL_OFFSET_TABLE_+0xb8>
  400eb6:	68 14 00 00 00       	pushq  $0x14
  400ebb:	e9 a0 fe ff ff       	jmpq   400d60 <_init+0x28>
  4013f2:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  4013fc:	0f 1f 40 00          	nopl   0x0(%rax)
  401078:	ba 20 0e 40 00       	mov    $0x400e20,%edx
  40107d:	be e0 20 60 00       	mov    $0x6020e0,%esi
  401082:	48 89 df             	mov    %rbx,%rdi
  400e80:	ff 25 1a 12 20 00    	jmpq   *0x20121a(%rip)        # 6020a0 <_GLOBAL_OFFSET_TABLE_+0xa0>
  400e86:	68 11 00 00 00       	pushq  $0x11
  400e8b:	e9 d0 fe ff ff       	jmpq   400d60 <_init+0x28>
  40108a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
  401090:	8d 44 6d 00          	lea    0x0(%rbp,%rbp,2),%eax
  401094:	c6 43 18 01          	movb   $0x1,0x18(%rbx)
  401098:	89 03                	mov    %eax,(%rbx)
  40109a:	48 83 c4 68          	add    $0x68,%rsp
  40109e:	48 89 d8             	mov    %rbx,%rax
  4010a1:	5b                   	pop    %rbx
  4010a2:	5d                   	pop    %rbp
  4010a3:	c3                   	retq
  4010a4:	0f 1f 40 00          	nopl   0x0(%rax)
  4010a8:	bf 20 00 00 00       	mov    $0x20,%edi
  400e60:	ff 25 2a 12 20 00    	jmpq   *0x20122a(%rip)        # 602090 <_GLOBAL_OFFSET_TABLE_+0x90>
  400e66:	68 0f 00 00 00       	pushq  $0xf
  400e6b:	e9 f0 fe ff ff       	jmpq   400d60 <_init+0x28>
  4010b2:	48 89 c3             	mov    %rax,%rbx
  4010b5:	0f b6 05 fc 10 20 00 	movzbl 0x2010fc(%rip),%eax        # 6021b8 <guard variable for boost::outcome::_1_0_std_std_9274c0d4::monad_category()::c>
  4010bc:	84 c0                	test   %al,%al
  4010be:	74 60                	je     401120 <test1()+0x110>
  4010c0:	48 8d 54 24 0f       	lea    0xf(%rsp),%rdx
  4010c5:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
  4010ca:	be 9c 14 40 00       	mov    $0x40149c,%esi
  400e40:	ff 25 3a 12 20 00    	jmpq   *0x20123a(%rip)        # 602080 <_GLOBAL_OFFSET_TABLE_+0x80>
  400e46:	68 0d 00 00 00       	pushq  $0xd
  400e4b:	e9 10 ff ff ff       	jmpq   400d60 <_init+0x28>
  4010d4:	48 8d 74 24 10       	lea    0x10(%rsp),%rsi
  4010d9:	48 89 df             	mov    %rbx,%rdi
  400da0:	ff 25 8a 12 20 00    	jmpq   *0x20128a(%rip)        # 602030 <_GLOBAL_OFFSET_TABLE_+0x30>
  400da6:	68 03 00 00 00       	pushq  $0x3
  400dab:	e9 b0 ff ff ff       	jmpq   400d60 <_init+0x28>
  4010e1:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  4010e6:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  4010ea:	48 81 ff 80 21 60 00 	cmp    $0x602180,%rdi
  4010f1:	75 65                	jne    401158 <test1()+0x148>
  4010f3:	c7 43 10 02 00 00 00 	movl   $0x2,0x10(%rbx)
  4010fa:	48 c7 43 18 d8 20 60 	movq   $0x6020d8,0x18(%rbx)
  401102:	ba e0 11 40 00       	mov    $0x4011e0,%edx
  401107:	48 c7 03 d0 15 40 00 	movq   $0x4015d0,(%rbx)
  40110e:	be 58 15 40 00       	mov    $0x401558,%esi
  401113:	48 89 df             	mov    %rbx,%rdi
  400e80:	ff 25 1a 12 20 00    	jmpq   *0x20121a(%rip)        # 6020a0 <_GLOBAL_OFFSET_TABLE_+0xa0>
  400e86:	68 11 00 00 00       	pushq  $0x11
  400e8b:	e9 d0 fe ff ff       	jmpq   400d60 <_init+0x28>
  40111b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
  401120:	bf b8 21 60 00       	mov    $0x6021b8,%edi
  400d90:	ff 25 92 12 20 00    	jmpq   *0x201292(%rip)        # 602028 <_GLOBAL_OFFSET_TABLE_+0x28>
  400d96:	68 02 00 00 00       	pushq  $0x2
  400d9b:	e9 c0 ff ff ff       	jmpq   400d60 <_init+0x28>
  40112a:	85 c0                	test   %eax,%eax
  40112c:	74 92                	je     4010c0 <test1()+0xb0>
  40112e:	bf b8 21 60 00       	mov    $0x6021b8,%edi
  400e10:	ff 25 52 12 20 00    	jmpq   *0x201252(%rip)        # 602068 <_GLOBAL_OFFSET_TABLE_+0x68>
  400e16:	68 0a 00 00 00       	pushq  $0xa
  400e1b:	e9 40 ff ff ff       	jmpq   400d60 <_init+0x28>
  401138:	ba d0 20 60 00       	mov    $0x6020d0,%edx
  40113d:	be d8 20 60 00       	mov    $0x6020d8,%esi
  401142:	bf 10 12 40 00       	mov    $0x401210,%edi
  400de0:	ff 25 6a 12 20 00    	jmpq   *0x20126a(%rip)        # 602050 <_GLOBAL_OFFSET_TABLE_+0x50>
  400de6:	68 07 00 00 00       	pushq  $0x7
  400deb:	e9 70 ff ff ff       	jmpq   400d60 <_init+0x28>
  40114c:	e9 6f ff ff ff       	jmpq   4010c0 <test1()+0xb0>
  401151:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
  401158:	ba 00 00 00 00       	mov    $0x0,%edx
  40115d:	48 85 d2             	test   %rdx,%rdx
  401160:	74 1d                	je     40117f <test1()+0x16f>
  401162:	ba ff ff ff ff       	mov    $0xffffffff,%edx
  401167:	f0 0f c1 50 f8       	lock xadd %edx,-0x8(%rax)
  40116c:	85 d2                	test   %edx,%edx
  40116e:	7f 83                	jg     4010f3 <test1()+0xe3>
  401170:	48 8d 74 24 0f       	lea    0xf(%rsp),%rsi
  400df0:	ff 25 62 12 20 00    	jmpq   *0x201262(%rip)        # 602058 <_GLOBAL_OFFSET_TABLE_+0x58>
  400df6:	68 08 00 00 00       	pushq  $0x8
  400dfb:	e9 60 ff ff ff       	jmpq   400d60 <_init+0x28>
  40117a:	e9 74 ff ff ff       	jmpq   4010f3 <test1()+0xe3>
  40117f:	8b 50 f8             	mov    -0x8(%rax),%edx
  401182:	8d 4a ff             	lea    -0x1(%rdx),%ecx
  401185:	89 48 f8             	mov    %ecx,-0x8(%rax)
  401188:	eb e2                	jmp    40116c <test1()+0x15c>
  40118a:	48 89 c5             	mov    %rax,%rbp
  40118d:	48 89 df             	mov    %rbx,%rdi
  400e70:	ff 25 22 12 20 00    	jmpq   *0x201222(%rip)        # 602098 <_GLOBAL_OFFSET_TABLE_+0x98>
  400e76:	68 10 00 00 00       	pushq  $0x10
  400e7b:	e9 e0 fe ff ff       	jmpq   400d60 <_init+0x28>
  401195:	48 89 ef             	mov    %rbp,%rdi
  400eb0:	ff 25 02 12 20 00    	jmpq   *0x201202(%rip)        # 6020b8 <_GLOBAL_OFFSET_TABLE_+0xb8>
  400eb6:	68 14 00 00 00       	pushq  $0x14
  400ebb:	e9 a0 fe ff ff       	jmpq   400d60 <_init+0x28>
  40119d:	eb eb                	jmp    40118a <test1()+0x17a>
  40119f:	48 89 c5             	mov    %rax,%rbp
  4011a2:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  4011a7:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  4011ab:	48 81 ff 80 21 60 00 	cmp    $0x602180,%rdi
  4011b2:	74 d9                	je     40118d <test1()+0x17d>
  4011b4:	48 8d 74 24 0f       	lea    0xf(%rsp),%rsi
  400ed0:	b8 00 00 00 00       	mov    $0x0,%eax
  400ed5:	48 85 c0             	test   %rax,%rax
  400ed8:	74 0a                	je     400ee4 <std::string::_Rep::_M_dispose(std::allocator<char> const&) [clone .part.1]+0x14>
  400eda:	83 c8 ff             	or     $0xffffffff,%eax
  400edd:	f0 0f c1 47 10       	lock xadd %eax,0x10(%rdi)
  400ee2:	eb 09                	jmp    400eed <std::string::_Rep::_M_dispose(std::allocator<char> const&) [clone .part.1]+0x1d>
  400ee4:	8b 47 10             	mov    0x10(%rdi),%eax
  400ee7:	8d 50 ff             	lea    -0x1(%rax),%edx
  400eea:	89 57 10             	mov    %edx,0x10(%rdi)
  400eed:	85 c0                	test   %eax,%eax
  400eef:	7f 05                	jg     400ef6 <std::string::_Rep::_M_dispose(std::allocator<char> const&) [clone .part.1]+0x26>
  400ef1:	e9 fa fe ff ff       	jmpq   400df0 <std::string::_Rep::_M_destroy(std::allocator<char> const&)@plt>
  400ef6:	c3                   	retq
  400ef7:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  4011be:	eb cd                	jmp    40118d <test1()+0x17d>
