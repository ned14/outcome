   0:	53                   	push   %rbx
   1:	48 83 ec 20          	sub    $0x20,%rsp
   5:	48 89 fb             	mov    %rdi,%rbx
   8:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
   d:	e8 00 00 00 00       	callq  12 <_Z5test1v+0x12>
  12:	0f b6 44 24 18       	movzbl 0x18(%rsp),%eax
  17:	83 f8 03             	cmp    $0x3,%eax
  1a:	74 16                	je     32 <_Z5test1v+0x32>
  1c:	0f b6 c0             	movzbl %al,%eax
  1f:	83 f8 02             	cmp    $0x2,%eax
  22:	75 2f                	jne    53 <_Z5test1v+0x53>
  24:	0f 10 44 24 08       	movups 0x8(%rsp),%xmm0
  29:	0f 11 03             	movups %xmm0,(%rbx)
  2c:	c6 43 10 02          	movb   $0x2,0x10(%rbx)
  30:	eb 46                	jmp    78 <_Z5test1v+0x78>
  32:	48 8b 44 24 08       	mov    0x8(%rsp),%rax
  37:	48 89 03             	mov    %rax,(%rbx)
  3a:	48 c7 44 24 08 00 00 	movq   $0x0,0x8(%rsp)
  41:	00 00 
  43:	c6 43 10 03          	movb   $0x3,0x10(%rbx)
  47:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  4c:	e8 00 00 00 00       	callq  51 <_Z5test1v+0x51>
  51:	eb 25                	jmp    78 <_Z5test1v+0x78>
  53:	83 f8 01             	cmp    $0x1,%eax
  56:	75 0d                	jne    65 <_Z5test1v+0x65>
  58:	6b 44 24 08 03       	imul   $0x3,0x8(%rsp),%eax
  5d:	89 03                	mov    %eax,(%rbx)
  5f:	c6 43 10 01          	movb   $0x1,0x10(%rbx)
  63:	eb 13                	jmp    78 <_Z5test1v+0x78>
  65:	0f 57 c0             	xorps  %xmm0,%xmm0
  68:	0f 11 03             	movups %xmm0,(%rbx)
  6b:	48 c7 43 10 00 00 00 	movq   $0x0,0x10(%rbx)
  72:	00 
  73:	83 f8 04             	cmp    $0x4,%eax
  76:	75 05                	jne    7d <_Z5test1v+0x7d>
  78:	c6 44 24 18 00       	movb   $0x0,0x18(%rsp)
  7d:	48 89 d8             	mov    %rbx,%rax
  80:	48 83 c4 20          	add    $0x20,%rsp
  84:	5b                   	pop    %rbx
  85:	c3                   	retq   
  86:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
  8d:	00 00 00 
