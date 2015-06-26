  0000000000000000: 40 53              push        rbx
  0000000000000002: 48 83 EC 30        sub         rsp,30h
  0000000000000006: 48 C7 44 24 28 FE  mov         qword ptr [rsp+28h],0FFFFFFFFFFFFFFFEh
                    FF FF FF
  000000000000000F: 48 8B D9           mov         rbx,rcx
  0000000000000012: C7 44 24 20 00 00  mov         dword ptr [rsp+20h],0
                    00 00
  000000000000001A: 33 C0              xor         eax,eax
  000000000000001C: 88 44 24 48        mov         byte ptr [rsp+48h],al
  0000000000000020: 89 54 24 40        mov         dword ptr [rsp+40h],edx
  0000000000000024: C6 44 24 44 01     mov         byte ptr [rsp+44h],1
  0000000000000029: 4C 8D 44 24 48     lea         r8,[rsp+48h]
  000000000000002E: 48 8B D1           mov         rdx,rcx
  0000000000000031: 48 8D 4C 24 40     lea         rcx,[rsp+40h]
  0000000000000036: E8 00 00 00 00     call        replaced
  0000000000000000: 4C 89 44 24 18     mov         qword ptr [rsp+18h],r8
  0000000000000005: 53                 push        rbx
  0000000000000006: 48 83 EC 30        sub         rsp,30h
  000000000000000A: 44 0F B6 4C 24 50  movzx       r9d,byte ptr [rsp+50h]
  0000000000000010: 4C 8B C1           mov         r8,rcx
  0000000000000013: 48 8D 4C 24 50     lea         rcx,[rsp+50h]
  0000000000000018: C7 44 24 20 00 00  mov         dword ptr [rsp+20h],0
                    00 00
  0000000000000020: 48 8B DA           mov         rbx,rdx
  0000000000000023: E8 00 00 00 00     call        replaced
  0000000000000000: 40 53              push        rbx
  0000000000000002: 48 83 EC 30        sub         rsp,30h
  0000000000000006: 48 C7 44 24 28 FE  mov         qword ptr [rsp+28h],0FFFFFFFFFFFFFFFEh
                    FF FF FF
  000000000000000F: 48 8B DA           mov         rbx,rdx
  0000000000000012: C7 44 24 20 00 00  mov         dword ptr [rsp+20h],0
                    00 00
  000000000000001A: C6 44 24 54 00     mov         byte ptr [rsp+54h],0
  000000000000001F: 41 0F B6 50 04     movzx       edx,byte ptr [r8+4]
  0000000000000024: 44 8B CA           mov         r9d,edx
  0000000000000027: 41 83 E9 01        sub         r9d,1
  000000000000002B: 74 18              je          0000000000000045
  000000000000002D: 41 83 E9 01        sub         r9d,1
  0000000000000031: 74 19              je          000000000000004C
  0000000000000033: 41 83 E9 01        sub         r9d,1
  0000000000000037: 74 13              je          000000000000004C
  0000000000000039: 41 83 F9 01        cmp         r9d,1
  000000000000003D: 75 0D              jne         000000000000004C
  000000000000003F: E8 00 00 00 00     call        abort
  0000000000000044: CC                 int         3
  0000000000000045: 41 8B 00           mov         eax,dword ptr [r8]
  0000000000000048: 89 44 24 50        mov         dword ptr [rsp+50h],eax
  000000000000004C: 88 54 24 54        mov         byte ptr [rsp+54h],dl
  0000000000000050: 48 8D 54 24 50     lea         rdx,[rsp+50h]
  0000000000000055: E8 00 00 00 00     call        replaced
  0000000000000000: 48 89 54 24 10     mov         qword ptr [rsp+10h],rdx
  0000000000000005: 55                 push        rbp
  0000000000000006: 48 8D 6C 24 A9     lea         rbp,[rsp-57h]
  000000000000000B: 48 81 EC A0 00 00  sub         rsp,0A0h
                    00
  0000000000000012: 48 C7 45 D7 FE FF  mov         qword ptr [rbp-29h],0FFFFFFFFFFFFFFFEh
                    FF FF
  000000000000001A: 0F B6 4A 04        movzx       ecx,byte ptr [rdx+4]
  000000000000001E: 84 C9              test        cl,cl
  0000000000000020: 0F 95 C0           setne       al
  0000000000000023: 84 C0              test        al,al
  0000000000000025: 0F 85 B7 00 00 00  jne         00000000000000E2
  000000000000002B: C7 45 E7 02 00 00  mov         dword ptr [rbp-19h],2
                    00
  0000000000000032: E8 00 00 00 00     call        replaced
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

  0000000000000037: 48 89 45 EF        mov         qword ptr [rbp-11h],rax
  000000000000003B: 0F 28 45 E7        movaps      xmm0,xmmword ptr [rbp-19h]
  000000000000003F: 66 0F 7F 45 F7     movdqa      xmmword ptr [rbp-9],xmm0
  0000000000000044: 48 8D 55 07        lea         rdx,[rbp+7]
  0000000000000048: 48 8D 4D F7        lea         rcx,[rbp-9]
  000000000000004C: E8 00 00 00 00     call        replaced
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

  0000000000000051: 48 83 78 18 10     cmp         qword ptr [rax+18h],10h
  0000000000000056: 72 03              jb          000000000000005B
  0000000000000058: 48 8B 00           mov         rax,qword ptr [rax]
  000000000000005B: 48 8D 0D 00 00 00  lea         rcx,[??_7exception@std@@6B@]
                    00
  0000000000000062: 48 89 4D 27        mov         qword ptr [rbp+27h],rcx
  0000000000000066: 33 C9              xor         ecx,ecx
  0000000000000068: 48 89 4D 2F        mov         qword ptr [rbp+2Fh],rcx
  000000000000006C: 48 89 4D 37        mov         qword ptr [rbp+37h],rcx
  0000000000000070: 48 89 45 E7        mov         qword ptr [rbp-19h],rax
  0000000000000074: C6 45 EF 01        mov         byte ptr [rbp-11h],1
  0000000000000078: 48 8D 55 2F        lea         rdx,[rbp+2Fh]
  000000000000007C: 48 8D 4D E7        lea         rcx,[rbp-19h]
  0000000000000080: E8 00 00 00 00     call        __std_exception_copy
  0000000000000085: 48 8D 05 00 00 00  lea         rax,[??_7logic_error@std@@6B@]
                    00
  000000000000008C: 48 89 45 27        mov         qword ptr [rbp+27h],rax
  0000000000000090: 4C 8B 45 1F        mov         r8,qword ptr [rbp+1Fh]
  0000000000000094: 49 83 F8 10        cmp         r8,10h
  0000000000000098: 72 10              jb          00000000000000AA
  000000000000009A: 49 FF C0           inc         r8
  000000000000009D: 48 8B 55 07        mov         rdx,qword ptr [rbp+7]
  00000000000000A1: 48 8D 4D 07        lea         rcx,[rbp+7]
  00000000000000A5: E8 00 00 00 00     call        replaced
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

  00000000000000AA: 48 C7 45 1F 0F 00  mov         qword ptr [rbp+1Fh],0Fh
                    00 00
  00000000000000B2: 48 C7 45 17 00 00  mov         qword ptr [rbp+17h],0
                    00 00
  00000000000000BA: C6 45 07 00        mov         byte ptr [rbp+7],0
  00000000000000BE: 48 8D 05 00 00 00  lea         rax,[??_7monad_error@lightweight_futures@v1_std@spinlock@boost@@6B@]
                    00
  00000000000000C5: 48 89 45 27        mov         qword ptr [rbp+27h],rax
  00000000000000C9: 0F 28 45 F7        movaps      xmm0,xmmword ptr [rbp-9]
  00000000000000CD: 0F 11 45 3F        movups      xmmword ptr [rbp+3Fh],xmm0
  00000000000000D1: 48 8D 15 00 00 00  lea         rdx,[_TI3?AVmonad_error@lightweight_futures@v1_std@spinlock@boost@@]
                    00
  00000000000000D8: 48 8D 4D 27        lea         rcx,[rbp+27h]
  00000000000000DC: E8 00 00 00 00     call        _CxxThrowException
  00000000000000E1: CC                 int         3
  00000000000000E2: 8B 02              mov         eax,dword ptr [rdx]
  00000000000000E4: 44 8D 04 40        lea         r8d,[rax+rax*2]
  00000000000000E8: 0F B6 C9           movzx       ecx,cl
  00000000000000EB: 83 E9 01           sub         ecx,1
  00000000000000EE: 74 0F              je          00000000000000FF
  00000000000000F0: 83 E9 01           sub         ecx,1
  00000000000000F3: 74 0A              je          00000000000000FF
  00000000000000F5: 83 E9 01           sub         ecx,1
  00000000000000F8: 74 05              je          00000000000000FF
  00000000000000FA: 83 F9 01           cmp         ecx,1
  00000000000000FD: 75 04              jne         0000000000000103
  00000000000000FF: C6 42 04 00        mov         byte ptr [rdx+4],0
  0000000000000103: 41 8B C0           mov         eax,r8d
  0000000000000106: 48 81 C4 A0 00 00  add         rsp,0A0h
                    00
  000000000000010D: 5D                 pop         rbp
  000000000000010E: C3                 ret

  000000000000005A: 89 03              mov         dword ptr [rbx],eax
  000000000000005C: C6 43 04 01        mov         byte ptr [rbx+4],1
  0000000000000060: 48 8B C3           mov         rax,rbx
  0000000000000063: 48 83 C4 30        add         rsp,30h
  0000000000000067: 5B                 pop         rbx
  0000000000000068: C3                 ret

  0000000000000028: 48 8B C3           mov         rax,rbx
  000000000000002B: 48 83 C4 30        add         rsp,30h
  000000000000002F: 5B                 pop         rbx
  0000000000000030: C3                 ret

  000000000000003B: 90                 nop
  000000000000003C: 48 8B C3           mov         rax,rbx
  000000000000003F: 48 83 C4 30        add         rsp,30h
  0000000000000043: 5B                 pop         rbx
  0000000000000044: C3                 ret
