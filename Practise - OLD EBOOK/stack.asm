mov ah , 0x0e ; BIOS teletype

mov bp, 0x8000 ; sets start of stack to above where BIOS has loaded our boot sector
mov sp, bp 

push 'A' ; put A to top of stack
push 'B' 
push 'C' ; put C to top of stack

pop bx ; can only pop 16bits so need to get higher section
mov al, bl ; move first 
int 0x10

pop bx ; can only pop 16bits so need to get higher section
mov al, bl ; move first 
int 0x10

jmp $

times 510-($-$$) db 0 ; fill rest of boot sector with zeroes

dw 0xaa55 ; magic number!