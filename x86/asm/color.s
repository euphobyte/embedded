[bits 16]
jmp start
hello: db "Hello World!",0
start:
        mov   bx, 0x1000  ; Fill character array
        mov   ds, bx
        xor   bx, bx
        mov   cl, 0x0A
.loop   mov   al, cl
        add   al, 65
        mov   [ds:bx], al
        inc   bx
        dec   cl
        jnz   .loop
        mov   [ds:bx], BYTE 0x0

read:   mov   ah, 0x0     ; set video mode
        mov   al, 0x03    ; color text mode, 0x12 color graphics
        int   0x10

        mov   ax, 0x1003  ; intense colors
        mov   bl, 0       ; 0 = intense colors 1 = blinking
        int   0x10

        mov   bx, 0x1000  ; pointer to character array
        mov   es, bx
        mov   si, 0
        call print

        mov   ah, 2       ; set cursor
        mov   bh, 0
        mov   dh, 12      ; cursor row
        mov   dl, 20      ; cursor column
        int   0x10  

        mov   ah, 9       ; display character at cursor
        mov   al, '#'
        mov   bl, 0x9F    ; color attributes
        mov   cx, 10      ; repeat value
        int   0x10

loop1:  hlt
        jmp   loop1
print:  mov   ah, 0x0E
pchar:  lodsb
        or    al, al
        jz    pend
        mov   bl, al
        sub   bl, 65
        int   0x10
        jmp   pchar
pend:   ret
times 510 - ($ - $$) db 0
db 0x55
db 0xaa
