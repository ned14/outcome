  0000000000000000: 40 53              push        rbx
  0000000000000002: 48 83 EC 40        sub         rsp,40h
  0000000000000006: 48 8B D9           mov         rbx,rcx
  0000000000000009: 48 8D 4C 24 20     lea         rcx,[rsp+20h]
  0000000000000000: 48 89 5C 24 08     mov         qword ptr [rsp+8],rbx
  0000000000000005: 48 89 74 24 10     mov         qword ptr [rsp+10h],rsi
  000000000000000A: 57                 push        rdi
  000000000000000B: 48 83 EC 30        sub         rsp,30h
  000000000000000F: 0F B6 1D 00 00 00  movzx       ebx,byte ptr [??$in_place_type@Verror_code@std@@@std@@3U?$in_place_type_t@Verror_code@std@@@1@B]
  0000000000000016: 48 8D 35 00 00 00  lea         rsi,[?_Storage@?1???$_Immortalize@V_Generic_error_category@std@@@std@@YAAEAV_Generic_error_category@1@XZ@4T?$_Align_type@N$0BA@@1@A]
  000000000000001D: 48 8B F9           mov         rdi,rcx
  0000000000000020: 48 8D 15 00 00 00  lea         rdx,[??$_Immortalize_impl@V_Generic_error_category@std@@@std@@YAHPEAX0PEAPEAX@Z]
  0000000000000027: 4C 8B C6           mov         r8,rsi
  000000000000002A: 48 8D 0D 00 00 00  lea         rcx,[?_Flag@?1???$_Immortalize@V_Generic_error_category@std@@@std@@YAAEAV_Generic_error_category@1@XZ@4PEAXEA]
  0000000000000031: E8 00 00 00 00     call        ?_Execute_once@std@@YAHAEAUonce_flag@1@P6AHPEAX1PEAPEAX@Z1@Z
  0000000000000036: 85 C0              test        eax,eax
  0000000000000038: 74 30              je          000000000000006A
  000000000000003A: 4C 8D 44 24 20     lea         r8,[rsp+20h]
  000000000000003F: C7 44 24 20 21 00  mov         dword ptr [rsp+20h],21h
  0000000000000047: 0F B6 D3           movzx       edx,bl
  000000000000004A: 48 89 74 24 28     mov         qword ptr [rsp+28h],rsi
  000000000000004F: 48 8B CF           mov         rcx,rdi
  0000000000000000: 48 89 5C 24 10     mov         qword ptr [rsp+10h],rbx
  0000000000000005: 57                 push        rdi
  0000000000000006: 48 83 EC 20        sub         rsp,20h
  000000000000000A: 48 8B D9           mov         rbx,rcx
  000000000000000D: C7 44 24 30 02 00  mov         dword ptr [rsp+30h],2
  0000000000000015: 8B 44 24 30        mov         eax,dword ptr [rsp+30h]
  0000000000000019: 48 8D 15 00 00 00  lea         rdx,[??$_Immortalize_impl@V_Generic_error_category@std@@@std@@YAHPEAX0PEAPEAX@Z]
  0000000000000020: 89 41 04           mov         dword ptr [rcx+4],eax
  0000000000000023: 41 0F 10 00        movups      xmm0,xmmword ptr [r8]
  0000000000000027: 4C 8D 05 00 00 00  lea         r8,[?_Storage@?1???$_Immortalize@V_Generic_error_category@std@@@std@@YAAEAV_Generic_error_category@1@XZ@4T?$_Align_type@N$0BA@@1@A]
  000000000000002E: 0F 11 41 08        movups      xmmword ptr [rcx+8],xmm0
  0000000000000032: 48 8B 79 10        mov         rdi,qword ptr [rcx+10h]
  0000000000000036: 48 8D 0D 00 00 00  lea         rcx,[?_Flag@?1???$_Immortalize@V_Generic_error_category@std@@@std@@YAAEAV_Generic_error_category@1@XZ@4PEAXEA]
  000000000000003D: E8 00 00 00 00     call        ?_Execute_once@std@@YAHAEAUonce_flag@1@P6AHPEAX1PEAPEAX@Z1@Z
  0000000000000042: 85 C0              test        eax,eax
  0000000000000044: 74 20              je          0000000000000066
  0000000000000046: 48 8B 05 08 00 00  mov         rax,qword ptr [?_Storage@?1???$_Immortalize@V_Generic_error_category@std@@@std@@YAAEAV_Generic_error_category@1@XZ@4T?$_Align_type@N$0BA@@1@A+8]
  000000000000004D: 48 39 47 08        cmp         qword ptr [rdi+8],rax
  0000000000000051: 75 05              jne         0000000000000058
  0000000000000053: 66 83 4B 04 10     or          word ptr [rbx+4],10h
  0000000000000058: 48 8B C3           mov         rax,rbx
  000000000000005B: 48 8B 5C 24 38     mov         rbx,qword ptr [rsp+38h]
  0000000000000060: 48 83 C4 20        add         rsp,20h
  0000000000000064: 5F                 pop         rdi
  0000000000000065: C3                 ret
  0000000000000066: E8 00 00 00 00     call        terminate
  000000000000006B: CC                 int         3
  0000000000000057: 48 8B 5C 24 40     mov         rbx,qword ptr [rsp+40h]
  000000000000005C: 48 8B C7           mov         rax,rdi
  000000000000005F: 48 8B 74 24 48     mov         rsi,qword ptr [rsp+48h]
  0000000000000064: 48 83 C4 30        add         rsp,30h
  0000000000000068: 5F                 pop         rdi
  0000000000000069: C3                 ret
  000000000000006A: E8 00 00 00 00     call        terminate
  000000000000006F: CC                 int         3
  0000000000000013: F6 44 24 24 01     test        byte ptr [rsp+24h],1
  0000000000000018: 74 4E              je          0000000000000068
  000000000000001A: 8B 44 24 20        mov         eax,dword ptr [rsp+20h]
  000000000000001E: 48 8D 15 00 00 00  lea         rdx,[??$_Immortalize_impl@V_System_error_category@std@@@std@@YAHPEAX0PEAPEAX@Z]
  0000000000000025: 33 C9              xor         ecx,ecx
  0000000000000027: 48 89 7C 24 50     mov         qword ptr [rsp+50h],rdi
  000000000000002C: 89 0D 00 00 00 00  mov         dword ptr [?foo@@3HA],ecx
  0000000000000032: 48 8D 3D 00 00 00  lea         rdi,[?_Storage@?1???$_Immortalize@V_System_error_category@std@@@std@@YAAEAV_System_error_category@1@XZ@4T?$_Align_type@N$0BA@@1@A]
  0000000000000039: 4C 8B C7           mov         r8,rdi
  000000000000003C: 89 03              mov         dword ptr [rbx],eax
  000000000000003E: 48 8D 0D 00 00 00  lea         rcx,[?_Flag@?1???$_Immortalize@V_System_error_category@std@@@std@@YAAEAV_System_error_category@1@XZ@4PEAXEA]
  0000000000000045: 48 C7 43 04 01 00  mov         qword ptr [rbx+4],1
  000000000000004D: E8 00 00 00 00     call        ?_Execute_once@std@@YAHAEAUonce_flag@1@P6AHPEAX1PEAPEAX@Z1@Z
  0000000000000052: 85 C0              test        eax,eax
  0000000000000054: 74 39              je          000000000000008F
  0000000000000056: 48 89 7B 10        mov         qword ptr [rbx+10h],rdi
  000000000000005A: 48 8B C3           mov         rax,rbx
  000000000000005D: 48 8B 7C 24 50     mov         rdi,qword ptr [rsp+50h]
  0000000000000062: 48 83 C4 40        add         rsp,40h
  0000000000000066: 5B                 pop         rbx
  0000000000000067: C3                 ret
  0000000000000068: 0F 10 44 24 28     movups      xmm0,xmmword ptr [rsp+28h]
  000000000000006D: 0F B6 15 00 00 00  movzx       edx,byte ptr [??$in_place_type@Verror_code@std@@@std@@3U?$in_place_type_t@Verror_code@std@@@1@B]
  0000000000000074: 4C 8D 44 24 20     lea         r8,[rsp+20h]
  0000000000000079: 48 8B CB           mov         rcx,rbx
  000000000000007C: 0F 11 44 24 20     movups      xmmword ptr [rsp+20h],xmm0
  0000000000000000: 48 89 5C 24 10     mov         qword ptr [rsp+10h],rbx
  0000000000000005: 57                 push        rdi
  0000000000000006: 48 83 EC 20        sub         rsp,20h
  000000000000000A: 48 8B D9           mov         rbx,rcx
  000000000000000D: C7 44 24 30 02 00  mov         dword ptr [rsp+30h],2
  0000000000000015: 8B 44 24 30        mov         eax,dword ptr [rsp+30h]
  0000000000000019: 48 8D 15 00 00 00  lea         rdx,[??$_Immortalize_impl@V_Generic_error_category@std@@@std@@YAHPEAX0PEAPEAX@Z]
  0000000000000020: 89 41 04           mov         dword ptr [rcx+4],eax
  0000000000000023: 41 0F 10 00        movups      xmm0,xmmword ptr [r8]
  0000000000000027: 4C 8D 05 00 00 00  lea         r8,[?_Storage@?1???$_Immortalize@V_Generic_error_category@std@@@std@@YAAEAV_Generic_error_category@1@XZ@4T?$_Align_type@N$0BA@@1@A]
  000000000000002E: 0F 11 41 08        movups      xmmword ptr [rcx+8],xmm0
  0000000000000032: 48 8B 79 10        mov         rdi,qword ptr [rcx+10h]
  0000000000000036: 48 8D 0D 00 00 00  lea         rcx,[?_Flag@?1???$_Immortalize@V_Generic_error_category@std@@@std@@YAAEAV_Generic_error_category@1@XZ@4PEAXEA]
  000000000000003D: E8 00 00 00 00     call        ?_Execute_once@std@@YAHAEAUonce_flag@1@P6AHPEAX1PEAPEAX@Z1@Z
  0000000000000042: 85 C0              test        eax,eax
  0000000000000044: 74 20              je          0000000000000066
  0000000000000046: 48 8B 05 08 00 00  mov         rax,qword ptr [?_Storage@?1???$_Immortalize@V_Generic_error_category@std@@@std@@YAAEAV_Generic_error_category@1@XZ@4T?$_Align_type@N$0BA@@1@A+8]
  000000000000004D: 48 39 47 08        cmp         qword ptr [rdi+8],rax
  0000000000000051: 75 05              jne         0000000000000058
  0000000000000053: 66 83 4B 04 10     or          word ptr [rbx+4],10h
  0000000000000058: 48 8B C3           mov         rax,rbx
  000000000000005B: 48 8B 5C 24 38     mov         rbx,qword ptr [rsp+38h]
  0000000000000060: 48 83 C4 20        add         rsp,20h
  0000000000000064: 5F                 pop         rdi
  0000000000000065: C3                 ret
  0000000000000066: E8 00 00 00 00     call        terminate
  000000000000006B: CC                 int         3
  0000000000000086: 48 8B C3           mov         rax,rbx
  0000000000000089: 48 83 C4 40        add         rsp,40h
  000000000000008D: 5B                 pop         rbx
  000000000000008E: C3                 ret
  000000000000008F: E8 00 00 00 00     call        terminate
  0000000000000094: CC                 int         3
