  0000000000000000: 48 83 EC 28        sub         rsp,28h
  0000000000000004: 48 8B 42 10        mov         rax,qword ptr [rdx+10h]
  0000000000000008: 48 89 44 24 10     mov         qword ptr [rsp+10h],rax
  000000000000000D: 0F 10 02           movups      xmm0,xmmword ptr [rdx]
  0000000000000010: 0F 29 04 24        movaps      xmmword ptr [rsp],xmm0
  0000000000000014: 48 8B 04 24        mov         rax,qword ptr [rsp]
  0000000000000018: 48 8B 54 24 08     mov         rdx,qword ptr [rsp+8]
  000000000000001D: 89 01              mov         dword ptr [rcx],eax
  000000000000001F: 48 C1 E8 20        shr         rax,20h
  0000000000000023: 89 41 04           mov         dword ptr [rcx+4],eax
  0000000000000026: 48 89 51 08        mov         qword ptr [rcx+8],rdx
  000000000000002A: 48 89 C8           mov         rax,rcx
  000000000000002D: 48 83 C4 28        add         rsp,28h
  0000000000000031: C3                 ret
  0000000000000032: 66 66 66 66 66 2E  nop         word ptr cs:[rax+rax]
                    0F 1F 84 00 00 00
                    00 00
