  0000000000000000: 8D 04 52           lea         eax,[rdx+rdx*2]
  0000000000000003: C6 41 04 01        mov         byte ptr [rcx+4],1
  0000000000000007: 89 01              mov         dword ptr [rcx],eax
  0000000000000009: 48 8B C1           mov         rax,rcx
  000000000000000C: C3                 ret
