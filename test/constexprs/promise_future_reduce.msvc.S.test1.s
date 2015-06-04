  0000000000000000: 48 8B C4           mov         rax,rsp
  0000000000000003: 55                 push        rbp
  0000000000000004: 56                 push        rsi
  0000000000000005: 57                 push        rdi
  0000000000000006: 48 8D A8 A8 FE FF  lea         rbp,[rax-158h]
                    FF
  000000000000000D: 48 81 EC 40 02 00  sub         rsp,240h
                    00
  0000000000000014: 48 C7 85 D0 00 00  mov         qword ptr [rbp+0D0h],0FFFFFFFFFFFFFFFEh
                    00 FE FF FF FF
  000000000000001F: 48 89 58 20        mov         qword ptr [rax+20h],rbx
  0000000000000023: 0F 29 70 D8        movaps      xmmword ptr [rax-28h],xmm6
  0000000000000027: C6 44 24 60 00     mov         byte ptr [rsp+60h],0
  000000000000002C: C7 85 68 01 00 00  mov         dword ptr [rbp+168h],5
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
  000000000000000F: 48 81 EC D0 00 00  sub         rsp,0D0h
                    00
  0000000000000016: 48 C7 45 3F FE FF  mov         qword ptr [rbp+3Fh],0FFFFFFFFFFFFFFFEh
                    FF FF
  000000000000001E: 48 89 58 18        mov         qword ptr [rax+18h],rbx
  0000000000000022: 48 89 70 20        mov         qword ptr [rax+20h],rsi
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
  0000000000000123: 88 4D A7           mov         byte ptr [rbp-59h],cl
  0000000000000126: 83 E9 01           sub         ecx,1
  0000000000000129: 74 32              je          000000000000015D
  000000000000012B: 83 E9 01           sub         ecx,1
  000000000000012E: 74 24              je          0000000000000154
  0000000000000130: 83 E9 01           sub         ecx,1
  0000000000000133: 74 11              je          0000000000000146
  0000000000000135: 83 F9 01           cmp         ecx,1
  0000000000000138: 75 28              jne         0000000000000162
  000000000000013A: 48 8B 03           mov         rax,qword ptr [rbx]
  000000000000013D: 48 89 45 97        mov         qword ptr [rbp-69h],rax
  0000000000000141: 4C 89 33           mov         qword ptr [rbx],r14
  0000000000000144: EB 1C              jmp         0000000000000162
  0000000000000146: 48 8B D3           mov         rdx,rbx
  0000000000000149: 48 8D 4D 97        lea         rcx,[rbp-69h]
  000000000000014D: E8 00 00 00 00     call        ?__ExceptionPtrCopy@@YAXPEAXPEBX@Z
  0000000000000152: EB 0E              jmp         0000000000000162
  0000000000000154: 0F 10 03           movups      xmm0,xmmword ptr [rbx]
  0000000000000157: 0F 11 45 97        movups      xmmword ptr [rbp-69h],xmm0
  000000000000015B: EB 05              jmp         0000000000000162
  000000000000015D: 8B 03              mov         eax,dword ptr [rbx]
  000000000000015F: 89 45 97           mov         dword ptr [rbp-69h],eax
  0000000000000162: C6 43 10 00        mov         byte ptr [rbx+10h],0
  0000000000000166: 0F B6 43 18        movzx       eax,byte ptr [rbx+18h]
  000000000000016A: 88 45 AF           mov         byte ptr [rbp-51h],al
  000000000000016D: 48 89 5D B7        mov         qword ptr [rbp-49h],rbx
  0000000000000171: 84 C0              test        al,al
  0000000000000173: 74 08              je          000000000000017D
  0000000000000175: C6 45 B0 00        mov         byte ptr [rbp-50h],0
  0000000000000179: C6 45 B0 00        mov         byte ptr [rbp-50h],0
  000000000000017D: 0F B6 4B 10        movzx       ecx,byte ptr [rbx+10h]
  0000000000000181: 83 E9 01           sub         ecx,1
  0000000000000184: 74 1C              je          00000000000001A2
  0000000000000186: 83 E9 01           sub         ecx,1
  0000000000000189: 74 17              je          00000000000001A2
  000000000000018B: 83 E9 01           sub         ecx,1
  000000000000018E: 74 0A              je          000000000000019A
  0000000000000190: 83 F9 01           cmp         ecx,1
  0000000000000193: 75 11              jne         00000000000001A6
  0000000000000195: 4C 89 33           mov         qword ptr [rbx],r14
  0000000000000198: EB 08              jmp         00000000000001A2
  000000000000019A: 48 8B CB           mov         rcx,rbx
  000000000000019D: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  00000000000001A2: C6 43 10 00        mov         byte ptr [rbx+10h],0
  00000000000001A6: 48 8D 45 97        lea         rax,[rbp-69h]
  00000000000001AA: 48 89 03           mov         qword ptr [rbx],rax
  00000000000001AD: C6 43 10 04        mov         byte ptr [rbx+10h],4
  00000000000001B1: 80 7B 18 00        cmp         byte ptr [rbx+18h],0
  00000000000001B5: 74 04              je          00000000000001BB
  00000000000001B7: C6 43 19 00        mov         byte ptr [rbx+19h],0
  00000000000001BB: 4C 89 75 DF        mov         qword ptr [rbp-21h],r14
  00000000000001BF: C6 46 10 00        mov         byte ptr [rsi+10h],0
  00000000000001C3: 0F B6 45 AF        movzx       eax,byte ptr [rbp-51h]
  00000000000001C7: 88 46 18           mov         byte ptr [rsi+18h],al
  00000000000001CA: 4C 89 76 20        mov         qword ptr [rsi+20h],r14
  00000000000001CE: 84 C0              test        al,al
  00000000000001D0: 74 0F              je          00000000000001E1
  00000000000001D2: 48 8D 46 19        lea         rax,[rsi+19h]
  00000000000001D6: 48 85 C0           test        rax,rax
  00000000000001D9: 74 06              je          00000000000001E1
  00000000000001DB: C6 00 00           mov         byte ptr [rax],0
  00000000000001DE: C6 00 00           mov         byte ptr [rax],0
  00000000000001E1: 0F 57 C0           xorps       xmm0,xmm0
  00000000000001E4: F3 0F 7F 45 BF     movdqu      xmmword ptr [rbp-41h],xmm0
  00000000000001E9: 80 7D AF 00        cmp         byte ptr [rbp-51h],0
  00000000000001ED: 75 0A              jne         00000000000001F9
  00000000000001EF: 48 8B 5D B7        mov         rbx,qword ptr [rbp-49h]
  00000000000001F3: 48 89 5D BF        mov         qword ptr [rbp-41h],rbx
  00000000000001F7: EB 37              jmp         0000000000000230
  00000000000001F9: 48 8D 4D B0        lea         rcx,[rbp-50h]
  00000000000001FD: E8 00 00 00 00     call        replaced
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

  0000000000000202: 48 83 7D B7 00     cmp         qword ptr [rbp-49h],0
  0000000000000207: 74 23              je          000000000000022C
  0000000000000209: 48 8B 4D B7        mov         rcx,qword ptr [rbp-49h]
  000000000000020D: 0F B6 41 19        movzx       eax,byte ptr [rcx+19h]
  0000000000000211: 84 C0              test        al,al
  0000000000000213: 75 11              jne         0000000000000226
  0000000000000215: B8 01 00 00 00     mov         eax,1
  000000000000021A: 86 41 19           xchg        al,byte ptr [rcx+19h]
  000000000000021D: 84 C0              test        al,al
  000000000000021F: 0F 95 C0           setne       al
  0000000000000222: 84 C0              test        al,al
  0000000000000224: 74 C9              je          00000000000001EF
  0000000000000226: C6 45 B0 00        mov         byte ptr [rbp-50h],0
  000000000000022A: EB CD              jmp         00000000000001F9
  000000000000022C: 48 8B 5D BF        mov         rbx,qword ptr [rbp-41h]
  0000000000000230: 48 8D 45 97        lea         rax,[rbp-69h]
  0000000000000234: 48 89 45 C7        mov         qword ptr [rbp-39h],rax
  0000000000000238: 48 89 75 67        mov         qword ptr [rbp+67h],rsi
  000000000000023C: 0F B6 45 A7        movzx       eax,byte ptr [rbp-59h]
  0000000000000240: 88 46 10           mov         byte ptr [rsi+10h],al
  0000000000000243: 8B C8              mov         ecx,eax
  0000000000000245: 83 E9 01           sub         ecx,1
  0000000000000248: 74 33              je          000000000000027D
  000000000000024A: 83 E9 01           sub         ecx,1
  000000000000024D: 74 25              je          0000000000000274
  000000000000024F: 83 E9 01           sub         ecx,1
  0000000000000252: 74 12              je          0000000000000266
  0000000000000254: 83 F9 01           cmp         ecx,1
  0000000000000257: 75 29              jne         0000000000000282
  0000000000000259: 48 8B 45 97        mov         rax,qword ptr [rbp-69h]
  000000000000025D: 48 89 06           mov         qword ptr [rsi],rax
  0000000000000260: 4C 89 75 97        mov         qword ptr [rbp-69h],r14
  0000000000000264: EB 1C              jmp         0000000000000282
  0000000000000266: 48 8D 55 97        lea         rdx,[rbp-69h]
  000000000000026A: 48 8B CE           mov         rcx,rsi
  000000000000026D: E8 00 00 00 00     call        ?__ExceptionPtrCopy@@YAXPEAXPEBX@Z
  0000000000000272: EB 0E              jmp         0000000000000282
  0000000000000274: 0F 10 45 97        movups      xmm0,xmmword ptr [rbp-69h]
  0000000000000278: 0F 11 06           movups      xmmword ptr [rsi],xmm0
  000000000000027B: EB 05              jmp         0000000000000282
  000000000000027D: 8B 45 97           mov         eax,dword ptr [rbp-69h]
  0000000000000280: 89 06              mov         dword ptr [rsi],eax
  0000000000000282: C6 45 A7 00        mov         byte ptr [rbp-59h],0
  0000000000000286: 48 8B 45 B7        mov         rax,qword ptr [rbp-49h]
  000000000000028A: 48 85 C0           test        rax,rax
  000000000000028D: 74 10              je          000000000000029F
  000000000000028F: 48 89 46 20        mov         qword ptr [rsi+20h],rax
  0000000000000293: 4C 89 75 B7        mov         qword ptr [rbp-49h],r14
  0000000000000297: 48 85 DB           test        rbx,rbx
  000000000000029A: 74 03              je          000000000000029F
  000000000000029C: 48 89 33           mov         qword ptr [rbx],rsi
  000000000000029F: 48 85 DB           test        rbx,rbx
  00000000000002A2: 74 0E              je          00000000000002B2
  00000000000002A4: 80 7B 18 00        cmp         byte ptr [rbx+18h],0
  00000000000002A8: 74 04              je          00000000000002AE
  00000000000002AA: C6 43 19 00        mov         byte ptr [rbx+19h],0
  00000000000002AE: 4C 89 75 BF        mov         qword ptr [rbp-41h],r14
  00000000000002B2: 80 7D AF 00        cmp         byte ptr [rbp-51h],0
  00000000000002B6: 74 04              je          00000000000002BC
  00000000000002B8: C6 45 B0 00        mov         byte ptr [rbp-50h],0
  00000000000002BC: 4C 89 75 C7        mov         qword ptr [rbp-39h],r14
  00000000000002C0: C7 45 EF 01 00 00  mov         dword ptr [rbp-11h],1
                    00
  00000000000002C7: 0F 57 C0           xorps       xmm0,xmm0
  00000000000002CA: F3 0F 7F 45 CF     movdqu      xmmword ptr [rbp-31h],xmm0
  00000000000002CF: 80 7D AF 00        cmp         byte ptr [rbp-51h],0
  00000000000002D3: 75 0A              jne         00000000000002DF
  00000000000002D5: 48 8B 5D B7        mov         rbx,qword ptr [rbp-49h]
  00000000000002D9: 48 89 5D CF        mov         qword ptr [rbp-31h],rbx
  00000000000002DD: EB 35              jmp         0000000000000314
  00000000000002DF: 48 8D 4D B0        lea         rcx,[rbp-50h]
  00000000000002E3: E8 00 00 00 00     call        replaced
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

  00000000000002E8: 48 8B 4D B7        mov         rcx,qword ptr [rbp-49h]
  00000000000002EC: 48 85 C9           test        rcx,rcx
  00000000000002EF: 74 1F              je          0000000000000310
  00000000000002F1: 0F B6 41 19        movzx       eax,byte ptr [rcx+19h]
  00000000000002F5: 84 C0              test        al,al
  00000000000002F7: 75 11              jne         000000000000030A
  00000000000002F9: B8 01 00 00 00     mov         eax,1
  00000000000002FE: 86 41 19           xchg        al,byte ptr [rcx+19h]
  0000000000000301: 84 C0              test        al,al
  0000000000000303: 0F 95 C0           setne       al
  0000000000000306: 84 C0              test        al,al
  0000000000000308: 74 CB              je          00000000000002D5
  000000000000030A: C6 45 B0 00        mov         byte ptr [rbp-50h],0
  000000000000030E: EB CF              jmp         00000000000002DF
  0000000000000310: 48 8B 5D CF        mov         rbx,qword ptr [rbp-31h]
  0000000000000314: 48 8D 45 97        lea         rax,[rbp-69h]
  0000000000000318: 48 89 45 D7        mov         qword ptr [rbp-29h],rax
  000000000000031C: 48 85 DB           test        rbx,rbx
  000000000000031F: 74 29              je          000000000000034A
  0000000000000321: 0F B6 4B 10        movzx       ecx,byte ptr [rbx+10h]
  0000000000000325: 83 E9 01           sub         ecx,1
  0000000000000328: 74 1C              je          0000000000000346
  000000000000032A: 83 E9 01           sub         ecx,1
  000000000000032D: 74 17              je          0000000000000346
  000000000000032F: 83 E9 01           sub         ecx,1
  0000000000000332: 74 0A              je          000000000000033E
  0000000000000334: 83 F9 01           cmp         ecx,1
  0000000000000337: 75 11              jne         000000000000034A
  0000000000000339: 4C 89 33           mov         qword ptr [rbx],r14
  000000000000033C: EB 08              jmp         0000000000000346
  000000000000033E: 48 8B CB           mov         rcx,rbx
  0000000000000341: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  0000000000000346: C6 43 10 00        mov         byte ptr [rbx+10h],0
  000000000000034A: 0F B6 4D A7        movzx       ecx,byte ptr [rbp-59h]
  000000000000034E: 83 E9 01           sub         ecx,1
  0000000000000351: 74 1E              je          0000000000000371
  0000000000000353: 83 E9 01           sub         ecx,1
  0000000000000356: 74 19              je          0000000000000371
  0000000000000358: 83 E9 01           sub         ecx,1
  000000000000035B: 74 0B              je          0000000000000368
  000000000000035D: 83 F9 01           cmp         ecx,1
  0000000000000360: 75 13              jne         0000000000000375
  0000000000000362: 4C 89 75 97        mov         qword ptr [rbp-69h],r14
  0000000000000366: EB 09              jmp         0000000000000371
  0000000000000368: 48 8D 4D 97        lea         rcx,[rbp-69h]
  000000000000036C: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  0000000000000371: C6 45 A7 00        mov         byte ptr [rbp-59h],0
  0000000000000375: 48 85 DB           test        rbx,rbx
  0000000000000378: 74 0E              je          0000000000000388
  000000000000037A: 80 7B 18 00        cmp         byte ptr [rbx+18h],0
  000000000000037E: 74 04              je          0000000000000384
  0000000000000380: C6 43 19 00        mov         byte ptr [rbx+19h],0
  0000000000000384: 4C 89 75 CF        mov         qword ptr [rbp-31h],r14
  0000000000000388: 80 7D AF 00        cmp         byte ptr [rbp-51h],0
  000000000000038C: 74 04              je          0000000000000392
  000000000000038E: C6 45 B0 00        mov         byte ptr [rbp-50h],0
  0000000000000392: 0F B6 4D A7        movzx       ecx,byte ptr [rbp-59h]
  0000000000000396: 83 E9 01           sub         ecx,1
  0000000000000399: 74 14              je          00000000000003AF
  000000000000039B: 83 E9 01           sub         ecx,1
  000000000000039E: 74 0F              je          00000000000003AF
  00000000000003A0: 83 F9 01           cmp         ecx,1
  00000000000003A3: 75 0A              jne         00000000000003AF
  00000000000003A5: 48 8D 4D 97        lea         rcx,[rbp-69h]
  00000000000003A9: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  00000000000003AE: 90                 nop
  00000000000003AF: 48 8B C6           mov         rax,rsi
  00000000000003B2: 4C 8D 9C 24 D0 00  lea         r11,[rsp+0D0h]
                    00 00
  00000000000003BA: 49 8B 5B 30        mov         rbx,qword ptr [r11+30h]
  00000000000003BE: 49 8B 73 38        mov         rsi,qword ptr [r11+38h]
  00000000000003C2: 49 8B E3           mov         rsp,r11
  00000000000003C5: 41 5E              pop         r14
  00000000000003C7: 5F                 pop         rdi
  00000000000003C8: 5D                 pop         rbp
  00000000000003C9: C3                 ret
  00000000000003CA: CC                 int         3

  0000000000000052: 90                 nop
  0000000000000053: 48 8B 5C 24 40     mov         rbx,qword ptr [rsp+40h]
  0000000000000058: 48 85 DB           test        rbx,rbx
  000000000000005B: 0F 95 C0           setne       al
  000000000000005E: 84 C0              test        al,al
  0000000000000060: 75 6B              jne         00000000000000CD
  0000000000000062: C7 45 E0 04 00 00  mov         dword ptr [rbp-20h],4
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

  000000000000006E: 48 89 45 E8        mov         qword ptr [rbp-18h],rax
  0000000000000072: 48 8D 05 00 00 00  lea         rax,[??_7exception@std@@6B@]
                    00
  0000000000000079: 48 89 45 70        mov         qword ptr [rbp+70h],rax
  000000000000007D: 33 C0              xor         eax,eax
  000000000000007F: 48 89 45 78        mov         qword ptr [rbp+78h],rax
  0000000000000083: 48 89 85 80 00 00  mov         qword ptr [rbp+80h],rax
                    00
  000000000000008A: 48 8D 05 00 00 00  lea         rax,[??_C@_00CNPNBAHC@?$AA@]
                    00
  0000000000000091: 48 89 45 10        mov         qword ptr [rbp+10h],rax
  0000000000000095: C6 45 18 01        mov         byte ptr [rbp+18h],1
  0000000000000099: 48 8D 55 78        lea         rdx,[rbp+78h]
  000000000000009D: 48 8D 4D 10        lea         rcx,[rbp+10h]
  00000000000000A1: E8 00 00 00 00     call        __std_exception_copy
  00000000000000A6: 48 8D 05 00 00 00  lea         rax,[??_7future_error@std@@6B@]
                    00
  00000000000000AD: 48 89 45 70        mov         qword ptr [rbp+70h],rax
  00000000000000B1: 0F 10 45 E0        movups      xmm0,xmmword ptr [rbp-20h]
  00000000000000B5: 0F 11 85 88 00 00  movups      xmmword ptr [rbp+88h],xmm0
                    00
  00000000000000BC: 48 8D 15 00 00 00  lea         rdx,[_TI3?AVfuture_error@std@@]
                    00
  00000000000000C3: 48 8D 4D 70        lea         rcx,[rbp+70h]
  00000000000000C7: E8 00 00 00 00     call        _CxxThrowException
  00000000000000CC: CC                 int         3
  00000000000000CD: 80 7C 24 30 00     cmp         byte ptr [rsp+30h],0
  00000000000000D2: 0F 95 C0           setne       al
  00000000000000D5: 84 C0              test        al,al
  00000000000000D7: 74 FC              je          00000000000000D5
  00000000000000D9: 0F 57 C0           xorps       xmm0,xmm0
  00000000000000DC: F3 0F 7F 45 88     movdqu      xmmword ptr [rbp-78h],xmm0
  00000000000000E1: 80 7C 24 38 00     cmp         byte ptr [rsp+38h],0
  00000000000000E6: 75 06              jne         00000000000000EE
  00000000000000E8: 48 89 5D 88        mov         qword ptr [rbp-78h],rbx
  00000000000000EC: EB 43              jmp         0000000000000131
  00000000000000EE: 48 8D 4C 24 39     lea         rcx,[rsp+39h]
  00000000000000F3: E8 00 00 00 00     call        replaced
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

  00000000000000F8: 48 8B 4C 24 40     mov         rcx,qword ptr [rsp+40h]
  00000000000000FD: 48 85 C9           test        rcx,rcx
  0000000000000100: 74 2B              je          000000000000012D
  0000000000000102: 0F B6 41 19        movzx       eax,byte ptr [rcx+19h]
  0000000000000106: 84 C0              test        al,al
  0000000000000108: 75 11              jne         000000000000011B
  000000000000010A: B8 01 00 00 00     mov         eax,1
  000000000000010F: 86 41 19           xchg        al,byte ptr [rcx+19h]
  0000000000000112: 84 C0              test        al,al
  0000000000000114: 0F 95 C0           setne       al
  0000000000000117: 84 C0              test        al,al
  0000000000000119: 74 07              je          0000000000000122
  000000000000011B: C6 44 24 39 00     mov         byte ptr [rsp+39h],0
  0000000000000120: EB CC              jmp         00000000000000EE
  0000000000000122: 48 8B 5C 24 40     mov         rbx,qword ptr [rsp+40h]
  0000000000000127: 48 89 5D 88        mov         qword ptr [rbp-78h],rbx
  000000000000012B: EB 04              jmp         0000000000000131
  000000000000012D: 48 8B 5D 88        mov         rbx,qword ptr [rbp-78h]
  0000000000000131: 48 8D 44 24 20     lea         rax,[rsp+20h]
  0000000000000136: 48 89 45 90        mov         qword ptr [rbp-70h],rax
  000000000000013A: 80 7C 24 30 00     cmp         byte ptr [rsp+30h],0
  000000000000013F: 0F 95 C0           setne       al
  0000000000000142: 84 C0              test        al,al
  0000000000000144: 75 65              jne         00000000000001AB
  0000000000000146: C7 45 00 04 00 00  mov         dword ptr [rbp],4
                    00
  000000000000014D: E8 00 00 00 00     call        replaced
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

  0000000000000152: 48 89 45 08        mov         qword ptr [rbp+8],rax
  0000000000000156: 48 8D 05 00 00 00  lea         rax,[??_7exception@std@@6B@]
                    00
  000000000000015D: 48 89 45 48        mov         qword ptr [rbp+48h],rax
  0000000000000161: 33 C0              xor         eax,eax
  0000000000000163: 48 89 45 50        mov         qword ptr [rbp+50h],rax
  0000000000000167: 48 89 45 58        mov         qword ptr [rbp+58h],rax
  000000000000016B: 48 8D 05 00 00 00  lea         rax,[??_C@_00CNPNBAHC@?$AA@]
                    00
  0000000000000172: 48 89 45 F0        mov         qword ptr [rbp-10h],rax
  0000000000000176: C6 45 F8 01        mov         byte ptr [rbp-8],1
  000000000000017A: 48 8D 55 50        lea         rdx,[rbp+50h]
  000000000000017E: 48 8D 4D F0        lea         rcx,[rbp-10h]
  0000000000000182: E8 00 00 00 00     call        __std_exception_copy
  0000000000000187: 48 8D 05 00 00 00  lea         rax,[??_7future_error@std@@6B@]
                    00
  000000000000018E: 48 89 45 48        mov         qword ptr [rbp+48h],rax
  0000000000000192: 0F 10 45 00        movups      xmm0,xmmword ptr [rbp]
  0000000000000196: 0F 11 45 60        movups      xmmword ptr [rbp+60h],xmm0
  000000000000019A: 48 8D 15 00 00 00  lea         rdx,[_TI3?AVfuture_error@std@@]
                    00
  00000000000001A1: 48 8D 4D 48        lea         rcx,[rbp+48h]
  00000000000001A5: E8 00 00 00 00     call        _CxxThrowException
  00000000000001AA: CC                 int         3
  00000000000001AB: 0F B6 4C 24 30     movzx       ecx,byte ptr [rsp+30h]
  00000000000001B0: 80 F9 02           cmp         cl,2
  00000000000001B3: 0F 94 C0           sete        al
  00000000000001B6: 84 C0              test        al,al
  00000000000001B8: 75 0C              jne         00000000000001C6
  00000000000001BA: 80 E9 02           sub         cl,2
  00000000000001BD: 80 F9 01           cmp         cl,1
  00000000000001C0: 0F 87 B1 00 00 00  ja          0000000000000277
  00000000000001C6: 48 8D 4D 98        lea         rcx,[rbp-68h]
  00000000000001CA: E8 00 00 00 00     call        ?__ExceptionPtrCreate@@YAXPEAX@Z
  00000000000001CF: 90                 nop
  00000000000001D0: 0F B6 4C 24 30     movzx       ecx,byte ptr [rsp+30h]
  00000000000001D5: 80 F9 02           cmp         cl,2
  00000000000001D8: 0F 94 C0           sete        al
  00000000000001DB: 84 C0              test        al,al
  00000000000001DD: 74 4D              je          000000000000022C
  00000000000001DF: 0F 10 44 24 20     movups      xmm0,xmmword ptr [rsp+20h]
  00000000000001E4: 0F 29 85 B0 00 00  movaps      xmmword ptr [rbp+0B0h],xmm0
                    00
  00000000000001EB: 48 8D 95 B0 00 00  lea         rdx,[rbp+0B0h]
                    00
  00000000000001F2: 48 8D 8D 00 01 00  lea         rcx,[rbp+100h]
                    00
  00000000000001F9: E8 00 00 00 00     call        replaced
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

  00000000000001FE: 48 8B D0           mov         rdx,rax
  0000000000000201: 48 8D 8D 98 00 00  lea         rcx,[rbp+98h]
                    00
  0000000000000208: E8 00 00 00 00     call        replaced
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
  0000000000000026: 4C 8D 05 00 00 00  lea         r8,[_TI4?AVsystem_error@std@@]
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

  000000000000020D: 90                 nop
  000000000000020E: 48 8B D0           mov         rdx,rax
  0000000000000211: 48 8D 4D 98        lea         rcx,[rbp-68h]
  0000000000000215: E8 00 00 00 00     call        ?__ExceptionPtrAssign@@YAXPEAXPEBX@Z
  000000000000021A: 90                 nop
  000000000000021B: 48 8D 8D 98 00 00  lea         rcx,[rbp+98h]
                    00
  0000000000000222: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  0000000000000227: 0F B6 4C 24 30     movzx       ecx,byte ptr [rsp+30h]
  000000000000022C: 80 E9 02           sub         cl,2
  000000000000022F: 80 F9 01           cmp         cl,1
  0000000000000232: 77 0E              ja          0000000000000242
  0000000000000234: 48 8D 54 24 20     lea         rdx,[rsp+20h]
  0000000000000239: 48 8D 4D 98        lea         rcx,[rbp-68h]
  000000000000023D: E8 00 00 00 00     call        ?__ExceptionPtrAssign@@YAXPEAXPEBX@Z
  0000000000000242: 48 8D 55 98        lea         rdx,[rbp-68h]
  0000000000000246: 48 8D 4D A8        lea         rcx,[rbp-58h]
  000000000000024A: E8 00 00 00 00     call        ?__ExceptionPtrCopy@@YAXPEAXPEBX@Z
  000000000000024F: 48 8D 45 A8        lea         rax,[rbp-58h]
  0000000000000253: 48 89 85 60 01 00  mov         qword ptr [rbp+160h],rax
                    00
  000000000000025A: 48 8D 4D A8        lea         rcx,[rbp-58h]
  000000000000025E: E8 00 00 00 00     call        ?__ExceptionPtrRethrow@@YAXPEBX@Z
  0000000000000263: 90                 nop
  0000000000000264: 48 8D 4D A8        lea         rcx,[rbp-58h]
  0000000000000268: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  000000000000026D: 90                 nop
  000000000000026E: 48 8D 4D 98        lea         rcx,[rbp-68h]
  0000000000000272: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  0000000000000277: 8B 44 24 20        mov         eax,dword ptr [rsp+20h]
  000000000000027B: 89 85 60 01 00 00  mov         dword ptr [rbp+160h],eax
  0000000000000281: 0F B6 4C 24 30     movzx       ecx,byte ptr [rsp+30h]
  0000000000000286: 33 F6              xor         esi,esi
  0000000000000288: 83 E9 01           sub         ecx,1
  000000000000028B: 74 20              je          00000000000002AD
  000000000000028D: 83 E9 01           sub         ecx,1
  0000000000000290: 74 1B              je          00000000000002AD
  0000000000000292: 83 E9 01           sub         ecx,1
  0000000000000295: 74 0C              je          00000000000002A3
  0000000000000297: 83 F9 01           cmp         ecx,1
  000000000000029A: 75 16              jne         00000000000002B2
  000000000000029C: 48 89 74 24 20     mov         qword ptr [rsp+20h],rsi
  00000000000002A1: EB 0A              jmp         00000000000002AD
  00000000000002A3: 48 8D 4C 24 20     lea         rcx,[rsp+20h]
  00000000000002A8: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  00000000000002AD: 40 88 74 24 30     mov         byte ptr [rsp+30h],sil
  00000000000002B2: 48 85 DB           test        rbx,rbx
  00000000000002B5: 74 29              je          00000000000002E0
  00000000000002B7: 0F B6 4B 10        movzx       ecx,byte ptr [rbx+10h]
  00000000000002BB: 83 E9 01           sub         ecx,1
  00000000000002BE: 74 1C              je          00000000000002DC
  00000000000002C0: 83 E9 01           sub         ecx,1
  00000000000002C3: 74 17              je          00000000000002DC
  00000000000002C5: 83 E9 01           sub         ecx,1
  00000000000002C8: 74 0A              je          00000000000002D4
  00000000000002CA: 83 F9 01           cmp         ecx,1
  00000000000002CD: 75 11              jne         00000000000002E0
  00000000000002CF: 48 89 33           mov         qword ptr [rbx],rsi
  00000000000002D2: EB 08              jmp         00000000000002DC
  00000000000002D4: 48 8B CB           mov         rcx,rbx
  00000000000002D7: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  00000000000002DC: C6 43 10 00        mov         byte ptr [rbx+10h],0
  00000000000002E0: 48 89 74 24 40     mov         qword ptr [rsp+40h],rsi
  00000000000002E5: 48 85 DB           test        rbx,rbx
  00000000000002E8: 74 0E              je          00000000000002F8
  00000000000002EA: 80 7B 18 00        cmp         byte ptr [rbx+18h],0
  00000000000002EE: 74 04              je          00000000000002F4
  00000000000002F0: C6 43 19 00        mov         byte ptr [rbx+19h],0
  00000000000002F4: 48 89 75 88        mov         qword ptr [rbp-78h],rsi
  00000000000002F8: 80 7C 24 38 00     cmp         byte ptr [rsp+38h],0
  00000000000002FD: 74 05              je          0000000000000304
  00000000000002FF: C6 44 24 39 00     mov         byte ptr [rsp+39h],0
  0000000000000304: 48 89 75 90        mov         qword ptr [rbp-70h],rsi
  0000000000000308: 0F 57 C0           xorps       xmm0,xmm0
  000000000000030B: F3 0F 7F 44 24 78  movdqu      xmmword ptr [rsp+78h],xmm0
  0000000000000311: 80 7C 24 38 00     cmp         byte ptr [rsp+38h],0
  0000000000000316: 75 0C              jne         0000000000000324
  0000000000000318: 48 8B 5C 24 40     mov         rbx,qword ptr [rsp+40h]
  000000000000031D: 48 89 5C 24 78     mov         qword ptr [rsp+78h],rbx
  0000000000000322: EB 39              jmp         000000000000035D
  0000000000000324: 48 8D 4C 24 39     lea         rcx,[rsp+39h]
  0000000000000329: E8 00 00 00 00     call        replaced
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

  000000000000032E: 48 8B 4C 24 40     mov         rcx,qword ptr [rsp+40h]
  0000000000000333: 48 85 C9           test        rcx,rcx
  0000000000000336: 74 20              je          0000000000000358
  0000000000000338: 0F B6 41 19        movzx       eax,byte ptr [rcx+19h]
  000000000000033C: 84 C0              test        al,al
  000000000000033E: 75 11              jne         0000000000000351
  0000000000000340: B8 01 00 00 00     mov         eax,1
  0000000000000345: 86 41 19           xchg        al,byte ptr [rcx+19h]
  0000000000000348: 84 C0              test        al,al
  000000000000034A: 0F 95 C0           setne       al
  000000000000034D: 84 C0              test        al,al
  000000000000034F: 74 C7              je          0000000000000318
  0000000000000351: C6 44 24 39 00     mov         byte ptr [rsp+39h],0
  0000000000000356: EB CC              jmp         0000000000000324
  0000000000000358: 48 8B 5C 24 78     mov         rbx,qword ptr [rsp+78h]
  000000000000035D: 48 8D 44 24 20     lea         rax,[rsp+20h]
  0000000000000362: 48 89 45 80        mov         qword ptr [rbp-80h],rax
  0000000000000366: 48 85 DB           test        rbx,rbx
  0000000000000369: 74 29              je          0000000000000394
  000000000000036B: 0F B6 4B 10        movzx       ecx,byte ptr [rbx+10h]
  000000000000036F: 83 E9 01           sub         ecx,1
  0000000000000372: 74 1C              je          0000000000000390
  0000000000000374: 83 E9 01           sub         ecx,1
  0000000000000377: 74 17              je          0000000000000390
  0000000000000379: 83 E9 01           sub         ecx,1
  000000000000037C: 74 0A              je          0000000000000388
  000000000000037E: 83 F9 01           cmp         ecx,1
  0000000000000381: 75 11              jne         0000000000000394
  0000000000000383: 48 89 33           mov         qword ptr [rbx],rsi
  0000000000000386: EB 08              jmp         0000000000000390
  0000000000000388: 48 8B CB           mov         rcx,rbx
  000000000000038B: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  0000000000000390: C6 43 10 00        mov         byte ptr [rbx+10h],0
  0000000000000394: 0F B6 4C 24 30     movzx       ecx,byte ptr [rsp+30h]
  0000000000000399: 83 E9 01           sub         ecx,1
  000000000000039C: 74 20              je          00000000000003BE
  000000000000039E: 83 E9 01           sub         ecx,1
  00000000000003A1: 74 1B              je          00000000000003BE
  00000000000003A3: 83 E9 01           sub         ecx,1
  00000000000003A6: 74 0C              je          00000000000003B4
  00000000000003A8: 83 F9 01           cmp         ecx,1
  00000000000003AB: 75 16              jne         00000000000003C3
  00000000000003AD: 48 89 74 24 20     mov         qword ptr [rsp+20h],rsi
  00000000000003B2: EB 0A              jmp         00000000000003BE
  00000000000003B4: 48 8D 4C 24 20     lea         rcx,[rsp+20h]
  00000000000003B9: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  00000000000003BE: C6 44 24 30 00     mov         byte ptr [rsp+30h],0
  00000000000003C3: 48 85 DB           test        rbx,rbx
  00000000000003C6: 74 0F              je          00000000000003D7
  00000000000003C8: 80 7B 18 00        cmp         byte ptr [rbx+18h],0
  00000000000003CC: 74 04              je          00000000000003D2
  00000000000003CE: C6 43 19 00        mov         byte ptr [rbx+19h],0
  00000000000003D2: 48 89 74 24 78     mov         qword ptr [rsp+78h],rsi
  00000000000003D7: 80 7C 24 38 00     cmp         byte ptr [rsp+38h],0
  00000000000003DC: 74 05              je          00000000000003E3
  00000000000003DE: C6 44 24 39 00     mov         byte ptr [rsp+39h],0
  00000000000003E3: 48 89 75 80        mov         qword ptr [rbp-80h],rsi
  00000000000003E7: 0F B6 4C 24 30     movzx       ecx,byte ptr [rsp+30h]
  00000000000003EC: 83 E9 01           sub         ecx,1
  00000000000003EF: 74 20              je          0000000000000411
  00000000000003F1: 83 E9 01           sub         ecx,1
  00000000000003F4: 74 1B              je          0000000000000411
  00000000000003F6: 83 E9 01           sub         ecx,1
  00000000000003F9: 74 0C              je          0000000000000407
  00000000000003FB: 83 F9 01           cmp         ecx,1
  00000000000003FE: 75 16              jne         0000000000000416
  0000000000000400: 48 89 74 24 20     mov         qword ptr [rsp+20h],rsi
  0000000000000405: EB 0A              jmp         0000000000000411
  0000000000000407: 48 8D 4C 24 20     lea         rcx,[rsp+20h]
  000000000000040C: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  0000000000000411: C6 44 24 30 00     mov         byte ptr [rsp+30h],0
  0000000000000416: 0F 57 C0           xorps       xmm0,xmm0
  0000000000000419: F3 0F 7F 44 24 68  movdqu      xmmword ptr [rsp+68h],xmm0
  000000000000041F: 80 7C 24 60 00     cmp         byte ptr [rsp+60h],0
  0000000000000424: 75 1D              jne         0000000000000443
  0000000000000426: 48 8D 44 24 48     lea         rax,[rsp+48h]
  000000000000042B: 48 89 44 24 68     mov         qword ptr [rsp+68h],rax
  0000000000000430: 80 7C 24 58 04     cmp         byte ptr [rsp+58h],4
  0000000000000435: 75 62              jne         0000000000000499
  0000000000000437: 48 8B 5C 24 48     mov         rbx,qword ptr [rsp+48h]
  000000000000043C: 48 89 5C 24 70     mov         qword ptr [rsp+70h],rbx
  0000000000000441: EB 5B              jmp         000000000000049E
  0000000000000443: 48 8D 4C 24 61     lea         rcx,[rsp+61h]
  0000000000000448: E8 00 00 00 00     call        replaced
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

  000000000000044D: 80 7C 24 58 04     cmp         byte ptr [rsp+58h],4
  0000000000000452: 75 3B              jne         000000000000048F
  0000000000000454: 48 8B 4C 24 48     mov         rcx,qword ptr [rsp+48h]
  0000000000000459: 0F B6 41 19        movzx       eax,byte ptr [rcx+19h]
  000000000000045D: 84 C0              test        al,al
  000000000000045F: 75 11              jne         0000000000000472
  0000000000000461: B8 01 00 00 00     mov         eax,1
  0000000000000466: 86 41 19           xchg        al,byte ptr [rcx+19h]
  0000000000000469: 84 C0              test        al,al
  000000000000046B: 0F 95 C0           setne       al
  000000000000046E: 84 C0              test        al,al
  0000000000000470: 74 07              je          0000000000000479
  0000000000000472: C6 44 24 61 00     mov         byte ptr [rsp+61h],0
  0000000000000477: EB CA              jmp         0000000000000443
  0000000000000479: 48 8D 44 24 48     lea         rax,[rsp+48h]
  000000000000047E: 48 89 44 24 68     mov         qword ptr [rsp+68h],rax
  0000000000000483: 48 8B 5C 24 48     mov         rbx,qword ptr [rsp+48h]
  0000000000000488: 48 89 5C 24 70     mov         qword ptr [rsp+70h],rbx
  000000000000048D: EB 0F              jmp         000000000000049E
  000000000000048F: 48 8D 44 24 48     lea         rax,[rsp+48h]
  0000000000000494: 48 89 44 24 68     mov         qword ptr [rsp+68h],rax
  0000000000000499: 48 8B 5C 24 70     mov         rbx,qword ptr [rsp+70h]
  000000000000049E: 48 85 DB           test        rbx,rbx
  00000000000004A1: 0F 84 D9 00 00 00  je          0000000000000580
  00000000000004A7: 80 7B 10 00        cmp         byte ptr [rbx+10h],0
  00000000000004AB: 0F 95 C0           setne       al
  00000000000004AE: 84 C0              test        al,al
  00000000000004B0: 0F 85 C6 00 00 00  jne         000000000000057C
  00000000000004B6: E8 00 00 00 00     call        replaced
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

  00000000000004BB: C7 45 D0 01 00 00  mov         dword ptr [rbp-30h],1
                    00
  00000000000004C2: 48 89 45 D8        mov         qword ptr [rbp-28h],rax
  00000000000004C6: 0F 28 75 D0        movaps      xmm6,xmmword ptr [rbp-30h]
  00000000000004CA: 66 0F 7F B5 E0 00  movdqa      xmmword ptr [rbp+0E0h],xmm6
                    00 00
  00000000000004D2: 48 8D 05 00 00 00  lea         rax,[??_7exception@std@@6B@]
                    00
  00000000000004D9: 48 89 45 20        mov         qword ptr [rbp+20h],rax
  00000000000004DD: 33 C0              xor         eax,eax
  00000000000004DF: 48 89 45 28        mov         qword ptr [rbp+28h],rax
  00000000000004E3: 48 89 45 30        mov         qword ptr [rbp+30h],rax
  00000000000004E7: 48 8D 05 00 00 00  lea         rax,[??_C@_00CNPNBAHC@?$AA@]
                    00
  00000000000004EE: 48 89 45 B8        mov         qword ptr [rbp-48h],rax
  00000000000004F2: C6 45 C0 01        mov         byte ptr [rbp-40h],1
  00000000000004F6: 48 8D 55 28        lea         rdx,[rbp+28h]
  00000000000004FA: 48 8D 4D B8        lea         rcx,[rbp-48h]
  00000000000004FE: E8 00 00 00 00     call        __std_exception_copy
  0000000000000503: 48 8D 05 00 00 00  lea         rax,[??_7future_error@std@@6B@]
                    00
  000000000000050A: 48 89 45 20        mov         qword ptr [rbp+20h],rax
  000000000000050E: 0F 11 75 38        movups      xmmword ptr [rbp+38h],xmm6
  0000000000000512: 48 8D 55 20        lea         rdx,[rbp+20h]
  0000000000000516: 48 8D 8D F0 00 00  lea         rcx,[rbp+0F0h]
                    00
  000000000000051D: E8 00 00 00 00     call        replaced
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

  0000000000000522: 48 8B F8           mov         rdi,rax
  0000000000000525: 48 89 85 70 01 00  mov         qword ptr [rbp+170h],rax
                    00
  000000000000052C: 0F B6 53 10        movzx       edx,byte ptr [rbx+10h]
  0000000000000530: 83 EA 01           sub         edx,1
  0000000000000533: 74 1C              je          0000000000000551
  0000000000000535: 83 EA 01           sub         edx,1
  0000000000000538: 74 17              je          0000000000000551
  000000000000053A: 83 EA 01           sub         edx,1
  000000000000053D: 74 0A              je          0000000000000549
  000000000000053F: 83 FA 01           cmp         edx,1
  0000000000000542: 75 11              jne         0000000000000555
  0000000000000544: 48 89 33           mov         qword ptr [rbx],rsi
  0000000000000547: EB 08              jmp         0000000000000551
  0000000000000549: 48 8B CB           mov         rcx,rbx
  000000000000054C: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  0000000000000551: C6 43 10 00        mov         byte ptr [rbx+10h],0
  0000000000000555: 48 8B D7           mov         rdx,rdi
  0000000000000558: 48 8D 8D C0 00 00  lea         rcx,[rbp+0C0h]
                    00
  000000000000055F: E8 00 00 00 00     call        ?__ExceptionPtrCopy@@YAXPEAXPEBX@Z
  0000000000000564: 48 8D 95 C0 00 00  lea         rdx,[rbp+0C0h]
                    00
  000000000000056B: 48 8B CB           mov         rcx,rbx
  000000000000056E: E8 00 00 00 00     call        replaced
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

  0000000000000573: 90                 nop
  0000000000000574: 48 8B CF           mov         rcx,rdi
  0000000000000577: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  000000000000057C: 48 89 73 20        mov         qword ptr [rbx+20h],rsi
  0000000000000580: 0F B6 4C 24 58     movzx       ecx,byte ptr [rsp+58h]
  0000000000000585: 83 E9 01           sub         ecx,1
  0000000000000588: 74 20              je          00000000000005AA
  000000000000058A: 83 E9 01           sub         ecx,1
  000000000000058D: 74 1B              je          00000000000005AA
  000000000000058F: 83 E9 01           sub         ecx,1
  0000000000000592: 74 0C              je          00000000000005A0
  0000000000000594: 83 F9 01           cmp         ecx,1
  0000000000000597: 75 16              jne         00000000000005AF
  0000000000000599: 48 89 74 24 48     mov         qword ptr [rsp+48h],rsi
  000000000000059E: EB 0A              jmp         00000000000005AA
  00000000000005A0: 48 8D 4C 24 48     lea         rcx,[rsp+48h]
  00000000000005A5: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  00000000000005AA: C6 44 24 58 00     mov         byte ptr [rsp+58h],0
  00000000000005AF: 80 7C 24 60 00     cmp         byte ptr [rsp+60h],0
  00000000000005B4: 74 05              je          00000000000005BB
  00000000000005B6: C6 44 24 61 00     mov         byte ptr [rsp+61h],0
  00000000000005BB: 48 89 74 24 68     mov         qword ptr [rsp+68h],rsi
  00000000000005C0: 48 85 DB           test        rbx,rbx
  00000000000005C3: 74 0A              je          00000000000005CF
  00000000000005C5: 80 7B 18 00        cmp         byte ptr [rbx+18h],0
  00000000000005C9: 74 04              je          00000000000005CF
  00000000000005CB: C6 43 19 00        mov         byte ptr [rbx+19h],0
  00000000000005CF: 0F B6 4C 24 58     movzx       ecx,byte ptr [rsp+58h]
  00000000000005D4: 83 E9 01           sub         ecx,1
  00000000000005D7: 74 15              je          00000000000005EE
  00000000000005D9: 83 E9 01           sub         ecx,1
  00000000000005DC: 74 10              je          00000000000005EE
  00000000000005DE: 83 F9 01           cmp         ecx,1
  00000000000005E1: 75 0B              jne         00000000000005EE
  00000000000005E3: 48 8D 4C 24 48     lea         rcx,[rsp+48h]
  00000000000005E8: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  00000000000005ED: 90                 nop
  00000000000005EE: 8B 85 60 01 00 00  mov         eax,dword ptr [rbp+160h]
  00000000000005F4: 48 8B 9C 24 78 02  mov         rbx,qword ptr [rsp+278h]
                    00 00
  00000000000005FC: 0F 28 B4 24 30 02  movaps      xmm6,xmmword ptr [rsp+230h]
                    00 00
  0000000000000604: 48 81 C4 40 02 00  add         rsp,240h
                    00
  000000000000060B: 5F                 pop         rdi
  000000000000060C: 5E                 pop         rsi
  000000000000060D: 5D                 pop         rbp
  000000000000060E: C3                 ret
