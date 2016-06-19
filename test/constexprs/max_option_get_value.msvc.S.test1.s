  0000000000000000: 40 55              push        rbp
  0000000000000002: 48 8D 6C 24 A9     lea         rbp,[rsp-57h]
  0000000000000007: 48 81 EC B0 00 00  sub         rsp,0B0h
                    00
  000000000000000E: 48 C7 45 37 FE FF  mov         qword ptr [rbp+37h],0FFFFFFFFFFFFFFFEh
                    FF FF
  0000000000000016: 48 8D 4D 3F        lea         rcx,[rbp+3Fh]
  000000000000001A: E8 00 00 00 00     call        ?unknown@@YA?AV?$basic_monad@U?$option_policy@H@detail@v1_std_std@outcome@boost@@@v1_std_std@outcome@boost@@XZ
  000000000000001F: 90                 nop
  0000000000000020: 80 78 04 00        cmp         byte ptr [rax+4],0
  0000000000000024: 0F 85 F3 00 00 00  jne         000000000000011D
  000000000000002A: C7 45 C7 02 00 00  mov         dword ptr [rbp-39h],2
                    00
  0000000000000031: E8 00 00 00 00     call        replaced
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

  0000000000000036: 48 89 45 CF        mov         qword ptr [rbp-31h],rax
  000000000000003A: 0F 28 45 C7        movaps      xmm0,xmmword ptr [rbp-39h]
  000000000000003E: 66 0F 7F 45 27     movdqa      xmmword ptr [rbp+27h],xmm0
  0000000000000043: 48 8D 55 D7        lea         rdx,[rbp-29h]
  0000000000000047: 48 8D 4D 27        lea         rcx,[rbp+27h]
  000000000000004B: E8 00 00 00 00     call        replaced
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

  0000000000000050: 48 83 78 18 10     cmp         qword ptr [rax+18h],10h
  0000000000000055: 72 03              jb          000000000000005A
  0000000000000057: 48 8B 00           mov         rax,qword ptr [rax]
  000000000000005A: 48 8D 0D 00 00 00  lea         rcx,[??_7exception@std@@6B@]
                    00
  0000000000000061: 48 89 4D F7        mov         qword ptr [rbp-9],rcx
  0000000000000065: 33 C9              xor         ecx,ecx
  0000000000000067: 48 89 4D FF        mov         qword ptr [rbp-1],rcx
  000000000000006B: 48 89 4D 07        mov         qword ptr [rbp+7],rcx
  000000000000006F: 48 89 45 C7        mov         qword ptr [rbp-39h],rax
  0000000000000073: C6 45 CF 01        mov         byte ptr [rbp-31h],1
  0000000000000077: 48 8D 55 FF        lea         rdx,[rbp-1]
  000000000000007B: 48 8D 4D C7        lea         rcx,[rbp-39h]
  000000000000007F: E8 00 00 00 00     call        __std_exception_copy
  0000000000000084: 48 8D 05 00 00 00  lea         rax,[??_7logic_error@std@@6B@]
                    00
  000000000000008B: 48 89 45 F7        mov         qword ptr [rbp-9],rax
  000000000000008F: 48 8B 45 EF        mov         rax,qword ptr [rbp-11h]
  0000000000000093: 48 83 F8 10        cmp         rax,10h
  0000000000000097: 72 4C              jb          00000000000000E5
  0000000000000099: 48 FF C0           inc         rax
  000000000000009C: 48 8B 4D D7        mov         rcx,qword ptr [rbp-29h]
  00000000000000A0: 48 3D 00 10 00 00  cmp         rax,1000h
  00000000000000A6: 72 38              jb          00000000000000E0
  00000000000000A8: F6 C1 1F           test        cl,1Fh
  00000000000000AB: 74 06              je          00000000000000B3
  00000000000000AD: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  00000000000000B2: CC                 int         3
  00000000000000B3: 48 8B 41 F8        mov         rax,qword ptr [rcx-8]
  00000000000000B7: 48 3B C1           cmp         rax,rcx
  00000000000000BA: 72 06              jb          00000000000000C2
  00000000000000BC: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  00000000000000C1: CC                 int         3
  00000000000000C2: 48 2B C8           sub         rcx,rax
  00000000000000C5: 48 83 F9 08        cmp         rcx,8
  00000000000000C9: 73 06              jae         00000000000000D1
  00000000000000CB: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  00000000000000D0: CC                 int         3
  00000000000000D1: 48 83 F9 27        cmp         rcx,27h
  00000000000000D5: 76 06              jbe         00000000000000DD
  00000000000000D7: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  00000000000000DC: CC                 int         3
  00000000000000DD: 48 8B C8           mov         rcx,rax
  00000000000000E0: E8 00 00 00 00     call        ??3@YAXPEAX@Z
  00000000000000E5: 48 C7 45 EF 0F 00  mov         qword ptr [rbp-11h],0Fh
                    00 00
  00000000000000ED: 48 C7 45 E7 00 00  mov         qword ptr [rbp-19h],0
                    00 00
  00000000000000F5: C6 45 D7 00        mov         byte ptr [rbp-29h],0
  00000000000000F9: 48 8D 05 00 00 00  lea         rax,[??_7monad_error@v1_std_std@outcome@boost@@6B@]
                    00
  0000000000000100: 48 89 45 F7        mov         qword ptr [rbp-9],rax
  0000000000000104: 0F 28 45 27        movaps      xmm0,xmmword ptr [rbp+27h]
  0000000000000108: 0F 11 45 0F        movups      xmmword ptr [rbp+0Fh],xmm0
  000000000000010C: 48 8D 15 00 00 00  lea         rdx,[_TI3?AVmonad_error@v1_std_std@outcome@boost@@]
                    00
  0000000000000113: 48 8D 4D F7        lea         rcx,[rbp-9]
  0000000000000117: E8 00 00 00 00     call        _CxxThrowException
  000000000000011C: 90                 nop
  000000000000011D: 8B 00              mov         eax,dword ptr [rax]
  000000000000011F: 48 81 C4 B0 00 00  add         rsp,0B0h
                    00
  0000000000000126: 5D                 pop         rbp
  0000000000000127: C3                 ret
