  401110:	8d 04 76             	lea    (%rsi,%rsi,2),%eax
  401113:	89 07                	mov    %eax,(%rdi)
  401115:	c6 47 18 01          	movb   $0x1,0x18(%rdi)
  401119:	48 89 f8             	mov    %rdi,%rax
  40111c:	c3                   	retq
  40111d:	0f 1f 00             	nopl   (%rax)
