[org 0x7c00] ; set offset
mov bp, 0x8000 ; set start of stack
mov sp,bp ; set stack topU'RE

mov bx, 0x9000 ; es:bx = 0x09000

mov dh, 2 ;2 sectors
call diskLoad

mov dx, [0x9000] ; retrieve first loaded value
call printHex

call printNewLine

mov dx, [0x9000 + 512] ; first word from second loaded sector, 0xface
call printHex

jmp $

%include "printString.asm"
%include "diskReading.asm"

mov dx, []