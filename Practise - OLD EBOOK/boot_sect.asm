loop:                   ; variable loop used as a label so we can jump to it permenantely
    jmp loop

times 510-($-$$) db 0 ; fill rest of boot sector with zeroes

dw 0xaa55 ; magic number!
