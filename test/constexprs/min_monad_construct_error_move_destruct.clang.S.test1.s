   0:	89 7c 24 e8          	mov    %edi,-0x18(%rsp)
   4:	48 89 74 24 f0       	mov    %rsi,-0x10(%rsp)
   9:	0f 10 44 24 e8       	movups -0x18(%rsp),%xmm0
   e:	0f 29 44 24 c8       	movaps %xmm0,-0x38(%rsp)
  13:	8b 44 24 c8          	mov    -0x38(%rsp),%eax
  17:	48 8b 54 24 d0       	mov    -0x30(%rsp),%rdx
  1c:	c3                   	retq   
  1d:	0f 1f 00             	nopl   (%rax)
