[org 0x7c00]
KERNEL_OFFSET equ 0x1000 ; The same one we used when linking the kernel
    mov [BOOT_DRIVE], dl ; set boot drive, this is set by BIOS in dl

    mov bp, 0x9000
    mov sp, bp ;set up stack

    mov bx, MSG_16_MODE
    call printString16
    call printNewLine16
    call loadKernel
    call switch32
    jmp $

;%include "printString16.asm"
printString16:
    pusha
    printFunc16:
        mov al, [bx] ; copy contents of adress [bx] to al 
        cmp al, 0 ; check if char = 0
        je return16 ; if yes sreturn
        push bx ; add bx to stack to save it
        mov ah, 0x0e ; set BIOS number
        int 0x10 ; interrupt
        pop bx ; restore bx
        inc bx ; increment to move to next character
        jmp printFunc16 ; repeat
    return16:
        popa 
       ret
printNewLine16:
    pusha
    mov ah, 0x0e ; BIOS teletype
    mov al, 0x0a ; newline character
    int 0x10 ; print interr[bits 32] ; set mode to 32 bitpt
    mov al, 0x0d ; carriage return - needed to return to start of new line
    int 0x10
    popa 
    ret
;%include "diskReading.asm"
loadDisk:
    pusha
    push dx ; reading from disk changes some registers so save dx value
    mov ah,0x02 ; set BIOS mode (read)
    mov al, dh ;get number of sectors to read from dh
    mov cl, 0x02 ; set sector to read to second sector (after boot sector)
    mov dh, 0x00 ; head number
    
    int 0x13 ; this will save the data to es:bx, the default for the interrupt
    jc diskError ; error if any stored in carry bit

    pop dx ; dx contains number of sectors to read
    cmp al, dh ; check if number of sectors read = number of sectors meant to be read
    jne sectorError
    mov bx, SUCCESS ; add string to register
    call printString16 ; print string func
    popa
    ret
diskError:
    mov bx, DISK_ERROR ; add string to register
    call printString16 ; print string func
    call printNewLine16 ; new line
    mov dh,ah ; ah = error code
    ;call printHex16 ; print error code
    jmp diskLoop ; back to diskLoop
sectorError:
    mov bx, SECTOR_ERROR ;move string to register
    call printString16 ; print string

diskLoop:
    jmp $

DISK_ERROR: db "Disk read error", 0
SECTOR_ERROR: db "Incorrect number of sectors read", 0
SUCCESS: db "SUCCESS", 0
;%include "gdt.asm"
gdt_start: ; don't remove the labels, they're needed to compute sizes and jumps
    ; the GDT starts with a null 8-byte
    dd 0x0 ; 4 byte
    dd 0x0 ; 4 byte

; GDT for code segment. base = 0x00000000, length = 0xfffff
; for flags, refer to os-dev.pdf document, page 36
gdt_code: 
    dw 0xffff    ; segment length, bits 0-15
    dw 0x0       ; segment base, bits 0-15
    db 0x0       ; segment base, bits 16-23
    db 10011010b ; flags (8 bits)
    db 11001111b ; flags (4 bits) + segment length, bits 16-19
    db 0x0       ; segment base, bits 24-31

; GDT for data segment. base and length identical to code segment
gdt_data:
    dw 0xffff
    dw 0x0
    db 0x0
    db 10010010b
    db 11001111b
    db 0x0

gdt_end:

; GDT descriptor
gdt_descriptor:
    dw gdt_end - gdt_start - 1 ; size (16 bit), always one less of its true size
    dd gdt_start ; address (32 bit)

; define some constants for later use
CODE_SEG equ gdt_code - gdt_start
DATA_SEG equ gdt_data - gdt_start
;%include "printString.asm"
[bits 32]
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
;%include "switch32.asm"
[bits 16]

switch32:

    cli ; disable interrupts
    lgdt [gdt_descriptor] ; load gdt
    mov eax, cr0
    or eax, 0x1 ; set to 32 bit mode
    mov cr0, eax ; set register to 32 bit
    jmp CODE_SEG:init32 ; jump a LONG way away in the code segment
    mov ah, 0x0e ; sets BIOS to teletype mode
    mov al, '5' ; set lower value to ASCII 'h'
    int 0x10 ; interrupt 0x10 to print value

[bits 32]
init32:
    mov ax, DATA_SEG ; 5. update the segment registers
    mov ds, ax
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    mov ebp, 0x90000 ; 6. update the stack right at the top of the free space
    mov esp, ebp

    call BEGIN_32 ; 7. Call a well-known label with useful code
;%include "printHex16.asm"

BOOT_DRIVE db 0 ; It is a good idea to store it in memory because 'dl' may get overwritten
MSG_16_MODE db "Started in 16-bit Real Mode", 0
MSG_32_MODE db "Landed in 32-bit Protected Mode", 0
MSG_LOAD_KERNEL db "Loading kernel into memory", 0
[bits 16]
loadKernel:
    mov bx, MSG_LOAD_KERNEL
    call printString16
    call printNewLine16

    mov bx, KERNEL_OFFSET ; set to place where kernel is stored
    mov dh, 2 
    mov dl, [BOOT_DRIVE] ; set to boot drive
    call loadDisk
    ret
[bits 32]
BEGIN_32:
    mov ebx, MSG_32_MODE
    call printString ;print
    call KERNEL_OFFSET ;pass to kernel
    jmp $ ; back here whern kernel has finished
times 510 - ($-$$) db 0
dw 0xaa55