 950:	53                   	push   %rbx
 951:	48 89 fb             	mov    %rdi,%rbx
 954:	48 83 ec 20          	sub    $0x20,%rsp
 958:	48 89 e6             	mov    %rsp,%rsi
 95b:	48 89 f7             	mov    %rsi,%rdi
 920:	ba 02 00 00 00       	mov    $0x2,%edx
 925:	31 c9                	xor    %ecx,%ecx
 927:	48 89 f8             	mov    %rdi,%rax
 92a:	66 89 57 04          	mov    %dx,0x4(%rdi)
 92e:	48 8d 15 3b 14 20 00 	lea    0x20143b(%rip),%rdx        # 201d70 <system_error2::generic_code_domain>
 935:	66 89 4f 06          	mov    %cx,0x6(%rdi)
 939:	48 c7 47 10 21 00 00 	movq   $0x21,0x10(%rdi)
 941:	48 89 57 08          	mov    %rdx,0x8(%rdi)
 945:	c3                   	retq
 946:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
 963:	0f b7 44 24 04       	movzwl 0x4(%rsp),%eax
 968:	83 e0 f7             	and    $0xfffffff7,%eax
 96b:	66 83 f8 01          	cmp    $0x1,%ax
 96f:	75 6f                	jne    9e0 <test1()+0x90>
 971:	8b 04 24             	mov    (%rsp),%eax
 974:	48 8b 7c 24 08       	mov    0x8(%rsp),%rdi
 979:	31 d2                	xor    %edx,%edx
 97b:	c7 05 8f 16 20 00 00 	movl   $0x0,0x20168f(%rip)        # 202014 <foo>
 985:	66 89 53 06          	mov    %dx,0x6(%rbx)
 989:	48 c7 43 08 00 00 00 	movq   $0x0,0x8(%rbx)
 991:	48 c7 43 10 00 00 00 	movq   $0x0,0x10(%rbx)
 999:	89 03                	mov    %eax,(%rbx)
 99b:	48 85 ff             	test   %rdi,%rdi
 99e:	b8 01 00 00 00       	mov    $0x1,%eax
 9a3:	66 89 43 04          	mov    %ax,0x4(%rbx)
 9a7:	74 13                	je     9bc <test1()+0x6c>
 9a9:	48 8b 07             	mov    (%rdi),%rax
 9ac:	48 8d 15 6d 00 00 00 	lea    0x6d(%rip),%rdx        # a20 <system_error2::status_code_domain::_do_erased_destroy(system_error2::status_code<void>&, unsigned long) const>
 9b3:	48 8b 40 38          	mov    0x38(%rax),%rax
 9b7:	48 39 d0             	cmp    %rdx,%rax
 9ba:	75 0c                	jne    9c8 <test1()+0x78>
 9bc:	48 83 c4 20          	add    $0x20,%rsp
 9c0:	48 89 d8             	mov    %rbx,%rax
 9c3:	5b                   	pop    %rbx
 9c4:	c3                   	retq
 9c5:	0f 1f 00             	nopl   (%rax)
 9c8:	48 83 c6 08          	add    $0x8,%rsi
 9cc:	ba 10 00 00 00       	mov    $0x10,%edx
 9d1:	ff d0                	callq  *%rax
 9d3:	48 83 c4 20          	add    $0x20,%rsp
 9d7:	48 89 d8             	mov    %rbx,%rax
 9da:	5b                   	pop    %rbx
 9db:	c3                   	retq
 9dc:	0f 1f 40 00          	nopl   0x0(%rax)
 9e0:	48 8b 44 24 08       	mov    0x8(%rsp),%rax
 9e5:	b9 02 00 00 00       	mov    $0x2,%ecx
 9ea:	31 f6                	xor    %esi,%esi
 9ec:	66 89 4b 04          	mov    %cx,0x4(%rbx)
 9f0:	66 89 73 06          	mov    %si,0x6(%rbx)
 9f4:	48 89 43 08          	mov    %rax,0x8(%rbx)
 9f8:	48 8b 44 24 10       	mov    0x10(%rsp),%rax
 9fd:	48 89 43 10          	mov    %rax,0x10(%rbx)
 a01:	48 83 c4 20          	add    $0x20,%rsp
 a05:	48 89 d8             	mov    %rbx,%rax
 a08:	5b                   	pop    %rbx
 a09:	c3                   	retq
 a0a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
