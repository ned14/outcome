  0000000000000000: 40 53              push        rbx
  0000000000000002: 48 83 EC 30        sub         rsp,30h
  0000000000000006: 48 8B D9           mov         rbx,rcx
  0000000000000009: 89 54 24 20        mov         dword ptr [rsp+20h],edx
  000000000000000D: 48 8D 54 24 20     lea         rdx,[rsp+20h]
  0000000000000012: C6 44 24 24 01     mov         byte ptr [rsp+24h],1
  0000000000000017: 48 8D 4C 24 40     lea         rcx,[rsp+40h]
  000000000000001C: E8 00 00 00 00     call        replaced
  0000000000000000: 40 55              push        rbp
  0000000000000002: 48 8D 6C 24 A9     lea         rbp,[rsp-57h]
  0000000000000007: 48 81 EC 90 00 00  sub         rsp,90h
                    00
  000000000000000E: 80 7A 04 00        cmp         byte ptr [rdx+4],0
  0000000000000012: 0F 85 9D 00 00 00  jne         00000000000000B5
  0000000000000018: C7 45 E7 02 00 00  mov         dword ptr [rbp-19h],2
                    00
  000000000000001F: E8 00 00 00 00     call        replaced
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

  0000000000000024: 48 89 45 EF        mov         qword ptr [rbp-11h],rax
  0000000000000028: 48 8D 55 07        lea         rdx,[rbp+7]
  000000000000002C: 0F 28 45 E7        movaps      xmm0,xmmword ptr [rbp-19h]
  0000000000000030: 48 8D 4D F7        lea         rcx,[rbp-9]
  0000000000000034: 66 0F 7F 45 F7     movdqa      xmmword ptr [rbp-9],xmm0
  0000000000000039: E8 00 00 00 00     call        replaced
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

  000000000000003E: 48 83 78 18 10     cmp         qword ptr [rax+18h],10h
  0000000000000043: 72 03              jb          0000000000000048
  0000000000000045: 48 8B 00           mov         rax,qword ptr [rax]
  0000000000000048: 48 8D 0D 00 00 00  lea         rcx,[??_7exception@std@@6B@]
                    00
  000000000000004F: 48 89 45 E7        mov         qword ptr [rbp-19h],rax
  0000000000000053: 48 89 4D 27        mov         qword ptr [rbp+27h],rcx
  0000000000000057: 48 8D 55 2F        lea         rdx,[rbp+2Fh]
  000000000000005B: 33 C9              xor         ecx,ecx
  000000000000005D: C6 45 EF 01        mov         byte ptr [rbp-11h],1
  0000000000000061: 48 89 4D 2F        mov         qword ptr [rbp+2Fh],rcx
  0000000000000065: 48 89 4D 37        mov         qword ptr [rbp+37h],rcx
  0000000000000069: 48 8D 4D E7        lea         rcx,[rbp-19h]
  000000000000006D: E8 00 00 00 00     call        __std_exception_copy
  0000000000000072: 48 8D 05 00 00 00  lea         rax,[??_7logic_error@std@@6B@]
                    00
  0000000000000079: 48 89 45 27        mov         qword ptr [rbp+27h],rax
  000000000000007D: 48 8B 45 1F        mov         rax,qword ptr [rbp+1Fh]
  0000000000000081: 48 83 F8 10        cmp         rax,10h
  0000000000000085: 72 5C              jb          00000000000000E3
  0000000000000087: 48 8B 4D 07        mov         rcx,qword ptr [rbp+7]
  000000000000008B: 48 FF C0           inc         rax
  000000000000008E: 48 3D 00 10 00 00  cmp         rax,1000h
  0000000000000094: 72 48              jb          00000000000000DE
  0000000000000096: F6 C1 1F           test        cl,1Fh
  0000000000000099: 75 28              jne         00000000000000C3
  000000000000009B: 48 8B 41 F8        mov         rax,qword ptr [rcx-8]
  000000000000009F: 48 3B C1           cmp         rax,rcx
  00000000000000A2: 73 25              jae         00000000000000C9
  00000000000000A4: 48 2B C8           sub         rcx,rax
  00000000000000A7: 48 83 F9 08        cmp         rcx,8
  00000000000000AB: 72 22              jb          00000000000000CF
  00000000000000AD: 48 83 F9 27        cmp         rcx,27h
  00000000000000B1: 77 22              ja          00000000000000D5
  00000000000000B3: EB 26              jmp         00000000000000DB
  00000000000000B5: 8B 02              mov         eax,dword ptr [rdx]
  00000000000000B7: 8D 04 40           lea         eax,[rax+rax*2]
  00000000000000BA: 48 81 C4 90 00 00  add         rsp,90h
                    00
  00000000000000C1: 5D                 pop         rbp
  00000000000000C2: C3                 ret
  00000000000000C3: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  00000000000000C8: CC                 int         3
  00000000000000C9: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  00000000000000CE: CC                 int         3
  00000000000000CF: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  00000000000000D4: CC                 int         3
  00000000000000D5: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  00000000000000DA: CC                 int         3
  00000000000000DB: 48 8B C8           mov         rcx,rax
  00000000000000DE: E8 00 00 00 00     call        ??3@YAXPEAX@Z
  00000000000000E3: 0F 28 45 F7        movaps      xmm0,xmmword ptr [rbp-9]
  00000000000000E7: 48 8D 05 00 00 00  lea         rax,[??_7monad_error@v1_std_std@outcome@boost@@6B@]
                    00
  00000000000000EE: 48 8D 15 00 00 00  lea         rdx,[_TI3?AVmonad_error@v1_std_std@outcome@boost@@]
                    00
  00000000000000F5: 48 89 45 27        mov         qword ptr [rbp+27h],rax
  00000000000000F9: 48 8D 4D 27        lea         rcx,[rbp+27h]
  00000000000000FD: 48 C7 45 1F 0F 00  mov         qword ptr [rbp+1Fh],0Fh
                    00 00
  0000000000000105: 0F 11 45 3F        movups      xmmword ptr [rbp+3Fh],xmm0
  0000000000000109: 48 C7 45 17 00 00  mov         qword ptr [rbp+17h],0
                    00 00
  0000000000000111: C6 45 07 00        mov         byte ptr [rbp+7],0
  0000000000000115: E8 00 00 00 00     call        _CxxThrowException
  000000000000011A: CC                 int         3

  0000000000000021: 89 03              mov         dword ptr [rbx],eax
  0000000000000023: 48 8B C3           mov         rax,rbx
  0000000000000026: C6 43 04 01        mov         byte ptr [rbx+4],1
  000000000000002A: 48 83 C4 30        add         rsp,30h
  000000000000002E: 5B                 pop         rbx
  000000000000002F: C3                 ret
