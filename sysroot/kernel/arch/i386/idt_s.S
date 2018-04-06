# 
# Copyright (c) 2018 by Dejan Radmanovic (SuppresSF0rcE).
# All Rights Reserved.
#
# This file is part of RafOS and is released under the terms
# of the NSCA License - See LICENSE.md for more info
#

# Loads the IDT defined in '_idtp' into the processor.
# This is declared in C as 'extern void idt_load();'
.global idt_load
idt_load:
    mov 4(%esp), %eax
    lidt (%eax)
    ret
