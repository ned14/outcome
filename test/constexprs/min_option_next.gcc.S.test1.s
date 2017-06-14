  400f50:	8d 14 76             	lea    (%rsi,%rsi,2),%edx
  400f53:	48 89 f8             	mov    %rdi,%rax
  400f56:	c6 47 04 01          	movb   $0x1,0x4(%rdi)
  400f5a:	89 17                	mov    %edx,(%rdi)
  400f5c:	c3                   	retq
  400f5d:	0f 1f 00             	nopl   (%rax)
