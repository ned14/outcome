  0000000000000000: 48 8B C4           mov         rax,rsp
  0000000000000003: 55                 push        rbp
  0000000000000004: 48 8B EC           mov         rbp,rsp
  0000000000000007: 48 81 EC 80 00 00  sub         rsp,80h
                    00
  000000000000000E: 48 C7 45 A0 FE FF  mov         qword ptr [rbp-60h],0FFFFFFFFFFFFFFFEh
                    FF FF
  0000000000000016: 48 89 58 08        mov         qword ptr [rax+8],rbx
  000000000000001A: 48 89 78 10        mov         qword ptr [rax+10h],rdi
  000000000000001E: C6 45 E0 00        mov         byte ptr [rbp-20h],0
  0000000000000022: C6 45 E8 00        mov         byte ptr [rbp-18h],0
  0000000000000026: C6 45 EA 00        mov         byte ptr [rbp-16h],0
  000000000000002A: 33 FF              xor         edi,edi
  000000000000002C: 48 89 7D F0        mov         qword ptr [rbp-10h],rdi
  0000000000000030: 48 8D 55 D0        lea         rdx,[rbp-30h]
  0000000000000034: 48 8D 4D A8        lea         rcx,[rbp-58h]
  0000000000000038: E8 00 00 00 00     call        replaced
  0000000000000000: 40 57              push        rdi
  0000000000000002: 48 83 EC 30        sub         rsp,30h
  0000000000000006: 48 C7 44 24 20 FE  mov         qword ptr [rsp+20h],0FFFFFFFFFFFFFFFEh
                    FF FF FF
  000000000000000F: 48 89 5C 24 40     mov         qword ptr [rsp+40h],rbx
  0000000000000014: 48 89 74 24 48     mov         qword ptr [rsp+48h],rsi
  0000000000000019: 48 8B DA           mov         rbx,rdx
  000000000000001C: 48 8B F9           mov         rdi,rcx
  000000000000001F: 80 7A 18 00        cmp         byte ptr [rdx+18h],0
  0000000000000023: 74 43              je          0000000000000068
  0000000000000025: 48 8D 4A 19        lea         rcx,[rdx+19h]
  0000000000000029: E8 00 00 00 00     call        replaced
  0000000000000000: 48 89 5C 24 18     mov         qword ptr [rsp+18h],rbx
  0000000000000005: 48 89 74 24 20     mov         qword ptr [rsp+20h],rsi
  000000000000000A: 57                 push        rdi
  000000000000000B: 48 83 EC 40        sub         rsp,40h
  000000000000000F: 48 8B F9           mov         rdi,rcx
  0000000000000012: 33 DB              xor         ebx,ebx
  0000000000000014: 48 BE B3 94 D6 26  mov         rsi,112E0BE826D694B3h
                    E8 0B 2E 11
  000000000000001E: 66 90              xchg        ax,ax
  0000000000000020: 0F B6 07           movzx       eax,byte ptr [rdi]
  0000000000000023: 84 C0              test        al,al
  0000000000000025: 75 0B              jne         0000000000000032
  0000000000000027: B8 01 00 00 00     mov         eax,1
  000000000000002C: 86 07              xchg        al,byte ptr [rdi]
  000000000000002E: 84 C0              test        al,al
  0000000000000030: 74 7D              je          00000000000000AF
  0000000000000032: 48 83 FB 7D        cmp         rbx,7Dh
  0000000000000036: 73 07              jae         000000000000003F
  0000000000000038: F3 90              pause
  000000000000003A: 48 FF C3           inc         rbx
  000000000000003D: EB E1              jmp         0000000000000020
  000000000000003F: 48 81 FB FA 00 00  cmp         rbx,0FAh
                    00
  0000000000000046: 73 0A              jae         0000000000000052
  0000000000000048: E8 00 00 00 00     call        _Thrd_yield
  000000000000004D: 48 FF C3           inc         rbx
  0000000000000050: EB CE              jmp         0000000000000020
  0000000000000052: E8 00 00 00 00     call        _Xtime_get_ticks
  0000000000000057: 48 6B C8 64        imul        rcx,rax,64h
  000000000000005B: 48 89 44 24 50     mov         qword ptr [rsp+50h],rax
  0000000000000060: 48 8B C6           mov         rax,rsi
  0000000000000063: 48 89 4C 24 58     mov         qword ptr [rsp+58h],rcx
  0000000000000068: 48 81 C1 40 42 0F  add         rcx,0F4240h
                    00
  000000000000006F: 48 F7 E9           imul        rcx
  0000000000000072: 48 C1 FA 1A        sar         rdx,1Ah
  0000000000000076: 48 8B C2           mov         rax,rdx
  0000000000000079: 48 C1 E8 3F        shr         rax,3Fh
  000000000000007D: 48 03 D0           add         rdx,rax
  0000000000000080: 48 69 C2 00 CA 9A  imul        rax,rdx,3B9ACA00h
                    3B
  0000000000000087: 48 89 54 24 20     mov         qword ptr [rsp+20h],rdx
  000000000000008C: 2B C8              sub         ecx,eax
  000000000000008E: 89 4C 24 28        mov         dword ptr [rsp+28h],ecx
  0000000000000092: 48 8D 4C 24 30     lea         rcx,[rsp+30h]
  0000000000000097: 0F 28 44 24 20     movaps      xmm0,xmmword ptr [rsp+20h]
  000000000000009C: 66 0F 7F 44 24 30  movdqa      xmmword ptr [rsp+30h],xmm0
  00000000000000A2: E8 00 00 00 00     call        _Thrd_sleep
  00000000000000A7: 48 FF C3           inc         rbx
  00000000000000AA: E9 71 FF FF FF     jmp         0000000000000020
  00000000000000AF: 48 8B 5C 24 60     mov         rbx,qword ptr [rsp+60h]
  00000000000000B4: 48 8B 74 24 68     mov         rsi,qword ptr [rsp+68h]
  00000000000000B9: 48 83 C4 40        add         rsp,40h
  00000000000000BD: 5F                 pop         rdi
  00000000000000BE: C3                 ret

  000000000000002E: 90                 nop
  000000000000002F: 48 8B 4B 20        mov         rcx,qword ptr [rbx+20h]
  0000000000000033: 48 85 C9           test        rcx,rcx
  0000000000000036: 74 30              je          0000000000000068
  0000000000000038: 0F B6 41 19        movzx       eax,byte ptr [rcx+19h]
  000000000000003C: 84 C0              test        al,al
  000000000000003E: 75 11              jne         0000000000000051
  0000000000000040: B8 01 00 00 00     mov         eax,1
  0000000000000045: 86 41 19           xchg        al,byte ptr [rcx+19h]
  0000000000000048: 84 C0              test        al,al
  000000000000004A: 0F 95 C0           setne       al
  000000000000004D: 84 C0              test        al,al
  000000000000004F: 74 17              je          0000000000000068
  0000000000000051: C6 43 19 00        mov         byte ptr [rbx+19h],0
  0000000000000055: 48 8D 4B 19        lea         rcx,[rbx+19h]
  0000000000000059: E8 00 00 00 00     call        replaced
  0000000000000000: 48 89 5C 24 18     mov         qword ptr [rsp+18h],rbx
  0000000000000005: 48 89 74 24 20     mov         qword ptr [rsp+20h],rsi
  000000000000000A: 57                 push        rdi
  000000000000000B: 48 83 EC 40        sub         rsp,40h
  000000000000000F: 48 8B F9           mov         rdi,rcx
  0000000000000012: 33 DB              xor         ebx,ebx
  0000000000000014: 48 BE B3 94 D6 26  mov         rsi,112E0BE826D694B3h
                    E8 0B 2E 11
  000000000000001E: 66 90              xchg        ax,ax
  0000000000000020: 0F B6 07           movzx       eax,byte ptr [rdi]
  0000000000000023: 84 C0              test        al,al
  0000000000000025: 75 0B              jne         0000000000000032
  0000000000000027: B8 01 00 00 00     mov         eax,1
  000000000000002C: 86 07              xchg        al,byte ptr [rdi]
  000000000000002E: 84 C0              test        al,al
  0000000000000030: 74 7D              je          00000000000000AF
  0000000000000032: 48 83 FB 7D        cmp         rbx,7Dh
  0000000000000036: 73 07              jae         000000000000003F
  0000000000000038: F3 90              pause
  000000000000003A: 48 FF C3           inc         rbx
  000000000000003D: EB E1              jmp         0000000000000020
  000000000000003F: 48 81 FB FA 00 00  cmp         rbx,0FAh
                    00
  0000000000000046: 73 0A              jae         0000000000000052
  0000000000000048: E8 00 00 00 00     call        _Thrd_yield
  000000000000004D: 48 FF C3           inc         rbx
  0000000000000050: EB CE              jmp         0000000000000020
  0000000000000052: E8 00 00 00 00     call        _Xtime_get_ticks
  0000000000000057: 48 6B C8 64        imul        rcx,rax,64h
  000000000000005B: 48 89 44 24 50     mov         qword ptr [rsp+50h],rax
  0000000000000060: 48 8B C6           mov         rax,rsi
  0000000000000063: 48 89 4C 24 58     mov         qword ptr [rsp+58h],rcx
  0000000000000068: 48 81 C1 40 42 0F  add         rcx,0F4240h
                    00
  000000000000006F: 48 F7 E9           imul        rcx
  0000000000000072: 48 C1 FA 1A        sar         rdx,1Ah
  0000000000000076: 48 8B C2           mov         rax,rdx
  0000000000000079: 48 C1 E8 3F        shr         rax,3Fh
  000000000000007D: 48 03 D0           add         rdx,rax
  0000000000000080: 48 69 C2 00 CA 9A  imul        rax,rdx,3B9ACA00h
                    3B
  0000000000000087: 48 89 54 24 20     mov         qword ptr [rsp+20h],rdx
  000000000000008C: 2B C8              sub         ecx,eax
  000000000000008E: 89 4C 24 28        mov         dword ptr [rsp+28h],ecx
  0000000000000092: 48 8D 4C 24 30     lea         rcx,[rsp+30h]
  0000000000000097: 0F 28 44 24 20     movaps      xmm0,xmmword ptr [rsp+20h]
  000000000000009C: 66 0F 7F 44 24 30  movdqa      xmmword ptr [rsp+30h],xmm0
  00000000000000A2: E8 00 00 00 00     call        _Thrd_sleep
  00000000000000A7: 48 FF C3           inc         rbx
  00000000000000AA: E9 71 FF FF FF     jmp         0000000000000020
  00000000000000AF: 48 8B 5C 24 60     mov         rbx,qword ptr [rsp+60h]
  00000000000000B4: 48 8B 74 24 68     mov         rsi,qword ptr [rsp+68h]
  00000000000000B9: 48 83 C4 40        add         rsp,40h
  00000000000000BD: 5F                 pop         rdi
  00000000000000BE: C3                 ret

  000000000000005E: 90                 nop
  000000000000005F: 48 8B 4B 20        mov         rcx,qword ptr [rbx+20h]
  0000000000000063: 48 85 C9           test        rcx,rcx
  0000000000000066: 75 D0              jne         0000000000000038
  0000000000000068: C6 47 10 00        mov         byte ptr [rdi+10h],0
  000000000000006C: 0F B6 4B 10        movzx       ecx,byte ptr [rbx+10h]
  0000000000000070: 83 E9 01           sub         ecx,1
  0000000000000073: 74 20              je          0000000000000095
  0000000000000075: 83 E9 01           sub         ecx,1
  0000000000000078: 74 13              je          000000000000008D
  000000000000007A: 83 F9 01           cmp         ecx,1
  000000000000007D: 75 1A              jne         0000000000000099
  000000000000007F: 48 8B D3           mov         rdx,rbx
  0000000000000082: 48 8B CF           mov         rcx,rdi
  0000000000000085: E8 00 00 00 00     call        ?__ExceptionPtrCopy@@YAXPEAXPEBX@Z
  000000000000008A: 90                 nop
  000000000000008B: EB 0C              jmp         0000000000000099
  000000000000008D: 0F 10 03           movups      xmm0,xmmword ptr [rbx]
  0000000000000090: 0F 11 07           movups      xmmword ptr [rdi],xmm0
  0000000000000093: EB 04              jmp         0000000000000099
  0000000000000095: 8B 03              mov         eax,dword ptr [rbx]
  0000000000000097: 89 07              mov         dword ptr [rdi],eax
  0000000000000099: 0F B6 43 10        movzx       eax,byte ptr [rbx+10h]
  000000000000009D: 88 47 10           mov         byte ptr [rdi+10h],al
  00000000000000A0: 0F B6 4B 18        movzx       ecx,byte ptr [rbx+18h]
  00000000000000A4: 88 4F 18           mov         byte ptr [rdi+18h],cl
  00000000000000A7: 0F B6 43 1A        movzx       eax,byte ptr [rbx+1Ah]
  00000000000000AB: 88 47 1A           mov         byte ptr [rdi+1Ah],al
  00000000000000AE: 48 8B 43 20        mov         rax,qword ptr [rbx+20h]
  00000000000000B2: 48 89 47 20        mov         qword ptr [rdi+20h],rax
  00000000000000B6: 84 C9              test        cl,cl
  00000000000000B8: 74 0C              je          00000000000000C6
  00000000000000BA: 48 8D 47 19        lea         rax,[rdi+19h]
  00000000000000BE: 48 85 C0           test        rax,rax
  00000000000000C1: 74 03              je          00000000000000C6
  00000000000000C3: C6 00 00           mov         byte ptr [rax],0
  00000000000000C6: 48 C7 43 20 00 00  mov         qword ptr [rbx+20h],0
                    00 00
  00000000000000CE: 48 8B 47 20        mov         rax,qword ptr [rdi+20h]
  00000000000000D2: 48 85 C0           test        rax,rax
  00000000000000D5: 74 04              je          00000000000000DB
  00000000000000D7: 48 89 78 20        mov         qword ptr [rax+20h],rdi
  00000000000000DB: 48 8B C7           mov         rax,rdi
  00000000000000DE: 48 8B 5C 24 40     mov         rbx,qword ptr [rsp+40h]
  00000000000000E3: 48 8B 74 24 48     mov         rsi,qword ptr [rsp+48h]
  00000000000000E8: 48 83 C4 30        add         rsp,30h
  00000000000000EC: 5F                 pop         rdi
  00000000000000ED: C3                 ret

  000000000000003D: 40 38 7D C0        cmp         byte ptr [rbp-40h],dil
  0000000000000041: 74 11              je          0000000000000054
  0000000000000043: 40 88 7D E9        mov         byte ptr [rbp-17h],dil
  0000000000000047: 48 8B 4D C8        mov         rcx,qword ptr [rbp-38h]
  000000000000004B: 48 85 C9           test        rcx,rcx
  000000000000004E: 74 08              je          0000000000000058
  0000000000000050: 40 88 79 19        mov         byte ptr [rcx+19h],dil
  0000000000000054: 48 8B 4D C8        mov         rcx,qword ptr [rbp-38h]
  0000000000000058: 48 85 C9           test        rcx,rcx
  000000000000005B: 75 13              jne         0000000000000070
  000000000000005D: 38 4D B8           cmp         byte ptr [rbp-48h],cl
  0000000000000060: 0F 95 C0           setne       al
  0000000000000063: 84 C0              test        al,al
  0000000000000065: 75 09              jne         0000000000000070
  0000000000000067: 38 45 C2           cmp         byte ptr [rbp-3Eh],al
  000000000000006A: 0F 84 8D 00 00 00  je          00000000000000FD
  0000000000000070: 48 8B DF           mov         rbx,rdi
  0000000000000073: 38 5D C0           cmp         byte ptr [rbp-40h],bl
  0000000000000076: 75 05              jne         000000000000007D
  0000000000000078: 48 8B D9           mov         rbx,rcx
  000000000000007B: EB 3A              jmp         00000000000000B7
  000000000000007D: 48 8D 4D C1        lea         rcx,[rbp-3Fh]
  0000000000000081: E8 00 00 00 00     call        replaced
  0000000000000000: 48 89 5C 24 18     mov         qword ptr [rsp+18h],rbx
  0000000000000005: 48 89 74 24 20     mov         qword ptr [rsp+20h],rsi
  000000000000000A: 57                 push        rdi
  000000000000000B: 48 83 EC 40        sub         rsp,40h
  000000000000000F: 48 8B F9           mov         rdi,rcx
  0000000000000012: 33 DB              xor         ebx,ebx
  0000000000000014: 48 BE B3 94 D6 26  mov         rsi,112E0BE826D694B3h
                    E8 0B 2E 11
  000000000000001E: 66 90              xchg        ax,ax
  0000000000000020: 0F B6 07           movzx       eax,byte ptr [rdi]
  0000000000000023: 84 C0              test        al,al
  0000000000000025: 75 0B              jne         0000000000000032
  0000000000000027: B8 01 00 00 00     mov         eax,1
  000000000000002C: 86 07              xchg        al,byte ptr [rdi]
  000000000000002E: 84 C0              test        al,al
  0000000000000030: 74 7D              je          00000000000000AF
  0000000000000032: 48 83 FB 7D        cmp         rbx,7Dh
  0000000000000036: 73 07              jae         000000000000003F
  0000000000000038: F3 90              pause
  000000000000003A: 48 FF C3           inc         rbx
  000000000000003D: EB E1              jmp         0000000000000020
  000000000000003F: 48 81 FB FA 00 00  cmp         rbx,0FAh
                    00
  0000000000000046: 73 0A              jae         0000000000000052
  0000000000000048: E8 00 00 00 00     call        _Thrd_yield
  000000000000004D: 48 FF C3           inc         rbx
  0000000000000050: EB CE              jmp         0000000000000020
  0000000000000052: E8 00 00 00 00     call        _Xtime_get_ticks
  0000000000000057: 48 6B C8 64        imul        rcx,rax,64h
  000000000000005B: 48 89 44 24 50     mov         qword ptr [rsp+50h],rax
  0000000000000060: 48 8B C6           mov         rax,rsi
  0000000000000063: 48 89 4C 24 58     mov         qword ptr [rsp+58h],rcx
  0000000000000068: 48 81 C1 40 42 0F  add         rcx,0F4240h
                    00
  000000000000006F: 48 F7 E9           imul        rcx
  0000000000000072: 48 C1 FA 1A        sar         rdx,1Ah
  0000000000000076: 48 8B C2           mov         rax,rdx
  0000000000000079: 48 C1 E8 3F        shr         rax,3Fh
  000000000000007D: 48 03 D0           add         rdx,rax
  0000000000000080: 48 69 C2 00 CA 9A  imul        rax,rdx,3B9ACA00h
                    3B
  0000000000000087: 48 89 54 24 20     mov         qword ptr [rsp+20h],rdx
  000000000000008C: 2B C8              sub         ecx,eax
  000000000000008E: 89 4C 24 28        mov         dword ptr [rsp+28h],ecx
  0000000000000092: 48 8D 4C 24 30     lea         rcx,[rsp+30h]
  0000000000000097: 0F 28 44 24 20     movaps      xmm0,xmmword ptr [rsp+20h]
  000000000000009C: 66 0F 7F 44 24 30  movdqa      xmmword ptr [rsp+30h],xmm0
  00000000000000A2: E8 00 00 00 00     call        _Thrd_sleep
  00000000000000A7: 48 FF C3           inc         rbx
  00000000000000AA: E9 71 FF FF FF     jmp         0000000000000020
  00000000000000AF: 48 8B 5C 24 60     mov         rbx,qword ptr [rsp+60h]
  00000000000000B4: 48 8B 74 24 68     mov         rsi,qword ptr [rsp+68h]
  00000000000000B9: 48 83 C4 40        add         rsp,40h
  00000000000000BD: 5F                 pop         rdi
  00000000000000BE: C3                 ret

  0000000000000086: 48 8B 4D C8        mov         rcx,qword ptr [rbp-38h]
  000000000000008A: 48 85 C9           test        rcx,rcx
  000000000000008D: 48 8B D1           mov         rdx,rcx
  0000000000000090: 74 32              je          00000000000000C4
  0000000000000092: 0F B6 41 19        movzx       eax,byte ptr [rcx+19h]
  0000000000000096: 84 C0              test        al,al
  0000000000000098: 75 11              jne         00000000000000AB
  000000000000009A: B8 01 00 00 00     mov         eax,1
  000000000000009F: 86 41 19           xchg        al,byte ptr [rcx+19h]
  00000000000000A2: 84 C0              test        al,al
  00000000000000A4: 0F 95 C0           setne       al
  00000000000000A7: 84 C0              test        al,al
  00000000000000A9: 74 05              je          00000000000000B0
  00000000000000AB: 88 5D C1           mov         byte ptr [rbp-3Fh],bl
  00000000000000AE: EB CD              jmp         000000000000007D
  00000000000000B0: 48 8B DA           mov         rbx,rdx
  00000000000000B3: 48 8B 4D C8        mov         rcx,qword ptr [rbp-38h]
  00000000000000B7: 48 85 C9           test        rcx,rcx
  00000000000000BA: 74 08              je          00000000000000C4
  00000000000000BC: 48 89 79 20        mov         qword ptr [rcx+20h],rdi
  00000000000000C0: 48 89 7D C8        mov         qword ptr [rbp-38h],rdi
  00000000000000C4: 0F B6 4D B8        movzx       ecx,byte ptr [rbp-48h]
  00000000000000C8: 83 E9 01           sub         ecx,1
  00000000000000CB: 74 13              je          00000000000000E0
  00000000000000CD: 83 E9 01           sub         ecx,1
  00000000000000D0: 74 0E              je          00000000000000E0
  00000000000000D2: 83 F9 01           cmp         ecx,1
  00000000000000D5: 75 0D              jne         00000000000000E4
  00000000000000D7: 48 8D 4D A8        lea         rcx,[rbp-58h]
  00000000000000DB: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  00000000000000E0: C6 45 B8 00        mov         byte ptr [rbp-48h],0
  00000000000000E4: 48 85 DB           test        rbx,rbx
  00000000000000E7: 74 0A              je          00000000000000F3
  00000000000000E9: 80 7B 18 00        cmp         byte ptr [rbx+18h],0
  00000000000000ED: 74 04              je          00000000000000F3
  00000000000000EF: C6 43 19 00        mov         byte ptr [rbx+19h],0
  00000000000000F3: 80 7D C0 00        cmp         byte ptr [rbp-40h],0
  00000000000000F7: 74 04              je          00000000000000FD
  00000000000000F9: C6 45 C1 00        mov         byte ptr [rbp-3Fh],0
  00000000000000FD: 0F B6 4D B8        movzx       ecx,byte ptr [rbp-48h]
  0000000000000101: 83 E9 01           sub         ecx,1
  0000000000000104: 74 13              je          0000000000000119
  0000000000000106: 83 E9 01           sub         ecx,1
  0000000000000109: 74 0E              je          0000000000000119
  000000000000010B: 83 F9 01           cmp         ecx,1
  000000000000010E: 75 0D              jne         000000000000011D
  0000000000000110: 48 8D 4D A8        lea         rcx,[rbp-58h]
  0000000000000114: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  0000000000000119: C6 45 B8 00        mov         byte ptr [rbp-48h],0
  000000000000011D: 48 8B 4D F0        mov         rcx,qword ptr [rbp-10h]
  0000000000000121: 48 85 C9           test        rcx,rcx
  0000000000000124: 75 13              jne         0000000000000139
  0000000000000126: 38 4D E0           cmp         byte ptr [rbp-20h],cl
  0000000000000129: 0F 95 C0           setne       al
  000000000000012C: 84 C0              test        al,al
  000000000000012E: 75 09              jne         0000000000000139
  0000000000000130: 38 45 EA           cmp         byte ptr [rbp-16h],al
  0000000000000133: 0F 84 8D 00 00 00  je          00000000000001C6
  0000000000000139: 48 8B DF           mov         rbx,rdi
  000000000000013C: 38 5D E8           cmp         byte ptr [rbp-18h],bl
  000000000000013F: 75 05              jne         0000000000000146
  0000000000000141: 48 8B D9           mov         rbx,rcx
  0000000000000144: EB 3A              jmp         0000000000000180
  0000000000000146: 48 8D 4D E9        lea         rcx,[rbp-17h]
  000000000000014A: E8 00 00 00 00     call        replaced
  0000000000000000: 48 89 5C 24 18     mov         qword ptr [rsp+18h],rbx
  0000000000000005: 48 89 74 24 20     mov         qword ptr [rsp+20h],rsi
  000000000000000A: 57                 push        rdi
  000000000000000B: 48 83 EC 40        sub         rsp,40h
  000000000000000F: 48 8B F9           mov         rdi,rcx
  0000000000000012: 33 DB              xor         ebx,ebx
  0000000000000014: 48 BE B3 94 D6 26  mov         rsi,112E0BE826D694B3h
                    E8 0B 2E 11
  000000000000001E: 66 90              xchg        ax,ax
  0000000000000020: 0F B6 07           movzx       eax,byte ptr [rdi]
  0000000000000023: 84 C0              test        al,al
  0000000000000025: 75 0B              jne         0000000000000032
  0000000000000027: B8 01 00 00 00     mov         eax,1
  000000000000002C: 86 07              xchg        al,byte ptr [rdi]
  000000000000002E: 84 C0              test        al,al
  0000000000000030: 74 7D              je          00000000000000AF
  0000000000000032: 48 83 FB 7D        cmp         rbx,7Dh
  0000000000000036: 73 07              jae         000000000000003F
  0000000000000038: F3 90              pause
  000000000000003A: 48 FF C3           inc         rbx
  000000000000003D: EB E1              jmp         0000000000000020
  000000000000003F: 48 81 FB FA 00 00  cmp         rbx,0FAh
                    00
  0000000000000046: 73 0A              jae         0000000000000052
  0000000000000048: E8 00 00 00 00     call        _Thrd_yield
  000000000000004D: 48 FF C3           inc         rbx
  0000000000000050: EB CE              jmp         0000000000000020
  0000000000000052: E8 00 00 00 00     call        _Xtime_get_ticks
  0000000000000057: 48 6B C8 64        imul        rcx,rax,64h
  000000000000005B: 48 89 44 24 50     mov         qword ptr [rsp+50h],rax
  0000000000000060: 48 8B C6           mov         rax,rsi
  0000000000000063: 48 89 4C 24 58     mov         qword ptr [rsp+58h],rcx
  0000000000000068: 48 81 C1 40 42 0F  add         rcx,0F4240h
                    00
  000000000000006F: 48 F7 E9           imul        rcx
  0000000000000072: 48 C1 FA 1A        sar         rdx,1Ah
  0000000000000076: 48 8B C2           mov         rax,rdx
  0000000000000079: 48 C1 E8 3F        shr         rax,3Fh
  000000000000007D: 48 03 D0           add         rdx,rax
  0000000000000080: 48 69 C2 00 CA 9A  imul        rax,rdx,3B9ACA00h
                    3B
  0000000000000087: 48 89 54 24 20     mov         qword ptr [rsp+20h],rdx
  000000000000008C: 2B C8              sub         ecx,eax
  000000000000008E: 89 4C 24 28        mov         dword ptr [rsp+28h],ecx
  0000000000000092: 48 8D 4C 24 30     lea         rcx,[rsp+30h]
  0000000000000097: 0F 28 44 24 20     movaps      xmm0,xmmword ptr [rsp+20h]
  000000000000009C: 66 0F 7F 44 24 30  movdqa      xmmword ptr [rsp+30h],xmm0
  00000000000000A2: E8 00 00 00 00     call        _Thrd_sleep
  00000000000000A7: 48 FF C3           inc         rbx
  00000000000000AA: E9 71 FF FF FF     jmp         0000000000000020
  00000000000000AF: 48 8B 5C 24 60     mov         rbx,qword ptr [rsp+60h]
  00000000000000B4: 48 8B 74 24 68     mov         rsi,qword ptr [rsp+68h]
  00000000000000B9: 48 83 C4 40        add         rsp,40h
  00000000000000BD: 5F                 pop         rdi
  00000000000000BE: C3                 ret

  000000000000014F: 48 8B 4D F0        mov         rcx,qword ptr [rbp-10h]
  0000000000000153: 48 85 C9           test        rcx,rcx
  0000000000000156: 48 8B D1           mov         rdx,rcx
  0000000000000159: 74 32              je          000000000000018D
  000000000000015B: 0F B6 41 19        movzx       eax,byte ptr [rcx+19h]
  000000000000015F: 84 C0              test        al,al
  0000000000000161: 75 11              jne         0000000000000174
  0000000000000163: B8 01 00 00 00     mov         eax,1
  0000000000000168: 86 41 19           xchg        al,byte ptr [rcx+19h]
  000000000000016B: 84 C0              test        al,al
  000000000000016D: 0F 95 C0           setne       al
  0000000000000170: 84 C0              test        al,al
  0000000000000172: 74 05              je          0000000000000179
  0000000000000174: 88 5D E9           mov         byte ptr [rbp-17h],bl
  0000000000000177: EB CD              jmp         0000000000000146
  0000000000000179: 48 8B DA           mov         rbx,rdx
  000000000000017C: 48 8B 4D F0        mov         rcx,qword ptr [rbp-10h]
  0000000000000180: 48 85 C9           test        rcx,rcx
  0000000000000183: 74 08              je          000000000000018D
  0000000000000185: 48 89 79 20        mov         qword ptr [rcx+20h],rdi
  0000000000000189: 48 89 7D F0        mov         qword ptr [rbp-10h],rdi
  000000000000018D: 0F B6 4D E0        movzx       ecx,byte ptr [rbp-20h]
  0000000000000191: 83 E9 01           sub         ecx,1
  0000000000000194: 74 13              je          00000000000001A9
  0000000000000196: 83 E9 01           sub         ecx,1
  0000000000000199: 74 0E              je          00000000000001A9
  000000000000019B: 83 F9 01           cmp         ecx,1
  000000000000019E: 75 0D              jne         00000000000001AD
  00000000000001A0: 48 8D 4D D0        lea         rcx,[rbp-30h]
  00000000000001A4: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  00000000000001A9: C6 45 E0 00        mov         byte ptr [rbp-20h],0
  00000000000001AD: 48 85 DB           test        rbx,rbx
  00000000000001B0: 74 0A              je          00000000000001BC
  00000000000001B2: 80 7B 18 00        cmp         byte ptr [rbx+18h],0
  00000000000001B6: 74 04              je          00000000000001BC
  00000000000001B8: C6 43 19 00        mov         byte ptr [rbx+19h],0
  00000000000001BC: 80 7D E8 00        cmp         byte ptr [rbp-18h],0
  00000000000001C0: 74 04              je          00000000000001C6
  00000000000001C2: C6 45 E9 00        mov         byte ptr [rbp-17h],0
  00000000000001C6: 0F B6 4D E0        movzx       ecx,byte ptr [rbp-20h]
  00000000000001CA: 83 E9 01           sub         ecx,1
  00000000000001CD: 74 14              je          00000000000001E3
  00000000000001CF: 83 E9 01           sub         ecx,1
  00000000000001D2: 74 0F              je          00000000000001E3
  00000000000001D4: 83 F9 01           cmp         ecx,1
  00000000000001D7: 75 0A              jne         00000000000001E3
  00000000000001D9: 48 8D 4D D0        lea         rcx,[rbp-30h]
  00000000000001DD: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  00000000000001E2: 90                 nop
  00000000000001E3: 4C 8D 9C 24 80 00  lea         r11,[rsp+80h]
                    00 00
  00000000000001EB: 49 8B 5B 10        mov         rbx,qword ptr [r11+10h]
  00000000000001EF: 49 8B 7B 18        mov         rdi,qword ptr [r11+18h]
  00000000000001F3: 49 8B E3           mov         rsp,r11
  00000000000001F6: 5D                 pop         rbp
  00000000000001F7: C3                 ret
