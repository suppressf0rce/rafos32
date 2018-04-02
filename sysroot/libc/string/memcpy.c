//
// Copyright (c) 2018 by Dejan Radmanovic (SuppresSF0rcE).
// All Rights Reserved.
//
// This file is part of RafOS and is released under the terms
// of the NSCA License - See LICENSE.md for more info
//

#include <string.h>

/*==============================================================================
The C library function void *memcpy(void *str1, const void *str2, size_t n)
copies n characters from memory area str2 to memory area str1.

Parameters:
    destptr − This is pointer to the destination array where the content is
           to be copied, type-casted to a pointer of type void*.
    srcptr − This is pointer to the source of data to be copied, type-casted to
           a pointer of type void*.
    size − This is the number of bytes to be copied.

Return Value:
  This function returns a pointer to destination, which is destptr
==============================================================================*/
void* memcpy(void* restrict destptr, const void* restrict srcptr, size_t size){
  unsigned char* dst = (unsigned char*) destptr;
  const unsigned char* src = (const unsigned char*) srcptr;

  for(size_t i = 0; i < size; i++)
    dst[i] = src[i];

    return dstptr;
}
