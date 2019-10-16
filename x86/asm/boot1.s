; Most basic example of a x86 bootloader program
; Install nasm in Linux: sudo apt-get install nasm
; Generate bin file to write to boot sector of a floppy disk:
; assemble: nasm -o boot1.bin -f bin boot1.s
; preview: dd if=boot1.bin bs=512 count=1 | hexdump -C
; write: dd if=boot1.bin of=/dev/fd0
; in win shell: dd if=boot1.bin of=\\.\a: bs=512 count=1
[bits 16]
start:
  jmp $
times 510 - ($ - $$) db0
db 0x55
db 0xAA
