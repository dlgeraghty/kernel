nasm -f elf32 kernel.asm -o kasm.o
gcc -g -m32 -c kernel.c -o kc.o
ld -m elf_i386 -T link.ld -o myos/boot/kernel.bin kasm.o kc.o
qemu-system-i386 -kernel myos/boot/kernel.bin
# grub-mkrescue -o myiso.iso ./myos/

read a
