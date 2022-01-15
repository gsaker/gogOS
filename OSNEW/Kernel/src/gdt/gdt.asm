global ASMStuffForGDT
ASMStuffForGDT:
	mov ax, 0x10  ; kernel data segment descriptor
	mov ds, ax
	mov es, ax
	mov fs, ax
	mov gs, ax

    mov eax, 0x08
    push eax

    retf