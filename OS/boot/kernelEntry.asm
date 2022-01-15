[bits 32]
; First make the ISRs global
mov bx, MSG_LOAD_KERNEL
call printString
[extern main] ; Define calling point. Must have same name as kernel.c 'main' function
call main ; Calls the C function. The linker will know where it is placed in memory
hlt
jmp $
; Defined in isr.c
MSG_LOAD_KERNEL db "In Kernel File", 0
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