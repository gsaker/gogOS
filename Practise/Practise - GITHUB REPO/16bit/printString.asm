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
printNewLine:
    pusha
    mov ah, 0x0e ; BIOS teletype
    mov al, 0x0a ; newline character
    int 0x10 ; print interr[bits 32] ; set mode to 32 bitpt
    mov al, 0x0d ; carriage return - needed to return to start of new line
    int 0x10
    popa 
    ret

printHex:
    pusha
    mov cx, 0 ;index var
hexLoop:
    cmp cx, 4 ; loop 4 times to get each char of hex value
    je end
    mov ax, dx ; ax as working register so we don't overwrite value
    and ax, 0x000f ; remove first 3 values of hex
    add al, 0x30 ; add to make into ascii char
    cmp al, 0x39 ; if larger than 0x39 then it is a letter so 8 needs to be added tp concert to a-f
    jle hex2
    add al, 7 ; add 7 to convert to the ascii char required

hex2:
    mov bx, HEX_OUT + 5 ; base adress + string length - char index
    sub bx, cx ; index var
    mov [bx], al ; copy ASCII char to bx position
    ror dx, 4; rotates bits 0x1234 -> 0x4123 -> 0x3412 -> 0x2341 -> 0x1234
    add cx, 1; increment
    jmp hexLoop

end:
    mov bx, HEX_OUT
    call printString
    popa
    ret
;string:
;    db 'Hello World', 0
HEX_OUT: db '0x0000',0

    ; reserve memory for our new string
