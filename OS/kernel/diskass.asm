

;[bits 16]

global PrintSomething
PrintSomething:
     
;    cli
;    mov bx, MSG_16_MODE
;    call printString16
;printString16:
;    pusha
;    printFunc16:
;        mov al, [bx] ; copy contents of adress [bx] to al 
;        cmp al, 0 ; check if char = 0
;        je return16 ; if yes sreturn
;        push bx ; add bx to stack to save it
;        mov ah, 0x0e ; set BIOS number
;        int 0x10 ; interrupt
;        pop bx ; restore bx
;        inc bx ; increment to move to next character
;        jmp printFunc16 ; repeat
;    return16:
;        popa 
;       ret
;printNewLine16:
;    pusha
;    mov ah, 0x0e ; BIOS teletype
;    mov al, 0x0a ; newline character
;    int 0x10 ; print interr[bits 32] ; set mode to 32 bitpt
;    mov al, 0x0d ; carriage return - needed to return to start of new line
;    int 0x10
;    popa 
;MSG_16_MODE db "Started in 16-bit Real Mode", 0