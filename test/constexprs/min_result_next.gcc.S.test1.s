  10:	8d 14 76             	lea    (%rsi,%rsi,2),%edx
  13:	48 89 f8             	mov    %rdi,%rax
  16:	c6 47 18 01          	movb   $0x1,0x18(%rdi)
  1a:	89 17                	mov    %edx,(%rdi)
  1c:	c3                   	retq   
