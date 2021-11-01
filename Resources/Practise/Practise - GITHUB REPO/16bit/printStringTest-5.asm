[ org 0x7c00 ] ; Tell the assembler where this code will be loaded

mov bx, string
call printString
call printNewLine

jmp $ ; jump to current adress, this doesn't appear to be needed??
%include 'printString.asm' 
string:
    db 'Hello World', 0
times 510-($-$$) db 0 ; fill rest of boot sector with zeroes
dw 0xaa55 ; magic number!