   0:	8d 04 76             	lea    (%rsi,%rsi,2),%eax
   3:	89 07                	mov    %eax,(%rdi)
   5:	c6 47 10 01          	movb   $0x1,0x10(%rdi)
   9:	48 89 f8             	mov    %rdi,%rax
   c:	c3                   	retq   
   d:	0f 1f 00             	nopl   (%rax)
