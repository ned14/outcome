  0000000000000000: 48 89 4C 24 08     mov         qword ptr [rsp+8],rcx
  0000000000000005: 53                 push        rbx
  0000000000000006: 48 83 EC 40        sub         rsp,40h
  000000000000000A: 48 C7 44 24 28 FE  mov         qword ptr [rsp+28h],0FFFFFFFFFFFFFFFEh
                    FF FF FF
  0000000000000013: 48 8B D9           mov         rbx,rcx
  0000000000000016: C7 44 24 20 00 00  mov         dword ptr [rsp+20h],0
                    00 00
  000000000000001E: 33 C0              xor         eax,eax
  0000000000000020: 88 44 24 50        mov         byte ptr [rsp+50h],al
  0000000000000024: 48 8D 4C 24 30     lea         rcx,[rsp+30h]
  0000000000000029: E8 00 00 00 00     call        ?unknown@@YA?AV?$basic_monad@U?$option_policy@H@detail@v1_std_std@outcome@boost@@@v1_std_std@outcome@boost@@XZ
  000000000000002E: 90                 nop
  000000000000002F: 4C 8D 44 24 50     lea         r8,[rsp+50h]
  0000000000000034: 48 8B D3           mov         rdx,rbx
  0000000000000037: 48 8B C8           mov         rcx,rax
  000000000000003A: E8 00 00 00 00     call        replaced
  0000000000000000: 40 53              push        rbx
  0000000000000002: 48 83 EC 30        sub         rsp,30h
  0000000000000006: 4C 8B C1           mov         r8,rcx
  0000000000000009: C7 44 24 20 00 00  mov         dword ptr [rsp+20h],0
                    00 00
  0000000000000011: 48 8D 4C 24 50     lea         rcx,[rsp+50h]
  0000000000000016: 48 8B DA           mov         rbx,rdx
  0000000000000019: E8 00 00 00 00     call        replaced
  0000000000000000: 40 53              push        rbx
  0000000000000002: 48 83 EC 40        sub         rsp,40h
  0000000000000006: 48 8B DA           mov         rbx,rdx
  0000000000000009: C7 44 24 20 00 00  mov         dword ptr [rsp+20h],0
                    00 00
  0000000000000011: 41 0F B6 50 04     movzx       edx,byte ptr [r8+4]
  0000000000000016: 44 8B CA           mov         r9d,edx
  0000000000000019: 41 83 E9 01        sub         r9d,1
  000000000000001D: 75 07              jne         0000000000000026
  000000000000001F: 41 8B 00           mov         eax,dword ptr [r8]
  0000000000000022: 89 44 24 28        mov         dword ptr [rsp+28h],eax
  0000000000000026: 88 54 24 2C        mov         byte ptr [rsp+2Ch],dl
  000000000000002A: 48 8D 54 24 28     lea         rdx,[rsp+28h]
  000000000000002F: E8 00 00 00 00     call        replaced
  0000000000000000: 48 89 54 24 10     mov         qword ptr [rsp+10h],rdx
  0000000000000005: 55                 push        rbp
  0000000000000006: 48 8D 6C 24 A9     lea         rbp,[rsp-57h]
  000000000000000B: 48 81 EC A0 00 00  sub         rsp,0A0h
                    00
  0000000000000012: 48 C7 45 D7 FE FF  mov         qword ptr [rbp-29h],0FFFFFFFFFFFFFFFEh
                    FF FF
  000000000000001A: 0F B6 4A 04        movzx       ecx,byte ptr [rdx+4]
  000000000000001E: 84 C9              test        cl,cl
  0000000000000020: 0F 85 F3 00 00 00  jne         0000000000000119
  0000000000000026: C7 45 E7 02 00 00  mov         dword ptr [rbp-19h],2
                    00
  000000000000002D: E8 00 00 00 00     call        replaced
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

  0000000000000032: 48 89 45 EF        mov         qword ptr [rbp-11h],rax
  0000000000000036: 0F 28 45 E7        movaps      xmm0,xmmword ptr [rbp-19h]
  000000000000003A: 66 0F 7F 45 F7     movdqa      xmmword ptr [rbp-9],xmm0
  000000000000003F: 48 8D 55 07        lea         rdx,[rbp+7]
  0000000000000043: 48 8D 4D F7        lea         rcx,[rbp-9]
  0000000000000047: E8 00 00 00 00     call        replaced
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

  000000000000004C: 48 83 78 18 10     cmp         qword ptr [rax+18h],10h
  0000000000000051: 72 03              jb          0000000000000056
  0000000000000053: 48 8B 00           mov         rax,qword ptr [rax]
  0000000000000056: 48 8D 0D 00 00 00  lea         rcx,[??_7exception@std@@6B@]
                    00
  000000000000005D: 48 89 4D 27        mov         qword ptr [rbp+27h],rcx
  0000000000000061: 33 C9              xor         ecx,ecx
  0000000000000063: 48 89 4D 2F        mov         qword ptr [rbp+2Fh],rcx
  0000000000000067: 48 89 4D 37        mov         qword ptr [rbp+37h],rcx
  000000000000006B: 48 89 45 E7        mov         qword ptr [rbp-19h],rax
  000000000000006F: C6 45 EF 01        mov         byte ptr [rbp-11h],1
  0000000000000073: 48 8D 55 2F        lea         rdx,[rbp+2Fh]
  0000000000000077: 48 8D 4D E7        lea         rcx,[rbp-19h]
  000000000000007B: E8 00 00 00 00     call        __std_exception_copy
  0000000000000080: 48 8D 05 00 00 00  lea         rax,[??_7logic_error@std@@6B@]
                    00
  0000000000000087: 48 89 45 27        mov         qword ptr [rbp+27h],rax
  000000000000008B: 48 8B 45 1F        mov         rax,qword ptr [rbp+1Fh]
  000000000000008F: 48 83 F8 10        cmp         rax,10h
  0000000000000093: 72 4C              jb          00000000000000E1
  0000000000000095: 48 FF C0           inc         rax
  0000000000000098: 48 8B 4D 07        mov         rcx,qword ptr [rbp+7]
  000000000000009C: 48 3D 00 10 00 00  cmp         rax,1000h
  00000000000000A2: 72 38              jb          00000000000000DC
  00000000000000A4: F6 C1 1F           test        cl,1Fh
  00000000000000A7: 74 06              je          00000000000000AF
  00000000000000A9: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  00000000000000AE: CC                 int         3
  00000000000000AF: 48 8B 41 F8        mov         rax,qword ptr [rcx-8]
  00000000000000B3: 48 3B C1           cmp         rax,rcx
  00000000000000B6: 72 06              jb          00000000000000BE
  00000000000000B8: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  00000000000000BD: CC                 int         3
  00000000000000BE: 48 2B C8           sub         rcx,rax
  00000000000000C1: 48 83 F9 08        cmp         rcx,8
  00000000000000C5: 73 06              jae         00000000000000CD
  00000000000000C7: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  00000000000000CC: CC                 int         3
  00000000000000CD: 48 83 F9 27        cmp         rcx,27h
  00000000000000D1: 76 06              jbe         00000000000000D9
  00000000000000D3: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  00000000000000D8: CC                 int         3
  00000000000000D9: 48 8B C8           mov         rcx,rax
  00000000000000DC: E8 00 00 00 00     call        ??3@YAXPEAX@Z
  00000000000000E1: 48 C7 45 1F 0F 00  mov         qword ptr [rbp+1Fh],0Fh
                    00 00
  00000000000000E9: 48 C7 45 17 00 00  mov         qword ptr [rbp+17h],0
                    00 00
  00000000000000F1: C6 45 07 00        mov         byte ptr [rbp+7],0
  00000000000000F5: 48 8D 05 00 00 00  lea         rax,[??_7monad_error@v1_std_std@outcome@boost@@6B@]
                    00
  00000000000000FC: 48 89 45 27        mov         qword ptr [rbp+27h],rax
  0000000000000100: 0F 28 45 F7        movaps      xmm0,xmmword ptr [rbp-9]
  0000000000000104: 0F 11 45 3F        movups      xmmword ptr [rbp+3Fh],xmm0
  0000000000000108: 48 8D 15 00 00 00  lea         rdx,[_TI3?AVmonad_error@v1_std_std@outcome@boost@@]
                    00
  000000000000010F: 48 8D 4D 27        lea         rcx,[rbp+27h]
  0000000000000113: E8 00 00 00 00     call        _CxxThrowException
  0000000000000118: CC                 int         3
  0000000000000119: 8B 02              mov         eax,dword ptr [rdx]
  000000000000011B: 44 8D 04 40        lea         r8d,[rax+rax*2]
  000000000000011F: 0F B6 C9           movzx       ecx,cl
  0000000000000122: 83 E9 01           sub         ecx,1
  0000000000000125: 74 0A              je          0000000000000131
  0000000000000127: 83 E9 01           sub         ecx,1
  000000000000012A: 74 05              je          0000000000000131
  000000000000012C: 83 F9 01           cmp         ecx,1
  000000000000012F: 75 04              jne         0000000000000135
  0000000000000131: C6 42 04 00        mov         byte ptr [rdx+4],0
  0000000000000135: 41 8B C0           mov         eax,r8d
  0000000000000138: 48 81 C4 A0 00 00  add         rsp,0A0h
                    00
  000000000000013F: 5D                 pop         rbp
  0000000000000140: C3                 ret

  0000000000000034: 89 03              mov         dword ptr [rbx],eax
  0000000000000036: 48 8B C3           mov         rax,rbx
  0000000000000039: C6 43 04 01        mov         byte ptr [rbx+4],1
  000000000000003D: 48 83 C4 40        add         rsp,40h
  0000000000000041: 5B                 pop         rbx
  0000000000000042: C3                 ret

  000000000000001E: 48 8B C3           mov         rax,rbx
  0000000000000021: 48 83 C4 30        add         rsp,30h
  0000000000000025: 5B                 pop         rbx
  0000000000000026: C3                 ret

  000000000000003F: 90                 nop
  0000000000000040: 48 8B C3           mov         rax,rbx
  0000000000000043: 48 83 C4 40        add         rsp,40h
  0000000000000047: 5B                 pop         rbx
  0000000000000048: C3                 ret
