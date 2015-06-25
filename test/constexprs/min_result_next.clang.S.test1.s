   8:	8d 04 76             	lea    (%rsi,%rsi,2),%eax
   b:	89 07                	mov    %eax,(%rdi)
   d:	c6 47 10 01          	movb   $0x1,0x10(%rdi)
  11:	48 89 f8             	mov    %rdi,%rax
  14:	c3                   	retq   
  15:	66 66 2e 0f 1f 84 00 	data32 nopw %cs:0x0(%rax,%rax,1)
  1c:	00 00 00 00 
