   0:	48 83 ec 78          	sub    $0x78,%rsp
   4:	c6 44 24 50 00       	movb   $0x0,0x50(%rsp)
   9:	c6 44 24 58 00       	movb   $0x0,0x58(%rsp)
   e:	c6 44 24 5a 00       	movb   $0x0,0x5a(%rsp)
  13:	48 c7 44 24 60 00 00 	movq   $0x0,0x60(%rsp)
  1a:	00 00 
  1c:	48 c7 44 24 38 00 00 	movq   $0x0,0x38(%rsp)
  23:	00 00 
  25:	48 c7 44 24 08 00 00 	movq   $0x0,0x8(%rsp)
  2c:	00 00 
  2e:	48 8d 7c 24 68       	lea    0x68(%rsp),%rdi
  33:	48 8d 74 24 38       	lea    0x38(%rsp),%rsi
  38:	e8 00 00 00 00       	callq  3d <_Z5test1v+0x3d>
  3d:	48 83 7c 24 68 00    	cmpq   $0x0,0x68(%rsp)
  43:	74 09                	je     4e <_Z5test1v+0x4e>
  45:	48 c7 44 24 68 00 00 	movq   $0x0,0x68(%rsp)
  4c:	00 00 
  4e:	48 83 7c 24 70 00    	cmpq   $0x0,0x70(%rsp)
  54:	74 09                	je     5f <_Z5test1v+0x5f>
  56:	48 c7 44 24 70 00 00 	movq   $0x0,0x70(%rsp)
  5d:	00 00 
  5f:	c6 44 24 20 00       	movb   $0x0,0x20(%rsp)
  64:	0f b6 44 24 50       	movzbl 0x50(%rsp),%eax
  69:	83 f8 03             	cmp    $0x3,%eax
  6c:	74 17                	je     85 <_Z5test1v+0x85>
  6e:	83 f8 02             	cmp    $0x2,%eax
  71:	75 27                	jne    9a <_Z5test1v+0x9a>
  73:	48 8d 4c 24 10       	lea    0x10(%rsp),%rcx
  78:	48 8d 54 24 40       	lea    0x40(%rsp),%rdx
  7d:	0f 10 02             	movups (%rdx),%xmm0
  80:	0f 11 01             	movups %xmm0,(%rcx)
  83:	eb 22                	jmp    a7 <_Z5test1v+0xa7>
  85:	48 8b 4c 24 40       	mov    0x40(%rsp),%rcx
  8a:	48 89 4c 24 10       	mov    %rcx,0x10(%rsp)
  8f:	48 c7 44 24 40 00 00 	movq   $0x0,0x40(%rsp)
  96:	00 00 
  98:	eb 0d                	jmp    a7 <_Z5test1v+0xa7>
  9a:	83 f8 01             	cmp    $0x1,%eax
  9d:	75 08                	jne    a7 <_Z5test1v+0xa7>
  9f:	8b 4c 24 40          	mov    0x40(%rsp),%ecx
  a3:	89 4c 24 10          	mov    %ecx,0x10(%rsp)
  a7:	88 44 24 20          	mov    %al,0x20(%rsp)
  ab:	8b 44 24 58          	mov    0x58(%rsp),%eax
  af:	88 44 24 28          	mov    %al,0x28(%rsp)
  b3:	89 c1                	mov    %eax,%ecx
  b5:	c1 e9 10             	shr    $0x10,%ecx
  b8:	88 4c 24 2a          	mov    %cl,0x2a(%rsp)
  bc:	48 8b 4c 24 60       	mov    0x60(%rsp),%rcx
  c1:	48 89 4c 24 30       	mov    %rcx,0x30(%rsp)
  c6:	84 c0                	test   %al,%al
  c8:	74 2c                	je     f6 <_Z5test1v+0xf6>
  ca:	c6 44 24 29 00       	movb   $0x0,0x29(%rsp)
  cf:	48 c7 44 24 60 00 00 	movq   $0x0,0x60(%rsp)
  d6:	00 00 
  d8:	48 c7 44 24 08 00 00 	movq   $0x0,0x8(%rsp)
  df:	00 00 
  e1:	c6 44 24 59 00       	movb   $0x0,0x59(%rsp)
  e6:	48 8b 44 24 30       	mov    0x30(%rsp),%rax
  eb:	48 85 c0             	test   %rax,%rax
  ee:	74 18                	je     108 <_Z5test1v+0x108>
  f0:	c6 40 21 00          	movb   $0x0,0x21(%rax)
  f4:	eb 12                	jmp    108 <_Z5test1v+0x108>
  f6:	48 c7 44 24 60 00 00 	movq   $0x0,0x60(%rsp)
  fd:	00 00 
  ff:	48 c7 44 24 08 00 00 	movq   $0x0,0x8(%rsp)
 106:	00 00 
 108:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
 10d:	e8 00 00 00 00       	callq  112 <_Z5test1v+0x112>
 112:	48 8d 7c 24 38       	lea    0x38(%rsp),%rdi
 117:	e8 00 00 00 00       	callq  11c <_Z5test1v+0x11c>
 11c:	48 83 c4 78          	add    $0x78,%rsp
 120:	c3                   	retq   
 121:	66 66 66 66 66 66 2e 	data32 data32 data32 data32 data32 nopw %cs:0x0(%rax,%rax,1)
 128:	0f 1f 84 00 00 00 00 
 12f:	00 
