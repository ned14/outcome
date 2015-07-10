   0:	53                   	push   %rbx
   1:	48 83 ec 20          	sub    $0x20,%rsp
   5:	48 89 fb             	mov    %rdi,%rbx
   8:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
   d:	e8 00 00 00 00       	callq  12 <_Z5test1v+0x12>
  12:	0f b6 44 24 18       	movzbl 0x18(%rsp),%eax
  17:	83 f8 03             	cmp    $0x3,%eax
  1a:	74 16                	je     32 <_Z5test1v+0x32>
  1c:	0f b6 c8             	movzbl %al,%ecx
  1f:	83 f9 02             	cmp    $0x2,%ecx
  22:	75 25                	jne    49 <_Z5test1v+0x49>
  24:	0f 10 44 24 08       	movups 0x8(%rsp),%xmm0
  29:	0f 11 03             	movups %xmm0,(%rbx)
  2c:	c6 43 10 02          	movb   $0x2,0x10(%rbx)
  30:	eb 37                	jmp    69 <_Z5test1v+0x69>
  32:	48 8b 4c 24 08       	mov    0x8(%rsp),%rcx
  37:	48 89 0b             	mov    %rcx,(%rbx)
  3a:	48 c7 44 24 08 00 00 	movq   $0x0,0x8(%rsp)
  41:	00 00 
  43:	c6 43 10 03          	movb   $0x3,0x10(%rbx)
  47:	eb 20                	jmp    69 <_Z5test1v+0x69>
  49:	83 f9 01             	cmp    $0x1,%ecx
  4c:	75 0d                	jne    5b <_Z5test1v+0x5b>
  4e:	6b 4c 24 08 03       	imul   $0x3,0x8(%rsp),%ecx
  53:	89 0b                	mov    %ecx,(%rbx)
  55:	c6 43 10 01          	movb   $0x1,0x10(%rbx)
  59:	eb 0e                	jmp    69 <_Z5test1v+0x69>
  5b:	0f 57 c0             	xorps  %xmm0,%xmm0
  5e:	0f 11 03             	movups %xmm0,(%rbx)
  61:	48 c7 43 10 00 00 00 	movq   $0x0,0x10(%rbx)
  68:	00 
  69:	83 f8 03             	cmp    $0x3,%eax
  6c:	74 0c                	je     7a <_Z5test1v+0x7a>
  6e:	83 f8 02             	cmp    $0x2,%eax
  71:	74 11                	je     84 <_Z5test1v+0x84>
  73:	83 f8 01             	cmp    $0x1,%eax
  76:	74 0c                	je     84 <_Z5test1v+0x84>
  78:	eb 0f                	jmp    89 <_Z5test1v+0x89>
  7a:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  7f:	e8 00 00 00 00       	callq  84 <_Z5test1v+0x84>
  84:	c6 44 24 18 00       	movb   $0x0,0x18(%rsp)
  89:	48 89 d8             	mov    %rbx,%rax
  8c:	48 83 c4 20          	add    $0x20,%rsp
  90:	5b                   	pop    %rbx
  91:	c3                   	retq   
  92:	66 66 66 66 66 2e 0f 	data32 data32 data32 data32 nopw %cs:0x0(%rax,%rax,1)
  99:	1f 84 00 00 00 00 00 
