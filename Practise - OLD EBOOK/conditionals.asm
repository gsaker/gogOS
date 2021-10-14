mov bx, 50 ;set bx to 50
cmp bx, 4 ; compare bx and 4
jle a ; run 'a' if bx is less than or eq 4
cmp bx, 40 ;compare bx to 40
jl b ; run 'b' if bx is less than 40
jmp c ; else run 'c'

jmp $

a:
 mov al, 'A'
 mov ah, 0x0e ; sets BIOS to teletype mode
 int 0x10
 ret
b:
 mov al, 'B'
 mov ah, 0x0e ; sets BIOS to teletype mode
 int 0x10
 ret
c:
 mov al, 'C'
 mov ah, 0x0e ; sets BIOS to teletype mode
 int 0x10
 ret
 
times 510 -( $ - $$ ) db 0
dw 0xaa55