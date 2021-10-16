[ bits 16]
; Switch to protected mode
switch_to_pm :
cli
lgdt [ gdt_descriptor ]; Load our global descriptor table , which defines
; the protected mode segments ( e.g. for code and data )
mov eax , cr0
or eax , 0x1
mov cr0 , eax; To make the switch to protected mode , we set
; the first bit of CR0 , a control register
jmp CODE_SEG : init_pm;

[ bits 32]
; Initialise registers and the stack once in PM.
init_pm :
    mov ax, DATA_SEG ; 5. update the segment registers
    mov ds, ax
    mov ss, ax
    mov es, ax
    mov fs, ax
    mov gs, ax

    mov ebp, 0x90000 ; 6. update the stack right at the top of the free space
    mov esp, ebp

    call BEGIN_PM ; 7. Call a well-known label with useful code
