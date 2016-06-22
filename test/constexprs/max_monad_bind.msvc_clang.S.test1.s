  0000000000000000: 56                 push        rsi
  0000000000000001: 48 83 EC 40        sub         rsp,40h
  0000000000000005: 48 89 CE           mov         rsi,rcx
  0000000000000008: 48 8D 4C 24 20     lea         rcx,[rsp+20h]
  000000000000000D: E8 00 00 00 00     call        ?unknown@@YA?AV?$basic_monad@U?$monad_policy@H@detail@v1_std_std@outcome@boost@@@v1_std_std@outcome@boost@@XZ
  0000000000000012: 8A 44 24 38        mov         al,byte ptr [rsp+38h]
  0000000000000016: 3C 03              cmp         al,3
  0000000000000018: 74 17              je          0000000000000031
  000000000000001A: 3C 02              cmp         al,2
  000000000000001C: 74 2A              je          0000000000000048
  000000000000001E: 3C 01              cmp         al,1
  0000000000000020: 75 3F              jne         0000000000000061
  0000000000000022: 6B 44 24 20 03     imul        eax,dword ptr [rsp+20h],3
  0000000000000027: 89 06              mov         dword ptr [rsi],eax
  0000000000000029: C6 46 18 01        mov         byte ptr [rsi+18h],1
  000000000000002D: B0 01              mov         al,1
  000000000000002F: EB 3A              jmp         000000000000006B
  0000000000000031: 48 8D 54 24 20     lea         rdx,[rsp+20h]
  0000000000000036: 48 89 F1           mov         rcx,rsi
  0000000000000039: E8 00 00 00 00     call        ?__ExceptionPtrCopy@@YAXPEAXPEBX@Z
  000000000000003E: C6 46 18 03        mov         byte ptr [rsi+18h],3
  0000000000000042: 8A 44 24 38        mov         al,byte ptr [rsp+38h]
  0000000000000046: EB 23              jmp         000000000000006B
  0000000000000048: 48 8B 44 24 30     mov         rax,qword ptr [rsp+30h]
  000000000000004D: 48 89 46 10        mov         qword ptr [rsi+10h],rax
  0000000000000051: 0F 10 44 24 20     movups      xmm0,xmmword ptr [rsp+20h]
  0000000000000056: 0F 11 06           movups      xmmword ptr [rsi],xmm0
  0000000000000059: C6 46 18 02        mov         byte ptr [rsi+18h],2
  000000000000005D: B0 02              mov         al,2
  000000000000005F: EB 0A              jmp         000000000000006B
  0000000000000061: 0F 57 C0           xorps       xmm0,xmm0
  0000000000000064: 0F 11 46 10        movups      xmmword ptr [rsi+10h],xmm0
  0000000000000068: 0F 11 06           movups      xmmword ptr [rsi],xmm0
  000000000000006B: 3C 03              cmp         al,3
  000000000000006D: 74 0F              je          000000000000007E
  000000000000006F: 0F B6 C0           movzx       eax,al
  0000000000000072: 83 F8 02           cmp         eax,2
  0000000000000075: 74 11              je          0000000000000088
  0000000000000077: 83 F8 01           cmp         eax,1
  000000000000007A: 74 0C              je          0000000000000088
  000000000000007C: EB 0F              jmp         000000000000008D
  000000000000007E: 48 8D 4C 24 20     lea         rcx,[rsp+20h]
  0000000000000083: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  0000000000000088: C6 44 24 38 00     mov         byte ptr [rsp+38h],0
  000000000000008D: 48 89 F0           mov         rax,rsi
  0000000000000090: 48 83 C4 40        add         rsp,40h
  0000000000000094: 5E                 pop         rsi
  0000000000000095: C3                 ret
  0000000000000096: 66 2E 0F 1F 84 00  nop         word ptr cs:[rax+rax]
                    00 00 00 00
