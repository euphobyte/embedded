; FOR EDUCATIONAL PURPOSES ONLY.
; Source code is provided as-is without warranty, and disclaiming liability for damages resulting from using the source code.

[bits 16]

jmp start
start:  mov     ah, 0x00        ; Setup serial port
        mov     al, 11100111b   ; 111 = 9600 baud, 00 = no parity, 1 = 1 stopbit,  11 = 8bit data length 
        xor     dx, dx
        int     0x14
        
loop:
        mov     al, 65          ; Write ASCII 'A' to serial port
        mov     dx, 0x3F8
        out     dx, al
        call    pause
        jmp     loop

pause:  cli
        mov     ax, 0x00
        int     0x1A            ; Retrieve system time ticks since midnight (18 per second)
        add     dx, 0x24        ; Pause 2 seconds
        mov     bx, dx

.loop1  mov     ax, 0x00
        int     0x1A
        cmp     bx, dx
        jge     .loop1
        sti
        ret
        
times 510 - ($-$$) db 0
        db 0x55
        db 0xAA
