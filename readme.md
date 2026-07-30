OS Boot Process
1. Build Process

When you run:

make

The following happens:

boot.asm is assembled into boot.o.
kernel.c is compiled into kernel.o.
screen.c is compiled into screen.o.
The linker (ld) uses linker.ld to combine all object files into kernel.bin.
kernel.bin is copied into the iso/boot/ directory.
grub-mkrescue creates a bootable ISO named mintOS.iso.

2. Boot Process

When you run:

qemu-system-x86_64 -cdrom mintOS.iso

The boot sequence is:

QEMU creates a virtual computer.
BIOS/UEFI starts.
BIOS/UEFI loads GRUB.
GRUB reads grub.cfg.
GRUB loads kernel.bin into memory.
Execution begins at boot.asm.
boot.asm initializes the CPU/stack.
boot.asm calls kernel_main() in kernel.c.
Your operating system starts running.
Complete

Complete Flow

make
   ↓
(creates object files)
boot.asm → boot.o
kernel.c → kernel.o
screen.c → screen.o
(combines them to run program)
   ↓
ld + linker.ld
   ↓
(combined file into one kernal)
kernel.bin
   ↓
(copied into iso)
mintOS.iso
   ↓
QEMU(the VM that runs the OS)
   ↓
(intialises the hardware)
BIOS/UEFI
   ↓
(boots the application)
GRUB
   ↓
( tells grub what, where and how to boot)
grub.cfg
   ↓
kernel.bin
   ↓
boot.asm
   ↓
kernel_main()
   ↓
Your Operating System
