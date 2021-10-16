; Formula to acess specific grid value
;; 0xb8000 + 2 * (row * 80 + col)
;
;VIDEO_MEMORY equ 0xb8000 ; constant
;WHITE_ON_BLACK equ 0x0f ; constant
;
;printString:
;    pusha
;    mov edx, VIDEO_MEMORY ; extended registers as 32 bit modes
;
;printStringLoop:
;    mov al, [ebx] ; adress of character
;    mov ah, WHITE_ON_BLACK
;
;    cmp al, 0 ; check if end of string
;    je printStringEnd
;
;    mov [edx], ax ; store car in vram
;    add ebx , 1 ; next char
;    add edx , 2 ; next vram pos
;
;    jmp printStringLoop
;
;printStringEnd:
;    popa
;    ret

[bits 32] ; using 32-bit protected mode

; this is how constants are defined
VIDEO_MEMORY equ 0xb8000
WHITE_ON_BLACK equ 0x0f ; the color byte for each character

printString:
    pusha
    mov edx, VIDEO_MEMORY

printStringLoop:
    mov al, [ebx] ; [ebx] is the address of our character
    mov ah, WHITE_ON_BLACK

    cmp al, 0 ; check if end of string
    je printStringEnd

    mov [edx], ax ; store character + attribute in video memory
    add ebx, 1 ; next char
    add edx, 2 ; next video memory position

    jmp printStringLoop

printStringEnd:
    popa
    ret

;clearScreen:
;    pusha
;    mov bl, 0
;    mov edx, VIDEO_MEMORY
;
;clearScreenLoop:
;    mov ax, 0
;    mov ah, WHITE_ON_BLACK
;
;    mov [edx], ax ; store character + attribute in video memory
;    add edx, 2 ; next video memory position 
;    cmp bl, 1
;    je clearScreenEnd 
;    add bl, 1
;    jmp clearScreenLoop
;    
;
;clearScreenEnd:
;    pusha
;    ret
