mov ax, 1234 ; stores 1234 in register ax
mov cx, 0x123 ; stores hex number 0x123 in register cx
mov dx, 't' ; stores ASCII code in register dx
mov bx, ax ; stores ax in bx (bx = 1234)

;high and low register values

mov ax, 0    ;ax = 0
mov ah, 0x56 ;ax = 0x5600
mov al, 0x23 ;ax = 0x5623
mov ah, 0x16 ;ax = 0x1623