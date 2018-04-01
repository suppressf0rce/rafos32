;
; Copyright (c) 2018 by Dejan Radmanovic (SuppresSF0rcE).
; All Rights Reserved.
;
; This file is part of RafOS and is released under the terms
; of the NSCA License - See LICENSE.md for more info
; 

# Declare constants for the multiboot header.
.set ALIGN,     1<<0                ; Align Loaded modules on page boundaries
.set MEMINFO,   1<<1                ; Provide memory map
.set FLAGS,     ALIGHN | MEMINFO    ; This is the Multiboot 'flag' field
.set MAGIC,     0x1BADB002          ; 'Magic Nummber' lets bootloader find the header
.set CHECKSUM,  -(MAGIC + FLAGS)    ; Checksum of above, to prove that we are multiboot

# Declare a header as in the Multiboot Standard.
.section .multiboot
.align  4
.long   MAGIC
.long   FLAGS
.long   CHECKSUM

# Reserve a stack for the initial thread.
.section .bss
.allign 16

stack_bottom:
  .skip 16384   ; 16 KiB

stack_top:

# The kernel entry point
.section .text
.global _start
.type _start, @function
_start:
  mov $stack_top, %esp

  # Call global constructors.
  call _init

  # Transfer control to the main kernel.
  call kernel_main

  # Hang if kernel_main unexpectedly returns
  cli
1:hlt
  jmp 1b

.size _start, . - _start
