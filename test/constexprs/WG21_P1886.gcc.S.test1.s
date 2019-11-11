 920:	41 54                	push   %r12
 922:	49 89 fc             	mov    %rdi,%r12
 925:	48 83 ec 30          	sub    $0x30,%rsp
 929:	48 8d 7c 24 10       	lea    0x10(%rsp),%rdi
 900:	48 8d 15 69 14 20 00 	lea    0x201469(%rip),%rdx        # 201d70 <system_error2::generic_code_domain>
 907:	c7 47 04 02 00 00 00 	movl   $0x2,0x4(%rdi)
 90e:	48 89 f8             	mov    %rdi,%rax
 911:	48 89 57 08          	mov    %rdx,0x8(%rdi)
 915:	48 c7 47 10 21 00 00 	movq   $0x21,0x10(%rdi)
 91d:	c3                   	retq
 91e:	66 90                	xchg   %ax,%ax
 933:	f6 44 24 14 01       	testb  $0x1,0x14(%rsp)
 938:	74 76                	je     9b0 <test1()+0x90>
 93a:	8b 44 24 10          	mov    0x10(%rsp),%eax
 93e:	48 8b 7c 24 18       	mov    0x18(%rsp),%rdi
 943:	c7 05 c7 16 20 00 00 	movl   $0x0,0x2016c7(%rip)        # 202014 <foo>
 94d:	41 c7 44 24 04 01 00 	movl   $0x1,0x4(%r12)
 956:	41 89 04 24          	mov    %eax,(%r12)
 95a:	49 c7 44 24 08 00 00 	movq   $0x0,0x8(%r12)
 963:	49 c7 44 24 10 00 00 	movq   $0x0,0x10(%r12)
 96c:	48 85 ff             	test   %rdi,%rdi
 96f:	74 13                	je     984 <test1()+0x64>
 971:	48 8b 07             	mov    (%rdi),%rax
 974:	48 8d 15 75 00 00 00 	lea    0x75(%rip),%rdx        # 9f0 <system_error2::status_code_domain::_do_erased_destroy(system_error2::status_code<void>&, unsigned long) const>
 97b:	48 8b 40 38          	mov    0x38(%rax),%rax
 97f:	48 39 d0             	cmp    %rdx,%rax
 982:	75 0c                	jne    990 <test1()+0x70>
 984:	48 83 c4 30          	add    $0x30,%rsp
 988:	4c 89 e0             	mov    %r12,%rax
 98b:	41 5c                	pop    %r12
 98d:	c3                   	retq
 98e:	66 90                	xchg   %ax,%ax
 990:	48 8d 74 24 18       	lea    0x18(%rsp),%rsi
 995:	ba 10 00 00 00       	mov    $0x10,%edx
 99a:	ff d0                	callq  *%rax
 99c:	48 83 c4 30          	add    $0x30,%rsp
 9a0:	4c 89 e0             	mov    %r12,%rax
 9a3:	41 5c                	pop    %r12
 9a5:	c3                   	retq
 9a6:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
 9b0:	41 c7 44 24 04 02 00 	movl   $0x2,0x4(%r12)
 9b9:	48 8b 44 24 18       	mov    0x18(%rsp),%rax
 9be:	49 89 44 24 08       	mov    %rax,0x8(%r12)
 9c3:	48 8b 44 24 20       	mov    0x20(%rsp),%rax
 9c8:	49 89 44 24 10       	mov    %rax,0x10(%r12)
 9cd:	48 83 c4 30          	add    $0x30,%rsp
 9d1:	4c 89 e0             	mov    %r12,%rax
 9d4:	41 5c                	pop    %r12
 9d6:	c3                   	retq
 9d7:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
