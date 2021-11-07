[bits 32]
; First make the ISRs global
global idt_load
[extern idtp]

[extern kernel_main] ; Define calling point. Must have same name as kernel.c 'main' function
call kernel_main ; Calls the C function. The linker will know where it is placed in memory
jmp $
; Defined in isr.c

idt_load:
    lidt [idtp]
    ret

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

; Defined in isr.c


; Common ISR code