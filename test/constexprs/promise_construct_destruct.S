	.file	"promise_construct_destruct.cpp"
 # GNU C++ (i686-posix-dwarf-rev3, Built by MinGW-W64 project) version 4.9.1 (i686-w64-mingw32)
 #	compiled by GNU C version 4.9.1, GMP version 6.0.0, MPFR version 3.1.2-p9, MPC version 1.0.2
 # warning: MPFR header version 3.1.2-p9 differs from library version 3.1.2-p10.
 # GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
 # options passed:  -I ../../include/boost/spinlock/bindlib/include
 # -iprefix c:/Program Files/mingw-w64/i686-4.9.1-posix-dwarf-rt_v3-rev3/mingw32/bin/../lib/gcc/i686-w64-mingw32/4.9.1/
 # -D_REENTRANT -D BOOST_SPINLOCK_STANDALONE=1
 # promise_construct_destruct.cpp -mtune=generic -march=i686
 # -auxbase-strip promise_construct_destruct.S -O3 -std=c++1y -fverbose-asm
 # options enabled:  -faggressive-loop-optimizations
 # -fasynchronous-unwind-tables -fauto-inc-dec -fbranch-count-reg
 # -fcaller-saves -fcombine-stack-adjustments -fcommon -fcompare-elim
 # -fcprop-registers -fcrossjumping -fcse-follow-jumps -fdefer-pop
 # -fdelete-null-pointer-checks -fdevirtualize -fdevirtualize-speculatively
 # -fdwarf2-cfi-asm -fearly-inlining -feliminate-unused-debug-types
 # -fexceptions -fexpensive-optimizations -fforward-propagate
 # -ffunction-cse -fgcse -fgcse-after-reload -fgcse-lm -fgnu-runtime
 # -fgnu-unique -fguess-branch-probability -fhoist-adjacent-loads -fident
 # -fif-conversion -fif-conversion2 -findirect-inlining -finline
 # -finline-atomics -finline-functions -finline-functions-called-once
 # -finline-small-functions -fipa-cp -fipa-cp-clone -fipa-profile
 # -fipa-pure-const -fipa-reference -fipa-sra -fira-hoist-pressure
 # -fira-share-save-slots -fira-share-spill-slots
 # -fisolate-erroneous-paths-dereference -fivopts -fkeep-inline-dllexport
 # -fkeep-static-consts -fleading-underscore -fmath-errno -fmerge-constants
 # -fmerge-debug-strings -fmove-loop-invariants -fomit-frame-pointer
 # -foptimize-sibling-calls -foptimize-strlen -fpartial-inlining -fpeephole
 # -fpeephole2 -fpredictive-commoning -fprefetch-loop-arrays -free
 # -freg-struct-return -freorder-blocks -freorder-blocks-and-partition
 # -freorder-functions -frerun-cse-after-loop
 # -fsched-critical-path-heuristic -fsched-dep-count-heuristic
 # -fsched-group-heuristic -fsched-interblock -fsched-last-insn-heuristic
 # -fsched-rank-heuristic -fsched-spec -fsched-spec-insn-heuristic
 # -fsched-stalled-insns-dep -fschedule-insns2 -fset-stack-executable
 # -fshow-column -fshrink-wrap -fsigned-zeros -fsplit-ivs-in-unroller
 # -fsplit-wide-types -fstrict-aliasing -fstrict-overflow
 # -fstrict-volatile-bitfields -fsync-libcalls -fthread-jumps
 # -ftoplevel-reorder -ftrapping-math -ftree-bit-ccp
 # -ftree-builtin-call-dce -ftree-ccp -ftree-ch -ftree-coalesce-vars
 # -ftree-copy-prop -ftree-copyrename -ftree-cselim -ftree-dce
 # -ftree-dominator-opts -ftree-dse -ftree-forwprop -ftree-fre
 # -ftree-loop-distribute-patterns -ftree-loop-if-convert -ftree-loop-im
 # -ftree-loop-ivcanon -ftree-loop-optimize -ftree-loop-vectorize
 # -ftree-parallelize-loops= -ftree-partial-pre -ftree-phiprop -ftree-pre
 # -ftree-pta -ftree-reassoc -ftree-scev-cprop -ftree-sink
 # -ftree-slp-vectorize -ftree-slsr -ftree-sra -ftree-switch-conversion
 # -ftree-tail-merge -ftree-ter -ftree-vrp -funit-at-a-time
 # -funswitch-loops -funwind-tables -fverbose-asm -fzero-initialized-in-bss
 # -m32 -m80387 -m96bit-long-double -maccumulate-outgoing-args
 # -malign-double -malign-stringops -mavx256-split-unaligned-load
 # -mavx256-split-unaligned-store -mfancy-math-387 -mfp-ret-in-387
 # -mieee-fp -mlong-double-80 -mms-bitfields -mno-red-zone -mno-sse4
 # -mpush-args -msahf -mstack-arg-probe -mvzeroupper

	.section	.text.unlikely,"x"
LCOLDB0:
	.text
LHOTB0:
	.p2align 4,,15
	.globl	__Z5test1v
	.def	__Z5test1v;	.scl	2;	.type	32;	.endef
__Z5test1v:
LFB3592:
	.cfi_startproc
	subl	$28, %esp	 #,
	.cfi_def_cfa_offset 32
	addl	$28, %esp	 #,
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE3592:
	.section	.text.unlikely,"x"
LCOLDE0:
	.text
LHOTE0:
	.section	.text.unlikely,"x"
LCOLDB1:
	.text
LHOTB1:
	.p2align 4,,15
	.globl	__Z5test2v
	.def	__Z5test2v;	.scl	2;	.type	32;	.endef
__Z5test2v:
LFB3599:
	.cfi_startproc
	rep ret
	.cfi_endproc
LFE3599:
	.section	.text.unlikely,"x"
LCOLDE1:
	.text
LHOTE1:
	.def	___main;	.scl	2;	.type	32;	.endef
	.section	.text.unlikely,"x"
LCOLDB2:
	.section	.text.startup,"x"
LHOTB2:
	.p2align 4,,15
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB3600:
	.cfi_startproc
	pushl	%ebp	 #
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp	 #,
	.cfi_def_cfa_register 5
	andl	$-16, %esp	 #,
	call	___main	 #
	call	__Z5test1v	 #
	xorl	%eax, %eax	 #
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE3600:
	.section	.text.unlikely,"x"
LCOLDE2:
	.section	.text.startup,"x"
LHOTE2:
	.ident	"GCC: (i686-posix-dwarf-rev3, Built by MinGW-W64 project) 4.9.1"
