; steps:
;    Disable interrupts
;    Load our GDT
;    Set a bit on the CPU control register cr0
;    Flush the CPU pipeline by issuing a carefully crafted far jump
;    Update all the segment registers
;    Update the stack
;    Call to a well-known label which contains the first useful code in 32 bits
[org 0x7c00]
mov bp, 0x9000 ; set stack
mov sp, bp ; set stack base
mov bx, MSG_16_MODE
call printString16
call switch32


jmp $ ; never run
%include 'printString16.asm'
%include 'gdt.asm'
%include 'switch32.asm'
%include 'printString.asm'

BEGIN_32:
    mov ebx, MSG_32_MODE
    call printString
    call clearScreen
    ;call printString
    jmp $

MSG_16_MODE db "Started in 16-bit real mode", 0
MSG_32_MODE db "Loaded 32-bit protected mode", 0

; bootsector
times 510-($-$$) db 0
dw 0xaa55