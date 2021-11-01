printHex16:
    pusha
    mov cx, 0 ;index var
hexLoop16:
    cmp cx, 4 ; loop 4 times to get each char of hex value
    je end16
    mov ax, dx ; ax as working register so we don't overwrite value
    and ax, 0x000f ; remove first 3 values of hex
    add al, 0x30 ; add to make into ascii char
    cmp al, 0x39 ; if larger than 0x39 then it is a letter so 8 needs to be added tp concert to a-f
    jle hex216
    add al, 7 ; add 7 to convert to the ascii char required

hex216:
    mov bx, HEX_OUT + 5 ; base adress + string length - char index
    sub bx, cx ; index var
    mov [bx], al ; copy ASCII char to bx position
    ror dx, 4; rotates bits 0x1234 -> 0x4123 -> 0x3412 -> 0x2341 -> 0x1234
    add cx, 1; increment
    jmp hexLoop16

end16:
    mov bx, HEX_OUT
    call printString
    popa
    ret

HEX_OUT: db '0x0000',0