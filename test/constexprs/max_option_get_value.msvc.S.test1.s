  0000000000000000: 40 55              push        rbp
  0000000000000002: 48 8D 6C 24 A9     lea         rbp,[rsp-57h]
  0000000000000007: 48 81 EC 90 00 00  sub         rsp,90h
                    00
  000000000000000E: 48 8D 4D 67        lea         rcx,[rbp+67h]
  0000000000000012: E8 00 00 00 00     call        ?unknown@@YA?AV?$basic_monad@U?$option_policy@H@detail@v1_std_std@outcome@boost@@@v1_std_std@outcome@boost@@XZ
  0000000000000017: 80 78 04 00        cmp         byte ptr [rax+4],0
  000000000000001B: 0F 85 9D 00 00 00  jne         00000000000000BE
  0000000000000021: C7 45 E7 02 00 00  mov         dword ptr [rbp-19h],2
                    00
  0000000000000028: E8 00 00 00 00     call        replaced
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

  000000000000002D: 48 89 45 EF        mov         qword ptr [rbp-11h],rax
  0000000000000031: 48 8D 55 07        lea         rdx,[rbp+7]
  0000000000000035: 0F 28 45 E7        movaps      xmm0,xmmword ptr [rbp-19h]
  0000000000000039: 48 8D 4D F7        lea         rcx,[rbp-9]
  000000000000003D: 66 0F 7F 45 F7     movdqa      xmmword ptr [rbp-9],xmm0
  0000000000000042: E8 00 00 00 00     call        replaced
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

  0000000000000047: 48 83 78 18 10     cmp         qword ptr [rax+18h],10h
  000000000000004C: 72 03              jb          0000000000000051
  000000000000004E: 48 8B 00           mov         rax,qword ptr [rax]
  0000000000000051: 48 8D 0D 00 00 00  lea         rcx,[??_7exception@std@@6B@]
                    00
  0000000000000058: 48 89 45 E7        mov         qword ptr [rbp-19h],rax
  000000000000005C: 48 89 4D 27        mov         qword ptr [rbp+27h],rcx
  0000000000000060: 48 8D 55 2F        lea         rdx,[rbp+2Fh]
  0000000000000064: 33 C9              xor         ecx,ecx
  0000000000000066: C6 45 EF 01        mov         byte ptr [rbp-11h],1
  000000000000006A: 48 89 4D 2F        mov         qword ptr [rbp+2Fh],rcx
  000000000000006E: 48 89 4D 37        mov         qword ptr [rbp+37h],rcx
  0000000000000072: 48 8D 4D E7        lea         rcx,[rbp-19h]
  0000000000000076: E8 00 00 00 00     call        __std_exception_copy
  000000000000007B: 48 8D 05 00 00 00  lea         rax,[??_7logic_error@std@@6B@]
                    00
  0000000000000082: 48 89 45 27        mov         qword ptr [rbp+27h],rax
  0000000000000086: 48 8B 45 1F        mov         rax,qword ptr [rbp+1Fh]
  000000000000008A: 48 83 F8 10        cmp         rax,10h
  000000000000008E: 72 59              jb          00000000000000E9
  0000000000000090: 48 8B 4D 07        mov         rcx,qword ptr [rbp+7]
  0000000000000094: 48 FF C0           inc         rax
  0000000000000097: 48 3D 00 10 00 00  cmp         rax,1000h
  000000000000009D: 72 45              jb          00000000000000E4
  000000000000009F: F6 C1 1F           test        cl,1Fh
  00000000000000A2: 75 25              jne         00000000000000C9
  00000000000000A4: 48 8B 41 F8        mov         rax,qword ptr [rcx-8]
  00000000000000A8: 48 3B C1           cmp         rax,rcx
  00000000000000AB: 73 22              jae         00000000000000CF
  00000000000000AD: 48 2B C8           sub         rcx,rax
  00000000000000B0: 48 83 F9 08        cmp         rcx,8
  00000000000000B4: 72 1F              jb          00000000000000D5
  00000000000000B6: 48 83 F9 27        cmp         rcx,27h
  00000000000000BA: 77 1F              ja          00000000000000DB
  00000000000000BC: EB 23              jmp         00000000000000E1
  00000000000000BE: 8B 00              mov         eax,dword ptr [rax]
  00000000000000C0: 48 81 C4 90 00 00  add         rsp,90h
                    00
  00000000000000C7: 5D                 pop         rbp
  00000000000000C8: C3                 ret
  00000000000000C9: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  00000000000000CE: CC                 int         3
  00000000000000CF: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  00000000000000D4: CC                 int         3
  00000000000000D5: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  00000000000000DA: CC                 int         3
  00000000000000DB: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  00000000000000E0: CC                 int         3
  00000000000000E1: 48 8B C8           mov         rcx,rax
  00000000000000E4: E8 00 00 00 00     call        ??3@YAXPEAX@Z
  00000000000000E9: 0F 28 45 F7        movaps      xmm0,xmmword ptr [rbp-9]
  00000000000000ED: 48 8D 05 00 00 00  lea         rax,[??_7monad_error@v1_std_std@outcome@boost@@6B@]
                    00
  00000000000000F4: 48 8D 15 00 00 00  lea         rdx,[_TI3?AVmonad_error@v1_std_std@outcome@boost@@]
                    00
  00000000000000FB: 48 89 45 27        mov         qword ptr [rbp+27h],rax
  00000000000000FF: 48 8D 4D 27        lea         rcx,[rbp+27h]
  0000000000000103: 48 C7 45 1F 0F 00  mov         qword ptr [rbp+1Fh],0Fh
                    00 00
  000000000000010B: 0F 11 45 3F        movups      xmmword ptr [rbp+3Fh],xmm0
  000000000000010F: 48 C7 45 17 00 00  mov         qword ptr [rbp+17h],0
                    00 00
  0000000000000117: C6 45 07 00        mov         byte ptr [rbp+7],0
  000000000000011B: E8 00 00 00 00     call        _CxxThrowException
  0000000000000120: CC                 int         3
