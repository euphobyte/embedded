bits 16]
        jmp start
msg     db    "0123456789ABCDEF" ; Data in same memory segment as the code 
start:
        mov   ah, 0x00        ; Clear screen set mode 3
        mov   al, 0x03
        int   0x10

        mov   ax, 0x07C0      ; load memory segment into ds register
        mov   ds, ax
        mov   al, 3
        call  putch           ; and print.

loop:   hlt                   ; Halt until interrupt
        jmp   loop

putch:  mov   dx, msg
        add   dx, al
        mov   al, [ds:dx]
        mov   ah, 0x0E
        mov   bh, 0
        mov   bl, 12
        int   0x10
        ret

times   510 - ($$ - $) db 0
        db    0x55
        db    0xaa
