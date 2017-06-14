  400e00:	53                   	push   %rbx
  400e01:	48 89 fb             	mov    %rdi,%rbx
  400e04:	48 83 ec 40          	sub    $0x40,%rsp
  400e08:	48 8b 06             	mov    (%rsi),%rax
  400e0b:	48 c7 06 00 00 00 00 	movq   $0x0,(%rsi)
  400e12:	48 8d 74 24 20       	lea    0x20(%rsp),%rsi
  400e17:	c6 44 24 18 03       	movb   $0x3,0x18(%rsp)
  400e1c:	48 c7 04 24 00 00 00 	movq   $0x0,(%rsp)
  400e24:	c6 44 24 38 03       	movb   $0x3,0x38(%rsp)
  400e29:	48 89 44 24 20       	mov    %rax,0x20(%rsp)
  400c20:	ff 25 52 14 20 00    	jmpq   *0x201452(%rip)        # 602078 <_GLOBAL_OFFSET_TABLE_+0x78>
  400c26:	68 0c 00 00 00       	pushq  $0xc
  400c2b:	e9 20 ff ff ff       	jmpq   400b50 <_init+0x28>
  400e33:	80 7c 24 38 03       	cmpb   $0x3,0x38(%rsp)
  400e38:	74 26                	je     400e60 <test1(std::__exception_ptr::exception_ptr)+0x60>
  400e3a:	80 7c 24 18 03       	cmpb   $0x3,0x18(%rsp)
  400e3f:	74 0f                	je     400e50 <test1(std::__exception_ptr::exception_ptr)+0x50>
  400e41:	48 83 c4 40          	add    $0x40,%rsp
  400e45:	48 89 d8             	mov    %rbx,%rax
  400e48:	5b                   	pop    %rbx
  400e49:	c3                   	retq
  400e4a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
  400e50:	48 89 e7             	mov    %rsp,%rdi
  400c10:	ff 25 5a 14 20 00    	jmpq   *0x20145a(%rip)        # 602070 <_GLOBAL_OFFSET_TABLE_+0x70>
  400c16:	68 0b 00 00 00       	pushq  $0xb
  400c1b:	e9 30 ff ff ff       	jmpq   400b50 <_init+0x28>
  400e58:	eb e7                	jmp    400e41 <test1(std::__exception_ptr::exception_ptr)+0x41>
  400e5a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
  400e60:	48 8d 7c 24 20       	lea    0x20(%rsp),%rdi
  400c10:	ff 25 5a 14 20 00    	jmpq   *0x20145a(%rip)        # 602070 <_GLOBAL_OFFSET_TABLE_+0x70>
  400c16:	68 0b 00 00 00       	pushq  $0xb
  400c1b:	e9 30 ff ff ff       	jmpq   400b50 <_init+0x28>
  400e6a:	eb ce                	jmp    400e3a <test1(std::__exception_ptr::exception_ptr)+0x3a>
  400e6c:	0f 1f 40 00          	nopl   0x0(%rax)
