  10:	48 89 7c 24 b8       	mov    %rdi,-0x48(%rsp)
  15:	48 89 74 24 c0       	mov    %rsi,-0x40(%rsp)
  1a:	48 8b 44 24 b8       	mov    -0x48(%rsp),%rax
  1f:	48 8b 54 24 c0       	mov    -0x40(%rsp),%rdx
  24:	48 89 44 24 d8       	mov    %rax,-0x28(%rsp)
  29:	48 89 54 24 e0       	mov    %rdx,-0x20(%rsp)
  2e:	8b 44 24 d8          	mov    -0x28(%rsp),%eax
  32:	48 8b 54 24 e0       	mov    -0x20(%rsp),%rdx
  37:	c3                   	retq   
