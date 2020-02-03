  0000000000000000: 40 53              push        rbx
  0000000000000002: 48 83 EC 50        sub         rsp,50h
  0000000000000006: 48 8D 1D 00 00 00  lea         rbx,[?_Storage@?1???$_Immortalize@V_System_error_category@std@@@std@@YAAEAV_System_error_category@1@XZ@4T?$_Align_type@N$0BA@@1@A]
  000000000000000D: C7 44 24 20 05 00  mov         dword ptr [rsp+20h],5
  0000000000000015: 4C 8B C3           mov         r8,rbx
  0000000000000018: 48 C7 44 24 24 01  mov         qword ptr [rsp+24h],1
  0000000000000021: 48 8D 15 00 00 00  lea         rdx,[??$_Immortalize_impl@V_System_error_category@std@@@std@@YAHPEAX0PEAPEAX@Z]
  0000000000000028: 48 8D 0D 00 00 00  lea         rcx,[?_Flag@?1???$_Immortalize@V_System_error_category@std@@@std@@YAAEAV_System_error_category@1@XZ@4PEAXEA]
  000000000000002F: E8 00 00 00 00     call        ?_Execute_once@std@@YAHAEAUonce_flag@1@P6AHPEAX1PEAPEAX@Z1@Z
  0000000000000034: 85 C0              test        eax,eax
  0000000000000036: 74 79              je          00000000000000B1
  0000000000000038: 0F 10 4C 24 20     movups      xmm1,xmmword ptr [rsp+20h]
  000000000000003D: 48 89 5C 24 30     mov         qword ptr [rsp+30h],rbx
  0000000000000042: F2 0F 10 44 24 30  movsd       xmm0,mmword ptr [rsp+30h]
  0000000000000048: 66 48 0F 7E C8     movq        rax,xmm1
  000000000000004D: F2 0F 11 44 24 48  movsd       mmword ptr [rsp+48h],xmm0
  0000000000000053: 48 C1 E8 20        shr         rax,20h
  0000000000000057: 0F 11 4C 24 38     movups      xmmword ptr [rsp+38h],xmm1
  000000000000005C: A8 01              test        al,1
  000000000000005E: 75 08              jne         0000000000000068
  0000000000000060: D0 E8              shr         al,1
  0000000000000062: A8 01              test        al,1
  0000000000000064: 75 30              jne         0000000000000096
  0000000000000066: EB 0B              jmp         0000000000000073
  0000000000000068: B8 05 00 00 00     mov         eax,5
  000000000000006D: 48 83 C4 50        add         rsp,50h
  0000000000000071: 5B                 pop         rbx
  0000000000000072: C3                 ret
  0000000000000073: 48 8D 15 00 00 00  lea         rdx,[??_C@_08JEIPHCP@no?5value@]
  000000000000007A: 48 8D 4C 24 20     lea         rcx,[rsp+20h]
  0000000000000000: 40 53              push        rbx
  0000000000000002: 48 83 EC 30        sub         rsp,30h
  0000000000000006: 48 8B D9           mov         rbx,rcx
  0000000000000009: C6 44 24 28 01     mov         byte ptr [rsp+28h],1
  000000000000000E: 48 8B C2           mov         rax,rdx
  0000000000000011: 48 8D 0D 00 00 00  lea         rcx,[??_7exception@std@@6B@]
  0000000000000018: 48 8D 53 08        lea         rdx,[rbx+8]
  000000000000001C: 48 89 44 24 20     mov         qword ptr [rsp+20h],rax
  0000000000000021: 0F 57 C0           xorps       xmm0,xmm0
  0000000000000024: 48 89 0B           mov         qword ptr [rbx],rcx
  0000000000000027: 48 8D 4C 24 20     lea         rcx,[rsp+20h]
  000000000000002C: 0F 11 02           movups      xmmword ptr [rdx],xmm0
  000000000000002F: E8 00 00 00 00     call        __std_exception_copy
  0000000000000034: 48 8D 05 00 00 00  lea         rax,[??_7bad_result_access@outcome_v2_3f877000@@6B@]
  000000000000003B: 48 89 03           mov         qword ptr [rbx],rax
  000000000000003E: 48 8B C3           mov         rax,rbx
  0000000000000041: 48 83 C4 30        add         rsp,30h
  0000000000000045: 5B                 pop         rbx
  0000000000000046: C3                 ret
  0000000000000084: 48 8D 15 00 00 00  lea         rdx,[_TI3?AVbad_result_access@outcome_v2_3f877000@@]
  000000000000008B: 48 8D 4C 24 20     lea         rcx,[rsp+20h]
  0000000000000090: E8 00 00 00 00     call        _CxxThrowException
  0000000000000095: CC                 int         3
  0000000000000096: 48 8D 4C 24 38     lea         rcx,[rsp+38h]
  0000000000000000: 48 8B C1           mov         rax,rcx
  0000000000000003: C3                 ret
  00000000000000A0: 48 8B C8           mov         rcx,rax
  0000000000000000: 48 8D 41 08        lea         rax,[rcx+8]
  0000000000000004: C3                 ret
  00000000000000A8: 48 8B C8           mov         rcx,rax
  0000000000000000: 48 83 EC 68        sub         rsp,68h
  0000000000000004: 0F 10 01           movups      xmm0,xmmword ptr [rcx]
  0000000000000007: 48 8D 54 24 20     lea         rdx,[rsp+20h]
  000000000000000C: 48 8D 4C 24 30     lea         rcx,[rsp+30h]
  0000000000000011: 0F 29 44 24 20     movaps      xmmword ptr [rsp+20h],xmm0
  0000000000000000: 48 89 5C 24 08     mov         qword ptr [rsp+8],rbx
  0000000000000005: 57                 push        rdi
  0000000000000006: 48 83 EC 50        sub         rsp,50h
  000000000000000A: 48 8B DA           mov         rbx,rdx
  000000000000000D: 48 8B F9           mov         rdi,rcx
  0000000000000010: 48 C7 44 24 40 00  mov         qword ptr [rsp+40h],0
  0000000000000019: 48 C7 44 24 48 0F  mov         qword ptr [rsp+48h],0Fh
  0000000000000022: C6 44 24 30 00     mov         byte ptr [rsp+30h],0
  0000000000000027: 45 33 C0           xor         r8d,r8d
  000000000000002A: 48 8D 15 00 00 00  lea         rdx,[??_C@_00CNPNBAHC@@]
  0000000000000031: 48 8D 4C 24 30     lea         rcx,[rsp+30h]
  0000000000000000: 48 89 5C 24 10     mov         qword ptr [rsp+10h],rbx
  0000000000000005: 48 89 6C 24 18     mov         qword ptr [rsp+18h],rbp
  000000000000000A: 56                 push        rsi
  000000000000000B: 57                 push        rdi
  000000000000000C: 41 57              push        r15
  000000000000000E: 48 83 EC 20        sub         rsp,20h
  0000000000000012: 48 8B 69 18        mov         rbp,qword ptr [rcx+18h]
  0000000000000016: 49 8B F0           mov         rsi,r8
  0000000000000019: 4C 8B FA           mov         r15,rdx
  000000000000001C: 48 8B D9           mov         rbx,rcx
  000000000000001F: 4C 3B C5           cmp         r8,rbp
  0000000000000022: 77 21              ja          0000000000000045
  0000000000000024: 48 8B F9           mov         rdi,rcx
  0000000000000027: 48 83 FD 10        cmp         rbp,10h
  000000000000002B: 72 03              jb          0000000000000030
  000000000000002D: 48 8B 39           mov         rdi,qword ptr [rcx]
  0000000000000030: 48 89 71 10        mov         qword ptr [rcx+10h],rsi
  0000000000000034: 48 8B CF           mov         rcx,rdi
  0000000000000037: E8 00 00 00 00     call        memmove
  000000000000003C: C6 04 37 00        mov         byte ptr [rdi+rsi],0
  0000000000000040: E9 E4 00 00 00     jmp         0000000000000129
  0000000000000045: 48 BF FF FF FF FF  mov         rdi,7FFFFFFFFFFFFFFFh
  000000000000004F: 48 3B F7           cmp         rsi,rdi
  0000000000000052: 0F 87 F3 00 00 00  ja          000000000000014B
  0000000000000058: 48 8B CE           mov         rcx,rsi
  000000000000005B: 48 83 C9 0F        or          rcx,0Fh
  000000000000005F: 48 3B CF           cmp         rcx,rdi
  0000000000000062: 77 1F              ja          0000000000000083
  0000000000000064: 48 8B D5           mov         rdx,rbp
  0000000000000067: 48 8B C7           mov         rax,rdi
  000000000000006A: 48 D1 EA           shr         rdx,1
  000000000000006D: 48 2B C2           sub         rax,rdx
  0000000000000070: 48 3B E8           cmp         rbp,rax
  0000000000000073: 77 0E              ja          0000000000000083
  0000000000000075: 48 8D 04 2A        lea         rax,[rdx+rbp]
  0000000000000079: 48 8B F9           mov         rdi,rcx
  000000000000007C: 48 3B C8           cmp         rcx,rax
  000000000000007F: 48 0F 42 F8        cmovb       rdi,rax
  0000000000000083: 48 8D 4F 01        lea         rcx,[rdi+1]
  0000000000000087: 4C 89 74 24 40     mov         qword ptr [rsp+40h],r14
  000000000000008C: 48 81 F9 00 10 00  cmp         rcx,1000h
  0000000000000093: 72 2C              jb          00000000000000C1
  0000000000000095: 48 8D 41 27        lea         rax,[rcx+27h]
  0000000000000099: 48 3B C1           cmp         rax,rcx
  000000000000009C: 0F 86 9D 00 00 00  jbe         000000000000013F
  00000000000000A2: 48 8B C8           mov         rcx,rax
  00000000000000A5: E8 00 00 00 00     call        ??2@YAPEAX_K@Z
  00000000000000AA: 48 85 C0           test        rax,rax
  00000000000000AD: 0F 84 92 00 00 00  je          0000000000000145
  00000000000000B3: 4C 8D 70 27        lea         r14,[rax+27h]
  00000000000000B7: 49 83 E6 E0        and         r14,0FFFFFFFFFFFFFFE0h
  00000000000000BB: 49 89 46 F8        mov         qword ptr [r14-8],rax
  00000000000000BF: EB 12              jmp         00000000000000D3
  00000000000000C1: 48 85 C9           test        rcx,rcx
  00000000000000C4: 74 0A              je          00000000000000D0
  00000000000000C6: E8 00 00 00 00     call        ??2@YAPEAX_K@Z
  00000000000000CB: 4C 8B F0           mov         r14,rax
  00000000000000CE: EB 03              jmp         00000000000000D3
  00000000000000D0: 45 33 F6           xor         r14d,r14d
  00000000000000D3: 4C 8B C6           mov         r8,rsi
  00000000000000D6: 48 89 73 10        mov         qword ptr [rbx+10h],rsi
  00000000000000DA: 49 8B D7           mov         rdx,r15
  00000000000000DD: 48 89 7B 18        mov         qword ptr [rbx+18h],rdi
  00000000000000E1: 49 8B CE           mov         rcx,r14
  00000000000000E4: E8 00 00 00 00     call        memcpy
  00000000000000E9: 41 C6 04 36 00     mov         byte ptr [r14+rsi],0
  00000000000000EE: 48 83 FD 10        cmp         rbp,10h
  00000000000000F2: 72 2D              jb          0000000000000121
  00000000000000F4: 48 8B 0B           mov         rcx,qword ptr [rbx]
  00000000000000F7: 48 8D 55 01        lea         rdx,[rbp+1]
  00000000000000FB: 48 81 FA 00 10 00  cmp         rdx,1000h
  0000000000000102: 72 18              jb          000000000000011C
  0000000000000104: 4C 8B 41 F8        mov         r8,qword ptr [rcx-8]
  0000000000000108: 48 83 C2 27        add         rdx,27h
  000000000000010C: 49 2B C8           sub         rcx,r8
  000000000000010F: 48 8D 41 F8        lea         rax,[rcx-8]
  0000000000000113: 48 83 F8 1F        cmp         rax,1Fh
  0000000000000117: 77 2C              ja          0000000000000145
  0000000000000119: 49 8B C8           mov         rcx,r8
  000000000000011C: E8 00 00 00 00     call        ??3@YAXPEAX_K@Z
  0000000000000121: 4C 89 33           mov         qword ptr [rbx],r14
  0000000000000124: 4C 8B 74 24 40     mov         r14,qword ptr [rsp+40h]
  0000000000000129: 48 8B 6C 24 50     mov         rbp,qword ptr [rsp+50h]
  000000000000012E: 48 8B C3           mov         rax,rbx
  0000000000000131: 48 8B 5C 24 48     mov         rbx,qword ptr [rsp+48h]
  0000000000000136: 48 83 C4 20        add         rsp,20h
  000000000000013A: 41 5F              pop         r15
  000000000000013C: 5F                 pop         rdi
  000000000000013D: 5E                 pop         rsi
  000000000000013E: C3                 ret
  0000000000000000: 48 83 EC 48        sub         rsp,48h
  0000000000000004: 48 8D 4C 24 20     lea         rcx,[rsp+20h]
  0000000000000000: 48 8D 05 00 00 00  lea         rax,[??_C@_0BF@KINCDENJ@bad?5array?5new?5length@]
  0000000000000007: 48 C7 41 10 00 00  mov         qword ptr [rcx+10h],0
  000000000000000F: 48 89 41 08        mov         qword ptr [rcx+8],rax
  0000000000000013: 48 8D 05 00 00 00  lea         rax,[??_7bad_array_new_length@std@@6B@]
  000000000000001A: 48 89 01           mov         qword ptr [rcx],rax
  000000000000001D: 48 8B C1           mov         rax,rcx
  0000000000000020: C3                 ret
  000000000000000E: 48 8D 15 00 00 00  lea         rdx,[_TI3?AVbad_array_new_length@std@@]
  0000000000000015: 48 8D 4C 24 20     lea         rcx,[rsp+20h]
  000000000000001A: E8 00 00 00 00     call        _CxxThrowException
  000000000000001F: CC                 int         3
  0000000000000144: CC                 int         3
  0000000000000145: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  000000000000014A: CC                 int         3
  0000000000000000: 48 83 EC 28        sub         rsp,28h
  0000000000000004: 48 8D 0D 00 00 00  lea         rcx,[??_C@_0BA@JFNIOLAK@string?5too?5long@]
  000000000000000B: E8 00 00 00 00     call        ?_Xlength_error@std@@YAXPEBD@Z
  0000000000000010: CC                 int         3
  0000000000000150: CC                 int         3
  000000000000003B: 90                 nop
  000000000000003C: 0F 10 03           movups      xmm0,xmmword ptr [rbx]
  000000000000003F: 0F 29 44 24 20     movaps      xmmword ptr [rsp+20h],xmm0
  0000000000000044: 4C 8D 44 24 30     lea         r8,[rsp+30h]
  0000000000000049: 48 8D 54 24 20     lea         rdx,[rsp+20h]
  000000000000004E: 48 8B CF           mov         rcx,rdi
  0000000000000000: 48 89 5C 24 08     mov         qword ptr [rsp+8],rbx
  0000000000000005: 48 89 74 24 10     mov         qword ptr [rsp+10h],rsi
  000000000000000A: 48 89 7C 24 20     mov         qword ptr [rsp+20h],rdi
  000000000000000F: 55                 push        rbp
  0000000000000010: 41 56              push        r14
  0000000000000012: 41 57              push        r15
  0000000000000014: 48 8D 6C 24 B9     lea         rbp,[rsp-47h]
  0000000000000019: 48 81 EC 90 00 00  sub         rsp,90h
  0000000000000020: 49 8B F0           mov         rsi,r8
  0000000000000023: 4C 8B FA           mov         r15,rdx
  0000000000000026: 4C 8B F1           mov         r14,rcx
  0000000000000029: 48 C7 45 17 00 00  mov         qword ptr [rbp+17h],0
  0000000000000031: 48 C7 45 1F 00 00  mov         qword ptr [rbp+1Fh],0
  0000000000000039: 49 8B 78 10        mov         rdi,qword ptr [r8+10h]
  000000000000003D: 49 83 78 18 10     cmp         qword ptr [r8+18h],10h
  0000000000000042: 72 03              jb          0000000000000047
  0000000000000044: 49 8B 30           mov         rsi,qword ptr [r8]
  0000000000000047: 48 83 FF 10        cmp         rdi,10h
  000000000000004B: 73 0E              jae         000000000000005B
  000000000000004D: 0F 10 06           movups      xmm0,xmmword ptr [rsi]
  0000000000000050: 0F 11 45 07        movups      xmmword ptr [rbp+7],xmm0
  0000000000000054: BB 0F 00 00 00     mov         ebx,0Fh
  0000000000000059: EB 75              jmp         00000000000000D0
  000000000000005B: 48 8B DF           mov         rbx,rdi
  000000000000005E: 48 83 CB 0F        or          rbx,0Fh
  0000000000000062: 48 B8 FF FF FF FF  mov         rax,7FFFFFFFFFFFFFFFh
  000000000000006C: 48 3B D8           cmp         rbx,rax
  000000000000006F: 48 0F 47 D8        cmova       rbx,rax
  0000000000000073: 48 8D 4B 01        lea         rcx,[rbx+1]
  0000000000000077: 48 81 F9 00 10 00  cmp         rcx,1000h
  000000000000007E: 72 2F              jb          00000000000000AF
  0000000000000080: 48 8D 41 27        lea         rax,[rcx+27h]
  0000000000000084: 48 3B C1           cmp         rax,rcx
  0000000000000087: 0F 86 F9 01 00 00  jbe         0000000000000286
  000000000000008D: 48 8B C8           mov         rcx,rax
  0000000000000090: E8 00 00 00 00     call        ??2@YAPEAX_K@Z
  0000000000000095: 48 8B C8           mov         rcx,rax
  0000000000000098: 48 85 C0           test        rax,rax
  000000000000009B: 0F 84 DF 01 00 00  je          0000000000000280
  00000000000000A1: 48 83 C0 27        add         rax,27h
  00000000000000A5: 48 83 E0 E0        and         rax,0FFFFFFFFFFFFFFE0h
  00000000000000A9: 48 89 48 F8        mov         qword ptr [rax-8],rcx
  00000000000000AD: EB 0E              jmp         00000000000000BD
  00000000000000AF: 48 85 C9           test        rcx,rcx
  00000000000000B2: 74 07              je          00000000000000BB
  00000000000000B4: E8 00 00 00 00     call        ??2@YAPEAX_K@Z
  00000000000000B9: EB 02              jmp         00000000000000BD
  00000000000000BB: 33 C0              xor         eax,eax
  00000000000000BD: 48 89 45 07        mov         qword ptr [rbp+7],rax
  00000000000000C1: 4C 8D 47 01        lea         r8,[rdi+1]
  00000000000000C5: 48 8B D6           mov         rdx,rsi
  00000000000000C8: 48 8B C8           mov         rcx,rax
  00000000000000CB: E8 00 00 00 00     call        memcpy
  00000000000000D0: 48 89 7D 17        mov         qword ptr [rbp+17h],rdi
  00000000000000D4: 48 89 5D 1F        mov         qword ptr [rbp+1Fh],rbx
  00000000000000D8: 48 8D 45 07        lea         rax,[rbp+7]
  00000000000000DC: 48 89 45 77        mov         qword ptr [rbp+77h],rax
  00000000000000E0: 41 0F 10 07        movups      xmm0,xmmword ptr [r15]
  00000000000000E4: 0F 29 45 E7        movaps      xmmword ptr [rbp-19h],xmm0
  00000000000000E8: 48 85 FF           test        rdi,rdi
  00000000000000EB: 74 51              je          000000000000013E
  00000000000000ED: 48 8B C3           mov         rax,rbx
  00000000000000F0: 48 2B C7           sub         rax,rdi
  00000000000000F3: 48 83 F8 02        cmp         rax,2
  00000000000000F7: 72 25              jb          000000000000011E
  00000000000000F9: 48 8D 47 02        lea         rax,[rdi+2]
  00000000000000FD: 48 89 45 17        mov         qword ptr [rbp+17h],rax
  0000000000000101: 48 8D 45 07        lea         rax,[rbp+7]
  0000000000000105: 48 83 FB 10        cmp         rbx,10h
  0000000000000109: 48 0F 43 45 07     cmovae      rax,qword ptr [rbp+7]
  000000000000010E: B9 3A 20 00 00     mov         ecx,203Ah
  0000000000000113: 66 89 0C 38        mov         word ptr [rax+rdi],cx
  0000000000000117: C6 44 38 02 00     mov         byte ptr [rax+rdi+2],0
  000000000000011C: EB 20              jmp         000000000000013E
  000000000000011E: 48 C7 44 24 20 02  mov         qword ptr [rsp+20h],2
  0000000000000127: 4C 8D 0D 00 00 00  lea         r9,[??_C@_02LMMGGCAJ@?3?5@]
  000000000000012E: 45 33 C0           xor         r8d,r8d
  0000000000000131: 41 8D 50 02        lea         edx,[r8+2]
  0000000000000135: 48 8D 4D 07        lea         rcx,[rbp+7]
  0000000000000000: 40 53              push        rbx
  0000000000000002: 56                 push        rsi
  0000000000000003: 41 55              push        r13
  0000000000000005: 41 56              push        r14
  0000000000000007: 48 83 EC 28        sub         rsp,28h
  000000000000000B: 4C 8B 71 10        mov         r14,qword ptr [rcx+10h]
  000000000000000F: 48 BB FF FF FF FF  mov         rbx,7FFFFFFFFFFFFFFFh
  0000000000000019: 48 8B C3           mov         rax,rbx
  000000000000001C: 4D 8B E9           mov         r13,r9
  000000000000001F: 49 2B C6           sub         rax,r14
  0000000000000022: 48 8B F1           mov         rsi,rcx
  0000000000000025: 48 3B C2           cmp         rax,rdx
  0000000000000028: 0F 82 41 01 00 00  jb          000000000000016F
  000000000000002E: 48 89 6C 24 50     mov         qword ptr [rsp+50h],rbp
  0000000000000033: 48 8B 69 18        mov         rbp,qword ptr [rcx+18h]
  0000000000000037: 4C 89 7C 24 20     mov         qword ptr [rsp+20h],r15
  000000000000003C: 4D 8D 3C 16        lea         r15,[r14+rdx]
  0000000000000040: 49 8B CF           mov         rcx,r15
  0000000000000043: 48 83 C9 0F        or          rcx,0Fh
  0000000000000047: 48 3B CB           cmp         rcx,rbx
  000000000000004A: 77 1F              ja          000000000000006B
  000000000000004C: 48 8B D5           mov         rdx,rbp
  000000000000004F: 48 8B C3           mov         rax,rbx
  0000000000000052: 48 D1 EA           shr         rdx,1
  0000000000000055: 48 2B C2           sub         rax,rdx
  0000000000000058: 48 3B E8           cmp         rbp,rax
  000000000000005B: 77 0E              ja          000000000000006B
  000000000000005D: 48 8D 04 2A        lea         rax,[rdx+rbp]
  0000000000000061: 48 8B D9           mov         rbx,rcx
  0000000000000064: 48 3B C8           cmp         rcx,rax
  0000000000000067: 48 0F 42 D8        cmovb       rbx,rax
  000000000000006B: 48 8D 4B 01        lea         rcx,[rbx+1]
  000000000000006F: 48 89 7C 24 58     mov         qword ptr [rsp+58h],rdi
  0000000000000074: 4C 89 64 24 60     mov         qword ptr [rsp+60h],r12
  0000000000000079: 48 81 F9 00 10 00  cmp         rcx,1000h
  0000000000000080: 72 2C              jb          00000000000000AE
  0000000000000082: 48 8D 41 27        lea         rax,[rcx+27h]
  0000000000000086: 48 3B C1           cmp         rax,rcx
  0000000000000089: 0F 86 E6 00 00 00  jbe         0000000000000175
  000000000000008F: 48 8B C8           mov         rcx,rax
  0000000000000092: E8 00 00 00 00     call        ??2@YAPEAX_K@Z
  0000000000000097: 48 85 C0           test        rax,rax
  000000000000009A: 0F 84 C9 00 00 00  je          0000000000000169
  00000000000000A0: 48 8D 78 27        lea         rdi,[rax+27h]
  00000000000000A4: 48 83 E7 E0        and         rdi,0FFFFFFFFFFFFFFE0h
  00000000000000A8: 48 89 47 F8        mov         qword ptr [rdi-8],rax
  00000000000000AC: EB 11              jmp         00000000000000BF
  00000000000000AE: 48 85 C9           test        rcx,rcx
  00000000000000B1: 74 0A              je          00000000000000BD
  00000000000000B3: E8 00 00 00 00     call        ??2@YAPEAX_K@Z
  00000000000000B8: 48 8B F8           mov         rdi,rax
  00000000000000BB: EB 02              jmp         00000000000000BF
  00000000000000BD: 33 FF              xor         edi,edi
  00000000000000BF: 4C 8B 64 24 70     mov         r12,qword ptr [rsp+70h]
  00000000000000C4: 4D 8B C6           mov         r8,r14
  00000000000000C7: 4C 89 7E 10        mov         qword ptr [rsi+10h],r15
  00000000000000CB: 4E 8D 3C 37        lea         r15,[rdi+r14]
  00000000000000CF: 48 89 5E 18        mov         qword ptr [rsi+18h],rbx
  00000000000000D3: 48 8B CF           mov         rcx,rdi
  00000000000000D6: 48 83 FD 10        cmp         rbp,10h
  00000000000000DA: 72 4D              jb          0000000000000129
  00000000000000DC: 48 8B 1E           mov         rbx,qword ptr [rsi]
  00000000000000DF: 48 8B D3           mov         rdx,rbx
  00000000000000E2: E8 00 00 00 00     call        memcpy
  00000000000000E7: 4D 8B C4           mov         r8,r12
  00000000000000EA: 49 8B D5           mov         rdx,r13
  00000000000000ED: 49 8B CF           mov         rcx,r15
  00000000000000F0: E8 00 00 00 00     call        memcpy
  00000000000000F5: 48 8D 55 01        lea         rdx,[rbp+1]
  00000000000000F9: 43 C6 04 27 00     mov         byte ptr [r15+r12],0
  00000000000000FE: 48 81 FA 00 10 00  cmp         rdx,1000h
  0000000000000105: 72 18              jb          000000000000011F
  0000000000000107: 48 8B 4B F8        mov         rcx,qword ptr [rbx-8]
  000000000000010B: 48 83 C2 27        add         rdx,27h
  000000000000010F: 48 2B D9           sub         rbx,rcx
  0000000000000112: 48 8D 43 F8        lea         rax,[rbx-8]
  0000000000000116: 48 83 F8 1F        cmp         rax,1Fh
  000000000000011A: 77 4D              ja          0000000000000169
  000000000000011C: 48 8B D9           mov         rbx,rcx
  000000000000011F: 48 8B CB           mov         rcx,rbx
  0000000000000122: E8 00 00 00 00     call        ??3@YAXPEAX_K@Z
  0000000000000127: EB 1B              jmp         0000000000000144
  0000000000000129: 48 8B D6           mov         rdx,rsi
  000000000000012C: E8 00 00 00 00     call        memcpy
  0000000000000131: 4D 8B C4           mov         r8,r12
  0000000000000134: 49 8B D5           mov         rdx,r13
  0000000000000137: 49 8B CF           mov         rcx,r15
  000000000000013A: E8 00 00 00 00     call        memcpy
  000000000000013F: 43 C6 04 27 00     mov         byte ptr [r15+r12],0
  0000000000000144: 48 89 3E           mov         qword ptr [rsi],rdi
  0000000000000147: 48 8B C6           mov         rax,rsi
  000000000000014A: 4C 8B 64 24 60     mov         r12,qword ptr [rsp+60h]
  000000000000014F: 48 8B 7C 24 58     mov         rdi,qword ptr [rsp+58h]
  0000000000000154: 48 8B 6C 24 50     mov         rbp,qword ptr [rsp+50h]
  0000000000000159: 4C 8B 7C 24 20     mov         r15,qword ptr [rsp+20h]
  000000000000015E: 48 83 C4 28        add         rsp,28h
  0000000000000162: 41 5E              pop         r14
  0000000000000164: 41 5D              pop         r13
  0000000000000166: 5E                 pop         rsi
  0000000000000167: 5B                 pop         rbx
  0000000000000168: C3                 ret
  0000000000000169: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  000000000000016E: CC                 int         3
  000000000000016F: E8 00 00 00 00     call        ?_Xlen@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@CAXXZ
  0000000000000174: CC                 int         3
  0000000000000175: E8 00 00 00 00     call        ?_Throw_bad_array_new_length@std@@YAXXZ
  000000000000017A: CC                 int         3
  000000000000013E: 48 8B 4D EF        mov         rcx,qword ptr [rbp-11h]
  0000000000000142: 48 8B 01           mov         rax,qword ptr [rcx]
  0000000000000145: 44 8B 45 E7        mov         r8d,dword ptr [rbp-19h]
  0000000000000149: 48 8D 55 E7        lea         rdx,[rbp-19h]
  000000000000014D: FF 50 10           call        qword ptr [rax+10h]
  0000000000000150: 90                 nop
  0000000000000151: 48 8D 55 E7        lea         rdx,[rbp-19h]
  0000000000000155: 48 83 7D FF 10     cmp         qword ptr [rbp-1],10h
  000000000000015A: 48 0F 43 55 E7     cmovae      rdx,qword ptr [rbp-19h]
  000000000000015F: 4C 8B 45 F7        mov         r8,qword ptr [rbp-9]
  0000000000000163: 48 8D 4D 07        lea         rcx,[rbp+7]
  0000000000000000: 48 89 74 24 10     mov         qword ptr [rsp+10h],rsi
  0000000000000005: 57                 push        rdi
  0000000000000006: 48 83 EC 30        sub         rsp,30h
  000000000000000A: 48 8B F9           mov         rdi,rcx
  000000000000000D: 49 8B F0           mov         rsi,r8
  0000000000000010: 48 8B 49 10        mov         rcx,qword ptr [rcx+10h]
  0000000000000014: 4C 8B 47 18        mov         r8,qword ptr [rdi+18h]
  0000000000000018: 49 8B C0           mov         rax,r8
  000000000000001B: 48 2B C1           sub         rax,rcx
  000000000000001E: 48 3B F0           cmp         rsi,rax
  0000000000000021: 77 3F              ja          0000000000000062
  0000000000000023: 48 89 5C 24 40     mov         qword ptr [rsp+40h],rbx
  0000000000000028: 48 8D 04 31        lea         rax,[rcx+rsi]
  000000000000002C: 48 89 47 10        mov         qword ptr [rdi+10h],rax
  0000000000000030: 48 8B C7           mov         rax,rdi
  0000000000000033: 49 83 F8 10        cmp         r8,10h
  0000000000000037: 72 03              jb          000000000000003C
  0000000000000039: 48 8B 07           mov         rax,qword ptr [rdi]
  000000000000003C: 48 8D 1C 08        lea         rbx,[rax+rcx]
  0000000000000040: 4C 8B C6           mov         r8,rsi
  0000000000000043: 48 8B CB           mov         rcx,rbx
  0000000000000046: E8 00 00 00 00     call        memmove
  000000000000004B: C6 04 33 00        mov         byte ptr [rbx+rsi],0
  000000000000004F: 48 8B C7           mov         rax,rdi
  0000000000000052: 48 8B 5C 24 40     mov         rbx,qword ptr [rsp+40h]
  0000000000000057: 48 8B 74 24 48     mov         rsi,qword ptr [rsp+48h]
  000000000000005C: 48 83 C4 30        add         rsp,30h
  0000000000000060: 5F                 pop         rdi
  0000000000000061: C3                 ret
  0000000000000062: 4C 8B CA           mov         r9,rdx
  0000000000000065: 48 89 74 24 20     mov         qword ptr [rsp+20h],rsi
  000000000000006A: 48 8B D6           mov         rdx,rsi
  000000000000006D: 45 33 C0           xor         r8d,r8d
  0000000000000070: 48 8B CF           mov         rcx,rdi
  0000000000000073: E8 00 00 00 00     call        ??$_Reallocate_grow_by@V<lambda_65e615be2a453ca0576c979606f46740>@@PEBD_K@?$basic_string@DU?$char_traits@D@std@@V?$allocator@D@2@@std@@AEAAAEAV01@_KV<lambda_65e615be2a453ca0576c979606f46740>@@PEBD_K@Z
  0000000000000078: 48 8B 74 24 48     mov         rsi,qword ptr [rsp+48h]
  000000000000007D: 48 83 C4 30        add         rsp,30h
  0000000000000081: 5F                 pop         rdi
  0000000000000082: C3                 ret
  000000000000016C: 90                 nop
  000000000000016D: 48 8B 55 FF        mov         rdx,qword ptr [rbp-1]
  0000000000000171: 48 83 FA 10        cmp         rdx,10h
  0000000000000175: 72 31              jb          00000000000001A8
  0000000000000177: 48 FF C2           inc         rdx
  000000000000017A: 48 8B 4D E7        mov         rcx,qword ptr [rbp-19h]
  000000000000017E: 48 8B C1           mov         rax,rcx
  0000000000000181: 48 81 FA 00 10 00  cmp         rdx,1000h
  0000000000000188: 72 19              jb          00000000000001A3
  000000000000018A: 48 83 C2 27        add         rdx,27h
  000000000000018E: 48 8B 49 F8        mov         rcx,qword ptr [rcx-8]
  0000000000000192: 48 2B C1           sub         rax,rcx
  0000000000000195: 48 83 C0 F8        add         rax,0FFFFFFFFFFFFFFF8h
  0000000000000199: 48 83 F8 1F        cmp         rax,1Fh
  000000000000019D: 0F 87 E9 00 00 00  ja          000000000000028C
  00000000000001A3: E8 00 00 00 00     call        ??3@YAXPEAX_K@Z
  00000000000001A8: 0F 10 45 07        movups      xmm0,xmmword ptr [rbp+7]
  00000000000001AC: 0F 11 45 27        movups      xmmword ptr [rbp+27h],xmm0
  00000000000001B0: 0F 10 4D 17        movups      xmm1,xmmword ptr [rbp+17h]
  00000000000001B4: 0F 11 4D 37        movups      xmmword ptr [rbp+37h],xmm1
  00000000000001B8: 48 C7 45 17 00 00  mov         qword ptr [rbp+17h],0
  00000000000001C0: 48 C7 45 1F 0F 00  mov         qword ptr [rbp+1Fh],0Fh
  00000000000001C8: C6 45 07 00        mov         byte ptr [rbp+7],0
  00000000000001CC: 4C 8D 45 27        lea         r8,[rbp+27h]
  00000000000001D0: 66 48 0F 7E C1     movq        rcx,xmm0
  00000000000001D5: 66 0F 73 D9 08     psrldq      xmm1,8
  00000000000001DA: 66 48 0F 7E C8     movq        rax,xmm1
  00000000000001DF: 48 83 F8 10        cmp         rax,10h
  00000000000001E3: 4C 0F 43 C1        cmovae      r8,rcx
  00000000000001E7: 48 8D 05 00 00 00  lea         rax,[??_7exception@std@@6B@]
  00000000000001EE: 49 89 06           mov         qword ptr [r14],rax
  00000000000001F1: 49 8D 56 08        lea         rdx,[r14+8]
  00000000000001F5: 0F 57 C0           xorps       xmm0,xmm0
  00000000000001F8: 0F 11 02           movups      xmmword ptr [rdx],xmm0
  00000000000001FB: 4C 89 45 E7        mov         qword ptr [rbp-19h],r8
  00000000000001FF: C6 45 EF 01        mov         byte ptr [rbp-11h],1
  0000000000000203: 48 8D 4D E7        lea         rcx,[rbp-19h]
  0000000000000207: E8 00 00 00 00     call        __std_exception_copy
  000000000000020C: 48 8D 05 00 00 00  lea         rax,[??_7runtime_error@std@@6B@]
  0000000000000213: 49 89 06           mov         qword ptr [r14],rax
  0000000000000216: 48 8B 55 3F        mov         rdx,qword ptr [rbp+3Fh]
  000000000000021A: 48 83 FA 10        cmp         rdx,10h
  000000000000021E: 72 2D              jb          000000000000024D
  0000000000000220: 48 FF C2           inc         rdx
  0000000000000223: 48 8B 4D 27        mov         rcx,qword ptr [rbp+27h]
  0000000000000227: 48 8B C1           mov         rax,rcx
  000000000000022A: 48 81 FA 00 10 00  cmp         rdx,1000h
  0000000000000231: 72 15              jb          0000000000000248
  0000000000000233: 48 83 C2 27        add         rdx,27h
  0000000000000237: 48 8B 49 F8        mov         rcx,qword ptr [rcx-8]
  000000000000023B: 48 2B C1           sub         rax,rcx
  000000000000023E: 48 83 C0 F8        add         rax,0FFFFFFFFFFFFFFF8h
  0000000000000242: 48 83 F8 1F        cmp         rax,1Fh
  0000000000000246: 77 38              ja          0000000000000280
  0000000000000248: E8 00 00 00 00     call        ??3@YAXPEAX_K@Z
  000000000000024D: 48 8D 05 00 00 00  lea         rax,[??_7_System_error@std@@6B@]
  0000000000000254: 49 89 06           mov         qword ptr [r14],rax
  0000000000000257: 41 0F 10 07        movups      xmm0,xmmword ptr [r15]
  000000000000025B: 41 0F 11 46 18     movups      xmmword ptr [r14+18h],xmm0
  0000000000000260: 49 8B C6           mov         rax,r14
  0000000000000263: 4C 8D 9C 24 90 00  lea         r11,[rsp+90h]
  000000000000026B: 49 8B 5B 20        mov         rbx,qword ptr [r11+20h]
  000000000000026F: 49 8B 73 28        mov         rsi,qword ptr [r11+28h]
  0000000000000273: 49 8B 7B 38        mov         rdi,qword ptr [r11+38h]
  0000000000000277: 49 8B E3           mov         rsp,r11
  000000000000027A: 41 5F              pop         r15
  000000000000027C: 41 5E              pop         r14
  000000000000027E: 5D                 pop         rbp
  000000000000027F: C3                 ret
  0000000000000280: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000285: CC                 int         3
  0000000000000286: E8 00 00 00 00     call        ?_Throw_bad_array_new_length@std@@YAXXZ
  000000000000028B: 90                 nop
  000000000000028C: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  0000000000000291: 90                 nop
  0000000000000056: 90                 nop
  0000000000000057: 48 8B 54 24 48     mov         rdx,qword ptr [rsp+48h]
  000000000000005C: 48 83 FA 10        cmp         rdx,10h
  0000000000000060: 72 2E              jb          0000000000000090
  0000000000000062: 48 FF C2           inc         rdx
  0000000000000065: 48 8B 4C 24 30     mov         rcx,qword ptr [rsp+30h]
  000000000000006A: 48 8B C1           mov         rax,rcx
  000000000000006D: 48 81 FA 00 10 00  cmp         rdx,1000h
  0000000000000074: 72 15              jb          000000000000008B
  0000000000000076: 48 83 C2 27        add         rdx,27h
  000000000000007A: 48 8B 49 F8        mov         rcx,qword ptr [rcx-8]
  000000000000007E: 48 2B C1           sub         rax,rcx
  0000000000000081: 48 83 C0 F8        add         rax,0FFFFFFFFFFFFFFF8h
  0000000000000085: 48 83 F8 1F        cmp         rax,1Fh
  0000000000000089: 77 1D              ja          00000000000000A8
  000000000000008B: E8 00 00 00 00     call        ??3@YAXPEAX_K@Z
  0000000000000090: 48 8D 05 00 00 00  lea         rax,[??_7system_error@std@@6B@]
  0000000000000097: 48 89 07           mov         qword ptr [rdi],rax
  000000000000009A: 48 8B C7           mov         rax,rdi
  000000000000009D: 48 8B 5C 24 60     mov         rbx,qword ptr [rsp+60h]
  00000000000000A2: 48 83 C4 50        add         rsp,50h
  00000000000000A6: 5F                 pop         rdi
  00000000000000A7: C3                 ret
  00000000000000A8: E8 00 00 00 00     call        _invalid_parameter_noinfo_noreturn
  00000000000000AD: CC                 int         3
  000000000000001B: 48 8D 15 00 00 00  lea         rdx,[_TI4?AVsystem_error@std@@]
  0000000000000022: 48 8D 4C 24 30     lea         rcx,[rsp+30h]
  0000000000000027: E8 00 00 00 00     call        _CxxThrowException
  000000000000002C: CC                 int         3
  00000000000000B0: CC                 int         3
  00000000000000B1: E8 00 00 00 00     call        terminate
  00000000000000B6: CC                 int         3
