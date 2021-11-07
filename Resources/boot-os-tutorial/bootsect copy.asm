; Identical to lesson 13's boot sector, but the %included files have new paths
[org 0x7c00]
KERNEL_OFFSET equ 0x1000 ; The same one we used when linking the kernel

    mov [BOOT_DRIVE], dl ; Remember that the BIOS sets us the boot drive in 'dl' on boot
    mov bp, 0x9000
    mov sp, bp

    mov bx, MSG_REAL_MODE 
    call print
    call print_nl

    call load_kernel ; read the kernel from disk
    call switch_to_pm ; disable interrupts, load GDT,  etc. Finally jumps to 'BEGIN_PM'
    jmp $ ; Never executed

;%include "boot/print.asm"
print:
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
print_nl:
    pusha
    mov ah, 0x0e ; BIOS teletype
    mov al, 0x0a ; newline character
    int 0x10 ; print interr[bits 32] ; set mode to 32 bitpt
    mov al, 0x0d ; carriage return - needed to return to start of new line
    int 0x10
    popa 
    ret
;%include "boot/print_hex.asm"
disk_load:
    pusha
    push dx ; reading from disk changes some registers so save dx value
    mov ah,0x02 ; set BIOS mode (read)
    mov al, dh ;get number of sectors to read from dh
    mov cl, 0x02 ; set sector to read to second sector (after boot sector)
    mov dh, 0x00 ; head number
    
    int 0x13 ; this will save the data to es:bx, the default for the interrupt
    ;jc diskError ; error if any stored in carry bit

    pop dx ; dx contains number of sectors to read
    cmp al, dh ; check if number of sectors read = number of sectors meant to be read
    ;jne sectorError
    ;mov bx, SUCCESS ; add string to register
    ;call print ; print string func
    popa
    ret

diskLoop:
    jmp $
;%include "boot/disk.asm"
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
CODE_SEG equ gdt_code - gdt_start
DATA_SEG equ gdt_data - gdt_start
;%include "boot/gdt.asm"
[bits 32]
VIDEO_MEMORY equ 0xb8000
WHITE_ON_BLACK equ 0x0f ; the color byte for each character

print_string_pm:
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

;%include "boot/32bit_print.asm"
[bits 16]

switch_to_pm:

    cli ; disable interrupts
    lgdt [gdt_descriptor] ; load gdt
    mov eax, cr0
    or eax, 0x1 ; set to 32 bit mode
    mov cr0, eax ; set register to 32 bit
    jmp CODE_SEG:init_pm ; jump a LONG way away in the code segment
    mov ah, 0x0e ; sets BIOS to teletype mode
    mov al, '5' ; set lower value to ASCII 'h'
    int 0x10 ; interrupt 0x10 to print value

[bits 32]
init_pm:
    mov ax, DATA_SEG ; 5. update the segment registers
    mov ds, ax
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    mov ebp, 0x90000 ; 6. update the stack right at the top of the free space
    mov esp, ebp

    call BEGIN_PM ; 7. Call a well-known label with useful code


[bits 16]
load_kernel:
    mov bx, MSG_LOAD_KERNEL
    call print
    call print_nl

    mov bx, KERNEL_OFFSET ; Read from disk and store in 0x1000
    mov dh, 32 ; Our future kernel will be larger, make this big
    mov dl, [BOOT_DRIVE]
    call disk_load
    ret

[bits 32]
BEGIN_PM:
    mov ebx, MSG_PROT_MODE
    call print_string_pm
    call KERNEL_OFFSET ; Give control to the kernel
    jmp $ ; Stay here when the kernel returns control to us (if ever)


BOOT_DRIVE db 0 ; It is a good idea to store it in memory because 'dl' may get overwritten
MSG_REAL_MODE db "Started in 16-bit Real Mode", 0
MSG_PROT_MODE db "Landed in 32-bit Protected Mode", 0
MSG_LOAD_KERNEL db "Loading kernel into memory", 0
MSG_RETURNED_KERNEL db "Returned from kernel. Error?", 0

; padding
times 510 - ($-$$) db 0
dw 0xaa55
