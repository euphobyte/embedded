; FOR EDUCATIONAL PURPOSES ONLY.
; Source code is provided as-is without warranty, and disclaiming liability for damages resulting from using the source code.

[bits 16]
start:
        mov   ah, 0       ; Set mode and clear screen
        mov   al, 0x03    ; Textmode 3
        int   0x10
loop2:
        mov   bh, 0       ; Page 0
        mov   al, 65      ; ASCII code for 'A'
        mov   ah, 0x0E    ; Put character on screen in teletype mode
        int   0x10        ; Video interrupt 

        xor   al, 1       ; Blink LED on/off
        mov   dx, 0x378   ; Port address
        out   dx, al
        call  pause

        jmp   loop2

pause:  cli
        mov   ax, 0
        int   0x1A        ; Retrieve system time ticks since midnight (18 per second)
        add   dx, 9       ; Pause half a second
        mov   bx, dx

.loop1  mov   ax, 0
        int   0x1a
        cmp   bx, dx
        jge   .loop1
        sti
        ret

times 510 - ($-$$) db 0
        db    0x55
        db    0xaa
