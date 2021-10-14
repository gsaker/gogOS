mov ah, 0x0e ; sets BIOS to teletype mode

mov al, the_secret ; doesn't work asthis returns the memory adress of the_secret
int 0x10 

mov al, [the_secret] ; also doesn't work, this looks for the memory adress from the start of memory
int 0x10 ; we need to offset by 0x7c00

;These will print a random ascii character from the BIOS

mov bx, the_secret
add bx, 0x7c00
mov al, [bx] ; this works as we have added 0x7c00 to the offset
int 0x10

mov al, [0x7c0f] ;this is the exact memory adress of the_secret
int 0x10

jmp $

the_secret:
    db 'X' ; db = allocates and stores some data

times 510-($-$$) db 0 ; fill rest of boot sector with zeroes

dw 0xaa55 ; magic number!