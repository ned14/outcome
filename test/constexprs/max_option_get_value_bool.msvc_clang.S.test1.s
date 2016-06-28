  0000000000000000: 56                 push        rsi
  0000000000000001: 57                 push        rdi
  0000000000000002: 48 83 EC 68        sub         rsp,68h
  0000000000000006: 48 8D 4C 24 28     lea         rcx,[rsp+28h]
  000000000000000B: E8 00 00 00 00     call        ?unknown@@YA?AV?$basic_monad@U?$option_policy@_N@detail@v1_std_std@outcome@boost@@@v1_std_std@outcome@boost@@XZ
  0000000000000010: 8A 44 24 28        mov         al,byte ptr [rsp+28h]
  0000000000000014: 3C 3F              cmp         al,3Fh
  0000000000000016: 76 0F              jbe         0000000000000027
  0000000000000018: A8 3F              test        al,3Fh
  000000000000001A: 0F 95 C0           setne       al
  000000000000001D: 0F B6 C0           movzx       eax,al
  0000000000000020: 48 83 C4 68        add         rsp,68h
  0000000000000024: 5F                 pop         rdi
  0000000000000025: 5E                 pop         rsi
  0000000000000026: C3                 ret
  0000000000000027: 48 8D 74 24 30     lea         rsi,[rsp+30h]
  000000000000002C: BA 02 00 00 00     mov         edx,2
  0000000000000031: 48 89 F1           mov         rcx,rsi
  0000000000000034: E8 00 00 00 00     call        replaced
  0000000000000000: 56                 push        rsi
  0000000000000001: 57                 push        rdi
  0000000000000002: 48 83 EC 28        sub         rsp,28h
  0000000000000006: 89 D7              mov         edi,edx
  0000000000000008: 48 89 CE           mov         rsi,rcx
  000000000000000B: C7 06 00 00 00 00  mov         dword ptr [rsi],0
  0000000000000011: 48 C7 46 08 00 00  mov         qword ptr [rsi+8],0
                    00 00
  0000000000000019: 8B 05 00 00 00 00  mov         eax,dword ptr [?$TSS0@?1??monad_category@v1_std_std@outcome@boost@@YAAEBV0_detail@123@XZ@4HA]
  000000000000001F: 8B 0D 00 00 00 00  mov         ecx,dword ptr [_tls_index]
  0000000000000025: 65 48 8B 14 25 58  mov         rdx,qword ptr gs:[58h]
                    00 00 00
  000000000000002E: 48 8B 0C CA        mov         rcx,qword ptr [rdx+rcx*8]
  0000000000000032: 3B 81 00 00 00 00  cmp         eax,dword ptr _Init_thread_epoch[rcx]
  0000000000000038: 7E 4B              jle         0000000000000085
  000000000000003A: 48 8D 0D 00 00 00  lea         rcx,[?$TSS0@?1??monad_category@v1_std_std@outcome@boost@@YAAEBV0_detail@123@XZ@4HA]
                    00
  0000000000000041: E8 00 00 00 00     call        _Init_thread_header
  0000000000000046: 8B 05 00 00 00 00  mov         eax,dword ptr [?$TSS0@?1??monad_category@v1_std_std@outcome@boost@@YAAEBV0_detail@123@XZ@4HA]
  000000000000004C: 83 F8 FF           cmp         eax,0FFFFFFFFh
  000000000000004F: 75 34              jne         0000000000000085
  0000000000000051: 48 8D 05 00 00 00  lea         rax,[?c@?1??monad_category@v1_std_std@outcome@boost@@YAAEBV1_detail@234@XZ@4V15234@A]
                    00
  0000000000000058: 48 89 05 08 00 00  mov         qword ptr [?c@?1??monad_category@v1_std_std@outcome@boost@@YAAEBV1_detail@234@XZ@4V15234@A+8],rax
                    00
  000000000000005F: 48 8D 05 00 00 00  lea         rax,[??_7monad_category@_detail@v1_std_std@outcome@boost@@6B@]
                    00
  0000000000000066: 48 89 05 00 00 00  mov         qword ptr [?c@?1??monad_category@v1_std_std@outcome@boost@@YAAEBV1_detail@234@XZ@4V15234@A],rax
                    00
  000000000000006D: 48 8D 0D 00 00 00  lea         rcx,[??__Fc@?1??monad_category@v1_std_std@outcome@boost@@YAAEBV1_detail@234@XZ@YAXXZ]
                    00
  0000000000000074: E8 00 00 00 00     call        atexit
  0000000000000079: 48 8D 0D 00 00 00  lea         rcx,[?$TSS0@?1??monad_category@v1_std_std@outcome@boost@@YAAEBV0_detail@123@XZ@4HA]
                    00
  0000000000000080: E8 00 00 00 00     call        _Init_thread_footer
  0000000000000085: 89 3E              mov         dword ptr [rsi],edi
  0000000000000087: 48 8D 05 00 00 00  lea         rax,[?c@?1??monad_category@v1_std_std@outcome@boost@@YAAEBV1_detail@234@XZ@4V15234@A]
                    00
  000000000000008E: 48 89 46 08        mov         qword ptr [rsi+8],rax
  0000000000000092: 48 89 F0           mov         rax,rsi
  0000000000000095: 48 83 C4 28        add         rsp,28h
  0000000000000099: 5F                 pop         rdi
  000000000000009A: 5E                 pop         rsi
  000000000000009B: C3                 ret

  0000000000000039: 48 8D 7C 24 40     lea         rdi,[rsp+40h]
  000000000000003E: 48 89 F9           mov         rcx,rdi
  0000000000000041: 48 89 F2           mov         rdx,rsi
  0000000000000044: E8 00 00 00 00     call        replaced
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

  0000000000000049: 48 8D 15 00 00 00  lea         rdx,[_TI3?AVmonad_error@v1_std_std@outcome@boost@@]
                    00
  0000000000000050: 48 89 F9           mov         rcx,rdi
  0000000000000053: E8 00 00 00 00     call        _CxxThrowException
  0000000000000058: 0F 0B              ud2
  000000000000005A: 66 0F 1F 44 00 00  nop         word ptr [rax+rax]
