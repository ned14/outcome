  0000000000000000: 55                 push        rbp
  0000000000000001: 48 83 EC 70        sub         rsp,70h
  0000000000000005: 48 8D 6C 24 70     lea         rbp,[rsp+70h]
  000000000000000A: 48 C7 45 F8 FE FF  mov         qword ptr [rbp-8],0FFFFFFFFFFFFFFFEh
                    FF FF
  0000000000000012: 48 8D 4D F0        lea         rcx,[rbp-10h]
  0000000000000016: E8 00 00 00 00     call        ?unknown@@YA?AV?$basic_monad@U?$option_policy@H@detail@v1_std_std@outcome@boost@@@v1_std_std@outcome@boost@@XZ
  000000000000001B: 0F B6 4D F4        movzx       ecx,byte ptr [rbp-0Ch]
  000000000000001F: 85 C9              test        ecx,ecx
  0000000000000021: 74 1C              je          000000000000003F
  0000000000000023: 8B 45 F0           mov         eax,dword ptr [rbp-10h]
  0000000000000026: 83 F9 03           cmp         ecx,3
  0000000000000029: 74 0A              je          0000000000000035
  000000000000002B: 83 F9 02           cmp         ecx,2
  000000000000002E: 74 05              je          0000000000000035
  0000000000000030: 83 F9 01           cmp         ecx,1
  0000000000000033: 75 04              jne         0000000000000039
  0000000000000035: C6 45 F4 00        mov         byte ptr [rbp-0Ch],0
  0000000000000039: 48 83 C4 70        add         rsp,70h
  000000000000003D: 5D                 pop         rbp
  000000000000003E: C3                 ret
  000000000000003F: C7 45 E0 00 00 00  mov         dword ptr [rbp-20h],0
                    00
  0000000000000046: 48 C7 45 E8 00 00  mov         qword ptr [rbp-18h],0
                    00 00
  000000000000004E: 8B 05 00 00 00 00  mov         eax,dword ptr [?$TSS0@?1??monad_category@v1_std_std@outcome@boost@@YAAEBV0_detail@123@XZ@4HA]
  0000000000000054: 8B 0D 00 00 00 00  mov         ecx,dword ptr [_tls_index]
  000000000000005A: 65 48 8B 14 25 58  mov         rdx,qword ptr gs:[58h]
                    00 00 00
  0000000000000063: 48 8B 0C CA        mov         rcx,qword ptr [rdx+rcx*8]
  0000000000000067: 3B 81 00 00 00 00  cmp         eax,dword ptr _Init_thread_epoch[rcx]
  000000000000006D: 7E 4B              jle         00000000000000BA
  000000000000006F: 48 8D 0D 00 00 00  lea         rcx,[?$TSS0@?1??monad_category@v1_std_std@outcome@boost@@YAAEBV0_detail@123@XZ@4HA]
                    00
  0000000000000076: E8 00 00 00 00     call        _Init_thread_header
  000000000000007B: 8B 05 00 00 00 00  mov         eax,dword ptr [?$TSS0@?1??monad_category@v1_std_std@outcome@boost@@YAAEBV0_detail@123@XZ@4HA]
  0000000000000081: 83 F8 FF           cmp         eax,0FFFFFFFFh
  0000000000000084: 75 34              jne         00000000000000BA
  0000000000000086: 48 8D 05 00 00 00  lea         rax,[?c@?1??monad_category@v1_std_std@outcome@boost@@YAAEBV1_detail@234@XZ@4V15234@A]
                    00
  000000000000008D: 48 89 05 08 00 00  mov         qword ptr [?c@?1??monad_category@v1_std_std@outcome@boost@@YAAEBV1_detail@234@XZ@4V15234@A+8],rax
                    00
  0000000000000094: 48 8D 05 00 00 00  lea         rax,[??_7monad_category@_detail@v1_std_std@outcome@boost@@6B@]
                    00
  000000000000009B: 48 89 05 00 00 00  mov         qword ptr [?c@?1??monad_category@v1_std_std@outcome@boost@@YAAEBV1_detail@234@XZ@4V15234@A],rax
                    00
  00000000000000A2: 48 8D 0D 00 00 00  lea         rcx,[??__Fc@?1??monad_category@v1_std_std@outcome@boost@@YAAEBV1_detail@234@XZ@YAXXZ]
                    00
  00000000000000A9: E8 00 00 00 00     call        atexit
  00000000000000AE: 48 8D 0D 00 00 00  lea         rcx,[?$TSS0@?1??monad_category@v1_std_std@outcome@boost@@YAAEBV0_detail@123@XZ@4HA]
                    00
  00000000000000B5: E8 00 00 00 00     call        _Init_thread_footer
  00000000000000BA: C7 45 E0 02 00 00  mov         dword ptr [rbp-20h],2
                    00
  00000000000000C1: 48 8D 05 00 00 00  lea         rax,[?c@?1??monad_category@v1_std_std@outcome@boost@@YAAEBV1_detail@234@XZ@4V15234@A]
                    00
  00000000000000C8: 48 89 45 E8        mov         qword ptr [rbp-18h],rax
  00000000000000CC: 48 8D 4D B8        lea         rcx,[rbp-48h]
  00000000000000D0: 48 8D 55 E0        lea         rdx,[rbp-20h]
  00000000000000D4: E8 00 00 00 00     call        replaced
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

  00000000000000D9: 48 8D 15 00 00 00  lea         rdx,[_TI3?AVmonad_error@v1_std_std@outcome@boost@@]
                    00
  00000000000000E0: 48 8D 4D B8        lea         rcx,[rbp-48h]
  00000000000000E4: E8 00 00 00 00     call        _CxxThrowException
  00000000000000E9: 0F 0B              ud2
  00000000000000EB: 0F 1F 44 00 00     nop         dword ptr [rax+rax]
