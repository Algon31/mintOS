# mintOS Notes

# Phase 1 --- Booting mintOS

## Tools

  Tool      Purpose
  --------- -------------------------
  GCC       Compiles C code
  NASM      Assembler
  QEMU      Emulator for testing OS
  GRUB      Bootloader
  xorriso   Creates bootable ISO

## VGA Video Memory

`0xB8000` is the VGA text-mode video memory.

Each character cell uses **2 bytes**:

-   1 byte → Character
-   1 byte → Color attribute

Example:

``` c
video[i * 2] = text[i];
video[i * 2 + 1] = 0x07;
```

## Boot Process

``` text
Power On
→ BIOS/UEFI
→ GRUB starts
→ GRUB reads grub.cfg
→ GRUB loads kernel
→ boot.asm starts
→ kernel_main() runs
```

## Project Structure

``` text
Makefile
boot/
iso/
kernel/
linker.ld
```

------------------------------------------------------------------------

# Phase 2 --- Screen Driver

-   `clear_screen()`
-   `print()`
-   VGA text output
-   Cursor management

------------------------------------------------------------------------

# Phase 3 --- Keyboard Driver

## Keyboard sends Scan Codes

  Key         Scan Code
  ----------- -----------
  A           0x1E
  B           0x30
  C           0x2E
  Enter       0x1C
  Backspace   0x0E

Flow:

``` text
Press Key
↓
Port 0x60
↓
inb(0x60)
↓
Scan Code
↓
Lookup Table
↓
ASCII
↓
Print
```

### Memory Mapped vs Port Mapped I/O

-   VGA → Memory (`0xB8000`)
-   Keyboard → Port (`0x60`)

### Polling

``` text
while(1)
    ↓
keyboard_get_char()
```

Current limitation:

-   Reads directly from `0x60`
-   Next improvement: check status port `0x64`

------------------------------------------------------------------------

# Phase 4 --- Kernel Library

## string.h

Functions:

-   strlen()
-   strcmp()
-   strcpy()
-   strncpy()

## Upcoming

-   memcpy()
-   memset()
-   memcmp()

Purpose:

Every subsystem (Shell, Drivers, Memory Manager, File System, Scheduler)
will reuse these functions instead of implementing their own.

------------------------------------------------------------------------

# Current mintOS Architecture

``` text
Kernel
│
├── Drivers
├── Shell
├── Input
└── Kernel Library
```

## Current Progress

-    Bootloader
-    GRUB
-    Linker Script
-    VGA Driver
-    Screen Driver
-    Keyboard Driver (Polling)
-    Input Buffer
-    Basic Shell
-    Kernel String Library

## Next Roadmap

1.  memcpy()
2.  memset()
3.  memcmp()
4.  GDT
5.  IDT
6.  Interrupts
7.  Memory Manager
8.  PIT Timer
9.  Scheduler
