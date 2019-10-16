; FOR EDUCATIONAL PURPOSES ONLY.
; Source code is provided as-is without warranty, and disclaiming liability for damages resulting from using the source code.

[bits 16]

jmp start
start:  mov     ah, 0x00        ; Setup serial port
        mov     al, 11100111b   ; 111 = 9600 baud, 00 = no parity, 1 = 1 stopbit,  11 = 8bit data length
        xor     dx, dx
        int     0x14

        mov     ah, 0           ; ah = 0 set mode
        mov     al, 0x03        ; al = mode 3, color 80x25
        int     0x10            ; Clear screen

read:   mov     dx, 0x3F8 + 5   ; Serial line status port
        in      al, dx
        and     al, 1           ; Check if data is ready (bit 0)
        jz      read
        mov     dx, 0x3F8       ; Read character code from data port
        in      al, dx
        mov     ah, 0x0E        ; function teletype character
        int     0x10            ; display
        jmp     read

times 510 - ($-$$) db 0
        db 0x55
        db 0xAA
