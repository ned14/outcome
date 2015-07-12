   0:	48 83 ec 68          	sub    $0x68,%rsp
   4:	c6 44 24 40 00       	movb   $0x0,0x40(%rsp)
   9:	c6 44 24 48 00       	movb   $0x0,0x48(%rsp)
   e:	c6 44 24 4a 00       	movb   $0x0,0x4a(%rsp)
  13:	48 c7 44 24 50 00 00 	movq   $0x0,0x50(%rsp)
  1a:	00 00 
  1c:	48 8d 7c 24 58       	lea    0x58(%rsp),%rdi
  21:	48 8d 74 24 30       	lea    0x30(%rsp),%rsi
  26:	e8 00 00 00 00       	callq  2b <_Z5test1v+0x2b>
  2b:	48 83 7c 24 58 00    	cmpq   $0x0,0x58(%rsp)
  31:	74 09                	je     3c <_Z5test1v+0x3c>
  33:	48 c7 44 24 58 00 00 	movq   $0x0,0x58(%rsp)
  3a:	00 00 
  3c:	48 83 7c 24 60 00    	cmpq   $0x0,0x60(%rsp)
  42:	74 09                	je     4d <_Z5test1v+0x4d>
  44:	48 c7 44 24 60 00 00 	movq   $0x0,0x60(%rsp)
  4b:	00 00 
  4d:	c6 44 24 10 00       	movb   $0x0,0x10(%rsp)
  52:	0f b6 44 24 40       	movzbl 0x40(%rsp),%eax
  57:	83 f8 03             	cmp    $0x3,%eax
  5a:	74 10                	je     6c <_Z5test1v+0x6c>
  5c:	83 f8 02             	cmp    $0x2,%eax
  5f:	75 1f                	jne    80 <_Z5test1v+0x80>
  61:	0f 10 44 24 30       	movups 0x30(%rsp),%xmm0
  66:	0f 29 04 24          	movaps %xmm0,(%rsp)
  6a:	eb 20                	jmp    8c <_Z5test1v+0x8c>
  6c:	48 8b 4c 24 30       	mov    0x30(%rsp),%rcx
  71:	48 89 0c 24          	mov    %rcx,(%rsp)
  75:	48 c7 44 24 30 00 00 	movq   $0x0,0x30(%rsp)
  7c:	00 00 
  7e:	eb 0c                	jmp    8c <_Z5test1v+0x8c>
  80:	83 f8 01             	cmp    $0x1,%eax
  83:	75 07                	jne    8c <_Z5test1v+0x8c>
  85:	8b 4c 24 30          	mov    0x30(%rsp),%ecx
  89:	89 0c 24             	mov    %ecx,(%rsp)
  8c:	88 44 24 10          	mov    %al,0x10(%rsp)
  90:	8b 44 24 48          	mov    0x48(%rsp),%eax
  94:	88 44 24 18          	mov    %al,0x18(%rsp)
  98:	89 c1                	mov    %eax,%ecx
  9a:	c1 e9 10             	shr    $0x10,%ecx
  9d:	88 4c 24 1a          	mov    %cl,0x1a(%rsp)
  a1:	48 8b 4c 24 50       	mov    0x50(%rsp),%rcx
  a6:	48 89 4c 24 20       	mov    %rcx,0x20(%rsp)
  ab:	84 c0                	test   %al,%al
  ad:	74 05                	je     b4 <_Z5test1v+0xb4>
  af:	c6 44 24 19 00       	movb   $0x0,0x19(%rsp)
  b4:	48 c7 44 24 50 00 00 	movq   $0x0,0x50(%rsp)
  bb:	00 00 
  bd:	48 85 c9             	test   %rcx,%rcx
  c0:	74 08                	je     ca <_Z5test1v+0xca>
  c2:	48 8d 14 24          	lea    (%rsp),%rdx
  c6:	48 89 51 20          	mov    %rdx,0x20(%rcx)
  ca:	84 c0                	test   %al,%al
  cc:	74 13                	je     e1 <_Z5test1v+0xe1>
  ce:	c6 44 24 49 00       	movb   $0x0,0x49(%rsp)
  d3:	48 8b 44 24 20       	mov    0x20(%rsp),%rax
  d8:	48 85 c0             	test   %rax,%rax
  db:	74 04                	je     e1 <_Z5test1v+0xe1>
  dd:	c6 40 19 00          	movb   $0x0,0x19(%rax)
  e1:	48 8d 3c 24          	lea    (%rsp),%rdi
  e5:	e8 00 00 00 00       	callq  ea <_Z5test1v+0xea>
  ea:	48 8d 7c 24 30       	lea    0x30(%rsp),%rdi
  ef:	e8 00 00 00 00       	callq  f4 <_Z5test1v+0xf4>
  f4:	48 83 c4 68          	add    $0x68,%rsp
  f8:	c3                   	retq   
  f9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
