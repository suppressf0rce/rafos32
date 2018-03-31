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
  
