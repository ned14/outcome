  0000000000000000: 56                 push        rsi
  0000000000000001: 48 83 EC 40        sub         rsp,40h
  0000000000000005: 48 89 CE           mov         rsi,rcx
  0000000000000008: 48 8D 4C 24 20     lea         rcx,[rsp+20h]
  000000000000000D: E8 00 00 00 00     call        ?unknown@@YA?AV?$basic_monad@U?$monad_policy@H@policy@_1_0_std_std_9274c0d4@outcome@boost@@@_1_0_std_std_9274c0d4@outcome@boost@@XZ
  0000000000000012: 8A 44 24 38        mov         al,byte ptr [rsp+38h]
  0000000000000016: 3C 03              cmp         al,3
  0000000000000018: 74 15              je          000000000000002F
  000000000000001A: 3C 02              cmp         al,2
  000000000000001C: 74 28              je          0000000000000046
  000000000000001E: 3C 01              cmp         al,1
  0000000000000020: 75 3B              jne         000000000000005D
  0000000000000022: 6B 44 24 20 03     imul        eax,dword ptr [rsp+20h],3
  0000000000000027: 89 06              mov         dword ptr [rsi],eax
  0000000000000029: C6 46 18 01        mov         byte ptr [rsi+18h],1
  000000000000002D: EB 4F              jmp         000000000000007E
  000000000000002F: 48 8D 54 24 20     lea         rdx,[rsp+20h]
  0000000000000034: 48 89 F1           mov         rcx,rsi
  0000000000000037: E8 00 00 00 00     call        ?__ExceptionPtrCopy@@YAXPEAXPEBX@Z
  000000000000003C: C6 46 18 03        mov         byte ptr [rsi+18h],3
  0000000000000040: 8A 44 24 38        mov         al,byte ptr [rsp+38h]
  0000000000000044: EB 21              jmp         0000000000000067
  0000000000000046: 48 8B 44 24 30     mov         rax,qword ptr [rsp+30h]
  000000000000004B: 48 89 46 10        mov         qword ptr [rsi+10h],rax
  000000000000004F: 0F 10 44 24 20     movups      xmm0,xmmword ptr [rsp+20h]
  0000000000000054: 0F 11 06           movups      xmmword ptr [rsi],xmm0
  0000000000000057: C6 46 18 02        mov         byte ptr [rsi+18h],2
  000000000000005B: EB 21              jmp         000000000000007E
  000000000000005D: 0F 57 C0           xorps       xmm0,xmm0
  0000000000000060: 0F 11 46 10        movups      xmmword ptr [rsi+10h],xmm0
  0000000000000064: 0F 11 06           movups      xmmword ptr [rsi],xmm0
  0000000000000067: 89 C1              mov         ecx,eax
  0000000000000069: FE C9              dec         cl
  000000000000006B: 80 F9 02           cmp         cl,2
  000000000000006E: 72 0E              jb          000000000000007E
  0000000000000070: 3C 03              cmp         al,3
  0000000000000072: 75 0F              jne         0000000000000083
  0000000000000074: 48 8D 4C 24 20     lea         rcx,[rsp+20h]
  0000000000000079: E8 00 00 00 00     call        ?__ExceptionPtrDestroy@@YAXPEAX@Z
  000000000000007E: C6 44 24 38 00     mov         byte ptr [rsp+38h],0
  0000000000000083: 48 89 F0           mov         rax,rsi
  0000000000000086: 48 83 C4 40        add         rsp,40h
  000000000000008A: 5E                 pop         rsi
  000000000000008B: C3                 ret
  000000000000008C: 0F 1F 40 00        nop         dword ptr [rax]
