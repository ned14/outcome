  400f40:	55                   	push   %rbp
  400f41:	53                   	push   %rbx
  400f42:	48 83 ec 38          	sub    $0x38,%rsp
  400f46:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
  400f4b:	e8 b0 f0 bf ff       	callq  0 <_init-0x400c98>
  400f50:	80 7c 24 11 00       	cmpb   $0x0,0x11(%rsp)
  400f55:	74 11                	je     400f68 <test1()+0x28>
  400f57:	0f b6 44 24 10       	movzbl 0x10(%rsp),%eax
  400f5c:	48 83 c4 38          	add    $0x38,%rsp
  400f60:	5b                   	pop    %rbx
  400f61:	5d                   	pop    %rbp
  400f62:	c3                   	retq
  400f63:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
  400f68:	bf 20 00 00 00       	mov    $0x20,%edi
  400db0:	ff 25 d2 12 20 00    	jmpq   *0x2012d2(%rip)        # 602088 <_GLOBAL_OFFSET_TABLE_+0x88>
  400db6:	68 0e 00 00 00       	pushq  $0xe
  400dbb:	e9 00 ff ff ff       	jmpq   400cc0 <_init+0x28>
  400f72:	48 89 c3             	mov    %rax,%rbx
  400f75:	0f b6 05 1c 12 20 00 	movzbl 0x20121c(%rip),%eax        # 602198 <guard variable for boost::outcome::_1_0_std_std_9274c0d4::monad_category()::c>
  400f7c:	84 c0                	test   %al,%al
  400f7e:	74 60                	je     400fe0 <test1()+0xa0>
  400f80:	48 8d 54 24 0f       	lea    0xf(%rsp),%rdx
  400f85:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
  400f8a:	be 5c 12 40 00       	mov    $0x40125c,%esi
  400d90:	ff 25 e2 12 20 00    	jmpq   *0x2012e2(%rip)        # 602078 <_GLOBAL_OFFSET_TABLE_+0x78>
  400d96:	68 0c 00 00 00       	pushq  $0xc
  400d9b:	e9 20 ff ff ff       	jmpq   400cc0 <_init+0x28>
  400f94:	48 8d 74 24 20       	lea    0x20(%rsp),%rsi
  400f99:	48 89 df             	mov    %rbx,%rdi
  400d00:	ff 25 2a 13 20 00    	jmpq   *0x20132a(%rip)        # 602030 <_GLOBAL_OFFSET_TABLE_+0x30>
  400d06:	68 03 00 00 00       	pushq  $0x3
  400d0b:	e9 b0 ff ff ff       	jmpq   400cc0 <_init+0x28>
  400fa1:	48 8b 44 24 20       	mov    0x20(%rsp),%rax
  400fa6:	48 8d 78 e8          	lea    -0x18(%rax),%rdi
  400faa:	48 81 ff 60 21 60 00 	cmp    $0x602160,%rdi
  400fb1:	75 65                	jne    401018 <test1()+0xd8>
  400fb3:	ba d0 10 40 00       	mov    $0x4010d0,%edx
  400fb8:	be 18 13 40 00       	mov    $0x401318,%esi
  400fbd:	48 89 df             	mov    %rbx,%rdi
  400fc0:	c7 43 10 02 00 00 00 	movl   $0x2,0x10(%rbx)
  400fc7:	48 c7 43 18 d0 20 60 	movq   $0x6020d0,0x18(%rbx)
  400fcf:	48 c7 03 90 13 40 00 	movq   $0x401390,(%rbx)
  400dd0:	ff 25 c2 12 20 00    	jmpq   *0x2012c2(%rip)        # 602098 <_GLOBAL_OFFSET_TABLE_+0x98>
  400dd6:	68 10 00 00 00       	pushq  $0x10
  400ddb:	e9 e0 fe ff ff       	jmpq   400cc0 <_init+0x28>
  400fdb:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
  400fe0:	bf 98 21 60 00       	mov    $0x602198,%edi
  400cf0:	ff 25 32 13 20 00    	jmpq   *0x201332(%rip)        # 602028 <_GLOBAL_OFFSET_TABLE_+0x28>
  400cf6:	68 02 00 00 00       	pushq  $0x2
  400cfb:	e9 c0 ff ff ff       	jmpq   400cc0 <_init+0x28>
  400fea:	85 c0                	test   %eax,%eax
  400fec:	74 92                	je     400f80 <test1()+0x40>
  400fee:	bf 98 21 60 00       	mov    $0x602198,%edi
  400d70:	ff 25 f2 12 20 00    	jmpq   *0x2012f2(%rip)        # 602068 <_GLOBAL_OFFSET_TABLE_+0x68>
  400d76:	68 0a 00 00 00       	pushq  $0xa
  400d7b:	e9 40 ff ff ff       	jmpq   400cc0 <_init+0x28>
  400ff8:	ba c8 20 60 00       	mov    $0x6020c8,%edx
  400ffd:	be d0 20 60 00       	mov    $0x6020d0,%esi
  401002:	bf 00 11 40 00       	mov    $0x401100,%edi
  400d40:	ff 25 0a 13 20 00    	jmpq   *0x20130a(%rip)        # 602050 <_GLOBAL_OFFSET_TABLE_+0x50>
  400d46:	68 07 00 00 00       	pushq  $0x7
  400d4b:	e9 70 ff ff ff       	jmpq   400cc0 <_init+0x28>
  40100c:	e9 6f ff ff ff       	jmpq   400f80 <test1()+0x40>
  401011:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
  401018:	ba 00 00 00 00       	mov    $0x0,%edx
  40101d:	48 85 d2             	test   %rdx,%rdx
  401020:	74 1e                	je     401040 <test1()+0x100>
  401022:	ba ff ff ff ff       	mov    $0xffffffff,%edx
  401027:	f0 0f c1 50 f8       	lock xadd %edx,-0x8(%rax)
  40102c:	85 d2                	test   %edx,%edx
  40102e:	7f 83                	jg     400fb3 <test1()+0x73>
  401030:	48 8d 74 24 0f       	lea    0xf(%rsp),%rsi
  400d50:	ff 25 02 13 20 00    	jmpq   *0x201302(%rip)        # 602058 <_GLOBAL_OFFSET_TABLE_+0x58>
  400d56:	68 08 00 00 00       	pushq  $0x8
  400d5b:	e9 60 ff ff ff       	jmpq   400cc0 <_init+0x28>
  40103a:	e9 74 ff ff ff       	jmpq   400fb3 <test1()+0x73>
  40103f:	90                   	nop
  401040:	8b 50 f8             	mov    -0x8(%rax),%edx
  401043:	8d 4a ff             	lea    -0x1(%rdx),%ecx
  401046:	89 48 f8             	mov    %ecx,-0x8(%rax)
  401049:	eb e1                	jmp    40102c <test1()+0xec>
  40104b:	48 89 c5             	mov    %rax,%rbp
  40104e:	48 89 df             	mov    %rbx,%rdi
  400dc0:	ff 25 ca 12 20 00    	jmpq   *0x2012ca(%rip)        # 602090 <_GLOBAL_OFFSET_TABLE_+0x90>
  400dc6:	68 0f 00 00 00       	pushq  $0xf
  400dcb:	e9 f0 fe ff ff       	jmpq   400cc0 <_init+0x28>
  401056:	48 89 ef             	mov    %rbp,%rdi
  400e00:	ff 25 aa 12 20 00    	jmpq   *0x2012aa(%rip)        # 6020b0 <_GLOBAL_OFFSET_TABLE_+0xb0>
  400e06:	68 13 00 00 00       	pushq  $0x13
  400e0b:	e9 b0 fe ff ff       	jmpq   400cc0 <_init+0x28>
  40105e:	48 8b 4c 24 20       	mov    0x20(%rsp),%rcx
  401063:	48 89 c5             	mov    %rax,%rbp
  401066:	48 8d 79 e8          	lea    -0x18(%rcx),%rdi
  40106a:	48 81 ff 60 21 60 00 	cmp    $0x602160,%rdi
  401071:	74 db                	je     40104e <test1()+0x10e>
  401073:	ba 00 00 00 00       	mov    $0x0,%edx
  401078:	48 8d 77 10          	lea    0x10(%rdi),%rsi
  40107c:	48 85 d2             	test   %rdx,%rdx
  40107f:	74 17                	je     401098 <test1()+0x158>
  401081:	83 ca ff             	or     $0xffffffff,%edx
  401084:	f0 0f c1 16          	lock xadd %edx,(%rsi)
  401088:	85 d2                	test   %edx,%edx
  40108a:	7f c2                	jg     40104e <test1()+0x10e>
  40108c:	48 8d 74 24 0f       	lea    0xf(%rsp),%rsi
  400d50:	ff 25 02 13 20 00    	jmpq   *0x201302(%rip)        # 602058 <_GLOBAL_OFFSET_TABLE_+0x58>
  400d56:	68 08 00 00 00       	pushq  $0x8
  400d5b:	e9 60 ff ff ff       	jmpq   400cc0 <_init+0x28>
  401096:	eb b6                	jmp    40104e <test1()+0x10e>
  401098:	8b 51 f8             	mov    -0x8(%rcx),%edx
  40109b:	8d 72 ff             	lea    -0x1(%rdx),%esi
  40109e:	89 71 f8             	mov    %esi,-0x8(%rcx)
  4010a1:	eb e5                	jmp    401088 <test1()+0x148>
  4010a3:	66 66 66 66 2e 0f 1f 	data32 data32 data32 nopw %cs:0x0(%rax,%rax,1)
