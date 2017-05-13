  400fa0:	8d 04 76             	lea    (%rsi,%rsi,2),%eax
  400fa3:	89 07                	mov    %eax,(%rdi)
  400fa5:	c6 47 18 01          	movb   $0x1,0x18(%rdi)
  400fa9:	48 89 f8             	mov    %rdi,%rax
  400fac:	c3                   	retq
  400fad:	0f 1f 00             	nopl   (%rax)
