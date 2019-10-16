; Generate bin file to write to boot sector of a floppy disk:
; nasm -o boot2.bin -f bin boot2.s ; dd if=boot2.bin of=\\.\a: bs=512
[bits 16]
        mov ah, 0x0E
        mov bh, 0
        mov al, 0x48  ; 0x48 => 'H'
        int 0x10
        mov al, 0x65  ; 0x65 => 'e'
        int 0x10
        mov al, 0x6C  ; 0x6C => 'l'
        int 0x10
        int 0x10
        mov al, 0x6F  ; 0x6F => 'o'
        int 0x10
        jmp $
times 510 - ($ - $$) db 0
        db 0x55
        db 0xaa
