  0000000000000000: 48 8B C4           mov         rax,rsp
  0000000000000003: 55                 push        rbp
  0000000000000004: 48 8D 68 A1        lea         rbp,[rax-5Fh]
  0000000000000008: 48 81 EC A0 00 00  sub         rsp,0A0h
                    00
  000000000000000F: 48 C7 45 47 FE FF  mov         qword ptr [rbp+47h],0FFFFFFFFFFFFFFFEh
                    FF FF
  0000000000000017: 48 89 58 08        mov         qword ptr [rax+8],rbx
  000000000000001B: 48 89 78 10        mov         qword ptr [rax+10h],rdi
  000000000000001F: C6 45 0F 00        mov         byte ptr [rbp+0Fh],0
  0000000000000023: C6 45 17 00        mov         byte ptr [rbp+17h],0
  0000000000000027: 33 FF              xor         edi,edi
  0000000000000029: 48 89 7D 1F        mov         qword ptr [rbp+1Fh],rdi
  000000000000002D: 40 88 7D E7        mov         byte ptr [rbp-19h],dil
  0000000000000031: 40 88 7D EF        mov         byte ptr [rbp-11h],dil
  0000000000000035: 48 89 7D F7        mov         qword ptr [rbp-9],rdi
  0000000000000039: 48 8D 55 FF        lea         rdx,[rbp-1]
  000000000000003D: 48 8D 4D D7        lea         rcx,[rbp-29h]
  0000000000000041: E8 00 00 00 00     call        replaced
  0000000000000000: 40 57              push        rdi
  0000000000000002: 48 83 EC 30        sub         rsp,30h
  0000000000000006: 48 C7 44 24 20 FE  mov         qword ptr [rsp+20h],0FFFFFFFFFFFFFFFEh
                    FF FF FF
  000000000000000F: 48 89 5C 24 40     mov         qword ptr [rsp+40h],rbx
  0000000000000014: 48 8B FA           mov         rdi,rdx
  0000000000000017: 48 8B D9           mov         rbx,rcx
  000000000000001A: C6 41 10 00        mov         byte ptr [rcx+10h],0
  000000000000001E: 44 0F B6 42 10     movzx       r8d,byte ptr [rdx+10h]
  0000000000000023: 41 83 E8 01        sub         r8d,1
  0000000000000027: 74 31              je          000000000000005A
  0000000000000029: 41 83 E8 01        sub         r8d,1
  000000000000002D: 74 23              je          0000000000000052
  000000000000002F: 41 83 E8 01        sub         r8d,1
  0000000000000033: 74 15              je          000000000000004A
  0000000000000035: 41 83 F8 01        cmp         r8d,1
  0000000000000039: 75 23              jne         000000000000005E
  000000000000003B: 48 8B 02           mov         rax,qword ptr [rdx]
  000000000000003E: 48 89 01           mov         qword ptr [rcx],rax
  0000000000000041: 48 C7 02 00 00 00  mov         qword ptr [rdx],0
                    00
  0000000000000048: EB 14              jmp         000000000000005E
  000000000000004A: E8 00 00 00 00     call        ?__ExceptionPtrCopy@@YAXPEAXPEBX@Z
  000000000000004F: 90                 nop
  0000000000000050: EB 0C              jmp         000000000000005E
  0000000000000052: 0F 10 02           movups      xmm0,xmmword ptr [rdx]
  0000000000000055: 0F 11 01           movups      xmmword ptr [rcx],xmm0
  0000000000000058: EB 04              jmp         000000000000005E
  000000000000005A: 8B 02              mov         eax,dword ptr [rdx]
  000000000000005C: 89 01              mov         dword ptr [rcx],eax
  000000000000005E: 0F B6 47 10        movzx       eax,byte ptr [rdi+10h]
  0000000000000062: 88 43 10           mov         byte ptr [rbx+10h],al
  0000000000000065: 48 8B C3           mov         rax,rbx
  0000000000000068: 48 8B 5C 24 40     mov         rbx,qword ptr [rsp+40h]
  000000000000006D: 48 83 C4 30        add         rsp,30h
  0000000000000071: 5F                 pop         rdi
  0000000000000072: C3                 ret

  0000000000000046: 48 8B 45 1F        mov         rax,qword ptr [rbp+1Fh]
  000000000000004A: 48 85 C0           test        rax,rax
  000000000000004D: 74 08              je          0000000000000057
  000000000000004F: 48 89 45 F7        mov         qword ptr [rbp-9],rax
  0000000000000053: 48 89 7D 1F        mov         qword ptr [rbp+1Fh],rdi
  0000000000000057: 80 7D 17 00        cmp         byte ptr [rbp+17h],0
  000000000000005B: 74 04              je          0000000000000061
  000000000000005D: C6 45 18 00        mov         byte ptr [rbp+18h],0
  0000000000000061: 0F 57 C0           xorps       xmm0,xmm0
  0000000000000064: F3 0F 7F 45 27     movdqu      xmmword ptr [rbp+27h],xmm0
  0000000000000069: 80 7D EF 00        cmp         byte ptr [rbp-11h],0
  000000000000006D: 75 0A              jne         0000000000000079
  000000000000006F: 48 8B 5D F7        mov         rbx,qword ptr [rbp-9]
  0000000000000073: 48 89 5D 27        mov         qword ptr [rbp+27h],rbx
  0000000000000077: EB 35              jmp         00000000000000AE
  0000000000000079: 48 8D 4D F0        lea         rcx,[rbp-10h]
  000000000000007D: E8 00 00 00 00     call        replaced
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

  0000000000000082: 48 8B 4D F7        mov         rcx,qword ptr [rbp-9]
  0000000000000086: 48 85 C9           test        rcx,rcx
  0000000000000089: 74 1F              je          00000000000000AA
  000000000000008B: 0F B6 41 19        movzx       eax,byte ptr [rcx+19h]
  000000000000008F: 84 C0              test        al,al
  0000000000000091: 75 11              jne         00000000000000A4
  0000000000000093: B8 01 00 00 00     mov         eax,1
  0000000000000098: 86 41 19           xchg        al,byte ptr [rcx+19h]
  000000000000009B: 84 C0              test        al,al
  000000000000009D: 0F 95 C0           setne       al
  00000000000000A0: 84 C0              test        al,al
  00000000000000A2: 74 CB              je          000000000000006F
  00000000000000A4: C6 45 F0 00        mov         byte ptr [rbp-10h],0
  00000000000000A8: EB CF              jmp         0000000000000079
  00000000000000AA: 48 8B 5D 27        mov         rbx,qword ptr [rbp+27h]
  00000000000000AE: 48 8D 45 D7        lea         rax,[rbp-29h]
  00000000000000B2: 48 89 45 2F        mov         qword ptr [rbp+2Fh],rax
  00000000000000B6: 48 85 DB           test        rbx,rbx
  00000000000000B9: 74 29              je          00000000000000E4
  00000000000000BB: 0F B6 4B 10        movzx       ecx,byte ptr [rbx+10h]
  00000000000000BF: 83 E9 01           sub         ecx,1
  00000000000000C2: 74 1C              je          00000000000000E0
  00000000000000C4: 83 E9 01           sub         ecx,1
  00000000000000C7: 74 17              je          00000000000000E0
  00000000000000C9: 83 E9 01           sub         ecx,1
  00000000000000CC: 74 0A              je          00000000000000D8
  00000000000000CE: 83 F9 01           cmp         ecx,1
  00000000000000D1: 75 11              jne         00000000000000E4
  00000000000000D3: 48 89 3B           mov         qword ptr [rbx],rdi
  00000000000000D6: EB 08              jmp         00000000000000E0
  00000000000000D8: 48 8B CB           mov         rcx,rbx
  00000000000000DB: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  00000000000000E0: C6 43 10 00        mov         byte ptr [rbx+10h],0
  00000000000000E4: 0F B6 4D E7        movzx       ecx,byte ptr [rbp-19h]
  00000000000000E8: 83 E9 01           sub         ecx,1
  00000000000000EB: 74 1E              je          000000000000010B
  00000000000000ED: 83 E9 01           sub         ecx,1
  00000000000000F0: 74 19              je          000000000000010B
  00000000000000F2: 83 E9 01           sub         ecx,1
  00000000000000F5: 74 0B              je          0000000000000102
  00000000000000F7: 83 F9 01           cmp         ecx,1
  00000000000000FA: 75 13              jne         000000000000010F
  00000000000000FC: 48 89 7D D7        mov         qword ptr [rbp-29h],rdi
  0000000000000100: EB 09              jmp         000000000000010B
  0000000000000102: 48 8D 4D D7        lea         rcx,[rbp-29h]
  0000000000000106: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  000000000000010B: C6 45 E7 00        mov         byte ptr [rbp-19h],0
  000000000000010F: 48 85 DB           test        rbx,rbx
  0000000000000112: 74 0E              je          0000000000000122
  0000000000000114: 80 7B 18 00        cmp         byte ptr [rbx+18h],0
  0000000000000118: 74 04              je          000000000000011E
  000000000000011A: C6 43 19 00        mov         byte ptr [rbx+19h],0
  000000000000011E: 48 89 7D 27        mov         qword ptr [rbp+27h],rdi
  0000000000000122: 80 7D EF 00        cmp         byte ptr [rbp-11h],0
  0000000000000126: 74 04              je          000000000000012C
  0000000000000128: C6 45 F0 00        mov         byte ptr [rbp-10h],0
  000000000000012C: 48 89 7D 2F        mov         qword ptr [rbp+2Fh],rdi
  0000000000000130: 0F B6 4D E7        movzx       ecx,byte ptr [rbp-19h]
  0000000000000134: 83 E9 01           sub         ecx,1
  0000000000000137: 74 1E              je          0000000000000157
  0000000000000139: 83 E9 01           sub         ecx,1
  000000000000013C: 74 19              je          0000000000000157
  000000000000013E: 83 E9 01           sub         ecx,1
  0000000000000141: 74 0B              je          000000000000014E
  0000000000000143: 83 F9 01           cmp         ecx,1
  0000000000000146: 75 13              jne         000000000000015B
  0000000000000148: 48 89 7D D7        mov         qword ptr [rbp-29h],rdi
  000000000000014C: EB 09              jmp         0000000000000157
  000000000000014E: 48 8D 4D D7        lea         rcx,[rbp-29h]
  0000000000000152: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  0000000000000157: C6 45 E7 00        mov         byte ptr [rbp-19h],0
  000000000000015B: 0F 57 C0           xorps       xmm0,xmm0
  000000000000015E: F3 0F 7F 45 37     movdqu      xmmword ptr [rbp+37h],xmm0
  0000000000000163: 80 7D 17 00        cmp         byte ptr [rbp+17h],0
  0000000000000167: 75 0A              jne         0000000000000173
  0000000000000169: 48 8B 5D 1F        mov         rbx,qword ptr [rbp+1Fh]
  000000000000016D: 48 89 5D 37        mov         qword ptr [rbp+37h],rbx
  0000000000000171: EB 35              jmp         00000000000001A8
  0000000000000173: 48 8D 4D 18        lea         rcx,[rbp+18h]
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

  000000000000017C: 48 8B 4D 1F        mov         rcx,qword ptr [rbp+1Fh]
  0000000000000180: 48 85 C9           test        rcx,rcx
  0000000000000183: 74 1F              je          00000000000001A4
  0000000000000185: 0F B6 41 19        movzx       eax,byte ptr [rcx+19h]
  0000000000000189: 84 C0              test        al,al
  000000000000018B: 75 11              jne         000000000000019E
  000000000000018D: B8 01 00 00 00     mov         eax,1
  0000000000000192: 86 41 19           xchg        al,byte ptr [rcx+19h]
  0000000000000195: 84 C0              test        al,al
  0000000000000197: 0F 95 C0           setne       al
  000000000000019A: 84 C0              test        al,al
  000000000000019C: 74 CB              je          0000000000000169
  000000000000019E: C6 45 18 00        mov         byte ptr [rbp+18h],0
  00000000000001A2: EB CF              jmp         0000000000000173
  00000000000001A4: 48 8B 5D 37        mov         rbx,qword ptr [rbp+37h]
  00000000000001A8: 48 8D 45 FF        lea         rax,[rbp-1]
  00000000000001AC: 48 89 45 3F        mov         qword ptr [rbp+3Fh],rax
  00000000000001B0: 48 85 DB           test        rbx,rbx
  00000000000001B3: 74 29              je          00000000000001DE
  00000000000001B5: 0F B6 4B 10        movzx       ecx,byte ptr [rbx+10h]
  00000000000001B9: 83 E9 01           sub         ecx,1
  00000000000001BC: 74 1C              je          00000000000001DA
  00000000000001BE: 83 E9 01           sub         ecx,1
  00000000000001C1: 74 17              je          00000000000001DA
  00000000000001C3: 83 E9 01           sub         ecx,1
  00000000000001C6: 74 0A              je          00000000000001D2
  00000000000001C8: 83 F9 01           cmp         ecx,1
  00000000000001CB: 75 11              jne         00000000000001DE
  00000000000001CD: 48 89 3B           mov         qword ptr [rbx],rdi
  00000000000001D0: EB 08              jmp         00000000000001DA
  00000000000001D2: 48 8B CB           mov         rcx,rbx
  00000000000001D5: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  00000000000001DA: C6 43 10 00        mov         byte ptr [rbx+10h],0
  00000000000001DE: 0F B6 4D 0F        movzx       ecx,byte ptr [rbp+0Fh]
  00000000000001E2: 83 E9 01           sub         ecx,1
  00000000000001E5: 74 1E              je          0000000000000205
  00000000000001E7: 83 E9 01           sub         ecx,1
  00000000000001EA: 74 19              je          0000000000000205
  00000000000001EC: 83 E9 01           sub         ecx,1
  00000000000001EF: 74 0B              je          00000000000001FC
  00000000000001F1: 83 F9 01           cmp         ecx,1
  00000000000001F4: 75 13              jne         0000000000000209
  00000000000001F6: 48 89 7D FF        mov         qword ptr [rbp-1],rdi
  00000000000001FA: EB 09              jmp         0000000000000205
  00000000000001FC: 48 8D 4D FF        lea         rcx,[rbp-1]
  0000000000000200: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  0000000000000205: C6 45 0F 00        mov         byte ptr [rbp+0Fh],0
  0000000000000209: 48 85 DB           test        rbx,rbx
  000000000000020C: 74 0E              je          000000000000021C
  000000000000020E: 80 7B 18 00        cmp         byte ptr [rbx+18h],0
  0000000000000212: 74 04              je          0000000000000218
  0000000000000214: C6 43 19 00        mov         byte ptr [rbx+19h],0
  0000000000000218: 48 89 7D 37        mov         qword ptr [rbp+37h],rdi
  000000000000021C: 80 7D 17 00        cmp         byte ptr [rbp+17h],0
  0000000000000220: 74 04              je          0000000000000226
  0000000000000222: C6 45 18 00        mov         byte ptr [rbp+18h],0
  0000000000000226: 0F B6 4D 0F        movzx       ecx,byte ptr [rbp+0Fh]
  000000000000022A: 83 E9 01           sub         ecx,1
  000000000000022D: 74 14              je          0000000000000243
  000000000000022F: 83 E9 01           sub         ecx,1
  0000000000000232: 74 0F              je          0000000000000243
  0000000000000234: 83 F9 01           cmp         ecx,1
  0000000000000237: 75 0A              jne         0000000000000243
  0000000000000239: 48 8D 4D FF        lea         rcx,[rbp-1]
  000000000000023D: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  0000000000000242: 90                 nop
  0000000000000243: 4C 8D 9C 24 A0 00  lea         r11,[rsp+0A0h]
                    00 00
  000000000000024B: 49 8B 5B 10        mov         rbx,qword ptr [r11+10h]
  000000000000024F: 49 8B 7B 18        mov         rdi,qword ptr [r11+18h]
  0000000000000253: 49 8B E3           mov         rsp,r11
  0000000000000256: 5D                 pop         rbp
  0000000000000257: C3                 ret
