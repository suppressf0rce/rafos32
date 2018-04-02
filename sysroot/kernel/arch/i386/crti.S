#
# Copyright (c) 2018 by Dejan Radmanovic (SuppresSF0rcE).
# All Rights Reserved.
#
# This file is part of RafOS and is released under the terms
# of the NSCA License - See LICENSE.md for more info
#

.section .init
.global _init
.type _init, @function
_init:
  push %ebp
  movl %esp, %ebp
  /* GCC will now know how to put the contents of crtbegin.o's .init section. It will be placed here */

.section .fini
.global _fini
.type _fini, @function
_fini:
  push %ebp
  movl %esp, %ebp
  /* GCC will now know how to put the contents of crtbegin.o's .fini section. It will be placed here */
