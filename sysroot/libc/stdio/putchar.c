//
// Copyright (c) 2018 by Dejan Radmanovic (SuppresSF0rcE).
// All Rights Reserved.
//
// This file is part of RafOS and is released under the terms
// of the NSCA License - See LICENSE.md for more info
//

#include <stdio.h>

#if defined(__is_libk)
#include <kernel/tty.h>
#endif

/*==============================================================================
The C library function int putchar(int char) writes a character
(an unsigned char) specified by the argument char to stdout.

Parameters:
    ic - This is the character to be written. This is passed as int promotion.

Return Value:
    This function returns the character written as an unsigned char cast to an
    int or EOF on error.
==============================================================================*/
int putchar(int ic){
#if defined(__is_libk)
  char c = (char ic);
  terminal_write(&c, sizeof(c));
#else
  // TODO: Implement stdio and the write system call.
#endif
  return ic;
}
