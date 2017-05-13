  0000000000000000: 48 83 EC 28        sub         rsp,28h
  0000000000000004: 48 8B 42 10        mov         rax,qword ptr [rdx+10h]
  0000000000000008: 48 89 44 24 10     mov         qword ptr [rsp+10h],rax
  000000000000000D: 0F 10 02           movups      xmm0,xmmword ptr [rdx]
  0000000000000010: 0F 29 04 24        movaps      xmmword ptr [rsp],xmm0
  0000000000000014: 8B 04 24           mov         eax,dword ptr [rsp]
  0000000000000017: 8B 54 24 04        mov         edx,dword ptr [rsp+4]
  000000000000001B: 4C 8B 44 24 08     mov         r8,qword ptr [rsp+8]
  0000000000000020: 89 01              mov         dword ptr [rcx],eax
  0000000000000022: 89 51 04           mov         dword ptr [rcx+4],edx
  0000000000000025: 4C 89 41 08        mov         qword ptr [rcx+8],r8
  0000000000000029: 48 89 C8           mov         rax,rcx
  000000000000002C: 48 83 C4 28        add         rsp,28h
  0000000000000030: C3                 ret
  0000000000000031: 66 66 66 66 66 66  nop         word ptr cs:[rax+rax]
