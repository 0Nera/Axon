# Написание ОС с нуля

Итак, раз Вы обратились к этой книге значит Вы хотите написать ОС. Верно?

Для начала учтите, Вам понадобится:

- Компьютер/Ноутбук/Смартфон с ОС Window, Linux или Android. Главное чтобы поддерживался Clang;
- Qemu или другая программа для виртуализации;
- Знание языка C;
- doxygen;
- Умение работы с GIT.

"Все?" - Спросите Вы. А я отвечу, нет. Далее - по-ситуации.

Давайте сразу приступим. Создайте git репозиторий.
В папке src создайте:

- kernel.c
- arch/x86/starter.s
- arch/x86/linker.ld

kernel.c

``` c
extern void asm_hlt();

void kernel() {
    while(1){
        asm_hlt();
    }
}
```

arch/x86_64/start.asm

``` fasm
format ELF64

public main
public asm_hlt

extrn kernel

asm_hlt:
    hlt

main:
    jmp kernel

hlt_kernel:
    hlt
    jmp hlt_kernel

```

## Сборка
<!-- 
clang -c -O0 --target=x86_64-pc-none-elf -m64 -march=x86-64 -nostdlib -nodefaultlibs -ffreestanding -mcmodel=large -mno-red-zone -mno-mmx -mno-sse -mno-sse2 -o bin/kernel.o src/kernel.c 
ld -T src/arch/x86_64/link.ld -o kernel.elf bin/kernel.o bin/start.o
-->

``` shell
clang -c -O0 --target=x86_64-pc-none-elf -m64 -march=x86-64 -nostdlib -nodefaultlibs -ffreestanding -mcmodel=large -mno-red-zone -mno-mmx -mno-sse -mno-sse2 -o bin/kernel.o src/kernel.c 
fasm src/arch/x86_64/start.asm bin/start.o
ld -T src/arch/x86_64/link.ld -o kernel.elf bin/kernel.o bin/start.o
qemu-system-x86_64 -kernel kernel.elf
```

``` shell
fasm src/arch/x86/start.asm bin/start.o
clang -c -O0 --target=i386-pc-none-elf -m32 -march=i386 -nostdlib -nodefaultlibs -ffreestanding -o bin/kernel.o src/kernel.c 
ld -T src/arch/x86/link.ld -o kernel.elf bin/kernel.o bin/start.o
qemu-system-i386 -kernel kernel.elf -d int
```
