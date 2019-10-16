; FOR EDUCATIONAL PURPOSES ONLY.
; Two sector boot program
; Write boot4.bin to sector 0: dd if=boot4.bin of=\\.\a: seek=0 count=1 bs=512
; Write data.bin to sector 1: dd if=data.bin of=\\.\a: seek=1 count=1 bs=512

[bits 16]

boot:   mov ah, 0x2    ; function ah=02h, read sector
        mov al, 0x1    ; read 1 sector
        mov dl, 0x0    ; drive 0
        mov ch, 0x0    ; cylinder 0
        mov dh, 0x0    ; head 0
        mov cl, 0x2    ; sector offset
        
        mov bx, 0x1000
        mov es, bx
        xor bx, bx
retry:
        int 0x13
        jc  retry

        mov ax, 0x1000  
        mov ds, ax
        mov si, 0x0
        call print
loop1:  hlt
        jmp loop1

print:  mov ah, 0x0e
pchar:  lodsb
        or  al,al
        jz  pend
        int 0x10
        jmp pchar
pend:   ret
times 510 - ($-$$) db 0
        db 0x55
        db 0xaa
