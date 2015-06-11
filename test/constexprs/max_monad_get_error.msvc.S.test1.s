  0000000000000000: 40 53              push        rbx
  0000000000000002: 48 83 EC 40        sub         rsp,40h
  0000000000000006: 48 C7 44 24 20 FE  mov         qword ptr [rsp+20h],0FFFFFFFFFFFFFFFEh
                    FF FF FF
  000000000000000F: 48 8B D9           mov         rbx,rcx
  0000000000000012: 48 8D 4C 24 28     lea         rcx,[rsp+28h]
  0000000000000017: E8 00 00 00 00     call        ?unknown@@YA?AV?$monad@HVerror_code@std@@Vexception_ptr@2@Uthrow_monad_error@detail@lightweight_futures@v1_std@spinlock@boost@@@lightweight_futures@v1_std@spinlock@boost@@XZ
  000000000000001C: 4C 8B C0           mov         r8,rax
  000000000000001F: 0F B6 48 10        movzx       ecx,byte ptr [rax+10h]
  0000000000000023: 84 C9              test        cl,cl
  0000000000000025: 0F 95 C2           setne       dl
  0000000000000028: 84 D2              test        dl,dl
  000000000000002A: 75 06              jne         0000000000000032
  000000000000002C: E8 00 00 00 00     call        replaced
  0000000000000000: 40 55              push        rbp
  0000000000000002: 48 8D 6C 24 A9     lea         rbp,[rsp-57h]
  0000000000000007: 48 81 EC 90 00 00  sub         rsp,90h
                    00
  000000000000000E: C7 45 E7 02 00 00  mov         dword ptr [rbp-19h],2
                    00
  0000000000000015: E8 00 00 00 00     call        replaced
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

  000000000000001A: 48 89 45 EF        mov         qword ptr [rbp-11h],rax
  000000000000001E: 48 8D 55 07        lea         rdx,[rbp+7]
  0000000000000022: 0F 28 45 E7        movaps      xmm0,xmmword ptr [rbp-19h]
  0000000000000026: 48 8D 4D F7        lea         rcx,[rbp-9]
  000000000000002A: 66 0F 7F 45 F7     movdqa      xmmword ptr [rbp-9],xmm0
  000000000000002F: E8 00 00 00 00     call        replaced
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

  0000000000000034: 48 83 78 18 10     cmp         qword ptr [rax+18h],10h
  0000000000000039: 72 03              jb          000000000000003E
  000000000000003B: 48 8B 00           mov         rax,qword ptr [rax]
  000000000000003E: 48 8D 0D 00 00 00  lea         rcx,[??_7exception@std@@6B@]
                    00
  0000000000000045: 48 89 45 E7        mov         qword ptr [rbp-19h],rax
  0000000000000049: 48 89 4D 27        mov         qword ptr [rbp+27h],rcx
  000000000000004D: 48 8D 55 2F        lea         rdx,[rbp+2Fh]
  0000000000000051: 33 C9              xor         ecx,ecx
  0000000000000053: C6 45 EF 01        mov         byte ptr [rbp-11h],1
  0000000000000057: 48 89 4D 2F        mov         qword ptr [rbp+2Fh],rcx
  000000000000005B: 48 89 4D 37        mov         qword ptr [rbp+37h],rcx
  000000000000005F: 48 8D 4D E7        lea         rcx,[rbp-19h]
  0000000000000063: E8 00 00 00 00     call        __std_exception_copy
  0000000000000068: 4C 8B 45 1F        mov         r8,qword ptr [rbp+1Fh]
  000000000000006C: 48 8D 05 00 00 00  lea         rax,[??_7logic_error@std@@6B@]
                    00
  0000000000000073: 48 89 45 27        mov         qword ptr [rbp+27h],rax
  0000000000000077: 49 83 F8 10        cmp         r8,10h
  000000000000007B: 72 10              jb          000000000000008D
  000000000000007D: 48 8B 55 07        mov         rdx,qword ptr [rbp+7]
  0000000000000081: 48 8D 4D 07        lea         rcx,[rbp+7]
  0000000000000085: 49 FF C0           inc         r8
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

  000000000000008D: 0F 28 45 F7        movaps      xmm0,xmmword ptr [rbp-9]
  0000000000000091: 48 8D 05 00 00 00  lea         rax,[??_7monad_error@lightweight_futures@v1_std@spinlock@boost@@6B@]
                    00
  0000000000000098: 48 8D 15 00 00 00  lea         rdx,[_TI3?AVmonad_error@lightweight_futures@v1_std@spinlock@boost@@]
                    00
  000000000000009F: 48 89 45 27        mov         qword ptr [rbp+27h],rax
  00000000000000A3: 48 8D 4D 27        lea         rcx,[rbp+27h]
  00000000000000A7: 48 C7 45 1F 0F 00  mov         qword ptr [rbp+1Fh],0Fh
                    00 00
  00000000000000AF: 0F 11 45 3F        movups      xmmword ptr [rbp+3Fh],xmm0
  00000000000000B3: 48 C7 45 17 00 00  mov         qword ptr [rbp+17h],0
                    00 00
  00000000000000BB: C6 45 07 00        mov         byte ptr [rbp+7],0
  00000000000000BF: E8 00 00 00 00     call        _CxxThrowException
  00000000000000C4: CC                 int         3

  0000000000000031: CC                 int         3
  0000000000000032: 80 F9 02           cmp         cl,2
  0000000000000035: 0F 94 C0           sete        al
  0000000000000038: 84 C0              test        al,al
  000000000000003A: 75 11              jne         000000000000004D
  000000000000003C: C7 03 00 00 00 00  mov         dword ptr [rbx],0
  0000000000000042: E8 00 00 00 00     call        replaced
  0000000000000000: 48 83 EC 28        sub         rsp,28h
  0000000000000004: 8B 0D 00 00 00 00  mov         ecx,dword ptr [_tls_index]
  000000000000000A: 65 48 8B 04 25 58  mov         rax,qword ptr gs:[58h]
                    00 00 00
  0000000000000013: BA 00 00 00 00     mov         edx,offset _Init_thread_epoch
  0000000000000018: 48 8B 04 C8        mov         rax,qword ptr [rax+rcx*8]
  000000000000001C: 8B 0C 02           mov         ecx,dword ptr [rdx+rax]
  000000000000001F: 39 0D 00 00 00 00  cmp         dword ptr [?$TSS0@?1???$_Immortalize@V_System_error_category@std@@@std@@YAAEAV_System_error_category@1@XZ@4HA],ecx
  0000000000000025: 7E 46              jle         000000000000006D
  0000000000000027: 48 8D 0D 00 00 00  lea         rcx,[?$TSS0@?1???$_Immortalize@V_System_error_category@std@@@std@@YAAEAV_System_error_category@1@XZ@4HA]
                    00
  000000000000002E: E8 00 00 00 00     call        _Init_thread_header
  0000000000000033: 83 3D 00 00 00 00  cmp         dword ptr [?$TSS0@?1???$_Immortalize@V_System_error_category@std@@@std@@YAAEAV_System_error_category@1@XZ@4HA],0FFFFFFFFh
                    FF
  000000000000003A: 75 31              jne         000000000000006D
  000000000000003C: 48 8D 05 00 00 00  lea         rax,[??_7_System_error_category@std@@6B@]
                    00
  0000000000000043: 48 C7 05 08 00 00  mov         qword ptr [?_Static@?1???$_Immortalize@V_System_error_category@std@@@std@@YAAEAV_System_error_category@1@XZ@4U?$_Immortalizer@V_System_error_category@std@@@1@A+8],7
                    00 07 00 00 00
  000000000000004E: 48 8D 0D 00 00 00  lea         rcx,[??__F_Static@?1???$_Immortalize@V_System_error_category@std@@@std@@YAAEAV_System_error_category@0@XZ@YAXXZ]
                    00
  0000000000000055: 48 89 05 00 00 00  mov         qword ptr [?_Static@?1???$_Immortalize@V_System_error_category@std@@@std@@YAAEAV_System_error_category@1@XZ@4U?$_Immortalizer@V_System_error_category@std@@@1@A],rax
                    00
  000000000000005C: E8 00 00 00 00     call        atexit
  0000000000000061: 48 8D 0D 00 00 00  lea         rcx,[?$TSS0@?1???$_Immortalize@V_System_error_category@std@@@std@@YAAEAV_System_error_category@1@XZ@4HA]
                    00
  0000000000000068: E8 00 00 00 00     call        _Init_thread_footer
  000000000000006D: 48 8D 05 00 00 00  lea         rax,[?_Static@?1???$_Immortalize@V_System_error_category@std@@@std@@YAAEAV_System_error_category@1@XZ@4U?$_Immortalizer@V_System_error_category@std@@@1@A]
                    00
  0000000000000074: 48 83 C4 28        add         rsp,28h
  0000000000000078: C3                 ret

  0000000000000047: 48 89 43 08        mov         qword ptr [rbx+8],rax
  000000000000004B: EB 07              jmp         0000000000000054
  000000000000004D: 41 0F 10 00        movups      xmm0,xmmword ptr [r8]
  0000000000000051: 0F 11 03           movups      xmmword ptr [rbx],xmm0
  0000000000000054: 0F B6 4C 24 38     movzx       ecx,byte ptr [rsp+38h]
  0000000000000059: 83 E9 01           sub         ecx,1
  000000000000005C: 74 15              je          0000000000000073
  000000000000005E: 83 E9 01           sub         ecx,1
  0000000000000061: 74 10              je          0000000000000073
  0000000000000063: 83 F9 01           cmp         ecx,1
  0000000000000066: 75 0B              jne         0000000000000073
  0000000000000068: 48 8D 4C 24 28     lea         rcx,[rsp+28h]
  000000000000006D: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  0000000000000072: 90                 nop
  0000000000000073: 48 8B C3           mov         rax,rbx
  0000000000000076: 48 83 C4 40        add         rsp,40h
  000000000000007A: 5B                 pop         rbx
  000000000000007B: C3                 ret
