mov ah, 0x0e
[org 0x7c00]
; This instruction sets memory offset to start of boot sector
; this will cause attempt 2 to and 4 to work
; without attempt 3 and 4 will work


mov al, "1"
int 0x10
mov al, the_secret ; This attempts to print out adress not data
int 0x10

mov al, "2"
int 0x10
mov al, [the_secret] ; correct but wrong offset
int 0x10

mov al, "3"
int 0x10
mov bx, the_secret 
add bx, 0x7c00 ;add memory offset, this will work
mov al, [bx] 
int 0x10


mov al, "4"
int 0x10
mov al, [0x7c2d] ; calculate based on where we know the data is 
int 0x10


jmp $ ; infinite loop

the_secret:
    ; ASCII code 0x58 ('X') is stored just before the zero-padding.
    ; On this code that is at byte 0x2d (check it out using 'xxd file.bin')
    db "X"

; zero padding and magic bios number
times 510-($-$$) db 0
dw 0xaa55