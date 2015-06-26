  0000000000000000: 48 8B C4           mov         rax,rsp
  0000000000000003: 55                 push        rbp
  0000000000000004: 56                 push        rsi
  0000000000000005: 57                 push        rdi
  0000000000000006: 48 8D A8 E8 FE FF  lea         rbp,[rax-118h]
                    FF
  000000000000000D: 48 81 EC 00 02 00  sub         rsp,200h
                    00
  0000000000000014: 48 C7 85 88 00 00  mov         qword ptr [rbp+88h],0FFFFFFFFFFFFFFFEh
                    00 FE FF FF FF
  000000000000001F: 48 89 58 20        mov         qword ptr [rax+20h],rbx
  0000000000000023: 0F 29 70 D8        movaps      xmmword ptr [rax-28h],xmm6
  0000000000000027: C6 44 24 60 00     mov         byte ptr [rsp+60h],0
  000000000000002C: C7 85 28 01 00 00  mov         dword ptr [rbp+128h],5
                    05 00 00 00
  0000000000000036: C7 44 24 48 05 00  mov         dword ptr [rsp+48h],5
                    00 00
  000000000000003E: C6 44 24 58 01     mov         byte ptr [rsp+58h],1
  0000000000000043: 48 8D 54 24 20     lea         rdx,[rsp+20h]
  0000000000000048: 48 8D 4C 24 48     lea         rcx,[rsp+48h]
  000000000000004D: E8 00 00 00 00     call        replaced
  0000000000000000: 48 8B C4           mov         rax,rsp
  0000000000000003: 48 89 50 10        mov         qword ptr [rax+10h],rdx
  0000000000000007: 57                 push        rdi
  0000000000000008: 48 81 EC 90 00 00  sub         rsp,90h
                    00
  000000000000000F: 48 C7 40 90 FE FF  mov         qword ptr [rax-70h],0FFFFFFFFFFFFFFFEh
                    FF FF
  0000000000000017: 48 89 58 08        mov         qword ptr [rax+8],rbx
  000000000000001B: 48 89 70 18        mov         qword ptr [rax+18h],rsi
  000000000000001F: 48 8B FA           mov         rdi,rdx
  0000000000000022: 48 8B D9           mov         rbx,rcx
  0000000000000025: C7 44 24 20 00 00  mov         dword ptr [rsp+20h],0
                    00 00
  000000000000002D: 80 79 18 00        cmp         byte ptr [rcx+18h],0
  0000000000000031: 75 19              jne         000000000000004C
  0000000000000033: 80 79 10 00        cmp         byte ptr [rcx+10h],0
  0000000000000037: 75 13              jne         000000000000004C
  0000000000000039: C6 41 18 01        mov         byte ptr [rcx+18h],1
  000000000000003D: 48 8D 41 19        lea         rax,[rcx+19h]
  0000000000000041: 48 85 C0           test        rax,rax
  0000000000000044: 74 06              je          000000000000004C
  0000000000000046: C6 00 00           mov         byte ptr [rax],0
  0000000000000049: C6 00 00           mov         byte ptr [rax],0
  000000000000004C: 0F 57 C0           xorps       xmm0,xmm0
  000000000000004F: F3 0F 7F 44 24 30  movdqu      xmmword ptr [rsp+30h],xmm0
  0000000000000055: 80 79 18 00        cmp         byte ptr [rcx+18h],0
  0000000000000059: 75 15              jne         0000000000000070
  000000000000005B: 48 89 4C 24 30     mov         qword ptr [rsp+30h],rcx
  0000000000000060: 80 79 10 04        cmp         byte ptr [rcx+10h],4
  0000000000000064: 75 4C              jne         00000000000000B2
  0000000000000066: 48 8B 01           mov         rax,qword ptr [rcx]
  0000000000000069: 48 89 44 24 38     mov         qword ptr [rsp+38h],rax
  000000000000006E: EB 42              jmp         00000000000000B2
  0000000000000070: 48 83 C1 19        add         rcx,19h
  0000000000000074: E8 00 00 00 00     call        replaced
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

  0000000000000079: 80 7B 10 04        cmp         byte ptr [rbx+10h],4
  000000000000007D: 75 2E              jne         00000000000000AD
  000000000000007F: 48 8B 0B           mov         rcx,qword ptr [rbx]
  0000000000000082: 0F B6 41 19        movzx       eax,byte ptr [rcx+19h]
  0000000000000086: 84 C0              test        al,al
  0000000000000088: 75 11              jne         000000000000009B
  000000000000008A: B8 01 00 00 00     mov         eax,1
  000000000000008F: 86 41 19           xchg        al,byte ptr [rcx+19h]
  0000000000000092: 84 C0              test        al,al
  0000000000000094: 0F 95 C0           setne       al
  0000000000000097: 84 C0              test        al,al
  0000000000000099: 74 0A              je          00000000000000A5
  000000000000009B: C6 43 19 00        mov         byte ptr [rbx+19h],0
  000000000000009F: 48 8D 4B 19        lea         rcx,[rbx+19h]
  00000000000000A3: EB CF              jmp         0000000000000074
  00000000000000A5: 48 8B 03           mov         rax,qword ptr [rbx]
  00000000000000A8: 48 89 44 24 38     mov         qword ptr [rsp+38h],rax
  00000000000000AD: 48 89 5C 24 30     mov         qword ptr [rsp+30h],rbx
  00000000000000B2: 48 83 7C 24 38 00  cmp         qword ptr [rsp+38h],0
  00000000000000B8: 74 72              je          000000000000012C
  00000000000000BA: C7 44 24 50 02 00  mov         dword ptr [rsp+50h],2
                    00 00
  00000000000000C2: E8 00 00 00 00     call        replaced
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

  00000000000000C7: 48 89 44 24 58     mov         qword ptr [rsp+58h],rax
  00000000000000CC: 48 8D 05 00 00 00  lea         rax,[??_7exception@std@@6B@]
                    00
  00000000000000D3: 48 89 44 24 60     mov         qword ptr [rsp+60h],rax
  00000000000000D8: 33 C0              xor         eax,eax
  00000000000000DA: 48 89 44 24 68     mov         qword ptr [rsp+68h],rax
  00000000000000DF: 48 89 44 24 70     mov         qword ptr [rsp+70h],rax
  00000000000000E4: 48 8D 05 00 00 00  lea         rax,[??_C@_00CNPNBAHC@?$AA@]
                    00
  00000000000000EB: 48 89 44 24 40     mov         qword ptr [rsp+40h],rax
  00000000000000F0: C6 44 24 48 01     mov         byte ptr [rsp+48h],1
  00000000000000F5: 48 8D 54 24 68     lea         rdx,[rsp+68h]
  00000000000000FA: 48 8D 4C 24 40     lea         rcx,[rsp+40h]
  00000000000000FF: E8 00 00 00 00     call        __std_exception_copy
  0000000000000104: 48 8D 05 00 00 00  lea         rax,[??_7future_error@std@@6B@]
                    00
  000000000000010B: 48 89 44 24 60     mov         qword ptr [rsp+60h],rax
  0000000000000110: 0F 10 44 24 50     movups      xmm0,xmmword ptr [rsp+50h]
  0000000000000115: 0F 11 44 24 78     movups      xmmword ptr [rsp+78h],xmm0
  000000000000011A: 48 8D 15 00 00 00  lea         rdx,[_TI3?AVfuture_error@std@@]
                    00
  0000000000000121: 48 8D 4C 24 60     lea         rcx,[rsp+60h]
  0000000000000126: E8 00 00 00 00     call        _CxxThrowException
  000000000000012B: 90                 nop
  000000000000012C: C6 47 10 00        mov         byte ptr [rdi+10h],0
  0000000000000130: 0F B6 4B 10        movzx       ecx,byte ptr [rbx+10h]
  0000000000000134: 83 E9 01           sub         ecx,1
  0000000000000137: 74 33              je          000000000000016C
  0000000000000139: 83 E9 01           sub         ecx,1
  000000000000013C: 74 26              je          0000000000000164
  000000000000013E: 83 E9 01           sub         ecx,1
  0000000000000141: 74 14              je          0000000000000157
  0000000000000143: 83 F9 01           cmp         ecx,1
  0000000000000146: 75 28              jne         0000000000000170
  0000000000000148: 48 8B 03           mov         rax,qword ptr [rbx]
  000000000000014B: 48 89 07           mov         qword ptr [rdi],rax
  000000000000014E: 48 C7 03 00 00 00  mov         qword ptr [rbx],0
                    00
  0000000000000155: EB 19              jmp         0000000000000170
  0000000000000157: 48 8B D3           mov         rdx,rbx
  000000000000015A: 48 8B CF           mov         rcx,rdi
  000000000000015D: E8 00 00 00 00     call        ?__ExceptionPtrCopy@@YAXPEAXPEBX@Z
  0000000000000162: EB 0C              jmp         0000000000000170
  0000000000000164: 0F 10 03           movups      xmm0,xmmword ptr [rbx]
  0000000000000167: 0F 11 07           movups      xmmword ptr [rdi],xmm0
  000000000000016A: EB 04              jmp         0000000000000170
  000000000000016C: 8B 03              mov         eax,dword ptr [rbx]
  000000000000016E: 89 07              mov         dword ptr [rdi],eax
  0000000000000170: 0F B6 43 10        movzx       eax,byte ptr [rbx+10h]
  0000000000000174: 88 47 10           mov         byte ptr [rdi+10h],al
  0000000000000177: 0F B6 43 18        movzx       eax,byte ptr [rbx+18h]
  000000000000017B: 88 47 18           mov         byte ptr [rdi+18h],al
  000000000000017E: 48 89 5F 20        mov         qword ptr [rdi+20h],rbx
  0000000000000182: 84 C0              test        al,al
  0000000000000184: 74 0F              je          0000000000000195
  0000000000000186: 48 8D 47 19        lea         rax,[rdi+19h]
  000000000000018A: 48 85 C0           test        rax,rax
  000000000000018D: 74 06              je          0000000000000195
  000000000000018F: C6 00 00           mov         byte ptr [rax],0
  0000000000000192: C6 00 00           mov         byte ptr [rax],0
  0000000000000195: 0F B6 4B 10        movzx       ecx,byte ptr [rbx+10h]
  0000000000000199: 83 E9 01           sub         ecx,1
  000000000000019C: 74 20              je          00000000000001BE
  000000000000019E: 83 E9 01           sub         ecx,1
  00000000000001A1: 74 1B              je          00000000000001BE
  00000000000001A3: 83 E9 01           sub         ecx,1
  00000000000001A6: 74 0E              je          00000000000001B6
  00000000000001A8: 83 F9 01           cmp         ecx,1
  00000000000001AB: 75 15              jne         00000000000001C2
  00000000000001AD: 48 C7 03 00 00 00  mov         qword ptr [rbx],0
                    00
  00000000000001B4: EB 08              jmp         00000000000001BE
  00000000000001B6: 48 8B CB           mov         rcx,rbx
  00000000000001B9: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  00000000000001BE: C6 43 10 00        mov         byte ptr [rbx+10h],0
  00000000000001C2: 48 89 3B           mov         qword ptr [rbx],rdi
  00000000000001C5: C6 43 10 04        mov         byte ptr [rbx+10h],4
  00000000000001C9: 80 7B 18 00        cmp         byte ptr [rbx+18h],0
  00000000000001CD: 74 04              je          00000000000001D3
  00000000000001CF: C6 43 19 00        mov         byte ptr [rbx+19h],0
  00000000000001D3: 48 8B C7           mov         rax,rdi
  00000000000001D6: 4C 8D 9C 24 90 00  lea         r11,[rsp+90h]
                    00 00
  00000000000001DE: 49 8B 5B 10        mov         rbx,qword ptr [r11+10h]
  00000000000001E2: 49 8B 73 20        mov         rsi,qword ptr [r11+20h]
  00000000000001E6: 49 8B E3           mov         rsp,r11
  00000000000001E9: 5F                 pop         rdi
  00000000000001EA: C3                 ret

  0000000000000052: 90                 nop
  0000000000000053: 48 8B 5C 24 40     mov         rbx,qword ptr [rsp+40h]
  0000000000000058: 48 85 DB           test        rbx,rbx
  000000000000005B: 0F 95 C0           setne       al
  000000000000005E: 84 C0              test        al,al
  0000000000000060: 75 65              jne         00000000000000C7
  0000000000000062: C7 45 C0 04 00 00  mov         dword ptr [rbp-40h],4
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

  000000000000006E: 48 89 45 C8        mov         qword ptr [rbp-38h],rax
  0000000000000072: 48 8D 05 00 00 00  lea         rax,[??_7exception@std@@6B@]
                    00
  0000000000000079: 48 89 45 50        mov         qword ptr [rbp+50h],rax
  000000000000007D: 33 C0              xor         eax,eax
  000000000000007F: 48 89 45 58        mov         qword ptr [rbp+58h],rax
  0000000000000083: 48 89 45 60        mov         qword ptr [rbp+60h],rax
  0000000000000087: 48 8D 05 00 00 00  lea         rax,[??_C@_00CNPNBAHC@?$AA@]
                    00
  000000000000008E: 48 89 45 F0        mov         qword ptr [rbp-10h],rax
  0000000000000092: C6 45 F8 01        mov         byte ptr [rbp-8],1
  0000000000000096: 48 8D 55 58        lea         rdx,[rbp+58h]
  000000000000009A: 48 8D 4D F0        lea         rcx,[rbp-10h]
  000000000000009E: E8 00 00 00 00     call        __std_exception_copy
  00000000000000A3: 48 8D 05 00 00 00  lea         rax,[??_7future_error@std@@6B@]
                    00
  00000000000000AA: 48 89 45 50        mov         qword ptr [rbp+50h],rax
  00000000000000AE: 0F 10 45 C0        movups      xmm0,xmmword ptr [rbp-40h]
  00000000000000B2: 0F 11 45 68        movups      xmmword ptr [rbp+68h],xmm0
  00000000000000B6: 48 8D 15 00 00 00  lea         rdx,[_TI3?AVfuture_error@std@@]
                    00
  00000000000000BD: 48 8D 4D 50        lea         rcx,[rbp+50h]
  00000000000000C1: E8 00 00 00 00     call        _CxxThrowException
  00000000000000C6: CC                 int         3
  00000000000000C7: 80 7C 24 30 00     cmp         byte ptr [rsp+30h],0
  00000000000000CC: 0F 95 C0           setne       al
  00000000000000CF: 90                 nop
  00000000000000D0: 84 C0              test        al,al
  00000000000000D2: 74 FC              je          00000000000000D0
  00000000000000D4: 0F 57 C0           xorps       xmm0,xmm0
  00000000000000D7: F3 0F 7F 45 88     movdqu      xmmword ptr [rbp-78h],xmm0
  00000000000000DC: 80 7C 24 38 00     cmp         byte ptr [rsp+38h],0
  00000000000000E1: 75 06              jne         00000000000000E9
  00000000000000E3: 48 89 5D 88        mov         qword ptr [rbp-78h],rbx
  00000000000000E7: EB 43              jmp         000000000000012C
  00000000000000E9: 48 8D 4C 24 39     lea         rcx,[rsp+39h]
  00000000000000EE: E8 00 00 00 00     call        replaced
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

  00000000000000F3: 48 8B 4C 24 40     mov         rcx,qword ptr [rsp+40h]
  00000000000000F8: 48 85 C9           test        rcx,rcx
  00000000000000FB: 74 2B              je          0000000000000128
  00000000000000FD: 0F B6 41 19        movzx       eax,byte ptr [rcx+19h]
  0000000000000101: 84 C0              test        al,al
  0000000000000103: 75 11              jne         0000000000000116
  0000000000000105: B8 01 00 00 00     mov         eax,1
  000000000000010A: 86 41 19           xchg        al,byte ptr [rcx+19h]
  000000000000010D: 84 C0              test        al,al
  000000000000010F: 0F 95 C0           setne       al
  0000000000000112: 84 C0              test        al,al
  0000000000000114: 74 07              je          000000000000011D
  0000000000000116: C6 44 24 39 00     mov         byte ptr [rsp+39h],0
  000000000000011B: EB CC              jmp         00000000000000E9
  000000000000011D: 48 8B 5C 24 40     mov         rbx,qword ptr [rsp+40h]
  0000000000000122: 48 89 5D 88        mov         qword ptr [rbp-78h],rbx
  0000000000000126: EB 04              jmp         000000000000012C
  0000000000000128: 48 8B 5D 88        mov         rbx,qword ptr [rbp-78h]
  000000000000012C: 48 8D 44 24 20     lea         rax,[rsp+20h]
  0000000000000131: 48 89 45 90        mov         qword ptr [rbp-70h],rax
  0000000000000135: 80 7C 24 30 00     cmp         byte ptr [rsp+30h],0
  000000000000013A: 0F 95 C0           setne       al
  000000000000013D: 84 C0              test        al,al
  000000000000013F: 75 65              jne         00000000000001A6
  0000000000000141: C7 45 E0 04 00 00  mov         dword ptr [rbp-20h],4
                    00
  0000000000000148: E8 00 00 00 00     call        replaced
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

  000000000000014D: 48 89 45 E8        mov         qword ptr [rbp-18h],rax
  0000000000000151: 48 8D 05 00 00 00  lea         rax,[??_7exception@std@@6B@]
                    00
  0000000000000158: 48 89 45 28        mov         qword ptr [rbp+28h],rax
  000000000000015C: 33 C0              xor         eax,eax
  000000000000015E: 48 89 45 30        mov         qword ptr [rbp+30h],rax
  0000000000000162: 48 89 45 38        mov         qword ptr [rbp+38h],rax
  0000000000000166: 48 8D 05 00 00 00  lea         rax,[??_C@_00CNPNBAHC@?$AA@]
                    00
  000000000000016D: 48 89 45 D0        mov         qword ptr [rbp-30h],rax
  0000000000000171: C6 45 D8 01        mov         byte ptr [rbp-28h],1
  0000000000000175: 48 8D 55 30        lea         rdx,[rbp+30h]
  0000000000000179: 48 8D 4D D0        lea         rcx,[rbp-30h]
  000000000000017D: E8 00 00 00 00     call        __std_exception_copy
  0000000000000182: 48 8D 05 00 00 00  lea         rax,[??_7future_error@std@@6B@]
                    00
  0000000000000189: 48 89 45 28        mov         qword ptr [rbp+28h],rax
  000000000000018D: 0F 10 45 E0        movups      xmm0,xmmword ptr [rbp-20h]
  0000000000000191: 0F 11 45 40        movups      xmmword ptr [rbp+40h],xmm0
  0000000000000195: 48 8D 15 00 00 00  lea         rdx,[_TI3?AVfuture_error@std@@]
                    00
  000000000000019C: 48 8D 4D 28        lea         rcx,[rbp+28h]
  00000000000001A0: E8 00 00 00 00     call        _CxxThrowException
  00000000000001A5: CC                 int         3
  00000000000001A6: 80 7C 24 30 02     cmp         byte ptr [rsp+30h],2
  00000000000001AB: 0F 94 C0           sete        al
  00000000000001AE: 84 C0              test        al,al
  00000000000001B0: 74 33              je          00000000000001E5
  00000000000001B2: 0F 10 44 24 20     movups      xmm0,xmmword ptr [rsp+20h]
  00000000000001B7: 0F 29 85 90 00 00  movaps      xmmword ptr [rbp+90h],xmm0
                    00
  00000000000001BE: 48 8D 95 90 00 00  lea         rdx,[rbp+90h]
                    00
  00000000000001C5: 48 8D 8D C0 00 00  lea         rcx,[rbp+0C0h]
                    00
  00000000000001CC: E8 00 00 00 00     call        replaced
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

  00000000000001D1: 48 8D 15 00 00 00  lea         rdx,[_TI4?AVsystem_error@std@@]
                    00
  00000000000001D8: 48 8D 8D C0 00 00  lea         rcx,[rbp+0C0h]
                    00
  00000000000001DF: E8 00 00 00 00     call        _CxxThrowException
  00000000000001E4: CC                 int         3
  00000000000001E5: 8B 44 24 20        mov         eax,dword ptr [rsp+20h]
  00000000000001E9: 89 85 20 01 00 00  mov         dword ptr [rbp+120h],eax
  00000000000001EF: 0F B6 4C 24 30     movzx       ecx,byte ptr [rsp+30h]
  00000000000001F4: 33 F6              xor         esi,esi
  00000000000001F6: 83 E9 01           sub         ecx,1
  00000000000001F9: 74 20              je          000000000000021B
  00000000000001FB: 83 E9 01           sub         ecx,1
  00000000000001FE: 74 1B              je          000000000000021B
  0000000000000200: 83 E9 01           sub         ecx,1
  0000000000000203: 74 0C              je          0000000000000211
  0000000000000205: 83 F9 01           cmp         ecx,1
  0000000000000208: 75 16              jne         0000000000000220
  000000000000020A: 48 89 74 24 20     mov         qword ptr [rsp+20h],rsi
  000000000000020F: EB 0A              jmp         000000000000021B
  0000000000000211: 48 8D 4C 24 20     lea         rcx,[rsp+20h]
  0000000000000216: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  000000000000021B: 40 88 74 24 30     mov         byte ptr [rsp+30h],sil
  0000000000000220: 48 85 DB           test        rbx,rbx
  0000000000000223: 74 29              je          000000000000024E
  0000000000000225: 0F B6 4B 10        movzx       ecx,byte ptr [rbx+10h]
  0000000000000229: 83 E9 01           sub         ecx,1
  000000000000022C: 74 1C              je          000000000000024A
  000000000000022E: 83 E9 01           sub         ecx,1
  0000000000000231: 74 17              je          000000000000024A
  0000000000000233: 83 E9 01           sub         ecx,1
  0000000000000236: 74 0A              je          0000000000000242
  0000000000000238: 83 F9 01           cmp         ecx,1
  000000000000023B: 75 11              jne         000000000000024E
  000000000000023D: 48 89 33           mov         qword ptr [rbx],rsi
  0000000000000240: EB 08              jmp         000000000000024A
  0000000000000242: 48 8B CB           mov         rcx,rbx
  0000000000000245: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  000000000000024A: C6 43 10 00        mov         byte ptr [rbx+10h],0
  000000000000024E: 48 89 74 24 40     mov         qword ptr [rsp+40h],rsi
  0000000000000253: 48 85 DB           test        rbx,rbx
  0000000000000256: 74 0E              je          0000000000000266
  0000000000000258: 80 7B 18 00        cmp         byte ptr [rbx+18h],0
  000000000000025C: 74 04              je          0000000000000262
  000000000000025E: C6 43 19 00        mov         byte ptr [rbx+19h],0
  0000000000000262: 48 89 75 88        mov         qword ptr [rbp-78h],rsi
  0000000000000266: 80 7C 24 38 00     cmp         byte ptr [rsp+38h],0
  000000000000026B: 74 05              je          0000000000000272
  000000000000026D: C6 44 24 39 00     mov         byte ptr [rsp+39h],0
  0000000000000272: 48 89 75 90        mov         qword ptr [rbp-70h],rsi
  0000000000000276: 0F 57 C0           xorps       xmm0,xmm0
  0000000000000279: F3 0F 7F 44 24 68  movdqu      xmmword ptr [rsp+68h],xmm0
  000000000000027F: 80 7C 24 38 00     cmp         byte ptr [rsp+38h],0
  0000000000000284: 75 0C              jne         0000000000000292
  0000000000000286: 48 8B 5C 24 40     mov         rbx,qword ptr [rsp+40h]
  000000000000028B: 48 89 5C 24 68     mov         qword ptr [rsp+68h],rbx
  0000000000000290: EB 39              jmp         00000000000002CB
  0000000000000292: 48 8D 4C 24 39     lea         rcx,[rsp+39h]
  0000000000000297: E8 00 00 00 00     call        replaced
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

  000000000000029C: 48 8B 4C 24 40     mov         rcx,qword ptr [rsp+40h]
  00000000000002A1: 48 85 C9           test        rcx,rcx
  00000000000002A4: 74 20              je          00000000000002C6
  00000000000002A6: 0F B6 41 19        movzx       eax,byte ptr [rcx+19h]
  00000000000002AA: 84 C0              test        al,al
  00000000000002AC: 75 11              jne         00000000000002BF
  00000000000002AE: B8 01 00 00 00     mov         eax,1
  00000000000002B3: 86 41 19           xchg        al,byte ptr [rcx+19h]
  00000000000002B6: 84 C0              test        al,al
  00000000000002B8: 0F 95 C0           setne       al
  00000000000002BB: 84 C0              test        al,al
  00000000000002BD: 74 C7              je          0000000000000286
  00000000000002BF: C6 44 24 39 00     mov         byte ptr [rsp+39h],0
  00000000000002C4: EB CC              jmp         0000000000000292
  00000000000002C6: 48 8B 5C 24 68     mov         rbx,qword ptr [rsp+68h]
  00000000000002CB: 48 8D 44 24 20     lea         rax,[rsp+20h]
  00000000000002D0: 48 89 44 24 70     mov         qword ptr [rsp+70h],rax
  00000000000002D5: 48 85 DB           test        rbx,rbx
  00000000000002D8: 74 29              je          0000000000000303
  00000000000002DA: 0F B6 4B 10        movzx       ecx,byte ptr [rbx+10h]
  00000000000002DE: 83 E9 01           sub         ecx,1
  00000000000002E1: 74 1C              je          00000000000002FF
  00000000000002E3: 83 E9 01           sub         ecx,1
  00000000000002E6: 74 17              je          00000000000002FF
  00000000000002E8: 83 E9 01           sub         ecx,1
  00000000000002EB: 74 0A              je          00000000000002F7
  00000000000002ED: 83 F9 01           cmp         ecx,1
  00000000000002F0: 75 11              jne         0000000000000303
  00000000000002F2: 48 89 33           mov         qword ptr [rbx],rsi
  00000000000002F5: EB 08              jmp         00000000000002FF
  00000000000002F7: 48 8B CB           mov         rcx,rbx
  00000000000002FA: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  00000000000002FF: C6 43 10 00        mov         byte ptr [rbx+10h],0
  0000000000000303: 0F B6 4C 24 30     movzx       ecx,byte ptr [rsp+30h]
  0000000000000308: 83 E9 01           sub         ecx,1
  000000000000030B: 74 20              je          000000000000032D
  000000000000030D: 83 E9 01           sub         ecx,1
  0000000000000310: 74 1B              je          000000000000032D
  0000000000000312: 83 E9 01           sub         ecx,1
  0000000000000315: 74 0C              je          0000000000000323
  0000000000000317: 83 F9 01           cmp         ecx,1
  000000000000031A: 75 16              jne         0000000000000332
  000000000000031C: 48 89 74 24 20     mov         qword ptr [rsp+20h],rsi
  0000000000000321: EB 0A              jmp         000000000000032D
  0000000000000323: 48 8D 4C 24 20     lea         rcx,[rsp+20h]
  0000000000000328: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  000000000000032D: C6 44 24 30 00     mov         byte ptr [rsp+30h],0
  0000000000000332: 48 85 DB           test        rbx,rbx
  0000000000000335: 74 0F              je          0000000000000346
  0000000000000337: 80 7B 18 00        cmp         byte ptr [rbx+18h],0
  000000000000033B: 74 04              je          0000000000000341
  000000000000033D: C6 43 19 00        mov         byte ptr [rbx+19h],0
  0000000000000341: 48 89 74 24 68     mov         qword ptr [rsp+68h],rsi
  0000000000000346: 80 7C 24 38 00     cmp         byte ptr [rsp+38h],0
  000000000000034B: 74 05              je          0000000000000352
  000000000000034D: C6 44 24 39 00     mov         byte ptr [rsp+39h],0
  0000000000000352: 48 89 74 24 70     mov         qword ptr [rsp+70h],rsi
  0000000000000357: 0F B6 4C 24 30     movzx       ecx,byte ptr [rsp+30h]
  000000000000035C: 83 E9 01           sub         ecx,1
  000000000000035F: 74 20              je          0000000000000381
  0000000000000361: 83 E9 01           sub         ecx,1
  0000000000000364: 74 1B              je          0000000000000381
  0000000000000366: 83 E9 01           sub         ecx,1
  0000000000000369: 74 0C              je          0000000000000377
  000000000000036B: 83 F9 01           cmp         ecx,1
  000000000000036E: 75 16              jne         0000000000000386
  0000000000000370: 48 89 74 24 20     mov         qword ptr [rsp+20h],rsi
  0000000000000375: EB 0A              jmp         0000000000000381
  0000000000000377: 48 8D 4C 24 20     lea         rcx,[rsp+20h]
  000000000000037C: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  0000000000000381: C6 44 24 30 00     mov         byte ptr [rsp+30h],0
  0000000000000386: 0F 57 C0           xorps       xmm0,xmm0
  0000000000000389: F3 0F 7F 44 24 78  movdqu      xmmword ptr [rsp+78h],xmm0
  000000000000038F: 80 7C 24 60 00     cmp         byte ptr [rsp+60h],0
  0000000000000394: 75 1C              jne         00000000000003B2
  0000000000000396: 48 8D 44 24 48     lea         rax,[rsp+48h]
  000000000000039B: 48 89 44 24 78     mov         qword ptr [rsp+78h],rax
  00000000000003A0: 80 7C 24 58 04     cmp         byte ptr [rsp+58h],4
  00000000000003A5: 75 60              jne         0000000000000407
  00000000000003A7: 48 8B 5C 24 48     mov         rbx,qword ptr [rsp+48h]
  00000000000003AC: 48 89 5D 80        mov         qword ptr [rbp-80h],rbx
  00000000000003B0: EB 59              jmp         000000000000040B
  00000000000003B2: 48 8D 4C 24 61     lea         rcx,[rsp+61h]
  00000000000003B7: E8 00 00 00 00     call        replaced
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

  00000000000003BC: 80 7C 24 58 04     cmp         byte ptr [rsp+58h],4
  00000000000003C1: 75 3A              jne         00000000000003FD
  00000000000003C3: 48 8B 4C 24 48     mov         rcx,qword ptr [rsp+48h]
  00000000000003C8: 0F B6 41 19        movzx       eax,byte ptr [rcx+19h]
  00000000000003CC: 84 C0              test        al,al
  00000000000003CE: 75 11              jne         00000000000003E1
  00000000000003D0: B8 01 00 00 00     mov         eax,1
  00000000000003D5: 86 41 19           xchg        al,byte ptr [rcx+19h]
  00000000000003D8: 84 C0              test        al,al
  00000000000003DA: 0F 95 C0           setne       al
  00000000000003DD: 84 C0              test        al,al
  00000000000003DF: 74 07              je          00000000000003E8
  00000000000003E1: C6 44 24 61 00     mov         byte ptr [rsp+61h],0
  00000000000003E6: EB CA              jmp         00000000000003B2
  00000000000003E8: 48 8D 44 24 48     lea         rax,[rsp+48h]
  00000000000003ED: 48 89 44 24 78     mov         qword ptr [rsp+78h],rax
  00000000000003F2: 48 8B 5C 24 48     mov         rbx,qword ptr [rsp+48h]
  00000000000003F7: 48 89 5D 80        mov         qword ptr [rbp-80h],rbx
  00000000000003FB: EB 0E              jmp         000000000000040B
  00000000000003FD: 48 8D 44 24 48     lea         rax,[rsp+48h]
  0000000000000402: 48 89 44 24 78     mov         qword ptr [rsp+78h],rax
  0000000000000407: 48 8B 5D 80        mov         rbx,qword ptr [rbp-80h]
  000000000000040B: 48 85 DB           test        rbx,rbx
  000000000000040E: 0F 84 D3 00 00 00  je          00000000000004E7
  0000000000000414: 80 7B 10 00        cmp         byte ptr [rbx+10h],0
  0000000000000418: 0F 95 C0           setne       al
  000000000000041B: 84 C0              test        al,al
  000000000000041D: 0F 85 C0 00 00 00  jne         00000000000004E3
  0000000000000423: E8 00 00 00 00     call        replaced
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

  0000000000000428: C7 45 B0 01 00 00  mov         dword ptr [rbp-50h],1
                    00
  000000000000042F: 48 89 45 B8        mov         qword ptr [rbp-48h],rax
  0000000000000433: 0F 28 75 B0        movaps      xmm6,xmmword ptr [rbp-50h]
  0000000000000437: 66 0F 7F B5 A0 00  movdqa      xmmword ptr [rbp+0A0h],xmm6
                    00 00
  000000000000043F: 48 8D 05 00 00 00  lea         rax,[??_7exception@std@@6B@]
                    00
  0000000000000446: 48 89 45 00        mov         qword ptr [rbp],rax
  000000000000044A: 33 C0              xor         eax,eax
  000000000000044C: 48 89 45 08        mov         qword ptr [rbp+8],rax
  0000000000000450: 48 89 45 10        mov         qword ptr [rbp+10h],rax
  0000000000000454: 48 8D 05 00 00 00  lea         rax,[??_C@_00CNPNBAHC@?$AA@]
                    00
  000000000000045B: 48 89 45 98        mov         qword ptr [rbp-68h],rax
  000000000000045F: C6 45 A0 01        mov         byte ptr [rbp-60h],1
  0000000000000463: 48 8D 55 08        lea         rdx,[rbp+8]
  0000000000000467: 48 8D 4D 98        lea         rcx,[rbp-68h]
  000000000000046B: E8 00 00 00 00     call        __std_exception_copy
  0000000000000470: 48 8D 05 00 00 00  lea         rax,[??_7future_error@std@@6B@]
                    00
  0000000000000477: 48 89 45 00        mov         qword ptr [rbp],rax
  000000000000047B: 0F 11 75 18        movups      xmmword ptr [rbp+18h],xmm6
  000000000000047F: 48 8D 55 00        lea         rdx,[rbp]
  0000000000000483: 48 8D 8D B0 00 00  lea         rcx,[rbp+0B0h]
                    00
  000000000000048A: E8 00 00 00 00     call        replaced
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

  000000000000048F: 48 8B F8           mov         rdi,rax
  0000000000000492: 48 89 85 30 01 00  mov         qword ptr [rbp+130h],rax
                    00
  0000000000000499: 0F B6 53 10        movzx       edx,byte ptr [rbx+10h]
  000000000000049D: 83 EA 01           sub         edx,1
  00000000000004A0: 74 1C              je          00000000000004BE
  00000000000004A2: 83 EA 01           sub         edx,1
  00000000000004A5: 74 17              je          00000000000004BE
  00000000000004A7: 83 EA 01           sub         edx,1
  00000000000004AA: 74 0A              je          00000000000004B6
  00000000000004AC: 83 FA 01           cmp         edx,1
  00000000000004AF: 75 11              jne         00000000000004C2
  00000000000004B1: 48 89 33           mov         qword ptr [rbx],rsi
  00000000000004B4: EB 08              jmp         00000000000004BE
  00000000000004B6: 48 8B CB           mov         rcx,rbx
  00000000000004B9: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  00000000000004BE: C6 43 10 00        mov         byte ptr [rbx+10h],0
  00000000000004C2: 48 8B D7           mov         rdx,rdi
  00000000000004C5: 48 8D 4D 78        lea         rcx,[rbp+78h]
  00000000000004C9: E8 00 00 00 00     call        ?__ExceptionPtrCopy@@YAXPEAXPEBX@Z
  00000000000004CE: 48 8D 55 78        lea         rdx,[rbp+78h]
  00000000000004D2: 48 8B CB           mov         rcx,rbx
  00000000000004D5: E8 00 00 00 00     call        replaced
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

  00000000000004DA: 90                 nop
  00000000000004DB: 48 8B CF           mov         rcx,rdi
  00000000000004DE: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  00000000000004E3: 48 89 73 20        mov         qword ptr [rbx+20h],rsi
  00000000000004E7: 0F B6 4C 24 58     movzx       ecx,byte ptr [rsp+58h]
  00000000000004EC: 83 E9 01           sub         ecx,1
  00000000000004EF: 74 20              je          0000000000000511
  00000000000004F1: 83 E9 01           sub         ecx,1
  00000000000004F4: 74 1B              je          0000000000000511
  00000000000004F6: 83 E9 01           sub         ecx,1
  00000000000004F9: 74 0C              je          0000000000000507
  00000000000004FB: 83 F9 01           cmp         ecx,1
  00000000000004FE: 75 16              jne         0000000000000516
  0000000000000500: 48 89 74 24 48     mov         qword ptr [rsp+48h],rsi
  0000000000000505: EB 0A              jmp         0000000000000511
  0000000000000507: 48 8D 4C 24 48     lea         rcx,[rsp+48h]
  000000000000050C: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  0000000000000511: C6 44 24 58 00     mov         byte ptr [rsp+58h],0
  0000000000000516: 80 7C 24 60 00     cmp         byte ptr [rsp+60h],0
  000000000000051B: 74 05              je          0000000000000522
  000000000000051D: C6 44 24 61 00     mov         byte ptr [rsp+61h],0
  0000000000000522: 48 89 74 24 78     mov         qword ptr [rsp+78h],rsi
  0000000000000527: 48 85 DB           test        rbx,rbx
  000000000000052A: 74 0A              je          0000000000000536
  000000000000052C: 80 7B 18 00        cmp         byte ptr [rbx+18h],0
  0000000000000530: 74 04              je          0000000000000536
  0000000000000532: C6 43 19 00        mov         byte ptr [rbx+19h],0
  0000000000000536: 0F B6 4C 24 58     movzx       ecx,byte ptr [rsp+58h]
  000000000000053B: 83 E9 01           sub         ecx,1
  000000000000053E: 74 15              je          0000000000000555
  0000000000000540: 83 E9 01           sub         ecx,1
  0000000000000543: 74 10              je          0000000000000555
  0000000000000545: 83 F9 01           cmp         ecx,1
  0000000000000548: 75 0B              jne         0000000000000555
  000000000000054A: 48 8D 4C 24 48     lea         rcx,[rsp+48h]
  000000000000054F: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  0000000000000554: 90                 nop
  0000000000000555: 8B 85 20 01 00 00  mov         eax,dword ptr [rbp+120h]
  000000000000055B: 48 8B 9C 24 38 02  mov         rbx,qword ptr [rsp+238h]
                    00 00
  0000000000000563: 0F 28 B4 24 F0 01  movaps      xmm6,xmmword ptr [rsp+1F0h]
                    00 00
  000000000000056B: 48 81 C4 00 02 00  add         rsp,200h
                    00
  0000000000000572: 5F                 pop         rdi
  0000000000000573: 5E                 pop         rsi
  0000000000000574: 5D                 pop         rbp
  0000000000000575: C3                 ret
