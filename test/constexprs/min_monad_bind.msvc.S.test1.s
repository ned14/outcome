  0000000000000000: 48 89 4C 24 08     mov         qword ptr [rsp+8],rcx
  0000000000000005: 53                 push        rbx
  0000000000000006: 48 83 EC 50        sub         rsp,50h
  000000000000000A: 48 C7 44 24 28 FE  mov         qword ptr [rsp+28h],0FFFFFFFFFFFFFFFEh
                    FF FF FF
  0000000000000013: 48 8B D9           mov         rbx,rcx
  0000000000000016: C7 44 24 20 00 00  mov         dword ptr [rsp+20h],0
                    00 00
  000000000000001E: 33 C0              xor         eax,eax
  0000000000000020: 88 44 24 70        mov         byte ptr [rsp+70h],al
  0000000000000024: 89 54 24 30        mov         dword ptr [rsp+30h],edx
  0000000000000028: C6 44 24 40 01     mov         byte ptr [rsp+40h],1
  000000000000002D: 4C 8D 44 24 70     lea         r8,[rsp+70h]
  0000000000000032: 48 8B D1           mov         rdx,rcx
  0000000000000035: 48 8D 4C 24 30     lea         rcx,[rsp+30h]
  000000000000003A: E8 00 00 00 00     call        replaced
  0000000000000000: 40 53              push        rbx
  0000000000000002: 48 83 EC 30        sub         rsp,30h
  0000000000000006: 0F B6 41 10        movzx       eax,byte ptr [rcx+10h]
  000000000000000A: 48 8B DA           mov         rbx,rdx
  000000000000000D: 44 0F B6 4C 24 40  movzx       r9d,byte ptr [rsp+40h]
  0000000000000013: C7 44 24 20 00 00  mov         dword ptr [rsp+20h],0
                    00 00
  000000000000001B: 3C 01              cmp         al,1
  000000000000001D: 75 16              jne         0000000000000035
  000000000000001F: 4C 8B C1           mov         r8,rcx
  0000000000000022: 48 8D 4C 24 40     lea         rcx,[rsp+40h]
  0000000000000027: E8 00 00 00 00     call        replaced
  0000000000000000: 48 83 EC 18        sub         rsp,18h
  0000000000000004: 41 8B 00           mov         eax,dword ptr [r8]
  0000000000000007: C7 04 24 00 00 00  mov         dword ptr [rsp],0
                    00
  000000000000000E: C6 42 10 01        mov         byte ptr [rdx+10h],1
  0000000000000012: 8D 0C 40           lea         ecx,[rax+rax*2]
  0000000000000015: 48 8B C2           mov         rax,rdx
  0000000000000018: 89 0A              mov         dword ptr [rdx],ecx
  000000000000001A: 48 83 C4 18        add         rsp,18h
  000000000000001E: C3                 ret

  000000000000002C: 48 8B C3           mov         rax,rbx
  000000000000002F: 48 83 C4 30        add         rsp,30h
  0000000000000033: 5B                 pop         rbx
  0000000000000034: C3                 ret
  0000000000000035: 3C 02              cmp         al,2
  0000000000000037: 75 16              jne         000000000000004F
  0000000000000039: 4C 8B C1           mov         r8,rcx
  000000000000003C: 48 8D 4C 24 40     lea         rcx,[rsp+40h]
  0000000000000041: E8 00 00 00 00     call        replaced
  0000000000000000: 48 83 EC 18        sub         rsp,18h
  0000000000000004: 41 0F 10 00        movups      xmm0,xmmword ptr [r8]
  0000000000000008: C7 04 24 00 00 00  mov         dword ptr [rsp],0
                    00
  000000000000000F: 48 8B C2           mov         rax,rdx
  0000000000000012: C6 42 10 02        mov         byte ptr [rdx+10h],2
  0000000000000016: 0F 11 02           movups      xmmword ptr [rdx],xmm0
  0000000000000019: 48 83 C4 18        add         rsp,18h
  000000000000001D: C3                 ret

  0000000000000046: 48 8B C3           mov         rax,rbx
  0000000000000049: 48 83 C4 30        add         rsp,30h
  000000000000004D: 5B                 pop         rbx
  000000000000004E: C3                 ret
  000000000000004F: 3C 03              cmp         al,3
  0000000000000051: 75 16              jne         0000000000000069
  0000000000000053: 4C 8B C1           mov         r8,rcx
  0000000000000056: 48 8D 4C 24 40     lea         rcx,[rsp+40h]
  000000000000005B: E8 00 00 00 00     call        replaced
  0000000000000000: 40 53              push        rbx
  0000000000000002: 48 83 EC 30        sub         rsp,30h
  0000000000000006: 48 C7 44 24 28 FE  mov         qword ptr [rsp+28h],0FFFFFFFFFFFFFFFEh
                    FF FF FF
  000000000000000F: 48 8B DA           mov         rbx,rdx
  0000000000000012: C7 44 24 20 00 00  mov         dword ptr [rsp+20h],0
                    00 00
  000000000000001A: 49 8B D0           mov         rdx,r8
  000000000000001D: 48 8B CB           mov         rcx,rbx
  0000000000000020: E8 00 00 00 00     call        ?__ExceptionPtrCopy@@YAXPEAXPEBX@Z
  0000000000000025: C6 43 10 03        mov         byte ptr [rbx+10h],3
  0000000000000029: 48 8B C3           mov         rax,rbx
  000000000000002C: 48 83 C4 30        add         rsp,30h
  0000000000000030: 5B                 pop         rbx
  0000000000000031: C3                 ret

  0000000000000060: 48 8B C3           mov         rax,rbx
  0000000000000063: 48 83 C4 30        add         rsp,30h
  0000000000000067: 5B                 pop         rbx
  0000000000000068: C3                 ret
  0000000000000069: 4C 8D 44 24 40     lea         r8,[rsp+40h]
  000000000000006E: 48 8D 4C 24 40     lea         rcx,[rsp+40h]
  0000000000000073: E8 00 00 00 00     call        replaced
  0000000000000000: 48 83 EC 18        sub         rsp,18h
  0000000000000004: 33 C0              xor         eax,eax
  0000000000000006: C7 04 24 00 00 00  mov         dword ptr [rsp],0
                    00
  000000000000000D: 48 89 02           mov         qword ptr [rdx],rax
  0000000000000010: 48 89 42 08        mov         qword ptr [rdx+8],rax
  0000000000000014: 48 89 42 10        mov         qword ptr [rdx+10h],rax
  0000000000000018: 88 42 10           mov         byte ptr [rdx+10h],al
  000000000000001B: 48 8B C2           mov         rax,rdx
  000000000000001E: 48 83 C4 18        add         rsp,18h
  0000000000000022: C3                 ret

  0000000000000078: 48 8B C3           mov         rax,rbx
  000000000000007B: 48 83 C4 30        add         rsp,30h
  000000000000007F: 5B                 pop         rbx
  0000000000000080: C3                 ret

  000000000000003F: C7 44 24 20 01 00  mov         dword ptr [rsp+20h],1
                    00 00
  0000000000000047: 0F B6 4C 24 40     movzx       ecx,byte ptr [rsp+40h]
  000000000000004C: 83 E9 01           sub         ecx,1
  000000000000004F: 74 15              je          0000000000000066
  0000000000000051: 83 E9 01           sub         ecx,1
  0000000000000054: 74 10              je          0000000000000066
  0000000000000056: 83 F9 01           cmp         ecx,1
  0000000000000059: 75 0B              jne         0000000000000066
  000000000000005B: 48 8D 4C 24 30     lea         rcx,[rsp+30h]
  0000000000000060: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  0000000000000065: 90                 nop
  0000000000000066: 48 8B C3           mov         rax,rbx
  0000000000000069: 48 83 C4 50        add         rsp,50h
  000000000000006D: 5B                 pop         rbx
  000000000000006E: C3                 ret
  000000000000006F: CC                 int         3
