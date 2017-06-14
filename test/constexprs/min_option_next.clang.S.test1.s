  400ef0:	8d 04 76             	lea    (%rsi,%rsi,2),%eax
  400ef3:	89 07                	mov    %eax,(%rdi)
  400ef5:	c6 47 04 01          	movb   $0x1,0x4(%rdi)
  400ef9:	48 89 f8             	mov    %rdi,%rax
  400efc:	c3                   	retq
  400efd:	0f 1f 00             	nopl   (%rax)
