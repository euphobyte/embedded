bits 16]
        jmp   star
msg     db    "0123456789ABCDEF" ; Data in same memory segment as the code
start:
        mov   ah, 0x00            ; Clear screen set mode 3
        mov   al, 0x03
        int   0x10

        mov   ax, 0x07C0          ; load memory segment into ds register
        mov   ds, ax
        mov   es, ax
        mov   ax, 0x5D
        call  phex

loop:   hlt                       ; Halt until interrupt
        jmp   loop

phex:   mov  cl, al
        shr   al, 4
        call  putch
        mov   al, cl
        and   al, 0x0F
        call  putch
        ret

putch:  mov   si, msg
        add   si, ax
        lodsb
        mov   ah, 0x0E
        mov   bh, 0
        mov   bl, 0
        int   0x10
        xor   ax, ax
        ret

times   510 - ($$ - $) db 0
        db    0x55
        db    0xaa
