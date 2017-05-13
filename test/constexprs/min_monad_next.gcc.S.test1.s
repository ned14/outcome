  401240:	8d 14 76             	lea    (%rsi,%rsi,2),%edx
  401243:	48 89 f8             	mov    %rdi,%rax
  401246:	c6 47 18 01          	movb   $0x1,0x18(%rdi)
  40124a:	89 17                	mov    %edx,(%rdi)
  40124c:	c3                   	retq
  40124d:	0f 1f 00             	nopl   (%rax)
