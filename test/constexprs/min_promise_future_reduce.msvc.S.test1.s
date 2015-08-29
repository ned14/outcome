  0000000000000000: 40 55              push        rbp
  0000000000000002: 53                 push        rbx
  0000000000000003: 56                 push        rsi
  0000000000000004: 57                 push        rdi
  0000000000000005: 48 8D AC 24 48 FF  lea         rbp,[rsp-0B8h]
                    FF FF
  000000000000000D: 48 81 EC B8 01 00  sub         rsp,1B8h
                    00
  0000000000000014: 48 C7 45 48 FE FF  mov         qword ptr [rbp+48h],0FFFFFFFFFFFFFFFEh
                    FF FF
  000000000000001C: 0F 29 B4 24 A0 01  movaps      xmmword ptr [rsp+1A0h],xmm6
                    00 00
  0000000000000024: C6 44 24 78 00     mov         byte ptr [rsp+78h],0
  0000000000000029: C6 44 24 7A 00     mov         byte ptr [rsp+7Ah],0
  000000000000002E: 0F 57 C0           xorps       xmm0,xmm0
  0000000000000031: 66 0F 7F 45 80     movdqa      xmmword ptr [rbp-80h],xmm0
  0000000000000036: 33 F6              xor         esi,esi
  0000000000000038: 48 89 75 90        mov         qword ptr [rbp-70h],rsi
  000000000000003C: 48 89 B5 F0 00 00  mov         qword ptr [rbp+0F0h],rsi
                    00
  0000000000000043: 48 89 75 98        mov         qword ptr [rbp-68h],rsi
  0000000000000047: C7 85 E8 00 00 00  mov         dword ptr [rbp+0E8h],5
                    05 00 00 00
  0000000000000051: 48 89 75 58        mov         qword ptr [rbp+58h],rsi
  0000000000000055: C7 44 24 60 05 00  mov         dword ptr [rsp+60h],5
                    00 00
  000000000000005D: C6 44 24 70 01     mov         byte ptr [rsp+70h],1
  0000000000000062: 48 89 75 50        mov         qword ptr [rbp+50h],rsi
  0000000000000066: 48 8D 54 24 20     lea         rdx,[rsp+20h]
  000000000000006B: 48 8D 4C 24 60     lea         rcx,[rsp+60h]
  0000000000000070: E8 00 00 00 00     call        replaced
  0000000000000000: 48 8B C4           mov         rax,rsp
  0000000000000003: 48 89 50 10        mov         qword ptr [rax+10h],rdx
  0000000000000007: 55                 push        rbp
  0000000000000008: 57                 push        rdi
  0000000000000009: 41 56              push        r14
  000000000000000B: 48 8D 68 A1        lea         rbp,[rax-5Fh]
  000000000000000F: 48 81 EC 90 00 00  sub         rsp,90h
                    00
  0000000000000016: 48 C7 45 DF FE FF  mov         qword ptr [rbp-21h],0FFFFFFFFFFFFFFFEh
                    FF FF
  000000000000001E: 48 89 58 18        mov         qword ptr [rax+18h],rbx
  0000000000000022: 48 89 70 20        mov         qword ptr [rax+20h],rsi
  0000000000000026: 48 8B F2           mov         rsi,rdx
  0000000000000029: 48 8B F9           mov         rdi,rcx
  000000000000002C: C7 45 D7 00 00 00  mov         dword ptr [rbp-29h],0
                    00
  0000000000000033: 80 79 18 00        cmp         byte ptr [rcx+18h],0
  0000000000000037: 75 16              jne         000000000000004F
  0000000000000039: 80 79 10 00        cmp         byte ptr [rcx+10h],0
  000000000000003D: 75 10              jne         000000000000004F
  000000000000003F: C6 41 18 01        mov         byte ptr [rcx+18h],1
  0000000000000043: 48 8D 41 19        lea         rax,[rcx+19h]
  0000000000000047: 48 85 C0           test        rax,rax
  000000000000004A: 74 03              je          000000000000004F
  000000000000004C: C6 00 00           mov         byte ptr [rax],0
  000000000000004F: 0F 57 C0           xorps       xmm0,xmm0
  0000000000000052: F3 0F 7F 45 E7     movdqu      xmmword ptr [rbp-19h],xmm0
  0000000000000057: 80 79 18 00        cmp         byte ptr [rcx+18h],0
  000000000000005B: 75 0E              jne         000000000000006B
  000000000000005D: 48 89 4D E7        mov         qword ptr [rbp-19h],rcx
  0000000000000061: 48 8B 59 20        mov         rbx,qword ptr [rcx+20h]
  0000000000000065: 48 89 5D EF        mov         qword ptr [rbp-11h],rbx
  0000000000000069: EB 43              jmp         00000000000000AE
  000000000000006B: 48 83 C1 19        add         rcx,19h
  000000000000006F: E8 00 00 00 00     call        replaced
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

  0000000000000074: 48 8B 5F 20        mov         rbx,qword ptr [rdi+20h]
  0000000000000078: 48 85 DB           test        rbx,rbx
  000000000000007B: 74 29              je          00000000000000A6
  000000000000007D: 0F B6 43 19        movzx       eax,byte ptr [rbx+19h]
  0000000000000081: 84 C0              test        al,al
  0000000000000083: 75 11              jne         0000000000000096
  0000000000000085: B8 01 00 00 00     mov         eax,1
  000000000000008A: 86 43 19           xchg        al,byte ptr [rbx+19h]
  000000000000008D: 84 C0              test        al,al
  000000000000008F: 0F 95 C0           setne       al
  0000000000000092: 84 C0              test        al,al
  0000000000000094: 74 0A              je          00000000000000A0
  0000000000000096: C6 47 19 00        mov         byte ptr [rdi+19h],0
  000000000000009A: 48 8D 4F 19        lea         rcx,[rdi+19h]
  000000000000009E: EB CF              jmp         000000000000006F
  00000000000000A0: 48 89 5D EF        mov         qword ptr [rbp-11h],rbx
  00000000000000A4: EB 04              jmp         00000000000000AA
  00000000000000A6: 48 8B 5D EF        mov         rbx,qword ptr [rbp-11h]
  00000000000000AA: 48 89 7D E7        mov         qword ptr [rbp-19h],rdi
  00000000000000AE: 80 7F 1A 00        cmp         byte ptr [rdi+1Ah],0
  00000000000000B2: 74 65              je          0000000000000119
  00000000000000B4: C7 45 07 02 00 00  mov         dword ptr [rbp+7],2
                    00
  00000000000000BB: E8 00 00 00 00     call        replaced
  0000000000000000: 48 83 EC 28        sub         rsp,28h
  0000000000000004: 8B 0D 00 00 00 00  mov         ecx,dword ptr [_tls_index]
  000000000000000A: 65 48 8B 04 25 58  mov         rax,qword ptr gs:[58h]
                    00 00 00
  0000000000000013: BA 00 00 00 00     mov         edx,offset _Init_thread_epoch
  0000000000000018: 48 8B 04 C8        mov         rax,qword ptr [rax+rcx*8]
  000000000000001C: 8B 0C 02           mov         ecx,dword ptr [rdx+rax]
  000000000000001F: 39 0D 00 00 00 00  cmp         dword ptr [?$TSS0@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4HA],ecx
  0000000000000025: 7E 46              jle         000000000000006D
  0000000000000027: 48 8D 0D 00 00 00  lea         rcx,[?$TSS0@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4HA]
                    00
  000000000000002E: E8 00 00 00 00     call        _Init_thread_header
  0000000000000033: 83 3D 00 00 00 00  cmp         dword ptr [?$TSS0@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4HA],0FFFFFFFFh
                    FF
  000000000000003A: 75 31              jne         000000000000006D
  000000000000003C: 48 8D 05 00 00 00  lea         rax,[??_7_Future_error_category@std@@6B@]
                    00
  0000000000000043: 48 C7 05 08 00 00  mov         qword ptr [?_Static@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4U?$_Immortalizer@V_Future_error_category@std@@@1@A+8],1
                    00 01 00 00 00
  000000000000004E: 48 8D 0D 00 00 00  lea         rcx,[??__F_Static@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@0@XZ@YAXXZ]
                    00
  0000000000000055: 48 89 05 00 00 00  mov         qword ptr [?_Static@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4U?$_Immortalizer@V_Future_error_category@std@@@1@A],rax
                    00
  000000000000005C: E8 00 00 00 00     call        atexit
  0000000000000061: 48 8D 0D 00 00 00  lea         rcx,[?$TSS0@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4HA]
                    00
  0000000000000068: E8 00 00 00 00     call        _Init_thread_footer
  000000000000006D: 48 8D 05 00 00 00  lea         rax,[?_Static@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4U?$_Immortalizer@V_Future_error_category@std@@@1@A]
                    00
  0000000000000074: 48 83 C4 28        add         rsp,28h
  0000000000000078: C3                 ret

  00000000000000C0: 48 89 45 0F        mov         qword ptr [rbp+0Fh],rax
  00000000000000C4: 48 8D 05 00 00 00  lea         rax,[??_7exception@std@@6B@]
                    00
  00000000000000CB: 48 89 45 17        mov         qword ptr [rbp+17h],rax
  00000000000000CF: 33 C0              xor         eax,eax
  00000000000000D1: 48 89 45 1F        mov         qword ptr [rbp+1Fh],rax
  00000000000000D5: 48 89 45 27        mov         qword ptr [rbp+27h],rax
  00000000000000D9: 48 8D 05 00 00 00  lea         rax,[??_C@_00CNPNBAHC@?$AA@]
                    00
  00000000000000E0: 48 89 45 F7        mov         qword ptr [rbp-9],rax
  00000000000000E4: C6 45 FF 01        mov         byte ptr [rbp-1],1
  00000000000000E8: 48 8D 55 1F        lea         rdx,[rbp+1Fh]
  00000000000000EC: 48 8D 4D F7        lea         rcx,[rbp-9]
  00000000000000F0: E8 00 00 00 00     call        __std_exception_copy
  00000000000000F5: 48 8D 05 00 00 00  lea         rax,[??_7future_error@std@@6B@]
                    00
  00000000000000FC: 48 89 45 17        mov         qword ptr [rbp+17h],rax
  0000000000000100: 0F 10 45 07        movups      xmm0,xmmword ptr [rbp+7]
  0000000000000104: 0F 11 45 2F        movups      xmmword ptr [rbp+2Fh],xmm0
  0000000000000108: 48 8D 15 00 00 00  lea         rdx,[_TI3?AVfuture_error@std@@]
                    00
  000000000000010F: 48 8D 4D 17        lea         rcx,[rbp+17h]
  0000000000000113: E8 00 00 00 00     call        _CxxThrowException
  0000000000000118: CC                 int         3
  0000000000000119: C6 46 10 00        mov         byte ptr [rsi+10h],0
  000000000000011D: C6 46 18 00        mov         byte ptr [rsi+18h],0
  0000000000000121: C6 46 1A 00        mov         byte ptr [rsi+1Ah],0
  0000000000000125: 48 C7 46 20 00 00  mov         qword ptr [rsi+20h],0
                    00 00
  000000000000012D: C7 45 D7 01 00 00  mov         dword ptr [rbp-29h],1
                    00
  0000000000000134: 80 7F 10 00        cmp         byte ptr [rdi+10h],0
  0000000000000138: 74 58              je          0000000000000192
  000000000000013A: 0F B6 4E 10        movzx       ecx,byte ptr [rsi+10h]
  000000000000013E: 83 E9 01           sub         ecx,1
  0000000000000141: 74 12              je          0000000000000155
  0000000000000143: 83 E9 01           sub         ecx,1
  0000000000000146: 74 0D              je          0000000000000155
  0000000000000148: 83 F9 01           cmp         ecx,1
  000000000000014B: 75 0C              jne         0000000000000159
  000000000000014D: 48 8B CE           mov         rcx,rsi
  0000000000000150: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  0000000000000155: C6 46 10 00        mov         byte ptr [rsi+10h],0
  0000000000000159: C6 46 10 00        mov         byte ptr [rsi+10h],0
  000000000000015D: 0F B6 4F 10        movzx       ecx,byte ptr [rdi+10h]
  0000000000000161: 83 E9 01           sub         ecx,1
  0000000000000164: 74 1F              je          0000000000000185
  0000000000000166: 83 E9 01           sub         ecx,1
  0000000000000169: 74 12              je          000000000000017D
  000000000000016B: 83 F9 01           cmp         ecx,1
  000000000000016E: 75 19              jne         0000000000000189
  0000000000000170: 48 8B D7           mov         rdx,rdi
  0000000000000173: 48 8B CE           mov         rcx,rsi
  0000000000000176: E8 00 00 00 00     call        ?__ExceptionPtrCopy@@YAXPEAXPEBX@Z
  000000000000017B: EB 0C              jmp         0000000000000189
  000000000000017D: 0F 10 07           movups      xmm0,xmmword ptr [rdi]
  0000000000000180: 0F 11 06           movups      xmmword ptr [rsi],xmm0
  0000000000000183: EB 04              jmp         0000000000000189
  0000000000000185: 8B 07              mov         eax,dword ptr [rdi]
  0000000000000187: 89 06              mov         dword ptr [rsi],eax
  0000000000000189: 0F B6 47 10        movzx       eax,byte ptr [rdi+10h]
  000000000000018D: 88 46 10           mov         byte ptr [rsi+10h],al
  0000000000000190: EB 0F              jmp         00000000000001A1
  0000000000000192: 48 89 77 20        mov         qword ptr [rdi+20h],rsi
  0000000000000196: 48 89 7E 20        mov         qword ptr [rsi+20h],rdi
  000000000000019A: 0F B6 47 18        movzx       eax,byte ptr [rdi+18h]
  000000000000019E: 88 46 18           mov         byte ptr [rsi+18h],al
  00000000000001A1: C6 47 1A 01        mov         byte ptr [rdi+1Ah],1
  00000000000001A5: 80 7F 18 00        cmp         byte ptr [rdi+18h],0
  00000000000001A9: 74 04              je          00000000000001AF
  00000000000001AB: C6 47 19 00        mov         byte ptr [rdi+19h],0
  00000000000001AF: 48 C7 45 E7 00 00  mov         qword ptr [rbp-19h],0
                    00 00
  00000000000001B7: 48 85 DB           test        rbx,rbx
  00000000000001BA: 74 10              je          00000000000001CC
  00000000000001BC: 80 7B 18 00        cmp         byte ptr [rbx+18h],0
  00000000000001C0: 74 04              je          00000000000001C6
  00000000000001C2: C6 43 19 00        mov         byte ptr [rbx+19h],0
  00000000000001C6: 33 DB              xor         ebx,ebx
  00000000000001C8: 48 89 5D EF        mov         qword ptr [rbp-11h],rbx
  00000000000001CC: 48 85 DB           test        rbx,rbx
  00000000000001CF: 74 0A              je          00000000000001DB
  00000000000001D1: 80 7B 18 00        cmp         byte ptr [rbx+18h],0
  00000000000001D5: 74 04              je          00000000000001DB
  00000000000001D7: C6 43 19 00        mov         byte ptr [rbx+19h],0
  00000000000001DB: 48 8B C6           mov         rax,rsi
  00000000000001DE: 4C 8D 9C 24 90 00  lea         r11,[rsp+90h]
                    00 00
  00000000000001E6: 49 8B 5B 30        mov         rbx,qword ptr [r11+30h]
  00000000000001EA: 49 8B 73 38        mov         rsi,qword ptr [r11+38h]
  00000000000001EE: 49 8B E3           mov         rsp,r11
  00000000000001F1: 41 5E              pop         r14
  00000000000001F3: 5F                 pop         rdi
  00000000000001F4: 5D                 pop         rbp
  00000000000001F5: C3                 ret
  00000000000001F6: CC                 int         3

  0000000000000075: 90                 nop
  0000000000000076: 40 38 74 24 30     cmp         byte ptr [rsp+30h],sil
  000000000000007B: 0F 95 C0           setne       al
  000000000000007E: 84 C0              test        al,al
  0000000000000080: 75 1C              jne         000000000000009E
  0000000000000082: 33 C0              xor         eax,eax
  0000000000000084: 88 85 E0 00 00 00  mov         byte ptr [rbp+0E0h],al
  000000000000008A: 41 B0 01           mov         r8b,1
  000000000000008D: 48 8D 95 E0 00 00  lea         rdx,[rbp+0E0h]
                    00
  0000000000000094: 48 8D 4C 24 20     lea         rcx,[rsp+20h]
  0000000000000099: E8 00 00 00 00     call        replaced
  0000000000000000: 40 55              push        rbp
  0000000000000002: 56                 push        rsi
  0000000000000003: 57                 push        rdi
  0000000000000004: 41 54              push        r12
  0000000000000006: 41 55              push        r13
  0000000000000008: 41 56              push        r14
  000000000000000A: 41 57              push        r15
  000000000000000C: 48 8D 6C 24 D9     lea         rbp,[rsp-27h]
  0000000000000011: 48 81 EC A0 00 00  sub         rsp,0A0h
                    00
  0000000000000018: 48 C7 45 E7 FE FF  mov         qword ptr [rbp-19h],0FFFFFFFFFFFFFFFEh
                    FF FF
  0000000000000020: 48 89 9C 24 E8 00  mov         qword ptr [rsp+0E8h],rbx
                    00 00
  0000000000000028: 45 0F B6 E8        movzx       r13d,r8b
  000000000000002C: 48 8B F9           mov         rdi,rcx
  000000000000002F: 0F 57 C0           xorps       xmm0,xmm0
  0000000000000032: F3 0F 7F 45 A7     movdqu      xmmword ptr [rbp-59h],xmm0
  0000000000000037: 80 79 18 00        cmp         byte ptr [rcx+18h],0
  000000000000003B: 75 0E              jne         000000000000004B
  000000000000003D: 48 8B 41 20        mov         rax,qword ptr [rcx+20h]
  0000000000000041: 48 89 45 A7        mov         qword ptr [rbp-59h],rax
  0000000000000045: 48 89 4D AF        mov         qword ptr [rbp-51h],rcx
  0000000000000049: EB 3D              jmp         0000000000000088
  000000000000004B: 48 83 C1 19        add         rcx,19h
  000000000000004F: E8 00 00 00 00     call        replaced
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

  0000000000000054: 48 8B 4F 20        mov         rcx,qword ptr [rdi+20h]
  0000000000000058: 48 85 C9           test        rcx,rcx
  000000000000005B: 74 27              je          0000000000000084
  000000000000005D: 0F B6 41 19        movzx       eax,byte ptr [rcx+19h]
  0000000000000061: 84 C0              test        al,al
  0000000000000063: 75 11              jne         0000000000000076
  0000000000000065: B8 01 00 00 00     mov         eax,1
  000000000000006A: 86 41 19           xchg        al,byte ptr [rcx+19h]
  000000000000006D: 84 C0              test        al,al
  000000000000006F: 0F 95 C0           setne       al
  0000000000000072: 84 C0              test        al,al
  0000000000000074: 74 0A              je          0000000000000080
  0000000000000076: C6 47 19 00        mov         byte ptr [rdi+19h],0
  000000000000007A: 48 8D 4F 19        lea         rcx,[rdi+19h]
  000000000000007E: EB CF              jmp         000000000000004F
  0000000000000080: 48 89 4D A7        mov         qword ptr [rbp-59h],rcx
  0000000000000084: 48 89 7D AF        mov         qword ptr [rbp-51h],rdi
  0000000000000088: 80 7F 10 00        cmp         byte ptr [rdi+10h],0
  000000000000008C: 0F 95 C0           setne       al
  000000000000008F: 33 F6              xor         esi,esi
  0000000000000091: 84 C0              test        al,al
  0000000000000093: 0F 85 72 03 00 00  jne         000000000000040B
  0000000000000099: 48 8B CF           mov         rcx,rdi
  000000000000009C: E8 00 00 00 00     call        replaced
  0000000000000000: 40 55              push        rbp
  0000000000000002: 48 8B EC           mov         rbp,rsp
  0000000000000005: 48 83 EC 70        sub         rsp,70h
  0000000000000009: 80 79 1A 00        cmp         byte ptr [rcx+1Ah],0
  000000000000000D: 75 13              jne         0000000000000022
  000000000000000F: 48 83 79 20 00     cmp         qword ptr [rcx+20h],0
  0000000000000014: 75 06              jne         000000000000001C
  0000000000000016: 80 79 10 00        cmp         byte ptr [rcx+10h],0
  000000000000001A: 74 6B              je          0000000000000087
  000000000000001C: 48 83 C4 70        add         rsp,70h
  0000000000000020: 5D                 pop         rbp
  0000000000000021: C3                 ret
  0000000000000022: C7 45 C0 01 00 00  mov         dword ptr [rbp-40h],1
                    00
  0000000000000029: E8 00 00 00 00     call        replaced
  0000000000000000: 48 83 EC 28        sub         rsp,28h
  0000000000000004: 8B 0D 00 00 00 00  mov         ecx,dword ptr [_tls_index]
  000000000000000A: 65 48 8B 04 25 58  mov         rax,qword ptr gs:[58h]
                    00 00 00
  0000000000000013: BA 00 00 00 00     mov         edx,offset _Init_thread_epoch
  0000000000000018: 48 8B 04 C8        mov         rax,qword ptr [rax+rcx*8]
  000000000000001C: 8B 0C 02           mov         ecx,dword ptr [rdx+rax]
  000000000000001F: 39 0D 00 00 00 00  cmp         dword ptr [?$TSS0@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4HA],ecx
  0000000000000025: 7E 46              jle         000000000000006D
  0000000000000027: 48 8D 0D 00 00 00  lea         rcx,[?$TSS0@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4HA]
                    00
  000000000000002E: E8 00 00 00 00     call        _Init_thread_header
  0000000000000033: 83 3D 00 00 00 00  cmp         dword ptr [?$TSS0@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4HA],0FFFFFFFFh
                    FF
  000000000000003A: 75 31              jne         000000000000006D
  000000000000003C: 48 8D 05 00 00 00  lea         rax,[??_7_Future_error_category@std@@6B@]
                    00
  0000000000000043: 48 C7 05 08 00 00  mov         qword ptr [?_Static@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4U?$_Immortalizer@V_Future_error_category@std@@@1@A+8],1
                    00 01 00 00 00
  000000000000004E: 48 8D 0D 00 00 00  lea         rcx,[??__F_Static@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@0@XZ@YAXXZ]
                    00
  0000000000000055: 48 89 05 00 00 00  mov         qword ptr [?_Static@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4U?$_Immortalizer@V_Future_error_category@std@@@1@A],rax
                    00
  000000000000005C: E8 00 00 00 00     call        atexit
  0000000000000061: 48 8D 0D 00 00 00  lea         rcx,[?$TSS0@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4HA]
                    00
  0000000000000068: E8 00 00 00 00     call        _Init_thread_footer
  000000000000006D: 48 8D 05 00 00 00  lea         rax,[?_Static@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4U?$_Immortalizer@V_Future_error_category@std@@@1@A]
                    00
  0000000000000074: 48 83 C4 28        add         rsp,28h
  0000000000000078: C3                 ret

  000000000000002E: 48 89 45 C8        mov         qword ptr [rbp-38h],rax
  0000000000000032: 48 8D 55 D8        lea         rdx,[rbp-28h]
  0000000000000036: 48 8D 05 00 00 00  lea         rax,[??_7exception@std@@6B@]
                    00
  000000000000003D: C6 45 B8 01        mov         byte ptr [rbp-48h],1
  0000000000000041: 48 89 45 D0        mov         qword ptr [rbp-30h],rax
  0000000000000045: 48 8D 4D B0        lea         rcx,[rbp-50h]
  0000000000000049: 33 C0              xor         eax,eax
  000000000000004B: 48 89 45 D8        mov         qword ptr [rbp-28h],rax
  000000000000004F: 48 89 45 E0        mov         qword ptr [rbp-20h],rax
  0000000000000053: 48 8D 05 00 00 00  lea         rax,[??_C@_00CNPNBAHC@?$AA@]
                    00
  000000000000005A: 48 89 45 B0        mov         qword ptr [rbp-50h],rax
  000000000000005E: E8 00 00 00 00     call        __std_exception_copy
  0000000000000063: 0F 10 45 C0        movups      xmm0,xmmword ptr [rbp-40h]
  0000000000000067: 48 8D 05 00 00 00  lea         rax,[??_7future_error@std@@6B@]
                    00
  000000000000006E: 48 8D 15 00 00 00  lea         rdx,[_TI3?AVfuture_error@std@@]
                    00
  0000000000000075: 48 89 45 D0        mov         qword ptr [rbp-30h],rax
  0000000000000079: 48 8D 4D D0        lea         rcx,[rbp-30h]
  000000000000007D: 0F 11 45 E8        movups      xmmword ptr [rbp-18h],xmm0
  0000000000000081: E8 00 00 00 00     call        _CxxThrowException
  0000000000000086: CC                 int         3
  0000000000000087: C7 45 B0 04 00 00  mov         dword ptr [rbp-50h],4
                    00
  000000000000008E: E8 00 00 00 00     call        replaced
  0000000000000000: 48 83 EC 28        sub         rsp,28h
  0000000000000004: 8B 0D 00 00 00 00  mov         ecx,dword ptr [_tls_index]
  000000000000000A: 65 48 8B 04 25 58  mov         rax,qword ptr gs:[58h]
                    00 00 00
  0000000000000013: BA 00 00 00 00     mov         edx,offset _Init_thread_epoch
  0000000000000018: 48 8B 04 C8        mov         rax,qword ptr [rax+rcx*8]
  000000000000001C: 8B 0C 02           mov         ecx,dword ptr [rdx+rax]
  000000000000001F: 39 0D 00 00 00 00  cmp         dword ptr [?$TSS0@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4HA],ecx
  0000000000000025: 7E 46              jle         000000000000006D
  0000000000000027: 48 8D 0D 00 00 00  lea         rcx,[?$TSS0@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4HA]
                    00
  000000000000002E: E8 00 00 00 00     call        _Init_thread_header
  0000000000000033: 83 3D 00 00 00 00  cmp         dword ptr [?$TSS0@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4HA],0FFFFFFFFh
                    FF
  000000000000003A: 75 31              jne         000000000000006D
  000000000000003C: 48 8D 05 00 00 00  lea         rax,[??_7_Future_error_category@std@@6B@]
                    00
  0000000000000043: 48 C7 05 08 00 00  mov         qword ptr [?_Static@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4U?$_Immortalizer@V_Future_error_category@std@@@1@A+8],1
                    00 01 00 00 00
  000000000000004E: 48 8D 0D 00 00 00  lea         rcx,[??__F_Static@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@0@XZ@YAXXZ]
                    00
  0000000000000055: 48 89 05 00 00 00  mov         qword ptr [?_Static@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4U?$_Immortalizer@V_Future_error_category@std@@@1@A],rax
                    00
  000000000000005C: E8 00 00 00 00     call        atexit
  0000000000000061: 48 8D 0D 00 00 00  lea         rcx,[?$TSS0@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4HA]
                    00
  0000000000000068: E8 00 00 00 00     call        _Init_thread_footer
  000000000000006D: 48 8D 05 00 00 00  lea         rax,[?_Static@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4U?$_Immortalizer@V_Future_error_category@std@@@1@A]
                    00
  0000000000000074: 48 83 C4 28        add         rsp,28h
  0000000000000078: C3                 ret

  0000000000000093: 48 89 45 B8        mov         qword ptr [rbp-48h],rax
  0000000000000097: 48 8D 55 D8        lea         rdx,[rbp-28h]
  000000000000009B: 48 8D 05 00 00 00  lea         rax,[??_7exception@std@@6B@]
                    00
  00000000000000A2: C6 45 C8 01        mov         byte ptr [rbp-38h],1
  00000000000000A6: 48 89 45 D0        mov         qword ptr [rbp-30h],rax
  00000000000000AA: 48 8D 4D C0        lea         rcx,[rbp-40h]
  00000000000000AE: 33 C0              xor         eax,eax
  00000000000000B0: 48 89 45 D8        mov         qword ptr [rbp-28h],rax
  00000000000000B4: 48 89 45 E0        mov         qword ptr [rbp-20h],rax
  00000000000000B8: 48 8D 05 00 00 00  lea         rax,[??_C@_00CNPNBAHC@?$AA@]
                    00
  00000000000000BF: 48 89 45 C0        mov         qword ptr [rbp-40h],rax
  00000000000000C3: E8 00 00 00 00     call        __std_exception_copy
  00000000000000C8: 0F 10 45 B0        movups      xmm0,xmmword ptr [rbp-50h]
  00000000000000CC: 48 8D 05 00 00 00  lea         rax,[??_7future_error@std@@6B@]
                    00
  00000000000000D3: 48 8D 15 00 00 00  lea         rdx,[_TI3?AVfuture_error@std@@]
                    00
  00000000000000DA: 48 89 45 D0        mov         qword ptr [rbp-30h],rax
  00000000000000DE: 48 8D 4D D0        lea         rcx,[rbp-30h]
  00000000000000E2: 0F 11 45 E8        movups      xmmword ptr [rbp-18h],xmm0
  00000000000000E6: E8 00 00 00 00     call        _CxxThrowException
  00000000000000EB: CC                 int         3

  00000000000000A1: 0F 57 C0           xorps       xmm0,xmm0
  00000000000000A4: F3 0F 7F 45 B7     movdqu      xmmword ptr [rbp-49h],xmm0
  00000000000000A9: 48 8B 47 20        mov         rax,qword ptr [rdi+20h]
  00000000000000AD: 48 39 70 38        cmp         qword ptr [rax+38h],rsi
  00000000000000B1: 74 2C              je          00000000000000DF
  00000000000000B3: 48 8B 40 38        mov         rax,qword ptr [rax+38h]
  00000000000000B7: 48 8B 48 08        mov         rcx,qword ptr [rax+8]
  00000000000000BB: 48 8B 10           mov         rdx,qword ptr [rax]
  00000000000000BE: 48 85 C9           test        rcx,rcx
  00000000000000C1: 74 04              je          00000000000000C7
  00000000000000C3: F0 FF 41 08        lock inc    dword ptr [rcx+8]
  00000000000000C7: 48 89 4D 7F        mov         qword ptr [rbp+7Fh],rcx
  00000000000000CB: 48 89 75 1F        mov         qword ptr [rbp+1Fh],rsi
  00000000000000CF: 48 89 4D BF        mov         qword ptr [rbp-41h],rcx
  00000000000000D3: 48 89 55 EF        mov         qword ptr [rbp-11h],rdx
  00000000000000D7: 48 89 75 17        mov         qword ptr [rbp+17h],rsi
  00000000000000DB: 48 89 55 B7        mov         qword ptr [rbp-49h],rdx
  00000000000000DF: 4C 8B E6           mov         r12,rsi
  00000000000000E2: 44 38 67 10        cmp         byte ptr [rdi+10h],r12b
  00000000000000E6: 0F 95 C0           setne       al
  00000000000000E9: 41 83 CF FF        or          r15d,0FFFFFFFFh
  00000000000000ED: 84 C0              test        al,al
  00000000000000EF: 0F 85 DD 02 00 00  jne         00000000000003D2
  00000000000000F5: 48 83 7D B7 00     cmp         qword ptr [rbp-49h],0
  00000000000000FA: 0F 95 C0           setne       al
  00000000000000FD: 84 C0              test        al,al
  00000000000000FF: 0F 85 EC 01 00 00  jne         00000000000002F1
  0000000000000105: 45 84 ED           test        r13b,r13b
  0000000000000108: 74 0D              je          0000000000000117
  000000000000010A: 49 81 FC E8 03 00  cmp         r12,3E8h
                    00
  0000000000000111: 0F 82 DA 01 00 00  jb          00000000000002F1
  0000000000000117: 48 8B 45 A7        mov         rax,qword ptr [rbp-59h]
  000000000000011B: 48 85 C0           test        rax,rax
  000000000000011E: 74 0E              je          000000000000012E
  0000000000000120: 80 78 18 00        cmp         byte ptr [rax+18h],0
  0000000000000124: 74 04              je          000000000000012A
  0000000000000126: C6 40 19 00        mov         byte ptr [rax+19h],0
  000000000000012A: 48 89 75 A7        mov         qword ptr [rbp-59h],rsi
  000000000000012E: 80 7F 18 00        cmp         byte ptr [rdi+18h],0
  0000000000000132: 74 04              je          0000000000000138
  0000000000000134: C6 47 19 00        mov         byte ptr [rdi+19h],0
  0000000000000138: 48 89 75 AF        mov         qword ptr [rbp-51h],rsi
  000000000000013C: B9 10 00 00 00     mov         ecx,10h
  0000000000000141: E8 00 00 00 00     call        ??2@YAPEAX_K@Z
  0000000000000146: 48 89 45 F7        mov         qword ptr [rbp-9],rax
  000000000000014A: 48 85 C0           test        rax,rax
  000000000000014D: 74 0D              je          000000000000015C
  000000000000014F: 48 8B C8           mov         rcx,rax
  0000000000000152: E8 00 00 00 00     call        replaced
  0000000000000000: 48 89 4C 24 08     mov         qword ptr [rsp+8],rcx
  0000000000000005: 53                 push        rbx
  0000000000000006: 48 83 EC 30        sub         rsp,30h
  000000000000000A: 48 C7 44 24 28 FE  mov         qword ptr [rsp+28h],0FFFFFFFFFFFFFFFEh
                    FF FF FF
  0000000000000013: 48 8B D9           mov         rbx,rcx
  0000000000000016: C7 44 24 20 00 00  mov         dword ptr [rsp+20h],0
                    00 00
  000000000000001E: B9 38 00 00 00     mov         ecx,38h
  0000000000000023: E8 00 00 00 00     call        ??2@YAPEAX_K@Z
  0000000000000028: 48 89 44 24 40     mov         qword ptr [rsp+40h],rax
  000000000000002D: 48 85 C0           test        rax,rax
  0000000000000030: 74 09              je          000000000000003B
  0000000000000032: 48 8B C8           mov         rcx,rax
  0000000000000035: E8 00 00 00 00     call        replaced
  0000000000000000: 48 89 4C 24 08     mov         qword ptr [rsp+8],rcx
  0000000000000005: 57                 push        rdi
  0000000000000006: 48 83 EC 30        sub         rsp,30h
  000000000000000A: 48 C7 44 24 20 FE  mov         qword ptr [rsp+20h],0FFFFFFFFFFFFFFFEh
                    FF FF FF
  0000000000000013: 48 89 5C 24 58     mov         qword ptr [rsp+58h],rbx
  0000000000000018: 48 8B F9           mov         rdi,rcx
  000000000000001B: C7 41 08 01 00 00  mov         dword ptr [rcx+8],1
                    00
  0000000000000022: C7 41 0C 01 00 00  mov         dword ptr [rcx+0Ch],1
                    00
  0000000000000029: 48 8D 05 00 00 00  lea         rax,[??_7?$_Ref_count_obj@U?$stl_wait_implementation@V?$promise@X@std@@V?$future@X@2@@detail@lightweight_futures@v1_std_std@outcome@boost@@@std@@6B@]
                    00
  0000000000000030: 48 89 01           mov         qword ptr [rcx],rax
  0000000000000033: 48 8D 59 10        lea         rbx,[rcx+10h]
  0000000000000037: 48 89 5C 24 48     mov         qword ptr [rsp+48h],rbx
  000000000000003C: 48 85 DB           test        rbx,rbx
  000000000000003F: 74 37              je          0000000000000078
  0000000000000041: B9 D0 00 00 00     mov         ecx,0D0h
  0000000000000046: E8 00 00 00 00     call        ??2@YAPEAX_K@Z
  000000000000004B: 48 89 44 24 50     mov         qword ptr [rsp+50h],rax
  0000000000000050: 48 85 C0           test        rax,rax
  0000000000000053: 74 0B              je          0000000000000060
  0000000000000055: 33 D2              xor         edx,edx
  0000000000000057: 48 8B C8           mov         rcx,rax
  000000000000005A: E8 00 00 00 00     call        replaced
  0000000000000000: 48 89 5C 24 08     mov         qword ptr [rsp+8],rbx
  0000000000000005: 57                 push        rdi
  0000000000000006: 48 83 EC 20        sub         rsp,20h
  000000000000000A: 48 8D 05 00 00 00  lea         rax,[??_7?$_Associated_state@H@std@@6B@]
                    00
  0000000000000011: 48 8B F9           mov         rdi,rcx
  0000000000000014: 48 89 01           mov         qword ptr [rcx],rax
  0000000000000017: 48 8B DA           mov         rbx,rdx
  000000000000001A: 48 83 C1 10        add         rcx,10h
  000000000000001E: E8 00 00 00 00     call        ?__ExceptionPtrCreate@@YAXPEAX@Z
  0000000000000023: 48 8D 4F 20        lea         rcx,[rdi+20h]
  0000000000000027: BA 02 00 00 00     mov         edx,2
  000000000000002C: E8 00 00 00 00     call        _Mtx_init_in_situ
  0000000000000031: 48 8D 4F 70        lea         rcx,[rdi+70h]
  0000000000000035: E8 00 00 00 00     call        _Cnd_init_in_situ
  000000000000003A: 48 89 9F C8 00 00  mov         qword ptr [rdi+0C8h],rbx
                    00
  0000000000000041: 48 8B C7           mov         rax,rdi
  0000000000000044: 48 8B 5C 24 30     mov         rbx,qword ptr [rsp+30h]
  0000000000000049: C6 87 B8 00 00 00  mov         byte ptr [rdi+0B8h],0
                    00
  0000000000000050: C7 87 BC 00 00 00  mov         dword ptr [rdi+0BCh],0
                    00 00 00 00
  000000000000005A: 66 C7 87 C0 00 00  mov         word ptr [rdi+0C0h],0
                    00 00 00
  0000000000000063: C6 87 C2 00 00 00  mov         byte ptr [rdi+0C2h],0
                    00
  000000000000006A: C7 47 08 01 00 00  mov         dword ptr [rdi+8],1
                    00
  0000000000000071: 48 83 C4 20        add         rsp,20h
  0000000000000075: 5F                 pop         rdi
  0000000000000076: C3                 ret

  000000000000005F: 90                 nop
  0000000000000060: 48 89 03           mov         qword ptr [rbx],rax
  0000000000000063: C6 43 08 00        mov         byte ptr [rbx+8],0
  0000000000000067: C6 43 10 00        mov         byte ptr [rbx+10h],0
  000000000000006B: 48 8D 53 18        lea         rdx,[rbx+18h]
  000000000000006F: 48 8B CB           mov         rcx,rbx
  0000000000000072: E8 00 00 00 00     call        replaced
  0000000000000000: 40 53              push        rbx
  0000000000000002: 48 83 EC 30        sub         rsp,30h
  0000000000000006: 48 8B DA           mov         rbx,rdx
  0000000000000009: C7 44 24 20 00 00  mov         dword ptr [rsp+20h],0
                    00 00
  0000000000000011: E8 00 00 00 00     call        replaced
  0000000000000000: 48 83 EC 38        sub         rsp,38h
  0000000000000004: 48 8B 01           mov         rax,qword ptr [rcx]
  0000000000000007: 48 85 C0           test        rax,rax
  000000000000000A: 74 3E              je          000000000000004A
  000000000000000C: 80 79 08 00        cmp         byte ptr [rcx+8],0
  0000000000000010: 74 09              je          000000000000001B
  0000000000000012: 80 B8 B8 00 00 00  cmp         byte ptr [rax+0B8h],0
                    00
  0000000000000019: 75 2F              jne         000000000000004A
  000000000000001B: 80 79 10 00        cmp         byte ptr [rcx+10h],0
  000000000000001F: 75 0C              jne         000000000000002D
  0000000000000021: C6 41 10 01        mov         byte ptr [rcx+10h],1
  0000000000000025: 48 8B C1           mov         rax,rcx
  0000000000000028: 48 83 C4 38        add         rsp,38h
  000000000000002C: C3                 ret
  000000000000002D: E8 00 00 00 00     call        replaced
  0000000000000000: 48 83 EC 28        sub         rsp,28h
  0000000000000004: 8B 0D 00 00 00 00  mov         ecx,dword ptr [_tls_index]
  000000000000000A: 65 48 8B 04 25 58  mov         rax,qword ptr gs:[58h]
                    00 00 00
  0000000000000013: BA 00 00 00 00     mov         edx,offset _Init_thread_epoch
  0000000000000018: 48 8B 04 C8        mov         rax,qword ptr [rax+rcx*8]
  000000000000001C: 8B 0C 02           mov         ecx,dword ptr [rdx+rax]
  000000000000001F: 39 0D 00 00 00 00  cmp         dword ptr [?$TSS0@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4HA],ecx
  0000000000000025: 7E 46              jle         000000000000006D
  0000000000000027: 48 8D 0D 00 00 00  lea         rcx,[?$TSS0@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4HA]
                    00
  000000000000002E: E8 00 00 00 00     call        _Init_thread_header
  0000000000000033: 83 3D 00 00 00 00  cmp         dword ptr [?$TSS0@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4HA],0FFFFFFFFh
                    FF
  000000000000003A: 75 31              jne         000000000000006D
  000000000000003C: 48 8D 05 00 00 00  lea         rax,[??_7_Future_error_category@std@@6B@]
                    00
  0000000000000043: 48 C7 05 08 00 00  mov         qword ptr [?_Static@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4U?$_Immortalizer@V_Future_error_category@std@@@1@A+8],1
                    00 01 00 00 00
  000000000000004E: 48 8D 0D 00 00 00  lea         rcx,[??__F_Static@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@0@XZ@YAXXZ]
                    00
  0000000000000055: 48 89 05 00 00 00  mov         qword ptr [?_Static@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4U?$_Immortalizer@V_Future_error_category@std@@@1@A],rax
                    00
  000000000000005C: E8 00 00 00 00     call        atexit
  0000000000000061: 48 8D 0D 00 00 00  lea         rcx,[?$TSS0@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4HA]
                    00
  0000000000000068: E8 00 00 00 00     call        _Init_thread_footer
  000000000000006D: 48 8D 05 00 00 00  lea         rax,[?_Static@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4U?$_Immortalizer@V_Future_error_category@std@@@1@A]
                    00
  0000000000000074: 48 83 C4 28        add         rsp,28h
  0000000000000078: C3                 ret

  0000000000000032: 48 8D 4C 24 20     lea         rcx,[rsp+20h]
  0000000000000037: C7 44 24 20 02 00  mov         dword ptr [rsp+20h],2
                    00 00
  000000000000003F: 48 89 44 24 28     mov         qword ptr [rsp+28h],rax
  0000000000000044: E8 00 00 00 00     call        ?_Throw_future_error@std@@YAXAEBVerror_code@1@@Z
  0000000000000049: CC                 int         3
  000000000000004A: E8 00 00 00 00     call        replaced
  0000000000000000: 48 83 EC 28        sub         rsp,28h
  0000000000000004: 8B 0D 00 00 00 00  mov         ecx,dword ptr [_tls_index]
  000000000000000A: 65 48 8B 04 25 58  mov         rax,qword ptr gs:[58h]
                    00 00 00
  0000000000000013: BA 00 00 00 00     mov         edx,offset _Init_thread_epoch
  0000000000000018: 48 8B 04 C8        mov         rax,qword ptr [rax+rcx*8]
  000000000000001C: 8B 0C 02           mov         ecx,dword ptr [rdx+rax]
  000000000000001F: 39 0D 00 00 00 00  cmp         dword ptr [?$TSS0@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4HA],ecx
  0000000000000025: 7E 46              jle         000000000000006D
  0000000000000027: 48 8D 0D 00 00 00  lea         rcx,[?$TSS0@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4HA]
                    00
  000000000000002E: E8 00 00 00 00     call        _Init_thread_header
  0000000000000033: 83 3D 00 00 00 00  cmp         dword ptr [?$TSS0@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4HA],0FFFFFFFFh
                    FF
  000000000000003A: 75 31              jne         000000000000006D
  000000000000003C: 48 8D 05 00 00 00  lea         rax,[??_7_Future_error_category@std@@6B@]
                    00
  0000000000000043: 48 C7 05 08 00 00  mov         qword ptr [?_Static@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4U?$_Immortalizer@V_Future_error_category@std@@@1@A+8],1
                    00 01 00 00 00
  000000000000004E: 48 8D 0D 00 00 00  lea         rcx,[??__F_Static@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@0@XZ@YAXXZ]
                    00
  0000000000000055: 48 89 05 00 00 00  mov         qword ptr [?_Static@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4U?$_Immortalizer@V_Future_error_category@std@@@1@A],rax
                    00
  000000000000005C: E8 00 00 00 00     call        atexit
  0000000000000061: 48 8D 0D 00 00 00  lea         rcx,[?$TSS0@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4HA]
                    00
  0000000000000068: E8 00 00 00 00     call        _Init_thread_footer
  000000000000006D: 48 8D 05 00 00 00  lea         rax,[?_Static@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4U?$_Immortalizer@V_Future_error_category@std@@@1@A]
                    00
  0000000000000074: 48 83 C4 28        add         rsp,28h
  0000000000000078: C3                 ret

  000000000000004F: 48 8D 4C 24 20     lea         rcx,[rsp+20h]
  0000000000000054: C7 44 24 20 04 00  mov         dword ptr [rsp+20h],4
                    00 00
  000000000000005C: 48 89 44 24 28     mov         qword ptr [rsp+28h],rax
  0000000000000061: E8 00 00 00 00     call        ?_Throw_future_error@std@@YAXAEBVerror_code@1@@Z
  0000000000000066: CC                 int         3

  0000000000000016: 48 8B D0           mov         rdx,rax
  0000000000000019: 48 C7 03 00 00 00  mov         qword ptr [rbx],0
                    00
  0000000000000020: 48 8B CB           mov         rcx,rbx
  0000000000000023: E8 00 00 00 00     call        replaced
  0000000000000000: 48 3B CA           cmp         rcx,rdx
  0000000000000003: 74 79              je          000000000000007E
  0000000000000005: 48 89 5C 24 08     mov         qword ptr [rsp+8],rbx
  000000000000000A: 57                 push        rdi
  000000000000000B: 48 83 EC 20        sub         rsp,20h
  000000000000000F: 48 8B D9           mov         rbx,rcx
  0000000000000012: 48 8B FA           mov         rdi,rdx
  0000000000000015: 48 8B 09           mov         rcx,qword ptr [rcx]
  0000000000000018: 48 85 C9           test        rcx,rcx
  000000000000001B: 74 30              je          000000000000004D
  000000000000001D: 83 C8 FF           or          eax,0FFFFFFFFh
  0000000000000020: F0 0F C1 41 08     lock xadd   dword ptr [rcx+8],eax
  0000000000000025: 83 F8 01           cmp         eax,1
  0000000000000028: 75 23              jne         000000000000004D
  000000000000002A: 4C 8B 81 C8 00 00  mov         r8,qword ptr [rcx+00000000000000C8h]
                    00
  0000000000000031: 4D 85 C0           test        r8,r8
  0000000000000034: 74 0D              je          0000000000000043
  0000000000000036: 49 8B 00           mov         rax,qword ptr [r8]
  0000000000000039: 48 8B D1           mov         rdx,rcx
  000000000000003C: 49 8B C8           mov         rcx,r8
  000000000000003F: FF 10              call        qword ptr [rax]
  0000000000000041: EB 0A              jmp         000000000000004D
  0000000000000043: 48 8B 01           mov         rax,qword ptr [rcx]
  0000000000000046: BA 01 00 00 00     mov         edx,1
  000000000000004B: FF 10              call        qword ptr [rax]
  000000000000004D: 48 8B 07           mov         rax,qword ptr [rdi]
  0000000000000050: 48 85 C0           test        rax,rax
  0000000000000053: 75 0E              jne         0000000000000063
  0000000000000055: 48 89 03           mov         qword ptr [rbx],rax
  0000000000000058: 48 8B 5C 24 30     mov         rbx,qword ptr [rsp+30h]
  000000000000005D: 48 83 C4 20        add         rsp,20h
  0000000000000061: 5F                 pop         rdi
  0000000000000062: C3                 ret
  0000000000000063: F0 FF 40 08        lock inc    dword ptr [rax+8]
  0000000000000067: 48 8B 07           mov         rax,qword ptr [rdi]
  000000000000006A: 48 89 03           mov         qword ptr [rbx],rax
  000000000000006D: 0F B6 47 08        movzx       eax,byte ptr [rdi+8]
  0000000000000071: 88 43 08           mov         byte ptr [rbx+8],al
  0000000000000074: 48 8B 5C 24 30     mov         rbx,qword ptr [rsp+30h]
  0000000000000079: 48 83 C4 20        add         rsp,20h
  000000000000007D: 5F                 pop         rdi
  000000000000007E: C3                 ret

  0000000000000028: 48 8B C3           mov         rax,rbx
  000000000000002B: C6 43 08 01        mov         byte ptr [rbx+8],1
  000000000000002F: 48 83 C4 30        add         rsp,30h
  0000000000000033: 5B                 pop         rbx
  0000000000000034: C3                 ret

  0000000000000077: 90                 nop
  0000000000000078: 48 8B C7           mov         rax,rdi
  000000000000007B: 48 8B 5C 24 58     mov         rbx,qword ptr [rsp+58h]
  0000000000000080: 48 83 C4 30        add         rsp,30h
  0000000000000084: 5F                 pop         rdi
  0000000000000085: C3                 ret

  000000000000003A: 90                 nop
  000000000000003B: 48 C7 03 00 00 00  mov         qword ptr [rbx],0
                    00
  0000000000000042: 48 C7 43 08 00 00  mov         qword ptr [rbx+8],0
                    00 00
  000000000000004A: 48 8D 50 10        lea         rdx,[rax+10h]
  000000000000004E: 4C 8B C0           mov         r8,rax
  0000000000000051: 48 8B CB           mov         rcx,rbx
  0000000000000054: E8 00 00 00 00     call        replaced
  0000000000000000: 48 89 5C 24 10     mov         qword ptr [rsp+10h],rbx
  0000000000000005: 48 89 6C 24 18     mov         qword ptr [rsp+18h],rbp
  000000000000000A: 48 89 74 24 20     mov         qword ptr [rsp+20h],rsi
  000000000000000F: 57                 push        rdi
  0000000000000010: 48 83 EC 20        sub         rsp,20h
  0000000000000014: 48 8B 79 08        mov         rdi,qword ptr [rcx+8]
  0000000000000018: 49 8B F0           mov         rsi,r8
  000000000000001B: 48 8B EA           mov         rbp,rdx
  000000000000001E: 48 8B D9           mov         rbx,rcx
  0000000000000021: 48 85 FF           test        rdi,rdi
  0000000000000024: 74 5D              je          0000000000000083
  0000000000000026: 4C 89 74 24 30     mov         qword ptr [rsp+30h],r14
  000000000000002B: 41 83 CE FF        or          r14d,0FFFFFFFFh
  000000000000002F: 41 8B C6           mov         eax,r14d
  0000000000000032: F0 0F C1 47 08     lock xadd   dword ptr [rdi+8],eax
  0000000000000037: 83 F8 01           cmp         eax,1
  000000000000003A: 75 3E              jne         000000000000007A
  000000000000003C: 48 8B 07           mov         rax,qword ptr [rdi]
  000000000000003F: 48 8B CF           mov         rcx,rdi
  0000000000000042: FF 10              call        qword ptr [rax]
  0000000000000044: F0 44 0F C1 77 0C  lock xadd   dword ptr [rdi+0Ch],r14d
  000000000000004A: 41 83 FE 01        cmp         r14d,1
  000000000000004E: 75 09              jne         0000000000000059
  0000000000000050: 48 8B 07           mov         rax,qword ptr [rdi]
  0000000000000053: 48 8B CF           mov         rcx,rdi
  0000000000000056: FF 50 08           call        qword ptr [rax+8]
  0000000000000059: 48 89 73 08        mov         qword ptr [rbx+8],rsi
  000000000000005D: 48 89 2B           mov         qword ptr [rbx],rbp
  0000000000000060: 4C 8B 74 24 30     mov         r14,qword ptr [rsp+30h]
  0000000000000065: 48 8B 5C 24 38     mov         rbx,qword ptr [rsp+38h]
  000000000000006A: 48 8B 6C 24 40     mov         rbp,qword ptr [rsp+40h]
  000000000000006F: 48 8B 74 24 48     mov         rsi,qword ptr [rsp+48h]
  0000000000000074: 48 83 C4 20        add         rsp,20h
  0000000000000078: 5F                 pop         rdi
  0000000000000079: C3                 ret
  000000000000007A: 4C 89 41 08        mov         qword ptr [rcx+8],r8
  000000000000007E: 48 89 11           mov         qword ptr [rcx],rdx
  0000000000000081: EB DD              jmp         0000000000000060
  0000000000000083: 4C 89 41 08        mov         qword ptr [rcx+8],r8
  0000000000000087: 48 89 11           mov         qword ptr [rcx],rdx
  000000000000008A: EB D9              jmp         0000000000000065

  0000000000000059: 48 8B C3           mov         rax,rbx
  000000000000005C: 48 83 C4 30        add         rsp,30h
  0000000000000060: 5B                 pop         rbx
  0000000000000061: C3                 ret

  0000000000000157: 4C 8B F0           mov         r14,rax
  000000000000015A: EB 03              jmp         000000000000015F
  000000000000015C: 4C 8B F6           mov         r14,rsi
  000000000000015F: 4C 89 75 FF        mov         qword ptr [rbp-1],r14
  0000000000000163: 4C 89 75 67        mov         qword ptr [rbp+67h],r14
  0000000000000167: 80 7F 18 00        cmp         byte ptr [rdi+18h],0
  000000000000016B: 75 06              jne         0000000000000173
  000000000000016D: 48 8B 47 20        mov         rax,qword ptr [rdi+20h]
  0000000000000171: EB 31              jmp         00000000000001A4
  0000000000000173: 48 8D 4F 19        lea         rcx,[rdi+19h]
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

  000000000000017C: 48 8B 47 20        mov         rax,qword ptr [rdi+20h]
  0000000000000180: 48 85 C0           test        rax,rax
  0000000000000183: 74 23              je          00000000000001A8
  0000000000000185: 0F B6 48 19        movzx       ecx,byte ptr [rax+19h]
  0000000000000189: 84 C9              test        cl,cl
  000000000000018B: 75 11              jne         000000000000019E
  000000000000018D: B9 01 00 00 00     mov         ecx,1
  0000000000000192: 86 48 19           xchg        cl,byte ptr [rax+19h]
  0000000000000195: 84 C9              test        cl,cl
  0000000000000197: 0F 95 C1           setne       cl
  000000000000019A: 84 C9              test        cl,cl
  000000000000019C: 74 06              je          00000000000001A4
  000000000000019E: C6 47 19 00        mov         byte ptr [rdi+19h],0
  00000000000001A2: EB CF              jmp         0000000000000173
  00000000000001A4: 48 89 45 A7        mov         qword ptr [rbp-59h],rax
  00000000000001A8: 48 89 7D AF        mov         qword ptr [rbp-51h],rdi
  00000000000001AC: 80 7F 10 00        cmp         byte ptr [rdi+10h],0
  00000000000001B0: 0F 95 C0           setne       al
  00000000000001B3: 84 C0              test        al,al
  00000000000001B5: 0F 85 EA 01 00 00  jne         00000000000003A5
  00000000000001BB: 48 8B CF           mov         rcx,rdi
  00000000000001BE: E8 00 00 00 00     call        replaced
  0000000000000000: 40 55              push        rbp
  0000000000000002: 48 8B EC           mov         rbp,rsp
  0000000000000005: 48 83 EC 70        sub         rsp,70h
  0000000000000009: 80 79 1A 00        cmp         byte ptr [rcx+1Ah],0
  000000000000000D: 75 13              jne         0000000000000022
  000000000000000F: 48 83 79 20 00     cmp         qword ptr [rcx+20h],0
  0000000000000014: 75 06              jne         000000000000001C
  0000000000000016: 80 79 10 00        cmp         byte ptr [rcx+10h],0
  000000000000001A: 74 6B              je          0000000000000087
  000000000000001C: 48 83 C4 70        add         rsp,70h
  0000000000000020: 5D                 pop         rbp
  0000000000000021: C3                 ret
  0000000000000022: C7 45 C0 01 00 00  mov         dword ptr [rbp-40h],1
                    00
  0000000000000029: E8 00 00 00 00     call        replaced
  0000000000000000: 48 83 EC 28        sub         rsp,28h
  0000000000000004: 8B 0D 00 00 00 00  mov         ecx,dword ptr [_tls_index]
  000000000000000A: 65 48 8B 04 25 58  mov         rax,qword ptr gs:[58h]
                    00 00 00
  0000000000000013: BA 00 00 00 00     mov         edx,offset _Init_thread_epoch
  0000000000000018: 48 8B 04 C8        mov         rax,qword ptr [rax+rcx*8]
  000000000000001C: 8B 0C 02           mov         ecx,dword ptr [rdx+rax]
  000000000000001F: 39 0D 00 00 00 00  cmp         dword ptr [?$TSS0@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4HA],ecx
  0000000000000025: 7E 46              jle         000000000000006D
  0000000000000027: 48 8D 0D 00 00 00  lea         rcx,[?$TSS0@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4HA]
                    00
  000000000000002E: E8 00 00 00 00     call        _Init_thread_header
  0000000000000033: 83 3D 00 00 00 00  cmp         dword ptr [?$TSS0@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4HA],0FFFFFFFFh
                    FF
  000000000000003A: 75 31              jne         000000000000006D
  000000000000003C: 48 8D 05 00 00 00  lea         rax,[??_7_Future_error_category@std@@6B@]
                    00
  0000000000000043: 48 C7 05 08 00 00  mov         qword ptr [?_Static@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4U?$_Immortalizer@V_Future_error_category@std@@@1@A+8],1
                    00 01 00 00 00
  000000000000004E: 48 8D 0D 00 00 00  lea         rcx,[??__F_Static@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@0@XZ@YAXXZ]
                    00
  0000000000000055: 48 89 05 00 00 00  mov         qword ptr [?_Static@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4U?$_Immortalizer@V_Future_error_category@std@@@1@A],rax
                    00
  000000000000005C: E8 00 00 00 00     call        atexit
  0000000000000061: 48 8D 0D 00 00 00  lea         rcx,[?$TSS0@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4HA]
                    00
  0000000000000068: E8 00 00 00 00     call        _Init_thread_footer
  000000000000006D: 48 8D 05 00 00 00  lea         rax,[?_Static@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4U?$_Immortalizer@V_Future_error_category@std@@@1@A]
                    00
  0000000000000074: 48 83 C4 28        add         rsp,28h
  0000000000000078: C3                 ret

  000000000000002E: 48 89 45 C8        mov         qword ptr [rbp-38h],rax
  0000000000000032: 48 8D 55 D8        lea         rdx,[rbp-28h]
  0000000000000036: 48 8D 05 00 00 00  lea         rax,[??_7exception@std@@6B@]
                    00
  000000000000003D: C6 45 B8 01        mov         byte ptr [rbp-48h],1
  0000000000000041: 48 89 45 D0        mov         qword ptr [rbp-30h],rax
  0000000000000045: 48 8D 4D B0        lea         rcx,[rbp-50h]
  0000000000000049: 33 C0              xor         eax,eax
  000000000000004B: 48 89 45 D8        mov         qword ptr [rbp-28h],rax
  000000000000004F: 48 89 45 E0        mov         qword ptr [rbp-20h],rax
  0000000000000053: 48 8D 05 00 00 00  lea         rax,[??_C@_00CNPNBAHC@?$AA@]
                    00
  000000000000005A: 48 89 45 B0        mov         qword ptr [rbp-50h],rax
  000000000000005E: E8 00 00 00 00     call        __std_exception_copy
  0000000000000063: 0F 10 45 C0        movups      xmm0,xmmword ptr [rbp-40h]
  0000000000000067: 48 8D 05 00 00 00  lea         rax,[??_7future_error@std@@6B@]
                    00
  000000000000006E: 48 8D 15 00 00 00  lea         rdx,[_TI3?AVfuture_error@std@@]
                    00
  0000000000000075: 48 89 45 D0        mov         qword ptr [rbp-30h],rax
  0000000000000079: 48 8D 4D D0        lea         rcx,[rbp-30h]
  000000000000007D: 0F 11 45 E8        movups      xmmword ptr [rbp-18h],xmm0
  0000000000000081: E8 00 00 00 00     call        _CxxThrowException
  0000000000000086: CC                 int         3
  0000000000000087: C7 45 B0 04 00 00  mov         dword ptr [rbp-50h],4
                    00
  000000000000008E: E8 00 00 00 00     call        replaced
  0000000000000000: 48 83 EC 28        sub         rsp,28h
  0000000000000004: 8B 0D 00 00 00 00  mov         ecx,dword ptr [_tls_index]
  000000000000000A: 65 48 8B 04 25 58  mov         rax,qword ptr gs:[58h]
                    00 00 00
  0000000000000013: BA 00 00 00 00     mov         edx,offset _Init_thread_epoch
  0000000000000018: 48 8B 04 C8        mov         rax,qword ptr [rax+rcx*8]
  000000000000001C: 8B 0C 02           mov         ecx,dword ptr [rdx+rax]
  000000000000001F: 39 0D 00 00 00 00  cmp         dword ptr [?$TSS0@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4HA],ecx
  0000000000000025: 7E 46              jle         000000000000006D
  0000000000000027: 48 8D 0D 00 00 00  lea         rcx,[?$TSS0@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4HA]
                    00
  000000000000002E: E8 00 00 00 00     call        _Init_thread_header
  0000000000000033: 83 3D 00 00 00 00  cmp         dword ptr [?$TSS0@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4HA],0FFFFFFFFh
                    FF
  000000000000003A: 75 31              jne         000000000000006D
  000000000000003C: 48 8D 05 00 00 00  lea         rax,[??_7_Future_error_category@std@@6B@]
                    00
  0000000000000043: 48 C7 05 08 00 00  mov         qword ptr [?_Static@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4U?$_Immortalizer@V_Future_error_category@std@@@1@A+8],1
                    00 01 00 00 00
  000000000000004E: 48 8D 0D 00 00 00  lea         rcx,[??__F_Static@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@0@XZ@YAXXZ]
                    00
  0000000000000055: 48 89 05 00 00 00  mov         qword ptr [?_Static@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4U?$_Immortalizer@V_Future_error_category@std@@@1@A],rax
                    00
  000000000000005C: E8 00 00 00 00     call        atexit
  0000000000000061: 48 8D 0D 00 00 00  lea         rcx,[?$TSS0@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4HA]
                    00
  0000000000000068: E8 00 00 00 00     call        _Init_thread_footer
  000000000000006D: 48 8D 05 00 00 00  lea         rax,[?_Static@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4U?$_Immortalizer@V_Future_error_category@std@@@1@A]
                    00
  0000000000000074: 48 83 C4 28        add         rsp,28h
  0000000000000078: C3                 ret

  0000000000000093: 48 89 45 B8        mov         qword ptr [rbp-48h],rax
  0000000000000097: 48 8D 55 D8        lea         rdx,[rbp-28h]
  000000000000009B: 48 8D 05 00 00 00  lea         rax,[??_7exception@std@@6B@]
                    00
  00000000000000A2: C6 45 C8 01        mov         byte ptr [rbp-38h],1
  00000000000000A6: 48 89 45 D0        mov         qword ptr [rbp-30h],rax
  00000000000000AA: 48 8D 4D C0        lea         rcx,[rbp-40h]
  00000000000000AE: 33 C0              xor         eax,eax
  00000000000000B0: 48 89 45 D8        mov         qword ptr [rbp-28h],rax
  00000000000000B4: 48 89 45 E0        mov         qword ptr [rbp-20h],rax
  00000000000000B8: 48 8D 05 00 00 00  lea         rax,[??_C@_00CNPNBAHC@?$AA@]
                    00
  00000000000000BF: 48 89 45 C0        mov         qword ptr [rbp-40h],rax
  00000000000000C3: E8 00 00 00 00     call        __std_exception_copy
  00000000000000C8: 0F 10 45 B0        movups      xmm0,xmmword ptr [rbp-50h]
  00000000000000CC: 48 8D 05 00 00 00  lea         rax,[??_7future_error@std@@6B@]
                    00
  00000000000000D3: 48 8D 15 00 00 00  lea         rdx,[_TI3?AVfuture_error@std@@]
                    00
  00000000000000DA: 48 89 45 D0        mov         qword ptr [rbp-30h],rax
  00000000000000DE: 48 8D 4D D0        lea         rcx,[rbp-30h]
  00000000000000E2: 0F 11 45 E8        movups      xmmword ptr [rbp-18h],xmm0
  00000000000000E6: E8 00 00 00 00     call        _CxxThrowException
  00000000000000EB: CC                 int         3

  00000000000001C3: 48 8B 47 20        mov         rax,qword ptr [rdi+20h]
  00000000000001C7: 48 83 C0 38        add         rax,38h
  00000000000001CB: 48 83 38 00        cmp         qword ptr [rax],0
  00000000000001CF: 75 59              jne         000000000000022A
  00000000000001D1: 48 8D 4D 67        lea         rcx,[rbp+67h]
  00000000000001D5: 48 3B C1           cmp         rax,rcx
  00000000000001D8: 74 50              je          000000000000022A
  00000000000001DA: 48 89 75 67        mov         qword ptr [rbp+67h],rsi
  00000000000001DE: 48 8B 30           mov         rsi,qword ptr [rax]
  00000000000001E1: 4C 89 30           mov         qword ptr [rax],r14
  00000000000001E4: 48 85 F6           test        rsi,rsi
  00000000000001E7: 74 41              je          000000000000022A
  00000000000001E9: 48 8B 5E 08        mov         rbx,qword ptr [rsi+8]
  00000000000001ED: 48 85 DB           test        rbx,rbx
  00000000000001F0: 74 2B              je          000000000000021D
  00000000000001F2: 41 8B C7           mov         eax,r15d
  00000000000001F5: F0 0F C1 43 08     lock xadd   dword ptr [rbx+8],eax
  00000000000001FA: 83 F8 01           cmp         eax,1
  00000000000001FD: 75 1E              jne         000000000000021D
  00000000000001FF: 48 8B 03           mov         rax,qword ptr [rbx]
  0000000000000202: 48 8B CB           mov         rcx,rbx
  0000000000000205: FF 10              call        qword ptr [rax]
  0000000000000207: 41 8B C7           mov         eax,r15d
  000000000000020A: F0 0F C1 43 0C     lock xadd   dword ptr [rbx+0Ch],eax
  000000000000020F: 83 F8 01           cmp         eax,1
  0000000000000212: 75 09              jne         000000000000021D
  0000000000000214: 48 8B 03           mov         rax,qword ptr [rbx]
  0000000000000217: 48 8B CB           mov         rcx,rbx
  000000000000021A: FF 50 08           call        qword ptr [rax+8]
  000000000000021D: BA 10 00 00 00     mov         edx,10h
  0000000000000222: 48 8B CE           mov         rcx,rsi
  0000000000000225: E8 00 00 00 00     call        ??3@YAXPEAX_K@Z
  000000000000022A: 48 8B 47 20        mov         rax,qword ptr [rdi+20h]
  000000000000022E: 48 8B 40 38        mov         rax,qword ptr [rax+38h]
  0000000000000232: 48 8B 48 08        mov         rcx,qword ptr [rax+8]
  0000000000000236: 48 8B 30           mov         rsi,qword ptr [rax]
  0000000000000239: 48 85 C9           test        rcx,rcx
  000000000000023C: 74 04              je          0000000000000242
  000000000000023E: F0 FF 41 08        lock inc    dword ptr [rcx+8]
  0000000000000242: 48 89 4D 07        mov         qword ptr [rbp+7],rcx
  0000000000000246: 48 8B 55 BF        mov         rdx,qword ptr [rbp-41h]
  000000000000024A: 48 89 55 CF        mov         qword ptr [rbp-31h],rdx
  000000000000024E: 48 89 4D BF        mov         qword ptr [rbp-41h],rcx
  0000000000000252: 48 89 75 0F        mov         qword ptr [rbp+0Fh],rsi
  0000000000000256: 48 8B 45 B7        mov         rax,qword ptr [rbp-49h]
  000000000000025A: 48 89 45 C7        mov         qword ptr [rbp-39h],rax
  000000000000025E: 48 89 75 B7        mov         qword ptr [rbp-49h],rsi
  0000000000000262: 48 85 D2           test        rdx,rdx
  0000000000000265: 74 31              je          0000000000000298
  0000000000000267: 41 8B C7           mov         eax,r15d
  000000000000026A: F0 0F C1 42 08     lock xadd   dword ptr [rdx+8],eax
  000000000000026F: 83 F8 01           cmp         eax,1
  0000000000000272: 75 24              jne         0000000000000298
  0000000000000274: 48 8B 5D CF        mov         rbx,qword ptr [rbp-31h]
  0000000000000278: 48 8B 03           mov         rax,qword ptr [rbx]
  000000000000027B: 48 8B CB           mov         rcx,rbx
  000000000000027E: FF 10              call        qword ptr [rax]
  0000000000000280: 41 8B C7           mov         eax,r15d
  0000000000000283: F0 0F C1 43 0C     lock xadd   dword ptr [rbx+0Ch],eax
  0000000000000288: 83 F8 01           cmp         eax,1
  000000000000028B: 75 0B              jne         0000000000000298
  000000000000028D: 48 8B 4D CF        mov         rcx,qword ptr [rbp-31h]
  0000000000000291: 48 8B 01           mov         rax,qword ptr [rcx]
  0000000000000294: FF 50 08           call        qword ptr [rax+8]
  0000000000000297: 90                 nop
  0000000000000298: 48 8B 45 67        mov         rax,qword ptr [rbp+67h]
  000000000000029C: 48 85 C0           test        rax,rax
  000000000000029F: 74 42              je          00000000000002E3
  00000000000002A1: 48 8B 58 08        mov         rbx,qword ptr [rax+8]
  00000000000002A5: 48 85 DB           test        rbx,rbx
  00000000000002A8: 74 2B              je          00000000000002D5
  00000000000002AA: 41 8B C7           mov         eax,r15d
  00000000000002AD: F0 0F C1 43 08     lock xadd   dword ptr [rbx+8],eax
  00000000000002B2: 83 F8 01           cmp         eax,1
  00000000000002B5: 75 1E              jne         00000000000002D5
  00000000000002B7: 48 8B 03           mov         rax,qword ptr [rbx]
  00000000000002BA: 48 8B CB           mov         rcx,rbx
  00000000000002BD: FF 10              call        qword ptr [rax]
  00000000000002BF: 41 8B C7           mov         eax,r15d
  00000000000002C2: F0 0F C1 43 0C     lock xadd   dword ptr [rbx+0Ch],eax
  00000000000002C7: 83 F8 01           cmp         eax,1
  00000000000002CA: 75 09              jne         00000000000002D5
  00000000000002CC: 48 8B 03           mov         rax,qword ptr [rbx]
  00000000000002CF: 48 8B CB           mov         rcx,rbx
  00000000000002D2: FF 50 08           call        qword ptr [rax+8]
  00000000000002D5: BA 10 00 00 00     mov         edx,10h
  00000000000002DA: 48 8B 4D 67        mov         rcx,qword ptr [rbp+67h]
  00000000000002DE: E8 00 00 00 00     call        ??3@YAXPEAX_K@Z
  00000000000002E3: 48 85 F6           test        rsi,rsi
  00000000000002E6: BE 00 00 00 00     mov         esi,0
  00000000000002EB: 0F 84 14 FE FF FF  je          0000000000000105
  00000000000002F1: 48 8B 45 A7        mov         rax,qword ptr [rbp-59h]
  00000000000002F5: 48 85 C0           test        rax,rax
  00000000000002F8: 74 0E              je          0000000000000308
  00000000000002FA: 80 78 18 00        cmp         byte ptr [rax+18h],0
  00000000000002FE: 74 04              je          0000000000000304
  0000000000000300: C6 40 19 00        mov         byte ptr [rax+19h],0
  0000000000000304: 48 89 75 A7        mov         qword ptr [rbp-59h],rsi
  0000000000000308: 80 7F 18 00        cmp         byte ptr [rdi+18h],0
  000000000000030C: 74 04              je          0000000000000312
  000000000000030E: C6 47 19 00        mov         byte ptr [rdi+19h],0
  0000000000000312: 48 89 75 AF        mov         qword ptr [rbp-51h],rsi
  0000000000000316: 48 8B 55 B7        mov         rdx,qword ptr [rbp-49h]
  000000000000031A: 48 85 D2           test        rdx,rdx
  000000000000031D: 0F 95 C0           setne       al
  0000000000000320: 84 C0              test        al,al
  0000000000000322: 74 24              je          0000000000000348
  0000000000000324: 48 8B 4A 18        mov         rcx,qword ptr [rdx+18h]
  0000000000000328: 48 85 C9           test        rcx,rcx
  000000000000032B: 0F 84 87 00 00 00  je          00000000000003B8
  0000000000000331: 80 7A 20 00        cmp         byte ptr [rdx+20h],0
  0000000000000335: 74 09              je          0000000000000340
  0000000000000337: 80 B9 B8 00 00 00  cmp         byte ptr [rcx+0B8h],0
                    00
  000000000000033E: 75 78              jne         00000000000003B8
  0000000000000340: 48 8B 01           mov         rax,qword ptr [rcx]
  0000000000000343: FF 50 08           call        qword ptr [rax+8]
  0000000000000346: EB 05              jmp         000000000000034D
  0000000000000348: E8 00 00 00 00     call        _Thrd_yield
  000000000000034D: 80 7F 18 00        cmp         byte ptr [rdi+18h],0
  0000000000000351: 75 0A              jne         000000000000035D
  0000000000000353: 48 8B 47 20        mov         rax,qword ptr [rdi+20h]
  0000000000000357: 48 89 45 A7        mov         qword ptr [rbp-59h],rax
  000000000000035B: EB 35              jmp         0000000000000392
  000000000000035D: 48 8D 4F 19        lea         rcx,[rdi+19h]
  0000000000000361: E8 00 00 00 00     call        replaced
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

  0000000000000366: 48 8B 4F 20        mov         rcx,qword ptr [rdi+20h]
  000000000000036A: 48 85 C9           test        rcx,rcx
  000000000000036D: 74 23              je          0000000000000392
  000000000000036F: 0F B6 41 19        movzx       eax,byte ptr [rcx+19h]
  0000000000000373: 84 C0              test        al,al
  0000000000000375: 75 11              jne         0000000000000388
  0000000000000377: B8 01 00 00 00     mov         eax,1
  000000000000037C: 86 41 19           xchg        al,byte ptr [rcx+19h]
  000000000000037F: 84 C0              test        al,al
  0000000000000381: 0F 95 C0           setne       al
  0000000000000384: 84 C0              test        al,al
  0000000000000386: 74 06              je          000000000000038E
  0000000000000388: C6 47 19 00        mov         byte ptr [rdi+19h],0
  000000000000038C: EB CF              jmp         000000000000035D
  000000000000038E: 48 89 4D A7        mov         qword ptr [rbp-59h],rcx
  0000000000000392: 48 89 7D AF        mov         qword ptr [rbp-51h],rdi
  0000000000000396: 49 FF C4           inc         r12
  0000000000000399: 80 7F 10 00        cmp         byte ptr [rdi+10h],0
  000000000000039D: 0F 95 C0           setne       al
  00000000000003A0: E9 48 FD FF FF     jmp         00000000000000ED
  00000000000003A5: 4D 85 F6           test        r14,r14
  00000000000003A8: 74 28              je          00000000000003D2
  00000000000003AA: 49 8B D6           mov         rdx,r14
  00000000000003AD: 48 8D 4D 67        lea         rcx,[rbp+67h]
  00000000000003B1: E8 00 00 00 00     call        replaced
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

  00000000000003B6: EB 1A              jmp         00000000000003D2
  00000000000003B8: E8 00 00 00 00     call        replaced
  0000000000000000: 48 83 EC 28        sub         rsp,28h
  0000000000000004: 8B 0D 00 00 00 00  mov         ecx,dword ptr [_tls_index]
  000000000000000A: 65 48 8B 04 25 58  mov         rax,qword ptr gs:[58h]
                    00 00 00
  0000000000000013: BA 00 00 00 00     mov         edx,offset _Init_thread_epoch
  0000000000000018: 48 8B 04 C8        mov         rax,qword ptr [rax+rcx*8]
  000000000000001C: 8B 0C 02           mov         ecx,dword ptr [rdx+rax]
  000000000000001F: 39 0D 00 00 00 00  cmp         dword ptr [?$TSS0@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4HA],ecx
  0000000000000025: 7E 46              jle         000000000000006D
  0000000000000027: 48 8D 0D 00 00 00  lea         rcx,[?$TSS0@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4HA]
                    00
  000000000000002E: E8 00 00 00 00     call        _Init_thread_header
  0000000000000033: 83 3D 00 00 00 00  cmp         dword ptr [?$TSS0@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4HA],0FFFFFFFFh
                    FF
  000000000000003A: 75 31              jne         000000000000006D
  000000000000003C: 48 8D 05 00 00 00  lea         rax,[??_7_Future_error_category@std@@6B@]
                    00
  0000000000000043: 48 C7 05 08 00 00  mov         qword ptr [?_Static@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4U?$_Immortalizer@V_Future_error_category@std@@@1@A+8],1
                    00 01 00 00 00
  000000000000004E: 48 8D 0D 00 00 00  lea         rcx,[??__F_Static@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@0@XZ@YAXXZ]
                    00
  0000000000000055: 48 89 05 00 00 00  mov         qword ptr [?_Static@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4U?$_Immortalizer@V_Future_error_category@std@@@1@A],rax
                    00
  000000000000005C: E8 00 00 00 00     call        atexit
  0000000000000061: 48 8D 0D 00 00 00  lea         rcx,[?$TSS0@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4HA]
                    00
  0000000000000068: E8 00 00 00 00     call        _Init_thread_footer
  000000000000006D: 48 8D 05 00 00 00  lea         rax,[?_Static@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4U?$_Immortalizer@V_Future_error_category@std@@@1@A]
                    00
  0000000000000074: 48 83 C4 28        add         rsp,28h
  0000000000000078: C3                 ret

  00000000000003BD: C7 45 D7 04 00 00  mov         dword ptr [rbp-29h],4
                    00
  00000000000003C4: 48 89 45 DF        mov         qword ptr [rbp-21h],rax
  00000000000003C8: 48 8D 4D D7        lea         rcx,[rbp-29h]
  00000000000003CC: E8 00 00 00 00     call        ?_Throw_future_error@std@@YAXAEBVerror_code@1@@Z
  00000000000003D1: 90                 nop
  00000000000003D2: 48 8B 4D BF        mov         rcx,qword ptr [rbp-41h]
  00000000000003D6: 48 85 C9           test        rcx,rcx
  00000000000003D9: 74 30              je          000000000000040B
  00000000000003DB: 41 8B C7           mov         eax,r15d
  00000000000003DE: F0 0F C1 41 08     lock xadd   dword ptr [rcx+8],eax
  00000000000003E3: 83 F8 01           cmp         eax,1
  00000000000003E6: 75 23              jne         000000000000040B
  00000000000003E8: 48 8B 5D BF        mov         rbx,qword ptr [rbp-41h]
  00000000000003EC: 48 8B 03           mov         rax,qword ptr [rbx]
  00000000000003EF: 48 8B CB           mov         rcx,rbx
  00000000000003F2: FF 10              call        qword ptr [rax]
  00000000000003F4: F0 44 0F C1 7B 0C  lock xadd   dword ptr [rbx+0Ch],r15d
  00000000000003FA: 41 83 FF 01        cmp         r15d,1
  00000000000003FE: 75 0B              jne         000000000000040B
  0000000000000400: 48 8B 4D BF        mov         rcx,qword ptr [rbp-41h]
  0000000000000404: 48 8B 01           mov         rax,qword ptr [rcx]
  0000000000000407: FF 50 08           call        qword ptr [rax+8]
  000000000000040A: 90                 nop
  000000000000040B: 48 8B 45 A7        mov         rax,qword ptr [rbp-59h]
  000000000000040F: 48 85 C0           test        rax,rax
  0000000000000412: 74 0E              je          0000000000000422
  0000000000000414: 80 78 18 00        cmp         byte ptr [rax+18h],0
  0000000000000418: 74 04              je          000000000000041E
  000000000000041A: C6 40 19 00        mov         byte ptr [rax+19h],0
  000000000000041E: 48 89 75 A7        mov         qword ptr [rbp-59h],rsi
  0000000000000422: 80 7F 18 00        cmp         byte ptr [rdi+18h],0
  0000000000000426: 74 04              je          000000000000042C
  0000000000000428: C6 47 19 00        mov         byte ptr [rdi+19h],0
  000000000000042C: 33 C0              xor         eax,eax
  000000000000042E: 48 8B 9C 24 E8 00  mov         rbx,qword ptr [rsp+0E8h]
                    00 00
  0000000000000436: 48 81 C4 A0 00 00  add         rsp,0A0h
                    00
  000000000000043D: 41 5F              pop         r15
  000000000000043F: 41 5E              pop         r14
  0000000000000441: 41 5D              pop         r13
  0000000000000443: 41 5C              pop         r12
  0000000000000445: 5F                 pop         rdi
  0000000000000446: 5E                 pop         rsi
  0000000000000447: 5D                 pop         rbp
  0000000000000448: C3                 ret

  000000000000009E: 0F 57 C0           xorps       xmm0,xmm0
  00000000000000A1: F3 0F 7F 44 24 48  movdqu      xmmword ptr [rsp+48h],xmm0
  00000000000000A7: 80 7C 24 38 00     cmp         byte ptr [rsp+38h],0
  00000000000000AC: 75 0C              jne         00000000000000BA
  00000000000000AE: 48 8B 5C 24 40     mov         rbx,qword ptr [rsp+40h]
  00000000000000B3: 48 89 5C 24 48     mov         qword ptr [rsp+48h],rbx
  00000000000000B8: EB 3C              jmp         00000000000000F6
  00000000000000BA: 48 8D 4C 24 39     lea         rcx,[rsp+39h]
  00000000000000BF: E8 00 00 00 00     call        replaced
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

  00000000000000C4: 48 8B 4C 24 40     mov         rcx,qword ptr [rsp+40h]
  00000000000000C9: 48 85 C9           test        rcx,rcx
  00000000000000CC: 48 8B D9           mov         rbx,rcx
  00000000000000CF: 74 20              je          00000000000000F1
  00000000000000D1: 0F B6 41 19        movzx       eax,byte ptr [rcx+19h]
  00000000000000D5: 84 C0              test        al,al
  00000000000000D7: 75 11              jne         00000000000000EA
  00000000000000D9: B8 01 00 00 00     mov         eax,1
  00000000000000DE: 86 41 19           xchg        al,byte ptr [rcx+19h]
  00000000000000E1: 84 C0              test        al,al
  00000000000000E3: 0F 95 C0           setne       al
  00000000000000E6: 84 C0              test        al,al
  00000000000000E8: 74 C9              je          00000000000000B3
  00000000000000EA: C6 44 24 39 00     mov         byte ptr [rsp+39h],0
  00000000000000EF: EB C9              jmp         00000000000000BA
  00000000000000F1: 48 8B 5C 24 48     mov         rbx,qword ptr [rsp+48h]
  00000000000000F6: 48 8D 44 24 20     lea         rax,[rsp+20h]
  00000000000000FB: 48 89 44 24 50     mov         qword ptr [rsp+50h],rax
  0000000000000100: 48 8D 4C 24 20     lea         rcx,[rsp+20h]
  0000000000000105: E8 00 00 00 00     call        replaced
  0000000000000000: 40 55              push        rbp
  0000000000000002: 48 8B EC           mov         rbp,rsp
  0000000000000005: 48 83 EC 70        sub         rsp,70h
  0000000000000009: 80 79 1A 00        cmp         byte ptr [rcx+1Ah],0
  000000000000000D: 75 13              jne         0000000000000022
  000000000000000F: 48 83 79 20 00     cmp         qword ptr [rcx+20h],0
  0000000000000014: 75 06              jne         000000000000001C
  0000000000000016: 80 79 10 00        cmp         byte ptr [rcx+10h],0
  000000000000001A: 74 6B              je          0000000000000087
  000000000000001C: 48 83 C4 70        add         rsp,70h
  0000000000000020: 5D                 pop         rbp
  0000000000000021: C3                 ret
  0000000000000022: C7 45 C0 01 00 00  mov         dword ptr [rbp-40h],1
                    00
  0000000000000029: E8 00 00 00 00     call        replaced
  0000000000000000: 48 83 EC 28        sub         rsp,28h
  0000000000000004: 8B 0D 00 00 00 00  mov         ecx,dword ptr [_tls_index]
  000000000000000A: 65 48 8B 04 25 58  mov         rax,qword ptr gs:[58h]
                    00 00 00
  0000000000000013: BA 00 00 00 00     mov         edx,offset _Init_thread_epoch
  0000000000000018: 48 8B 04 C8        mov         rax,qword ptr [rax+rcx*8]
  000000000000001C: 8B 0C 02           mov         ecx,dword ptr [rdx+rax]
  000000000000001F: 39 0D 00 00 00 00  cmp         dword ptr [?$TSS0@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4HA],ecx
  0000000000000025: 7E 46              jle         000000000000006D
  0000000000000027: 48 8D 0D 00 00 00  lea         rcx,[?$TSS0@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4HA]
                    00
  000000000000002E: E8 00 00 00 00     call        _Init_thread_header
  0000000000000033: 83 3D 00 00 00 00  cmp         dword ptr [?$TSS0@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4HA],0FFFFFFFFh
                    FF
  000000000000003A: 75 31              jne         000000000000006D
  000000000000003C: 48 8D 05 00 00 00  lea         rax,[??_7_Future_error_category@std@@6B@]
                    00
  0000000000000043: 48 C7 05 08 00 00  mov         qword ptr [?_Static@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4U?$_Immortalizer@V_Future_error_category@std@@@1@A+8],1
                    00 01 00 00 00
  000000000000004E: 48 8D 0D 00 00 00  lea         rcx,[??__F_Static@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@0@XZ@YAXXZ]
                    00
  0000000000000055: 48 89 05 00 00 00  mov         qword ptr [?_Static@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4U?$_Immortalizer@V_Future_error_category@std@@@1@A],rax
                    00
  000000000000005C: E8 00 00 00 00     call        atexit
  0000000000000061: 48 8D 0D 00 00 00  lea         rcx,[?$TSS0@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4HA]
                    00
  0000000000000068: E8 00 00 00 00     call        _Init_thread_footer
  000000000000006D: 48 8D 05 00 00 00  lea         rax,[?_Static@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4U?$_Immortalizer@V_Future_error_category@std@@@1@A]
                    00
  0000000000000074: 48 83 C4 28        add         rsp,28h
  0000000000000078: C3                 ret

  000000000000002E: 48 89 45 C8        mov         qword ptr [rbp-38h],rax
  0000000000000032: 48 8D 55 D8        lea         rdx,[rbp-28h]
  0000000000000036: 48 8D 05 00 00 00  lea         rax,[??_7exception@std@@6B@]
                    00
  000000000000003D: C6 45 B8 01        mov         byte ptr [rbp-48h],1
  0000000000000041: 48 89 45 D0        mov         qword ptr [rbp-30h],rax
  0000000000000045: 48 8D 4D B0        lea         rcx,[rbp-50h]
  0000000000000049: 33 C0              xor         eax,eax
  000000000000004B: 48 89 45 D8        mov         qword ptr [rbp-28h],rax
  000000000000004F: 48 89 45 E0        mov         qword ptr [rbp-20h],rax
  0000000000000053: 48 8D 05 00 00 00  lea         rax,[??_C@_00CNPNBAHC@?$AA@]
                    00
  000000000000005A: 48 89 45 B0        mov         qword ptr [rbp-50h],rax
  000000000000005E: E8 00 00 00 00     call        __std_exception_copy
  0000000000000063: 0F 10 45 C0        movups      xmm0,xmmword ptr [rbp-40h]
  0000000000000067: 48 8D 05 00 00 00  lea         rax,[??_7future_error@std@@6B@]
                    00
  000000000000006E: 48 8D 15 00 00 00  lea         rdx,[_TI3?AVfuture_error@std@@]
                    00
  0000000000000075: 48 89 45 D0        mov         qword ptr [rbp-30h],rax
  0000000000000079: 48 8D 4D D0        lea         rcx,[rbp-30h]
  000000000000007D: 0F 11 45 E8        movups      xmmword ptr [rbp-18h],xmm0
  0000000000000081: E8 00 00 00 00     call        _CxxThrowException
  0000000000000086: CC                 int         3
  0000000000000087: C7 45 B0 04 00 00  mov         dword ptr [rbp-50h],4
                    00
  000000000000008E: E8 00 00 00 00     call        replaced
  0000000000000000: 48 83 EC 28        sub         rsp,28h
  0000000000000004: 8B 0D 00 00 00 00  mov         ecx,dword ptr [_tls_index]
  000000000000000A: 65 48 8B 04 25 58  mov         rax,qword ptr gs:[58h]
                    00 00 00
  0000000000000013: BA 00 00 00 00     mov         edx,offset _Init_thread_epoch
  0000000000000018: 48 8B 04 C8        mov         rax,qword ptr [rax+rcx*8]
  000000000000001C: 8B 0C 02           mov         ecx,dword ptr [rdx+rax]
  000000000000001F: 39 0D 00 00 00 00  cmp         dword ptr [?$TSS0@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4HA],ecx
  0000000000000025: 7E 46              jle         000000000000006D
  0000000000000027: 48 8D 0D 00 00 00  lea         rcx,[?$TSS0@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4HA]
                    00
  000000000000002E: E8 00 00 00 00     call        _Init_thread_header
  0000000000000033: 83 3D 00 00 00 00  cmp         dword ptr [?$TSS0@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4HA],0FFFFFFFFh
                    FF
  000000000000003A: 75 31              jne         000000000000006D
  000000000000003C: 48 8D 05 00 00 00  lea         rax,[??_7_Future_error_category@std@@6B@]
                    00
  0000000000000043: 48 C7 05 08 00 00  mov         qword ptr [?_Static@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4U?$_Immortalizer@V_Future_error_category@std@@@1@A+8],1
                    00 01 00 00 00
  000000000000004E: 48 8D 0D 00 00 00  lea         rcx,[??__F_Static@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@0@XZ@YAXXZ]
                    00
  0000000000000055: 48 89 05 00 00 00  mov         qword ptr [?_Static@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4U?$_Immortalizer@V_Future_error_category@std@@@1@A],rax
                    00
  000000000000005C: E8 00 00 00 00     call        atexit
  0000000000000061: 48 8D 0D 00 00 00  lea         rcx,[?$TSS0@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4HA]
                    00
  0000000000000068: E8 00 00 00 00     call        _Init_thread_footer
  000000000000006D: 48 8D 05 00 00 00  lea         rax,[?_Static@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4U?$_Immortalizer@V_Future_error_category@std@@@1@A]
                    00
  0000000000000074: 48 83 C4 28        add         rsp,28h
  0000000000000078: C3                 ret

  0000000000000093: 48 89 45 B8        mov         qword ptr [rbp-48h],rax
  0000000000000097: 48 8D 55 D8        lea         rdx,[rbp-28h]
  000000000000009B: 48 8D 05 00 00 00  lea         rax,[??_7exception@std@@6B@]
                    00
  00000000000000A2: C6 45 C8 01        mov         byte ptr [rbp-38h],1
  00000000000000A6: 48 89 45 D0        mov         qword ptr [rbp-30h],rax
  00000000000000AA: 48 8D 4D C0        lea         rcx,[rbp-40h]
  00000000000000AE: 33 C0              xor         eax,eax
  00000000000000B0: 48 89 45 D8        mov         qword ptr [rbp-28h],rax
  00000000000000B4: 48 89 45 E0        mov         qword ptr [rbp-20h],rax
  00000000000000B8: 48 8D 05 00 00 00  lea         rax,[??_C@_00CNPNBAHC@?$AA@]
                    00
  00000000000000BF: 48 89 45 C0        mov         qword ptr [rbp-40h],rax
  00000000000000C3: E8 00 00 00 00     call        __std_exception_copy
  00000000000000C8: 0F 10 45 B0        movups      xmm0,xmmword ptr [rbp-50h]
  00000000000000CC: 48 8D 05 00 00 00  lea         rax,[??_7future_error@std@@6B@]
                    00
  00000000000000D3: 48 8D 15 00 00 00  lea         rdx,[_TI3?AVfuture_error@std@@]
                    00
  00000000000000DA: 48 89 45 D0        mov         qword ptr [rbp-30h],rax
  00000000000000DE: 48 8D 4D D0        lea         rcx,[rbp-30h]
  00000000000000E2: 0F 11 45 E8        movups      xmmword ptr [rbp-18h],xmm0
  00000000000000E6: E8 00 00 00 00     call        _CxxThrowException
  00000000000000EB: CC                 int         3

  000000000000010A: 0F B6 44 24 30     movzx       eax,byte ptr [rsp+30h]
  000000000000010F: 3C 02              cmp         al,2
  0000000000000111: 0F 94 C1           sete        cl
  0000000000000114: 84 C9              test        cl,cl
  0000000000000116: 75 12              jne         000000000000012A
  0000000000000118: 2C 02              sub         al,2
  000000000000011A: 3C 01              cmp         al,1
  000000000000011C: 0F 87 BA 01 00 00  ja          00000000000002DC
  0000000000000122: 84 C9              test        cl,cl
  0000000000000124: 0F 84 40 01 00 00  je          000000000000026A
  000000000000012A: 48 8B 5C 24 28     mov         rbx,qword ptr [rsp+28h]
  000000000000012F: E8 00 00 00 00     call        replaced
  0000000000000000: 48 83 EC 28        sub         rsp,28h
  0000000000000004: 8B 0D 00 00 00 00  mov         ecx,dword ptr [_tls_index]
  000000000000000A: 65 48 8B 04 25 58  mov         rax,qword ptr gs:[58h]
                    00 00 00
  0000000000000013: BA 00 00 00 00     mov         edx,offset _Init_thread_epoch
  0000000000000018: 48 8B 04 C8        mov         rax,qword ptr [rax+rcx*8]
  000000000000001C: 8B 0C 02           mov         ecx,dword ptr [rdx+rax]
  000000000000001F: 39 0D 00 00 00 00  cmp         dword ptr [?$TSS0@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4HA],ecx
  0000000000000025: 7E 46              jle         000000000000006D
  0000000000000027: 48 8D 0D 00 00 00  lea         rcx,[?$TSS0@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4HA]
                    00
  000000000000002E: E8 00 00 00 00     call        _Init_thread_header
  0000000000000033: 83 3D 00 00 00 00  cmp         dword ptr [?$TSS0@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4HA],0FFFFFFFFh
                    FF
  000000000000003A: 75 31              jne         000000000000006D
  000000000000003C: 48 8D 05 00 00 00  lea         rax,[??_7_Future_error_category@std@@6B@]
                    00
  0000000000000043: 48 C7 05 08 00 00  mov         qword ptr [?_Static@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4U?$_Immortalizer@V_Future_error_category@std@@@1@A+8],1
                    00 01 00 00 00
  000000000000004E: 48 8D 0D 00 00 00  lea         rcx,[??__F_Static@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@0@XZ@YAXXZ]
                    00
  0000000000000055: 48 89 05 00 00 00  mov         qword ptr [?_Static@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4U?$_Immortalizer@V_Future_error_category@std@@@1@A],rax
                    00
  000000000000005C: E8 00 00 00 00     call        atexit
  0000000000000061: 48 8D 0D 00 00 00  lea         rcx,[?$TSS0@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4HA]
                    00
  0000000000000068: E8 00 00 00 00     call        _Init_thread_footer
  000000000000006D: 48 8D 05 00 00 00  lea         rax,[?_Static@?1???$_Immortalize@V_Future_error_category@std@@@std@@YAAEAV_Future_error_category@1@XZ@4U?$_Immortalizer@V_Future_error_category@std@@@1@A]
                    00
  0000000000000074: 48 83 C4 28        add         rsp,28h
  0000000000000078: C3                 ret

  0000000000000134: 48 8B 48 08        mov         rcx,qword ptr [rax+8]
  0000000000000138: 48 39 4B 08        cmp         qword ptr [rbx+8],rcx
  000000000000013C: 0F 94 C0           sete        al
  000000000000013F: 84 C0              test        al,al
  0000000000000141: 0F 84 A0 00 00 00  je          00000000000001E7
  0000000000000147: 0F 10 74 24 20     movups      xmm6,xmmword ptr [rsp+20h]
  000000000000014C: 48 8D 1D 00 00 00  lea         rbx,[??_7exception@std@@6B@]
                    00
  0000000000000153: 48 89 5D B0        mov         qword ptr [rbp-50h],rbx
  0000000000000157: 33 C0              xor         eax,eax
  0000000000000159: 48 89 45 B8        mov         qword ptr [rbp-48h],rax
  000000000000015D: 48 89 45 C0        mov         qword ptr [rbp-40h],rax
  0000000000000161: 48 8D 05 00 00 00  lea         rax,[??_C@_00CNPNBAHC@?$AA@]
                    00
  0000000000000168: 48 89 45 D8        mov         qword ptr [rbp-28h],rax
  000000000000016C: C6 45 E0 01        mov         byte ptr [rbp-20h],1
  0000000000000170: 48 8D 55 B8        lea         rdx,[rbp-48h]
  0000000000000174: 48 8D 4D D8        lea         rcx,[rbp-28h]
  0000000000000178: E8 00 00 00 00     call        __std_exception_copy
  000000000000017D: 48 8D 3D 00 00 00  lea         rdi,[??_7future_error@std@@6B@]
                    00
  0000000000000184: 48 89 7D B0        mov         qword ptr [rbp-50h],rdi
  0000000000000188: 0F 11 75 C8        movups      xmmword ptr [rbp-38h],xmm6
  000000000000018C: 0F B6 4C 24 30     movzx       ecx,byte ptr [rsp+30h]
  0000000000000191: 83 E9 01           sub         ecx,1
  0000000000000194: 74 14              je          00000000000001AA
  0000000000000196: 83 E9 01           sub         ecx,1
  0000000000000199: 74 0F              je          00000000000001AA
  000000000000019B: 83 F9 01           cmp         ecx,1
  000000000000019E: 75 0F              jne         00000000000001AF
  00000000000001A0: 48 8D 4C 24 20     lea         rcx,[rsp+20h]
  00000000000001A5: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  00000000000001AA: C6 44 24 30 00     mov         byte ptr [rsp+30h],0
  00000000000001AF: 48 89 5D F8        mov         qword ptr [rbp-8],rbx
  00000000000001B3: 33 C0              xor         eax,eax
  00000000000001B5: 48 89 45 00        mov         qword ptr [rbp],rax
  00000000000001B9: 48 89 45 08        mov         qword ptr [rbp+8],rax
  00000000000001BD: 48 8D 55 00        lea         rdx,[rbp]
  00000000000001C1: 48 8D 4D B8        lea         rcx,[rbp-48h]
  00000000000001C5: E8 00 00 00 00     call        __std_exception_copy
  00000000000001CA: 48 89 7D F8        mov         qword ptr [rbp-8],rdi
  00000000000001CE: 0F 10 45 C8        movups      xmm0,xmmword ptr [rbp-38h]
  00000000000001D2: 0F 11 45 10        movups      xmmword ptr [rbp+10h],xmm0
  00000000000001D6: 48 8D 15 00 00 00  lea         rdx,[_TI3?AVfuture_error@std@@]
                    00
  00000000000001DD: 48 8D 4D F8        lea         rcx,[rbp-8]
  00000000000001E1: E8 00 00 00 00     call        _CxxThrowException
  00000000000001E6: 90                 nop
  00000000000001E7: 0F 10 44 24 20     movups      xmm0,xmmword ptr [rsp+20h]
  00000000000001EC: 0F 29 45 60        movaps      xmmword ptr [rbp+60h],xmm0
  00000000000001F0: 48 8D 55 60        lea         rdx,[rbp+60h]
  00000000000001F4: 48 8D 4D 70        lea         rcx,[rbp+70h]
  00000000000001F8: E8 00 00 00 00     call        replaced
  0000000000000000: 48 8B C4           mov         rax,rsp
  0000000000000003: 55                 push        rbp
  0000000000000004: 48 8D 68 A1        lea         rbp,[rax-5Fh]
  0000000000000008: 48 81 EC B0 00 00  sub         rsp,0B0h
                    00
  000000000000000F: 48 C7 45 C7 FE FF  mov         qword ptr [rbp-39h],0FFFFFFFFFFFFFFFEh
                    FF FF
  0000000000000017: 48 89 58 10        mov         qword ptr [rax+10h],rbx
  000000000000001B: 48 89 78 18        mov         qword ptr [rax+18h],rdi
  000000000000001F: 0F 29 70 E8        movaps      xmmword ptr [rax-18h],xmm6
  0000000000000023: 48 8B DA           mov         rbx,rdx
  0000000000000026: 48 8B F9           mov         rdi,rcx
  0000000000000029: 48 C7 45 FF 0F 00  mov         qword ptr [rbp-1],0Fh
                    00 00
  0000000000000031: 48 C7 45 F7 00 00  mov         qword ptr [rbp-9],0
                    00 00
  0000000000000039: C6 45 E7 00        mov         byte ptr [rbp-19h],0
  000000000000003D: 45 33 C0           xor         r8d,r8d
  0000000000000040: 48 8D 15 00 00 00  lea         rdx,[??_C@_00CNPNBAHC@?$AA@]
                    00
  0000000000000047: 48 8D 4D E7        lea         rcx,[rbp-19h]
  000000000000004B: E8 00 00 00 00     call        replaced
  0000000000000000: 48 89 5C 24 08     mov         qword ptr [rsp+8],rbx
  0000000000000005: 48 89 74 24 10     mov         qword ptr [rsp+10h],rsi
  000000000000000A: 57                 push        rdi
  000000000000000B: 48 83 EC 20        sub         rsp,20h
  000000000000000F: 49 8B F8           mov         rdi,r8
  0000000000000012: 48 8B F2           mov         rsi,rdx
  0000000000000015: 48 8B D9           mov         rbx,rcx
  0000000000000018: 48 85 D2           test        rdx,rdx
  000000000000001B: 74 5A              je          0000000000000077
  000000000000001D: 48 8B 51 18        mov         rdx,qword ptr [rcx+18h]
  0000000000000021: 48 83 FA 10        cmp         rdx,10h
  0000000000000025: 72 05              jb          000000000000002C
  0000000000000027: 48 8B 01           mov         rax,qword ptr [rcx]
  000000000000002A: EB 03              jmp         000000000000002F
  000000000000002C: 48 8B C1           mov         rax,rcx
  000000000000002F: 48 3B F0           cmp         rsi,rax
  0000000000000032: 72 43              jb          0000000000000077
  0000000000000034: 48 83 FA 10        cmp         rdx,10h
  0000000000000038: 72 03              jb          000000000000003D
  000000000000003A: 48 8B 09           mov         rcx,qword ptr [rcx]
  000000000000003D: 48 03 4B 10        add         rcx,qword ptr [rbx+10h]
  0000000000000041: 48 3B CE           cmp         rcx,rsi
  0000000000000044: 76 31              jbe         0000000000000077
  0000000000000046: 48 83 FA 10        cmp         rdx,10h
  000000000000004A: 72 05              jb          0000000000000051
  000000000000004C: 48 8B 03           mov         rax,qword ptr [rbx]
  000000000000004F: EB 03              jmp         0000000000000054
  0000000000000051: 48 8B C3           mov         rax,rbx
  0000000000000054: 48 2B F0           sub         rsi,rax
  0000000000000057: 4D 8B C8           mov         r9,r8
  000000000000005A: 4C 8B C6           mov         r8,rsi
  000000000000005D: 48 8B D3           mov         rdx,rbx
  0000000000000060: 48 8B CB           mov         rcx,rbx
  0000000000000063: 48 8B 5C 24 30     mov         rbx,qword ptr [rsp+30h]
  0000000000000068: 48 8B 74 24 38     mov         rsi,qword ptr [rsp+38h]
  000000000000006D: 48 83 C4 20        add         rsp,20h
  0000000000000071: 5F                 pop         rdi
  0000000000000072: E9 00 00 00 00     jmp         replaced
  0000000000000000: 48 89 5C 24 08     mov         qword ptr [rsp+8],rbx
  0000000000000005: 48 89 6C 24 10     mov         qword ptr [rsp+10h],rbp
  000000000000000A: 48 89 74 24 18     mov         qword ptr [rsp+18h],rsi
  000000000000000F: 57                 push        rdi
  0000000000000010: 48 83 EC 20        sub         rsp,20h
  0000000000000014: 48 8B 7A 10        mov         rdi,qword ptr [rdx+10h]
  0000000000000018: 49 8B E8           mov         rbp,r8
  000000000000001B: 48 8B F2           mov         rsi,rdx
  000000000000001E: 48 8B D9           mov         rbx,rcx
  0000000000000021: 49 3B F8           cmp         rdi,r8
  0000000000000024: 0F 82 D8 00 00 00  jb          0000000000000102
  000000000000002A: 49 2B F8           sub         rdi,r8
  000000000000002D: 4C 3B CF           cmp         r9,rdi
  0000000000000030: 49 0F 42 F9        cmovb       rdi,r9
  0000000000000034: 48 3B CA           cmp         rcx,rdx
  0000000000000037: 75 2F              jne         0000000000000068
  0000000000000039: 4A 8D 04 07        lea         rax,[rdi+r8]
  000000000000003D: 48 39 41 10        cmp         qword ptr [rcx+10h],rax
  0000000000000041: 0F 82 C8 00 00 00  jb          000000000000010F
  0000000000000047: 48 89 41 10        mov         qword ptr [rcx+10h],rax
  000000000000004B: 48 83 79 18 10     cmp         qword ptr [rcx+18h],10h
  0000000000000050: 72 03              jb          0000000000000055
  0000000000000052: 48 8B 09           mov         rcx,qword ptr [rcx]
  0000000000000055: C6 04 01 00        mov         byte ptr [rcx+rax],0
  0000000000000059: 33 D2              xor         edx,edx
  000000000000005B: 48 8B CB           mov         rcx,rbx
  000000000000005E: E8 00 00 00 00     call        replaced
  0000000000000000: 48 89 5C 24 08     mov         qword ptr [rsp+8],rbx
  0000000000000005: 57                 push        rdi
  0000000000000006: 48 83 EC 20        sub         rsp,20h
  000000000000000A: 48 8B 79 10        mov         rdi,qword ptr [rcx+10h]
  000000000000000E: 48 8B D9           mov         rbx,rcx
  0000000000000011: 48 3B FA           cmp         rdi,rdx
  0000000000000014: 0F 82 A4 00 00 00  jb          00000000000000BE
  000000000000001A: 48 8B C7           mov         rax,rdi
  000000000000001D: 48 2B C2           sub         rax,rdx
  0000000000000020: 49 3B C0           cmp         rax,r8
  0000000000000023: 77 35              ja          000000000000005A
  0000000000000025: 48 89 51 10        mov         qword ptr [rcx+10h],rdx
  0000000000000029: 48 83 79 18 10     cmp         qword ptr [rcx+18h],10h
  000000000000002E: 72 15              jb          0000000000000045
  0000000000000030: 48 8B 01           mov         rax,qword ptr [rcx]
  0000000000000033: C6 04 10 00        mov         byte ptr [rax+rdx],0
  0000000000000037: 48 8B C1           mov         rax,rcx
  000000000000003A: 48 8B 5C 24 30     mov         rbx,qword ptr [rsp+30h]
  000000000000003F: 48 83 C4 20        add         rsp,20h
  0000000000000043: 5F                 pop         rdi
  0000000000000044: C3                 ret
  0000000000000045: 48 8B C1           mov         rax,rcx
  0000000000000048: C6 04 11 00        mov         byte ptr [rcx+rdx],0
  000000000000004C: 48 8B C3           mov         rax,rbx
  000000000000004F: 48 8B 5C 24 30     mov         rbx,qword ptr [rsp+30h]
  0000000000000054: 48 83 C4 20        add         rsp,20h
  0000000000000058: 5F                 pop         rdi
  0000000000000059: C3                 ret
  000000000000005A: 4D 85 C0           test        r8,r8
  000000000000005D: 74 51              je          00000000000000B0
  000000000000005F: 48 83 79 18 10     cmp         qword ptr [rcx+18h],10h
  0000000000000064: 72 05              jb          000000000000006B
  0000000000000066: 48 8B 01           mov         rax,qword ptr [rcx]
  0000000000000069: EB 03              jmp         000000000000006E
  000000000000006B: 48 8B C1           mov         rax,rcx
  000000000000006E: 49 2B F8           sub         rdi,r8
  0000000000000071: 48 8D 0C 10        lea         rcx,[rax+rdx]
  0000000000000075: 48 8B C7           mov         rax,rdi
  0000000000000078: 48 2B C2           sub         rax,rdx
  000000000000007B: 74 0C              je          0000000000000089
  000000000000007D: 4A 8D 14 01        lea         rdx,[rcx+r8]
  0000000000000081: 4C 8B C0           mov         r8,rax
  0000000000000084: E8 00 00 00 00     call        memmove
  0000000000000089: 48 89 7B 10        mov         qword ptr [rbx+10h],rdi
  000000000000008D: 48 83 7B 18 10     cmp         qword ptr [rbx+18h],10h
  0000000000000092: 72 15              jb          00000000000000A9
  0000000000000094: 48 8B 03           mov         rax,qword ptr [rbx]
  0000000000000097: C6 04 38 00        mov         byte ptr [rax+rdi],0
  000000000000009B: 48 8B C3           mov         rax,rbx
  000000000000009E: 48 8B 5C 24 30     mov         rbx,qword ptr [rsp+30h]
  00000000000000A3: 48 83 C4 20        add         rsp,20h
  00000000000000A7: 5F                 pop         rdi
  00000000000000A8: C3                 ret
  00000000000000A9: 48 8B C3           mov         rax,rbx
  00000000000000AC: C6 04 3B 00        mov         byte ptr [rbx+rdi],0
  00000000000000B0: 48 8B C3           mov         rax,rbx
  00000000000000B3: 48 8B 5C 24 30     mov         rbx,qword ptr [rsp+30h]
  00000000000000B8: 48 83 C4 20        add         rsp,20h
  00000000000000BC: 5F                 pop         rdi
  00000000000000BD: C3                 ret
  00000000000000BE: 48 8D 0D 00 00 00  lea         rcx,[??_C@_0BI@CFPLBAOH@invalid?5string?5position?$AA@]
                    00
  00000000000000C5: E8 00 00 00 00     call        ?_Xout_of_range@std@@YAXPEBD@Z
  00000000000000CA: CC                 int         3

  0000000000000063: E9 82 00 00 00     jmp         00000000000000EA
  0000000000000068: 48 83 FF FE        cmp         rdi,0FFFFFFFFFFFFFFFEh
  000000000000006C: 0F 87 AA 00 00 00  ja          000000000000011C
  0000000000000072: 48 39 79 18        cmp         qword ptr [rcx+18h],rdi
  0000000000000076: 73 27              jae         000000000000009F
  0000000000000078: 4C 8B 41 10        mov         r8,qword ptr [rcx+10h]
  000000000000007C: 48 8B D7           mov         rdx,rdi
  000000000000007F: E8 00 00 00 00     call        replaced
  0000000000000000: 4C 89 44 24 18     mov         qword ptr [rsp+18h],r8
  0000000000000005: 48 89 54 24 10     mov         qword ptr [rsp+10h],rdx
  000000000000000A: 48 89 4C 24 08     mov         qword ptr [rsp+8],rcx
  000000000000000F: 53                 push        rbx
  0000000000000010: 56                 push        rsi
  0000000000000011: 57                 push        rdi
  0000000000000012: 41 56              push        r14
  0000000000000014: 48 83 EC 38        sub         rsp,38h
  0000000000000018: 48 C7 44 24 20 FE  mov         qword ptr [rsp+20h],0FFFFFFFFFFFFFFFEh
                    FF FF FF
  0000000000000021: 49 8B F0           mov         rsi,r8
  0000000000000024: 48 8B D9           mov         rbx,rcx
  0000000000000027: 48 8B FA           mov         rdi,rdx
  000000000000002A: 48 83 CF 0F        or          rdi,0Fh
  000000000000002E: 48 83 FF FE        cmp         rdi,0FFFFFFFFFFFFFFFEh
  0000000000000032: 76 05              jbe         0000000000000039
  0000000000000034: 48 8B FA           mov         rdi,rdx
  0000000000000037: EB 35              jmp         000000000000006E
  0000000000000039: 4C 8B 41 18        mov         r8,qword ptr [rcx+18h]
  000000000000003D: 49 8B C8           mov         rcx,r8
  0000000000000040: 48 D1 E9           shr         rcx,1
  0000000000000043: 48 B8 AB AA AA AA  mov         rax,0AAAAAAAAAAAAAAABh
                    AA AA AA AA
  000000000000004D: 48 F7 E7           mul         rax,rdi
  0000000000000050: 48 D1 EA           shr         rdx,1
  0000000000000053: 48 3B CA           cmp         rcx,rdx
  0000000000000056: 76 16              jbe         000000000000006E
  0000000000000058: 48 C7 C7 FE FF FF  mov         rdi,0FFFFFFFFFFFFFFFEh
                    FF
  000000000000005F: 48 8B C7           mov         rax,rdi
  0000000000000062: 48 2B C1           sub         rax,rcx
  0000000000000065: 4C 3B C0           cmp         r8,rax
  0000000000000068: 77 04              ja          000000000000006E
  000000000000006A: 4A 8D 3C 01        lea         rdi,[rcx+r8]
  000000000000006E: 48 8D 57 01        lea         rdx,[rdi+1]
  0000000000000072: 48 8B CB           mov         rcx,rbx
  0000000000000075: E8 00 00 00 00     call        replaced
  0000000000000000: 48 83 EC 28        sub         rsp,28h
  0000000000000004: 48 85 D2           test        rdx,rdx
  0000000000000007: 75 07              jne         0000000000000010
  0000000000000009: 33 C0              xor         eax,eax
  000000000000000B: 48 83 C4 28        add         rsp,28h
  000000000000000F: C3                 ret
  0000000000000010: 48 83 FA FF        cmp         rdx,0FFFFFFFFFFFFFFFFh
  0000000000000014: 77 3F              ja          0000000000000055
  0000000000000016: 48 81 FA 00 10 00  cmp         rdx,1000h
                    00
  000000000000001D: 72 27              jb          0000000000000046
  000000000000001F: 48 8D 4A 27        lea         rcx,[rdx+27h]
  0000000000000023: 48 3B CA           cmp         rcx,rdx
  0000000000000026: 76 33              jbe         000000000000005B
  0000000000000028: E8 00 00 00 00     call        ??2@YAPEAX_K@Z
  000000000000002D: 48 8B C8           mov         rcx,rax
  0000000000000030: 48 85 C0           test        rax,rax
  0000000000000033: 74 2C              je          0000000000000061
  0000000000000035: 48 83 C0 27        add         rax,27h
  0000000000000039: 48 83 E0 E0        and         rax,0FFFFFFFFFFFFFFE0h
  000000000000003D: 48 89 48 F8        mov         qword ptr [rax-8],rcx
  0000000000000041: 48 83 C4 28        add         rsp,28h
  0000000000000045: C3                 ret
  0000000000000046: 48 8B CA           mov         rcx,rdx
  0000000000000049: E8 00 00 00 00     call        ??2@YAPEAX_K@Z
  000000000000004E: 48 85 C0           test        rax,rax
  0000000000000051: 75 B8              jne         000000000000000B
  0000000000000053: EB 12              jmp         0000000000000067
  0000000000000055: E8 00 00 00 00     call        ?_Xbad_alloc@std@@YAXXZ
  000000000000005A: CC                 int         3
  000000000000005B: E8 00 00 00 00     call        ?_Xbad_alloc@std@@YAXXZ
  0000000000000060: CC                 int         3
  0000000000000061: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000066: CC                 int         3
  0000000000000067: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  000000000000006C: CC                 int         3

  000000000000007A: 4C 8B F0           mov         r14,rax
  000000000000007D: EB 14              jmp         0000000000000093
$LN19:
  000000000000007F: 48 8B 5C 24 60     mov         rbx,qword ptr [rsp+60h]
  0000000000000084: 48 8B 74 24 70     mov         rsi,qword ptr [rsp+70h]
  0000000000000089: 48 8B 7C 24 68     mov         rdi,qword ptr [rsp+68h]
  000000000000008E: 4C 8B 74 24 78     mov         r14,qword ptr [rsp+78h]
  0000000000000093: 48 85 F6           test        rsi,rsi
  0000000000000096: 74 1F              je          00000000000000B7
  0000000000000098: 48 83 7B 18 10     cmp         qword ptr [rbx+18h],10h
  000000000000009D: 72 05              jb          00000000000000A4
  000000000000009F: 48 8B 13           mov         rdx,qword ptr [rbx]
  00000000000000A2: EB 03              jmp         00000000000000A7
  00000000000000A4: 48 8B D3           mov         rdx,rbx
  00000000000000A7: 48 85 F6           test        rsi,rsi
  00000000000000AA: 74 0B              je          00000000000000B7
  00000000000000AC: 4C 8B C6           mov         r8,rsi
  00000000000000AF: 49 8B CE           mov         rcx,r14
  00000000000000B2: E8 00 00 00 00     call        memcpy
  00000000000000B7: 4C 8B 43 18        mov         r8,qword ptr [rbx+18h]
  00000000000000BB: 49 83 F8 10        cmp         r8,10h
  00000000000000BF: 72 0E              jb          00000000000000CF
  00000000000000C1: 49 FF C0           inc         r8
  00000000000000C4: 48 8B 13           mov         rdx,qword ptr [rbx]
  00000000000000C7: 48 8B CB           mov         rcx,rbx
  00000000000000CA: E8 00 00 00 00     call        replaced
  0000000000000000: 48 83 EC 28        sub         rsp,28h
  0000000000000004: 49 83 F8 FF        cmp         r8,0FFFFFFFFFFFFFFFFh
  0000000000000008: 77 35              ja          000000000000003F
  000000000000000A: 49 81 F8 00 10 00  cmp         r8,1000h
                    00
  0000000000000011: 72 20              jb          0000000000000033
  0000000000000013: F6 C2 1F           test        dl,1Fh
  0000000000000016: 75 2D              jne         0000000000000045
  0000000000000018: 48 8B 42 F8        mov         rax,qword ptr [rdx-8]
  000000000000001C: 48 3B C2           cmp         rax,rdx
  000000000000001F: 73 2A              jae         000000000000004B
  0000000000000021: 48 2B D0           sub         rdx,rax
  0000000000000024: 48 83 FA 08        cmp         rdx,8
  0000000000000028: 72 27              jb          0000000000000051
  000000000000002A: 48 83 FA 27        cmp         rdx,27h
  000000000000002E: 77 27              ja          0000000000000057
  0000000000000030: 48 8B D0           mov         rdx,rax
  0000000000000033: 48 8B CA           mov         rcx,rdx
  0000000000000036: 48 83 C4 28        add         rsp,28h
  000000000000003A: E9 00 00 00 00     jmp         ??3@YAXPEAX@Z
  000000000000003F: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000044: CC                 int         3
  0000000000000045: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  000000000000004A: CC                 int         3
  000000000000004B: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000050: CC                 int         3
  0000000000000051: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000056: CC                 int         3
  0000000000000057: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  000000000000005C: CC                 int         3

  00000000000000CF: 48 C7 43 18 0F 00  mov         qword ptr [rbx+18h],0Fh
                    00 00
  00000000000000D7: 48 C7 43 10 00 00  mov         qword ptr [rbx+10h],0
                    00 00
  00000000000000DF: 48 83 7B 18 10     cmp         qword ptr [rbx+18h],10h
  00000000000000E4: 72 05              jb          00000000000000EB
  00000000000000E6: 48 8B 03           mov         rax,qword ptr [rbx]
  00000000000000E9: EB 03              jmp         00000000000000EE
  00000000000000EB: 48 8B C3           mov         rax,rbx
  00000000000000EE: C6 00 00           mov         byte ptr [rax],0
  00000000000000F1: 4C 89 33           mov         qword ptr [rbx],r14
  00000000000000F4: 48 89 7B 18        mov         qword ptr [rbx+18h],rdi
  00000000000000F8: 48 89 73 10        mov         qword ptr [rbx+10h],rsi
  00000000000000FC: 48 83 7B 18 10     cmp         qword ptr [rbx+18h],10h
  0000000000000101: 72 03              jb          0000000000000106
  0000000000000103: 49 8B DE           mov         rbx,r14
  0000000000000106: C6 04 33 00        mov         byte ptr [rbx+rsi],0
  000000000000010A: 48 83 C4 38        add         rsp,38h
  000000000000010E: 41 5E              pop         r14
  0000000000000110: 5F                 pop         rdi
  0000000000000111: 5E                 pop         rsi
  0000000000000112: 5B                 pop         rbx
  0000000000000113: C3                 ret

  0000000000000084: 48 85 FF           test        rdi,rdi
  0000000000000087: 74 61              je          00000000000000EA
  0000000000000089: 48 83 7E 18 10     cmp         qword ptr [rsi+18h],10h
  000000000000008E: 72 03              jb          0000000000000093
  0000000000000090: 48 8B 36           mov         rsi,qword ptr [rsi]
  0000000000000093: 48 83 7B 18 10     cmp         qword ptr [rbx+18h],10h
  0000000000000098: 72 25              jb          00000000000000BF
  000000000000009A: 48 8B 0B           mov         rcx,qword ptr [rbx]
  000000000000009D: EB 23              jmp         00000000000000C2
  000000000000009F: 48 85 FF           test        rdi,rdi
  00000000000000A2: 75 E5              jne         0000000000000089
  00000000000000A4: 48 89 79 10        mov         qword ptr [rcx+10h],rdi
  00000000000000A8: 48 83 79 18 10     cmp         qword ptr [rcx+18h],10h
  00000000000000AD: 72 08              jb          00000000000000B7
  00000000000000AF: 48 8B 01           mov         rax,qword ptr [rcx]
  00000000000000B2: 40 88 38           mov         byte ptr [rax],dil
  00000000000000B5: EB 33              jmp         00000000000000EA
  00000000000000B7: 48 8B C1           mov         rax,rcx
  00000000000000BA: C6 01 00           mov         byte ptr [rcx],0
  00000000000000BD: EB 2B              jmp         00000000000000EA
  00000000000000BF: 48 8B CB           mov         rcx,rbx
  00000000000000C2: 48 85 FF           test        rdi,rdi
  00000000000000C5: 74 0C              je          00000000000000D3
  00000000000000C7: 48 8D 14 2E        lea         rdx,[rsi+rbp]
  00000000000000CB: 4C 8B C7           mov         r8,rdi
  00000000000000CE: E8 00 00 00 00     call        memcpy
  00000000000000D3: 48 89 7B 10        mov         qword ptr [rbx+10h],rdi
  00000000000000D7: 48 83 7B 18 10     cmp         qword ptr [rbx+18h],10h
  00000000000000DC: 72 05              jb          00000000000000E3
  00000000000000DE: 48 8B 03           mov         rax,qword ptr [rbx]
  00000000000000E1: EB 03              jmp         00000000000000E6
  00000000000000E3: 48 8B C3           mov         rax,rbx
  00000000000000E6: C6 04 38 00        mov         byte ptr [rax+rdi],0
  00000000000000EA: 48 8B 6C 24 38     mov         rbp,qword ptr [rsp+38h]
  00000000000000EF: 48 8B C3           mov         rax,rbx
  00000000000000F2: 48 8B 5C 24 30     mov         rbx,qword ptr [rsp+30h]
  00000000000000F7: 48 8B 74 24 40     mov         rsi,qword ptr [rsp+40h]
  00000000000000FC: 48 83 C4 20        add         rsp,20h
  0000000000000100: 5F                 pop         rdi
  0000000000000101: C3                 ret
  0000000000000102: 48 8D 0D 00 00 00  lea         rcx,[??_C@_0BI@CFPLBAOH@invalid?5string?5position?$AA@]
                    00
  0000000000000109: E8 00 00 00 00     call        ?_Xout_of_range@std@@YAXPEBD@Z
  000000000000010E: CC                 int         3
  000000000000010F: 48 8D 0D 00 00 00  lea         rcx,[??_C@_0BI@CFPLBAOH@invalid?5string?5position?$AA@]
                    00
  0000000000000116: E8 00 00 00 00     call        ?_Xout_of_range@std@@YAXPEBD@Z
  000000000000011B: CC                 int         3
  000000000000011C: 48 8D 0D 00 00 00  lea         rcx,[??_C@_0BA@JFNIOLAK@string?5too?5long?$AA@]
                    00
  0000000000000123: E8 00 00 00 00     call        ?_Xlength_error@std@@YAXPEBD@Z
  0000000000000128: CC                 int         3

  0000000000000077: 49 83 F8 FE        cmp         r8,0FFFFFFFFFFFFFFFEh
  000000000000007B: 0F 87 A2 00 00 00  ja          0000000000000123
  0000000000000081: 4C 39 43 18        cmp         qword ptr [rbx+18h],r8
  0000000000000085: 73 20              jae         00000000000000A7
  0000000000000087: 4C 8B 43 10        mov         r8,qword ptr [rbx+10h]
  000000000000008B: 48 8B D7           mov         rdx,rdi
  000000000000008E: 48 8B CB           mov         rcx,rbx
  0000000000000091: E8 00 00 00 00     call        replaced
  0000000000000000: 4C 89 44 24 18     mov         qword ptr [rsp+18h],r8
  0000000000000005: 48 89 54 24 10     mov         qword ptr [rsp+10h],rdx
  000000000000000A: 48 89 4C 24 08     mov         qword ptr [rsp+8],rcx
  000000000000000F: 53                 push        rbx
  0000000000000010: 56                 push        rsi
  0000000000000011: 57                 push        rdi
  0000000000000012: 41 56              push        r14
  0000000000000014: 48 83 EC 38        sub         rsp,38h
  0000000000000018: 48 C7 44 24 20 FE  mov         qword ptr [rsp+20h],0FFFFFFFFFFFFFFFEh
                    FF FF FF
  0000000000000021: 49 8B F0           mov         rsi,r8
  0000000000000024: 48 8B D9           mov         rbx,rcx
  0000000000000027: 48 8B FA           mov         rdi,rdx
  000000000000002A: 48 83 CF 0F        or          rdi,0Fh
  000000000000002E: 48 83 FF FE        cmp         rdi,0FFFFFFFFFFFFFFFEh
  0000000000000032: 76 05              jbe         0000000000000039
  0000000000000034: 48 8B FA           mov         rdi,rdx
  0000000000000037: EB 35              jmp         000000000000006E
  0000000000000039: 4C 8B 41 18        mov         r8,qword ptr [rcx+18h]
  000000000000003D: 49 8B C8           mov         rcx,r8
  0000000000000040: 48 D1 E9           shr         rcx,1
  0000000000000043: 48 B8 AB AA AA AA  mov         rax,0AAAAAAAAAAAAAAABh
                    AA AA AA AA
  000000000000004D: 48 F7 E7           mul         rax,rdi
  0000000000000050: 48 D1 EA           shr         rdx,1
  0000000000000053: 48 3B CA           cmp         rcx,rdx
  0000000000000056: 76 16              jbe         000000000000006E
  0000000000000058: 48 C7 C7 FE FF FF  mov         rdi,0FFFFFFFFFFFFFFFEh
                    FF
  000000000000005F: 48 8B C7           mov         rax,rdi
  0000000000000062: 48 2B C1           sub         rax,rcx
  0000000000000065: 4C 3B C0           cmp         r8,rax
  0000000000000068: 77 04              ja          000000000000006E
  000000000000006A: 4A 8D 3C 01        lea         rdi,[rcx+r8]
  000000000000006E: 48 8D 57 01        lea         rdx,[rdi+1]
  0000000000000072: 48 8B CB           mov         rcx,rbx
  0000000000000075: E8 00 00 00 00     call        replaced
  0000000000000000: 48 83 EC 28        sub         rsp,28h
  0000000000000004: 48 85 D2           test        rdx,rdx
  0000000000000007: 75 07              jne         0000000000000010
  0000000000000009: 33 C0              xor         eax,eax
  000000000000000B: 48 83 C4 28        add         rsp,28h
  000000000000000F: C3                 ret
  0000000000000010: 48 83 FA FF        cmp         rdx,0FFFFFFFFFFFFFFFFh
  0000000000000014: 77 3F              ja          0000000000000055
  0000000000000016: 48 81 FA 00 10 00  cmp         rdx,1000h
                    00
  000000000000001D: 72 27              jb          0000000000000046
  000000000000001F: 48 8D 4A 27        lea         rcx,[rdx+27h]
  0000000000000023: 48 3B CA           cmp         rcx,rdx
  0000000000000026: 76 33              jbe         000000000000005B
  0000000000000028: E8 00 00 00 00     call        ??2@YAPEAX_K@Z
  000000000000002D: 48 8B C8           mov         rcx,rax
  0000000000000030: 48 85 C0           test        rax,rax
  0000000000000033: 74 2C              je          0000000000000061
  0000000000000035: 48 83 C0 27        add         rax,27h
  0000000000000039: 48 83 E0 E0        and         rax,0FFFFFFFFFFFFFFE0h
  000000000000003D: 48 89 48 F8        mov         qword ptr [rax-8],rcx
  0000000000000041: 48 83 C4 28        add         rsp,28h
  0000000000000045: C3                 ret
  0000000000000046: 48 8B CA           mov         rcx,rdx
  0000000000000049: E8 00 00 00 00     call        ??2@YAPEAX_K@Z
  000000000000004E: 48 85 C0           test        rax,rax
  0000000000000051: 75 B8              jne         000000000000000B
  0000000000000053: EB 12              jmp         0000000000000067
  0000000000000055: E8 00 00 00 00     call        ?_Xbad_alloc@std@@YAXXZ
  000000000000005A: CC                 int         3
  000000000000005B: E8 00 00 00 00     call        ?_Xbad_alloc@std@@YAXXZ
  0000000000000060: CC                 int         3
  0000000000000061: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000066: CC                 int         3
  0000000000000067: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  000000000000006C: CC                 int         3

  000000000000007A: 4C 8B F0           mov         r14,rax
  000000000000007D: EB 14              jmp         0000000000000093
$LN19:
  000000000000007F: 48 8B 5C 24 60     mov         rbx,qword ptr [rsp+60h]
  0000000000000084: 48 8B 74 24 70     mov         rsi,qword ptr [rsp+70h]
  0000000000000089: 48 8B 7C 24 68     mov         rdi,qword ptr [rsp+68h]
  000000000000008E: 4C 8B 74 24 78     mov         r14,qword ptr [rsp+78h]
  0000000000000093: 48 85 F6           test        rsi,rsi
  0000000000000096: 74 1F              je          00000000000000B7
  0000000000000098: 48 83 7B 18 10     cmp         qword ptr [rbx+18h],10h
  000000000000009D: 72 05              jb          00000000000000A4
  000000000000009F: 48 8B 13           mov         rdx,qword ptr [rbx]
  00000000000000A2: EB 03              jmp         00000000000000A7
  00000000000000A4: 48 8B D3           mov         rdx,rbx
  00000000000000A7: 48 85 F6           test        rsi,rsi
  00000000000000AA: 74 0B              je          00000000000000B7
  00000000000000AC: 4C 8B C6           mov         r8,rsi
  00000000000000AF: 49 8B CE           mov         rcx,r14
  00000000000000B2: E8 00 00 00 00     call        memcpy
  00000000000000B7: 4C 8B 43 18        mov         r8,qword ptr [rbx+18h]
  00000000000000BB: 49 83 F8 10        cmp         r8,10h
  00000000000000BF: 72 0E              jb          00000000000000CF
  00000000000000C1: 49 FF C0           inc         r8
  00000000000000C4: 48 8B 13           mov         rdx,qword ptr [rbx]
  00000000000000C7: 48 8B CB           mov         rcx,rbx
  00000000000000CA: E8 00 00 00 00     call        replaced
  0000000000000000: 48 83 EC 28        sub         rsp,28h
  0000000000000004: 49 83 F8 FF        cmp         r8,0FFFFFFFFFFFFFFFFh
  0000000000000008: 77 35              ja          000000000000003F
  000000000000000A: 49 81 F8 00 10 00  cmp         r8,1000h
                    00
  0000000000000011: 72 20              jb          0000000000000033
  0000000000000013: F6 C2 1F           test        dl,1Fh
  0000000000000016: 75 2D              jne         0000000000000045
  0000000000000018: 48 8B 42 F8        mov         rax,qword ptr [rdx-8]
  000000000000001C: 48 3B C2           cmp         rax,rdx
  000000000000001F: 73 2A              jae         000000000000004B
  0000000000000021: 48 2B D0           sub         rdx,rax
  0000000000000024: 48 83 FA 08        cmp         rdx,8
  0000000000000028: 72 27              jb          0000000000000051
  000000000000002A: 48 83 FA 27        cmp         rdx,27h
  000000000000002E: 77 27              ja          0000000000000057
  0000000000000030: 48 8B D0           mov         rdx,rax
  0000000000000033: 48 8B CA           mov         rcx,rdx
  0000000000000036: 48 83 C4 28        add         rsp,28h
  000000000000003A: E9 00 00 00 00     jmp         ??3@YAXPEAX@Z
  000000000000003F: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000044: CC                 int         3
  0000000000000045: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  000000000000004A: CC                 int         3
  000000000000004B: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000050: CC                 int         3
  0000000000000051: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000056: CC                 int         3
  0000000000000057: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  000000000000005C: CC                 int         3

  00000000000000CF: 48 C7 43 18 0F 00  mov         qword ptr [rbx+18h],0Fh
                    00 00
  00000000000000D7: 48 C7 43 10 00 00  mov         qword ptr [rbx+10h],0
                    00 00
  00000000000000DF: 48 83 7B 18 10     cmp         qword ptr [rbx+18h],10h
  00000000000000E4: 72 05              jb          00000000000000EB
  00000000000000E6: 48 8B 03           mov         rax,qword ptr [rbx]
  00000000000000E9: EB 03              jmp         00000000000000EE
  00000000000000EB: 48 8B C3           mov         rax,rbx
  00000000000000EE: C6 00 00           mov         byte ptr [rax],0
  00000000000000F1: 4C 89 33           mov         qword ptr [rbx],r14
  00000000000000F4: 48 89 7B 18        mov         qword ptr [rbx+18h],rdi
  00000000000000F8: 48 89 73 10        mov         qword ptr [rbx+10h],rsi
  00000000000000FC: 48 83 7B 18 10     cmp         qword ptr [rbx+18h],10h
  0000000000000101: 72 03              jb          0000000000000106
  0000000000000103: 49 8B DE           mov         rbx,r14
  0000000000000106: C6 04 33 00        mov         byte ptr [rbx+rsi],0
  000000000000010A: 48 83 C4 38        add         rsp,38h
  000000000000010E: 41 5E              pop         r14
  0000000000000110: 5F                 pop         rdi
  0000000000000111: 5E                 pop         rsi
  0000000000000112: 5B                 pop         rbx
  0000000000000113: C3                 ret

  0000000000000096: 48 85 FF           test        rdi,rdi
  0000000000000099: 74 75              je          0000000000000110
  000000000000009B: 48 83 7B 18 10     cmp         qword ptr [rbx+18h],10h
  00000000000000A0: 72 44              jb          00000000000000E6
  00000000000000A2: 48 8B 0B           mov         rcx,qword ptr [rbx]
  00000000000000A5: EB 42              jmp         00000000000000E9
  00000000000000A7: 4D 85 C0           test        r8,r8
  00000000000000AA: 75 EA              jne         0000000000000096
  00000000000000AC: 4C 89 43 10        mov         qword ptr [rbx+10h],r8
  00000000000000B0: 48 83 7B 18 10     cmp         qword ptr [rbx+18h],10h
  00000000000000B5: 72 19              jb          00000000000000D0
  00000000000000B7: 48 8B 03           mov         rax,qword ptr [rbx]
  00000000000000BA: 44 88 00           mov         byte ptr [rax],r8b
  00000000000000BD: 48 8B C3           mov         rax,rbx
  00000000000000C0: 48 8B 5C 24 30     mov         rbx,qword ptr [rsp+30h]
  00000000000000C5: 48 8B 74 24 38     mov         rsi,qword ptr [rsp+38h]
  00000000000000CA: 48 83 C4 20        add         rsp,20h
  00000000000000CE: 5F                 pop         rdi
  00000000000000CF: C3                 ret
  00000000000000D0: 48 8B C3           mov         rax,rbx
  00000000000000D3: C6 03 00           mov         byte ptr [rbx],0
  00000000000000D6: 48 8B 5C 24 30     mov         rbx,qword ptr [rsp+30h]
  00000000000000DB: 48 8B 74 24 38     mov         rsi,qword ptr [rsp+38h]
  00000000000000E0: 48 83 C4 20        add         rsp,20h
  00000000000000E4: 5F                 pop         rdi
  00000000000000E5: C3                 ret
  00000000000000E6: 48 8B CB           mov         rcx,rbx
  00000000000000E9: 48 85 FF           test        rdi,rdi
  00000000000000EC: 74 0B              je          00000000000000F9
  00000000000000EE: 4C 8B C7           mov         r8,rdi
  00000000000000F1: 48 8B D6           mov         rdx,rsi
  00000000000000F4: E8 00 00 00 00     call        memcpy
  00000000000000F9: 48 89 7B 10        mov         qword ptr [rbx+10h],rdi
  00000000000000FD: 48 83 7B 18 10     cmp         qword ptr [rbx+18h],10h
  0000000000000102: 72 05              jb          0000000000000109
  0000000000000104: 48 8B 03           mov         rax,qword ptr [rbx]
  0000000000000107: EB 03              jmp         000000000000010C
  0000000000000109: 48 8B C3           mov         rax,rbx
  000000000000010C: C6 04 38 00        mov         byte ptr [rax+rdi],0
  0000000000000110: 48 8B 74 24 38     mov         rsi,qword ptr [rsp+38h]
  0000000000000115: 48 8B C3           mov         rax,rbx
  0000000000000118: 48 8B 5C 24 30     mov         rbx,qword ptr [rsp+30h]
  000000000000011D: 48 83 C4 20        add         rsp,20h
  0000000000000121: 5F                 pop         rdi
  0000000000000122: C3                 ret
  0000000000000123: 48 8D 0D 00 00 00  lea         rcx,[??_C@_0BA@JFNIOLAK@string?5too?5long?$AA@]
                    00
  000000000000012A: E8 00 00 00 00     call        ?_Xlength_error@std@@YAXPEBD@Z
  000000000000012F: CC                 int         3

  0000000000000050: 90                 nop
  0000000000000051: 0F 10 33           movups      xmm6,xmmword ptr [rbx]
  0000000000000054: 48 C7 45 1F 0F 00  mov         qword ptr [rbp+1Fh],0Fh
                    00 00
  000000000000005C: 48 C7 45 17 00 00  mov         qword ptr [rbp+17h],0
                    00 00
  0000000000000064: C6 45 07 00        mov         byte ptr [rbp+7],0
  0000000000000068: 49 83 C9 FF        or          r9,0FFFFFFFFFFFFFFFFh
  000000000000006C: 45 33 C0           xor         r8d,r8d
  000000000000006F: 48 8D 55 E7        lea         rdx,[rbp-19h]
  0000000000000073: 48 8D 4D 07        lea         rcx,[rbp+7]
  0000000000000077: E8 00 00 00 00     call        replaced
  0000000000000000: 48 89 5C 24 08     mov         qword ptr [rsp+8],rbx
  0000000000000005: 48 89 6C 24 10     mov         qword ptr [rsp+10h],rbp
  000000000000000A: 48 89 74 24 18     mov         qword ptr [rsp+18h],rsi
  000000000000000F: 57                 push        rdi
  0000000000000010: 48 83 EC 20        sub         rsp,20h
  0000000000000014: 48 8B 7A 10        mov         rdi,qword ptr [rdx+10h]
  0000000000000018: 49 8B E8           mov         rbp,r8
  000000000000001B: 48 8B F2           mov         rsi,rdx
  000000000000001E: 48 8B D9           mov         rbx,rcx
  0000000000000021: 49 3B F8           cmp         rdi,r8
  0000000000000024: 0F 82 D8 00 00 00  jb          0000000000000102
  000000000000002A: 49 2B F8           sub         rdi,r8
  000000000000002D: 4C 3B CF           cmp         r9,rdi
  0000000000000030: 49 0F 42 F9        cmovb       rdi,r9
  0000000000000034: 48 3B CA           cmp         rcx,rdx
  0000000000000037: 75 2F              jne         0000000000000068
  0000000000000039: 4A 8D 04 07        lea         rax,[rdi+r8]
  000000000000003D: 48 39 41 10        cmp         qword ptr [rcx+10h],rax
  0000000000000041: 0F 82 C8 00 00 00  jb          000000000000010F
  0000000000000047: 48 89 41 10        mov         qword ptr [rcx+10h],rax
  000000000000004B: 48 83 79 18 10     cmp         qword ptr [rcx+18h],10h
  0000000000000050: 72 03              jb          0000000000000055
  0000000000000052: 48 8B 09           mov         rcx,qword ptr [rcx]
  0000000000000055: C6 04 01 00        mov         byte ptr [rcx+rax],0
  0000000000000059: 33 D2              xor         edx,edx
  000000000000005B: 48 8B CB           mov         rcx,rbx
  000000000000005E: E8 00 00 00 00     call        replaced
  0000000000000000: 48 89 5C 24 08     mov         qword ptr [rsp+8],rbx
  0000000000000005: 57                 push        rdi
  0000000000000006: 48 83 EC 20        sub         rsp,20h
  000000000000000A: 48 8B 79 10        mov         rdi,qword ptr [rcx+10h]
  000000000000000E: 48 8B D9           mov         rbx,rcx
  0000000000000011: 48 3B FA           cmp         rdi,rdx
  0000000000000014: 0F 82 A4 00 00 00  jb          00000000000000BE
  000000000000001A: 48 8B C7           mov         rax,rdi
  000000000000001D: 48 2B C2           sub         rax,rdx
  0000000000000020: 49 3B C0           cmp         rax,r8
  0000000000000023: 77 35              ja          000000000000005A
  0000000000000025: 48 89 51 10        mov         qword ptr [rcx+10h],rdx
  0000000000000029: 48 83 79 18 10     cmp         qword ptr [rcx+18h],10h
  000000000000002E: 72 15              jb          0000000000000045
  0000000000000030: 48 8B 01           mov         rax,qword ptr [rcx]
  0000000000000033: C6 04 10 00        mov         byte ptr [rax+rdx],0
  0000000000000037: 48 8B C1           mov         rax,rcx
  000000000000003A: 48 8B 5C 24 30     mov         rbx,qword ptr [rsp+30h]
  000000000000003F: 48 83 C4 20        add         rsp,20h
  0000000000000043: 5F                 pop         rdi
  0000000000000044: C3                 ret
  0000000000000045: 48 8B C1           mov         rax,rcx
  0000000000000048: C6 04 11 00        mov         byte ptr [rcx+rdx],0
  000000000000004C: 48 8B C3           mov         rax,rbx
  000000000000004F: 48 8B 5C 24 30     mov         rbx,qword ptr [rsp+30h]
  0000000000000054: 48 83 C4 20        add         rsp,20h
  0000000000000058: 5F                 pop         rdi
  0000000000000059: C3                 ret
  000000000000005A: 4D 85 C0           test        r8,r8
  000000000000005D: 74 51              je          00000000000000B0
  000000000000005F: 48 83 79 18 10     cmp         qword ptr [rcx+18h],10h
  0000000000000064: 72 05              jb          000000000000006B
  0000000000000066: 48 8B 01           mov         rax,qword ptr [rcx]
  0000000000000069: EB 03              jmp         000000000000006E
  000000000000006B: 48 8B C1           mov         rax,rcx
  000000000000006E: 49 2B F8           sub         rdi,r8
  0000000000000071: 48 8D 0C 10        lea         rcx,[rax+rdx]
  0000000000000075: 48 8B C7           mov         rax,rdi
  0000000000000078: 48 2B C2           sub         rax,rdx
  000000000000007B: 74 0C              je          0000000000000089
  000000000000007D: 4A 8D 14 01        lea         rdx,[rcx+r8]
  0000000000000081: 4C 8B C0           mov         r8,rax
  0000000000000084: E8 00 00 00 00     call        memmove
  0000000000000089: 48 89 7B 10        mov         qword ptr [rbx+10h],rdi
  000000000000008D: 48 83 7B 18 10     cmp         qword ptr [rbx+18h],10h
  0000000000000092: 72 15              jb          00000000000000A9
  0000000000000094: 48 8B 03           mov         rax,qword ptr [rbx]
  0000000000000097: C6 04 38 00        mov         byte ptr [rax+rdi],0
  000000000000009B: 48 8B C3           mov         rax,rbx
  000000000000009E: 48 8B 5C 24 30     mov         rbx,qword ptr [rsp+30h]
  00000000000000A3: 48 83 C4 20        add         rsp,20h
  00000000000000A7: 5F                 pop         rdi
  00000000000000A8: C3                 ret
  00000000000000A9: 48 8B C3           mov         rax,rbx
  00000000000000AC: C6 04 3B 00        mov         byte ptr [rbx+rdi],0
  00000000000000B0: 48 8B C3           mov         rax,rbx
  00000000000000B3: 48 8B 5C 24 30     mov         rbx,qword ptr [rsp+30h]
  00000000000000B8: 48 83 C4 20        add         rsp,20h
  00000000000000BC: 5F                 pop         rdi
  00000000000000BD: C3                 ret
  00000000000000BE: 48 8D 0D 00 00 00  lea         rcx,[??_C@_0BI@CFPLBAOH@invalid?5string?5position?$AA@]
                    00
  00000000000000C5: E8 00 00 00 00     call        ?_Xout_of_range@std@@YAXPEBD@Z
  00000000000000CA: CC                 int         3

  0000000000000063: E9 82 00 00 00     jmp         00000000000000EA
  0000000000000068: 48 83 FF FE        cmp         rdi,0FFFFFFFFFFFFFFFEh
  000000000000006C: 0F 87 AA 00 00 00  ja          000000000000011C
  0000000000000072: 48 39 79 18        cmp         qword ptr [rcx+18h],rdi
  0000000000000076: 73 27              jae         000000000000009F
  0000000000000078: 4C 8B 41 10        mov         r8,qword ptr [rcx+10h]
  000000000000007C: 48 8B D7           mov         rdx,rdi
  000000000000007F: E8 00 00 00 00     call        replaced
  0000000000000000: 4C 89 44 24 18     mov         qword ptr [rsp+18h],r8
  0000000000000005: 48 89 54 24 10     mov         qword ptr [rsp+10h],rdx
  000000000000000A: 48 89 4C 24 08     mov         qword ptr [rsp+8],rcx
  000000000000000F: 53                 push        rbx
  0000000000000010: 56                 push        rsi
  0000000000000011: 57                 push        rdi
  0000000000000012: 41 56              push        r14
  0000000000000014: 48 83 EC 38        sub         rsp,38h
  0000000000000018: 48 C7 44 24 20 FE  mov         qword ptr [rsp+20h],0FFFFFFFFFFFFFFFEh
                    FF FF FF
  0000000000000021: 49 8B F0           mov         rsi,r8
  0000000000000024: 48 8B D9           mov         rbx,rcx
  0000000000000027: 48 8B FA           mov         rdi,rdx
  000000000000002A: 48 83 CF 0F        or          rdi,0Fh
  000000000000002E: 48 83 FF FE        cmp         rdi,0FFFFFFFFFFFFFFFEh
  0000000000000032: 76 05              jbe         0000000000000039
  0000000000000034: 48 8B FA           mov         rdi,rdx
  0000000000000037: EB 35              jmp         000000000000006E
  0000000000000039: 4C 8B 41 18        mov         r8,qword ptr [rcx+18h]
  000000000000003D: 49 8B C8           mov         rcx,r8
  0000000000000040: 48 D1 E9           shr         rcx,1
  0000000000000043: 48 B8 AB AA AA AA  mov         rax,0AAAAAAAAAAAAAAABh
                    AA AA AA AA
  000000000000004D: 48 F7 E7           mul         rax,rdi
  0000000000000050: 48 D1 EA           shr         rdx,1
  0000000000000053: 48 3B CA           cmp         rcx,rdx
  0000000000000056: 76 16              jbe         000000000000006E
  0000000000000058: 48 C7 C7 FE FF FF  mov         rdi,0FFFFFFFFFFFFFFFEh
                    FF
  000000000000005F: 48 8B C7           mov         rax,rdi
  0000000000000062: 48 2B C1           sub         rax,rcx
  0000000000000065: 4C 3B C0           cmp         r8,rax
  0000000000000068: 77 04              ja          000000000000006E
  000000000000006A: 4A 8D 3C 01        lea         rdi,[rcx+r8]
  000000000000006E: 48 8D 57 01        lea         rdx,[rdi+1]
  0000000000000072: 48 8B CB           mov         rcx,rbx
  0000000000000075: E8 00 00 00 00     call        replaced
  0000000000000000: 48 83 EC 28        sub         rsp,28h
  0000000000000004: 48 85 D2           test        rdx,rdx
  0000000000000007: 75 07              jne         0000000000000010
  0000000000000009: 33 C0              xor         eax,eax
  000000000000000B: 48 83 C4 28        add         rsp,28h
  000000000000000F: C3                 ret
  0000000000000010: 48 83 FA FF        cmp         rdx,0FFFFFFFFFFFFFFFFh
  0000000000000014: 77 3F              ja          0000000000000055
  0000000000000016: 48 81 FA 00 10 00  cmp         rdx,1000h
                    00
  000000000000001D: 72 27              jb          0000000000000046
  000000000000001F: 48 8D 4A 27        lea         rcx,[rdx+27h]
  0000000000000023: 48 3B CA           cmp         rcx,rdx
  0000000000000026: 76 33              jbe         000000000000005B
  0000000000000028: E8 00 00 00 00     call        ??2@YAPEAX_K@Z
  000000000000002D: 48 8B C8           mov         rcx,rax
  0000000000000030: 48 85 C0           test        rax,rax
  0000000000000033: 74 2C              je          0000000000000061
  0000000000000035: 48 83 C0 27        add         rax,27h
  0000000000000039: 48 83 E0 E0        and         rax,0FFFFFFFFFFFFFFE0h
  000000000000003D: 48 89 48 F8        mov         qword ptr [rax-8],rcx
  0000000000000041: 48 83 C4 28        add         rsp,28h
  0000000000000045: C3                 ret
  0000000000000046: 48 8B CA           mov         rcx,rdx
  0000000000000049: E8 00 00 00 00     call        ??2@YAPEAX_K@Z
  000000000000004E: 48 85 C0           test        rax,rax
  0000000000000051: 75 B8              jne         000000000000000B
  0000000000000053: EB 12              jmp         0000000000000067
  0000000000000055: E8 00 00 00 00     call        ?_Xbad_alloc@std@@YAXXZ
  000000000000005A: CC                 int         3
  000000000000005B: E8 00 00 00 00     call        ?_Xbad_alloc@std@@YAXXZ
  0000000000000060: CC                 int         3
  0000000000000061: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000066: CC                 int         3
  0000000000000067: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  000000000000006C: CC                 int         3

  000000000000007A: 4C 8B F0           mov         r14,rax
  000000000000007D: EB 14              jmp         0000000000000093
$LN19:
  000000000000007F: 48 8B 5C 24 60     mov         rbx,qword ptr [rsp+60h]
  0000000000000084: 48 8B 74 24 70     mov         rsi,qword ptr [rsp+70h]
  0000000000000089: 48 8B 7C 24 68     mov         rdi,qword ptr [rsp+68h]
  000000000000008E: 4C 8B 74 24 78     mov         r14,qword ptr [rsp+78h]
  0000000000000093: 48 85 F6           test        rsi,rsi
  0000000000000096: 74 1F              je          00000000000000B7
  0000000000000098: 48 83 7B 18 10     cmp         qword ptr [rbx+18h],10h
  000000000000009D: 72 05              jb          00000000000000A4
  000000000000009F: 48 8B 13           mov         rdx,qword ptr [rbx]
  00000000000000A2: EB 03              jmp         00000000000000A7
  00000000000000A4: 48 8B D3           mov         rdx,rbx
  00000000000000A7: 48 85 F6           test        rsi,rsi
  00000000000000AA: 74 0B              je          00000000000000B7
  00000000000000AC: 4C 8B C6           mov         r8,rsi
  00000000000000AF: 49 8B CE           mov         rcx,r14
  00000000000000B2: E8 00 00 00 00     call        memcpy
  00000000000000B7: 4C 8B 43 18        mov         r8,qword ptr [rbx+18h]
  00000000000000BB: 49 83 F8 10        cmp         r8,10h
  00000000000000BF: 72 0E              jb          00000000000000CF
  00000000000000C1: 49 FF C0           inc         r8
  00000000000000C4: 48 8B 13           mov         rdx,qword ptr [rbx]
  00000000000000C7: 48 8B CB           mov         rcx,rbx
  00000000000000CA: E8 00 00 00 00     call        replaced
  0000000000000000: 48 83 EC 28        sub         rsp,28h
  0000000000000004: 49 83 F8 FF        cmp         r8,0FFFFFFFFFFFFFFFFh
  0000000000000008: 77 35              ja          000000000000003F
  000000000000000A: 49 81 F8 00 10 00  cmp         r8,1000h
                    00
  0000000000000011: 72 20              jb          0000000000000033
  0000000000000013: F6 C2 1F           test        dl,1Fh
  0000000000000016: 75 2D              jne         0000000000000045
  0000000000000018: 48 8B 42 F8        mov         rax,qword ptr [rdx-8]
  000000000000001C: 48 3B C2           cmp         rax,rdx
  000000000000001F: 73 2A              jae         000000000000004B
  0000000000000021: 48 2B D0           sub         rdx,rax
  0000000000000024: 48 83 FA 08        cmp         rdx,8
  0000000000000028: 72 27              jb          0000000000000051
  000000000000002A: 48 83 FA 27        cmp         rdx,27h
  000000000000002E: 77 27              ja          0000000000000057
  0000000000000030: 48 8B D0           mov         rdx,rax
  0000000000000033: 48 8B CA           mov         rcx,rdx
  0000000000000036: 48 83 C4 28        add         rsp,28h
  000000000000003A: E9 00 00 00 00     jmp         ??3@YAXPEAX@Z
  000000000000003F: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000044: CC                 int         3
  0000000000000045: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  000000000000004A: CC                 int         3
  000000000000004B: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000050: CC                 int         3
  0000000000000051: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000056: CC                 int         3
  0000000000000057: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  000000000000005C: CC                 int         3

  00000000000000CF: 48 C7 43 18 0F 00  mov         qword ptr [rbx+18h],0Fh
                    00 00
  00000000000000D7: 48 C7 43 10 00 00  mov         qword ptr [rbx+10h],0
                    00 00
  00000000000000DF: 48 83 7B 18 10     cmp         qword ptr [rbx+18h],10h
  00000000000000E4: 72 05              jb          00000000000000EB
  00000000000000E6: 48 8B 03           mov         rax,qword ptr [rbx]
  00000000000000E9: EB 03              jmp         00000000000000EE
  00000000000000EB: 48 8B C3           mov         rax,rbx
  00000000000000EE: C6 00 00           mov         byte ptr [rax],0
  00000000000000F1: 4C 89 33           mov         qword ptr [rbx],r14
  00000000000000F4: 48 89 7B 18        mov         qword ptr [rbx+18h],rdi
  00000000000000F8: 48 89 73 10        mov         qword ptr [rbx+10h],rsi
  00000000000000FC: 48 83 7B 18 10     cmp         qword ptr [rbx+18h],10h
  0000000000000101: 72 03              jb          0000000000000106
  0000000000000103: 49 8B DE           mov         rbx,r14
  0000000000000106: C6 04 33 00        mov         byte ptr [rbx+rsi],0
  000000000000010A: 48 83 C4 38        add         rsp,38h
  000000000000010E: 41 5E              pop         r14
  0000000000000110: 5F                 pop         rdi
  0000000000000111: 5E                 pop         rsi
  0000000000000112: 5B                 pop         rbx
  0000000000000113: C3                 ret

  0000000000000084: 48 85 FF           test        rdi,rdi
  0000000000000087: 74 61              je          00000000000000EA
  0000000000000089: 48 83 7E 18 10     cmp         qword ptr [rsi+18h],10h
  000000000000008E: 72 03              jb          0000000000000093
  0000000000000090: 48 8B 36           mov         rsi,qword ptr [rsi]
  0000000000000093: 48 83 7B 18 10     cmp         qword ptr [rbx+18h],10h
  0000000000000098: 72 25              jb          00000000000000BF
  000000000000009A: 48 8B 0B           mov         rcx,qword ptr [rbx]
  000000000000009D: EB 23              jmp         00000000000000C2
  000000000000009F: 48 85 FF           test        rdi,rdi
  00000000000000A2: 75 E5              jne         0000000000000089
  00000000000000A4: 48 89 79 10        mov         qword ptr [rcx+10h],rdi
  00000000000000A8: 48 83 79 18 10     cmp         qword ptr [rcx+18h],10h
  00000000000000AD: 72 08              jb          00000000000000B7
  00000000000000AF: 48 8B 01           mov         rax,qword ptr [rcx]
  00000000000000B2: 40 88 38           mov         byte ptr [rax],dil
  00000000000000B5: EB 33              jmp         00000000000000EA
  00000000000000B7: 48 8B C1           mov         rax,rcx
  00000000000000BA: C6 01 00           mov         byte ptr [rcx],0
  00000000000000BD: EB 2B              jmp         00000000000000EA
  00000000000000BF: 48 8B CB           mov         rcx,rbx
  00000000000000C2: 48 85 FF           test        rdi,rdi
  00000000000000C5: 74 0C              je          00000000000000D3
  00000000000000C7: 48 8D 14 2E        lea         rdx,[rsi+rbp]
  00000000000000CB: 4C 8B C7           mov         r8,rdi
  00000000000000CE: E8 00 00 00 00     call        memcpy
  00000000000000D3: 48 89 7B 10        mov         qword ptr [rbx+10h],rdi
  00000000000000D7: 48 83 7B 18 10     cmp         qword ptr [rbx+18h],10h
  00000000000000DC: 72 05              jb          00000000000000E3
  00000000000000DE: 48 8B 03           mov         rax,qword ptr [rbx]
  00000000000000E1: EB 03              jmp         00000000000000E6
  00000000000000E3: 48 8B C3           mov         rax,rbx
  00000000000000E6: C6 04 38 00        mov         byte ptr [rax+rdi],0
  00000000000000EA: 48 8B 6C 24 38     mov         rbp,qword ptr [rsp+38h]
  00000000000000EF: 48 8B C3           mov         rax,rbx
  00000000000000F2: 48 8B 5C 24 30     mov         rbx,qword ptr [rsp+30h]
  00000000000000F7: 48 8B 74 24 40     mov         rsi,qword ptr [rsp+40h]
  00000000000000FC: 48 83 C4 20        add         rsp,20h
  0000000000000100: 5F                 pop         rdi
  0000000000000101: C3                 ret
  0000000000000102: 48 8D 0D 00 00 00  lea         rcx,[??_C@_0BI@CFPLBAOH@invalid?5string?5position?$AA@]
                    00
  0000000000000109: E8 00 00 00 00     call        ?_Xout_of_range@std@@YAXPEBD@Z
  000000000000010E: CC                 int         3
  000000000000010F: 48 8D 0D 00 00 00  lea         rcx,[??_C@_0BI@CFPLBAOH@invalid?5string?5position?$AA@]
                    00
  0000000000000116: E8 00 00 00 00     call        ?_Xout_of_range@std@@YAXPEBD@Z
  000000000000011B: CC                 int         3
  000000000000011C: 48 8D 0D 00 00 00  lea         rcx,[??_C@_0BA@JFNIOLAK@string?5too?5long?$AA@]
                    00
  0000000000000123: E8 00 00 00 00     call        ?_Xlength_error@std@@YAXPEBD@Z
  0000000000000128: CC                 int         3

  000000000000007C: 66 0F 7F 75 D7     movdqa      xmmword ptr [rbp-29h],xmm6
  0000000000000081: 4C 8D 45 07        lea         r8,[rbp+7]
  0000000000000085: 48 8D 55 D7        lea         rdx,[rbp-29h]
  0000000000000089: 48 8D 4D 27        lea         rcx,[rbp+27h]
  000000000000008D: E8 00 00 00 00     call        replaced
  0000000000000000: 4C 89 44 24 18     mov         qword ptr [rsp+18h],r8
  0000000000000005: 57                 push        rdi
  0000000000000006: 48 83 EC 50        sub         rsp,50h
  000000000000000A: 48 C7 44 24 28 FE  mov         qword ptr [rsp+28h],0FFFFFFFFFFFFFFFEh
                    FF FF FF
  0000000000000013: 48 89 5C 24 60     mov         qword ptr [rsp+60h],rbx
  0000000000000018: 48 89 74 24 68     mov         qword ptr [rsp+68h],rsi
  000000000000001D: 49 8B D8           mov         rbx,r8
  0000000000000020: 48 8B F2           mov         rsi,rdx
  0000000000000023: 48 8B F9           mov         rdi,rcx
  0000000000000026: C7 44 24 20 00 00  mov         dword ptr [rsp+20h],0
                    00 00
  000000000000002E: 49 83 78 10 00     cmp         qword ptr [r8+10h],0
  0000000000000033: 0F 94 C0           sete        al
  0000000000000036: 84 C0              test        al,al
  0000000000000038: 75 15              jne         000000000000004F
  000000000000003A: 41 B8 02 00 00 00  mov         r8d,2
  0000000000000040: 48 8D 15 00 00 00  lea         rdx,[??_C@_02LMMGGCAJ@?3?5?$AA@]
                    00
  0000000000000047: 48 8B CB           mov         rcx,rbx
  000000000000004A: E8 00 00 00 00     call        replaced
  0000000000000000: 48 89 5C 24 10     mov         qword ptr [rsp+10h],rbx
  0000000000000005: 48 89 6C 24 18     mov         qword ptr [rsp+18h],rbp
  000000000000000A: 56                 push        rsi
  000000000000000B: 48 83 EC 20        sub         rsp,20h
  000000000000000F: 49 8B F0           mov         rsi,r8
  0000000000000012: 48 8B EA           mov         rbp,rdx
  0000000000000015: 48 8B D9           mov         rbx,rcx
  0000000000000018: 48 85 D2           test        rdx,rdx
  000000000000001B: 74 5A              je          0000000000000077
  000000000000001D: 4C 8B 41 18        mov         r8,qword ptr [rcx+18h]
  0000000000000021: 49 83 F8 10        cmp         r8,10h
  0000000000000025: 72 05              jb          000000000000002C
  0000000000000027: 48 8B 01           mov         rax,qword ptr [rcx]
  000000000000002A: EB 03              jmp         000000000000002F
  000000000000002C: 48 8B C1           mov         rax,rcx
  000000000000002F: 48 3B D0           cmp         rdx,rax
  0000000000000032: 72 43              jb          0000000000000077
  0000000000000034: 49 83 F8 10        cmp         r8,10h
  0000000000000038: 72 03              jb          000000000000003D
  000000000000003A: 48 8B 09           mov         rcx,qword ptr [rcx]
  000000000000003D: 48 03 4B 10        add         rcx,qword ptr [rbx+10h]
  0000000000000041: 48 3B CA           cmp         rcx,rdx
  0000000000000044: 76 31              jbe         0000000000000077
  0000000000000046: 49 83 F8 10        cmp         r8,10h
  000000000000004A: 72 05              jb          0000000000000051
  000000000000004C: 48 8B 03           mov         rax,qword ptr [rbx]
  000000000000004F: EB 03              jmp         0000000000000054
  0000000000000051: 48 8B C3           mov         rax,rbx
  0000000000000054: 48 2B E8           sub         rbp,rax
  0000000000000057: 4C 8B CE           mov         r9,rsi
  000000000000005A: 4C 8B C5           mov         r8,rbp
  000000000000005D: 48 8B D3           mov         rdx,rbx
  0000000000000060: 48 8B CB           mov         rcx,rbx
  0000000000000063: 48 8B 5C 24 38     mov         rbx,qword ptr [rsp+38h]
  0000000000000068: 48 8B 6C 24 40     mov         rbp,qword ptr [rsp+40h]
  000000000000006D: 48 83 C4 20        add         rsp,20h
  0000000000000071: 5E                 pop         rsi
  0000000000000072: E9 00 00 00 00     jmp         replaced
  0000000000000000: 48 89 5C 24 10     mov         qword ptr [rsp+10h],rbx
  0000000000000005: 48 89 6C 24 18     mov         qword ptr [rsp+18h],rbp
  000000000000000A: 48 89 74 24 20     mov         qword ptr [rsp+20h],rsi
  000000000000000F: 41 56              push        r14
  0000000000000011: 48 83 EC 20        sub         rsp,20h
  0000000000000015: 48 8B 42 10        mov         rax,qword ptr [rdx+10h]
  0000000000000019: 49 8B F1           mov         rsi,r9
  000000000000001C: 49 8B E8           mov         rbp,r8
  000000000000001F: 4C 8B F2           mov         r14,rdx
  0000000000000022: 48 8B D9           mov         rbx,rcx
  0000000000000025: 49 3B C0           cmp         rax,r8
  0000000000000028: 0F 82 D0 00 00 00  jb          00000000000000FE
  000000000000002E: 49 2B C0           sub         rax,r8
  0000000000000031: 4C 8B 41 10        mov         r8,qword ptr [rcx+10h]
  0000000000000035: 49 3B C1           cmp         rax,r9
  0000000000000038: 48 0F 42 F0        cmovb       rsi,rax
  000000000000003C: 48 83 C8 FF        or          rax,0FFFFFFFFFFFFFFFFh
  0000000000000040: 49 2B C0           sub         rax,r8
  0000000000000043: 48 3B C6           cmp         rax,rsi
  0000000000000046: 0F 86 BF 00 00 00  jbe         000000000000010B
  000000000000004C: 48 89 7C 24 30     mov         qword ptr [rsp+30h],rdi
  0000000000000051: 48 85 F6           test        rsi,rsi
  0000000000000054: 0F 84 86 00 00 00  je          00000000000000E0
  000000000000005A: 49 8D 3C 30        lea         rdi,[r8+rsi]
  000000000000005E: 48 83 FF FE        cmp         rdi,0FFFFFFFFFFFFFFFEh
  0000000000000062: 0F 87 B0 00 00 00  ja          0000000000000118
  0000000000000068: 48 39 79 18        cmp         qword ptr [rcx+18h],rdi
  000000000000006C: 73 23              jae         0000000000000091
  000000000000006E: 48 8B D7           mov         rdx,rdi
  0000000000000071: E8 00 00 00 00     call        replaced
  0000000000000000: 4C 89 44 24 18     mov         qword ptr [rsp+18h],r8
  0000000000000005: 48 89 54 24 10     mov         qword ptr [rsp+10h],rdx
  000000000000000A: 48 89 4C 24 08     mov         qword ptr [rsp+8],rcx
  000000000000000F: 53                 push        rbx
  0000000000000010: 56                 push        rsi
  0000000000000011: 57                 push        rdi
  0000000000000012: 41 56              push        r14
  0000000000000014: 48 83 EC 38        sub         rsp,38h
  0000000000000018: 48 C7 44 24 20 FE  mov         qword ptr [rsp+20h],0FFFFFFFFFFFFFFFEh
                    FF FF FF
  0000000000000021: 49 8B F0           mov         rsi,r8
  0000000000000024: 48 8B D9           mov         rbx,rcx
  0000000000000027: 48 8B FA           mov         rdi,rdx
  000000000000002A: 48 83 CF 0F        or          rdi,0Fh
  000000000000002E: 48 83 FF FE        cmp         rdi,0FFFFFFFFFFFFFFFEh
  0000000000000032: 76 05              jbe         0000000000000039
  0000000000000034: 48 8B FA           mov         rdi,rdx
  0000000000000037: EB 35              jmp         000000000000006E
  0000000000000039: 4C 8B 41 18        mov         r8,qword ptr [rcx+18h]
  000000000000003D: 49 8B C8           mov         rcx,r8
  0000000000000040: 48 D1 E9           shr         rcx,1
  0000000000000043: 48 B8 AB AA AA AA  mov         rax,0AAAAAAAAAAAAAAABh
                    AA AA AA AA
  000000000000004D: 48 F7 E7           mul         rax,rdi
  0000000000000050: 48 D1 EA           shr         rdx,1
  0000000000000053: 48 3B CA           cmp         rcx,rdx
  0000000000000056: 76 16              jbe         000000000000006E
  0000000000000058: 48 C7 C7 FE FF FF  mov         rdi,0FFFFFFFFFFFFFFFEh
                    FF
  000000000000005F: 48 8B C7           mov         rax,rdi
  0000000000000062: 48 2B C1           sub         rax,rcx
  0000000000000065: 4C 3B C0           cmp         r8,rax
  0000000000000068: 77 04              ja          000000000000006E
  000000000000006A: 4A 8D 3C 01        lea         rdi,[rcx+r8]
  000000000000006E: 48 8D 57 01        lea         rdx,[rdi+1]
  0000000000000072: 48 8B CB           mov         rcx,rbx
  0000000000000075: E8 00 00 00 00     call        replaced
  0000000000000000: 48 83 EC 28        sub         rsp,28h
  0000000000000004: 48 85 D2           test        rdx,rdx
  0000000000000007: 75 07              jne         0000000000000010
  0000000000000009: 33 C0              xor         eax,eax
  000000000000000B: 48 83 C4 28        add         rsp,28h
  000000000000000F: C3                 ret
  0000000000000010: 48 83 FA FF        cmp         rdx,0FFFFFFFFFFFFFFFFh
  0000000000000014: 77 3F              ja          0000000000000055
  0000000000000016: 48 81 FA 00 10 00  cmp         rdx,1000h
                    00
  000000000000001D: 72 27              jb          0000000000000046
  000000000000001F: 48 8D 4A 27        lea         rcx,[rdx+27h]
  0000000000000023: 48 3B CA           cmp         rcx,rdx
  0000000000000026: 76 33              jbe         000000000000005B
  0000000000000028: E8 00 00 00 00     call        ??2@YAPEAX_K@Z
  000000000000002D: 48 8B C8           mov         rcx,rax
  0000000000000030: 48 85 C0           test        rax,rax
  0000000000000033: 74 2C              je          0000000000000061
  0000000000000035: 48 83 C0 27        add         rax,27h
  0000000000000039: 48 83 E0 E0        and         rax,0FFFFFFFFFFFFFFE0h
  000000000000003D: 48 89 48 F8        mov         qword ptr [rax-8],rcx
  0000000000000041: 48 83 C4 28        add         rsp,28h
  0000000000000045: C3                 ret
  0000000000000046: 48 8B CA           mov         rcx,rdx
  0000000000000049: E8 00 00 00 00     call        ??2@YAPEAX_K@Z
  000000000000004E: 48 85 C0           test        rax,rax
  0000000000000051: 75 B8              jne         000000000000000B
  0000000000000053: EB 12              jmp         0000000000000067
  0000000000000055: E8 00 00 00 00     call        ?_Xbad_alloc@std@@YAXXZ
  000000000000005A: CC                 int         3
  000000000000005B: E8 00 00 00 00     call        ?_Xbad_alloc@std@@YAXXZ
  0000000000000060: CC                 int         3
  0000000000000061: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000066: CC                 int         3
  0000000000000067: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  000000000000006C: CC                 int         3

  000000000000007A: 4C 8B F0           mov         r14,rax
  000000000000007D: EB 14              jmp         0000000000000093
$LN19:
  000000000000007F: 48 8B 5C 24 60     mov         rbx,qword ptr [rsp+60h]
  0000000000000084: 48 8B 74 24 70     mov         rsi,qword ptr [rsp+70h]
  0000000000000089: 48 8B 7C 24 68     mov         rdi,qword ptr [rsp+68h]
  000000000000008E: 4C 8B 74 24 78     mov         r14,qword ptr [rsp+78h]
  0000000000000093: 48 85 F6           test        rsi,rsi
  0000000000000096: 74 1F              je          00000000000000B7
  0000000000000098: 48 83 7B 18 10     cmp         qword ptr [rbx+18h],10h
  000000000000009D: 72 05              jb          00000000000000A4
  000000000000009F: 48 8B 13           mov         rdx,qword ptr [rbx]
  00000000000000A2: EB 03              jmp         00000000000000A7
  00000000000000A4: 48 8B D3           mov         rdx,rbx
  00000000000000A7: 48 85 F6           test        rsi,rsi
  00000000000000AA: 74 0B              je          00000000000000B7
  00000000000000AC: 4C 8B C6           mov         r8,rsi
  00000000000000AF: 49 8B CE           mov         rcx,r14
  00000000000000B2: E8 00 00 00 00     call        memcpy
  00000000000000B7: 4C 8B 43 18        mov         r8,qword ptr [rbx+18h]
  00000000000000BB: 49 83 F8 10        cmp         r8,10h
  00000000000000BF: 72 0E              jb          00000000000000CF
  00000000000000C1: 49 FF C0           inc         r8
  00000000000000C4: 48 8B 13           mov         rdx,qword ptr [rbx]
  00000000000000C7: 48 8B CB           mov         rcx,rbx
  00000000000000CA: E8 00 00 00 00     call        replaced
  0000000000000000: 48 83 EC 28        sub         rsp,28h
  0000000000000004: 49 83 F8 FF        cmp         r8,0FFFFFFFFFFFFFFFFh
  0000000000000008: 77 35              ja          000000000000003F
  000000000000000A: 49 81 F8 00 10 00  cmp         r8,1000h
                    00
  0000000000000011: 72 20              jb          0000000000000033
  0000000000000013: F6 C2 1F           test        dl,1Fh
  0000000000000016: 75 2D              jne         0000000000000045
  0000000000000018: 48 8B 42 F8        mov         rax,qword ptr [rdx-8]
  000000000000001C: 48 3B C2           cmp         rax,rdx
  000000000000001F: 73 2A              jae         000000000000004B
  0000000000000021: 48 2B D0           sub         rdx,rax
  0000000000000024: 48 83 FA 08        cmp         rdx,8
  0000000000000028: 72 27              jb          0000000000000051
  000000000000002A: 48 83 FA 27        cmp         rdx,27h
  000000000000002E: 77 27              ja          0000000000000057
  0000000000000030: 48 8B D0           mov         rdx,rax
  0000000000000033: 48 8B CA           mov         rcx,rdx
  0000000000000036: 48 83 C4 28        add         rsp,28h
  000000000000003A: E9 00 00 00 00     jmp         ??3@YAXPEAX@Z
  000000000000003F: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000044: CC                 int         3
  0000000000000045: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  000000000000004A: CC                 int         3
  000000000000004B: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000050: CC                 int         3
  0000000000000051: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000056: CC                 int         3
  0000000000000057: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  000000000000005C: CC                 int         3

  00000000000000CF: 48 C7 43 18 0F 00  mov         qword ptr [rbx+18h],0Fh
                    00 00
  00000000000000D7: 48 C7 43 10 00 00  mov         qword ptr [rbx+10h],0
                    00 00
  00000000000000DF: 48 83 7B 18 10     cmp         qword ptr [rbx+18h],10h
  00000000000000E4: 72 05              jb          00000000000000EB
  00000000000000E6: 48 8B 03           mov         rax,qword ptr [rbx]
  00000000000000E9: EB 03              jmp         00000000000000EE
  00000000000000EB: 48 8B C3           mov         rax,rbx
  00000000000000EE: C6 00 00           mov         byte ptr [rax],0
  00000000000000F1: 4C 89 33           mov         qword ptr [rbx],r14
  00000000000000F4: 48 89 7B 18        mov         qword ptr [rbx+18h],rdi
  00000000000000F8: 48 89 73 10        mov         qword ptr [rbx+10h],rsi
  00000000000000FC: 48 83 7B 18 10     cmp         qword ptr [rbx+18h],10h
  0000000000000101: 72 03              jb          0000000000000106
  0000000000000103: 49 8B DE           mov         rbx,r14
  0000000000000106: C6 04 33 00        mov         byte ptr [rbx+rsi],0
  000000000000010A: 48 83 C4 38        add         rsp,38h
  000000000000010E: 41 5E              pop         r14
  0000000000000110: 5F                 pop         rdi
  0000000000000111: 5E                 pop         rsi
  0000000000000112: 5B                 pop         rbx
  0000000000000113: C3                 ret

  0000000000000076: 48 85 FF           test        rdi,rdi
  0000000000000079: 74 65              je          00000000000000E0
  000000000000007B: 49 83 7E 18 10     cmp         qword ptr [r14+18h],10h
  0000000000000080: 72 03              jb          0000000000000085
  0000000000000082: 4D 8B 36           mov         r14,qword ptr [r14]
  0000000000000085: 48 83 7B 18 10     cmp         qword ptr [rbx+18h],10h
  000000000000008A: 72 25              jb          00000000000000B1
  000000000000008C: 48 8B 0B           mov         rcx,qword ptr [rbx]
  000000000000008F: EB 23              jmp         00000000000000B4
  0000000000000091: 48 85 FF           test        rdi,rdi
  0000000000000094: 75 E5              jne         000000000000007B
  0000000000000096: 48 89 79 10        mov         qword ptr [rcx+10h],rdi
  000000000000009A: 48 83 79 18 10     cmp         qword ptr [rcx+18h],10h
  000000000000009F: 72 08              jb          00000000000000A9
  00000000000000A1: 48 8B 01           mov         rax,qword ptr [rcx]
  00000000000000A4: 40 88 38           mov         byte ptr [rax],dil
  00000000000000A7: EB 37              jmp         00000000000000E0
  00000000000000A9: 48 8B C1           mov         rax,rcx
  00000000000000AC: C6 01 00           mov         byte ptr [rcx],0
  00000000000000AF: EB 2F              jmp         00000000000000E0
  00000000000000B1: 48 8B CB           mov         rcx,rbx
  00000000000000B4: 48 85 F6           test        rsi,rsi
  00000000000000B7: 74 10              je          00000000000000C9
  00000000000000B9: 48 03 4B 10        add         rcx,qword ptr [rbx+10h]
  00000000000000BD: 49 8D 14 2E        lea         rdx,[r14+rbp]
  00000000000000C1: 4C 8B C6           mov         r8,rsi
  00000000000000C4: E8 00 00 00 00     call        memcpy
  00000000000000C9: 48 89 7B 10        mov         qword ptr [rbx+10h],rdi
  00000000000000CD: 48 83 7B 18 10     cmp         qword ptr [rbx+18h],10h
  00000000000000D2: 72 05              jb          00000000000000D9
  00000000000000D4: 48 8B 03           mov         rax,qword ptr [rbx]
  00000000000000D7: EB 03              jmp         00000000000000DC
  00000000000000D9: 48 8B C3           mov         rax,rbx
  00000000000000DC: C6 04 38 00        mov         byte ptr [rax+rdi],0
  00000000000000E0: 48 8B 7C 24 30     mov         rdi,qword ptr [rsp+30h]
  00000000000000E5: 48 8B C3           mov         rax,rbx
  00000000000000E8: 48 8B 5C 24 38     mov         rbx,qword ptr [rsp+38h]
  00000000000000ED: 48 8B 6C 24 40     mov         rbp,qword ptr [rsp+40h]
  00000000000000F2: 48 8B 74 24 48     mov         rsi,qword ptr [rsp+48h]
  00000000000000F7: 48 83 C4 20        add         rsp,20h
  00000000000000FB: 41 5E              pop         r14
  00000000000000FD: C3                 ret
  00000000000000FE: 48 8D 0D 00 00 00  lea         rcx,[??_C@_0BI@CFPLBAOH@invalid?5string?5position?$AA@]
                    00
  0000000000000105: E8 00 00 00 00     call        ?_Xout_of_range@std@@YAXPEBD@Z
  000000000000010A: CC                 int         3
  000000000000010B: 48 8D 0D 00 00 00  lea         rcx,[??_C@_0BA@JFNIOLAK@string?5too?5long?$AA@]
                    00
  0000000000000112: E8 00 00 00 00     call        ?_Xlength_error@std@@YAXPEBD@Z
  0000000000000117: CC                 int         3
  0000000000000118: 48 8D 0D 00 00 00  lea         rcx,[??_C@_0BA@JFNIOLAK@string?5too?5long?$AA@]
                    00
  000000000000011F: E8 00 00 00 00     call        ?_Xlength_error@std@@YAXPEBD@Z
  0000000000000124: CC                 int         3

  0000000000000077: 4C 8B 43 10        mov         r8,qword ptr [rbx+10h]
  000000000000007B: 48 83 C8 FF        or          rax,0FFFFFFFFFFFFFFFFh
  000000000000007F: 49 2B C0           sub         rax,r8
  0000000000000082: 48 3B C6           cmp         rax,rsi
  0000000000000085: 0F 86 A0 00 00 00  jbe         000000000000012B
  000000000000008B: 48 89 7C 24 30     mov         qword ptr [rsp+30h],rdi
  0000000000000090: 48 85 F6           test        rsi,rsi
  0000000000000093: 74 7E              je          0000000000000113
  0000000000000095: 49 8D 3C 30        lea         rdi,[r8+rsi]
  0000000000000099: 48 83 FF FE        cmp         rdi,0FFFFFFFFFFFFFFFEh
  000000000000009D: 0F 87 95 00 00 00  ja          0000000000000138
  00000000000000A3: 48 39 7B 18        cmp         qword ptr [rbx+18h],rdi
  00000000000000A7: 73 1C              jae         00000000000000C5
  00000000000000A9: 48 8B D7           mov         rdx,rdi
  00000000000000AC: 48 8B CB           mov         rcx,rbx
  00000000000000AF: E8 00 00 00 00     call        replaced
  0000000000000000: 4C 89 44 24 18     mov         qword ptr [rsp+18h],r8
  0000000000000005: 48 89 54 24 10     mov         qword ptr [rsp+10h],rdx
  000000000000000A: 48 89 4C 24 08     mov         qword ptr [rsp+8],rcx
  000000000000000F: 53                 push        rbx
  0000000000000010: 56                 push        rsi
  0000000000000011: 57                 push        rdi
  0000000000000012: 41 56              push        r14
  0000000000000014: 48 83 EC 38        sub         rsp,38h
  0000000000000018: 48 C7 44 24 20 FE  mov         qword ptr [rsp+20h],0FFFFFFFFFFFFFFFEh
                    FF FF FF
  0000000000000021: 49 8B F0           mov         rsi,r8
  0000000000000024: 48 8B D9           mov         rbx,rcx
  0000000000000027: 48 8B FA           mov         rdi,rdx
  000000000000002A: 48 83 CF 0F        or          rdi,0Fh
  000000000000002E: 48 83 FF FE        cmp         rdi,0FFFFFFFFFFFFFFFEh
  0000000000000032: 76 05              jbe         0000000000000039
  0000000000000034: 48 8B FA           mov         rdi,rdx
  0000000000000037: EB 35              jmp         000000000000006E
  0000000000000039: 4C 8B 41 18        mov         r8,qword ptr [rcx+18h]
  000000000000003D: 49 8B C8           mov         rcx,r8
  0000000000000040: 48 D1 E9           shr         rcx,1
  0000000000000043: 48 B8 AB AA AA AA  mov         rax,0AAAAAAAAAAAAAAABh
                    AA AA AA AA
  000000000000004D: 48 F7 E7           mul         rax,rdi
  0000000000000050: 48 D1 EA           shr         rdx,1
  0000000000000053: 48 3B CA           cmp         rcx,rdx
  0000000000000056: 76 16              jbe         000000000000006E
  0000000000000058: 48 C7 C7 FE FF FF  mov         rdi,0FFFFFFFFFFFFFFFEh
                    FF
  000000000000005F: 48 8B C7           mov         rax,rdi
  0000000000000062: 48 2B C1           sub         rax,rcx
  0000000000000065: 4C 3B C0           cmp         r8,rax
  0000000000000068: 77 04              ja          000000000000006E
  000000000000006A: 4A 8D 3C 01        lea         rdi,[rcx+r8]
  000000000000006E: 48 8D 57 01        lea         rdx,[rdi+1]
  0000000000000072: 48 8B CB           mov         rcx,rbx
  0000000000000075: E8 00 00 00 00     call        replaced
  0000000000000000: 48 83 EC 28        sub         rsp,28h
  0000000000000004: 48 85 D2           test        rdx,rdx
  0000000000000007: 75 07              jne         0000000000000010
  0000000000000009: 33 C0              xor         eax,eax
  000000000000000B: 48 83 C4 28        add         rsp,28h
  000000000000000F: C3                 ret
  0000000000000010: 48 83 FA FF        cmp         rdx,0FFFFFFFFFFFFFFFFh
  0000000000000014: 77 3F              ja          0000000000000055
  0000000000000016: 48 81 FA 00 10 00  cmp         rdx,1000h
                    00
  000000000000001D: 72 27              jb          0000000000000046
  000000000000001F: 48 8D 4A 27        lea         rcx,[rdx+27h]
  0000000000000023: 48 3B CA           cmp         rcx,rdx
  0000000000000026: 76 33              jbe         000000000000005B
  0000000000000028: E8 00 00 00 00     call        ??2@YAPEAX_K@Z
  000000000000002D: 48 8B C8           mov         rcx,rax
  0000000000000030: 48 85 C0           test        rax,rax
  0000000000000033: 74 2C              je          0000000000000061
  0000000000000035: 48 83 C0 27        add         rax,27h
  0000000000000039: 48 83 E0 E0        and         rax,0FFFFFFFFFFFFFFE0h
  000000000000003D: 48 89 48 F8        mov         qword ptr [rax-8],rcx
  0000000000000041: 48 83 C4 28        add         rsp,28h
  0000000000000045: C3                 ret
  0000000000000046: 48 8B CA           mov         rcx,rdx
  0000000000000049: E8 00 00 00 00     call        ??2@YAPEAX_K@Z
  000000000000004E: 48 85 C0           test        rax,rax
  0000000000000051: 75 B8              jne         000000000000000B
  0000000000000053: EB 12              jmp         0000000000000067
  0000000000000055: E8 00 00 00 00     call        ?_Xbad_alloc@std@@YAXXZ
  000000000000005A: CC                 int         3
  000000000000005B: E8 00 00 00 00     call        ?_Xbad_alloc@std@@YAXXZ
  0000000000000060: CC                 int         3
  0000000000000061: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000066: CC                 int         3
  0000000000000067: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  000000000000006C: CC                 int         3

  000000000000007A: 4C 8B F0           mov         r14,rax
  000000000000007D: EB 14              jmp         0000000000000093
$LN19:
  000000000000007F: 48 8B 5C 24 60     mov         rbx,qword ptr [rsp+60h]
  0000000000000084: 48 8B 74 24 70     mov         rsi,qword ptr [rsp+70h]
  0000000000000089: 48 8B 7C 24 68     mov         rdi,qword ptr [rsp+68h]
  000000000000008E: 4C 8B 74 24 78     mov         r14,qword ptr [rsp+78h]
  0000000000000093: 48 85 F6           test        rsi,rsi
  0000000000000096: 74 1F              je          00000000000000B7
  0000000000000098: 48 83 7B 18 10     cmp         qword ptr [rbx+18h],10h
  000000000000009D: 72 05              jb          00000000000000A4
  000000000000009F: 48 8B 13           mov         rdx,qword ptr [rbx]
  00000000000000A2: EB 03              jmp         00000000000000A7
  00000000000000A4: 48 8B D3           mov         rdx,rbx
  00000000000000A7: 48 85 F6           test        rsi,rsi
  00000000000000AA: 74 0B              je          00000000000000B7
  00000000000000AC: 4C 8B C6           mov         r8,rsi
  00000000000000AF: 49 8B CE           mov         rcx,r14
  00000000000000B2: E8 00 00 00 00     call        memcpy
  00000000000000B7: 4C 8B 43 18        mov         r8,qword ptr [rbx+18h]
  00000000000000BB: 49 83 F8 10        cmp         r8,10h
  00000000000000BF: 72 0E              jb          00000000000000CF
  00000000000000C1: 49 FF C0           inc         r8
  00000000000000C4: 48 8B 13           mov         rdx,qword ptr [rbx]
  00000000000000C7: 48 8B CB           mov         rcx,rbx
  00000000000000CA: E8 00 00 00 00     call        replaced
  0000000000000000: 48 83 EC 28        sub         rsp,28h
  0000000000000004: 49 83 F8 FF        cmp         r8,0FFFFFFFFFFFFFFFFh
  0000000000000008: 77 35              ja          000000000000003F
  000000000000000A: 49 81 F8 00 10 00  cmp         r8,1000h
                    00
  0000000000000011: 72 20              jb          0000000000000033
  0000000000000013: F6 C2 1F           test        dl,1Fh
  0000000000000016: 75 2D              jne         0000000000000045
  0000000000000018: 48 8B 42 F8        mov         rax,qword ptr [rdx-8]
  000000000000001C: 48 3B C2           cmp         rax,rdx
  000000000000001F: 73 2A              jae         000000000000004B
  0000000000000021: 48 2B D0           sub         rdx,rax
  0000000000000024: 48 83 FA 08        cmp         rdx,8
  0000000000000028: 72 27              jb          0000000000000051
  000000000000002A: 48 83 FA 27        cmp         rdx,27h
  000000000000002E: 77 27              ja          0000000000000057
  0000000000000030: 48 8B D0           mov         rdx,rax
  0000000000000033: 48 8B CA           mov         rcx,rdx
  0000000000000036: 48 83 C4 28        add         rsp,28h
  000000000000003A: E9 00 00 00 00     jmp         ??3@YAXPEAX@Z
  000000000000003F: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000044: CC                 int         3
  0000000000000045: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  000000000000004A: CC                 int         3
  000000000000004B: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000050: CC                 int         3
  0000000000000051: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000056: CC                 int         3
  0000000000000057: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  000000000000005C: CC                 int         3

  00000000000000CF: 48 C7 43 18 0F 00  mov         qword ptr [rbx+18h],0Fh
                    00 00
  00000000000000D7: 48 C7 43 10 00 00  mov         qword ptr [rbx+10h],0
                    00 00
  00000000000000DF: 48 83 7B 18 10     cmp         qword ptr [rbx+18h],10h
  00000000000000E4: 72 05              jb          00000000000000EB
  00000000000000E6: 48 8B 03           mov         rax,qword ptr [rbx]
  00000000000000E9: EB 03              jmp         00000000000000EE
  00000000000000EB: 48 8B C3           mov         rax,rbx
  00000000000000EE: C6 00 00           mov         byte ptr [rax],0
  00000000000000F1: 4C 89 33           mov         qword ptr [rbx],r14
  00000000000000F4: 48 89 7B 18        mov         qword ptr [rbx+18h],rdi
  00000000000000F8: 48 89 73 10        mov         qword ptr [rbx+10h],rsi
  00000000000000FC: 48 83 7B 18 10     cmp         qword ptr [rbx+18h],10h
  0000000000000101: 72 03              jb          0000000000000106
  0000000000000103: 49 8B DE           mov         rbx,r14
  0000000000000106: C6 04 33 00        mov         byte ptr [rbx+rsi],0
  000000000000010A: 48 83 C4 38        add         rsp,38h
  000000000000010E: 41 5E              pop         r14
  0000000000000110: 5F                 pop         rdi
  0000000000000111: 5E                 pop         rsi
  0000000000000112: 5B                 pop         rbx
  0000000000000113: C3                 ret

  00000000000000B4: 48 85 FF           test        rdi,rdi
  00000000000000B7: 74 5A              je          0000000000000113
  00000000000000B9: 48 83 7B 18 10     cmp         qword ptr [rbx+18h],10h
  00000000000000BE: 72 25              jb          00000000000000E5
  00000000000000C0: 48 8B 0B           mov         rcx,qword ptr [rbx]
  00000000000000C3: EB 23              jmp         00000000000000E8
  00000000000000C5: 48 85 FF           test        rdi,rdi
  00000000000000C8: 75 EF              jne         00000000000000B9
  00000000000000CA: 48 89 7B 10        mov         qword ptr [rbx+10h],rdi
  00000000000000CE: 48 83 7B 18 10     cmp         qword ptr [rbx+18h],10h
  00000000000000D3: 72 08              jb          00000000000000DD
  00000000000000D5: 48 8B 03           mov         rax,qword ptr [rbx]
  00000000000000D8: 40 88 38           mov         byte ptr [rax],dil
  00000000000000DB: EB 36              jmp         0000000000000113
  00000000000000DD: 48 8B C3           mov         rax,rbx
  00000000000000E0: C6 03 00           mov         byte ptr [rbx],0
  00000000000000E3: EB 2E              jmp         0000000000000113
  00000000000000E5: 48 8B CB           mov         rcx,rbx
  00000000000000E8: 48 85 F6           test        rsi,rsi
  00000000000000EB: 74 0F              je          00000000000000FC
  00000000000000ED: 48 03 4B 10        add         rcx,qword ptr [rbx+10h]
  00000000000000F1: 4C 8B C6           mov         r8,rsi
  00000000000000F4: 48 8B D5           mov         rdx,rbp
  00000000000000F7: E8 00 00 00 00     call        memcpy
  00000000000000FC: 48 89 7B 10        mov         qword ptr [rbx+10h],rdi
  0000000000000100: 48 83 7B 18 10     cmp         qword ptr [rbx+18h],10h
  0000000000000105: 72 05              jb          000000000000010C
  0000000000000107: 48 8B 03           mov         rax,qword ptr [rbx]
  000000000000010A: EB 03              jmp         000000000000010F
  000000000000010C: 48 8B C3           mov         rax,rbx
  000000000000010F: C6 04 38 00        mov         byte ptr [rax+rdi],0
  0000000000000113: 48 8B 7C 24 30     mov         rdi,qword ptr [rsp+30h]
  0000000000000118: 48 8B C3           mov         rax,rbx
  000000000000011B: 48 8B 5C 24 38     mov         rbx,qword ptr [rsp+38h]
  0000000000000120: 48 8B 6C 24 40     mov         rbp,qword ptr [rsp+40h]
  0000000000000125: 48 83 C4 20        add         rsp,20h
  0000000000000129: 5E                 pop         rsi
  000000000000012A: C3                 ret
  000000000000012B: 48 8D 0D 00 00 00  lea         rcx,[??_C@_0BA@JFNIOLAK@string?5too?5long?$AA@]
                    00
  0000000000000132: E8 00 00 00 00     call        ?_Xlength_error@std@@YAXPEBD@Z
  0000000000000137: CC                 int         3
  0000000000000138: 48 8D 0D 00 00 00  lea         rcx,[??_C@_0BA@JFNIOLAK@string?5too?5long?$AA@]
                    00
  000000000000013F: E8 00 00 00 00     call        ?_Xlength_error@std@@YAXPEBD@Z
  0000000000000144: CC                 int         3

  000000000000004F: 48 8D 54 24 30     lea         rdx,[rsp+30h]
  0000000000000054: 48 8B CE           mov         rcx,rsi
  0000000000000057: E8 00 00 00 00     call        replaced
  0000000000000000: 40 53              push        rbx
  0000000000000002: 48 83 EC 30        sub         rsp,30h
  0000000000000006: 44 8B 01           mov         r8d,dword ptr [rcx]
  0000000000000009: 48 8B DA           mov         rbx,rdx
  000000000000000C: 48 8B 49 08        mov         rcx,qword ptr [rcx+8]
  0000000000000010: C7 44 24 20 00 00  mov         dword ptr [rsp+20h],0
                    00 00
  0000000000000018: 48 8B 01           mov         rax,qword ptr [rcx]
  000000000000001B: FF 50 10           call        qword ptr [rax+10h]
  000000000000001E: 48 8B C3           mov         rax,rbx
  0000000000000021: 48 83 C4 30        add         rsp,30h
  0000000000000025: 5B                 pop         rbx
  0000000000000026: C3                 ret

  000000000000005C: 90                 nop
  000000000000005D: 49 83 C9 FF        or          r9,0FFFFFFFFFFFFFFFFh
  0000000000000061: 45 33 C0           xor         r8d,r8d
  0000000000000064: 48 8B D0           mov         rdx,rax
  0000000000000067: 48 8B CB           mov         rcx,rbx
  000000000000006A: E8 00 00 00 00     call        replaced
  0000000000000000: 48 89 5C 24 10     mov         qword ptr [rsp+10h],rbx
  0000000000000005: 48 89 6C 24 18     mov         qword ptr [rsp+18h],rbp
  000000000000000A: 48 89 74 24 20     mov         qword ptr [rsp+20h],rsi
  000000000000000F: 41 56              push        r14
  0000000000000011: 48 83 EC 20        sub         rsp,20h
  0000000000000015: 48 8B 42 10        mov         rax,qword ptr [rdx+10h]
  0000000000000019: 49 8B F1           mov         rsi,r9
  000000000000001C: 49 8B E8           mov         rbp,r8
  000000000000001F: 4C 8B F2           mov         r14,rdx
  0000000000000022: 48 8B D9           mov         rbx,rcx
  0000000000000025: 49 3B C0           cmp         rax,r8
  0000000000000028: 0F 82 D0 00 00 00  jb          00000000000000FE
  000000000000002E: 49 2B C0           sub         rax,r8
  0000000000000031: 4C 8B 41 10        mov         r8,qword ptr [rcx+10h]
  0000000000000035: 49 3B C1           cmp         rax,r9
  0000000000000038: 48 0F 42 F0        cmovb       rsi,rax
  000000000000003C: 48 83 C8 FF        or          rax,0FFFFFFFFFFFFFFFFh
  0000000000000040: 49 2B C0           sub         rax,r8
  0000000000000043: 48 3B C6           cmp         rax,rsi
  0000000000000046: 0F 86 BF 00 00 00  jbe         000000000000010B
  000000000000004C: 48 89 7C 24 30     mov         qword ptr [rsp+30h],rdi
  0000000000000051: 48 85 F6           test        rsi,rsi
  0000000000000054: 0F 84 86 00 00 00  je          00000000000000E0
  000000000000005A: 49 8D 3C 30        lea         rdi,[r8+rsi]
  000000000000005E: 48 83 FF FE        cmp         rdi,0FFFFFFFFFFFFFFFEh
  0000000000000062: 0F 87 B0 00 00 00  ja          0000000000000118
  0000000000000068: 48 39 79 18        cmp         qword ptr [rcx+18h],rdi
  000000000000006C: 73 23              jae         0000000000000091
  000000000000006E: 48 8B D7           mov         rdx,rdi
  0000000000000071: E8 00 00 00 00     call        replaced
  0000000000000000: 4C 89 44 24 18     mov         qword ptr [rsp+18h],r8
  0000000000000005: 48 89 54 24 10     mov         qword ptr [rsp+10h],rdx
  000000000000000A: 48 89 4C 24 08     mov         qword ptr [rsp+8],rcx
  000000000000000F: 53                 push        rbx
  0000000000000010: 56                 push        rsi
  0000000000000011: 57                 push        rdi
  0000000000000012: 41 56              push        r14
  0000000000000014: 48 83 EC 38        sub         rsp,38h
  0000000000000018: 48 C7 44 24 20 FE  mov         qword ptr [rsp+20h],0FFFFFFFFFFFFFFFEh
                    FF FF FF
  0000000000000021: 49 8B F0           mov         rsi,r8
  0000000000000024: 48 8B D9           mov         rbx,rcx
  0000000000000027: 48 8B FA           mov         rdi,rdx
  000000000000002A: 48 83 CF 0F        or          rdi,0Fh
  000000000000002E: 48 83 FF FE        cmp         rdi,0FFFFFFFFFFFFFFFEh
  0000000000000032: 76 05              jbe         0000000000000039
  0000000000000034: 48 8B FA           mov         rdi,rdx
  0000000000000037: EB 35              jmp         000000000000006E
  0000000000000039: 4C 8B 41 18        mov         r8,qword ptr [rcx+18h]
  000000000000003D: 49 8B C8           mov         rcx,r8
  0000000000000040: 48 D1 E9           shr         rcx,1
  0000000000000043: 48 B8 AB AA AA AA  mov         rax,0AAAAAAAAAAAAAAABh
                    AA AA AA AA
  000000000000004D: 48 F7 E7           mul         rax,rdi
  0000000000000050: 48 D1 EA           shr         rdx,1
  0000000000000053: 48 3B CA           cmp         rcx,rdx
  0000000000000056: 76 16              jbe         000000000000006E
  0000000000000058: 48 C7 C7 FE FF FF  mov         rdi,0FFFFFFFFFFFFFFFEh
                    FF
  000000000000005F: 48 8B C7           mov         rax,rdi
  0000000000000062: 48 2B C1           sub         rax,rcx
  0000000000000065: 4C 3B C0           cmp         r8,rax
  0000000000000068: 77 04              ja          000000000000006E
  000000000000006A: 4A 8D 3C 01        lea         rdi,[rcx+r8]
  000000000000006E: 48 8D 57 01        lea         rdx,[rdi+1]
  0000000000000072: 48 8B CB           mov         rcx,rbx
  0000000000000075: E8 00 00 00 00     call        replaced
  0000000000000000: 48 83 EC 28        sub         rsp,28h
  0000000000000004: 48 85 D2           test        rdx,rdx
  0000000000000007: 75 07              jne         0000000000000010
  0000000000000009: 33 C0              xor         eax,eax
  000000000000000B: 48 83 C4 28        add         rsp,28h
  000000000000000F: C3                 ret
  0000000000000010: 48 83 FA FF        cmp         rdx,0FFFFFFFFFFFFFFFFh
  0000000000000014: 77 3F              ja          0000000000000055
  0000000000000016: 48 81 FA 00 10 00  cmp         rdx,1000h
                    00
  000000000000001D: 72 27              jb          0000000000000046
  000000000000001F: 48 8D 4A 27        lea         rcx,[rdx+27h]
  0000000000000023: 48 3B CA           cmp         rcx,rdx
  0000000000000026: 76 33              jbe         000000000000005B
  0000000000000028: E8 00 00 00 00     call        ??2@YAPEAX_K@Z
  000000000000002D: 48 8B C8           mov         rcx,rax
  0000000000000030: 48 85 C0           test        rax,rax
  0000000000000033: 74 2C              je          0000000000000061
  0000000000000035: 48 83 C0 27        add         rax,27h
  0000000000000039: 48 83 E0 E0        and         rax,0FFFFFFFFFFFFFFE0h
  000000000000003D: 48 89 48 F8        mov         qword ptr [rax-8],rcx
  0000000000000041: 48 83 C4 28        add         rsp,28h
  0000000000000045: C3                 ret
  0000000000000046: 48 8B CA           mov         rcx,rdx
  0000000000000049: E8 00 00 00 00     call        ??2@YAPEAX_K@Z
  000000000000004E: 48 85 C0           test        rax,rax
  0000000000000051: 75 B8              jne         000000000000000B
  0000000000000053: EB 12              jmp         0000000000000067
  0000000000000055: E8 00 00 00 00     call        ?_Xbad_alloc@std@@YAXXZ
  000000000000005A: CC                 int         3
  000000000000005B: E8 00 00 00 00     call        ?_Xbad_alloc@std@@YAXXZ
  0000000000000060: CC                 int         3
  0000000000000061: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000066: CC                 int         3
  0000000000000067: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  000000000000006C: CC                 int         3

  000000000000007A: 4C 8B F0           mov         r14,rax
  000000000000007D: EB 14              jmp         0000000000000093
$LN19:
  000000000000007F: 48 8B 5C 24 60     mov         rbx,qword ptr [rsp+60h]
  0000000000000084: 48 8B 74 24 70     mov         rsi,qword ptr [rsp+70h]
  0000000000000089: 48 8B 7C 24 68     mov         rdi,qword ptr [rsp+68h]
  000000000000008E: 4C 8B 74 24 78     mov         r14,qword ptr [rsp+78h]
  0000000000000093: 48 85 F6           test        rsi,rsi
  0000000000000096: 74 1F              je          00000000000000B7
  0000000000000098: 48 83 7B 18 10     cmp         qword ptr [rbx+18h],10h
  000000000000009D: 72 05              jb          00000000000000A4
  000000000000009F: 48 8B 13           mov         rdx,qword ptr [rbx]
  00000000000000A2: EB 03              jmp         00000000000000A7
  00000000000000A4: 48 8B D3           mov         rdx,rbx
  00000000000000A7: 48 85 F6           test        rsi,rsi
  00000000000000AA: 74 0B              je          00000000000000B7
  00000000000000AC: 4C 8B C6           mov         r8,rsi
  00000000000000AF: 49 8B CE           mov         rcx,r14
  00000000000000B2: E8 00 00 00 00     call        memcpy
  00000000000000B7: 4C 8B 43 18        mov         r8,qword ptr [rbx+18h]
  00000000000000BB: 49 83 F8 10        cmp         r8,10h
  00000000000000BF: 72 0E              jb          00000000000000CF
  00000000000000C1: 49 FF C0           inc         r8
  00000000000000C4: 48 8B 13           mov         rdx,qword ptr [rbx]
  00000000000000C7: 48 8B CB           mov         rcx,rbx
  00000000000000CA: E8 00 00 00 00     call        replaced
  0000000000000000: 48 83 EC 28        sub         rsp,28h
  0000000000000004: 49 83 F8 FF        cmp         r8,0FFFFFFFFFFFFFFFFh
  0000000000000008: 77 35              ja          000000000000003F
  000000000000000A: 49 81 F8 00 10 00  cmp         r8,1000h
                    00
  0000000000000011: 72 20              jb          0000000000000033
  0000000000000013: F6 C2 1F           test        dl,1Fh
  0000000000000016: 75 2D              jne         0000000000000045
  0000000000000018: 48 8B 42 F8        mov         rax,qword ptr [rdx-8]
  000000000000001C: 48 3B C2           cmp         rax,rdx
  000000000000001F: 73 2A              jae         000000000000004B
  0000000000000021: 48 2B D0           sub         rdx,rax
  0000000000000024: 48 83 FA 08        cmp         rdx,8
  0000000000000028: 72 27              jb          0000000000000051
  000000000000002A: 48 83 FA 27        cmp         rdx,27h
  000000000000002E: 77 27              ja          0000000000000057
  0000000000000030: 48 8B D0           mov         rdx,rax
  0000000000000033: 48 8B CA           mov         rcx,rdx
  0000000000000036: 48 83 C4 28        add         rsp,28h
  000000000000003A: E9 00 00 00 00     jmp         ??3@YAXPEAX@Z
  000000000000003F: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000044: CC                 int         3
  0000000000000045: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  000000000000004A: CC                 int         3
  000000000000004B: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000050: CC                 int         3
  0000000000000051: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000056: CC                 int         3
  0000000000000057: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  000000000000005C: CC                 int         3

  00000000000000CF: 48 C7 43 18 0F 00  mov         qword ptr [rbx+18h],0Fh
                    00 00
  00000000000000D7: 48 C7 43 10 00 00  mov         qword ptr [rbx+10h],0
                    00 00
  00000000000000DF: 48 83 7B 18 10     cmp         qword ptr [rbx+18h],10h
  00000000000000E4: 72 05              jb          00000000000000EB
  00000000000000E6: 48 8B 03           mov         rax,qword ptr [rbx]
  00000000000000E9: EB 03              jmp         00000000000000EE
  00000000000000EB: 48 8B C3           mov         rax,rbx
  00000000000000EE: C6 00 00           mov         byte ptr [rax],0
  00000000000000F1: 4C 89 33           mov         qword ptr [rbx],r14
  00000000000000F4: 48 89 7B 18        mov         qword ptr [rbx+18h],rdi
  00000000000000F8: 48 89 73 10        mov         qword ptr [rbx+10h],rsi
  00000000000000FC: 48 83 7B 18 10     cmp         qword ptr [rbx+18h],10h
  0000000000000101: 72 03              jb          0000000000000106
  0000000000000103: 49 8B DE           mov         rbx,r14
  0000000000000106: C6 04 33 00        mov         byte ptr [rbx+rsi],0
  000000000000010A: 48 83 C4 38        add         rsp,38h
  000000000000010E: 41 5E              pop         r14
  0000000000000110: 5F                 pop         rdi
  0000000000000111: 5E                 pop         rsi
  0000000000000112: 5B                 pop         rbx
  0000000000000113: C3                 ret

  0000000000000076: 48 85 FF           test        rdi,rdi
  0000000000000079: 74 65              je          00000000000000E0
  000000000000007B: 49 83 7E 18 10     cmp         qword ptr [r14+18h],10h
  0000000000000080: 72 03              jb          0000000000000085
  0000000000000082: 4D 8B 36           mov         r14,qword ptr [r14]
  0000000000000085: 48 83 7B 18 10     cmp         qword ptr [rbx+18h],10h
  000000000000008A: 72 25              jb          00000000000000B1
  000000000000008C: 48 8B 0B           mov         rcx,qword ptr [rbx]
  000000000000008F: EB 23              jmp         00000000000000B4
  0000000000000091: 48 85 FF           test        rdi,rdi
  0000000000000094: 75 E5              jne         000000000000007B
  0000000000000096: 48 89 79 10        mov         qword ptr [rcx+10h],rdi
  000000000000009A: 48 83 79 18 10     cmp         qword ptr [rcx+18h],10h
  000000000000009F: 72 08              jb          00000000000000A9
  00000000000000A1: 48 8B 01           mov         rax,qword ptr [rcx]
  00000000000000A4: 40 88 38           mov         byte ptr [rax],dil
  00000000000000A7: EB 37              jmp         00000000000000E0
  00000000000000A9: 48 8B C1           mov         rax,rcx
  00000000000000AC: C6 01 00           mov         byte ptr [rcx],0
  00000000000000AF: EB 2F              jmp         00000000000000E0
  00000000000000B1: 48 8B CB           mov         rcx,rbx
  00000000000000B4: 48 85 F6           test        rsi,rsi
  00000000000000B7: 74 10              je          00000000000000C9
  00000000000000B9: 48 03 4B 10        add         rcx,qword ptr [rbx+10h]
  00000000000000BD: 49 8D 14 2E        lea         rdx,[r14+rbp]
  00000000000000C1: 4C 8B C6           mov         r8,rsi
  00000000000000C4: E8 00 00 00 00     call        memcpy
  00000000000000C9: 48 89 7B 10        mov         qword ptr [rbx+10h],rdi
  00000000000000CD: 48 83 7B 18 10     cmp         qword ptr [rbx+18h],10h
  00000000000000D2: 72 05              jb          00000000000000D9
  00000000000000D4: 48 8B 03           mov         rax,qword ptr [rbx]
  00000000000000D7: EB 03              jmp         00000000000000DC
  00000000000000D9: 48 8B C3           mov         rax,rbx
  00000000000000DC: C6 04 38 00        mov         byte ptr [rax+rdi],0
  00000000000000E0: 48 8B 7C 24 30     mov         rdi,qword ptr [rsp+30h]
  00000000000000E5: 48 8B C3           mov         rax,rbx
  00000000000000E8: 48 8B 5C 24 38     mov         rbx,qword ptr [rsp+38h]
  00000000000000ED: 48 8B 6C 24 40     mov         rbp,qword ptr [rsp+40h]
  00000000000000F2: 48 8B 74 24 48     mov         rsi,qword ptr [rsp+48h]
  00000000000000F7: 48 83 C4 20        add         rsp,20h
  00000000000000FB: 41 5E              pop         r14
  00000000000000FD: C3                 ret
  00000000000000FE: 48 8D 0D 00 00 00  lea         rcx,[??_C@_0BI@CFPLBAOH@invalid?5string?5position?$AA@]
                    00
  0000000000000105: E8 00 00 00 00     call        ?_Xout_of_range@std@@YAXPEBD@Z
  000000000000010A: CC                 int         3
  000000000000010B: 48 8D 0D 00 00 00  lea         rcx,[??_C@_0BA@JFNIOLAK@string?5too?5long?$AA@]
                    00
  0000000000000112: E8 00 00 00 00     call        ?_Xlength_error@std@@YAXPEBD@Z
  0000000000000117: CC                 int         3
  0000000000000118: 48 8D 0D 00 00 00  lea         rcx,[??_C@_0BA@JFNIOLAK@string?5too?5long?$AA@]
                    00
  000000000000011F: E8 00 00 00 00     call        ?_Xlength_error@std@@YAXPEBD@Z
  0000000000000124: CC                 int         3

  000000000000006F: 90                 nop
  0000000000000070: 4C 8B 44 24 48     mov         r8,qword ptr [rsp+48h]
  0000000000000075: 49 83 F8 10        cmp         r8,10h
  0000000000000079: 72 12              jb          000000000000008D
  000000000000007B: 49 FF C0           inc         r8
  000000000000007E: 48 8B 54 24 30     mov         rdx,qword ptr [rsp+30h]
  0000000000000083: 48 8D 4C 24 30     lea         rcx,[rsp+30h]
  0000000000000088: E8 00 00 00 00     call        replaced
  0000000000000000: 48 83 EC 28        sub         rsp,28h
  0000000000000004: 49 83 F8 FF        cmp         r8,0FFFFFFFFFFFFFFFFh
  0000000000000008: 77 35              ja          000000000000003F
  000000000000000A: 49 81 F8 00 10 00  cmp         r8,1000h
                    00
  0000000000000011: 72 20              jb          0000000000000033
  0000000000000013: F6 C2 1F           test        dl,1Fh
  0000000000000016: 75 2D              jne         0000000000000045
  0000000000000018: 48 8B 42 F8        mov         rax,qword ptr [rdx-8]
  000000000000001C: 48 3B C2           cmp         rax,rdx
  000000000000001F: 73 2A              jae         000000000000004B
  0000000000000021: 48 2B D0           sub         rdx,rax
  0000000000000024: 48 83 FA 08        cmp         rdx,8
  0000000000000028: 72 27              jb          0000000000000051
  000000000000002A: 48 83 FA 27        cmp         rdx,27h
  000000000000002E: 77 27              ja          0000000000000057
  0000000000000030: 48 8B D0           mov         rdx,rax
  0000000000000033: 48 8B CA           mov         rcx,rdx
  0000000000000036: 48 83 C4 28        add         rsp,28h
  000000000000003A: E9 00 00 00 00     jmp         ??3@YAXPEAX@Z
  000000000000003F: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000044: CC                 int         3
  0000000000000045: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  000000000000004A: CC                 int         3
  000000000000004B: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000050: CC                 int         3
  0000000000000051: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000056: CC                 int         3
  0000000000000057: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  000000000000005C: CC                 int         3

  000000000000008D: 48 C7 47 18 0F 00  mov         qword ptr [rdi+18h],0Fh
                    00 00
  0000000000000095: 48 C7 47 10 00 00  mov         qword ptr [rdi+10h],0
                    00 00
  000000000000009D: 48 83 7F 18 10     cmp         qword ptr [rdi+18h],10h
  00000000000000A2: 72 05              jb          00000000000000A9
  00000000000000A4: 48 8B 07           mov         rax,qword ptr [rdi]
  00000000000000A7: EB 03              jmp         00000000000000AC
  00000000000000A9: 48 8B C7           mov         rax,rdi
  00000000000000AC: C6 00 00           mov         byte ptr [rax],0
  00000000000000AF: 48 8B D3           mov         rdx,rbx
  00000000000000B2: 48 8B CF           mov         rcx,rdi
  00000000000000B5: E8 00 00 00 00     call        replaced
  0000000000000000: 48 89 5C 24 08     mov         qword ptr [rsp+8],rbx
  0000000000000005: 57                 push        rdi
  0000000000000006: 48 83 EC 20        sub         rsp,20h
  000000000000000A: 48 83 7A 18 10     cmp         qword ptr [rdx+18h],10h
  000000000000000F: 48 8B DA           mov         rbx,rdx
  0000000000000012: 48 8B F9           mov         rdi,rcx
  0000000000000015: 73 11              jae         0000000000000028
  0000000000000017: 4C 8B 42 10        mov         r8,qword ptr [rdx+10h]
  000000000000001B: 49 83 C0 01        add         r8,1
  000000000000001F: 74 19              je          000000000000003A
  0000000000000021: E8 00 00 00 00     call        memmove
  0000000000000026: EB 12              jmp         000000000000003A
  0000000000000028: 48 85 C9           test        rcx,rcx
  000000000000002B: 74 06              je          0000000000000033
  000000000000002D: 48 8B 02           mov         rax,qword ptr [rdx]
  0000000000000030: 48 89 01           mov         qword ptr [rcx],rax
  0000000000000033: 48 C7 02 00 00 00  mov         qword ptr [rdx],0
                    00
  000000000000003A: 48 8B 43 10        mov         rax,qword ptr [rbx+10h]
  000000000000003E: 48 89 47 10        mov         qword ptr [rdi+10h],rax
  0000000000000042: 48 8B 43 18        mov         rax,qword ptr [rbx+18h]
  0000000000000046: 48 89 47 18        mov         qword ptr [rdi+18h],rax
  000000000000004A: 48 C7 43 18 0F 00  mov         qword ptr [rbx+18h],0Fh
                    00 00
  0000000000000052: 48 C7 43 10 00 00  mov         qword ptr [rbx+10h],0
                    00 00
  000000000000005A: 48 83 7B 18 10     cmp         qword ptr [rbx+18h],10h
  000000000000005F: 72 11              jb          0000000000000072
  0000000000000061: 48 8B 03           mov         rax,qword ptr [rbx]
  0000000000000064: C6 00 00           mov         byte ptr [rax],0
  0000000000000067: 48 8B 5C 24 30     mov         rbx,qword ptr [rsp+30h]
  000000000000006C: 48 83 C4 20        add         rsp,20h
  0000000000000070: 5F                 pop         rdi
  0000000000000071: C3                 ret
  0000000000000072: C6 03 00           mov         byte ptr [rbx],0
  0000000000000075: 48 8B 5C 24 30     mov         rbx,qword ptr [rsp+30h]
  000000000000007A: 48 83 C4 20        add         rsp,20h
  000000000000007E: 5F                 pop         rdi
  000000000000007F: C3                 ret

  00000000000000BA: 90                 nop
  00000000000000BB: 4C 8B 43 18        mov         r8,qword ptr [rbx+18h]
  00000000000000BF: 49 83 F8 10        cmp         r8,10h
  00000000000000C3: 72 0E              jb          00000000000000D3
  00000000000000C5: 49 FF C0           inc         r8
  00000000000000C8: 48 8B 13           mov         rdx,qword ptr [rbx]
  00000000000000CB: 48 8B CB           mov         rcx,rbx
  00000000000000CE: E8 00 00 00 00     call        replaced
  0000000000000000: 48 83 EC 28        sub         rsp,28h
  0000000000000004: 49 83 F8 FF        cmp         r8,0FFFFFFFFFFFFFFFFh
  0000000000000008: 77 35              ja          000000000000003F
  000000000000000A: 49 81 F8 00 10 00  cmp         r8,1000h
                    00
  0000000000000011: 72 20              jb          0000000000000033
  0000000000000013: F6 C2 1F           test        dl,1Fh
  0000000000000016: 75 2D              jne         0000000000000045
  0000000000000018: 48 8B 42 F8        mov         rax,qword ptr [rdx-8]
  000000000000001C: 48 3B C2           cmp         rax,rdx
  000000000000001F: 73 2A              jae         000000000000004B
  0000000000000021: 48 2B D0           sub         rdx,rax
  0000000000000024: 48 83 FA 08        cmp         rdx,8
  0000000000000028: 72 27              jb          0000000000000051
  000000000000002A: 48 83 FA 27        cmp         rdx,27h
  000000000000002E: 77 27              ja          0000000000000057
  0000000000000030: 48 8B D0           mov         rdx,rax
  0000000000000033: 48 8B CA           mov         rcx,rdx
  0000000000000036: 48 83 C4 28        add         rsp,28h
  000000000000003A: E9 00 00 00 00     jmp         ??3@YAXPEAX@Z
  000000000000003F: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000044: CC                 int         3
  0000000000000045: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  000000000000004A: CC                 int         3
  000000000000004B: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000050: CC                 int         3
  0000000000000051: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000056: CC                 int         3
  0000000000000057: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  000000000000005C: CC                 int         3

  00000000000000D3: 48 C7 43 18 0F 00  mov         qword ptr [rbx+18h],0Fh
                    00 00
  00000000000000DB: 48 C7 43 10 00 00  mov         qword ptr [rbx+10h],0
                    00 00
  00000000000000E3: 48 83 7B 18 10     cmp         qword ptr [rbx+18h],10h
  00000000000000E8: 72 08              jb          00000000000000F2
  00000000000000EA: 48 8B 03           mov         rax,qword ptr [rbx]
  00000000000000ED: C6 00 00           mov         byte ptr [rax],0
  00000000000000F0: EB 03              jmp         00000000000000F5
  00000000000000F2: C6 03 00           mov         byte ptr [rbx],0
  00000000000000F5: 48 8B C7           mov         rax,rdi
  00000000000000F8: 48 8B 5C 24 60     mov         rbx,qword ptr [rsp+60h]
  00000000000000FD: 48 8B 74 24 68     mov         rsi,qword ptr [rsp+68h]
  0000000000000102: 48 83 C4 50        add         rsp,50h
  0000000000000106: 5F                 pop         rdi
  0000000000000107: C3                 ret

  0000000000000092: 48 83 78 18 10     cmp         qword ptr [rax+18h],10h
  0000000000000097: 72 03              jb          000000000000009C
  0000000000000099: 48 8B 00           mov         rax,qword ptr [rax]
  000000000000009C: 48 8D 0D 00 00 00  lea         rcx,[??_7exception@std@@6B@]
                    00
  00000000000000A3: 48 89 0F           mov         qword ptr [rdi],rcx
  00000000000000A6: 48 8D 57 08        lea         rdx,[rdi+8]
  00000000000000AA: 33 C9              xor         ecx,ecx
  00000000000000AC: 48 89 0A           mov         qword ptr [rdx],rcx
  00000000000000AF: 48 89 4A 08        mov         qword ptr [rdx+8],rcx
  00000000000000B3: 48 89 45 D7        mov         qword ptr [rbp-29h],rax
  00000000000000B7: C6 45 DF 01        mov         byte ptr [rbp-21h],1
  00000000000000BB: 48 8D 4D D7        lea         rcx,[rbp-29h]
  00000000000000BF: E8 00 00 00 00     call        __std_exception_copy
  00000000000000C4: 48 8D 05 00 00 00  lea         rax,[??_7runtime_error@std@@6B@]
                    00
  00000000000000CB: 48 89 07           mov         qword ptr [rdi],rax
  00000000000000CE: 4C 8B 45 3F        mov         r8,qword ptr [rbp+3Fh]
  00000000000000D2: 49 83 F8 10        cmp         r8,10h
  00000000000000D6: 72 10              jb          00000000000000E8
  00000000000000D8: 49 FF C0           inc         r8
  00000000000000DB: 48 8B 55 27        mov         rdx,qword ptr [rbp+27h]
  00000000000000DF: 48 8D 4D 27        lea         rcx,[rbp+27h]
  00000000000000E3: E8 00 00 00 00     call        replaced
  0000000000000000: 48 83 EC 28        sub         rsp,28h
  0000000000000004: 49 83 F8 FF        cmp         r8,0FFFFFFFFFFFFFFFFh
  0000000000000008: 77 35              ja          000000000000003F
  000000000000000A: 49 81 F8 00 10 00  cmp         r8,1000h
                    00
  0000000000000011: 72 20              jb          0000000000000033
  0000000000000013: F6 C2 1F           test        dl,1Fh
  0000000000000016: 75 2D              jne         0000000000000045
  0000000000000018: 48 8B 42 F8        mov         rax,qword ptr [rdx-8]
  000000000000001C: 48 3B C2           cmp         rax,rdx
  000000000000001F: 73 2A              jae         000000000000004B
  0000000000000021: 48 2B D0           sub         rdx,rax
  0000000000000024: 48 83 FA 08        cmp         rdx,8
  0000000000000028: 72 27              jb          0000000000000051
  000000000000002A: 48 83 FA 27        cmp         rdx,27h
  000000000000002E: 77 27              ja          0000000000000057
  0000000000000030: 48 8B D0           mov         rdx,rax
  0000000000000033: 48 8B CA           mov         rcx,rdx
  0000000000000036: 48 83 C4 28        add         rsp,28h
  000000000000003A: E9 00 00 00 00     jmp         ??3@YAXPEAX@Z
  000000000000003F: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000044: CC                 int         3
  0000000000000045: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  000000000000004A: CC                 int         3
  000000000000004B: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000050: CC                 int         3
  0000000000000051: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000056: CC                 int         3
  0000000000000057: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  000000000000005C: CC                 int         3

  00000000000000E8: 48 8D 05 00 00 00  lea         rax,[??_7_System_error@std@@6B@]
                    00
  00000000000000EF: 48 89 07           mov         qword ptr [rdi],rax
  00000000000000F2: 0F 11 77 18        movups      xmmword ptr [rdi+18h],xmm6
  00000000000000F6: 4C 8B 45 FF        mov         r8,qword ptr [rbp-1]
  00000000000000FA: 49 83 F8 10        cmp         r8,10h
  00000000000000FE: 72 10              jb          0000000000000110
  0000000000000100: 49 FF C0           inc         r8
  0000000000000103: 48 8B 55 E7        mov         rdx,qword ptr [rbp-19h]
  0000000000000107: 48 8D 4D E7        lea         rcx,[rbp-19h]
  000000000000010B: E8 00 00 00 00     call        replaced
  0000000000000000: 48 83 EC 28        sub         rsp,28h
  0000000000000004: 49 83 F8 FF        cmp         r8,0FFFFFFFFFFFFFFFFh
  0000000000000008: 77 35              ja          000000000000003F
  000000000000000A: 49 81 F8 00 10 00  cmp         r8,1000h
                    00
  0000000000000011: 72 20              jb          0000000000000033
  0000000000000013: F6 C2 1F           test        dl,1Fh
  0000000000000016: 75 2D              jne         0000000000000045
  0000000000000018: 48 8B 42 F8        mov         rax,qword ptr [rdx-8]
  000000000000001C: 48 3B C2           cmp         rax,rdx
  000000000000001F: 73 2A              jae         000000000000004B
  0000000000000021: 48 2B D0           sub         rdx,rax
  0000000000000024: 48 83 FA 08        cmp         rdx,8
  0000000000000028: 72 27              jb          0000000000000051
  000000000000002A: 48 83 FA 27        cmp         rdx,27h
  000000000000002E: 77 27              ja          0000000000000057
  0000000000000030: 48 8B D0           mov         rdx,rax
  0000000000000033: 48 8B CA           mov         rcx,rdx
  0000000000000036: 48 83 C4 28        add         rsp,28h
  000000000000003A: E9 00 00 00 00     jmp         ??3@YAXPEAX@Z
  000000000000003F: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000044: CC                 int         3
  0000000000000045: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  000000000000004A: CC                 int         3
  000000000000004B: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000050: CC                 int         3
  0000000000000051: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000056: CC                 int         3
  0000000000000057: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  000000000000005C: CC                 int         3

  0000000000000110: 48 8D 05 00 00 00  lea         rax,[??_7system_error@std@@6B@]
                    00
  0000000000000117: 48 89 07           mov         qword ptr [rdi],rax
  000000000000011A: 48 8B C7           mov         rax,rdi
  000000000000011D: 4C 8D 9C 24 B0 00  lea         r11,[rsp+0B0h]
                    00 00
  0000000000000125: 49 8B 5B 18        mov         rbx,qword ptr [r11+18h]
  0000000000000129: 49 8B 7B 20        mov         rdi,qword ptr [r11+20h]
  000000000000012D: 41 0F 28 73 F0     movaps      xmm6,xmmword ptr [r11-10h]
  0000000000000132: 49 8B E3           mov         rsp,r11
  0000000000000135: 5D                 pop         rbp
  0000000000000136: C3                 ret

  00000000000001FD: 90                 nop
  00000000000001FE: 0F B6 4C 24 30     movzx       ecx,byte ptr [rsp+30h]
  0000000000000203: 83 E9 01           sub         ecx,1
  0000000000000206: 74 14              je          000000000000021C
  0000000000000208: 83 E9 01           sub         ecx,1
  000000000000020B: 74 0F              je          000000000000021C
  000000000000020D: 83 F9 01           cmp         ecx,1
  0000000000000210: 75 0F              jne         0000000000000221
  0000000000000212: 48 8D 4C 24 20     lea         rcx,[rsp+20h]
  0000000000000217: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  000000000000021C: C6 44 24 30 00     mov         byte ptr [rsp+30h],0
  0000000000000221: 48 8D 1D 00 00 00  lea         rbx,[??_7exception@std@@6B@]
                    00
  0000000000000228: 48 89 5D 20        mov         qword ptr [rbp+20h],rbx
  000000000000022C: 33 C0              xor         eax,eax
  000000000000022E: 48 89 45 28        mov         qword ptr [rbp+28h],rax
  0000000000000232: 48 89 45 30        mov         qword ptr [rbp+30h],rax
  0000000000000236: 48 8D 55 28        lea         rdx,[rbp+28h]
  000000000000023A: 48 8D 4D 78        lea         rcx,[rbp+78h]
  000000000000023E: E8 00 00 00 00     call        __std_exception_copy
  0000000000000243: 0F 10 85 88 00 00  movups      xmm0,xmmword ptr [rbp+88h]
                    00
  000000000000024A: 0F 11 45 38        movups      xmmword ptr [rbp+38h],xmm0
  000000000000024E: 48 8D 05 00 00 00  lea         rax,[??_7system_error@std@@6B@]
                    00
  0000000000000255: 48 89 45 20        mov         qword ptr [rbp+20h],rax
  0000000000000259: 48 8D 15 00 00 00  lea         rdx,[_TI4?AVsystem_error@std@@]
                    00
  0000000000000260: 48 8D 4D 20        lea         rcx,[rbp+20h]
  0000000000000264: E8 00 00 00 00     call        _CxxThrowException
  0000000000000269: 90                 nop
  000000000000026A: 0F B6 44 24 30     movzx       eax,byte ptr [rsp+30h]
  000000000000026F: 2C 02              sub         al,2
  0000000000000271: 3C 01              cmp         al,1
  0000000000000273: 77 67              ja          00000000000002DC
  0000000000000275: 48 8D 54 24 20     lea         rdx,[rsp+20h]
  000000000000027A: 48 8D 4D E8        lea         rcx,[rbp-18h]
  000000000000027E: E8 00 00 00 00     call        ?__ExceptionPtrCopy@@YAXPEAXPEBX@Z
  0000000000000283: 90                 nop
  0000000000000284: 0F B6 4C 24 30     movzx       ecx,byte ptr [rsp+30h]
  0000000000000289: 83 E9 01           sub         ecx,1
  000000000000028C: 74 14              je          00000000000002A2
  000000000000028E: 83 E9 01           sub         ecx,1
  0000000000000291: 74 0F              je          00000000000002A2
  0000000000000293: 83 F9 01           cmp         ecx,1
  0000000000000296: 75 0F              jne         00000000000002A7
  0000000000000298: 48 8D 4C 24 20     lea         rcx,[rsp+20h]
  000000000000029D: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  00000000000002A2: C6 44 24 30 00     mov         byte ptr [rsp+30h],0
  00000000000002A7: 48 8D 55 E8        lea         rdx,[rbp-18h]
  00000000000002AB: 48 8D 4D A0        lea         rcx,[rbp-60h]
  00000000000002AF: E8 00 00 00 00     call        ?__ExceptionPtrCopy@@YAXPEAXPEBX@Z
  00000000000002B4: 48 8D 45 A0        lea         rax,[rbp-60h]
  00000000000002B8: 48 89 85 F8 00 00  mov         qword ptr [rbp+0F8h],rax
                    00
  00000000000002BF: 48 8D 4D A0        lea         rcx,[rbp-60h]
  00000000000002C3: E8 00 00 00 00     call        ?__ExceptionPtrRethrow@@YAXPEBX@Z
  00000000000002C8: 90                 nop
  00000000000002C9: 48 8D 4D A0        lea         rcx,[rbp-60h]
  00000000000002CD: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  00000000000002D2: 90                 nop
  00000000000002D3: 48 8D 4D E8        lea         rcx,[rbp-18h]
  00000000000002D7: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  00000000000002DC: 8B 7C 24 20        mov         edi,dword ptr [rsp+20h]
  00000000000002E0: 0F B6 4C 24 30     movzx       ecx,byte ptr [rsp+30h]
  00000000000002E5: 83 E9 01           sub         ecx,1
  00000000000002E8: 74 14              je          00000000000002FE
  00000000000002EA: 83 E9 01           sub         ecx,1
  00000000000002ED: 74 0F              je          00000000000002FE
  00000000000002EF: 83 F9 01           cmp         ecx,1
  00000000000002F2: 75 0F              jne         0000000000000303
  00000000000002F4: 48 8D 4C 24 20     lea         rcx,[rsp+20h]
  00000000000002F9: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  00000000000002FE: C6 44 24 30 00     mov         byte ptr [rsp+30h],0
  0000000000000303: 48 85 DB           test        rbx,rbx
  0000000000000306: 74 0F              je          0000000000000317
  0000000000000308: 80 7B 18 00        cmp         byte ptr [rbx+18h],0
  000000000000030C: 74 04              je          0000000000000312
  000000000000030E: C6 43 19 00        mov         byte ptr [rbx+19h],0
  0000000000000312: 48 89 74 24 48     mov         qword ptr [rsp+48h],rsi
  0000000000000317: 80 7C 24 38 00     cmp         byte ptr [rsp+38h],0
  000000000000031C: 74 05              je          0000000000000323
  000000000000031E: C6 44 24 39 00     mov         byte ptr [rsp+39h],0
  0000000000000323: 48 89 74 24 50     mov         qword ptr [rsp+50h],rsi
  0000000000000328: 48 8B 4C 24 40     mov         rcx,qword ptr [rsp+40h]
  000000000000032D: 48 85 C9           test        rcx,rcx
  0000000000000330: 75 15              jne         0000000000000347
  0000000000000332: 38 4C 24 30        cmp         byte ptr [rsp+30h],cl
  0000000000000336: 0F 95 C0           setne       al
  0000000000000339: 84 C0              test        al,al
  000000000000033B: 75 0A              jne         0000000000000347
  000000000000033D: 38 44 24 3A        cmp         byte ptr [rsp+3Ah],al
  0000000000000341: 0F 84 98 00 00 00  je          00000000000003DF
  0000000000000347: 48 8B DE           mov         rbx,rsi
  000000000000034A: 38 5C 24 38        cmp         byte ptr [rsp+38h],bl
  000000000000034E: 75 05              jne         0000000000000355
  0000000000000350: 48 8B D9           mov         rbx,rcx
  0000000000000353: EB 3E              jmp         0000000000000393
  0000000000000355: 48 8D 4C 24 39     lea         rcx,[rsp+39h]
  000000000000035A: E8 00 00 00 00     call        replaced
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

  000000000000035F: 48 8B 4C 24 40     mov         rcx,qword ptr [rsp+40h]
  0000000000000364: 48 85 C9           test        rcx,rcx
  0000000000000367: 48 8B D1           mov         rdx,rcx
  000000000000036A: 74 35              je          00000000000003A1
  000000000000036C: 0F B6 41 19        movzx       eax,byte ptr [rcx+19h]
  0000000000000370: 84 C0              test        al,al
  0000000000000372: 75 11              jne         0000000000000385
  0000000000000374: B8 01 00 00 00     mov         eax,1
  0000000000000379: 86 41 19           xchg        al,byte ptr [rcx+19h]
  000000000000037C: 84 C0              test        al,al
  000000000000037E: 0F 95 C0           setne       al
  0000000000000381: 84 C0              test        al,al
  0000000000000383: 74 06              je          000000000000038B
  0000000000000385: 88 5C 24 39        mov         byte ptr [rsp+39h],bl
  0000000000000389: EB CA              jmp         0000000000000355
  000000000000038B: 48 8B DA           mov         rbx,rdx
  000000000000038E: 48 8B 4C 24 40     mov         rcx,qword ptr [rsp+40h]
  0000000000000393: 48 85 C9           test        rcx,rcx
  0000000000000396: 74 09              je          00000000000003A1
  0000000000000398: 48 89 71 20        mov         qword ptr [rcx+20h],rsi
  000000000000039C: 48 89 74 24 40     mov         qword ptr [rsp+40h],rsi
  00000000000003A1: 0F B6 4C 24 30     movzx       ecx,byte ptr [rsp+30h]
  00000000000003A6: 83 E9 01           sub         ecx,1
  00000000000003A9: 74 14              je          00000000000003BF
  00000000000003AB: 83 E9 01           sub         ecx,1
  00000000000003AE: 74 0F              je          00000000000003BF
  00000000000003B0: 83 F9 01           cmp         ecx,1
  00000000000003B3: 75 0F              jne         00000000000003C4
  00000000000003B5: 48 8D 4C 24 20     lea         rcx,[rsp+20h]
  00000000000003BA: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  00000000000003BF: C6 44 24 30 00     mov         byte ptr [rsp+30h],0
  00000000000003C4: 48 85 DB           test        rbx,rbx
  00000000000003C7: 74 0A              je          00000000000003D3
  00000000000003C9: 80 7B 18 00        cmp         byte ptr [rbx+18h],0
  00000000000003CD: 74 04              je          00000000000003D3
  00000000000003CF: C6 43 19 00        mov         byte ptr [rbx+19h],0
  00000000000003D3: 80 7C 24 38 00     cmp         byte ptr [rsp+38h],0
  00000000000003D8: 74 05              je          00000000000003DF
  00000000000003DA: C6 44 24 39 00     mov         byte ptr [rsp+39h],0
  00000000000003DF: 0F B6 4C 24 30     movzx       ecx,byte ptr [rsp+30h]
  00000000000003E4: 83 E9 01           sub         ecx,1
  00000000000003E7: 74 14              je          00000000000003FD
  00000000000003E9: 83 E9 01           sub         ecx,1
  00000000000003EC: 74 0F              je          00000000000003FD
  00000000000003EE: 83 F9 01           cmp         ecx,1
  00000000000003F1: 75 0F              jne         0000000000000402
  00000000000003F3: 48 8D 4C 24 20     lea         rcx,[rsp+20h]
  00000000000003F8: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  00000000000003FD: C6 44 24 30 00     mov         byte ptr [rsp+30h],0
  0000000000000402: 80 7C 24 7A 00     cmp         byte ptr [rsp+7Ah],0
  0000000000000407: 0F 84 A2 00 00 00  je          00000000000004AF
  000000000000040D: 48 8B 45 80        mov         rax,qword ptr [rbp-80h]
  0000000000000411: 48 85 C0           test        rax,rax
  0000000000000414: 0F 84 95 00 00 00  je          00000000000004AF
  000000000000041A: 48 8B DE           mov         rbx,rsi
  000000000000041D: 38 5C 24 78        cmp         byte ptr [rsp+78h],bl
  0000000000000421: 75 05              jne         0000000000000428
  0000000000000423: 48 8B D8           mov         rbx,rax
  0000000000000426: EB 38              jmp         0000000000000460
  0000000000000428: 48 8D 4C 24 79     lea         rcx,[rsp+79h]
  000000000000042D: E8 00 00 00 00     call        replaced
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

  0000000000000432: 48 8B 4D 80        mov         rcx,qword ptr [rbp-80h]
  0000000000000436: 48 85 C9           test        rcx,rcx
  0000000000000439: 48 8B D1           mov         rdx,rcx
  000000000000043C: 74 2F              je          000000000000046D
  000000000000043E: 0F B6 41 19        movzx       eax,byte ptr [rcx+19h]
  0000000000000442: 84 C0              test        al,al
  0000000000000444: 75 11              jne         0000000000000457
  0000000000000446: B8 01 00 00 00     mov         eax,1
  000000000000044B: 86 41 19           xchg        al,byte ptr [rcx+19h]
  000000000000044E: 84 C0              test        al,al
  0000000000000450: 0F 95 C0           setne       al
  0000000000000453: 84 C0              test        al,al
  0000000000000455: 74 06              je          000000000000045D
  0000000000000457: 88 5C 24 79        mov         byte ptr [rsp+79h],bl
  000000000000045B: EB CB              jmp         0000000000000428
  000000000000045D: 48 8B DA           mov         rbx,rdx
  0000000000000460: 48 85 DB           test        rbx,rbx
  0000000000000463: 74 08              je          000000000000046D
  0000000000000465: C6 43 1A 01        mov         byte ptr [rbx+1Ah],1
  0000000000000469: 48 89 73 20        mov         qword ptr [rbx+20h],rsi
  000000000000046D: 48 89 75 80        mov         qword ptr [rbp-80h],rsi
  0000000000000471: 0F B6 4C 24 70     movzx       ecx,byte ptr [rsp+70h]
  0000000000000476: 83 E9 01           sub         ecx,1
  0000000000000479: 74 14              je          000000000000048F
  000000000000047B: 83 E9 01           sub         ecx,1
  000000000000047E: 74 0F              je          000000000000048F
  0000000000000480: 83 F9 01           cmp         ecx,1
  0000000000000483: 75 0F              jne         0000000000000494
  0000000000000485: 48 8D 4C 24 60     lea         rcx,[rsp+60h]
  000000000000048A: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  000000000000048F: C6 44 24 70 00     mov         byte ptr [rsp+70h],0
  0000000000000494: 80 7C 24 78 00     cmp         byte ptr [rsp+78h],0
  0000000000000499: 74 05              je          00000000000004A0
  000000000000049B: C6 44 24 79 00     mov         byte ptr [rsp+79h],0
  00000000000004A0: 48 85 DB           test        rbx,rbx
  00000000000004A3: 74 0A              je          00000000000004AF
  00000000000004A5: 80 7B 18 00        cmp         byte ptr [rbx+18h],0
  00000000000004A9: 74 04              je          00000000000004AF
  00000000000004AB: C6 43 19 00        mov         byte ptr [rbx+19h],0
  00000000000004AF: 48 8D 4C 24 60     lea         rcx,[rsp+60h]
  00000000000004B4: E8 00 00 00 00     call        replaced
  0000000000000000: 40 53              push        rbx
  0000000000000002: 48 83 EC 30        sub         rsp,30h
  0000000000000006: 48 C7 44 24 20 FE  mov         qword ptr [rsp+20h],0FFFFFFFFFFFFFFFEh
                    FF FF FF
  000000000000000F: 48 8B D9           mov         rbx,rcx
  0000000000000012: 48 83 C1 38        add         rcx,38h
  0000000000000016: 48 8B 11           mov         rdx,qword ptr [rcx]
  0000000000000019: 48 85 D2           test        rdx,rdx
  000000000000001C: 74 06              je          0000000000000024
  000000000000001E: E8 00 00 00 00     call        replaced
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

  0000000000000023: 90                 nop
  0000000000000024: 48 8B 4B 30        mov         rcx,qword ptr [rbx+30h]
  0000000000000028: 48 85 C9           test        rcx,rcx
  000000000000002B: 74 0B              je          0000000000000038
  000000000000002D: 48 8B 01           mov         rax,qword ptr [rcx]
  0000000000000030: BA 01 00 00 00     mov         edx,1
  0000000000000035: FF 10              call        qword ptr [rax]
  0000000000000037: 90                 nop
  0000000000000038: 0F B6 4B 10        movzx       ecx,byte ptr [rbx+10h]
  000000000000003C: 83 E9 01           sub         ecx,1
  000000000000003F: 74 13              je          0000000000000054
  0000000000000041: 83 E9 01           sub         ecx,1
  0000000000000044: 74 0E              je          0000000000000054
  0000000000000046: 83 F9 01           cmp         ecx,1
  0000000000000049: 75 0D              jne         0000000000000058
  000000000000004B: 48 8B CB           mov         rcx,rbx
  000000000000004E: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  0000000000000053: 90                 nop
  0000000000000054: C6 43 10 00        mov         byte ptr [rbx+10h],0
  0000000000000058: 48 83 C4 30        add         rsp,30h
  000000000000005C: 5B                 pop         rbx
  000000000000005D: C3                 ret

  00000000000004B9: 90                 nop
  00000000000004BA: 8B C7              mov         eax,edi
  00000000000004BC: 0F 28 B4 24 A0 01  movaps      xmm6,xmmword ptr [rsp+1A0h]
                    00 00
  00000000000004C4: 48 81 C4 B8 01 00  add         rsp,1B8h
                    00
  00000000000004CB: 5F                 pop         rdi
  00000000000004CC: 5E                 pop         rsi
  00000000000004CD: 5B                 pop         rbx
  00000000000004CE: 5D                 pop         rbp
  00000000000004CF: C3                 ret
