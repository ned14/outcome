  401030:	55                   	push   %rbp
  401031:	53                   	push   %rbx
  401032:	48 83 ec 58          	sub    $0x58,%rsp
  401036:	48 8d 7c 24 30       	lea    0x30(%rsp),%rdi
  40103b:	e8 c0 ef bf ff       	callq  0 <_init-0x400d60>
  401040:	0f b6 5c 24 48       	movzbl 0x48(%rsp),%ebx
  401045:	84 db                	test   %bl,%bl
  401047:	75 77                	jne    4010c0 <test1()+0x90>
  401049:	bf 20 00 00 00       	mov    $0x20,%edi
  400e90:	ff 25 02 12 20 00    	jmpq   *0x201202(%rip)        # 602098 <_GLOBAL_OFFSET_TABLE_+0x98>
  400e96:	68 10 00 00 00       	pushq  $0x10
  400e9b:	e9 e0 fe ff ff       	jmpq   400d80 <_init+0x20>
  401053:	48 89 c3             	mov    %rax,%rbx
  401056:	0f b6 05 5b 11 20 00 	movzbl 0x20115b(%rip),%eax        # 6021b8 <guard variable for boost::outcome::_1_0_std_std_9274c0d4::monad_category()::c>
  40105d:	84 c0                	test   %al,%al
  40105f:	74 77                	je     4010d8 <test1()+0xa8>
  401061:	48 8d 54 24 1f       	lea    0x1f(%rsp),%rdx
  401066:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
  40106b:	be fc 13 40 00       	mov    $0x4013fc,%esi
  400e50:	ff 25 22 12 20 00    	jmpq   *0x201222(%rip)        # 602078 <_GLOBAL_OFFSET_TABLE_+0x78>
  400e56:	68 0c 00 00 00       	pushq  $0xc
  400e5b:	e9 20 ff ff ff       	jmpq   400d80 <_init+0x20>
  401075:	48 8d 74 24 20       	lea    0x20(%rsp),%rsi
  40107a:	48 89 df             	mov    %rbx,%rdi
  400dc0:	ff 25 6a 12 20 00    	jmpq   *0x20126a(%rip)        # 602030 <_GLOBAL_OFFSET_TABLE_+0x30>
  400dc6:	68 03 00 00 00       	pushq  $0x3
  400dcb:	e9 b0 ff ff ff       	jmpq   400d80 <_init+0x20>
  401082:	48 8b 44 24 20       	mov    0x20(%rsp),%rax
  401087:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  40108b:	48 81 ff 80 21 60 00 	cmp    $0x602180,%rdi
  401092:	0f 85 b8 00 00 00    	jne    401150 <test1()+0x120>
  401098:	c7 43 10 02 00 00 00 	movl   $0x2,0x10(%rbx)
  40109f:	48 c7 43 18 e0 20 60 	movq   $0x6020e0,0x18(%rbx)
  4010a7:	ba 80 12 40 00       	mov    $0x401280,%edx
  4010ac:	48 c7 03 30 15 40 00 	movq   $0x401530,(%rbx)
  4010b3:	be b8 14 40 00       	mov    $0x4014b8,%esi
  4010b8:	48 89 df             	mov    %rbx,%rdi
  400eb0:	ff 25 f2 11 20 00    	jmpq   *0x2011f2(%rip)        # 6020a8 <_GLOBAL_OFFSET_TABLE_+0xa8>
  400eb6:	68 12 00 00 00       	pushq  $0x12
  400ebb:	e9 c0 fe ff ff       	jmpq   400d80 <_init+0x20>
  4010c0:	80 fb 02             	cmp    $0x2,%bl
  4010c3:	75 4b                	jne    401110 <test1()+0xe0>
  4010c5:	8b 44 24 30          	mov    0x30(%rsp),%eax
  4010c9:	48 8b 54 24 38       	mov    0x38(%rsp),%rdx
  4010ce:	48 83 c4 58          	add    $0x58,%rsp
  4010d2:	5b                   	pop    %rbx
  4010d3:	5d                   	pop    %rbp
  4010d4:	c3                   	retq
  4010d5:	0f 1f 00             	nopl   (%rax)
  4010d8:	bf b8 21 60 00       	mov    $0x6021b8,%edi
  400db0:	ff 25 72 12 20 00    	jmpq   *0x201272(%rip)        # 602028 <_GLOBAL_OFFSET_TABLE_+0x28>
  400db6:	68 02 00 00 00       	pushq  $0x2
  400dbb:	e9 c0 ff ff ff       	jmpq   400d80 <_init+0x20>
  4010e2:	85 c0                	test   %eax,%eax
  4010e4:	0f 84 77 ff ff ff    	je     401061 <test1()+0x31>
  4010ea:	bf b8 21 60 00       	mov    $0x6021b8,%edi
  400e30:	ff 25 32 12 20 00    	jmpq   *0x201232(%rip)        # 602068 <_GLOBAL_OFFSET_TABLE_+0x68>
  400e36:	68 0a 00 00 00       	pushq  $0xa
  400e3b:	e9 40 ff ff ff       	jmpq   400d80 <_init+0x20>
  4010f4:	ba d8 20 60 00       	mov    $0x6020d8,%edx
  4010f9:	be e0 20 60 00       	mov    $0x6020e0,%esi
  4010fe:	bf 30 13 40 00       	mov    $0x401330,%edi
  400e00:	ff 25 4a 12 20 00    	jmpq   *0x20124a(%rip)        # 602050 <_GLOBAL_OFFSET_TABLE_+0x50>
  400e06:	68 07 00 00 00       	pushq  $0x7
  400e0b:	e9 70 ff ff ff       	jmpq   400d80 <_init+0x20>
  401108:	e9 54 ff ff ff       	jmpq   401061 <test1()+0x31>
  40110d:	0f 1f 00             	nopl   (%rax)
  401110:	80 fb 03             	cmp    $0x3,%bl
  401113:	0f 84 97 00 00 00    	je     4011b0 <test1()+0x180>
  400e70:	ff 25 12 12 20 00    	jmpq   *0x201212(%rip)        # 602088 <_GLOBAL_OFFSET_TABLE_+0x88>
  400e76:	68 0e 00 00 00       	pushq  $0xe
  400e7b:	e9 00 ff ff ff       	jmpq   400d80 <_init+0x20>
  40111e:	48 89 c2             	mov    %rax,%rdx
  401121:	31 c0                	xor    %eax,%eax
  401123:	83 e0 03             	and    $0x3,%eax
  401126:	80 fb 03             	cmp    $0x3,%bl
  401129:	75 a3                	jne    4010ce <test1()+0x9e>
  40112b:	48 8d 7c 24 30       	lea    0x30(%rsp),%rdi
  401130:	48 89 54 24 08       	mov    %rdx,0x8(%rsp)
  401135:	48 89 04 24          	mov    %rax,(%rsp)
  400e80:	ff 25 0a 12 20 00    	jmpq   *0x20120a(%rip)        # 602090 <_GLOBAL_OFFSET_TABLE_+0x90>
  400e86:	68 0f 00 00 00       	pushq  $0xf
  400e8b:	e9 f0 fe ff ff       	jmpq   400d80 <_init+0x20>
  40113e:	48 8b 04 24          	mov    (%rsp),%rax
  401142:	48 8b 54 24 08       	mov    0x8(%rsp),%rdx
  401147:	48 83 c4 58          	add    $0x58,%rsp
  40114b:	5b                   	pop    %rbx
  40114c:	5d                   	pop    %rbp
  40114d:	c3                   	retq
  40114e:	66 90                	xchg   %ax,%ax
  401150:	ba 00 00 00 00       	mov    $0x0,%edx
  401155:	48 85 d2             	test   %rdx,%rdx
  401158:	74 46                	je     4011a0 <test1()+0x170>
  40115a:	ba ff ff ff ff       	mov    $0xffffffff,%edx
  40115f:	f0 0f c1 50 f8       	lock xadd %edx,-0x8(%rax)
  401164:	85 d2                	test   %edx,%edx
  401166:	0f 8f 2c ff ff ff    	jg     401098 <test1()+0x68>
  40116c:	48 8d 74 24 1f       	lea    0x1f(%rsp),%rsi
  400e10:	ff 25 42 12 20 00    	jmpq   *0x201242(%rip)        # 602058 <_GLOBAL_OFFSET_TABLE_+0x58>
  400e16:	68 08 00 00 00       	pushq  $0x8
  400e1b:	e9 60 ff ff ff       	jmpq   400d80 <_init+0x20>
  401176:	e9 1d ff ff ff       	jmpq   401098 <test1()+0x68>
  40117b:	48 89 c3             	mov    %rax,%rbx
  40117e:	80 7c 24 48 03       	cmpb   $0x3,0x48(%rsp)
  401183:	75 0a                	jne    40118f <test1()+0x15f>
  401185:	48 8d 7c 24 30       	lea    0x30(%rsp),%rdi
  400e80:	ff 25 0a 12 20 00    	jmpq   *0x20120a(%rip)        # 602090 <_GLOBAL_OFFSET_TABLE_+0x90>
  400e86:	68 0f 00 00 00       	pushq  $0xf
  400e8b:	e9 f0 fe ff ff       	jmpq   400d80 <_init+0x20>
  40118f:	48 89 df             	mov    %rbx,%rdi
  400ee0:	ff 25 da 11 20 00    	jmpq   *0x2011da(%rip)        # 6020c0 <_GLOBAL_OFFSET_TABLE_+0xc0>
  400ee6:	68 15 00 00 00       	pushq  $0x15
  400eeb:	e9 90 fe ff ff       	jmpq   400d80 <_init+0x20>
  401197:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  4011a0:	8b 50 f8             	mov    -0x8(%rax),%edx
  4011a3:	8d 4a ff             	lea    -0x1(%rdx),%ecx
  4011a6:	89 48 f8             	mov    %ecx,-0x8(%rax)
  4011a9:	eb b9                	jmp    401164 <test1()+0x134>
  4011ab:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
  4011b0:	0f b6 05 01 10 20 00 	movzbl 0x201001(%rip),%eax        # 6021b8 <guard variable for boost::outcome::_1_0_std_std_9274c0d4::monad_category()::c>
  4011b7:	84 c0                	test   %al,%al
  4011b9:	74 15                	je     4011d0 <test1()+0x1a0>
  4011bb:	0f b6 5c 24 48       	movzbl 0x48(%rsp),%ebx
  4011c0:	ba e0 20 60 00       	mov    $0x6020e0,%edx
  4011c5:	b8 03 00 00 00       	mov    $0x3,%eax
  4011ca:	e9 54 ff ff ff       	jmpq   401123 <test1()+0xf3>
  4011cf:	90                   	nop
  4011d0:	bf b8 21 60 00       	mov    $0x6021b8,%edi
  400db0:	ff 25 72 12 20 00    	jmpq   *0x201272(%rip)        # 602028 <_GLOBAL_OFFSET_TABLE_+0x28>
  400db6:	68 02 00 00 00       	pushq  $0x2
  400dbb:	e9 c0 ff ff ff       	jmpq   400d80 <_init+0x20>
  4011da:	85 c0                	test   %eax,%eax
  4011dc:	74 dd                	je     4011bb <test1()+0x18b>
  4011de:	bf b8 21 60 00       	mov    $0x6021b8,%edi
  400e30:	ff 25 32 12 20 00    	jmpq   *0x201232(%rip)        # 602068 <_GLOBAL_OFFSET_TABLE_+0x68>
  400e36:	68 0a 00 00 00       	pushq  $0xa
  400e3b:	e9 40 ff ff ff       	jmpq   400d80 <_init+0x20>
  4011e8:	ba d8 20 60 00       	mov    $0x6020d8,%edx
  4011ed:	be e0 20 60 00       	mov    $0x6020e0,%esi
  4011f2:	bf 30 13 40 00       	mov    $0x401330,%edi
  400e00:	ff 25 4a 12 20 00    	jmpq   *0x20124a(%rip)        # 602050 <_GLOBAL_OFFSET_TABLE_+0x50>
  400e06:	68 07 00 00 00       	pushq  $0x7
  400e0b:	e9 70 ff ff ff       	jmpq   400d80 <_init+0x20>
  4011fc:	eb bd                	jmp    4011bb <test1()+0x18b>
  4011fe:	48 8b 4c 24 20       	mov    0x20(%rsp),%rcx
  401203:	48 89 c5             	mov    %rax,%rbp
  401206:	48 8d 79 e8          	lea    -0x18(%rcx),%rdi
  40120a:	48 81 ff 80 21 60 00 	cmp    $0x602180,%rdi
  401211:	75 15                	jne    401228 <test1()+0x1f8>
  401213:	48 89 df             	mov    %rbx,%rdi
  401216:	48 89 eb             	mov    %rbp,%rbx
  400ea0:	ff 25 fa 11 20 00    	jmpq   *0x2011fa(%rip)        # 6020a0 <_GLOBAL_OFFSET_TABLE_+0xa0>
  400ea6:	68 11 00 00 00       	pushq  $0x11
  400eab:	e9 d0 fe ff ff       	jmpq   400d80 <_init+0x20>
  40121e:	e9 5b ff ff ff       	jmpq   40117e <test1()+0x14e>
  401223:	48 89 c5             	mov    %rax,%rbp
  401226:	eb eb                	jmp    401213 <test1()+0x1e3>
  401228:	ba 00 00 00 00       	mov    $0x0,%edx
  40122d:	48 8d 77 10          	lea    0x10(%rdi),%rsi
  401231:	48 85 d2             	test   %rdx,%rdx
  401234:	74 17                	je     40124d <test1()+0x21d>
  401236:	83 ca ff             	or     $0xffffffff,%edx
  401239:	f0 0f c1 16          	lock xadd %edx,(%rsi)
  40123d:	85 d2                	test   %edx,%edx
  40123f:	7f d2                	jg     401213 <test1()+0x1e3>
  401241:	48 8d 74 24 1f       	lea    0x1f(%rsp),%rsi
  400e10:	ff 25 42 12 20 00    	jmpq   *0x201242(%rip)        # 602058 <_GLOBAL_OFFSET_TABLE_+0x58>
  400e16:	68 08 00 00 00       	pushq  $0x8
  400e1b:	e9 60 ff ff ff       	jmpq   400d80 <_init+0x20>
  40124b:	eb c6                	jmp    401213 <test1()+0x1e3>
  40124d:	8b 51 f8             	mov    -0x8(%rcx),%edx
  401250:	8d 72 ff             	lea    -0x1(%rdx),%esi
  401253:	89 71 f8             	mov    %esi,-0x8(%rcx)
  401256:	eb e5                	jmp    40123d <test1()+0x20d>
  401258:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
