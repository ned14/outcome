   0:	53                   	push   %rbx
   1:	48 83 ec 20          	sub    $0x20,%rsp
   5:	48 89 fb             	mov    %rdi,%rbx
   8:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
   d:	e8 00 00 00 00       	callq  12 <_Z5test1v+0x12>
  12:	0f b6 4c 24 18       	movzbl 0x18(%rsp),%ecx
  17:	83 f9 02             	cmp    $0x2,%ecx
  1a:	75 0e                	jne    2a <_Z5test1v+0x2a>
  1c:	0f 10 44 24 08       	movups 0x8(%rsp),%xmm0
  21:	0f 11 03             	movups %xmm0,(%rbx)
  24:	c6 43 10 02          	movb   $0x2,0x10(%rbx)
  28:	eb 64                	jmp    8e <_Z5test1v+0x8e>
  2a:	0f b6 c1             	movzbl %cl,%eax
  2d:	83 f8 01             	cmp    $0x1,%eax
  30:	75 0d                	jne    3f <_Z5test1v+0x3f>
  32:	6b 44 24 08 03       	imul   $0x3,0x8(%rsp),%eax
  37:	89 03                	mov    %eax,(%rbx)
  39:	c6 43 10 01          	movb   $0x1,0x10(%rbx)
  3d:	eb 4f                	jmp    8e <_Z5test1v+0x8e>
  3f:	80 e1 fe             	and    $0xfe,%cl
  42:	0f b6 c9             	movzbl %cl,%ecx
  45:	83 f9 02             	cmp    $0x2,%ecx
  48:	75 17                	jne    61 <_Z5test1v+0x61>
  4a:	48 8b 4c 24 08       	mov    0x8(%rsp),%rcx
  4f:	48 89 0b             	mov    %rcx,(%rbx)
  52:	48 c7 44 24 08 00 00 	movq   $0x0,0x8(%rsp)
  59:	00 00 
  5b:	c6 43 10 03          	movb   $0x3,0x10(%rbx)
  5f:	eb 0e                	jmp    6f <_Z5test1v+0x6f>
  61:	0f 57 c0             	xorps  %xmm0,%xmm0
  64:	0f 11 03             	movups %xmm0,(%rbx)
  67:	48 c7 43 10 00 00 00 	movq   $0x0,0x10(%rbx)
  6e:	00 
  6f:	83 f8 04             	cmp    $0x4,%eax
  72:	75 0b                	jne    7f <_Z5test1v+0x7f>
  74:	48 c7 44 24 08 00 00 	movq   $0x0,0x8(%rsp)
  7b:	00 00 
  7d:	eb 0f                	jmp    8e <_Z5test1v+0x8e>
  7f:	83 f8 03             	cmp    $0x3,%eax
  82:	75 0f                	jne    93 <_Z5test1v+0x93>
  84:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  89:	e8 00 00 00 00       	callq  8e <_Z5test1v+0x8e>
  8e:	c6 44 24 18 00       	movb   $0x0,0x18(%rsp)
  93:	48 89 d8             	mov    %rbx,%rax
  96:	48 83 c4 20          	add    $0x20,%rsp
  9a:	5b                   	pop    %rbx
  9b:	c3                   	retq   
  9c:	0f 1f 40 00          	nopl   0x0(%rax)
