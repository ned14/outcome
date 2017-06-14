  0000000000000000: 48 89 4C 24 08     mov         qword ptr [rsp+8],rcx
  0000000000000005: 53                 push        rbx
  0000000000000006: 48 83 EC 50        sub         rsp,50h
  000000000000000A: 48 C7 44 24 28 FE  mov         qword ptr [rsp+28h],0FFFFFFFFFFFFFFFEh
  0000000000000013: 48 8B D9           mov         rbx,rcx
  0000000000000016: C7 44 24 20 00 00  mov         dword ptr [rsp+20h],0
  000000000000001E: 33 C0              xor         eax,eax
  0000000000000020: 88 44 24 60        mov         byte ptr [rsp+60h],al
  0000000000000024: 89 54 24 30        mov         dword ptr [rsp+30h],edx
  0000000000000028: C6 44 24 48 01     mov         byte ptr [rsp+48h],1
  000000000000002D: 4C 8D 44 24 60     lea         r8,[rsp+60h]
  0000000000000032: 48 8B D1           mov         rdx,rcx
  0000000000000035: 48 8D 4C 24 30     lea         rcx,[rsp+30h]
  0000000000000000: 40 53              push        rbx
  0000000000000002: 48 83 EC 30        sub         rsp,30h
  0000000000000006: 0F B6 41 18        movzx       eax,byte ptr [rcx+18h]
  000000000000000A: 48 8B DA           mov         rbx,rdx
  000000000000000D: 44 0F B6 4C 24 40  movzx       r9d,byte ptr [rsp+40h]
  0000000000000013: C7 44 24 20 00 00  mov         dword ptr [rsp+20h],0
  000000000000001B: 3C 01              cmp         al,1
  000000000000001D: 75 16              jne         0000000000000035
  000000000000001F: 4C 8B C1           mov         r8,rcx
  0000000000000022: 48 8D 4C 24 40     lea         rcx,[rsp+40h]
  0000000000000000: 48 83 EC 18        sub         rsp,18h
  0000000000000004: 41 8B 00           mov         eax,dword ptr [r8]
  0000000000000007: C7 04 24 00 00 00  mov         dword ptr [rsp],0
  000000000000000E: C6 42 18 01        mov         byte ptr [rdx+18h],1
  0000000000000012: 8D 0C 40           lea         ecx,[rax+rax*2]
  0000000000000015: 48 8B C2           mov         rax,rdx
  0000000000000018: 89 0A              mov         dword ptr [rdx],ecx
  000000000000001A: 48 83 C4 18        add         rsp,18h
  000000000000001E: C3                 ret
  000000000000002C: 48 8B C2           mov         rax,rdx
  000000000000002F: 48 83 C4 30        add         rsp,30h
  0000000000000033: 5B                 pop         rbx
  0000000000000034: C3                 ret
  0000000000000035: 3C 02              cmp         al,2
  0000000000000037: 75 16              jne         000000000000004F
  0000000000000039: 4C 8B C1           mov         r8,rcx
  000000000000003C: 48 8D 4C 24 40     lea         rcx,[rsp+40h]
  0000000000000000: 48 83 EC 18        sub         rsp,18h
  0000000000000004: 41 0F 10 00        movups      xmm0,xmmword ptr [r8]
  0000000000000008: C7 04 24 00 00 00  mov         dword ptr [rsp],0
  000000000000000F: 48 8B C2           mov         rax,rdx
  0000000000000012: 0F 11 02           movups      xmmword ptr [rdx],xmm0
  0000000000000015: F2 41 0F 10 48 10  movsd       xmm1,mmword ptr [r8+10h]
  000000000000001B: F2 0F 11 4A 10     movsd       mmword ptr [rdx+10h],xmm1
  0000000000000020: C6 42 18 02        mov         byte ptr [rdx+18h],2
  0000000000000024: 48 83 C4 18        add         rsp,18h
  0000000000000028: C3                 ret
  0000000000000046: 48 8B C3           mov         rax,rbx
  0000000000000049: 48 83 C4 30        add         rsp,30h
  000000000000004D: 5B                 pop         rbx
  000000000000004E: C3                 ret
  000000000000004F: 3C 03              cmp         al,3
  0000000000000051: 75 16              jne         0000000000000069
  0000000000000053: 4C 8B C1           mov         r8,rcx
  0000000000000056: 48 8D 4C 24 40     lea         rcx,[rsp+40h]
  0000000000000000: 40 53              push        rbx
  0000000000000002: 48 83 EC 30        sub         rsp,30h
  0000000000000006: 48 8B DA           mov         rbx,rdx
  0000000000000009: C7 44 24 20 00 00  mov         dword ptr [rsp+20h],0
  0000000000000011: 48 8B CB           mov         rcx,rbx
  0000000000000014: 49 8B D0           mov         rdx,r8
  0000000000000017: E8 00 00 00 00     call        ?__ExceptionPtrCopy@@YAXPEAXPEBX@Z
  000000000000001C: 48 8B C3           mov         rax,rbx
  000000000000001F: C6 43 18 03        mov         byte ptr [rbx+18h],3
  0000000000000023: 48 83 C4 30        add         rsp,30h
  0000000000000027: 5B                 pop         rbx
  0000000000000028: C3                 ret
  0000000000000060: 48 8B C3           mov         rax,rbx
  0000000000000063: 48 83 C4 30        add         rsp,30h
  0000000000000067: 5B                 pop         rbx
  0000000000000068: C3                 ret
  0000000000000069: 4C 8D 44 24 40     lea         r8,[rsp+40h]
  000000000000006E: 48 8D 4C 24 40     lea         rcx,[rsp+40h]
  0000000000000000: 48 83 EC 18        sub         rsp,18h
  0000000000000004: 33 C0              xor         eax,eax
  0000000000000006: C7 04 24 00 00 00  mov         dword ptr [rsp],0
  000000000000000D: 48 89 02           mov         qword ptr [rdx],rax
  0000000000000010: 48 89 42 08        mov         qword ptr [rdx+8],rax
  0000000000000014: 48 89 42 10        mov         qword ptr [rdx+10h],rax
  0000000000000018: 48 89 42 18        mov         qword ptr [rdx+18h],rax
  000000000000001C: 88 42 18           mov         byte ptr [rdx+18h],al
  000000000000001F: 48 8B C2           mov         rax,rdx
  0000000000000022: 48 83 C4 18        add         rsp,18h
  0000000000000026: C3                 ret
  0000000000000078: 48 8B C3           mov         rax,rbx
  000000000000007B: 48 83 C4 30        add         rsp,30h
  000000000000007F: 5B                 pop         rbx
  0000000000000080: C3                 ret
  000000000000003F: 90                 nop
  0000000000000040: 0F B6 4C 24 48     movzx       ecx,byte ptr [rsp+48h]
  0000000000000045: 83 E9 01           sub         ecx,1
  0000000000000048: 74 14              je          000000000000005E
  000000000000004A: 83 E9 01           sub         ecx,1
  000000000000004D: 74 0F              je          000000000000005E
  000000000000004F: 83 F9 01           cmp         ecx,1
  0000000000000052: 75 0A              jne         000000000000005E
  0000000000000054: 48 8D 4C 24 30     lea         rcx,[rsp+30h]
  0000000000000059: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  000000000000005E: 48 8B C3           mov         rax,rbx
  0000000000000061: 48 83 C4 50        add         rsp,50h
  0000000000000065: 5B                 pop         rbx
  0000000000000066: C3                 ret
