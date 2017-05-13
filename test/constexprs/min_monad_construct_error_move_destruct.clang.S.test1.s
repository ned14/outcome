  400630:	0f 28 44 24 08       	movaps 0x8(%rsp),%xmm0
  400635:	0f 29 44 24 d8       	movaps %xmm0,-0x28(%rsp)
  40063a:	48 8b 44 24 18       	mov    0x18(%rsp),%rax
  40063f:	48 89 44 24 e8       	mov    %rax,-0x18(%rsp)
  400644:	8b 44 24 d8          	mov    -0x28(%rsp),%eax
  400648:	48 8b 54 24 e0       	mov    -0x20(%rsp),%rdx
  40064d:	c3                   	retq
  40064e:	66 90                	xchg   %ax,%ax
