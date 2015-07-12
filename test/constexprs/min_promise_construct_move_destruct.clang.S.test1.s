   0:	48 81 ec 88 00 00 00 	sub    $0x88,%rsp
   7:	c6 44 24 58 00       	movb   $0x0,0x58(%rsp)
   c:	c6 44 24 60 00       	movb   $0x0,0x60(%rsp)
  11:	c6 44 24 62 00       	movb   $0x0,0x62(%rsp)
  16:	0f 57 c0             	xorps  %xmm0,%xmm0
  19:	0f 11 44 24 78       	movups %xmm0,0x78(%rsp)
  1e:	0f 11 44 24 68       	movups %xmm0,0x68(%rsp)
  23:	48 8d 7c 24 48       	lea    0x48(%rsp),%rdi
  28:	e8 00 00 00 00       	callq  2d <_Z5test1v+0x2d>
  2d:	c6 44 24 10 00       	movb   $0x0,0x10(%rsp)
  32:	0f b6 44 24 58       	movzbl 0x58(%rsp),%eax
  37:	83 f8 03             	cmp    $0x3,%eax
  3a:	74 10                	je     4c <_Z5test1v+0x4c>
  3c:	83 f8 02             	cmp    $0x2,%eax
  3f:	75 1f                	jne    60 <_Z5test1v+0x60>
  41:	0f 10 44 24 48       	movups 0x48(%rsp),%xmm0
  46:	0f 29 04 24          	movaps %xmm0,(%rsp)
  4a:	eb 20                	jmp    6c <_Z5test1v+0x6c>
  4c:	48 8b 4c 24 48       	mov    0x48(%rsp),%rcx
  51:	48 89 0c 24          	mov    %rcx,(%rsp)
  55:	48 c7 44 24 48 00 00 	movq   $0x0,0x48(%rsp)
  5c:	00 00 
  5e:	eb 0c                	jmp    6c <_Z5test1v+0x6c>
  60:	83 f8 01             	cmp    $0x1,%eax
  63:	75 07                	jne    6c <_Z5test1v+0x6c>
  65:	8b 4c 24 48          	mov    0x48(%rsp),%ecx
  69:	89 0c 24             	mov    %ecx,(%rsp)
  6c:	88 44 24 10          	mov    %al,0x10(%rsp)
  70:	8b 44 24 60          	mov    0x60(%rsp),%eax
  74:	88 44 24 18          	mov    %al,0x18(%rsp)
  78:	89 c1                	mov    %eax,%ecx
  7a:	c1 e9 10             	shr    $0x10,%ecx
  7d:	88 4c 24 1a          	mov    %cl,0x1a(%rsp)
  81:	48 8b 4c 24 68       	mov    0x68(%rsp),%rcx
  86:	48 89 4c 24 20       	mov    %rcx,0x20(%rsp)
  8b:	84 c0                	test   %al,%al
  8d:	74 05                	je     94 <_Z5test1v+0x94>
  8f:	c6 44 24 19 00       	movb   $0x0,0x19(%rsp)
  94:	48 c7 44 24 68 00 00 	movq   $0x0,0x68(%rsp)
  9b:	00 00 
  9d:	48 85 c9             	test   %rcx,%rcx
  a0:	74 08                	je     aa <_Z5test1v+0xaa>
  a2:	48 8d 14 24          	lea    (%rsp),%rdx
  a6:	48 89 51 20          	mov    %rdx,0x20(%rcx)
  aa:	84 c0                	test   %al,%al
  ac:	0f 10 44 24 70       	movups 0x70(%rsp),%xmm0
  b1:	48 c7 44 24 78 00 00 	movq   $0x0,0x78(%rsp)
  b8:	00 00 
  ba:	48 8b 84 24 80 00 00 	mov    0x80(%rsp),%rax
  c1:	00 
  c2:	48 c7 84 24 80 00 00 	movq   $0x0,0x80(%rsp)
  c9:	00 00 00 00 00 
  ce:	48 89 44 24 38       	mov    %rax,0x38(%rsp)
  d3:	0f 11 44 24 28       	movups %xmm0,0x28(%rsp)
  d8:	74 13                	je     ed <_Z5test1v+0xed>
  da:	c6 44 24 61 00       	movb   $0x0,0x61(%rsp)
  df:	48 8b 44 24 20       	mov    0x20(%rsp),%rax
  e4:	48 85 c0             	test   %rax,%rax
  e7:	74 04                	je     ed <_Z5test1v+0xed>
  e9:	c6 40 19 00          	movb   $0x0,0x19(%rax)
  ed:	48 8d 3c 24          	lea    (%rsp),%rdi
  f1:	e8 00 00 00 00       	callq  f6 <_Z5test1v+0xf6>
  f6:	48 8d 7c 24 48       	lea    0x48(%rsp),%rdi
  fb:	e8 00 00 00 00       	callq  100 <_Z5test1v+0x100>
 100:	48 81 c4 88 00 00 00 	add    $0x88,%rsp
 107:	c3                   	retq   
 108:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
 10f:	00 
