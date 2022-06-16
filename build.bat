@fasm src/arch/x86/start.asm bin/start.o
@clang -c -O0 --target=i386-pc-none-elf -march=i386 -nostdlib -nodefaultlibs -ffreestanding -o bin/kernel.o src/kernel.c 
@i686-elf-ld -T src/arch/x86/link.ld -o kernel.elf bin/start.o
@qemu-system-i386 -kernel kernel.elf -d int -machine type=pc-i440fx-3.1