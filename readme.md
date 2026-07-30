# 🖥️ mintOS

**mintOS** is a hobby operating system built from scratch in **C**, created to explore low-level computer systems and understand how an operating system works beneath modern software.

The goal of this project is not to build a production-ready operating system, but to learn operating system internals by implementing each component from the ground up.

---

## 🎯 Project Goals

* Understand the OS boot process
* Build a custom kernel from scratch
* Learn memory management
* Explore interrupts and hardware interaction
* Develop a simple command-line shell
* Gain hands-on experience with systems programming

---

## 🚀 Current Features

* ✅ Custom bootloader
* ✅ 32-bit protected mode
* ✅ Kernel initialization
* ✅ VGA text output
* ✅ Keyboard input
* ✅ Basic terminal
* ✅ Command parser
* 🚧 Memory management *(In Progress)*
* 🚧 Interrupt handling *(In Progress)*
* 🚧 File system *(Planned)*

---

## 🛠️ Tech Stack

### 💻 Language

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge\&logo=c\&logoColor=white)

### ⚙️ Build Tools

![GCC](https://img.shields.io/badge/GCC-181717?style=for-the-badge\&logo=gnu\&logoColor=white)
![GNU Make](https://img.shields.io/badge/GNU_Make-6D00CC?style=for-the-badge)

### 🖥️ Platform

![x86](https://img.shields.io/badge/x86-Architecture-blue?style=for-the-badge)
![QEMU](https://img.shields.io/badge/QEMU-FF6600?style=for-the-badge)

---

## 🏗️ Project Structure

```text
mintOS/
│
├── boot/          # Bootloader
├── kernel/        # Kernel source
│   ├── drivers/
│   ├── lib/
│   ├── shell/
│   └── memory/
│
├── include/
├── scripts/
├── Makefile
└── README.md
```

---

## ⚙️ Getting Started

### Clone the repository

```bash
git clone https://github.com/Algon31/mintOS.git
```

### Build the operating system

```bash
make
```

### Run using QEMU

```bash
make run
```

---

## 🗺️ Development Roadmap

### Phase 1

* [x] Bootloader
* [x] VGA Text Mode
* [x] Basic Kernel
* [x] Keyboard Driver
* [x] Simple Shell

### Phase 2

* [ ] Interrupt Descriptor Table (IDT)
* [ ] Programmable Interrupt Controller (PIC)
* [ ] Timer Driver
* [ ] Dynamic Memory Allocation

### Phase 3

* [ ] Paging
* [ ] Virtual Memory
* [ ] File System
* [ ] Process Management

### Phase 4

* [ ] User Programs
* [ ] Multitasking
* [ ] ELF Loader
* [ ] System Calls

---

## 📚 What I Learned

Through building **mintOS**, I explored:

* Operating system architecture
* Boot process
* Kernel development
* Low-level C programming
* Memory layout
* Hardware interaction
* Interrupt handling
* Terminal implementation
* Computer architecture

---

## 🔮 Future Improvements

* FAT32 file system
* Dynamic memory allocator
* Process scheduler
* Multitasking
* Virtual memory
* Graphics mode
* Networking
* User-space applications

---

## 👨‍💻 Author

**Ravi Bhuvan**

* GitHub: https://github.com/Algon31
* LinkedIn: https://www.linkedin.com/in/ravibhuvan

---

> **Note:** This project is built for educational purposes to deepen my understanding of operating systems and low-level programming.
