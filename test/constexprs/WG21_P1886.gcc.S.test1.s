     c60:	53                   	push   %rbx
     c61:	48 89 fb             	mov    %rdi,%rbx
     c64:	48 83 ec 20          	sub    $0x20,%rsp
     c68:	48 89 e6             	mov    %rsp,%rsi
     c6b:	48 89 f7             	mov    %rsi,%rdi
     c40:	48 8d 15 b9 20 20 00 	lea    0x2020b9(%rip),%rdx        # 202d00 <system_error2::generic_code_domain>
     c47:	48 89 f8             	mov    %rdi,%rax
     c4a:	c7 47 04 02 00 00 00 	movl   $0x2,0x4(%rdi)
     c51:	48 c7 47 10 21 00 00 	movq   $0x21,0x10(%rdi)
     c59:	48 89 57 08          	mov    %rdx,0x8(%rdi)
     c5d:	c3                   	retq
     c5e:	66 90                	xchg   %ax,%ax
     c73:	f6 44 24 04 01       	testb  $0x1,0x4(%rsp)
     c78:	74 6e                	je     ce8 <test1()+0x88>
     c7a:	48 8b 7c 24 08       	mov    0x8(%rsp),%rdi
     c7f:	8b 04 24             	mov    (%rsp),%eax
     c82:	c7 05 90 23 20 00 00 	movl   $0x0,0x202390(%rip)        # 20301c <foo>
     c8c:	c7 43 04 01 00 00 00 	movl   $0x1,0x4(%rbx)
     c93:	48 c7 43 08 00 00 00 	movq   $0x0,0x8(%rbx)
     c9b:	48 c7 43 10 00 00 00 	movq   $0x0,0x10(%rbx)
     ca3:	48 85 ff             	test   %rdi,%rdi
     ca6:	89 03                	mov    %eax,(%rbx)
     ca8:	74 13                	je     cbd <test1()+0x5d>
     caa:	48 8b 07             	mov    (%rdi),%rax
     cad:	48 8d 15 6c 00 00 00 	lea    0x6c(%rip),%rdx        # d20 <system_error2::status_code_domain::_do_erased_destroy(system_error2::status_code<void>&, unsigned long) const>
     cb4:	48 8b 40 38          	mov    0x38(%rax),%rax
     cb8:	48 39 d0             	cmp    %rdx,%rax
     cbb:	75 13                	jne    cd0 <test1()+0x70>
     cbd:	48 83 c4 20          	add    $0x20,%rsp
     cc1:	48 89 d8             	mov    %rbx,%rax
     cc4:	5b                   	pop    %rbx
     cc5:	c3                   	retq
     cc6:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
     cd0:	48 83 c6 08          	add    $0x8,%rsi
     cd4:	ba 10 00 00 00       	mov    $0x10,%edx
     cd9:	ff d0                	callq  *%rax
     cdb:	48 83 c4 20          	add    $0x20,%rsp
     cdf:	48 89 d8             	mov    %rbx,%rax
     ce2:	5b                   	pop    %rbx
     ce3:	c3                   	retq
     ce4:	0f 1f 40 00          	nopl   0x0(%rax)
     ce8:	48 8b 44 24 08       	mov    0x8(%rsp),%rax
     ced:	c7 43 04 02 00 00 00 	movl   $0x2,0x4(%rbx)
     cf4:	48 89 43 08          	mov    %rax,0x8(%rbx)
     cf8:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
     cfd:	48 89 43 10          	mov    %rax,0x10(%rbx)
     d01:	48 83 c4 20          	add    $0x20,%rsp
     d05:	48 89 d8             	mov    %rbx,%rax
     d08:	5b                   	pop    %rbx
     d09:	c3                   	retq
     d0a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
