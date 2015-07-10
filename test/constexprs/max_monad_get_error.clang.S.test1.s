   0:	55                   	push   %rbp
   1:	41 56                	push   %r14
   3:	53                   	push   %rbx
   4:	48 83 ec 20          	sub    $0x20,%rsp
   8:	48 8d 3c 24          	lea    (%rsp),%rdi
   c:	e8 00 00 00 00       	callq  11 <_Z5test1v+0x11>
  11:	0f b6 6c 24 10       	movzbl 0x10(%rsp),%ebp
  16:	83 fd 02             	cmp    $0x2,%ebp
  19:	74 48                	je     63 <_Z5test1v+0x63>
  1b:	40 0f b6 c5          	movzbl %bpl,%eax
  1f:	83 f8 03             	cmp    $0x3,%eax
  22:	75 23                	jne    47 <_Z5test1v+0x47>
  24:	48 c7 44 24 18 00 00 	movq   $0x0,0x18(%rsp)
  2b:	00 00 
  2d:	48 8d 5c 24 18       	lea    0x18(%rsp),%rbx
  32:	48 89 df             	mov    %rbx,%rdi
  35:	e8 00 00 00 00       	callq  3a <_Z5test1v+0x3a>
  3a:	41 be 03 00 00 00    	mov    $0x3,%r14d
  40:	40 8a 6c 24 10       	mov    0x10(%rsp),%bpl
  45:	eb 28                	jmp    6f <_Z5test1v+0x6f>
  47:	40 84 ed             	test   %bpl,%bpl
  4a:	74 0d                	je     59 <_Z5test1v+0x59>
  4c:	45 31 f6             	xor    %r14d,%r14d
  4f:	e8 00 00 00 00       	callq  54 <_Z5test1v+0x54>
  54:	48 89 c3             	mov    %rax,%rbx
  57:	eb 16                	jmp    6f <_Z5test1v+0x6f>
  59:	bf 02 00 00 00       	mov    $0x2,%edi
  5e:	e8 00 00 00 00       	callq  63 <_Z5test1v+0x63>
  63:	44 8b 34 24          	mov    (%rsp),%r14d
  67:	40 b5 02             	mov    $0x2,%bpl
  6a:	48 8b 5c 24 08       	mov    0x8(%rsp),%rbx
  6f:	40 0f b6 c5          	movzbl %bpl,%eax
  73:	83 f8 03             	cmp    $0x3,%eax
  76:	74 0c                	je     84 <_Z5test1v+0x84>
  78:	83 f8 02             	cmp    $0x2,%eax
  7b:	74 10                	je     8d <_Z5test1v+0x8d>
  7d:	83 f8 01             	cmp    $0x1,%eax
  80:	74 0b                	je     8d <_Z5test1v+0x8d>
  82:	eb 0e                	jmp    92 <_Z5test1v+0x92>
  84:	48 8d 3c 24          	lea    (%rsp),%rdi
  88:	e8 00 00 00 00       	callq  8d <_Z5test1v+0x8d>
  8d:	c6 44 24 10 00       	movb   $0x0,0x10(%rsp)
  92:	44 89 f0             	mov    %r14d,%eax
  95:	48 89 da             	mov    %rbx,%rdx
  98:	48 83 c4 20          	add    $0x20,%rsp
  9c:	5b                   	pop    %rbx
  9d:	41 5e                	pop    %r14
  9f:	5d                   	pop    %rbp
  a0:	c3                   	retq   
  a1:	48 89 c3             	mov    %rax,%rbx
  a4:	0f b6 44 24 10       	movzbl 0x10(%rsp),%eax
  a9:	83 f8 03             	cmp    $0x3,%eax
  ac:	74 0c                	je     ba <_Z5test1v+0xba>
  ae:	83 f8 02             	cmp    $0x2,%eax
  b1:	74 10                	je     c3 <_Z5test1v+0xc3>
  b3:	83 f8 01             	cmp    $0x1,%eax
  b6:	74 0b                	je     c3 <_Z5test1v+0xc3>
  b8:	eb 0e                	jmp    c8 <_Z5test1v+0xc8>
  ba:	48 8d 3c 24          	lea    (%rsp),%rdi
  be:	e8 00 00 00 00       	callq  c3 <_Z5test1v+0xc3>
  c3:	c6 44 24 10 00       	movb   $0x0,0x10(%rsp)
  c8:	48 89 df             	mov    %rbx,%rdi
  cb:	e8 00 00 00 00       	callq  d0 replaced
  d0:	c3                   	retq   
  d1:	66 66 66 66 66 66 2e 	data32 data32 data32 data32 data32 nopw %cs:0x0(%rax,%rax,1)
  d8:	0f 1f 84 00 00 00 00 
  df:	00 

