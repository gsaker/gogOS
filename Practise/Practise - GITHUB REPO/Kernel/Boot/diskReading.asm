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
    call printHex16 ; print error code
    jmp diskLoop ; back to diskLoop
sectorError:
    mov bx, SECTOR_ERROR ;move string to register
    call printString16 ; print string

diskLoop:
    jmp $

DISK_ERROR: db "Disk read error", 0
SECTOR_ERROR: db "Incorrect number of sectors read", 0
SUCCESS: db "SUCCESS", 0