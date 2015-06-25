   2:	8d 14 76             	lea    (%rsi,%rsi,2),%edx
   5:	48 89 f8             	mov    %rdi,%rax
   8:	c6 47 10 01          	movb   $0x1,0x10(%rdi)
   c:	89 17                	mov    %edx,(%rdi)
   e:	c3                   	retq   
