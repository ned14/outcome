  0000000000000000: 40 53              push        rbx
  0000000000000002: 48 83 EC 40        sub         rsp,40h
  0000000000000006: 48 8B D9           mov         rbx,rcx
  0000000000000009: 48 8D 4C 24 20     lea         rcx,[rsp+20h]
  0000000000000000: 48 8D 05 00 00 00  lea         rax,[?generic_code_domain@system_error2@@3V_generic_code_domain@1@B]
  0000000000000007: C7 41 04 02 00 00  mov         dword ptr [rcx+4],2
  000000000000000E: 48 89 41 08        mov         qword ptr [rcx+8],rax
  0000000000000012: 48 8B C1           mov         rax,rcx
  0000000000000015: 48 C7 41 10 21 00  mov         qword ptr [rcx+10h],21h
  000000000000001D: C3                 ret
  0000000000000013: F6 44 24 24 01     test        byte ptr [rsp+24h],1
  0000000000000018: 74 41              je          000000000000005B
  000000000000001A: 8B 44 24 20        mov         eax,dword ptr [rsp+20h]
  000000000000001E: 33 C9              xor         ecx,ecx
  0000000000000020: 89 0D 00 00 00 00  mov         dword ptr [?foo@@3HA],ecx
  0000000000000026: 89 03              mov         dword ptr [rbx],eax
  0000000000000028: C7 43 04 01 00 00  mov         dword ptr [rbx+4],1
  000000000000002F: 48 89 4B 08        mov         qword ptr [rbx+8],rcx
  0000000000000033: 48 89 4B 10        mov         qword ptr [rbx+10h],rcx
  0000000000000037: 48 8B 4C 24 28     mov         rcx,qword ptr [rsp+28h]
  000000000000003C: 48 85 C9           test        rcx,rcx
  000000000000003F: 74 33              je          0000000000000074
  0000000000000041: 48 8B 01           mov         rax,qword ptr [rcx]
  0000000000000044: 48 8D 54 24 28     lea         rdx,[rsp+28h]
  0000000000000049: 41 B8 10 00 00 00  mov         r8d,10h
  000000000000004F: FF 50 38           call        qword ptr [rax+38h]
  0000000000000052: 48 8B C3           mov         rax,rbx
  0000000000000055: 48 83 C4 40        add         rsp,40h
  0000000000000059: 5B                 pop         rbx
  000000000000005A: C3                 ret
  000000000000005B: 48 8B 44 24 28     mov         rax,qword ptr [rsp+28h]
  0000000000000060: C7 43 04 02 00 00  mov         dword ptr [rbx+4],2
  0000000000000067: 48 89 43 08        mov         qword ptr [rbx+8],rax
  000000000000006B: 48 8B 44 24 30     mov         rax,qword ptr [rsp+30h]
  0000000000000070: 48 89 43 10        mov         qword ptr [rbx+10h],rax
  0000000000000074: 48 8B C3           mov         rax,rbx
  0000000000000077: 48 83 C4 40        add         rsp,40h
  000000000000007B: 5B                 pop         rbx
  000000000000007C: C3                 ret
