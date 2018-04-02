//
// Copyright (c) 2018 by Dejan Radmanovic (SuppresSF0rcE).
// All Rights Reserved.
//
// This file is part of RafOS and is released under the terms
// of the NSCA License - See LICENSE.md for more info
//

#include <string.h>

/*==============================================================================
The C library function void *memset(void *str, int c, size_t n) copies the
character c (an unsigned char) to the first n characters of the
string pointed to, by the argument str.

Params:
    bufptr − This is a pointer to the block of memory to fill.
    value − This is the value to be set. The value is passed as an int,
            but the function fills the block of memory using the unsigned char
            conversion of this value.
    size − This is the number of bytes to be set to the value.

Return Value:
    This function returns a pointer to the memory area str.
==============================================================================*/
void* memset(void* bufptr, int value, size_t size){
  unsigned char* buf = (unsigned char*) bufptr;

  for(size_t i = 0; i < size; i++)
    buf[i] = (unsigned char) value;

    return bufptr;
 }
