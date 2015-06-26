  0000000000000000: 48 83 EC 48        sub         rsp,48h
  0000000000000004: 48 C7 04 24 FE FF  mov         qword ptr [rsp],0FFFFFFFFFFFFFFFEh
                    FF FF
  000000000000000C: B8 05 00 00 00     mov         eax,5
  0000000000000011: 48 83 C4 48        add         rsp,48h
  0000000000000015: C3                 ret
