  401020:	55                   	push   %rbp
  401021:	53                   	push   %rbx
  401022:	48 83 ec 48          	sub    $0x48,%rsp
  401026:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
  40102b:	e8 d0 ef bf ff       	callq  0 <_init-0x400d38>
  401030:	0f b6 44 24 38       	movzbl 0x38(%rsp),%eax
  401035:	84 c0                	test   %al,%al
  401037:	74 47                	je     401080 <test1()+0x60>
  401039:	3c 02                	cmp    $0x2,%al
  40103b:	75 33                	jne    401070 <test1()+0x50>
  40103d:	bf 20 00 00 00       	mov    $0x20,%edi
  400e60:	ff 25 2a 12 20 00    	jmpq   *0x20122a(%rip)        # 602090 <_GLOBAL_OFFSET_TABLE_+0x90>
  400e66:	68 0f 00 00 00       	pushq  $0xf
  400e6b:	e9 f0 fe ff ff       	jmpq   400d60 <_init+0x28>
  401047:	8b 74 24 20          	mov    0x20(%rsp),%esi
  40104b:	48 8b 54 24 28       	mov    0x28(%rsp),%rdx
  401050:	48 89 c7             	mov    %rax,%rdi
  401053:	48 89 c3             	mov    %rax,%rbx
  4012a0:	41 55                	push   %r13
  4012a2:	41 54                	push   %r12
  4012a4:	49 89 f5             	mov    %rsi,%r13
  4012a7:	55                   	push   %rbp
  4012a8:	53                   	push   %rbx
  4012a9:	48 89 d5             	mov    %rdx,%rbp
  4012ac:	48 89 fb             	mov    %rdi,%rbx
  4012af:	48 83 ec 28          	sub    $0x28,%rsp
  4012b3:	48 8b 02             	mov    (%rdx),%rax
  4012b6:	4c 8d 64 24 10       	lea    0x10(%rsp),%r12
  4012bb:	48 8b 40 18          	mov    0x18(%rax),%rax
  4012bf:	48 3d 20 12 40 00    	cmp    $0x401220,%rax
  4012c5:	0f 85 95 00 00 00    	jne    401360 <std::system_error::system_error(std::error_code)+0xc0>
  4012cb:	83 fe 02             	cmp    $0x2,%esi
  4012ce:	48 8d 54 24 0f       	lea    0xf(%rsp),%rdx
  4012d3:	74 7b                	je     401350 <std::system_error::system_error(std::error_code)+0xb0>
  4012d5:	83 fe 03             	cmp    $0x3,%esi
  4012d8:	74 4e                	je     401328 <std::system_error::system_error(std::error_code)+0x88>
  4012da:	83 fe 01             	cmp    $0x1,%esi
  4012dd:	74 61                	je     401340 <std::system_error::system_error(std::error_code)+0xa0>
  4012df:	be 97 14 40 00       	mov    $0x401497,%esi
  4012e4:	4c 89 e7             	mov    %r12,%rdi
  400e40:	ff 25 3a 12 20 00    	jmpq   *0x20123a(%rip)        # 602080 <_GLOBAL_OFFSET_TABLE_+0x80>
  400e46:	68 0d 00 00 00       	pushq  $0xd
  400e4b:	e9 10 ff ff ff       	jmpq   400d60 <_init+0x28>
  4012ec:	4c 89 e6             	mov    %r12,%rsi
  4012ef:	48 89 df             	mov    %rbx,%rdi
  400da0:	ff 25 8a 12 20 00    	jmpq   *0x20128a(%rip)        # 602030 <_GLOBAL_OFFSET_TABLE_+0x30>
  400da6:	68 03 00 00 00       	pushq  $0x3
  400dab:	e9 b0 ff ff ff       	jmpq   400d60 <_init+0x28>
  4012f7:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  4012fc:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  401300:	48 81 ff 80 21 60 00 	cmp    $0x602180,%rdi
  401307:	75 67                	jne    401370 <std::system_error::system_error(std::error_code)+0xd0>
  401309:	48 c7 03 08 21 60 00 	movq   $0x602108,(%rbx)
  401310:	4c 89 6b 10          	mov    %r13,0x10(%rbx)
  401314:	48 89 6b 18          	mov    %rbp,0x18(%rbx)
  401318:	48 83 c4 28          	add    $0x28,%rsp
  40131c:	5b                   	pop    %rbx
  40131d:	5d                   	pop    %rbp
  40131e:	41 5c                	pop    %r12
  401320:	41 5d                	pop    %r13
  401322:	c3                   	retq
  401323:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
  401328:	be 85 14 40 00       	mov    $0x401485,%esi
  40132d:	4c 89 e7             	mov    %r12,%rdi
  401330:	e8 0b fb ff ff       	callq  400e40 <std::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string(char const*, std::allocator<char> const&)@plt>
  401335:	eb b5                	jmp    4012ec <std::system_error::system_error(std::error_code)+0x4c>
  401337:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  401340:	be 70 14 40 00       	mov    $0x401470,%esi
  401345:	4c 89 e7             	mov    %r12,%rdi
  401348:	e8 f3 fa ff ff       	callq  400e40 <std::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string(char const*, std::allocator<char> const&)@plt>
  40134d:	eb 9d                	jmp    4012ec <std::system_error::system_error(std::error_code)+0x4c>
  40134f:	90                   	nop
  401350:	be 7c 14 40 00       	mov    $0x40147c,%esi
  401355:	4c 89 e7             	mov    %r12,%rdi
  401358:	e8 e3 fa ff ff       	callq  400e40 <std::basic_string<char, std::char_traits<char>, std::allocator<char> >::basic_string(char const*, std::allocator<char> const&)@plt>
  40135d:	eb 8d                	jmp    4012ec <std::system_error::system_error(std::error_code)+0x4c>
  40135f:	90                   	nop
  401360:	89 f2                	mov    %esi,%edx
  401362:	4c 89 e7             	mov    %r12,%rdi
  401365:	48 89 ee             	mov    %rbp,%rsi
  401368:	ff d0                	callq  *%rax
  40136a:	eb 80                	jmp    4012ec <std::system_error::system_error(std::error_code)+0x4c>
  40136c:	0f 1f 40 00          	nopl   0x0(%rax)
  401370:	ba 00 00 00 00       	mov    $0x0,%edx
  401375:	48 85 d2             	test   %rdx,%rdx
  401378:	74 26                	je     4013a0 <std::system_error::system_error(std::error_code)+0x100>
  40137a:	ba ff ff ff ff       	mov    $0xffffffff,%edx
  40137f:	f0 0f c1 50 f8       	lock xadd %edx,-0x8(%rax)
  401384:	85 d2                	test   %edx,%edx
  401386:	7f 81                	jg     401309 <std::system_error::system_error(std::error_code)+0x69>
  401388:	48 8d 74 24 0f       	lea    0xf(%rsp),%rsi
  400df0:	ff 25 62 12 20 00    	jmpq   *0x201262(%rip)        # 602058 <_GLOBAL_OFFSET_TABLE_+0x58>
  400df6:	68 08 00 00 00       	pushq  $0x8
  400dfb:	e9 60 ff ff ff       	jmpq   400d60 <_init+0x28>
  401392:	e9 72 ff ff ff       	jmpq   401309 <std::system_error::system_error(std::error_code)+0x69>
  401397:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  4013a0:	8b 50 f8             	mov    -0x8(%rax),%edx
  4013a3:	8d 4a ff             	lea    -0x1(%rdx),%ecx
  4013a6:	89 48 f8             	mov    %ecx,-0x8(%rax)
  4013a9:	eb d9                	jmp    401384 <std::system_error::system_error(std::error_code)+0xe4>
  4013ab:	48 89 c3             	mov    %rax,%rbx
  4013ae:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  4013b3:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  4013b7:	48 81 ff 80 21 60 00 	cmp    $0x602180,%rdi
  4013be:	74 0a                	je     4013ca <std::system_error::system_error(std::error_code)+0x12a>
  4013c0:	48 8d 74 24 0f       	lea    0xf(%rsp),%rsi
  400ed0:	b8 00 00 00 00       	mov    $0x0,%eax
  400ed5:	48 85 c0             	test   %rax,%rax
  400ed8:	74 0a                	je     400ee4 <std::string::_Rep::_M_dispose(std::allocator<char> const&) [clone .part.0]+0x14>
  400eda:	83 c8 ff             	or     $0xffffffff,%eax
  400edd:	f0 0f c1 47 10       	lock xadd %eax,0x10(%rdi)
  400ee2:	eb 09                	jmp    400eed <std::string::_Rep::_M_dispose(std::allocator<char> const&) [clone .part.0]+0x1d>
  400ee4:	8b 47 10             	mov    0x10(%rdi),%eax
  400ee7:	8d 50 ff             	lea    -0x1(%rax),%edx
  400eea:	89 57 10             	mov    %edx,0x10(%rdi)
  400eed:	85 c0                	test   %eax,%eax
  400eef:	7f 05                	jg     400ef6 <std::string::_Rep::_M_dispose(std::allocator<char> const&) [clone .part.0]+0x26>
  400ef1:	e9 fa fe ff ff       	jmpq   400df0 <std::string::_Rep::_M_destroy(std::allocator<char> const&)@plt>
  400ef6:	c3                   	retq
  400ef7:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  4013ca:	48 89 df             	mov    %rbx,%rdi
  400eb0:	ff 25 02 12 20 00    	jmpq   *0x201202(%rip)        # 6020b8 <_GLOBAL_OFFSET_TABLE_+0xb8>
  400eb6:	68 14 00 00 00       	pushq  $0x14
  400ebb:	e9 a0 fe ff ff       	jmpq   400d60 <_init+0x28>
  4013d2:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  4013dc:	0f 1f 40 00          	nopl   0x0(%rax)
  40105b:	ba 20 0e 40 00       	mov    $0x400e20,%edx
  401060:	be e0 20 60 00       	mov    $0x6020e0,%esi
  401065:	48 89 df             	mov    %rbx,%rdi
  400e80:	ff 25 1a 12 20 00    	jmpq   *0x20121a(%rip)        # 6020a0 <_GLOBAL_OFFSET_TABLE_+0xa0>
  400e86:	68 11 00 00 00       	pushq  $0x11
  400e8b:	e9 d0 fe ff ff       	jmpq   400d60 <_init+0x28>
  40106d:	0f 1f 00             	nopl   (%rax)
  401070:	8b 44 24 20          	mov    0x20(%rsp),%eax
  401074:	48 83 c4 48          	add    $0x48,%rsp
  401078:	5b                   	pop    %rbx
  401079:	5d                   	pop    %rbp
  40107a:	c3                   	retq
  40107b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
  401080:	bf 20 00 00 00       	mov    $0x20,%edi
  400e60:	ff 25 2a 12 20 00    	jmpq   *0x20122a(%rip)        # 602090 <_GLOBAL_OFFSET_TABLE_+0x90>
  400e66:	68 0f 00 00 00       	pushq  $0xf
  400e6b:	e9 f0 fe ff ff       	jmpq   400d60 <_init+0x28>
  40108a:	48 89 c3             	mov    %rax,%rbx
  40108d:	0f b6 05 24 11 20 00 	movzbl 0x201124(%rip),%eax        # 6021b8 <guard variable for boost::outcome::_1_0_std_std_9274c0d4::monad_category()::c>
  401094:	84 c0                	test   %al,%al
  401096:	74 60                	je     4010f8 <test1()+0xd8>
  401098:	48 8d 54 24 0f       	lea    0xf(%rsp),%rdx
  40109d:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
  4010a2:	be 7c 14 40 00       	mov    $0x40147c,%esi
  400e40:	ff 25 3a 12 20 00    	jmpq   *0x20123a(%rip)        # 602080 <_GLOBAL_OFFSET_TABLE_+0x80>
  400e46:	68 0d 00 00 00       	pushq  $0xd
  400e4b:	e9 10 ff ff ff       	jmpq   400d60 <_init+0x28>
  4010ac:	48 8d 74 24 10       	lea    0x10(%rsp),%rsi
  4010b1:	48 89 df             	mov    %rbx,%rdi
  400da0:	ff 25 8a 12 20 00    	jmpq   *0x20128a(%rip)        # 602030 <_GLOBAL_OFFSET_TABLE_+0x30>
  400da6:	68 03 00 00 00       	pushq  $0x3
  400dab:	e9 b0 ff ff ff       	jmpq   400d60 <_init+0x28>
  4010b9:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  4010be:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  4010c2:	48 81 ff 80 21 60 00 	cmp    $0x602180,%rdi
  4010c9:	75 65                	jne    401130 <test1()+0x110>
  4010cb:	c7 43 10 02 00 00 00 	movl   $0x2,0x10(%rbx)
  4010d2:	48 c7 43 18 d8 20 60 	movq   $0x6020d8,0x18(%rbx)
  4010da:	ba c0 11 40 00       	mov    $0x4011c0,%edx
  4010df:	48 c7 03 b0 15 40 00 	movq   $0x4015b0,(%rbx)
  4010e6:	be 38 15 40 00       	mov    $0x401538,%esi
  4010eb:	48 89 df             	mov    %rbx,%rdi
  400e80:	ff 25 1a 12 20 00    	jmpq   *0x20121a(%rip)        # 6020a0 <_GLOBAL_OFFSET_TABLE_+0xa0>
  400e86:	68 11 00 00 00       	pushq  $0x11
  400e8b:	e9 d0 fe ff ff       	jmpq   400d60 <_init+0x28>
  4010f3:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
  4010f8:	bf b8 21 60 00       	mov    $0x6021b8,%edi
  400d90:	ff 25 92 12 20 00    	jmpq   *0x201292(%rip)        # 602028 <_GLOBAL_OFFSET_TABLE_+0x28>
  400d96:	68 02 00 00 00       	pushq  $0x2
  400d9b:	e9 c0 ff ff ff       	jmpq   400d60 <_init+0x28>
  401102:	85 c0                	test   %eax,%eax
  401104:	74 92                	je     401098 <test1()+0x78>
  401106:	bf b8 21 60 00       	mov    $0x6021b8,%edi
  400e10:	ff 25 52 12 20 00    	jmpq   *0x201252(%rip)        # 602068 <_GLOBAL_OFFSET_TABLE_+0x68>
  400e16:	68 0a 00 00 00       	pushq  $0xa
  400e1b:	e9 40 ff ff ff       	jmpq   400d60 <_init+0x28>
  401110:	ba d0 20 60 00       	mov    $0x6020d0,%edx
  401115:	be d8 20 60 00       	mov    $0x6020d8,%esi
  40111a:	bf f0 11 40 00       	mov    $0x4011f0,%edi
  400de0:	ff 25 6a 12 20 00    	jmpq   *0x20126a(%rip)        # 602050 <_GLOBAL_OFFSET_TABLE_+0x50>
  400de6:	68 07 00 00 00       	pushq  $0x7
  400deb:	e9 70 ff ff ff       	jmpq   400d60 <_init+0x28>
  401124:	e9 6f ff ff ff       	jmpq   401098 <test1()+0x78>
  401129:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
  401130:	ba 00 00 00 00       	mov    $0x0,%edx
  401135:	48 85 d2             	test   %rdx,%rdx
  401138:	74 1d                	je     401157 <test1()+0x137>
  40113a:	ba ff ff ff ff       	mov    $0xffffffff,%edx
  40113f:	f0 0f c1 50 f8       	lock xadd %edx,-0x8(%rax)
  401144:	85 d2                	test   %edx,%edx
  401146:	7f 83                	jg     4010cb <test1()+0xab>
  401148:	48 8d 74 24 0f       	lea    0xf(%rsp),%rsi
  400df0:	ff 25 62 12 20 00    	jmpq   *0x201262(%rip)        # 602058 <_GLOBAL_OFFSET_TABLE_+0x58>
  400df6:	68 08 00 00 00       	pushq  $0x8
  400dfb:	e9 60 ff ff ff       	jmpq   400d60 <_init+0x28>
  401152:	e9 74 ff ff ff       	jmpq   4010cb <test1()+0xab>
  401157:	8b 50 f8             	mov    -0x8(%rax),%edx
  40115a:	8d 4a ff             	lea    -0x1(%rdx),%ecx
  40115d:	89 48 f8             	mov    %ecx,-0x8(%rax)
  401160:	eb e2                	jmp    401144 <test1()+0x124>
  401162:	48 89 c5             	mov    %rax,%rbp
  401165:	48 89 df             	mov    %rbx,%rdi
  400e70:	ff 25 22 12 20 00    	jmpq   *0x201222(%rip)        # 602098 <_GLOBAL_OFFSET_TABLE_+0x98>
  400e76:	68 10 00 00 00       	pushq  $0x10
  400e7b:	e9 e0 fe ff ff       	jmpq   400d60 <_init+0x28>
  40116d:	48 89 ef             	mov    %rbp,%rdi
  400eb0:	ff 25 02 12 20 00    	jmpq   *0x201202(%rip)        # 6020b8 <_GLOBAL_OFFSET_TABLE_+0xb8>
  400eb6:	68 14 00 00 00       	pushq  $0x14
  400ebb:	e9 a0 fe ff ff       	jmpq   400d60 <_init+0x28>
  401175:	eb eb                	jmp    401162 <test1()+0x142>
  401177:	48 89 c5             	mov    %rax,%rbp
  40117a:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
  40117f:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  401183:	48 81 ff 80 21 60 00 	cmp    $0x602180,%rdi
  40118a:	74 d9                	je     401165 <test1()+0x145>
  40118c:	48 8d 74 24 0f       	lea    0xf(%rsp),%rsi
  400ed0:	b8 00 00 00 00       	mov    $0x0,%eax
  400ed5:	48 85 c0             	test   %rax,%rax
  400ed8:	74 0a                	je     400ee4 <std::string::_Rep::_M_dispose(std::allocator<char> const&) [clone .part.0]+0x14>
  400eda:	83 c8 ff             	or     $0xffffffff,%eax
  400edd:	f0 0f c1 47 10       	lock xadd %eax,0x10(%rdi)
  400ee2:	eb 09                	jmp    400eed <std::string::_Rep::_M_dispose(std::allocator<char> const&) [clone .part.0]+0x1d>
  400ee4:	8b 47 10             	mov    0x10(%rdi),%eax
  400ee7:	8d 50 ff             	lea    -0x1(%rax),%edx
  400eea:	89 57 10             	mov    %edx,0x10(%rdi)
  400eed:	85 c0                	test   %eax,%eax
  400eef:	7f 05                	jg     400ef6 <std::string::_Rep::_M_dispose(std::allocator<char> const&) [clone .part.0]+0x26>
  400ef1:	e9 fa fe ff ff       	jmpq   400df0 <std::string::_Rep::_M_destroy(std::allocator<char> const&)@plt>
  400ef6:	c3                   	retq
  400ef7:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  401196:	eb cd                	jmp    401165 <test1()+0x145>
  401198:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
