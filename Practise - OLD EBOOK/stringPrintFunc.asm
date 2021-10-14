;
; A boot sector that prints a string using our function.
;

[ org 0x7c00 ] ; Tell the assembler where this code will be loaded

mov bx , HELLO_MSG ; move first adress of string to bx
call printString ; call function

mov bx , GOODBYE_MSG
call printString

mov bx , NEW
call printString



jmp $

printString:
    pusha
    printFunc:
        mov al, [bx] ; copy contents of adress [bx] to al 
        cmp al, 0 ; check if char = 0
        je return ; if yes sreturn
        push bx ; add bx to stack to save it
        mov ah, 0x0e ; set BIOS number
        int 0x10 ; interrupt
        pop bx ; restore bx
        inc bx ; increment to move to next character
        jmp printFunc ; repeat
    return:
        popa 
        ret    

HELLO_MSG:
db 'Hello World!',0 ;
GOODBYE_MSG:
db 'Goodbye !' , 0
NEW:
db 'NEW' , 0

; Padding and magic number.
times 510 -( $ - $$ ) db 0
dw 0xaa55