[org 0x7c00] ; set offset
mov bp, 0x8000 ; set start of stack
mov sp,bp ; set stack topU'RE

mov bx, 0x9000 ; es:bx = 0x09000

mov dh, 2 ;2 sectors
call loadDisk

mov dx, [0x9000] ; retrieve first loaded value
call printHex

call printNewLine

mov dx, [0x9000 + 512] ; first word from second loaded sector, 0xface
call printHex

jmp $

%include "printString.asm"
%include "diskReading.asm"

times 510 - ($-$$) db 0
dw 0xaa55

; boot sector = sector 1 of cyl 0 of head 0 of hdd 0
; from now on = sector 2 ...
times 256 dw 0xdada ; sector 2 = 512 bytes
times 256 dw 0xface ; sector 3 = 512 bytes
