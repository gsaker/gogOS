[bits 32]
; First make the ISRs global

[extern main] ; Define calling point. Must have same name as kernel.c 'main' function
call main ; Calls the C function. The linker will know where it is placed in memory
hlt
jmp $
; Defined in isr.c
