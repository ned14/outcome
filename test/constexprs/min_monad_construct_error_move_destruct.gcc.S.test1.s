   2:	48 89 7c 24 b8       	mov    %rdi,-0x48(%rsp)
   7:	48 89 74 24 c0       	mov    %rsi,-0x40(%rsp)
   c:	48 8b 44 24 b8       	mov    -0x48(%rsp),%rax
  11:	48 8b 54 24 c0       	mov    -0x40(%rsp),%rdx
  16:	48 89 44 24 d8       	mov    %rax,-0x28(%rsp)
  1b:	48 89 54 24 e0       	mov    %rdx,-0x20(%rsp)
  20:	8b 44 24 d8          	mov    -0x28(%rsp),%eax
  24:	48 8b 54 24 e0       	mov    -0x20(%rsp),%rdx
  29:	c3                   	retq   
