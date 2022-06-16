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
