[org 0x7c00]
KERNEL_OFFSET equ 0x1000 ; The same one we used when linking the kernel
    mov [BOOT_DRIVE], dl ; set boot drive, this is set by BIOS in dl

    mov bp, 0x9000
    mov sp, bp ;set up stack

    mov bx, MSG_16_MODE
    call printString16
    call printNewLine16
    call loadKernel
    call switch32
    jmp $

%include "printString16.asm"
%include "diskReading.asm"
%include "gdt.asm"
%include "printString.asm"
%include "switch32.asm"
%include "printHex16.asm"

BOOT_DRIVE db 0 ; It is a good idea to store it in memory because 'dl' may get overwritten
MSG_16_MODE db "Started in 16-bit Real Mode", 0
MSG_32_MODE db "Landed in 32-bit Protected Mode", 0
MSG_LOAD_KERNEL db "Loading kernel into memory", 0
[bits 16]
loadKernel:
    mov bx, MSG_LOAD_KERNEL
    call printString16
    call printNewLine16

    mov bx, KERNEL_OFFSET ; set to place where kernel is stored
    mov dh, 2 
    mov dl, [BOOT_DRIVE] ; set to boot drive
    call loadDisk
    ret
[bits 32]
BEGIN_32:
    mov ebx, MSG_32_MODE
    call printString ;print
    call KERNEL_OFFSET ;pass to kernel
    jmp $ ; back here whern kernel has finished
times 510 - ($-$$) db 0
dw 0xaa55