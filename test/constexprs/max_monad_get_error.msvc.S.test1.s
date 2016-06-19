  0000000000000000: 40 55              push        rbp
  0000000000000002: 48 8D 6C 24 A9     lea         rbp,[rsp-57h]
  0000000000000007: 48 81 EC C0 00 00  sub         rsp,0C0h
                    00
  000000000000000E: 48 C7 45 2F FE FF  mov         qword ptr [rbp+2Fh],0FFFFFFFFFFFFFFFEh
                    FF FF
  0000000000000016: 48 89 9C 24 D0 00  mov         qword ptr [rsp+0D0h],rbx
                    00 00
  000000000000001E: 48 8B D9           mov         rbx,rcx
  0000000000000021: 48 8D 4D 37        lea         rcx,[rbp+37h]
  0000000000000025: E8 00 00 00 00     call        ?unknown@@YA?AV?$basic_monad@U?$monad_policy@H@detail@v1_std_std@outcome@boost@@@v1_std_std@outcome@boost@@XZ
  000000000000002A: 90                 nop
  000000000000002B: 0F B6 50 18        movzx       edx,byte ptr [rax+18h]
  000000000000002F: 84 D2              test        dl,dl
  0000000000000031: 0F 85 F3 00 00 00  jne         000000000000012A
  0000000000000037: C7 45 D7 02 00 00  mov         dword ptr [rbp-29h],2
                    00
  000000000000003E: E8 00 00 00 00     call        replaced
  0000000000000000: 40 53              push        rbx
  0000000000000002: 48 83 EC 20        sub         rsp,20h
  0000000000000006: 65 48 8B 04 25 58  mov         rax,qword ptr gs:[58h]
                    00 00 00
  000000000000000F: 8B 0D 00 00 00 00  mov         ecx,dword ptr [_tls_index]
  0000000000000015: BA 00 00 00 00     mov         edx,offset _Init_thread_epoch
  000000000000001A: 48 8B 0C C8        mov         rcx,qword ptr [rax+rcx*8]
  000000000000001E: 8B 04 0A           mov         eax,dword ptr [rdx+rcx]
  0000000000000021: 39 05 00 00 00 00  cmp         dword ptr [?$TSS0@?1??monad_category@v1_std_std@outcome@boost@@YAAEBV1_detail@234@XZ@4HA],eax
  0000000000000027: 7F 0D              jg          0000000000000036
  0000000000000029: 48 8D 05 00 00 00  lea         rax,[?c@?1??monad_category@v1_std_std@outcome@boost@@YAAEBV1_detail@234@XZ@4V15234@A]
                    00
  0000000000000030: 48 83 C4 20        add         rsp,20h
  0000000000000034: 5B                 pop         rbx
  0000000000000035: C3                 ret
  0000000000000036: 48 8D 0D 00 00 00  lea         rcx,[?$TSS0@?1??monad_category@v1_std_std@outcome@boost@@YAAEBV1_detail@234@XZ@4HA]
                    00
  000000000000003D: E8 00 00 00 00     call        _Init_thread_header
  0000000000000042: 83 3D 00 00 00 00  cmp         dword ptr [?$TSS0@?1??monad_category@v1_std_std@outcome@boost@@YAAEBV1_detail@234@XZ@4HA],0FFFFFFFFh
                    FF
  0000000000000049: 75 DE              jne         0000000000000029
  000000000000004B: 48 8D 05 00 00 00  lea         rax,[??_7monad_category@_detail@v1_std_std@outcome@boost@@6B@]
                    00
  0000000000000052: 48 8D 1D 00 00 00  lea         rbx,[?c@?1??monad_category@v1_std_std@outcome@boost@@YAAEBV1_detail@234@XZ@4V15234@A]
                    00
  0000000000000059: 48 89 05 00 00 00  mov         qword ptr [?c@?1??monad_category@v1_std_std@outcome@boost@@YAAEBV1_detail@234@XZ@4V15234@A],rax
                    00
  0000000000000060: 48 8D 0D 00 00 00  lea         rcx,[??__Fc@?1??monad_category@v1_std_std@outcome@boost@@YAAEBV0_detail@123@XZ@YAXXZ]
                    00
  0000000000000067: 48 89 1D 08 00 00  mov         qword ptr [?c@?1??monad_category@v1_std_std@outcome@boost@@YAAEBV1_detail@234@XZ@4V15234@A+8],rbx
                    00
  000000000000006E: E8 00 00 00 00     call        atexit
  0000000000000073: 48 8D 0D 00 00 00  lea         rcx,[?$TSS0@?1??monad_category@v1_std_std@outcome@boost@@YAAEBV1_detail@234@XZ@4HA]
                    00
  000000000000007A: E8 00 00 00 00     call        _Init_thread_footer
  000000000000007F: 48 8B C3           mov         rax,rbx
  0000000000000082: 48 83 C4 20        add         rsp,20h
  0000000000000086: 5B                 pop         rbx
  0000000000000087: C3                 ret

  0000000000000043: 48 89 45 DF        mov         qword ptr [rbp-21h],rax
  0000000000000047: 0F 28 45 D7        movaps      xmm0,xmmword ptr [rbp-29h]
  000000000000004B: 66 0F 7F 45 B7     movdqa      xmmword ptr [rbp-49h],xmm0
  0000000000000050: 48 8D 55 E7        lea         rdx,[rbp-19h]
  0000000000000054: 48 8D 4D B7        lea         rcx,[rbp-49h]
  0000000000000058: E8 00 00 00 00     call        replaced
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

  000000000000005D: 48 83 78 18 10     cmp         qword ptr [rax+18h],10h
  0000000000000062: 72 03              jb          0000000000000067
  0000000000000064: 48 8B 00           mov         rax,qword ptr [rax]
  0000000000000067: 48 8D 0D 00 00 00  lea         rcx,[??_7exception@std@@6B@]
                    00
  000000000000006E: 48 89 4D 07        mov         qword ptr [rbp+7],rcx
  0000000000000072: 33 C9              xor         ecx,ecx
  0000000000000074: 48 89 4D 0F        mov         qword ptr [rbp+0Fh],rcx
  0000000000000078: 48 89 4D 17        mov         qword ptr [rbp+17h],rcx
  000000000000007C: 48 89 45 D7        mov         qword ptr [rbp-29h],rax
  0000000000000080: C6 45 DF 01        mov         byte ptr [rbp-21h],1
  0000000000000084: 48 8D 55 0F        lea         rdx,[rbp+0Fh]
  0000000000000088: 48 8D 4D D7        lea         rcx,[rbp-29h]
  000000000000008C: E8 00 00 00 00     call        __std_exception_copy
  0000000000000091: 48 8D 05 00 00 00  lea         rax,[??_7logic_error@std@@6B@]
                    00
  0000000000000098: 48 89 45 07        mov         qword ptr [rbp+7],rax
  000000000000009C: 48 8B 45 FF        mov         rax,qword ptr [rbp-1]
  00000000000000A0: 48 83 F8 10        cmp         rax,10h
  00000000000000A4: 72 4C              jb          00000000000000F2
  00000000000000A6: 48 FF C0           inc         rax
  00000000000000A9: 48 8B 4D E7        mov         rcx,qword ptr [rbp-19h]
  00000000000000AD: 48 3D 00 10 00 00  cmp         rax,1000h
  00000000000000B3: 72 38              jb          00000000000000ED
  00000000000000B5: F6 C1 1F           test        cl,1Fh
  00000000000000B8: 74 06              je          00000000000000C0
  00000000000000BA: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  00000000000000BF: CC                 int         3
  00000000000000C0: 48 8B 41 F8        mov         rax,qword ptr [rcx-8]
  00000000000000C4: 48 3B C1           cmp         rax,rcx
  00000000000000C7: 72 06              jb          00000000000000CF
  00000000000000C9: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  00000000000000CE: CC                 int         3
  00000000000000CF: 48 2B C8           sub         rcx,rax
  00000000000000D2: 48 83 F9 08        cmp         rcx,8
  00000000000000D6: 73 06              jae         00000000000000DE
  00000000000000D8: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  00000000000000DD: CC                 int         3
  00000000000000DE: 48 83 F9 27        cmp         rcx,27h
  00000000000000E2: 76 06              jbe         00000000000000EA
  00000000000000E4: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  00000000000000E9: CC                 int         3
  00000000000000EA: 48 8B C8           mov         rcx,rax
  00000000000000ED: E8 00 00 00 00     call        ??3@YAXPEAX@Z
  00000000000000F2: 48 C7 45 FF 0F 00  mov         qword ptr [rbp-1],0Fh
                    00 00
  00000000000000FA: 48 C7 45 F7 00 00  mov         qword ptr [rbp-9],0
                    00 00
  0000000000000102: C6 45 E7 00        mov         byte ptr [rbp-19h],0
  0000000000000106: 48 8D 05 00 00 00  lea         rax,[??_7monad_error@v1_std_std@outcome@boost@@6B@]
                    00
  000000000000010D: 48 89 45 07        mov         qword ptr [rbp+7],rax
  0000000000000111: 0F 28 45 B7        movaps      xmm0,xmmword ptr [rbp-49h]
  0000000000000115: 0F 11 45 1F        movups      xmmword ptr [rbp+1Fh],xmm0
  0000000000000119: 48 8D 15 00 00 00  lea         rdx,[_TI3?AVmonad_error@v1_std_std@outcome@boost@@]
                    00
  0000000000000120: 48 8D 4D 07        lea         rcx,[rbp+7]
  0000000000000124: E8 00 00 00 00     call        _CxxThrowException
  0000000000000129: CC                 int         3
  000000000000012A: 80 FA 02           cmp         dl,2
  000000000000012D: 75 05              jne         0000000000000134
  000000000000012F: 0F 10 10           movups      xmm2,xmmword ptr [rax]
  0000000000000132: EB 27              jmp         000000000000015B
  0000000000000134: 80 FA 03           cmp         dl,3
  0000000000000137: 75 0E              jne         0000000000000147
  0000000000000139: E8 00 00 00 00     call        replaced
  0000000000000000: 40 53              push        rbx
  0000000000000002: 48 83 EC 20        sub         rsp,20h
  0000000000000006: 65 48 8B 04 25 58  mov         rax,qword ptr gs:[58h]
                    00 00 00
  000000000000000F: 8B 0D 00 00 00 00  mov         ecx,dword ptr [_tls_index]
  0000000000000015: BA 00 00 00 00     mov         edx,offset _Init_thread_epoch
  000000000000001A: 48 8B 0C C8        mov         rcx,qword ptr [rax+rcx*8]
  000000000000001E: 8B 04 0A           mov         eax,dword ptr [rdx+rcx]
  0000000000000021: 39 05 00 00 00 00  cmp         dword ptr [?$TSS0@?1??monad_category@v1_std_std@outcome@boost@@YAAEBV1_detail@234@XZ@4HA],eax
  0000000000000027: 7F 0D              jg          0000000000000036
  0000000000000029: 48 8D 05 00 00 00  lea         rax,[?c@?1??monad_category@v1_std_std@outcome@boost@@YAAEBV1_detail@234@XZ@4V15234@A]
                    00
  0000000000000030: 48 83 C4 20        add         rsp,20h
  0000000000000034: 5B                 pop         rbx
  0000000000000035: C3                 ret
  0000000000000036: 48 8D 0D 00 00 00  lea         rcx,[?$TSS0@?1??monad_category@v1_std_std@outcome@boost@@YAAEBV1_detail@234@XZ@4HA]
                    00
  000000000000003D: E8 00 00 00 00     call        _Init_thread_header
  0000000000000042: 83 3D 00 00 00 00  cmp         dword ptr [?$TSS0@?1??monad_category@v1_std_std@outcome@boost@@YAAEBV1_detail@234@XZ@4HA],0FFFFFFFFh
                    FF
  0000000000000049: 75 DE              jne         0000000000000029
  000000000000004B: 48 8D 05 00 00 00  lea         rax,[??_7monad_category@_detail@v1_std_std@outcome@boost@@6B@]
                    00
  0000000000000052: 48 8D 1D 00 00 00  lea         rbx,[?c@?1??monad_category@v1_std_std@outcome@boost@@YAAEBV1_detail@234@XZ@4V15234@A]
                    00
  0000000000000059: 48 89 05 00 00 00  mov         qword ptr [?c@?1??monad_category@v1_std_std@outcome@boost@@YAAEBV1_detail@234@XZ@4V15234@A],rax
                    00
  0000000000000060: 48 8D 0D 00 00 00  lea         rcx,[??__Fc@?1??monad_category@v1_std_std@outcome@boost@@YAAEBV0_detail@123@XZ@YAXXZ]
                    00
  0000000000000067: 48 89 1D 08 00 00  mov         qword ptr [?c@?1??monad_category@v1_std_std@outcome@boost@@YAAEBV1_detail@234@XZ@4V15234@A+8],rbx
                    00
  000000000000006E: E8 00 00 00 00     call        atexit
  0000000000000073: 48 8D 0D 00 00 00  lea         rcx,[?$TSS0@?1??monad_category@v1_std_std@outcome@boost@@YAAEBV1_detail@234@XZ@4HA]
                    00
  000000000000007A: E8 00 00 00 00     call        _Init_thread_footer
  000000000000007F: 48 8B C3           mov         rax,rbx
  0000000000000082: 48 83 C4 20        add         rsp,20h
  0000000000000086: 5B                 pop         rbx
  0000000000000087: C3                 ret

  000000000000013E: C7 45 B7 03 00 00  mov         dword ptr [rbp-49h],3
                    00
  0000000000000145: EB 0C              jmp         0000000000000153
  0000000000000147: C7 45 B7 00 00 00  mov         dword ptr [rbp-49h],0
                    00
  000000000000014E: E8 00 00 00 00     call        replaced
  0000000000000000: 48 83 EC 28        sub         rsp,28h
  0000000000000004: 65 48 8B 04 25 58  mov         rax,qword ptr gs:[58h]
                    00 00 00
  000000000000000D: 8B 0D 00 00 00 00  mov         ecx,dword ptr [_tls_index]
  0000000000000013: BA 00 00 00 00     mov         edx,offset _Init_thread_epoch
  0000000000000018: 48 8B 0C C8        mov         rcx,qword ptr [rax+rcx*8]
  000000000000001C: 8B 04 0A           mov         eax,dword ptr [rdx+rcx]
  000000000000001F: 39 05 00 00 00 00  cmp         dword ptr [?$TSS0@?1???$_Immortalize@V_System_error_category@std@@@std@@YAAEAV_System_error_category@1@XZ@4HA],eax
  0000000000000025: 7F 0C              jg          0000000000000033
  0000000000000027: 48 8D 05 00 00 00  lea         rax,[?_Static@?1???$_Immortalize@V_System_error_category@std@@@std@@YAAEAV_System_error_category@1@XZ@4U?$_Immortalizer@V_System_error_category@std@@@1@A]
                    00
  000000000000002E: 48 83 C4 28        add         rsp,28h
  0000000000000032: C3                 ret
  0000000000000033: 48 8D 0D 00 00 00  lea         rcx,[?$TSS0@?1???$_Immortalize@V_System_error_category@std@@@std@@YAAEAV_System_error_category@1@XZ@4HA]
                    00
  000000000000003A: E8 00 00 00 00     call        _Init_thread_header
  000000000000003F: 83 3D 00 00 00 00  cmp         dword ptr [?$TSS0@?1???$_Immortalize@V_System_error_category@std@@@std@@YAAEAV_System_error_category@1@XZ@4HA],0FFFFFFFFh
                    FF
  0000000000000046: 75 DF              jne         0000000000000027
  0000000000000048: 48 8D 05 00 00 00  lea         rax,[??_7_System_error_category@std@@6B@]
                    00
  000000000000004F: 48 C7 05 08 00 00  mov         qword ptr [?_Static@?1???$_Immortalize@V_System_error_category@std@@@std@@YAAEAV_System_error_category@1@XZ@4U?$_Immortalizer@V_System_error_category@std@@@1@A+8],7
                    00 07 00 00 00
  000000000000005A: 48 8D 0D 00 00 00  lea         rcx,[??__F_Static@?1???$_Immortalize@V_System_error_category@std@@@std@@YAAEAV_System_error_category@0@XZ@YAXXZ]
                    00
  0000000000000061: 48 89 05 00 00 00  mov         qword ptr [?_Static@?1???$_Immortalize@V_System_error_category@std@@@std@@YAAEAV_System_error_category@1@XZ@4U?$_Immortalizer@V_System_error_category@std@@@1@A],rax
                    00
  0000000000000068: E8 00 00 00 00     call        atexit
  000000000000006D: 48 8D 0D 00 00 00  lea         rcx,[?$TSS0@?1???$_Immortalize@V_System_error_category@std@@@std@@YAAEAV_System_error_category@1@XZ@4HA]
                    00
  0000000000000074: E8 00 00 00 00     call        _Init_thread_footer
  0000000000000079: EB AC              jmp         0000000000000027

  0000000000000153: 48 89 45 BF        mov         qword ptr [rbp-41h],rax
  0000000000000157: 0F 10 55 B7        movups      xmm2,xmmword ptr [rbp-49h]
  000000000000015B: 0F 11 13           movups      xmmword ptr [rbx],xmm2
  000000000000015E: 0F B6 4D 4F        movzx       ecx,byte ptr [rbp+4Fh]
  0000000000000162: 83 E9 01           sub         ecx,1
  0000000000000165: 74 13              je          000000000000017A
  0000000000000167: 83 E9 01           sub         ecx,1
  000000000000016A: 74 0E              je          000000000000017A
  000000000000016C: 83 F9 01           cmp         ecx,1
  000000000000016F: 75 09              jne         000000000000017A
  0000000000000171: 48 8D 4D 37        lea         rcx,[rbp+37h]
  0000000000000175: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  000000000000017A: 48 8B C3           mov         rax,rbx
  000000000000017D: 48 8B 9C 24 D0 00  mov         rbx,qword ptr [rsp+0D0h]
                    00 00
  0000000000000185: 48 81 C4 C0 00 00  add         rsp,0C0h
                    00
  000000000000018C: 5D                 pop         rbp
  000000000000018D: C3                 ret
