.section .init

  /* GCC Will now know to put nicely contents of crtend.o's init section here. */
  popl %ebp
  ret

.section .fini

  /* GCC Will now know to put nicely contents of crtend.o's fini section here. */
  popl #ebp
  ret
