   0:	55                   	push   %rbp
   1:	53                   	push   %rbx
   2:	48 83 ec 28          	sub    $0x28,%rsp
   6:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
   b:	e8 00 00 00 00       	callq  10 <_Z5test1v+0x10>
  10:	0f b6 44 24 20       	movzbl 0x20(%rsp),%eax
  15:	83 f8 02             	cmp    $0x2,%eax
  18:	74 6e                	je     88 <_Z5test1v+0x88>
  1a:	0f b6 c8             	movzbl %al,%ecx
  1d:	83 f9 03             	cmp    $0x3,%ecx
  20:	74 10                	je     32 <_Z5test1v+0x32>
  22:	84 c0                	test   %al,%al
  24:	74 58                	je     7e <_Z5test1v+0x7e>
  26:	31 ed                	xor    %ebp,%ebp
  28:	e8 00 00 00 00       	callq  2d <_Z5test1v+0x2d>
  2d:	48 89 c3             	mov    %rax,%rbx
  30:	eb 5f                	jmp    91 <_Z5test1v+0x91>
  32:	8a 05 00 00 00 00    	mov    0x0(%rip),%al        # 38 <_Z5test1v+0x38>
  38:	bb 00 00 00 00       	mov    $0x0,%ebx
  3d:	bd 03 00 00 00       	mov    $0x3,%ebp
  42:	84 c0                	test   %al,%al
  44:	75 4b                	jne    91 <_Z5test1v+0x91>
  46:	bf 00 00 00 00       	mov    $0x0,%edi
  4b:	e8 00 00 00 00       	callq  50 <_Z5test1v+0x50>
  50:	bb 00 00 00 00       	mov    $0x0,%ebx
  55:	85 c0                	test   %eax,%eax
  57:	74 38                	je     91 <_Z5test1v+0x91>
  59:	bb 00 00 00 00       	mov    $0x0,%ebx
  5e:	bf 00 00 00 00       	mov    $0x0,%edi
  63:	be 00 00 00 00       	mov    $0x0,%esi
  68:	ba 00 00 00 00       	mov    $0x0,%edx
  6d:	e8 00 00 00 00       	callq  72 <_Z5test1v+0x72>
  72:	bf 00 00 00 00       	mov    $0x0,%edi
  77:	e8 00 00 00 00       	callq  7c <_Z5test1v+0x7c>
  7c:	eb 13                	jmp    91 <_Z5test1v+0x91>
  7e:	bf 02 00 00 00       	mov    $0x2,%edi
  83:	e8 00 00 00 00       	callq  88 <_Z5test1v+0x88>
  88:	8b 6c 24 08          	mov    0x8(%rsp),%ebp
  8c:	48 8b 5c 24 10       	mov    0x10(%rsp),%rbx
  91:	0f b6 44 24 20       	movzbl 0x20(%rsp),%eax
  96:	83 f8 03             	cmp    $0x3,%eax
  99:	74 0c                	je     a7 <_Z5test1v+0xa7>
  9b:	83 f8 02             	cmp    $0x2,%eax
  9e:	74 11                	je     b1 <_Z5test1v+0xb1>
  a0:	83 f8 01             	cmp    $0x1,%eax
  a3:	74 0c                	je     b1 <_Z5test1v+0xb1>
  a5:	eb 0f                	jmp    b6 <_Z5test1v+0xb6>
  a7:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  ac:	e8 00 00 00 00       	callq  b1 <_Z5test1v+0xb1>
  b1:	c6 44 24 20 00       	movb   $0x0,0x20(%rsp)
  b6:	89 e8                	mov    %ebp,%eax
  b8:	48 89 da             	mov    %rbx,%rdx
  bb:	48 83 c4 28          	add    $0x28,%rsp
  bf:	5b                   	pop    %rbx
  c0:	5d                   	pop    %rbp
  c1:	c3                   	retq   
  c2:	48 89 c3             	mov    %rax,%rbx
  c5:	0f b6 44 24 20       	movzbl 0x20(%rsp),%eax
  ca:	83 f8 03             	cmp    $0x3,%eax
  cd:	74 0c                	je     db <_Z5test1v+0xdb>
  cf:	83 f8 02             	cmp    $0x2,%eax
  d2:	74 11                	je     e5 <_Z5test1v+0xe5>
  d4:	83 f8 01             	cmp    $0x1,%eax
  d7:	74 0c                	je     e5 <_Z5test1v+0xe5>
  d9:	eb 0f                	jmp    ea <_Z5test1v+0xea>
  db:	48 8d 7c 24 08       	lea    0x8(%rsp),%rdi
  e0:	e8 00 00 00 00       	callq  e5 <_Z5test1v+0xe5>
  e5:	c6 44 24 20 00       	movb   $0x0,0x20(%rsp)
  ea:	48 89 df             	mov    %rbx,%rdi
  ed:	e8 00 00 00 00       	callq  f2 <_Z5test1v+0xf2>
  f2:	66 66 66 66 66 2e 0f 	data16 data16 data16 data16 nopw %cs:0x0(%rax,%rax,1)
  f9:	1f 84 00 00 00 00 00 
