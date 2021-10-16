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