  0000000000000000: 55                 push        rbp
  0000000000000001: 56                 push        rsi
  0000000000000002: 57                 push        rdi
  0000000000000003: 53                 push        rbx
  0000000000000004: 48 81 EC 88 00 00  sub         rsp,88h
                    00
  000000000000000B: 48 8D AC 24 80 00  lea         rbp,[rsp+80h]
                    00 00
  0000000000000013: 48 C7 45 00 FE FF  mov         qword ptr [rbp],0FFFFFFFFFFFFFFFEh
                    FF FF
  000000000000001B: 48 89 CE           mov         rsi,rcx
  000000000000001E: 48 8D 4D E0        lea         rcx,[rbp-20h]
  0000000000000022: E8 00 00 00 00     call        ?unknown@@YA?AV?$basic_monad@U?$monad_policy@H@detail@v1_std_std@outcome@boost@@@v1_std_std@outcome@boost@@XZ
  0000000000000027: 8A 45 F8           mov         al,byte ptr [rbp-8]
  000000000000002A: 3C 02              cmp         al,2
  000000000000002C: 0F 84 8A 00 00 00  je          00000000000000BC
  0000000000000032: 3C 03              cmp         al,3
  0000000000000034: 0F 84 93 00 00 00  je          00000000000000CD
  000000000000003A: 84 C0              test        al,al
  000000000000003C: 0F 84 3D 01 00 00  je          000000000000017F
  0000000000000042: 8B 05 00 00 00 00  mov         eax,dword ptr [?$TSS0@?1???$_Immortalize@V_System_error_category@std@@@std@@YAAEAV_System_error_category@0@XZ@4HA]
  0000000000000048: 8B 0D 00 00 00 00  mov         ecx,dword ptr [_tls_index]
  000000000000004E: 65 48 8B 14 25 58  mov         rdx,qword ptr gs:[58h]
                    00 00 00
  0000000000000057: 48 8B 0C CA        mov         rcx,qword ptr [rdx+rcx*8]
  000000000000005B: 31 FF              xor         edi,edi
  000000000000005D: 48 8D 1D 00 00 00  lea         rbx,[?_Static@?1???$_Immortalize@V_System_error_category@std@@@std@@YAAEAV_System_error_category@1@XZ@4U?$_Immortalizer@V_System_error_category@std@@@1@A]
                    00
  0000000000000064: 3B 81 00 00 00 00  cmp         eax,dword ptr _Init_thread_epoch[rcx]
  000000000000006A: 0F 8E D5 00 00 00  jle         0000000000000145
  0000000000000070: 48 8D 0D 00 00 00  lea         rcx,[?$TSS0@?1???$_Immortalize@V_System_error_category@std@@@std@@YAAEAV_System_error_category@0@XZ@4HA]
                    00
  0000000000000077: E8 00 00 00 00     call        _Init_thread_header
  000000000000007C: 8B 05 00 00 00 00  mov         eax,dword ptr [?$TSS0@?1???$_Immortalize@V_System_error_category@std@@@std@@YAAEAV_System_error_category@0@XZ@4HA]
  0000000000000082: 83 F8 FF           cmp         eax,0FFFFFFFFh
  0000000000000085: 0F 85 BA 00 00 00  jne         0000000000000145
  000000000000008B: 48 8D 05 00 00 00  lea         rax,[??_7_System_error_category@std@@6B@]
                    00
  0000000000000092: 48 89 05 00 00 00  mov         qword ptr [?_Static@?1???$_Immortalize@V_System_error_category@std@@@std@@YAAEAV_System_error_category@1@XZ@4U?$_Immortalizer@V_System_error_category@std@@@1@A],rax
                    00
  0000000000000099: 48 C7 05 04 00 00  mov         qword ptr [?_Static@?1???$_Immortalize@V_System_error_category@std@@@std@@YAAEAV_System_error_category@1@XZ@4U?$_Immortalizer@V_System_error_category@std@@@1@A+4],7
                    00 07 00 00 00
  00000000000000A4: 48 8D 0D 00 00 00  lea         rcx,[??__F_Static@?1???$_Immortalize@V_System_error_category@std@@@std@@YAAEAV_System_error_category@1@XZ@YAXXZ]
                    00
  00000000000000AB: E8 00 00 00 00     call        atexit
  00000000000000B0: 48 8D 0D 00 00 00  lea         rcx,[?$TSS0@?1???$_Immortalize@V_System_error_category@std@@@std@@YAAEAV_System_error_category@0@XZ@4HA]
                    00
  00000000000000B7: E9 84 00 00 00     jmp         0000000000000140
  00000000000000BC: 48 8B 7D E0        mov         rdi,qword ptr [rbp-20h]
  00000000000000C0: 48 8B 5D E8        mov         rbx,qword ptr [rbp-18h]
  00000000000000C4: 48 89 F8           mov         rax,rdi
  00000000000000C7: 48 C1 E8 20        shr         rax,20h
  00000000000000CB: EB 78              jmp         0000000000000145
  00000000000000CD: 8B 05 00 00 00 00  mov         eax,dword ptr [?$TSS0@?1??monad_category@v1_std_std@outcome@boost@@YAAEBV0_detail@123@XZ@4HA]
  00000000000000D3: 8B 0D 00 00 00 00  mov         ecx,dword ptr [_tls_index]
  00000000000000D9: 65 48 8B 14 25 58  mov         rdx,qword ptr gs:[58h]
                    00 00 00
  00000000000000E2: 48 8B 0C CA        mov         rcx,qword ptr [rdx+rcx*8]
  00000000000000E6: BF 03 00 00 00     mov         edi,3
  00000000000000EB: 48 8D 1D 00 00 00  lea         rbx,[?c@?1??monad_category@v1_std_std@outcome@boost@@YAAEBV1_detail@234@XZ@4V15234@A]
                    00
  00000000000000F2: 3B 81 00 00 00 00  cmp         eax,dword ptr _Init_thread_epoch[rcx]
  00000000000000F8: 7E 4B              jle         0000000000000145
  00000000000000FA: 48 8D 0D 00 00 00  lea         rcx,[?$TSS0@?1??monad_category@v1_std_std@outcome@boost@@YAAEBV0_detail@123@XZ@4HA]
                    00
  0000000000000101: E8 00 00 00 00     call        _Init_thread_header
  0000000000000106: 8B 05 00 00 00 00  mov         eax,dword ptr [?$TSS0@?1??monad_category@v1_std_std@outcome@boost@@YAAEBV0_detail@123@XZ@4HA]
  000000000000010C: 83 F8 FF           cmp         eax,0FFFFFFFFh
  000000000000010F: 75 34              jne         0000000000000145
  0000000000000111: 48 8D 1D 00 00 00  lea         rbx,[?c@?1??monad_category@v1_std_std@outcome@boost@@YAAEBV1_detail@234@XZ@4V15234@A]
                    00
  0000000000000118: 48 89 1D 08 00 00  mov         qword ptr [?c@?1??monad_category@v1_std_std@outcome@boost@@YAAEBV1_detail@234@XZ@4V15234@A+8],rbx
                    00
  000000000000011F: 48 8D 05 00 00 00  lea         rax,[??_7monad_category@_detail@v1_std_std@outcome@boost@@6B@]
                    00
  0000000000000126: 48 89 05 00 00 00  mov         qword ptr [?c@?1??monad_category@v1_std_std@outcome@boost@@YAAEBV1_detail@234@XZ@4V15234@A],rax
                    00
  000000000000012D: 48 8D 0D 00 00 00  lea         rcx,[??__Fc@?1??monad_category@v1_std_std@outcome@boost@@YAAEBV1_detail@234@XZ@YAXXZ]
                    00
  0000000000000134: E8 00 00 00 00     call        atexit
  0000000000000139: 48 8D 0D 00 00 00  lea         rcx,[?$TSS0@?1??monad_category@v1_std_std@outcome@boost@@YAAEBV0_detail@123@XZ@4HA]
                    00
  0000000000000140: E8 00 00 00 00     call        _Init_thread_footer
  0000000000000145: 89 3E              mov         dword ptr [rsi],edi
  0000000000000147: 89 46 04           mov         dword ptr [rsi+4],eax
  000000000000014A: 48 89 5E 08        mov         qword ptr [rsi+8],rbx
  000000000000014E: 0F B6 45 F8        movzx       eax,byte ptr [rbp-8]
  0000000000000152: 83 F8 03           cmp         eax,3
  0000000000000155: 74 0C              je          0000000000000163
  0000000000000157: 83 F8 02           cmp         eax,2
  000000000000015A: 74 10              je          000000000000016C
  000000000000015C: 83 F8 01           cmp         eax,1
  000000000000015F: 74 0B              je          000000000000016C
  0000000000000161: EB 0D              jmp         0000000000000170
  0000000000000163: 48 8D 4D E0        lea         rcx,[rbp-20h]
  0000000000000167: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  000000000000016C: C6 45 F8 00        mov         byte ptr [rbp-8],0
  0000000000000170: 48 89 F0           mov         rax,rsi
  0000000000000173: 48 81 C4 88 00 00  add         rsp,88h
                    00
  000000000000017A: 5B                 pop         rbx
  000000000000017B: 5F                 pop         rdi
  000000000000017C: 5E                 pop         rsi
  000000000000017D: 5D                 pop         rbp
  000000000000017E: C3                 ret
  000000000000017F: C7 45 D0 00 00 00  mov         dword ptr [rbp-30h],0
                    00
  0000000000000186: 48 C7 45 D8 00 00  mov         qword ptr [rbp-28h],0
                    00 00
  000000000000018E: 8B 05 00 00 00 00  mov         eax,dword ptr [?$TSS0@?1??monad_category@v1_std_std@outcome@boost@@YAAEBV0_detail@123@XZ@4HA]
  0000000000000194: 8B 0D 00 00 00 00  mov         ecx,dword ptr [_tls_index]
  000000000000019A: 65 48 8B 14 25 58  mov         rdx,qword ptr gs:[58h]
                    00 00 00
  00000000000001A3: 48 8B 0C CA        mov         rcx,qword ptr [rdx+rcx*8]
  00000000000001A7: 3B 81 00 00 00 00  cmp         eax,dword ptr _Init_thread_epoch[rcx]
  00000000000001AD: 7E 4B              jle         00000000000001FA
  00000000000001AF: 48 8D 0D 00 00 00  lea         rcx,[?$TSS0@?1??monad_category@v1_std_std@outcome@boost@@YAAEBV0_detail@123@XZ@4HA]
                    00
  00000000000001B6: E8 00 00 00 00     call        _Init_thread_header
  00000000000001BB: 8B 05 00 00 00 00  mov         eax,dword ptr [?$TSS0@?1??monad_category@v1_std_std@outcome@boost@@YAAEBV0_detail@123@XZ@4HA]
  00000000000001C1: 83 F8 FF           cmp         eax,0FFFFFFFFh
  00000000000001C4: 75 34              jne         00000000000001FA
  00000000000001C6: 48 8D 05 00 00 00  lea         rax,[?c@?1??monad_category@v1_std_std@outcome@boost@@YAAEBV1_detail@234@XZ@4V15234@A]
                    00
  00000000000001CD: 48 89 05 08 00 00  mov         qword ptr [?c@?1??monad_category@v1_std_std@outcome@boost@@YAAEBV1_detail@234@XZ@4V15234@A+8],rax
                    00
  00000000000001D4: 48 8D 05 00 00 00  lea         rax,[??_7monad_category@_detail@v1_std_std@outcome@boost@@6B@]
                    00
  00000000000001DB: 48 89 05 00 00 00  mov         qword ptr [?c@?1??monad_category@v1_std_std@outcome@boost@@YAAEBV1_detail@234@XZ@4V15234@A],rax
                    00
  00000000000001E2: 48 8D 0D 00 00 00  lea         rcx,[??__Fc@?1??monad_category@v1_std_std@outcome@boost@@YAAEBV1_detail@234@XZ@YAXXZ]
                    00
  00000000000001E9: E8 00 00 00 00     call        atexit
  00000000000001EE: 48 8D 0D 00 00 00  lea         rcx,[?$TSS0@?1??monad_category@v1_std_std@outcome@boost@@YAAEBV0_detail@123@XZ@4HA]
                    00
  00000000000001F5: E8 00 00 00 00     call        _Init_thread_footer
  00000000000001FA: C7 45 D0 02 00 00  mov         dword ptr [rbp-30h],2
                    00
  0000000000000201: 48 8D 05 00 00 00  lea         rax,[?c@?1??monad_category@v1_std_std@outcome@boost@@YAAEBV1_detail@234@XZ@4V15234@A]
                    00
  0000000000000208: 48 89 45 D8        mov         qword ptr [rbp-28h],rax
  000000000000020C: 48 8D 4D A8        lea         rcx,[rbp-58h]
  0000000000000210: 48 8D 55 D0        lea         rdx,[rbp-30h]
  0000000000000214: E8 00 00 00 00     call        replaced
  0000000000000000: 55                 push        rbp
  0000000000000001: 56                 push        rsi
  0000000000000002: 57                 push        rdi
  0000000000000003: 53                 push        rbx
  0000000000000004: 48 83 EC 58        sub         rsp,58h
  0000000000000008: 48 8D 6C 24 50     lea         rbp,[rsp+50h]
  000000000000000D: 48 C7 45 00 FE FF  mov         qword ptr [rbp],0FFFFFFFFFFFFFFFEh
                    FF FF
  0000000000000015: 48 89 D7           mov         rdi,rdx
  0000000000000018: 48 89 CE           mov         rsi,rcx
  000000000000001B: 48 8B 4F 08        mov         rcx,qword ptr [rdi+8]
  000000000000001F: 48 8B 01           mov         rax,qword ptr [rcx]
  0000000000000022: 44 8B 07           mov         r8d,dword ptr [rdi]
  0000000000000025: 48 8D 5D D0        lea         rbx,[rbp-30h]
  0000000000000029: 48 89 DA           mov         rdx,rbx
  000000000000002C: FF 50 10           call        qword ptr [rax+10h]
  000000000000002F: 48 83 7D E8 0F     cmp         qword ptr [rbp-18h],0Fh
  0000000000000034: 48 0F 47 5D D0     cmova       rbx,qword ptr [rbp-30h]
  0000000000000039: 48 8D 05 00 00 00  lea         rax,[??_7exception@std@@6B@]
                    00
  0000000000000040: 48 89 06           mov         qword ptr [rsi],rax
  0000000000000043: 48 8D 56 08        lea         rdx,[rsi+8]
  0000000000000047: 0F 57 C0           xorps       xmm0,xmm0
  000000000000004A: 0F 11 46 08        movups      xmmword ptr [rsi+8],xmm0
  000000000000004E: 48 89 5D F0        mov         qword ptr [rbp-10h],rbx
  0000000000000052: C6 45 F8 01        mov         byte ptr [rbp-8],1
  0000000000000056: 48 8D 4D F0        lea         rcx,[rbp-10h]
  000000000000005A: E8 00 00 00 00     call        __std_exception_copy
  000000000000005F: 48 8D 05 00 00 00  lea         rax,[??_7logic_error@std@@6B@]
                    00
  0000000000000066: 48 89 06           mov         qword ptr [rsi],rax
  0000000000000069: 48 8B 45 E8        mov         rax,qword ptr [rbp-18h]
  000000000000006D: 48 83 F8 10        cmp         rax,10h
  0000000000000071: 72 31              jb          00000000000000A4
  0000000000000073: 48 8B 4D D0        mov         rcx,qword ptr [rbp-30h]
  0000000000000077: 48 FF C0           inc         rax
  000000000000007A: 48 3D 00 10 00 00  cmp         rax,1000h
  0000000000000080: 72 1D              jb          000000000000009F
  0000000000000082: F6 C1 1F           test        cl,1Fh
  0000000000000085: 75 3A              jne         00000000000000C1
  0000000000000087: 48 8B 41 F8        mov         rax,qword ptr [rcx-8]
  000000000000008B: 48 29 C1           sub         rcx,rax
  000000000000008E: 76 38              jbe         00000000000000C8
  0000000000000090: 48 83 F9 07        cmp         rcx,7
  0000000000000094: 76 39              jbe         00000000000000CF
  0000000000000096: 48 83 F9 28        cmp         rcx,28h
  000000000000009A: 73 3A              jae         00000000000000D6
  000000000000009C: 48 89 C1           mov         rcx,rax
  000000000000009F: E8 00 00 00 00     call        ??3@YAXPEAX@Z
  00000000000000A4: 48 8D 05 00 00 00  lea         rax,[??_7monad_error@v1_std_std@outcome@boost@@6B@]
                    00
  00000000000000AB: 48 89 06           mov         qword ptr [rsi],rax
  00000000000000AE: 0F 10 07           movups      xmm0,xmmword ptr [rdi]
  00000000000000B1: 0F 11 46 18        movups      xmmword ptr [rsi+18h],xmm0
  00000000000000B5: 48 89 F0           mov         rax,rsi
  00000000000000B8: 48 83 C4 58        add         rsp,58h
  00000000000000BC: 5B                 pop         rbx
  00000000000000BD: 5F                 pop         rdi
  00000000000000BE: 5E                 pop         rsi
  00000000000000BF: 5D                 pop         rbp
  00000000000000C0: C3                 ret
  00000000000000C1: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  00000000000000C6: 0F 0B              ud2
  00000000000000C8: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  00000000000000CD: 0F 0B              ud2
  00000000000000CF: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  00000000000000D4: 0F 0B              ud2
  00000000000000D6: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  00000000000000DB: 0F 0B              ud2
  00000000000000DD: 0F 1F 00           nop         dword ptr [rax]

  0000000000000219: 48 8D 15 00 00 00  lea         rdx,[_TI3?AVmonad_error@v1_std_std@outcome@boost@@]
                    00
  0000000000000220: 48 8D 4D A8        lea         rcx,[rbp-58h]
  0000000000000224: E8 00 00 00 00     call        _CxxThrowException
  0000000000000229: 0F 0B              ud2
  000000000000022B: 0F 1F 44 00 00     nop         dword ptr [rax+rax]
