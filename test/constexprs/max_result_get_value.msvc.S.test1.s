  0000000000000000: 48 81 EC 88 00 00  sub         rsp,88h
  0000000000000007: 48 8D 4C 24 30     lea         rcx,[rsp+30h]
  000000000000000C: E8 00 00 00 00     call        ?unknown@@YA?AV?$basic_monad@U?$result_policy@H@policy@_1_0_std_std_9274c0d4@outcome@boost@@@_1_0_std_std_9274c0d4@outcome@boost@@XZ
  0000000000000011: 0F B6 48 18        movzx       ecx,byte ptr [rax+18h]
  0000000000000015: 84 C9              test        cl,cl
  0000000000000017: 74 0F              je          0000000000000028
  0000000000000019: 80 F9 02           cmp         cl,2
  000000000000001C: 74 15              je          0000000000000033
  000000000000001E: 8B 00              mov         eax,dword ptr [rax]
  0000000000000020: 48 81 C4 88 00 00  add         rsp,88h
  0000000000000027: C3                 ret
  0000000000000028: B9 02 00 00 00     mov         ecx,2
  0000000000000000: 48 83 EC 78        sub         rsp,78h
  0000000000000004: 8B D1              mov         edx,ecx
  0000000000000006: 48 8D 4C 24 30     lea         rcx,[rsp+30h]
  0000000000000000: 40 53              push        rbx
  0000000000000002: 48 83 EC 30        sub         rsp,30h
  0000000000000006: 33 C0              xor         eax,eax
  0000000000000008: 89 54 24 20        mov         dword ptr [rsp+20h],edx
  000000000000000C: 89 01              mov         dword ptr [rcx],eax
  000000000000000E: 48 8B D9           mov         rbx,rcx
  0000000000000011: 48 89 41 08        mov         qword ptr [rcx+8],rax
  0000000000000000: 40 53              push        rbx
  0000000000000002: 48 83 EC 20        sub         rsp,20h
  0000000000000006: 65 48 8B 04 25 58  mov         rax,qword ptr gs:[58h]
  000000000000000F: 8B 0D 00 00 00 00  mov         ecx,dword ptr [_tls_index]
  0000000000000015: BA 00 00 00 00     mov         edx,offset _Init_thread_epoch
  000000000000001A: 48 8B 0C C8        mov         rcx,qword ptr [rax+rcx*8]
  000000000000001E: 8B 04 0A           mov         eax,dword ptr [rdx+rcx]
  0000000000000021: 39 05 00 00 00 00  cmp         dword ptr [?$TSS0@?1??monad_category@_1_0_std_std_9274c0d4@outcome@boost@@YAAEBV1_detail@234@XZ@4HA],eax
  0000000000000027: 7F 0D              jg          0000000000000036
  0000000000000029: 48 8D 05 00 00 00  lea         rax,[?c@?1??monad_category@_1_0_std_std_9274c0d4@outcome@boost@@YAAEBV1_detail@234@XZ@4V15234@A]
  0000000000000030: 48 83 C4 20        add         rsp,20h
  0000000000000034: 5B                 pop         rbx
  0000000000000035: C3                 ret
  0000000000000036: 48 8D 0D 00 00 00  lea         rcx,[?$TSS0@?1??monad_category@_1_0_std_std_9274c0d4@outcome@boost@@YAAEBV1_detail@234@XZ@4HA]
  000000000000003D: E8 00 00 00 00     call        _Init_thread_header
  0000000000000042: 83 3D 00 00 00 00  cmp         dword ptr [?$TSS0@?1??monad_category@_1_0_std_std_9274c0d4@outcome@boost@@YAAEBV1_detail@234@XZ@4HA],0FFFFFFFFh
  0000000000000049: 75 DE              jne         0000000000000029
  000000000000004B: 48 8D 05 00 00 00  lea         rax,[??_7monad_category@_detail@_1_0_std_std_9274c0d4@outcome@boost@@6B@]
  0000000000000052: 48 8D 1D 00 00 00  lea         rbx,[?c@?1??monad_category@_1_0_std_std_9274c0d4@outcome@boost@@YAAEBV1_detail@234@XZ@4V15234@A]
  0000000000000059: 48 89 05 00 00 00  mov         qword ptr [?c@?1??monad_category@_1_0_std_std_9274c0d4@outcome@boost@@YAAEBV1_detail@234@XZ@4V15234@A],rax
  0000000000000060: 48 8D 0D 00 00 00  lea         rcx,[??__Fc@?1??monad_category@_1_0_std_std_9274c0d4@outcome@boost@@YAAEBV0_detail@123@XZ@YAXXZ]
  0000000000000067: 48 89 1D 08 00 00  mov         qword ptr [?c@?1??monad_category@_1_0_std_std_9274c0d4@outcome@boost@@YAAEBV1_detail@234@XZ@4V15234@A+8],rbx
  000000000000006E: E8 00 00 00 00     call        atexit
  0000000000000073: 48 8D 0D 00 00 00  lea         rcx,[?$TSS0@?1??monad_category@_1_0_std_std_9274c0d4@outcome@boost@@YAAEBV1_detail@234@XZ@4HA]
  000000000000007A: E8 00 00 00 00     call        _Init_thread_footer
  000000000000007F: 48 8B C3           mov         rax,rbx
  0000000000000082: 48 83 C4 20        add         rsp,20h
  0000000000000086: 5B                 pop         rbx
  0000000000000087: C3                 ret
  000000000000001A: 48 89 44 24 28     mov         qword ptr [rsp+28h],rax
  000000000000001F: 48 8B C3           mov         rax,rbx
  0000000000000022: 0F 10 44 24 20     movups      xmm0,xmmword ptr [rsp+20h]
  0000000000000027: 0F 11 03           movups      xmmword ptr [rbx],xmm0
  000000000000002A: 48 83 C4 30        add         rsp,30h
  000000000000002E: 5B                 pop         rbx
  000000000000002F: C3                 ret
  0000000000000010: 48 8D 54 24 20     lea         rdx,[rsp+20h]
  0000000000000015: 48 8D 4C 24 40     lea         rcx,[rsp+40h]
  000000000000001A: 0F 10 00           movups      xmm0,xmmword ptr [rax]
  000000000000001D: 0F 29 44 24 20     movaps      xmmword ptr [rsp+20h],xmm0
  0000000000000000: 40 53              push        rbx
  0000000000000002: 48 83 EC 30        sub         rsp,30h
  0000000000000006: 0F 10 02           movups      xmm0,xmmword ptr [rdx]
  0000000000000009: 48 8D 54 24 20     lea         rdx,[rsp+20h]
  000000000000000E: 48 8B D9           mov         rbx,rcx
  0000000000000011: 0F 29 44 24 20     movaps      xmmword ptr [rsp+20h],xmm0
  0000000000000000: 40 57              push        rdi
  0000000000000002: 48 83 EC 60        sub         rsp,60h
  0000000000000006: 48 C7 44 24 20 FE  mov         qword ptr [rsp+20h],0FFFFFFFFFFFFFFFEh
  000000000000000F: 48 89 5C 24 70     mov         qword ptr [rsp+70h],rbx
  0000000000000014: 48 8B DA           mov         rbx,rdx
  0000000000000017: 48 8B F9           mov         rdi,rcx
  000000000000001A: 48 C7 44 24 50 00  mov         qword ptr [rsp+50h],0
  0000000000000023: 48 C7 44 24 58 0F  mov         qword ptr [rsp+58h],0Fh
  000000000000002C: C6 44 24 40 00     mov         byte ptr [rsp+40h],0
  0000000000000031: 45 33 C0           xor         r8d,r8d
  0000000000000034: 48 8D 15 00 00 00  lea         rdx,[??_C@_00CNPNBAHC@?$AA@]
  000000000000003B: 48 8D 4C 24 40     lea         rcx,[rsp+40h]
  0000000000000000: 48 89 5C 24 08     mov         qword ptr [rsp+8],rbx
  0000000000000005: 48 89 74 24 10     mov         qword ptr [rsp+10h],rsi
  000000000000000A: 57                 push        rdi
  000000000000000B: 48 83 EC 20        sub         rsp,20h
  000000000000000F: 48 8B F2           mov         rsi,rdx
  0000000000000012: 49 8B F8           mov         rdi,r8
  0000000000000015: 48 8B 51 18        mov         rdx,qword ptr [rcx+18h]
  0000000000000019: 48 8B D9           mov         rbx,rcx
  000000000000001C: 48 83 FA 10        cmp         rdx,10h
  0000000000000020: 72 03              jb          0000000000000025
  0000000000000022: 48 8B 09           mov         rcx,qword ptr [rcx]
  0000000000000025: 48 3B CE           cmp         rcx,rsi
  0000000000000028: 77 3A              ja          0000000000000064
  000000000000002A: 48 03 4B 10        add         rcx,qword ptr [rbx+10h]
  000000000000002E: 48 3B F1           cmp         rsi,rcx
  0000000000000031: 73 31              jae         0000000000000064
  0000000000000033: 48 83 FA 10        cmp         rdx,10h
  0000000000000037: 72 05              jb          000000000000003E
  0000000000000039: 48 8B 03           mov         rax,qword ptr [rbx]
  000000000000003C: EB 03              jmp         0000000000000041
  000000000000003E: 48 8B C3           mov         rax,rbx
  0000000000000041: 48 2B F0           sub         rsi,rax
  0000000000000044: 4C 8B CF           mov         r9,rdi
  0000000000000047: 4C 8B C6           mov         r8,rsi
  000000000000004A: 48 8B D3           mov         rdx,rbx
  000000000000004D: 48 8B CB           mov         rcx,rbx
  0000000000000050: 48 8B 5C 24 30     mov         rbx,qword ptr [rsp+30h]
  0000000000000055: 48 8B 74 24 38     mov         rsi,qword ptr [rsp+38h]
  000000000000005A: 48 83 C4 20        add         rsp,20h
  000000000000005E: 5F                 pop         rdi
  000000000000005F: E9 00 00 00 00     jmp         ?assign@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAAEAV12@AEBV12@_K_K@Z
  0000000000000064: 48 85 FF           test        rdi,rdi
  0000000000000067: 75 39              jne         00000000000000A2
  0000000000000069: 48 89 7B 10        mov         qword ptr [rbx+10h],rdi
  000000000000006D: 48 83 FA 10        cmp         rdx,10h
  0000000000000071: 72 19              jb          000000000000008C
  0000000000000073: 48 8B 03           mov         rax,qword ptr [rbx]
  0000000000000076: 40 88 38           mov         byte ptr [rax],dil
  0000000000000079: 48 8B C3           mov         rax,rbx
  000000000000007C: 48 8B 5C 24 30     mov         rbx,qword ptr [rsp+30h]
  0000000000000081: 48 8B 74 24 38     mov         rsi,qword ptr [rsp+38h]
  0000000000000086: 48 83 C4 20        add         rsp,20h
  000000000000008A: 5F                 pop         rdi
  000000000000008B: C3                 ret
  000000000000008C: 48 8B C3           mov         rax,rbx
  000000000000008F: C6 03 00           mov         byte ptr [rbx],0
  0000000000000092: 48 8B 5C 24 30     mov         rbx,qword ptr [rsp+30h]
  0000000000000097: 48 8B 74 24 38     mov         rsi,qword ptr [rsp+38h]
  000000000000009C: 48 83 C4 20        add         rsp,20h
  00000000000000A0: 5F                 pop         rdi
  00000000000000A1: C3                 ret
  00000000000000A2: 48 3B D7           cmp         rdx,rdi
  00000000000000A5: 73 0B              jae         00000000000000B2
  00000000000000A7: 48 8B D7           mov         rdx,rdi
  00000000000000AA: 48 8B CB           mov         rcx,rbx
  0000000000000000: 48 89 54 24 10     mov         qword ptr [rsp+10h],rdx
  0000000000000005: 48 89 4C 24 08     mov         qword ptr [rsp+8],rcx
  000000000000000A: 53                 push        rbx
  000000000000000B: 56                 push        rsi
  000000000000000C: 57                 push        rdi
  000000000000000D: 41 56              push        r14
  000000000000000F: 48 83 EC 38        sub         rsp,38h
  0000000000000013: 48 C7 44 24 20 FE  mov         qword ptr [rsp+20h],0FFFFFFFFFFFFFFFEh
  000000000000001C: 48 8B F9           mov         rdi,rcx
  000000000000001F: 48 83 FA FE        cmp         rdx,0FFFFFFFFFFFFFFFEh
  0000000000000023: 76 06              jbe         000000000000002B
  0000000000000000: 48 83 EC 28        sub         rsp,28h
  0000000000000004: 48 8D 0D 00 00 00  lea         rcx,[??_C@_0BA@JFNIOLAK@string?5too?5long?$AA@]
  000000000000000B: E8 00 00 00 00     call        ?_Xlength_error@std@@YAXPEBD@Z
  0000000000000010: CC                 int         3
  000000000000002A: CC                 int         3
  000000000000002B: 4C 8B 71 18        mov         r14,qword ptr [rcx+18h]
  000000000000002F: 4C 89 74 24 70     mov         qword ptr [rsp+70h],r14
  0000000000000034: 48 8B DA           mov         rbx,rdx
  0000000000000037: 48 83 CB 0F        or          rbx,0Fh
  000000000000003B: 48 83 FB FE        cmp         rbx,0FFFFFFFFFFFFFFFEh
  000000000000003F: 76 05              jbe         0000000000000046
  0000000000000041: 48 8B DA           mov         rbx,rdx
  0000000000000044: EB 31              jmp         0000000000000077
  0000000000000046: 49 8B CE           mov         rcx,r14
  0000000000000049: 48 D1 E9           shr         rcx,1
  000000000000004C: 48 B8 AB AA AA AA  mov         rax,0AAAAAAAAAAAAAAABh
  0000000000000056: 48 F7 E3           mul         rax,rbx
  0000000000000059: 48 D1 EA           shr         rdx,1
  000000000000005C: 48 3B CA           cmp         rcx,rdx
  000000000000005F: 76 16              jbe         0000000000000077
  0000000000000061: 48 C7 C3 FE FF FF  mov         rbx,0FFFFFFFFFFFFFFFEh
  0000000000000068: 48 8B C3           mov         rax,rbx
  000000000000006B: 48 2B C1           sub         rax,rcx
  000000000000006E: 4C 3B F0           cmp         r14,rax
  0000000000000071: 77 04              ja          0000000000000077
  0000000000000073: 4A 8D 1C 31        lea         rbx,[rcx+r14]
  0000000000000077: 48 8D 4B 01        lea         rcx,[rbx+1]
  000000000000007B: 48 85 C9           test        rcx,rcx
  000000000000007E: 75 04              jne         0000000000000084
  0000000000000080: 33 F6              xor         esi,esi
  0000000000000082: EB 4B              jmp         00000000000000CF
  0000000000000084: 48 81 F9 00 10 00  cmp         rcx,1000h
  000000000000008B: 72 2F              jb          00000000000000BC
  000000000000008D: 48 8D 41 27        lea         rax,[rcx+27h]
  0000000000000091: 48 3B C1           cmp         rax,rcx
  0000000000000094: 77 05              ja          000000000000009B
  0000000000000096: E8 00 00 00 00     call        ?_Xbad_alloc@std@@YAXXZ
  000000000000009B: 48 8B C8           mov         rcx,rax
  000000000000009E: E8 00 00 00 00     call        ??2@YAPEAX_K@Z
  00000000000000A3: 48 85 C0           test        rax,rax
  00000000000000A6: 75 06              jne         00000000000000AE
  00000000000000A8: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  00000000000000AD: CC                 int         3
  00000000000000AE: 48 8D 70 27        lea         rsi,[rax+27h]
  00000000000000B2: 48 83 E6 E0        and         rsi,0FFFFFFFFFFFFFFE0h
  00000000000000B6: 48 89 46 F8        mov         qword ptr [rsi-8],rax
  00000000000000BA: EB 13              jmp         00000000000000CF
  00000000000000BC: E8 00 00 00 00     call        ??2@YAPEAX_K@Z
  00000000000000C1: 48 8B F0           mov         rsi,rax
  00000000000000C4: 48 85 C0           test        rax,rax
  00000000000000C7: 75 06              jne         00000000000000CF
  00000000000000C9: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  00000000000000CE: 90                 nop
  00000000000000CF: EB 14              jmp         00000000000000E5
  00000000000000B2: 48 83 7B 18 10     cmp         qword ptr [rbx+18h],10h
  00000000000000B7: 72 05              jb          00000000000000BE
  00000000000000B9: 48 8B 0B           mov         rcx,qword ptr [rbx]
  00000000000000BC: EB 03              jmp         00000000000000C1
  00000000000000BE: 48 8B CB           mov         rcx,rbx
  00000000000000C1: 4C 8B C7           mov         r8,rdi
  00000000000000C4: 48 8B D6           mov         rdx,rsi
  00000000000000C7: E8 00 00 00 00     call        memcpy
  00000000000000CC: 48 83 7B 18 10     cmp         qword ptr [rbx+18h],10h
  00000000000000D1: 48 89 7B 10        mov         qword ptr [rbx+10h],rdi
  00000000000000D5: 72 05              jb          00000000000000DC
  00000000000000D7: 48 8B 03           mov         rax,qword ptr [rbx]
  00000000000000DA: EB 03              jmp         00000000000000DF
  00000000000000DC: 48 8B C3           mov         rax,rbx
  00000000000000DF: 48 8B 74 24 38     mov         rsi,qword ptr [rsp+38h]
  00000000000000E4: C6 04 38 00        mov         byte ptr [rax+rdi],0
  00000000000000E8: 48 8B C3           mov         rax,rbx
  00000000000000EB: 48 8B 5C 24 30     mov         rbx,qword ptr [rsp+30h]
  00000000000000F0: 48 83 C4 20        add         rsp,20h
  00000000000000F4: 5F                 pop         rdi
  00000000000000F5: C3                 ret
  0000000000000045: 90                 nop
  0000000000000046: 0F 10 03           movups      xmm0,xmmword ptr [rbx]
  0000000000000049: 0F 29 44 24 30     movaps      xmmword ptr [rsp+30h],xmm0
  000000000000004E: 4C 8D 44 24 40     lea         r8,[rsp+40h]
  0000000000000053: 48 8D 54 24 30     lea         rdx,[rsp+30h]
  0000000000000058: 48 8B CF           mov         rcx,rdi
  0000000000000000: 48 89 5C 24 10     mov         qword ptr [rsp+10h],rbx
  0000000000000005: 57                 push        rdi
  0000000000000006: 48 83 EC 70        sub         rsp,70h
  000000000000000A: 49 8B C0           mov         rax,r8
  000000000000000D: 48 C7 44 24 40 00  mov         qword ptr [rsp+40h],0
  0000000000000016: 48 8B FA           mov         rdi,rdx
  0000000000000019: 48 C7 44 24 48 0F  mov         qword ptr [rsp+48h],0Fh
  0000000000000022: 48 8B D9           mov         rbx,rcx
  0000000000000025: C6 44 24 30 00     mov         byte ptr [rsp+30h],0
  000000000000002A: 48 8B D0           mov         rdx,rax
  000000000000002D: 48 8D 4C 24 30     lea         rcx,[rsp+30h]
  0000000000000032: 49 83 C9 FF        or          r9,0FFFFFFFFFFFFFFFFh
  0000000000000036: 45 33 C0           xor         r8d,r8d
  0000000000000000: 48 89 5C 24 08     mov         qword ptr [rsp+8],rbx
  0000000000000005: 48 89 74 24 10     mov         qword ptr [rsp+10h],rsi
  000000000000000A: 48 89 7C 24 18     mov         qword ptr [rsp+18h],rdi
  000000000000000F: 41 56              push        r14
  0000000000000011: 48 83 EC 20        sub         rsp,20h
  0000000000000015: 48 8B 42 10        mov         rax,qword ptr [rdx+10h]
  0000000000000019: 49 8B F9           mov         rdi,r9
  000000000000001C: 4D 8B F0           mov         r14,r8
  000000000000001F: 48 8B F2           mov         rsi,rdx
  0000000000000022: 48 8B D9           mov         rbx,rcx
  0000000000000025: 49 3B C0           cmp         rax,r8
  0000000000000028: 0F 82 BE 00 00 00  jb          00000000000000EC
  000000000000002E: 49 2B C0           sub         rax,r8
  0000000000000031: 49 3B C1           cmp         rax,r9
  0000000000000034: 48 0F 42 F8        cmovb       rdi,rax
  0000000000000038: 48 3B CA           cmp         rcx,rdx
  000000000000003B: 75 2C              jne         0000000000000069
  000000000000003D: 49 8D 04 38        lea         rax,[r8+rdi]
  0000000000000041: 48 39 41 10        cmp         qword ptr [rcx+10h],rax
  0000000000000045: 0F 82 A7 00 00 00  jb          00000000000000F2
  000000000000004B: 48 89 41 10        mov         qword ptr [rcx+10h],rax
  000000000000004F: 48 83 79 18 10     cmp         qword ptr [rcx+18h],10h
  0000000000000054: 72 03              jb          0000000000000059
  0000000000000056: 48 8B 09           mov         rcx,qword ptr [rcx]
  0000000000000059: C6 04 01 00        mov         byte ptr [rcx+rax],0
  000000000000005D: 33 D2              xor         edx,edx
  000000000000005F: 48 8B CB           mov         rcx,rbx
  0000000000000000: 48 89 5C 24 08     mov         qword ptr [rsp+8],rbx
  0000000000000005: 57                 push        rdi
  0000000000000006: 48 83 EC 20        sub         rsp,20h
  000000000000000A: 48 8B 79 10        mov         rdi,qword ptr [rcx+10h]
  000000000000000E: 4D 8B C8           mov         r9,r8
  0000000000000011: 48 8B D9           mov         rbx,rcx
  0000000000000014: 48 3B FA           cmp         rdi,rdx
  0000000000000017: 0F 82 9C 00 00 00  jb          00000000000000B9
  000000000000001D: 48 8B C7           mov         rax,rdi
  0000000000000020: 48 2B C2           sub         rax,rdx
  0000000000000023: 49 3B C0           cmp         rax,r8
  0000000000000026: 77 32              ja          000000000000005A
  0000000000000028: 48 89 51 10        mov         qword ptr [rcx+10h],rdx
  000000000000002C: 48 83 79 18 10     cmp         qword ptr [rcx+18h],10h
  0000000000000031: 72 15              jb          0000000000000048
  0000000000000033: 48 8B 01           mov         rax,qword ptr [rcx]
  0000000000000036: C6 04 10 00        mov         byte ptr [rax+rdx],0
  000000000000003A: 48 8B C1           mov         rax,rcx
  000000000000003D: 48 8B 5C 24 30     mov         rbx,qword ptr [rsp+30h]
  0000000000000042: 48 83 C4 20        add         rsp,20h
  0000000000000046: 5F                 pop         rdi
  0000000000000047: C3                 ret
  0000000000000048: 48 8B C3           mov         rax,rbx
  000000000000004B: C6 04 13 00        mov         byte ptr [rbx+rdx],0
  000000000000004F: 48 8B 5C 24 30     mov         rbx,qword ptr [rsp+30h]
  0000000000000054: 48 83 C4 20        add         rsp,20h
  0000000000000058: 5F                 pop         rdi
  0000000000000059: C3                 ret
  000000000000005A: 4D 85 C9           test        r9,r9
  000000000000005D: 74 4C              je          00000000000000AB
  000000000000005F: 48 83 79 18 10     cmp         qword ptr [rcx+18h],10h
  0000000000000064: 72 05              jb          000000000000006B
  0000000000000066: 48 8B 01           mov         rax,qword ptr [rcx]
  0000000000000069: EB 03              jmp         000000000000006E
  000000000000006B: 48 8B C3           mov         rax,rbx
  000000000000006E: 49 2B F9           sub         rdi,r9
  0000000000000071: 48 8D 0C 10        lea         rcx,[rax+rdx]
  0000000000000075: 4C 8B C7           mov         r8,rdi
  0000000000000078: 4C 2B C2           sub         r8,rdx
  000000000000007B: 4A 8D 14 09        lea         rdx,[rcx+r9]
  000000000000007F: E8 00 00 00 00     call        memmove
  0000000000000084: 48 83 7B 18 10     cmp         qword ptr [rbx+18h],10h
  0000000000000089: 48 89 7B 10        mov         qword ptr [rbx+10h],rdi
  000000000000008D: 72 15              jb          00000000000000A4
  000000000000008F: 48 8B 03           mov         rax,qword ptr [rbx]
  0000000000000092: C6 04 38 00        mov         byte ptr [rax+rdi],0
  0000000000000096: 48 8B C3           mov         rax,rbx
  0000000000000099: 48 8B 5C 24 30     mov         rbx,qword ptr [rsp+30h]
  000000000000009E: 48 83 C4 20        add         rsp,20h
  00000000000000A2: 5F                 pop         rdi
  00000000000000A3: C3                 ret
  00000000000000A4: 48 8B C3           mov         rax,rbx
  00000000000000A7: C6 04 3B 00        mov         byte ptr [rbx+rdi],0
  00000000000000AB: 48 8B C3           mov         rax,rbx
  00000000000000AE: 48 8B 5C 24 30     mov         rbx,qword ptr [rsp+30h]
  00000000000000B3: 48 83 C4 20        add         rsp,20h
  00000000000000B7: 5F                 pop         rdi
  00000000000000B8: C3                 ret
  0000000000000000: 48 83 EC 28        sub         rsp,28h
  0000000000000004: 48 8D 0D 00 00 00  lea         rcx,[??_C@_0BI@CFPLBAOH@invalid?5string?5position?$AA@]
  000000000000000B: E8 00 00 00 00     call        ?_Xout_of_range@std@@YAXPEBD@Z
  0000000000000010: CC                 int         3
  00000000000000BE: CC                 int         3
  0000000000000067: EB 6A              jmp         00000000000000D3
  0000000000000069: 48 85 FF           test        rdi,rdi
  000000000000006C: 75 1B              jne         0000000000000089
  000000000000006E: 48 83 79 18 10     cmp         qword ptr [rcx+18h],10h
  0000000000000073: 48 89 79 10        mov         qword ptr [rcx+10h],rdi
  0000000000000077: 72 08              jb          0000000000000081
  0000000000000079: 48 8B 01           mov         rax,qword ptr [rcx]
  000000000000007C: 40 88 38           mov         byte ptr [rax],dil
  000000000000007F: EB 52              jmp         00000000000000D3
  0000000000000081: 48 8B C3           mov         rax,rbx
  0000000000000084: C6 03 00           mov         byte ptr [rbx],0
  0000000000000087: EB 4A              jmp         00000000000000D3
  0000000000000089: 48 39 79 18        cmp         qword ptr [rcx+18h],rdi
  000000000000008D: 73 08              jae         0000000000000097
  000000000000008F: 48 8B D7           mov         rdx,rdi
  0000000000000092: E8 00 00 00 00     call        ?_Copy@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAX_K@Z
  0000000000000097: 48 83 7E 18 10     cmp         qword ptr [rsi+18h],10h
  000000000000009C: 72 03              jb          00000000000000A1
  000000000000009E: 48 8B 36           mov         rsi,qword ptr [rsi]
  00000000000000A1: 48 83 7B 18 10     cmp         qword ptr [rbx+18h],10h
  00000000000000A6: 72 05              jb          00000000000000AD
  00000000000000A8: 48 8B 0B           mov         rcx,qword ptr [rbx]
  00000000000000AB: EB 03              jmp         00000000000000B0
  00000000000000AD: 48 8B CB           mov         rcx,rbx
  00000000000000B0: 4A 8D 14 36        lea         rdx,[rsi+r14]
  00000000000000B4: 4C 8B C7           mov         r8,rdi
  00000000000000B7: E8 00 00 00 00     call        memcpy
  00000000000000BC: 48 83 7B 18 10     cmp         qword ptr [rbx+18h],10h
  00000000000000C1: 48 89 7B 10        mov         qword ptr [rbx+10h],rdi
  00000000000000C5: 72 05              jb          00000000000000CC
  00000000000000C7: 48 8B 03           mov         rax,qword ptr [rbx]
  00000000000000CA: EB 03              jmp         00000000000000CF
  00000000000000CC: 48 8B C3           mov         rax,rbx
  00000000000000CF: C6 04 38 00        mov         byte ptr [rax+rdi],0
  00000000000000D3: 48 8B 74 24 38     mov         rsi,qword ptr [rsp+38h]
  00000000000000D8: 48 8B C3           mov         rax,rbx
  00000000000000DB: 48 8B 5C 24 30     mov         rbx,qword ptr [rsp+30h]
  00000000000000E0: 48 8B 7C 24 40     mov         rdi,qword ptr [rsp+40h]
  00000000000000E5: 48 83 C4 20        add         rsp,20h
  00000000000000E9: 41 5E              pop         r14
  00000000000000EB: C3                 ret
  00000000000000EC: E8 00 00 00 00     call        ?_Xran@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@SAXXZ
  00000000000000F1: CC                 int         3
  00000000000000F2: E8 00 00 00 00     call        ?_Xran@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@SAXXZ
  00000000000000F7: CC                 int         3
  000000000000003E: 0F 10 07           movups      xmm0,xmmword ptr [rdi]
  0000000000000041: 4C 8D 44 24 30     lea         r8,[rsp+30h]
  0000000000000046: 48 8D 54 24 20     lea         rdx,[rsp+20h]
  000000000000004B: 48 8D 4C 24 50     lea         rcx,[rsp+50h]
  0000000000000050: 0F 29 44 24 20     movaps      xmmword ptr [rsp+20h],xmm0
  0000000000000000: 4C 89 44 24 18     mov         qword ptr [rsp+18h],r8
  0000000000000005: 57                 push        rdi
  0000000000000006: 48 83 EC 50        sub         rsp,50h
  000000000000000A: 48 C7 44 24 28 FE  mov         qword ptr [rsp+28h],0FFFFFFFFFFFFFFFEh
  0000000000000013: 48 89 5C 24 60     mov         qword ptr [rsp+60h],rbx
  0000000000000018: 48 89 6C 24 68     mov         qword ptr [rsp+68h],rbp
  000000000000001D: 48 89 74 24 78     mov         qword ptr [rsp+78h],rsi
  0000000000000022: 49 8B D8           mov         rbx,r8
  0000000000000025: 48 8B F2           mov         rsi,rdx
  0000000000000028: 48 8B F9           mov         rdi,rcx
  000000000000002B: 33 ED              xor         ebp,ebp
  000000000000002D: 89 6C 24 20        mov         dword ptr [rsp+20h],ebp
  0000000000000031: 49 39 68 10        cmp         qword ptr [r8+10h],rbp
  0000000000000035: 74 13              je          000000000000004A
  0000000000000037: 44 8D 45 02        lea         r8d,[rbp+2]
  000000000000003B: 48 8D 15 00 00 00  lea         rdx,[??_C@_02LMMGGCAJ@?3?5?$AA@]
  0000000000000042: 48 8B CB           mov         rcx,rbx
  0000000000000000: 48 89 5C 24 10     mov         qword ptr [rsp+10h],rbx
  0000000000000005: 48 89 6C 24 18     mov         qword ptr [rsp+18h],rbp
  000000000000000A: 56                 push        rsi
  000000000000000B: 48 83 EC 20        sub         rsp,20h
  000000000000000F: 48 8B F2           mov         rsi,rdx
  0000000000000012: 49 8B E8           mov         rbp,r8
  0000000000000015: 48 8B 51 18        mov         rdx,qword ptr [rcx+18h]
  0000000000000019: 48 8B D9           mov         rbx,rcx
  000000000000001C: 48 83 FA 10        cmp         rdx,10h
  0000000000000020: 72 03              jb          0000000000000025
  0000000000000022: 48 8B 09           mov         rcx,qword ptr [rcx]
  0000000000000025: 48 3B CE           cmp         rcx,rsi
  0000000000000028: 77 3A              ja          0000000000000064
  000000000000002A: 48 03 4B 10        add         rcx,qword ptr [rbx+10h]
  000000000000002E: 48 3B F1           cmp         rsi,rcx
  0000000000000031: 73 31              jae         0000000000000064
  0000000000000033: 48 83 FA 10        cmp         rdx,10h
  0000000000000037: 72 05              jb          000000000000003E
  0000000000000039: 48 8B 03           mov         rax,qword ptr [rbx]
  000000000000003C: EB 03              jmp         0000000000000041
  000000000000003E: 48 8B C3           mov         rax,rbx
  0000000000000041: 48 2B F0           sub         rsi,rax
  0000000000000044: 4C 8B CD           mov         r9,rbp
  0000000000000047: 4C 8B C6           mov         r8,rsi
  000000000000004A: 48 8B D3           mov         rdx,rbx
  000000000000004D: 48 8B CB           mov         rcx,rbx
  0000000000000050: 48 8B 5C 24 38     mov         rbx,qword ptr [rsp+38h]
  0000000000000055: 48 8B 6C 24 40     mov         rbp,qword ptr [rsp+40h]
  000000000000005A: 48 83 C4 20        add         rsp,20h
  000000000000005E: 5E                 pop         rsi
  000000000000005F: E9 00 00 00 00     jmp         ?append@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAAEAV12@AEBV12@_K_K@Z
  0000000000000064: 48 8B 4B 10        mov         rcx,qword ptr [rbx+10h]
  0000000000000068: 48 8B C1           mov         rax,rcx
  000000000000006B: 48 F7 D0           not         rax
  000000000000006E: 48 3B C5           cmp         rax,rbp
  0000000000000071: 0F 86 8A 00 00 00  jbe         0000000000000101
  0000000000000077: 48 89 7C 24 30     mov         qword ptr [rsp+30h],rdi
  000000000000007C: 4A 8D 3C 01        lea         rdi,[rcx+r8]
  0000000000000080: 48 85 ED           test        rbp,rbp
  0000000000000083: 74 64              je          00000000000000E9
  0000000000000085: 48 85 FF           test        rdi,rdi
  0000000000000088: 75 1A              jne         00000000000000A4
  000000000000008A: 48 89 7B 10        mov         qword ptr [rbx+10h],rdi
  000000000000008E: 48 83 FA 10        cmp         rdx,10h
  0000000000000092: 72 08              jb          000000000000009C
  0000000000000094: 48 8B 03           mov         rax,qword ptr [rbx]
  0000000000000097: 40 88 38           mov         byte ptr [rax],dil
  000000000000009A: EB 4D              jmp         00000000000000E9
  000000000000009C: 48 8B C3           mov         rax,rbx
  000000000000009F: C6 03 00           mov         byte ptr [rbx],0
  00000000000000A2: EB 45              jmp         00000000000000E9
  00000000000000A4: 48 3B D7           cmp         rdx,rdi
  00000000000000A7: 73 0B              jae         00000000000000B4
  00000000000000A9: 48 8B D7           mov         rdx,rdi
  00000000000000AC: 48 8B CB           mov         rcx,rbx
  00000000000000AF: E8 00 00 00 00     call        ?_Copy@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAX_K@Z
  00000000000000B4: 48 83 7B 18 10     cmp         qword ptr [rbx+18h],10h
  00000000000000B9: 72 05              jb          00000000000000C0
  00000000000000BB: 48 8B 0B           mov         rcx,qword ptr [rbx]
  00000000000000BE: EB 03              jmp         00000000000000C3
  00000000000000C0: 48 8B CB           mov         rcx,rbx
  00000000000000C3: 48 03 4B 10        add         rcx,qword ptr [rbx+10h]
  00000000000000C7: 4C 8B C5           mov         r8,rbp
  00000000000000CA: 48 8B D6           mov         rdx,rsi
  00000000000000CD: E8 00 00 00 00     call        memcpy
  00000000000000D2: 48 83 7B 18 10     cmp         qword ptr [rbx+18h],10h
  00000000000000D7: 48 89 7B 10        mov         qword ptr [rbx+10h],rdi
  00000000000000DB: 72 05              jb          00000000000000E2
  00000000000000DD: 48 8B 03           mov         rax,qword ptr [rbx]
  00000000000000E0: EB 03              jmp         00000000000000E5
  00000000000000E2: 48 8B C3           mov         rax,rbx
  00000000000000E5: C6 04 38 00        mov         byte ptr [rax+rdi],0
  00000000000000E9: 48 8B 7C 24 30     mov         rdi,qword ptr [rsp+30h]
  00000000000000EE: 48 8B C3           mov         rax,rbx
  00000000000000F1: 48 8B 5C 24 38     mov         rbx,qword ptr [rsp+38h]
  00000000000000F6: 48 8B 6C 24 40     mov         rbp,qword ptr [rsp+40h]
  00000000000000FB: 48 83 C4 20        add         rsp,20h
  00000000000000FF: 5E                 pop         rsi
  0000000000000100: C3                 ret
  0000000000000101: E8 00 00 00 00     call        ?_Xlen@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@SAXXZ
  0000000000000106: CC                 int         3
  000000000000004A: 48 8D 54 24 30     lea         rdx,[rsp+30h]
  000000000000004F: 48 8B CE           mov         rcx,rsi
  0000000000000000: 40 53              push        rbx
  0000000000000002: 48 83 EC 30        sub         rsp,30h
  0000000000000006: 44 8B 01           mov         r8d,dword ptr [rcx]
  0000000000000009: 48 8B DA           mov         rbx,rdx
  000000000000000C: 48 8B 49 08        mov         rcx,qword ptr [rcx+8]
  0000000000000010: C7 44 24 20 00 00  mov         dword ptr [rsp+20h],0
  0000000000000018: 48 8B 01           mov         rax,qword ptr [rcx]
  000000000000001B: FF 50 10           call        qword ptr [rax+10h]
  000000000000001E: 48 8B C3           mov         rax,rbx
  0000000000000021: 48 83 C4 30        add         rsp,30h
  0000000000000025: 5B                 pop         rbx
  0000000000000026: C3                 ret
  0000000000000057: 90                 nop
  0000000000000058: 49 83 C9 FF        or          r9,0FFFFFFFFFFFFFFFFh
  000000000000005C: 45 33 C0           xor         r8d,r8d
  000000000000005F: 48 8B D0           mov         rdx,rax
  0000000000000062: 48 8B CB           mov         rcx,rbx
  0000000000000000: 48 89 5C 24 10     mov         qword ptr [rsp+10h],rbx
  0000000000000005: 48 89 6C 24 18     mov         qword ptr [rsp+18h],rbp
  000000000000000A: 48 89 74 24 20     mov         qword ptr [rsp+20h],rsi
  000000000000000F: 41 56              push        r14
  0000000000000011: 48 83 EC 20        sub         rsp,20h
  0000000000000015: 48 8B 42 10        mov         rax,qword ptr [rdx+10h]
  0000000000000019: 49 8B F1           mov         rsi,r9
  000000000000001C: 49 8B E8           mov         rbp,r8
  000000000000001F: 4C 8B F2           mov         r14,rdx
  0000000000000022: 48 8B D9           mov         rbx,rcx
  0000000000000025: 49 3B C0           cmp         rax,r8
  0000000000000028: 0F 82 BA 00 00 00  jb          00000000000000E8
  000000000000002E: 48 8B 49 10        mov         rcx,qword ptr [rcx+10h]
  0000000000000032: 49 2B C0           sub         rax,r8
  0000000000000035: 49 3B C1           cmp         rax,r9
  0000000000000038: 48 0F 42 F0        cmovb       rsi,rax
  000000000000003C: 48 8B C1           mov         rax,rcx
  000000000000003F: 48 F7 D0           not         rax
  0000000000000042: 48 3B C6           cmp         rax,rsi
  0000000000000045: 0F 86 A3 00 00 00  jbe         00000000000000EE
  000000000000004B: 48 89 7C 24 30     mov         qword ptr [rsp+30h],rdi
  0000000000000050: 48 8D 3C 31        lea         rdi,[rcx+rsi]
  0000000000000054: 48 85 F6           test        rsi,rsi
  0000000000000057: 74 71              je          00000000000000CA
  0000000000000059: 48 85 FF           test        rdi,rdi
  000000000000005C: 75 1B              jne         0000000000000079
  000000000000005E: 48 89 7B 10        mov         qword ptr [rbx+10h],rdi
  0000000000000062: 48 83 7B 18 10     cmp         qword ptr [rbx+18h],10h
  0000000000000067: 72 08              jb          0000000000000071
  0000000000000069: 48 8B 03           mov         rax,qword ptr [rbx]
  000000000000006C: 40 88 38           mov         byte ptr [rax],dil
  000000000000006F: EB 59              jmp         00000000000000CA
  0000000000000071: 48 8B C3           mov         rax,rbx
  0000000000000074: C6 03 00           mov         byte ptr [rbx],0
  0000000000000077: EB 51              jmp         00000000000000CA
  0000000000000079: 48 39 7B 18        cmp         qword ptr [rbx+18h],rdi
  000000000000007D: 73 0B              jae         000000000000008A
  000000000000007F: 48 8B D7           mov         rdx,rdi
  0000000000000082: 48 8B CB           mov         rcx,rbx
  0000000000000085: E8 00 00 00 00     call        ?_Copy@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAX_K@Z
  000000000000008A: 49 83 7E 18 10     cmp         qword ptr [r14+18h],10h
  000000000000008F: 72 03              jb          0000000000000094
  0000000000000091: 4D 8B 36           mov         r14,qword ptr [r14]
  0000000000000094: 48 83 7B 18 10     cmp         qword ptr [rbx+18h],10h
  0000000000000099: 72 05              jb          00000000000000A0
  000000000000009B: 48 8B 0B           mov         rcx,qword ptr [rbx]
  000000000000009E: EB 03              jmp         00000000000000A3
  00000000000000A0: 48 8B CB           mov         rcx,rbx
  00000000000000A3: 48 03 4B 10        add         rcx,qword ptr [rbx+10h]
  00000000000000A7: 49 8D 14 2E        lea         rdx,[r14+rbp]
  00000000000000AB: 4C 8B C6           mov         r8,rsi
  00000000000000AE: E8 00 00 00 00     call        memcpy
  00000000000000B3: 48 83 7B 18 10     cmp         qword ptr [rbx+18h],10h
  00000000000000B8: 48 89 7B 10        mov         qword ptr [rbx+10h],rdi
  00000000000000BC: 72 05              jb          00000000000000C3
  00000000000000BE: 48 8B 03           mov         rax,qword ptr [rbx]
  00000000000000C1: EB 03              jmp         00000000000000C6
  00000000000000C3: 48 8B C3           mov         rax,rbx
  00000000000000C6: C6 04 38 00        mov         byte ptr [rax+rdi],0
  00000000000000CA: 48 8B 7C 24 30     mov         rdi,qword ptr [rsp+30h]
  00000000000000CF: 48 8B C3           mov         rax,rbx
  00000000000000D2: 48 8B 5C 24 38     mov         rbx,qword ptr [rsp+38h]
  00000000000000D7: 48 8B 6C 24 40     mov         rbp,qword ptr [rsp+40h]
  00000000000000DC: 48 8B 74 24 48     mov         rsi,qword ptr [rsp+48h]
  00000000000000E1: 48 83 C4 20        add         rsp,20h
  00000000000000E5: 41 5E              pop         r14
  00000000000000E7: C3                 ret
  00000000000000E8: E8 00 00 00 00     call        ?_Xran@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@SAXXZ
  00000000000000ED: CC                 int         3
  00000000000000EE: E8 00 00 00 00     call        ?_Xlen@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@SAXXZ
  00000000000000F3: CC                 int         3
  000000000000006A: 90                 nop
  000000000000006B: 48 8B 44 24 48     mov         rax,qword ptr [rsp+48h]
  0000000000000070: 48 83 F8 10        cmp         rax,10h
  0000000000000074: 72 4D              jb          00000000000000C3
  0000000000000076: 48 FF C0           inc         rax
  0000000000000079: 48 8B 4C 24 30     mov         rcx,qword ptr [rsp+30h]
  000000000000007E: 48 3D 00 10 00 00  cmp         rax,1000h
  0000000000000084: 72 38              jb          00000000000000BE
  0000000000000086: F6 C1 1F           test        cl,1Fh
  0000000000000089: 74 06              je          0000000000000091
  000000000000008B: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000090: CC                 int         3
  0000000000000091: 48 8B 41 F8        mov         rax,qword ptr [rcx-8]
  0000000000000095: 48 3B C1           cmp         rax,rcx
  0000000000000098: 72 06              jb          00000000000000A0
  000000000000009A: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  000000000000009F: CC                 int         3
  00000000000000A0: 48 2B C8           sub         rcx,rax
  00000000000000A3: 48 83 F9 08        cmp         rcx,8
  00000000000000A7: 73 06              jae         00000000000000AF
  00000000000000A9: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  00000000000000AE: CC                 int         3
  00000000000000AF: 48 83 F9 27        cmp         rcx,27h
  00000000000000B3: 76 06              jbe         00000000000000BB
  00000000000000B5: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  00000000000000BA: CC                 int         3
  00000000000000BB: 48 8B C8           mov         rcx,rax
  00000000000000BE: E8 00 00 00 00     call        ??3@YAXPEAX@Z
  00000000000000C3: 48 89 6F 10        mov         qword ptr [rdi+10h],rbp
  00000000000000C7: 48 89 6F 18        mov         qword ptr [rdi+18h],rbp
  00000000000000CB: 0F 10 03           movups      xmm0,xmmword ptr [rbx]
  00000000000000CE: 0F 11 07           movups      xmmword ptr [rdi],xmm0
  00000000000000D1: 0F 10 4B 10        movups      xmm1,xmmword ptr [rbx+10h]
  00000000000000D5: 0F 11 4F 10        movups      xmmword ptr [rdi+10h],xmm1
  00000000000000D9: 48 89 6B 10        mov         qword ptr [rbx+10h],rbp
  00000000000000DD: 48 C7 43 18 0F 00  mov         qword ptr [rbx+18h],0Fh
  00000000000000E5: C6 03 00           mov         byte ptr [rbx],0
  00000000000000E8: 48 8B CB           mov         rcx,rbx
  0000000000000000: 40 53              push        rbx
  0000000000000002: 48 83 EC 20        sub         rsp,20h
  0000000000000006: 48 8B 41 18        mov         rax,qword ptr [rcx+18h]
  000000000000000A: 48 8B D9           mov         rbx,rcx
  000000000000000D: 48 83 F8 10        cmp         rax,10h
  0000000000000011: 72 33              jb          0000000000000046
  0000000000000013: 48 8B 09           mov         rcx,qword ptr [rcx]
  0000000000000016: 48 FF C0           inc         rax
  0000000000000019: 48 3D 00 10 00 00  cmp         rax,1000h
  000000000000001F: 72 20              jb          0000000000000041
  0000000000000021: F6 C1 1F           test        cl,1Fh
  0000000000000024: 75 39              jne         000000000000005F
  0000000000000026: 48 8B 41 F8        mov         rax,qword ptr [rcx-8]
  000000000000002A: 48 3B C1           cmp         rax,rcx
  000000000000002D: 73 36              jae         0000000000000065
  000000000000002F: 48 2B C8           sub         rcx,rax
  0000000000000032: 48 83 F9 08        cmp         rcx,8
  0000000000000036: 72 33              jb          000000000000006B
  0000000000000038: 48 83 F9 27        cmp         rcx,27h
  000000000000003C: 77 33              ja          0000000000000071
  000000000000003E: 48 8B C8           mov         rcx,rax
  0000000000000041: E8 00 00 00 00     call        ??3@YAXPEAX@Z
  0000000000000046: 48 C7 43 10 00 00  mov         qword ptr [rbx+10h],0
  000000000000004E: 48 C7 43 18 0F 00  mov         qword ptr [rbx+18h],0Fh
  0000000000000056: C6 03 00           mov         byte ptr [rbx],0
  0000000000000059: 48 83 C4 20        add         rsp,20h
  000000000000005D: 5B                 pop         rbx
  000000000000005E: C3                 ret
  000000000000005F: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000064: CC                 int         3
  0000000000000065: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  000000000000006A: CC                 int         3
  000000000000006B: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000070: CC                 int         3
  0000000000000071: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000076: CC                 int         3
  00000000000000F0: 48 8B C7           mov         rax,rdi
  00000000000000F3: 48 8B 5C 24 60     mov         rbx,qword ptr [rsp+60h]
  00000000000000F8: 48 8B 6C 24 68     mov         rbp,qword ptr [rsp+68h]
  00000000000000FD: 48 8B 74 24 78     mov         rsi,qword ptr [rsp+78h]
  0000000000000102: 48 83 C4 50        add         rsp,50h
  0000000000000106: 5F                 pop         rdi
  0000000000000107: C3                 ret
  000000000000005A: 48 83 78 18 10     cmp         qword ptr [rax+18h],10h
  000000000000005F: 72 03              jb          0000000000000064
  0000000000000061: 48 8B 00           mov         rax,qword ptr [rax]
  0000000000000064: 48 8D 53 08        lea         rdx,[rbx+8]
  0000000000000068: 48 89 44 24 20     mov         qword ptr [rsp+20h],rax
  000000000000006D: 48 8D 0D 00 00 00  lea         rcx,[??_7exception@std@@6B@]
  0000000000000074: C6 44 24 28 01     mov         byte ptr [rsp+28h],1
  0000000000000079: 48 89 0B           mov         qword ptr [rbx],rcx
  000000000000007C: 33 C9              xor         ecx,ecx
  000000000000007E: 48 89 0A           mov         qword ptr [rdx],rcx
  0000000000000081: 48 89 4A 08        mov         qword ptr [rdx+8],rcx
  0000000000000085: 48 8D 4C 24 20     lea         rcx,[rsp+20h]
  000000000000008A: E8 00 00 00 00     call        __std_exception_copy
  000000000000008F: 48 8D 05 00 00 00  lea         rax,[??_7runtime_error@std@@6B@]
  0000000000000096: 48 89 03           mov         qword ptr [rbx],rax
  0000000000000099: 48 8B 44 24 68     mov         rax,qword ptr [rsp+68h]
  000000000000009E: 48 83 F8 10        cmp         rax,10h
  00000000000000A2: 72 35              jb          00000000000000D9
  00000000000000A4: 48 8B 4C 24 50     mov         rcx,qword ptr [rsp+50h]
  00000000000000A9: 48 FF C0           inc         rax
  00000000000000AC: 48 3D 00 10 00 00  cmp         rax,1000h
  00000000000000B2: 72 20              jb          00000000000000D4
  00000000000000B4: F6 C1 1F           test        cl,1Fh
  00000000000000B7: 75 42              jne         00000000000000FB
  00000000000000B9: 48 8B 41 F8        mov         rax,qword ptr [rcx-8]
  00000000000000BD: 48 3B C1           cmp         rax,rcx
  00000000000000C0: 73 3F              jae         0000000000000101
  00000000000000C2: 48 2B C8           sub         rcx,rax
  00000000000000C5: 48 83 F9 08        cmp         rcx,8
  00000000000000C9: 72 3C              jb          0000000000000107
  00000000000000CB: 48 83 F9 27        cmp         rcx,27h
  00000000000000CF: 77 3C              ja          000000000000010D
  00000000000000D1: 48 8B C8           mov         rcx,rax
  00000000000000D4: E8 00 00 00 00     call        ??3@YAXPEAX@Z
  00000000000000D9: 48 8D 05 00 00 00  lea         rax,[??_7_System_error@std@@6B@]
  00000000000000E0: 48 89 03           mov         qword ptr [rbx],rax
  00000000000000E3: 48 8B C3           mov         rax,rbx
  00000000000000E6: 0F 10 07           movups      xmm0,xmmword ptr [rdi]
  00000000000000E9: 0F 11 43 18        movups      xmmword ptr [rbx+18h],xmm0
  00000000000000ED: 48 8B 9C 24 88 00  mov         rbx,qword ptr [rsp+88h]
  00000000000000F5: 48 83 C4 70        add         rsp,70h
  00000000000000F9: 5F                 pop         rdi
  00000000000000FA: C3                 ret
  00000000000000FB: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000100: CC                 int         3
  0000000000000101: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000106: CC                 int         3
  0000000000000107: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  000000000000010C: CC                 int         3
  000000000000010D: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000112: CC                 int         3
  0000000000000060: 90                 nop
  0000000000000061: 48 8B 44 24 58     mov         rax,qword ptr [rsp+58h]
  0000000000000066: 48 83 F8 10        cmp         rax,10h
  000000000000006A: 72 4D              jb          00000000000000B9
  000000000000006C: 48 FF C0           inc         rax
  000000000000006F: 48 8B 4C 24 40     mov         rcx,qword ptr [rsp+40h]
  0000000000000074: 48 3D 00 10 00 00  cmp         rax,1000h
  000000000000007A: 72 38              jb          00000000000000B4
  000000000000007C: F6 C1 1F           test        cl,1Fh
  000000000000007F: 74 06              je          0000000000000087
  0000000000000081: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000086: CC                 int         3
  0000000000000087: 48 8B 41 F8        mov         rax,qword ptr [rcx-8]
  000000000000008B: 48 3B C1           cmp         rax,rcx
  000000000000008E: 72 06              jb          0000000000000096
  0000000000000090: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000095: CC                 int         3
  0000000000000096: 48 2B C8           sub         rcx,rax
  0000000000000099: 48 83 F9 08        cmp         rcx,8
  000000000000009D: 73 06              jae         00000000000000A5
  000000000000009F: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  00000000000000A4: CC                 int         3
  00000000000000A5: 48 83 F9 27        cmp         rcx,27h
  00000000000000A9: 76 06              jbe         00000000000000B1
  00000000000000AB: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  00000000000000B0: CC                 int         3
  00000000000000B1: 48 8B C8           mov         rcx,rax
  00000000000000B4: E8 00 00 00 00     call        ??3@YAXPEAX@Z
  00000000000000B9: 48 8D 05 00 00 00  lea         rax,[??_7system_error@std@@6B@]
  00000000000000C0: 48 89 07           mov         qword ptr [rdi],rax
  00000000000000C3: 48 8B C7           mov         rax,rdi
  00000000000000C6: 48 8B 5C 24 70     mov         rbx,qword ptr [rsp+70h]
  00000000000000CB: 48 83 C4 60        add         rsp,60h
  00000000000000CF: 5F                 pop         rdi
  00000000000000D0: C3                 ret
  000000000000001B: 48 8D 05 00 00 00  lea         rax,[??_7monad_error@_1_0_std_std_9274c0d4@outcome@boost@@6B@]
  0000000000000022: 48 89 03           mov         qword ptr [rbx],rax
  0000000000000025: 48 8B C3           mov         rax,rbx
  0000000000000028: 48 83 C4 30        add         rsp,30h
  000000000000002C: 5B                 pop         rbx
  000000000000002D: C3                 ret
  0000000000000027: 48 8D 15 00 00 00  lea         rdx,[_TI5?AVmonad_error@_1_0_std_std_9274c0d4@outcome@boost@@]
  000000000000002E: 48 8D 4C 24 40     lea         rcx,[rsp+40h]
  0000000000000033: E8 00 00 00 00     call        _CxxThrowException
  0000000000000038: CC                 int         3
  0000000000000032: CC                 int         3
  0000000000000033: 0F 10 00           movups      xmm0,xmmword ptr [rax]
  0000000000000036: 48 8D 54 24 20     lea         rdx,[rsp+20h]
  000000000000003B: 48 8D 4C 24 50     lea         rcx,[rsp+50h]
  0000000000000040: 0F 29 44 24 20     movaps      xmmword ptr [rsp+20h],xmm0
  0000000000000000: 40 57              push        rdi
  0000000000000002: 48 83 EC 60        sub         rsp,60h
  0000000000000006: 48 C7 44 24 20 FE  mov         qword ptr [rsp+20h],0FFFFFFFFFFFFFFFEh
  000000000000000F: 48 89 5C 24 70     mov         qword ptr [rsp+70h],rbx
  0000000000000014: 48 8B DA           mov         rbx,rdx
  0000000000000017: 48 8B F9           mov         rdi,rcx
  000000000000001A: 48 C7 44 24 50 00  mov         qword ptr [rsp+50h],0
  0000000000000023: 48 C7 44 24 58 0F  mov         qword ptr [rsp+58h],0Fh
  000000000000002C: C6 44 24 40 00     mov         byte ptr [rsp+40h],0
  0000000000000031: 45 33 C0           xor         r8d,r8d
  0000000000000034: 48 8D 15 00 00 00  lea         rdx,[??_C@_00CNPNBAHC@?$AA@]
  000000000000003B: 48 8D 4C 24 40     lea         rcx,[rsp+40h]
  0000000000000000: 48 89 5C 24 08     mov         qword ptr [rsp+8],rbx
  0000000000000005: 48 89 74 24 10     mov         qword ptr [rsp+10h],rsi
  000000000000000A: 57                 push        rdi
  000000000000000B: 48 83 EC 20        sub         rsp,20h
  000000000000000F: 48 8B F2           mov         rsi,rdx
  0000000000000012: 49 8B F8           mov         rdi,r8
  0000000000000015: 48 8B 51 18        mov         rdx,qword ptr [rcx+18h]
  0000000000000019: 48 8B D9           mov         rbx,rcx
  000000000000001C: 48 83 FA 10        cmp         rdx,10h
  0000000000000020: 72 03              jb          0000000000000025
  0000000000000022: 48 8B 09           mov         rcx,qword ptr [rcx]
  0000000000000025: 48 3B CE           cmp         rcx,rsi
  0000000000000028: 77 3A              ja          0000000000000064
  000000000000002A: 48 03 4B 10        add         rcx,qword ptr [rbx+10h]
  000000000000002E: 48 3B F1           cmp         rsi,rcx
  0000000000000031: 73 31              jae         0000000000000064
  0000000000000033: 48 83 FA 10        cmp         rdx,10h
  0000000000000037: 72 05              jb          000000000000003E
  0000000000000039: 48 8B 03           mov         rax,qword ptr [rbx]
  000000000000003C: EB 03              jmp         0000000000000041
  000000000000003E: 48 8B C3           mov         rax,rbx
  0000000000000041: 48 2B F0           sub         rsi,rax
  0000000000000044: 4C 8B CF           mov         r9,rdi
  0000000000000047: 4C 8B C6           mov         r8,rsi
  000000000000004A: 48 8B D3           mov         rdx,rbx
  000000000000004D: 48 8B CB           mov         rcx,rbx
  0000000000000050: 48 8B 5C 24 30     mov         rbx,qword ptr [rsp+30h]
  0000000000000055: 48 8B 74 24 38     mov         rsi,qword ptr [rsp+38h]
  000000000000005A: 48 83 C4 20        add         rsp,20h
  000000000000005E: 5F                 pop         rdi
  000000000000005F: E9 00 00 00 00     jmp         ?assign@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAAEAV12@AEBV12@_K_K@Z
  0000000000000064: 48 85 FF           test        rdi,rdi
  0000000000000067: 75 39              jne         00000000000000A2
  0000000000000069: 48 89 7B 10        mov         qword ptr [rbx+10h],rdi
  000000000000006D: 48 83 FA 10        cmp         rdx,10h
  0000000000000071: 72 19              jb          000000000000008C
  0000000000000073: 48 8B 03           mov         rax,qword ptr [rbx]
  0000000000000076: 40 88 38           mov         byte ptr [rax],dil
  0000000000000079: 48 8B C3           mov         rax,rbx
  000000000000007C: 48 8B 5C 24 30     mov         rbx,qword ptr [rsp+30h]
  0000000000000081: 48 8B 74 24 38     mov         rsi,qword ptr [rsp+38h]
  0000000000000086: 48 83 C4 20        add         rsp,20h
  000000000000008A: 5F                 pop         rdi
  000000000000008B: C3                 ret
  000000000000008C: 48 8B C3           mov         rax,rbx
  000000000000008F: C6 03 00           mov         byte ptr [rbx],0
  0000000000000092: 48 8B 5C 24 30     mov         rbx,qword ptr [rsp+30h]
  0000000000000097: 48 8B 74 24 38     mov         rsi,qword ptr [rsp+38h]
  000000000000009C: 48 83 C4 20        add         rsp,20h
  00000000000000A0: 5F                 pop         rdi
  00000000000000A1: C3                 ret
  00000000000000A2: 48 3B D7           cmp         rdx,rdi
  00000000000000A5: 73 0B              jae         00000000000000B2
  00000000000000A7: 48 8B D7           mov         rdx,rdi
  00000000000000AA: 48 8B CB           mov         rcx,rbx
  0000000000000000: 48 89 54 24 10     mov         qword ptr [rsp+10h],rdx
  0000000000000005: 48 89 4C 24 08     mov         qword ptr [rsp+8],rcx
  000000000000000A: 53                 push        rbx
  000000000000000B: 56                 push        rsi
  000000000000000C: 57                 push        rdi
  000000000000000D: 41 56              push        r14
  000000000000000F: 48 83 EC 38        sub         rsp,38h
  0000000000000013: 48 C7 44 24 20 FE  mov         qword ptr [rsp+20h],0FFFFFFFFFFFFFFFEh
  000000000000001C: 48 8B F9           mov         rdi,rcx
  000000000000001F: 48 83 FA FE        cmp         rdx,0FFFFFFFFFFFFFFFEh
  0000000000000023: 76 06              jbe         000000000000002B
  0000000000000000: 48 83 EC 28        sub         rsp,28h
  0000000000000004: 48 8D 0D 00 00 00  lea         rcx,[??_C@_0BA@JFNIOLAK@string?5too?5long?$AA@]
  000000000000000B: E8 00 00 00 00     call        ?_Xlength_error@std@@YAXPEBD@Z
  0000000000000010: CC                 int         3
  000000000000002A: CC                 int         3
  000000000000002B: 4C 8B 71 18        mov         r14,qword ptr [rcx+18h]
  000000000000002F: 4C 89 74 24 70     mov         qword ptr [rsp+70h],r14
  0000000000000034: 48 8B DA           mov         rbx,rdx
  0000000000000037: 48 83 CB 0F        or          rbx,0Fh
  000000000000003B: 48 83 FB FE        cmp         rbx,0FFFFFFFFFFFFFFFEh
  000000000000003F: 76 05              jbe         0000000000000046
  0000000000000041: 48 8B DA           mov         rbx,rdx
  0000000000000044: EB 31              jmp         0000000000000077
  0000000000000046: 49 8B CE           mov         rcx,r14
  0000000000000049: 48 D1 E9           shr         rcx,1
  000000000000004C: 48 B8 AB AA AA AA  mov         rax,0AAAAAAAAAAAAAAABh
  0000000000000056: 48 F7 E3           mul         rax,rbx
  0000000000000059: 48 D1 EA           shr         rdx,1
  000000000000005C: 48 3B CA           cmp         rcx,rdx
  000000000000005F: 76 16              jbe         0000000000000077
  0000000000000061: 48 C7 C3 FE FF FF  mov         rbx,0FFFFFFFFFFFFFFFEh
  0000000000000068: 48 8B C3           mov         rax,rbx
  000000000000006B: 48 2B C1           sub         rax,rcx
  000000000000006E: 4C 3B F0           cmp         r14,rax
  0000000000000071: 77 04              ja          0000000000000077
  0000000000000073: 4A 8D 1C 31        lea         rbx,[rcx+r14]
  0000000000000077: 48 8D 4B 01        lea         rcx,[rbx+1]
  000000000000007B: 48 85 C9           test        rcx,rcx
  000000000000007E: 75 04              jne         0000000000000084
  0000000000000080: 33 F6              xor         esi,esi
  0000000000000082: EB 4B              jmp         00000000000000CF
  0000000000000084: 48 81 F9 00 10 00  cmp         rcx,1000h
  000000000000008B: 72 2F              jb          00000000000000BC
  000000000000008D: 48 8D 41 27        lea         rax,[rcx+27h]
  0000000000000091: 48 3B C1           cmp         rax,rcx
  0000000000000094: 77 05              ja          000000000000009B
  0000000000000096: E8 00 00 00 00     call        ?_Xbad_alloc@std@@YAXXZ
  000000000000009B: 48 8B C8           mov         rcx,rax
  000000000000009E: E8 00 00 00 00     call        ??2@YAPEAX_K@Z
  00000000000000A3: 48 85 C0           test        rax,rax
  00000000000000A6: 75 06              jne         00000000000000AE
  00000000000000A8: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  00000000000000AD: CC                 int         3
  00000000000000AE: 48 8D 70 27        lea         rsi,[rax+27h]
  00000000000000B2: 48 83 E6 E0        and         rsi,0FFFFFFFFFFFFFFE0h
  00000000000000B6: 48 89 46 F8        mov         qword ptr [rsi-8],rax
  00000000000000BA: EB 13              jmp         00000000000000CF
  00000000000000BC: E8 00 00 00 00     call        ??2@YAPEAX_K@Z
  00000000000000C1: 48 8B F0           mov         rsi,rax
  00000000000000C4: 48 85 C0           test        rax,rax
  00000000000000C7: 75 06              jne         00000000000000CF
  00000000000000C9: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  00000000000000CE: 90                 nop
  00000000000000CF: EB 14              jmp         00000000000000E5
  00000000000000B2: 48 83 7B 18 10     cmp         qword ptr [rbx+18h],10h
  00000000000000B7: 72 05              jb          00000000000000BE
  00000000000000B9: 48 8B 0B           mov         rcx,qword ptr [rbx]
  00000000000000BC: EB 03              jmp         00000000000000C1
  00000000000000BE: 48 8B CB           mov         rcx,rbx
  00000000000000C1: 4C 8B C7           mov         r8,rdi
  00000000000000C4: 48 8B D6           mov         rdx,rsi
  00000000000000C7: E8 00 00 00 00     call        memcpy
  00000000000000CC: 48 83 7B 18 10     cmp         qword ptr [rbx+18h],10h
  00000000000000D1: 48 89 7B 10        mov         qword ptr [rbx+10h],rdi
  00000000000000D5: 72 05              jb          00000000000000DC
  00000000000000D7: 48 8B 03           mov         rax,qword ptr [rbx]
  00000000000000DA: EB 03              jmp         00000000000000DF
  00000000000000DC: 48 8B C3           mov         rax,rbx
  00000000000000DF: 48 8B 74 24 38     mov         rsi,qword ptr [rsp+38h]
  00000000000000E4: C6 04 38 00        mov         byte ptr [rax+rdi],0
  00000000000000E8: 48 8B C3           mov         rax,rbx
  00000000000000EB: 48 8B 5C 24 30     mov         rbx,qword ptr [rsp+30h]
  00000000000000F0: 48 83 C4 20        add         rsp,20h
  00000000000000F4: 5F                 pop         rdi
  00000000000000F5: C3                 ret
  0000000000000045: 90                 nop
  0000000000000046: 0F 10 03           movups      xmm0,xmmword ptr [rbx]
  0000000000000049: 0F 29 44 24 30     movaps      xmmword ptr [rsp+30h],xmm0
  000000000000004E: 4C 8D 44 24 40     lea         r8,[rsp+40h]
  0000000000000053: 48 8D 54 24 30     lea         rdx,[rsp+30h]
  0000000000000058: 48 8B CF           mov         rcx,rdi
  0000000000000000: 48 89 5C 24 10     mov         qword ptr [rsp+10h],rbx
  0000000000000005: 57                 push        rdi
  0000000000000006: 48 83 EC 70        sub         rsp,70h
  000000000000000A: 49 8B C0           mov         rax,r8
  000000000000000D: 48 C7 44 24 40 00  mov         qword ptr [rsp+40h],0
  0000000000000016: 48 8B FA           mov         rdi,rdx
  0000000000000019: 48 C7 44 24 48 0F  mov         qword ptr [rsp+48h],0Fh
  0000000000000022: 48 8B D9           mov         rbx,rcx
  0000000000000025: C6 44 24 30 00     mov         byte ptr [rsp+30h],0
  000000000000002A: 48 8B D0           mov         rdx,rax
  000000000000002D: 48 8D 4C 24 30     lea         rcx,[rsp+30h]
  0000000000000032: 49 83 C9 FF        or          r9,0FFFFFFFFFFFFFFFFh
  0000000000000036: 45 33 C0           xor         r8d,r8d
  0000000000000000: 48 89 5C 24 08     mov         qword ptr [rsp+8],rbx
  0000000000000005: 48 89 74 24 10     mov         qword ptr [rsp+10h],rsi
  000000000000000A: 48 89 7C 24 18     mov         qword ptr [rsp+18h],rdi
  000000000000000F: 41 56              push        r14
  0000000000000011: 48 83 EC 20        sub         rsp,20h
  0000000000000015: 48 8B 42 10        mov         rax,qword ptr [rdx+10h]
  0000000000000019: 49 8B F9           mov         rdi,r9
  000000000000001C: 4D 8B F0           mov         r14,r8
  000000000000001F: 48 8B F2           mov         rsi,rdx
  0000000000000022: 48 8B D9           mov         rbx,rcx
  0000000000000025: 49 3B C0           cmp         rax,r8
  0000000000000028: 0F 82 BE 00 00 00  jb          00000000000000EC
  000000000000002E: 49 2B C0           sub         rax,r8
  0000000000000031: 49 3B C1           cmp         rax,r9
  0000000000000034: 48 0F 42 F8        cmovb       rdi,rax
  0000000000000038: 48 3B CA           cmp         rcx,rdx
  000000000000003B: 75 2C              jne         0000000000000069
  000000000000003D: 49 8D 04 38        lea         rax,[r8+rdi]
  0000000000000041: 48 39 41 10        cmp         qword ptr [rcx+10h],rax
  0000000000000045: 0F 82 A7 00 00 00  jb          00000000000000F2
  000000000000004B: 48 89 41 10        mov         qword ptr [rcx+10h],rax
  000000000000004F: 48 83 79 18 10     cmp         qword ptr [rcx+18h],10h
  0000000000000054: 72 03              jb          0000000000000059
  0000000000000056: 48 8B 09           mov         rcx,qword ptr [rcx]
  0000000000000059: C6 04 01 00        mov         byte ptr [rcx+rax],0
  000000000000005D: 33 D2              xor         edx,edx
  000000000000005F: 48 8B CB           mov         rcx,rbx
  0000000000000000: 48 89 5C 24 08     mov         qword ptr [rsp+8],rbx
  0000000000000005: 57                 push        rdi
  0000000000000006: 48 83 EC 20        sub         rsp,20h
  000000000000000A: 48 8B 79 10        mov         rdi,qword ptr [rcx+10h]
  000000000000000E: 4D 8B C8           mov         r9,r8
  0000000000000011: 48 8B D9           mov         rbx,rcx
  0000000000000014: 48 3B FA           cmp         rdi,rdx
  0000000000000017: 0F 82 9C 00 00 00  jb          00000000000000B9
  000000000000001D: 48 8B C7           mov         rax,rdi
  0000000000000020: 48 2B C2           sub         rax,rdx
  0000000000000023: 49 3B C0           cmp         rax,r8
  0000000000000026: 77 32              ja          000000000000005A
  0000000000000028: 48 89 51 10        mov         qword ptr [rcx+10h],rdx
  000000000000002C: 48 83 79 18 10     cmp         qword ptr [rcx+18h],10h
  0000000000000031: 72 15              jb          0000000000000048
  0000000000000033: 48 8B 01           mov         rax,qword ptr [rcx]
  0000000000000036: C6 04 10 00        mov         byte ptr [rax+rdx],0
  000000000000003A: 48 8B C1           mov         rax,rcx
  000000000000003D: 48 8B 5C 24 30     mov         rbx,qword ptr [rsp+30h]
  0000000000000042: 48 83 C4 20        add         rsp,20h
  0000000000000046: 5F                 pop         rdi
  0000000000000047: C3                 ret
  0000000000000048: 48 8B C3           mov         rax,rbx
  000000000000004B: C6 04 13 00        mov         byte ptr [rbx+rdx],0
  000000000000004F: 48 8B 5C 24 30     mov         rbx,qword ptr [rsp+30h]
  0000000000000054: 48 83 C4 20        add         rsp,20h
  0000000000000058: 5F                 pop         rdi
  0000000000000059: C3                 ret
  000000000000005A: 4D 85 C9           test        r9,r9
  000000000000005D: 74 4C              je          00000000000000AB
  000000000000005F: 48 83 79 18 10     cmp         qword ptr [rcx+18h],10h
  0000000000000064: 72 05              jb          000000000000006B
  0000000000000066: 48 8B 01           mov         rax,qword ptr [rcx]
  0000000000000069: EB 03              jmp         000000000000006E
  000000000000006B: 48 8B C3           mov         rax,rbx
  000000000000006E: 49 2B F9           sub         rdi,r9
  0000000000000071: 48 8D 0C 10        lea         rcx,[rax+rdx]
  0000000000000075: 4C 8B C7           mov         r8,rdi
  0000000000000078: 4C 2B C2           sub         r8,rdx
  000000000000007B: 4A 8D 14 09        lea         rdx,[rcx+r9]
  000000000000007F: E8 00 00 00 00     call        memmove
  0000000000000084: 48 83 7B 18 10     cmp         qword ptr [rbx+18h],10h
  0000000000000089: 48 89 7B 10        mov         qword ptr [rbx+10h],rdi
  000000000000008D: 72 15              jb          00000000000000A4
  000000000000008F: 48 8B 03           mov         rax,qword ptr [rbx]
  0000000000000092: C6 04 38 00        mov         byte ptr [rax+rdi],0
  0000000000000096: 48 8B C3           mov         rax,rbx
  0000000000000099: 48 8B 5C 24 30     mov         rbx,qword ptr [rsp+30h]
  000000000000009E: 48 83 C4 20        add         rsp,20h
  00000000000000A2: 5F                 pop         rdi
  00000000000000A3: C3                 ret
  00000000000000A4: 48 8B C3           mov         rax,rbx
  00000000000000A7: C6 04 3B 00        mov         byte ptr [rbx+rdi],0
  00000000000000AB: 48 8B C3           mov         rax,rbx
  00000000000000AE: 48 8B 5C 24 30     mov         rbx,qword ptr [rsp+30h]
  00000000000000B3: 48 83 C4 20        add         rsp,20h
  00000000000000B7: 5F                 pop         rdi
  00000000000000B8: C3                 ret
  0000000000000000: 48 83 EC 28        sub         rsp,28h
  0000000000000004: 48 8D 0D 00 00 00  lea         rcx,[??_C@_0BI@CFPLBAOH@invalid?5string?5position?$AA@]
  000000000000000B: E8 00 00 00 00     call        ?_Xout_of_range@std@@YAXPEBD@Z
  0000000000000010: CC                 int         3
  00000000000000BE: CC                 int         3
  0000000000000067: EB 6A              jmp         00000000000000D3
  0000000000000069: 48 85 FF           test        rdi,rdi
  000000000000006C: 75 1B              jne         0000000000000089
  000000000000006E: 48 83 79 18 10     cmp         qword ptr [rcx+18h],10h
  0000000000000073: 48 89 79 10        mov         qword ptr [rcx+10h],rdi
  0000000000000077: 72 08              jb          0000000000000081
  0000000000000079: 48 8B 01           mov         rax,qword ptr [rcx]
  000000000000007C: 40 88 38           mov         byte ptr [rax],dil
  000000000000007F: EB 52              jmp         00000000000000D3
  0000000000000081: 48 8B C3           mov         rax,rbx
  0000000000000084: C6 03 00           mov         byte ptr [rbx],0
  0000000000000087: EB 4A              jmp         00000000000000D3
  0000000000000089: 48 39 79 18        cmp         qword ptr [rcx+18h],rdi
  000000000000008D: 73 08              jae         0000000000000097
  000000000000008F: 48 8B D7           mov         rdx,rdi
  0000000000000092: E8 00 00 00 00     call        ?_Copy@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAX_K@Z
  0000000000000097: 48 83 7E 18 10     cmp         qword ptr [rsi+18h],10h
  000000000000009C: 72 03              jb          00000000000000A1
  000000000000009E: 48 8B 36           mov         rsi,qword ptr [rsi]
  00000000000000A1: 48 83 7B 18 10     cmp         qword ptr [rbx+18h],10h
  00000000000000A6: 72 05              jb          00000000000000AD
  00000000000000A8: 48 8B 0B           mov         rcx,qword ptr [rbx]
  00000000000000AB: EB 03              jmp         00000000000000B0
  00000000000000AD: 48 8B CB           mov         rcx,rbx
  00000000000000B0: 4A 8D 14 36        lea         rdx,[rsi+r14]
  00000000000000B4: 4C 8B C7           mov         r8,rdi
  00000000000000B7: E8 00 00 00 00     call        memcpy
  00000000000000BC: 48 83 7B 18 10     cmp         qword ptr [rbx+18h],10h
  00000000000000C1: 48 89 7B 10        mov         qword ptr [rbx+10h],rdi
  00000000000000C5: 72 05              jb          00000000000000CC
  00000000000000C7: 48 8B 03           mov         rax,qword ptr [rbx]
  00000000000000CA: EB 03              jmp         00000000000000CF
  00000000000000CC: 48 8B C3           mov         rax,rbx
  00000000000000CF: C6 04 38 00        mov         byte ptr [rax+rdi],0
  00000000000000D3: 48 8B 74 24 38     mov         rsi,qword ptr [rsp+38h]
  00000000000000D8: 48 8B C3           mov         rax,rbx
  00000000000000DB: 48 8B 5C 24 30     mov         rbx,qword ptr [rsp+30h]
  00000000000000E0: 48 8B 7C 24 40     mov         rdi,qword ptr [rsp+40h]
  00000000000000E5: 48 83 C4 20        add         rsp,20h
  00000000000000E9: 41 5E              pop         r14
  00000000000000EB: C3                 ret
  00000000000000EC: E8 00 00 00 00     call        ?_Xran@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@SAXXZ
  00000000000000F1: CC                 int         3
  00000000000000F2: E8 00 00 00 00     call        ?_Xran@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@SAXXZ
  00000000000000F7: CC                 int         3
  000000000000003E: 0F 10 07           movups      xmm0,xmmword ptr [rdi]
  0000000000000041: 4C 8D 44 24 30     lea         r8,[rsp+30h]
  0000000000000046: 48 8D 54 24 20     lea         rdx,[rsp+20h]
  000000000000004B: 48 8D 4C 24 50     lea         rcx,[rsp+50h]
  0000000000000050: 0F 29 44 24 20     movaps      xmmword ptr [rsp+20h],xmm0
  0000000000000000: 4C 89 44 24 18     mov         qword ptr [rsp+18h],r8
  0000000000000005: 57                 push        rdi
  0000000000000006: 48 83 EC 50        sub         rsp,50h
  000000000000000A: 48 C7 44 24 28 FE  mov         qword ptr [rsp+28h],0FFFFFFFFFFFFFFFEh
  0000000000000013: 48 89 5C 24 60     mov         qword ptr [rsp+60h],rbx
  0000000000000018: 48 89 6C 24 68     mov         qword ptr [rsp+68h],rbp
  000000000000001D: 48 89 74 24 78     mov         qword ptr [rsp+78h],rsi
  0000000000000022: 49 8B D8           mov         rbx,r8
  0000000000000025: 48 8B F2           mov         rsi,rdx
  0000000000000028: 48 8B F9           mov         rdi,rcx
  000000000000002B: 33 ED              xor         ebp,ebp
  000000000000002D: 89 6C 24 20        mov         dword ptr [rsp+20h],ebp
  0000000000000031: 49 39 68 10        cmp         qword ptr [r8+10h],rbp
  0000000000000035: 74 13              je          000000000000004A
  0000000000000037: 44 8D 45 02        lea         r8d,[rbp+2]
  000000000000003B: 48 8D 15 00 00 00  lea         rdx,[??_C@_02LMMGGCAJ@?3?5?$AA@]
  0000000000000042: 48 8B CB           mov         rcx,rbx
  0000000000000000: 48 89 5C 24 10     mov         qword ptr [rsp+10h],rbx
  0000000000000005: 48 89 6C 24 18     mov         qword ptr [rsp+18h],rbp
  000000000000000A: 56                 push        rsi
  000000000000000B: 48 83 EC 20        sub         rsp,20h
  000000000000000F: 48 8B F2           mov         rsi,rdx
  0000000000000012: 49 8B E8           mov         rbp,r8
  0000000000000015: 48 8B 51 18        mov         rdx,qword ptr [rcx+18h]
  0000000000000019: 48 8B D9           mov         rbx,rcx
  000000000000001C: 48 83 FA 10        cmp         rdx,10h
  0000000000000020: 72 03              jb          0000000000000025
  0000000000000022: 48 8B 09           mov         rcx,qword ptr [rcx]
  0000000000000025: 48 3B CE           cmp         rcx,rsi
  0000000000000028: 77 3A              ja          0000000000000064
  000000000000002A: 48 03 4B 10        add         rcx,qword ptr [rbx+10h]
  000000000000002E: 48 3B F1           cmp         rsi,rcx
  0000000000000031: 73 31              jae         0000000000000064
  0000000000000033: 48 83 FA 10        cmp         rdx,10h
  0000000000000037: 72 05              jb          000000000000003E
  0000000000000039: 48 8B 03           mov         rax,qword ptr [rbx]
  000000000000003C: EB 03              jmp         0000000000000041
  000000000000003E: 48 8B C3           mov         rax,rbx
  0000000000000041: 48 2B F0           sub         rsi,rax
  0000000000000044: 4C 8B CD           mov         r9,rbp
  0000000000000047: 4C 8B C6           mov         r8,rsi
  000000000000004A: 48 8B D3           mov         rdx,rbx
  000000000000004D: 48 8B CB           mov         rcx,rbx
  0000000000000050: 48 8B 5C 24 38     mov         rbx,qword ptr [rsp+38h]
  0000000000000055: 48 8B 6C 24 40     mov         rbp,qword ptr [rsp+40h]
  000000000000005A: 48 83 C4 20        add         rsp,20h
  000000000000005E: 5E                 pop         rsi
  000000000000005F: E9 00 00 00 00     jmp         ?append@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAAEAV12@AEBV12@_K_K@Z
  0000000000000064: 48 8B 4B 10        mov         rcx,qword ptr [rbx+10h]
  0000000000000068: 48 8B C1           mov         rax,rcx
  000000000000006B: 48 F7 D0           not         rax
  000000000000006E: 48 3B C5           cmp         rax,rbp
  0000000000000071: 0F 86 8A 00 00 00  jbe         0000000000000101
  0000000000000077: 48 89 7C 24 30     mov         qword ptr [rsp+30h],rdi
  000000000000007C: 4A 8D 3C 01        lea         rdi,[rcx+r8]
  0000000000000080: 48 85 ED           test        rbp,rbp
  0000000000000083: 74 64              je          00000000000000E9
  0000000000000085: 48 85 FF           test        rdi,rdi
  0000000000000088: 75 1A              jne         00000000000000A4
  000000000000008A: 48 89 7B 10        mov         qword ptr [rbx+10h],rdi
  000000000000008E: 48 83 FA 10        cmp         rdx,10h
  0000000000000092: 72 08              jb          000000000000009C
  0000000000000094: 48 8B 03           mov         rax,qword ptr [rbx]
  0000000000000097: 40 88 38           mov         byte ptr [rax],dil
  000000000000009A: EB 4D              jmp         00000000000000E9
  000000000000009C: 48 8B C3           mov         rax,rbx
  000000000000009F: C6 03 00           mov         byte ptr [rbx],0
  00000000000000A2: EB 45              jmp         00000000000000E9
  00000000000000A4: 48 3B D7           cmp         rdx,rdi
  00000000000000A7: 73 0B              jae         00000000000000B4
  00000000000000A9: 48 8B D7           mov         rdx,rdi
  00000000000000AC: 48 8B CB           mov         rcx,rbx
  00000000000000AF: E8 00 00 00 00     call        ?_Copy@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAX_K@Z
  00000000000000B4: 48 83 7B 18 10     cmp         qword ptr [rbx+18h],10h
  00000000000000B9: 72 05              jb          00000000000000C0
  00000000000000BB: 48 8B 0B           mov         rcx,qword ptr [rbx]
  00000000000000BE: EB 03              jmp         00000000000000C3
  00000000000000C0: 48 8B CB           mov         rcx,rbx
  00000000000000C3: 48 03 4B 10        add         rcx,qword ptr [rbx+10h]
  00000000000000C7: 4C 8B C5           mov         r8,rbp
  00000000000000CA: 48 8B D6           mov         rdx,rsi
  00000000000000CD: E8 00 00 00 00     call        memcpy
  00000000000000D2: 48 83 7B 18 10     cmp         qword ptr [rbx+18h],10h
  00000000000000D7: 48 89 7B 10        mov         qword ptr [rbx+10h],rdi
  00000000000000DB: 72 05              jb          00000000000000E2
  00000000000000DD: 48 8B 03           mov         rax,qword ptr [rbx]
  00000000000000E0: EB 03              jmp         00000000000000E5
  00000000000000E2: 48 8B C3           mov         rax,rbx
  00000000000000E5: C6 04 38 00        mov         byte ptr [rax+rdi],0
  00000000000000E9: 48 8B 7C 24 30     mov         rdi,qword ptr [rsp+30h]
  00000000000000EE: 48 8B C3           mov         rax,rbx
  00000000000000F1: 48 8B 5C 24 38     mov         rbx,qword ptr [rsp+38h]
  00000000000000F6: 48 8B 6C 24 40     mov         rbp,qword ptr [rsp+40h]
  00000000000000FB: 48 83 C4 20        add         rsp,20h
  00000000000000FF: 5E                 pop         rsi
  0000000000000100: C3                 ret
  0000000000000101: E8 00 00 00 00     call        ?_Xlen@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@SAXXZ
  0000000000000106: CC                 int         3
  000000000000004A: 48 8D 54 24 30     lea         rdx,[rsp+30h]
  000000000000004F: 48 8B CE           mov         rcx,rsi
  0000000000000000: 40 53              push        rbx
  0000000000000002: 48 83 EC 30        sub         rsp,30h
  0000000000000006: 44 8B 01           mov         r8d,dword ptr [rcx]
  0000000000000009: 48 8B DA           mov         rbx,rdx
  000000000000000C: 48 8B 49 08        mov         rcx,qword ptr [rcx+8]
  0000000000000010: C7 44 24 20 00 00  mov         dword ptr [rsp+20h],0
  0000000000000018: 48 8B 01           mov         rax,qword ptr [rcx]
  000000000000001B: FF 50 10           call        qword ptr [rax+10h]
  000000000000001E: 48 8B C3           mov         rax,rbx
  0000000000000021: 48 83 C4 30        add         rsp,30h
  0000000000000025: 5B                 pop         rbx
  0000000000000026: C3                 ret
  0000000000000057: 90                 nop
  0000000000000058: 49 83 C9 FF        or          r9,0FFFFFFFFFFFFFFFFh
  000000000000005C: 45 33 C0           xor         r8d,r8d
  000000000000005F: 48 8B D0           mov         rdx,rax
  0000000000000062: 48 8B CB           mov         rcx,rbx
  0000000000000000: 48 89 5C 24 10     mov         qword ptr [rsp+10h],rbx
  0000000000000005: 48 89 6C 24 18     mov         qword ptr [rsp+18h],rbp
  000000000000000A: 48 89 74 24 20     mov         qword ptr [rsp+20h],rsi
  000000000000000F: 41 56              push        r14
  0000000000000011: 48 83 EC 20        sub         rsp,20h
  0000000000000015: 48 8B 42 10        mov         rax,qword ptr [rdx+10h]
  0000000000000019: 49 8B F1           mov         rsi,r9
  000000000000001C: 49 8B E8           mov         rbp,r8
  000000000000001F: 4C 8B F2           mov         r14,rdx
  0000000000000022: 48 8B D9           mov         rbx,rcx
  0000000000000025: 49 3B C0           cmp         rax,r8
  0000000000000028: 0F 82 BA 00 00 00  jb          00000000000000E8
  000000000000002E: 48 8B 49 10        mov         rcx,qword ptr [rcx+10h]
  0000000000000032: 49 2B C0           sub         rax,r8
  0000000000000035: 49 3B C1           cmp         rax,r9
  0000000000000038: 48 0F 42 F0        cmovb       rsi,rax
  000000000000003C: 48 8B C1           mov         rax,rcx
  000000000000003F: 48 F7 D0           not         rax
  0000000000000042: 48 3B C6           cmp         rax,rsi
  0000000000000045: 0F 86 A3 00 00 00  jbe         00000000000000EE
  000000000000004B: 48 89 7C 24 30     mov         qword ptr [rsp+30h],rdi
  0000000000000050: 48 8D 3C 31        lea         rdi,[rcx+rsi]
  0000000000000054: 48 85 F6           test        rsi,rsi
  0000000000000057: 74 71              je          00000000000000CA
  0000000000000059: 48 85 FF           test        rdi,rdi
  000000000000005C: 75 1B              jne         0000000000000079
  000000000000005E: 48 89 7B 10        mov         qword ptr [rbx+10h],rdi
  0000000000000062: 48 83 7B 18 10     cmp         qword ptr [rbx+18h],10h
  0000000000000067: 72 08              jb          0000000000000071
  0000000000000069: 48 8B 03           mov         rax,qword ptr [rbx]
  000000000000006C: 40 88 38           mov         byte ptr [rax],dil
  000000000000006F: EB 59              jmp         00000000000000CA
  0000000000000071: 48 8B C3           mov         rax,rbx
  0000000000000074: C6 03 00           mov         byte ptr [rbx],0
  0000000000000077: EB 51              jmp         00000000000000CA
  0000000000000079: 48 39 7B 18        cmp         qword ptr [rbx+18h],rdi
  000000000000007D: 73 0B              jae         000000000000008A
  000000000000007F: 48 8B D7           mov         rdx,rdi
  0000000000000082: 48 8B CB           mov         rcx,rbx
  0000000000000085: E8 00 00 00 00     call        ?_Copy@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@QEAAX_K@Z
  000000000000008A: 49 83 7E 18 10     cmp         qword ptr [r14+18h],10h
  000000000000008F: 72 03              jb          0000000000000094
  0000000000000091: 4D 8B 36           mov         r14,qword ptr [r14]
  0000000000000094: 48 83 7B 18 10     cmp         qword ptr [rbx+18h],10h
  0000000000000099: 72 05              jb          00000000000000A0
  000000000000009B: 48 8B 0B           mov         rcx,qword ptr [rbx]
  000000000000009E: EB 03              jmp         00000000000000A3
  00000000000000A0: 48 8B CB           mov         rcx,rbx
  00000000000000A3: 48 03 4B 10        add         rcx,qword ptr [rbx+10h]
  00000000000000A7: 49 8D 14 2E        lea         rdx,[r14+rbp]
  00000000000000AB: 4C 8B C6           mov         r8,rsi
  00000000000000AE: E8 00 00 00 00     call        memcpy
  00000000000000B3: 48 83 7B 18 10     cmp         qword ptr [rbx+18h],10h
  00000000000000B8: 48 89 7B 10        mov         qword ptr [rbx+10h],rdi
  00000000000000BC: 72 05              jb          00000000000000C3
  00000000000000BE: 48 8B 03           mov         rax,qword ptr [rbx]
  00000000000000C1: EB 03              jmp         00000000000000C6
  00000000000000C3: 48 8B C3           mov         rax,rbx
  00000000000000C6: C6 04 38 00        mov         byte ptr [rax+rdi],0
  00000000000000CA: 48 8B 7C 24 30     mov         rdi,qword ptr [rsp+30h]
  00000000000000CF: 48 8B C3           mov         rax,rbx
  00000000000000D2: 48 8B 5C 24 38     mov         rbx,qword ptr [rsp+38h]
  00000000000000D7: 48 8B 6C 24 40     mov         rbp,qword ptr [rsp+40h]
  00000000000000DC: 48 8B 74 24 48     mov         rsi,qword ptr [rsp+48h]
  00000000000000E1: 48 83 C4 20        add         rsp,20h
  00000000000000E5: 41 5E              pop         r14
  00000000000000E7: C3                 ret
  00000000000000E8: E8 00 00 00 00     call        ?_Xran@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@SAXXZ
  00000000000000ED: CC                 int         3
  00000000000000EE: E8 00 00 00 00     call        ?_Xlen@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@SAXXZ
  00000000000000F3: CC                 int         3
  000000000000006A: 90                 nop
  000000000000006B: 48 8B 44 24 48     mov         rax,qword ptr [rsp+48h]
  0000000000000070: 48 83 F8 10        cmp         rax,10h
  0000000000000074: 72 4D              jb          00000000000000C3
  0000000000000076: 48 FF C0           inc         rax
  0000000000000079: 48 8B 4C 24 30     mov         rcx,qword ptr [rsp+30h]
  000000000000007E: 48 3D 00 10 00 00  cmp         rax,1000h
  0000000000000084: 72 38              jb          00000000000000BE
  0000000000000086: F6 C1 1F           test        cl,1Fh
  0000000000000089: 74 06              je          0000000000000091
  000000000000008B: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000090: CC                 int         3
  0000000000000091: 48 8B 41 F8        mov         rax,qword ptr [rcx-8]
  0000000000000095: 48 3B C1           cmp         rax,rcx
  0000000000000098: 72 06              jb          00000000000000A0
  000000000000009A: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  000000000000009F: CC                 int         3
  00000000000000A0: 48 2B C8           sub         rcx,rax
  00000000000000A3: 48 83 F9 08        cmp         rcx,8
  00000000000000A7: 73 06              jae         00000000000000AF
  00000000000000A9: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  00000000000000AE: CC                 int         3
  00000000000000AF: 48 83 F9 27        cmp         rcx,27h
  00000000000000B3: 76 06              jbe         00000000000000BB
  00000000000000B5: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  00000000000000BA: CC                 int         3
  00000000000000BB: 48 8B C8           mov         rcx,rax
  00000000000000BE: E8 00 00 00 00     call        ??3@YAXPEAX@Z
  00000000000000C3: 48 89 6F 10        mov         qword ptr [rdi+10h],rbp
  00000000000000C7: 48 89 6F 18        mov         qword ptr [rdi+18h],rbp
  00000000000000CB: 0F 10 03           movups      xmm0,xmmword ptr [rbx]
  00000000000000CE: 0F 11 07           movups      xmmword ptr [rdi],xmm0
  00000000000000D1: 0F 10 4B 10        movups      xmm1,xmmword ptr [rbx+10h]
  00000000000000D5: 0F 11 4F 10        movups      xmmword ptr [rdi+10h],xmm1
  00000000000000D9: 48 89 6B 10        mov         qword ptr [rbx+10h],rbp
  00000000000000DD: 48 C7 43 18 0F 00  mov         qword ptr [rbx+18h],0Fh
  00000000000000E5: C6 03 00           mov         byte ptr [rbx],0
  00000000000000E8: 48 8B CB           mov         rcx,rbx
  0000000000000000: 40 53              push        rbx
  0000000000000002: 48 83 EC 20        sub         rsp,20h
  0000000000000006: 48 8B 41 18        mov         rax,qword ptr [rcx+18h]
  000000000000000A: 48 8B D9           mov         rbx,rcx
  000000000000000D: 48 83 F8 10        cmp         rax,10h
  0000000000000011: 72 33              jb          0000000000000046
  0000000000000013: 48 8B 09           mov         rcx,qword ptr [rcx]
  0000000000000016: 48 FF C0           inc         rax
  0000000000000019: 48 3D 00 10 00 00  cmp         rax,1000h
  000000000000001F: 72 20              jb          0000000000000041
  0000000000000021: F6 C1 1F           test        cl,1Fh
  0000000000000024: 75 39              jne         000000000000005F
  0000000000000026: 48 8B 41 F8        mov         rax,qword ptr [rcx-8]
  000000000000002A: 48 3B C1           cmp         rax,rcx
  000000000000002D: 73 36              jae         0000000000000065
  000000000000002F: 48 2B C8           sub         rcx,rax
  0000000000000032: 48 83 F9 08        cmp         rcx,8
  0000000000000036: 72 33              jb          000000000000006B
  0000000000000038: 48 83 F9 27        cmp         rcx,27h
  000000000000003C: 77 33              ja          0000000000000071
  000000000000003E: 48 8B C8           mov         rcx,rax
  0000000000000041: E8 00 00 00 00     call        ??3@YAXPEAX@Z
  0000000000000046: 48 C7 43 10 00 00  mov         qword ptr [rbx+10h],0
  000000000000004E: 48 C7 43 18 0F 00  mov         qword ptr [rbx+18h],0Fh
  0000000000000056: C6 03 00           mov         byte ptr [rbx],0
  0000000000000059: 48 83 C4 20        add         rsp,20h
  000000000000005D: 5B                 pop         rbx
  000000000000005E: C3                 ret
  000000000000005F: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000064: CC                 int         3
  0000000000000065: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  000000000000006A: CC                 int         3
  000000000000006B: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000070: CC                 int         3
  0000000000000071: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000076: CC                 int         3
  00000000000000F0: 48 8B C7           mov         rax,rdi
  00000000000000F3: 48 8B 5C 24 60     mov         rbx,qword ptr [rsp+60h]
  00000000000000F8: 48 8B 6C 24 68     mov         rbp,qword ptr [rsp+68h]
  00000000000000FD: 48 8B 74 24 78     mov         rsi,qword ptr [rsp+78h]
  0000000000000102: 48 83 C4 50        add         rsp,50h
  0000000000000106: 5F                 pop         rdi
  0000000000000107: C3                 ret
  000000000000005A: 48 83 78 18 10     cmp         qword ptr [rax+18h],10h
  000000000000005F: 72 03              jb          0000000000000064
  0000000000000061: 48 8B 00           mov         rax,qword ptr [rax]
  0000000000000064: 48 8D 53 08        lea         rdx,[rbx+8]
  0000000000000068: 48 89 44 24 20     mov         qword ptr [rsp+20h],rax
  000000000000006D: 48 8D 0D 00 00 00  lea         rcx,[??_7exception@std@@6B@]
  0000000000000074: C6 44 24 28 01     mov         byte ptr [rsp+28h],1
  0000000000000079: 48 89 0B           mov         qword ptr [rbx],rcx
  000000000000007C: 33 C9              xor         ecx,ecx
  000000000000007E: 48 89 0A           mov         qword ptr [rdx],rcx
  0000000000000081: 48 89 4A 08        mov         qword ptr [rdx+8],rcx
  0000000000000085: 48 8D 4C 24 20     lea         rcx,[rsp+20h]
  000000000000008A: E8 00 00 00 00     call        __std_exception_copy
  000000000000008F: 48 8D 05 00 00 00  lea         rax,[??_7runtime_error@std@@6B@]
  0000000000000096: 48 89 03           mov         qword ptr [rbx],rax
  0000000000000099: 48 8B 44 24 68     mov         rax,qword ptr [rsp+68h]
  000000000000009E: 48 83 F8 10        cmp         rax,10h
  00000000000000A2: 72 35              jb          00000000000000D9
  00000000000000A4: 48 8B 4C 24 50     mov         rcx,qword ptr [rsp+50h]
  00000000000000A9: 48 FF C0           inc         rax
  00000000000000AC: 48 3D 00 10 00 00  cmp         rax,1000h
  00000000000000B2: 72 20              jb          00000000000000D4
  00000000000000B4: F6 C1 1F           test        cl,1Fh
  00000000000000B7: 75 42              jne         00000000000000FB
  00000000000000B9: 48 8B 41 F8        mov         rax,qword ptr [rcx-8]
  00000000000000BD: 48 3B C1           cmp         rax,rcx
  00000000000000C0: 73 3F              jae         0000000000000101
  00000000000000C2: 48 2B C8           sub         rcx,rax
  00000000000000C5: 48 83 F9 08        cmp         rcx,8
  00000000000000C9: 72 3C              jb          0000000000000107
  00000000000000CB: 48 83 F9 27        cmp         rcx,27h
  00000000000000CF: 77 3C              ja          000000000000010D
  00000000000000D1: 48 8B C8           mov         rcx,rax
  00000000000000D4: E8 00 00 00 00     call        ??3@YAXPEAX@Z
  00000000000000D9: 48 8D 05 00 00 00  lea         rax,[??_7_System_error@std@@6B@]
  00000000000000E0: 48 89 03           mov         qword ptr [rbx],rax
  00000000000000E3: 48 8B C3           mov         rax,rbx
  00000000000000E6: 0F 10 07           movups      xmm0,xmmword ptr [rdi]
  00000000000000E9: 0F 11 43 18        movups      xmmword ptr [rbx+18h],xmm0
  00000000000000ED: 48 8B 9C 24 88 00  mov         rbx,qword ptr [rsp+88h]
  00000000000000F5: 48 83 C4 70        add         rsp,70h
  00000000000000F9: 5F                 pop         rdi
  00000000000000FA: C3                 ret
  00000000000000FB: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000100: CC                 int         3
  0000000000000101: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000106: CC                 int         3
  0000000000000107: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  000000000000010C: CC                 int         3
  000000000000010D: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000112: CC                 int         3
  0000000000000060: 90                 nop
  0000000000000061: 48 8B 44 24 58     mov         rax,qword ptr [rsp+58h]
  0000000000000066: 48 83 F8 10        cmp         rax,10h
  000000000000006A: 72 4D              jb          00000000000000B9
  000000000000006C: 48 FF C0           inc         rax
  000000000000006F: 48 8B 4C 24 40     mov         rcx,qword ptr [rsp+40h]
  0000000000000074: 48 3D 00 10 00 00  cmp         rax,1000h
  000000000000007A: 72 38              jb          00000000000000B4
  000000000000007C: F6 C1 1F           test        cl,1Fh
  000000000000007F: 74 06              je          0000000000000087
  0000000000000081: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000086: CC                 int         3
  0000000000000087: 48 8B 41 F8        mov         rax,qword ptr [rcx-8]
  000000000000008B: 48 3B C1           cmp         rax,rcx
  000000000000008E: 72 06              jb          0000000000000096
  0000000000000090: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000095: CC                 int         3
  0000000000000096: 48 2B C8           sub         rcx,rax
  0000000000000099: 48 83 F9 08        cmp         rcx,8
  000000000000009D: 73 06              jae         00000000000000A5
  000000000000009F: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  00000000000000A4: CC                 int         3
  00000000000000A5: 48 83 F9 27        cmp         rcx,27h
  00000000000000A9: 76 06              jbe         00000000000000B1
  00000000000000AB: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  00000000000000B0: CC                 int         3
  00000000000000B1: 48 8B C8           mov         rcx,rax
  00000000000000B4: E8 00 00 00 00     call        ??3@YAXPEAX@Z
  00000000000000B9: 48 8D 05 00 00 00  lea         rax,[??_7system_error@std@@6B@]
  00000000000000C0: 48 89 07           mov         qword ptr [rdi],rax
  00000000000000C3: 48 8B C7           mov         rax,rdi
  00000000000000C6: 48 8B 5C 24 70     mov         rbx,qword ptr [rsp+70h]
  00000000000000CB: 48 83 C4 60        add         rsp,60h
  00000000000000CF: 5F                 pop         rdi
  00000000000000D0: C3                 ret
  000000000000004A: 48 8D 15 00 00 00  lea         rdx,[_TI4?AVsystem_error@std@@]
  0000000000000051: 48 8D 4C 24 50     lea         rcx,[rsp+50h]
  0000000000000056: E8 00 00 00 00     call        _CxxThrowException
  000000000000005B: CC                 int         3
