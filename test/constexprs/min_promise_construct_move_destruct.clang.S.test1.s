   0:	48 81 ec a8 00 00 00 	sub    $0xa8,%rsp
   7:	c6 44 24 70 00       	movb   $0x0,0x70(%rsp)
   c:	c6 44 24 78 00       	movb   $0x0,0x78(%rsp)
  11:	c6 44 24 7a 00       	movb   $0x0,0x7a(%rsp)
  16:	0f 57 c0             	xorps  %xmm0,%xmm0
  19:	0f 11 84 24 90 00 00 	movups %xmm0,0x90(%rsp)
  20:	00 
  21:	0f 11 84 24 80 00 00 	movups %xmm0,0x80(%rsp)
  28:	00 
  29:	48 c7 84 24 a0 00 00 	movq   $0x0,0xa0(%rsp)
  30:	00 00 00 00 00 
  35:	48 c7 44 24 58 00 00 	movq   $0x0,0x58(%rsp)
  3c:	00 00 
  3e:	48 c7 44 24 08 00 00 	movq   $0x0,0x8(%rsp)
  45:	00 00 
  47:	48 8d 7c 24 58       	lea    0x58(%rsp),%rdi
  4c:	e8 00 00 00 00       	callq  51 <_Z5test1v+0x51>
  51:	c6 44 24 20 00       	movb   $0x0,0x20(%rsp)
  56:	0f b6 44 24 70       	movzbl 0x70(%rsp),%eax
  5b:	83 f8 03             	cmp    $0x3,%eax
  5e:	74 17                	je     77 <_Z5test1v+0x77>
  60:	83 f8 02             	cmp    $0x2,%eax
  63:	75 27                	jne    8c <_Z5test1v+0x8c>
  65:	48 8d 4c 24 60       	lea    0x60(%rsp),%rcx
  6a:	48 8d 54 24 10       	lea    0x10(%rsp),%rdx
  6f:	0f 10 01             	movups (%rcx),%xmm0
  72:	0f 11 02             	movups %xmm0,(%rdx)
  75:	eb 22                	jmp    99 <_Z5test1v+0x99>
  77:	48 8b 4c 24 60       	mov    0x60(%rsp),%rcx
  7c:	48 89 4c 24 10       	mov    %rcx,0x10(%rsp)
  81:	48 c7 44 24 60 00 00 	movq   $0x0,0x60(%rsp)
  88:	00 00 
  8a:	eb 0d                	jmp    99 <_Z5test1v+0x99>
  8c:	83 f8 01             	cmp    $0x1,%eax
  8f:	75 08                	jne    99 <_Z5test1v+0x99>
  91:	8b 4c 24 60          	mov    0x60(%rsp),%ecx
  95:	89 4c 24 10          	mov    %ecx,0x10(%rsp)
  99:	88 44 24 20          	mov    %al,0x20(%rsp)
  9d:	8b 44 24 78          	mov    0x78(%rsp),%eax
  a1:	88 44 24 28          	mov    %al,0x28(%rsp)
  a5:	89 c1                	mov    %eax,%ecx
  a7:	c1 e9 10             	shr    $0x10,%ecx
  aa:	88 4c 24 2a          	mov    %cl,0x2a(%rsp)
  ae:	48 8b 8c 24 80 00 00 	mov    0x80(%rsp),%rcx
  b5:	00 
  b6:	48 89 4c 24 30       	mov    %rcx,0x30(%rsp)
  bb:	84 c0                	test   %al,%al
  bd:	74 05                	je     c4 <_Z5test1v+0xc4>
  bf:	c6 44 24 29 00       	movb   $0x0,0x29(%rsp)
  c4:	84 c0                	test   %al,%al
  c6:	48 c7 84 24 80 00 00 	movq   $0x0,0x80(%rsp)
  cd:	00 00 00 00 00 
  d2:	0f 10 84 24 88 00 00 	movups 0x88(%rsp),%xmm0
  d9:	00 
  da:	48 c7 84 24 90 00 00 	movq   $0x0,0x90(%rsp)
  e1:	00 00 00 00 00 
  e6:	0f 10 8c 24 98 00 00 	movups 0x98(%rsp),%xmm1
  ed:	00 
  ee:	48 c7 84 24 a0 00 00 	movq   $0x0,0xa0(%rsp)
  f5:	00 00 00 00 00 
  fa:	0f 11 4c 24 48       	movups %xmm1,0x48(%rsp)
  ff:	48 c7 84 24 98 00 00 	movq   $0x0,0x98(%rsp)
 106:	00 00 00 00 00 
 10b:	0f 11 44 24 38       	movups %xmm0,0x38(%rsp)
 110:	48 c7 44 24 08 00 00 	movq   $0x0,0x8(%rsp)
 117:	00 00 
 119:	74 13                	je     12e <_Z5test1v+0x12e>
 11b:	c6 44 24 79 00       	movb   $0x0,0x79(%rsp)
 120:	48 8b 44 24 30       	mov    0x30(%rsp),%rax
 125:	48 85 c0             	test   %rax,%rax
 128:	74 04                	je     12e <_Z5test1v+0x12e>
 12a:	c6 40 21 00          	movb   $0x0,0x21(%rax)
 12e:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
 133:	e8 00 00 00 00       	callq  138 <_Z5test1v+0x138>
 138:	48 8d 7c 24 58       	lea    0x58(%rsp),%rdi
 13d:	e8 00 00 00 00       	callq  142 <_Z5test1v+0x142>
 142:	48 81 c4 a8 00 00 00 	add    $0xa8,%rsp
 149:	c3                   	retq   
 14a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
