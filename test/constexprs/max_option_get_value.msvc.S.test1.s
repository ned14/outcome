  0000000000000000: 40 55              push        rbp
  0000000000000002: 48 8D 6C 24 A9     lea         rbp,[rsp-57h]
  0000000000000007: 48 81 EC A0 00 00  sub         rsp,0A0h
                    00
  000000000000000E: 48 C7 45 D7 FE FF  mov         qword ptr [rbp-29h],0FFFFFFFFFFFFFFFEh
                    FF FF
  0000000000000016: 48 8D 4D 67        lea         rcx,[rbp+67h]
  000000000000001A: E8 00 00 00 00     call        ?unknown@@YA?AV?$basic_monad@U?$option_policy@H@detail@lightweight_futures@v1_std@spinlock@boost@@@lightweight_futures@v1_std@spinlock@boost@@XZ
  000000000000001F: 90                 nop
  0000000000000020: 80 78 04 00        cmp         byte ptr [rax+4],0
  0000000000000024: 0F 95 C1           setne       cl
  0000000000000027: 84 C9              test        cl,cl
  0000000000000029: 0F 85 B7 00 00 00  jne         00000000000000E6
  000000000000002F: C7 45 E7 02 00 00  mov         dword ptr [rbp-19h],2
                    00
  0000000000000036: E8 00 00 00 00     call        replaced
  0000000000000000: 40 53              push        rbx
  0000000000000002: 48 83 EC 20        sub         rsp,20h
  0000000000000006: 8B 0D 00 00 00 00  mov         ecx,dword ptr [_tls_index]
  000000000000000C: 65 48 8B 04 25 58  mov         rax,qword ptr gs:[58h]
                    00 00 00
  0000000000000015: BA 00 00 00 00     mov         edx,offset _Init_thread_epoch
  000000000000001A: 48 8B 04 C8        mov         rax,qword ptr [rax+rcx*8]
  000000000000001E: 8B 0C 02           mov         ecx,dword ptr [rdx+rax]
  0000000000000021: 39 0D 00 00 00 00  cmp         dword ptr [?$TSS0@?1??monad_category@lightweight_futures@v1_std@spinlock@boost@@YAAEBV1detail@2345@XZ@4HA],ecx
  0000000000000027: 7E 52              jle         000000000000007B
  0000000000000029: 48 8D 0D 00 00 00  lea         rcx,[?$TSS0@?1??monad_category@lightweight_futures@v1_std@spinlock@boost@@YAAEBV1detail@2345@XZ@4HA]
                    00
  0000000000000030: E8 00 00 00 00     call        _Init_thread_header
  0000000000000035: 83 3D 00 00 00 00  cmp         dword ptr [?$TSS0@?1??monad_category@lightweight_futures@v1_std@spinlock@boost@@YAAEBV1detail@2345@XZ@4HA],0FFFFFFFFh
                    FF
  000000000000003C: 75 3D              jne         000000000000007B
  000000000000003E: 48 8D 05 00 00 00  lea         rax,[??_7monad_category@detail@lightweight_futures@v1_std@spinlock@boost@@6B@]
                    00
  0000000000000045: 48 8D 1D 00 00 00  lea         rbx,[?c@?1??monad_category@lightweight_futures@v1_std@spinlock@boost@@YAAEBV1detail@2345@XZ@4V162345@A]
                    00
  000000000000004C: 48 89 05 00 00 00  mov         qword ptr [?c@?1??monad_category@lightweight_futures@v1_std@spinlock@boost@@YAAEBV1detail@2345@XZ@4V162345@A],rax
                    00
  0000000000000053: 48 8D 0D 00 00 00  lea         rcx,[??__Fc@?1??monad_category@lightweight_futures@v1_std@spinlock@boost@@YAAEBV0detail@1234@XZ@YAXXZ]
                    00
  000000000000005A: 48 89 1D 08 00 00  mov         qword ptr [?c@?1??monad_category@lightweight_futures@v1_std@spinlock@boost@@YAAEBV1detail@2345@XZ@4V162345@A+8],rbx
                    00
  0000000000000061: E8 00 00 00 00     call        atexit
  0000000000000066: 48 8D 0D 00 00 00  lea         rcx,[?$TSS0@?1??monad_category@lightweight_futures@v1_std@spinlock@boost@@YAAEBV1detail@2345@XZ@4HA]
                    00
  000000000000006D: E8 00 00 00 00     call        _Init_thread_footer
  0000000000000072: 48 8B C3           mov         rax,rbx
  0000000000000075: 48 83 C4 20        add         rsp,20h
  0000000000000079: 5B                 pop         rbx
  000000000000007A: C3                 ret
  000000000000007B: 48 8D 05 00 00 00  lea         rax,[?c@?1??monad_category@lightweight_futures@v1_std@spinlock@boost@@YAAEBV1detail@2345@XZ@4V162345@A]
                    00
  0000000000000082: 48 83 C4 20        add         rsp,20h
  0000000000000086: 5B                 pop         rbx
  0000000000000087: C3                 ret

  000000000000003B: 48 89 45 EF        mov         qword ptr [rbp-11h],rax
  000000000000003F: 0F 28 45 E7        movaps      xmm0,xmmword ptr [rbp-19h]
  0000000000000043: 66 0F 7F 45 F7     movdqa      xmmword ptr [rbp-9],xmm0
  0000000000000048: 48 8D 55 07        lea         rdx,[rbp+7]
  000000000000004C: 48 8D 4D F7        lea         rcx,[rbp-9]
  0000000000000050: E8 00 00 00 00     call        replaced
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

  0000000000000055: 48 83 78 18 10     cmp         qword ptr [rax+18h],10h
  000000000000005A: 72 03              jb          000000000000005F
  000000000000005C: 48 8B 00           mov         rax,qword ptr [rax]
  000000000000005F: 48 8D 0D 00 00 00  lea         rcx,[??_7exception@std@@6B@]
                    00
  0000000000000066: 48 89 4D 27        mov         qword ptr [rbp+27h],rcx
  000000000000006A: 33 C9              xor         ecx,ecx
  000000000000006C: 48 89 4D 2F        mov         qword ptr [rbp+2Fh],rcx
  0000000000000070: 48 89 4D 37        mov         qword ptr [rbp+37h],rcx
  0000000000000074: 48 89 45 E7        mov         qword ptr [rbp-19h],rax
  0000000000000078: C6 45 EF 01        mov         byte ptr [rbp-11h],1
  000000000000007C: 48 8D 55 2F        lea         rdx,[rbp+2Fh]
  0000000000000080: 48 8D 4D E7        lea         rcx,[rbp-19h]
  0000000000000084: E8 00 00 00 00     call        __std_exception_copy
  0000000000000089: 48 8D 05 00 00 00  lea         rax,[??_7logic_error@std@@6B@]
                    00
  0000000000000090: 48 89 45 27        mov         qword ptr [rbp+27h],rax
  0000000000000094: 4C 8B 45 1F        mov         r8,qword ptr [rbp+1Fh]
  0000000000000098: 49 83 F8 10        cmp         r8,10h
  000000000000009C: 72 10              jb          00000000000000AE
  000000000000009E: 49 FF C0           inc         r8
  00000000000000A1: 48 8B 55 07        mov         rdx,qword ptr [rbp+7]
  00000000000000A5: 48 8D 4D 07        lea         rcx,[rbp+7]
  00000000000000A9: E8 00 00 00 00     call        replaced
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

  00000000000000AE: 48 C7 45 1F 0F 00  mov         qword ptr [rbp+1Fh],0Fh
                    00 00
  00000000000000B6: 48 C7 45 17 00 00  mov         qword ptr [rbp+17h],0
                    00 00
  00000000000000BE: C6 45 07 00        mov         byte ptr [rbp+7],0
  00000000000000C2: 48 8D 05 00 00 00  lea         rax,[??_7monad_error@lightweight_futures@v1_std@spinlock@boost@@6B@]
                    00
  00000000000000C9: 48 89 45 27        mov         qword ptr [rbp+27h],rax
  00000000000000CD: 0F 28 45 F7        movaps      xmm0,xmmword ptr [rbp-9]
  00000000000000D1: 0F 11 45 3F        movups      xmmword ptr [rbp+3Fh],xmm0
  00000000000000D5: 48 8D 15 00 00 00  lea         rdx,[_TI3?AVmonad_error@lightweight_futures@v1_std@spinlock@boost@@]
                    00
  00000000000000DC: 48 8D 4D 27        lea         rcx,[rbp+27h]
  00000000000000E0: E8 00 00 00 00     call        _CxxThrowException
  00000000000000E5: 90                 nop
  00000000000000E6: 8B 00              mov         eax,dword ptr [rax]
  00000000000000E8: 48 81 C4 A0 00 00  add         rsp,0A0h
                    00
  00000000000000EF: 5D                 pop         rbp
  00000000000000F0: C3                 ret
