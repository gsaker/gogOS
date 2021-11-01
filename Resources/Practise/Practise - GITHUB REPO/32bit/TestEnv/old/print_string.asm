print_string:
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