  0000000000000000: 48 8B C4           mov         rax,rsp
  0000000000000003: 55                 push        rbp
  0000000000000004: 56                 push        rsi
  0000000000000005: 57                 push        rdi
  0000000000000006: 48 8D A8 D8 FE FF  lea         rbp,[rax-128h]
                    FF
  000000000000000D: 48 81 EC 10 02 00  sub         rsp,210h
                    00
  0000000000000014: 48 C7 85 98 00 00  mov         qword ptr [rbp+98h],0FFFFFFFFFFFFFFFEh
                    00 FE FF FF FF
  000000000000001F: 48 89 58 20        mov         qword ptr [rax+20h],rbx
  0000000000000023: 0F 29 70 D8        movaps      xmmword ptr [rax-28h],xmm6
  0000000000000027: C6 44 24 60 00     mov         byte ptr [rsp+60h],0
  000000000000002C: C7 85 38 01 00 00  mov         dword ptr [rbp+138h],5
                    05 00 00 00
  0000000000000036: C7 44 24 48 05 00  mov         dword ptr [rsp+48h],5
                    00 00
  000000000000003E: C6 44 24 58 01     mov         byte ptr [rsp+58h],1
  0000000000000043: 48 8D 54 24 20     lea         rdx,[rsp+20h]
  0000000000000048: 48 8D 4C 24 48     lea         rcx,[rsp+48h]
  000000000000004D: E8 00 00 00 00     call        replaced
  0000000000000000: 48 8B C4           mov         rax,rsp
  0000000000000003: 48 89 50 10        mov         qword ptr [rax+10h],rdx
  0000000000000007: 55                 push        rbp
  0000000000000008: 57                 push        rdi
  0000000000000009: 41 56              push        r14
  000000000000000B: 48 8D 68 A1        lea         rbp,[rax-5Fh]
  000000000000000F: 48 81 EC C0 00 00  sub         rsp,0C0h
                    00
  0000000000000016: 48 C7 45 3F FE FF  mov         qword ptr [rbp+3Fh],0FFFFFFFFFFFFFFFEh
                    FF FF
  000000000000001E: 48 89 58 08        mov         qword ptr [rax+8],rbx
  0000000000000022: 48 89 70 18        mov         qword ptr [rax+18h],rsi
  0000000000000026: 48 8B F2           mov         rsi,rdx
  0000000000000029: 48 8B D9           mov         rbx,rcx
  000000000000002C: 45 33 F6           xor         r14d,r14d
  000000000000002F: 44 89 75 EF        mov         dword ptr [rbp-11h],r14d
  0000000000000033: 44 38 71 18        cmp         byte ptr [rcx+18h],r14b
  0000000000000037: 75 19              jne         0000000000000052
  0000000000000039: 44 38 71 10        cmp         byte ptr [rcx+10h],r14b
  000000000000003D: 75 13              jne         0000000000000052
  000000000000003F: C6 41 18 01        mov         byte ptr [rcx+18h],1
  0000000000000043: 48 8D 41 19        lea         rax,[rcx+19h]
  0000000000000047: 48 85 C0           test        rax,rax
  000000000000004A: 74 06              je          0000000000000052
  000000000000004C: 44 88 30           mov         byte ptr [rax],r14b
  000000000000004F: 44 88 30           mov         byte ptr [rax],r14b
  0000000000000052: 0F 57 C0           xorps       xmm0,xmm0
  0000000000000055: F3 0F 7F 45 DF     movdqu      xmmword ptr [rbp-21h],xmm0
  000000000000005A: 44 38 71 18        cmp         byte ptr [rcx+18h],r14b
  000000000000005E: 75 13              jne         0000000000000073
  0000000000000060: 48 89 4D DF        mov         qword ptr [rbp-21h],rcx
  0000000000000064: 80 79 10 04        cmp         byte ptr [rcx+10h],4
  0000000000000068: 75 49              jne         00000000000000B3
  000000000000006A: 48 8B 01           mov         rax,qword ptr [rcx]
  000000000000006D: 48 89 45 E7        mov         qword ptr [rbp-19h],rax
  0000000000000071: EB 40              jmp         00000000000000B3
  0000000000000073: 48 83 C1 19        add         rcx,19h
  0000000000000077: E8 00 00 00 00     call        replaced
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

  000000000000007C: 80 7B 10 04        cmp         byte ptr [rbx+10h],4
  0000000000000080: 75 2D              jne         00000000000000AF
  0000000000000082: 48 8B 0B           mov         rcx,qword ptr [rbx]
  0000000000000085: 0F B6 41 19        movzx       eax,byte ptr [rcx+19h]
  0000000000000089: 84 C0              test        al,al
  000000000000008B: 75 11              jne         000000000000009E
  000000000000008D: B8 01 00 00 00     mov         eax,1
  0000000000000092: 86 41 19           xchg        al,byte ptr [rcx+19h]
  0000000000000095: 84 C0              test        al,al
  0000000000000097: 0F 95 C0           setne       al
  000000000000009A: 84 C0              test        al,al
  000000000000009C: 74 0A              je          00000000000000A8
  000000000000009E: 44 88 73 19        mov         byte ptr [rbx+19h],r14b
  00000000000000A2: 48 8D 4B 19        lea         rcx,[rbx+19h]
  00000000000000A6: EB CF              jmp         0000000000000077
  00000000000000A8: 48 8B 03           mov         rax,qword ptr [rbx]
  00000000000000AB: 48 89 45 E7        mov         qword ptr [rbp-19h],rax
  00000000000000AF: 48 89 5D DF        mov         qword ptr [rbp-21h],rbx
  00000000000000B3: 48 83 7D E7 00     cmp         qword ptr [rbp-19h],0
  00000000000000B8: 74 65              je          000000000000011F
  00000000000000BA: C7 45 07 02 00 00  mov         dword ptr [rbp+7],2
                    00
  00000000000000C1: E8 00 00 00 00     call        replaced
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

  00000000000000C6: 48 89 45 0F        mov         qword ptr [rbp+0Fh],rax
  00000000000000CA: 48 8D 05 00 00 00  lea         rax,[??_7exception@std@@6B@]
                    00
  00000000000000D1: 48 89 45 17        mov         qword ptr [rbp+17h],rax
  00000000000000D5: 33 C0              xor         eax,eax
  00000000000000D7: 48 89 45 1F        mov         qword ptr [rbp+1Fh],rax
  00000000000000DB: 48 89 45 27        mov         qword ptr [rbp+27h],rax
  00000000000000DF: 48 8D 05 00 00 00  lea         rax,[??_C@_00CNPNBAHC@?$AA@]
                    00
  00000000000000E6: 48 89 45 F7        mov         qword ptr [rbp-9],rax
  00000000000000EA: C6 45 FF 01        mov         byte ptr [rbp-1],1
  00000000000000EE: 48 8D 55 1F        lea         rdx,[rbp+1Fh]
  00000000000000F2: 48 8D 4D F7        lea         rcx,[rbp-9]
  00000000000000F6: E8 00 00 00 00     call        __std_exception_copy
  00000000000000FB: 48 8D 05 00 00 00  lea         rax,[??_7future_error@std@@6B@]
                    00
  0000000000000102: 48 89 45 17        mov         qword ptr [rbp+17h],rax
  0000000000000106: 0F 10 45 07        movups      xmm0,xmmword ptr [rbp+7]
  000000000000010A: 0F 11 45 2F        movups      xmmword ptr [rbp+2Fh],xmm0
  000000000000010E: 48 8D 15 00 00 00  lea         rdx,[_TI3?AVfuture_error@std@@]
                    00
  0000000000000115: 48 8D 4D 17        lea         rcx,[rbp+17h]
  0000000000000119: E8 00 00 00 00     call        _CxxThrowException
  000000000000011E: 90                 nop
  000000000000011F: 0F B6 4B 10        movzx       ecx,byte ptr [rbx+10h]
  0000000000000123: 88 4D B7           mov         byte ptr [rbp-49h],cl
  0000000000000126: 83 E9 01           sub         ecx,1
  0000000000000129: 74 32              je          000000000000015D
  000000000000012B: 83 E9 01           sub         ecx,1
  000000000000012E: 74 24              je          0000000000000154
  0000000000000130: 83 E9 01           sub         ecx,1
  0000000000000133: 74 11              je          0000000000000146
  0000000000000135: 83 F9 01           cmp         ecx,1
  0000000000000138: 75 28              jne         0000000000000162
  000000000000013A: 48 8B 03           mov         rax,qword ptr [rbx]
  000000000000013D: 48 89 45 A7        mov         qword ptr [rbp-59h],rax
  0000000000000141: 4C 89 33           mov         qword ptr [rbx],r14
  0000000000000144: EB 1C              jmp         0000000000000162
  0000000000000146: 48 8B D3           mov         rdx,rbx
  0000000000000149: 48 8D 4D A7        lea         rcx,[rbp-59h]
  000000000000014D: E8 00 00 00 00     call        ?__ExceptionPtrCopy@@YAXPEAXPEBX@Z
  0000000000000152: EB 0E              jmp         0000000000000162
  0000000000000154: 0F 10 03           movups      xmm0,xmmword ptr [rbx]
  0000000000000157: 0F 11 45 A7        movups      xmmword ptr [rbp-59h],xmm0
  000000000000015B: EB 05              jmp         0000000000000162
  000000000000015D: 8B 03              mov         eax,dword ptr [rbx]
  000000000000015F: 89 45 A7           mov         dword ptr [rbp-59h],eax
  0000000000000162: 0F B6 43 18        movzx       eax,byte ptr [rbx+18h]
  0000000000000166: 88 45 BF           mov         byte ptr [rbp-41h],al
  0000000000000169: 48 89 5D C7        mov         qword ptr [rbp-39h],rbx
  000000000000016D: 84 C0              test        al,al
  000000000000016F: 74 08              je          0000000000000179
  0000000000000171: C6 45 C0 00        mov         byte ptr [rbp-40h],0
  0000000000000175: C6 45 C0 00        mov         byte ptr [rbp-40h],0
  0000000000000179: 0F B6 4B 10        movzx       ecx,byte ptr [rbx+10h]
  000000000000017D: 83 E9 01           sub         ecx,1
  0000000000000180: 74 1C              je          000000000000019E
  0000000000000182: 83 E9 01           sub         ecx,1
  0000000000000185: 74 17              je          000000000000019E
  0000000000000187: 83 E9 01           sub         ecx,1
  000000000000018A: 74 0A              je          0000000000000196
  000000000000018C: 83 F9 01           cmp         ecx,1
  000000000000018F: 75 11              jne         00000000000001A2
  0000000000000191: 4C 89 33           mov         qword ptr [rbx],r14
  0000000000000194: EB 08              jmp         000000000000019E
  0000000000000196: 48 8B CB           mov         rcx,rbx
  0000000000000199: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  000000000000019E: C6 43 10 00        mov         byte ptr [rbx+10h],0
  00000000000001A2: 48 8D 45 A7        lea         rax,[rbp-59h]
  00000000000001A6: 48 89 03           mov         qword ptr [rbx],rax
  00000000000001A9: C6 43 10 04        mov         byte ptr [rbx+10h],4
  00000000000001AD: 80 7B 18 00        cmp         byte ptr [rbx+18h],0
  00000000000001B1: 74 04              je          00000000000001B7
  00000000000001B3: C6 43 19 00        mov         byte ptr [rbx+19h],0
  00000000000001B7: 4C 89 75 DF        mov         qword ptr [rbp-21h],r14
  00000000000001BB: C6 46 10 00        mov         byte ptr [rsi+10h],0
  00000000000001BF: 0F B6 45 BF        movzx       eax,byte ptr [rbp-41h]
  00000000000001C3: 88 46 18           mov         byte ptr [rsi+18h],al
  00000000000001C6: 4C 89 76 20        mov         qword ptr [rsi+20h],r14
  00000000000001CA: 84 C0              test        al,al
  00000000000001CC: 74 0F              je          00000000000001DD
  00000000000001CE: 48 8D 46 19        lea         rax,[rsi+19h]
  00000000000001D2: 48 85 C0           test        rax,rax
  00000000000001D5: 74 06              je          00000000000001DD
  00000000000001D7: C6 00 00           mov         byte ptr [rax],0
  00000000000001DA: C6 00 00           mov         byte ptr [rax],0
  00000000000001DD: 49 8B DE           mov         rbx,r14
  00000000000001E0: 38 5D BF           cmp         byte ptr [rbp-41h],bl
  00000000000001E3: 74 31              je          0000000000000216
  00000000000001E5: 48 8D 4D C0        lea         rcx,[rbp-40h]
  00000000000001E9: E8 00 00 00 00     call        replaced
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

  00000000000001EE: 48 39 5D C7        cmp         qword ptr [rbp-39h],rbx
  00000000000001F2: 74 26              je          000000000000021A
  00000000000001F4: 48 8B 4D C7        mov         rcx,qword ptr [rbp-39h]
  00000000000001F8: 0F B6 41 19        movzx       eax,byte ptr [rcx+19h]
  00000000000001FC: 84 C0              test        al,al
  00000000000001FE: 75 11              jne         0000000000000211
  0000000000000200: B8 01 00 00 00     mov         eax,1
  0000000000000205: 86 41 19           xchg        al,byte ptr [rcx+19h]
  0000000000000208: 84 C0              test        al,al
  000000000000020A: 0F 95 C0           setne       al
  000000000000020D: 84 C0              test        al,al
  000000000000020F: 74 05              je          0000000000000216
  0000000000000211: 88 5D C0           mov         byte ptr [rbp-40h],bl
  0000000000000214: EB CF              jmp         00000000000001E5
  0000000000000216: 48 8B 5D C7        mov         rbx,qword ptr [rbp-39h]
  000000000000021A: 0F B6 45 B7        movzx       eax,byte ptr [rbp-49h]
  000000000000021E: 88 46 10           mov         byte ptr [rsi+10h],al
  0000000000000221: 8B C8              mov         ecx,eax
  0000000000000223: 83 E9 01           sub         ecx,1
  0000000000000226: 74 33              je          000000000000025B
  0000000000000228: 83 E9 01           sub         ecx,1
  000000000000022B: 74 25              je          0000000000000252
  000000000000022D: 83 E9 01           sub         ecx,1
  0000000000000230: 74 12              je          0000000000000244
  0000000000000232: 83 F9 01           cmp         ecx,1
  0000000000000235: 75 29              jne         0000000000000260
  0000000000000237: 48 8B 45 A7        mov         rax,qword ptr [rbp-59h]
  000000000000023B: 48 89 06           mov         qword ptr [rsi],rax
  000000000000023E: 4C 89 75 A7        mov         qword ptr [rbp-59h],r14
  0000000000000242: EB 1C              jmp         0000000000000260
  0000000000000244: 48 8D 55 A7        lea         rdx,[rbp-59h]
  0000000000000248: 48 8B CE           mov         rcx,rsi
  000000000000024B: E8 00 00 00 00     call        ?__ExceptionPtrCopy@@YAXPEAXPEBX@Z
  0000000000000250: EB 0E              jmp         0000000000000260
  0000000000000252: 0F 10 45 A7        movups      xmm0,xmmword ptr [rbp-59h]
  0000000000000256: 0F 11 06           movups      xmmword ptr [rsi],xmm0
  0000000000000259: EB 05              jmp         0000000000000260
  000000000000025B: 8B 45 A7           mov         eax,dword ptr [rbp-59h]
  000000000000025E: 89 06              mov         dword ptr [rsi],eax
  0000000000000260: 48 8B 45 C7        mov         rax,qword ptr [rbp-39h]
  0000000000000264: 48 85 C0           test        rax,rax
  0000000000000267: 74 10              je          0000000000000279
  0000000000000269: 48 89 46 20        mov         qword ptr [rsi+20h],rax
  000000000000026D: 4C 89 75 C7        mov         qword ptr [rbp-39h],r14
  0000000000000271: 48 85 DB           test        rbx,rbx
  0000000000000274: 74 12              je          0000000000000288
  0000000000000276: 48 89 33           mov         qword ptr [rbx],rsi
  0000000000000279: 48 85 DB           test        rbx,rbx
  000000000000027C: 74 0A              je          0000000000000288
  000000000000027E: 80 7B 18 00        cmp         byte ptr [rbx+18h],0
  0000000000000282: 74 04              je          0000000000000288
  0000000000000284: C6 43 19 00        mov         byte ptr [rbx+19h],0
  0000000000000288: 80 7D BF 00        cmp         byte ptr [rbp-41h],0
  000000000000028C: 74 04              je          0000000000000292
  000000000000028E: C6 45 C0 00        mov         byte ptr [rbp-40h],0
  0000000000000292: C7 45 EF 01 00 00  mov         dword ptr [rbp-11h],1
                    00
  0000000000000299: 0F 57 C0           xorps       xmm0,xmm0
  000000000000029C: F3 0F 7F 45 CF     movdqu      xmmword ptr [rbp-31h],xmm0
  00000000000002A1: 80 7D BF 00        cmp         byte ptr [rbp-41h],0
  00000000000002A5: 75 0A              jne         00000000000002B1
  00000000000002A7: 48 8B 5D C7        mov         rbx,qword ptr [rbp-39h]
  00000000000002AB: 48 89 5D CF        mov         qword ptr [rbp-31h],rbx
  00000000000002AF: EB 35              jmp         00000000000002E6
  00000000000002B1: 48 8D 4D C0        lea         rcx,[rbp-40h]
  00000000000002B5: E8 00 00 00 00     call        replaced
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

  00000000000002BA: 48 8B 4D C7        mov         rcx,qword ptr [rbp-39h]
  00000000000002BE: 48 85 C9           test        rcx,rcx
  00000000000002C1: 74 1F              je          00000000000002E2
  00000000000002C3: 0F B6 41 19        movzx       eax,byte ptr [rcx+19h]
  00000000000002C7: 84 C0              test        al,al
  00000000000002C9: 75 11              jne         00000000000002DC
  00000000000002CB: B8 01 00 00 00     mov         eax,1
  00000000000002D0: 86 41 19           xchg        al,byte ptr [rcx+19h]
  00000000000002D3: 84 C0              test        al,al
  00000000000002D5: 0F 95 C0           setne       al
  00000000000002D8: 84 C0              test        al,al
  00000000000002DA: 74 CB              je          00000000000002A7
  00000000000002DC: C6 45 C0 00        mov         byte ptr [rbp-40h],0
  00000000000002E0: EB CF              jmp         00000000000002B1
  00000000000002E2: 48 8B 5D CF        mov         rbx,qword ptr [rbp-31h]
  00000000000002E6: 48 8D 45 A7        lea         rax,[rbp-59h]
  00000000000002EA: 48 89 45 D7        mov         qword ptr [rbp-29h],rax
  00000000000002EE: 48 85 DB           test        rbx,rbx
  00000000000002F1: 74 29              je          000000000000031C
  00000000000002F3: 0F B6 4B 10        movzx       ecx,byte ptr [rbx+10h]
  00000000000002F7: 83 E9 01           sub         ecx,1
  00000000000002FA: 74 1C              je          0000000000000318
  00000000000002FC: 83 E9 01           sub         ecx,1
  00000000000002FF: 74 17              je          0000000000000318
  0000000000000301: 83 E9 01           sub         ecx,1
  0000000000000304: 74 0A              je          0000000000000310
  0000000000000306: 83 F9 01           cmp         ecx,1
  0000000000000309: 75 11              jne         000000000000031C
  000000000000030B: 4C 89 33           mov         qword ptr [rbx],r14
  000000000000030E: EB 08              jmp         0000000000000318
  0000000000000310: 48 8B CB           mov         rcx,rbx
  0000000000000313: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  0000000000000318: C6 43 10 00        mov         byte ptr [rbx+10h],0
  000000000000031C: 0F B6 4D B7        movzx       ecx,byte ptr [rbp-49h]
  0000000000000320: 83 E9 01           sub         ecx,1
  0000000000000323: 74 1E              je          0000000000000343
  0000000000000325: 83 E9 01           sub         ecx,1
  0000000000000328: 74 19              je          0000000000000343
  000000000000032A: 83 E9 01           sub         ecx,1
  000000000000032D: 74 0B              je          000000000000033A
  000000000000032F: 83 F9 01           cmp         ecx,1
  0000000000000332: 75 13              jne         0000000000000347
  0000000000000334: 4C 89 75 A7        mov         qword ptr [rbp-59h],r14
  0000000000000338: EB 09              jmp         0000000000000343
  000000000000033A: 48 8D 4D A7        lea         rcx,[rbp-59h]
  000000000000033E: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  0000000000000343: C6 45 B7 00        mov         byte ptr [rbp-49h],0
  0000000000000347: 48 85 DB           test        rbx,rbx
  000000000000034A: 74 0E              je          000000000000035A
  000000000000034C: 80 7B 18 00        cmp         byte ptr [rbx+18h],0
  0000000000000350: 74 04              je          0000000000000356
  0000000000000352: C6 43 19 00        mov         byte ptr [rbx+19h],0
  0000000000000356: 4C 89 75 CF        mov         qword ptr [rbp-31h],r14
  000000000000035A: 80 7D BF 00        cmp         byte ptr [rbp-41h],0
  000000000000035E: 74 04              je          0000000000000364
  0000000000000360: C6 45 C0 00        mov         byte ptr [rbp-40h],0
  0000000000000364: 0F B6 4D B7        movzx       ecx,byte ptr [rbp-49h]
  0000000000000368: 83 E9 01           sub         ecx,1
  000000000000036B: 74 14              je          0000000000000381
  000000000000036D: 83 E9 01           sub         ecx,1
  0000000000000370: 74 0F              je          0000000000000381
  0000000000000372: 83 F9 01           cmp         ecx,1
  0000000000000375: 75 0A              jne         0000000000000381
  0000000000000377: 48 8D 4D A7        lea         rcx,[rbp-59h]
  000000000000037B: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  0000000000000380: 90                 nop
  0000000000000381: 48 8B C6           mov         rax,rsi
  0000000000000384: 4C 8D 9C 24 C0 00  lea         r11,[rsp+0C0h]
                    00 00
  000000000000038C: 49 8B 5B 20        mov         rbx,qword ptr [r11+20h]
  0000000000000390: 49 8B 73 30        mov         rsi,qword ptr [r11+30h]
  0000000000000394: 49 8B E3           mov         rsp,r11
  0000000000000397: 41 5E              pop         r14
  0000000000000399: 5F                 pop         rdi
  000000000000039A: 5D                 pop         rbp
  000000000000039B: C3                 ret
  000000000000039C: CC                 int         3

  0000000000000052: 90                 nop
  0000000000000053: 48 8B 5C 24 40     mov         rbx,qword ptr [rsp+40h]
  0000000000000058: 48 85 DB           test        rbx,rbx
  000000000000005B: 0F 95 C0           setne       al
  000000000000005E: 84 C0              test        al,al
  0000000000000060: 75 65              jne         00000000000000C7
  0000000000000062: C7 45 D0 04 00 00  mov         dword ptr [rbp-30h],4
                    00
  0000000000000069: E8 00 00 00 00     call        replaced
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

  000000000000006E: 48 89 45 D8        mov         qword ptr [rbp-28h],rax
  0000000000000072: 48 8D 05 00 00 00  lea         rax,[??_7exception@std@@6B@]
                    00
  0000000000000079: 48 89 45 60        mov         qword ptr [rbp+60h],rax
  000000000000007D: 33 C0              xor         eax,eax
  000000000000007F: 48 89 45 68        mov         qword ptr [rbp+68h],rax
  0000000000000083: 48 89 45 70        mov         qword ptr [rbp+70h],rax
  0000000000000087: 48 8D 05 00 00 00  lea         rax,[??_C@_00CNPNBAHC@?$AA@]
                    00
  000000000000008E: 48 89 45 00        mov         qword ptr [rbp],rax
  0000000000000092: C6 45 08 01        mov         byte ptr [rbp+8],1
  0000000000000096: 48 8D 55 68        lea         rdx,[rbp+68h]
  000000000000009A: 48 8D 4D 00        lea         rcx,[rbp]
  000000000000009E: E8 00 00 00 00     call        __std_exception_copy
  00000000000000A3: 48 8D 05 00 00 00  lea         rax,[??_7future_error@std@@6B@]
                    00
  00000000000000AA: 48 89 45 60        mov         qword ptr [rbp+60h],rax
  00000000000000AE: 0F 10 45 D0        movups      xmm0,xmmword ptr [rbp-30h]
  00000000000000B2: 0F 11 45 78        movups      xmmword ptr [rbp+78h],xmm0
  00000000000000B6: 48 8D 15 00 00 00  lea         rdx,[_TI3?AVfuture_error@std@@]
                    00
  00000000000000BD: 48 8D 4D 60        lea         rcx,[rbp+60h]
  00000000000000C1: E8 00 00 00 00     call        _CxxThrowException
  00000000000000C6: CC                 int         3
  00000000000000C7: 80 7C 24 30 00     cmp         byte ptr [rsp+30h],0
  00000000000000CC: 0F 95 C0           setne       al
  00000000000000CF: 90                 nop
  00000000000000D0: 84 C0              test        al,al
  00000000000000D2: 74 FC              je          00000000000000D0
  00000000000000D4: 0F 57 C0           xorps       xmm0,xmm0
  00000000000000D7: F3 0F 7F 44 24 78  movdqu      xmmword ptr [rsp+78h],xmm0
  00000000000000DD: 80 7C 24 38 00     cmp         byte ptr [rsp+38h],0
  00000000000000E2: 75 07              jne         00000000000000EB
  00000000000000E4: 48 89 5C 24 78     mov         qword ptr [rsp+78h],rbx
  00000000000000E9: EB 45              jmp         0000000000000130
  00000000000000EB: 48 8D 4C 24 39     lea         rcx,[rsp+39h]
  00000000000000F0: E8 00 00 00 00     call        replaced
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

  00000000000000F5: 48 8B 4C 24 40     mov         rcx,qword ptr [rsp+40h]
  00000000000000FA: 48 85 C9           test        rcx,rcx
  00000000000000FD: 74 2C              je          000000000000012B
  00000000000000FF: 0F B6 41 19        movzx       eax,byte ptr [rcx+19h]
  0000000000000103: 84 C0              test        al,al
  0000000000000105: 75 11              jne         0000000000000118
  0000000000000107: B8 01 00 00 00     mov         eax,1
  000000000000010C: 86 41 19           xchg        al,byte ptr [rcx+19h]
  000000000000010F: 84 C0              test        al,al
  0000000000000111: 0F 95 C0           setne       al
  0000000000000114: 84 C0              test        al,al
  0000000000000116: 74 07              je          000000000000011F
  0000000000000118: C6 44 24 39 00     mov         byte ptr [rsp+39h],0
  000000000000011D: EB CC              jmp         00000000000000EB
  000000000000011F: 48 8B 5C 24 40     mov         rbx,qword ptr [rsp+40h]
  0000000000000124: 48 89 5C 24 78     mov         qword ptr [rsp+78h],rbx
  0000000000000129: EB 05              jmp         0000000000000130
  000000000000012B: 48 8B 5C 24 78     mov         rbx,qword ptr [rsp+78h]
  0000000000000130: 48 8D 44 24 20     lea         rax,[rsp+20h]
  0000000000000135: 48 89 45 80        mov         qword ptr [rbp-80h],rax
  0000000000000139: 80 7C 24 30 00     cmp         byte ptr [rsp+30h],0
  000000000000013E: 0F 95 C0           setne       al
  0000000000000141: 84 C0              test        al,al
  0000000000000143: 75 65              jne         00000000000001AA
  0000000000000145: C7 45 F0 04 00 00  mov         dword ptr [rbp-10h],4
                    00
  000000000000014C: E8 00 00 00 00     call        replaced
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

  0000000000000151: 48 89 45 F8        mov         qword ptr [rbp-8],rax
  0000000000000155: 48 8D 05 00 00 00  lea         rax,[??_7exception@std@@6B@]
                    00
  000000000000015C: 48 89 45 38        mov         qword ptr [rbp+38h],rax
  0000000000000160: 33 C0              xor         eax,eax
  0000000000000162: 48 89 45 40        mov         qword ptr [rbp+40h],rax
  0000000000000166: 48 89 45 48        mov         qword ptr [rbp+48h],rax
  000000000000016A: 48 8D 05 00 00 00  lea         rax,[??_C@_00CNPNBAHC@?$AA@]
                    00
  0000000000000171: 48 89 45 E0        mov         qword ptr [rbp-20h],rax
  0000000000000175: C6 45 E8 01        mov         byte ptr [rbp-18h],1
  0000000000000179: 48 8D 55 40        lea         rdx,[rbp+40h]
  000000000000017D: 48 8D 4D E0        lea         rcx,[rbp-20h]
  0000000000000181: E8 00 00 00 00     call        __std_exception_copy
  0000000000000186: 48 8D 05 00 00 00  lea         rax,[??_7future_error@std@@6B@]
                    00
  000000000000018D: 48 89 45 38        mov         qword ptr [rbp+38h],rax
  0000000000000191: 0F 10 45 F0        movups      xmm0,xmmword ptr [rbp-10h]
  0000000000000195: 0F 11 45 50        movups      xmmword ptr [rbp+50h],xmm0
  0000000000000199: 48 8D 15 00 00 00  lea         rdx,[_TI3?AVfuture_error@std@@]
                    00
  00000000000001A0: 48 8D 4D 38        lea         rcx,[rbp+38h]
  00000000000001A4: E8 00 00 00 00     call        _CxxThrowException
  00000000000001A9: CC                 int         3
  00000000000001AA: 0F B6 44 24 30     movzx       eax,byte ptr [rsp+30h]
  00000000000001AF: 3C 02              cmp         al,2
  00000000000001B1: 0F 94 C1           sete        cl
  00000000000001B4: 84 C9              test        cl,cl
  00000000000001B6: 75 0A              jne         00000000000001C2
  00000000000001B8: 2C 02              sub         al,2
  00000000000001BA: 3C 01              cmp         al,1
  00000000000001BC: 77 6E              ja          000000000000022C
  00000000000001BE: 84 C9              test        cl,cl
  00000000000001C0: 74 33              je          00000000000001F5
  00000000000001C2: 0F 10 44 24 20     movups      xmm0,xmmword ptr [rsp+20h]
  00000000000001C7: 0F 29 85 A0 00 00  movaps      xmmword ptr [rbp+0A0h],xmm0
                    00
  00000000000001CE: 48 8D 95 A0 00 00  lea         rdx,[rbp+0A0h]
                    00
  00000000000001D5: 48 8D 8D D0 00 00  lea         rcx,[rbp+0D0h]
                    00
  00000000000001DC: E8 00 00 00 00     call        replaced
  0000000000000000: 48 8B C4           mov         rax,rsp
  0000000000000003: 55                 push        rbp
  0000000000000004: 48 8D 68 A1        lea         rbp,[rax-5Fh]
  0000000000000008: 48 81 EC B0 00 00  sub         rsp,0B0h
                    00
  000000000000000F: 48 C7 45 C7 FE FF  mov         qword ptr [rbp-39h],0FFFFFFFFFFFFFFFEh
                    FF FF
  0000000000000017: 48 89 58 08        mov         qword ptr [rax+8],rbx
  000000000000001B: 48 89 78 10        mov         qword ptr [rax+10h],rdi
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
  0000000000000125: 49 8B 5B 10        mov         rbx,qword ptr [r11+10h]
  0000000000000129: 49 8B 7B 18        mov         rdi,qword ptr [r11+18h]
  000000000000012D: 41 0F 28 73 F0     movaps      xmm6,xmmword ptr [r11-10h]
  0000000000000132: 49 8B E3           mov         rsp,r11
  0000000000000135: 5D                 pop         rbp
  0000000000000136: C3                 ret

  00000000000001E1: 48 8D 15 00 00 00  lea         rdx,[_TI4?AVsystem_error@std@@]
                    00
  00000000000001E8: 48 8D 8D D0 00 00  lea         rcx,[rbp+0D0h]
                    00
  00000000000001EF: E8 00 00 00 00     call        _CxxThrowException
  00000000000001F4: CC                 int         3
  00000000000001F5: 0F B6 44 24 30     movzx       eax,byte ptr [rsp+30h]
  00000000000001FA: 2C 02              sub         al,2
  00000000000001FC: 3C 01              cmp         al,1
  00000000000001FE: 77 2C              ja          000000000000022C
  0000000000000200: 48 8D 54 24 20     lea         rdx,[rsp+20h]
  0000000000000205: 48 8D 4D 98        lea         rcx,[rbp-68h]
  0000000000000209: E8 00 00 00 00     call        ?__ExceptionPtrCopy@@YAXPEAXPEBX@Z
  000000000000020E: 48 8D 45 98        lea         rax,[rbp-68h]
  0000000000000212: 48 89 85 30 01 00  mov         qword ptr [rbp+130h],rax
                    00
  0000000000000219: 48 8D 4D 98        lea         rcx,[rbp-68h]
  000000000000021D: E8 00 00 00 00     call        ?__ExceptionPtrRethrow@@YAXPEBX@Z
  0000000000000222: 90                 nop
  0000000000000223: 48 8D 4D 98        lea         rcx,[rbp-68h]
  0000000000000227: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  000000000000022C: 8B 44 24 20        mov         eax,dword ptr [rsp+20h]
  0000000000000230: 89 85 30 01 00 00  mov         dword ptr [rbp+130h],eax
  0000000000000236: 0F B6 4C 24 30     movzx       ecx,byte ptr [rsp+30h]
  000000000000023B: 33 F6              xor         esi,esi
  000000000000023D: 83 E9 01           sub         ecx,1
  0000000000000240: 74 20              je          0000000000000262
  0000000000000242: 83 E9 01           sub         ecx,1
  0000000000000245: 74 1B              je          0000000000000262
  0000000000000247: 83 E9 01           sub         ecx,1
  000000000000024A: 74 0C              je          0000000000000258
  000000000000024C: 83 F9 01           cmp         ecx,1
  000000000000024F: 75 16              jne         0000000000000267
  0000000000000251: 48 89 74 24 20     mov         qword ptr [rsp+20h],rsi
  0000000000000256: EB 0A              jmp         0000000000000262
  0000000000000258: 48 8D 4C 24 20     lea         rcx,[rsp+20h]
  000000000000025D: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  0000000000000262: 40 88 74 24 30     mov         byte ptr [rsp+30h],sil
  0000000000000267: 48 85 DB           test        rbx,rbx
  000000000000026A: 74 29              je          0000000000000295
  000000000000026C: 0F B6 4B 10        movzx       ecx,byte ptr [rbx+10h]
  0000000000000270: 83 E9 01           sub         ecx,1
  0000000000000273: 74 1C              je          0000000000000291
  0000000000000275: 83 E9 01           sub         ecx,1
  0000000000000278: 74 17              je          0000000000000291
  000000000000027A: 83 E9 01           sub         ecx,1
  000000000000027D: 74 0A              je          0000000000000289
  000000000000027F: 83 F9 01           cmp         ecx,1
  0000000000000282: 75 11              jne         0000000000000295
  0000000000000284: 48 89 33           mov         qword ptr [rbx],rsi
  0000000000000287: EB 08              jmp         0000000000000291
  0000000000000289: 48 8B CB           mov         rcx,rbx
  000000000000028C: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  0000000000000291: C6 43 10 00        mov         byte ptr [rbx+10h],0
  0000000000000295: 48 89 74 24 40     mov         qword ptr [rsp+40h],rsi
  000000000000029A: 48 85 DB           test        rbx,rbx
  000000000000029D: 74 0F              je          00000000000002AE
  000000000000029F: 80 7B 18 00        cmp         byte ptr [rbx+18h],0
  00000000000002A3: 74 04              je          00000000000002A9
  00000000000002A5: C6 43 19 00        mov         byte ptr [rbx+19h],0
  00000000000002A9: 48 89 74 24 78     mov         qword ptr [rsp+78h],rsi
  00000000000002AE: 80 7C 24 38 00     cmp         byte ptr [rsp+38h],0
  00000000000002B3: 74 05              je          00000000000002BA
  00000000000002B5: C6 44 24 39 00     mov         byte ptr [rsp+39h],0
  00000000000002BA: 48 89 75 80        mov         qword ptr [rbp-80h],rsi
  00000000000002BE: 0F 57 C0           xorps       xmm0,xmm0
  00000000000002C1: F3 0F 7F 44 24 68  movdqu      xmmword ptr [rsp+68h],xmm0
  00000000000002C7: 80 7C 24 38 00     cmp         byte ptr [rsp+38h],0
  00000000000002CC: 75 0C              jne         00000000000002DA
  00000000000002CE: 48 8B 5C 24 40     mov         rbx,qword ptr [rsp+40h]
  00000000000002D3: 48 89 5C 24 68     mov         qword ptr [rsp+68h],rbx
  00000000000002D8: EB 39              jmp         0000000000000313
  00000000000002DA: 48 8D 4C 24 39     lea         rcx,[rsp+39h]
  00000000000002DF: E8 00 00 00 00     call        replaced
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

  00000000000002E4: 48 8B 4C 24 40     mov         rcx,qword ptr [rsp+40h]
  00000000000002E9: 48 85 C9           test        rcx,rcx
  00000000000002EC: 74 20              je          000000000000030E
  00000000000002EE: 0F B6 41 19        movzx       eax,byte ptr [rcx+19h]
  00000000000002F2: 84 C0              test        al,al
  00000000000002F4: 75 11              jne         0000000000000307
  00000000000002F6: B8 01 00 00 00     mov         eax,1
  00000000000002FB: 86 41 19           xchg        al,byte ptr [rcx+19h]
  00000000000002FE: 84 C0              test        al,al
  0000000000000300: 0F 95 C0           setne       al
  0000000000000303: 84 C0              test        al,al
  0000000000000305: 74 C7              je          00000000000002CE
  0000000000000307: C6 44 24 39 00     mov         byte ptr [rsp+39h],0
  000000000000030C: EB CC              jmp         00000000000002DA
  000000000000030E: 48 8B 5C 24 68     mov         rbx,qword ptr [rsp+68h]
  0000000000000313: 48 8D 44 24 20     lea         rax,[rsp+20h]
  0000000000000318: 48 89 44 24 70     mov         qword ptr [rsp+70h],rax
  000000000000031D: 48 85 DB           test        rbx,rbx
  0000000000000320: 74 29              je          000000000000034B
  0000000000000322: 0F B6 4B 10        movzx       ecx,byte ptr [rbx+10h]
  0000000000000326: 83 E9 01           sub         ecx,1
  0000000000000329: 74 1C              je          0000000000000347
  000000000000032B: 83 E9 01           sub         ecx,1
  000000000000032E: 74 17              je          0000000000000347
  0000000000000330: 83 E9 01           sub         ecx,1
  0000000000000333: 74 0A              je          000000000000033F
  0000000000000335: 83 F9 01           cmp         ecx,1
  0000000000000338: 75 11              jne         000000000000034B
  000000000000033A: 48 89 33           mov         qword ptr [rbx],rsi
  000000000000033D: EB 08              jmp         0000000000000347
  000000000000033F: 48 8B CB           mov         rcx,rbx
  0000000000000342: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  0000000000000347: C6 43 10 00        mov         byte ptr [rbx+10h],0
  000000000000034B: 0F B6 4C 24 30     movzx       ecx,byte ptr [rsp+30h]
  0000000000000350: 83 E9 01           sub         ecx,1
  0000000000000353: 74 20              je          0000000000000375
  0000000000000355: 83 E9 01           sub         ecx,1
  0000000000000358: 74 1B              je          0000000000000375
  000000000000035A: 83 E9 01           sub         ecx,1
  000000000000035D: 74 0C              je          000000000000036B
  000000000000035F: 83 F9 01           cmp         ecx,1
  0000000000000362: 75 16              jne         000000000000037A
  0000000000000364: 48 89 74 24 20     mov         qword ptr [rsp+20h],rsi
  0000000000000369: EB 0A              jmp         0000000000000375
  000000000000036B: 48 8D 4C 24 20     lea         rcx,[rsp+20h]
  0000000000000370: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  0000000000000375: C6 44 24 30 00     mov         byte ptr [rsp+30h],0
  000000000000037A: 48 85 DB           test        rbx,rbx
  000000000000037D: 74 0F              je          000000000000038E
  000000000000037F: 80 7B 18 00        cmp         byte ptr [rbx+18h],0
  0000000000000383: 74 04              je          0000000000000389
  0000000000000385: C6 43 19 00        mov         byte ptr [rbx+19h],0
  0000000000000389: 48 89 74 24 68     mov         qword ptr [rsp+68h],rsi
  000000000000038E: 80 7C 24 38 00     cmp         byte ptr [rsp+38h],0
  0000000000000393: 74 05              je          000000000000039A
  0000000000000395: C6 44 24 39 00     mov         byte ptr [rsp+39h],0
  000000000000039A: 48 89 74 24 70     mov         qword ptr [rsp+70h],rsi
  000000000000039F: 0F B6 4C 24 30     movzx       ecx,byte ptr [rsp+30h]
  00000000000003A4: 83 E9 01           sub         ecx,1
  00000000000003A7: 74 20              je          00000000000003C9
  00000000000003A9: 83 E9 01           sub         ecx,1
  00000000000003AC: 74 1B              je          00000000000003C9
  00000000000003AE: 83 E9 01           sub         ecx,1
  00000000000003B1: 74 0C              je          00000000000003BF
  00000000000003B3: 83 F9 01           cmp         ecx,1
  00000000000003B6: 75 16              jne         00000000000003CE
  00000000000003B8: 48 89 74 24 20     mov         qword ptr [rsp+20h],rsi
  00000000000003BD: EB 0A              jmp         00000000000003C9
  00000000000003BF: 48 8D 4C 24 20     lea         rcx,[rsp+20h]
  00000000000003C4: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  00000000000003C9: C6 44 24 30 00     mov         byte ptr [rsp+30h],0
  00000000000003CE: 0F 57 C0           xorps       xmm0,xmm0
  00000000000003D1: F3 0F 7F 45 88     movdqu      xmmword ptr [rbp-78h],xmm0
  00000000000003D6: 80 7C 24 60 00     cmp         byte ptr [rsp+60h],0
  00000000000003DB: 75 1B              jne         00000000000003F8
  00000000000003DD: 48 8D 44 24 48     lea         rax,[rsp+48h]
  00000000000003E2: 48 89 45 88        mov         qword ptr [rbp-78h],rax
  00000000000003E6: 80 7C 24 58 04     cmp         byte ptr [rsp+58h],4
  00000000000003EB: 75 5E              jne         000000000000044B
  00000000000003ED: 48 8B 5C 24 48     mov         rbx,qword ptr [rsp+48h]
  00000000000003F2: 48 89 5D 90        mov         qword ptr [rbp-70h],rbx
  00000000000003F6: EB 57              jmp         000000000000044F
  00000000000003F8: 48 8D 4C 24 61     lea         rcx,[rsp+61h]
  00000000000003FD: E8 00 00 00 00     call        replaced
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

  0000000000000402: 80 7C 24 58 04     cmp         byte ptr [rsp+58h],4
  0000000000000407: 75 39              jne         0000000000000442
  0000000000000409: 48 8B 4C 24 48     mov         rcx,qword ptr [rsp+48h]
  000000000000040E: 0F B6 41 19        movzx       eax,byte ptr [rcx+19h]
  0000000000000412: 84 C0              test        al,al
  0000000000000414: 75 11              jne         0000000000000427
  0000000000000416: B8 01 00 00 00     mov         eax,1
  000000000000041B: 86 41 19           xchg        al,byte ptr [rcx+19h]
  000000000000041E: 84 C0              test        al,al
  0000000000000420: 0F 95 C0           setne       al
  0000000000000423: 84 C0              test        al,al
  0000000000000425: 74 07              je          000000000000042E
  0000000000000427: C6 44 24 61 00     mov         byte ptr [rsp+61h],0
  000000000000042C: EB CA              jmp         00000000000003F8
  000000000000042E: 48 8D 44 24 48     lea         rax,[rsp+48h]
  0000000000000433: 48 89 45 88        mov         qword ptr [rbp-78h],rax
  0000000000000437: 48 8B 5C 24 48     mov         rbx,qword ptr [rsp+48h]
  000000000000043C: 48 89 5D 90        mov         qword ptr [rbp-70h],rbx
  0000000000000440: EB 0D              jmp         000000000000044F
  0000000000000442: 48 8D 44 24 48     lea         rax,[rsp+48h]
  0000000000000447: 48 89 45 88        mov         qword ptr [rbp-78h],rax
  000000000000044B: 48 8B 5D 90        mov         rbx,qword ptr [rbp-70h]
  000000000000044F: 48 85 DB           test        rbx,rbx
  0000000000000452: 0F 84 D9 00 00 00  je          0000000000000531
  0000000000000458: 80 7B 10 00        cmp         byte ptr [rbx+10h],0
  000000000000045C: 0F 95 C0           setne       al
  000000000000045F: 84 C0              test        al,al
  0000000000000461: 0F 85 C6 00 00 00  jne         000000000000052D
  0000000000000467: E8 00 00 00 00     call        replaced
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

  000000000000046C: C7 45 C0 01 00 00  mov         dword ptr [rbp-40h],1
                    00
  0000000000000473: 48 89 45 C8        mov         qword ptr [rbp-38h],rax
  0000000000000477: 0F 28 75 C0        movaps      xmm6,xmmword ptr [rbp-40h]
  000000000000047B: 66 0F 7F B5 B0 00  movdqa      xmmword ptr [rbp+0B0h],xmm6
                    00 00
  0000000000000483: 48 8D 05 00 00 00  lea         rax,[??_7exception@std@@6B@]
                    00
  000000000000048A: 48 89 45 10        mov         qword ptr [rbp+10h],rax
  000000000000048E: 33 C0              xor         eax,eax
  0000000000000490: 48 89 45 18        mov         qword ptr [rbp+18h],rax
  0000000000000494: 48 89 45 20        mov         qword ptr [rbp+20h],rax
  0000000000000498: 48 8D 05 00 00 00  lea         rax,[??_C@_00CNPNBAHC@?$AA@]
                    00
  000000000000049F: 48 89 45 A8        mov         qword ptr [rbp-58h],rax
  00000000000004A3: C6 45 B0 01        mov         byte ptr [rbp-50h],1
  00000000000004A7: 48 8D 55 18        lea         rdx,[rbp+18h]
  00000000000004AB: 48 8D 4D A8        lea         rcx,[rbp-58h]
  00000000000004AF: E8 00 00 00 00     call        __std_exception_copy
  00000000000004B4: 48 8D 05 00 00 00  lea         rax,[??_7future_error@std@@6B@]
                    00
  00000000000004BB: 48 89 45 10        mov         qword ptr [rbp+10h],rax
  00000000000004BF: 0F 11 75 28        movups      xmmword ptr [rbp+28h],xmm6
  00000000000004C3: 48 8D 55 10        lea         rdx,[rbp+10h]
  00000000000004C7: 48 8D 8D C0 00 00  lea         rcx,[rbp+0C0h]
                    00
  00000000000004CE: E8 00 00 00 00     call        replaced
  0000000000000000: 48 89 54 24 10     mov         qword ptr [rsp+10h],rdx
  0000000000000005: 57                 push        rdi
  0000000000000006: 48 83 EC 30        sub         rsp,30h
  000000000000000A: 48 C7 44 24 28 FE  mov         qword ptr [rsp+28h],0FFFFFFFFFFFFFFFEh
                    FF FF FF
  0000000000000013: 48 89 5C 24 40     mov         qword ptr [rsp+40h],rbx
  0000000000000018: 48 8B DA           mov         rbx,rdx
  000000000000001B: 48 8B F9           mov         rdi,rcx
  000000000000001E: C7 44 24 20 00 00  mov         dword ptr [rsp+20h],0
                    00 00
  0000000000000026: 4C 8D 05 00 00 00  lea         r8,[_TI3?AVfuture_error@std@@]
                    00
  000000000000002D: E8 00 00 00 00     call        replaced
  0000000000000000: 40 57              push        rdi
  0000000000000002: 48 83 EC 40        sub         rsp,40h
  0000000000000006: 48 C7 44 24 28 FE  mov         qword ptr [rsp+28h],0FFFFFFFFFFFFFFFEh
                    FF FF FF
  000000000000000F: 48 89 5C 24 50     mov         qword ptr [rsp+50h],rbx
  0000000000000014: 48 89 74 24 58     mov         qword ptr [rsp+58h],rsi
  0000000000000019: 49 8B F8           mov         rdi,r8
  000000000000001C: 48 8B F2           mov         rsi,rdx
  000000000000001F: 48 8B D9           mov         rbx,rcx
  0000000000000022: C7 44 24 20 00 00  mov         dword ptr [rsp+20h],0
                    00 00
  000000000000002A: 48 8D 4C 24 30     lea         rcx,[rsp+30h]
  000000000000002F: E8 00 00 00 00     call        ?__ExceptionPtrCreate@@YAXPEAX@Z
  0000000000000034: 90                 nop
  0000000000000035: 48 85 FF           test        rdi,rdi
  0000000000000038: 74 10              je          000000000000004A
  000000000000003A: 4C 8B C7           mov         r8,rdi
  000000000000003D: 48 8B D6           mov         rdx,rsi
  0000000000000040: 48 8D 4C 24 30     lea         rcx,[rsp+30h]
  0000000000000045: E8 00 00 00 00     call        ?__ExceptionPtrCopyException@@YAXPEAXPEBX1@Z
  000000000000004A: 48 8D 54 24 30     lea         rdx,[rsp+30h]
  000000000000004F: 48 8B CB           mov         rcx,rbx
  0000000000000052: E8 00 00 00 00     call        ?__ExceptionPtrCopy@@YAXPEAXPEBX@Z
  0000000000000057: 90                 nop
  0000000000000058: 48 8D 4C 24 30     lea         rcx,[rsp+30h]
  000000000000005D: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  0000000000000062: 48 8B C3           mov         rax,rbx
  0000000000000065: 48 8B 5C 24 50     mov         rbx,qword ptr [rsp+50h]
  000000000000006A: 48 8B 74 24 58     mov         rsi,qword ptr [rsp+58h]
  000000000000006F: 48 83 C4 40        add         rsp,40h
  0000000000000073: 5F                 pop         rdi
  0000000000000074: C3                 ret

  0000000000000032: 90                 nop
  0000000000000033: 48 8D 05 00 00 00  lea         rax,[??_7exception@std@@6B@]
                    00
  000000000000003A: 48 89 03           mov         qword ptr [rbx],rax
  000000000000003D: 48 8D 4B 08        lea         rcx,[rbx+8]
  0000000000000041: E8 00 00 00 00     call        __std_exception_destroy
  0000000000000046: 48 8B C7           mov         rax,rdi
  0000000000000049: 48 8B 5C 24 40     mov         rbx,qword ptr [rsp+40h]
  000000000000004E: 48 83 C4 30        add         rsp,30h
  0000000000000052: 5F                 pop         rdi
  0000000000000053: C3                 ret

  00000000000004D3: 48 8B F8           mov         rdi,rax
  00000000000004D6: 48 89 85 40 01 00  mov         qword ptr [rbp+140h],rax
                    00
  00000000000004DD: 0F B6 53 10        movzx       edx,byte ptr [rbx+10h]
  00000000000004E1: 83 EA 01           sub         edx,1
  00000000000004E4: 74 1C              je          0000000000000502
  00000000000004E6: 83 EA 01           sub         edx,1
  00000000000004E9: 74 17              je          0000000000000502
  00000000000004EB: 83 EA 01           sub         edx,1
  00000000000004EE: 74 0A              je          00000000000004FA
  00000000000004F0: 83 FA 01           cmp         edx,1
  00000000000004F3: 75 11              jne         0000000000000506
  00000000000004F5: 48 89 33           mov         qword ptr [rbx],rsi
  00000000000004F8: EB 08              jmp         0000000000000502
  00000000000004FA: 48 8B CB           mov         rcx,rbx
  00000000000004FD: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  0000000000000502: C6 43 10 00        mov         byte ptr [rbx+10h],0
  0000000000000506: 48 8B D7           mov         rdx,rdi
  0000000000000509: 48 8D 8D 88 00 00  lea         rcx,[rbp+88h]
                    00
  0000000000000510: E8 00 00 00 00     call        ?__ExceptionPtrCopy@@YAXPEAXPEBX@Z
  0000000000000515: 48 8D 95 88 00 00  lea         rdx,[rbp+88h]
                    00
  000000000000051C: 48 8B CB           mov         rcx,rbx
  000000000000051F: E8 00 00 00 00     call        replaced
  0000000000000000: 48 8B C4           mov         rax,rsp
  0000000000000003: 48 89 50 10        mov         qword ptr [rax+10h],rdx
  0000000000000007: 57                 push        rdi
  0000000000000008: 48 83 EC 70        sub         rsp,70h
  000000000000000C: 48 C7 40 A8 FE FF  mov         qword ptr [rax-58h],0FFFFFFFFFFFFFFFEh
                    FF FF
  0000000000000014: 48 89 58 08        mov         qword ptr [rax+8],rbx
  0000000000000018: 48 8B DA           mov         rbx,rdx
  000000000000001B: 48 8B F9           mov         rdi,rcx
  000000000000001E: 80 79 10 00        cmp         byte ptr [rcx+10h],0
  0000000000000022: 74 71              je          0000000000000095
  0000000000000024: C7 40 C0 03 00 00  mov         dword ptr [rax-40h],3
                    00
  000000000000002B: E8 00 00 00 00     call        replaced
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

  0000000000000030: 48 89 44 24 40     mov         qword ptr [rsp+40h],rax
  0000000000000035: 48 8D 05 00 00 00  lea         rax,[??_7exception@std@@6B@]
                    00
  000000000000003C: 48 89 44 24 48     mov         qword ptr [rsp+48h],rax
  0000000000000041: 33 C0              xor         eax,eax
  0000000000000043: 48 89 44 24 50     mov         qword ptr [rsp+50h],rax
  0000000000000048: 48 89 44 24 58     mov         qword ptr [rsp+58h],rax
  000000000000004D: 48 8D 05 00 00 00  lea         rax,[??_C@_00CNPNBAHC@?$AA@]
                    00
  0000000000000054: 48 89 44 24 28     mov         qword ptr [rsp+28h],rax
  0000000000000059: C6 44 24 30 01     mov         byte ptr [rsp+30h],1
  000000000000005E: 48 8D 54 24 50     lea         rdx,[rsp+50h]
  0000000000000063: 48 8D 4C 24 28     lea         rcx,[rsp+28h]
  0000000000000068: E8 00 00 00 00     call        __std_exception_copy
  000000000000006D: 48 8D 05 00 00 00  lea         rax,[??_7future_error@std@@6B@]
                    00
  0000000000000074: 48 89 44 24 48     mov         qword ptr [rsp+48h],rax
  0000000000000079: 0F 10 44 24 38     movups      xmm0,xmmword ptr [rsp+38h]
  000000000000007E: 0F 11 44 24 60     movups      xmmword ptr [rsp+60h],xmm0
  0000000000000083: 48 8D 15 00 00 00  lea         rdx,[_TI3?AVfuture_error@std@@]
                    00
  000000000000008A: 48 8D 4C 24 48     lea         rcx,[rsp+48h]
  000000000000008F: E8 00 00 00 00     call        _CxxThrowException
  0000000000000094: CC                 int         3
  0000000000000095: E8 00 00 00 00     call        ?__ExceptionPtrCopy@@YAXPEAXPEBX@Z
  000000000000009A: C6 47 10 03        mov         byte ptr [rdi+10h],3
  000000000000009E: 48 8B CB           mov         rcx,rbx
  00000000000000A1: 48 8B 9C 24 80 00  mov         rbx,qword ptr [rsp+80h]
                    00 00
  00000000000000A9: 48 83 C4 70        add         rsp,70h
  00000000000000AD: 5F                 pop         rdi
  00000000000000AE: E9 00 00 00 00     jmp         ?__ExceptionPtrDestroy@@YAXPEAX@Z

  0000000000000524: 90                 nop
  0000000000000525: 48 8B CF           mov         rcx,rdi
  0000000000000528: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  000000000000052D: 48 89 73 20        mov         qword ptr [rbx+20h],rsi
  0000000000000531: 0F B6 4C 24 58     movzx       ecx,byte ptr [rsp+58h]
  0000000000000536: 83 E9 01           sub         ecx,1
  0000000000000539: 74 20              je          000000000000055B
  000000000000053B: 83 E9 01           sub         ecx,1
  000000000000053E: 74 1B              je          000000000000055B
  0000000000000540: 83 E9 01           sub         ecx,1
  0000000000000543: 74 0C              je          0000000000000551
  0000000000000545: 83 F9 01           cmp         ecx,1
  0000000000000548: 75 16              jne         0000000000000560
  000000000000054A: 48 89 74 24 48     mov         qword ptr [rsp+48h],rsi
  000000000000054F: EB 0A              jmp         000000000000055B
  0000000000000551: 48 8D 4C 24 48     lea         rcx,[rsp+48h]
  0000000000000556: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  000000000000055B: C6 44 24 58 00     mov         byte ptr [rsp+58h],0
  0000000000000560: 80 7C 24 60 00     cmp         byte ptr [rsp+60h],0
  0000000000000565: 74 05              je          000000000000056C
  0000000000000567: C6 44 24 61 00     mov         byte ptr [rsp+61h],0
  000000000000056C: 48 89 75 88        mov         qword ptr [rbp-78h],rsi
  0000000000000570: 48 85 DB           test        rbx,rbx
  0000000000000573: 74 0A              je          000000000000057F
  0000000000000575: 80 7B 18 00        cmp         byte ptr [rbx+18h],0
  0000000000000579: 74 04              je          000000000000057F
  000000000000057B: C6 43 19 00        mov         byte ptr [rbx+19h],0
  000000000000057F: 0F B6 4C 24 58     movzx       ecx,byte ptr [rsp+58h]
  0000000000000584: 83 E9 01           sub         ecx,1
  0000000000000587: 74 15              je          000000000000059E
  0000000000000589: 83 E9 01           sub         ecx,1
  000000000000058C: 74 10              je          000000000000059E
  000000000000058E: 83 F9 01           cmp         ecx,1
  0000000000000591: 75 0B              jne         000000000000059E
  0000000000000593: 48 8D 4C 24 48     lea         rcx,[rsp+48h]
  0000000000000598: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  000000000000059D: 90                 nop
  000000000000059E: 8B 85 30 01 00 00  mov         eax,dword ptr [rbp+130h]
  00000000000005A4: 48 8B 9C 24 48 02  mov         rbx,qword ptr [rsp+248h]
                    00 00
  00000000000005AC: 0F 28 B4 24 00 02  movaps      xmm6,xmmword ptr [rsp+200h]
                    00 00
  00000000000005B4: 48 81 C4 10 02 00  add         rsp,210h
                    00
  00000000000005BB: 5F                 pop         rdi
  00000000000005BC: 5E                 pop         rsi
  00000000000005BD: 5D                 pop         rbp
  00000000000005BE: C3                 ret
