   0:	41 56                	push   %r14
   2:	53                   	push   %rbx
   3:	48 83 ec 38          	sub    $0x38,%rsp
   7:	48 89 fb             	mov    %rdi,%rbx
   a:	48 8d 3c 24          	lea    (%rsp),%rdi
   e:	e8 00 00 00 00       	callq  13 <_Z5test1v+0x13>
  13:	0f b6 44 24 10       	movzbl 0x10(%rsp),%eax
  18:	83 f8 02             	cmp    $0x2,%eax
  1b:	74 16                	je     33 <_Z5test1v+0x33>
  1d:	0f b6 c8             	movzbl %al,%ecx
  20:	83 f9 03             	cmp    $0x3,%ecx
  23:	75 66                	jne    8b <_Z5test1v+0x8b>
  25:	48 8d 34 24          	lea    (%rsp),%rsi
  29:	48 89 df             	mov    %rbx,%rdi
  2c:	e8 00 00 00 00       	callq  31 <_Z5test1v+0x31>
  31:	eb 2a                	jmp    5d <_Z5test1v+0x5d>
  33:	8b 34 24             	mov    (%rsp),%esi
  36:	48 8b 54 24 08       	mov    0x8(%rsp),%rdx
  3b:	48 8d 7c 24 18       	lea    0x18(%rsp),%rdi
  40:	e8 00 00 00 00       	callq  45 <_Z5test1v+0x45>
  45:	4c 8d 74 24 18       	lea    0x18(%rsp),%r14
  4a:	48 89 df             	mov    %rbx,%rdi
  4d:	4c 89 f6             	mov    %r14,%rsi
  50:	e8 00 00 00 00       	callq  55 <_Z5test1v+0x55>
  55:	4c 89 f7             	mov    %r14,%rdi
  58:	e8 00 00 00 00       	callq  5d <_Z5test1v+0x5d>
  5d:	8a 44 24 10          	mov    0x10(%rsp),%al
  61:	fe c8                	dec    %al
  63:	0f b6 c0             	movzbl %al,%eax
  66:	83 f8 03             	cmp    $0x3,%eax
  69:	77 15                	ja     80 <_Z5test1v+0x80>
  6b:	ff 24 c5 00 00 00 00 	jmpq   *0x0(,%rax,8)
  72:	48 8d 3c 24          	lea    (%rsp),%rdi
  76:	e8 00 00 00 00       	callq  7b <_Z5test1v+0x7b>
  7b:	c6 44 24 10 00       	movb   $0x0,0x10(%rsp)
  80:	48 89 d8             	mov    %rbx,%rax
  83:	48 83 c4 38          	add    $0x38,%rsp
  87:	5b                   	pop    %rbx
  88:	41 5e                	pop    %r14
  8a:	c3                   	retq   
  8b:	84 c0                	test   %al,%al
  8d:	74 0a                	je     99 <_Z5test1v+0x99>
  8f:	48 89 df             	mov    %rbx,%rdi
  92:	e8 00 00 00 00       	callq  97 <_Z5test1v+0x97>
  97:	eb c4                	jmp    5d <_Z5test1v+0x5d>
  99:	bf 02 00 00 00       	mov    $0x2,%edi
  9e:	e8 00 00 00 00       	callq  a3 <_Z5test1v+0xa3>
  a3:	eb ea                	jmp    8f <_Z5test1v+0x8f>
  a5:	48 89 c3             	mov    %rax,%rbx
  a8:	8a 44 24 10          	mov    0x10(%rsp),%al
  ac:	fe c8                	dec    %al
  ae:	0f b6 c0             	movzbl %al,%eax
  b1:	83 f8 03             	cmp    $0x3,%eax
  b4:	77 15                	ja     cb <_Z5test1v+0xcb>
  b6:	ff 24 c5 00 00 00 00 	jmpq   *0x0(,%rax,8)
  bd:	48 8d 3c 24          	lea    (%rsp),%rdi
  c1:	e8 00 00 00 00       	callq  c6 <_Z5test1v+0xc6>
  c6:	c6 44 24 10 00       	movb   $0x0,0x10(%rsp)
  cb:	48 89 df             	mov    %rbx,%rdi
  ce:	e8 00 00 00 00       	callq  d3 <_Z5test1v+0xd3>
  d3:	66 66 66 66 2e 0f 1f 	data32 data32 data32 nopw %cs:0x0(%rax,%rax,1)
  da:	84 00 00 00 00 00 
