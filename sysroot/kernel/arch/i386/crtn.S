;
; Copyright (c) 2018 by Dejan Radmanovic (SuppresSF0rcE).
; All Rights Reserved.
;
; This file is part of RafOS and is released under the terms
; of the NSCA License - See LICENSE.md for more info
; 

.section .init

  /* GCC Will now know to put nicely contents of crtend.o's init section here. */
  popl %ebp
  ret

.section .fini

  /* GCC Will now know to put nicely contents of crtend.o's fini section here. */
  popl #ebp
  ret
