  0000000000000000: 55                 push        rbp
  0000000000000001: 56                 push        rsi
  0000000000000002: 57                 push        rdi
  0000000000000003: 53                 push        rbx
  0000000000000004: 48 81 EC 88 00 00  sub         rsp,88h
  000000000000000B: 48 8D AC 24 80 00  lea         rbp,[rsp+80h]
  0000000000000013: 48 C7 45 00 FE FF  mov         qword ptr [rbp],0FFFFFFFFFFFFFFFEh
  000000000000001B: 48 89 CE           mov         rsi,rcx
  000000000000001E: 48 8D 4D E0        lea         rcx,[rbp-20h]
  0000000000000022: E8 00 00 00 00     call        ?unknown@@YA?AV?$basic_monad@U?$monad_policy@H@policy@_1_0_std_std_9274c0d4@outcome@boost@@@_1_0_std_std_9274c0d4@outcome@boost@@XZ
  0000000000000027: 8A 45 F8           mov         al,byte ptr [rbp-8]
  000000000000002A: 3C 02              cmp         al,2
  000000000000002C: 0F 84 87 00 00 00  je          00000000000000B9
  0000000000000032: 3C 03              cmp         al,3
  0000000000000034: 0F 84 8B 00 00 00  je          00000000000000C5
  000000000000003A: 84 C0              test        al,al
  000000000000003C: 0F 84 30 01 00 00  je          0000000000000172
  0000000000000042: 8B 05 00 00 00 00  mov         eax,dword ptr [?$TSS0@?1???$_Immortalize@V_System_error_category@std@@@std@@YAAEAV_System_error_category@0@XZ@4HA]
  0000000000000048: 8B 0D 00 00 00 00  mov         ecx,dword ptr [_tls_index]
  000000000000004E: 65 48 8B 14 25 58  mov         rdx,qword ptr gs:[58h]
  0000000000000057: 48 8B 0C CA        mov         rcx,qword ptr [rdx+rcx*8]
  000000000000005B: 31 FF              xor         edi,edi
  000000000000005D: 48 8D 1D 00 00 00  lea         rbx,[?_Static@?1???$_Immortalize@V_System_error_category@std@@@std@@YAAEAV_System_error_category@1@XZ@4U?$_Immortalizer@V_System_error_category@std@@@1@A]
  0000000000000064: 3B 81 00 00 00 00  cmp         eax,dword ptr _Init_thread_epoch[rcx]
  000000000000006A: 0F 8E CD 00 00 00  jle         000000000000013D
  0000000000000070: 48 8D 0D 00 00 00  lea         rcx,[?$TSS0@?1???$_Immortalize@V_System_error_category@std@@@std@@YAAEAV_System_error_category@0@XZ@4HA]
  0000000000000077: E8 00 00 00 00     call        _Init_thread_header
  000000000000007C: 8B 05 00 00 00 00  mov         eax,dword ptr [?$TSS0@?1???$_Immortalize@V_System_error_category@std@@@std@@YAAEAV_System_error_category@0@XZ@4HA]
  0000000000000082: 83 F8 FF           cmp         eax,0FFFFFFFFh
  0000000000000085: 0F 85 B2 00 00 00  jne         000000000000013D
  000000000000008B: 48 8D 05 00 00 00  lea         rax,[??_7_System_error_category@std@@6B@]
  0000000000000092: 48 89 05 00 00 00  mov         qword ptr [?_Static@?1???$_Immortalize@V_System_error_category@std@@@std@@YAAEAV_System_error_category@1@XZ@4U?$_Immortalizer@V_System_error_category@std@@@1@A],rax
  0000000000000099: 48 C7 05 04 00 00  mov         qword ptr [?_Static@?1???$_Immortalize@V_System_error_category@std@@@std@@YAAEAV_System_error_category@1@XZ@4U?$_Immortalizer@V_System_error_category@std@@@1@A+4],7
  00000000000000A4: 48 8D 0D 00 00 00  lea         rcx,[??__F_Static@?1???$_Immortalize@V_System_error_category@std@@@std@@YAAEAV_System_error_category@1@XZ@YAXXZ]
  00000000000000AB: E8 00 00 00 00     call        atexit
  00000000000000B0: 48 8D 0D 00 00 00  lea         rcx,[?$TSS0@?1???$_Immortalize@V_System_error_category@std@@@std@@YAAEAV_System_error_category@0@XZ@4HA]
  00000000000000B7: EB 7F              jmp         0000000000000138
  00000000000000B9: 8B 7D E0           mov         edi,dword ptr [rbp-20h]
  00000000000000BC: 8B 45 E4           mov         eax,dword ptr [rbp-1Ch]
  00000000000000BF: 48 8B 5D E8        mov         rbx,qword ptr [rbp-18h]
  00000000000000C3: EB 78              jmp         000000000000013D
  00000000000000C5: 8B 05 00 00 00 00  mov         eax,dword ptr [?$TSS0@?1??monad_category@_1_0_std_std_9274c0d4@outcome@boost@@YAAEBV0_detail@123@XZ@4HA]
  00000000000000CB: 8B 0D 00 00 00 00  mov         ecx,dword ptr [_tls_index]
  00000000000000D1: 65 48 8B 14 25 58  mov         rdx,qword ptr gs:[58h]
  00000000000000DA: 48 8B 0C CA        mov         rcx,qword ptr [rdx+rcx*8]
  00000000000000DE: BF 03 00 00 00     mov         edi,3
  00000000000000E3: 48 8D 1D 00 00 00  lea         rbx,[?c@?1??monad_category@_1_0_std_std_9274c0d4@outcome@boost@@YAAEBV1_detail@234@XZ@4V15234@A]
  00000000000000EA: 3B 81 00 00 00 00  cmp         eax,dword ptr _Init_thread_epoch[rcx]
  00000000000000F0: 7E 4B              jle         000000000000013D
  00000000000000F2: 48 8D 0D 00 00 00  lea         rcx,[?$TSS0@?1??monad_category@_1_0_std_std_9274c0d4@outcome@boost@@YAAEBV0_detail@123@XZ@4HA]
  00000000000000F9: E8 00 00 00 00     call        _Init_thread_header
  00000000000000FE: 8B 05 00 00 00 00  mov         eax,dword ptr [?$TSS0@?1??monad_category@_1_0_std_std_9274c0d4@outcome@boost@@YAAEBV0_detail@123@XZ@4HA]
  0000000000000104: 83 F8 FF           cmp         eax,0FFFFFFFFh
  0000000000000107: 75 34              jne         000000000000013D
  0000000000000109: 48 8D 1D 00 00 00  lea         rbx,[?c@?1??monad_category@_1_0_std_std_9274c0d4@outcome@boost@@YAAEBV1_detail@234@XZ@4V15234@A]
  0000000000000110: 48 89 1D 08 00 00  mov         qword ptr [?c@?1??monad_category@_1_0_std_std_9274c0d4@outcome@boost@@YAAEBV1_detail@234@XZ@4V15234@A+8],rbx
  0000000000000117: 48 8D 05 00 00 00  lea         rax,[??_7monad_category@_detail@_1_0_std_std_9274c0d4@outcome@boost@@6B@]
  000000000000011E: 48 89 05 00 00 00  mov         qword ptr [?c@?1??monad_category@_1_0_std_std_9274c0d4@outcome@boost@@YAAEBV1_detail@234@XZ@4V15234@A],rax
  0000000000000125: 48 8D 0D 00 00 00  lea         rcx,[??__Fc@?1??monad_category@_1_0_std_std_9274c0d4@outcome@boost@@YAAEBV1_detail@234@XZ@YAXXZ]
  000000000000012C: E8 00 00 00 00     call        atexit
  0000000000000131: 48 8D 0D 00 00 00  lea         rcx,[?$TSS0@?1??monad_category@_1_0_std_std_9274c0d4@outcome@boost@@YAAEBV0_detail@123@XZ@4HA]
  0000000000000138: E8 00 00 00 00     call        _Init_thread_footer
  000000000000013D: 89 3E              mov         dword ptr [rsi],edi
  000000000000013F: 89 46 04           mov         dword ptr [rsi+4],eax
  0000000000000142: 48 89 5E 08        mov         qword ptr [rsi+8],rbx
  0000000000000146: 8A 45 F8           mov         al,byte ptr [rbp-8]
  0000000000000149: 89 C1              mov         ecx,eax
  000000000000014B: FE C9              dec         cl
  000000000000014D: 80 F9 02           cmp         cl,2
  0000000000000150: 72 0D              jb          000000000000015F
  0000000000000152: 3C 03              cmp         al,3
  0000000000000154: 75 0D              jne         0000000000000163
  0000000000000156: 48 8D 4D E0        lea         rcx,[rbp-20h]
  000000000000015A: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  000000000000015F: C6 45 F8 00        mov         byte ptr [rbp-8],0
  0000000000000163: 48 89 F0           mov         rax,rsi
  0000000000000166: 48 81 C4 88 00 00  add         rsp,88h
  000000000000016D: 5B                 pop         rbx
  000000000000016E: 5F                 pop         rdi
  000000000000016F: 5E                 pop         rsi
  0000000000000170: 5D                 pop         rbp
  0000000000000171: C3                 ret
  0000000000000172: C7 45 D0 00 00 00  mov         dword ptr [rbp-30h],0
  0000000000000179: 48 C7 45 D8 00 00  mov         qword ptr [rbp-28h],0
  0000000000000181: 8B 05 00 00 00 00  mov         eax,dword ptr [?$TSS0@?1??monad_category@_1_0_std_std_9274c0d4@outcome@boost@@YAAEBV0_detail@123@XZ@4HA]
  0000000000000187: 8B 0D 00 00 00 00  mov         ecx,dword ptr [_tls_index]
  000000000000018D: 65 48 8B 14 25 58  mov         rdx,qword ptr gs:[58h]
  0000000000000196: 48 8B 0C CA        mov         rcx,qword ptr [rdx+rcx*8]
  000000000000019A: 3B 81 00 00 00 00  cmp         eax,dword ptr _Init_thread_epoch[rcx]
  00000000000001A0: 7E 4B              jle         00000000000001ED
  00000000000001A2: 48 8D 0D 00 00 00  lea         rcx,[?$TSS0@?1??monad_category@_1_0_std_std_9274c0d4@outcome@boost@@YAAEBV0_detail@123@XZ@4HA]
  00000000000001A9: E8 00 00 00 00     call        _Init_thread_header
  00000000000001AE: 8B 05 00 00 00 00  mov         eax,dword ptr [?$TSS0@?1??monad_category@_1_0_std_std_9274c0d4@outcome@boost@@YAAEBV0_detail@123@XZ@4HA]
  00000000000001B4: 83 F8 FF           cmp         eax,0FFFFFFFFh
  00000000000001B7: 75 34              jne         00000000000001ED
  00000000000001B9: 48 8D 05 00 00 00  lea         rax,[?c@?1??monad_category@_1_0_std_std_9274c0d4@outcome@boost@@YAAEBV1_detail@234@XZ@4V15234@A]
  00000000000001C0: 48 89 05 08 00 00  mov         qword ptr [?c@?1??monad_category@_1_0_std_std_9274c0d4@outcome@boost@@YAAEBV1_detail@234@XZ@4V15234@A+8],rax
  00000000000001C7: 48 8D 05 00 00 00  lea         rax,[??_7monad_category@_detail@_1_0_std_std_9274c0d4@outcome@boost@@6B@]
  00000000000001CE: 48 89 05 00 00 00  mov         qword ptr [?c@?1??monad_category@_1_0_std_std_9274c0d4@outcome@boost@@YAAEBV1_detail@234@XZ@4V15234@A],rax
  00000000000001D5: 48 8D 0D 00 00 00  lea         rcx,[??__Fc@?1??monad_category@_1_0_std_std_9274c0d4@outcome@boost@@YAAEBV1_detail@234@XZ@YAXXZ]
  00000000000001DC: E8 00 00 00 00     call        atexit
  00000000000001E1: 48 8D 0D 00 00 00  lea         rcx,[?$TSS0@?1??monad_category@_1_0_std_std_9274c0d4@outcome@boost@@YAAEBV0_detail@123@XZ@4HA]
  00000000000001E8: E8 00 00 00 00     call        _Init_thread_footer
  00000000000001ED: C7 45 D0 02 00 00  mov         dword ptr [rbp-30h],2
  00000000000001F4: 48 8D 05 00 00 00  lea         rax,[?c@?1??monad_category@_1_0_std_std_9274c0d4@outcome@boost@@YAAEBV1_detail@234@XZ@4V15234@A]
  00000000000001FB: 48 89 45 D8        mov         qword ptr [rbp-28h],rax
  00000000000001FF: 48 8D 4D A8        lea         rcx,[rbp-58h]
  0000000000000203: 48 8D 55 D0        lea         rdx,[rbp-30h]
  0000000000000000: 55                 push        rbp
  0000000000000001: 56                 push        rsi
  0000000000000002: 57                 push        rdi
  0000000000000003: 48 83 EC 70        sub         rsp,70h
  0000000000000007: 48 8D 6C 24 70     lea         rbp,[rsp+70h]
  000000000000000C: 48 C7 45 F8 FE FF  mov         qword ptr [rbp-8],0FFFFFFFFFFFFFFFEh
  0000000000000014: 48 89 CE           mov         rsi,rcx
  0000000000000017: 0F 10 02           movups      xmm0,xmmword ptr [rdx]
  000000000000001A: 0F 29 45 C0        movaps      xmmword ptr [rbp-40h],xmm0
  000000000000001E: B8 0F 00 00 00     mov         eax,0Fh
  0000000000000023: 66 48 0F 6E C0     movq        xmm0,rax
  0000000000000028: 66 0F 73 F8 08     pslldq      xmm0,8
  000000000000002D: F3 0F 7F 45 E8     movdqu      xmmword ptr [rbp-18h],xmm0
  0000000000000032: C6 45 D8 00        mov         byte ptr [rbp-28h],0
  0000000000000036: 48 8D 15 00 00 00  lea         rdx,[??_C@_00CNPNBAHC@?$AA@]
  000000000000003D: 48 8D 7D D8        lea         rdi,[rbp-28h]
  0000000000000041: 45 31 C0           xor         r8d,r8d
  0000000000000044: 48 89 F9           mov         rcx,rdi
  0000000000000000: 56                 push        rsi
  0000000000000001: 57                 push        rdi
  0000000000000002: 53                 push        rbx
  0000000000000003: 48 83 EC 20        sub         rsp,20h
  0000000000000007: 4C 89 C3           mov         rbx,r8
  000000000000000A: 48 89 D7           mov         rdi,rdx
  000000000000000D: 48 89 CE           mov         rsi,rcx
  0000000000000010: 48 8B 46 18        mov         rax,qword ptr [rsi+18h]
  0000000000000014: 48 83 F8 10        cmp         rax,10h
  0000000000000018: 72 0A              jb          0000000000000024
  000000000000001A: 48 8B 16           mov         rdx,qword ptr [rsi]
  000000000000001D: 48 39 FA           cmp         rdx,rdi
  0000000000000020: 76 0A              jbe         000000000000002C
  0000000000000022: EB 1F              jmp         0000000000000043
  0000000000000024: 48 89 F2           mov         rdx,rsi
  0000000000000027: 48 39 FA           cmp         rdx,rdi
  000000000000002A: 77 17              ja          0000000000000043
  000000000000002C: 48 8B 4E 10        mov         rcx,qword ptr [rsi+10h]
  0000000000000030: 48 01 CA           add         rdx,rcx
  0000000000000033: 48 39 FA           cmp         rdx,rdi
  0000000000000036: 76 0B              jbe         0000000000000043
  0000000000000038: 48 83 F8 10        cmp         rax,10h
  000000000000003C: 72 34              jb          0000000000000072
  000000000000003E: 48 8B 16           mov         rdx,qword ptr [rsi]
  0000000000000041: EB 32              jmp         0000000000000075
  0000000000000043: 48 85 DB           test        rbx,rbx
  0000000000000046: 0F 84 AA 00 00 00  je          00000000000000F6
  000000000000004C: 48 39 D8           cmp         rax,rbx
  000000000000004F: 73 0F              jae         0000000000000060
  0000000000000051: 48 89 F1           mov         rcx,rsi
  0000000000000054: 48 89 DA           mov         rdx,rbx
  0000000000000000: 55                 push        rbp
  0000000000000001: 56                 push        rsi
  0000000000000002: 57                 push        rdi
  0000000000000003: 53                 push        rbx
  0000000000000004: 48 83 EC 48        sub         rsp,48h
  0000000000000008: 48 8D 6C 24 40     lea         rbp,[rsp+40h]
  000000000000000D: 48 C7 45 00 FE FF  mov         qword ptr [rbp],0FFFFFFFFFFFFFFFEh
  0000000000000015: 48 89 D7           mov         rdi,rdx
  0000000000000018: 48 83 FF FF        cmp         rdi,0FFFFFFFFFFFFFFFFh
  000000000000001C: 0F 84 32 01 00 00  je          0000000000000154
  0000000000000022: 48 89 4D E0        mov         qword ptr [rbp-20h],rcx
  0000000000000026: 4C 8B 41 18        mov         r8,qword ptr [rcx+18h]
  000000000000002A: 48 89 F9           mov         rcx,rdi
  000000000000002D: 48 83 C9 0F        or          rcx,0Fh
  0000000000000031: 48 83 F9 FF        cmp         rcx,0FFFFFFFFFFFFFFFFh
  0000000000000035: 48 89 FB           mov         rbx,rdi
  0000000000000038: 74 3F              je          0000000000000079
  000000000000003A: 4C 89 C6           mov         rsi,r8
  000000000000003D: 48 D1 EE           shr         rsi,1
  0000000000000040: 48 BA AB AA AA AA  mov         rdx,0AAAAAAAAAAAAAAABh
  000000000000004A: 48 89 C8           mov         rax,rcx
  000000000000004D: 48 F7 E2           mul         rax,rdx
  0000000000000050: 48 D1 EA           shr         rdx,1
  0000000000000053: 48 39 D6           cmp         rsi,rdx
  0000000000000056: 48 89 CB           mov         rbx,rcx
  0000000000000059: 76 1E              jbe         0000000000000079
  000000000000005B: 48 C7 C0 FE FF FF  mov         rax,0FFFFFFFFFFFFFFFEh
  0000000000000062: 48 C7 C1 FE FF FF  mov         rcx,0FFFFFFFFFFFFFFFEh
  0000000000000069: 48 29 F1           sub         rcx,rsi
  000000000000006C: 4C 01 C6           add         rsi,r8
  000000000000006F: 49 39 C8           cmp         r8,rcx
  0000000000000072: 48 0F 47 F0        cmova       rsi,rax
  0000000000000076: 48 89 F3           mov         rbx,rsi
  0000000000000079: 48 89 D9           mov         rcx,rbx
  000000000000007C: 48 FF C1           inc         rcx
  000000000000007F: 4C 89 45 E8        mov         qword ptr [rbp-18h],r8
  0000000000000083: 74 38              je          00000000000000BD
  0000000000000085: 48 81 F9 00 10 00  cmp         rcx,1000h
  000000000000008C: 48 89 7D F0        mov         qword ptr [rbp-10h],rdi
  0000000000000090: 72 3B              jb          00000000000000CD
  0000000000000092: 48 83 F9 D9        cmp         rcx,0FFFFFFFFFFFFFFD9h
  0000000000000096: 0F 83 C6 00 00 00  jae         0000000000000162
  000000000000009C: 48 8D 4B 28        lea         rcx,[rbx+28h]
  00000000000000A0: E8 00 00 00 00     call        ??2@YAPEAX_K@Z
  00000000000000A5: 48 89 C1           mov         rcx,rax
  00000000000000A8: 48 83 C1 27        add         rcx,27h
  00000000000000AC: 48 83 E1 E0        and         rcx,0FFFFFFFFFFFFFFE0h
  00000000000000B0: 48 89 CA           mov         rdx,rcx
  00000000000000B3: 48 89 55 F8        mov         qword ptr [rbp-8],rdx
  00000000000000B7: 48 89 41 F8        mov         qword ptr [rcx-8],rax
  00000000000000BB: EB 19              jmp         00000000000000D6
  00000000000000BD: 31 C0              xor         eax,eax
  00000000000000BF: 48 89 45 F8        mov         qword ptr [rbp-8],rax
  00000000000000C3: 48 C7 45 F0 FF FF  mov         qword ptr [rbp-10h],0FFFFFFFFFFFFFFFFh
  00000000000000CB: EB 0D              jmp         00000000000000DA
  00000000000000CD: E8 00 00 00 00     call        ??2@YAPEAX_K@Z
  00000000000000D2: 48 89 45 F8        mov         qword ptr [rbp-8],rax
  00000000000000D6: 48 89 5D F0        mov         qword ptr [rbp-10h],rbx
  00000000000000DA: 48 8B 75 E0        mov         rsi,qword ptr [rbp-20h]
  00000000000000DE: 4C 8B 46 10        mov         r8,qword ptr [rsi+10h]
  00000000000000E2: 49 FF C0           inc         r8
  00000000000000E5: 48 83 7E 18 10     cmp         qword ptr [rsi+18h],10h
  00000000000000EA: 72 45              jb          0000000000000131
  00000000000000EC: 48 8B 16           mov         rdx,qword ptr [rsi]
  00000000000000EF: 48 8B 7D F8        mov         rdi,qword ptr [rbp-8]
  00000000000000F3: 48 89 F9           mov         rcx,rdi
  00000000000000F6: E8 00 00 00 00     call        memcpy
  00000000000000FB: 48 8B 45 E8        mov         rax,qword ptr [rbp-18h]
  00000000000000FF: 48 FF C0           inc         rax
  0000000000000102: 48 8B 0E           mov         rcx,qword ptr [rsi]
  0000000000000105: 48 3D 00 10 00 00  cmp         rax,1000h
  000000000000010B: 72 1D              jb          000000000000012A
  000000000000010D: F6 C1 1F           test        cl,1Fh
  0000000000000110: 75 57              jne         0000000000000169
  0000000000000112: 48 8B 41 F8        mov         rax,qword ptr [rcx-8]
  0000000000000116: 48 29 C1           sub         rcx,rax
  0000000000000119: 76 40              jbe         000000000000015B
  000000000000011B: 48 83 F9 07        cmp         rcx,7
  000000000000011F: 76 3A              jbe         000000000000015B
  0000000000000121: 48 83 F9 28        cmp         rcx,28h
  0000000000000125: 73 34              jae         000000000000015B
  0000000000000127: 48 89 C1           mov         rcx,rax
  000000000000012A: E8 00 00 00 00     call        ??3@YAXPEAX@Z
  000000000000012F: EB 0F              jmp         0000000000000140
  0000000000000131: 48 8B 7D F8        mov         rdi,qword ptr [rbp-8]
  0000000000000135: 48 89 F9           mov         rcx,rdi
  0000000000000138: 48 89 F2           mov         rdx,rsi
  000000000000013B: E8 00 00 00 00     call        memcpy
  0000000000000140: 48 89 3E           mov         qword ptr [rsi],rdi
  0000000000000143: 48 8B 45 F0        mov         rax,qword ptr [rbp-10h]
  0000000000000147: 48 89 46 18        mov         qword ptr [rsi+18h],rax
  000000000000014B: 48 83 C4 48        add         rsp,48h
  000000000000014F: 5B                 pop         rbx
  0000000000000150: 5F                 pop         rdi
  0000000000000151: 5E                 pop         rsi
  0000000000000152: 5D                 pop         rbp
  0000000000000153: C3                 ret
  0000000000000000: 48 83 EC 28        sub         rsp,28h
  0000000000000004: 48 8D 0D 00 00 00  lea         rcx,[??_C@_0BA@JFNIOLAK@string?5too?5long?$AA@]
  000000000000000B: E8 00 00 00 00     call        ?_Xlength_error@std@@YAXPEBD@Z
  0000000000000010: 0F 0B              ud2
  0000000000000159: 0F 0B              ud2
  000000000000015B: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000160: 0F 0B              ud2
  0000000000000162: E8 00 00 00 00     call        ?_Xbad_alloc@std@@YAXXZ
  0000000000000167: 0F 0B              ud2
  0000000000000169: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  000000000000016E: 0F 0B              ud2
  000000000000005C: 48 8B 46 18        mov         rax,qword ptr [rsi+18h]
  0000000000000060: 48 83 F8 10        cmp         rax,10h
  0000000000000064: 0F 82 9F 00 00 00  jb          0000000000000109
  000000000000006A: 48 8B 0E           mov         rcx,qword ptr [rsi]
  000000000000006D: E9 9A 00 00 00     jmp         000000000000010C
  0000000000000072: 48 89 F2           mov         rdx,rsi
  0000000000000075: 48 29 D7           sub         rdi,rdx
  0000000000000078: 48 89 CA           mov         rdx,rcx
  000000000000007B: 48 29 FA           sub         rdx,rdi
  000000000000007E: 0F 82 C4 00 00 00  jb          0000000000000148
  0000000000000084: 48 39 DA           cmp         rdx,rbx
  0000000000000087: 48 0F 42 DA        cmovb       rbx,rdx
  000000000000008B: 48 01 FB           add         rbx,rdi
  000000000000008E: 48 39 D9           cmp         rcx,rbx
  0000000000000091: 0F 82 B1 00 00 00  jb          0000000000000148
  0000000000000097: 48 83 F8 0F        cmp         rax,0Fh
  000000000000009B: 48 8B 06           mov         rax,qword ptr [rsi]
  000000000000009E: 48 0F 46 C6        cmovbe      rax,rsi
  00000000000000A2: 48 89 5E 10        mov         qword ptr [rsi+10h],rbx
  00000000000000A6: C6 04 18 00        mov         byte ptr [rax+rbx],0
  00000000000000AA: 48 8B 5E 10        mov         rbx,qword ptr [rsi+10h]
  00000000000000AE: 48 29 FB           sub         rbx,rdi
  00000000000000B1: 76 2D              jbe         00000000000000E0
  00000000000000B3: 48 85 FF           test        rdi,rdi
  00000000000000B6: 74 78              je          0000000000000130
  00000000000000B8: 48 83 7E 18 0F     cmp         qword ptr [rsi+18h],0Fh
  00000000000000BD: 48 8B 0E           mov         rcx,qword ptr [rsi]
  00000000000000C0: 48 0F 46 CE        cmovbe      rcx,rsi
  00000000000000C4: 48 01 CF           add         rdi,rcx
  00000000000000C7: 48 89 FA           mov         rdx,rdi
  00000000000000CA: 49 89 D8           mov         r8,rbx
  00000000000000CD: E8 00 00 00 00     call        memmove
  00000000000000D2: 48 83 7E 18 0F     cmp         qword ptr [rsi+18h],0Fh
  00000000000000D7: 48 8B 06           mov         rax,qword ptr [rsi]
  00000000000000DA: 48 0F 46 C6        cmovbe      rax,rsi
  00000000000000DE: EB 46              jmp         0000000000000126
  00000000000000E0: 48 83 7E 18 0F     cmp         qword ptr [rsi+18h],0Fh
  00000000000000E5: 48 8B 06           mov         rax,qword ptr [rsi]
  00000000000000E8: 48 0F 46 C6        cmovbe      rax,rsi
  00000000000000EC: 48 C7 46 10 00 00  mov         qword ptr [rsi+10h],0
  00000000000000F4: EB 37              jmp         000000000000012D
  00000000000000F6: 48 83 F8 10        cmp         rax,10h
  00000000000000FA: 72 3F              jb          000000000000013B
  00000000000000FC: 48 8B 06           mov         rax,qword ptr [rsi]
  00000000000000FF: 48 C7 46 10 00 00  mov         qword ptr [rsi+10h],0
  0000000000000107: EB 24              jmp         000000000000012D
  0000000000000109: 48 89 F1           mov         rcx,rsi
  000000000000010C: 48 89 FA           mov         rdx,rdi
  000000000000010F: 49 89 D8           mov         r8,rbx
  0000000000000112: E8 00 00 00 00     call        memcpy
  0000000000000117: 48 83 7E 18 10     cmp         qword ptr [rsi+18h],10h
  000000000000011C: 72 05              jb          0000000000000123
  000000000000011E: 48 8B 06           mov         rax,qword ptr [rsi]
  0000000000000121: EB 03              jmp         0000000000000126
  0000000000000123: 48 89 F0           mov         rax,rsi
  0000000000000126: 48 89 5E 10        mov         qword ptr [rsi+10h],rbx
  000000000000012A: 48 01 D8           add         rax,rbx
  000000000000012D: C6 00 00           mov         byte ptr [rax],0
  0000000000000130: 48 89 F0           mov         rax,rsi
  0000000000000133: 48 83 C4 20        add         rsp,20h
  0000000000000137: 5B                 pop         rbx
  0000000000000138: 5F                 pop         rdi
  0000000000000139: 5E                 pop         rsi
  000000000000013A: C3                 ret
  000000000000013B: 48 C7 46 10 00 00  mov         qword ptr [rsi+10h],0
  0000000000000143: 48 89 F0           mov         rax,rsi
  0000000000000146: EB E5              jmp         000000000000012D
  0000000000000000: 48 83 EC 28        sub         rsp,28h
  0000000000000004: 48 8D 0D 00 00 00  lea         rcx,[??_C@_0BI@CFPLBAOH@invalid?5string?5position?$AA@]
  000000000000000B: E8 00 00 00 00     call        ?_Xout_of_range@std@@YAXPEBD@Z
  0000000000000010: 0F 0B              ud2
  000000000000014D: 0F 0B              ud2
  000000000000004C: 0F 28 45 C0        movaps      xmm0,xmmword ptr [rbp-40h]
  0000000000000050: 0F 29 45 B0        movaps      xmmword ptr [rbp-50h],xmm0
  0000000000000054: 48 8D 55 B0        lea         rdx,[rbp-50h]
  0000000000000058: 48 89 F1           mov         rcx,rsi
  000000000000005B: 49 89 F8           mov         r8,rdi
  0000000000000000: 55                 push        rbp
  0000000000000001: 41 56              push        r14
  0000000000000003: 56                 push        rsi
  0000000000000004: 57                 push        rdi
  0000000000000005: 53                 push        rbx
  0000000000000006: 48 81 EC 90 00 00  sub         rsp,90h
  000000000000000D: 48 8D AC 24 80 00  lea         rbp,[rsp+80h]
  0000000000000015: 48 C7 45 08 FE FF  mov         qword ptr [rbp+8],0FFFFFFFFFFFFFFFEh
  000000000000001D: 4C 89 C0           mov         rax,r8
  0000000000000020: 49 89 D6           mov         r14,rdx
  0000000000000023: 48 89 CE           mov         rsi,rcx
  0000000000000026: B9 0F 00 00 00     mov         ecx,0Fh
  000000000000002B: 66 48 0F 6E C1     movq        xmm0,rcx
  0000000000000030: 66 0F 73 F8 08     pslldq      xmm0,8
  0000000000000035: F3 0F 7F 45 B0     movdqu      xmmword ptr [rbp-50h],xmm0
  000000000000003A: C6 45 A0 00        mov         byte ptr [rbp-60h],0
  000000000000003E: 48 8D 5D A0        lea         rbx,[rbp-60h]
  0000000000000042: 45 31 C0           xor         r8d,r8d
  0000000000000045: 49 C7 C1 FF FF FF  mov         r9,0FFFFFFFFFFFFFFFFh
  000000000000004C: 48 89 D9           mov         rcx,rbx
  000000000000004F: 48 89 C2           mov         rdx,rax
  0000000000000000: 41 56              push        r14
  0000000000000002: 56                 push        rsi
  0000000000000003: 57                 push        rdi
  0000000000000004: 53                 push        rbx
  0000000000000005: 48 83 EC 28        sub         rsp,28h
  0000000000000009: 4C 89 CB           mov         rbx,r9
  000000000000000C: 4C 89 C6           mov         rsi,r8
  000000000000000F: 48 89 D7           mov         rdi,rdx
  0000000000000012: 49 89 CE           mov         r14,rcx
  0000000000000015: 48 8B 47 10        mov         rax,qword ptr [rdi+10h]
  0000000000000019: 48 89 C1           mov         rcx,rax
  000000000000001C: 48 29 F1           sub         rcx,rsi
  000000000000001F: 0F 82 0C 01 00 00  jb          0000000000000131
  0000000000000025: 48 39 D9           cmp         rcx,rbx
  0000000000000028: 48 0F 42 D9        cmovb       rbx,rcx
  000000000000002C: 4C 39 F7           cmp         rdi,r14
  000000000000002F: 74 38              je          0000000000000069
  0000000000000031: 49 8B 46 18        mov         rax,qword ptr [r14+18h]
  0000000000000035: 48 85 DB           test        rbx,rbx
  0000000000000038: 0F 84 89 00 00 00  je          00000000000000C7
  000000000000003E: 48 39 D8           cmp         rax,rbx
  0000000000000041: 73 0F              jae         0000000000000052
  0000000000000043: 4C 89 F1           mov         rcx,r14
  0000000000000046: 48 89 DA           mov         rdx,rbx
  0000000000000049: E8 00 00 00 00     call        ?_Copy@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAX_K@Z
  000000000000004E: 49 8B 46 18        mov         rax,qword ptr [r14+18h]
  0000000000000052: 48 83 7F 18 0F     cmp         qword ptr [rdi+18h],0Fh
  0000000000000057: 48 0F 47 3F        cmova       rdi,qword ptr [rdi]
  000000000000005B: 48 01 F7           add         rdi,rsi
  000000000000005E: 48 83 F8 10        cmp         rax,10h
  0000000000000062: 72 76              jb          00000000000000DA
  0000000000000064: 49 8B 0E           mov         rcx,qword ptr [r14]
  0000000000000067: EB 74              jmp         00000000000000DD
  0000000000000069: 48 01 F3           add         rbx,rsi
  000000000000006C: 48 39 D8           cmp         rax,rbx
  000000000000006F: 0F 82 BC 00 00 00  jb          0000000000000131
  0000000000000075: 48 83 7F 18 0F     cmp         qword ptr [rdi+18h],0Fh
  000000000000007A: 48 8B 07           mov         rax,qword ptr [rdi]
  000000000000007D: 48 0F 46 C7        cmovbe      rax,rdi
  0000000000000081: 48 89 5F 10        mov         qword ptr [rdi+10h],rbx
  0000000000000085: C6 04 18 00        mov         byte ptr [rax+rbx],0
  0000000000000089: 48 8B 5F 10        mov         rbx,qword ptr [rdi+10h]
  000000000000008D: 48 29 F3           sub         rbx,rsi
  0000000000000090: 76 6E              jbe         0000000000000100
  0000000000000092: 48 85 F6           test        rsi,rsi
  0000000000000095: 0F 84 89 00 00 00  je          0000000000000124
  000000000000009B: 48 83 7F 18 0F     cmp         qword ptr [rdi+18h],0Fh
  00000000000000A0: 48 8B 0F           mov         rcx,qword ptr [rdi]
  00000000000000A3: 48 0F 46 CF        cmovbe      rcx,rdi
  00000000000000A7: 48 01 CE           add         rsi,rcx
  00000000000000AA: 48 89 F2           mov         rdx,rsi
  00000000000000AD: 49 89 D8           mov         r8,rbx
  00000000000000B0: E8 00 00 00 00     call        memmove
  00000000000000B5: 48 83 7F 18 0F     cmp         qword ptr [rdi+18h],0Fh
  00000000000000BA: 48 8B 07           mov         rax,qword ptr [rdi]
  00000000000000BD: 48 0F 46 C7        cmovbe      rax,rdi
  00000000000000C1: 48 89 5F 10        mov         qword ptr [rdi+10h],rbx
  00000000000000C5: EB 34              jmp         00000000000000FB
  00000000000000C7: 48 83 F8 10        cmp         rax,10h
  00000000000000CB: 72 49              jb          0000000000000116
  00000000000000CD: 49 8B 06           mov         rax,qword ptr [r14]
  00000000000000D0: 49 C7 46 10 00 00  mov         qword ptr [r14+10h],0
  00000000000000D8: EB 47              jmp         0000000000000121
  00000000000000DA: 4C 89 F1           mov         rcx,r14
  00000000000000DD: 48 89 FA           mov         rdx,rdi
  00000000000000E0: 49 89 D8           mov         r8,rbx
  00000000000000E3: E8 00 00 00 00     call        memcpy
  00000000000000E8: 49 83 7E 18 10     cmp         qword ptr [r14+18h],10h
  00000000000000ED: 72 05              jb          00000000000000F4
  00000000000000EF: 49 8B 06           mov         rax,qword ptr [r14]
  00000000000000F2: EB 03              jmp         00000000000000F7
  00000000000000F4: 4C 89 F0           mov         rax,r14
  00000000000000F7: 49 89 5E 10        mov         qword ptr [r14+10h],rbx
  00000000000000FB: 48 01 D8           add         rax,rbx
  00000000000000FE: EB 21              jmp         0000000000000121
  0000000000000100: 48 83 7F 18 0F     cmp         qword ptr [rdi+18h],0Fh
  0000000000000105: 48 8B 07           mov         rax,qword ptr [rdi]
  0000000000000108: 48 0F 46 C7        cmovbe      rax,rdi
  000000000000010C: 48 C7 47 10 00 00  mov         qword ptr [rdi+10h],0
  0000000000000114: EB 0B              jmp         0000000000000121
  0000000000000116: 49 C7 46 10 00 00  mov         qword ptr [r14+10h],0
  000000000000011E: 4C 89 F0           mov         rax,r14
  0000000000000121: C6 00 00           mov         byte ptr [rax],0
  0000000000000124: 4C 89 F0           mov         rax,r14
  0000000000000127: 48 83 C4 28        add         rsp,28h
  000000000000012B: 5B                 pop         rbx
  000000000000012C: 5F                 pop         rdi
  000000000000012D: 5E                 pop         rsi
  000000000000012E: 41 5E              pop         r14
  0000000000000130: C3                 ret
  0000000000000131: E8 00 00 00 00     call        ?_Xran@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@SAXXZ
  0000000000000136: 0F 0B              ud2
  0000000000000057: 41 0F 10 06        movups      xmm0,xmmword ptr [r14]
  000000000000005B: 0F 29 45 C0        movaps      xmmword ptr [rbp-40h],xmm0
  000000000000005F: 48 8D 7D D8        lea         rdi,[rbp-28h]
  0000000000000063: 48 8D 55 C0        lea         rdx,[rbp-40h]
  0000000000000067: 48 89 F9           mov         rcx,rdi
  000000000000006A: 49 89 D8           mov         r8,rbx
  0000000000000000: 55                 push        rbp
  0000000000000001: 56                 push        rsi
  0000000000000002: 57                 push        rdi
  0000000000000003: 48 83 EC 50        sub         rsp,50h
  0000000000000007: 48 8D 6C 24 50     lea         rbp,[rsp+50h]
  000000000000000C: 48 C7 45 F8 FE FF  mov         qword ptr [rbp-8],0FFFFFFFFFFFFFFFEh
  0000000000000014: 48 89 D7           mov         rdi,rdx
  0000000000000017: 48 89 CE           mov         rsi,rcx
  000000000000001A: 4C 89 45 F0        mov         qword ptr [rbp-10h],r8
  000000000000001E: 49 83 78 10 00     cmp         qword ptr [r8+10h],0
  0000000000000023: 74 16              je          000000000000003B
  0000000000000025: 48 8D 15 00 00 00  lea         rdx,[??_C@_02LMMGGCAJ@?3?5?$AA@]
  000000000000002C: 41 B8 02 00 00 00  mov         r8d,2
  0000000000000032: 48 8B 4D F0        mov         rcx,qword ptr [rbp-10h]
  0000000000000000: 41 56              push        r14
  0000000000000002: 56                 push        rsi
  0000000000000003: 57                 push        rdi
  0000000000000004: 53                 push        rbx
  0000000000000005: 48 83 EC 28        sub         rsp,28h
  0000000000000009: 4D 89 C6           mov         r14,r8
  000000000000000C: 48 89 D3           mov         rbx,rdx
  000000000000000F: 48 89 CE           mov         rsi,rcx
  0000000000000012: 48 8B 46 18        mov         rax,qword ptr [rsi+18h]
  0000000000000016: 48 83 F8 10        cmp         rax,10h
  000000000000001A: 72 05              jb          0000000000000021
  000000000000001C: 48 8B 0E           mov         rcx,qword ptr [rsi]
  000000000000001F: EB 03              jmp         0000000000000024
  0000000000000021: 48 89 F1           mov         rcx,rsi
  0000000000000024: 48 8B 7E 10        mov         rdi,qword ptr [rsi+10h]
  0000000000000028: 48 39 D9           cmp         rcx,rbx
  000000000000002B: 77 13              ja          0000000000000040
  000000000000002D: 48 01 F9           add         rcx,rdi
  0000000000000030: 48 39 D9           cmp         rcx,rbx
  0000000000000033: 76 0B              jbe         0000000000000040
  0000000000000035: 48 83 F8 10        cmp         rax,10h
  0000000000000039: 72 41              jb          000000000000007C
  000000000000003B: 48 8B 06           mov         rax,qword ptr [rsi]
  000000000000003E: EB 3F              jmp         000000000000007F
  0000000000000040: 48 89 F9           mov         rcx,rdi
  0000000000000043: 48 F7 D1           not         rcx
  0000000000000046: 4C 39 F1           cmp         rcx,r14
  0000000000000049: 0F 86 9E 00 00 00  jbe         00000000000000ED
  000000000000004F: 4D 85 F6           test        r14,r14
  0000000000000052: 0F 84 88 00 00 00  je          00000000000000E0
  0000000000000058: 4C 01 F7           add         rdi,r14
  000000000000005B: 74 3F              je          000000000000009C
  000000000000005D: 48 39 F8           cmp         rax,rdi
  0000000000000060: 73 0F              jae         0000000000000071
  0000000000000062: 48 89 F1           mov         rcx,rsi
  0000000000000065: 48 89 FA           mov         rdx,rdi
  0000000000000068: E8 00 00 00 00     call        ?_Copy@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAX_K@Z
  000000000000006D: 48 8B 46 18        mov         rax,qword ptr [rsi+18h]
  0000000000000071: 48 83 F8 10        cmp         rax,10h
  0000000000000075: 72 30              jb          00000000000000A7
  0000000000000077: 48 8B 0E           mov         rcx,qword ptr [rsi]
  000000000000007A: EB 2E              jmp         00000000000000AA
  000000000000007C: 48 89 F0           mov         rax,rsi
  000000000000007F: 48 29 C3           sub         rbx,rax
  0000000000000082: 48 89 F1           mov         rcx,rsi
  0000000000000085: 48 89 F2           mov         rdx,rsi
  0000000000000088: 49 89 D8           mov         r8,rbx
  000000000000008B: 4D 89 F1           mov         r9,r14
  000000000000008E: 48 83 C4 28        add         rsp,28h
  0000000000000092: 5B                 pop         rbx
  0000000000000093: 5F                 pop         rdi
  0000000000000094: 5E                 pop         rsi
  0000000000000095: 41 5E              pop         r14
  0000000000000097: E9 00 00 00 00     jmp         ?append@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAAEAV12@AEBV12@_K_K@Z
  000000000000009C: 48 83 F8 10        cmp         rax,10h
  00000000000000A0: 72 30              jb          00000000000000D2
  00000000000000A2: 48 8B 06           mov         rax,qword ptr [rsi]
  00000000000000A5: EB 2E              jmp         00000000000000D5
  00000000000000A7: 48 89 F1           mov         rcx,rsi
  00000000000000AA: 48 03 4E 10        add         rcx,qword ptr [rsi+10h]
  00000000000000AE: 48 89 DA           mov         rdx,rbx
  00000000000000B1: 4D 89 F0           mov         r8,r14
  00000000000000B4: E8 00 00 00 00     call        memcpy
  00000000000000B9: 48 83 7E 18 10     cmp         qword ptr [rsi+18h],10h
  00000000000000BE: 72 05              jb          00000000000000C5
  00000000000000C0: 48 8B 06           mov         rax,qword ptr [rsi]
  00000000000000C3: EB 03              jmp         00000000000000C8
  00000000000000C5: 48 89 F0           mov         rax,rsi
  00000000000000C8: 48 89 7E 10        mov         qword ptr [rsi+10h],rdi
  00000000000000CC: C6 04 38 00        mov         byte ptr [rax+rdi],0
  00000000000000D0: EB 0E              jmp         00000000000000E0
  00000000000000D2: 48 89 F0           mov         rax,rsi
  00000000000000D5: 48 C7 46 10 00 00  mov         qword ptr [rsi+10h],0
  00000000000000DD: C6 00 00           mov         byte ptr [rax],0
  00000000000000E0: 48 89 F0           mov         rax,rsi
  00000000000000E3: 48 83 C4 28        add         rsp,28h
  00000000000000E7: 5B                 pop         rbx
  00000000000000E8: 5F                 pop         rdi
  00000000000000E9: 5E                 pop         rsi
  00000000000000EA: 41 5E              pop         r14
  00000000000000EC: C3                 ret
  00000000000000ED: E8 00 00 00 00     call        ?_Xlen@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@SAXXZ
  00000000000000F2: 0F 0B              ud2
  000000000000003B: 48 8B 4F 08        mov         rcx,qword ptr [rdi+8]
  000000000000003F: 48 8B 01           mov         rax,qword ptr [rcx]
  0000000000000042: 44 8B 07           mov         r8d,dword ptr [rdi]
  0000000000000045: 48 8D 55 D0        lea         rdx,[rbp-30h]
  0000000000000049: FF 50 10           call        qword ptr [rax+10h]
  000000000000004C: 48 8D 55 D0        lea         rdx,[rbp-30h]
  0000000000000050: 45 31 C0           xor         r8d,r8d
  0000000000000053: 49 C7 C1 FF FF FF  mov         r9,0FFFFFFFFFFFFFFFFh
  000000000000005A: 48 8B 4D F0        mov         rcx,qword ptr [rbp-10h]
  0000000000000000: 41 57              push        r15
  0000000000000002: 41 56              push        r14
  0000000000000004: 56                 push        rsi
  0000000000000005: 57                 push        rdi
  0000000000000006: 53                 push        rbx
  0000000000000007: 48 83 EC 20        sub         rsp,20h
  000000000000000B: 4C 89 CB           mov         rbx,r9
  000000000000000E: 4D 89 C7           mov         r15,r8
  0000000000000011: 48 89 D7           mov         rdi,rdx
  0000000000000014: 48 89 CE           mov         rsi,rcx
  0000000000000017: 48 8B 47 10        mov         rax,qword ptr [rdi+10h]
  000000000000001B: 4C 29 F8           sub         rax,r15
  000000000000001E: 0F 82 AD 00 00 00  jb          00000000000000D1
  0000000000000024: 48 39 D8           cmp         rax,rbx
  0000000000000027: 48 0F 42 D8        cmovb       rbx,rax
  000000000000002B: 4C 8B 76 10        mov         r14,qword ptr [rsi+10h]
  000000000000002F: 4C 89 F0           mov         rax,r14
  0000000000000032: 48 F7 D0           not         rax
  0000000000000035: 48 39 C3           cmp         rbx,rax
  0000000000000038: 0F 83 9A 00 00 00  jae         00000000000000D8
  000000000000003E: 48 85 DB           test        rbx,rbx
  0000000000000041: 74 7F              je          00000000000000C2
  0000000000000043: 49 01 DE           add         r14,rbx
  0000000000000046: 48 8B 46 18        mov         rax,qword ptr [rsi+18h]
  000000000000004A: 74 2B              je          0000000000000077
  000000000000004C: 4C 39 F0           cmp         rax,r14
  000000000000004F: 73 0F              jae         0000000000000060
  0000000000000051: 48 89 F1           mov         rcx,rsi
  0000000000000054: 4C 89 F2           mov         rdx,r14
  0000000000000057: E8 00 00 00 00     call        ?_Copy@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAX_K@Z
  000000000000005C: 48 8B 46 18        mov         rax,qword ptr [rsi+18h]
  0000000000000060: 48 83 7F 18 0F     cmp         qword ptr [rdi+18h],0Fh
  0000000000000065: 48 0F 47 3F        cmova       rdi,qword ptr [rdi]
  0000000000000069: 4C 01 FF           add         rdi,r15
  000000000000006C: 48 83 F8 10        cmp         rax,10h
  0000000000000070: 72 18              jb          000000000000008A
  0000000000000072: 48 8B 0E           mov         rcx,qword ptr [rsi]
  0000000000000075: EB 16              jmp         000000000000008D
  0000000000000077: 48 83 F8 10        cmp         rax,10h
  000000000000007B: 72 37              jb          00000000000000B4
  000000000000007D: 48 8B 06           mov         rax,qword ptr [rsi]
  0000000000000080: 48 C7 46 10 00 00  mov         qword ptr [rsi+10h],0
  0000000000000088: EB 35              jmp         00000000000000BF
  000000000000008A: 48 89 F1           mov         rcx,rsi
  000000000000008D: 48 03 4E 10        add         rcx,qword ptr [rsi+10h]
  0000000000000091: 48 89 FA           mov         rdx,rdi
  0000000000000094: 49 89 D8           mov         r8,rbx
  0000000000000097: E8 00 00 00 00     call        memcpy
  000000000000009C: 48 83 7E 18 10     cmp         qword ptr [rsi+18h],10h
  00000000000000A1: 72 05              jb          00000000000000A8
  00000000000000A3: 48 8B 06           mov         rax,qword ptr [rsi]
  00000000000000A6: EB 03              jmp         00000000000000AB
  00000000000000A8: 48 89 F0           mov         rax,rsi
  00000000000000AB: 4C 89 76 10        mov         qword ptr [rsi+10h],r14
  00000000000000AF: 4C 01 F0           add         rax,r14
  00000000000000B2: EB 0B              jmp         00000000000000BF
  00000000000000B4: 48 C7 46 10 00 00  mov         qword ptr [rsi+10h],0
  00000000000000BC: 48 89 F0           mov         rax,rsi
  00000000000000BF: C6 00 00           mov         byte ptr [rax],0
  00000000000000C2: 48 89 F0           mov         rax,rsi
  00000000000000C5: 48 83 C4 20        add         rsp,20h
  00000000000000C9: 5B                 pop         rbx
  00000000000000CA: 5F                 pop         rdi
  00000000000000CB: 5E                 pop         rsi
  00000000000000CC: 41 5E              pop         r14
  00000000000000CE: 41 5F              pop         r15
  00000000000000D0: C3                 ret
  00000000000000D1: E8 00 00 00 00     call        ?_Xran@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@SAXXZ
  00000000000000D6: 0F 0B              ud2
  00000000000000D8: E8 00 00 00 00     call        ?_Xlen@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@SAXXZ
  00000000000000DD: 0F 0B              ud2
  0000000000000063: 48 8B 45 E8        mov         rax,qword ptr [rbp-18h]
  0000000000000067: 48 83 F8 10        cmp         rax,10h
  000000000000006B: 72 31              jb          000000000000009E
  000000000000006D: 48 8B 4D D0        mov         rcx,qword ptr [rbp-30h]
  0000000000000071: 48 FF C0           inc         rax
  0000000000000074: 48 3D 00 10 00 00  cmp         rax,1000h
  000000000000007A: 72 1D              jb          0000000000000099
  000000000000007C: F6 C1 1F           test        cl,1Fh
  000000000000007F: 75 56              jne         00000000000000D7
  0000000000000081: 48 8B 41 F8        mov         rax,qword ptr [rcx-8]
  0000000000000085: 48 29 C1           sub         rcx,rax
  0000000000000088: 76 54              jbe         00000000000000DE
  000000000000008A: 48 83 F9 07        cmp         rcx,7
  000000000000008E: 76 55              jbe         00000000000000E5
  0000000000000090: 48 83 F9 28        cmp         rcx,28h
  0000000000000094: 73 56              jae         00000000000000EC
  0000000000000096: 48 89 C1           mov         rcx,rax
  0000000000000099: E8 00 00 00 00     call        ??3@YAXPEAX@Z
  000000000000009E: 48 8B 4D F0        mov         rcx,qword ptr [rbp-10h]
  00000000000000A2: 0F 10 01           movups      xmm0,xmmword ptr [rcx]
  00000000000000A5: 0F 10 49 10        movups      xmm1,xmmword ptr [rcx+10h]
  00000000000000A9: 0F 11 4E 10        movups      xmmword ptr [rsi+10h],xmm1
  00000000000000AD: 0F 11 06           movups      xmmword ptr [rsi],xmm0
  00000000000000B0: B8 0F 00 00 00     mov         eax,0Fh
  00000000000000B5: 66 48 0F 6E C0     movq        xmm0,rax
  00000000000000BA: 66 0F 73 F8 08     pslldq      xmm0,8
  00000000000000BF: F3 0F 7F 41 10     movdqu      xmmword ptr [rcx+10h],xmm0
  00000000000000C4: C6 01 00           mov         byte ptr [rcx],0
  0000000000000000: 55                 push        rbp
  0000000000000001: 56                 push        rsi
  0000000000000002: 48 83 EC 28        sub         rsp,28h
  0000000000000006: 48 8D 6C 24 20     lea         rbp,[rsp+20h]
  000000000000000B: 48 C7 45 00 FE FF  mov         qword ptr [rbp],0FFFFFFFFFFFFFFFEh
  0000000000000013: 48 89 CE           mov         rsi,rcx
  0000000000000016: 48 8B 46 18        mov         rax,qword ptr [rsi+18h]
  000000000000001A: 48 83 F8 10        cmp         rax,10h
  000000000000001E: 72 30              jb          0000000000000050
  0000000000000020: 48 8B 0E           mov         rcx,qword ptr [rsi]
  0000000000000023: 48 FF C0           inc         rax
  0000000000000026: 48 3D 00 10 00 00  cmp         rax,1000h
  000000000000002C: 72 1D              jb          000000000000004B
  000000000000002E: F6 C1 1F           test        cl,1Fh
  0000000000000031: 75 3B              jne         000000000000006E
  0000000000000033: 48 8B 41 F8        mov         rax,qword ptr [rcx-8]
  0000000000000037: 48 29 C1           sub         rcx,rax
  000000000000003A: 76 39              jbe         0000000000000075
  000000000000003C: 48 83 F9 07        cmp         rcx,7
  0000000000000040: 76 3A              jbe         000000000000007C
  0000000000000042: 48 83 F9 28        cmp         rcx,28h
  0000000000000046: 73 3B              jae         0000000000000083
  0000000000000048: 48 89 C1           mov         rcx,rax
  000000000000004B: E8 00 00 00 00     call        ??3@YAXPEAX@Z
  0000000000000050: B8 0F 00 00 00     mov         eax,0Fh
  0000000000000055: 66 48 0F 6E C0     movq        xmm0,rax
  000000000000005A: 66 0F 73 F8 08     pslldq      xmm0,8
  000000000000005F: F3 0F 7F 46 10     movdqu      xmmword ptr [rsi+10h],xmm0
  0000000000000064: C6 06 00           mov         byte ptr [rsi],0
  0000000000000067: 48 83 C4 28        add         rsp,28h
  000000000000006B: 5E                 pop         rsi
  000000000000006C: 5D                 pop         rbp
  000000000000006D: C3                 ret
  000000000000006E: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000073: 0F 0B              ud2
  0000000000000075: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  000000000000007A: 0F 0B              ud2
  000000000000007C: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000081: 0F 0B              ud2
  0000000000000083: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000088: 0F 0B              ud2
  000000000000008A: 66 0F 1F 44 00 00  nop         word ptr [rax+rax]
  00000000000000CC: 48 89 F0           mov         rax,rsi
  00000000000000CF: 48 83 C4 50        add         rsp,50h
  00000000000000D3: 5F                 pop         rdi
  00000000000000D4: 5E                 pop         rsi
  00000000000000D5: 5D                 pop         rbp
  00000000000000D6: C3                 ret
  00000000000000D7: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  00000000000000DC: 0F 0B              ud2
  00000000000000DE: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  00000000000000E3: 0F 0B              ud2
  00000000000000E5: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  00000000000000EA: 0F 0B              ud2
  00000000000000EC: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  00000000000000F1: 0F 0B              ud2
  00000000000000F3: 66 66 66 66 2E 0F  nop         word ptr cs:[rax+rax]
  0000000000000072: 48 83 7D F0 0F     cmp         qword ptr [rbp-10h],0Fh
  0000000000000077: 48 0F 47 7D D8     cmova       rdi,qword ptr [rbp-28h]
  000000000000007C: 48 8D 05 00 00 00  lea         rax,[??_7exception@std@@6B@]
  0000000000000083: 48 89 06           mov         qword ptr [rsi],rax
  0000000000000086: 48 8D 56 08        lea         rdx,[rsi+8]
  000000000000008A: 0F 57 C0           xorps       xmm0,xmm0
  000000000000008D: 0F 11 46 08        movups      xmmword ptr [rsi+8],xmm0
  0000000000000091: 48 89 7D F8        mov         qword ptr [rbp-8],rdi
  0000000000000095: C6 45 00 01        mov         byte ptr [rbp],1
  0000000000000099: 48 8D 4D F8        lea         rcx,[rbp-8]
  000000000000009D: E8 00 00 00 00     call        __std_exception_copy
  00000000000000A2: 48 8D 05 00 00 00  lea         rax,[??_7runtime_error@std@@6B@]
  00000000000000A9: 48 89 06           mov         qword ptr [rsi],rax
  00000000000000AC: 48 8B 45 F0        mov         rax,qword ptr [rbp-10h]
  00000000000000B0: 48 83 F8 10        cmp         rax,10h
  00000000000000B4: 72 31              jb          00000000000000E7
  00000000000000B6: 48 8B 4D D8        mov         rcx,qword ptr [rbp-28h]
  00000000000000BA: 48 FF C0           inc         rax
  00000000000000BD: 48 3D 00 10 00 00  cmp         rax,1000h
  00000000000000C3: 72 1D              jb          00000000000000E2
  00000000000000C5: F6 C1 1F           test        cl,1Fh
  00000000000000C8: 75 40              jne         000000000000010A
  00000000000000CA: 48 8B 41 F8        mov         rax,qword ptr [rcx-8]
  00000000000000CE: 48 29 C1           sub         rcx,rax
  00000000000000D1: 76 3E              jbe         0000000000000111
  00000000000000D3: 48 83 F9 07        cmp         rcx,7
  00000000000000D7: 76 3F              jbe         0000000000000118
  00000000000000D9: 48 83 F9 28        cmp         rcx,28h
  00000000000000DD: 73 40              jae         000000000000011F
  00000000000000DF: 48 89 C1           mov         rcx,rax
  00000000000000E2: E8 00 00 00 00     call        ??3@YAXPEAX@Z
  00000000000000E7: 48 8D 05 00 00 00  lea         rax,[??_7_System_error@std@@6B@]
  00000000000000EE: 48 89 06           mov         qword ptr [rsi],rax
  00000000000000F1: 41 0F 10 06        movups      xmm0,xmmword ptr [r14]
  00000000000000F5: 0F 11 46 18        movups      xmmword ptr [rsi+18h],xmm0
  00000000000000F9: 48 89 F0           mov         rax,rsi
  00000000000000FC: 48 81 C4 90 00 00  add         rsp,90h
  0000000000000103: 5B                 pop         rbx
  0000000000000104: 5F                 pop         rdi
  0000000000000105: 5E                 pop         rsi
  0000000000000106: 41 5E              pop         r14
  0000000000000108: 5D                 pop         rbp
  0000000000000109: C3                 ret
  000000000000010A: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  000000000000010F: 0F 0B              ud2
  0000000000000111: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000116: 0F 0B              ud2
  0000000000000118: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  000000000000011D: 0F 0B              ud2
  000000000000011F: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000124: 0F 0B              ud2
  0000000000000126: 66 2E 0F 1F 84 00  nop         word ptr cs:[rax+rax]
  0000000000000063: 48 8B 45 F0        mov         rax,qword ptr [rbp-10h]
  0000000000000067: 48 83 F8 10        cmp         rax,10h
  000000000000006B: 72 31              jb          000000000000009E
  000000000000006D: 48 8B 4D D8        mov         rcx,qword ptr [rbp-28h]
  0000000000000071: 48 FF C0           inc         rax
  0000000000000074: 48 3D 00 10 00 00  cmp         rax,1000h
  000000000000007A: 72 1D              jb          0000000000000099
  000000000000007C: F6 C1 1F           test        cl,1Fh
  000000000000007F: 75 32              jne         00000000000000B3
  0000000000000081: 48 8B 41 F8        mov         rax,qword ptr [rcx-8]
  0000000000000085: 48 29 C1           sub         rcx,rax
  0000000000000088: 76 30              jbe         00000000000000BA
  000000000000008A: 48 83 F9 07        cmp         rcx,7
  000000000000008E: 76 31              jbe         00000000000000C1
  0000000000000090: 48 83 F9 28        cmp         rcx,28h
  0000000000000094: 73 32              jae         00000000000000C8
  0000000000000096: 48 89 C1           mov         rcx,rax
  0000000000000099: E8 00 00 00 00     call        ??3@YAXPEAX@Z
  000000000000009E: 48 8D 05 00 00 00  lea         rax,[??_7monad_error@_1_0_std_std_9274c0d4@outcome@boost@@6B@]
  00000000000000A5: 48 89 06           mov         qword ptr [rsi],rax
  00000000000000A8: 48 89 F0           mov         rax,rsi
  00000000000000AB: 48 83 C4 70        add         rsp,70h
  00000000000000AF: 5F                 pop         rdi
  00000000000000B0: 5E                 pop         rsi
  00000000000000B1: 5D                 pop         rbp
  00000000000000B2: C3                 ret
  00000000000000B3: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  00000000000000B8: 0F 0B              ud2
  00000000000000BA: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  00000000000000BF: 0F 0B              ud2
  00000000000000C1: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  00000000000000C6: 0F 0B              ud2
  00000000000000C8: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  00000000000000CD: 0F 0B              ud2
  00000000000000CF: 90                 nop
  000000000000020C: 48 8D 15 00 00 00  lea         rdx,[_TI5?AVmonad_error@_1_0_std_std_9274c0d4@outcome@boost@@]
  0000000000000213: 48 8D 4D A8        lea         rcx,[rbp-58h]
  0000000000000217: FF 15 00 00 00 00  call        qword ptr [__imp__CxxThrowException]
  000000000000021D: 0F 0B              ud2
  000000000000021F: 90                 nop
