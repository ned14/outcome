   0:	8d 14 76             	lea    (%rsi,%rsi,2),%edx
   3:	48 89 f8             	mov    %rdi,%rax
   6:	c6 47 18 01          	movb   $0x1,0x18(%rdi)
   a:	89 17                	mov    %edx,(%rdi)
   c:	c3                   	retq   
   d:	0f 1f 00             	nopl   (%rax)
