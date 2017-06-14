  401080:	8d 14 76             	lea    (%rsi,%rsi,2),%edx
  401083:	48 89 f8             	mov    %rdi,%rax
  401086:	c6 47 18 01          	movb   $0x1,0x18(%rdi)
  40108a:	89 17                	mov    %edx,(%rdi)
  40108c:	c3                   	retq
  40108d:	0f 1f 00             	nopl   (%rax)
