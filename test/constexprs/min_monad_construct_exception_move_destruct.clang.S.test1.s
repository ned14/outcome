  400880:	53                   	push   %rbx
  400881:	48 83 ec 40          	sub    $0x40,%rsp
  400885:	48 89 fb             	mov    %rdi,%rbx
  400888:	48 8b 06             	mov    (%rsi),%rax
  40088b:	48 c7 06 00 00 00 00 	movq   $0x0,(%rsi)
  400892:	c6 44 24 38 03       	movb   $0x3,0x38(%rsp)
  400897:	48 89 04 24          	mov    %rax,(%rsp)
  40089b:	48 c7 44 24 20 00 00 	movq   $0x0,0x20(%rsp)
  4008a4:	c6 44 24 18 03       	movb   $0x3,0x18(%rsp)
  4008a9:	48 89 e6             	mov    %rsp,%rsi
  400740:	ff 25 f2 08 20 00    	jmpq   *0x2008f2(%rip)        # 601038 <_GLOBAL_OFFSET_TABLE_+0x38>
  400746:	68 04 00 00 00       	pushq  $0x4
  40074b:	e9 a0 ff ff ff       	jmpq   4006f0 <_init+0x28>
  4008b1:	8a 44 24 18          	mov    0x18(%rsp),%al
  4008b5:	89 c1                	mov    %eax,%ecx
  4008b7:	fe c9                	dec    %cl
  4008b9:	80 f9 02             	cmp    $0x2,%cl
  4008bc:	72 0c                	jb     4008ca <test1(std::__exception_ptr::exception_ptr)+0x4a>
  4008be:	3c 03                	cmp    $0x3,%al
  4008c0:	75 0d                	jne    4008cf <test1(std::__exception_ptr::exception_ptr)+0x4f>
  4008c2:	48 89 e7             	mov    %rsp,%rdi
  400730:	ff 25 fa 08 20 00    	jmpq   *0x2008fa(%rip)        # 601030 <_GLOBAL_OFFSET_TABLE_+0x30>
  400736:	68 03 00 00 00       	pushq  $0x3
  40073b:	e9 b0 ff ff ff       	jmpq   4006f0 <_init+0x28>
  4008ca:	c6 44 24 18 00       	movb   $0x0,0x18(%rsp)
  4008cf:	8a 44 24 38          	mov    0x38(%rsp),%al
  4008d3:	89 c1                	mov    %eax,%ecx
  4008d5:	fe c9                	dec    %cl
  4008d7:	80 f9 02             	cmp    $0x2,%cl
  4008da:	72 0e                	jb     4008ea <test1(std::__exception_ptr::exception_ptr)+0x6a>
  4008dc:	3c 03                	cmp    $0x3,%al
  4008de:	75 0f                	jne    4008ef <test1(std::__exception_ptr::exception_ptr)+0x6f>
  4008e0:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
  400730:	ff 25 fa 08 20 00    	jmpq   *0x2008fa(%rip)        # 601030 <_GLOBAL_OFFSET_TABLE_+0x30>
  400736:	68 03 00 00 00       	pushq  $0x3
  40073b:	e9 b0 ff ff ff       	jmpq   4006f0 <_init+0x28>
  4008ea:	c6 44 24 38 00       	movb   $0x0,0x38(%rsp)
  4008ef:	48 89 d8             	mov    %rbx,%rax
  4008f2:	48 83 c4 40          	add    $0x40,%rsp
  4008f6:	5b                   	pop    %rbx
  4008f7:	c3                   	retq
  4008f8:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
