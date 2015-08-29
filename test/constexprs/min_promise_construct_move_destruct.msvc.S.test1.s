  0000000000000000: 48 8B C4           mov         rax,rsp
  0000000000000003: 55                 push        rbp
  0000000000000004: 48 8D 68 A1        lea         rbp,[rax-5Fh]
  0000000000000008: 48 81 EC B0 00 00  sub         rsp,0B0h
                    00
  000000000000000F: 48 C7 45 47 FE FF  mov         qword ptr [rbp+47h],0FFFFFFFFFFFFFFFEh
                    FF FF
  0000000000000017: 48 89 58 10        mov         qword ptr [rax+10h],rbx
  000000000000001B: 48 89 78 18        mov         qword ptr [rax+18h],rdi
  000000000000001F: C6 45 D7 00        mov         byte ptr [rbp-29h],0
  0000000000000023: C6 45 DF 00        mov         byte ptr [rbp-21h],0
  0000000000000027: C6 45 E1 00        mov         byte ptr [rbp-1Fh],0
  000000000000002B: 0F 57 C0           xorps       xmm0,xmm0
  000000000000002E: 66 0F 7F 45 E7     movdqa      xmmword ptr [rbp-19h],xmm0
  0000000000000033: 33 FF              xor         edi,edi
  0000000000000035: 48 89 7D F7        mov         qword ptr [rbp-9],rdi
  0000000000000039: 48 89 7D 67        mov         qword ptr [rbp+67h],rdi
  000000000000003D: 48 89 7D FF        mov         qword ptr [rbp-1],rdi
  0000000000000041: 48 8D 55 C7        lea         rdx,[rbp-39h]
  0000000000000045: 48 8D 4D 07        lea         rcx,[rbp+7]
  0000000000000049: E8 00 00 00 00     call        replaced
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
  00000000000000C6: 33 C9              xor         ecx,ecx
  00000000000000C8: 48 89 4B 20        mov         qword ptr [rbx+20h],rcx
  00000000000000CC: 48 8B 47 20        mov         rax,qword ptr [rdi+20h]
  00000000000000D0: 48 85 C0           test        rax,rax
  00000000000000D3: 74 04              je          00000000000000D9
  00000000000000D5: 48 89 78 20        mov         qword ptr [rax+20h],rdi
  00000000000000D9: 48 8B 43 28        mov         rax,qword ptr [rbx+28h]
  00000000000000DD: 48 89 47 28        mov         qword ptr [rdi+28h],rax
  00000000000000E1: 48 8B 43 30        mov         rax,qword ptr [rbx+30h]
  00000000000000E5: 48 89 47 30        mov         qword ptr [rdi+30h],rax
  00000000000000E9: 48 89 4B 30        mov         qword ptr [rbx+30h],rcx
  00000000000000ED: 48 8B 43 38        mov         rax,qword ptr [rbx+38h]
  00000000000000F1: 48 89 4B 38        mov         qword ptr [rbx+38h],rcx
  00000000000000F5: 48 89 47 38        mov         qword ptr [rdi+38h],rax
  00000000000000F9: 48 8B C7           mov         rax,rdi
  00000000000000FC: 48 8B 5C 24 40     mov         rbx,qword ptr [rsp+40h]
  0000000000000101: 48 8B 74 24 48     mov         rsi,qword ptr [rsp+48h]
  0000000000000106: 48 83 C4 30        add         rsp,30h
  000000000000010A: 5F                 pop         rdi
  000000000000010B: C3                 ret

  000000000000004E: 40 38 7D 1F        cmp         byte ptr [rbp+1Fh],dil
  0000000000000052: 74 11              je          0000000000000065
  0000000000000054: 40 88 7D E0        mov         byte ptr [rbp-20h],dil
  0000000000000058: 48 8B 45 27        mov         rax,qword ptr [rbp+27h]
  000000000000005C: 48 85 C0           test        rax,rax
  000000000000005F: 74 08              je          0000000000000069
  0000000000000061: 40 88 78 19        mov         byte ptr [rax+19h],dil
  0000000000000065: 48 8B 45 27        mov         rax,qword ptr [rbp+27h]
  0000000000000069: 80 7D 21 00        cmp         byte ptr [rbp+21h],0
  000000000000006D: 0F 84 96 00 00 00  je          0000000000000109
  0000000000000073: 48 85 C0           test        rax,rax
  0000000000000076: 0F 84 8D 00 00 00  je          0000000000000109
  000000000000007C: 48 8B DF           mov         rbx,rdi
  000000000000007F: 38 5D 1F           cmp         byte ptr [rbp+1Fh],bl
  0000000000000082: 75 05              jne         0000000000000089
  0000000000000084: 48 8B D8           mov         rbx,rax
  0000000000000087: EB 36              jmp         00000000000000BF
  0000000000000089: 48 8D 4D 20        lea         rcx,[rbp+20h]
  000000000000008D: E8 00 00 00 00     call        replaced
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

  0000000000000092: 48 8B 4D 27        mov         rcx,qword ptr [rbp+27h]
  0000000000000096: 48 85 C9           test        rcx,rcx
  0000000000000099: 48 8B D1           mov         rdx,rcx
  000000000000009C: 74 2E              je          00000000000000CC
  000000000000009E: 0F B6 41 19        movzx       eax,byte ptr [rcx+19h]
  00000000000000A2: 84 C0              test        al,al
  00000000000000A4: 75 11              jne         00000000000000B7
  00000000000000A6: B8 01 00 00 00     mov         eax,1
  00000000000000AB: 86 41 19           xchg        al,byte ptr [rcx+19h]
  00000000000000AE: 84 C0              test        al,al
  00000000000000B0: 0F 95 C0           setne       al
  00000000000000B3: 84 C0              test        al,al
  00000000000000B5: 74 05              je          00000000000000BC
  00000000000000B7: 88 5D 20           mov         byte ptr [rbp+20h],bl
  00000000000000BA: EB CD              jmp         0000000000000089
  00000000000000BC: 48 8B DA           mov         rbx,rdx
  00000000000000BF: 48 85 DB           test        rbx,rbx
  00000000000000C2: 74 08              je          00000000000000CC
  00000000000000C4: C6 43 1A 01        mov         byte ptr [rbx+1Ah],1
  00000000000000C8: 48 89 7B 20        mov         qword ptr [rbx+20h],rdi
  00000000000000CC: 48 89 7D 27        mov         qword ptr [rbp+27h],rdi
  00000000000000D0: 0F B6 4D 17        movzx       ecx,byte ptr [rbp+17h]
  00000000000000D4: 83 E9 01           sub         ecx,1
  00000000000000D7: 74 13              je          00000000000000EC
  00000000000000D9: 83 E9 01           sub         ecx,1
  00000000000000DC: 74 0E              je          00000000000000EC
  00000000000000DE: 83 F9 01           cmp         ecx,1
  00000000000000E1: 75 0D              jne         00000000000000F0
  00000000000000E3: 48 8D 4D 07        lea         rcx,[rbp+7]
  00000000000000E7: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  00000000000000EC: C6 45 17 00        mov         byte ptr [rbp+17h],0
  00000000000000F0: 80 7D 1F 00        cmp         byte ptr [rbp+1Fh],0
  00000000000000F4: 74 04              je          00000000000000FA
  00000000000000F6: C6 45 20 00        mov         byte ptr [rbp+20h],0
  00000000000000FA: 48 85 DB           test        rbx,rbx
  00000000000000FD: 74 0A              je          0000000000000109
  00000000000000FF: 80 7B 18 00        cmp         byte ptr [rbx+18h],0
  0000000000000103: 74 04              je          0000000000000109
  0000000000000105: C6 43 19 00        mov         byte ptr [rbx+19h],0
  0000000000000109: 48 8B 55 3F        mov         rdx,qword ptr [rbp+3Fh]
  000000000000010D: 48 85 D2           test        rdx,rdx
  0000000000000110: 74 09              je          000000000000011B
  0000000000000112: 48 8D 4D 3F        lea         rcx,[rbp+3Fh]
  0000000000000116: E8 00 00 00 00     call        replaced
  0000000000000000: 48 85 D2           test        rdx,rdx
  0000000000000003: 74 61              je          0000000000000066
  0000000000000005: 57                 push        rdi
  0000000000000006: 48 83 EC 20        sub         rsp,20h
  000000000000000A: 48 89 5C 24 30     mov         qword ptr [rsp+30h],rbx
  000000000000000F: 48 8B FA           mov         rdi,rdx
  0000000000000012: 48 8B 5A 08        mov         rbx,qword ptr [rdx+8]
  0000000000000016: 48 85 DB           test        rbx,rbx
  0000000000000019: 74 34              je          000000000000004F
  000000000000001B: 48 89 74 24 38     mov         qword ptr [rsp+38h],rsi
  0000000000000020: 83 CE FF           or          esi,0FFFFFFFFh
  0000000000000023: 8B C6              mov         eax,esi
  0000000000000025: F0 0F C1 43 08     lock xadd   dword ptr [rbx+8],eax
  000000000000002A: 83 F8 01           cmp         eax,1
  000000000000002D: 75 1B              jne         000000000000004A
  000000000000002F: 48 8B 03           mov         rax,qword ptr [rbx]
  0000000000000032: 48 8B CB           mov         rcx,rbx
  0000000000000035: FF 10              call        qword ptr [rax]
  0000000000000037: F0 0F C1 73 0C     lock xadd   dword ptr [rbx+0Ch],esi
  000000000000003C: 83 FE 01           cmp         esi,1
  000000000000003F: 75 09              jne         000000000000004A
  0000000000000041: 48 8B 03           mov         rax,qword ptr [rbx]
  0000000000000044: 48 8B CB           mov         rcx,rbx
  0000000000000047: FF 50 08           call        qword ptr [rax+8]
  000000000000004A: 48 8B 74 24 38     mov         rsi,qword ptr [rsp+38h]
  000000000000004F: BA 10 00 00 00     mov         edx,10h
  0000000000000054: 48 8B CF           mov         rcx,rdi
  0000000000000057: E8 00 00 00 00     call        ??3@YAXPEAX_K@Z
  000000000000005C: 48 8B 5C 24 30     mov         rbx,qword ptr [rsp+30h]
  0000000000000061: 48 83 C4 20        add         rsp,20h
  0000000000000065: 5F                 pop         rdi
  0000000000000066: C3                 ret

  000000000000011B: 48 8B 4D 37        mov         rcx,qword ptr [rbp+37h]
  000000000000011F: 48 85 C9           test        rcx,rcx
  0000000000000122: 74 0B              je          000000000000012F
  0000000000000124: 48 8B 01           mov         rax,qword ptr [rcx]
  0000000000000127: BA 01 00 00 00     mov         edx,1
  000000000000012C: FF 10              call        qword ptr [rax]
  000000000000012E: 90                 nop
  000000000000012F: 0F B6 4D 17        movzx       ecx,byte ptr [rbp+17h]
  0000000000000133: 83 E9 01           sub         ecx,1
  0000000000000136: 74 13              je          000000000000014B
  0000000000000138: 83 E9 01           sub         ecx,1
  000000000000013B: 74 0E              je          000000000000014B
  000000000000013D: 83 F9 01           cmp         ecx,1
  0000000000000140: 75 0D              jne         000000000000014F
  0000000000000142: 48 8D 4D 07        lea         rcx,[rbp+7]
  0000000000000146: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  000000000000014B: C6 45 17 00        mov         byte ptr [rbp+17h],0
  000000000000014F: 80 7D E1 00        cmp         byte ptr [rbp-1Fh],0
  0000000000000153: 0F 84 9A 00 00 00  je          00000000000001F3
  0000000000000159: 48 8B 45 E7        mov         rax,qword ptr [rbp-19h]
  000000000000015D: 48 85 C0           test        rax,rax
  0000000000000160: 0F 84 8D 00 00 00  je          00000000000001F3
  0000000000000166: 48 8B DF           mov         rbx,rdi
  0000000000000169: 38 5D DF           cmp         byte ptr [rbp-21h],bl
  000000000000016C: 75 05              jne         0000000000000173
  000000000000016E: 48 8B D8           mov         rbx,rax
  0000000000000171: EB 36              jmp         00000000000001A9
  0000000000000173: 48 8D 4D E0        lea         rcx,[rbp-20h]
  0000000000000177: E8 00 00 00 00     call        replaced
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

  000000000000017C: 48 8B 4D E7        mov         rcx,qword ptr [rbp-19h]
  0000000000000180: 48 85 C9           test        rcx,rcx
  0000000000000183: 48 8B D1           mov         rdx,rcx
  0000000000000186: 74 2E              je          00000000000001B6
  0000000000000188: 0F B6 41 19        movzx       eax,byte ptr [rcx+19h]
  000000000000018C: 84 C0              test        al,al
  000000000000018E: 75 11              jne         00000000000001A1
  0000000000000190: B8 01 00 00 00     mov         eax,1
  0000000000000195: 86 41 19           xchg        al,byte ptr [rcx+19h]
  0000000000000198: 84 C0              test        al,al
  000000000000019A: 0F 95 C0           setne       al
  000000000000019D: 84 C0              test        al,al
  000000000000019F: 74 05              je          00000000000001A6
  00000000000001A1: 88 5D E0           mov         byte ptr [rbp-20h],bl
  00000000000001A4: EB CD              jmp         0000000000000173
  00000000000001A6: 48 8B DA           mov         rbx,rdx
  00000000000001A9: 48 85 DB           test        rbx,rbx
  00000000000001AC: 74 08              je          00000000000001B6
  00000000000001AE: C6 43 1A 01        mov         byte ptr [rbx+1Ah],1
  00000000000001B2: 48 89 7B 20        mov         qword ptr [rbx+20h],rdi
  00000000000001B6: 48 89 7D E7        mov         qword ptr [rbp-19h],rdi
  00000000000001BA: 0F B6 4D D7        movzx       ecx,byte ptr [rbp-29h]
  00000000000001BE: 83 E9 01           sub         ecx,1
  00000000000001C1: 74 13              je          00000000000001D6
  00000000000001C3: 83 E9 01           sub         ecx,1
  00000000000001C6: 74 0E              je          00000000000001D6
  00000000000001C8: 83 F9 01           cmp         ecx,1
  00000000000001CB: 75 0D              jne         00000000000001DA
  00000000000001CD: 48 8D 4D C7        lea         rcx,[rbp-39h]
  00000000000001D1: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  00000000000001D6: C6 45 D7 00        mov         byte ptr [rbp-29h],0
  00000000000001DA: 80 7D DF 00        cmp         byte ptr [rbp-21h],0
  00000000000001DE: 74 04              je          00000000000001E4
  00000000000001E0: C6 45 E0 00        mov         byte ptr [rbp-20h],0
  00000000000001E4: 48 85 DB           test        rbx,rbx
  00000000000001E7: 74 0A              je          00000000000001F3
  00000000000001E9: 80 7B 18 00        cmp         byte ptr [rbx+18h],0
  00000000000001ED: 74 04              je          00000000000001F3
  00000000000001EF: C6 43 19 00        mov         byte ptr [rbx+19h],0
  00000000000001F3: 48 8B 55 FF        mov         rdx,qword ptr [rbp-1]
  00000000000001F7: 48 85 D2           test        rdx,rdx
  00000000000001FA: 74 09              je          0000000000000205
  00000000000001FC: 48 8D 4D FF        lea         rcx,[rbp-1]
  0000000000000200: E8 00 00 00 00     call        replaced
  0000000000000000: 48 85 D2           test        rdx,rdx
  0000000000000003: 74 61              je          0000000000000066
  0000000000000005: 57                 push        rdi
  0000000000000006: 48 83 EC 20        sub         rsp,20h
  000000000000000A: 48 89 5C 24 30     mov         qword ptr [rsp+30h],rbx
  000000000000000F: 48 8B FA           mov         rdi,rdx
  0000000000000012: 48 8B 5A 08        mov         rbx,qword ptr [rdx+8]
  0000000000000016: 48 85 DB           test        rbx,rbx
  0000000000000019: 74 34              je          000000000000004F
  000000000000001B: 48 89 74 24 38     mov         qword ptr [rsp+38h],rsi
  0000000000000020: 83 CE FF           or          esi,0FFFFFFFFh
  0000000000000023: 8B C6              mov         eax,esi
  0000000000000025: F0 0F C1 43 08     lock xadd   dword ptr [rbx+8],eax
  000000000000002A: 83 F8 01           cmp         eax,1
  000000000000002D: 75 1B              jne         000000000000004A
  000000000000002F: 48 8B 03           mov         rax,qword ptr [rbx]
  0000000000000032: 48 8B CB           mov         rcx,rbx
  0000000000000035: FF 10              call        qword ptr [rax]
  0000000000000037: F0 0F C1 73 0C     lock xadd   dword ptr [rbx+0Ch],esi
  000000000000003C: 83 FE 01           cmp         esi,1
  000000000000003F: 75 09              jne         000000000000004A
  0000000000000041: 48 8B 03           mov         rax,qword ptr [rbx]
  0000000000000044: 48 8B CB           mov         rcx,rbx
  0000000000000047: FF 50 08           call        qword ptr [rax+8]
  000000000000004A: 48 8B 74 24 38     mov         rsi,qword ptr [rsp+38h]
  000000000000004F: BA 10 00 00 00     mov         edx,10h
  0000000000000054: 48 8B CF           mov         rcx,rdi
  0000000000000057: E8 00 00 00 00     call        ??3@YAXPEAX_K@Z
  000000000000005C: 48 8B 5C 24 30     mov         rbx,qword ptr [rsp+30h]
  0000000000000061: 48 83 C4 20        add         rsp,20h
  0000000000000065: 5F                 pop         rdi
  0000000000000066: C3                 ret

  0000000000000205: 48 8B 4D F7        mov         rcx,qword ptr [rbp-9]
  0000000000000209: 48 85 C9           test        rcx,rcx
  000000000000020C: 74 0B              je          0000000000000219
  000000000000020E: 48 8B 01           mov         rax,qword ptr [rcx]
  0000000000000211: BA 01 00 00 00     mov         edx,1
  0000000000000216: FF 10              call        qword ptr [rax]
  0000000000000218: 90                 nop
  0000000000000219: 0F B6 4D D7        movzx       ecx,byte ptr [rbp-29h]
  000000000000021D: 83 E9 01           sub         ecx,1
  0000000000000220: 74 14              je          0000000000000236
  0000000000000222: 83 E9 01           sub         ecx,1
  0000000000000225: 74 0F              je          0000000000000236
  0000000000000227: 83 F9 01           cmp         ecx,1
  000000000000022A: 75 0A              jne         0000000000000236
  000000000000022C: 48 8D 4D C7        lea         rcx,[rbp-39h]
  0000000000000230: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  0000000000000235: 90                 nop
  0000000000000236: 4C 8D 9C 24 B0 00  lea         r11,[rsp+0B0h]
                    00 00
  000000000000023E: 49 8B 5B 18        mov         rbx,qword ptr [r11+18h]
  0000000000000242: 49 8B 7B 20        mov         rdi,qword ptr [r11+20h]
  0000000000000246: 49 8B E3           mov         rsp,r11
  0000000000000249: 5D                 pop         rbp
  000000000000024A: C3                 ret
