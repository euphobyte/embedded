; Code is loaded by BIOS to memory location 0000:7C00.
; To use lodsb (read next byte an put in in regisetr AL), DS:SI has to point
; to the correct memory location, so set SI to offset "hello" and 
; set DS to 0x07C0. 0x7C0 * 16 + offset "hello" points to the correct location.
; int 0x10 funtion ah=0x0E is used to display a teletype character.
; nasm -o boot3.bin -f bin boot3.s ; dd if=boot3.bin of=\\.\a: bs=512

[bits 16]
        jmp start
hello:  db "Hello World!",0
start:  cli
        cld
        mov ax, 0x07C0
        mov ds, ax
        mov si, hello
        call print
        sti
        jmp $
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
        
