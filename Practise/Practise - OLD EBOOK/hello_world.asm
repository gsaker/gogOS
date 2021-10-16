mov ah, 0x0e ; sets BIOS to teletype mode

mov al, 'H' ; set lower value to ASCII 'h'
int 0x10 ; interrupt 0x10 to print value
mov al, 'e'
int 0x10
mov al, 'l'
int 0x10
mov al, 'l'
int 0x10
mov al, 'o'
int 0x10

jmp $ ; jump to current adress, this doesn't appear to be needed??

times 510-($-$$) db 0 ; fill rest of boot sector with zeroes

dw 0xaa55 ; magic number!