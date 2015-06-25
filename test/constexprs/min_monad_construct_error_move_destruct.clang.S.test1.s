   8:	89 7c 24 e8          	mov    %edi,-0x18(%rsp)
   c:	48 89 74 24 f0       	mov    %rsi,-0x10(%rsp)
  11:	0f 10 44 24 e8       	movups -0x18(%rsp),%xmm0
  16:	0f 29 44 24 c8       	movaps %xmm0,-0x38(%rsp)
  1b:	8b 44 24 c8          	mov    -0x38(%rsp),%eax
  1f:	48 8b 54 24 d0       	mov    -0x30(%rsp),%rdx
  24:	c3                   	retq   
  25:	66 66 2e 0f 1f 84 00 	data32 nopw %cs:0x0(%rax,%rax,1)
  2c:	00 00 00 00 
