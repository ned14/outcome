   0:	41 56                	push   %r14
   2:	53                   	push   %rbx
   3:	48 83 ec 18          	sub    $0x18,%rsp
   7:	48 8d 3c 24          	lea    (%rsp),%rdi
   b:	e8 00 00 00 00       	callq  10 <_Z5test1v+0x10>
  10:	0f b6 4c 24 10       	movzbl 0x10(%rsp),%ecx
  15:	83 f9 02             	cmp    $0x2,%ecx
  18:	74 2d                	je     47 <_Z5test1v+0x47>
  1a:	84 c9                	test   %cl,%cl
  1c:	74 1f                	je     3d <_Z5test1v+0x3d>
  1e:	8b 04 24             	mov    (%rsp),%eax
  21:	83 f9 03             	cmp    $0x3,%ecx
  24:	74 0a                	je     30 <_Z5test1v+0x30>
  26:	83 f9 02             	cmp    $0x2,%ecx
  29:	74 05                	je     30 <_Z5test1v+0x30>
  2b:	83 f9 01             	cmp    $0x1,%ecx
  2e:	75 05                	jne    35 <_Z5test1v+0x35>
  30:	c6 44 24 10 00       	movb   $0x0,0x10(%rsp)
  35:	48 83 c4 18          	add    $0x18,%rsp
  39:	5b                   	pop    %rbx
  3a:	41 5e                	pop    %r14
  3c:	c3                   	retq   
  3d:	bf 02 00 00 00       	mov    $0x2,%edi
  42:	e8 00 00 00 00       	callq  47 <_Z5test1v+0x47>
  47:	bf 20 00 00 00       	mov    $0x20,%edi
  4c:	e8 00 00 00 00       	callq  51 <_Z5test1v+0x51>
  51:	48 89 c3             	mov    %rax,%rbx
  54:	8b 34 24             	mov    (%rsp),%esi
  57:	48 8b 54 24 08       	mov    0x8(%rsp),%rdx
  5c:	48 89 df             	mov    %rbx,%rdi
  5f:	e8 00 00 00 00       	callq  64 <_Z5test1v+0x64>
  64:	be 00 00 00 00       	mov    $0x0,%esi
  69:	ba 00 00 00 00       	mov    $0x0,%edx
  6e:	48 89 df             	mov    %rbx,%rdi
  71:	e8 00 00 00 00       	callq  76 <_Z5test1v+0x76>
  76:	49 89 c6             	mov    %rax,%r14
  79:	48 89 df             	mov    %rbx,%rdi
  7c:	e8 00 00 00 00       	callq  81 <_Z5test1v+0x81>
  81:	eb 03                	jmp    86 <_Z5test1v+0x86>
  83:	49 89 c6             	mov    %rax,%r14
  86:	0f b6 44 24 10       	movzbl 0x10(%rsp),%eax
  8b:	83 f8 03             	cmp    $0x3,%eax
  8e:	74 0a                	je     9a <_Z5test1v+0x9a>
  90:	83 f8 02             	cmp    $0x2,%eax
  93:	74 05                	je     9a <_Z5test1v+0x9a>
  95:	83 f8 01             	cmp    $0x1,%eax
  98:	75 05                	jne    9f <_Z5test1v+0x9f>
  9a:	c6 44 24 10 00       	movb   $0x0,0x10(%rsp)
  9f:	4c 89 f7             	mov    %r14,%rdi
  a2:	e8 00 00 00 00       	callq  a7 <_Z5test1v+0xa7>
  a7:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
  ae:	00 00 
