   0:	53                   	push   %rbx
   1:	48 83 ec 20          	sub    $0x20,%rsp
   5:	48 89 fb             	mov    %rdi,%rbx
   8:	48 8d 3c 24          	lea    (%rsp),%rdi
   c:	e8 00 00 00 00       	callq  11 <_Z5test1v+0x11>
  11:	0f b6 44 24 18       	movzbl 0x18(%rsp),%eax
  16:	83 f8 03             	cmp    $0x3,%eax
  19:	74 19                	je     34 <_Z5test1v+0x34>
  1b:	0f b6 c8             	movzbl %al,%ecx
  1e:	83 f9 02             	cmp    $0x2,%ecx
  21:	74 26                	je     49 <_Z5test1v+0x49>
  23:	83 f9 01             	cmp    $0x1,%ecx
  26:	75 37                	jne    5f <_Z5test1v+0x5f>
  28:	6b 0c 24 03          	imul   $0x3,(%rsp),%ecx
  2c:	89 0b                	mov    %ecx,(%rbx)
  2e:	c6 43 18 01          	movb   $0x1,0x18(%rbx)
  32:	eb 35                	jmp    69 <_Z5test1v+0x69>
  34:	48 8b 0c 24          	mov    (%rsp),%rcx
  38:	48 89 0b             	mov    %rcx,(%rbx)
  3b:	48 c7 04 24 00 00 00 	movq   $0x0,(%rsp)
  42:	00 
  43:	c6 43 18 03          	movb   $0x3,0x18(%rbx)
  47:	eb 20                	jmp    69 <_Z5test1v+0x69>
  49:	48 8b 4c 24 10       	mov    0x10(%rsp),%rcx
  4e:	48 89 4b 10          	mov    %rcx,0x10(%rbx)
  52:	0f 10 04 24          	movups (%rsp),%xmm0
  56:	0f 11 03             	movups %xmm0,(%rbx)
  59:	c6 43 18 02          	movb   $0x2,0x18(%rbx)
  5d:	eb 0a                	jmp    69 <_Z5test1v+0x69>
  5f:	0f 57 c0             	xorps  %xmm0,%xmm0
  62:	0f 11 43 10          	movups %xmm0,0x10(%rbx)
  66:	0f 11 03             	movups %xmm0,(%rbx)
  69:	83 f8 03             	cmp    $0x3,%eax
  6c:	74 0c                	je     7a <_Z5test1v+0x7a>
  6e:	83 f8 02             	cmp    $0x2,%eax
  71:	74 10                	je     83 <_Z5test1v+0x83>
  73:	83 f8 01             	cmp    $0x1,%eax
  76:	74 0b                	je     83 <_Z5test1v+0x83>
  78:	eb 0e                	jmp    88 <_Z5test1v+0x88>
  7a:	48 8d 3c 24          	lea    (%rsp),%rdi
  7e:	e8 00 00 00 00       	callq  83 <_Z5test1v+0x83>
  83:	c6 44 24 18 00       	movb   $0x0,0x18(%rsp)
  88:	48 89 d8             	mov    %rbx,%rax
  8b:	48 83 c4 20          	add    $0x20,%rsp
  8f:	5b                   	pop    %rbx
  90:	c3                   	retq   
  91:	66 66 66 66 66 66 2e 	data16 data16 data16 data16 data16 nopw %cs:0x0(%rax,%rax,1)
  98:	0f 1f 84 00 00 00 00 
  9f:	00 
