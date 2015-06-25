   8:	53                   	push   %rbx
   9:	48 83 ec 20          	sub    $0x20,%rsp
   d:	48 89 fb             	mov    %rdi,%rbx
  10:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  15:	e8 00 00 00 00       	callq  1a <_Z5test1v+0x12>
  1a:	0f b6 4c 24 18       	movzbl 0x18(%rsp),%ecx
  1f:	83 f9 02             	cmp    $0x2,%ecx
  22:	75 0e                	jne    32 <_Z5test1v+0x2a>
  24:	0f 10 44 24 08       	movups 0x8(%rsp),%xmm0
  29:	0f 11 03             	movups %xmm0,(%rbx)
  2c:	c6 43 10 02          	movb   $0x2,0x10(%rbx)
  30:	eb 59                	jmp    8b <_Z5test1v+0x83>
  32:	0f b6 c1             	movzbl %cl,%eax
  35:	83 f8 01             	cmp    $0x1,%eax
  38:	75 0d                	jne    47 <_Z5test1v+0x3f>
  3a:	6b 44 24 08 03       	imul   $0x3,0x8(%rsp),%eax
  3f:	89 03                	mov    %eax,(%rbx)
  41:	c6 43 10 01          	movb   $0x1,0x10(%rbx)
  45:	eb 44                	jmp    8b <_Z5test1v+0x83>
  47:	80 e1 fe             	and    $0xfe,%cl
  4a:	0f b6 c9             	movzbl %cl,%ecx
  4d:	83 f9 02             	cmp    $0x2,%ecx
  50:	75 17                	jne    69 <_Z5test1v+0x61>
  52:	48 8b 4c 24 08       	mov    0x8(%rsp),%rcx
  57:	48 89 0b             	mov    %rcx,(%rbx)
  5a:	48 c7 44 24 08 00 00 	movq   $0x0,0x8(%rsp)
  61:	00 00 
  63:	c6 43 10 03          	movb   $0x3,0x10(%rbx)
  67:	eb 0e                	jmp    77 <_Z5test1v+0x6f>
  69:	0f 57 c0             	xorps  %xmm0,%xmm0
  6c:	0f 11 03             	movups %xmm0,(%rbx)
  6f:	48 c7 43 10 00 00 00 	movq   $0x0,0x10(%rbx)
  76:	00 
  77:	83 f8 04             	cmp    $0x4,%eax
  7a:	74 0f                	je     8b <_Z5test1v+0x83>
  7c:	83 f8 03             	cmp    $0x3,%eax
  7f:	75 0f                	jne    90 <_Z5test1v+0x88>
  81:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  86:	e8 00 00 00 00       	callq  8b <_Z5test1v+0x83>
  8b:	c6 44 24 18 00       	movb   $0x0,0x18(%rsp)
  90:	48 89 d8             	mov    %rbx,%rax
  93:	48 83 c4 20          	add    $0x20,%rsp
  97:	5b                   	pop    %rbx
  98:	c3                   	retq   
  99:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
