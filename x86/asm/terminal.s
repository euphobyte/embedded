; Standalone minimal terminal in boot sector of floppy disk
; nasm -o terminal.bin -f bin terminal.s
; dd if=terminal.bin of=\\.\a: bs=512
[bits 16]
        jmp start
hello:  db "Hello World!",13,10,0x3E,0
start:  cli
        cld
        mov ax, 0x07C0  ; Offset by BIOS in memory
        mov ds, ax
        mov si, hello
        call print
        sti
read:   xor ax,ax
        int 0x16        ; Read keyboard 
        or al,al        ; ASCII code in AL
        jz read
        mov ah,0x0E     ; function teletype character
        int 0x10        ; display
        jmp read
print:  mov ah,0x0E
pchar:  lodsb
        or al,al
        jz pend
        int 0x10
        jmp pchar
pend:   ret
times 510 - ($ - $$) db 0
        db 0x55
        db 0xaa
