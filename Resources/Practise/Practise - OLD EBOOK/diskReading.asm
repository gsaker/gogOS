diskTest:
    mov ah, 0x02 ; BIOS read number
    mov dl, 0 ; drive 0
    mov ch, 3 ; cylinder 3
    mov dh, 1 ; side 2
    mov cl, 4 ; 4th sector on track
    mov al, 5 ; 5 sectors from start point

    ; set adress to read to
    mov bx, 0xa000 ;move 0xa000 to bx
    mov es, bx ;move bx to ex offset
    mov bx, 0x1234 ; move 0x1234 to bx
    ; this means the data will be read to 0xa1234
    int 0x13 ; interrupt to read

diskLoad:
    push dx ; store dx on stack so we can see how many sectors needed to be read
    mov ah , 0 x02 ; BIOS read sector function
    mov al , dh ; Read DH sectors
    mov ch , 0 x00 ; Select cylinder 0
    mov dh , 0 x00 ; Select head 0
    mov cl , 0 x02; Start reading from second sector ( i.e. after the boot sector )
    