.set MAGIC, 0x1badb002
.set FLAGS, (1<<0 | 1<<1)
.set CHECKSUM, -(MAGIC + FLAGS)

.section .mutiboot
    .long MAGIC
    .long FLAGS
    .long CHECKSUM

.section .text
.extern KernelMain
.extern CallConstructors
.global loader

loader:
    mov $KernelStack, %esp

    call CallConstructors

    push %rax
    push %rbx
    call KernelMain

_stop:
    cli
    hlt
    jmp _stop

.section .bss
.space 2*1024*1024; # 2MiB
KernelStack: