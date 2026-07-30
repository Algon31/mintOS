.PHONY: all build run clean rebuild

CC = gcc
AS = nasm
LD = ld

CFLAGS = -m32 -ffreestanding -Ikernel/include -Ikernel/arch/x86 -Ikernel/lib -Ikernel/input
ASFLAGS = -f elf32
LDFLAGS = -m elf_i386 -T linker.ld

all: build

build:
	$(AS) $(ASFLAGS) boot/boot.asm -o build/boot.o

	$(CC) $(CFLAGS) -c kernel/kernel.c -o build/kernel.o
	$(CC) $(CFLAGS) -c kernel/drivers/screen.c -o build/screen.o
	$(CC) $(CFLAGS) -c kernel/drivers/keyboard.c -o build/keyboard.o
	$(CC) $(CFLAGS) -c kernel/input/input.c -o build/input.o
	$(CC) $(CFLAGS) -c kernel/shell/shell.c -o build/shell.o
	$(CC) $(CFLAGS) -c kernel/lib/string.c -o build/string.o
	$(CC) $(CFLAGS) -c kernel/lib/memory.c -o build/memory.o
	$(CC) $(CFLAGS) -c kernel/shell/parser.c -o build/parser.o
	$(CC) $(CFLAGS) -c kernel/shell/commands.c -o build/commands.o

	$(LD) $(LDFLAGS) -o build/kernel.bin \
		build/boot.o \
		build/kernel.o \
		build/screen.o \
		build/keyboard.o \
		build/input.o \
		build/shell.o \
		build/string.o \
		build/memory.o \
		build/parser.o \
		build/commands.o



	cp build/kernel.bin iso/boot/kernel.bin
	grub-mkrescue -o mintOS.iso iso

run: build
	qemu-system-x86_64 -cdrom mintOS.iso

clean:
	rm -rf build/*
	rm -f mintOS.iso

rebuild: clean run
